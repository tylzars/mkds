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

void BounceItemObject(ItemObject *a, Vec3 *b, Vec3 *c);
void AdvanceBouncingItem(BouncingItemObject *a, s32 b, s32 c, s32 d, u32 *e);
void InitBouncingItem(BouncingItemObject *a, s32 b, Vec3 *c);
void ThrowBouncingItem(BouncingItemObject *p, ItemInUse *a, s32 b, s32 c, s32 d, s32 e, s32 f);
void InitItemPointLinkDirections(void);
