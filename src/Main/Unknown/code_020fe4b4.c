#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/code_0205a548.h"
#include "Main/Unknown/code_0205a92c.h"
#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f36a0.h"
#include "Main/Unknown/code_020f8000.h"
#include "Main/Unknown/code_020ff344.h"
#include "code_02146d78.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_020f813c.h"
#include "Main/Unknown/code_021053e4.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_020f2d98.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_0205a000.h"
#include "01/code_02187d14.h" // data_0217c600

#pragma thumb off

u8 *func_020ff2b0(u8 *cursor, ItemFBox *fbox, void *toData) {
    u8 *nextCursor;

    if (fbox != NULL && toData != NULL) {
        func_020ff1b8(fbox->mThrownForward, &fbox->mUnk_000.mItemObject.mVelocity.y);
    }
    nextCursor = CopyItemObjectData(cursor, fbox, toData);
    if (fbox != NULL && toData == NULL) {
        func_020ff1a0(fbox->mUnk_000.mItemObject.mVelocity.y, &fbox->mThrownForward);
    }
    if (fbox != NULL && toData != NULL) {
        return func_020fe8ac(fbox->mUnk_000.mItemObject.mKind);
    }
    return nextCursor;
}

void InitItemFBoxFromData(ItemFBox *fbox) {
    func_020f8e78(fbox);
    StartItemObjectBouncing(&fbox->mUnk_000, 0);
    if ((fbox->mUnk_000.mItemObject.mFlags & 0x10000000) == 0) {
        return;
    }
    if (fbox->mThrownForward == 0) {
        return;
    }
    StartSound(&fbox->mUnk_000.mItemObject.mSoundSource, 0xda, 0x7f, 0);
}

#pragma thumb on

void func_020ff1d8(void) {
    Vec3 axis;
    ItemPool *pool;
    ItemFBox *fbox;
    ItemObject **objectCursor;
    s32 objectCount;
    s32 index;

    if (gItemInfos[3].mEnabled == FALSE) {
        return;
    }
    axis = data_0216c734;
    MTX_RotAxis33(&data_0217c600, &axis, 0xb50, 0xb50);
    pool = &gItemPools[7];
    objectCursor = pool->mObjects;
    objectCount = pool->mObjectCount;
    for (index = 0; index < objectCount; index++) {
        fbox = (ItemFBox *) objectCursor[0];
        fbox->mPooledMapObject = (PooledMapObject *) AllocPooledMapObject();
        fbox->mPooledMapObject->mUnk_fc = &fbox->mUnk_000.mItemObject.mPos;
        objectCursor++;
    }
    pool->mUnk_40 = 1;
}

#pragma thumb off

void func_020ff1b8(s32 flag, s32 *word) {
    if (flag != 0) {
        *word |= 0x200;
    } else {
        *word &= ~0x200;
    }
}

void func_020ff1a0(s32 word, s32 *flag) {
    if (word & 0x200) {
        *flag = 1;
    } else {
        *flag = 0;
    }
}

s32 ComputeItemObjectId(ItemObject *item) {
    return (s16) (((s16) (u16) (item->mUnk_78 & ~0xff00) << 4) | item->mPoolIndex);
}

static inline u8 *func_020ff0b0_inline(u8 *cursor, volatile s32 *value, void *toData, s32 shift) {
    if (toData != NULL) {
        *cursor = *value >> shift;
    } else {
        *value = *(s8 *) cursor << shift;
    }
    return cursor + 1;
}

u8 *CopyItemPrevPosOffset(u8 *cursor, Vec3 *position, Vec3 *prevPosition, void *toData) {
    volatile s32 offset[3];

    if (prevPosition != NULL) {
        if (toData != NULL) {
            VEC_Subtract(prevPosition, position, (Vec3 *) offset);
        }
        cursor = func_020ff0b0_inline(cursor, &offset[0], toData, 10);
        cursor = func_020ff0b0_inline(cursor, &offset[1], toData, 9);
        cursor = func_020ff0b0_inline(cursor, &offset[2], toData, 10);
        if (toData == NULL) {
            VEC_Add((Vec3 *) offset, position, prevPosition);
        }
    } else {
        cursor++;
        cursor = (u8 *) cursor + 1;
        cursor++;
    }
    return cursor;
}

u8 *CopyItemPointLinkIndex(u8 *cursor, void *pointLink, void *toData) {
    volatile u8 pointLinkIndex;

    if (pointLink != NULL) {
        if (toData != NULL) {
            pointLinkIndex = GetItemPointLinkIndex(pointLink);
        }
        if (toData != NULL) {
            *(u8 *) cursor = pointLinkIndex;
        } else {
            pointLinkIndex = *(u8 *) cursor;
        }
        cursor++;
        if (toData == NULL) {
            SetItemPointLinkRefFromIndex(pointLinkIndex, pointLink);
        }
    } else {
        cursor++;
    }
    return cursor;
}

u8 *func_020fefe8(u8 *cursor, s32 *valueSlot, void *toData) {
    volatile s32 value;

    if (valueSlot != NULL) {
        if (toData != NULL) {
            value = *valueSlot;
        }
        if (toData != NULL) {
            *(u8 *) cursor = value >> 9;
        } else {
            value = *(s8 *) cursor << 9;
        }
        cursor++;
        if (toData == NULL) {
            *valueSlot = value;
        }
    } else {
        cursor++;
    }
    return cursor;
}

static inline u8 *func_020fecdc_inline(u8 *cursor, s16 *valueSlot, void *toData) {
    volatile u8 byteValue;
    u8 *nextCursor;

    if (valueSlot != NULL) {
        if (toData != NULL) {
            byteValue = *valueSlot;
        }
        if (toData != NULL) {
            *cursor = byteValue;
        } else {
            byteValue = *cursor;
        }
        nextCursor = cursor + 1;
        if (toData == NULL) {
            *valueSlot = byteValue;
        }
        return nextCursor;
    }
    return cursor + 1;
}

static inline u8 *func_020fecdc_inline2(u8 *cursor, u32 *valueSlot, void *toData) {
    volatile u16 halfword;

    if (valueSlot != NULL) {
        if (toData != NULL) {
            halfword = *valueSlot >> 12;
        }
        if (toData != NULL) {
            *(u16 *) cursor = halfword;
        } else {
            halfword = *(u16 *) cursor;
        }
        if (toData == NULL) {
            *valueSlot = halfword << 12;
        }
        return cursor + 2;
    }
    return cursor + 2;
}

static inline u8 *func_020fecdc_inline3(u8 *cursor, s32 *valueSlot, void *toData) {
    if (valueSlot != NULL) {
        if (toData != NULL) {
            *(s16 *) cursor = *valueSlot >> 9;
        } else {
            *valueSlot = *(s16 *) cursor << 9;
        }
    }
    return cursor + 2;
}

static inline u8 *func_020fecdc_inline4(u8 *cursor, s32 *valueSlot, void *toData, s32 shift) {
    if (valueSlot != NULL) {
        if (toData != NULL) {
            *cursor = *valueSlot >> shift;
        } else {
            *valueSlot = *(s8 *) cursor << shift;
        }
    }
    return cursor + 1;
}

u8 *CopyItemObjectData(u8 *cursor, void *object, void *toData) {
    ItemObject *item;
    u16 *p;

    item = object;

    if (object != NULL) {
        if (toData != NULL) {
            cursor = gItemDataBuffer;
        }
        cursor++;
    }
    cursor = func_020fecdc_inline(cursor, object != NULL ? &item->mId : 0, toData);
    cursor = func_020fecdc_inline2(cursor, object != NULL ? &item->mFlags : 0, toData);
    cursor = func_020fecdc_inline3(
        cursor, (object != NULL ? &item->mPos : 0) != NULL ? &(object != NULL ? &item->mPos : 0)->x : 0, toData);
    cursor = func_020fecdc_inline3(
        cursor, (object != NULL ? &item->mPos : 0) != NULL ? &(object != NULL ? &item->mPos : 0)->y : 0, toData);
    cursor = func_020fecdc_inline3(
        cursor, (object != NULL ? &item->mPos : 0) != NULL ? &(object != NULL ? &item->mPos : 0)->z : 0, toData);
    cursor =
        CopyItemPrevPosOffset(cursor, object != NULL ? &item->mPos : 0, object != NULL ? &item->mPrevPos : 0, toData);
    cursor = func_020fecdc_inline4(
        cursor, (object != NULL ? &item->mVelocity : 0) != NULL ? &(object != NULL ? &item->mVelocity : 0)->x : 0,
        toData, 10);
    cursor = func_020fecdc_inline4(
        cursor, (object != NULL ? &item->mVelocity : 0) != NULL ? &(object != NULL ? &item->mVelocity : 0)->y : 0,
        toData, 9);
    cursor = func_020fecdc_inline4(
        cursor, (object != NULL ? &item->mVelocity : 0) != NULL ? &(object != NULL ? &item->mVelocity : 0)->z : 0,
        toData, 10);
    p = object != NULL ? &item->mUnk_78 : 0;
    if (p != NULL) {
        if (toData != NULL) {
            *(u16 *) cursor = *p;
        } else {
            *p = *(u16 *) cursor;
        }
    }
    return cursor + 2;
}

void func_020fec30(void) {
    u32 index;
    s32 available;
    u32 nextIndex;
    ItemDataRecord *record;

    index = gItemDataQueueUsedHead[0];
    if (index == 0xff) {
        return;
    }
    do {
        available = data_0217aa14->mUnk_724;
        nextIndex = gItemDataQueueLinks[index][0];
        if (available < gItemDataQueueLinks[index][1]) {
            return;
        }
        if (func_0205ad44() == FALSE) {
            return;
        }
        gItemDataQueueUsedHead[0] = nextIndex;
        gItemDataQueueLinks[index][0] = gItemDataQueueFreeHead[0];
        gItemDataQueueFreeHead[0] = index;
        record = &gItemDataQueue[index];
        func_0205a858(record->mKind, record->mUnk_18, record, gItemDataQueueLinks[index][1]);
        index = nextIndex;
    } while (nextIndex != 0xff);
}

void func_020feb44(void) {
    u32 raceUpdateFrames;
    u32 index;
    u32 previousIndex;
    u32 nextIndex;
    u32 countdown;
    u32 freeHead;
    ItemDataRecord *record;

    raceUpdateFrames = GetRaceUpdateFrames();
    index = gItemDataDelayedUsedHead[0];
    previousIndex = 0xff;
    while (index != 0xff) {
        countdown = gItemDataDelayedLinks[index][1];
        nextIndex = gItemDataDelayedLinks[index][0];
        gItemDataDelayedLinks[index][1]--;
        if (countdown == 0) {
            freeHead = gItemDataDelayedFreeHead[0];
            gItemDataDelayedLinks[index][0] = freeHead;
            gItemDataDelayedFreeHead[0] = index;
            if (previousIndex == 0xff) {
                gItemDataDelayedUsedHead[0] = nextIndex;
            } else {
                gItemDataDelayedLinks[previousIndex][0] = nextIndex;
            }
            record = &gItemDataDelayed[index];
            if (record->mRaceUpdateFramesStamp == 0 || (record->mRaceUpdateFramesStamp + 0x100) >= raceUpdateFrames) {
                u32 k = *(vu32 *) &record->mKind;
                func_020f0758(gItemPools + k, record->mUnk_18, 0, (u8 *) record, record->mRaceUpdateFramesStamp);
            }
        } else {
            previousIndex = index;
        }
        index = nextIndex;
    }
}

void func_020fea84(u32 kind, u32 messageKind, void *packet, u8 size) {
    u32 index;
    ItemDataRecord *record;

    index = gItemDataQueueFreeHead[0];
    if (index == 0xff) {
        return;
    }
    record = &gItemDataQueue[index];
    record->mKind = kind;
    record->mUnk_18 = messageKind;
    MI_CpuCopy8(packet, record, size);
    gItemDataQueueFreeHead[0] = gItemDataQueueLinks[index][0];
    if (gItemDataQueueUsedHead[0] == 0xff) {
        gItemDataQueueUsedHead[0] = index;
    } else {
        u32 walkIndex;
        u8 nextIndex;

        walkIndex = gItemDataQueueUsedHead[0];
        nextIndex = gItemDataQueueLinks[walkIndex][0];
        while (nextIndex != 0xff) {
            walkIndex = nextIndex;
            nextIndex = gItemDataQueueLinks[walkIndex][0];
        }
        gItemDataQueueLinks[walkIndex][0] = index;
    }
    gItemDataQueueLinks[index][0] = 0xff;
    gItemDataQueueLinks[index][1] = size;
}

void func_020fe9d0(u32 kind, u32 messageKind, s32 frameDifference, void *packet, u32 frameStamp) {
    u32 index;
    ItemDataRecord *record;

    index = gItemDataDelayedFreeHead[0];
    if (index == 0xff) {
        return;
    }
    record = &gItemDataDelayed[index];
    record->mKind = kind;
    record->mUnk_18 = messageKind;
    record->mRaceUpdateFramesStamp = frameStamp;
    MI_CpuCopy8(packet, record, 0x14);
    gItemDataDelayedFreeHead[0] = gItemDataDelayedLinks[index][0];
    gItemDataDelayedLinks[index][0] = gItemDataDelayedUsedHead[0];
    if (frameStamp != 0) {
        gItemDataDelayedLinks[index][1] = 4;
    } else {
        gItemDataDelayedLinks[index][1] = -frameDifference;
    }
    gItemDataDelayedUsedHead[0] = index;
}

u8 *func_020fe958(u32 kind) {
    s32 available;

    gItemDataBuffer[0] = GetRaceUpdateFrames();
    available = data_0217aa14->mUnk_724;
    if (available >= 1 && func_0205ad44() != FALSE) {
        func_0205a858(kind, 0, gItemDataBuffer, 1);
    } else {
        func_020fea84(kind, 0, gItemDataBuffer, 1);
    }
    return gItemDataBuffer;
}

u8 *func_020fe8ac(u32 kind) {
    u32 dataSize;
    s32 available;

    dataSize = gItemKinds[kind].mDataSize & 0xff;
    gItemDataBuffer[0] = GetRaceUpdateFrames();
    available = data_0217aa14->mUnk_724;
    if (available >= (u8) (dataSize + 1) && func_0205ad44() != FALSE) {
        func_0205a858(kind, 0, gItemDataBuffer, dataSize + 1);
    } else {
        func_020fea84(kind, 0, gItemDataBuffer, dataSize + 1);
    }
    return gItemDataBuffer;
}

u8 *func_020fe828(u32 kind) {
    s32 available;

    gItemDataBuffer[1] = 0xff;
    gItemDataBuffer[0] = GetRaceUpdateFrames();
    available = data_0217aa14->mUnk_724;
    if (available >= 2 && func_0205ad44() != FALSE) {
        func_0205a858(kind, 0, gItemDataBuffer, 2);
    } else {
        func_020fea84(kind, 0, gItemDataBuffer, 2);
    }
    return gItemDataBuffer;
}

u8 *func_020fe7a0(u32 kind, u32 b, u32 c, u32 itemId) {
    s32 available;

    gItemDataBuffer[1] = itemId;
    gItemDataBuffer[2] = b | (c << 4);
    gItemDataBuffer[0] = GetRaceUpdateFrames();
    available = data_0217aa14->mUnk_724;
    if (available >= 3 && func_0205ad44() != FALSE) {
        func_0205a858(kind, 2, gItemDataBuffer, 3);
    } else {
        func_020fea84(kind, 2, gItemDataBuffer, 3);
    }
    return gItemDataBuffer;
}

u8 *func_020fe71c(u32 kind, u32 kartIndex, u32 itemId) {
    s32 available;

    gItemDataBuffer[1] = itemId;
    gItemDataBuffer[2] = kartIndex;
    gItemDataBuffer[0] = GetRaceUpdateFrames();
    available = data_0217aa14->mUnk_724;
    if (available >= 3 && func_0205ad44() != FALSE) {
        func_0205a858(kind, 3, gItemDataBuffer, 3);
    } else {
        func_020fea84(kind, 3, gItemDataBuffer, 3);
    }
    return gItemDataBuffer;
}

u8 *func_020fe694(u32 kind, u32 itemId, u32 c, u32 d) {
    s32 available;

    gItemDataBuffer[1] = itemId;
    gItemDataBuffer[2] = c;
    gItemDataBuffer[3] = d;
    gItemDataBuffer[0] = GetRaceUpdateFrames();
    available = data_0217aa14->mUnk_724;
    if (available >= 4 && func_0205ad44() != FALSE) {
        func_0205a858(kind, 3, gItemDataBuffer, 4);
    } else {
        func_020fea84(kind, 3, gItemDataBuffer, 4);
    }
    return gItemDataBuffer;
}

void func_020fe5b8(u32 kind, u32 messageKind, u8 *packet, u32 kartIndex) {
    s8 frameDifference;

    frameDifference = (u8) GetRaceUpdateFrames() - packet[0];
    if (frameDifference >= 0) {
        func_020f0758(gItemPools + kind, messageKind, frameDifference, packet, 0);
    } else {
        func_020fe9d0(kind, messageKind, frameDifference, packet, 0);
    }
    if (kind != 0xb) {
        return;
    }
    if (messageKind != 0) {
        return;
    }
    if (packet[1] == 0xff) {
        return;
    }
    SetActiveItem(&gKartItems[(u16) kartIndex], 0x10);
}

void func_020fe56c(u32 kind, u32 messageKind, u32 frameDifference, void *packet, u32 frameStamp) {
    u32 storedFrameStamp;

    storedFrameStamp = frameStamp;
    if (storedFrameStamp == 0) {
        storedFrameStamp = GetRaceUpdateFrames();
    }
    func_020fe9d0(kind, messageKind, frameDifference, packet, storedFrameStamp);
}

void *func_020fe4c0(void *cursor, void *object, s32 toData) {
    ItemObject *item;
    u8 *nextCursor;
    s32 kind;
    s32 available;

    item = object;
    nextCursor = CopyItemObjectData(cursor, object, (void *) toData);
    if (object == NULL) {
        return nextCursor;
    }
    if (toData == 0) {
        return nextCursor;
    }
    kind = item->mKind;
    gItemDataBuffer[0] = GetRaceUpdateFrames();
    available = data_0217aa14->mUnk_724;
    if (available >= 0x12 && func_0205ad44() != FALSE) {
        func_0205a858(kind, 1, gItemDataBuffer, 0x12);
    } else {
        func_020fea84(kind, 1, gItemDataBuffer, 0x12);
    }
    return gItemDataBuffer;
}

void func_020fe4b4(void *object) {
    func_020f8e78(object);
}
