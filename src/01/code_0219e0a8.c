#include "01/code_0219e0a8.h"
#include "registers.h"
#include "01/code_0219e000.h"
#include "01/code_0219f000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021ca000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/unk_021759c0.h"

EndingScene *gEndingScene;

void CreateEndingScene(void *heap) {
    void *result;

    gEndingScene = HeapAlloc(heap, 0x470);
    gEndingScene->mHeap = heap;
    gEndingScene->mUnk_01c = func_021250b0(heap);
    gEndingScene->mNextScene = -1;
    gEndingScene->mState = 0;
    gEndingScene->mNextState = gEndingScene->mState;
    gEndingScene->mUnk_008 = 0;
    if (gRaceSetup->mCourseId == COURSE_ID_STAFFROLLTRUE) {
        gEndingScene->mKind = 1;
    } else {
        gEndingScene->mKind = 0;
    }
    gEndingScene->mIndex1Queued = FALSE;
    gEndingScene->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    func_ov001_0219e660();
    LoadAndQueueEndingSceneData();
    ResetOamLists(gEndingScene->mMainOam, NULL);
    InitLayoutTable(gEndingScene->mHeap, gEndingScene->mEndingThanksBncl, gEndingScene->mEndingThanksBnll,
                    &gEndingScene->mEndingThanksTable);
    result = NULL;
    gEndingScene->mEndingThanksTable->mVisible = 0;
    {
        u16 table[2][2] = {{200, 24}, {200, 24}};

        switch (gEndingScene->mKind) {
            case 0:
                result = GetBmgEntry(gEndingScene->mCommonMessages, 0x77);
                break;
            case 1:
                result = GetBmgEntry(gEndingScene->mCommonMessages, 0x78);
                break;
        }
        InitLabelCanvas(gEndingScene->mHeap, 0, gEndingScene->mEndingThanksBnll, table[gEndingScene->mKind][0],
                        table[gEndingScene->mKind][1], 0, gEndingScene->mThanksYouMNcer,
                        gEndingScene->mEndingThanksBncl, gEndingScene->mEndingThanksTable, 0x8000);
        func_0212426c(0, 0, gEndingScene->mEndingThanksBnll, result, gEndingScene->mEndingThanksBncl,
                      gEndingScene->mEndingThanksTable);
    }
}

void func_ov001_0219e6e0(void) {
    *&gEndingScene = 0;
}

void func_ov001_0219e660(void) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x100;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | 0x100;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 3;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0x1f00;
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & 0x43) | 0x1000;
    reg_G2_BG2OFS = 0;
    reg_G2S_DB_BG0OFS = 0;
    *(vu16 *) 0x5000000 = 0;
    *(vu16 *) 0x5000400 = 0;
}

void QueueEndingSceneNcgrNscrNclr(int i) {
    CallQueueAppend(4, 0, gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNcgrs[i]->mData,
                    gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNcgrs[i]->mDataSize);
    CallQueueAppend(8, 0, gEndingScene->mLogoEndMarioKartMBgAndThanksYouMBgNscrs[i]->mData,
                    gEndingScene->mLogoEndMarioKartMBgAndThanksYouMBgNscrs[i]->mDataSize);
    CallQueueAppend(0xf, 0, gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNclrs[i]->mData,
                    gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNclrs[i]->mDataSize);
    CallQueueAppend(0x14, 0, gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNcgrs[i]->mData,
                    gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNcgrs[i]->mDataSize);
    CallQueueAppend(0x18, 0, gEndingScene->mEndAllRightsReservedSBgAndLogoEndNintendoSBgNscrs[i]->mData,
                    gEndingScene->mEndAllRightsReservedSBgAndLogoEndNintendoSBgNscrs[i]->mDataSize);
    CallQueueAppend(0x1f, 0, gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNclrs[i]->mData,
                    gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNclrs[i]->mDataSize);
}

void func_ov001_0219e5a0(void) {
    reg_G2_BG0CNT = reg_G2_BG0CNT & 0x43 | 0x00001f80u;
    QueueEndingSceneNcgrNscrNclr(1);
    gEndingScene->mIndex1Queued = TRUE;
}

void LoadAndQueueEndingSceneData(void) {
#ifdef version_EUR
    LoadNcgrData(&gEndingScene->mUnk_038[0], FindSceneFile("logo_end_marioKart_m_b_02.ncgr"));
    LoadNscrData(&gEndingScene->mUnk_040[0], FindSceneFile("logo_end_marioKart_m_bg_02.nscr"));
#else
    LoadNcgrData(&gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNcgrs[0],
                 FindSceneFile("logo_end_marioKart_m_b_01.ncgr"));
    LoadNscrData(&gEndingScene->mLogoEndMarioKartMBgAndThanksYouMBgNscrs[0],
                 FindSceneFile("logo_end_marioKart_m_bg_01.nscr"));
#endif
    LoadNclrData(&gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNclrs[0],
                 FindSceneFile("logo_end_marioKart_m_b.nclr"));
    switch (gEndingScene->mKind) {
        case 0:
            LoadNcgrData(&gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNcgrs[1],
                         FindSceneFile("thanksYou_m_b_00.ncgr"));
            LoadNscrData(&gEndingScene->mLogoEndMarioKartMBgAndThanksYouMBgNscrs[1],
                         FindSceneFile("thanksYou_m_bg_00.nscr"));
            LoadNclrData(&gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNclrs[1],
                         FindSceneFile("thanksYou_m_b_00.nclr"));
            break;
        case 1:
            LoadNcgrData(&gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNcgrs[1],
                         FindSceneFile("thanksYou_m_b_01_2.ncgr"));
            LoadNscrData(&gEndingScene->mLogoEndMarioKartMBgAndThanksYouMBgNscrs[1],
                         FindSceneFile("thanksYou_m_bg_01_2.nscr"));
            LoadNclrData(&gEndingScene->mLogoEndMarioKartMBAndThanksYouMBNclrs[1],
                         FindSceneFile("thanksYou_m_b_01.nclr"));
            break;
    }
    LoadNcgrData(&gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNcgrs[0],
                 FindSceneFile("end_allRightsReserved_s_b.ncgr"));
    LoadNscrData(&gEndingScene->mEndAllRightsReservedSBgAndLogoEndNintendoSBgNscrs[0],
                 FindSceneFile("end_allRightsReserved_s_bg.nscr"));
    LoadNclrData(&gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNclrs[0],
                 FindSceneFile("end_allRightsReserved_s_b.nclr"));
    LoadNcgrData(&gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNcgrs[1],
                 FindSceneFile("logo_end_Nintendo_s_b.ncgr"));
    LoadNscrData(&gEndingScene->mEndAllRightsReservedSBgAndLogoEndNintendoSBgNscrs[1],
                 FindSceneFile("logo_end_Nintendo_s_bg.nscr"));
    LoadNclrData(&gEndingScene->mEndAllRightsReservedSBAndLogoEndNintendoSBNclrs[1],
                 FindSceneFile("logo_end_Nintendo_s_b.nclr"));
    LoadNcerData(&gEndingScene->mThanksYouMNcer, FindSceneFile("thanksYou_m.nce.ncer"));
    LoadNclrData(&gEndingScene->mThanksYouMO00Nclr, FindSceneFile("thanksYou_m_o_00.nclr"));
    switch (gEndingScene->mKind) {
        case 0:
            gEndingScene->mEndingThanksBncl = FindSceneFile("ending_thanks_00.bncl");
            gEndingScene->mEndingThanksBnll = FindSceneFile("ending_thanks_00.bnll");
            break;
        case 1:
            gEndingScene->mEndingThanksBncl = FindSceneFile("ending_thanks_01.bncl");
            gEndingScene->mEndingThanksBnll = FindSceneFile("ending_thanks_01.bnll");
            break;
    }
    if (data_0217b488->mUnk_70 != 0) {
        func_ov001_0219e5a0();
    } else {
        QueueEndingSceneNcgrNscrNclr(0);
    }
    CallQueueAppend(0xe, 0, gEndingScene->mThanksYouMO00Nclr->mData, gEndingScene->mThanksYouMO00Nclr->mDataSize);
}

void AdvanceEndingSceneState0(void) {
    if (AreBrightnessFadesClear() != 0) {
        if (data_0217b488->mUnk_70 != 0) {
            gEndingScene->mNextState = 5;
            data_0217b488->mUnk_70 = 0;
            return;
        }
        gEndingScene->mNextState = 1;
    }
}

void AdvanceEndingSceneState1(void) {
    gEndingScene->mUnk_008++;
    if (gEndingScene->mUnk_008 > gEndingSceneStateTable[gEndingScene->mState]) {
        gEndingScene->mNextState = 2;
        gEndingScene->mUnk_008 = 0;
        StartFadeToFadedNegative(gEndingSceneStateTable[2]);
    }
}

void AdvanceEndingSceneState2(void) {
    int v1;
    v1 = AreBrightnessFadesFaded();
    if (v1 != 0) {
        gEndingScene->mNextState = 3;
    }
}

void AdvanceEndingSceneState3(void) {
    EndingScene *p;

    gEndingScene->mUnk_008++;
    p = gEndingScene;
    if (p->mUnk_008 > gEndingSceneStateTable[3]) {
        p->mNextState = 4;
        gEndingScene->mUnk_008 = 0;
        StartFadeToClearNegative(gEndingSceneStateTable[4]);
        func_ov001_0219e5a0();
    }
}

void AdvanceEndingSceneState4(void) {
    int v1;
    v1 = AreBrightnessFadesClear();
    if (v1 != 0) {
        gEndingScene->mNextState = 5;
    }
}

void AdvanceEndingSceneState5(void) {
    InputSlotIndex idx = UNK_02175628_INDEX_8;
    u16 flags;
    BOOL a;
    BOOL b;
    u16 x;

    gEndingScene->mUnk_008++;
    if (gEndingScene->mUnk_008 > gEndingSceneStateTable[gEndingScene->mState]) {
        gEndingScene->mUnk_008 = gEndingSceneStateTable[gEndingScene->mState];
        flags = data_02175628[idx].mPressedBits & 0xc0f;
        if (flags == 0) {
            a = FALSE;
            b = FALSE;
            x = data_02175628[idx].mHasPair;
            if (x == 0 && data_02175628[idx].mNoPairCount < 5) {
                b = TRUE;
            }
            if (b == FALSE && data_02175628[idx].mPrevHasPair == 0 && x != 0) {
                a = TRUE;
            }
            if (a == FALSE) {
                return;
            }
        }
        gEndingScene->mNextState = 6;
        gEndingScene->mUnk_008 = 0;
        StartFadeToFadedNegative(gEndingSceneStateTable[6]);
    }
}

void AdvanceEndingSceneState6(void) {
    if (AreBrightnessFadesFaded() != 0) {
        gEndingScene->mNextState = 7;
        gEndingScene->mUnk_008 = 0;
    }
}

void AdvanceEndingSceneState7(void) {
    gEndingScene->mUnk_008++;
    if (gEndingScene->mUnk_008 > gEndingSceneStateTable[7]) {
        gEndingScene->mNextScene = 0;
    }
}

void AdvanceEndingScene(void) {
    gEndingScene->mState = gEndingScene->mNextState;
    ClearOamListCounts(gEndingScene->mMainOam, NULL);
    switch (gEndingScene->mState) {
        case 0:
            AdvanceEndingSceneState0();
            break;
        case 1:
            AdvanceEndingSceneState1();
            break;
        case 2:
            AdvanceEndingSceneState2();
            break;
        case 3:
            AdvanceEndingSceneState3();
            break;
        case 4:
            AdvanceEndingSceneState4();
            break;
        case 5:
            AdvanceEndingSceneState5();
            break;
        case 6:
            AdvanceEndingSceneState6();
            break;
        case 7:
            AdvanceEndingSceneState7();
            break;
    }
    DrawLayoutTable(gEndingScene->mEndingThanksBncl, gEndingScene->mThanksYouMNcer, gEndingScene->mEndingThanksBnll,
                    gEndingScene->mMainOam, gEndingScene->mEndingThanksTable);
    func_020ae630(gEndingScene->mMainOam, NULL);
}

void func_ov001_0219e0d4(void) {
    u32 bits;

    if (gEndingScene->mIndex1Queued != FALSE) {
        bits = (reg_GX_DISPCNT & 0x1f00) >> 8;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | ((bits | 0x10) << 8);
    }
    UploadOamLists(gEndingScene->mMainOam, NULL);
}

void func_ov001_0219e0c4(void) {
    data_0217b488->mUnk_70 = 1;
}

s32 func_ov001_0219e0b8(void) {
    return data_0217b488->mUnk_70;
}

int GetEndingSceneNextScene(void) {
    return gEndingScene->mNextScene;
}
