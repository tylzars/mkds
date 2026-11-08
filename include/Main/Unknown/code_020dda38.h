#pragma once

#include "types.h"
#include "Main/Unknown/code_020dc474.h"
#include "Main/Unknown/code_020dd8b0.h"
#include "Main/Unknown/code_020e66e4.h"

// Object of InitWanwanChainObject: a vector at 0x04, a vector at 0x1c, a word at 0x68, the Wanwan it was set up from at
// 0xa0, an WanwanChain at 0xa4 and a word at 0xf4.
typedef struct WanwanChainObject {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ Vec3 mPos;
    /* 10 */ u8 mUnk_10[0xc];
    /* 1c */ Vec3 mUnk_1c;
    /* 28 */ u8 mUnk_28[0x40];
    /* 68 */ s32 mUnk_68;
    /* 6c */ u8 mUnk_6c[0x34];
    /* a0 */ Wanwan *mWanwan;
    /* a4 */ WanwanChain mChain;
    /* f0 */ u8 mUnk_f0[4];
    /* f4 */ BOOL mHasKui;
} WanwanChainObject;

extern const u16 data_021583d4;

void ResetWanwanChainPoints(WanwanChainObject *chainObject);
void CreateWanwanChainAndWanwanKui(void);
void InitWanwanChainObject(WanwanChainObject *chainObject, void *unused, Wanwan *wanwan);
void UpdateWanwanChainPoints(WanwanChain *chain, Vec3 *endPoint, Vec3 *unused);
void DrawWanwanChainLinks(WanwanChain *chain, Unk020e6488 *model, s32 unused, u16 e);
void DrawWanwanChainKui(WanwanChain *chain, Unk020e6488 *model, Vec3 *position, s32 unused, u16 e);
