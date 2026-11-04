#pragma once

#include "types.h"

u32 IrqEnable(void);
u32 IrqDisable(void);
u32 IrqRestore(u32 a);
u32 ProcessorModeGet(void);

// Filled by func_0200fddc from the bytes of a fixed-address block: mUnk_04 holds the 0x14 bytes at offset 0x06 of the
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
void func_0200fd74(void);
void func_0200fddc(Unk0200fddc *p);
void func_0200fe58(void *p);
