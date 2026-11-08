#pragma once

#include "types.h"

typedef struct ItemObject ItemObject;
typedef struct ItemFBox ItemFBox;

// Element of the two tables gItemDataDelayed and gItemDataQueue: 0x14 bytes of
// bytes passed on followed by three words.
typedef struct ItemDataRecord {
    /* 00 */ u8 mData[0x14];
    /* 14 */ u32 mKind;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mRaceUpdateFramesStamp;
} ItemDataRecord;

extern ItemDataRecord gItemDataDelayed[];

extern ItemDataRecord gItemDataQueue[];

u8 *func_020ff2b0(u8 *cursor, ItemFBox *fbox, void *toData);
void InitItemFBoxFromData(ItemFBox *fbox);
void func_020ff1d8(void);
void func_020ff1b8(s32 flag, s32 *word);
void func_020ff1a0(s32 word, s32 *flag);
s32 ComputeItemObjectId(ItemObject *item);
u8 *CopyItemPrevPosOffset(u8 *cursor, Vec3 *position, Vec3 *prevPosition, void *toData);
u8 *CopyItemPointLinkIndex(u8 *cursor, void *pointLink, void *toData);
u8 *func_020fefe8(u8 *cursor, s32 *valueSlot, void *toData);
u8 *CopyItemObjectData(u8 *cursor, void *object, void *toData);
void func_020fec30(void);
void func_020feb44(void);
void func_020fea84(u32 kind, u32 messageKind, void *packet, u8 size);
void func_020fe9d0(u32 kind, u32 messageKind, s32 frameDifference, void *packet, u32 frameStamp);
u8 *func_020fe958(u32 kind);
u8 *func_020fe8ac(u32 kind);
u8 *func_020fe828(u32 kind);
u8 *func_020fe7a0(u32 kind, u32 b, u32 c, u32 itemId);
u8 *func_020fe71c(u32 kind, u32 kartIndex, u32 itemId);
u8 *func_020fe694(u32 kind, u32 itemId, u32 c, u32 d);
void func_020fe5b8(u32 kind, u32 messageKind, u8 *packet, u32 kartIndex);
void func_020fe56c(u32 kind, u32 messageKind, u32 frameDifference, void *packet, u32 frameStamp);
void *func_020fe4c0(void *cursor, void *object, s32 toData);
void func_020fe4b4(void *object);
