#include "Main/Unknown/code_0206390c.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0207a30c.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02012b30.h"
#include "code_02013740.h"
#include "code_02146d78.h"
#include "code_02147288.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02077bc0.h"

// Copies row 1 of the matrix at 0x120 (mUnk_120_m), the kart's up direction, to the out vector. The camera takes it as
// its up while bit 0x40000000 of mUnk_48 is set and the world up (0, 0x1000, 0) otherwise; the steering code removes
// this component from vectors. The kart has two more matrices (0x150 and 0x184), built from this one for drawing.
void GetKartUp(const Kart *kart, Vec3 *upDirection) {
    const MtxFx43 *matrix;

    matrix = OFFSET_PTR(const MtxFx43, kart, 0x120);
    upDirection->x = matrix->mUnk_00[1].x;
    upDirection->y = matrix->mUnk_00[1].y;
    upDirection->z = matrix->mUnk_00[1].z;
}

// Copies row 2 of the matrix at 0x120 (mUnk_120_m), the kart's forward direction, to the out vector. The camera follows
// it, and its mSavedKartForward holds a copy taken when the camera is set up. The kart has two more matrices (0x150 and
// 0x184), built from this one for drawing.
void GetKartForward(const Kart *kart, Vec3 *forward) {
    const MtxFx43 *matrix;

    matrix = OFFSET_PTR(const MtxFx43, kart, 0x120);
    forward->x = matrix->mUnk_00[2].x;
    forward->y = matrix->mUnk_00[2].y;
    forward->z = matrix->mUnk_00[2].z;
}

void func_02063ad0(Kart *kart) {
    if ((kart->mUnk_7c & 0x400) != 0) {
        return;
    }
    kart->mSlotFunctions[6](kart);
    if ((kart->mUnk_7c & 0x200) != 0) {
        kart->mUnk_514->mUnk_2c ^= 0x10000;
    }
}

void func_02063a68(Kart *kart) {
    u32 b;

    b = kart->mUnk_7c & 0x400;
    if (b != 0) {
        return;
    }
    if (b == 0) {
        kart->mSlotFunctions[6](kart);
        if ((kart->mUnk_7c & 0x200) != 0) {
            kart->mUnk_514->mUnk_2c ^= 0x10000;
        }
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        kart->mUnk_48 &= ~0x200;
    }
}

void PlaceKartKillerEffectCallback(Unk0206390c *renderState) {
    u32 killerItemKartIndex;
    Vec3 c[3];
    MtxFx43 positionMatrix;
    Vec3 effectPosition;
    Vec3 offset;
    MtxFx43 inverseViewMatrix;
    s32 offsetScale;
    MtxFx43 *currentViewMatrix;
    Kart *kart;
    s32 killerItemDictIndex;

    killerItemKartIndex = GetKillerItemKartIndex();
    killerItemDictIndex = NNS_G3dGetResDictIdxByName(renderState->mUnk_04->mUnk_04 + 0x40, data_02154a2c);
    if (killerItemDictIndex != ((renderState->mUnk_08 & 0x10) != 0 ? renderState->mUnk_ae : -1)) {
        return;
    }
    currentViewMatrix = GetCurrentViewMatrix();
    NNS_G3dGetCurrentMtx(&positionMatrix, c);
    MTX_Inverse43(currentViewMatrix, &inverseViewMatrix);
    MTX_Concat43(&positionMatrix, &inverseViewMatrix, &positionMatrix);
    MTX_Concat33((const s32 *) c, (const s32 *) &inverseViewMatrix, (s32 *) c);
    effectPosition = positionMatrix.mUnk_00[3];
    offset = c[2];
    kart = GetKart(killerItemKartIndex);
    offsetScale = (s32) ((s64) kart->mRadiusFactor * -0xd000 + 0x800 >> 12) >> 4;
    offset.x = (s64) offset.x * offsetScale >> 12;
    offset.y = (s64) offset.y * offsetScale >> 12;
    offset.z = (s64) offset.z * offsetScale >> 12;
    VEC_Add(&effectPosition, &offset, &effectPosition);
    PlaceKartKillerEffect(killerItemKartIndex, &effectPosition);
    renderState->mUnk_24 = 0;
    renderState->mUnk_92 = 0;
}
