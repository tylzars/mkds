#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f1d70.h"

// Element of gItemPools[2], [3], [7], [8] and [9] up to 0x130: the word at 0x12c that AdvanceBouncingItem,
// InitBouncingItem and ThrowBouncingItem use after the shared part.
typedef struct BouncingItemObject {
    /* 000 */ ItemObject mItemObject;
    /* 12c */ s32 mBouncesRemaining;
} BouncingItemObject;

void BounceItemObject(ItemObject *item, Vec3 *b, Vec3 *awayDirection);
void AdvanceBouncingItem(BouncingItemObject *item, s32 gravity, s32 velocityFactor, s32 reflectFactor, u32 *e);
void InitBouncingItem(BouncingItemObject *item, s32 bounceCount, Vec3 *velocity);
void ThrowBouncingItem(BouncingItemObject *item, ItemInUse *itemInUse, s32 bounceCount, s32 throwForward,
                       s32 forwardSpeed, s32 forwardUpSpeed, s32 backwardUpSpeed);
void InitItemPointLinkDirections(void);
