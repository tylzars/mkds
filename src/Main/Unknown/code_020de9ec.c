#include "Main/Unknown/code_020de9ec.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020d8c74.h"

#include "Main/Unknown/code_020de9f8.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d8654.h"
#include "Main/Unknown/code_020deb2c.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020debec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e516c.h"
#include "Main/Unknown/code_020e55b4.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020df428.h"
#include "code_021471bc.h"

#pragma thumb on

void InitGroupItemBox(ItemBox *itemBox, Unk020de6a8_1 *row) {
    InitItemBox(itemBox, row);
    if (itemBox->mUnk_0f8 != 0) {
        itemBox->mFollower.mUnk_00.mGroupIndex = (0x0000ffffu);
        return;
    }
    func_020d7d4c(&itemBox->mFollower, (CourseMapRow *) row, *&data_02158908, row->mUnk_28);
    SetupGroupFollowerWithSpeeds(&itemBox->mFollower, row->mUnk_30, 1);
    GetGroupFollowerCurvePosition(&itemBox->mFollower.mUnk_00, &itemBox->mUnk_000.mPos);
}

#pragma thumb off

#pragma thumb on
void func_020df3f8(void) {
    data_0217b750 = 0;
    data_0217b754 = 0;
    data_0217b75c = 0x1000;
    data_0217b760.x = 0x1000;
    data_0217b760.y = 0x1000;
    data_0217b760.z = 0x1000;
}
#pragma thumb off

Unk020de390 *CreateItemBoxKindData(void) {
    Unk020de390 *kindData;

    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = data_02158654;
    return kindData;
}

Unk020de334 *CreateBoxDrawList(void) {
    gBoxDrawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    *gBoxDrawList = data_02158628;
    func_020d49d8(&gBoxDrawList);
    return gBoxDrawList;
}

Unk020de334 *CreateQuestionDrawList(void) {
    gQuestionDrawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    *gQuestionDrawList = data_021585fc;
    func_020d49d8(&gQuestionDrawList);
    return gQuestionDrawList;
}

Unk020de334 *func_020df294(void) {
    data_0217b714 = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    *data_0217b714 = data_021585d0;
    func_020d49d8(&data_0217b714);
    return data_0217b714;
}

Unk020de2d8 *CreateItemBoxUpdateList(void) {
    gItemBoxUpdateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    *gItemBoxUpdateList = data_021585a8;
    SetUpdateListSlot(&gItemBoxUpdateList);
    return gItemBoxUpdateList;
}

void SetupDrawBox(void) {
    func_020e6a18(gBox);
}

void DrawBox(void *unused0, ItemBox *itemBox, void *unused1, u16 d) {
    MtxFx43 matrix;
    Unk020e6488 *model;
    Vec3 *position;
    s32 cosine;
    s32 sine;
    s32 negatedProduct;
    u16 x;
    u16 polygonId;
    u16 newPolygonId;
    BoxRotation *rotation;

    if (itemBox->mUnk_0e8 < 1) {
        return;
    }
    if (itemBox->mUnk_100 != NULL) {
        itemBox->mUnk_100(itemBox->mUnk_104, &matrix);
        newPolygonId = AllocPolygonIdWrapping();
        model = gBox;
        model->mUnk_14 = model->mUnk_14 & 0xc0ffffff;
        model->mUnk_14 = model->mUnk_14 | newPolygonId << 24;
    } else {
        rotation = &gBoxRotations[itemBox->mBoxRotationIndex];
        cosine = rotation->mUnk_00;
        matrix.mUnk_00[0].x = cosine;
        sine = rotation->mUnk_04;
        matrix.mUnk_00[0].y = sine;
        matrix.mUnk_00[0].z = 0;
        negatedProduct = -rotation->mUnk_10;
        matrix.mUnk_00[1].x = negatedProduct;
        matrix.mUnk_00[1].y = rotation->mUnk_08;
        matrix.mUnk_00[1].z = sine;
        matrix.mUnk_00[2].x = rotation->mUnk_0c;
        matrix.mUnk_00[2].y = negatedProduct;
        matrix.mUnk_00[2].z = cosine;
        position = itemBox->mUnk_0fc;
        matrix.mUnk_00[3].x = position->x >> 4;
        matrix.mUnk_00[3].y = position->y >> 4;
        matrix.mUnk_00[3].z = position->z >> 4;
        polygonId = itemBox->mPolygonId;
        model = gBox;
        model->mUnk_14 = model->mUnk_14 & 0xc0ffffff;
        model->mUnk_14 = model->mUnk_14 | polygonId << 24;
    }
    x = itemBox->mUnk_0e8;
    model = gBox;
    model->mUnk_14 = model->mUnk_14 & 0xffe0ffff;
    model->mUnk_14 = model->mUnk_14 | x << 16;
    if (itemBox->mUnk_0fc != NULL) {
        if (itemBox->mUnk_000.mScale.z < 0x29) {
            return;
        }
        func_020e67c4(gBox, &matrix, &itemBox->mUnk_000.mScale, 0, d);
    } else {
        func_020e67c4(gBox, &matrix, NULL, 0, d);
    }
}

void SetupDrawQuestion(void) {
    func_020e6a18(gQuestion);
}

void DrawQuestion(void *unused0, ItemBox *itemBox, void *unused1, u16 d) {
    MtxFx43 matrix;
    s32 cosine;
    s32 negatedSine;
    QuestionRotation *rotation;
    Unk020e6488 *p;
    Vec3 *position;
    s32 x;
    Unk020e6488 *p2;
    u16 polygonId;

    itemBox->mPolygonId = AllocPolygonIdWrapping();
    if (itemBox->mUnk_100 != NULL) {
        return;
    }
    if ((s32) (itemBox->mUnk_000.mDistanceSquaredAndFlags & 0x3fffffe0) > 0x27100) {
        if (func_0203c5e4() == 0) {
            return;
        }
    }
    if (itemBox->mUnk_0ec < 1) {
        return;
    }
    rotation = &gQuestionRotations[itemBox->mQuestionRotationIndex];
    cosine = rotation->mUnk_00;
    matrix.mUnk_00[0].x = cosine;
    matrix.mUnk_00[0].y = 0;
    negatedSine = -rotation->mUnk_04;
    matrix.mUnk_00[0].z = negatedSine;
    matrix.mUnk_00[1].x = 0;
    matrix.mUnk_00[1].y = 0x1000;
    matrix.mUnk_00[1].z = 0;
    matrix.mUnk_00[2].x = -negatedSine;
    matrix.mUnk_00[2].y = 0;
    matrix.mUnk_00[2].z = cosine;
    position = itemBox->mUnk_0fc;
    matrix.mUnk_00[3].x = position->x >> 4;
    matrix.mUnk_00[3].y = position->y >> 4;
    matrix.mUnk_00[3].z = position->z >> 4;
    p = gQuestion;
    x = itemBox->mUnk_0ec;
    p->mUnk_14 &= 0xffe0ffff;
    p->mUnk_14 |= (u16) x << 16;
    polygonId = itemBox->mPolygonId;
    p2 = gQuestion;
    p2->mUnk_14 &= 0xc0ffffff;
    p2->mUnk_14 |= polygonId << 24;
    func_020e67c4(gQuestion, &matrix, itemBox->mUnk_0fc != NULL ? &itemBox->mUnk_000.mScale : 0, 0, d);
}

void func_020dee8c(void) {
    s32 angleIndex;

    func_020e55b4();
    if (func_020b2ec0() != 0) {
        return;
    }
    data_0217b6fc += 0xca;
    angleIndex = data_0217b6fc >> 4;
    MTX_RotY43_(&data_0217b720, gPairsByAngle[angleIndex * 2], gPairsByAngle[angleIndex * 2 + 1]);
}

void func_020dec4c(void *unused, ItemBox *itemBox, u32 c, u32 d) {
    Vec3 shadowScale;
    Vec3 *position;
    s32 n;
    s32 x;
    s32 y;
    MtxFx43 *matrix;

    n = itemBox->mFramesSinceHit - 0x40;
    if (n >= 0x40) {
        itemBox->mUnk_0e8 = 0x1a;
        itemBox->mUnk_0ec = 0x14;
        n = 0xd;
    } else {
        x = n * 0x1a >> 6;
        y = n * 0x14 >> 6;
        n = n * 0xd >> 6;
        if (x > 0) {
            if (y < 1) {
                y = 1;
            }
            if (n < 1) {
                n = 1;
            }
        }
        itemBox->mUnk_0e8 = x;
        itemBox->mUnk_0ec = y;
    }
    if ((s32) (itemBox->mUnk_000.mDistanceSquaredAndFlags & ~0xc000001f) > 0x27100) {
        if (func_0203c5e4() == 0) {
            return;
        }
    }
    if (n < 1) {
        return;
    }
    if (itemBox->mUnk_0b0 == 0) {
        itemBox->mUnk_0b4.mUnk_030 = n;
        func_020e54e4(&itemBox->mUnk_0b4, itemBox->mUnk_0a8 != 0 ? &data_0217b75c : 0, c, d);
        return;
    }
    if (itemBox->mUnk_0b0 != 1) {
        return;
    }
    if (itemBox->mUnk_0a8 != 0) {
        position = itemBox->mUnk_0fc;
        data_0217b720.mUnk_00[3].x = position->x >> 4;
        data_0217b720.mUnk_00[3].y = position->y >> 4;
        data_0217b720.mUnk_00[3].z = position->z >> 4;
        DrawJgShadowWithMatrix(&data_0217b760, &data_0217b720, (u16) n, d);
        return;
    }
    shadowScale.x = ((s64) itemBox->mUnk_000.mScale.x * 0x1666) >> 12;
    shadowScale.y = ((s64) itemBox->mUnk_000.mScale.y * 0x1666) >> 12;
    shadowScale.z = ((s64) itemBox->mUnk_000.mScale.z * 0x1666) >> 12;
    if (itemBox->mUnk_100 != NULL) {
        matrix = SetTranslationMatrixPos(itemBox->mUnk_0fc);
    } else {
        position = itemBox->mUnk_0fc;
        data_0217b720.mUnk_00[3].x = position->x >> 4;
        data_0217b720.mUnk_00[3].y = position->y >> 4;
        data_0217b720.mUnk_00[3].z = position->z >> 4;
        matrix = &data_0217b720;
    }
    DrawJgShadowWithMatrix(&shadowScale, matrix, (u16) n, d);
}

void UpdateItemBox(void *unused, ItemBox *itemBox) {
    u32 framesSinceHit;

    itemBox->mBoxRotationIndex++;
    if (itemBox->mBoxRotationIndex >= 0x12c) {
        itemBox->mBoxRotationIndex = 0;
    }
    itemBox->mQuestionRotationIndex++;
    if (itemBox->mQuestionRotationIndex >= 0x82) {
        itemBox->mQuestionRotationIndex = 0;
    }
    framesSinceHit = itemBox->mFramesSinceHit;
    if (framesSinceHit >= 0x80) {
        return;
    }
    itemBox->mFramesSinceHit = framesSinceHit + 1;
    if (framesSinceHit > 0x60) {
        itemBox->mUnk_000.mFlags = itemBox->mUnk_000.mFlags & ~1;
    }
}

void func_020deb2c(Vec3 *position, void *kart, u32 c, int d, u32 e) {
    void *effect;
    u32 kartIndex;
    kartIndex = *OFFSET_PTR(u16, kart, 0x74);
    if (d == 0) {
        if (kartIndex == gRaceSetup->mEntryIndex) {
            effect = StartEffect(0x2d, position);
            if (effect != NULL) {
                SetupKartFollowEffect(effect, kartIndex, 0x1e);
            }
            effect = StartEffect(0x2e, position);
            if (effect != NULL) {
                SetupKartFollowEffect(effect, kartIndex, 0x1e);
            }
        }
        effect = StartEffect(0x2f, position);
        if (effect != NULL) {
            SetupKartFollowEffect(effect, kartIndex, 0x1e);
        }
    }
    func_020d26ec(kart, 0xd4);
    StartItemSlotForKart(kartIndex, c, e);
}

u8 CollideKartWithItemBox(ItemBox *itemBox, Unk020dea50_1 *kart, void *c, u8 *d) {
    s32 playerKind;
    BOOL kindInMask;
    u32 distanceBits;

    if ((kart->mUnk_7c & 0x400000) != 0) {
        return 0;
    }
    kindInMask = FALSE;
    itemBox->mFramesSinceHit = 0;
    itemBox->mUnk_000.mFlags |= data_021585a4;
    distanceBits = itemBox->mUnk_000.mDistanceSquaredAndFlags & 3;
    playerKind = gRaceSetup->mCurrentEntries[kart->mUnk_74].mPlayer.mKind;
    if ((u32) playerKind <= 3) {
        if (((1 << playerKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) != 0) {
            kindInMask = TRUE;
        }
    }
    func_020deb2c(&itemBox->mUnk_000.mPos, kart, kindInMask != FALSE ? itemBox->mUnk_0f2 : itemBox->mUnk_0f4,
                  distanceBits, itemBox->mUnk_0ac);
    if (itemBox->mUnk_0f8 != 0 || itemBox->mUnk_000.mCourseMapRow->mUnk_32 != 0) {
        itemBox->mFramesSinceHit = 0x80;
        ParkMapObject(&itemBox->mUnk_000);
    }
    return *d;
}

u32 func_020de9f8(ItemBox *itemBox) {
    if (itemBox->mUnk_0f8 != 0) {
        return 0x270f000;
    }
    if (itemBox->mUnk_0a8 == 0) {
        return 0;
    }
    return GetMaxXzDistanceToGroup(&itemBox->mFollower.mUnk_00, &itemBox->mUnk_000.mPos);
}

void func_020de9ec(ItemBox *itemBox) {
    itemBox->mFramesSinceHit = 0x80;
}
