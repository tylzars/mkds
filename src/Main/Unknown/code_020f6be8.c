#include "Main/Unknown/code_020f6be8.h"

#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f6be4.h"
#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_020f9c40.h"
#include "code_02147cd8.h"

s32 func_020f7184(ItemObject *item, s32 b, s32 c) {
    Vec3 *velocity = &item->mVelocity;
    ItemKind *kindInfo;
    s32 r;
    enum { K0 } kind;

    if (item->mFlags & 0x80000) {
        return 2;
    }
    if (c == 0 && (item->mFlags & 0x8000000) && !(item->mFlags & 0x10000000) && !(item->mFlags & 0x20000000)) {
        if (item->mUnk_78 & 0xf00) {
            return 2;
        }
        if (b == 0) {
            item->mUnk_78 |= data_02159b6c;
        } else {
            item->mUnk_78 |= data_02159b68;
            FreeItemObjectCollisionSlot((s32) item);
        }
        item->mAdvance = NULL;
        return 1;
    }
    if (b == 0) {
        kind = item->mKind;
        kindInfo = &gItemKinds[kind];
        if (kindInfo->mUnk_34 != NULL) {
            r = kindInfo->mUnk_34(item);
            if (r == 0) {
                return 2;
            }
            if (r == 1) {
                return 0;
            }
        }
    }
    if (b != 0) {
        item->mUnk_108.y = 0x266;
    } else {
        item->mUnk_108.y = 0x333;
        if (!(item->mFlags & 0x8000)) {
            item->mUnk_108.y += (s32) (((s64) VEC_Mag(velocity) * 0x15c) >> 12);
            if (item->mUnk_108.y > 0x5c3) {
                item->mUnk_108.y = 0x5c3;
            }
        }
    }
    kind = item->mKind;
    kindInfo = &gItemKinds[kind];
    if (kindInfo->mUnk_40 == 0) {
        item->mAdvance = func_020f6e58;
    }
    item->mUnk_124 = (void (*)(ItemObject *, Vec3 *, Vec3 *)) func_020f6be4;
    if (item->mUnk_f0.y != 0) {
        Vec3 *normal = &item->mUnk_f0;

        r = Vec3DotUnrounded(velocity, normal);
        if (r < 0x3000) {
            VEC_MultAdd(0x3000 - r, normal, velocity, velocity);
        }
    }
    item->mFlags |= 0x80001;
    FreeItemObjectCollisionSlot((s32) item);
    r = Vec3DotUnrounded(velocity, func_020e6b28());
    if (r > 1) {
        item->mUnk_108.x = 1;
    } else {
        item->mUnk_108.x = 0;
    }
    return 0;
}

void func_020f7104(ItemObject *item, s32 b) {
    s32 result;

    if (!(item->mFlags & 0x8000000)) {
        func_020f7184(item, 0, 0);
        return;
    }
    result = func_020f7184(item, 0, 0);
    if (result != 0) {
        return;
    }
    if (b == 0) {
        return;
    }
    func_020fe7a0(item->mKind, 0, 8, item->mId);
}

void func_020f70f0(ItemObject *item) {
    func_020f7184(item, 0, 1);
}

void func_020f7070(void *objectParam, s32 b) {
    ItemObject *item = objectParam;
    s32 result;

    if (!(item->mFlags & 0x8000000)) {
        func_020f7184(item, 1, 0);
        return;
    }
    result = func_020f7184(item, 1, 0);
    if (result != 0) {
        return;
    }
    if (b == 0) {
        return;
    }
    func_020fe7a0(item->mKind, 1, 8, item->mId);
}

void func_020f705c(ItemObject *item) {
    func_020f7184(item, 1, 1);
}

void func_020f6fc4(void *objectParam, s32 b) {
    ItemObject *item = objectParam;
    s32 result;
    enum { K0 } kind;

    result = func_020f7184(item, 0, 0);
    if (result <= 1) {
        kind = item->mKind;
        func_020f91fc(item, gItemKinds[kind].mUnk_94);
    }
    if (result != 0) {
        return;
    }
    if (!(item->mFlags & 0x8000000)) {
        return;
    }
    if (b == 0) {
        return;
    }
    if (item->mKind == 5) {
        return;
    }
    func_020fe7a0(item->mKind, 2, 8, item->mId);
}

void func_020f6f10(ItemObject *item, s32 b, s32 c) {
    s32 result;
    enum { K0 } kind;

    result = func_020f7184(item, 0, 0);
    if (result <= 1) {
        kind = item->mKind;
        func_020f91fc(item, gItemKinds[kind].mUnk_98);
    }
    if (result != 0) {
        return;
    }
    if (!(item->mFlags & 0x8000000)) {
        return;
    }
    if (b == 0) {
        return;
    }
    if (item->mKind == 5) {
        return;
    }
    func_020fe7a0(item->mKind, 3, c, item->mId);
}

void func_020f6e58(ItemObject *item) {
    Vec3 direction;

    Vec3CrossUnrounded(&item->mUnk_f0, GetViewTransposeMatrixAxis2(), &direction);
    VEC_MultAdd(item->mUnk_108.x != 0 ? item->mUnk_108.y : -item->mUnk_108.y, &direction, &item->mUnk_f0,
                &item->mUnk_f0);
    item->mFlags |= 0x80;
    item->mVelocity.y -= 0x400;
    VEC_Add(&item->mPos, &item->mVelocity, &item->mPos);
    item->mUnk_d8--;
    if (item->mUnk_d8 > 0) {
        return;
    }
    ReleaseItemPoolObject(&gItemPools[item->mKind], item);
}

void func_020f6be8(ItemObject *item, Vec3 *otherPos, Vec3 *otherVelocity, Vec3 *normal) {
    Vec3 away;
    Vec3 relativeVelocity;
    Vec3 *push;
    s32 dot;
    s64 lengthSquared;

    VEC_Subtract(otherVelocity, &item->mVelocity, &relativeVelocity);
    VEC_Subtract(&item->mPos, otherPos, &away);
    dot = VEC_DotProduct(normal, &away);
    away.x -= (s32) (((s64) normal->x * dot) >> 12);
    away.y -= (s32) (((s64) normal->y * dot) >> 12);
    away.z -= (s32) (((s64) normal->z * dot) >> 12);
    lengthSquared = (s64) away.x * away.x + (s64) away.y * away.y + (s64) away.z * away.z;
    if (lengthSquared >= 0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&away, &away);
    }
    if (item->mFlags & 0x8000) {
        VEC_MultAdd(0x666, &relativeVelocity, &item->mVelocity, &item->mVelocity);
        push = data_0217bc4c;
        push->x = ((s64) away.x * 0xccd) >> 12;
        push->y = ((s64) away.y * 0xccd) >> 12;
        push->z = ((s64) away.z * 0xccd) >> 12;
        VEC_Add(&item->mVelocity, data_0217bc4c, &item->mVelocity);
    } else {
        item->mVelocity.x = ((s64) otherVelocity->x * 0x8cd) >> 12;
        item->mVelocity.y = ((s64) otherVelocity->y * 0x8cd) >> 12;
        item->mVelocity.z = ((s64) otherVelocity->z * 0x8cd) >> 12;
        push = data_0217bc4c;
        push->x = ((s64) away.x * 0x1800) >> 12;
        push->y = ((s64) away.y * 0x1800) >> 12;
        push->z = ((s64) away.z * 0x1800) >> 12;
        VEC_Add(&item->mVelocity, data_0217bc4c, &item->mVelocity);
    }
}
