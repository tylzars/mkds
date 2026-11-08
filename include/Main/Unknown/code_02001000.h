#pragma once

#include "types.h"

typedef struct Bmg Bmg;
typedef struct Ncgr Ncgr;
typedef struct Nscr Nscr;
typedef struct Nclr Nclr;

// Three pointers filled in by LoadNclrData, LoadNcgrData2 and LoadNscrData.
typedef struct Unk02001d30 {
    /* 00 */ Nclr *mPalette;
    /* 04 */ Ncgr *mChars;
    /* 08 */ Nscr *mScreenMap;
} Unk02001d30;

// The part of LogoScene from 0x18: a halfword at 0x0e and the halfwords at 0x10 and 0x12.
typedef struct Unk021a99c0_18 {
    /* 00 */ u8 mUnk_00[0xe];
    /* 0e */ u16 mState;
    /* 10 */ u16 mNextState;
    /* 12 */ u16 mNextStateRequested;
} Unk021a99c0_18;

// Object behind gLogoScene.
typedef struct LogoScene {
    /* 00 */ Unk02001d30 mMainBg;
    /* 0c */ Unk02001d30 mSubBg;
    /* 18 */ Unk021a99c0_18 mStateMachine;
    /* 2c */ union {
        s32 mUnk_2c;
        struct {
// Set to 1 when A, B, X, Y, L and R are held together in state 0, and stays set.
            s32 mUnk_2c_0 : 1;
            u32 mUnk_2c_1 : 1;
        };
    };
    /* 30 */ s32 mState0Frames;
    /* 34 */ s32 mSubTextFrames;
    /* 38 */ Bmg *mCommonMessages;
} LogoScene;

extern LogoScene *gLogoScene;
extern s32 data_usa_02174e54;

void func_02001000(void);
void func_0200104c(void);
