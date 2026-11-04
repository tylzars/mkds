#pragma once

#include "types.h"
#include "Main/Unknown/code_0200ad00.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200fd1c.h"
#include "Main/Unknown/code_0200aeb4.h"

struct Unk02008188;

// The 0x16 bytes at 0x1300 of Unk0216fdac: a count at mUnk_01 and that many halfwords from mUnk_02.
typedef struct Unk02009ff4 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02[10];
} Unk02009ff4;

// One of the 15 entries of 0x16 bytes in mUnk_1340 of Unk0216fdac.
typedef struct Unk0216fdac_1340 {
    /* 00 */ u8 mUnk_00_0 : 4;
    /* 00 */ u8 mUnk_00_4 : 4;
    /* 01 */ u8 mUnk_01[0x15];
} Unk0216fdac_1340;

// Object behind data_0216fdac. The members from 0x1788 on are reached from a pointer advanced in steps of 0x5d4
// bytes, so their offsets here include the 0x1788.
typedef struct Unk0216fdac {
    /* 0000 */ u8 mUnk_0000[0x1300];
    /* 1300 */ Unk02009ff4 mUnk_1300;
    /* 1316 */ u16 mUnk_1316;
    /* 1318 */ s32 mUnk_1318;
    /* 131c */ u32 mUnk_131c;
    /* 1320 */ u32 mUnk_1320;
    /* 1324 */ u8 mUnk_1324[0x1340 - 0x1324];
    /* 1340 */ u8 mUnk_1340[0x14a];
    /* 148a */ u16 mUnk_148a[15];
    /* 14a8 */ u32 mUnk_14a8[15];
    /* 14e4 */ void (*mUnk_14e4)(u32, u32, void *);
    /* 14e8 */ u32 mUnk_14e8[15];
    /* 1524 */ u8 mUnk_1524;
    /* 1525 */ u8 mUnk_1525;
    /* 1526 */ s8 mUnk_1526[15];
    /* 1535 */ u8 mUnk_1535;
    /* 1536 */ u16 mUnk_1536;
    /* 1538 */ u8 mUnk_1538[0x1754 - 0x1538];
    /* 1754 */ u16 mUnk_1754[15];
    /* 1772 */ u8 mUnk_1772[0x16];
    /* 1788 */ u8 mUnk_1788[0x1d1f - 0x1788];
    /* 1d1f */ u8 mUnk_1d1f;
    /* 1d20 */ u8 mUnk_1d20;
    /* 1d21 */ u8 mUnk_1d21;
    /* 1d22 */ u8 mUnk_1d22[0x1d2c - 0x1d22];
    /* 1d2c */ u8 mUnk_1d2c[0x14];
    /* 1d40 */ Unk0200adfc *mUnk_1d40;
    /* 1d44 */ struct Unk02008188 *mUnk_1d44;
    /* 1d48 */ u16 mUnk_1d48;
    /* 1d4a */ u16 mUnk_1d4a;
    /* 1d4c */ u16 mUnk_1d4c;
    /* 1d4e */ u16 mUnk_1d4e;
    /* 1d50 */ u16 mUnk_1d50;
    /* 1d52 */ u8 mUnk_1d52;
    /* 1d53 */ u8 mUnk_1d53;
    /* 1d54 */ Unk0200adfc *mUnk_1d54;
    /* 1d58 */ u32 *mUnk_1d58;
    /* 1d5c */ u8 mUnk_1d5c[0x74c8 - 0x1d5c];
    /* 74c8 */ s32 mUnk_74c8;
    /* 74cc */ u8 mUnk_74cc[0x74e0 - 0x74cc];
    /* 74e0 */ Unk0200aeec_head mUnk_74e0;
    /* ---- */ u8 mUnk_74e0_end[0x800 - sizeof(Unk0200aeec_head)];
    /* 7ce0 */ u8 mUnk_7ce0[0x18];
} Unk0216fdac;

u32 func_02007148(u32 a, u32 b);
void func_02007154(u32 a);
