#include "Main/Unknown/code_020c3e44.h"

#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b1cf4.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020b837c.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_020b3000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02022030.h"
#include "Main/Unknown/code_020c476c.h"
#include "Main/Unknown/code_02036820.h"
#include "code_0200eddc.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "code_0214c778.h"
#include "Main/Unknown/code_020c4bd8.h"
#include "Main/Unknown/code_0212a724.h"
#include "g2d_CharCanvas.h"
#include "code_0214b824.h"
#include "Main/Unknown/code_020b47b4.h"
#include "g2d_NOB_load.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Unknown/code_02025d5c.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_0212030c.h"
#include "code_02142eac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_020b85dc.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c53c4.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b19f8.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_020c5ccc.h"
#include "Main/Unknown/code_020c5ce0.h"
#include "Main/Unknown/code_0205f000.h"
#include "Main/Unknown/code_020c5db0.h"
#include "Main/Unknown/code_020b33d8.h"
#include "Main/Unknown/code_0203c5f8.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"
#include "registers.h"

u32 func_020c5dc4(void) {
    return (gRaceGoalM->mUnk_00);
}

u32 GetRaceGoalMUpdateFrames(void) {
    return (gRaceGoalM->mUpdateFrames);
}

void InitRaceGoalM(void) {
    gRaceGoalM = HeapAlloc(GetHeap(func_020364e8()), 0x1c);
    gRaceGoalM->mUnk_00 = 1;
    gRaceGoalM->mUpdateFrames = 0;
    gRaceGoalM->mRankIndex = 0;
    gRaceGoalM->mPointsGained = 0;
    gRaceGoalM->mFirstPlaceKartIndex = 0;
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        if (func_0205fd78(gRaceSetup->mMode == MODE_MISSION_RUN ? gRaceSetup->mMissionTableRow : -1,
                          gRaceSetup->mMode == MODE_MISSION_RUN ? gRaceSetup->mMissionTableColumn : -1,
                          &gRaceGoalM->mUnk_14) == 0) {
            gRaceGoalM->mUnk_14 = 9;
        }
    } else {
        gRaceGoalM->mUnk_14 = 9;
    }
    gRaceGoalM->mUnk_18 = 9;
}

u32 ClearRaceGoalMPointer(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gRaceGoalM;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

void UpdateRaceGoalM(void) {
    u32 b;
    s32 a;
    u16 i;
    s32 n;
    u16 x;
    s32 *q;
    Unk0217aa1c_00 *p;

    n = gRaceGoalM->mUpdateFrames;
    x = GetFollowedKartOrEntryIndex();
    if (gRaceProgress->mUnk_000[x].mStatus == 1 || gRaceProgress->mRaceDone != 0) {
        gRaceGoalM->mUnk_00 = 0;
    }
    if (func_020b1d0c() == 0) {
        return;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        if ((IsKartEnded((u16) gRaceSetup->mEntryIndex) != 0 ? gRaceProgress->mEntryEndKind : 6) != 0 &&
            func_0207a218() == 0 && n == 0) {
            return;
        }
    }
    q = &gRaceGoalM->mUpdateFrames;
    if (*q < 0x7fffffff) {
        *q = *q + 1;
    }
    switch (gRaceSetup->mMode) {
        case MODE_GRAND_PRIX:
            gRaceGoalM->mRankIndex = GetKartRank(GetFollowedKartOrEntryIndex()) - 1;
            b = func_0205dc7c(GetFollowedKartOrEntryIndex());
            a = GetCourseIndexInCup();
            p = &data_0217aa1c->mUnk_000[a][func_0205dc7c(b)];
            a = p->mUnk_00;
            gRaceGoalM->mPointsGained = a - GetKartPreviousTotalPoints(GetFollowedKartOrEntryIndex());
            if (n > 0x14) {
                gRaceGoalM->mUnk_00 = 1;
            }
            break;
        case MODE_TIME_ATTACK:
            if (n > 0x14) {
                gRaceGoalM->mUnk_00 = 1;
            }
            break;
        case MODE_VS:
        case 5:
            gRaceGoalM->mRankIndex = GetKartRank(GetFollowedKartOrEntryIndex()) - 1;
            for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
                if (GetKartRank(i) == 1) {
                    break;
                }
            }
            gRaceGoalM->mFirstPlaceKartIndex = i;
            if (n > 0x14) {
                gRaceGoalM->mUnk_00 = 1;
            }
            break;
        case MODE_MISSION_RUN:
            if (IsKartEnded((u16) gRaceSetup->mEntryIndex) != 0 ? gRaceProgress->mEntryEndKind : 6) {
                gRaceGoalM->mUnk_18 = 9;
            } else {
                gRaceGoalM->mUnk_18 = func_0205d140();
            }
            if ((IsKartEnded((u16) gRaceSetup->mEntryIndex) != 0 ? gRaceProgress->mEntryEndKind : 6) == 0) {
                if (n == 1) {
                    switch (gRaceGoalM->mUnk_18) {
                        case 0:
                        case 1:
                        case 2:
                        case 3:
                        case 4:
                            break;
                        case 5:
                            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1b);
                            break;
                        case 6:
                            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1c);
                            break;
                        case 7:
                            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x1d);
                            break;
                    }
                } else if (n > 0x1e) {
                    gRaceGoalM->mUnk_00 = 1;
                }
            } else if (n > 0x4b) {
                gRaceGoalM->mUnk_00 = 1;
            }
            break;
        default:
            gRaceGoalM->mUnk_00 = 1;
            break;
    }
}

void DrawRaceGoalM(Unk020c06c4 *a) {
    s32 y;
    s32 k;
    s32 e[2];
    void *c;

    if (gRaceSetup->mRaceKind != RACE_KIND_NORMAL) {
        return;
    }
    if (func_020b1d0c() == 0) {
        return;
    }
    switch (gRaceSetup->mMode) {
        case MODE_GRAND_PRIX:
            DrawRaceGoalMGrandPrix(a);
            break;
        case MODE_VS:
        case 5:
            y = InterpolateS16(1, 0x40, 0, gRaceGoalM->mUpdateFrames, 0x14);
            c = GetRaceGoalMNcerEntry(gRaceGoalM->mRankIndex);
            e[0] = 0x18000;
            e[1] = (y + 0xa8) << 12;
            k = a->mUnk_400;
            a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, c, NULL, e, 0, 1);
            break;
        case MODE_MISSION_RUN:
            DrawRaceGoalMMissionRun(a);
            break;
    }
}

void DrawRaceGoalMGrandPrix(Unk020c06c4 *a) {
    s32 y;
    s32 k;
    s32 e0[2];
    s32 e1[2];
    s32 e2[2];
    s32 e3[2];
    s32 e4[2];
    s32 z;
    void *c;

    y = InterpolateS16(1, 0x40, 0, gRaceGoalM->mUpdateFrames, 0x14);
    c = GetRaceGoalMNcerEntry(gRaceGoalM->mRankIndex);
    e0[0] = 0x18000;
    e0[1] = (y + 0xa8) << 12;
    k = a->mUnk_400;
    a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, c, NULL, e0, 0, 1);

    c = GetRaceGoalMNcerEntry(gRaceGoalM->mPointsGained + 8);
    e1[0] = 0x48000;
    e1[1] = (y + 0xb0) << 12;
    k = a->mUnk_400;
    a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, c, NULL, e1, 0, 1);

    c = GetRaceGoalMNcerEntry(func_020b4b98(gRaceGoalM->mPointsGained) != FALSE ? 0x13 : 0x14);
    e2[0] = 0x48000;
    e2[1] = (y + 0xb0) << 12;
    k = a->mUnk_400;
    a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, c, NULL, e2, 0, 1);

    c = GetRaceGoalMNcerEntry(0x40);
    e3[0] = 0xda000;
    e3[1] = (y + 0xa6) << 12;
    k = a->mUnk_400;
    a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, c, NULL, e3, 0, 1);

    c = GetRaceGoalMNcerEntry(0x41);
    e4[0] = 0xda000;
    e4[1] = (y + 0xa6) << 12;
    k = a->mUnk_400;
    a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, c, NULL, e4, 0, 1);
}

void DrawRaceGoalMMissionRun(Unk020c06c4 *a) {
    s32 n;
    s32 y;
    s32 k;
    s32 v;
    s32 t;
    s32 e[2];
    void *c;

    n = gRaceGoalM->mUpdateFrames;
    y = InterpolateS16(1, -0x80, 0, n, 0x14);
    if (gRaceGoalM->mUnk_14 != 9 && gRaceGoalM->mUnk_18 > gRaceGoalM->mUnk_14 && n >= 0x1e) {
        t = n - 10;
        if (t < 0x54) {
            n = t % 12;
            if (n >= 8) {
                return;
            }
        }
    }
    switch (gRaceGoalM->mUnk_18) {
        case 0:
            v = 7;
            break;
        case 1:
            v = 6;
            break;
        case 2:
            v = 5;
            break;
        case 3:
            v = 4;
            break;
        case 4:
            v = 3;
            break;
        case 5:
            v = 2;
            break;
        case 6:
            v = 1;
            break;
        case 7:
            v = 0;
            break;
    }
    if (gRaceGoalM->mUnk_18 >= 8) {
        return;
    }
    c = GetRaceGoalMrMNcerEntry(v);
    e[0] = (y + 0x80) << 12;
    e[1] = 0x60000;
    k = a->mUnk_400;
    a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[k], 0x80 - k, c, NULL, e, 0, 1);
}

void InitRaceLinkLevel(void) {
    gRaceLinkLevel = HeapAlloc(GetHeap(func_020364e8()), 0x14);
    gRaceLinkLevel->mUnk_00 = 0;
    gRaceLinkLevel->mUnk_04 = 0;
    gRaceLinkLevel->mUnk_08 = 0;
    gRaceLinkLevel->mUnk_0c = 0;
    gRaceLinkLevel->mUnk_10 = 0;
}

u32 ClearRaceLinkLevelPointer(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gRaceLinkLevel;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

void UpdateRaceLinkLevel(void) {
    if (gRaceLinkLevel == NULL) {
        return;
    }
    if (data_021759d0->mUnk_20 == 0) {
        return;
    }
    if (gRaceSetup->mMode == 5) {
        gRaceLinkLevel->mUnk_04 = func_021205e8();
        gRaceLinkLevel->mUnk_0c = gRaceLinkLevel->mUnk_10;
        gRaceLinkLevel->mUnk_10 = func_0212a8d0();
        if (gRaceLinkLevel->mUnk_10 != 0 && gRaceLinkLevel->mUnk_0c == 0) {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x26);
        }
        if (gRaceLinkLevel->mUnk_10 != 0) {
            gRaceLinkLevel->mUnk_08++;
            if (gRaceLinkLevel->mUnk_08 >= 0x78) {
                gRaceLinkLevel->mUnk_08 = 0;
            }
        } else {
            gRaceLinkLevel->mUnk_08 = 0;
            gRaceLinkLevel->mUnk_0c = 0;
            gRaceLinkLevel->mUnk_10 = 0;
        }
    } else {
        gRaceLinkLevel->mUnk_00 = data_0217aa00->mUnk_0004 == 0 ? 0 : WM_GetLinkLevel();
    }
}

void DrawRaceLinkLevel(Unk020c06c4 *a) {
    void *p = NULL;
    void *q = NULL;

    if (gRaceLinkLevel == NULL) {
        return;
    }
    if (data_021759d0->mUnk_20 != 0) {
        if (func_020b1d20() == 0) {
            if (gRaceSetup->mMode == 5) {
                p = GetRaceMNcerEntry(gRaceLinkLevel->mUnk_04 + 0x28);
            } else {
                p = GetRaceMNcerEntry(gRaceLinkLevel->mUnk_00 + 0x28);
            }
        } else {
            if (gRaceSetup->mMode == 5) {
                p = GetRaceGoalMNcerEntry(gRaceLinkLevel->mUnk_04 + 0x3c);
            } else {
                p = GetRaceGoalMNcerEntry(gRaceLinkLevel->mUnk_00 + 0x3c);
            }
        }
        if (gRaceSetup->mMode == 5 && gRaceLinkLevel->mUnk_10 != 0 && gRaceLinkLevel->mUnk_08 < 0x69) {
            if (func_020b1d20() != 0) {
                q = GetRaceGoalMNcerEntry(0x42);
            } else {
                q = GetRaceMNcerEntry(0x2c);
            }
        }
    }
    if (p != NULL) {
        s32 v[2];
        s32 w[2];
        s32 n;
        Unk020c06c4_08 *e;

        n = a->mUnk_400;
        v[0] = 0xf8000;
        v[1] = 0xb8000;
        e = &a->mUnk_000.mUnk_00[n];
        a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) e, 0x80 - n, p, NULL, v, 0, 1);
        for (; n < a->mUnk_400; n++, e++) {
            e->mUnk_0a = 2;
            e->mUnk_0e = 1;
        }
        w[0] = 0xf8000;
        w[1] = 0xb8000;
        n = a->mUnk_400;
        a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[n], 0x80 - n, p, NULL, w, 0, 1);
    }
    if (q != NULL) {
        s32 v[2];
        s32 w[2];
        s32 n;
        Unk020c06c4_08 *e;

        n = a->mUnk_400;
        v[0] = 0xf8000;
        v[1] = 0xa7000;
        e = &a->mUnk_000.mUnk_00[n];
        a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) e, 0x80 - n, q, NULL, v, 0, 1);
        for (; n < a->mUnk_400; n++, e++) {
            e->mUnk_0a = 2;
            e->mUnk_0e = 1;
        }
        w[0] = 0xf8000;
        w[1] = 0xa7000;
        n = a->mUnk_400;
        a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &a->mUnk_000.mUnk_00[n], 0x80 - n, q, NULL, w, 0, 1);
    }
}

void UploadRaceStartGpOam(void) {
    u32 v;
    u32 p;

    DC_FlushRange(&gRaceStartGp->mMainOam, 0x400);
    GX_LoadOAM(&gRaceStartGp->mMainOam, 0, 0x400);
    v = (reg_GX_POWCNT & 0x8000) >> 15;
    if (v != 0) {
        if (v == 1) {
            p = (reg_GX_DISPCNT & 0x1f00) >> 8;
            reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | ((p | 0x10) << 8);
        }
    } else {
        p = (reg_GX_DISPCNT & 0x1f00) >> 8;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | ((p & ~0x10) << 8);
    }
}

void InitRaceStartGp(void) {
    Unk02021dc8 *ncer;
    u8 buf[0x20];
    Unk02180728 w;
    void *r;
    s32 s;
    s32 i;

    gRaceStartGp = HeapAlloc(GetHeap(func_020364e8()), 0x41c);
    for (i = 0; i < 0x80; i++) {
        Unk020c06c4_08 *e = &gRaceStartGp->mMainOam.mUnk_000.mUnk_00[i];
        e->mUnk_0a = 3;
    }
    gRaceStartGp->mUpdateFrames = 0;
    LoadNclrData(&gRaceStartGp->mRaceStartGpMONclr, FindSceneFileWrapper("race_start_gp_m_o.NCLR"));
    LoadNcgrData2(&gRaceStartGp->mRaceStartGpMONcgr, FindSceneFileWrapper("race_start_gp_m_o.NCGR"));
    ncer = NULL;
    LoadNcerData(&ncer, FindSceneFileWrapper("race_start_gp_m.NCER"));
    for (i = 0; i < 3; i++) {
        gRaceStartGp->mRaceStartGpMNcerEntries[i] = NNS_G2dGetCellDataByIdx(ncer, (u16) i);
    }
    r = func_020b403c(2);
    s = -1;
    NNS_G2dCharCanvasInitForBG(buf, gRaceStartGp->mRaceStartGpMONcgr->mData, 0x20, 4, 4);
    w.mUnk_00 = buf;
    w.mUnk_04 = r;
    w.mUnk_08 = 1;
    w.mUnk_0c = 0;
    if (gRaceSetup->mMode == MODE_GRAND_PRIX) {
        s = func_02025d8c(gRaceSetup->mCourseId);
        w.mUnk_08 = func_020b4b10();
    } else if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        s = (gRaceSetup->mMode == MODE_MISSION_RUN ? gRaceSetup->mMissionTableRow : s) + 0x55;
        w.mUnk_08 = func_020b4b54();
    }
    NNSi_G2dTextCanvasDrawText(&w, 0, 9, 0xe, 0x40a, GetBmgEntry(func_020b47cc("common.bmg"), s));
    NNSi_G2dTextCanvasDrawText(&w, 0, 8, 0xe, 0x40a, GetBmgEntry(func_020b47cc("common.bmg"), s));
    DC_FlushRange(gRaceStartGp->mRaceStartGpMONcgr->mData, gRaceStartGp->mRaceStartGpMONcgr->mDataSize);
    GX_LoadOBJPltt(gRaceStartGp->mRaceStartGpMONclr->mData, 0, gRaceStartGp->mRaceStartGpMONclr->mDataSize);
    GX_LoadOBJ(gRaceStartGp->mRaceStartGpMONcgr->mData, 0, gRaceStartGp->mRaceStartGpMONcgr->mDataSize);
}

u32 ClearRaceStartGpPointer(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gRaceStartGp;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

u16 UpdateRaceStartGp(void) {
    u16 *v1;
    int *v2;
    v1 = ((u16 *) &reg_GX_POWCNT);
    v2 = (s32 *) gRaceStartGp;
    *v2 = (*(u32 *) v2) + 1;
    return *v1;
}

const Vec3 gVec3Zero = {0, 0, 0};

void DrawRaceStartGp(void) {
    Unk020c06c4 *p;
    Unk020224e0_c *c;
    s32 v[2];

    gRaceStartGp->mMainOam.mUnk_400 = 0;
    c = gRaceStartGp->mRaceStartGpMNcerEntries[0];
    p = &gRaceStartGp->mMainOam;
    v[0] = 0x80000;
    v[1] = 0x60000;
    p->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) &p->mUnk_000.mUnk_00[p->mUnk_400], 0x80 - p->mUnk_400, c,
                                         NULL, v, 0, 1);
    DC_FlushRange(&gRaceStartGp->mMainOam, 0x400);
    MI_DmaFill32(3, &gRaceStartGp->mMainOam.mUnk_000.mUnk_00[gRaceStartGp->mMainOam.mUnk_400], 0xc0,
                 (0x80 - gRaceStartGp->mMainOam.mUnk_400) * 8);
}

void HideRaceTaKartPositions(s32 a) {
    if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
        gRaceTaPositions->mKartVisible[a] = 0;
    }
}

void ResetRaceTaKartPositions(s32 a) {
    s32 i;
    s32 j;

    if (gRaceSetup->mMode != MODE_TIME_ATTACK) {
        return;
    }
    for (i = 0; i < 0x28; i++) {
        gRaceTaPositions->mSamples[a][i].mKind = 0;
    }
    for (j = 0; j < gRaceTaPositions->mUnk_790[a].mUnk_00; j++) {
        gRaceTaPositions->mUnk_790[a].mUnk_34[j] = 0x28;
    }
    gRaceTaPositions->mKartVisible[a] = 1;
}

void InitRaceTaPositions(void) {
    s32 a;
    s32 j;
    Vec3 v;

    if (gRaceSetup->mMode != MODE_TIME_ATTACK) {
        return;
    }
    gRaceTaPositions = HeapAlloc(GetHeap(func_020364e8()), 0x910);
    gRaceTaPositions->mVisible = 1;
    for (a = 0; a < gRaceSetup->mKartCount; a++) {
        gRaceTaPositions->mKartVisible[a] = 1;
    }
    gRaceTaPositions->mSampleFrames = 0;
    for (a = 0; a < gRaceSetup->mKartCount; a++) {
        u16 w = (u32) func_020b6338(a);
        func_0207a91c(&v, a);
        for (j = 0; j < 0x28; j++) {
            gRaceTaPositions->mSamples[a][j].mPos = v;
            gRaceTaPositions->mSamples[a][j].mAngle = w;
            gRaceTaPositions->mSamples[a][j].mKind = 0;
            gRaceTaPositions->mSamples[a][j].mUnk_14 = 3;
        }
    }
    a = 0;
    if (a < gRaceSetup->mKartCount) {
        Vec3 z = gVec3Zero;
        do {
            gRaceTaPositions->mUnk_790[a].mUnk_00 = 0;
            for (j = 0; j < 3; j++) {
                gRaceTaPositions->mUnk_790[a].mUnk_04[j] = z;
                gRaceTaPositions->mUnk_790[a].mUnk_34[j] = -1;
                gRaceTaPositions->mUnk_790[a].mUnk_28[j] = 3;
            }
            a++;
        } while (a < gRaceSetup->mKartCount);
    }
    for (a = 0; a < 16; a++) {
        s32 s = gPairsByAngle[((u16) (a * 0x10000 / 16) >> 4) * 2];
        s32 c = gPairsByAngle[((u16) (a * 0x10000 / 16) >> 4) * 2 + 1];
        gRaceTaPositions->mRotations[a].mUnk_00 = c;
        gRaceTaPositions->mRotations[a].mUnk_04 = s;
        gRaceTaPositions->mRotations[a].mUnk_08 = -s;
        gRaceTaPositions->mRotations[a].mUnk_0c = c;
    }
}

u32 ClearRaceTaPositionsPointer(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gRaceTaPositions;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

void UpdateRaceTaPositions(void) {
    Kart *p;
    RaceTaPositions *d;
    u16 j;
    s32 n;
    u32 i;

    if (gRaceSetup->mMode != MODE_TIME_ATTACK) {
        return;
    }
    if (IsRaceStartSequenceDone() == 0) {
        return;
    }
    if ((u16) (data_02175628[func_020435bc()].mUnk_00 & 4) != 0) {
        gRaceTaPositions->mVisible = gRaceTaPositions->mVisible == 0 ? 1 : 0;
    }
    for (i = 0; i < gRaceSetup->mKartCount; i = (u16) (i + 1)) {
        if ((gKartItems)[i].mUnk_204 != FALSE) {
            n = gRaceTaPositions->mUnk_790[i].mUnk_00;
            gRaceTaPositions->mUnk_790[i].mUnk_00 = n + 1;
            ((void (*)(Vec3 *, s32)) func_0207a91c)(&gRaceTaPositions->mUnk_790[i].mUnk_04[n], i);
            gRaceTaPositions->mUnk_790[i].mUnk_28[n] =
                func_020b4e70(&gRaceTaPositions->mUnk_790[i].mUnk_04[n]) != 0 ? 2 : 3;
        }
    }
    gRaceTaPositions->mSampleFrames++;
    if (gRaceTaPositions->mSampleFrames > 0xf) {
        gRaceTaPositions->mSampleFrames = 0;
        for (i = 0; i < gRaceSetup->mKartCount; i = (u16) (i + 1)) {
            for (j = 0; j < gRaceTaPositions->mUnk_790[i].mUnk_00; j = j + 1) {
                if (gRaceTaPositions->mUnk_790[i].mUnk_34[j] < 0x28) {
                    gRaceTaPositions->mUnk_790[i].mUnk_34[j]++;
                }
            }
        }
        func_020b1d50();
        func_020b1d50();
        for (i = 0; i < gRaceSetup->mKartCount; i = (u16) (i + 1)) {
            p = GetKart(i);
            d = gRaceTaPositions;
            for (j = 0x27; j != 0; j--) {
                d->mSamples[i][j] = d->mSamples[i][j - 1];
            }
            func_0207a91c(&gRaceTaPositions->mSamples[i][0].mPos, i);
            gRaceTaPositions->mSamples[i][0].mUnk_14 =
                func_020b4e70(&gRaceTaPositions->mSamples[i][0].mPos) != 0 ? 2 : 3;
            gRaceTaPositions->mSamples[i][0].mAngle = func_020b6338(i);
            if ((p->mUnk_44 & 0xa) != 0) {
                gRaceTaPositions->mSamples[i][0].mKind = 2;
            } else if ((p->mUnk_48 & 0x80020) != 0) {
                gRaceTaPositions->mSamples[i][0].mKind = 3;
            } else {
                gRaceTaPositions->mSamples[i][0].mKind = 1;
            }
            if (gRaceProgress->mRaceDone != 0) {
                gRaceTaPositions->mSamples[i][0].mKind = 0;
                gRaceTaPositions->mKartVisible[i] = 0;
            }
        }
    }
}

void DrawRaceTaPositions(Unk020c06c4 *a) {
    UnkPair020b502c o1;
    UnkPair020b502c o2;
    s32 w1[2];
    s32 w2[2];
    u16 c;
    void *r;
    float f;
    s32 v;
    s32 s;
    s32 i;
    s32 j;
    u32 m;
    s32 n;
    Unk020c06c4_08 *e;
    void *q;
    u32 h;
    s32 d;
    Unk020c06c4_08 *p;

    if (gRaceSetup->mMode != MODE_TIME_ATTACK) {
        return;
    }
    if (gRaceTaPositions->mVisible == 0) {
        return;
    }
    c = func_020ae5c4(a);
    for (i = 1; i < 16; i++) {
        func_020ae5c4(a);
    }
    if ((func_020b1d50() * 3) > 0) {
        f = (func_020b1d50() * 0x3000) + 0.5f;
    } else {
        f = (func_020b1d50() * 0x3000) - 0.5f;
    }
    v = f;
    s = ((s64) v * 20) >> 12;
    for (i = 0; i < gRaceSetup->mKartCount; i++) {
        if (gRaceTaPositions->mKartVisible[i] != 0) {
            if (gRaceProgress->mRaceDone == 0) {
                for (j = 0; j < gRaceTaPositions->mUnk_790[i].mUnk_00; j++) {
                    if (gRaceTaPositions->mUnk_790[i].mUnk_34[j] < 0x28) {
                        if (ComputeRaceHudSubScreenPosition(&gRaceTaPositions->mUnk_790[i].mUnk_04[j], &o1, s, 1, 1) !=
                            FALSE) {
                            m = gRaceTaPositions->mUnk_790[i].mUnk_28[j];
                            q = GetRaceSNcerEntry(0x4f);
                            n = a->mUnk_400;
                            w1[0] = o1.mUnk_00 << 12;
                            w1[1] = o1.mUnk_04 << 12;
                            e = &a->mUnk_000.mUnk_00[n];
                            a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) e, 0x80 - n, q, NULL, w1, 0, 1);
                            for (; n < a->mUnk_400; n++, e++) {
                                if (m != -1) {
                                    e->mUnk_0e = m;
                                }
                            }
                        }
                    }
                }
            }
            for (j = 0; j < 0x28; j++) {
                u16 x = (u16) (gRaceTaPositions->mSamples[i][j].mAngle + func_020b6368()) + 0x800;
                u16 y = ((x << 4) / 0x10000) % 16;
                if (ComputeRaceHudSubScreenPosition(&gRaceTaPositions->mSamples[i][j].mPos, &o2, s, 1, 1) != FALSE) {
                    switch (gRaceTaPositions->mSamples[i][j].mKind) {
                        case 0:
                            r = NULL;
                            break;
                        case 1:
                            r = GetRaceSNcerEntry(0x51);
                            break;
                        case 2:
                            r = GetRaceSNcerEntry(0x52);
                            break;
                        case 3:
                            r = GetRaceSNcerEntry(0x53);
                            break;
                    }
                    if (r != NULL) {
                        h = gRaceTaPositions->mSamples[i][j].mUnk_14;
                        d = a->mUnk_400;
                        w2[0] = o2.mUnk_00 << 12;
                        w2[1] = o2.mUnk_04 << 12;
                        p = &a->mUnk_000.mUnk_00[d];
                        a->mUnk_400 += NNS_G2dMakeCellToOams((Unk020224e0_o *) p, 0x80 - d, r,
                                                             &gRaceTaPositions->mRotations[y].mUnk_00, w2, y + c, 1);
                        for (; d < a->mUnk_400; d++, p++) {
                            if ((i != 0 ? 1 : -1) != -1) {
                                p->mUnk_0a = i != 0 ? 1 : -1;
                            }
                            if (h != -1) {
                                p->mUnk_0e = h;
                            }
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i < 16; i++) {
        Matrix2x2 *t = &gRaceTaPositions->mRotations[i];
        (a->mUnk_000.mUnk_20 + c)[i].mUnk_06 = t->mUnk_00 >> 4;
        (a->mUnk_000.mUnk_20 + c)[i].mUnk_0e = t->mUnk_04 >> 4;
        (a->mUnk_000.mUnk_20 + c)[i].mUnk_16 = t->mUnk_08 >> 4;
        (a->mUnk_000.mUnk_20 + c)[i].mUnk_1e = t->mUnk_0c >> 4;
    }
}
