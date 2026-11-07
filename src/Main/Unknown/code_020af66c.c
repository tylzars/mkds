#include "Main/Unknown/code_020af66c.h"

#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020b03bc.h"
#include "Main/Unknown/code_020b32ec.h"
#include "Main/Unknown/code_020b33d8.h"
#include "Main/Unknown/code_020b36c8.h"
#include "Main/Unknown/code_020b3728.h"
#include "Main/Unknown/code_020b3adc.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b85f0.h"
#include "Main/Unknown/code_020b8610.h"
#include "Main/Unknown/code_020b8624.h"
#include "Main/Unknown/code_020b9994.h"
#include "Main/Unknown/code_020ba50c.h"
#include "Main/Unknown/code_020bb5cc.h"
#include "Main/Unknown/code_020bb5ec.h"
#include "Main/Unknown/code_020bc108.h"
#include "Main/Unknown/code_020bc11c.h"
#include "Main/Unknown/code_020be950.h"
#include "Main/Unknown/code_020c214c.h"
#include "Main/Unknown/code_020c31ec.h"
#include "Main/Unknown/code_020c3e00.h"
#include "Main/Unknown/code_020c3e44.h"
#include "Main/Unknown/code_020c476c.h"
#include "Main/Unknown/code_020c4bd8.h"
#include "Main/Unknown/code_020c53c4.h"
#include "Main/Unknown/code_020c5ccc.h"
#include "Main/Unknown/code_020c5e30.h"
#include "Main/Unknown/code_020cf310.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020cffd0.h"
#include "Main/Unknown/code_020d129c.h"
#include "Main/Unknown/code_020d12e0.h"
#include "Main/Unknown/code_020d1298.h"
#include "Main/Unknown/code_020d1450.h"
#include "Main/Unknown/code_020d2090.h"
#include "Main/Unknown/code_020d2094.h"
#include "Main/Unknown/code_0212b1c0.h"
#include "Main/Unknown/code_0212b5d8.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_0200eddc.h"
#include "code_021488e8.h"
#include "code_02148950.h"
#include "code_0214a390.h"
#include "code_0214b338.h"
#include "code_0214b824.h"
#include "registers.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020adb04.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_020b2e98.h"
#include "Main/Unknown/code_020b36dc.h"
#include "Main/Unknown/code_020b3b08.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_020b65f0.h"
#include "Main/Unknown/code_020bb530.h"
#include "Main/Unknown/code_020b6d98.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_020beb9c.h"
#include "code_02022030.h"
#include "Main/Unknown/code_020cffa0.h"
#include "Main/Unknown/code_020d12b0.h"
#include "Main/Unknown/code_020d1464.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b2000.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020c5db0.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "code_0214c778.h"
#include "Main/Unknown/code_020ad000.h"
#include "Main/Unknown/code_020b3000.h"
#include "Main/Unknown/code_020b6000.h"
#include "Main/Unknown/code_020ba000.h"
#include "Main/Unknown/code_020bb000.h"
#include "Main/Unknown/code_020be7fc.h"
#include "Main/Unknown/code_020c5ce0.h"
#include "Main/Unknown/code_0212b1a8.h"
#include "Main/Unknown/code_0203c5f8.h"

void func_020b18b0(void) {
    if (func_020b64e8() != 0) {
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1c00;
    } else {
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1400;
    }
    GXS_SetGraphicsMode(5);
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~3) | 2;
    reg_G2S_DB_BG2CNT &= ~0x40;
    reg_G2S_DB_BG3CNT &= ~0x40;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & 0x43) | 0x8410;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 3;
    reg_G2S_DB_BG3CNT &= ~0x40;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x8810 | ((func_020b6430() != 0) << 13);
}

void func_020b17a4(void) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1e00;
    GXS_SetGraphicsMode(0);
    reg_G2S_DB_BG1OFS = 0;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
    reg_G2S_DB_BG1CNT &= ~0x40;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | 8;
    reg_G2S_DB_BG2OFS = 0x100;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~3) | 2;
    reg_G2S_DB_BG2CNT &= ~0x40;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & 0x43) | 0x4c08;
    reg_G2S_DB_BG3OFS = 0x100;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 2;
    reg_G2S_DB_BG3CNT &= ~0x40;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x4e08;
}

void func_020b0b8c(void) {
    s32 i;
    u32 v;
    s32 w;
    s32 a;

    v = gRaceSetup->mRaceKind;
    if (v == RACE_KIND_START_GP) {
        UploadRaceStartGpOam();
        return;
    }
    if (v == RACE_KIND_AWARD) {
        return;
    }
    if (v == RACE_KIND_STAFF_ROLL) {
        *(vu16 *) 0x05000000 = 0;
        func_020d159c();
        func_0212b1c0();
        return;
    }
    if (gRaceHud->mEnabled == FALSE) {
        return;
    }
    if (gRaceHud->mUnk_840 != FALSE) {
        GXS_LoadBG0Char(func_020b3374()->mData, 0, 0x3000);
        gRaceHud->mUnk_840 = FALSE;
        GX_LoadOBJPltt(GetRaceNclrNcgr(1)->mNclr->mData, 0, GetRaceNclrNcgr(1)->mNclr->mDataSize);
        GX_LoadOBJ(GetRaceNclrNcgr(1)->mNcgr->mData, 0, 0x4000);
        gRaceHud->mUnk_848 = 1;
        gRaceHud->mUnk_844 = 1;
        reg_GX_DISPCNT &= ~0xe000;
    } else if (gRaceHud->mUnk_844 != 0) {
        if (func_020b2ec0() == 0) {
            if (gRaceHud->mUnk_844++ >= gRaceHud->mUnk_850) {
                if (gRaceSetup->mMode == MODE_GRAND_PRIX && gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
                    w = (reg_GX_DISPCNT & 0x1f00) >> 8;
                    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | ((w | 8) << 8);
                    reg_G2_BG3CNT = (reg_G2_BG3CNT & ~3) | 1;
                    reg_G2_BG3CNT &= ~0x40;
                    reg_G2_BG3CNT = (reg_G2_BG3CNT & 0x43) | 0x500;
                    GX_LoadBGPltt(gRaceHud->mNclrs[0]->mData, 0, gRaceHud->mNclrs[0]->mDataSize);
                    GX_LoadBG3Char(gRaceHud->mNcgrs[0]->mData, 0, gRaceHud->mNcgrs[0]->mDataSize);
                    GX_LoadBG3Scr(gRaceHud->mNscrs[1]->mData, 0, 0x600);
                    G2x_SetBlendAlpha_(&reg_G2_BLDCNT, 8, 0x27, 5, 9);
                }
                gRaceHud->mUnk_844 = 0;
                gRaceHud->mUnk_84c = 1;
            }
        }
    }
    v = gRaceSetup->mMode;
    if (v == MODE_GRAND_PRIX && gRaceHud->mUnk_84c != 0) {
        reg_G2_BG3OFS = 0x01ff0000 & (InterpolateS16(1, -64, 0, GetRaceGoalMUpdateFrames(), 20) << 16);
    } else if (v == MODE_MISSION_RUN && gRaceHud->mUnk_84c != 0) {
        GXS_LoadBG0Char(func_020b3374()->mData, 0, 0x3000);
        GXS_LoadBG0Scr(func_020b32f8(), 0, 0x600);
    }
    DC_FlushRange(gRaceHud->mUnk_004, 0x400);
    GX_LoadOAM(gRaceHud->mUnk_004, 0, 0x400);
    DC_FlushRange(gRaceHud->mUnk_408, 0x400);
    GXS_LoadOAM(gRaceHud->mUnk_408, 0, 0x400);
    if (gRaceHud->mUnk_82c != FALSE) {
        switch (gRaceHud->mSubScreenState) {
            case 0:
                reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1c00;
                GXS_SetGraphicsMode(0);
                reg_G2S_DB_BG2OFS = 0;
                reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~3) | 2;
                reg_G2S_DB_BG2CNT &= ~0x40;
                reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & 0x43) | 0x208;
                reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~3) | 3;
                reg_G2S_DB_BG3CNT &= ~0x40;
                reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x308;
                GXS_LoadBGPltt(data_0217b34c, 0, 0x200);
                break;
            case 1:
            case 2:
            case 3:
                func_020b18b0();
                GXS_LoadBGPltt(GetChoisesSBNclr()->mData, 0, 0x200);
                break;
            case 4:
            case 5:
                reg_G2S_DB_BG0OFS = 0;
                reg_G2S_DB_BG0CNT = reg_G2S_DB_BG0CNT & ~3;
                reg_G2S_DB_BG0CNT &= ~0x40;
                reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & 0x43) | 0x10c;
                func_020b17a4();
                GXS_LoadBGPltt(func_020c3e2c(0)->mUnk_00->mData, 0, func_020c3e2c(0)->mUnk_00->mDataSize);
                GXS_LoadBG1Char(func_020c3e2c(0)->mUnk_04->mData, 0, func_020c3e2c(0)->mUnk_04->mDataSize);
                GXS_LoadOBJPltt(GetRaceNclrNcgr(7)->mNclr->mData, 0, 0x80);
                GXS_LoadOBJ(GetRaceNclrNcgr(7)->mNcgr->mData, 0, 0x4000);
                GXS_LoadBG0Char(func_020b3374()->mData, 0, 0x3000);
                GXS_LoadBG0Scr(func_020b32f8(), 0, 0x600);
                break;
            case 6:
                break;
        }
    }
    switch (gRaceHud->mSubScreenState) {
        case 0:
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1c00;
            a = gRaceHud->mUpdateFrames / 6;
            reg_G2S_DB_BG3OFS = (a & 0x1ff) | (((0x200 - a) << 16) & 0x01ff0000);
            break;
        case 1:
        case 2:
        case 3:
            if (gRaceSetup->mMode == MODE_MISSION_RUN) {
                GXS_LoadOBJPltt(GetRaceNclrNcgr(6)->mNclr->mData, 0, GetRaceNclrNcgr(6)->mNclr->mDataSize);
            }
            G2x_SetBGyAffine_(&reg_G2S_DB_BG2PA, gRaceHud->mUnk_858[0].mUnk_00, gRaceHud->mUnk_858[0].mUnk_10,
                              gRaceHud->mUnk_858[0].mUnk_14, gRaceHud->mUnk_858[0].mUnk_18,
                              gRaceHud->mUnk_858[0].mUnk_1c);
            if (func_020b64e8() != 0) {
                G2x_SetBGyAffine_(&reg_G2S_DB_BG3PA, gRaceHud->mUnk_858[1].mUnk_00, gRaceHud->mUnk_858[1].mUnk_10,
                                  gRaceHud->mUnk_858[1].mUnk_14, gRaceHud->mUnk_858[1].mUnk_18,
                                  gRaceHud->mUnk_858[1].mUnk_1c);
            }
            func_020cf340((Unk020cf340 *) &data_0217b34c[0x100]);
            if (func_020b64e8() != 0) {
                if (func_020b4e0c() != 0) {
                    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1c00;
                } else {
                    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1800;
                }
            } else {
                reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1400;
            }
            break;
        case 4:
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1e00;
            switch (gRaceSetup->mMode) {
                case MODE_BATTLE:
                case MODE_VS:
                    GXS_LoadBG0Char(func_020b3374()->mData, 0, 0x800);
                    break;
            }
            w = func_020c3e00();
            if (w < 0x100) {
                a = -w & 0x1ff;
                reg_G2S_DB_BG2OFS = a;
                reg_G2S_DB_BG3OFS = a;
                GXS_LoadBG2Scr(GetRaceGoalSNscr(1)->mData, 0, 0x600);
                GXS_LoadBG3Scr(GetRaceGoalSNscr(2)->mData, 0, 0x600);
            }
            break;
        case 5:
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1e00;
            switch (gRaceSetup->mMode) {
                case MODE_BATTLE:
                case MODE_VS:
                    GXS_LoadBG0Char(func_020b3374()->mData, 0, 0x800);
                    break;
            }
            w = func_020c3e00();
            if (gRaceHud->mUnk_830 != FALSE) {
                GXS_LoadBG1Scr(GetRaceGoalSNscr(3)->mData, 0, GetRaceGoalSNscr(3)->mDataSize);
                GXS_LoadBG2Scr(GetRaceGoalSNscr(4)->mData, 0, GetRaceGoalSNscr(4)->mDataSize);
                GXS_LoadBG3Scr(GetRaceGoalSNscr(5)->mData, 0, GetRaceGoalSNscr(5)->mDataSize);
                GXS_LoadOBJPltt(GetRaceNclrNcgr(8)->mNclr->mData, 0, 0x20);
                GXS_LoadOBJPltt(GetRaceNclrNcgr(8)->mNclr->mData + 0xc0, 0x180, 0x80);
                GXS_LoadOBJ(GetRaceNclrNcgr(8)->mNcgr->mData, 0, 0x4000);
                gRaceHud->mUnk_830 = FALSE;
            }
            if (w < 0x100) {
                reg_G2S_DB_BG2OFS = w & 0x1ff;
                reg_G2S_DB_BG3OFS = -w & 0x1ff;
            }
            break;
        case 6:
            if (gRaceHud->mUnk_834 != FALSE) {
                reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1200;
                GXS_SetGraphicsMode(0);
                reg_G2S_DB_BG1OFS = 0;
                reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
                reg_G2S_DB_BG1CNT &= ~0x40;
                reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | 8;
                GXS_LoadBGPltt(gRaceHud->mNclrs[1]->mData, 0, 0x20);
                GXS_LoadBG1Char(gRaceHud->mNcgrs[1]->mData, 0, gRaceHud->mNcgrs[1]->mDataSize);
                GXS_LoadBG1Scr(gRaceHud->mNscrs[2]->mData, 0, gRaceHud->mNscrs[2]->mDataSize);
                GXS_LoadOBJPltt(GetRaceNclrNcgr(9)->mNclr->mData, 0, 0xa0);
                GXS_LoadOBJPltt(GetRaceNclrNcgr(9)->mNclr->mData + 0xb0, 0x160, 0xa0);
                GXS_LoadOBJ(GetRaceNclrNcgr(9)->mNcgr->mData, 0, 0x4000);
                gRaceHud->mUnk_834 = FALSE;
            }
            break;
    }
    if (func_020b2e98() != 0) {
        if (gRaceProgress->mRaceDone == 0) {
            w = (reg_GX_DISPCNT & 0x1f00) >> 8;
            reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | ((w | 4) << 8);
            GX_LoadBG2Scr(gRaceHud->mNscrs[0]->mData, 0, 0x600);
        }
        GXS_LoadBG0Scr(func_020b32f8(), 0, 0x600);
        w = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | ((w | 1) << 8);
        G2x_SetBlendBrightnessExt_(&reg_G2S_DB_BLDCNT, 0x3e, 0x3f, 8, 8, -7);
    } else {
        w = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | ((w & ~1) << 8);
        w = (reg_GX_DISPCNT & 0x1f00) >> 8;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | ((w & ~4) << 8);
        G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 0x3f, 6, 10);
    }
    for (i = 0; i < gRaceSetup->mKartCount; i++) {
        if (gRaceHud->mUnk_89c[i] != 0 && gRaceHud->mUnk_8bc[i] == 0) {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x52);
            gRaceHud->mUnk_8bc[i] = 1;
        }
    }
}

void func_020b03bc(void) {
    s32 i;
    u32 v;
    u16 *p;
    u32 j;
    u16 w;

    v = gRaceSetup->mRaceKind;
    if (v == RACE_KIND_START_GP) {
        InitRaceStartGp();
        return;
    }
    if (v == RACE_KIND_AWARD) {
        return;
    }
    if (v == RACE_KIND_STAFF_ROLL) {
        InitEndingStaffRoll();
        InitStaffRollText(GetHeap(func_020364e8()));
        return;
    }
    gRaceHud = HeapAlloc(GetHeap(func_020364e8()), 0x914);
    InitRaceStartSequence();
    func_020b3b08();
    InitRaceHudSubScreenProjection();
    func_020b8624();
    func_020cffa0();
    if (gRaceSetup->mRaceKind == 4) {
        func_020d12b0();
    }
    func_020bb530();
    InitRaceLinkLevel();
    func_020ba520();
    InitRaceGoalM();
    InitRaceTimeDigits();
    InitRaceLapNumber();
    InitRaceMNumberPair();
    InitRaceGoalTimes();
    InitRaceRankList();
    InitRaceHudSubScreenCellGroups();
    InitRaceGoalS();
    InitRaceNewRecordTa();
    InitRaceTaPositions();
    gRaceHud->mUpdateFrames = 0;
    for (i = 0; i < 7; i++) {
        gRaceHud->mNclrs[i] = NULL;
        gRaceHud->mNcgrs[i] = NULL;
    }
    gRaceHud->mSubScreenState = 1;
    gRaceHud->mUnk_82c = FALSE;
    gRaceHud->mUnk_830 = FALSE;
    gRaceHud->mUnk_838 = FALSE;
    gRaceHud->mUnk_83c = FALSE;
    gRaceHud->mUnk_840 = FALSE;
    gRaceHud->mUnk_844 = 0;
    gRaceHud->mUnk_848 = 0;
    gRaceHud->mUnk_84c = 0;
    gRaceHud->mUnk_850 = 0;
    if (gRaceSetup->mMode == MODE_BATTLE) {
        switch (gRaceSetup->mCourseId) {
            case COURSE_ID_MINI_STAGE3:
                gRaceHud->mUnk_854 = 0x40;
                break;
            default:
                gRaceHud->mUnk_854 = 0x64;
                break;
        }
    } else if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        switch (gRaceSetup->mCourseId) {
            case COURSE_ID_MR_STAGE1:
            case COURSE_ID_MR_STAGE2:
            case COURSE_ID_MR_STAGE3:
            case COURSE_ID_MR_STAGE4:
                gRaceHud->mUnk_854 = 0x64;
                break;
            default:
                gRaceHud->mUnk_854 = 0x86;
                break;
        }
    } else {
        gRaceHud->mUnk_854 = 0x86;
    }
    gRaceHud->mEnabled = FALSE;
    for (i = 0; i < 8; i++) {
        gRaceHud->mUnk_89c[i] = 0;
        gRaceHud->mUnk_8bc[i] = 0;
    }
    gRaceHud->mUnk_8dc = 0;
    gRaceHud->mUnk_8e0 = -1;
    if (gRaceSetup->mMode == MODE_TIME_ATTACK && gRaceSetup->mKartCount > 1) {
        gRaceHud->mUseTimeDifference = 1;
    } else {
        gRaceHud->mUseTimeDifference = 0;
    }
    gRaceHud->mUnk_908 = 0;
    gRaceHud->mUnk_90c = FALSE;
    gRaceHud->mUnk_910 = gRaceSetup->mMode == MODE_MISSION_RUN ? func_020adc04() : 0;
    MI_DmaFill32(3, gRaceHud->mUnk_004, 0xc0, 0x400);
    MI_DmaFill32(3, gRaceHud->mUnk_408, 0xc0, 0x400);
    LoadNclrData(&gRaceHud->mNclrs[0], FindSceneFileWrapper("race_m_b.NCLR"));
    LoadNcgrData(&gRaceHud->mNcgrs[0], FindSceneFileWrapper("race_m_b.NCGR"));
    LoadNscrData(&gRaceHud->mNscrs[0], FindSceneFileWrapper("race_m_pause.NSCR"));
    LoadNscrData(&gRaceHud->mNscrs[1], FindSceneFileWrapper("race_m_goal.NSCR"));
    if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
        LoadNclrData(&gRaceHud->mNclrs[1], FindSceneFileWrapper("race_new_record_ta_s_b.NCLR"));
        LoadNcgrData(&gRaceHud->mNcgrs[1], FindSceneFileWrapper("race_new_record_ta_s_b.NCGR"));
        LoadNscrData(&gRaceHud->mNscrs[2], FindSceneFileWrapper("race_new_record_ta_s_bg.NSCR"));
        DC_FlushRange(((Ncgr *) gRaceHud->mNscrs[0])->mData, ((Ncgr *) gRaceHud->mNscrs[0])->mDataSize);
        DC_FlushRange(gRaceHud->mNscrs[2]->mData, gRaceHud->mNscrs[2]->mDataSize);
    }
    p = GetChoisesSBNclr()->mData;
    for (i = 0; i < 0x80; i++) {
        data_0217b34c[i + 0x80] = p[i + 0x80];
    }
    GetChoisesSBNclr()->mData[0] = data_0217b34c[0x100];
    DC_FlushRange(GetChoisesSBNclr()->mData, 0x200);
    for (i = 0; i < 0x20; i++) {
        w = GetChoisesSBNclr()->mData[i + 0xe0];
        func_020c3e2c(0)->mUnk_00->mData[i + 0xe0] = w;
    }
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 0x3f, 6, 10);
    if (gRaceSetup->mMode == MODE_GRAND_PRIX) {
        func_020b6dc4(GetRaceNclrNcgr(1)->mNclr->mData, GetRaceNclrNcgr(1)->mNcgr->mData);
        DC_FlushRange(GetRaceNclrNcgr(1)->mNclr->mData, GetRaceNclrNcgr(1)->mNclr->mDataSize);
        DC_FlushRange(GetRaceNclrNcgr(1)->mNcgr->mData, GetRaceNclrNcgr(1)->mNcgr->mDataSize);
    }
    func_020b6d98(GetRaceNclrNcgr(6)->mNclr->mData, GetRaceNclrNcgr(6)->mNcgr->mData);
    DC_FlushRange(GetRaceNclrNcgr(6)->mNclr->mData, GetRaceNclrNcgr(6)->mNclr->mDataSize);
    DC_FlushRange(GetRaceNclrNcgr(6)->mNcgr->mData, GetRaceNclrNcgr(6)->mNcgr->mDataSize);
    func_020b46d0(GetRaceNclrNcgr(6)->mNcgr->mData, 0x10, 0, 0x10, 2, GetRaceNclrNcgr(7)->mNcgr->mData, 0x10, 0);
    DC_FlushRange(GetRaceNclrNcgr(7)->mNcgr->mData, GetRaceNclrNcgr(7)->mNcgr->mDataSize);
    func_020b46d0(GetRaceNclrNcgr(6)->mNcgr->mData, 0x10, 0, 0x10, 2, GetRaceNclrNcgr(8)->mNcgr->mData, 0x10, 0);
    DC_FlushRange(GetRaceNclrNcgr(8)->mNcgr->mData, GetRaceNclrNcgr(8)->mNcgr->mDataSize);
    if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
        func_020b46d0(GetRaceNclrNcgr(6)->mNcgr->mData, 0x10, 0, 0x10, 2, GetRaceNclrNcgr(9)->mNcgr->mData, 0x10, 0);
        DC_FlushRange(GetRaceNclrNcgr(9)->mNcgr->mData, GetRaceNclrNcgr(9)->mNcgr->mDataSize);
    }
    func_020b36a4();
    func_020b3adc();
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        data_0217b488->mUnk_10 = 0;
    }
}

static inline void InitMap2D_inline(u16 *v1) {
    s32 j;
    s32 i;
    u16 *v2 = v1;

    for (i = 3; i < 24; i++) {
        s32 v3 = i * 32;
        for (j = 14; j < 32; j++) {
            s32 x = j + v3;
            s32 y = v3 + (45 - j);
            if (x < y) {
                u16 t = v2[y];
                v2[y] = v2[x];
                v2[x] = t;
            }
            v2[x] ^= 0x400;
        }
    }
}

void InitMap2D(void) {
    Nclr *nclrs[3];
    Ncgr *ncgrs[3];
    Nscr *nscrs[4];
    BOOL v1;
    s32 i;
    s32 k;

    v1 = gRaceSetup->mMode != MODE_MISSION_RUN;
    if (gRaceSetup->mRaceKind == RACE_KIND_START_GP) {
        return;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_AWARD || gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
        return;
    }
    data_0217b34c = HeapAlloc(GetHeap(func_020364e8()), 0x400);
    for (i = 0; i < 2; i++) {
        nclrs[i] = NULL;
        ncgrs[i] = NULL;
    }
    for (i = 0; i < 3; i++) {
        nscrs[i] = NULL;
    }

    if (func_02047250()) {
        if (v1) {
            LoadNclrData(&nclrs[0], FindCourseFileWrapper("Map2D/global.NCLR"));
            LoadNclrData(&nclrs[1], FindCourseFileWrapper("Map2D/global2.NCLR"));
        }
        LoadNclrData(&nclrs[2], FindCourseFileWrapper("Map2D/local.NCLR"));
    } else {
        if (v1) {
            LocateNclr(&nclrs[0], FindCourseFileWrapper("Map2D/global.NCLR"));
            LocateNclr(&nclrs[1], FindCourseFileWrapper("Map2D/global.NCLR"));
        }
        LocateNclr(&nclrs[2], FindCourseFileWrapper("Map2D/local.NCLR"));
    }

    if (func_02047250()) {
        if (v1) {
            LoadNcgrData(&ncgrs[0], FindCourseFileWrapper("Map2D/global.NCGR"));
            LoadNcgrData(&ncgrs[1], FindCourseFileWrapper("Map2D/global2.NCGR"));
        }
        LoadNcgrData(&ncgrs[2], FindCourseFileWrapper("Map2D/local.NCGR"));
    } else {
        if (v1) {
            LocateNcgr(&ncgrs[0], FindCourseFileWrapper("Map2D/global.NCGR"));
            LocateNcgr(&ncgrs[1], FindCourseFileWrapper("Map2D/global2.NCGR"));
        }
        LocateNcgr(&ncgrs[2], FindCourseFileWrapper("Map2D/local.NCGR"));
    }

    if (func_02047250()) {
        if (v1) {
            LoadNscrData(&nscrs[0], FindCourseFileWrapper("Map2D/global1.NSCR"));
            LoadNscrData(&nscrs[1], FindCourseFileWrapper("Map2D/global2.NSCR"));
        }
        LoadNscrData(&nscrs[2], FindCourseFileWrapper("Map2D/local2.NSCR"));
        if (func_020b64e8()) {
            LoadNscrData(&nscrs[3], FindCourseFileWrapper("Map2D/local3.NSCR"));
        }
    } else {
        if (v1) {
            LocateNscr(&nscrs[0], FindCourseFileWrapper("Map2D/global1.NSCR"));
            LocateNscr(&nscrs[1], FindCourseFileWrapper("Map2D/global2.NSCR"));
        }
        LocateNscr(&nscrs[2], FindCourseFileWrapper("Map2D/local2.NSCR"));
        if (func_020b64e8()) {
            LocateNscr(&nscrs[3], FindCourseFileWrapper("Map2D/local3.NSCR"));
        }
    }

    if (v1) {
        if (gRaceSetup->mMirrorMode != 0) {
            InitMap2D_inline(nscrs[0]->mData);
        }
        k = 0;
        if (gRaceSetup->mMode == MODE_BATTLE && gRaceSetup->mBattleKind == BATTLE_KIND_SHINE) {
            k = 1;
        }
        for (i = 0; i < 16; i++) {
            nclrs[0]->mData[i + 16] = nclrs[1]->mData[(k + 1) * 16 + i];
        }
        for (i = 0; i < 0x400; i++) {
            s32 r = nscrs[1]->mData[i];
            r %= 0x400;
            nscrs[1]->mData[i] = (u16) (nscrs[1]->mData[i] & 0xfc00) | (r + ((k + 6) << 5));
        }
        DC_StoreAll();
        GXS_SetGraphicsMode(5);
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1c00;
        GXS_SetGraphicsMode(0);
        reg_G2S_DB_BG2OFS = 0;
        reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~3) | 2;
        reg_G2S_DB_BG2CNT = reg_G2S_DB_BG2CNT & ~0x40;
        reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & 0x43) | 0x208;
        reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~3) | 3;
        reg_G2S_DB_BG3CNT = reg_G2S_DB_BG3CNT & ~0x40;
        reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x308;
        GXS_LoadBGPltt(nclrs[0]->mData, 0, nclrs[0]->mDataSize);
        GXS_LoadBG2Char(ncgrs[0]->mData, 0, ncgrs[0]->mDataSize);
        GXS_LoadBG2Char(ncgrs[1]->mData, 0x1800, ncgrs[1]->mDataSize);
        GXS_LoadBG2Scr(nscrs[0]->mData, 0, nscrs[0]->mDataSize);
        GXS_LoadBG3Scr(nscrs[1]->mData, 0, nscrs[1]->mDataSize);
    }

    func_020b18b0();
    GXS_LoadBGPltt(nclrs[2]->mData, 0, 0x200);
    GXS_LoadBG3Char(ncgrs[2]->mData, 0, ncgrs[2]->mDataSize);
    GXS_LoadBG2Scr(nscrs[2]->mData, 0, nscrs[2]->mDataSize);
    if (func_020b64e8()) {
        GXS_LoadBG3Scr(nscrs[3]->mData, 0, nscrs[3]->mDataSize);
    }
    GX_SetBankForSubBGExtPltt(0x80);
    GXS_BeginLoadBGExtPltt();
    GXS_LoadBGExtPltt(nclrs[2]->mData, 0x4000, 0x200);
    GXS_LoadBGExtPltt(nclrs[2]->mData, 0x6000, 0x200);
    GXS_EndLoadBGExtPltt();
    for (i = 0; i < 0x100; i++) {
        if (v1) {
            data_0217b34c[i] = nclrs[0]->mData[i];
        }
        (data_0217b34c + i)[0x100] = nclrs[2]->mData[i];
    }
    if (v1) {
        DC_FlushRange(data_0217b34c, 0x200);
    }
    DC_FlushRange(data_0217b34c + 0x100, 0x200);
}

void func_020af99c(void) {
    u32 v;
    u16 w;

    v = gRaceSetup->mRaceKind;
    if (v == RACE_KIND_START_GP) {
        return;
    }
    if (v == RACE_KIND_AWARD || v == RACE_KIND_STAFF_ROLL) {
        return;
    }
    w = gCourseMap->mSettings->mColorAndFogAlpha & 0x7fff;
    *(vu16 *) 0x05000000 = w;
    gRaceHud->mNclrs[0]->mData[0] = w;
    DC_FlushRange(gRaceHud->mNclrs[0]->mData, gRaceHud->mNclrs[0]->mDataSize);
    GX_LoadBGPltt(gRaceHud->mNclrs[0]->mData, 0, gRaceHud->mNclrs[0]->mDataSize);
    GX_LoadBG2Char(gRaceHud->mNcgrs[0]->mData, 0, gRaceHud->mNcgrs[0]->mDataSize);
    GX_LoadBG2Scr(gRaceHud->mNscrs[0]->mData, 0, gRaceHud->mNscrs[0]->mDataSize);
    GX_LoadOBJPltt(GetRaceNclrNcgr(0)->mNclr->mData, 0, GetRaceNclrNcgr(0)->mNclr->mDataSize);
    GX_LoadOBJ(GetRaceNclrNcgr(0)->mNcgr->mData, 0, 0x4000);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0xe000) | 0xe000;
    w = reg_G2_WININ;
    reg_G2_WININ = (u32) ((w & ~0x3f) | 0x1f) | 0x20;
    reg_G2_WIN0H = 0xff;
    reg_G2_WIN0V = 0x60c0;
    reg_G2_WININ = (u32) ((reg_G2_WININ & ~0x3f00) | 0x1f00) | 0x2000;
    reg_G2_WIN1H = 0x40ff;
    reg_G2_WIN1V = 0x60;
    reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~0x3f00) | 0x1200) | 0x2000;
    reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~0x3f) | 0xf) | 0x20;
    reg_GXS_DB_DISPCNT &= ~0xe000;
    GXS_SetGraphicsMode(5);
    GXS_LoadOBJPltt(GetRaceNclrNcgr(6)->mNclr->mData, 0, GetRaceNclrNcgr(6)->mNclr->mDataSize);
    GXS_LoadOBJ(GetRaceNclrNcgr(6)->mNcgr->mData, 0, 0x4000);
    func_020b17a4();
    GXS_LoadBG1Scr(GetRaceGoalSNscr(0)->mData, 0, GetRaceGoalSNscr(0)->mDataSize);
    GXS_LoadBG2Scr(GetRaceGoalSNscr(1)->mData, 0, GetRaceGoalSNscr(1)->mDataSize);
    GXS_LoadBG3Scr(GetRaceGoalSNscr(2)->mData, 0, GetRaceGoalSNscr(2)->mDataSize);
    GXS_LoadBGPltt(data_0217b34c + 0x100, 0, 0x200);
    func_020cfca4();
    GX_SetBankForSubBGExtPltt(0x80);
    GXS_BeginLoadBGExtPltt();
    GXS_LoadBGExtPltt(data_0217b34c + 0x100, 0x4000, 0x200);
    GXS_LoadBGExtPltt(data_0217b34c + 0x100, 0x6000, 0x200);
    GXS_EndLoadBGExtPltt();
    GXS_LoadBGPltt(GetChoisesSBNclr()->mData, 0, 0x200);
    reg_G2S_DB_BG0OFS = 0;
    reg_G2S_DB_BG0CNT = reg_G2S_DB_BG0CNT & ~3;
    reg_G2S_DB_BG0CNT &= ~0x40;
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & 0x43) | 0x10c;
    GXS_LoadBG0Char(func_020b3374()->mData, 0, func_020b3374()->mDataSize);
    GXS_LoadBG0Scr(func_020b32f8(), 0, 0x600);
    func_020b18b0();
    gRaceHud->mEnabled = TRUE;
}

void func_020af86c(void) {
    u32 v;

    v = gRaceSetup->mRaceKind;
    if (v == RACE_KIND_START_GP) {
        ClearRaceStartGpPointer();
        return;
    }
    if (v == RACE_KIND_AWARD) {
        return;
    }
    if (v == RACE_KIND_STAFF_ROLL) {
        func_0212b5d8();
        func_020d1450();
        return;
    }
    G2x_SetBlendAlpha_(&reg_G2_BLDCNT, 0, 0, 0x10, 0x10);
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 0, 0x10, 0x10);
    gRaceHud = NULL;
    func_020b36c8();
    func_020b3af4();
    ClearRaceHudSubScreenProjection();
    func_020b8610();
    if (gRaceSetup->mRaceKind == 4) {
        func_020d129c();
    }
    func_020bb51c();
    ClearRaceLinkLevelPointer();
    func_020ba50c();
    ClearRaceGoalMPointer();
    func_020bc108();
    ClearRaceLapNumberPointer();
    func_020d2094();
    ClearRaceGoalTimesPointer();
    ClearRaceRankListPointer();
    ClearRaceHudSubScreenCellGroups();
    func_020c31ec();
    ClearRaceNewRecordTaPointer();
    ClearRaceTaPositionsPointer();
    reg_GX_DISPCNT &= ~0xe000;
    reg_GXS_DB_DISPCNT &= ~0xe000;
}

void func_020af66c(void) {
    u32 v;

    if (gRaceHud != NULL) {
        gRaceHud->mUnk_908 = 1;
    }
    v = gRaceSetup->mRaceKind;
    if (v == RACE_KIND_START_GP) {
        UpdateRaceStartGp();
        return;
    }
    if (v == RACE_KIND_AWARD) {
        return;
    }
    if (v == RACE_KIND_STAFF_ROLL) {
        UpdateEndingStaffRoll();
        AdvanceStaffRollText();
        return;
    }
    if (gRaceHud->mEnabled == FALSE) {
        return;
    }
    if (gRaceHud->mUnk_8dc != 0) {
        gRaceHud->mUnk_8e0++;
        if (gRaceHud->mUnk_8e0 >= 0x80) {
            gRaceHud->mUnk_8dc = 0;
            gRaceHud->mUnk_8e0 = -1;
        }
    }
    UpdateRaceStartSequence();
    func_020b3728();
    if (gRaceSetup->mRaceKind == 4) {
        func_020d1298();
    }
    v = gRaceSetup->mMode;
    if ((v == MODE_BATTLE        ? gRaceProgress->mRaceDone
         : v == MODE_MISSION_RUN ? IsFramesSinceFinishPastWait()
                                 : (IsKartEnded(GetFollowedKartOrEntryIndex()) != 0 && gRaceHud->mUnk_8dc == 0)) == 0) {
        func_020bab54();
        UpdateRaceLapNumber();
        func_020d2090();
        UpdateRaceGoalTimes();
        func_020ba3ec();
        UpdateRaceGoalM();
    } else {
        func_020bb5cc();
        UpdateRaceLapNumber();
        UpdateRaceGoalTimes();
        UpdateRaceGoalM();
    }
    func_020bbbb4();
    UpdateRaceRankList();
    switch (gRaceHud->mSubScreenState) {
        case 0:
        case 1:
        case 2:
        case 3:
            UpdateRaceHudSubScreenCellGroups();
            UpdateRaceTaPositions();
            break;
        case 4:
        case 5:
            func_020c31c0();
            break;
        case 6:
            break;
    }
    UpdateRaceNewRecordTa();
    gRaceHud->mUpdateFrames++;
    if (gRaceHud->mUpdateFrames >= 0xc00) {
        gRaceHud->mUpdateFrames = 0;
    }
}
