#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d50ec.h"

#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0210cf9c.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_0210c000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020f9334.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_02109038.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_020e337c.h"

BOOL func_020f9290(void *itemParam, Vec3 *normal) {
    ItemObject *item = itemParam;
    if ((item->mFlags & 0x2000000) != 0 && Vec3DotUnrounded(normal, &item->mUnk_108) < 0 && (item->mFlags & 8) == 0) {
        func_020f6fc4(item, 1);
        return TRUE;
    }
    return FALSE;
}

void func_020f91fc(void *itemParam, s32 soundId) {
    ItemObject *item = itemParam;
    Unk0210b7a8 request;

    if (soundId == 1) {
        return;
    }
    if ((s32) (item->mDistanceSquaredAndFlags & ~0xc000001f) >= gSoundFalloffs[1].mUnk_20) {
        return;
    }
    if (soundId == 1) {
        return;
    }
    request = data_0216c698;
    request.mUnk_04 = &item->mPos;
    request.mUnk_00 = soundId;
    request.mUnk_0c = item->mDistanceSquaredAndFlags & ~0xc000001f;
    func_0210b7a8(&request);
}

BOOL func_020f91e0(ItemObject *itemParam) {
    ItemObject *item = itemParam;

    return item->mScale.z >= 0xccd;
}

BOOL IsItemObjectFartherFromCameraThan(ItemObject *item, s32 distance) {
    return (s32) (item->mDistanceSquaredAndFlags & ~0xc000001f) > distance * distance;
}

BOOL func_020f9160(ItemObject *c) {
    BOOL a;
    BOOL b;

    a = FALSE;
    if ((c->mFlags & 0x10000) == 0) {
        a = TRUE;
    }
    if (a != FALSE && (s32) (c->mDistanceSquaredAndFlags & ~0xc000001f) <= 0x3d0900) {
        b = TRUE;
    } else {
        b = FALSE;
    }
    if (b == FALSE && (s32) (c->mDistanceSquaredAndFlags & ~0xc000001f) > 0x3d090) {
        return TRUE;
    }
    return FALSE;
}

void func_020f9114(void *itemParam) {
    ItemObject *item = itemParam;
    enum { K0 } kind = item->mKind;

    func_02109038(item, gItemKinds[kind].mUnk_a0, &item->mPos);
    SetSoundSourceEnabled(&item->mSoundSource, 1);
    item->mFlags |= 0x400000;
}

void func_020f90dc(ItemObject *itemParam) {
    ItemObject *item = itemParam;
    if ((item->mFlags & 0x400000) == 0) {
        return;
    }
    func_02109054(&item->mSoundSource);
    item->mSoundSource.mUnk_30 = NULL;
    item->mFlags &= ~0x400000;
}

void func_020f90bc(ItemObject *itemParam) {
    ItemObject *item = itemParam;

    item->mSoundSource.mDistanceSquared = item->mDistanceSquaredAndFlags & ~0xc000001f;
    func_020d4e28(item, &item->mPos, item->mDistanceSquaredAndFlags);
}

void ResetItemObjectFromData(ItemObject *itemParam, s32 kind, void *buffer, s32 d) {
    ItemObject *item = itemParam;
    void *(*copyData)(void *, void *, s32);

    copyData = d != 0 ? func_020fe4c0 : gItemKinds[kind].mCopyData;
    ResetItemObject(item, kind);
    copyData(buffer, item, 0);
    item->mFlags &= ~0x400000;
    item->mFlags |= 0x10000000;
}

void func_020f8e78(void *itemParam) {
    ItemObject *item = itemParam;
    ItemKind *kindInfo;
    BOOL hasCollisionSlot;
    s32 kindRadius;
    enum { K0 } kind;
    void (*advance)(struct ItemObject *);

    item->mScale.z = 0xccd;
    kind = item->mKind;
    item->mFlags |= 0x40;
    item->mScale.y = item->mScale.z;
    item->mScale.x = item->mScale.y;
    kindInfo = &gItemKinds[kind];
    kindRadius = kindInfo->mUnk_6c;
    item->mUnk_dc = ((s64) item->mScale.y * kindInfo->mUnk_64) >> 12;
    item->mRadius = ((s64) item->mScale.y * kindRadius) >> 12;
    SetCollisionSlotRadius(item->mCollisionSlotIndex, item->mRadius + 0xa000);
    InitCourseColorBlend(item->mColorBlend.mUnk_00, 1);
    item->mUnk_90 = NULL;
    item->mNormal = data_02159ca0;
    item->mCollisionBits = 0;
    item->mUnk_100 = 0;
    item->mUnk_104->mUnk_00 = NULL;
    item->mUnk_108.x = 0;
    item->mUnk_108.y = 0;
    item->mUnk_108.z = 0;
    item->mUnk_114 = 5;
    item->mUnk_116 = 0;
    item->mUnk_118 = 0;
    item->mUnk_11a = 0;
    item->mAgeFrames = 1;
    if ((item->mFlags & 0x400000) == 0) {
        kind = item->mKind;
        func_02109038(item, gItemKinds[kind].mUnk_a0, &item->mPos);
        SetSoundSourceEnabled(&item->mSoundSource, 1);
        item->mFlags |= 0x400000;
    }
    kind = item->mKind;
    advance = gItemKinds[kind].mAdvance;
    if ((item->mFlags & 0x180000) == 0) {
        item->mAdvance = advance;
    }
    if ((item->mUnk_78 & 0xf00) != 0) {
        return;
    }
    kind = item->mKind;
    if (gItemKinds[kind].mUnk_54 != 0) {
        return;
    }
    hasCollisionSlot = item->mCollisionSlotIndex != -1;
    if (hasCollisionSlot != FALSE) {
        return;
    }
    if (hasCollisionSlot != FALSE) {
        return;
    }
    item->mCollisionSlotIndex = CreateCollisionSlot(&item->mPos, item->mRadius + 0xa000, 0x4000, item);
}
