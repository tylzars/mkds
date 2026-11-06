#include "Main/Unknown/code_020d278c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/code_0210cf9c.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02147cd8.h"

void SetMapObjectScale(MapObject *d, Vec3 *e) {
    s32 a;
    MapObjectKindData *b;
    s32 c;
    d->mScale.x = e->x;
    d->mScale.y = e->y;
    d->mScale.z = e->z;
    d->mExtent.x = (s64) d->mKindData->mUnk_0c * d->mScale.x >> 12;
    if (d->mCollisionSlotIndex >= 0) {
        switch (d->mKindData->mUnk_08) {
            case 3:
            case 4:
            case 5:
                a = Vec3Length(&d->mExtent);
                break;
            case 0:
            case 1:
            case 2:
            default:
                a = d->mExtent.x;
                break;
        }
        func_020d5148(d->mCollisionSlotIndex, a);
    }
    d->mExtent.y = (s64) d->mKindData->mUnk_10 * d->mScale.y >> 12;
    if (d->mCollisionSlotIndex >= 0) {
        switch (d->mKindData->mUnk_08) {
            case 3:
            case 4:
            case 5:
                a = Vec3Length(&d->mExtent);
                break;
            case 0:
            case 1:
            case 2:
            default:
                a = d->mExtent.x;
                break;
        }
        func_020d5148(d->mCollisionSlotIndex, a);
    }
    d->mExtent.z = (s64) d->mKindData->mUnk_14 * d->mScale.z >> 12;
    if (d->mCollisionSlotIndex >= 0) {
        switch (d->mKindData->mUnk_08) {
            case 3:
            case 4:
            case 5:
                a = Vec3Length(&d->mExtent);
                break;
            case 0:
            case 1:
            case 2:
            default:
                a = d->mExtent.x;
                break;
        }
        func_020d5148(d->mCollisionSlotIndex, a);
    }
    a = d->mScale.x;
    b = d->mKindData;
    c = b->mUnk_2c;
    if (a < d->mScale.y) {
        a = d->mScale.y;
    }
    if (a < d->mScale.z) {
        a = d->mScale.z;
    }
    d->mViewRadius = (s64) c * a >> 12;
}

void func_020d2950(MapObject *b, s32 c) {
    s32 a;
    b->mExtent.x = (s64) c * b->mScale.x >> 12;
    if (b->mCollisionSlotIndex < 0) {
        return;
    }
    switch (b->mKindData->mUnk_08) {
        case 3:
        case 4:
        case 5:
            a = Vec3Length(&b->mExtent);
            break;
        case 0:
        case 1:
        case 2:
        default:
            a = b->mExtent.x;
            break;
    }
    func_020d5148(b->mCollisionSlotIndex, a);
}

void CreateMapObjectSoundSourceFalloff2(MapObject *a) {
    a->mSound = HeapAlloc(GetHeap(func_020364e8()), 0x44);
    InitSoundSource(&a->mSound->mSoundSource, 2, &a->mPos);
    a->mFarDistanceSquared = gSoundFalloffs[2].mUnk_20;
    func_0210cf9c(&a->mSound->mSoundSource, 0);
    if (a->mSound->mSoundSource.mUnk_34 & 1) {
        func_0210cfbc(&a->mSound->mSoundSource, 2, 1);
    }
}

Unk0210b7ec *func_020d286c(MapObject *a) {
    a->mSound = HeapAlloc(GetHeap(func_020364e8()), 0x60);
    InitSoundSource(&a->mSound->mSoundSource, 2, &a->mPos);
    a->mFarDistanceSquared = gSoundFalloffs[2].mUnk_20;
    func_0210cf9c(&a->mSound->mSoundSource, 0);
    if (a->mSound->mSoundSource.mUnk_34 & 1) {
        func_0210cfbc(&a->mSound->mSoundSource, 2, 1);
    }
    return &a->mSound->mUnk_44;
}

void CreateMapObjectSoundSourceFalloff3(MapObject *a) {
    a->mSound = HeapAlloc(GetHeap(func_020364e8()), 0x44);
    InitSoundSource(&a->mSound->mSoundSource, 3, &a->mPos);
    a->mFarDistanceSquared = gSoundFalloffs[3].mUnk_20;
    func_0210cf9c(&a->mSound->mSoundSource, 0);
    if (a->mSound->mSoundSource.mUnk_34 & 1) {
        func_0210cfbc(&a->mSound->mSoundSource, 2, 1);
    }
}

void CreateMapObjectSoundSourceFalloff4(MapObject *a) {
    a->mSound = HeapAlloc(GetHeap(func_020364e8()), 0x44);
    InitSoundSource(&a->mSound->mSoundSource, 4, &a->mPos);
    a->mFarDistanceSquared = gSoundFalloffs[4].mUnk_20;
    func_0210cf9c(&a->mSound->mSoundSource, 0);
    if (a->mSound->mSoundSource.mUnk_34 & 1) {
        func_0210cfbc(&a->mSound->mSoundSource, 2, 1);
    }
}
