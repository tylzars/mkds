#pragma once

#include "types.h"
#include "code_0200e77c.h"

// Fixed-address object in the data TCM; the code reads and writes words at these offsets.
typedef struct Unk027e0000 {
    /* 0000 */ OSThreadQueue mUnk_0000;
    /* 0008 */ u8 mUnk_0008[0x3380 - 0x8];
    /* 3380 */ u32 mUnk_3380;
    /* 3384 */ u8 mUnk_3384[0x3f7c - 0x3384];
    /* 3f7c */ u32 mUnk_3f7c;
    /* 3f80 */ u8 mUnk_3f80[0x3ff8 - 0x3f80];
    /* 3ff8 */ u32 mUnk_3ff8;
} Unk027e0000;

extern Unk027e0000 data_027e0000;

typedef void (*OSIrqFunction)(void);
typedef u32 OSIrqMask;

// One registered callback of a DMA channel or timer: the function, whether its interrupt stays enabled after the
// callback has run, and the argument the function is called with.
typedef struct OSIrqCallbackInfo {
    /* 00 */ UnkFunc *mFunc;
    /* 04 */ u32 mEnable;
    /* 08 */ u32 mArg;
} OSIrqCallbackInfo;

// Handler for each of the 22 interrupt bits; the unused ones hold OS_IrqDummy.
extern OSIrqFunction OS_IRQTable[22];
// Entries 0 to 3 belong to DMA channels 0 to 3, entries 4 to 7 to timers 0 to 3. OSi_IrqCallback clears an entry's
// function before calling it, so each registration runs once.
extern OSIrqCallbackInfo OSi_IrqCallbackInfo[8];
// Interrupt bit of each entry of OSi_IrqCallbackInfo.
extern u16 OSi_IrqCallbackInfoIndex[8];

// Call OSi_IrqCallback with entry 7 to 4 (timer 3 to 0) and entry 3 to 0 (DMA 3 to 0).
void OSi_IrqTimer3(void);
void OSi_IrqTimer2(void);
void OSi_IrqTimer1(void);
void OSi_IrqTimer0(void);
void OSi_IrqDma3(void);
void OSi_IrqDma2(void);
void OSi_IrqDma1(void);
void OSi_IrqDma0(void);
// Clears the function of entry index of OSi_IrqCallbackInfo and calls it with its argument, sets the entry's bit in
// the interrupt check word at 0x027e3ff8, and clears the bit in the interrupt enable mask unless the entry says it
// stays enabled.
void OSi_IrqCallback(int index);
// Returns at once; the interrupt bits without a handler point to it.
void OS_IrqDummy(void);
// Writes 0xfddb597d at 0x027e3f7c and 0x7bf9dd5b at 0x027e3380, the two ends of the stack region the start-up code
// sets up for interrupt mode.
void OS_SetIrqStackChecker(void);
// Write REG_IF and REG_IE with interrupts off and return the previous value.
OSIrqMask OS_ResetRequestIrqMask(OSIrqMask intr);
OSIrqMask OS_DisableIrqMask(OSIrqMask intr);
OSIrqMask OS_EnableIrqMask(OSIrqMask intr);
OSIrqMask OS_SetIrqMask(OSIrqMask intr);
// Store the callback and its argument in the entry for timer timerNo (OSi_IrqCallbackInfo[timerNo + 4]) or DMA
// channel dmaNo, enable the interrupt bit and set the entry's mEnable: always for a timer, and for a DMA channel
// only when the bit was already set.
void OSi_EnterTimerCallback(u32 timerNo, UnkFunc *callback, u32 arg);
void OSi_EnterDmaCallback(u32 dmaNo, UnkFunc *callback, u32 arg);
// Return and set the handler of the lowest interrupt bit in intrBit. DMA and timer bits use OSi_IrqCallbackInfo, with
// no argument and mEnable set.
OSIrqFunction OS_GetIrqFunction(OSIrqMask intrBit);
void OS_SetIrqFunction(OSIrqMask intrBit, OSIrqFunction function);
