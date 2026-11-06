#include "03/code_021d27d8.h"

#include "code_0200c914.h"
#include "code_0200fc8c.h"
#include "code_020176c0.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0214d000.h"

void func_ov003_021d28b0(void *buffer) {
    MI_CpuFill8(buffer, 0, 0x40000);
    data_ov003_021da2c8 = NNS_FndCreateExpHeapEx(buffer, 0x40000, 0);
    if (data_ov003_021da2c8 == NULL) {
        OS_Terminate();
    }
}

void func_ov003_021d2894(void) {
    NNS_FndDestroyExpHeap(data_ov003_021da2c8);
    data_ov003_021da2c8 = NULL;
}

void *func_ov003_021d285c(u32 size, s32 alignment) {
    u32 interrupts = OS_DisableIrqMask(1);
    void *block = NNS_FndAllocFromExpHeapEx(data_ov003_021da2c8, size, alignment);

    if (block == NULL) {
        OS_Terminate();
    }
    OS_EnableIrqMask(interrupts);
    return block;
}

void *func_ov003_021d283c(u32 size, s32 alignment) {
    void *block = func_ov003_021d285c(size, alignment);

    MI_CpuFill8(block, 0, size);
    return block;
}

void func_ov003_021d2808(void *storage) {
    void **block = storage;
    u32 interrupts = OS_DisableIrqMask(1);

    if (*block != NULL) {
        NNS_FndFreeToExpHeap(data_ov003_021da2c8, *block);
        OS_EnableIrqMask(interrupts);
        *block = NULL;
    }
}

void func_ov003_021d27d8(void *block) {
    u32 interrupts = OS_DisableIrqMask(1);

    if (block != NULL) {
        NNS_FndFreeToExpHeap(data_ov003_021da2c8, block);
        OS_EnableIrqMask(interrupts);
    }
}
