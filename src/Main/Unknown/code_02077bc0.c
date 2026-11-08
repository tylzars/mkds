#include "Main/Unknown/code_02077bc0.h"
#include "Main/Unknown/code_0207ae58.h"
#include "code_02012b30.h" // NNSG3dResFileHeader

#include "Main/Unknown/code_02036820.h"
#include "code_020169a4.h"
#include "gfd_LinkedListTexVramMan.h"
#include "gfd_LinkedListPlttVramMan.h"
#include "code_020172d0.h"
#include "Main/Unknown/code_020483e4.h"
#include "code_020176c0.h"
#include "code_0214a5e0.h"
#include "Main/Unknown/code_02048000.h"
#include "code_02013740.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02088000.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/code_02088338.h"
#include "Main/Unknown/code_0207adf8.h"
#include "Main/Unknown/code_02017000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "gx.h"
#include "Main/Unknown/code_02076cd0.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "code_0200eddc.h"
#include "00/code_02181f98.h"
#include "01/code_021a2398.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020799a0.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_021108bc.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "gx_load3d.h"
#include "code_0200fe74.h"
#include "code_02010c84.h"
#include "code_02016468.h"
#include "code_02147288.h"
#include "code_0214a748.h"
#include "code_0214d018.h"
#include "code_02146cbc.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02039860.h"
#include "code_020176b0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02077000.h"
#include "gecom.h"
#include "Main/Unknown/code_0208533c.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02170000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_02079a3c.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_02056444.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0207a14c.h"
#include "Main/Unknown/code_020638c0.h"
#include "Main/Unknown/code_02079a14.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208537c.h"
#include "code_02134398.h"
#include "code_02133048.h"
#include "res_struct_accessor.h"
#include "Main/Unknown/code_02079a04.h"
#include "Main/Unknown/code_02087cd0.h"
#include "Main/Unknown/code_02079b40.h"
#include "Main/Unknown/code_02079b60.h"
#include "Main/Unknown/code_02079b9c.h"
#include "Main/Unknown/code_02079bcc.h"
#include "Main/Unknown/code_02079c0c.h"
#include "Main/Unknown/code_0207a104.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "01/code_0218155c.h"
#include "Main/Unknown/code_0207a30c.h"
#include "Main/Unknown/code_0207a32c.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0207a68c.h"
#include "Main/Unknown/code_0207a6b0.h"
#include "Main/Unknown/code_0207a73c.h"
#include "Main/Unknown/code_0207a74c.h"
#include "Main/Unknown/code_0207a780.h"
#include "Main/Unknown/code_0207a790.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_0207a7ec.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_0207a7fc.h"
#include "Main/Unknown/code_02066ac0.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_0207a870.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_0207a8c4.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02063b70.h"
#include "Main/Unknown/code_020649ec.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_0208c188.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_02086058.h"
#include "Main/Unknown/code_020733ec.h"
#include "ITCM/code_01ffba68.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "code_021471bc.h"

void func_0207ad88(ShadowModel *shadowModel, u32 b, u32 c) {
    if ((shadowModel->mFlags & 1) != 0) {
        func_02084ad8(shadowModel, shadowModel->mAlpha);
        data_02155a20[shadowModel->mNsbmd.mDrawKind](shadowModel);
        func_02084a88(shadowModel, shadowModel->mAlpha, shadowModel->mPolygonId);
        data_02155a20[shadowModel->mNsbmd.mDrawKind](shadowModel);
    }
}

void InitKarts(u32 kartCount) {
    u16 i;
    void *heap = GetHeap(GetCurrentHeapCall());
    EntryKartCounters *entryKartCounters;
    gKarts = HeapAlloc(heap, kartCount * 0x5a8);
    gKartCount = kartCount;
    entryKartCounters = HeapAlloc(heap, 0x1c);
    gEntryKartCounters = entryKartCounters;
    gKillerItemKartIndex = 0;
    gMinKartDistanceSquaredPresent = 0;
    gMinKartDistanceSquared = -1;
    entryKartCounters->mUnk_00 = 0;
    entryKartCounters->mUnk_04 = 0;
    entryKartCounters->mUnk_08 = 0;
    entryKartCounters->mUnk_0c = 0;
    entryKartCounters->mUnk_10 = 0;
    entryKartCounters->mUnk_14 = 0;
    entryKartCounters->mUnk_18 = 0;
    data_usa_021658bc = gRaceSetup->mMode == MODE_BATTLE ? 1 : 2;
    func_02073630();
    RegisterKartAiCallbacks();
    InitKartEffects(kartCount);
    gMissionRunKind2ShapesPresent = 0;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        if (gCourseMap->mKind2ShapeCountInMode4 != 0) {
            gMissionRunKind2ShapesPresent = 1;
        }
    }
    for (i = 0; i < kartCount; i++) {
        gKarts[i].mIndex = i;
        gKarts[i].mEntryIndex = gRaceSetup->mCurrentEntries[i].mPlayer.mIndex;
        InitKart(&gKarts[i], gKartDefaultSlotFunctions);
    }
    gKartKind3ShapeMask = 0;
}

void UpdateKarts(void) {
    s32 i;
    Kart *kart = gKarts;
    gMinKartDistanceSquaredPresent = 0;
    gMinKartDistanceSquared = -1;
    for (i = 0; i < gKartCount; i++) {
        UpdateKartPrevValuesAndClearFlags(kart);
        kart++;
    }
    func_0207a32c();
    kart = gKarts;
    for (i = 0; i < gKartCount; i++) {
        kart->mSlotFunctions[3](kart);
        kart++;
    }
    kart = gKarts;
    for (i = 0; i < gKartCount; i++) {
        kart->mSlotFunctions[4](kart);
        kart++;
    }
}

void UpdateKartSoundDistancesSquared(void) {
    Kart *kart = gKarts;
    s16 i;
    for (i = 0; i < gKartCount; i++) {
        kart->mSlotFunctions[2](kart);
        kart++;
    }
}

void DrawKarts(void) {
    s32 i = 0;
    u16 *kartIndices = func_02086058();
    (gKarts[gRaceSetup->mEntryIndex].mKartModelsEntry)->mUnk_060 = TRUE;
    for (; i < gKartCount; i++) {
        DrawKart(&gKarts[*kartIndices]);
        kartIndices++;
    }
}

void func_0207a990(void) {
    s32 i;
    for (i = 0; i < gKartCount; i++) {
        CallKartSlot8(&gKarts[i]);
    }
    gKarts = NULL;
}

Kart *GetKart(s32 kartIndex) {
    return &gKarts[kartIndex];
}

void GetKartPos(Vec3 *pos, s32 kartIndex) {
    *pos = *gKarts[kartIndex].mPosSource;
}

void func_0207a91c(Vec3 *pos, u8 kartIndex) {
    *pos = *gKarts[kartIndex].mUnk_534;
}

void GetKartPrevPos(Vec3 *pos, s32 kartIndex) {
    *pos = gKarts[kartIndex].mPrevPos;
}

void GetKartScale(Vec3 *scale, s32 kartIndex) {
    *scale = gKarts[kartIndex].mScale;
}

u32 GetKartItemEffect(u32 kartIndex) {
    return gKarts[kartIndex].mItemEffect;
}

u16 GetKartHeadingAngle(s32 kartIndex) {
    return gKarts[kartIndex].mHeadingAngle;
}

u32 IsMissionRunWithKind2Shapes(void) {
    return gMissionRunKind2ShapesPresent;
}

s32 func_0207a84c(s32 kartIndex) {
    return func_02068eac(&gKarts[kartIndex]);
}

void func_0207a828(s32 kartIndex) {
    func_02066fe0(&gKarts[kartIndex]);
}

BOOL func_0207a7fc(s32 kartIndex) {
    return (gKarts[kartIndex].mUnk_48 & 1) != 0;
}

u32 GetKartForwardSpeedRatio(void) {
    return gKartForwardSpeedRatio;
}

// Sets bit i when the kart is inside kind 3 shape list i.
void SetKartKind3ShapeMask(s32 kartIndex) {
    u16 i;

    gKartKind3ShapeMask = 0;
    for (i = 0; i < 8; i++) {
        if (IsKartInCourseMapKind3ShapeList(kartIndex, i) != 0) {
            gKartKind3ShapeMask |= 1 << i;
        }
    }
}

u32 GetKartKind3ShapeMask(void) {
    return gKartKind3ShapeMask;
}

// Stores the forward speed as a part of the speed limit, 0x1000 = 1.0.
void SetKartForwardSpeedRatio(s32 forwardSpeed) {
    gKartForwardSpeedRatio = ((s64) forwardSpeed * gKartSpeedLimitReciprocal + 0x800) >> 12;
}

void SetKartSpeedLimitReciprocal(u32 speedLimitReciprocal) {
    gKartSpeedLimitReciprocal = speedLimitReciprocal;
}

void func_0207a70c(s32 kartIndex) {
    if (kartIndex == gRaceSetup->mEntryIndex) {
        gEntryKartCounters->mUnk_08++;
    }
}

void func_0207a6c0(Kart *kart) {
    if (kart->mIndex != gRaceSetup->mEntryIndex) {
        return;
    }
    if (kart->mUnk_4c & 0x40) {
        return;
    }
    if (!(kart->mUnk_48 & 0x20000000)) {
        gEntryKartCounters->mUnk_0c++;
    }
}

EntryKartCounters *GetEntryKartCounters(void) {
    return gEntryKartCounters;
}

u32 func_0207a68c(int kartIndex) {
    return func_0206c0a8(&gKarts[kartIndex]);
}

void SetKartModelsFogEnable(s32 fogEnableFlag) {
    s32 i;
    Kart *kart = gKarts;
    KartModelsEntry *entry;
    for (i = 0; i < gKartCount; i++) {
        entry = kart->mKartModelsEntry;
        NNS_G3dMdlSetMdlFogEnableFlagAll(entry->mModels[1]->mResMdl, fogEnableFlag);
        NNS_G3dMdlSetMdlFogEnableFlagAll(entry->mModels[0]->mResMdl, fogEnableFlag);
        if (entry->mModels[2] != NULL) {
            NNS_G3dMdlSetMdlFogEnableFlagAll(entry->mModels[2]->mResMdl, fogEnableFlag);
        }
        kart++;
    }
}

BOOL func_0207a5c4(s32 kartIndex) {
    return (gKarts[kartIndex].mUnk_48 & 0x800) != 0 ? 1 : 0;
}

BOOL func_0207a574(void) {
    Kart *kart = &gKarts[gRaceSetup->mEntryIndex];
    if (kart->mState != KART_STATE_NORMAL || (kart->mUnk_48 & 0x4000000) != 0) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_0207a538(void) {
    return (gKarts[gRaceSetup->mEntryIndex].mUnk_44 & 0xc0) != 0 ? 1 : 0;
}

BOOL func_0207a4fc(void) {
    return (gKarts[gRaceSetup->mEntryIndex].mUnk_48 & 0x1000) != 0 ? 1 : 0;
}

void func_0207a32c(void) {
    s32 kartIndices[3];
    u32 kartRank = GetKartRank((u16) gRaceSetup->mEntryIndex);
    u16 i;
    u16 k;
    s32 kartIndex;
    Kart *kart;
    if (gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
        for (k = 0; k < 3; k++) {
            gKarts[k].mUnk_4c |= 0x8000;
        }
        return;
    }
    kartIndices[0] = gRaceSetup->mEntryIndex;
    if (kartRank == 1) {
        kartIndices[1] = GetKartIndexAtRank(2);
        if (kartIndices[1] >= 0) {
            if ((gKarts[kartIndices[1]].mKartModelsEntry)->mUnk_060 != FALSE) {
                kartIndices[1] = -1;
            }
        }
    } else {
        kartIndices[1] = GetKartIndexAtRank((u16) (kartRank - 1));
        if (kartIndices[1] >= 0) {
            if ((gKarts[kartIndices[1]].mKartModelsEntry)->mUnk_060 != FALSE) {
                kartIndices[1] = -1;
            }
        }
        if (kartRank < gRaceSetup->mKartCount) {
            kartIndex = GetKartIndexAtRank((u16) (kartRank + 1));
            if (kartIndex >= 0) {
                kart = &gKarts[kartIndex];
                kart->mUnk_4c |= 0x40000;
            }
        }
    }
    for (i = 0; i < data_usa_021658bc; i++) {
        kartIndex = kartIndices[i];
        if (kartIndex >= 0) {
            kart = &gKarts[kartIndex];
            if ((kart->mUnk_4c & 0x10000000) == 0) {
                kart->mUnk_4c |= 0x8000;
            }
        }
    }
}

u32 GetKillerItemKartIndex(void) {
    return (gKillerItemKartIndex);
}

void SetKillerItemKartIndex(u32 kartIndex) {
    gKillerItemKartIndex = kartIndex;
}

// Keeps the smallest value of the frame; UpdateKarts clears it.
void SetMinKartDistanceSquared(s32 distanceSquared) {
    if (gMinKartDistanceSquared < 0 || distanceSquared < gMinKartDistanceSquared) {
        gMinKartDistanceSquared = distanceSquared;
        gMinKartDistanceSquaredPresent = 1;
    }
}

BOOL TryGetMinKartDistanceSquared(s32 *distanceSquared) {
    if (gMinKartDistanceSquaredPresent == 0) {
        return FALSE;
    }
    *distanceSquared = gMinKartDistanceSquared;
    return TRUE;
}

BOOL func_0207a218(void) {
    BOOL result = TRUE;
    s32 mode = gRaceSetup->mMode;
    if (mode == MODE_MISSION_RUN) {
        Kart *kart = &gKarts[gRaceSetup->mEntryIndex];
        if (kart->mState != KART_STATE_NORMAL || (kart->mUnk_48 & 0x2000840) != 0 ||
            (kart->mUnk_44 & KART_44_ON_GROUND) == 0 || (mode != MODE_MISSION_RUN ? 0 : func_ov001_021816b4()) != 0) {
            result = FALSE;
        }
    }
    return result;
}

void SetKartModelMaterialColors(NNSG3dResMdl *mdl, u32 colorSet) {
    u32 diffColor;
    u32 ambColor;
    u32 specColor;
    u32 emiColor;
    switch (colorSet) {
        case 0: {
            u16 *courseColors = gKartModels->mCourseColors;
            diffColor = courseColors[0];
            ambColor = courseColors[1];
            specColor = courseColors[2];
            emiColor = courseColors[3];
            break;
        }
        case 2:
            ambColor = 0;
            specColor = 0;
            emiColor = 0;
            diffColor = 0x2108;
            break;
        case 3:
            ambColor = 0;
            specColor = 0;
            diffColor = 0x2108;
            emiColor = 0x4210;
            break;
        case 1:
            diffColor = 0x7fff;
            ambColor = 0x14a5;
            emiColor = 0x2108;
            specColor = 0;
            break;
    }
    NNS_G3dMdlSetMdlDiffAll(mdl, diffColor);
    NNS_G3dMdlSetMdlAmbAll(mdl, ambColor);
    NNS_G3dMdlSetMdlSpecAll(mdl, specColor);
    NNS_G3dMdlSetMdlEmiAll(mdl, emiColor);
}

u16 GetKartCourseDiffColor(void) {
    return gKartModels->mCourseColors[0];
}

u16 GetKartCourseEmiColor(void) {
    return gKartModels->mCourseColors[3];
}

u16 GetKartCourseAmbColor(void) {
    return gKartModels->mCourseColors[1];
}

void StartKartModelColorBlend(struct KartModelsEntry *kartModelsEntry, u16 targetDiffColor, u16 targetEmiColor,
                              u16 targetAmbColor) {
    KartModelColorBlend *blend;

    blend = &kartModelsEntry->mColorBlend;
    blend->mUnk_06 = kartModelsEntry->mColorBlend.mDiffColor & 0x1f;
    blend->mUnk_0c = (s16) (targetDiffColor & 0x1f) - blend->mUnk_06;
    blend->mUnk_08 = (kartModelsEntry->mColorBlend.mDiffColor >> 5) & 0x1f;
    blend->mUnk_0e = (s16) ((targetDiffColor >> 5) & 0x1f) - blend->mUnk_08;
    blend->mUnk_0a = (kartModelsEntry->mColorBlend.mDiffColor >> 10) & 0x1f;
    blend->mUnk_10 = (s16) ((targetDiffColor >> 10) & 0x1f) - blend->mUnk_0a;
    blend->mUnk_12 = blend->mEmiColor & 0x1f;
    blend->mUnk_18 = (s16) (targetEmiColor & 0x1f) - blend->mUnk_12;
    blend->mUnk_14 = (blend->mEmiColor >> 5) & 0x1f;
    blend->mUnk_1a = (s16) ((targetEmiColor >> 5) & 0x1f) - blend->mUnk_14;
    blend->mUnk_16 = (blend->mEmiColor >> 10) & 0x1f;
    blend->mUnk_1c = (s16) ((targetEmiColor >> 10) & 0x1f) - blend->mUnk_16;
    blend->mUnk_1e = blend->mAmbColor & 0x1f;
    blend->mUnk_24 = (s16) (targetAmbColor & 0x1f) - blend->mUnk_1e;
    blend->mUnk_20 = (blend->mAmbColor >> 5) & 0x1f;
    blend->mUnk_26 = (s16) ((targetAmbColor >> 5) & 0x1f) - blend->mUnk_20;
    blend->mUnk_22 = (blend->mAmbColor >> 10) & 0x1f;
    blend->mUnk_28 = (s16) ((targetAmbColor >> 10) & 0x1f) - blend->mUnk_22;
    blend->mBlendProgress = 0;
}

s32 AdvanceKartModelColorBlend(struct KartModelsEntry *kartModelsEntry, s32 blendAmount) {
    KartModelColorBlend *blend = &kartModelsEntry->mColorBlend;
    BOOL finished = FALSE;

    if (blend->mBlendProgress < 0x1000) {
        blend->mBlendProgress += blendAmount;
        if (blend->mBlendProgress >= 0x1000) {
            blend->mBlendProgress = 0x1000;
            finished = TRUE;
        }
        blend->mDiffColor =
            (s16) (blend->mUnk_06 + (s32) (((s64) blend->mUnk_0c * blend->mBlendProgress + 0x800) >> 12)) +
            ((s16) (blend->mUnk_08 + (s32) (((s64) blend->mUnk_0e * blend->mBlendProgress + 0x800) >> 12)) << 5) +
            ((s16) (blend->mUnk_0a + (s32) (((s64) blend->mUnk_10 * blend->mBlendProgress + 0x800) >> 12)) << 10);
        NNS_G3dMdlSetMdlDiffAll(kartModelsEntry->mModels[0]->mResMdl, blend->mDiffColor);
        NNS_G3dMdlSetMdlDiffAll(kartModelsEntry->mModels[1]->mResMdl, blend->mDiffColor);
        if (kartModelsEntry->mModels[2] != NULL) {
            NNS_G3dMdlSetMdlDiffAll(kartModelsEntry->mModels[2]->mResMdl, blend->mDiffColor);
        }
        blend->mEmiColor =
            (s16) (blend->mUnk_12 + (s32) (((s64) blend->mUnk_18 * blend->mBlendProgress + 0x800) >> 12)) +
            ((s16) (blend->mUnk_14 + (s32) (((s64) blend->mUnk_1a * blend->mBlendProgress + 0x800) >> 12)) << 5) +
            ((s16) (blend->mUnk_16 + (s32) (((s64) blend->mUnk_1c * blend->mBlendProgress + 0x800) >> 12)) << 10);
        NNS_G3dMdlSetMdlEmiAll(kartModelsEntry->mModels[0]->mResMdl, blend->mEmiColor);
        NNS_G3dMdlSetMdlEmiAll(kartModelsEntry->mModels[1]->mResMdl, blend->mEmiColor);
        if (kartModelsEntry->mModels[2] != NULL) {
            NNS_G3dMdlSetMdlEmiAll(kartModelsEntry->mModels[2]->mResMdl, blend->mEmiColor);
        }
        {
            s16 x = blend->mUnk_1e + (s32) (((s64) blend->mUnk_24 * blend->mBlendProgress + 0x800) >> 12);
            s16 y = blend->mUnk_20 + (s32) (((s64) blend->mUnk_26 * blend->mBlendProgress + 0x800) >> 12);
            s16 z = blend->mUnk_22 + (s32) (((s64) blend->mUnk_28 * blend->mBlendProgress + 0x800) >> 12);
            NNS_G3dMdlSetMdlAmbAll(kartModelsEntry->mModels[0]->mResMdl, blend->mAmbColor);
            NNS_G3dMdlSetMdlAmbAll(kartModelsEntry->mModels[1]->mResMdl, blend->mAmbColor);
            if (kartModelsEntry->mModels[2] != NULL) {
                NNS_G3dMdlSetMdlAmbAll(kartModelsEntry->mModels[2]->mResMdl, blend->mAmbColor);
            }
            blend->mAmbColor = x + (y << 5) + (z << 10);
        }
    } else {
        finished = TRUE;
    }
    return finished;
}

void SetKartModelsEntryCourseColors(struct KartModelsEntry *kartModelsEntry) {
    u16 *courseColors = gKartModels->mCourseColors;
    u32 diffColor;
    u32 emiColor;
    u32 ambColor;

    diffColor = courseColors[0];
    emiColor = courseColors[3];
    ambColor = courseColors[1];
    NNS_G3dMdlSetMdlDiffAll(kartModelsEntry->mModels[0]->mResMdl, diffColor);
    NNS_G3dMdlSetMdlDiffAll(kartModelsEntry->mModels[1]->mResMdl, diffColor);
    NNS_G3dMdlSetMdlEmiAll(kartModelsEntry->mModels[0]->mResMdl, emiColor);
    NNS_G3dMdlSetMdlEmiAll(kartModelsEntry->mModels[1]->mResMdl, emiColor);
    NNS_G3dMdlSetMdlAmbAll(kartModelsEntry->mModels[0]->mResMdl, ambColor);
    NNS_G3dMdlSetMdlAmbAll(kartModelsEntry->mModels[1]->mResMdl, ambColor);
    if (kartModelsEntry->mModels[2] != NULL) {
        NNS_G3dMdlSetMdlDiffAll(kartModelsEntry->mModels[2]->mResMdl, diffColor);
        NNS_G3dMdlSetMdlEmiAll(kartModelsEntry->mModels[2]->mResMdl, emiColor);
        NNS_G3dMdlSetMdlAmbAll(kartModelsEntry->mModels[2]->mResMdl, ambColor);
    }
}

KartModelsEntry *GetKartModelsEntry(u32 kartIndex) {
    return &gKartModels->mKartModelsEntries[kartIndex];
}

void *GetKartModelResMdl(u32 kartIndex) {
    return gKartModels->mKartModelsEntries[kartIndex].mModels[1]->mResMdl;
}

// Shows (b non-zero) or hides the tire material of the kart model.
void SetKartModelTireAlpha(struct KartModelsEntry *kartModelsEntry, s32 visible) {
    NNS_G3dMdlSetMdlAlpha(kartModelsEntry->mModels[1]->mResMdl, gKartModels->mKartTireMaterialIndex,
                          visible != 0 ? 0x1f : 0);
}

void *GetKillerItem(void) {
    return &gKartModels->mKillerItem;
}

void *GetKillerItemS(void) {
    return &gKartModels->mKillerItemS;
}

void *GetKillerItemNsbca(void) {
    return &gKartModels->mKillerItemNsbca;
}

u32 GetKartVariant(u32 kartIndex) {
    return gKartModels->mKartModelsEntries[kartIndex].mVariant;
}

#pragma thumb on
void InitKartModelsEntry(void *entry) {
    u32 value0 = (u32) entry;
    u32 value1;
    u32 value2;
    u32 entryAddress;
    entryAddress = (value0) + (0u);
    value0 = 0u;
    value1 = ~(value0);
    *(u32 *) ((entryAddress) + 0u) = value1;
    *(u32 *) ((entryAddress) + 4u) = value1;
    *(u32 *) ((entryAddress) + 8u) = value0;
    *(u32 *) ((entryAddress) + 12u) = value0;
    *(u32 *) ((entryAddress) + 16u) = value0;
    *(u32 *) ((entryAddress) + 20u) = value0;
    *(u32 *) ((entryAddress) + 24u) = value0;
    *(u32 *) ((entryAddress) + 28u) = value0;
    *(u32 *) ((entryAddress) + 32u) = value0;
    value0 = (entryAddress) + (0u);
    value0 = (value0) + 36u;
    func_02079a04(value0);
    value0 = 0u;
    *(u32 *) ((entryAddress) + 84u) = value0;
    *(u32 *) ((entryAddress) + 88u) = value0;
    *(u32 *) ((entryAddress) + 92u) = value0;
    *(u32 *) ((entryAddress) + 96u) = value0;
    *(u32 *) ((entryAddress) + 100u) = value0;
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 104u;
    *(u16 *) ((value1) + 0u) = value0;
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 172u;
    *(u32 *) ((value1) + 0u) = value0;
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 176u;
    *(u32 *) ((value1) + 0u) = value0;
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 110u;
    *(u16 *) ((value1) + 0u) = value0;
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 110u;
    value2 = *(const u16 *) ((value1) + 0u);
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 108u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 108u;
    value2 = *(const u16 *) ((value1) + 0u);
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 106u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 116u;
    *(u16 *) ((value1) + 0u) = value0;
    value1 = 116u;
    value2 = *(const s16 *) ((entryAddress) + (value1));
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 114u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = 114u;
    value2 = *(const s16 *) ((entryAddress) + (value1));
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 112u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 122u;
    *(u16 *) ((value1) + 0u) = value0;
    value1 = 122u;
    value2 = *(const s16 *) ((entryAddress) + (value1));
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 120u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = 120u;
    value2 = *(const s16 *) ((entryAddress) + (value1));
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 118u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 128u;
    *(u16 *) ((value1) + 0u) = value0;
    value1 = 128u;
    value2 = *(const s16 *) ((entryAddress) + (value1));
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 126u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = 126u;
    value2 = *(const s16 *) ((entryAddress) + (value1));
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 124u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 134u;
    *(u16 *) ((value1) + 0u) = value0;
    value1 = 134u;
    value2 = *(const s16 *) ((entryAddress) + (value1));
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 132u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = 132u;
    value2 = *(const s16 *) ((entryAddress) + (value1));
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 130u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 140u;
    *(u16 *) ((value1) + 0u) = value0;
    value1 = 140u;
    value2 = *(const s16 *) ((entryAddress) + (value1));
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 138u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = 138u;
    value2 = *(const s16 *) ((entryAddress) + (value1));
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 136u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 146u;
    *(u16 *) ((value1) + 0u) = value0;
    value1 = 146u;
    value2 = *(const s16 *) ((entryAddress) + (value1));
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 144u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = 144u;
    value2 = *(const s16 *) ((entryAddress) + (value1));
    value1 = (entryAddress) + (0u);
    value1 = (value1) + 142u;
    *(u16 *) ((value1) + 0u) = value2;
    entryAddress = (entryAddress) + 148u;
    *(u16 *) ((entryAddress) + 0u) = value0;
}
#pragma thumb off

#pragma thumb on

void func_02079a14(KartModelsEntry *kartModelsEntry) {
    ResetModelAnimationLooping((ModelAnimation *) kartModelsEntry->mUnk_098,
                               GetModelAnimationFrameCountFixed(&gKartModels->mKillerItemNsbca));
}

#pragma thumb off

#pragma thumb on
void func_02079a04(u32 animationStateAddress) {
    u32 animationState = animationStateAddress;
    u32 zero;
    zero = 0u;
    *(u32 *) ((animationState) + 0u) = zero;
    *(u32 *) ((animationState) + 20u) = zero;
    *(u16 *) ((animationState) + 24u) = zero;
    *(u32 *) ((animationState) + 4u) = zero;
    *(u16 *) ((animationState) + 16u) = zero;
}
#pragma thumb off

#pragma thumb on

// TRUE when the entry's character files use the P name list.
BOOL IsCharacterPNameUsed(s32 kartIndex) {
    BOOL pNameUsed = TRUE;
    s32 b = pNameUsed;
    s32 c = pNameUsed;
    s32 isEntryOrFollowedKart = pNameUsed;
    if (kartIndex != gRaceSetup->mEntryIndex && kartIndex != gRaceSetup->mFollowedKartIndex) {
        isEntryOrFollowedKart = 0;
    }
    if (isEntryOrFollowedKart == 0 && gRaceSetup->mMode != MODE_MISSION_RUN) {
        c = 0;
    }
    if (c == 0 && IsRaceAwardOrStaffRoll() == 0) {
        b = 0;
    }
    if (b == 0 && gRaceSetup->mMode != MODE_TIME_ATTACK) {
        pNameUsed = FALSE;
    }
    if (pNameUsed != FALSE) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

// Stores the kart index modulo 3.
void SetKartModelsEntryVariant(KartModelsEntry *kartModelsEntry, int kartIndex) {
    u16 variant;
    variant = kartIndex % 3;
    kartModelsEntry->mVariant = variant;
}

#pragma thumb off

#pragma thumb on

void InitKartModels(void *heap, u32 kartCount) {
    u8 *kartOffsetFile;
    u16 i;
    KartModelsEntry *entry;
    KartModelsEntry *entries;
    kartOffsetFile = FindKartModelFile("kartoffsetdata.bin");
    SetKartModelPathPrefix(0);
    gKartModelMenu = NULL;
    gKartModels = HeapAlloc(heap, 0x144);
    gKartModels->mKartModelsEntries = HeapAlloc(heap, kartCount * 0xb4);
    gKartModels->mCourseColors = func_02047950("kartcrsmat.bin");
    gKartModels->mCourseColors = gKartModels->mCourseColors + (gRaceSetup->mCourseId << 2) - 4;
    gKartModels->mKartAPalette = LoadKartAPaletteFromKartModelFile();
    gKartModels->mHeyhoPalettes = NULL;
    gKartModels->mPFaceanimNsbtpFile = func_02047950((const char *) BuildPFaceanimNsbtpPath());
    gKartModels->mKartCount = kartCount;
    gKartModels->mKartTireMaterialIndex = 0;
    CreateKartPhysicalParamTable(heap, kartCount);
    SetKartAiParamRow();
    CreateKillerItem(heap);
    for (i = 0; i < gKartModels->mKartCount; i++) {
        entries = gKartModels->mKartModelsEntries;
        entry = &entries[i];
        InitKartModelsEntry(entry);
        entry->mUnk_0b0 = gRaceSetup->mCurrentEntries[i].mPlayer.mUnk_25;
        func_02079a14(entry);
        entries[i].mCharacterIndex = gRaceSetup->mCurrentEntries[i].mCharacterIndex;
        entry->mKartIndex = gRaceSetup->mCurrentEntries[i].mKartIndex;
        SetKartModelsEntryVariant(entry, entry->mKartIndex);
        entry->mKartOffsetData = HeapAlloc(heap, 0xe0);
        MI_CpuCopy8(kartOffsetFile + entry->mKartIndex * 0xe0, entry->mKartOffsetData, 0xe0);
        CopyKartPhysicalParams(i, (u16) entry->mKartIndex, (u16) entries[i].mCharacterIndex);
    }
    func_02079678(heap, 1);
    func_0204775c();
    func_02079678(heap, 0);
    for (i = 0; i < gKartModels->mKartCount; i++) {
        entry = &gKartModels->mKartModelsEntries[i];
        UploadKartModelsEntryPalettes(entry, IsCharacterPNameUsed(i));
    }
    {
        Nclr *nclr;
        LoadNclrData(&nclr, func_02047950("/character/heyho/HH_color.NCLR"));
        gKartModels->mHeyhoPalettes = (HeyhoPalette *) nclr->mData;
    }
}

void func_02079678(void *heap, s32 firstPass) {
    BOOL isVariantZero;
    KartModelsEntry *entry;
    s32 pNameUsed;
    u16 j;
    BOOL f;
    s32 g;
    u16 i;
    s32 characterRangeStart;
    s32 characterRangeEnd;
    s32 kartRangeStart;
    s32 kartRangeEnd;
    Vec3 *dst;
    Vec3 *src;
    if (firstPass != 0) {
        characterRangeStart = 0;
        characterRangeEnd = 7;
        kartRangeStart = characterRangeStart;
        kartRangeEnd = 0x15;
    } else {
        characterRangeStart = 7;
        characterRangeEnd = 0xd;
        kartRangeStart = 0x15;
        kartRangeEnd = 0x25;
    }
    i = 0;
    if (i < gKartModels->mKartCount) {
        g = (firstPass == 0) ? 1 : i;
        do {
            entry = &gKartModels->mKartModelsEntries[i];
            pNameUsed = IsCharacterPNameUsed(i);
            if ((u16) entry->mKartIndex % 3 == 0) {
                isVariantZero = TRUE;
            } else {
                isVariantZero = FALSE;
            }
            f = (isVariantZero != FALSE && g != 0) ? TRUE : FALSE;
            if (entry->mCharacterIndex >= characterRangeStart && entry->mCharacterIndex < characterRangeEnd) {
                CreateCharacter(entry, heap, pNameUsed);
            }
            if (f == FALSE) {
                if ((isVariantZero != FALSE && firstPass != 0) ||
                    (entry->mKartIndex >= kartRangeStart && entry->mKartIndex < kartRangeEnd)) {
                    CreateKart(entry, heap, pNameUsed);
                }
            }
            if (firstPass != 0) {
                if (pNameUsed != 0) {
                    j = 0;
                    entry->mUnk_054 = HeapAlloc(heap, 0x30);
                    do {
                        dst = &entry->mUnk_054->mUnk_v[j];
                        src = &entry->mKartOffsetData->mUnk_14[j];
                        dst->x = src->x >> 4;
                        dst->y = src->y >> 4;
                        dst->z = src->z >> 4;
                        j++;
                    } while (j < 4);
                    entry->mUnk_054->mUnk_v[1].x =
                        FX_Div(-entry->mUnk_054->mUnk_v[0].x * 2, entry->mKartOffsetData->mUnk_10);
                    entry->mUnk_054->mUnk_v[3].x = -entry->mUnk_054->mUnk_v[2].x * 2;
                    CreateTire(entry, heap);
                }
                CreateKartShadow(entry, heap);
            }
            i++;
        } while (i < gKartModels->mKartCount);
    }
}

void CreateCharacter(KartModelsEntry *kartModelsEntry, void *heap, s32 pNameUsed) {
    u16 i;
    u16 characterIndex;
    BOOL hasFirstAnimation;
    void *nsbmdFile;
    NNSG3dResFileHeader *nsbtxFile;
    NNSG3dResMdl *mdl;
    void *animationFile;
    characterIndex = kartModelsEntry->mCharacterIndex;
    nsbmdFile = func_02047950(BuildCharacterNsbmdPath(characterIndex, pNameUsed));
    nsbtxFile = FindKartModelFile(BuildCharacterNsbtxPath(characterIndex, pNameUsed));
    kartModelsEntry->mModels[0] = HeapAlloc(heap, 0x6c);
    mdl = InitNsbmdWithTextureInfoCopy(heap, kartModelsEntry->mModels[0], nsbmdFile, nsbtxFile);
    SetNsbmdPolygonIdAll(kartModelsEntry->mModels[0], 3);
    SetKartModelMaterialColors(mdl, 0);
    if (pNameUsed != 0) {
        i = 0;
        hasFirstAnimation = FALSE;
        kartModelsEntry->mCharacterAnimation = HeapAlloc(heap, 0x38);
        InitModelAnimation(0, kartModelsEntry->mCharacterAnimation, kartModelsEntry->mModels[0], 4, heap, NULL);
        do {
            animationFile = func_02047950(BuildCharacterNsbcaPath(characterIndex, i));
            if (animationFile != NULL) {
                void *jointAnimation = NNS_G3dGetJntAnmByIdx(NNS_G3dGetJntAnmSet(animationFile), 0);
                InitModelAnimationEntry(kartModelsEntry->mCharacterAnimation, i, jointAnimation,
                                        GetCharacterAnimationLoopFlag(i), heap);
                if (i == 0) {
                    hasFirstAnimation = TRUE;
                }
            }
            i++;
        } while (i < 4);
        if (hasFirstAnimation != FALSE) {
            SetModelAnimation(kartModelsEntry->mCharacterAnimation, 0);
            kartModelsEntry->mMiddleFrame =
                (GetModelAnimationFrameCountFixed(kartModelsEntry->mCharacterAnimation) - 0x1000) / 2;
            kartModelsEntry->mMiddleFrameReciprocal = FX_Div(0x1000, kartModelsEntry->mMiddleFrame);
        } else {
            kartModelsEntry->mCharacterAnimation->mUnk_18 = 0;
        }
    }
    kartModelsEntry->mFaceAnimation = HeapAlloc(heap, 0x38);
    InitModelAnimation(2, kartModelsEntry->mFaceAnimation, kartModelsEntry->mModels[0], 1, heap, NULL);
    InitModelAnimationEntries(kartModelsEntry->mFaceAnimation, gKartModels->mPFaceanimNsbtpFile, heap);
    SetModelAnimation(kartModelsEntry->mFaceAnimation, 0);
}

void CreateKart(KartModelsEntry *kartModelsEntry, void *heap, s32 pNameUsed) {
    u16 kartIndex = kartModelsEntry->mKartIndex;
    void *nsbmdFile;
    NNSG3dResFileHeader *nsbtxFile;
    NNSG3dResMdl *mdl;
    s32 tireMaterialIndex;
    nsbmdFile = func_02047950(BuildKartNsbmdPath(kartIndex));
    nsbtxFile = FindKartModelFile(BuildKartNsbtxPath(kartIndex));
    kartModelsEntry->mModels[1] = HeapAlloc(heap, 0x6c);
    mdl = InitNsbmdWithTextureInfoCopy(heap, kartModelsEntry->mModels[1], nsbmdFile, nsbtxFile);
    SetNsbmdPolygonIdAll(kartModelsEntry->mModels[1], 3);
    SetKartModelMaterialColors(mdl, 0);
    if (pNameUsed != 0) {
        tireMaterialIndex = NNS_G3dGetResDictIdxByName((u8 *) mdl + mdl->mOfsMat + 4, data_usa_021550b8);
        NNS_G3dMdlSetMdlAlpha(mdl, tireMaterialIndex, 0);
        gKartModels->mKartTireMaterialIndex = tireMaterialIndex;
    }
    UploadKartAPaletteSlice(kartModelsEntry->mModels[1], kartModelsEntry->mKartIndex, gKartModels->mKartAPalette);
}

u16 *LoadKartAPaletteFromKartModelFile(void) {
    Nclr *nclr;
    LoadNclrData(&nclr, func_02047950("/kart/palette/kart_a.NCLR"));
    return nclr->mData;
}

u16 *LoadKartAPaletteFromKartModelMenu(void *heap) {
    void *file;
    Nclr *nclr;
    LoadKartModelMenuFile(heap, "kart/palette/kart_a.NCLR", &file);
    LoadNclrData(&nclr, file);
    return nclr->mData;
}

void UploadKartAPaletteSlice(Nsbmd *nsbmd, s32 kartIndex, void *kartAPalette) {
    u8 *mdlBytes;
    u8 *q;
    u8 *t;
    u8 *paletteSlice;
    s32 materialIndex;
    u32 paletteBase;
    if (kartIndex % 3 == 0) {
        mdlBytes = (u8 *) nsbmd->mResMdl;
        paletteSlice = (u8 *) kartAPalette + kartIndex / 3 * 0x20;
        DC_FlushRange(paletteSlice, 0x10);
        materialIndex = NNS_G3dGetResDictIdxByName(mdlBytes + *(s32 *) (mdlBytes + 8) + 4, data_usa_02155088);
        q = mdlBytes + *(s32 *) (mdlBytes + 8);
        t = q + 4 + *OFFSET_PTR(u16, q, 0xa);
        paletteBase = *(u16 *) (q + *(s32 *) (t + *(u16 *) t * materialIndex + 4) + 0x1c) << 4;
        GX_BeginLoadTexPltt();
        GX_LoadTexPltt(paletteSlice, paletteBase, 0x10);
        GX_EndLoadTexPltt();
    }
}

void UploadKartModelsEntryPalettes(KartModelsEntry *kartModelsEntry, s32 pNameUsed) {
    u8 *c;
    u32 k;
    u32 m;
    u8 *h;
    u8 *mdlBytes;
    u8 *q;
    u8 *t;
    u8 *e;
    u8 *f;
    u8 *g;
    s32 j;
    s32 i;
    if (kartModelsEntry->mUnk_0b0 != 0) {
        if ((u32) (kartModelsEntry->mKartIndex - 0x22) <= 1) {
            c = NULL;
            mdlBytes = (u8 *) kartModelsEntry->mModels[1]->mResMdl;
            switch (kartModelsEntry->mKartIndex) {
                case 0x22:
                    c = data_usa_021550e8;
                    break;
                case 0x23:
                    c = data_usa_02155108;
                    break;
            }
            i = NNS_G3dGetResDictIdxByName(mdlBytes + *(s32 *) (mdlBytes + 8) + 4, data_usa_02155008);
            q = mdlBytes + *(s32 *) (mdlBytes + 8);
            t = q + 4 + *OFFSET_PTR(u16, q, 0xa);
            e = q + *(s32 *) (t + *(u16 *) t * i + 4);
            data_usa_0217acec = e;
            k = *OFFSET_PTR(u16, e, 0x1c) << 4;
            GX_BeginLoadTexPltt();
            GX_LoadTexPltt(c, k, 0x20);
            GX_EndLoadTexPltt();
        }
        if (kartModelsEntry->mCharacterIndex == 0xb) {
            mdlBytes = (u8 *) kartModelsEntry->mModels[0]->mResMdl;
            if (pNameUsed != 0) {
                i = NNS_G3dGetResDictIdxByName(mdlBytes + *(s32 *) (mdlBytes + 8) + 4, data_usa_02155028);
                j = NNS_G3dGetResDictIdxByName(mdlBytes + *(s32 *) (mdlBytes + 8) + 4, data_usa_02155038);
                c = data_usa_02155128;
                h = data_usa_02155148;
                m = 0x40;
            } else {
                i = NNS_G3dGetResDictIdxByName(mdlBytes + *(s32 *) (mdlBytes + 8) + 4, data_usa_02155058);
                j = NNS_G3dGetResDictIdxByName(mdlBytes + *(s32 *) (mdlBytes + 8) + 4, data_usa_02155078);
                c = data_usa_021550c8;
                h = data_usa_02154fe8;
                m = 0x10;
            }
            q = mdlBytes + *(s32 *) (mdlBytes + 8);
            t = q + 4;
            e = q + *(s32 *) ((t = t + *OFFSET_PTR(u16, q, 0xa)) + *(u16 *) t * j + 4);
            f = q + *(s32 *) (t + *(u16 *) t * i + 4);
            g = (u8 *) (*OFFSET_PTR(u16, f, 0x1c) << 4);
            GX_BeginLoadTexPltt();
            GX_LoadTexPltt(c, (u32) g, 0x20);
            GX_EndLoadTexPltt();
            g = (u8 *) (*OFFSET_PTR(u16, e, 0x1c) << 4);
            GX_BeginLoadTexPltt();
            GX_LoadTexPltt(h, (u32) g, m);
            GX_EndLoadTexPltt();
        }
    }
}

void CreateTire(KartModelsEntry *kartModelsEntry, void *heap) {
    u16 kartIndex = kartModelsEntry->mKartIndex;
    void *nsbmdFile;
    NNSG3dResMdl *mdl;
    NNSG3dResFileHeader *nsbtxFile;
    nsbmdFile = func_02047950(BuildTireNsbmdPath(kartIndex, kartModelsEntry->mKartOffsetData->mUnk_00));
    nsbtxFile = FindKartModelFile(BuildTireNsbtxPath(kartIndex, kartModelsEntry->mKartOffsetData->mUnk_00));
    kartModelsEntry->mModels[2] = HeapAlloc(heap, 0x6c);
    mdl = InitNsbmdWithTextureInfoCopy(heap, kartModelsEntry->mModels[2], nsbmdFile, nsbtxFile);
    SetNsbmdPolygonIdAll(kartModelsEntry->mModels[2], 3);
    SetKartModelMaterialColors(mdl, 0);
}

void CreateKartShadow(KartModelsEntry *kartModelsEntry, void *heap) {
    void *nsbmdFile;
    u8 *mdlSet;
    nsbmdFile = func_02047950(BuildKartShadowNsbmdPath(kartModelsEntry->mKartIndex));
    kartModelsEntry->mShadowModel = HeapAlloc(heap, 0x74);
    AddResFileEntry(&kartModelsEntry->mShadowModel->mNsbmd.mResFileEntry, nsbmdFile, nsbmdFile);
    mdlSet = (u8 *) NNS_G3dGetMdlSet(nsbmdFile);
    InitShadowModelFromResMdl(&kartModelsEntry->mShadowModel->mNsbmd,
                              mdlSet + *(s32 *) (mdlSet + *OFFSET_PTR(u16, mdlSet, 0xe) + 0xc), 3);
}

void CreateKillerItem(void *heap) {
    void *nsbmdFile = func_02047950("character/common/KillerItem.nsbmd");
    NNSG3dResFileHeader *nsbtxFile = FindKartModelFile("character/common/KillerItem.nsbtx");
    void *shadowNsbmdFile = func_02047950("character/common/KillerItem_s.nsbmd");
    void *nsbcaFile;
    SetKartModelMaterialColors(InitNsbmdWithTextureInfoCopy(heap, &gKartModels->mKillerItem, nsbmdFile, nsbtxFile), 0);
    SetNsbmdPolygonIdAll(&gKartModels->mKillerItem, 3);
    nsbcaFile = func_02047950("character/common/KillerItem.nsbca");
    InitModelAnimation(0, &gKartModels->mKillerItemNsbca, &gKartModels->mKillerItem, 1, heap, nsbmdFile);
    InitModelAnimationEntries(&gKartModels->mKillerItemNsbca, nsbcaFile, heap);
    SetModelAnimation(&gKartModels->mKillerItemNsbca, 0);
    InitShadowModel(&gKartModels->mKillerItemS, shadowNsbmdFile, 3);
    SetKillerItemRenderCallback(&gKartModels->mKillerItem);
}

void LoadKartModelMenuFile(void *heap, const void *fileName, void **file) {
    char path[0x100];
    snprintf(path, 0x100, "/data/KartModelMenu/%s", fileName);
    LoadFileIntoHeap(path, heap, file);
}

void func_020790e0(void *heap, s32 createKartAppear) {
    if (createKartAppear != 0) {
        gKartModelMenu->mUseEmblemTex = FALSE;
        gKartModelMenu->mKartAppear = CreateKartAppear(heap);
    } else {
        gKartModelMenu->mUseEmblemTex = TRUE;
    }
    gKartModelMenu->mKartAPalette = LoadKartAPaletteFromKartModelMenu(heap);
    gKartModelMenu->mSelectModel = NULL;
}

#pragma thumb off

#pragma thumb on

void CreateKartModelMenuCharacter(void *heap, Nsbmd *nsbmd, void *animation, NNSG3dResFileHeader *modelFile,
                                  NNSG3dResFileHeader *textureFile, void *animationFile) {
    NNSG3dResMdl *mdl;
    u32 loopFlag;
    void *jointAnimation;
    mdl = InitNsbmdWithTextureFile(nsbmd, modelFile, textureFile);
    SetNsbmdPolygonIdAll(nsbmd, 3);
    SetKartModelMaterialColors(mdl, 1);
    InitModelAnimation(0, animation, nsbmd, 1, heap, NULL);
    jointAnimation = NNS_G3dGetJntAnmByIdx(NNS_G3dGetJntAnmSet(animationFile), 0);
    loopFlag = GetCharacterAnimationLoopFlag(2);
    InitModelAnimationEntry(animation, 0, jointAnimation, loopFlag, heap);
    SetModelAnimation(animation, 0);
}

void CreateKartModelMenuKart(Nsbmd *nsbmd, NNSG3dResFileHeader *modelFile, NNSG3dResFileHeader *textureFile) {
    NNSG3dResMdl *mdl;
    u32 tireMaterialIndex;
    mdl = InitNsbmdWithTextureFile(nsbmd, modelFile, textureFile);
    SetNsbmdPolygonIdAll(nsbmd, 3);
    SetKartModelMaterialColors(mdl, 1);
    tireMaterialIndex = NNS_G3dGetResDictIdxByName((u8 *) mdl + mdl->mOfsMat + 4, data_02155098);
    NNS_G3dMdlSetMdlAlpha(mdl, tireMaterialIndex, 0);
}

void CreateKartModelMenuTire(Nsbmd *nsbmd, NNSG3dResFileHeader *modelFile, NNSG3dResFileHeader *textureFile) {
    NNSG3dResMdl *mdl;
    mdl = InitNsbmdWithTextureFile(nsbmd, modelFile, textureFile);
    SetNsbmdPolygonIdAll(nsbmd, 3);
    SetKartModelMaterialColors(mdl, 1);
}

#pragma thumb off

#pragma thumb on

void *CreateKartModelMenuShadow(void *shadowModel, NNSG3dResFileHeader *modelFile) {
    return InitShadowModel(shadowModel, modelFile, 3);
}

void LoadKartModelMenuSelectModel(void *heap) {
    void *modelFile;
    void *textureFile;
    LoadKartModelMenuFile(heap, data_usa_02165760, &modelFile);
    LoadKartModelMenuFile(heap, data_usa_0216577c, &textureFile);
    gKartModelMenu->mSelectModel = HeapAlloc(heap, 0x6c);
    InitNsbmdWithTextureFile(gKartModelMenu->mSelectModel, modelFile, textureFile);
    SetNsbmdPolygonIdAll(gKartModelMenu->mSelectModel, 2);
    NNS_G3dMdlSetMdlXLDepthUpdateAll(gKartModelMenu->mSelectModel->mResMdl, 1);
}

#pragma thumb off

#pragma thumb on

void LoadKartModelMenuEmblemTexData(NNSG3dResFileHeader *file) {
    gKartModelMenu->mEmblemTex = NNS_G3dGetTex(file);
    NNS_G3dResDefaultSetup(file);
}

void InitKartModelMenuSlot(void *heap, KartModelMenuSlot *slot) {
    InitKartModelsEntry(slot);
    slot->mUnk_b0 = data_021759d0->mUnk_00;
    slot->mEmblemTex = 0;
    slot->mCharacterNsbmd = HeapAlloc(heap, 0x6c);
    slot->mKartNsbmd = HeapAlloc(heap, 0x6c);
    slot->mTireNsbmd = HeapAlloc(heap, 0x6c);
    slot->mShadowModel = HeapAlloc(heap, 0x74);
    slot->mCharacterAnimation = HeapAlloc(heap, 0x38);
}

void InitKartModelMenuView(KartModelMenuView *view, int b) {
    u32 bg0Offset;
    bg0Offset = 0;
    view->mCharacterIndex = 0xffffffff;
    view->mKartIndex = 0xffffffff;
    view->mScale = 0x1000;
    view->mYawAngle = 0xeaab;
    view->mSpinAngle = view->mYawAngle;
    view->mUnk_18 = 0;
    view->mUnk_0c = 0;
    view->mUnk_10 = 0xffffff88;
    if (b != 0) {
        bg0Offset = 0xffffff06;
    }
    view->mBg0Offset = bg0Offset;
    view->mBg0Direction = 0;
}

#pragma thumb off

#pragma thumb on

void QueueKartEmblemTexture(void *emblemData, void *emblemPalette) {
    NNSG3dResMdl *mdl;
    u8 *t;
    u8 *u;
    u8 *w;
    s32 materialIndex;
    s32 paletteBase;
    NNSG3dResMatData *material;
    KartModelMenuData *menu = gKartModelMenu;
    KartModelMenuFiles *files = &menu->mFiles[menu->mLoadSlotIndex];
    s16 shownSlotIndex = menu->mShownSlotIndex;
    if (shownSlotIndex >= 0 && files->mLoadRequested == FALSE) {
        mdl = menu->mSlots[shownSlotIndex].mKartNsbmd->mResMdl;
        materialIndex = NNS_G3dGetResDictIdxByName((u8 *) mdl + mdl->mOfsMat + 4, data_usa_02155018);
        t = (u8 *) mdl + mdl->mOfsMat;
        u = t + 4;
        w = u + *OFFSET_PTR(u16, t, 0xa);
        material = (NNSG3dResMatData *) (t + *(u32 *) (w + *(u16 *) w * materialIndex + 4));
        paletteBase = material->mTexPlttBase << 4;
        CallQueueAppend(0, (material->mTexImageParam & 0xffff) << 3, emblemData, 0x200);
        CallQueueAppend(1, paletteBase, emblemPalette, 0x20);
    }
}

void func_02078d64(void *heap) {
    u32 i;
    SetHeapGroupId(1);
    Init3dEngine();
    NNS_G3dGeUseFastDma(0);
    data_021759d0->mUnk_1c &= ~8;
    InitLnkVramManagers(heap);
    ResetResFileEntries();
    SetKartModelPathPrefix(1);
    InitKartModelMenu(heap);
    func_020790e0(heap, 0);
    LoadKartModelMenuFile(heap, data_usa_02165738, (void **) &gKartModelMenu->mCharMenuParams);
    LoadKartModelMenuFile(heap, data_usa_0216574c, (void **) &gKartModelMenu->mKartMenuParams);
    LoadKartModelMenuSelectModel(heap);
    for (i = 0; i < 2; i = (u16) (i + 1)) {
        InitKartModelMenuFiles(heap, &gKartModelMenu->mFiles[i]);
    }
    if (data_0217aa08->mEmblemRecord->mFilled != 0 && data_0217aa08->mFirstBlock->mUnk_31_3 == 0) {
        gKartModelMenu->mEmblemData = data_0217aa08->mEmblemRecord->mEmblemData;
        gKartModelMenu->mEmblemPalette = GetEmblemSBNclr()->mData;
    }
    SetHeapGroupId(9);
}

void func_02078c58(void *heap) {
    u32 i;
    enum { K0 } kartIndex;
    s32 characterIndex;
    SetHeapGroupId(1);
    Init3dEngine();
    NNS_G3dGeUseFastDma(0);
    data_021759d0->mUnk_1c &= ~8;
    InitLnkVramManagers(heap);
    ResetResFileEntries();
    SetKartModelPathPrefix(1);
    InitKartModelMenu(heap);
    func_020790e0(heap, 1);
    kartIndex = 0;
    gKartModelMenu->mKartIndex = kartIndex;
    gKartModelMenu->mKartListCount = kartIndex;
    gKartModelMenu->mKartListPos = kartIndex;
    while (kartIndex < 0x24) {
        if (func_02077a70(&characterIndex, kartIndex) != 0) {
            gKartModelMenu->mKartListCount++;
        }
        kartIndex++;
    }
    gKartModelMenu->mView.mScale = data_usa_021656e0;
    for (i = 0; i < 2; i = (u16) (i + 1)) {
        InitKartModelMenuFiles(heap, &gKartModelMenu->mFiles[i]);
    }
    gKartModelMenu->mFiles[gKartModelMenu->mLoadSlotIndex].mLoadRequested = TRUE;
    gKartModelMenu->mView.mCharacterIndex = 0;
    gKartModelMenu->mView.mKartIndex = 0;
    gKartModelMenu->mLoadSlot->mCharacterIndex = 0;
    gKartModelMenu->mLoadSlot->mKartIndex = 0;
    gKartModelMenu->mLoadSlot->mKartOffsetData = gKartModelMenu->mKartOffsetTable;
    LoadKartAndCharacterFiles();
    AdvanceKartModelMenuLoad();
    InitKartModelMenuView(&gKartModelMenu->mView, 0);
    SetHeapGroupId(9);
}

void InitKartModelMenu(void *heap) {
    u32 i;
    gKartModels = NULL;
    gKartModelMenu = HeapAlloc(heap, 0x26c);
    gKartModelMenu->mShownSlotIndex = -1;
    gKartModelMenu->mLoadSlotIndex = 0;
    gKartModelMenu->mLoadSlot = &gKartModelMenu->mSlots[gKartModelMenu->mLoadSlotIndex];
    gKartModelMenu->mKartAPalette = NULL;
    gKartModelMenu->mUnk_1dc = FALSE;
    gKartModelMenu->mUnk_1d8 = 0;
    gKartModelMenu->mMirrorMode = 0;
    gKartModelMenu->mCharMenuParams = NULL;
    gKartModelMenu->mKartMenuParams = NULL;
    gKartModelMenu->mCharacterRequested = 0;
    gKartModelMenu->mKartRequested = 0;
    gKartModelMenu->mKartAppear = NULL;
    gKartModelMenu->mUnk_1f0 = 0;
    gKartModelMenu->mEmblemPalette = NULL;
    gKartModelMenu->mEmblemData = gKartModelMenu->mEmblemPalette;
    LoadEmblemSBNclr(heap);
    LoadKartModelMenuFile(heap, data_usa_02165724, (void **) &gKartModelMenu->mKartOffsetTable);
    for (i = 0; i < 2; i = (u16) (i + 1)) {
        InitKartModelMenuSlot(heap, &gKartModelMenu->mSlots[i]);
    }
    InitKartModelMenuView(&gKartModelMenu->mView, 1);
    SetHeapGroupId(9);
}

s16 *ComputeKartMenuParams(s32 kartIndex, s32 characterIndex) {
    KartModelMenuData *menu = gKartModelMenu;
    s16 *characterParam = &menu->mCharMenuParams[characterIndex];
    KartMenuParams *kartParams = &menu->mKartMenuParams[kartIndex];
    menu->mMenuParams[0] = kartParams->mUnk_00[0];
    menu->mMenuParams[1] = kartParams->mUnk_00[1];
    menu->mMenuParams[2] = kartParams->mUnk_00[2];
    menu->mMenuParams[3] = kartParams->mUnk_00[3];
    menu->mMenuParams[4] = kartParams->mUnk_00[4];
    menu->mMenuParams[5] = kartParams->mUnk_00[5];
    menu->mMenuParams[2] += *characterParam;
    return gKartModelMenu->mMenuParams;
}

// Asks for a new character in the menu view; -1 clears it at once.
void RequestKartModelMenuCharacter(s32 characterIndex) {
    KartModelMenuData *menu = gKartModelMenu;
    KartModelMenuView *view = &menu->mView;
    KartModelMenuFiles *files = &menu->mFiles[menu->mLoadSlotIndex];
    s32 currentCharacterIndex = view->mCharacterIndex;
    s32 c = -1;
    KartModelMenuSlot *slots;
    KartModelMenuSlot *shownSlot;
    if (characterIndex == c) {
        slots = menu->mSlots;
        shownSlot = &slots[menu->mShownSlotIndex];
        view->mCharacterIndex = characterIndex;
        shownSlot->mCharacterIndex = c;
        return;
    }
    if (files->mLoadRequested == FALSE && currentCharacterIndex != characterIndex && characterIndex <= 0xd) {
        view->mCharacterIndex = characterIndex;
        gKartModelMenu->mCharacterRequested = 1;
    }
}

void RequestKartModelMenuKart(s32 kartIndex) {
    KartModelMenuData *menu = gKartModelMenu;
    KartModelMenuView *view = &menu->mView;
    KartModelMenuFiles *files = &menu->mFiles[menu->mLoadSlotIndex];
    s32 currentKartIndex = view->mKartIndex;
    s32 c = -1;
    KartModelMenuSlot *slots;
    KartModelMenuSlot *shownSlot;
    if (kartIndex == c) {
        slots = menu->mSlots;
        shownSlot = &slots[menu->mShownSlotIndex];
        view->mKartIndex = kartIndex;
        shownSlot->mKartIndex = c;
        return;
    }
    if (files->mLoadRequested == FALSE && currentKartIndex != kartIndex && kartIndex <= 0x25) {
        view->mKartIndex = kartIndex;
        gKartModelMenu->mKartRequested = 1;
    }
}

void AdvanceKartModelMenuBg0Offset(void) {
    KartModelMenuView *view = &gKartModelMenu->mView;
    switch (view->mBg0Direction) {
        case 0:
            view->mBg0Offset += 0x15;
            if (view->mBg0Offset > -0x2e) {
                view->mBg0Offset = -0x2e;
            }
            break;
        case 1:
            view->mBg0Offset -= 0x15;
            if (view->mBg0Offset < -0xfa) {
                view->mBg0Offset = -0xfa;
            }
            break;
    }
}

void StartKartModelMenuBg0Increase(void) {
    gKartModelMenu->mView.mBg0Direction = 0;
}

void StartKartModelMenuBg0Decrease(void) {
    gKartModelMenu->mView.mBg0Direction = 1;
}

void SetFrustumProjection(s32 mirrored) {
    s32 e;
    s32 d;
    s32 c;
    s32 b;
    s32 a;
    a = ((s64) FX_Div(0x579, 0xf09) * 0x200) >> 12;
    b = -a;
    c = ((s64) b * 0x1555) >> 12;
    d = -c;
    e = d;
    if (mirrored != 0) {
        e = -d;
        c = d;
    }
    func_01ff9048(0x15, NULL, 0);
    G3i_FrustumW_(a, b, c, e, 0x200, 0x64000, 0x1000, 0, (Unk0214ad4c *) data_0217029c.mProjMtx);
    data_0217029c.mFlag &= ~0x50;
    NNS_G3dGlbFlushP();
}

void SetupLightFrustumAndLookAt(s32 param_1, s32 yOffset) {
    Vec3 lightDirection;
    Vec3 e;
    Vec3 d;
    Vec3 b;
    Vec3 c;
    NNS_G3dGlbFlushP();
    lightDirection = data_usa_02165708;
    if ((s64) lightDirection.z * lightDirection.z +
            ((s64) lightDirection.x * lightDirection.x + (s64) lightDirection.y * lightDirection.y) >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&lightDirection, &lightDirection);
    }
    NNS_G3dGlbLightVector(0, (s16) lightDirection.x, (s16) lightDirection.y, (s16) lightDirection.z);
    NNS_G3dGlbLightColor(0, (u16) (data_usa_021656d8 | (data_usa_021656d8 << 5) | (data_usa_021656d8 << 10)));
    SetFrustumProjection(0);
    b = data_usa_02155188;
    c = data_usa_021656f0;
    c.y += yOffset;
    VEC_Subtract(&c, &data_usa_021656fc, &d);
    VEC_CrossProduct(&b, &d, &e);
    data_021704dc[0] = data_usa_021656fc;
    data_021704dc[1] = e;
    data_021704dc[2] = c;
    G3i_LookAt_(&data_usa_021656fc, &e, &c, 0, &data_0217029c.mCameraMtx);
    data_0217029c.mFlag &= ~0xe8;
    NNS_G3dGlbFlushP();
}

void DrawKartModelMenuSlot(KartModelMenuSlot *slot, KartModelMenuView *view, s32 mirrored) {
    Vec3 scale;
    s32 m1[9];
    s32 m2[9];
    MtxFx43 m3;
    Vec3 t;
    Vec3 u;
    Vec3 w;
    Vec3 *e;
    s32 k;
    u16 i;

    data_0217029c.mPrmViewPort = 0xbfff0000;
    t.x = data_usa_021656f0.x;
    t.y = data_usa_021656f0.y;
    t.z = data_usa_021656f0.z;
    k = FX_MulFunc(data_usa_021656e4, view->mScale);
    scale.x = k;
    scale.y = k;
    scale.z = k;
    MTX_RotY33_(m1, gPairsByAngle[(view->mYawAngle >> 4) * 2], gPairsByAngle[(view->mYawAngle >> 4) * 2 + 1]);
    MTX_RotX33_(m2, gPairsByAngle[(((u16) (data_usa_021656dc + view->mUnk_1a)) >> 4) * 2],
                gPairsByAngle[(((u16) (data_usa_021656dc + view->mUnk_1a)) >> 4) * 2 + 1]);
    MTX_Concat33(m1, m2, m1);
    if (slot->mKartOffsetData != NULL) {
        MTX_Copy33To43_(m1, &m3.mUnk_00[0].x);
        m3.mUnk_00[3] = t;
        MTX_ScaleApply43(&m3, &m3, scale.x, scale.y, scale.z);
    } else {
        MTX_Identity43_(&m3);
    }
    NNS_G3dGlbSetBaseScale(&scale);
    NNS_G3dGlbSetBaseTrans(&t);
    MI_Copy36B(m2, data_0217029c.mPrmBaseRot);
    data_0217029c.mFlag &= ~0xa4;
    NNS_G3dGlbFlushP();
    if (gKartModelMenu->mSelectModel != NULL) {
        func_01ff8cf0(gKartModelMenu->mSelectModel);
    }
    MI_Copy36B(m1, data_0217029c.mPrmBaseRot);
    data_0217029c.mFlag &= ~0xa4;
    NNS_G3dGlbSetBaseTrans(&t);
    NNS_G3dGlbFlushP();
    if (slot->mCharacterIndex != -1 && slot->mKartIndex != -1) {
        SetFrustumProjection(mirrored);
        if (slot->mShadowModel != NULL) {
            if (mirrored != 0) {
                slot->mShadowModel->mNsbmd.mCullModesSwapped = 1;
            } else {
                slot->mShadowModel->mNsbmd.mCullModesSwapped = 0;
            }
            ((void (*)(ShadowModel *)) DrawShadowModel)(slot->mShadowModel);
        }
        if (slot->mKartNsbmd != NULL) {
            if (mirrored != 0) {
                func_02084f68(slot->mKartNsbmd);
            } else {
                func_02084f20(slot->mKartNsbmd);
            }
            func_01ff8cf0(slot->mKartNsbmd);
        }
        if (slot->mTireNsbmd != NULL) {
            for (i = 0; i < 4; i++) {
                if (i < 2) {
                    k = slot->mKartOffsetData->mUnk_10;
                    w.x = ((s64) scale.x * k) >> 12;
                    w.y = ((s64) scale.y * k) >> 12;
                    w.z = ((s64) scale.z * k) >> 12;
                } else {
                    w = scale;
                }
                if (i != 1 || slot->mKartOffsetData->mUnk_14[0].x != 0) {
                    e = &slot->mKartOffsetData->mUnk_14[i];
                    u.x = e->x >> 4;
                    u.y = e->y >> 4;
                    u.z = e->z >> 4;
                    MTX_MultVec43(&u, &m3, &t);
                    NNS_G3dGlbSetBaseScale(&w);
                    NNS_G3dGlbSetBaseTrans(&t);
                    NNS_G3dGlbFlushP();
                    if (mirrored != 0) {
                        func_02084f68(slot->mTireNsbmd);
                    } else {
                        func_02084f20(slot->mTireNsbmd);
                    }
                    func_01ff8cf0(slot->mTireNsbmd);
                }
            }
        }
        if (slot->mCharacterNsbmd != NULL) {
            MTX_MultVec43(&slot->mKartOffsetData->mUnk_44[slot->mCharacterIndex], &m3, &t);
            NNS_G3dGlbSetBaseTrans(&t);
            NNS_G3dGlbFlushP();
            if (mirrored != 0) {
                func_02084f68(slot->mCharacterNsbmd);
            } else {
                func_02084f20(slot->mCharacterNsbmd);
            }
            func_01ff8cf0(slot->mCharacterNsbmd);
        }
    }
}

#pragma thumb off

#pragma thumb on

void SetupKartModelEmblemTex(KartModelMenuSlot *slot) {
    if ((gKartModelMenu->mUseEmblemTex != FALSE) && (slot->mEmblemTex != NULL)) {
        NNS_G3dReleaseMdlTexEx(slot->mKartNsbmd->mResMdl, data_02155048);
        NNS_G3dReleaseMdlPlttEx(slot->mKartNsbmd->mResMdl, data_021550a8);
        NNS_G3dBindMdlTexEx(slot->mKartNsbmd->mResMdl, slot->mEmblemTex, data_02155048);
        NNS_G3dBindMdlPlttEx(slot->mKartNsbmd->mResMdl, slot->mEmblemTex, data_021550a8);
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceKartModelMenu(s32 mirrorMode) {
    KartModelMenuView *view;
    KartModelMenuSlot *shownSlot;
    view = &gKartModelMenu->mView;
    gKartModelMenu->mMirrorMode = mirrorMode;
    QueueKartModelMenuLoad();
    AdvanceKartModelMenuBg0Offset();
    if (gKartModelMenu->mShownSlotIndex >= 0) {
        shownSlot = &gKartModelMenu->mSlots[gKartModelMenu->mShownSlotIndex];
        if (gKartModelMenu->mUnk_1d8 != 0 || gKartModelMenu->mUnk_1dc != FALSE) {
            AdvanceAngleToward(&view->mSpinAngle, 0xeaab, data_usa_021656e8);
            if (gKartModelMenu->mUnk_1d8 == 0 && gKartModelMenu->mUnk_1dc != FALSE) {
                gKartModelMenu->mUnk_1f0++;
                if (gKartModelMenu->mUnk_1f0 > 0x3c) {
                    gKartModelMenu->mUnk_1dc = FALSE;
                }
            }
        } else {
            view->mSpinAngle += 0x64;
        }
        view->mYawAngle = mirrorMode != 0 ? (u16) -view->mSpinAngle : view->mSpinAngle;
        AdvanceModelAnimation(shownSlot->mCharacterAnimation);
        if (gKartModelMenu->mEmblemData != NULL && gKartModelMenu->mEmblemPalette != NULL &&
            gKartModelMenu->mFiles[gKartModelMenu->mLoadSlotIndex].mLoadRequested == FALSE) {
            QueueKartEmblemTexture(gKartModelMenu->mEmblemData, gKartModelMenu->mEmblemPalette);
        }
    }
    ClearKartModelMenuRequests();
}

void AdvanceShownSlotAndQueueEmblem(void) {
    s16 shownSlotIndex = gKartModelMenu->mShownSlotIndex;
    if (shownSlotIndex >= 0) {
        AdvanceModelAnimation(gKartModelMenu->mSlots[shownSlotIndex].mCharacterAnimation);
        if (gKartModelMenu->mFiles[gKartModelMenu->mLoadSlotIndex].mLoadRequested == FALSE) {
            QueueKartEmblemTexture(func_ov001_021a2398(), func_ov001_021a23ac());
        }
    }
}

void AdvanceKartModelMenuInput(void) {
    KartModelMenuView *view = &gKartModelMenu->mView;
    s32 a = 0;
    BOOL b;
    s32 d;
    s32 characterIndex;
    u16 buttons;
    InputSlotIndex v1;
    s32 v = 2;
    KartModelMenuFiles *files;

    files = &gKartModelMenu->mFiles[gKartModelMenu->mLoadSlotIndex];
    if (gThreadFunctionQueue->mRunRequested == 0 && files->mLoadRequested == FALSE) {
        characterIndex = ~a;
        v1 = UNK_02175628_INDEX_8;
        buttons = data_02175628[v1].mPressedBits;
        if ((u16) (buttons & PAD_KEY_R) != 0) {
            d = a;
            do {
                gKartModelMenu->mKartIndex++;
                if (gKartModelMenu->mKartIndex > 0x23) {
                    gKartModelMenu->mKartIndex = a;
                }
                if (func_02077a70(&characterIndex, gKartModelMenu->mKartIndex) != 0) {
                    RequestKartModelMenuCharacter(characterIndex);
                    RequestKartModelMenuKart(gKartModelMenu->mKartIndex);
                    d = 1;
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, a, 0x1fd);
                }
            } while (d == 0);
            gKartModelMenu->mKartListPos++;
            if (gKartModelMenu->mKartListPos >= gKartModelMenu->mKartListCount) {
                gKartModelMenu->mKartListPos = 0;
            }
        } else if ((u16) (buttons & PAD_KEY_L) != 0) {
            d = a;
            do {
                gKartModelMenu->mKartIndex--;
                if (gKartModelMenu->mKartIndex < 0) {
                    gKartModelMenu->mKartIndex = 0x23;
                }
                if (func_02077a70(&characterIndex, gKartModelMenu->mKartIndex) != 0) {
                    RequestKartModelMenuCharacter(characterIndex);
                    RequestKartModelMenuKart(gKartModelMenu->mKartIndex);
                    d = 1;
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, a, 0x1fe);
                }
            } while (d == 0);
            gKartModelMenu->mKartListPos--;
            if (gKartModelMenu->mKartListPos < 0) {
                gKartModelMenu->mKartListPos = gKartModelMenu->mKartListCount - 1;
            }
        }
    }
    b = FALSE;
    d = b;
    GetSndHandleSlot(2);
    v1 = UNK_02175628_INDEX_8;
    buttons = data_02175628[v1].mBits;
    if ((u16) (buttons & PAD_KEY_RIGHT) != 0) {
        view->mYawAngle += 0x1c2;
        b = TRUE;
    } else if ((u16) (buttons & PAD_KEY_LEFT) != 0) {
        view->mYawAngle -= 0x1c2;
        b = TRUE;
    }
    v1 = UNK_02175628_INDEX_8;
    buttons = data_02175628[v1].mBits;
    if ((u16) (buttons & PAD_KEY_DOWN) != 0) {
        view->mUnk_18 += 0x1c2;
        if (view->mUnk_18 > 0x1b58) {
            view->mUnk_18 = 0x1b58;
        } else {
            d = 1;
        }
    } else if ((u16) (buttons & PAD_KEY_UP) != 0) {
        view->mUnk_18 -= 0x1c2;
        if (view->mUnk_18 < -0x1388) {
            view->mUnk_18 = -0x1388;
        } else {
            d = 1;
        }
    }
    if (d != 0 || b != FALSE) {
        a = 1;
    }
    GetSndHandleSlot(1);
    v1 = UNK_02175628_INDEX_8;
    buttons = data_02175628[v1].mBits;
    if ((u16) (buttons & PAD_KEY_X) != 0) {
        view->mScale += 0x7b;
        if (view->mScale > data_usa_021656e0) {
            view->mScale = data_usa_021656e0;
        } else {
            v = 0;
        }
    } else {
        v1 = UNK_02175628_INDEX_8;
        buttons = data_02175628[v1].mBits;
        if ((u16) (buttons & PAD_KEY_B) != 0) {
            view->mScale -= 0x7b;
            if (view->mScale < 0x800) {
                view->mScale = 0x800;
            } else {
                v = 1;
            }
        }
    }
    view->mUnk_1a = view->mUnk_18;
    func_02110aac(v, a);
    QueueKartModelMenuLoad();
    ClearKartModelMenuRequests();
}

void DrawKartModelMenu(void) {
    KartModelMenuSlot *slot;
    KartModelMenuView *view;
    if (gKartModelMenu->mShownSlotIndex >= 0) {
        slot = &gKartModelMenu->mSlots[gKartModelMenu->mShownSlotIndex];
        view = &gKartModelMenu->mView;
        if (view->mCharacterIndex != -1 && view->mKartIndex != -1) {
            SetupLightFrustumAndLookAt(view->mBg0Offset, data_usa_021656ec);
            DrawKartModelMenuSlot(slot, &gKartModelMenu->mView, gKartModelMenu->mMirrorMode);
            func_01ff9234();
        }
    }
}

void DrawKartModelMenuUnmirrored(void) {
    KartModelMenuSlot *slot;
    if (gKartModelMenu->mShownSlotIndex >= 0) {
        slot = &gKartModelMenu->mSlots[gKartModelMenu->mShownSlotIndex];
        SetupLightFrustumAndLookAt(0, data_usa_021656ec);
        DrawKartModelMenuSlot(slot, &gKartModelMenu->mView, 0);
        func_01ff9234();
    }
}

void CopyHeyhoPaletteIndices(void) {
    u16 i;
    for (i = 0; i < 8; i++) {
        gKartModels->mHeyhoPaletteIndices[i] = data_0217b488->mShuffledIndices[i];
    }
}

void SetupHeyhoPalettes(void) {
    u32 i;
    if (gKartModels->mHeyhoPalettes != NULL) {
        CopyHeyhoPaletteIndices();
        for (i = 0; i < gRaceSetup->mKartCount; i = (u16) (i + 1)) {
            if (gKartModels->mKartModelsEntries[i].mCharacterIndex == 0xc) {
                UploadHeyhoPalette(i, &gKartModels->mKartModelsEntries[i], GetHeyhoPalette(i));
            }
        }
    }
}

void UploadHeyhoPalette(int kartIndex, struct KartModelsEntry *kartModelsEntry, HeyhoPalette *palette) {
    NNSG3dResMdl *mdl;
    u8 *t;
    u8 *u;
    u8 *w;
    s32 materialIndex;
    s32 paletteBase;
    mdl = kartModelsEntry->mModels[0]->mResMdl;
    DC_FlushRange(palette, 0x20);
    if (IsCharacterPNameUsed(kartIndex) != 0) {
        materialIndex = NNS_G3dGetResDictIdxByName((u8 *) mdl + mdl->mOfsMat + 4, data_usa_02154ff8);
    } else {
        materialIndex = NNS_G3dGetResDictIdxByName((u8 *) mdl + mdl->mOfsMat + 4, data_usa_02155068);
    }
    t = (u8 *) mdl + mdl->mOfsMat;
    u = t + 4;
    w = u + *OFFSET_PTR(u16, t, 0xa);
    paletteBase = ((NNSG3dResMatData *) (t + *(u32 *) (w + *(u16 *) w * materialIndex + 4)))->mTexPlttBase << 4;
    GX_BeginLoadTexPltt();
    GX_LoadTexPltt(palette, paletteBase, 0x20);
    GX_EndLoadTexPltt();
}

HeyhoPalette *GetHeyhoPalette(int kartIndex) {
    HeyhoPalette *palette = NULL;
    if (gKartModels->mHeyhoPalettes != NULL) {
        palette = gKartModels->mHeyhoPalettes + gKartModels->mHeyhoPaletteIndices[kartIndex];
    }
    return palette;
}

void func_02077f5c(void) {
    gKartModelMenu->mUnk_1dc = TRUE;
    gKartModelMenu->mUnk_1f0 = 0;
}

#pragma thumb off

#pragma thumb on

void func_02077f48(u32 flag) {
    gKartModelMenu->mUnk_1d8 = flag;
}

// Moves *a toward b by a share of the distance plus 100; keeps the old value when the step would reach b.
void AdvanceAngleToward(u16 *angle, int targetAngle, u32 easeFactor) {
    u16 oldAngle;
    int change;
    int difference;
    oldAngle = *angle;
    difference = targetAngle - oldAngle;
    if (difference < 0) {
        difference = 0xffff - difference;
    }
    change = FX_MulFunc(difference, easeFactor);
    *angle = *angle + change;
    if (((*angle + 100) - targetAngle) < 0) {
        *angle = *angle + 100;
        return;
    }
    *angle = oldAngle;
}

#pragma thumb off

#pragma thumb on

Nclr *GetEmblemSBNclr(void) {
    return gEmblemSBNclr;
}

#pragma thumb off

#pragma thumb on

void InitKartModelMenuFiles(void *heap, KartModelMenuFiles *files) {
    void *heapMemory;
    struct NNSiFndHeapHead *expHeap;
    heapMemory = HeapAlloc(heap, 0xf000);
    expHeap = NNS_FndCreateExpHeapEx(heapMemory, 0xf000, 0);
    files->mHeap = expHeap;
    files->mHeapMemory = heapMemory;
    files->mEmblemNsbtxFile = NULL;
    files->mCharacterNsbtxFile = files->mEmblemNsbtxFile;
    files->mCharacterNsbmdFile = files->mCharacterNsbtxFile;
    files->mKartNsbtxFile = NULL;
    files->mKartNsbmdFile = files->mKartNsbtxFile;
    files->mCharacterNsbcaFile = files->mKartNsbmdFile;
    files->mKartShadowNsbmdFile = NULL;
    files->mTireNsbtxFile = files->mKartShadowNsbmdFile;
    files->mTireNsbmdFile = files->mTireNsbtxFile;
    files->mLoadRequested = FALSE;
    files->mLoadStep = 0;
}

#pragma thumb off

#pragma thumb on

void LoadKartAndCharacterFiles(void) {
    KartModelMenuFiles *files;
    s32 characterIndex;
    KartModelMenuFiles *loadFiles;
    s32 kartIndex;
    s32 loadSlotIndex;
    char *tireName;

    files = gKartModelMenu->mFiles;
    loadSlotIndex = gKartModelMenu->mLoadSlotIndex;
    loadFiles = &files[loadSlotIndex];
    characterIndex = gKartModelMenu->mLoadSlot->mCharacterIndex;
    kartIndex = gKartModelMenu->mLoadSlot->mKartIndex;
    loadFiles->mLoadStep = 0;
    NNS_FndDestroyExpHeap(loadFiles->mHeap);
    loadFiles->mHeap = NNS_FndCreateExpHeapEx(loadFiles->mHeapMemory, 0xf000, 0);
    if (characterIndex != -1 && loadFiles->mCharacterNsbmdFile != NULL) {
        NNS_G3dResDefaultRelease(loadFiles->mCharacterNsbmdFile);
        NNS_G3dResDefaultRelease(loadFiles->mCharacterNsbtxFile);
        NNS_G3dResDefaultRelease(loadFiles->mEmblemNsbtxFile);
        NNS_G3dResDefaultRelease(loadFiles->mKartNsbmdFile);
        NNS_G3dResDefaultRelease(loadFiles->mKartNsbtxFile);
        NNS_G3dResDefaultRelease(loadFiles->mTireNsbmdFile);
        NNS_G3dResDefaultRelease(loadFiles->mTireNsbtxFile);
        NNS_G3dResDefaultRelease(loadFiles->mKartShadowNsbmdFile);
    }
    tireName = (char *) &gKartModelMenu->mKartOffsetTable[kartIndex];
    LoadFileIntoHeap(BuildCharacterNsbmdPath(characterIndex, 1), loadFiles->mHeap,
                     (void **) &loadFiles->mCharacterNsbmdFile);
    LoadFileIntoHeap(BuildCharacterNsbtxPath(characterIndex, 1), loadFiles->mHeap,
                     (void **) &loadFiles->mCharacterNsbtxFile);
    LoadFileIntoHeap(BuildCharacterNsbcaPath(characterIndex, 2), loadFiles->mHeap, &loadFiles->mCharacterNsbcaFile);
    LoadFileIntoHeap(BuildEmblemNsbtxPath(characterIndex), loadFiles->mHeap, (void **) &loadFiles->mEmblemNsbtxFile);
    LoadFileIntoHeap(BuildKartNsbmdPath(kartIndex), loadFiles->mHeap, (void **) &loadFiles->mKartNsbmdFile);
    LoadFileIntoHeap(BuildKartNsbtxPath(kartIndex), loadFiles->mHeap, (void **) &loadFiles->mKartNsbtxFile);
    LoadFileIntoHeap(BuildKartShadowNsbmdPath(kartIndex), loadFiles->mHeap, (void **) &loadFiles->mKartShadowNsbmdFile);
    LoadFileIntoHeap(BuildTireNsbmdPath(kartIndex, tireName), loadFiles->mHeap, (void **) &loadFiles->mTireNsbmdFile);
    LoadFileIntoHeap(BuildTireNsbtxPath(kartIndex, tireName), loadFiles->mHeap, (void **) &loadFiles->mTireNsbtxFile);
}

// Builds the slot being loaded over three calls, then shows it and loads into the other slot next.
void AdvanceKartModelMenuLoad(void) {
    KartModelMenuFiles *loadFiles;
    KartModelMenuSlot *loadSlot;
    KartModelMenuSlot *shownSlot;
    Unk0217ad08_058_08 *animation;

    G2Bg0OfsWrite(gKartModelMenu->mView.mBg0Offset);
    if (gThreadFunctionQueue->mRunRequested == 0) {
        loadFiles = &gKartModelMenu->mFiles[gKartModelMenu->mLoadSlotIndex];
        if (loadFiles->mLoadRequested != FALSE) {
            loadSlot = gKartModelMenu->mLoadSlot;
            if (loadFiles->mLoadStep == 0) {
                CreateKartModelMenuCharacter(loadFiles->mHeap, loadSlot->mCharacterNsbmd, loadSlot->mCharacterAnimation,
                                             loadFiles->mCharacterNsbmdFile, loadFiles->mCharacterNsbtxFile,
                                             loadFiles->mCharacterNsbcaFile);
                loadFiles->mLoadStep++;
                return;
            }
            if (loadFiles->mLoadStep == 1) {
                LoadKartModelMenuEmblemTexData(loadFiles->mEmblemNsbtxFile);
                gKartModelMenu->mLoadSlot->mEmblemTex = gKartModelMenu->mEmblemTex;
                CreateKartModelMenuShadow(loadSlot->mShadowModel, loadFiles->mKartShadowNsbmdFile);
                CreateKartModelMenuTire(loadSlot->mTireNsbmd, loadFiles->mTireNsbmdFile, loadFiles->mTireNsbtxFile);
                loadFiles->mLoadStep++;
                return;
            }
            CreateKartModelMenuKart(loadSlot->mKartNsbmd, loadFiles->mKartNsbmdFile, loadFiles->mKartNsbtxFile);
            SetupKartModelEmblemTex(gKartModelMenu->mLoadSlot);
            UploadKartAPaletteSlice(loadSlot->mKartNsbmd, loadSlot->mKartIndex, gKartModelMenu->mKartAPalette);
            UploadKartModelsEntryPalettes((struct KartModelsEntry *) loadSlot, 1);
            loadFiles->mLoadRequested = FALSE;
            loadFiles->mLoadStep = 0;
            if (gKartModelMenu->mShownSlotIndex >= 0) {
                shownSlot = &gKartModelMenu->mSlots[gKartModelMenu->mShownSlotIndex];
                if (loadSlot->mCharacterIndex == shownSlot->mCharacterIndex) {
                    animation = loadSlot->mCharacterAnimation;
                    animation->mUnk_0c = shownSlot->mCharacterAnimation->mUnk_0c;
                    *animation->mUnk_1c[animation->mUnk_1a] = animation->mUnk_0c;
                }
            }
            gKartModelMenu->mShownSlotIndex = gKartModelMenu->mLoadSlotIndex;
            gKartModelMenu->mLoadSlotIndex = gKartModelMenu->mLoadSlotIndex == 0 ? 1 : 0;
            gKartModelMenu->mLoadSlot = &gKartModelMenu->mSlots[gKartModelMenu->mLoadSlotIndex];
        }
    }
}

#pragma thumb off

#pragma thumb on

void InitLnkVramManagers(void *heap) {
    u32 texWorkSize;
    u32 plttWorkSize;
    RangeEntry *texWork;
    RangeEntry *plttWork;
    texWorkSize = NNS_GfdGetLnkTexVramManagerWorkSize(0x20);
    plttWorkSize = func_020172d0(0x20);
    texWork = HeapAlloc(heap, texWorkSize);
    plttWork = HeapAlloc(heap, plttWorkSize);
    NNS_GfdInitLnkTexVramManager(0x00040000u, 0x00020000u, texWork, texWorkSize, 1);
    NNS_GfdInitLnkPlttVramManager(0x00010000u, plttWork, plttWorkSize, 1);
}

#pragma thumb off
