#pragma once

#include "types.h"
#include "Main/Unknown/types_02180728.h"

// Object behind gWLMenuMessage, 0x654 bytes: the halfwords from 0x34 are 32 per row.
typedef struct WLMenuMessage {
    /* 000 */ void *mFont;
    /* 004 */ u8 mCharCanvas[0x20];
    /* 024 */ TextCanvas mTextCanvas;
    /* 034 */ u16 mScreenMap[0x300];
    /* 634 */ void *mCommonMessages;
    /* 638 */ struct Bmg *mMBChildMessages;
    /* 63c */ u8 mUnk_63c[4];
    /* 640 */ s32 mBg3Offset;
    /* 644 */ u8 mUnk_644[8];
    /* 64c */ s32 mState;
    /* 650 */ void *mHeap;
} WLMenuMessage;

void func_02035d18(void);
void func_02035d20(void);
void WriteSubBg3Offset(u32 offsetX, int offsetY);
void WriteSubDispcntBits(int bits);
void ReleaseWLMenuMessage(void);
s32 func_02035db4(u32 sceneNumbers);
void SetNextScene(unsigned int sceneNumbers, unsigned int nextScene);
void func_02035e38(void);
u32 func_02035e44(void);
s32 func_02035e64(u32 sceneNumbers);
s32 func_02035ee0(u32 sceneNumbers);
s32 func_02035f5c(u32 sceneNumbers);
void func_02036044(unsigned int value);
void func_02036058(unsigned int value);
