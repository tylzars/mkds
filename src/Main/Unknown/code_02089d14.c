#include "Main/Unknown/code_02089d14.h"

#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_02089d70.h"
#include "Main/Unknown/code_02089e10.h"
#include "registers.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/code_02089ecc.h"
#include "Main/Unknown/code_02089ef4.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_02089fa0.h"
#include "Main/Unknown/code_02089f9c.h"
#include "Main/Unknown/code_02036820.h"
#include "ITCM/code_01ff8000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_02170000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02010c84.h"
#include "code_02013740.h"
#include "code_02134398.h"
#include "code_02146cbc.h"
#include "g3imm.h"
#include "code_0214a748.h"
#include "code_021471bc.h"

void InitStemSets(void *heap) {
    TimedQuad *timedQuad;

    gStemSets = HeapAlloc(heap, 0x79c);
    InitStemSetArray(heap);
    gStemSets->mShownIndex = 9;
    reg_G3_MTX_MODE = 0;
    G3i_OrthoW_(0x60000, -0x60000, -0x80000, 0x80000, 0, 0x1000, 0x200, 1, &gStemSets->mOrthoMtx);
    timedQuad = &gStemSets->mTimedQuad;
    gStemSets->mTimedQuad.mTimer = 0;
    timedQuad->mUnk_02 = 0;
    timedQuad->mColor = 0x7fff;
    timedQuad->mEnabled = FALSE;
}

void InitNsbmdNsbcaNsbmaNsbtp(void *heap, StemSet *stemSet, const StemSetParams *stemSetParams, u16 setIndex) {
    char fileName[0x80];
    void *lastNsbmdFile;
    u16 nsbmdIndex;
    Nsbmd *nsbmd;
    Nsbmd *nsbcaModel;
    ModelAnimation *g;
    u16 nsbcaIndex;
    Nsbmd *nsbmaModel;
    ModelAnimation *nsbmaAnimation;
    u16 nsbmaIndex;
    u16 nsbtpIndex;
    BOOL useOneNsbtpAnimation;

    lastNsbmdFile = NULL;
    stemSet->mNsbmdCount = stemSetParams->mNsbmdCount;
    stemSet->mNsbmds = NULL;
    stemSet->mNsbcaNsbmaNsbtp[0] = stemSet->mNsbcaNsbmaNsbtp[1] = stemSet->mNsbcaNsbmaNsbtp[2] = NULL;
    useOneNsbtpAnimation = FALSE;
    if (stemSetParams->mNsbmdCount != 0) {
        stemSet->mNsbmds = HeapAlloc(heap, stemSetParams->mNsbmdCount * 0x6c);
    }
    if (stemSetParams->mNsbcaCount != 0) {
        stemSet->mNsbcaNsbmaNsbtp[0] = HeapAlloc(heap, stemSetParams->mNsbcaCount * 0x38);
    }
    if (stemSetParams->mNsbmaCount != 0) {
        stemSet->mNsbcaNsbmaNsbtp[1] = HeapAlloc(heap, stemSetParams->mNsbmaCount * 0x38);
    }
    if (stemSetParams->mNsbmdCount == 1 && stemSetParams->mNsbtpCount > 1) {
        stemSet->mNsbcaNsbmaNsbtp[2] = HeapAlloc(heap, 0x38);
        useOneNsbtpAnimation = TRUE;
    } else if (stemSetParams->mNsbtpCount != 0) {
        stemSet->mNsbcaNsbmaNsbtp[2] = HeapAlloc(heap, stemSetParams->mNsbtpCount * 0x38);
    }
    for (nsbmdIndex = 0; nsbmdIndex < stemSetParams->mNsbmdCount; nsbmdIndex++) {
        nsbmd = &stemSet->mNsbmds[nsbmdIndex];
        snprintf(fileName, 0x80, "%s.nsbmd", stemSetParams->mStems[nsbmdIndex]);
        lastNsbmdFile = FindSceneFile(fileName);
        InitNsbmdWithoutCullSwap(nsbmd, lastNsbmdFile);
    }
    for (nsbcaIndex = 0; nsbcaIndex < stemSetParams->mNsbcaCount; nsbcaIndex++) {
        nsbcaModel = &stemSet->mNsbmds[nsbcaIndex];
        g = &stemSet->mNsbcaNsbmaNsbtp[0][nsbcaIndex];
        snprintf(fileName, 0x80, "%s.nsbca", stemSetParams->mStems[nsbcaIndex]);
        InitModelAnimation(0, g, nsbcaModel, 1, heap, NULL);
        InitModelAnimationEntries(g, FindSceneFile(fileName), heap);
        SetModelAnimation(g, 0);
    }
    for (nsbmaIndex = 0; nsbmaIndex < stemSetParams->mNsbmaCount; nsbmaIndex++) {
        nsbmaModel = &stemSet->mNsbmds[nsbmaIndex];
        nsbmaAnimation = &stemSet->mNsbcaNsbmaNsbtp[1][nsbmaIndex];
        snprintf(fileName, 0x80, "%s.nsbma", stemSetParams->mStems[nsbmaIndex]);
        InitModelAnimation(4, nsbmaAnimation, nsbmaModel, 1, heap, NULL);
        InitModelAnimationEntries(nsbmaAnimation, FindSceneFile(fileName), heap);
        SetModelAnimation(nsbmaAnimation, 0);
    }
    if (useOneNsbtpAnimation != FALSE) {
        g = stemSet->mNsbcaNsbmaNsbtp[2];
        InitModelAnimation(2, g, stemSet->mNsbmds, stemSetParams->mNsbtpCount, heap, lastNsbmdFile);
        for (nsbtpIndex = 0; nsbtpIndex < stemSetParams->mNsbtpCount; nsbtpIndex++) {
            snprintf(fileName, 0x80, "%s.nsbtp", stemSetParams->mStems[nsbtpIndex]);
            InitModelAnimationEntry(
                g, nsbtpIndex, NNS_G3dGetTexPatAnmByIdx(NNS_G3dGetTexPatAnmSet(FindSceneFile(fileName)), 0), 0, heap);
        }
        SetModelAnimation(g, 0);
    }
}

void InitStemSetArray(void *heap) {
    s16 setIndex;
    StemSet *sourceSet;
    StemSet *copiedSet;

    for (setIndex = 0; setIndex < 8; setIndex++) {
        gStemSets->mSets[setIndex] = NULL;
    }
    if (IsRaceAwardOrStaffRoll() != 0) {
        return;
    }
    for (setIndex = 0; setIndex <= 2; setIndex++) {
        if (setIndex == 2) {
            gStemSets->mSets[setIndex] = HeapAlloc(heap, 0x14);
            sourceSet = gStemSets->mSets[0];
            copiedSet = gStemSets->mSets[2];
            copiedSet->mNsbmds = sourceSet->mNsbmds;
            copiedSet->mNsbcaNsbmaNsbtp[0] = NULL;
            copiedSet->mNsbcaNsbmaNsbtp[1] = sourceSet->mNsbcaNsbmaNsbtp[1];
            copiedSet->mNsbcaNsbmaNsbtp[2] = sourceSet->mNsbcaNsbmaNsbtp[2];
            copiedSet->mNsbmdCount = sourceSet->mNsbmdCount;
        } else {
            gStemSets->mSets[setIndex] = HeapAlloc(heap, 0x14);
            InitNsbmdNsbcaNsbmaNsbtp(heap, gStemSets->mSets[setIndex], &gCountStartStems[(u32) setIndex], setIndex);
        }
    }
    if (gRaceSetup->mMode == MODE_BATTLE || gRaceSetup->mRuleKind == 1) {
        gStemSets->mSets[4] = HeapAlloc(heap, 0x14);
        InitNsbmdNsbcaNsbmaNsbtp(heap, gStemSets->mSets[4], &gWinStems, 4);
        gStemSets->mSets[5] = HeapAlloc(heap, 0x14);
        InitNsbmdNsbcaNsbmaNsbtp(heap, gStemSets->mSets[5], &gLoseStems, 5);
    } else if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        gStemSets->mSets[6] = HeapAlloc(heap, 0x14);
        InitNsbmdNsbcaNsbmaNsbtp(heap, gStemSets->mSets[6], &gCompleteStems, 6);
        gStemSets->mSets[7] = HeapAlloc(heap, 0x14);
        InitNsbmdNsbcaNsbmaNsbtp(heap, gStemSets->mSets[7], &gFailedStems, 7);
    } else {
        gStemSets->mSets[3] = HeapAlloc(heap, 0x14);
        InitNsbmdNsbcaNsbmaNsbtp(heap, gStemSets->mSets[3], &gGoalStems, 3);
    }
}

void StartStemSet(s32 setIndex) {
    StemSet *stemSet;
    ModelAnimation *e;
    u16 nsbmdIndex;
    s32 animationIndex;
    s32 loopCount;

    gStemSets->mSets[8] = gStemSets->mSets[setIndex];
    stemSet = gStemSets->mSets[8];
    if (stemSet == NULL) {
        gStemSets->mShownIndex = 9;
        return;
    }
    gStemSets->mShownIndex = setIndex;
    for (nsbmdIndex = 0; nsbmdIndex < stemSet->mNsbmdCount; nsbmdIndex++) {
        if (stemSet->mNsbcaNsbmaNsbtp[0] != NULL) {
            SetModelAnimation(&stemSet->mNsbcaNsbmaNsbtp[0][nsbmdIndex], 0);
        }
        if (stemSet->mNsbcaNsbmaNsbtp[1] != NULL) {
            SetModelAnimation(&stemSet->mNsbcaNsbmaNsbtp[1][nsbmdIndex], 0);
        }
        if (setIndex == 0 || setIndex == 2) {
            if (setIndex == 2) {
                animationIndex = 1;
            } else {
                animationIndex = 0;
            }
            if (setIndex == 2) {
                loopCount = 5;
            } else {
                loopCount = 3;
            }
            SetModelAnimation(stemSet->mNsbcaNsbmaNsbtp[2], (u16) animationIndex);
            e = stemSet->mNsbcaNsbmaNsbtp[0];
            if (e != NULL) {
                e[nsbmdIndex].mLoopMode = 2;
                e[nsbmdIndex].mLoopCount = loopCount;
            }
            e = stemSet->mNsbcaNsbmaNsbtp[1];
            if (e != NULL) {
                e[nsbmdIndex].mLoopMode = 2;
                e[nsbmdIndex].mLoopCount = loopCount;
            }
        }
    }
}

void UpdateStemSets(void) {
    StemSet *stemSet;
    u16 nsbmdIndex;

    if (gStemSets->mShownIndex == 1 || gStemSets->mShownIndex == 3) {
        gStemSets->mShownFrames++;
        if (gStemSets->mShownFrames > gStemSets->mShownFrameCount) {
            gStemSets->mShownIndex = 9;
        }
    }
    if (gStemSets->mShownIndex != 9) {
        stemSet = gStemSets->mSets[8];
        for (nsbmdIndex = 0; nsbmdIndex < stemSet->mNsbmdCount; nsbmdIndex++) {
            if (stemSet->mNsbcaNsbmaNsbtp[0] != NULL) {
                AdvanceModelAnimation(stemSet->mNsbcaNsbmaNsbtp[0]);
            }
            if (stemSet->mNsbcaNsbmaNsbtp[1] != NULL) {
                AdvanceModelAnimation(stemSet->mNsbcaNsbmaNsbtp[1]);
            }
            if (stemSet->mNsbcaNsbmaNsbtp[2] != NULL) {
                AdvanceModelAnimation(stemSet->mNsbcaNsbmaNsbtp[2]);
            }
        }
    }
    if (gStemSets->mTimedQuad.mEnabled != FALSE) {
        gStemSets->mUpdateFunction(&gStemSets->mTimedQuad);
    }
}

void DrawStemSets(void) {
    MtxFx43 identityMatrix;
    MtxFx43 baseTransform;
    Vec3 baseScale;
    Vec3 *baseTranslation;
    u16 nsbmdIndex;
    Nsbmd *nsbmd;

    MTX_Identity43_(&identityMatrix);
    data_0217029c.mCameraMtx = identityMatrix;
    if (gRaceSetup->mRaceKind != RACE_KIND_NORMAL) {
        return;
    }
    if (gStemSets->mShownIndex != 9) {
        baseTranslation = &baseTransform.mUnk_00[3];
        baseTranslation->x = 0;
        baseTranslation->y = 0;
        baseTranslation->z = 0;
        baseScale = data_0216608c;
        baseTransform.mUnk_00[3].y = data_02166048;
        if (gStemSets->mShownIndex == 2) {
            baseTransform.mUnk_00[3].y = 0x50000;
        }
        MTX_Identity33_(&baseTransform);
        for (nsbmdIndex = 0; nsbmdIndex < gStemSets->mSets[8]->mNsbmdCount; nsbmdIndex++) {
            nsbmd = &gStemSets->mSets[8]->mNsbmds[nsbmdIndex];
            G3i_OrthoW_(0x60000, -0x60000, -0x80000, 0x80000, 0, 0x1000, 0x1f6, 0,
                        (Unk0214ad4c *) data_0217029c.mProjMtx);
            data_0217029c.mFlag &= ~0x50;
            NNS_G3dGlbSetBaseScale(&baseScale);
            MI_Copy36B(&baseTransform, data_0217029c.mPrmBaseRot);
            data_0217029c.mFlag &= ~0xa4;
            NNS_G3dGlbSetBaseTrans(&baseTransform.mUnk_00[3]);
            NNS_G3dGlbFlushP();
            func_01ff8cf0(nsbmd);
        }
    }
    if (gStemSets->mTimedQuad.mEnabled != FALSE) {
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 8;
        reg_G3_SPE_EMI = 0x4210;
        reg_G3_DIF_AMB = 0x42100000;
        reg_G3_MTX_MODE = 0;
        G3_LoadMtx44(&gStemSets->mOrthoMtx);
        reg_G3_TEXIMAGE_PARAM = 0x20000000;
        reg_G3_MTX_MODE = 2;
        reg_G3_MTX_IDENTITY = 0;
        DrawTimedQuad(&gStemSets->mTimedQuad);
    }
}

u32 func_02089f9c(u32 value) {
    return value;
}

void SetStemSet(s32 setIndex) {
    if (setIndex == 9) {
        gStemSets->mShownIndex = setIndex;
        return;
    }
    if (gStemSets->mShownIndex != setIndex || setIndex == 2) {
        StartStemSet(setIndex);
    }
    gStemSets->mShownFrames = 0;
    if (gStemSets->mShownIndex == 1 || gStemSets->mShownIndex == 3) {
        gStemSets->mShownFrameCount = GetModelAnimationFrameCountFixed(gStemSets->mSets[8]->mNsbcaNsbmaNsbtp[0]) >> 12;
    }
}

void StartTimedQuad(Unk02089ecc *timedQuad) {
    timedQuad->mTimer = 0xau;
    timedQuad->mUnk_02 = 0xcu;
    timedQuad->mColor = 0x7fffu;
    timedQuad->mEnabled = 0x1u;
}

void UpdateTimedQuad(Unk02089e68 *timedQuad) {
    timedQuad->mUnk_02 = (s32) (((s64) ((s32) timedQuad->mTimer << 12) * 0x1333 + 0x800) >> 12) >> 12;
    timedQuad->mTimer = timedQuad->mTimer - 1;
    if (timedQuad->mTimer <= 0) {
        timedQuad->mEnabled = 0;
    }
}

void WriteQuadVertex(int vertexIndex) {
    reg_G3_VTX_16 = data_02155ed0[vertexIndex * 3] | data_02155ed0[vertexIndex * 3 + 1] << 16;
    reg_G3_VTX_16 = data_02155ed0[vertexIndex * 3 + 2];
}

void DrawTimedQuad(TimedQuad *timedQuad) {
    u32 *scaleRegister;
    u32 *beginVtxsRegister;
    scaleRegister = ((u32 *) &reg_G3_MTX_SCALE);
    reg_G3_POLYGON_ATTR = (0x090000c0u) | timedQuad->mUnk_02 << 0x10;
    *scaleRegister = 0x8c000;
    *scaleRegister = 0x6e000;
    beginVtxsRegister = ((u32 *) &reg_G3_BEGIN_VTXS);
    *scaleRegister = 0xa000;
    *beginVtxsRegister = 1;
    reg_G3_COLOR = timedQuad->mColor;
    WriteQuadVertex(0);
    WriteQuadVertex(1);
    WriteQuadVertex(2);
    WriteQuadVertex(3);
    reg_G3_END_VTXS = 0;
}

void func_02089d14(u32 tableIndex) {
    gStemSets->mStartFunction = data_02155ec8[tableIndex];
    gStemSets->mUpdateFunction = data_02155ecc[tableIndex];
    gStemSets->mStartFunction(&gStemSets->mTimedQuad);
}
