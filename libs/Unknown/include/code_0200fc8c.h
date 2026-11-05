#pragma once

#include "types.h"

u32 IrqEnable(void);
u32 IrqDisable(void);
u32 IrqRestore(u32 a);
u32 ProcessorModeGet(void);

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

void IrqDisableLoopForever(void);

extern u16 data_0217027c;
extern u16 data_02170280;

u32 func_0200fccc(void);
u32 func_0200fce0(u32 a);
void func_0200fd04(void);
void func_0200fd10(u32 a);
void func_0200fd30(u32 a, u32 b);
// Runs once: opens PXI tag 12, waits for the other processor and installs func_0200fd30, which stores 1 in the halfword
// at 0x02170260 for command 0x10 and halts for any other command. Nothing else reads the halfword.
void OS_InitReset(void);
// Fills the record from the words at 0x027ffc80: bits 0-2 of the halfword at +0x64, the low 4 bits of byte +2, bytes +3
// and +4, a 20-byte text from +6 with its length from byte +0x1a, a 52-byte text from +0x1c with its length from byte
// +0x50. The game copies the first text with its length into its own buffers.
void OS_GetOwnerInfo(Unk0200fddc *p);
// Copies the 6 bytes at 0x027ffcf4 into the buffer (one game site prints them as six hex pairs joined by dashes).
void OS_GetMacAddress(void *p);
