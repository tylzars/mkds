#include "Main/Unknown/code_020a23a0.h"
#include "registers.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0204984c.h"
#include "code_02010c84.h"
#include "code_02146cbc.h"
#include "code_0214a748.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0204a000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02088000.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_02018000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_02146000.h"
#include "code_02147cd8.h"
#include "code_0214a390.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/unk_02170000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b200.h"
#include "code_021471bc.h"

void func_020a29cc(void) {
    s32 x;
    s32 y;
    s32 v;
    Trophy *trophy;
    Unk0217b200_08 *wobble;

    G2x_SetBlendAlpha_(&reg_G2_BLDCNT, 1, 0x1f, 0x10, 0x10);
    NNS_G3dGlbLightVector(0, gTrophy->mLight0X, gTrophy->mLight0Y, gTrophy->mLight0Z);
    NNS_G3dGlbLightVector(1, gTrophy->mLight1X, gTrophy->mLight1Y, gTrophy->mLight1Z);
    NNS_G3dGlbLightColor(0, 0x7fff);
    NNS_G3dGlbLightColor(1, 0x7fff);
    x = ((s64) FX_Div(data_0215d6b4[0x54], data_0215d6b4[0x55]) * 0x19a) >> 12;
    y = ((s64) -x * 0x1555) >> 12;
    if (gRaceSetup->mMirrorMode != 0) {
        G3i_FrustumW_(x, -x, -y, y, 0x19a, 0x1388000, 0x200, 0, (Unk0214ad4c *) data_0217029c.mProjMtx);
        data_0217029c.mFlag &= ~0x50;
    } else {
        G3i_FrustumW_(x, -x, y, -y, 0x19a, 0x1388000, 0x200, 0, (Unk0214ad4c *) data_0217029c.mProjMtx);
        data_0217029c.mFlag &= ~0x50;
    }
    {
        Vec3 v3;
        Vec3 v2;
        Vec3 v1 = {0, 0, 0};

        v2 = data_021676d0;
        v3 = data_021676c4;
        data_021704dc[0] = v3;
        data_021704dc[1] = v2;
        data_021704dc[2] = v1;
        G3i_LookAt_(&v3, &v2, &v1, 0, &data_0217029c.mCameraMtx);
        data_0217029c.mFlag &= ~0xe8;
        SetG3xSwapBits(gDisplaySettings, 1, 1);
        data_0217029c.mPrmViewPort = 0xbfff0000;
        NNS_G3dGlbFlushP();
        if (gTrophy->mRankIndex >= 3) {
            return;
        }
        gTrophy->mRotateYAngle = -GetSceneFadeToClearFrameCount() * 0x6d;
        v = -GetSceneFadeToClearFrameCount() * 0x36;
        trophy = gTrophy;
        trophy->mRotateZWobble.mUnk_00 = v;
        wobble = &trophy->mRotateZWobble;
        wobble->mUnk_0c = 0;
        wobble->mUnk_10 = 0xaab;
        wobble->mUnk_14 = 0;
        wobble->mUnk_18 = 0x36;
        wobble->mUnk_1c = 0;
        MTX_Identity43_(&gTrophy->mEffectMatrix);
        if (gTrophy->mRankIndex == 0) {
            gTrophy->mEffect0->mUnk_5c = gTrophy->mUnk_114;
            gTrophy->mEffect0->mUnk_28.x = gTrophy->mEffectOffset.x + gTrophy->mEffect0->mUnk_20->mUnk_00->mUnk_04.x;
            gTrophy->mEffect0->mUnk_28.y = gTrophy->mEffectOffset.y + gTrophy->mEffect0->mUnk_20->mUnk_00->mUnk_04.y;
            gTrophy->mEffect0->mUnk_28.z = gTrophy->mEffectOffset.z + gTrophy->mEffect0->mUnk_20->mUnk_00->mUnk_04.z;
            gTrophy->mEffect4->mUnk_28.x = gTrophy->mEffect4->mUnk_20->mUnk_00->mUnk_04.x;
            gTrophy->mEffect4->mUnk_28.y = gTrophy->mEffect4->mUnk_20->mUnk_00->mUnk_04.y - 0xcd;
            gTrophy->mEffect4->mUnk_28.z = gTrophy->mEffect4->mUnk_20->mUnk_00->mUnk_04.z - 0x21ec;
            gTrophy->mEffect5->mUnk_28.x = gTrophy->mEffect5->mUnk_20->mUnk_00->mUnk_04.x;
            gTrophy->mEffect5->mUnk_28.y = gTrophy->mEffect5->mUnk_20->mUnk_00->mUnk_04.y - 0xcd;
            gTrophy->mEffect5->mUnk_28.z = gTrophy->mEffect5->mUnk_20->mUnk_00->mUnk_04.z - 0x21ec;
        } else if (gTrophy->mRankIndex == 1) {
            gTrophy->mEffect0->mUnk_5c = gTrophy->mUnk_114;
            gTrophy->mEffect0->mUnk_28.x = gTrophy->mEffectOffset.x + gTrophy->mEffect0->mUnk_20->mUnk_00->mUnk_04.x;
            gTrophy->mEffect0->mUnk_28.y = gTrophy->mEffectOffset.y + gTrophy->mEffect0->mUnk_20->mUnk_00->mUnk_04.y;
            gTrophy->mEffect0->mUnk_28.z = gTrophy->mEffectOffset.z + gTrophy->mEffect0->mUnk_20->mUnk_00->mUnk_04.z;
        }
    }
}

void InitTrophy(s32 modelIndex, u32 rankIndex) {
    void *modelFile;
    void *animationFile;
    void *heap;
    float f;
    s32 x;
    ModelAnimationView *modelAnimation;

    gTrophy = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x124);
    gTrophy->mRankIndex = rankIndex;
    gTrophy->mModelIndex = modelIndex;
    if (modelIndex < 9 && rankIndex < 3) {
        modelFile = FindSceneFile(data_021677fc[modelIndex]);
        animationFile = FindSceneFile(data_02167820[modelIndex]);
        gTrophy->mLight0X = data_02156640[modelIndex];
        gTrophy->mLight0Y = data_02156654[modelIndex];
        gTrophy->mLight0Z = data_02156668[modelIndex];
        gTrophy->mLight1X = data_0215667c[modelIndex];
        gTrophy->mLight1Y = data_02156690[modelIndex];
        gTrophy->mLight1Z = data_021566a4[modelIndex];
        gTrophy->mEffectOffset.x = 0;
        gTrophy->mEffectOffset.y = data_021566dc[modelIndex];
        gTrophy->mEffectOffset.z = -0x2000;
        gTrophy->mUnk_114 = data_021566b8[modelIndex];
        InitNsbmd(&gTrophy->mModel, modelFile);
        SetNsbmdLightEnableFlagAll(&gTrophy->mModel, 3);
        if (gRaceSetup->mMirrorMode != 0) {
            SetNsbmdCullModeAll(&gTrophy->mModel, 1);
        } else {
            SetNsbmdCullModeAll(&gTrophy->mModel, 2);
        }
        heap = GetHeap(GetCurrentHeapCall());
        InitModelAnimation(2, &gTrophy->mModelAnimation, &gTrophy->mModel, 1, heap, modelFile);
        InitModelAnimationEntries(&gTrophy->mModelAnimation, animationFile, GetHeap(GetCurrentHeapCall()));
        SetModelAnimation(&gTrophy->mModelAnimation, 0);
        x = gTrophy->mRankIndex;
        if (x != 0) {
            f = 0.5f + (x << 12);
        } else {
            f = (x << 12) - 0.5f;
        }
        modelAnimation = &gTrophy->mModelAnimation;
        modelAnimation->mUnk_0c = f;
        *modelAnimation->mUnk_1c[modelAnimation->mUnk_1a] = modelAnimation->mUnk_0c;
        InitEffects(GetHeap(GetCurrentHeapCall()));
        if (rankIndex == 0) {
            Vec3 w0 = {0, 0, 0};

            gTrophy->mEffect0 = StartEffect(0, &w0);
            {
                Vec3 w1 = {0, 0, 0};

                gTrophy->mEffect4 = StartEffect(4, &w1);
                {
                    Vec3 w2 = {0, 0, 0};

                    gTrophy->mEffect5 = StartEffect(5, &w2);
                }
            }
        } else if (rankIndex == 1) {
            Vec3 w3 = {0, 0, 0};

            gTrophy->mEffect0 = StartEffect(0, &w3);
        }
    }
    func_020a29cc();
}

s16 func_020a2684(s32 angle) {
    return gPairsByAngle[(angle >> 4) * 2];
}

s32 func_020a2668(s32 a, s32 b) {
    return ((s64) a * b + 0x800) >> 12;
}

void AdvanceTrophy(void) {
    Trophy *trophy;
    Unk0217b200_08 *wobble;
    s32 v;

    if (gTrophy->mRankIndex >= 3) {
        return;
    }
    UpdateEffects();
    gTrophy->mRotateYAngle += 0x6d;
    trophy = gTrophy;
    wobble = &trophy->mRotateZWobble;
    trophy->mRotateZWobble.mUnk_00 += wobble->mUnk_18;
    wobble->mUnk_08 = wobble->mUnk_0c + func_020a2668(wobble->mUnk_10, func_020a2684(trophy->mRotateZWobble.mUnk_00)) -
                      wobble->mUnk_04;
    wobble->mUnk_04 += wobble->mUnk_08;
    if (wobble->mUnk_10 > 0) {
        v = wobble->mUnk_10 + wobble->mUnk_14;
        if (v <= 0) {
            v = 0;
        }
        wobble->mUnk_10 = v;
    } else if (wobble->mUnk_10 < 0) {
        v = wobble->mUnk_10 + wobble->mUnk_14;
        if (v >= 0) {
            v = 0;
        }
        wobble->mUnk_10 = v;
    }
    if (wobble->mUnk_18 > 0) {
        v = wobble->mUnk_18 + wobble->mUnk_1c;
        if (v <= 0) {
            v = 0;
        }
        wobble->mUnk_18 = v;
    } else if (wobble->mUnk_18 < 0) {
        v = wobble->mUnk_18 + wobble->mUnk_1c;
        if (v >= 0) {
            v = 0;
        }
        wobble->mUnk_18 = v;
    }
}

void DrawTrophy(void) {
    s32 rotateXMatrix[9];
    s32 rotateYMatrix[9];
    s32 rotateZMatrix[9];
    s32 scale[3];
    s32 translation[3];
    s32 v3[3];
    u16 rotateZAngle;

    if (gTrophy->mRankIndex >= 3) {
        return;
    }
    DrawEffects(&gTrophy->mEffectMatrix);
    NNS_G3dGlbFlushP();
    func_01ff9048(0x15, NULL, 0);
    scale[0] = 0x1000;
    scale[1] = 0x1000;
    scale[2] = 0x1000;
    func_01ff9048(0x1b, scale, 3);
    translation[0] = 0;
    translation[1] = -0xcd;
    translation[2] = -0x2000;
    func_01ff9048(0x1c, translation, 3);
    rotateZAngle = gTrophy->mRotateZWobble.mUnk_04;
    MTX_RotX33_(rotateXMatrix, data_0215d6b4[0x76], data_0215d6b4[0x77]);
    MTX_RotY33_(rotateYMatrix, gPairsByAngle[(gTrophy->mRotateYAngle >> 4) * 2],
                gPairsByAngle[(gTrophy->mRotateYAngle >> 4) * 2 + 1]);
    MTX_RotZ33_(rotateZMatrix, gPairsByAngle[(rotateZAngle >> 4) * 2], gPairsByAngle[(rotateZAngle >> 4) * 2 + 1]);
    func_01ff9048(0x1a, rotateXMatrix, 9);
    func_01ff9048(0x1a, rotateYMatrix, 9);
    func_01ff9048(0x1a, rotateZMatrix, 9);
    v3[0] = 0;
    v3[1] = 0;
    v3[2] = 0;
    func_01ff9048(0x1c, v3, 3);
    DrawNsbmd(&gTrophy->mModel);
    func_01ff9234();
}

s32 func_020a23a0(Kart *kart) {
    KartModelsEntry *kartModelsEntry;

    kartModelsEntry = kart->mKartModelsEntry;
    return data_02156600[kartModelsEntry->mCharacterIndex] +
           kartModelsEntry->mKartOffsetData->mUnk_48[kartModelsEntry->mCharacterIndex].x;
}
