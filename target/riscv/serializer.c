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
#include "checkpoint/checkpoint_arg.h"
extern RISCVAclintMTimerState *my_riscv_mtimer;
static void serializeRegs(void){
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

static void serializePMem(int64_t addr, int64_t size,
                  Error **errp)
{
    uint32_t l;
    uint8_t buf[4096];
    char filepath[200];
    if (checkpoint_state == SimpointCheckpointing) {
        strcpy(filepath, pathmanger.outputPath);
        filepath[strlen(filepath)] = '_';
        filepath[strlen(filepath) + 1] = '\0';
        strcat(filepath, )
        filepath = pathmanger.outputPath + "_" + \
                            to_string(simpoint2Weights.begin()->first) + "_" + \
                            to_string(simpoint2Weights.begin()->second) + "_.gz";
    } else {
        filepath = pathManager.getOutputPath() + "_" + \
                            to_string(inst_count) + "_.gz";
    }
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

static uint64_t find_minlocation(void) {
    uint64_t min = -1;
    for (int i = 0; i < SIMPOINT_IDX_MAX; i++){
        if(!serializer.simpoints[i] && serializer.simpoints[i] < min){
            min = serializer.simpoints[i];
            serializer.simpoints[i] = 0;
        }
    }
    if(min != -1){
        return min;
    }
    return 0;
}

static bool instrsCouldTakeCpt(uint64_t num_insts) {
    int minlocation = find_minlocation();
    switch (checkpoint_state) {
        case SimpointCheckpointing:
        if (!minlocation) {
            break;
        }else{
            uint64_t next_point = minlocation * serializer.intervalSize + 100000;
            if (num_insts >= next_point) {
            info_report("Should take cpt now: %lu", num_insts);
            return true;
            } else if (num_insts % serializer.intervalSize == 0) {
            info_report("First cpt @ %lu, now: %lu",
            next_point, num_insts);
            break;
            }else{
            break;
            }
        }
        case ManualOneShotCheckpointing:
        return true;
        case ManualUniformCheckpointing:
        case UniformCheckpointing:
        // if (num_insts >= nextUniformPoint) {
        //     info_report("Should take cpt now: %lu", num_insts);
        //     return true;
        // }
        break;
        case NoCheckpoint:
        break;
        default:
        break;
    }
    return false;
    }
// void notify_taken(uint64_t i) {
//   info_report("Taking checkpoint @ instruction count %lu", i);
//   if (checkpoint_state == SimpointCheckpointing) {
//     info_report("simpoint2Weights size: %ld", simpoint2Weights.size());

//     if (!simpoint2Weights.empty()) {
//       simpoint2Weights.erase(simpoint2Weights.begin());
//     }

//     if (!simpoint2Weights.empty()) {
//         pathManager.setCheckpointingOutputDir();
//     } 

//   } else if (checkpoint_state==ManualUniformCheckpointing||checkpoint_state==UniformCheckpointing) {
//     nextUniformPoint += intervalSize;
//     pathManager.setCheckpointingOutputDir();
//   }
// }

#include "qapi/qapi-commands-machine.h"

static void serialize(uint64_t icount){
    MemoryInfo * info = qmp_query_memory_size_summary(NULL);
    serializeRegs();
    serializePMem(0x80000000, info->base_memory, "bbl.gz", NULL);  
}

bool try_take_cpt(uint64_t icount) {
  if (instrsCouldTakeCpt(icount)) {
    serialize(icount);
    // notify_taken(icount);
    info_report("return true");
    return true;
  }
  return false;
}
