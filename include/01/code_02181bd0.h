#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020e005c.h"

// Object updated by UpdateCoin, one state per value of mUnk_0f8.
typedef struct Coin {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ u16 mModelAlpha;
    /* 0a2 */ u8 mUnk_0a2[0x2];
    /* 0a4 */ s32 mNsbtpFrameIndex;
    /* 0a8 */ s32 mUnk_0a8;
    /* 0ac */ s32 mTimer;
    /* 0b0 */ s32 mScaleFactor;
    /* 0b4 */ GroupFollower mFollower;
    /* 0d8 */ Vec3 mUnk_0d8;
    /* 0e4 */ s32 mBounceY;
    /* 0e8 */ Vec3 *mTargetPos;
    /* 0ec */ Vec3 mUnk_0ec;
    /* 0f8 */ s32 mState;
    /* 0fc */ void *mEffect;
    /* 100 */ s32 mEffectTimer;
} Coin;

// List of objects, as returned by FindMapObjectKindUpdateList(0x68).
typedef struct CoinList {
    /* 00 */ Coin **mObjects;
    /* 04 */ u16 mObjectCount;
} CoinList;

#include "Main/Unknown/code_0209b000.h"
#include "01/code_02182000.h"
#include "01/code_0218155c.h"
#include "01/unk_021a6000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/code_0219b250.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_02100000.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_020d22c0.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d4000.h"

void *func_ov001_02181bd0(void);
void *func_ov001_02181bec(void);
void *func_ov001_02181c08(void);
void CreateCoinKindData(void);
void UpdateCoin(void *a, Coin *coin);
void func_ov001_0218254c(void);
void InitCoinObjects(CoinList *coinList);
void DrawCoin(void *b, Coin *coin);
void LoadCoin(Unk0219b478 *a);
u8 CollideKartWithCoin(Coin *coin, Kart *kart, u8 *e, u8 *f);
void func_ov001_021827a4(void);
void func_ov001_021827f0(void);
void func_ov001_021828f0(void);
void func_ov001_021829ac(s32 a);
void func_ov001_02182a3c(s32 a);
void func_ov001_02182bbc(u32 amount);
void func_ov001_02182bdc(void);
void func_ov001_02182d30(void);
void func_ov001_02182e84(void);
void func_ov001_02182eb8(Coin *coin, s32 b);
void func_ov001_02182f1c(Coin *coin, Kart *kart);

#include "01/code_0219b540.h"
#include "Main/Unknown/code_02081000.h"
#include "Main/Unknown/code_02081618.h"
