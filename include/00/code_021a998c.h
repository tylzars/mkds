#pragma once

#include "types.h"

typedef struct Unk021a998c_0c Unk021a998c_0c;

// Argument of func_ov000_021a998c.
struct Unk021a998c;
typedef s32 (*Unk021a998cFunc)(void *param_1, u32 param_2, struct Unk021a998c *param_3);

typedef struct Unk021a998c {
    /* 00 */ struct Unk0200db5c *mThread;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mState;
    /* 09 */ u8 mUnk_09;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ Unk021a998c_0c *mUnk_0c;
    /* 10 */ u32 mStateStartTime;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u16 mUnk_18;
    /* 1a */ u16 mUnk_1a;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
    /* 28 */ u32 mUnk_28;
    /* 2c */ u16 mUnk_2c;
    /* 2e */ u16 mUnk_2e;
    /* 30 */ u32 mUnk_30;
    /* 34 */ u32 mUnk_34;
    /* 38 */ Unk021a998cFunc mReceiveCallback;
    /* 3c */ u32 mReceiveBufferSize;
    /* 40 */ u8 *mReceiveBuffer;
    /* 44 */ u32 mReceiveBufferLength;
    /* 48 */ u32 mSendBufferSize;
    /* 4c */ u8 *mSendBuffer;
    /* 50 */ u8 mUnk_50[0xc];
    /* 5c */ u8 *mUnk_5c;
    /* 60 */ u32 mUnk_60;
} Unk021a998c;

void func_ov000_021a998c(Unk021a998c *a);
