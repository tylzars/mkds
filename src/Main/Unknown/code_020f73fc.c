#include "Main/Unknown/code_020f73fc.h"

#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020f73a4.h"
#include "Main/Unknown/code_020f7c60.h"
#include "Main/Unknown/code_020f7c90.h"
#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_020f9c40.h"
#include "code_02147cd8.h"

void func_020f77f8(ItemObject *itemParam, s32 hitType, Vec3 *otherPos, Vec3 *otherVelocity, MapObject *mapObject) {
    ItemObject *item = itemParam;
    Vec3 offset;
    Vec3 direction;
    Vec3 push;
    s32 i;
    s32 n;
    s32 radius;
    void (*soundCallback)(ItemObject *, s32);

    if (item->mFlags & 0x80000) {
        return;
    }
    i = mapObject ? mapObject->mKindData->mUnk_28 : -1;
    switch (hitType) {
        case 1:
            if (item->mFlags & 0x1000) {
                break;
            }
            VEC_Subtract(&item->mPrevPos, otherPos, &offset);
            if (!(item->mFlags & 0x8000) && (item->mFlags & 0x1000000)) {
                func_020f7c90(item, otherPos, &offset);
                break;
            }
            item->mFlags |= 0x4000000;
            if (Vec3DotUnrounded(&item->mVelocity, &offset) <= 0) {
                if ((s64) offset.x * offset.x + (s64) offset.y * offset.y + (s64) offset.z * offset.z >= 0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&offset, &offset);
                }
                item->mUnk_124(item, otherVelocity, &offset);
                if (item->mFlags & 0x8000) {
                    break;
                }
                radius = item->mRadius;
                if ((s64) (otherPos->x - item->mPos.x) * (otherPos->x - item->mPos.x) +
                        (s64) (otherPos->y - item->mPos.y) * (otherPos->y - item->mPos.y) +
                        (s64) (otherPos->z - item->mPos.z) * (otherPos->z - item->mPos.z) >=
                    (s64) radius * radius) {
                    break;
                }
                item->mPos.x = otherPos->x + (s32) (((s64) radius * offset.x) >> 12);
                item->mPos.z = otherPos->z + (s32) (((s64) radius * offset.z) >> 12);
                break;
            }
            if (item->mFlags & 0x8000) {
                break;
            }
            radius = item->mRadius;
            if ((s64) (otherPos->x - item->mPos.x) * (otherPos->x - item->mPos.x) +
                    (s64) (otherPos->y - item->mPos.y) * (otherPos->y - item->mPos.y) +
                    (s64) (otherPos->z - item->mPos.z) * (otherPos->z - item->mPos.z) >=
                (s64) radius * radius) {
                break;
            }
            if ((s64) offset.x * offset.x + (s64) offset.y * offset.y + (s64) offset.z * offset.z >= 0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&offset, &offset);
            }
            radius = item->mRadius;
            item->mPos.x = otherPos->x + (s32) (((s64) radius * offset.x) >> 12);
            item->mPos.z = otherPos->z + (s32) (((s64) radius * offset.z) >> 12);
            break;
        case 2:
            if (item->mFlags & 0x1000) {
                RemoveItemInUseObject(&(gKartItems)[(u16) (item->mUnk_78 & ~0xff00)].mItemInUse, item);
            }
            n = 0;
            if ((s64) otherVelocity->x * otherVelocity->x + (s64) otherVelocity->y * otherVelocity->y +
                    (s64) otherVelocity->z * otherVelocity->z >=
                0x10) {
                n = Vec3NormalizeAndGetLengthUnchecked(otherVelocity, &direction);
            }
            if (n != 0) {
                func_020f6be8(item, otherPos, otherVelocity, &direction);
            } else {
                VEC_Subtract(&item->mPos, otherPos, &direction);
                if (direction.y < 0) {
                    direction.y = 0;
                }
                if ((s64) direction.x * direction.x + (s64) direction.y * direction.y +
                        (s64) direction.z * direction.z >=
                    0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&direction, &direction);
                }
                push.x = ((s64) direction.x * 0x1800) >> 12;
                push.y = ((s64) direction.y * 0x1800) >> 12;
                push.z = ((s64) direction.z * 0x1800) >> 12;
                func_020f6be8(item, otherPos, &push, &direction);
            }
            if (i == -1 || (item->mFlags & 0x8000000)) {
                func_020f6fc4(item, 1);
            } else {
                n = item->mKind;
                func_020f7104(item, 1);
                if (n == 5 || n == 9) {
                    i = -1;
                }
            }
    }
    if (i == -1) {
        return;
    }
    soundCallback = (item->mFlags & 0x400000) ? (void (*)(ItemObject *, s32)) func_020f7c60
                                              : (void (*)(ItemObject *, s32)) func_020f91fc;
    soundCallback(item, i);
}

void func_020f7658(ItemObject *item, s32 c) {
    BOOL started;
    enum { K0 } kind;

    if (!(item->mFlags & 0x8000000)) {
        if ((item->mFlags & 0x8000000) && !(item->mFlags & 0x10000000) && !(item->mFlags & 0x20000000)) {
            if (item->mUnk_78 & 0xf00) {
                return;
            }
            item->mUnk_78 |= data_02159b74;
            item->mAdvance = NULL;
            return;
        }
        if (item->mFlags & 0x180000) {
            return;
        }
        kind = item->mKind;
        if (gItemKinds[kind].mUnk_40 == 0 && !(item->mFlags & 0x180000)) {
            item->mAdvance = AdvanceItemObjectReleaseTimer;
        }
        item->mFlags |= 0x100002;
        return;
    }
    if ((item->mFlags & 0x8000000) && !(item->mFlags & 0x10000000) && !(item->mFlags & 0x20000000)) {
        if (item->mUnk_78 & 0xf00) {
            started = FALSE;
        } else {
            item->mUnk_78 |= data_02159b74;
            item->mAdvance = NULL;
            started = TRUE;
        }
    } else {
        if (item->mFlags & 0x180000) {
            started = FALSE;
        } else {
            kind = item->mKind;
            if (gItemKinds[kind].mUnk_40 == 0 && !(item->mFlags & 0x180000)) {
                item->mAdvance = AdvanceItemObjectReleaseTimer;
            }
            item->mFlags |= 0x100002;
            started = TRUE;
        }
    }
    if (started == FALSE) {
        return;
    }
    if (c == 0) {
        return;
    }
    func_020fe7a0(item->mKind, 4, 8, item->mId);
}

void StartItemObjectReleaseTimer(ItemObject *item) {
    enum { K0 } kind;

    if (item->mFlags & 0x180000) {
        return;
    }
    kind = item->mKind;
    if (gItemKinds[kind].mUnk_40 == 0 && !(item->mFlags & 0x180000)) {
        item->mAdvance = AdvanceItemObjectReleaseTimer;
    }
    item->mFlags |= 0x100002;
}

void AdvanceItemObjectReleaseTimer(ItemObject *item) {
    if (item->mFlags & 0x8000) {
        AdvanceRestingItemObject(item);
    }
    item->mUnk_d8--;
    if (item->mUnk_d8 <= 0) {
        ReleaseItemPoolObject(&gItemPools[item->mKind], item);
    } else {
        if (item->mUnk_d8 < 0xa) {
            FreeItemObjectCollisionSlot((s32) item);
        }
    }
}

void func_020f7430(ItemObject *item, s32 c) {
    BOOL started;

    if (!(item->mFlags & 0x8000000)) {
        if ((item->mFlags & 0x8000000) && !(item->mFlags & 0x10000000) && !(item->mFlags & 0x20000000)) {
            if (item->mUnk_78 & 0xf00) {
                return;
            }
            item->mUnk_78 |= data_02159b70;
            item->mAdvance = NULL;
            return;
        }
        if (item->mFlags & 0x180000) {
            return;
        }
        if (!(item->mFlags & 0x180000)) {
            item->mAdvance = (void (*)(ItemObject *)) ReleaseItemObjectToItsPool;
        }
        item->mFlags |= 0x100002;
        return;
    }
    if ((item->mFlags & 0x8000000) && !(item->mFlags & 0x10000000) && !(item->mFlags & 0x20000000)) {
        if (item->mUnk_78 & 0xf00) {
            started = FALSE;
        } else {
            item->mUnk_78 |= data_02159b70;
            item->mAdvance = NULL;
            started = TRUE;
        }
    } else {
        if (item->mFlags & 0x180000) {
            started = FALSE;
        } else {
            if (!(item->mFlags & 0x180000)) {
                item->mAdvance = (void (*)(ItemObject *)) ReleaseItemObjectToItsPool;
            }
            item->mFlags |= 0x100002;
            started = TRUE;
        }
    }
    if (started == FALSE) {
        return;
    }
    if (c == 0) {
        return;
    }
    func_020fe7a0(item->mKind, 5, 8, item->mId);
}

void StartItemObjectRelease(ItemObject *item) {
    if (item->mFlags & 0x180000) {
        return;
    }
    if (!(item->mFlags & 0x180000)) {
        item->mAdvance = (void (*)(ItemObject *)) ReleaseItemObjectToItsPool;
    }
    item->mFlags |= 0x100002;
}
