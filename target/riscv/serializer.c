#include "qemu/osdep.h"
#include "qemu/log.h"
#include "cpu.h"
#include "tcg/tcg-op.h"
#include "disas/disas.h"
#include "exec/cpu_ldst.h"
#include "exec/exec-all.h"
#include "exec/helper-proto.h"
#include "exec/helper-gen.h"

#include "exec/translator.h"
#include "exec/log.h"
#include "semihosting/semihost.h"
#include "checkpoint/serializer.h"
#include "instmap.h"
#include <zlib.h>
#include "internals.h"
#include "hw/intc/riscv_aclint.h"
extern RISCVAclintMTimerState *my_riscv_mtimer;
void serializeRegs(void){
    CPUState *cs = qemu_get_cpu(0);
    for(int i = 0 ; i < 32; i++){
        cpu_physical_memory_write(INT_REG_CPT_ADDR + i*8, &cs->env_ptr->gpr[i], 8);
    }
    // F extertion
    for(int i = 0 ; i < 32; i++){
        cpu_physical_memory_write(FLOAT_REG_CPT_ADDR + i*8, &cs->env_ptr->fpr[i], 8);
    }

    cpu_physical_memory_write(PC_CPT_ADDR, &cs->env_ptr->pc, 8);
    // V extertion
    if(cs->env_ptr->vill){
        for(int i = 0; i < 32 * RV_VLEN_MAX / 64; i++){
            cpu_physical_memory_write(VECTOR_REGS_CPT_ADDR + i*8, &cs->env_ptr->vreg[i], 8);
        }        
    }
    // CSR registers
    for(int i = 0; i < CSR_TABLE_SIZE; i++){
        if(csr_ops[i].read != NULL){
            target_ulong val;
            csr_ops[i].read(cs->env_ptr, i, &val);
            cpu_physical_memory_write(CSR_CPT_ADDR + i * 8, &val, 8);
        }
    }
    uint64_t val;
    val = CPT_MAGIC_BUMBER;
    cpu_physical_memory_write(BOOT_FLAGS, &val, 8);
    uint64_t mtimecmp = riscv_aclint_mtimer_read(my_riscv_mtimer, my_riscv_mtimer->timecmp_base, 8);
    cpu_physical_memory_write(BOOT_FLAGS+16, &mtimecmp, 8);
    uint64_t mtime = riscv_aclint_mtimer_read(my_riscv_mtimer, my_riscv_mtimer->time_base, 8);
    cpu_physical_memory_write(BOOT_FLAGS+24, &mtime, 8);
    
}

void qmp_gzpmemsave(int64_t addr, int64_t size, const char *filename,
                  Error **errp)
{
    uint32_t l;
    uint8_t buf[4096];
    gzFile compressed_mem = gzopen(filename, "wb");
    if (!compressed_mem) {
        error_printf("filename %s can't open", filename);
        return;
    }

    while (size != 0) {
        l = sizeof(buf);
        if (l > size)
            l = size;
        cpu_physical_memory_read(addr, buf, l);
        if (gzwrite(compressed_mem, buf, (uint32_t) l) != l) {
            error_printf("qmp_gzpmemsave write error");
            goto exit;
        }
        addr += l;
        size -= l;
    }
exit:
    gzclose(compressed_mem);
}
