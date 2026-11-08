#include "Main/Unknown/code_0207ae58.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_0207a14c.h"
#include "Main/Unknown/code_02087cfc.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_02088338.h"
#include "ITCM/code_01ff8000.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_020c70ec.h"
#include "Main/Unknown/code_021112fc.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0200fe74.h"
#include "code_020109c4.h"
#include "code_02012b30.h"
#include "code_02134398.h"
#include "Main/Unknown/code_020681f0.h"

char *BuildCharacterNsbcaPath(u16 characterIndex, s32 animationIndex) {
    char *dirPath = BuildCharacterDirPath(characterIndex);
    const char *pName = LookupCharacterPOrEName(characterIndex, 1);

    snprintf(gCharacterNsbcaPathBuffer, 0x100, gCharacterNsbcaFormat, dirPath, pName,
             gCharacterNsbcaStems[animationIndex].mUnk_00);
    return gCharacterNsbcaPathBuffer;
}

// Returns 0 for the driving animation and 1 for the other three (the ones that loop).
u32 GetCharacterAnimationLoopFlag(int animationIndex) {
    return gCharacterAnimationLoopFlags[animationIndex].mUnk_00;
}

void ClearCharacterTurnAndNextAnimation(struct KartModelsEntry *kartModelsEntry) {
    CharacterAnimationState *animationState;

    kartModelsEntry->mTurnFrameOffset = 0;
    animationState = (CharacterAnimationState *) &kartModelsEntry->mTurnFrameOffset;
    animationState->mNextAnimationPending = FALSE;
    animationState->mNextAnimationIndex = 0;
}

// Steps the turn offset of the driving animation, or the playing animation and its hand-over to the next one.
void AdvanceKartCharacterAnimation(Kart *kart) {
    s32 turnFrameStep;
    KartModelsEntry *modelsEntry;
    CharacterAnimationState *animationState;
    KartModelAnimationView *characterAnimation;
    s32 turnFrameLimit;
    u32 bits48;
    KartModelAnimationView *faceAnimation;

    modelsEntry = kart->mKartModelsEntry;
    animationState = (CharacterAnimationState *) &modelsEntry->mTurnFrameOffset;
    characterAnimation = modelsEntry->mCharacterAnimation;
    turnFrameLimit = animationState->mMiddleFrame;
    turnFrameStep = (kart->mUnk_44 & KART_44_DRIFTING) != 0 ? 0x2000 : 0x1000;
    bits48 = kart->mUnk_48;
    if ((bits48 & KART_48_TURN_LEFT) != 0) {
        if (gRaceSetup->mRaceKind != RACE_KIND_STAFF_ROLL) {
            animationState->mTurnFrameOffset += turnFrameStep;
            if (animationState->mTurnFrameOffset > turnFrameLimit) {
                animationState->mTurnFrameOffset = turnFrameLimit;
            }
        }
    } else if ((bits48 & KART_48_TURN_RIGHT) != 0) {
        if (gRaceSetup->mRaceKind != RACE_KIND_STAFF_ROLL) {
            turnFrameLimit *= -1;
            animationState->mTurnFrameOffset -= turnFrameStep;
            if (animationState->mTurnFrameOffset < turnFrameLimit) {
                animationState->mTurnFrameOffset = turnFrameLimit;
            }
        }
    } else if (animationState->mTurnFrameOffset != 0) {
        if (animationState->mTurnFrameOffset > 0) {
            animationState->mTurnFrameOffset -= turnFrameStep;
            if (animationState->mTurnFrameOffset < 0) {
                animationState->mTurnFrameOffset = 0;
            }
        } else {
            animationState->mTurnFrameOffset += turnFrameStep;
            if (animationState->mTurnFrameOffset > 0) {
                animationState->mTurnFrameOffset = 0;
            }
        }
    }
    if (characterAnimation->mUnk_1a != 0) {
        AdvanceModelAnimation(characterAnimation);
        if (animationState->mNextAnimationPending == FALSE) {
            return;
        }
        if (characterAnimation->mUnk_02 != 1) {
            return;
        }
        func_02087cfc(characterAnimation, characterAnimation->mUnk_1a, 1);
        StartModelAnimationBlend(modelsEntry->mCharacterAnimation, animationState->mNextAnimationIndex);
        faceAnimation = modelsEntry->mFaceAnimation;
        faceAnimation->mUnk_0c = gCharacterFaceFrames[0];
        *faceAnimation->mUnk_1c[faceAnimation->mUnk_1a] = faceAnimation->mUnk_0c;
        animationState->mNextAnimationPending = FALSE;
    } else {
        characterAnimation->mUnk_0c = animationState->mTurnFrameOffset + animationState->mMiddleFrame;
        AdvanceModelAnimationBlend((ModelAnimation *) characterAnimation);
    }
}

void SetCharacterFaceFrameIndex(struct KartModelsEntry *kartModelsEntry, s32 faceFrameIndex) {
    KartModelAnimationView *faceAnimation = kartModelsEntry->mFaceAnimation;

    faceAnimation->mUnk_0c = gCharacterFaceFrames[faceFrameIndex];
    *faceAnimation->mUnk_1c[faceAnimation->mUnk_1a] = faceAnimation->mUnk_0c;
}

void SetCharacterAnimation(struct KartModelsEntry *kartModelsEntry, s32 animationIndex, s32 useBlend) {
    if (useBlend != 0) {
        StartModelAnimationBlend(kartModelsEntry->mCharacterAnimation, animationIndex);
    } else {
        SetModelAnimation(kartModelsEntry->mCharacterAnimation, (u16) animationIndex);
    }
}

static inline s32 func_0207b44c_inline(u32 entryIndex) {
    return *(vs32 *) &gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mTeamIndex;
}

// Starts the win or lose animation of a kart that has finished, from the race result; nothing for the middle results.
void StartKartWinOrLoseAnimation(Kart *kart) {
    u32 finishResult;
    u16 b;
    s32 isRuleKindWinner;
    s32 mode;
    BOOL c;
    s32 normalizedResult;
    CharacterAnimationState *animationState;
    RandomState64 *localRandom;
    u32 bits7c;

    c = TRUE;
    finishResult = c;
    isRuleKindWinner = 0;
    b = gRaceSetup->mKartCount;

    bits7c = kart->mUnk_7c;
    if ((bits7c & 0x10) == 0) {
        return;
    }
    mode = gRaceSetup->mMode;
    if (mode == MODE_BATTLE) {
        return;
    }
    if (mode == MODE_MISSION_RUN) {
        return;
    }
    if (mode != MODE_BATTLE && gRaceSetup->mRuleKind == 1) {
        b = gRaceProgress->mKartAtRank[0];
        if (gRaceSetup->mUseTeams != 0) {
            if (func_0207b44c_inline(b) != func_0207b44c_inline(kart->mIndex)) {
                finishResult = 2;
            } else {
                finishResult = 0;
                kart->mUnk_7c |= 0x2000000;
                isRuleKindWinner = c;
            }
        } else if (kart->mIndex != b) {
            finishResult = 2;
        } else {
            finishResult = 0;
            kart->mUnk_7c |= 0x2000000;
            isRuleKindWinner = c;
        }
    } else if (mode == MODE_TIME_ATTACK) {
        if ((bits7c & 4) == 0) {
            if (IsRaceNewRecordTaFinishRecord() != 0 || IsRaceNewRecordTaBestLapRecord() != 0) {
                finishResult = 0;
            } else {
                finishResult = 2;
            }
        }
    } else if (b > 1) {
        finishResult = ((s16 *) &gFinishResultByRank[(b - 2) * 4])[GetKartRank(kart->mIndex) - 1];
    }
    if (finishResult == 0) {
        KartModelsEntry *modelsEntry = kart->mKartModelsEntry;
        animationState = (CharacterAnimationState *) &modelsEntry->mTurnFrameOffset;
        func_02087cfc(modelsEntry->mCharacterAnimation, (u16) finishResult, 1);
        func_02068a64(kart, 2, 1);
        if (isRuleKindWinner != 0) {
            kart->mUnk_7c |= 0x10000;
        } else {
            animationState->mAnimationChangeTimerSet = TRUE;
            localRandom = &gRaceProgress->mLocalRandom;
            localRandom->mValue = localRandom->mMultiplier * localRandom->mValue + localRandom->mIncrement;
            animationState->mAnimationChangeTimer = (u32) (((localRandom->mValue >> 32) * 200) >> 32);
            animationState->mAnimationChangeTimer += 0x96;
        }
    } else if (finishResult == 2) {
        kart->mUnk_7c |= 0x20000;
        func_02068a64(kart, 3, 1);
    }
    if ((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0) {
        normalizedResult = 1;
        if (finishResult != 0) {
            if (finishResult == 2) {
                normalizedResult = 2;
            }
        } else {
            normalizedResult = 0;
        }
        func_021112fc(normalizedResult);
    }
}

void AdvanceKartAnimationChangeTimer(Kart *kart) {
    CharacterAnimationState *animationState = (CharacterAnimationState *) &kart->mKartModelsEntry->mTurnFrameOffset;
    RandomState64 *localRandom;
    KartModelsEntry *modelsEntry;

    if (animationState->mAnimationChangeTimerSet == FALSE) {
        return;
    }
    animationState->mAnimationChangeTimer--;
    if (animationState->mAnimationChangeTimer > 0) {
        return;
    }
    modelsEntry = kart->mKartModelsEntry;
    if ((kart->mUnk_7c & 0x40) != 0 || modelsEntry->mCharacterAnimation->mUnk_1a == 2) {
        func_02068a64(kart, 0, 1);
    } else if (modelsEntry->mCharacterAnimation->mUnk_1a == 0) {
        func_02068a64(kart, 2, 1);
    }
    localRandom = &gRaceProgress->mLocalRandom;
    localRandom->mValue = localRandom->mMultiplier * localRandom->mValue + localRandom->mIncrement;
    animationState->mAnimationChangeTimer = (u32) (((localRandom->mValue >> 32) * 200) >> 32);
    animationState->mAnimationChangeTimer += 0x96;
}

void StartKartStarModels(Kart *kart) {
    KartModelsEntry *modelsEntry = kart->mKartModelsEntry;
    Nsbmd *firstModel = modelsEntry->mModels[0];
    KartModelAnimationView *faceAnimation = modelsEntry->mFaceAnimation;
    NNSG3dResMdl *resMdl = firstModel->mResMdl;

    NNS_G3dMdlSetMdlPolygonModeAll(resMdl, 2);
    NNS_G3dReleaseMdlTex(resMdl);
    if (faceAnimation != NULL && modelsEntry->mFaceAnimationRemoved == FALSE) {
        NNS_G3dRenderObjRemoveAnmObj((NNSG3dRenderObj *) firstModel, (NNSG3dAnmObj *) faceAnimation->mUnk_1c[0]);
        modelsEntry->mFaceAnimationRemoved = TRUE;
    }
    SetKartModelMaterialColors(resMdl, 2);
    resMdl = modelsEntry->mModels[1]->mResMdl;
    NNS_G3dMdlSetMdlPolygonModeAll(resMdl, 2);
    NNS_G3dReleaseMdlTex(resMdl);
    SetKartModelMaterialColors(resMdl, 2);
    if (modelsEntry->mModels[2] != NULL) {
        resMdl = modelsEntry->mModels[2]->mResMdl;
        NNS_G3dMdlSetMdlPolygonModeAll(resMdl, 2);
        NNS_G3dReleaseMdlTex(resMdl);
        SetKartModelMaterialColors(resMdl, 2);
    }
    modelsEntry->mStarModelsSet = TRUE;
}

void StopKartStarModels(Kart *kart) {
    KartModelsEntry *modelsEntry = kart->mKartModelsEntry;
    Nsbmd *firstModel = modelsEntry->mModels[0];
    KartModelAnimationView *faceAnimation = modelsEntry->mFaceAnimation;
    NNSG3dResMdl *resMdl = firstModel->mResMdl;
    Nsbmd *secondModel;
    NNSG3dResMdl *thirdResMdl;
    Nsbmd *thirdModel;

    NNS_G3dMdlSetMdlPolygonModeAll(resMdl, 0);
    NNS_G3dBindMdlTex(resMdl, firstModel->mResFileEntry.mTexture);
    if (faceAnimation != NULL && modelsEntry->mFaceAnimationRemoved != FALSE) {
        NNS_G3dRenderObjAddAnmObj((NNSG3dRenderObj *) firstModel, (NNSG3dAnmObj *) faceAnimation->mUnk_1c[0]);
        modelsEntry->mFaceAnimationRemoved = FALSE;
    }
    SetKartModelMaterialColors(resMdl, 0);
    secondModel = modelsEntry->mModels[1];
    resMdl = secondModel->mResMdl;
    NNS_G3dMdlSetMdlPolygonModeAll(resMdl, 0);
    NNS_G3dBindMdlTex(resMdl, secondModel->mResFileEntry.mTexture);
    SetKartModelMaterialColors(resMdl, 0);
    thirdModel = modelsEntry->mModels[2];
    if (thirdModel != NULL) {
        thirdResMdl = thirdModel->mResMdl;
        NNS_G3dMdlSetMdlPolygonModeAll(thirdResMdl, 0);
        NNS_G3dBindMdlTex(thirdResMdl, thirdModel->mResFileEntry.mTexture);
        SetKartModelMaterialColors(thirdResMdl, 0);
    }
    modelsEntry->mStarModelsSet = FALSE;
}

void func_0207b13c(Kart *kart) {
    KartModelsEntry *modelsEntry = kart->mKartModelsEntry;
    NNSG3dResMdl *resMdl;

    if (modelsEntry->mStarModelsSet != FALSE) {
        return;
    }
    resMdl = modelsEntry->mModels[0]->mResMdl;
    NNS_G3dMdlSetMdlPolygonModeAll(resMdl, 2);
    SetKartModelMaterialColors(resMdl, 3);
    resMdl = modelsEntry->mModels[1]->mResMdl;
    NNS_G3dMdlSetMdlPolygonModeAll(resMdl, 2);
    SetKartModelMaterialColors(resMdl, 3);
}

void func_0207b0d0(Kart *kart) {
    KartModelsEntry *modelsEntry = kart->mKartModelsEntry;
    NNSG3dResMdl *resMdl;

    if (modelsEntry->mStarModelsSet != FALSE) {
        return;
    }
    resMdl = modelsEntry->mModels[0]->mResMdl;
    NNS_G3dMdlSetMdlPolygonModeAll(resMdl, 0);
    SetKartModelMaterialColors(resMdl, 0);
    resMdl = modelsEntry->mModels[1]->mResMdl;
    NNS_G3dMdlSetMdlPolygonModeAll(resMdl, 0);
    SetKartModelMaterialColors(resMdl, 0);
}

// Plays animation a once, then goes on to animation b.
void StartKartCharacterAnimationOnce(Kart *kart, s32 animationIndex, s32 nextAnimationIndex) {
    KartModelsEntry *modelsEntry = kart->mKartModelsEntry;
    KartModelAnimationView *characterAnimation;
    CharacterAnimationState *animationState = (CharacterAnimationState *) &modelsEntry->mTurnFrameOffset;

    characterAnimation = modelsEntry->mCharacterAnimation;
    if (animationState->mNextAnimationPending != FALSE && characterAnimation->mUnk_1a != 0) {
        func_02087cfc(characterAnimation, characterAnimation->mUnk_1a, 1);
    }
    animationState->mNextAnimationPending = TRUE;
    animationState->mNextAnimationIndex = nextAnimationIndex;
    StartModelAnimationBlend(kart->mKartModelsEntry->mCharacterAnimation, animationIndex);
    func_02087cfc(characterAnimation, (u16) animationIndex, 0);
}

void InitShadowModelFromResMdl(Nsbmd *nsbmd, void *resFile, u32 polygonId) {
    ShadowModel *shadowModel = (ShadowModel *) nsbmd;
    NNSG3dResMdl *resMdl;

    func_02084f10(nsbmd, resFile);
    resMdl = nsbmd->mResMdl;
    shadowModel->mPolygonId = polygonId;
    shadowModel->mAlpha = 0xd;
    shadowModel->mFlags |= 1;
    NNS_G3dMdlSetMdlPolygonMode(resMdl, 0, 3);
    NNS_G3dMdlSetMdlLightEnableFlag(resMdl, 0, 0);
}

NNSG3dResMdl *InitShadowModel(void *model, NNSG3dResFileHeader *resFileHeader, u32 polygonId) {
    ShadowModel *shadowModel = model;
    NNSG3dResMdl *resMdl;

    InitNsbmd(shadowModel, resFileHeader);
    resMdl = shadowModel->mNsbmd.mResMdl;
    shadowModel->mPolygonId = polygonId;
    shadowModel->mAlpha = 0xd;
    shadowModel->mFlags |= 1;
    NNS_G3dMdlSetMdlPolygonMode(resMdl, 0, 3);
    NNS_G3dMdlSetMdlLightEnableFlag(resMdl, 0, 0);
    return shadowModel->mNsbmd.mResMdl;
}

// Draws the shadow with matrix b; when c is not NULL its three words are sent after the matrix.
void DrawShadowWithMatrix(void *model, const void *matrix, Vec3 *extraVector) {
    ShadowModel *shadowModel = model;
    s32 v;
    Vec3 copiedVector;

    if ((shadowModel->mFlags & 1) == 0) {
        return;
    }
    v = 0x1e;
    func_01ff9048(0x14, &v, 1);
    func_01ff9048(0x19, matrix, 0xc);
    if (extraVector != NULL) {
        s32 z = extraVector->z;
        s32 y = extraVector->y;
        s32 x = extraVector->x;
        copiedVector.x = x;
        copiedVector.y = y;
        copiedVector.z = z;
        func_01ff9048(0x1b, &copiedVector, 3);
    }
    func_02084ad8(shadowModel, shadowModel->mAlpha);
    gNsbmdDrawFunctions[shadowModel->mNsbmd.mDrawKind](shadowModel);
    func_02084a88(shadowModel, shadowModel->mAlpha, shadowModel->mPolygonId);
    gNsbmdDrawFunctions[shadowModel->mNsbmd.mDrawKind](shadowModel);
}

void func_0207ae58(ShadowModel *shadowModel) {
    if ((shadowModel->mFlags & 1) == 0) {
        return;
    }
    func_02084ad8(shadowModel, shadowModel->mAlpha);
    gNsbmdDrawFunctions[shadowModel->mNsbmd.mDrawKind](shadowModel);
    func_02084a88(shadowModel, shadowModel->mAlpha, shadowModel->mPolygonId);
    gNsbmdDrawFunctions[shadowModel->mNsbmd.mDrawKind](shadowModel);
}
