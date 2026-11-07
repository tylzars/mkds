#include "Main/Unknown/code_020ff344.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_021052f0.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020f2dac.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0215a000.h"
#include "Main/Unknown/code_020f73fc.h"
#include "Main/Unknown/code_021053e4.h"
#include "Main/Unknown/code_020ee684.h"
#include "01/code_02187d14.h" // data_0217c600

#pragma thumb on

void CreateDram(void) {
    CreateNsbmd(&gDram, FindCourseMapObjFile(gDramNsbmdName), NULL);
    func_02084968(gDram, 0x3f, 2, 0x294a);
}

void InitDram(Dram *dram, struct CourseMapRow *courseRow) {
    func_02046be8(&dram->mUnk_00.mStateMachine, (UnkFunc *const *) data_0216c740, 6, dram);
    dram->mUnk_b4[0] = courseRow->mUnk_28 * 0x80 / 100;
    dram->mUnk_b4[2] = courseRow->mUnk_30 * 0x80 / 100;
    dram->mUnk_b4[1] = (dram->mUnk_b4[0] + dram->mUnk_b4[2]) / 2;
    dram->mUnk_a2 = courseRow->mUnk_2a;
    dram->mUnk_a0 = courseRow->mUnk_2c;
    dram->mUnk_a4 = courseRow->mUnk_2e;
    dram->mUnk_a6 = 0;
    if (dram->mUnk_a0 != 0) {
        dram->mUnk_b0 = 0x1000 / dram->mUnk_a0;
    } else {
        dram->mUnk_b0 = 0;
    }
    dram->mUnk_ac = 0;
    dram->mUnk_00.mStateMachine.mNextState = 1;
    dram->mUnk_00.mStateMachine.mNextStateRequested = 1;
}

#pragma thumb off

Unk02100004 *func_020ffacc(void) {
    Unk02100004 *p;

    p = GetHeap(GetCurrentHeapCall());
    p = HeapAlloc(p, 0x40);
    *p = data_0215a068;
    return p;
}

BOOL func_020ffabc(u32 kind) {
    return kind == 0xb;
}

#pragma thumb on

void func_020ff97c(Unk020ff97c *object) {
    object->mUnk_a0 = *(MtxFx33 *) &object->mUnk_00.mMatrix;
    object->mUnk_124 = 0;
    object->mUnk_128 = 0;
    object->mUnk_12c = 0;
    object->mUnk_130 = 0;
    object->mUnk_100 = ((s64) object->mUnk_00.mScale.x * 0x190000) >> 12;
    object->mUnk_104 = (s32) (((s64) object->mUnk_00.mScale.y * 0x64000) >> 12) >> 1;
    object->mUnk_108 = ((s64) object->mUnk_00.mScale.z * 0xaf000) >> 12;
    object->mUnk_10c = ((s64) object->mUnk_00.mScale.z * 0xaf000) >> 12;
    object->mUnk_110 = 0;
    object->mUnk_114 = 1;
    object->mUnk_118 = 0;
    object->mUnk_11c = 0;
    object->mUnk_120 = 0x800;
    object->mUnk_e8 = object->mUnk_00.mPos;
    object->mUnk_00.mUnk_10.x = 0;
    object->mUnk_00.mUnk_10.y = 0;
    object->mUnk_00.mUnk_10.z = 0;
    VEC_MultAdd(-object->mUnk_104, &object->mUnk_00.mMatrix.mUnk_00[1], &object->mUnk_00.mPos, &object->mUnk_f4);
    object->mUnk_134 = 0;
    object->mUnk_138 = 0;
    object->mUnk_13c = 1;
    object->mUnk_00.mFlags |= data_0215a030;
}

#pragma thumb off

void SetItemFBoxDrawMatrix(ItemFBox *fbox, MtxFx43 *out) {
    Vec3 *position;

    position = fbox->mUnk_000.mItemObject.mUnk_d0;
    fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[3].x = position->x >> 4;
    fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[3].y = position->y >> 4;
    fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[3].z = position->z >> 4;
    *out = fbox->mUnk_000.mItemObject.mUnk_94;
    MTX_Concat33((const s32 *) &data_0217c600, (const s32 *) out, (s32 *) out);
}

void func_020ff6d8(ItemFBox *fbox, MtxFx43 *out) {
    s32 scaledX, scaledZ;
    Vec3 *position;

    if ((fbox->mUnk_000.mItemObject.mFlags & 0x80000) && func_020b2ec0() == 0) {
        s32 row0Dot, row2Dot;

        row0Dot = ((s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].x * fbox->mUnk_130.x +
                   (s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].z * fbox->mUnk_130.z) >>
                  12;
        scaledX = ((s64) fbox->mUnk_130.x * 0xa4) >> 12;
        row2Dot = ((s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2].x * fbox->mUnk_130.x +
                   (s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2].z * fbox->mUnk_130.z) >>
                  12;
        scaledZ = ((s64) fbox->mUnk_130.z * 0xa4) >> 12;
        fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1].x =
            (s32) (fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1].x + scaledX);
        fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1].z += scaledZ;
        if ((s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1].x * fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1].x +
                (s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1].y *
                    fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1].y +
                (s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1].z *
                    fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1].z >=
            0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1],
                                               &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1]);
        }
        if (row0Dot * row0Dot > row2Dot * row2Dot) {
            fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2].x =
                (s32) (fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2].x - scaledX);
            fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2].z -= scaledZ;
            Vec3CrossUnrounded(&fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1],
                               &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2],
                               &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0]);
            if ((s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].x *
                        fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].x +
                    (s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].y *
                        fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].y +
                    (s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].z *
                        fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].z >=
                0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0],
                                                   &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0]);
            }
            Vec3CrossUnrounded(&fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0],
                               &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1],
                               &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2]);
        } else {
            fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].x -= scaledX;
            fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].z -= scaledZ;
            Vec3CrossUnrounded(&fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0],
                               &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1],
                               &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2]);
            if ((s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2].x *
                        fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2].x +
                    (s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2].y *
                        fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2].y +
                    (s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2].z *
                        fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2].z >=
                0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2],
                                                   &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2]);
            }
            Vec3CrossUnrounded(&fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1],
                               &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2],
                               &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0]);
        }
    }
    position = fbox->mUnk_000.mItemObject.mUnk_d0;
    fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[3].x = position->x >> 4;
    fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[3].y = position->y >> 4;
    fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[3].z = position->z >> 4;
    *out = fbox->mUnk_000.mItemObject.mUnk_94;
}

void ResetItemFBox(ItemFBox *fbox) {
    *(MtxFx33 *) &fbox->mUnk_000.mItemObject.mUnk_94 = *(MtxFx33 *) &data_0217c600;
    func_021053e4(fbox->mPooledMapObject);
    fbox->mPooledMapObject->mUnk_b0 = 2;
    SetPooledMapObjectCallback(fbox->mPooledMapObject, SetItemFBoxDrawMatrix, fbox);
}

void StartItemFBox(ItemFBox *fbox) {
    fbox->mPooledMapObject->mUnk_b0 = 1;
    SetPooledMapObjectCallback(fbox->mPooledMapObject, func_020ff6d8, fbox);
}

void AdvanceItemFBoxInUse(ItemInUse *inUse, ItemFBox *fbox) {
    SetPooledMapObjectFromItem(fbox->mPooledMapObject, fbox->mUnk_000.mItemObject.mUnk_d8,
                               &fbox->mUnk_000.mItemObject.mScale);
}

u32 InitItemFBox(ItemInUse *inUse, ItemFBox *fbox) {
    func_020f9114(fbox);
    fbox->mUnk_000.mItemObject.mUnk_78 |= data_0215a02c;
    MTX_Concat33((const s32 *) &data_0217c600, (const s32 *) &fbox->mUnk_000.mItemObject.mUnk_94,
                 (s32 *) &fbox->mUnk_000.mItemObject.mUnk_94);
    fbox->mUnk_130.x = 0;
    fbox->mUnk_130.y = 0;
    fbox->mUnk_130.z = 0;
    if ((inUse->mKartItems->mFlags & KART_ITEMS_THROW_FORWARD) != 0) {
        ThrowBouncingItem(&fbox->mUnk_000, inUse, 0, 1, 0x4000, 0x3000, 0x59a);
        StartSound(&fbox->mUnk_000.mItemObject.mSoundSource, 0xda, 0x7f, 0);
        fbox->mThrownForward = 1;
        return fbox->mThrownForward;
    }
    ThrowBouncingItem(&fbox->mUnk_000, inUse, 0, 0, 0x4000, 0x3000, 0x59a);
    fbox->mThrownForward = 0;
    return fbox->mThrownForward;
}

void AdvanceItemFBox(ItemFBox *fbox) {
    s32 t;

    if (fbox->mUnk_000.mItemObject.mFlags & 0x180000) {
        if (fbox->mUnk_000.mItemObject.mFlags & 0x80000) {
            func_020f6e58(&fbox->mUnk_000.mItemObject);
        } else if (fbox->mUnk_000.mItemObject.mFlags & 0x100000) {
            AdvanceItemObjectReleaseTimer(&fbox->mUnk_000.mItemObject);
        }
    } else if (fbox->mUnk_000.mItemObject.mFlags & 0x8000) {
        AdvanceRestingItemObject(&fbox->mUnk_000.mItemObject);
    } else if (fbox->mUnk_000.mItemObject.mFlags & 0x4000) {
        AdvanceFallingItemObject(&fbox->mUnk_000.mItemObject);
    } else {
        if (fbox->mThrownForward != 0) {
            AdvanceBouncingItem(&fbox->mUnk_000, 0x1ec, 0xfec, 0, (u32 *) &t);
        } else {
            AdvanceBouncingItem(&fbox->mUnk_000, 0x2e1, 0xf85, 0, (u32 *) &t);
        }
        if ((fbox->mUnk_000.mItemObject.mFlags & 8) && (fbox->mUnk_000.mItemObject.mFlags & 3) == 0) {
            if (fbox->mThrownForward != 0) {
                fbox->mUnk_000.mItemObject.mVelocity.y *= 2;
            }
            StopSound(&fbox->mUnk_000.mItemObject.mSoundSource, 0xda);
            StartRestingItemObject(&fbox->mUnk_000.mItemObject, &t);
        }
    }
    SetPooledMapObjectFromItem(fbox->mPooledMapObject, fbox->mUnk_000.mItemObject.mUnk_d8,
                               &fbox->mUnk_000.mItemObject.mScale);
}

s32 func_020ff3c4(ItemFBox *fbox) {
    Vec3 *vector;

    vector = data_0217bc4c;
    if ((s64) vector->x * vector->x + (s64) vector->y * vector->y + (s64) vector->z * vector->z >= 0x10) {
        Vec3NormalizeAndGetLengthUnchecked(vector, &fbox->mUnk_130);
    }
    fbox->mPooledMapObject->mUnk_b0 = 2;
    if ((fbox->mUnk_000.mItemObject.mFlags & 0x180000) == 0) {
        fbox->mUnk_000.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceItemFBox;
    }
    return 2;
}

void func_020ff344(ItemFBox *fbox) {
    if ((s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].x * fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].x +
            (s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].y * fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].y +
            (s64) fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].z * fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0].z >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0],
                                           &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0]);
    }
    Vec3CrossUnrounded(&fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[0], &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[1],
                       &fbox->mUnk_000.mItemObject.mUnk_94.mUnk_00[2]);
    MTX_Concat33((const s32 *) &data_0217c600, (const s32 *) &fbox->mUnk_000.mItemObject.mUnk_94,
                 (s32 *) &fbox->mUnk_000.mItemObject.mUnk_94);
    if ((fbox->mUnk_000.mItemObject.mFlags & 0x180000) == 0) {
        fbox->mUnk_000.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceItemFBox;
    }
}
