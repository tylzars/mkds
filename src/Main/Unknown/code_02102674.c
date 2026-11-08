#include "Main/Unknown/code_02102674.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_020fe4b4.h"

#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f8000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_02102000.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_021031f4.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02102eb8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f8e3c.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02077bc0.h"

void AdvanceItemGesso(ItemGesso *p) {
    Kart *kart;
    Camera *camera;
    s32 ageFrames;
    s32 i;
    s32 kartCount;
    Kart *kartAtIndex;
    s32 v;
    Vec3 viewOffset;
    s32 m;
    s32 n;
    s32 factor;

    kart = p->mKart;
    camera = GetChaseCamera();
    ageFrames = p->mUnk_000.mAgeFrames;
    if (ageFrames == 0x3f) {
        func_021031f4(p);
    }
    if (ageFrames == 0x8f) {
        kartCount = gRaceSetup->mKartCount;
        for (i = 0; i < kartCount; i++) {
            if (p->mOrthoQuadCounts[i] == 0) {
                continue;
            }
            kartAtIndex = GetKart(i);
            if (kartAtIndex->mUnk_7c & 0x402020) {
                continue;
            }
            if (kartAtIndex->mUnk_4c & 0x10000840) {
                continue;
            }
            if (kartAtIndex->mUnk_48 & 0x10000) {
                continue;
            }
            StartKartGesso(kartAtIndex, p->mOrthoQuadCounts[i]);
            func_020f8e3c((u32) kartAtIndex, 0xf0);
        }
    }
    if (p->mUnk_160 != FALSE) {
        if (ageFrames <= gItemGessoFrameCount) {
            return;
        }
        ReleaseItemPoolObject(gItemPools + p->mUnk_000.mKind, &p->mUnk_000);
        return;
    }
    if (p->mStepIndex >= 4 && p->mStepIndex < 0xd) {
        if ((kart->mUnk_7c & 0x402020) || (kart->mUnk_4c & 0x10000840) || (kart->mUnk_48 & 0x10000)) {
            p->mStepIndex = 0xd;
            SetupNextItemGessoStep(p);
            if (p->mVisible != FALSE) {
                func_020f8e3c((u32) kart, 0xf3);
            }
        }
    }
    if (kart->mUnk_4c & 0x800) {
        p->mUnk_160 = TRUE;
        p->mVisible = FALSE;
    }
    v = p->mVelocityX;
    if (p->mUnk_000.mAlpha < 0x1f && p->mUnk_194 == 0 && p->mVisible != FALSE) {
        p->mUnk_000.mAlpha = p->mUnk_000.mAlpha + 7;
        if (p->mUnk_000.mAlpha > 0x1f) {
            p->mUnk_000.mAlpha = 0x1f;
        }
    }
    p->mStepTimer = p->mStepTimer - 1;
    if (p->mStepTimer > 0) {
        factor = p->mApproachRate;
        m = p->mTargetVelocityX - p->mVelocityX;
        n = p->mTargetVelocityY - p->mVelocityY;
        p->mVelocityX += (s32) (((s64) factor * m) >> 12);
        p->mVelocityY += (s32) (((s64) factor * n) >> 12);
    } else {
        factor = p->mDamping;
        p->mVelocityX = ((s64) p->mVelocityX * factor) >> 12;
        p->mVelocityY = ((s64) p->mVelocityY * factor) >> 12;
        if (p->mUnk_194 != 0) {
            p->mUnk_000.mAlpha = p->mUnk_000.mAlpha - p->mUnk_170;
            if (p->mUnk_000.mAlpha >= 1) {
                p->mStepTimer = 0;
            } else {
                p->mStepTimer = -1 - p->mUnk_170;
                p->mVisible = FALSE;
                p->mUnk_000.mAlpha = 1;
            }
        }
        if (p->mStepTimer < -p->mUnk_170) {
            if (SetupNextItemGessoStep(p) != FALSE) {
                p->mUnk_160 = TRUE;
                p->mVisible = FALSE;
                return;
            }
        }
    }
    p->mViewOffset.x += p->mVelocityX;
    p->mViewOffset.y += p->mVelocityY;
    v = ((s64) (p->mVelocityX - (s32) (((s64) v * 0xccd) >> 12)) * 0x19a) >> 12;
    if (v > 0x19a) {
        v = 0x19a;
    } else if (v < -0x19a) {
        v = -0x19a;
    }
    p->mUnk_19c += v;
    p->mUnk_19c = ((s64) p->mUnk_19c * 0xeb8) >> 12;
    if (p->mUnk_19c > 0x266) {
        p->mUnk_19c = 0x266;
    } else if (p->mUnk_19c < -0x266) {
        p->mUnk_19c = -0x266;
    }
    factor = p->mUnk_184.z;
    m = p->mUnk_174 - p->mUnk_180;
    n = p->mUnk_178 - p->mUnk_184.x;
    p->mUnk_180 += (s32) (((s64) factor * m) >> 12);
    p->mUnk_184.x += (s32) (((s64) factor * n) >> 12);
    viewOffset = p->mViewOffset;
    v = ((s64) p->mUnk_19c * 0x800) >> 12;
    viewOffset.x -= (s32) (((s64) v * viewOffset.x) >> 12);
    p->mUnk_000.mPos.x = ((s64) camera->mSide.x * -viewOffset.x) >> 12;
    p->mUnk_000.mPos.y = ((s64) camera->mSide.y * -viewOffset.x) >> 12;
    p->mUnk_000.mPos.z = ((s64) camera->mSide.z * -viewOffset.x) >> 12;
    VEC_MultAdd(viewOffset.y, &camera->mUp, &p->mUnk_000.mPos, &p->mUnk_000.mPos);
    VEC_MultAdd(-viewOffset.z, &camera->mForward, &p->mUnk_000.mPos, &p->mUnk_000.mPos);
    VEC_Add(&camera->mPos, &p->mUnk_000.mPos, &p->mUnk_000.mPos);
}

void DrawItemGesso(ItemGesso *p, s32 param_2, NsbmdModel *t) {
    Vec3 scale;
    MtxFx43 matrix;
    s32 scaleFactor;
    s32 d;

    if (p->mKart == NULL) {
        return;
    }
    if (p->mVisible == FALSE) {
        return;
    }
    matrix = *SetViewTransposeMatrixPos(&p->mUnk_000.mPos);
    d = p->mUnk_19c;
    if (d <= 0) {
        d = -d;
    }
    d = 0x1000 - (s32) (((s64) d * 0xa4) >> 12);
    matrix.mUnk_00[1].x = ((s64) matrix.mUnk_00[1].x * d) >> 12;
    matrix.mUnk_00[1].y = ((s64) matrix.mUnk_00[1].y * d) >> 12;
    matrix.mUnk_00[1].z = ((s64) matrix.mUnk_00[1].z * d) >> 12;
    VEC_MultAdd(p->mUnk_19c, &matrix.mUnk_00[0], &matrix.mUnk_00[1], &matrix.mUnk_00[1]);
    scale.x = ((s64) p->mUnk_180 * p->mUnk_000.mScale.x) >> 12;
    scale.y = ((s64) p->mUnk_184.x * p->mUnk_000.mScale.y) >> 12;
    scale.z = p->mUnk_000.mScale.z;
    scaleFactor = func_0203c5e4() != 0 ? 0xccd : 0x119a;
    scale.x = ((s64) scale.x * scaleFactor) >> 12;
    scale.y = ((s64) scale.y * scaleFactor) >> 12;
    d = p->mUnk_000.mAlpha;
    if (d != 0x1f) {
        t->mUnk_14 = t->mUnk_14 & ~0x1f0000;
        t->mUnk_14 = t->mUnk_14 | ((u16) d << 16);
    }
    func_020e6a18(t);
    func_020e67c4(t, &matrix, &scale, 0, 0x1f);
    if (p->mUnk_000.mAlpha == 0x1f) {
        return;
    }
    t->mUnk_14 = t->mUnk_14 & ~0x1f0000;
    t->mUnk_14 = t->mUnk_14 | 0x1f0000;
}

void CopyItemGessoData(void *data, ItemGesso *gesso, void *toData) {
    CopyItemObjectData(data, gesso, toData);
    if (gesso == NULL) {
        return;
    }
    if (toData == NULL) {
        return;
    }
    func_020fe8ac(gesso->mUnk_000.mKind);
}

void InitItemGessoFromData(ItemGesso *gesso) {
    func_020f8e78(gesso);
    SetupItemGesso((u32) gesso, 1);
}

#pragma thumb on
void ComputeItemGessoFrameCount(void) {
    s32 i;
    ItemGessoStep *step;

    gItemGessoFrameCount = 0xf;
    for (i = 0, step = gItemGessoSteps; i < 0x11; i++) {
        gItemGessoFrameCount += step->mUnk_08 + step->mUnk_0a;
        step++;
    }
}
#pragma thumb off

void CreateItemTeresaFrameScaleTable(void) {
    s32 i;

    gItemTeresaFrameScales = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x52);
    for (i = 0; i <= 0x28; i++) {
        gItemTeresaFrameScales[i] = ((0x28 - i) << 12) / (0x29 - i);
    }
    for (i -= 5; i <= 0x28; i++) {
        gItemTeresaFrameScales[i] = (gItemTeresaFrameScales[i] + gItemTeresaFrameScales[i - 1]) >> 1;
    }
}
