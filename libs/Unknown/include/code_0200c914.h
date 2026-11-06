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
extern UnkFunc *data_027e0008[22];

// Entry of the table of 8 at gDmaTimerCallbacks: a function pointer, a word, and the argument the function is called
// with.
typedef struct Unk0216fee0 {
    /* 00 */ UnkFunc *mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
} Unk0216fee0;

// Eight interrupt callback slots of three words (function, keep-enabled word, argument). Slots 0-3: the done
// interrupt of DMA channels 0-3 (interrupt-enable bits 8-11); slots 4-7: timers 0-3 (bits 3-6). The dispatcher
// clears a slot's function before calling it, so each registration runs once.
extern Unk0216fee0 gDmaTimerCallbacks[8];
extern u16 data_021617bc[8];

// Calls InterruptSlotHandler with slot 7. Table index 6; nothing else in the game uses timer 3, the number follows the
// timer 0 and 1 entries.
void Timer3InterruptHandler(void);
// Calls InterruptSlotHandler with slot 6. Table index 5; nothing else in the game uses timer 2, the number follows the
// timer 0 and 1 entries.
void Timer2InterruptHandler(void);
// Calls InterruptSlotHandler with slot 5. Table index 4 of the interrupt table at 0x027e0008.
void Timer1InterruptHandler(void);
// Calls InterruptSlotHandler with slot 4. Table index 3 of the interrupt table at 0x027e0008.
void Timer0InterruptHandler(void);
// Calls InterruptSlotHandler with slot 3. Table index 11 of the interrupt table at 0x027e0008.
void Dma3InterruptHandler(void);
// Calls InterruptSlotHandler with slot 2. Table index 10 of the interrupt table at 0x027e0008.
void Dma2InterruptHandler(void);
// Calls InterruptSlotHandler with slot 1. Table index 9 of the interrupt table at 0x027e0008.
void Dma1InterruptHandler(void);
// Calls InterruptSlotHandler with slot 0. Table index 8 of the interrupt table at 0x027e0008.
void Dma0InterruptHandler(void);
// Entry body for slot n of gDmaTimerCallbacks (0 to 3: DMA 0 to 3, 4 to 7: timers 0 to 3). Zeroes the stored
// function and calls it with the stored argument, ors bit data_021617bc[n] into the word at 0x027e3ff8, and when the
// slot's keep-enabled word is 0 clears that bit in the interrupt enable mask.
void InterruptSlotHandler(u32 n);
// Returns at once. The 14 slots of the interrupt table at 0x027e0008 that have no handler (0, 1, 2, 7 and 12 to 21)
// hold its address.
void OS_IrqDummy(void);
// Writes 0xfddb597d at 0x027e3f7c and 0x7bf9dd5b at 0x027e3380, the upper and lower end of the stack region the
// start-up code sets up for interrupt mode.
void OS_SetIrqStackChecker(void);
u32 InterruptFlagWrite(u32 v);
u32 InterruptEnableClearBits(u32 m);
u32 InterruptEnableSetBits(u32 m);
u32 InterruptEnableWrite(u32 v);
// Stores function f and argument a in slot n + 4 of gDmaTimerCallbacks, sets the slot's keep-enabled word to 1 and
// enables interrupt bit n + 3. Callers: the tick (n = 0) and the alarm (n = 1).
void SetTimerOverflowCallback(u32 n, UnkFunc *f, u32 a);
// Stores the function and the argument in slot n of gDmaTimerCallbacks, sets interrupt-enable bit n + 8 and keeps
// in the slot whether that bit was already set before. The dispatcher of the slot clears the function, calls it
// with the argument and clears the bit again unless the slot says it was set before.
void SetDmaDoneCallback(u32 n, UnkFunc *f, u32 a);
UnkFunc *InterruptHandlerGet(u32 m);
void InterruptHandlerSet(u32 m, UnkFunc *f);
