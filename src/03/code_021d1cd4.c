#include "03/code_021d1cd4.h"
#include "03/code_021d1d88.h"
#include "code_0200c914.h"
#include "code_0200fc8c.h"
#include "code_02147cd8.h"

void PushPointerStack(PointerStack *stack, void *pointer) {
    u32 interrupts = OS_DisableIrqMask(1);
    u32 newTop = FX_ModS32(stack->mTopIndex + 1, stack->mSlotCount);

    if (newTop == stack->mBottomIndex) {
        OS_Terminate();
    }
    stack->mPointers[stack->mTopIndex] = pointer;
    stack->mTopIndex = newTop;
    OS_EnableIrqMask(interrupts);
}

void *PopPointerStack(PointerStack *stack) {
    void *pointer = NULL;
    u32 interrupts = OS_DisableIrqMask(1);
    u8 top = stack->mTopIndex;

    if (stack->mBottomIndex != top) {
        stack->mTopIndex = FX_ModS32(top + stack->mSlotCount - 1, stack->mSlotCount);
        pointer = stack->mPointers[stack->mTopIndex];
    }
    OS_EnableIrqMask(interrupts);
    return pointer;
}
