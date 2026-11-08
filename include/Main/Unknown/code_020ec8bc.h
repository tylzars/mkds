#pragma once

#include "types.h"
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_020f36d8.h"

// Element of gItemPools[1] and [5] up to 0x228: after the DirectedItemObject part, the ItemPointLinkRef at 0x168 that
// PickNextItemPointLink fills, the SegmentPoints at 0x170, the words at 0x214 and 0x218 and the ItemPointLinkRef at
// 0x21c.
typedef struct LinkFollowingItemObject {
    /* 000 */ DirectedItemObject mUnk_000;
    /* 168 */ ItemPointLinkRef mTargetLink;
    /* 170 */ SegmentPoints mSegmentPoints;
    /* 214 */ s32 mUnk_214;
    /* 218 */ s32 mUnk_218;
    /* 21c */ ItemPointLinkRef mPreviousLink;
    /* 224 */ s32 mUnk_224;
} LinkFollowingItemObject;

void InitLinkFollowingItem(LinkFollowingItemObject *follower, s32 rampCount, s32 rampWeightPerCount, s32 c,
                           s32 endsOnFirstHit, s32 reverse, u16 targetKartIndex, s32 g);
void AdvanceLinkFollowingItem(LinkFollowingItemObject *follower, s32 targetSpeed, s32 speedEase, s32 targetKartIndex,
                              s32 d);
void func_020ec9c0(LinkFollowingItemObject *follower, s32 targetSpeed, s32 speedEase, s32 targetKartIndex, s32 e);
void func_020ece1c(LinkFollowingItemObject *follower, s32 targetSpeed, s32 targetKartIndex, s32 c);
BOOL func_020ed0f4(LinkFollowingItemObject *follower);
void InitLinkFollowingItemFromInUse(LinkFollowingItemObject *follower, ItemInUse *inUse, s32 rampCount,
                                    s32 rampWeightPerCount, s32 throwForward, s32 d, s32 endsOnFirstHit, s32 baseSpeed,
                                    u16 targetKartIndex, s32 h);
void CreateItemModels(void);
void *CreateItemNsbmd(u8 *modelName, u8 *textureName);
NsbmdModel *CreateItemModel(u8 *modelName, u8 *animationName, u8 *textureName);
void *FindItemFile(u8 *fileName);
