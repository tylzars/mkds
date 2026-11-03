#pragma once

#include "types.h"

typedef struct Unk02152490 Unk02152490;

struct GpConnection;

typedef struct Unk021b5664 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ struct GpConnection *mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u64 mUnk_0c;
    /* 14 */ s32 mUnk_14;
    /* 18 */ Unk02152490 *mUnk_18;
    /* 1c */ u8 mUnk_1c;
    /* 1d */ u8 mUnk_1d;
    /* 1e */ u8 mUnk_1e;
    /* 1f */ u8 mUnk_1f;
    /* 20 */ u32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ char *mUnk_28;
    /* 2c */ void (*mUnk_2c)(s32, u8, void *);
    /* 30 */ void *mUnk_30;
    /* 34 */ void (*mUnk_34)(s32, u8, void *, void *);
    /* 38 */ void *mUnk_38;
    /* 3c */ void (*mUnk_3c)(s32, s32, void *);
    /* 40 */ void *mUnk_40;
    /* 44 */ void *mUnk_44;
    /* 48 */ void *mUnk_48;
    /* 4c */ void (*mUnk_4c)(s32 a, s32 b, u32 c);
    /* 50 */ u32 mUnk_50;
} Unk021b5664;

extern Unk021b5664 *data_ov000_021b5664;

void func_ov000_0219d934(void *first, void *second);
