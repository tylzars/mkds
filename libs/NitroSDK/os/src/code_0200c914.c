#include "code_0200c914.h"
#include "Main/Unknown/code_02000000.h"
#include "Main/Unknown/code_0200c000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_00000000.h"
#include "registers.h"

u16 OSi_IrqCallbackInfoIndex[8] = {8, 9, 10, 11, 3, 4, 5, 6};
OSIrqCallbackInfo OSi_IrqCallbackInfo[8];

// Sets the handler for each interrupt bit in intrBit. DMA and timer bits register a callback with no argument.
void OS_SetIrqFunction(OSIrqMask intrBit, OSIrqFunction function) {
    s32 i;
    OSIrqCallbackInfo *info;

    for (i = 0; i < 22; i++) {
        if (intrBit & 1) {
            info = 0;
            if (i >= 8 && i <= 11) {
                info = &OSi_IrqCallbackInfo[i - 8];
            } else if (i >= 3 && i <= 6) {
                info = &OSi_IrqCallbackInfo[i + 1];
            } else {
                OS_IRQTable[i] = function;
            }
            if (info != 0) {
                info->mFunc = function;
                info->mArg = 0;
                info->mEnable = 1;
            }
        }
        intrBit >>= 1;
    }
}

// Returns the handler of the lowest interrupt bit set in intrBit, or 0 when none is set.
OSIrqFunction OS_GetIrqFunction(OSIrqMask intrBit) {
    s32 i;
    OSIrqFunction *table;

    table = OS_IRQTable;
    for (i = 0; i < 22; i++, table++) {
        if (intrBit & 1) {
            if (i >= 8 && i <= 11) {
                return OSi_IrqCallbackInfo[i - 8].mFunc;
            }
            if (i >= 3 && i <= 6) {
                return OSi_IrqCallbackInfo[i + 1].mFunc;
            }
            return *table;
        }
        intrBit >>= 1;
    }
    return 0;
}

// Registers callback with arg for DMA channel dmaNo and enables its interrupt; the interrupt is only disabled again
// after the callback when it was not already enabled.
void OSi_EnterDmaCallback(u32 dmaNo, UnkFunc *callback, u32 arg) {
    OSIrqMask imask;

    imask = 1 << (dmaNo + 8);
    OSi_IrqCallbackInfo[dmaNo].mFunc = callback;
    OSi_IrqCallbackInfo[dmaNo].mArg = arg;
    OSi_IrqCallbackInfo[dmaNo].mEnable = OS_EnableIrqMask(imask) & imask;
}

// Registers callback with arg for timer timerNo and enables its interrupt, which stays enabled afterwards.
void OSi_EnterTimerCallback(u32 timerNo, UnkFunc *callback, u32 arg) {
    (OSi_IrqCallbackInfo + 4)[timerNo].mFunc = callback;
    (OSi_IrqCallbackInfo + 4)[timerNo].mArg = arg;
    OS_EnableIrqMask(1 << (timerNo + 3));
    (OSi_IrqCallbackInfo + 4)[timerNo].mEnable = 1;
}

// Writes the interrupt enable mask with interrupts off and returns the previous mask.
OSIrqMask OS_SetIrqMask(OSIrqMask intr) {
    u16 savedMasterEnable;
    OSIrqMask prev;

    savedMasterEnable = reg_OS_IME;
    reg_OS_IME = 0;
    prev = reg_OS_IE;
    reg_OS_IE = intr;
    reg_OS_IME;
    reg_OS_IME = savedMasterEnable;
    return prev;
}

// Sets the bits of intr in the interrupt enable mask and returns the previous mask.
OSIrqMask OS_EnableIrqMask(OSIrqMask intr) {
    u16 savedMasterEnable;
    OSIrqMask prev;

    savedMasterEnable = reg_OS_IME;
    reg_OS_IME = 0;
    prev = reg_OS_IE;
    reg_OS_IE = prev | intr;
    reg_OS_IME;
    reg_OS_IME = savedMasterEnable;
    return prev;
}

// Clears the bits of intr in the interrupt enable mask and returns the previous mask.
OSIrqMask OS_DisableIrqMask(OSIrqMask intr) {
    u16 savedMasterEnable;
    OSIrqMask prev;

    savedMasterEnable = reg_OS_IME;
    reg_OS_IME = 0;
    prev = reg_OS_IE;
    reg_OS_IE = prev & ~intr;
    reg_OS_IME;
    reg_OS_IME = savedMasterEnable;
    return prev;
}

// Writes the interrupt request flags with interrupts off and returns the previous flags.
OSIrqMask OS_ResetRequestIrqMask(OSIrqMask intr) {
    u16 savedMasterEnable;
    OSIrqMask prev;

    savedMasterEnable = reg_OS_IME;
    reg_OS_IME = 0;
    prev = reg_OS_IF;
    reg_OS_IF = intr;
    reg_OS_IME;
    reg_OS_IME = savedMasterEnable;
    return prev;
}

// Writes the check values at both ends of the interrupt stack.
void OS_SetIrqStackChecker(void) {
    u32 base;

    base = (u32) &data_027e0000;
    *OFFSET_PTR(u32, base, 0x3f7c) = 0xfddb597d;
    *(u32 *) (base + 0x3f80 - (u32) data_00000c00) = 0x7bf9dd5b;
}

void OS_IrqDummy(void) {}

// Runs and clears the callback of entry index, marks its interrupt as handled and disables it again unless the entry
// stays enabled.
void OSi_IrqCallback(int index) {
    UnkFunc *callback;
    OSIrqMask irqBit;

    irqBit = 1 << OSi_IrqCallbackInfoIndex[index];
    callback = OSi_IrqCallbackInfo[index].mFunc;
    OSi_IrqCallbackInfo[index].mFunc = 0;
    if (callback != 0) {
        callback(OSi_IrqCallbackInfo[index].mArg);
    }
    *OFFSET_PTR(u32, &data_027e0000, 0x3ff8) |= irqBit;
    if (OSi_IrqCallbackInfo[index].mEnable != 0) {
        return;
    }
    OS_DisableIrqMask(irqBit);
}

void OSi_IrqDma0(void) {
    OSi_IrqCallback(0);
}

void OSi_IrqDma1(void) {
    OSi_IrqCallback(1);
}

void OSi_IrqDma2(void) {
    OSi_IrqCallback(2);
}

void OSi_IrqDma3(void) {
    OSi_IrqCallback(3);
}

void OSi_IrqTimer0(void) {
    OSi_IrqCallback(4);
}

void OSi_IrqTimer1(void) {
    OSi_IrqCallback(5);
}

void OSi_IrqTimer2(void) {
    OSi_IrqCallback(6);
}

void OSi_IrqTimer3(void) {
    OSi_IrqCallback(7);
}
