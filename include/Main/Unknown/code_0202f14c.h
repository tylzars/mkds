#pragma once

#include "types.h"

struct WLMenuScene;

// Table of four functions that member 0x80c of WLMenuScene points to.
typedef struct WLMenuCallbacks {
    /* 00 */ void (*mUnk_00)(void *a, struct WLMenuScene *b, void *c);
    /* 04 */ s32 (*mUnk_04)(void *a);
    /* 08 */ void (*mUnk_08)(void);
    /* 0c */ void (*mUnk_0c)(void);
} WLMenuCallbacks;

// 0x16-byte entries from 4 of Unk02174e4c_818.
typedef struct Unk02174e4c_818_04 {
    /* 00 */ u16 mUnk_00[0xa];
    /* 14 */ u16 mUnk_14;
} Unk02174e4c_818_04;

// The 0x5c bytes at 0x818 of WLMenuScene.
typedef struct Unk02174e4c_818 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ Unk02174e4c_818_04 mUnk_04[4];
} Unk02174e4c_818;

// 0x874-byte object that gWLMenuScene points to.
typedef struct WLMenuScene {
    /* 000 */ u8 mMainOam[0x404];
    /* 404 */ u8 mSubOam[0x404];
    /* 808 */ void *mHeap;
    /* 80c */ WLMenuCallbacks *mCurrentCallbacks;
    /* 810 */ s32 mRequestedCallbacksIndex;
    /* 814 */ s32 mCurrentCallbacksIndex;
    /* 818 */ Unk02174e4c_818 mUnk_818;
} WLMenuScene;

Unk02174e4c_818 *func_0202f14c(void);
void func_0202f160(void);
u32 func_0202f19c(void);
u32 func_0202f1a8(void);
u16 *func_0202f1d0(void);
void ReleaseWLMenuScene(void);
void AdvanceWLMenuScene(void *a);
void InitWLMenuScene(void *heap);
void func_0202f454(u32 bits);
void func_0202f478(u32 bits);
