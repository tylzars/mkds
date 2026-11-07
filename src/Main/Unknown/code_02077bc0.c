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

void func_0207ad88(ShadowModel *a, u32 b, u32 c) {
    if ((a->mFlags & 1) != 0) {
        func_02084ad8(a, a->mAlpha);
        data_02155a20[a->mNsbmd.mDrawKind](a);
        func_02084a88(a, a->mAlpha, a->mPolygonId);
        data_02155a20[a->mNsbmd.mDrawKind](a);
    }
}

void InitKarts(u32 a) {
    u16 i;
    void *h = GetHeap(GetCurrentHeapCall());
    EntryKartCounters *q;
    gKarts = HeapAlloc(h, a * 0x5a8);
    gKartCount = a;
    q = HeapAlloc(h, 0x1c);
    gEntryKartCounters = q;
    gKillerItemKartIndex = 0;
    gMinKartDistanceSquaredPresent = 0;
    gMinKartDistanceSquared = -1;
    q->mUnk_00 = 0;
    q->mUnk_04 = 0;
    q->mUnk_08 = 0;
    q->mUnk_0c = 0;
    q->mUnk_10 = 0;
    q->mUnk_14 = 0;
    q->mUnk_18 = 0;
    data_usa_021658bc = gRaceSetup->mMode == MODE_BATTLE ? 1 : 2;
    func_02073630();
    RegisterKartAiCallbacks();
    InitKartEffects(a);
    gMissionRunKind2ShapesPresent = 0;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        if (gCourseMap->mKind2ShapeCountInMode4 != 0) {
            gMissionRunKind2ShapesPresent = 1;
        }
    }
    for (i = 0; i < a; i++) {
        gKarts[i].mIndex = i;
        gKarts[i].mEntryIndex = gRaceSetup->mCurrentEntries[i].mPlayer.mIndex;
        InitKart(&gKarts[i], gKartDefaultSlotFunctions);
    }
    gKartKind3ShapeMask = 0;
}

void UpdateKarts(void) {
    s32 i;
    Kart *p = gKarts;
    gMinKartDistanceSquaredPresent = 0;
    gMinKartDistanceSquared = -1;
    for (i = 0; i < gKartCount; i++) {
        UpdateKartPrevValuesAndClearFlags(p);
        p++;
    }
    func_0207a32c();
    p = gKarts;
    for (i = 0; i < gKartCount; i++) {
        p->mSlotFunctions[3](p);
        p++;
    }
    p = gKarts;
    for (i = 0; i < gKartCount; i++) {
        p->mSlotFunctions[4](p);
        p++;
    }
}

void UpdateKartSoundDistancesSquared(void) {
    Kart *p = gKarts;
    s16 i;
    for (i = 0; i < gKartCount; i++) {
        p->mSlotFunctions[2](p);
        p++;
    }
}

void DrawKarts(void) {
    s32 i = 0;
    u16 *p = func_02086058();
    (gKarts[gRaceSetup->mEntryIndex].mKartModelsEntry)->mUnk_060 = TRUE;
    for (; i < gKartCount; i++) {
        DrawKart(&gKarts[*p]);
        p++;
    }
}

void func_0207a990(void) {
    s32 i;
    for (i = 0; i < gKartCount; i++) {
        CallKartSlot8(&gKarts[i]);
    }
    gKarts = NULL;
}

Kart *GetKart(s32 a) {
    return &gKarts[a];
}

void GetKartPos(Vec3 *a, s32 b) {
    *a = *gKarts[b].mPosSource;
}

void func_0207a91c(Vec3 *a, u8 b) {
    *a = *gKarts[b].mUnk_534;
}

void GetKartPrevPos(Vec3 *a, s32 b) {
    *a = gKarts[b].mPrevPos;
}

void GetKartScale(Vec3 *a, s32 b) {
    *a = gKarts[b].mScale;
}

u32 GetKartItemEffect(u32 a) {
    return gKarts[a].mItemEffect;
}

u16 GetKartHeadingAngle(s32 a) {
    return gKarts[a].mHeadingAngle;
}

u32 IsMissionRunWithKind2Shapes(void) {
    return gMissionRunKind2ShapesPresent;
}

s32 func_0207a84c(s32 a) {
    return func_02068eac(&gKarts[a]);
}

void func_0207a828(s32 a) {
    func_02066fe0(&gKarts[a]);
}

u32 func_0207a7fc(s32 a) {
    return (gKarts[a].mUnk_48 & 1) != 0;
}

u32 GetKartForwardSpeedRatio(void) {
    return gKartForwardSpeedRatio;
}

// Sets bit i when the kart is inside kind 3 shape list i.
void SetKartKind3ShapeMask(s32 a) {
    u16 i;

    gKartKind3ShapeMask = 0;
    for (i = 0; i < 8; i++) {
        if (IsKartInCourseMapKind3ShapeList(a, i) != 0) {
            gKartKind3ShapeMask |= 1 << i;
        }
    }
}

u32 GetKartKind3ShapeMask(void) {
    return gKartKind3ShapeMask;
}

// Stores the forward speed as a part of the speed limit, 0x1000 = 1.0.
void SetKartForwardSpeedRatio(s32 a) {
    gKartForwardSpeedRatio = ((s64) a * gKartSpeedLimitReciprocal + 0x800) >> 12;
}

void SetKartSpeedLimitReciprocal(u32 p0) {
    gKartSpeedLimitReciprocal = p0;
}

void func_0207a70c(s32 a) {
    if (a == gRaceSetup->mEntryIndex) {
        gEntryKartCounters->mUnk_08++;
    }
}

void func_0207a6c0(Kart *a) {
    if (a->mIndex != gRaceSetup->mEntryIndex) {
        return;
    }
    if (a->mUnk_4c & 0x40) {
        return;
    }
    if (!(a->mUnk_48 & 0x20000000)) {
        gEntryKartCounters->mUnk_0c++;
    }
}

EntryKartCounters *GetEntryKartCounters(void) {
    return gEntryKartCounters;
}

u32 func_0207a68c(int a) {
    return func_0206c0a8(&gKarts[a]);
}

void SetKartModelsFogEnable(s32 a) {
    s32 i;
    Kart *p = gKarts;
    KartModelsEntry *s;
    for (i = 0; i < gKartCount; i++) {
        s = p->mKartModelsEntry;
        NNS_G3dMdlSetMdlFogEnableFlagAll(s->mModels[1]->mResMdl, a);
        NNS_G3dMdlSetMdlFogEnableFlagAll(s->mModels[0]->mResMdl, a);
        if (s->mModels[2] != NULL) {
            NNS_G3dMdlSetMdlFogEnableFlagAll(s->mModels[2]->mResMdl, a);
        }
        p++;
    }
}

s32 func_0207a5c4(s32 a) {
    return (gKarts[a].mUnk_48 & 0x800) != 0 ? 1 : 0;
}

BOOL func_0207a574(void) {
    Kart *p = &gKarts[gRaceSetup->mEntryIndex];
    if (p->mState != KART_STATE_NORMAL || (p->mUnk_48 & 0x4000000) != 0) {
        return TRUE;
    }
    return FALSE;
}

s32 func_0207a538(void) {
    return (gKarts[gRaceSetup->mEntryIndex].mUnk_44 & 0xc0) != 0 ? 1 : 0;
}

s32 func_0207a4fc(void) {
    return (gKarts[gRaceSetup->mEntryIndex].mUnk_48 & 0x1000) != 0 ? 1 : 0;
}

void func_0207a32c(void) {
    s32 d[3];
    u32 n = GetKartRank((u16) gRaceSetup->mEntryIndex);
    u16 i;
    u16 k;
    s32 j;
    Kart *p;
    if (gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
        for (k = 0; k < 3; k++) {
            gKarts[k].mUnk_4c |= 0x8000;
        }
        return;
    }
    d[0] = gRaceSetup->mEntryIndex;
    if (n == 1) {
        d[1] = GetKartIndexAtRank(2);
        if (d[1] >= 0) {
            if ((gKarts[d[1]].mKartModelsEntry)->mUnk_060 != FALSE) {
                d[1] = -1;
            }
        }
    } else {
        d[1] = GetKartIndexAtRank((u16) (n - 1));
        if (d[1] >= 0) {
            if ((gKarts[d[1]].mKartModelsEntry)->mUnk_060 != FALSE) {
                d[1] = -1;
            }
        }
        if (n < gRaceSetup->mKartCount) {
            j = GetKartIndexAtRank((u16) (n + 1));
            if (j >= 0) {
                p = &gKarts[j];
                p->mUnk_4c |= 0x40000;
            }
        }
    }
    for (i = 0; i < data_usa_021658bc; i++) {
        j = d[i];
        if (j >= 0) {
            p = &gKarts[j];
            if ((p->mUnk_4c & 0x10000000) == 0) {
                p->mUnk_4c |= 0x8000;
            }
        }
    }
}

u32 GetKillerItemKartIndex(void) {
    return (gKillerItemKartIndex);
}

void SetKillerItemKartIndex(u32 p0) {
    gKillerItemKartIndex = p0;
}

// Keeps the smallest value of the frame; UpdateKarts clears it.
void SetMinKartDistanceSquared(s32 a) {
    if (gMinKartDistanceSquared < 0 || a < gMinKartDistanceSquared) {
        gMinKartDistanceSquared = a;
        gMinKartDistanceSquaredPresent = 1;
    }
}

BOOL TryGetMinKartDistanceSquared(s32 *a) {
    if (gMinKartDistanceSquaredPresent == 0) {
        return FALSE;
    }
    *a = gMinKartDistanceSquared;
    return TRUE;
}

s32 func_0207a218(void) {
    BOOL r = TRUE;
    s32 m = gRaceSetup->mMode;
    if (m == MODE_MISSION_RUN) {
        Kart *p = &gKarts[gRaceSetup->mEntryIndex];
        if (p->mState != KART_STATE_NORMAL || (p->mUnk_48 & 0x2000840) != 0 || (p->mUnk_44 & KART_44_ON_GROUND) == 0 ||
            (m != MODE_MISSION_RUN ? 0 : func_ov001_021816b4()) != 0) {
            r = FALSE;
        }
    }
    return r;
}

void SetKartModelMaterialColors(NNSG3dResMdl *a, u32 b) {
    u32 c;
    u32 d;
    u32 e;
    u32 f;
    switch (b) {
        case 0: {
            u16 *p = gKartModels->mUnk_004;
            c = p[0];
            d = p[1];
            e = p[2];
            f = p[3];
            break;
        }
        case 2:
            d = 0;
            e = 0;
            f = 0;
            c = 0x2108;
            break;
        case 3:
            d = 0;
            e = 0;
            c = 0x2108;
            f = 0x4210;
            break;
        case 1:
            c = 0x7fff;
            d = 0x14a5;
            f = 0x2108;
            e = 0;
            break;
    }
    NNS_G3dMdlSetMdlDiffAll(a, c);
    NNS_G3dMdlSetMdlAmbAll(a, d);
    NNS_G3dMdlSetMdlSpecAll(a, e);
    NNS_G3dMdlSetMdlEmiAll(a, f);
}

u16 GetKartCourseDiffColor(void) {
    return gKartModels->mUnk_004[0];
}

u16 GetKartCourseEmiColor(void) {
    return gKartModels->mUnk_004[3];
}

u16 GetKartCourseAmbColor(void) {
    return gKartModels->mUnk_004[1];
}

void StartKartModelColorBlend(struct KartModelsEntry *a, u16 b, u16 c, u16 d) {
    Unk0206bcb0_590_6a *q;

    q = &a->mUnk_06a;
    q->mUnk_06 = a->mUnk_06a.mUnk_00 & 0x1f;
    q->mUnk_0c = (s16) (b & 0x1f) - q->mUnk_06;
    q->mUnk_08 = (a->mUnk_06a.mUnk_00 >> 5) & 0x1f;
    q->mUnk_0e = (s16) ((b >> 5) & 0x1f) - q->mUnk_08;
    q->mUnk_0a = (a->mUnk_06a.mUnk_00 >> 10) & 0x1f;
    q->mUnk_10 = (s16) ((b >> 10) & 0x1f) - q->mUnk_0a;
    q->mUnk_12 = q->mUnk_02 & 0x1f;
    q->mUnk_18 = (s16) (c & 0x1f) - q->mUnk_12;
    q->mUnk_14 = (q->mUnk_02 >> 5) & 0x1f;
    q->mUnk_1a = (s16) ((c >> 5) & 0x1f) - q->mUnk_14;
    q->mUnk_16 = (q->mUnk_02 >> 10) & 0x1f;
    q->mUnk_1c = (s16) ((c >> 10) & 0x1f) - q->mUnk_16;
    q->mUnk_1e = q->mUnk_04 & 0x1f;
    q->mUnk_24 = (s16) (d & 0x1f) - q->mUnk_1e;
    q->mUnk_20 = (q->mUnk_04 >> 5) & 0x1f;
    q->mUnk_26 = (s16) ((d >> 5) & 0x1f) - q->mUnk_20;
    q->mUnk_22 = (q->mUnk_04 >> 10) & 0x1f;
    q->mUnk_28 = (s16) ((d >> 10) & 0x1f) - q->mUnk_22;
    q->mUnk_2a = 0;
}

s32 AdvanceKartModelColorBlend(struct KartModelsEntry *a, s32 b) {
    Unk0206bcb0_590_6a *q = &a->mUnk_06a;
    BOOL r = FALSE;

    if (q->mUnk_2a < 0x1000) {
        q->mUnk_2a += b;
        if (q->mUnk_2a >= 0x1000) {
            q->mUnk_2a = 0x1000;
            r = TRUE;
        }
        q->mUnk_00 = (s16) (q->mUnk_06 + (s32) (((s64) q->mUnk_0c * q->mUnk_2a + 0x800) >> 12)) +
                     ((s16) (q->mUnk_08 + (s32) (((s64) q->mUnk_0e * q->mUnk_2a + 0x800) >> 12)) << 5) +
                     ((s16) (q->mUnk_0a + (s32) (((s64) q->mUnk_10 * q->mUnk_2a + 0x800) >> 12)) << 10);
        NNS_G3dMdlSetMdlDiffAll(a->mModels[0]->mResMdl, q->mUnk_00);
        NNS_G3dMdlSetMdlDiffAll(a->mModels[1]->mResMdl, q->mUnk_00);
        if (a->mModels[2] != NULL) {
            NNS_G3dMdlSetMdlDiffAll(a->mModels[2]->mResMdl, q->mUnk_00);
        }
        q->mUnk_02 = (s16) (q->mUnk_12 + (s32) (((s64) q->mUnk_18 * q->mUnk_2a + 0x800) >> 12)) +
                     ((s16) (q->mUnk_14 + (s32) (((s64) q->mUnk_1a * q->mUnk_2a + 0x800) >> 12)) << 5) +
                     ((s16) (q->mUnk_16 + (s32) (((s64) q->mUnk_1c * q->mUnk_2a + 0x800) >> 12)) << 10);
        NNS_G3dMdlSetMdlEmiAll(a->mModels[0]->mResMdl, q->mUnk_02);
        NNS_G3dMdlSetMdlEmiAll(a->mModels[1]->mResMdl, q->mUnk_02);
        if (a->mModels[2] != NULL) {
            NNS_G3dMdlSetMdlEmiAll(a->mModels[2]->mResMdl, q->mUnk_02);
        }
        {
            s16 x = q->mUnk_1e + (s32) (((s64) q->mUnk_24 * q->mUnk_2a + 0x800) >> 12);
            s16 y = q->mUnk_20 + (s32) (((s64) q->mUnk_26 * q->mUnk_2a + 0x800) >> 12);
            s16 z = q->mUnk_22 + (s32) (((s64) q->mUnk_28 * q->mUnk_2a + 0x800) >> 12);
            NNS_G3dMdlSetMdlAmbAll(a->mModels[0]->mResMdl, q->mUnk_04);
            NNS_G3dMdlSetMdlAmbAll(a->mModels[1]->mResMdl, q->mUnk_04);
            if (a->mModels[2] != NULL) {
                NNS_G3dMdlSetMdlAmbAll(a->mModels[2]->mResMdl, q->mUnk_04);
            }
            q->mUnk_04 = x + (y << 5) + (z << 10);
        }
    } else {
        r = TRUE;
    }
    return r;
}

void SetKartModelsEntryCourseColors(struct KartModelsEntry *a) {
    u16 *p = gKartModels->mUnk_004;
    u32 b;
    u32 c;
    u32 d;

    b = p[0];
    c = p[3];
    d = p[1];
    NNS_G3dMdlSetMdlDiffAll(a->mModels[0]->mResMdl, b);
    NNS_G3dMdlSetMdlDiffAll(a->mModels[1]->mResMdl, b);
    NNS_G3dMdlSetMdlEmiAll(a->mModels[0]->mResMdl, c);
    NNS_G3dMdlSetMdlEmiAll(a->mModels[1]->mResMdl, c);
    NNS_G3dMdlSetMdlAmbAll(a->mModels[0]->mResMdl, d);
    NNS_G3dMdlSetMdlAmbAll(a->mModels[1]->mResMdl, d);
    if (a->mModels[2] != NULL) {
        NNS_G3dMdlSetMdlDiffAll(a->mModels[2]->mResMdl, b);
        NNS_G3dMdlSetMdlEmiAll(a->mModels[2]->mResMdl, c);
        NNS_G3dMdlSetMdlAmbAll(a->mModels[2]->mResMdl, d);
    }
}

KartModelsEntry *GetKartModelsEntry(u32 a) {
    return &gKartModels->mKartModelsEntries[a];
}

void *GetKartModelResMdl(u32 a) {
    return gKartModels->mKartModelsEntries[a].mModels[1]->mResMdl;
}

// Shows (b non-zero) or hides the tire material of the kart model.
void SetKartModelTireAlpha(struct KartModelsEntry *a, s32 b) {
    NNS_G3dMdlSetMdlAlpha(a->mModels[1]->mResMdl, gKartModels->mKartTireMaterialIndex, b != 0 ? 0x1f : 0);
}

void *GetKillerItem(void) {
    return &gKartModels->mUnk_02c;
}

void *GetKillerItemS(void) {
    return &gKartModels->mUnk_098;
}

void *GetKillerItemNsbca(void) {
    return &gKartModels->mUnk_10c;
}

u32 GetKartVariant(u32 a) {
    return gKartModels->mKartModelsEntries[a].mUnk_068;
}

#pragma thumb on
void InitKartModelsEntry(void *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    u32 value4;
    value4 = (value0) + (0u);
    value0 = 0u;
    value1 = ~(value0);
    *(u32 *) ((value4) + 0u) = value1;
    *(u32 *) ((value4) + 4u) = value1;
    *(u32 *) ((value4) + 8u) = value0;
    *(u32 *) ((value4) + 12u) = value0;
    *(u32 *) ((value4) + 16u) = value0;
    *(u32 *) ((value4) + 20u) = value0;
    *(u32 *) ((value4) + 24u) = value0;
    *(u32 *) ((value4) + 28u) = value0;
    *(u32 *) ((value4) + 32u) = value0;
    value0 = (value4) + (0u);
    value0 = (value0) + 36u;
    func_02079a04(value0);
    value0 = 0u;
    *(u32 *) ((value4) + 84u) = value0;
    *(u32 *) ((value4) + 88u) = value0;
    *(u32 *) ((value4) + 92u) = value0;
    *(u32 *) ((value4) + 96u) = value0;
    *(u32 *) ((value4) + 100u) = value0;
    value1 = (value4) + (0u);
    value1 = (value1) + 104u;
    *(u16 *) ((value1) + 0u) = value0;
    value1 = (value4) + (0u);
    value1 = (value1) + 172u;
    *(u32 *) ((value1) + 0u) = value0;
    value1 = (value4) + (0u);
    value1 = (value1) + 176u;
    *(u32 *) ((value1) + 0u) = value0;
    value1 = (value4) + (0u);
    value1 = (value1) + 110u;
    *(u16 *) ((value1) + 0u) = value0;
    value1 = (value4) + (0u);
    value1 = (value1) + 110u;
    value2 = *(const u16 *) ((value1) + 0u);
    value1 = (value4) + (0u);
    value1 = (value1) + 108u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = (value4) + (0u);
    value1 = (value1) + 108u;
    value2 = *(const u16 *) ((value1) + 0u);
    value1 = (value4) + (0u);
    value1 = (value1) + 106u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = (value4) + (0u);
    value1 = (value1) + 116u;
    *(u16 *) ((value1) + 0u) = value0;
    value1 = 116u;
    value2 = *(const s16 *) ((value4) + (value1));
    value1 = (value4) + (0u);
    value1 = (value1) + 114u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = 114u;
    value2 = *(const s16 *) ((value4) + (value1));
    value1 = (value4) + (0u);
    value1 = (value1) + 112u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = (value4) + (0u);
    value1 = (value1) + 122u;
    *(u16 *) ((value1) + 0u) = value0;
    value1 = 122u;
    value2 = *(const s16 *) ((value4) + (value1));
    value1 = (value4) + (0u);
    value1 = (value1) + 120u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = 120u;
    value2 = *(const s16 *) ((value4) + (value1));
    value1 = (value4) + (0u);
    value1 = (value1) + 118u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = (value4) + (0u);
    value1 = (value1) + 128u;
    *(u16 *) ((value1) + 0u) = value0;
    value1 = 128u;
    value2 = *(const s16 *) ((value4) + (value1));
    value1 = (value4) + (0u);
    value1 = (value1) + 126u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = 126u;
    value2 = *(const s16 *) ((value4) + (value1));
    value1 = (value4) + (0u);
    value1 = (value1) + 124u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = (value4) + (0u);
    value1 = (value1) + 134u;
    *(u16 *) ((value1) + 0u) = value0;
    value1 = 134u;
    value2 = *(const s16 *) ((value4) + (value1));
    value1 = (value4) + (0u);
    value1 = (value1) + 132u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = 132u;
    value2 = *(const s16 *) ((value4) + (value1));
    value1 = (value4) + (0u);
    value1 = (value1) + 130u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = (value4) + (0u);
    value1 = (value1) + 140u;
    *(u16 *) ((value1) + 0u) = value0;
    value1 = 140u;
    value2 = *(const s16 *) ((value4) + (value1));
    value1 = (value4) + (0u);
    value1 = (value1) + 138u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = 138u;
    value2 = *(const s16 *) ((value4) + (value1));
    value1 = (value4) + (0u);
    value1 = (value1) + 136u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = (value4) + (0u);
    value1 = (value1) + 146u;
    *(u16 *) ((value1) + 0u) = value0;
    value1 = 146u;
    value2 = *(const s16 *) ((value4) + (value1));
    value1 = (value4) + (0u);
    value1 = (value1) + 144u;
    *(u16 *) ((value1) + 0u) = value2;
    value1 = 144u;
    value2 = *(const s16 *) ((value4) + (value1));
    value1 = (value4) + (0u);
    value1 = (value1) + 142u;
    *(u16 *) ((value1) + 0u) = value2;
    value4 = (value4) + 148u;
    *(u16 *) ((value4) + 0u) = value0;
}
#pragma thumb off

#pragma thumb on

void func_02079a14(KartModelsEntry *a) {
    ResetModelAnimationLooping((ModelAnimation *) a->mUnk_098,
                               GetModelAnimationFrameCountFixed(&gKartModels->mUnk_10c));
}

#pragma thumb off

#pragma thumb on
void func_02079a04(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = 0u;
    *(u32 *) ((value0) + 0u) = value1;
    *(u32 *) ((value0) + 20u) = value1;
    *(u16 *) ((value0) + 24u) = value1;
    *(u32 *) ((value0) + 4u) = value1;
    *(u16 *) ((value0) + 16u) = value1;
}
#pragma thumb off

#pragma thumb on

// TRUE when the entry's character files use the P name list.
u32 IsCharacterPNameUsed(s32 e) {
    BOOL a = TRUE;
    s32 b = a;
    s32 c = a;
    s32 d = a;
    if (e != gRaceSetup->mEntryIndex && e != gRaceSetup->mFollowedKartIndex) {
        d = 0;
    }
    if (d == 0 && gRaceSetup->mMode != MODE_MISSION_RUN) {
        c = 0;
    }
    if (c == 0 && IsRaceAwardOrStaffRoll() == 0) {
        b = 0;
    }
    if (b == 0 && gRaceSetup->mMode != MODE_TIME_ATTACK) {
        a = FALSE;
    }
    if (a != FALSE) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

// Stores the kart index modulo 3.
void SetKartModelsEntryVariant(KartModelsEntry *a, int b) {
    u16 v1;
    v1 = b % 3;
    a->mUnk_068 = v1;
}

#pragma thumb off

#pragma thumb on

void InitKartModels(void *a, u32 b) {
    u8 *v4;
    u16 i;
    KartModelsEntry *e;
    KartModelsEntry *d;
    v4 = FindKartModelFile("kartoffsetdata.bin");
    SetKartModelPathPrefix(0);
    gKartModelMenu = NULL;
    gKartModels = HeapAlloc(a, 0x144);
    gKartModels->mKartModelsEntries = HeapAlloc(a, b * 0xb4);
    gKartModels->mUnk_004 = func_02047950("kartcrsmat.bin");
    gKartModels->mUnk_004 = gKartModels->mUnk_004 + (gRaceSetup->mCourseId << 2) - 4;
    gKartModels->mUnk_010 = LoadKartAPaletteFromKartModelFile();
    gKartModels->mUnk_014 = NULL;
    gKartModels->mUnk_028 = func_02047950((const char *) BuildPFaceanimNsbtpPath());
    gKartModels->mKartCount = b;
    gKartModels->mKartTireMaterialIndex = 0;
    CreateKartPhysicalParamTable(a, b);
    SetKartAiParamRow();
    CreateKillerItem(a);
    for (i = 0; i < gKartModels->mKartCount; i++) {
        d = gKartModels->mKartModelsEntries;
        e = &d[i];
        InitKartModelsEntry(e);
        e->mUnk_0b0 = gRaceSetup->mCurrentEntries[i].mPlayer.mUnk_25;
        func_02079a14(e);
        d[i].mUnk_000 = gRaceSetup->mCurrentEntries[i].mCharacterIndex;
        e->mUnk_004 = gRaceSetup->mCurrentEntries[i].mKartIndex;
        SetKartModelsEntryVariant(e, e->mUnk_004);
        e->mUnk_020 = HeapAlloc(a, 0xe0);
        MI_CpuCopy8(v4 + e->mUnk_004 * 0xe0, e->mUnk_020, 0xe0);
        CopyKartPhysicalParams(i, (u16) e->mUnk_004, (u16) d[i].mUnk_000);
    }
    func_02079678(a, 1);
    func_0204775c();
    func_02079678(a, 0);
    for (i = 0; i < gKartModels->mKartCount; i++) {
        e = &gKartModels->mKartModelsEntries[i];
        UploadKartModelsEntryPalettes(e, IsCharacterPNameUsed(i));
    }
    {
        Nclr *p;
        LoadNclrData(&p, func_02047950("/character/heyho/HH_color.NCLR"));
        gKartModels->mUnk_014 = (Unk0217ad00_014 *) p->mData;
    }
}

void func_02079678(void *a, s32 b) {
    BOOL v6;
    KartModelsEntry *e;
    s32 v4;
    u16 j;
    BOOL f;
    s32 g;
    u16 i;
    s32 p;
    s32 q;
    s32 r;
    s32 s;
    Vec3 *dst;
    Vec3 *src;
    if (b != 0) {
        p = 0;
        q = 7;
        r = p;
        s = 0x15;
    } else {
        p = 7;
        q = 0xd;
        r = 0x15;
        s = 0x25;
    }
    i = 0;
    if (i < gKartModels->mKartCount) {
        g = (b == 0) ? 1 : i;
        do {
            e = &gKartModels->mKartModelsEntries[i];
            v4 = IsCharacterPNameUsed(i);
            if ((u16) e->mUnk_004 % 3 == 0) {
                v6 = TRUE;
            } else {
                v6 = FALSE;
            }
            f = (v6 != FALSE && g != 0) ? TRUE : FALSE;
            if (e->mUnk_000 >= p && e->mUnk_000 < q) {
                CreateCharacter(e, a, v4);
            }
            if (f == FALSE) {
                if ((v6 != FALSE && b != 0) || (e->mUnk_004 >= r && e->mUnk_004 < s)) {
                    CreateKart(e, a, v4);
                }
            }
            if (b != 0) {
                if (v4 != 0) {
                    j = 0;
                    e->mUnk_054 = HeapAlloc(a, 0x30);
                    do {
                        dst = &e->mUnk_054->mUnk_v[j];
                        src = &e->mUnk_020->mUnk_14[j];
                        dst->x = src->x >> 4;
                        dst->y = src->y >> 4;
                        dst->z = src->z >> 4;
                        j++;
                    } while (j < 4);
                    e->mUnk_054->mUnk_v[1].x = FX_Div(-e->mUnk_054->mUnk_v[0].x * 2, e->mUnk_020->mUnk_10);
                    e->mUnk_054->mUnk_v[3].x = -e->mUnk_054->mUnk_v[2].x * 2;
                    CreateTire(e, a);
                }
                CreateKartShadow(e, a);
            }
            i++;
        } while (i < gKartModels->mKartCount);
    }
}

void CreateCharacter(KartModelsEntry *a, void *b, s32 c) {
    u16 i;
    u16 e8;
    BOOL d;
    void *v7;
    NNSG3dResFileHeader *v10;
    NNSG3dResMdl *p;
    void *s;
    e8 = a->mUnk_000;
    v7 = func_02047950(BuildCharacterNsbmdPath(e8, c));
    v10 = FindKartModelFile(BuildCharacterNsbtxPath(e8, c));
    a->mModels[0] = HeapAlloc(b, 0x6c);
    p = InitNsbmdWithTextureInfoCopy(b, a->mModels[0], v7, v10);
    SetNsbmdPolygonIdAll(a->mModels[0], 3);
    SetKartModelMaterialColors(p, 0);
    if (c != 0) {
        i = 0;
        d = FALSE;
        a->mCharacterAnimation = HeapAlloc(b, 0x38);
        InitModelAnimation(0, a->mCharacterAnimation, a->mModels[0], 4, b, NULL);
        do {
            s = func_02047950(BuildCharacterNsbcaPath(e8, i));
            if (s != NULL) {
                void *w = NNS_G3dGetJntAnmByIdx(NNS_G3dGetJntAnmSet(s), 0);
                InitModelAnimationEntry(a->mCharacterAnimation, i, w, GetCharacterAnimationLoopFlag(i), b);
                if (i == 0) {
                    d = TRUE;
                }
            }
            i++;
        } while (i < 4);
        if (d != FALSE) {
            SetModelAnimation(a->mCharacterAnimation, 0);
            a->mMiddleFrame = (GetModelAnimationFrameCountFixed(a->mCharacterAnimation) - 0x1000) / 2;
            a->mMiddleFrameReciprocal = FX_Div(0x1000, a->mMiddleFrame);
        } else {
            a->mCharacterAnimation->mUnk_18 = 0;
        }
    }
    a->mFaceAnimation = HeapAlloc(b, 0x38);
    InitModelAnimation(2, a->mFaceAnimation, a->mModels[0], 1, b, NULL);
    InitModelAnimationEntries(a->mFaceAnimation, gKartModels->mUnk_028, b);
    SetModelAnimation(a->mFaceAnimation, 0);
}

void CreateKart(KartModelsEntry *a, void *b, s32 c) {
    u16 v7 = a->mUnk_004;
    void *s;
    NNSG3dResFileHeader *t;
    NNSG3dResMdl *r4;
    s32 i;
    s = func_02047950(BuildKartNsbmdPath(v7));
    t = FindKartModelFile(BuildKartNsbtxPath(v7));
    a->mModels[1] = HeapAlloc(b, 0x6c);
    r4 = InitNsbmdWithTextureInfoCopy(b, a->mModels[1], s, t);
    SetNsbmdPolygonIdAll(a->mModels[1], 3);
    SetKartModelMaterialColors(r4, 0);
    if (c != 0) {
        i = NNS_G3dGetResDictIdxByName((u8 *) r4 + r4->mOfsMat + 4, data_usa_021550b8);
        NNS_G3dMdlSetMdlAlpha(r4, i, 0);
        gKartModels->mKartTireMaterialIndex = i;
    }
    UploadKartAPaletteSlice(a->mModels[1], a->mUnk_004, gKartModels->mUnk_010);
}

u16 *LoadKartAPaletteFromKartModelFile(void) {
    Nclr *p;
    LoadNclrData(&p, func_02047950("/kart/palette/kart_a.NCLR"));
    return p->mData;
}

u16 *LoadKartAPaletteFromKartModelMenu(void *a) {
    void *x;
    Nclr *p;
    LoadKartModelMenuFile(a, "kart/palette/kart_a.NCLR", &x);
    LoadNclrData(&p, x);
    return p->mData;
}

void UploadKartAPaletteSlice(Nsbmd *a, s32 b, void *c) {
    u8 *p;
    u8 *q;
    u8 *t;
    u8 *d;
    s32 i;
    u32 k;
    if (b % 3 == 0) {
        p = (u8 *) a->mResMdl;
        d = (u8 *) c + b / 3 * 0x20;
        DC_FlushRange(d, 0x10);
        i = NNS_G3dGetResDictIdxByName(p + *(s32 *) (p + 8) + 4, data_usa_02155088);
        q = p + *(s32 *) (p + 8);
        t = q + 4 + *(u16 *) (q + 0xa);
        k = *(u16 *) (q + *(s32 *) (t + *(u16 *) t * i + 4) + 0x1c) << 4;
        GX_BeginLoadTexPltt();
        GX_LoadTexPltt(d, k, 0x10);
        GX_EndLoadTexPltt();
    }
}

void UploadKartModelsEntryPalettes(KartModelsEntry *a, s32 b) {
    u8 *c;
    u32 k;
    u32 m;
    u8 *h;
    u8 *p;
    u8 *q;
    u8 *t;
    u8 *e;
    u8 *f;
    u8 *g;
    s32 j;
    s32 i;
    if (a->mUnk_0b0 != 0) {
        if ((u32) (a->mUnk_004 - 0x22) <= 1) {
            c = NULL;
            p = (u8 *) a->mModels[1]->mResMdl;
            switch (a->mUnk_004) {
                case 0x22:
                    c = data_usa_021550e8;
                    break;
                case 0x23:
                    c = data_usa_02155108;
                    break;
            }
            i = NNS_G3dGetResDictIdxByName(p + *(s32 *) (p + 8) + 4, data_usa_02155008);
            q = p + *(s32 *) (p + 8);
            t = q + 4 + *(u16 *) (q + 0xa);
            e = q + *(s32 *) (t + *(u16 *) t * i + 4);
            data_usa_0217acec = e;
            k = *(u16 *) (e + 0x1c) << 4;
            GX_BeginLoadTexPltt();
            GX_LoadTexPltt(c, k, 0x20);
            GX_EndLoadTexPltt();
        }
        if (a->mUnk_000 == 0xb) {
            p = (u8 *) a->mModels[0]->mResMdl;
            if (b != 0) {
                i = NNS_G3dGetResDictIdxByName(p + *(s32 *) (p + 8) + 4, data_usa_02155028);
                j = NNS_G3dGetResDictIdxByName(p + *(s32 *) (p + 8) + 4, data_usa_02155038);
                c = data_usa_02155128;
                h = data_usa_02155148;
                m = 0x40;
            } else {
                i = NNS_G3dGetResDictIdxByName(p + *(s32 *) (p + 8) + 4, data_usa_02155058);
                j = NNS_G3dGetResDictIdxByName(p + *(s32 *) (p + 8) + 4, data_usa_02155078);
                c = data_usa_021550c8;
                h = data_usa_02154fe8;
                m = 0x10;
            }
            q = p + *(s32 *) (p + 8);
            t = q + 4;
            e = q + *(s32 *) ((t = t + *(u16 *) (q + 0xa)) + *(u16 *) t * j + 4);
            f = q + *(s32 *) (t + *(u16 *) t * i + 4);
            g = (u8 *) (*(u16 *) (f + 0x1c) << 4);
            GX_BeginLoadTexPltt();
            GX_LoadTexPltt(c, (u32) g, 0x20);
            GX_EndLoadTexPltt();
            g = (u8 *) (*(u16 *) (e + 0x1c) << 4);
            GX_BeginLoadTexPltt();
            GX_LoadTexPltt(h, (u32) g, m);
            GX_EndLoadTexPltt();
        }
    }
}

void CreateTire(KartModelsEntry *a, void *b) {
    u16 v6 = a->mUnk_004;
    void *v7;
    NNSG3dResMdl *v4;
    NNSG3dResFileHeader *v8;
    v7 = func_02047950(BuildTireNsbmdPath(v6, a->mUnk_020->mUnk_00));
    v8 = FindKartModelFile(BuildTireNsbtxPath(v6, a->mUnk_020->mUnk_00));
    a->mModels[2] = HeapAlloc(b, 0x6c);
    v4 = InitNsbmdWithTextureInfoCopy(b, a->mModels[2], v7, v8);
    SetNsbmdPolygonIdAll(a->mModels[2], 3);
    SetKartModelMaterialColors(v4, 0);
}

void CreateKartShadow(KartModelsEntry *a, void *b) {
    void *v6;
    u8 *p;
    v6 = func_02047950(BuildKartShadowNsbmdPath(a->mUnk_004));
    a->mUnk_01c = HeapAlloc(b, 0x74);
    AddResFileEntry(&a->mUnk_01c->mNsbmd.mResFileEntry, v6, v6);
    p = (u8 *) NNS_G3dGetMdlSet(v6);
    InitShadowModelFromResMdl(&a->mUnk_01c->mNsbmd, p + *(s32 *) (p + *(u16 *) (p + 0xe) + 0xc), 3);
}

void CreateKillerItem(void *a) {
    void *v4 = func_02047950("character/common/KillerItem.nsbmd");
    NNSG3dResFileHeader *v6 = FindKartModelFile("character/common/KillerItem.nsbtx");
    void *v7 = func_02047950("character/common/KillerItem_s.nsbmd");
    void *v8;
    SetKartModelMaterialColors(InitNsbmdWithTextureInfoCopy(a, &gKartModels->mUnk_02c, v4, v6), 0);
    SetNsbmdPolygonIdAll(&gKartModels->mUnk_02c, 3);
    v8 = func_02047950("character/common/KillerItem.nsbca");
    InitModelAnimation(0, &gKartModels->mUnk_10c, &gKartModels->mUnk_02c, 1, a, v4);
    InitModelAnimationEntries(&gKartModels->mUnk_10c, v8, a);
    SetModelAnimation(&gKartModels->mUnk_10c, 0);
    InitShadowModel(&gKartModels->mUnk_098, v7, 3);
    SetKillerItemRenderCallback(&gKartModels->mUnk_02c);
}

void LoadKartModelMenuFile(void *a, const void *b, void **c) {
    char d[0x100];
    snprintf(d, 0x100, "/data/KartModelMenu/%s", b);
    LoadFileIntoHeap(d, a, c);
}

void func_020790e0(void *a, s32 b) {
    if (b != 0) {
        gKartModelMenu->mUseEmblemTex = FALSE;
        gKartModelMenu->mUnk_268 = CreateKartAppear(a);
    } else {
        gKartModelMenu->mUseEmblemTex = TRUE;
    }
    gKartModelMenu->mUnk_1d0 = LoadKartAPaletteFromKartModelMenu(a);
    gKartModelMenu->mSelectModel = NULL;
}

#pragma thumb off

#pragma thumb on

void CreateKartModelMenuCharacter(void *a, Nsbmd *b, void *c, NNSG3dResFileHeader *d, NNSG3dResFileHeader *e, void *f) {
    NNSG3dResMdl *v2;
    u32 v3;
    void *v1;
    v2 = InitNsbmdWithTextureFile(b, d, e);
    SetNsbmdPolygonIdAll(b, 3);
    SetKartModelMaterialColors(v2, 1);
    InitModelAnimation(0, c, b, 1, a, NULL);
    v1 = NNS_G3dGetJntAnmByIdx(NNS_G3dGetJntAnmSet(f), 0);
    v3 = GetCharacterAnimationLoopFlag(2);
    InitModelAnimationEntry(c, 0, v1, v3, a);
    SetModelAnimation(c, 0);
}

void CreateKartModelMenuKart(Nsbmd *a, NNSG3dResFileHeader *b, NNSG3dResFileHeader *c) {
    NNSG3dResMdl *v1;
    u32 v2;
    v1 = InitNsbmdWithTextureFile(a, b, c);
    SetNsbmdPolygonIdAll(a, 3);
    SetKartModelMaterialColors(v1, 1);
    v2 = NNS_G3dGetResDictIdxByName((u8 *) v1 + v1->mOfsMat + 4, data_02155098);
    NNS_G3dMdlSetMdlAlpha(v1, v2, 0);
}

void CreateKartModelMenuTire(Nsbmd *a, NNSG3dResFileHeader *b, NNSG3dResFileHeader *c) {
    NNSG3dResMdl *v1;
    v1 = InitNsbmdWithTextureFile(a, b, c);
    SetNsbmdPolygonIdAll(a, 3);
    SetKartModelMaterialColors(v1, 1);
}

#pragma thumb off

#pragma thumb on

void *CreateKartModelMenuShadow(void *a, NNSG3dResFileHeader *b) {
    return InitShadowModel(a, b, 3);
}

void LoadKartModelMenuSelectModel(void *c) {
    void *a;
    void *b;
    LoadKartModelMenuFile(c, data_usa_02165760, &a);
    LoadKartModelMenuFile(c, data_usa_0216577c, &b);
    gKartModelMenu->mSelectModel = HeapAlloc(c, 0x6c);
    InitNsbmdWithTextureFile(gKartModelMenu->mSelectModel, a, b);
    SetNsbmdPolygonIdAll(gKartModelMenu->mSelectModel, 2);
    NNS_G3dMdlSetMdlXLDepthUpdateAll(gKartModelMenu->mSelectModel->mResMdl, 1);
}

#pragma thumb off

#pragma thumb on

void LoadKartModelMenuEmblemTexData(NNSG3dResFileHeader *a) {
    gKartModelMenu->mEmblemTex = NNS_G3dGetTex(a);
    NNS_G3dResDefaultSetup(a);
}

void InitKartModelMenuSlot(void *a, KartModelMenuSlot *b) {
    InitKartModelsEntry(b);
    b->mUnk_b0 = data_021759d0->mUnk_00;
    b->mEmblemTex = 0;
    b->mUnk_10 = HeapAlloc(a, 0x6c);
    b->mUnk_14 = HeapAlloc(a, 0x6c);
    b->mUnk_18 = HeapAlloc(a, 0x6c);
    b->mUnk_1c = HeapAlloc(a, 0x74);
    b->mCharacterAnimation = HeapAlloc(a, 0x38);
}

void InitKartModelMenuView(KartModelMenuView *a, int b) {
    u32 v1;
    v1 = 0;
    a->mCharacterIndex = 0xffffffff;
    a->mKartIndex = 0xffffffff;
    a->mScale = 0x1000;
    a->mYawAngle = 0xeaab;
    a->mSpinAngle = a->mYawAngle;
    a->mUnk_18 = 0;
    a->mUnk_0c = 0;
    a->mUnk_10 = 0xffffff88;
    if (b != 0) {
        v1 = 0xffffff06;
    }
    a->mBg0Offset = v1;
    a->mBg0Direction = 0;
}

#pragma thumb off

#pragma thumb on

void QueueKartEmblemTexture(void *param_1, void *param_2) {
    NNSG3dResMdl *e;
    u8 *t;
    u8 *u;
    u8 *w;
    s32 k;
    s32 h;
    NNSG3dResMatData *x;
    KartModelMenuData *d = gKartModelMenu;
    KartModelMenuFiles *p = &d->mFiles[d->mLoadSlotIndex];
    s16 i = d->mShownSlotIndex;
    if (i >= 0 && p->mLoadRequested == FALSE) {
        e = d->mSlots[i].mUnk_14->mResMdl;
        k = NNS_G3dGetResDictIdxByName((u8 *) e + e->mOfsMat + 4, data_usa_02155018);
        t = (u8 *) e + e->mOfsMat;
        u = t + 4;
        w = u + *(u16 *) (t + 0xa);
        x = (NNSG3dResMatData *) (t + *(u32 *) (w + *(u16 *) w * k + 4));
        h = x->mTexPlttBase << 4;
        CallQueueAppend(0, (x->mTexImageParam & 0xffff) << 3, param_1, 0x200);
        CallQueueAppend(1, h, param_2, 0x20);
    }
}

void func_02078d64(void *param_1) {
    u32 i;
    SetHeapGroupId(1);
    Init3dEngine();
    NNS_G3dGeUseFastDma(0);
    data_021759d0->mUnk_1c &= ~8;
    InitLnkVramManagers(param_1);
    ResetResFileEntries();
    SetKartModelPathPrefix(1);
    InitKartModelMenu(param_1);
    func_020790e0(param_1, 0);
    LoadKartModelMenuFile(param_1, data_usa_02165738, (void **) &gKartModelMenu->mCharMenuParams);
    LoadKartModelMenuFile(param_1, data_usa_0216574c, (void **) &gKartModelMenu->mKartMenuParams);
    LoadKartModelMenuSelectModel(param_1);
    for (i = 0; i < 2; i = (u16) (i + 1)) {
        InitKartModelMenuFiles(param_1, &gKartModelMenu->mFiles[i]);
    }
    if (data_0217aa08->mEmblemRecord->mFilled != 0 && data_0217aa08->mUnk_00->mUnk_31_3 == 0) {
        gKartModelMenu->mEmblemData = data_0217aa08->mEmblemRecord->mEmblemData;
        gKartModelMenu->mEmblemPalette = GetEmblemSBNclr()->mData;
    }
    SetHeapGroupId(9);
}

void func_02078c58(void *param_1) {
    u32 i;
    enum { K0 } j;
    s32 a;
    SetHeapGroupId(1);
    Init3dEngine();
    NNS_G3dGeUseFastDma(0);
    data_021759d0->mUnk_1c &= ~8;
    InitLnkVramManagers(param_1);
    ResetResFileEntries();
    SetKartModelPathPrefix(1);
    InitKartModelMenu(param_1);
    func_020790e0(param_1, 1);
    j = 0;
    gKartModelMenu->mKartIndex = j;
    gKartModelMenu->mKartListCount = j;
    gKartModelMenu->mKartListPos = j;
    while (j < 0x24) {
        if (func_02077a70(&a, j) != 0) {
            gKartModelMenu->mKartListCount++;
        }
        j++;
    }
    gKartModelMenu->mView.mScale = data_usa_021656e0;
    for (i = 0; i < 2; i = (u16) (i + 1)) {
        InitKartModelMenuFiles(param_1, &gKartModelMenu->mFiles[i]);
    }
    gKartModelMenu->mFiles[gKartModelMenu->mLoadSlotIndex].mLoadRequested = TRUE;
    gKartModelMenu->mView.mCharacterIndex = 0;
    gKartModelMenu->mView.mKartIndex = 0;
    gKartModelMenu->mLoadSlot->mUnk_00 = 0;
    gKartModelMenu->mLoadSlot->mUnk_04 = 0;
    gKartModelMenu->mLoadSlot->mUnk_20 = gKartModelMenu->mUnk_1c8;
    LoadKartAndCharacterFiles();
    AdvanceKartModelMenuLoad();
    InitKartModelMenuView(&gKartModelMenu->mView, 0);
    SetHeapGroupId(9);
}

void InitKartModelMenu(void *param_1) {
    u32 i;
    gKartModels = NULL;
    gKartModelMenu = HeapAlloc(param_1, 0x26c);
    gKartModelMenu->mShownSlotIndex = -1;
    gKartModelMenu->mLoadSlotIndex = 0;
    gKartModelMenu->mLoadSlot = &gKartModelMenu->mSlots[gKartModelMenu->mLoadSlotIndex];
    gKartModelMenu->mUnk_1d0 = NULL;
    gKartModelMenu->mUnk_1dc = FALSE;
    gKartModelMenu->mUnk_1d8 = 0;
    gKartModelMenu->mMirrorMode = 0;
    gKartModelMenu->mCharMenuParams = NULL;
    gKartModelMenu->mKartMenuParams = NULL;
    gKartModelMenu->mCharacterRequested = 0;
    gKartModelMenu->mKartRequested = 0;
    gKartModelMenu->mUnk_268 = NULL;
    gKartModelMenu->mUnk_1f0 = 0;
    gKartModelMenu->mEmblemPalette = NULL;
    gKartModelMenu->mEmblemData = gKartModelMenu->mEmblemPalette;
    LoadEmblemSBNclr(param_1);
    LoadKartModelMenuFile(param_1, data_usa_02165724, (void **) &gKartModelMenu->mUnk_1c8);
    for (i = 0; i < 2; i = (u16) (i + 1)) {
        InitKartModelMenuSlot(param_1, &gKartModelMenu->mSlots[i]);
    }
    InitKartModelMenuView(&gKartModelMenu->mView, 1);
    SetHeapGroupId(9);
}

s16 *ComputeKartMenuParams(s32 param_1, s32 param_2) {
    KartModelMenuData *d = gKartModelMenu;
    s16 *k = &d->mCharMenuParams[param_2];
    Unk0217ad08_01c *v1 = &d->mKartMenuParams[param_1];
    d->mMenuParams[0] = v1->mUnk_00[0];
    d->mMenuParams[1] = v1->mUnk_00[1];
    d->mMenuParams[2] = v1->mUnk_00[2];
    d->mMenuParams[3] = v1->mUnk_00[3];
    d->mMenuParams[4] = v1->mUnk_00[4];
    d->mMenuParams[5] = v1->mUnk_00[5];
    d->mMenuParams[2] += *k;
    return gKartModelMenu->mMenuParams;
}

// Asks for a new character in the menu view; -1 clears it at once.
void RequestKartModelMenuCharacter(s32 param_1) {
    KartModelMenuData *d = gKartModelMenu;
    KartModelMenuView *q = &d->mView;
    KartModelMenuFiles *t = &d->mFiles[d->mLoadSlotIndex];
    s32 a = q->mCharacterIndex;
    s32 c = -1;
    KartModelMenuSlot *e;
    KartModelMenuSlot *b;
    if (param_1 == c) {
        e = d->mSlots;
        b = &e[d->mShownSlotIndex];
        q->mCharacterIndex = param_1;
        b->mUnk_00 = c;
        return;
    }
    if (t->mLoadRequested == FALSE && a != param_1 && param_1 <= 0xd) {
        q->mCharacterIndex = param_1;
        gKartModelMenu->mCharacterRequested = 1;
    }
}

void RequestKartModelMenuKart(s32 param_1) {
    KartModelMenuData *d = gKartModelMenu;
    KartModelMenuView *q = &d->mView;
    KartModelMenuFiles *t = &d->mFiles[d->mLoadSlotIndex];
    s32 a = q->mKartIndex;
    s32 c = -1;
    KartModelMenuSlot *e;
    KartModelMenuSlot *b;
    if (param_1 == c) {
        e = d->mSlots;
        b = &e[d->mShownSlotIndex];
        q->mKartIndex = param_1;
        b->mUnk_04 = c;
        return;
    }
    if (t->mLoadRequested == FALSE && a != param_1 && param_1 <= 0x25) {
        q->mKartIndex = param_1;
        gKartModelMenu->mKartRequested = 1;
    }
}

void AdvanceKartModelMenuBg0Offset(void) {
    KartModelMenuView *q = &gKartModelMenu->mView;
    switch (q->mBg0Direction) {
        case 0:
            q->mBg0Offset += 0x15;
            if (q->mBg0Offset > -0x2e) {
                q->mBg0Offset = -0x2e;
            }
            break;
        case 1:
            q->mBg0Offset -= 0x15;
            if (q->mBg0Offset < -0xfa) {
                q->mBg0Offset = -0xfa;
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

void SetFrustumProjection(s32 param_1) {
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
    if (param_1 != 0) {
        e = -d;
        c = d;
    }
    func_01ff9048(0x15, NULL, 0);
    G3i_FrustumW_(a, b, c, e, 0x200, 0x64000, 0x1000, 0, (Unk0214ad4c *) data_0217029c.mProjMtx);
    data_0217029c.mFlag &= ~0x50;
    NNS_G3dGlbFlushP();
}

void SetupLightFrustumAndLookAt(s32 param_1, s32 param_2) {
    Vec3 a;
    Vec3 e;
    Vec3 d;
    Vec3 b;
    Vec3 c;
    NNS_G3dGlbFlushP();
    a = data_usa_02165708;
    if ((s64) a.z * a.z + ((s64) a.x * a.x + (s64) a.y * a.y) >= 0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&a, &a);
    }
    NNS_G3dGlbLightVector(0, (s16) a.x, (s16) a.y, (s16) a.z);
    NNS_G3dGlbLightColor(0, (u16) (data_usa_021656d8 | (data_usa_021656d8 << 5) | (data_usa_021656d8 << 10)));
    SetFrustumProjection(0);
    b = data_usa_02155188;
    c = data_usa_021656f0;
    c.y += param_2;
    VEC_Subtract(&c, &data_usa_021656fc, &d);
    VEC_CrossProduct(&b, &d, &e);
    data_021704dc[0] = data_usa_021656fc;
    data_021704dc[1] = e;
    data_021704dc[2] = c;
    G3i_LookAt_(&data_usa_021656fc, &e, &c, 0, &data_0217029c.mCameraMtx);
    data_0217029c.mFlag &= ~0xe8;
    NNS_G3dGlbFlushP();
}

void DrawKartModelMenuSlot(KartModelMenuSlot *param_1, KartModelMenuView *param_2, s32 param_3) {
    Vec3 v;
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
    k = FX_MulFunc(data_usa_021656e4, param_2->mScale);
    v.x = k;
    v.y = k;
    v.z = k;
    MTX_RotY33_(m1, gPairsByAngle[(param_2->mYawAngle >> 4) * 2], gPairsByAngle[(param_2->mYawAngle >> 4) * 2 + 1]);
    MTX_RotX33_(m2, gPairsByAngle[(((u16) (data_usa_021656dc + param_2->mUnk_1a)) >> 4) * 2],
                gPairsByAngle[(((u16) (data_usa_021656dc + param_2->mUnk_1a)) >> 4) * 2 + 1]);
    MTX_Concat33(m1, m2, m1);
    if (param_1->mUnk_20 != NULL) {
        MTX_Copy33To43_(m1, &m3.mUnk_00[0].x);
        m3.mUnk_00[3] = t;
        MTX_ScaleApply43(&m3, &m3, v.x, v.y, v.z);
    } else {
        MTX_Identity43_(&m3);
    }
    NNS_G3dGlbSetBaseScale(&v);
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
    if (param_1->mUnk_00 != -1 && param_1->mUnk_04 != -1) {
        SetFrustumProjection(param_3);
        if (param_1->mUnk_1c != NULL) {
            if (param_3 != 0) {
                param_1->mUnk_1c->mNsbmd.mCullModesSwapped = 1;
            } else {
                param_1->mUnk_1c->mNsbmd.mCullModesSwapped = 0;
            }
            ((void (*)(ShadowModel *)) DrawShadowModel)(param_1->mUnk_1c);
        }
        if (param_1->mUnk_14 != NULL) {
            if (param_3 != 0) {
                func_02084f68(param_1->mUnk_14);
            } else {
                func_02084f20(param_1->mUnk_14);
            }
            func_01ff8cf0(param_1->mUnk_14);
        }
        if (param_1->mUnk_18 != NULL) {
            for (i = 0; i < 4; i++) {
                if (i < 2) {
                    k = param_1->mUnk_20->mUnk_10;
                    w.x = ((s64) v.x * k) >> 12;
                    w.y = ((s64) v.y * k) >> 12;
                    w.z = ((s64) v.z * k) >> 12;
                } else {
                    w = v;
                }
                if (i != 1 || param_1->mUnk_20->mUnk_14[0].x != 0) {
                    e = &param_1->mUnk_20->mUnk_14[i];
                    u.x = e->x >> 4;
                    u.y = e->y >> 4;
                    u.z = e->z >> 4;
                    MTX_MultVec43(&u, &m3, &t);
                    NNS_G3dGlbSetBaseScale(&w);
                    NNS_G3dGlbSetBaseTrans(&t);
                    NNS_G3dGlbFlushP();
                    if (param_3 != 0) {
                        func_02084f68(param_1->mUnk_18);
                    } else {
                        func_02084f20(param_1->mUnk_18);
                    }
                    func_01ff8cf0(param_1->mUnk_18);
                }
            }
        }
        if (param_1->mUnk_10 != NULL) {
            MTX_MultVec43(&param_1->mUnk_20->mUnk_44[param_1->mUnk_00], &m3, &t);
            NNS_G3dGlbSetBaseTrans(&t);
            NNS_G3dGlbFlushP();
            if (param_3 != 0) {
                func_02084f68(param_1->mUnk_10);
            } else {
                func_02084f20(param_1->mUnk_10);
            }
            func_01ff8cf0(param_1->mUnk_10);
        }
    }
}

#pragma thumb off

#pragma thumb on

void SetupKartModelEmblemTex(KartModelMenuSlot *a) {
    if ((gKartModelMenu->mUseEmblemTex != FALSE) && (a->mEmblemTex != NULL)) {
        NNS_G3dReleaseMdlTexEx(a->mUnk_14->mResMdl, data_02155048);
        NNS_G3dReleaseMdlPlttEx(a->mUnk_14->mResMdl, data_021550a8);
        NNS_G3dBindMdlTexEx(a->mUnk_14->mResMdl, a->mEmblemTex, data_02155048);
        NNS_G3dBindMdlPlttEx(a->mUnk_14->mResMdl, a->mEmblemTex, data_021550a8);
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceKartModelMenu(s32 param_1) {
    KartModelMenuView *q;
    KartModelMenuSlot *e;
    q = &gKartModelMenu->mView;
    gKartModelMenu->mMirrorMode = param_1;
    func_02077b3c();
    AdvanceKartModelMenuBg0Offset();
    if (gKartModelMenu->mShownSlotIndex >= 0) {
        e = &gKartModelMenu->mSlots[gKartModelMenu->mShownSlotIndex];
        if (gKartModelMenu->mUnk_1d8 != 0 || gKartModelMenu->mUnk_1dc != FALSE) {
            AdvanceAngleToward(&q->mSpinAngle, 0xeaab, data_usa_021656e8);
            if (gKartModelMenu->mUnk_1d8 == 0 && gKartModelMenu->mUnk_1dc != FALSE) {
                gKartModelMenu->mUnk_1f0++;
                if (gKartModelMenu->mUnk_1f0 > 0x3c) {
                    gKartModelMenu->mUnk_1dc = FALSE;
                }
            }
        } else {
            q->mSpinAngle += 0x64;
        }
        q->mYawAngle = param_1 != 0 ? (u16) -q->mSpinAngle : q->mSpinAngle;
        AdvanceModelAnimation(e->mCharacterAnimation);
        if (gKartModelMenu->mEmblemData != NULL && gKartModelMenu->mEmblemPalette != NULL &&
            gKartModelMenu->mFiles[gKartModelMenu->mLoadSlotIndex].mLoadRequested == FALSE) {
            QueueKartEmblemTexture(gKartModelMenu->mEmblemData, gKartModelMenu->mEmblemPalette);
        }
    }
    func_02077b1c();
}

void func_020783c8(void) {
    s16 i = gKartModelMenu->mShownSlotIndex;
    if (i >= 0) {
        AdvanceModelAnimation(gKartModelMenu->mSlots[i].mCharacterAnimation);
        if (gKartModelMenu->mFiles[gKartModelMenu->mLoadSlotIndex].mLoadRequested == FALSE) {
            QueueKartEmblemTexture(func_ov001_021a2398(), func_ov001_021a23ac());
        }
    }
}

void AdvanceKartModelMenuInput(void) {
    KartModelMenuView *q = &gKartModelMenu->mView;
    s32 a = 0;
    BOOL b;
    s32 d;
    s32 w;
    u16 k;
    Unk02175628Index v1;
    s32 v = 2;
    KartModelMenuFiles *p;

    p = &gKartModelMenu->mFiles[gKartModelMenu->mLoadSlotIndex];
    if (data_0217aa0c->mUnk_f8 == 0 && p->mLoadRequested == FALSE) {
        w = ~a;
        v1 = UNK_02175628_INDEX_8;
        k = data_02175628[v1].mUnk_00;
        if ((u16) (k & PAD_KEY_R) != 0) {
            d = a;
            do {
                gKartModelMenu->mKartIndex++;
                if (gKartModelMenu->mKartIndex > 0x23) {
                    gKartModelMenu->mKartIndex = a;
                }
                if (func_02077a70(&w, gKartModelMenu->mKartIndex) != 0) {
                    RequestKartModelMenuCharacter(w);
                    RequestKartModelMenuKart(gKartModelMenu->mKartIndex);
                    d = 1;
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, a, 0x1fd);
                }
            } while (d == 0);
            gKartModelMenu->mKartListPos++;
            if (gKartModelMenu->mKartListPos >= gKartModelMenu->mKartListCount) {
                gKartModelMenu->mKartListPos = 0;
            }
        } else if ((u16) (k & PAD_KEY_L) != 0) {
            d = a;
            do {
                gKartModelMenu->mKartIndex--;
                if (gKartModelMenu->mKartIndex < 0) {
                    gKartModelMenu->mKartIndex = 0x23;
                }
                if (func_02077a70(&w, gKartModelMenu->mKartIndex) != 0) {
                    RequestKartModelMenuCharacter(w);
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
    func_02108e6c(2);
    v1 = UNK_02175628_INDEX_8;
    k = data_02175628[v1].mBits;
    if ((u16) (k & PAD_KEY_RIGHT) != 0) {
        q->mYawAngle += 0x1c2;
        b = TRUE;
    } else if ((u16) (k & PAD_KEY_LEFT) != 0) {
        q->mYawAngle -= 0x1c2;
        b = TRUE;
    }
    v1 = UNK_02175628_INDEX_8;
    k = data_02175628[v1].mBits;
    if ((u16) (k & PAD_KEY_DOWN) != 0) {
        q->mUnk_18 += 0x1c2;
        if (q->mUnk_18 > 0x1b58) {
            q->mUnk_18 = 0x1b58;
        } else {
            d = 1;
        }
    } else if ((u16) (k & PAD_KEY_UP) != 0) {
        q->mUnk_18 -= 0x1c2;
        if (q->mUnk_18 < -0x1388) {
            q->mUnk_18 = -0x1388;
        } else {
            d = 1;
        }
    }
    if (d != 0 || b != FALSE) {
        a = 1;
    }
    func_02108e6c(1);
    v1 = UNK_02175628_INDEX_8;
    k = data_02175628[v1].mBits;
    if ((u16) (k & PAD_KEY_X) != 0) {
        q->mScale += 0x7b;
        if (q->mScale > data_usa_021656e0) {
            q->mScale = data_usa_021656e0;
        } else {
            v = 0;
        }
    } else {
        v1 = UNK_02175628_INDEX_8;
        k = data_02175628[v1].mBits;
        if ((u16) (k & PAD_KEY_B) != 0) {
            q->mScale -= 0x7b;
            if (q->mScale < 0x800) {
                q->mScale = 0x800;
            } else {
                v = 1;
            }
        }
    }
    q->mUnk_1a = q->mUnk_18;
    func_02110aac(v, a);
    func_02077b3c();
    func_02077b1c();
}

void DrawKartModelMenu(void) {
    KartModelMenuSlot *p;
    KartModelMenuView *q;
    if (gKartModelMenu->mShownSlotIndex >= 0) {
        p = &gKartModelMenu->mSlots[gKartModelMenu->mShownSlotIndex];
        q = &gKartModelMenu->mView;
        if (q->mCharacterIndex != -1 && q->mKartIndex != -1) {
            SetupLightFrustumAndLookAt(q->mBg0Offset, data_usa_021656ec);
            DrawKartModelMenuSlot(p, &gKartModelMenu->mView, gKartModelMenu->mMirrorMode);
            func_01ff9234();
        }
    }
}

void DrawKartModelMenuUnmirrored(void) {
    KartModelMenuSlot *p;
    if (gKartModelMenu->mShownSlotIndex >= 0) {
        p = &gKartModelMenu->mSlots[gKartModelMenu->mShownSlotIndex];
        SetupLightFrustumAndLookAt(0, data_usa_021656ec);
        DrawKartModelMenuSlot(p, &gKartModelMenu->mView, 0);
        func_01ff9234();
    }
}

void func_02078078(void) {
    u16 i;
    for (i = 0; i < 8; i++) {
        gKartModels->mUnk_018[i] = data_0217b488->mUnk_10c[i];
    }
}

void func_0207800c(void) {
    u32 i;
    if (gKartModels->mUnk_014 != NULL) {
        func_02078078();
        for (i = 0; i < gRaceSetup->mKartCount; i = (u16) (i + 1)) {
            if (gKartModels->mKartModelsEntries[i].mUnk_000 == 0xc) {
                func_02077f9c(i, &gKartModels->mKartModelsEntries[i], func_02077f7c(i));
            }
        }
    }
}

void func_02077f9c(int param_1, struct KartModelsEntry *param_2, Unk0217ad00_014 *param_3) {
    NNSG3dResMdl *e;
    u8 *t;
    u8 *u;
    u8 *w;
    s32 k;
    s32 h;
    e = param_2->mModels[0]->mResMdl;
    DC_FlushRange(param_3, 0x20);
    if (IsCharacterPNameUsed(param_1) != 0) {
        k = NNS_G3dGetResDictIdxByName((u8 *) e + e->mOfsMat + 4, data_usa_02154ff8);
    } else {
        k = NNS_G3dGetResDictIdxByName((u8 *) e + e->mOfsMat + 4, data_usa_02155068);
    }
    t = (u8 *) e + e->mOfsMat;
    u = t + 4;
    w = u + *(u16 *) (t + 0xa);
    h = ((NNSG3dResMatData *) (t + *(u32 *) (w + *(u16 *) w * k + 4)))->mTexPlttBase << 4;
    GX_BeginLoadTexPltt();
    GX_LoadTexPltt(param_3, h, 0x20);
    GX_EndLoadTexPltt();
}

Unk0217ad00_014 *func_02077f7c(int param_1) {
    Unk0217ad00_014 *r = NULL;
    if (gKartModels->mUnk_014 != NULL) {
        r = gKartModels->mUnk_014 + gKartModels->mUnk_018[param_1];
    }
    return r;
}

void func_02077f5c(void) {
    gKartModelMenu->mUnk_1dc = TRUE;
    gKartModelMenu->mUnk_1f0 = 0;
}

#pragma thumb off

#pragma thumb on

void func_02077f48(u32 p0) {
    gKartModelMenu->mUnk_1d8 = p0;
}

// Moves *a toward b by a share of the distance plus 100; keeps the old value when the step would reach b.
void AdvanceAngleToward(u16 *a, int b, u32 c) {
    u16 v1;
    int v2;
    int v3;
    v1 = *a;
    v3 = b - v1;
    if (v3 < 0) {
        v3 = 0xffff - v3;
    }
    v2 = FX_MulFunc(v3, c);
    *a = *a + v2;
    if (((*a + 100) - b) < 0) {
        *a = *a + 100;
        return;
    }
    *a = v1;
}

#pragma thumb off

#pragma thumb on

Nclr *GetEmblemSBNclr(void) {
    return gEmblemSBNclr;
}

#pragma thumb off

#pragma thumb on

void InitKartModelMenuFiles(void *a, KartModelMenuFiles *b) {
    void *v1;
    struct NNSiFndHeapHead *v2;
    v1 = HeapAlloc(a, 0xf000);
    v2 = NNS_FndCreateExpHeapEx(v1, 0xf000, 0);
    b->mHeap = v2;
    b->mHeapMemory = v1;
    b->mUnk_10 = NULL;
    b->mUnk_0c = b->mUnk_10;
    b->mUnk_08 = b->mUnk_0c;
    b->mUnk_1c = NULL;
    b->mUnk_18 = b->mUnk_1c;
    b->mUnk_14 = b->mUnk_18;
    b->mUnk_28 = NULL;
    b->mUnk_24 = b->mUnk_28;
    b->mUnk_20 = b->mUnk_24;
    b->mLoadRequested = FALSE;
    b->mLoadStep = 0;
}

#pragma thumb off

#pragma thumb on

void LoadKartAndCharacterFiles(void) {
    KartModelMenuFiles *a;
    s32 b;
    KartModelMenuFiles *p;
    s32 c;
    s32 i;
    char *e;

    a = gKartModelMenu->mFiles;
    i = gKartModelMenu->mLoadSlotIndex;
    p = &a[i];
    b = gKartModelMenu->mLoadSlot->mUnk_00;
    c = gKartModelMenu->mLoadSlot->mUnk_04;
    p->mLoadStep = 0;
    NNS_FndDestroyExpHeap(p->mHeap);
    p->mHeap = NNS_FndCreateExpHeapEx(p->mHeapMemory, 0xf000, 0);
    if (b != -1 && p->mUnk_08 != NULL) {
        NNS_G3dResDefaultRelease(p->mUnk_08);
        NNS_G3dResDefaultRelease(p->mUnk_0c);
        NNS_G3dResDefaultRelease(p->mUnk_10);
        NNS_G3dResDefaultRelease(p->mUnk_18);
        NNS_G3dResDefaultRelease(p->mUnk_1c);
        NNS_G3dResDefaultRelease(p->mUnk_20);
        NNS_G3dResDefaultRelease(p->mUnk_24);
        NNS_G3dResDefaultRelease(p->mUnk_28);
    }
    e = (char *) &gKartModelMenu->mUnk_1c8[c];
    LoadFileIntoHeap(BuildCharacterNsbmdPath(b, 1), p->mHeap, (void **) &p->mUnk_08);
    LoadFileIntoHeap(BuildCharacterNsbtxPath(b, 1), p->mHeap, (void **) &p->mUnk_0c);
    LoadFileIntoHeap(BuildCharacterNsbcaPath(b, 2), p->mHeap, &p->mUnk_14);
    LoadFileIntoHeap(BuildEmblemNsbtxPath(b), p->mHeap, (void **) &p->mUnk_10);
    LoadFileIntoHeap(BuildKartNsbmdPath(c), p->mHeap, (void **) &p->mUnk_18);
    LoadFileIntoHeap(BuildKartNsbtxPath(c), p->mHeap, (void **) &p->mUnk_1c);
    LoadFileIntoHeap(BuildKartShadowNsbmdPath(c), p->mHeap, (void **) &p->mUnk_28);
    LoadFileIntoHeap(BuildTireNsbmdPath(c, e), p->mHeap, (void **) &p->mUnk_20);
    LoadFileIntoHeap(BuildTireNsbtxPath(c, e), p->mHeap, (void **) &p->mUnk_24);
}

// Builds the slot being loaded over three calls, then shows it and loads into the other slot next.
void AdvanceKartModelMenuLoad(void) {
    KartModelMenuFiles *p;
    KartModelMenuSlot *q;
    KartModelMenuSlot *e;
    Unk0217ad08_058_08 *r;

    G2Bg0OfsWrite(gKartModelMenu->mView.mBg0Offset);
    if (data_0217aa0c->mUnk_f8 == 0) {
        p = &gKartModelMenu->mFiles[gKartModelMenu->mLoadSlotIndex];
        if (p->mLoadRequested != FALSE) {
            q = gKartModelMenu->mLoadSlot;
            if (p->mLoadStep == 0) {
                CreateKartModelMenuCharacter(p->mHeap, q->mUnk_10, q->mCharacterAnimation, p->mUnk_08, p->mUnk_0c,
                                             p->mUnk_14);
                p->mLoadStep++;
                return;
            }
            if (p->mLoadStep == 1) {
                LoadKartModelMenuEmblemTexData(p->mUnk_10);
                gKartModelMenu->mLoadSlot->mEmblemTex = gKartModelMenu->mEmblemTex;
                CreateKartModelMenuShadow(q->mUnk_1c, p->mUnk_28);
                CreateKartModelMenuTire(q->mUnk_18, p->mUnk_20, p->mUnk_24);
                p->mLoadStep++;
                return;
            }
            CreateKartModelMenuKart(q->mUnk_14, p->mUnk_18, p->mUnk_1c);
            SetupKartModelEmblemTex(gKartModelMenu->mLoadSlot);
            UploadKartAPaletteSlice(q->mUnk_14, q->mUnk_04, gKartModelMenu->mUnk_1d0);
            UploadKartModelsEntryPalettes((struct KartModelsEntry *) q, 1);
            p->mLoadRequested = FALSE;
            p->mLoadStep = 0;
            if (gKartModelMenu->mShownSlotIndex >= 0) {
                e = &gKartModelMenu->mSlots[gKartModelMenu->mShownSlotIndex];
                if (q->mUnk_00 == e->mUnk_00) {
                    r = q->mCharacterAnimation;
                    r->mUnk_0c = e->mCharacterAnimation->mUnk_0c;
                    *r->mUnk_1c[r->mUnk_1a] = r->mUnk_0c;
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

void InitLnkVramManagers(void *a) {
    u32 v1;
    u32 v2;
    RangeEntry *v3;
    RangeEntry *v4;
    v1 = NNS_GfdGetLnkTexVramManagerWorkSize(0x20);
    v2 = func_020172d0(0x20);
    v3 = HeapAlloc(a, v1);
    v4 = HeapAlloc(a, v2);
    NNS_GfdInitLnkTexVramManager(0x00040000u, 0x00020000u, v3, v1, 1);
    NNS_GfdInitLnkPlttVramManager(0x00010000u, v4, v2, 1);
}

#pragma thumb off
