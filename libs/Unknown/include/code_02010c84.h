#pragma once

#include "types.h"
#include "code_02012b30.h" // Unk02012f58

typedef struct Unk02010c84 Unk02010c84;

// Leading words of the object func_02010cec compares with the entries of data_021617f4.
typedef struct Unk02010cec_08 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
} Unk02010cec_08;

// Entry of data_021617f4 (8 bytes).
typedef struct Unk021617f4 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[4];
} Unk021617f4;

// Entry of data_021617f8 (8 bytes).
typedef struct Unk021617f8 {
    /* 00 */ void (*mUnk_00)(Unk02010c84 *, const Unk02010cec_08 *, u32);
    /* 04 */ u8 mUnk_04[4];
} Unk021617f8;

struct Unk02010c84 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ const Unk02010cec_08 *mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u8 mUnk_18;
    /* 19 */ u8 mUnk_19[3];
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u8 mUnk_20[0x34];
};

// Second argument of func_02010d98; the bytes at 0x17 and 0x18 are read.
typedef struct Unk02010d98 {
    /* 00 */ u8 mUnk_00[0x17];
    /* 17 */ u8 mUnk_17;
    /* 18 */ u8 mUnk_18;
} Unk02010d98;

// Object at data_0217029c.
typedef struct Unk0217029c {
    /* 000 */ u32 mUnk_00;
    /* 004 */ u32 mUnk_04;
    /* 008 */ s32 mUnk_08[16];
    /* 048 */ u32 mUnk_48;
    /* 04c */ Unk02012f58 mUnk_4c;
    /* 07c */ u32 mUnk_7c;
    /* 080 */ u32 mUnk_80;
    /* 084 */ u32 mUnk_84;
    /* 088 */ u32 mUnk_88;
    /* 08c */ u32 mUnk_8c;
    /* 090 */ u32 mUnk_90;
    /* 094 */ u32 mUnk_94;
    /* 098 */ u32 mUnk_98;
    /* 09c */ u32 mUnk_9c;
    /* 0a0 */ u32 mUnk_a0;
    /* 0a4 */ u32 mUnk_a4;
    /* 0a8 */ u32 mUnk_a8;
    /* 0ac */ u32 mUnk_ac;
    /* 0b0 */ u32 mUnk_b0;
    /* 0b4 */ u32 mUnk_b4;
    /* 0b8 */ u32 mUnk_b8;
    /* 0bc */ Unk02012f58 mUnk_bc;
    /* 0ec */ Vec3 mUnk_ec;
    /* 0f8 */ u32 mUnk_f8;
    /* 0fc */ u32 mUnk_fc;
    /* 100 */ Unk02012f58 mUnk_100[3];
    /* 190 */ u8 mUnk_190[0xb0];
    /* 240 */ u32 mUnk_240;
    /* 244 */ u32 mUnk_244;
    /* 248 */ u32 mUnk_248;
    /* 24c */ u32 mUnk_24c;
    /* 250 */ u32 mUnk_250;
    /* 254 */ u32 mUnk_254;
    /* 258 */ u32 mUnk_258;
    /* 25c */ u32 mUnk_25c;
    /* 260 */ u32 mUnk_260;
} Unk0217029c;

void func_02010c84(Unk02010c84 *a, u32 b);
void func_02010cec(Unk02010c84 *a, const Unk02010cec_08 *b, u32 c, u32 d);
u32 func_02010d98(const u8 *a, const Unk02010d98 *b);
Unk02012f58 *func_02010de8(void);
Unk02012f58 *func_02010e2c(void);
void func_02010e70(void);
Unk02012f58 *func_02010ed4(void);
void func_02010f24(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
void func_02010f50(u32 a, u32 b, u32 c);
void func_02010f74(u32 a, u32 b, u32 c);
