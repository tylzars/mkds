#pragma once

#include "types.h"
#include "01/code_02188950.h"

typedef struct EmblemInput {
    /* 0x00 */ s32 mX;
    /* 0x04 */ s32 mY;
    /* 0x08 */ s32 mPressed;
    /* 0x0c */ s32 mReleased;
    /* 0x10 */ s32 mDown;
    /* 0x14 */ s32 mStillCallCount;
    /* 0x18 */ s32 mPrevX;
    /* 0x1c */ s32 mPrevY;
    /* 0x20 */ s32 mPrevPressed;
    /* 0x24 */ s32 mPrevReleased;
    /* 0x28 */ s32 mPrevDown;
    /* 0x2c */ s32 mBit5HeldCount;
    /* 0x30 */ s32 mBit4HeldCount;
    /* 0x34 */ s32 mBit6HeldCount;
    /* 0x38 */ s32 mBit7HeldCount;
    /* 0x3c */ s32 mBit0HeldCount;
    /* 0x40 */ s32 mBit1HeldCount;
    /* 0x44 */ s32 mBit10HeldCount;
    /* 0x48 */ s32 mBit11HeldCount;
    /* 0x4c */ s32 mBit9HeldCount;
    /* 0x50 */ s32 mBit8HeldCount;
} EmblemInput;

#include "01/code_0218f9d4.h"

BOOL IsEmblemInputRepeat(int a);
u16 func_ov001_02192a04(u16 a);
u16 func_ov001_02192a14(u16 a);
u32 GetEmblemInputPrevDown(void);
u32 GetEmblemInputPrevY(void);
u32 GetEmblemInputPrevX(void);
u32 GetEmblemInputDown(void);
u32 GetEmblemInputPressed(void);
u32 GetEmblemInputY(void);
s32 GetEmblemInputX(void);
void AdvanceEmblemInput(void);
void CreateEmblemInput(void);
