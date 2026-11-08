#pragma once

#include "types.h"
#include "tp.h"

typedef struct Rect {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Rect;

typedef struct KeyTouchInput {
    /* 00 */ TPData mTouchSamples[5];
    /* 28 */ u16 mTouchX;
    /* 2a */ u16 mTouchY;
    /* 2c */ u16 mPrevTouchX;
    /* 2e */ u16 mPrevTouchY;
    /* 30 */ u16 mKeysDown;
    /* 32 */ u16 mKeysPressed;
    /* 34 */ u16 mKeysPressedOrRepeated;
    /* 36 */ u16 mKeysReleased;
    /* 38 */ union {
        u8 mTouchFlags;
        struct {
            u8 mDown : 1;
            u8 mPressed : 1;
            u8 mPressedOrRepeated : 1;
            u8 mReleased : 1;
            u8 mOther : 4;
        } mBits;
    };
} KeyTouchInput;
