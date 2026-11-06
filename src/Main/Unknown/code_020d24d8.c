#include "Main/Unknown/code_020d24d8.h"
#include "Main/Unknown/code_02024974.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02024000.h"

void func_020d2668(MapObject *b, SoundSource *c, s32 d, s32 e) {
    s32 a;
    a = b->mKindData->mUnk_24;
    if (a == -1) {
        return;
    }
    if (b->mDistanceSquaredAndFlags & 0x40000000) {
        return;
    }
    if (b->mSound != NULL) {
        func_02024a28(&b->mSound->mSoundSource, a, e, d);
    } else {
        func_02024a28(c, a, e, d);
    }
}

void func_020d2600(s32 c, Vec3 *d, s32 e) {
    s32 a;
    Unk0210b7a8 b;
    a = func_020d4ef4(d);
    if (a >= (e == 2 ? gSoundFalloffs[2].mUnk_20 : gSoundFalloffs[4].mUnk_20)) {
        return;
    }
    b.mUnk_00 = c;
    b.mUnk_04 = d;
    b.mUnk_08 = e;
    b.mUnk_0c = a;
    func_0210b7a8(&b);
}

void func_020d2584(MapObject *b, s32 c) {
    s32 a;
    b->mExtent.y = (s64) c * b->mScale.y >> 12;
    if (b->mCollisionSlotIndex < 0) {
        return;
    }
    switch (b->mKindData->mUnk_08) {
        case 3:
        case 4:
        case 5:
            a = VEC_Mag(&b->mExtent);
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

s32 func_020d252c(MapObject *a) {
    switch (a->mKindData->mUnk_08) {
        case 3:
        case 4:
        case 5:
            return VEC_Mag(&a->mExtent);
        case 0:
        case 1:
        case 2:
        default:
            return a->mExtent.x;
    }
}

void func_020d24d8(MapObject *b, s32 c) {
    s32 a;
    b->mDrawDistance = c;
    if (data_021759c0->mUnk_00c == 3) {
        b->mDrawDistance = 0x270f000;
        return;
    }
    a = gCourseMap->mSettings->mMapObjectDrawDistanceMax;
    if (a == 0) {
        return;
    }
    if (b->mDrawDistance > a) {
        b->mDrawDistance = a;
    }
}
