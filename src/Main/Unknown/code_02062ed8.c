#include "Main/Unknown/code_02062ed8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0203be88.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/code_020649ec.h"
#include "Main/Unknown/code_0206d020.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0206d000.h"
#include "Main/Unknown/code_02064000.h"
#include "Main/Unknown/code_02065000.h"
#include "Main/Unknown/code_0207a870.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02036bec.h"
#include "code_02010c84.h"
#include "code_02012b30.h"
#include "code_02013740.h"
#include "Main/Unknown/code_02087cfc.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_02147000.h"
#include "code_021471bc.h"

static inline void func_0206331c_inline(u32 animationKind, u8 *animation, Nsbmd *nsbmd, void *heap,
                                        const char *modelFile, const char *animationFile, u16 *animationCount) {
    if (animationFile == NULL) {
        *animationCount = 0;
    } else {
        InitModelAnimation(animationKind, animation, nsbmd, 1, heap, modelFile);
        InitModelAnimationEntries(animation, animationFile, heap);
        func_02087cfc(animation, 0, 1);
        SetModelAnimation(animation, 0);
    }
}

void func_02063880(Kart *kart) {
    AdvanceKartCollision(kart);
    if ((data_0217aa14->mUnk_75c & 2) != 0) {
        func_020636f8(kart);
    }
    func_020641f0(kart);
}

void func_02063830(Kart *kart) {
    if (IsMissionRunWithKind2Shapes() != 0) {
        func_0203c1a8(&kart->mPos, kart->mIndex);
    }
    if ((kart->mUnk_4c & 0x1000) != 0) {
        func_0206d138(kart);
    }
    kart->mUnk_4c = kart->mUnk_4c & ~0x1000;
    AdvanceKartMotion(kart);
}

void func_020637e0(Kart *kart) {
    if (IsMissionRunWithKind2Shapes() != 0) {
        func_0203c1a8(&kart->mPos, kart->mIndex);
    }
    if ((kart->mUnk_4c & 0x1000) != 0) {
        func_0206d138(kart);
    }
    kart->mUnk_4c = kart->mUnk_4c & ~0x1000;
    func_020651fc(kart);
}

void func_020637c4(Kart *kart) {
    func_02064f50(kart);
    func_020641f0(kart);
}

void func_020636f8(Kart *kart) {
    ParticipantKartRecordState *b;
    Unk0217aa14_754_04 *recordBase;
    Unk020636f8_B *record;

    recordBase = &data_0217aa14->mUnk_754->mUnk_04;
    record = OFFSET_PTR(Unk020636f8_B, recordBase, 8);
    b = kart->mUnk_514;
    record->mUnk_00 = kart->mPos.x >> 10;
    record->mUnk_02 = (kart->mPos.y - kart->mHopHeight) >> 10;
    record->mUnk_04 = kart->mPos.z >> 10;
    record->mUnk_06 = kart->mForwardSpeed >> 2;
    record->mUnk_0a = kart->mHeadingAngle;
    record->mUnk_10 = kart->mUnk_44;
    record->mUnk_10 =
        record->mUnk_10 | (((b->mPushDirection.x >> 6) & 0xff) << 24 | ((b->mPushDirection.y >> 6) & 0xff) << 16 |
                           ((b->mPushDirection.z >> 6) & 0xff) << 8);
    record->mUnk_14 = kart->mUnk_48;
    record->mUnk_0c = b->mUnk_2c;
    record->mUnk_08 = kart->mTurnAngle;
}

// Also sets the matrix and the per-course flags (CreateCourseModels would be the verb for just finding and building).
void InitCourseModels(void *heap) {
    const char *nsbmdFile;
    const char *nsbtxFile;
    const char *animationFile;
    NNSG3dResMdl *resMdl;
    s32 materialIndex;
    s32 shdwOffMaterialIndices[6];
    s32 i;

    nsbmdFile = FindCourseFile(data_usa_02165404);
    nsbtxFile = FindCourseFile(data_usa_02165418);
    gCourseModels.mNsbmd = HeapAlloc(heap, 0x6c);
    resMdl = InitNsbmdWithTextureInfoCopy(heap, gCourseModels.mNsbmd, (NNSG3dResFileHeader *) nsbmdFile,
                                          (NNSG3dResFileHeader *) nsbtxFile);
    animationFile = FindCourseFile(data_usa_0216542c);
    func_0206331c_inline(2, data_usa_0217ab04, gCourseModels.mNsbmd, heap, nsbmdFile, animationFile,
                         &gCourseModels.mNsbtpAnmObjCount);
    animationFile = FindCourseFile(data_usa_02165440);
    func_0206331c_inline(1, data_0217ab5c, gCourseModels.mNsbmd, heap, nsbmdFile, animationFile,
                         &gCourseModels.mNsbtaAnmObjCount);
    SetNsbmdPolygonIdAll(gCourseModels.mNsbmd, 8);
    NNS_G3dMdlSetMdlXLDepthUpdateAll(resMdl, 1);
    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_OLD_KOOPA_AGB:
            materialIndex = NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, data_usa_02154a00);
            if (materialIndex >= 0) {
                NNS_G3dMdlSetMdlAlpha(resMdl, materialIndex, 0x1e);
                NNS_G3dMdlSetMdlXLDepthUpdate(resMdl, materialIndex, 0);
            }
            break;
        case COURSE_ID_BANK:
            materialIndex = NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, data_usa_02154990);
            if (materialIndex >= 0) {
                NNS_G3dMdlSetMdlXLDepthUpdate(resMdl, materialIndex, 0);
            }
            materialIndex = NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, data_usa_02154a10);
            if (materialIndex >= 0) {
                NNS_G3dMdlSetMdlXLDepthUpdate(resMdl, materialIndex, 0);
            }
            break;
    }
    gCourseModels.mVNsbmd = NULL;
    nsbmdFile = FindCourseFile(data_usa_02165454);
    nsbtxFile = FindCourseFile(data_usa_0216546c);
    if (nsbmdFile != NULL) {
        gCourseModels.mVNsbmd = HeapAlloc(heap, 0x6c);
        InitNsbmdWithTextureInfoCopy(heap, gCourseModels.mVNsbmd, (NNSG3dResFileHeader *) nsbmdFile,
                                     (NNSG3dResFileHeader *) nsbtxFile);
        SetNsbmdPolygonIdAll(gCourseModels.mVNsbmd, 8);
        animationFile = FindCourseFile(data_usa_02165484);
        func_0206331c_inline(1, data_usa_0217ab74, gCourseModels.mVNsbmd, heap, nsbmdFile, animationFile,
                             &gCourseModels.mVNsbtaAnmObjCount);
    }
    shdwOffMaterialIndices[0] = NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, data_usa_021549f0);
    shdwOffMaterialIndices[1] = NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, data_usa_021549c0);
    shdwOffMaterialIndices[2] = NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, data_usa_021549d0);
    shdwOffMaterialIndices[3] = NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, data_usa_021549e0);
    shdwOffMaterialIndices[4] = NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, data_usa_021549b0);
    shdwOffMaterialIndices[5] = NNS_G3dGetResDictIdxByName((u8 *) resMdl + resMdl->mOfsMat + 4, data_usa_021549a0);
    for (i = 0; i < 6; i++) {
        if (shdwOffMaterialIndices[i] >= 0) {
            NNS_G3dMdlSetMdlPolygonID(resMdl, shdwOffMaterialIndices[i], 7);
        }
    }
    MTX_Identity43_(&data_usa_0217abac);
    InitCourseModelsFogEnableFlags();
}

void UpdateCourseModels(void) {
    if (gCourseModels.mNsbtpAnmObjCount != 0) {
        AdvanceModelAnimation(data_usa_0217ab04);
    }
    if (gCourseModels.mNsbtaAnmObjCount != 0) {
        AdvanceModelAnimation(data_0217ab5c);
    }
    if (gCourseModels.mVNsbmd != NULL && gCourseModels.mVNsbtaAnmObjCount != 0) {
        AdvanceModelAnimation(data_usa_0217ab74);
    }
}

void DrawCourseModel(void) {
    DrawNsbmdWithMatrix(gCourseModels.mNsbmd, &data_usa_0217abac, data_usa_02154a20);
}

void DrawCourseModelV(void) {
    if (gCourseModels.mVNsbmd == NULL) {
        return;
    }
    DrawNsbmdWithMatrix(gCourseModels.mVNsbmd, &data_usa_0217abac, data_usa_02154a20);
}

void SetKoopaCourseLight2(void) {
    UnkVec16 lightVector;

    if (gRaceSetup->mCourseId != COURSE_ID_KOOPA) {
        return;
    }
    lightVector = data_usa_021653fc;
    NNS_G3dGlbLightVector(2, lightVector.x, lightVector.y, lightVector.z);
    NNS_G3dGlbLightColor(2, 0x7fff);
}

void InitCourseModelsFogEnableFlags(void) {
    u32 i;
    NNSG3dResMdl *courseResMdl;
    u32 j;
    NNSG3dResMdl *vResMdl;

    gCourseModels.mRestoreFogEnableFlags = FALSE;
    gCourseModels.mSavedFogEnableFlags = 0;
    gCourseModels.mRestoreVFogEnableFlags = FALSE;
    gCourseModels.mSavedVFogEnableFlags = 0;
    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_MANSION:
        case COURSE_ID_DESERT:
        case COURSE_ID_MINI_STAGE2:
            gCourseModels.mRestoreFogEnableFlags = TRUE;
            break;
        case COURSE_ID_RAINBOW:
            gCourseModels.mRestoreVFogEnableFlags = TRUE;
            break;
    }
    if (gCourseModels.mRestoreFogEnableFlags != FALSE) {
        courseResMdl = gCourseModels.mNsbmd->mResMdl;
        for (i = 0; i < courseResMdl->mInfo.mNumMat; i++) {
            if (NNS_G3dMdlGetMdlFogEnableFlag(courseResMdl, i) != 0) {
                gCourseModels.mSavedFogEnableFlags |= (s64) (1 << i);
            }
        }
    } else {
        NNS_G3dMdlSetMdlFogEnableFlagAll(gCourseModels.mNsbmd->mResMdl, 1);
    }
    if (gCourseModels.mVNsbmd == NULL) {
        return;
    }
    if (gCourseModels.mRestoreVFogEnableFlags == FALSE) {
        return;
    }
    vResMdl = gCourseModels.mVNsbmd->mResMdl;
    for (j = 0; j < vResMdl->mInfo.mNumMat; j++) {
        if (NNS_G3dMdlGetMdlFogEnableFlag(vResMdl, j) != 0) {
            gCourseModels.mSavedVFogEnableFlags |= 1 << j;
        }
    }
}

void SetCourseModelsFogEnableFlags(u32 flag) {
    u32 i;
    NNSG3dResMdl *resMdl;
    u32 j;

    if (gCourseModels.mVNsbmd != NULL) {
        if (gCourseModels.mRestoreVFogEnableFlags != FALSE && flag == 0) {
            resMdl = gCourseModels.mVNsbmd->mResMdl;
            for (i = 0; i < resMdl->mInfo.mNumMat; i++) {
                NNS_G3dMdlSetMdlFogEnableFlag(resMdl, i, (gCourseModels.mSavedVFogEnableFlags & (1 << i)) != 0 ? 1 : 0);
            }
        } else {
            NNS_G3dMdlSetMdlFogEnableFlagAll(gCourseModels.mVNsbmd->mResMdl, flag);
        }
    }
    if (gCourseModels.mRestoreFogEnableFlags == FALSE) {
        return;
    }
    if (flag != 0) {
        NNS_G3dMdlSetMdlFogEnableFlagAll(gCourseModels.mNsbmd->mResMdl, 1);
        return;
    }
    resMdl = gCourseModels.mNsbmd->mResMdl;
    for (j = 0; j < resMdl->mInfo.mNumMat; j++) {
        if ((gCourseModels.mSavedFogEnableFlags & (s64) (1 << j)) == 0) {
            NNS_G3dMdlSetMdlFogEnableFlag(resMdl, j, 0);
        }
    }
}

s32 GetCourseModelNsbtpFrame(void) {
    if (gCourseModels.mNsbtpAnmObjCount != 0) {
        return gCourseModels.mNsbtpFrameIndex >> 12;
    }
    return -1;
}
