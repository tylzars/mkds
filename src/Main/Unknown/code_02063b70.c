#include "Main/Unknown/code_02063b70.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02079b9c.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_02079b60.h"
#include "Main/Unknown/code_02079000.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_0207a30c.h"
#include "Main/Unknown/code_02081374.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02086058.h"
#include "Main/Unknown/code_0208ab00.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_02146000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_0215d000.h"

void SetKartSoundDistanceSquaredAndChange(Kart *kart) {
    kart->mSoundSource.mDistanceSquared = GetKartCameraDistanceSquared(kart->mIndex);
    AdvanceSoundDistanceSquaredChange(&kart->mUnk_518, GetKartCameraDistanceSquared(kart->mIndex));
}

static inline void func_02063cc4_inline(u32 command, s32 value) {
    func_01ff9048(command, &value, 1);
}

static inline void func_02063cc4_inline2(u32 command, s32 valueX, s32 valueY, s32 valueZ) {
    Vec3 vector;

    vector.x = valueX;
    vector.y = valueY;
    vector.z = valueZ;
    func_01ff9048(command, &vector, 3);
}

static inline void func_02063cc4_inline3(Vec3 *destination, const Vec3 *source) {
    destination->x = source->x >> 4;
    destination->y = source->y >> 4;
    destination->z = source->z >> 4;
}

void DrawKart(Kart *kart) {
    u32 b;
    u32 c;
    u32 d;
    KartModelsEntry *modelsEntry;
    Unk0206bcb0_590_54 *f;
    s32 killerItemShown;
    s32 h;
    s32 spinMatrix[9];
    s32 k[9];
    Vec3 translation;
    s32 pairIndex;

    c = kart->mUnk_4c;
    b = (c & 0x10) != 0;
    d = kart->mUnk_7c;
    modelsEntry = kart->mKartModelsEntry;
    if ((d & 0x1008040) != 0 || (c & 0x11800000) != 0) {
        killerItemShown = 0;
        if ((d & 0x1008040) == 0 && (c & 0x1800000) == 0) {
            killerItemShown = DrawKartKillerItem(kart);
        }
        SetKartKillerEffectShown(kart->mIndex, killerItemShown);
        kart->mVisible = 0;
        return;
    }
    if ((d & 0x404004) != 0) {
        kart->mVisible = ~kart->mVisible;
        if (kart->mVisible == 0) {
            return;
        }
    } else {
        kart->mVisible = 0xffff;
    }
    func_02063cc4_inline(0x14, 0x1e);
    if (b != 0) {
        func_02063cc4_inline3(&kart->mUnk_144, kart->mPosSource);
        func_01ff9048(0x19, &kart->mUnk_120, 0xc);
        func_01ff9048(0x1b, &kart->mScale, 3);
        func_02063cc4_inline2(0x1b, kart->mModelScaleX, kart->mModelScaleY, kart->mModelScaleZ);
        func_0207ae58(modelsEntry->mShadowModel);
        func_02063cc4_inline(0x14, 0x1e);
    }
    func_01ff9048(0x19, kart->mDrawMatrix, 0xc);
    func_01ff9048(0x1b, &kart->mScale, 3);
    func_02063cc4_inline(0x13, 0x1d);
    func_02063cc4_inline2(0x1b, kart->mModelScaleX, kart->mModelScaleY, kart->mModelScaleZ);
    if (b == 0) {
        func_0207ae58(modelsEntry->mShadowModel);
    }
    func_0208ab4c(&modelsEntry->mUnk_040);
    if (modelsEntry->mUnk_058 == 0) {
        SetKartModelTireAlpha(modelsEntry, modelsEntry->mUnk_060 == FALSE);
        func_02063cc4_inline(0x13, 0x1c);
        func_02063cc4_inline2(0x1b, kart->mUnk_4f0.x, kart->mUnk_4f0.y, 0x1000);
        DrawNsbmd(modelsEntry->mModels[1]);
        if (modelsEntry->mModels[2] != NULL) {
            f = kart->mKartModelsEntry->mUnk_054;
            h = kart->mKartModelsEntry->mKartOffsetData->mUnk_10;
            func_02063cc4_inline(0x14, 0x1c);
            func_01ff9048(0x1c, &f->mUnk_18, 3);
            pairIndex = (kart->mTireSpinAngle >> 4) * 2;
            MTX_RotX33_(spinMatrix, gPairsByAngle[pairIndex], gPairsByAngle[pairIndex + 1]);
            func_01ff9048(0x1a, spinMatrix, 9);
            DrawNsbmd(modelsEntry->mModels[2]);
            if (f->mUnk_18 != 0) {
                func_02063cc4_inline2(0x1c, f->mUnk_24, 0, 0);
                DrawNsbmd(modelsEntry->mModels[2]);
            }
            func_02063cc4_inline(0x14, 0x1c);
            func_01ff9048(0x1c, f, 3);
            func_02063cc4_inline2(0x1b, h, h, h);
            func_01ff9048(0x11, NULL, 0);
            pairIndex = (kart->mUnk_4cc >> 4) * 2;
            MTX_RotY33_(k, gPairsByAngle[pairIndex], gPairsByAngle[pairIndex + 1]);
            func_01ff9048(0x1a, k, 9);
            func_01ff9048(0x1a, spinMatrix, 9);
            DrawNsbmd(modelsEntry->mModels[2]);
            if (f->mUnk_00 != 0) {
                func_02063cc4_inline(0x12, 1);
                func_02063cc4_inline2(0x1c, f->mUnk_0c, 0, 0);
                func_01ff9048(0x1a, k, 9);
                func_01ff9048(0x1a, spinMatrix, 9);
                DrawNsbmd(modelsEntry->mModels[2]);
            }
        }
    }
    if (modelsEntry->mUnk_05c != 0) {
        return;
    }
    translation = ((Vec3 *) &modelsEntry->mKartOffsetData->mUnk_44)[modelsEntry->mCharacterIndex];
    translation.y = translation.y + (kart->mModelOffsetY + kart->mUnk_4f0.z);
    func_02063cc4_inline(0x14, 0x1d);
    func_01ff9048(0x1c, &translation, 3);
    DrawNsbmd(modelsEntry->mModels[0]);
}

BOOL DrawKartKillerItem(Kart *kart) {
    KartModelsEntry *modelsEntry;
    KartModelAnimationView *killerItemNsbca;
    BOOL drawn;
    s32 frame;
    s32 f;
    s32 t;
    s32 radiusFactor;
    Vec3 position;
    Vec3 scale;
    MtxFx43 matrix;

    modelsEntry = kart->mKartModelsEntry;
    drawn = modelsEntry->mUnk_058 == 0;
    if (drawn != FALSE) {
        t = kart->mRadius + 0x5000;
        matrix = *kart->mDrawMatrix;
        VEC_MultAdd(t, &kart->mUnk_12c, kart->mPosSource, &position);
        matrix.mUnk_00[3].x = position.x >> 4;
        matrix.mUnk_00[3].y = position.y >> 4;
        matrix.mUnk_00[3].z = position.z >> 4;
        radiusFactor = kart->mRadiusFactor;
        scale.x = (s64) kart->mScale.x * radiusFactor >> 12;
        scale.y = (s64) kart->mScale.y * radiusFactor >> 12;
        scale.z = (s64) kart->mScale.z * radiusFactor >> 12;
        f = 0x1e;
        func_01ff9048(0x14, &f, 1);
        func_01ff9048(0x19, &matrix, 0xc);
        func_01ff9048(0x1b, &scale, 3);
        func_0208ab4c(&modelsEntry->mUnk_040);
        SetKillerItemKartIndex(kart->mIndex);
        frame = kart->mKartModelsEntry->mUnk_0a4;
        killerItemNsbca = GetKillerItemNsbca();
        killerItemNsbca->mUnk_0c = frame;
        *killerItemNsbca->mUnk_1c[killerItemNsbca->mUnk_1a] = killerItemNsbca->mUnk_0c;
        DrawNsbmd(GetKillerItem());
        func_0207ae58(GetKillerItemS());
    }
    return drawn;
}
