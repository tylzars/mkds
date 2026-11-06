#include "03/code_021d27d8.h"

#include "code_0200c914.h"
#include "code_0200fc8c.h"
#include "code_020176c0.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0214d000.h"

void func_ov003_021d28b0(void *buffer) {
    MemFill(buffer, 0, 0x40000);
    data_ov003_021da2c8 = ExpHeapCreate(buffer, 0x40000, 0);
    if (data_ov003_021da2c8 == NULL) {
        IrqDisableLoopForever();
    }
}

void func_ov003_021d2894(void) {
    ExpHeapDestroy(&data_ov003_021da2c8->mUnk_00);
    data_ov003_021da2c8 = NULL;
}

void *func_ov003_021d285c(u32 size, s32 alignment) {
    u32 interrupts = OS_DisableIrqMask(1);
    void *block = ExpHeapAlloc(data_ov003_021da2c8, size, alignment);

    if (block == NULL) {
        IrqDisableLoopForever();
    }
    OS_EnableIrqMask(interrupts);
    return block;
}

void *func_ov003_021d283c(u32 size, s32 alignment) {
    void *block = func_ov003_021d285c(size, alignment);

    MemFill(block, 0, size);
    return block;
}

void func_ov003_021d2808(void *storage) {
    void **block = storage;
    u32 interrupts = OS_DisableIrqMask(1);

    if (*block != NULL) {
        ExpHeapFree(data_ov003_021da2c8, *block);
        OS_EnableIrqMask(interrupts);
        *block = NULL;
    }
}

void func_ov003_021d27d8(void *block) {
    u32 interrupts = OS_DisableIrqMask(1);

    if (block != NULL) {
        ExpHeapFree(data_ov003_021da2c8, block);
        OS_EnableIrqMask(interrupts);
    }
}
