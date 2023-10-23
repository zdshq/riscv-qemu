#ifndef __RESTORE_ROM_ADDR__
#define __RESTORE_ROM_ADDR__

#define CPT_MAGIC_BUMBER       0xbeef
#define BOOT_CODE              0x80000000
#define BOOT_FLAGS             0x80000f00
#define INT_REG_CPT_ADDR       0x80001000
#define FLOAT_REG_CPT_ADDR     0x80001100
#define VECTOR_REGS_CPT_ADDR   0x80001200
#define PC_CPT_ADDR            0x80002200//1400
#define CSR_CPT_ADDR           0x80002300

#ifndef RESET_VECTOR
    #define RESET_VECTOR        0x80200000
#endif

#define CLINT_MMIO 0x38000000
#define CLINT_MTIMECMP 0x4000
#define CLINT_MTIME 0xBFF8


#endif //__RESTORE_ROM_ADDR__

void serializeRegs(void);
void qmp_gzpmemsave(int64_t addr, int64_t size, const char *filename,Error **errp);