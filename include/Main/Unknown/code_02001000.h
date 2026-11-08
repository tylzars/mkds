#pragma once

#include "types.h"
#include "Main/Unknown/code_020467d0.h" // StateMachine

typedef struct Bmg Bmg;
typedef struct Ncgr Ncgr;
typedef struct Nscr Nscr;
typedef struct Nclr Nclr;

// Three pointers filled in by LoadNclrData, LoadNcgrData2 and LoadNscrData.
typedef struct Bg1Files {
    /* 00 */ Nclr *mPalette;
    /* 04 */ Ncgr *mChars;
    /* 08 */ Nscr *mScreenMap;
} Bg1Files;

// Object behind gLogoScene.
typedef struct LogoScene {
    /* 00 */ Bg1Files mMainBg;
    /* 0c */ Bg1Files mSubBg;
    /* 18 */ StateMachine mStateMachine;
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
