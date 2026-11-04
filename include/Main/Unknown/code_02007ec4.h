#pragma once

#include "types.h"
#include "Main/Unknown/code_02007148.h"
#include "Main/Unknown/code_0200ad00.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02152000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200fc8c.h"

// 0xc0-byte record: the first 0x3c bytes are taken from 0x027ffc42 when the halfword at 0x027ffc40 is 2 (or from
// address 0); the halfwords at 0x4c and 0x4e and the bytes from 0x4a are set by func_02007ec4 and func_0200b15c.
typedef struct Unk02007ec4 {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u8 mUnk_12[0x2a];
    /* 3c */ u16 mUnk_3c;
    /* 3e */ u8 mUnk_3e[2];
    /* 40 */ u16 mUnk_40;
    /* 42 */ u8 mUnk_42[2];
    /* 44 */ u32 mUnk_44;
    /* 48 */ u16 mUnk_48;
    /* 4a */ u8 mUnk_4a;
    /* 4b */ u8 mUnk_4b;
    /* 4c */ u16 mUnk_4c;
    /* 4e */ u16 mUnk_4e;
    /* 50 */ u8 mUnk_50[0x70];
} Unk02007ec4;

// Filled by func_0200806c.
typedef struct Unk020072c0_buf {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u8 mUnk_0c;
    /* 0d */ u8 mUnk_0d[3];
} Unk020072c0_buf;

// 0x14 bytes at 0x1d2c of an entry of Unk0216fdac: three words, then four halfwords.
typedef struct Unk0200806c_b {
    /* 00 */ u32 mUnk_00[3];
    /* 0c */ u16 mUnk_0c[4];
} Unk0200806c_b;

// 0x10-byte entry of Unk020082b4.
typedef struct Unk020082b4_0c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk020082b4_0c;

// 0xe4-byte object that func_020082b4 sets up at 0x1788 of an entry of Unk0216fdac.
typedef struct Unk020082b4 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mUnk_08[4];
    /* 0c */ Unk020082b4_0c mUnk_0c[3];
    /* 3c */ u8 mUnk_3c[0x88];
    /* c4 */ u8 mUnk_c4[0x20];
} Unk020082b4;

// Object func_02008310 and func_020082b4 read; the Unk0200adfc at 0x1e8 and the words at 0x258 go to the entry.
typedef struct Unk02008188 {
    /* 000 */ u8 mUnk_000[0x24];
    /* 024 */ u32 mUnk_024;
    /* 028 */ u32 mUnk_028[2];
    /* 030 */ u8 mUnk_030[4];
    /* 034 */ u32 mUnk_034;
    /* 038 */ u32 mUnk_038[2];
    /* 040 */ u8 mUnk_040[0x120];
    /* 160 */ u8 mUnk_160[0x88];
    /* 1e8 */ Unk0200adfc mUnk_1e8;
    /* 258 */ u32 mUnk_258[1];
} Unk02008188;

void func_02007ec4(Unk02007ec4 *a, u16 b, u16 c, u32 d, u32 e);
u32 func_02007f38(u32 a, u32 b, u32 c);
u32 func_02007ff0(u32 a, u32 b, u32 c);
BOOL func_0200806c(Unk020072c0_buf *a, void *b, u16 c, void *d);
u32 func_020080e8(Unk0200806c_b *a, Unk020082b4 *b);
void func_02008188(Unk02008188 *a, u32 *b, Unk020082b4_0c *c, u32 *d);
void func_020082b4(Unk020082b4 *a, Unk02008188 *b);
u32 func_02008310(void *a, Unk02008188 *b);
