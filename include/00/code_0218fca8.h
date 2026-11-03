#pragma once

#include "types.h"

typedef struct GpConnection GpConnection;

// Object func_ov000_0218fca8 allocates with 0xc bytes and passes to func_ov000_02190ed4.
typedef struct Unk0218fca8 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ void *mUnk_08;
} Unk0218fca8;

// Object func_ov000_0218fca8 allocates with 0x40c bytes and passes to func_ov000_02190ed4.
typedef struct Unk0218fca8_40c {
    /* 000 */ s32 mUnk_000;
    /* 004 */ s32 mUnk_004;
    /* 008 */ u8 mUnk_008[0x404];
} Unk0218fca8_40c;

// Object func_ov000_0218fca8 allocates with 0x108 bytes and passes to func_ov000_02190ed4.
typedef struct Unk0218fca8_108 {
    /* 000 */ s32 mUnk_000;
    /* 004 */ s32 mUnk_004;
    /* 008 */ u8 mUnk_008[0x100];
} Unk0218fca8_108;

extern u8 data_ov000_021b27c4[];
extern u8 data_ov000_021b27d0[];
extern u8 data_ov000_021b27d8[];
extern u8 data_ov000_021b2808[];
extern u8 data_ov000_021b280c[];
extern u8 data_ov000_021b2814[];
extern u8 data_ov000_021b2824[];
extern u8 data_ov000_021b2830[];
extern u8 data_ov000_021b2834[];
extern u8 data_ov000_021b283c[];
extern u8 data_ov000_021b2844[];
extern u8 data_ov000_021b284c[];
extern u8 data_ov000_021b2850[];
extern u8 data_ov000_021b2854[];

s32 func_ov000_0218fca8(GpConnection *a, u8 *b);
