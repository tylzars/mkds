#pragma once

#include "types.h"
#include "Main/Unknown/code_020f2dac.h" // BouncingItemObject
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_021052fc.h"

struct ModelEffect;

// Object of item kind 9, element of gItemPools[9].
typedef struct ItemBomb {
    /* 000 */ BouncingItemObject mUnk_000;
    /* 130 */ s32 mUnk_130;
    /* 134 */ s32 mUnk_134;
    /* 138 */ struct ModelEffect *mModelEffect;
    /* 13c */ u8 mUnk_13c[0x30];
    /* 16c */ BOOL mUnk_16c;
    /* 170 */ s32 mTimer;
    /* 174 */ s32 mUnk_174;
    /* 178 */ u16 mNearestKartIndex;
    /* 17a */ u8 mUnk_17a[2];
    /* 17c */ s32 mNearestKartDistanceSquared;
    /* 180 */ s32 mUnk_180;
    /* 184 */ u8 mUnk_184[4];
    /* 188 */ s32 mStateFrames;
    /* 18c */ u8 mUnk_18c[6];
    /* 192 */ u16 mState;
    /* 194 */ u16 mNextState;
    /* 196 */ u16 mNextStateRequested;
    /* 198 */ PooledMapObject *mPooledMapObject;
    /* 19c */ s32 mMapObjectOffsetY;
    /* 1a0 */ BOOL mVisible;
} ItemBomb;

void func_020fd83c(ItemBomb *bomb);
int RequestItemBombState2(ItemBomb *bomb);
void DrawItemBomb(ItemBomb *bomb, Vec3 *a, NsbmdModel *model);
void InitItemBombFromData(ItemBomb *bomb);
void *func_020fda50(void *cursor, ItemBomb *bomb, void *toData);
void AdvanceItemBomb(ItemBomb *bomb);
void AdvanceItemBombWithMapObject(ItemBomb *bomb, ItemBomb *bombAlias, PooledMapObject *pooledMapObject);
void ClampItemBombTimerByDistance(ItemBomb *bomb);
void AdvanceItemBombNearestKart(ItemBomb *bomb);
void UpdateItemBombState2(ItemBomb *bomb);
void EnterItemBombState2(ItemBomb *bomb);
void UpdateItemBombState1(ItemBomb *bomb);
