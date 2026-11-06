#pragma once

#include "types.h"

typedef u32 OSIntrMode;

// Clears the IRQ disable bit and returns the previous bit.
OSIntrMode OS_EnableInterrupts(void);
// Sets the IRQ disable bit and returns the previous bit.
OSIntrMode OS_DisableInterrupts(void);
// Puts the IRQ disable bit back to the one in state and returns the previous bit.
OSIntrMode OS_RestoreInterrupts(OSIntrMode state);
// Returns the processor mode (low five bits of the status register).
u32 OS_GetProcMode(void);

// Filled by OS_GetOwnerInfo from the bytes of a fixed-address block: mUnk_04 holds the 0x14 bytes at offset 0x06 of the
// block and mUnk_1a the 0x34 bytes at offset 0x1c.
typedef struct Unk0200fddc {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
    /* 04 */ u8 mUnk_04[0x14];
    /* 18 */ u16 mUnk_18;
    /* 1a */ u8 mUnk_1a[0x34];
    /* 4e */ u16 mUnk_4e;
} Unk0200fddc;

// Disables interrupts and halts forever.
void OS_Terminate(void);

extern u16 data_0217027c;
extern u16 data_02170280;

// Sets the IRQ and FIQ disable bits and returns their previous value.
OSIntrMode OS_DisableInterrupts_IrqAndFiq(void);
// Puts the IRQ and FIQ disable bits back to those in state and returns their previous value.
OSIntrMode OS_RestoreInterrupts_IrqAndFiq(OSIntrMode state);
// Halts the processor until the next interrupt.
void OS_Halt(void);
// Busy wait of about cycle / 4 loops.
void OS_SpinWait(u32 cycle);
// Receive function registered for channel 12 by OS_InitReset. Takes the command from bits 8 to 14 of its second
// argument: command 0x10 stores 1 in the halfword data_02170280 (nothing reads it), any other command ends in
// OS_Terminate.
void OSi_CommonCallback(u32 tag, u32 data);
// Runs once: opens PXI tag 12, waits for the other processor and installs OSi_CommonCallback, which stores 1 in
// the halfword data_02170280 for command 0x10 and halts for any other command. Nothing else reads the halfword.
void OS_InitReset(void);
// Fills the record from the words at 0x027ffc80: bits 0-2 of the halfword at +0x64, the low 4 bits of byte +2, bytes +3
// and +4, a 20-byte text from +6 with its length from byte +0x1a, a 52-byte text from +0x1c with its length from byte
// +0x50. The game copies the first text with its length into its own buffers.
void OS_GetOwnerInfo(Unk0200fddc *info);
// Copies the 6 bytes at 0x027ffcf4 into the buffer (one game site prints them as six hex pairs joined by dashes).
void OS_GetMacAddress(void *macAddress);
