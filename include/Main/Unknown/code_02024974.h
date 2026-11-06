#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct SoundSource SoundSource;

// Ten words at 0x40 of an Unk02024eec, built on the stack by func_020719d0.
typedef struct Unk02024eec_40 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
} Unk02024eec_40;

// The bytes from 0x450 of an Kart, which func_02024a88 and func_02024eec read and write.
typedef struct Unk02024eec {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u8 mUnk_04;
    /* 05 */ u8 mUnk_05[3];
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ u8 mUnk_2c;
    /* 2d */ u8 mUnk_2d[3];
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
    /* 3c */ u8 mUnk_3c[4];
    /* 40 */ union {
        struct {
            u8 mUnk_40[4];
            s32 mUnk_44;
            u8 mUnk_48[8];
            s32 mUnk_50;
            s32 mUnk_54;
            s32 mUnk_58;
            s32 mUnk_5c;
            s32 mUnk_60;
            s32 mUnk_64;
        };
        Unk02024eec_40 mUnk_40_m;
    };
    /* 68 */ s32 mUnk_68;
} Unk02024eec;

typedef struct Kart Kart;
typedef struct Unk02024eec Unk02024eec;

s32 func_02024974(s32 a, s32 b, u32 c, u32 d);
void func_020249b8(Kart *a, s32 b, s32 c);
void func_02024a28(SoundSource *p, u16 a, s32 b, s32 c);
void func_02024a88(Kart *a);
s32 func_02024eec(Unk02024eec *a, s32 b, s32 c);
void func_02024fc0(Kart *a, Unk02024eec *b);
void func_02024fe8(Kart *a, Unk02024eec *b);
void func_02025030(Kart *a, Unk02024eec *b);
void func_0202506c(Kart *a, Unk02024eec *b);
u32 func_020250a8(void);
