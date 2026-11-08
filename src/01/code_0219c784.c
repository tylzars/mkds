#include "01/code_0219c784.h"

#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02037000.h"
#include "01/unk_021a9000.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_0211732c.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02128210.h"
#include "01/code_0219c000.h"
#include "code_0201ea58.h"
#include "code_0214a390.h"
#include "registers.h"

const u8 data_ov001_021a6bc4[] = {0};
const u8 data_ov001_021a6bc8[] = {0, 1};
const u8 gSelectBattleStageMNscrCopyDestination[] = {9, 7};
const u8 data_ov001_021a6bd0[] = {1, 2, 3};
const u8 data_ov001_021a6bd4[] = {4, 5, 6};
const u8 gSelectBattleStageBnblRectIndices[6] = {0, 1, 2, 3, 4, 5};
const s8 gSelectBattleStageOffsets[] = {0, -2, -3, -4, -3, -2};
const u8 gSelectBattleStageMNscrIndices[] = {0, 0, 1, 1, 2, 2};
const u8 gSelectBattleStageSTableIndices[6][3] = {{0, 12, 6}, {1, 13, 7},  {2, 14, 8},
                                                  {3, 15, 9}, {4, 16, 10}, {5, 17, 11}};
const SelectBattleStageNscrRect gSelectBattleStageNscrRects[] = {
    {2, 15, 7, 16}, {16, 29, 7, 16}, {2, 15, 7, 16}, {16, 29, 7, 16}, {2, 15, 7, 16}, {16, 29, 7, 16},
};
SelectBattleStage *gSelectBattleStage;

void InitSelectBattleStage(void *c, s32 d, void *e, void *f) {
    s32 i, j;
    void *heap;
    void *p;

    heap = CreateExpHeapFromMaxFree(c);
    gSelectBattleStage = HeapAlloc(heap, 0x1088);
    gSelectBattleStage->mHeap = heap;
    gSelectBattleStage->mState = 0;
    gSelectBattleStage->mNextState = 0;
    gSelectBattleStage->mIndex = 0;
    gSelectBattleStage->mStateFrames = 0;
    gSelectBattleStage->mOffsetTimer = 0;
    gSelectBattleStage->mOffset = 0;
    gSelectBattleStage->mUnk_20 = TRUE;
    gSelectBattleStage->mResult = -4;
    gSelectBattleStage->mMenuMessages = FindSceneFile("menu.bmg");
    gSelectBattleStage->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    LocateAndQueueSelectBattleStage();
    CopyAndQueueSelectBattleStageNscrRect();
    for (i = 0; i < 6; i++) {
        func_02124a98(gSelectBattleStageSTableIndices[i][0], 1, gSelectBattleStage->mSelectBattleStageSNcer,
                      gSelectBattleStage->mSelectBattleStageBncls[1]);
    }
    gSelectBattleStage->mUnk_1078 = e;
    gSelectBattleStage->mUnk_107c = f;
    func_020ae6d4(e, f);
    for (i = 0; i < 2; i++) {
        InitLayoutTable(gSelectBattleStage->mHeap, gSelectBattleStage->mSelectBattleStageBncls[i],
                        gSelectBattleStage->mSelectBattleStageBnlls[i],
                        &gSelectBattleStage->mSelectBattleStageTables[i]);
    }
    gSelectBattleStage->mSelectBattleStageTables[0][0].mOffsetY = -0xa0;
    gSelectBattleStage->mUnk_14 = 0xa0;
    func_ov001_0219cec4();
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 3; j++) {
            gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[i][j]].mOffsetX = 0xdc;
        }
    }
    {
        u8 a[2] = {0, 1};
        u8 b[2] = {5, 6};
        s32 rem = 0x8000;

        p = GetBmgEntry(gSelectBattleStage->mMenuMessages, 6);
        if (d == 0) {
            p = GetBmgEntry(gSelectBattleStage->mMenuMessages, 7);
        }
        for (i = 0; i < 2; i++) {
            rem -= InitLabelCanvas(gSelectBattleStage->mHeap, a[i], gSelectBattleStage->mSelectBattleStageBnlls[0],
                                   0xa8, 13, b[i], gSelectBattleStage->mSelectBattleStageMNcer,
                                   gSelectBattleStage->mSelectBattleStageBncls[0],
                                   gSelectBattleStage->mSelectBattleStageTables[0], rem);
            func_0212426c(0, a[i], gSelectBattleStage->mSelectBattleStageBnlls[0], p,
                          gSelectBattleStage->mSelectBattleStageBncls[0],
                          gSelectBattleStage->mSelectBattleStageTables[0]);
        }
        if (d == 1) {
            gSelectBattleStage->mSelectBattleStageTables[0][5].mVisible = 0;
        } else {
            gSelectBattleStage->mSelectBattleStageTables[0][6].mVisible = 0;
        }
    }
    reg_G2_BG2CNT = (reg_G2_BG2CNT & 0x43) | 0x9e10;
    SetSelectReturnSoundId(14);
}

void ReleaseSelectBattleStage(void) {
    reg_G2_BG2CNT = (reg_G2_BG2CNT & 0x43) | 0x1e10;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | 0x1800;
    HeapDestroy(gSelectBattleStage->mHeap);
    gSelectBattleStage = NULL;
}

void LocateAndQueueSelectBattleStage(void) {
    volatile u16 z;
    Ncgr *ncgrMB;
    Nclr *nclrMB;
    Nclr *nclrMO;
    Nclr *nclrSO;

    LocateNcgr(&ncgrMB, FindSceneFile("mg/select_battle_stage_m_b.ncgr"));
    LocateNscr(&gSelectBattleStage->mSelectBattleStageMNscrs[0], FindSceneFile("mg/select_battle_stage_m_00.nscr"));
    LocateNscr(&gSelectBattleStage->mSelectBattleStageMNscrs[1], FindSceneFile("mg/select_battle_stage_m_01.nscr"));
    LocateNscr(&gSelectBattleStage->mSelectBattleStageMNscrs[2], FindSceneFile("mg/select_battle_stage_m_02.nscr"));
    LocateNclr(&nclrMB, FindSceneFile("mg/select_battle_stage_m_b.nclr"));
    gSelectBattleStage->mSelectBattleStageBncls[0] = FindSceneFile("mg/select_battle_stage_m.bncl");
    gSelectBattleStage->mSelectBattleStageBnbls[0] = NULL;
    gSelectBattleStage->mSelectBattleStageBnlls[0] = FindSceneFile("mg/select_battle_stage_m.bnll");
    gSelectBattleStage->mSelectBattleStageBncls[1] = FindSceneFile("mg/select_battle_stage_s.bncl");
    gSelectBattleStage->mSelectBattleStageBnbls[1] = FindSceneFile("mg/select_battle_stage_s.bnbl");
    gSelectBattleStage->mSelectBattleStageBnlls[1] = NULL;
    LocateNcgr2(&gSelectBattleStage->mSelectBattleStageMNcgr, FindSceneFile("mg/select_battle_stage_m.nce.ncgr"));
    LocateNcer(&gSelectBattleStage->mSelectBattleStageMNcer, FindSceneFile("mg/select_battle_stage_m.nce.ncer"));
    LocateNclr(&nclrMO, FindSceneFile("mg/select_battle_stage_m_o.nclr"));
    LocateNcgr2(&gSelectBattleStage->mSelectBattleStageSNcgr, FindSceneFile("mg/select_battle_stage_s.nce.ncgr"));
    LocateNcer(&gSelectBattleStage->mSelectBattleStageSNcer, FindSceneFile("mg/select_battle_stage_s.nce.ncer"));
    LocateNclr(&nclrSO, FindSceneFile("mg/select_battle_stage_s_o.nclr"));
    z = 0;
    MIi_CpuClear16(z, gSelectBattleStage->mSelectBattleStageMNscrCopy, 0x1000);
    CallQueueAppend(6, 0, ncgrMB->mData, ncgrMB->mDataSize);
    CallQueueAppend(10, 0, gSelectBattleStage->mSelectBattleStageMNscrCopy, 0x1000);
    CallQueueAppend(15, 0, nclrMB->mData, 0x180);
    CallQueueAppend(19, 0, gSelectBattleStage->mSelectBattleStageMNcgr->mData,
                    gSelectBattleStage->mSelectBattleStageMNcgr->mDataSize);
    CallQueueAppend(14, 0, nclrMO->mData, 0x1a0);
    CallQueueAppend(14, 0x1c0, nclrMO->mData + 0xe0, 0x40);
    CallQueueAppend(35, 0, gSelectBattleStage->mSelectBattleStageSNcgr->mData,
                    gSelectBattleStage->mSelectBattleStageSNcgr->mDataSize);
    CallQueueAppend(30, 0, nclrSO->mData, nclrSO->mDataSize);
}

void CopyAndQueueSelectBattleStageNscrRect(void) {
    s32 x, y;
    s32 idx = gSelectBattleStage->mIndex;
    u8 src = gSelectBattleStageMNscrIndices[idx];

    for (y = 0; y <= gSelectBattleStageNscrRects[gSelectBattleStage->mIndex].mLastRow -
                         gSelectBattleStageNscrRects[gSelectBattleStage->mIndex].mFirstRow;
         y++) {
        for (x = 0; x <= gSelectBattleStageNscrRects[gSelectBattleStage->mIndex].mLastColumn -
                             gSelectBattleStageNscrRects[gSelectBattleStage->mIndex].mFirstColumn;
             x++) {
            (gSelectBattleStage->mSelectBattleStageMNscrCopy[gSelectBattleStageMNscrCopyDestination[1] + y] +
             gSelectBattleStageMNscrCopyDestination[0])[x] =
                *((u16 *) gSelectBattleStage->mSelectBattleStageMNscrs[src]->mData + x +
                  gSelectBattleStageNscrRects[gSelectBattleStage->mIndex].mFirstColumn +
                  (gSelectBattleStageNscrRects[gSelectBattleStage->mIndex].mFirstRow + y) * 32);
        }
    }
    CallQueueAppend(10, 0, gSelectBattleStage->mSelectBattleStageMNscrCopy, 0x600);
}

void func_ov001_0219cec4(void) {
    s32 i;
    u16 x = gSelectBattleStage->mSelectBattleStageBncls[0]->mUnk_06;

    for (i = 0; i < 1; i++) {
        gSelectBattleStage->mSelectBattleStageTables[0][data_ov001_021a6bc4[i]].mOffsetY = -gSelectBattleStage->mUnk_14;
    }
    for (i = 0; i < 3; i++) {
        gSelectBattleStage->mSelectBattleStageTables[0][data_ov001_021a6bd0[i]].mOffsetY =
            gSelectBattleStage->mOffset - gSelectBattleStage->mUnk_14;
    }
    for (i = 0; i < 3; i++) {
        gSelectBattleStage->mSelectBattleStageTables[0][data_ov001_021a6bd4[i]].mOffsetX = gSelectBattleStage->mUnk_18;
    }
    for (i = 0; i < 2; i++) {
        (gSelectBattleStage->mSelectBattleStageTables[0] + x)[data_ov001_021a6bc8[i]].mOffsetX =
            gSelectBattleStage->mUnk_18;
    }
}

void AdvanceSelectBattleStageState0(void) {
    s32 i, j;

    gSelectBattleStage->mStateFrames++;
    if (gSelectBattleStage->mStateFrames > 20) {
        gSelectBattleStage->mNextState = 1;
        gSelectBattleStage->mStateFrames = 0;
        gSelectBattleStage->mNextState = 1;
        RequestSelectReturnState1();
    } else if (gSelectBattleStage->mStateFrames > 10) {
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 3; j++) {
                gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[i][j]].mOffsetX =
                    func_020ae488(gSelectBattleStage->mStateFrames - 10);
            }
        }
    } else {
        gSelectBattleStage->mUnk_14 = InterpolateS16(1, 0xa0, 0, gSelectBattleStage->mStateFrames, 10);
        gSelectBattleStage->mUnk_18 = InterpolateS16(1, -0x100, 0, gSelectBattleStage->mStateFrames, 10);
        for (i = 0; i < 6; i++) {
            for (j = 0; j < 3; j++) {
                gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[i][j]].mOffsetX =
                    InterpolateS16(1, 0xdc, 0, gSelectBattleStage->mStateFrames, 10);
            }
        }
    }
}

void AdvanceSelectBattleStageState1(void) {
    int v1;
    v1 = IsSelectReturnState2NoState3Or4Request();
    if (v1 != 0) {
        gSelectBattleStage->mNextState = 2;
    }
}

void AdvanceSelectBattleStageState2(void) {
    Unk02175628Index idx = UNK_02175628_INDEX_8;
    s32 res = -1;
    s32 sel = -4;
    BOOL b = FALSE;
    BOOL a;
    s32 i;
    s32 prev;
    u16 x;

    a = FALSE;
    x = data_02175628[idx].mHasPair;
    if (x == 0 && data_02175628[idx].mNoPairCount < 5) {
        a = TRUE;
    }
    if (a == FALSE && data_02175628[idx].mPrevHasPair == 0 && x != 0) {
        b = TRUE;
    }
    if (b != FALSE) {
        res = RectTableFindContaining(gSelectBattleStage->mSelectBattleStageBnbls[1], data_02175628[idx].mPairX,
                                      data_02175628[idx].mPairY);
    }
    for (i = 0; i < 6; i++) {
        if (res == gSelectBattleStageBnblRectIndices[i]) {
            sel = i;
        }
    }
    if ((u16) (data_02175628[idx].mUnk_00 & PAD_KEY_B) == 0) {
        b = FALSE;
        a = FALSE;
        x = data_02175628[idx].mHasPair;
        if (x == 0 && data_02175628[idx].mNoPairCount < 5) {
            a = TRUE;
        }
        if (a == FALSE && data_02175628[idx].mPrevHasPair == 0 && x != 0) {
            b = TRUE;
        }
        if (b == FALSE || IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175628[idx].mPairX,
                                                                          data_02175628[idx].mPairY) == FALSE) {
            goto next;
        }
    }
    if (data_0217b488->mUnk_08 == 2) {
        gSelectBattleStage->mNextState = 4;
        RequestSelectReturnState3WithSound(0);
        gSelectBattleStage->mUnk_2c = FALSE;
        return;
    }
    gSelectBattleStage->mNextState = 6;
    gSelectBattleStage->mPendingResult = -3;
    if (data_021759d0->mUnk_20 == 0) {
        RequestSelectReturnState3WithSound(0);
        gSelectBattleStage->mUnk_2c = FALSE;
        return;
    }
    RequestSelectReturnState3WithSound(1);
    gSelectBattleStage->mUnk_2c = TRUE;
    return;
next:
    if ((u16) (data_02175628[idx].mUnk_00 & PAD_KEY_A) != 0 || sel != -4) {
        prev = gSelectBattleStage->mIndex;
        if ((u16) (data_02175628[idx].mUnk_00 & PAD_KEY_A) == 0) {
            gSelectBattleStage->mIndex = sel;
        }
        if (gSelectBattleStage->mIndex == prev) {
            gSelectBattleStage->mUnk_20 = FALSE;
        }
        gSelectBattleStage->mPendingResult = gSelectBattleStage->mIndex;
        gSelectBattleStage->mNextState = 3;
        gSelectBattleStage->mOffsetTimer = 6;
        StartSoundOncePerFrame(5);
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
        gSelectBattleStage->mIndex--;
        if (gSelectBattleStage->mIndex < 0) {
            gSelectBattleStage->mIndex = 5;
        }
        gSelectBattleStage->mOffsetTimer = 6;
        StartSoundOncePerFrame(0);
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
        gSelectBattleStage->mIndex++;
        if (gSelectBattleStage->mIndex >= 6) {
            gSelectBattleStage->mIndex = 0;
        }
        gSelectBattleStage->mOffsetTimer = 6;
        StartSoundOncePerFrame(0);
    }
}

void AdvanceSelectBattleStageState3(void) {
    s32 i;
    s16 v;

    gSelectBattleStage->mStateFrames++;
    v = func_020ae488(gSelectBattleStage->mStateFrames);
    for (i = 0; i < 3; i++) {
        gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[gSelectBattleStage->mIndex][i]]
            .mOffsetX = v;
    }
    if (gSelectBattleStage->mStateFrames >= 10) {
        gSelectBattleStage->mNextState = 5;
        gSelectBattleStage->mStateFrames = 0;
        StartSelectChoises(GetBmgEntry(gSelectBattleStage->mCommonMessages, 4),
                           GetBmgEntry(gSelectBattleStage->mCommonMessages, 2), 0);
        SetSelectChoisesSoundId(0, 7);
        SetSelectChoisesSoundId(1, 0x10);
    } else if (gSelectBattleStage->mStateFrames >= 5) {
        gSelectBattleStage->mUnk_20 = TRUE;
    }
}

void AdvanceSelectBattleStageState4(void) {
    if (IsSelectReturnState2NoState3Or4Request() != 0) {
        gSelectBattleStage->mPendingResult = -2;
        StartSelectChoises(GetBmgEntry(gSelectBattleStage->mMenuMessages, 0x14),
                           GetBmgEntry(gSelectBattleStage->mMenuMessages, 0x15), 0);
        SetSelectChoisesSoundId(0, 5);
        SetSelectChoisesSoundId(1, 0xc);
        gSelectBattleStage->mNextState = 5;
    }
}

void AdvanceSelectBattleStageState5(void) {
    if (GetSelectChoisesDone() != 0) {
        if (gSelectBattleStage->mPendingResult == -2 || gSelectBattleStage->mPendingResult == -1) {
            if (GetSelectChoisesIndex() == 1) {
                gSelectBattleStage->mNextState = 6;
            } else {
                gSelectBattleStage->mNextState = 2;
            }
        } else {
            if (GetSelectChoisesIndex() == 0) {
                gSelectBattleStage->mNextState = 6;
                RequestSelectReturnState4();
                gSelectBattleStage->mUnk_2c = TRUE;
            } else {
                gSelectBattleStage->mNextState = 2;
            }
        }
        RequestSelectChoisesState0();
    }
}

void AdvanceSelectBattleStageState6(void) {
    s32 i;
    s32 j;

    gSelectBattleStage->mStateFrames++;
    if (gSelectBattleStage->mStateFrames > 10) {
        if ((gSelectBattleStage->mUnk_2c != FALSE && IsSelectReturnState0NoState1Request() != 0) ||
            (gSelectBattleStage->mUnk_2c == FALSE && IsSelectReturnState2NoState3Or4Request() != 0)) {
            gSelectBattleStage->mResult = gSelectBattleStage->mPendingResult;
            return;
        }
    }
    if (gSelectBattleStage->mStateFrames > 10) {
        gSelectBattleStage->mStateFrames = 10;
    }
    gSelectBattleStage->mUnk_14 = InterpolateS16(1, 0, 0xa0, gSelectBattleStage->mStateFrames, 10);
    gSelectBattleStage->mUnk_18 = InterpolateS16(1, 0, -0x100, gSelectBattleStage->mStateFrames, 10);
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 3; j++) {
            gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[i][j]].mOffsetX =
                InterpolateS16(1, 0, 0xdc, gSelectBattleStage->mStateFrames, 10);
        }
    }
}

void func_ov001_0219c8ec(void) {
    s32 i;
    BOOL zero = FALSE;

    for (i = 0; i < 6; i++) {
        if (i == gSelectBattleStage->mIndex && gSelectBattleStage->mUnk_20 != FALSE) {
            gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[i][1]].mVisible = 1;
            gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[i][2]].mVisible = 0;
        } else {
            gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[i][1]].mVisible = zero;
            gSelectBattleStage->mSelectBattleStageTables[1][gSelectBattleStageSTableIndices[i][2]].mVisible = 1;
        }
    }
}

void AdvanceSelectBattleStageOffsetTimer(void) {
    if (gSelectBattleStage->mOffsetTimer > 0) {
        gSelectBattleStage->mOffsetTimer--;
    }
    gSelectBattleStage->mOffset = gSelectBattleStageOffsets[gSelectBattleStage->mOffsetTimer];
}

s32 AdvanceSelectBattleStage(void) {
    s32 i;

    gSelectBattleStage->mState = gSelectBattleStage->mNextState;
    switch (gSelectBattleStage->mState) {
        case 0:
            AdvanceSelectBattleStageState0();
            break;
        case 1:
            AdvanceSelectBattleStageState1();
            break;
        case 2:
            AdvanceSelectBattleStageState2();
            break;
        case 3:
            AdvanceSelectBattleStageState3();
            break;
        case 4:
            AdvanceSelectBattleStageState4();
            break;
        case 5:
            AdvanceSelectBattleStageState5();
            break;
        case 6:
            AdvanceSelectBattleStageState6();
            break;
    }
    AdvanceSelectBattleStageOffsetTimer();
    func_ov001_0219c8ec();
    func_ov001_0219cec4();
    CopyAndQueueSelectBattleStageNscrRect();
    for (i = 0; i < 2; i++) {
        DrawLayoutTable(gSelectBattleStage->mSelectBattleStageBncls[i],
                        (&gSelectBattleStage->mSelectBattleStageMNcer)[i],
                        gSelectBattleStage->mSelectBattleStageBnlls[i], (&gSelectBattleStage->mUnk_1078)[i],
                        gSelectBattleStage->mSelectBattleStageTables[i]);
    }
    return gSelectBattleStage->mResult;
}

void WriteSelectBattleStageRegisters(void) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1c00;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | 0x1600;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~3) | 1;
    reg_G2_BLDCNT = 0;
    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 2, 6, 10);
    reg_G2_BG2OFS = ((gSelectBattleStage->mUnk_14 - gSelectBattleStage->mOffset) << 16) & 0x1ff0000;
}
