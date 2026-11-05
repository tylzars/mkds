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
    d->mUnk_58.x = (s64) d->mKindData->mUnk_0c * d->mScale.x >> 12;
    if (d->mUnk_64 >= 0) {
        switch (d->mKindData->mUnk_08) {
            case 3:
            case 4:
            case 5:
                a = Vec3Length(&d->mUnk_58);
                break;
            case 0:
            case 1:
            case 2:
            default:
                a = d->mUnk_58.x;
                break;
        }
        func_020d5148(d->mUnk_64, a);
    }
    d->mUnk_58.y = (s64) d->mKindData->mUnk_10 * d->mScale.y >> 12;
    if (d->mUnk_64 >= 0) {
        switch (d->mKindData->mUnk_08) {
            case 3:
            case 4:
            case 5:
                a = Vec3Length(&d->mUnk_58);
                break;
            case 0:
            case 1:
            case 2:
            default:
                a = d->mUnk_58.x;
                break;
        }
        func_020d5148(d->mUnk_64, a);
    }
    d->mUnk_58.z = (s64) d->mKindData->mUnk_14 * d->mScale.z >> 12;
    if (d->mUnk_64 >= 0) {
        switch (d->mKindData->mUnk_08) {
            case 3:
            case 4:
            case 5:
                a = Vec3Length(&d->mUnk_58);
                break;
            case 0:
            case 1:
            case 2:
            default:
                a = d->mUnk_58.x;
                break;
        }
        func_020d5148(d->mUnk_64, a);
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
    d->mUnk_68 = (s64) c * a >> 12;
}

void func_020d2950(MapObject *b, s32 c) {
    s32 a;
    b->mUnk_58.x = (s64) c * b->mScale.x >> 12;
    if (b->mUnk_64 < 0) {
        return;
    }
    switch (b->mKindData->mUnk_08) {
        case 3:
        case 4:
        case 5:
            a = Vec3Length(&b->mUnk_58);
            break;
        case 0:
        case 1:
        case 2:
        default:
            a = b->mUnk_58.x;
            break;
    }
    func_020d5148(b->mUnk_64, a);
}

void func_020d28e0(MapObject *a) {
    a->mUnk_94 = HeapAlloc(GetHeap(func_020364e8()), 0x44);
    func_02109110(&a->mUnk_94->mUnk_00, 2, &a->mPos);
    a->mUnk_70 = data_0217ca6c[2].mUnk_20;
    func_0210cf9c(&a->mUnk_94->mUnk_00, 0);
    if (a->mUnk_94->mUnk_00.mUnk_34 & 1) {
        func_0210cfbc(&a->mUnk_94->mUnk_00, 2, 1);
    }
}

Unk0210b7ec *func_020d286c(MapObject *a) {
    a->mUnk_94 = HeapAlloc(GetHeap(func_020364e8()), 0x60);
    func_02109110(&a->mUnk_94->mUnk_00, 2, &a->mPos);
    a->mUnk_70 = data_0217ca6c[2].mUnk_20;
    func_0210cf9c(&a->mUnk_94->mUnk_00, 0);
    if (a->mUnk_94->mUnk_00.mUnk_34 & 1) {
        func_0210cfbc(&a->mUnk_94->mUnk_00, 2, 1);
    }
    return &a->mUnk_94->mUnk_44;
}

void func_020d27fc(MapObject *a) {
    a->mUnk_94 = HeapAlloc(GetHeap(func_020364e8()), 0x44);
    func_02109110(&a->mUnk_94->mUnk_00, 3, &a->mPos);
    a->mUnk_70 = data_0217ca6c[3].mUnk_20;
    func_0210cf9c(&a->mUnk_94->mUnk_00, 0);
    if (a->mUnk_94->mUnk_00.mUnk_34 & 1) {
        func_0210cfbc(&a->mUnk_94->mUnk_00, 2, 1);
    }
}

void func_020d278c(MapObject *a) {
    a->mUnk_94 = HeapAlloc(GetHeap(func_020364e8()), 0x44);
    func_02109110(&a->mUnk_94->mUnk_00, 4, &a->mPos);
    a->mUnk_70 = data_0217ca6c[4].mUnk_20;
    func_0210cf9c(&a->mUnk_94->mUnk_00, 0);
    if (a->mUnk_94->mUnk_00.mUnk_34 & 1) {
        func_0210cfbc(&a->mUnk_94->mUnk_00, 2, 1);
    }
}
