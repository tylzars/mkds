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

void func_ov001_0219e6ec(void *heap) {
    void *result;

    data_ov001_021ca400 = HeapAlloc(heap, 0x470);
    data_ov001_021ca400->mHeap = heap;
    data_ov001_021ca400->mUnk_01c = func_021250b0(heap);
    data_ov001_021ca400->mUnk_014 = -1;
    data_ov001_021ca400->mState = 0;
    data_ov001_021ca400->mNextState = data_ov001_021ca400->mState;
    data_ov001_021ca400->mUnk_008 = 0;
    if (data_021759c0->mCourseId == 0x36) {
        data_ov001_021ca400->mKind = 1;
    } else {
        data_ov001_021ca400->mKind = 0;
    }
    data_ov001_021ca400->mUnk_018 = FALSE;
    data_ov001_021ca400->mCommonMessages = func_02047a28("common.bmg");
    func_ov001_0219e660();
    func_ov001_0219e38c();
    func_020ae6d4(data_ov001_021ca400->mUnk_068, NULL);
    func_02124ed0(data_ov001_021ca400->mHeap, data_ov001_021ca400->mEndingThanksBncl,
                  data_ov001_021ca400->mEndingThanksBnll, &data_ov001_021ca400->mUnk_020);
    result = NULL;
    data_ov001_021ca400->mUnk_020->mUnk_00 = 0;
    {
        u16 table[2][2] = {{200, 24}, {200, 24}};

        switch (data_ov001_021ca400->mKind) {
            case 0:
                result = GetBmgEntry(data_ov001_021ca400->mCommonMessages, 0x77);
                break;
            case 1:
                result = GetBmgEntry(data_ov001_021ca400->mCommonMessages, 0x78);
                break;
        }
        func_021243ac(data_ov001_021ca400->mHeap, 0, data_ov001_021ca400->mEndingThanksBnll,
                      table[data_ov001_021ca400->mKind][0], table[data_ov001_021ca400->mKind][1], 0,
                      data_ov001_021ca400->mThanksYouMNcer, data_ov001_021ca400->mEndingThanksBncl,
                      data_ov001_021ca400->mUnk_020, 0x8000);
        func_0212426c(0, 0, data_ov001_021ca400->mEndingThanksBnll, result, data_ov001_021ca400->mEndingThanksBncl,
                      data_ov001_021ca400->mUnk_020);
    }
}

void func_ov001_0219e6e0(void) {
    *(u32 *) &data_ov001_021ca400 = 0;
    return;
}

void func_ov001_0219e660(void) {
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | 0x100;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | 0x100;
    *(vu16 *) 0x4000008 = (*(vu16 *) 0x4000008 & ~3) | 3;
    *(vu16 *) 0x4000008 = (*(vu16 *) 0x4000008 & 0x43) | 0x1f00;
    *(vu16 *) 0x4001008 = (*(vu16 *) 0x4001008 & 0x43) | 0x1000;
    *(vu32 *) 0x4000018 = 0;
    *(vu32 *) 0x4001010 = 0;
    *(vu16 *) 0x5000000 = 0;
    *(vu16 *) 0x5000400 = 0;
}

void func_ov001_0219e5d4(int i) {
    func_02016468(4, 0, data_ov001_021ca400->mLogoEndMarioKartMBAndThanksYouMBNcgrs[i]->mData,
                  data_ov001_021ca400->mLogoEndMarioKartMBAndThanksYouMBNcgrs[i]->mDataSize);
    func_02016468(8, 0, data_ov001_021ca400->mLogoEndMarioKartMBgAndThanksYouMBgNscrs[i]->mData,
                  data_ov001_021ca400->mLogoEndMarioKartMBgAndThanksYouMBgNscrs[i]->mDataSize);
    func_02016468(0xf, 0, data_ov001_021ca400->mLogoEndMarioKartMBAndThanksYouMBNclrs[i]->mData,
                  data_ov001_021ca400->mLogoEndMarioKartMBAndThanksYouMBNclrs[i]->mDataSize);
    func_02016468(0x14, 0, data_ov001_021ca400->mEndAllRightsReservedSBAndLogoEndNintendoSBNcgrs[i]->mData,
                  data_ov001_021ca400->mEndAllRightsReservedSBAndLogoEndNintendoSBNcgrs[i]->mDataSize);
    func_02016468(0x18, 0, data_ov001_021ca400->mEndAllRightsReservedSBgAndLogoEndNintendoSBgNscrs[i]->mData,
                  data_ov001_021ca400->mEndAllRightsReservedSBgAndLogoEndNintendoSBgNscrs[i]->mDataSize);
    func_02016468(0x1f, 0, data_ov001_021ca400->mEndAllRightsReservedSBAndLogoEndNintendoSBNclrs[i]->mData,
                  data_ov001_021ca400->mEndAllRightsReservedSBAndLogoEndNintendoSBNclrs[i]->mDataSize);
}

void func_ov001_0219e5a0(void) {
    reg_G2_BG0CNT = reg_G2_BG0CNT & 0x43 | (u16) 0x00001f80u;
    func_ov001_0219e5d4(1);
    data_ov001_021ca400->mUnk_018 = TRUE;
    return;
}

void func_ov001_0219e38c(void) {
#ifdef version_EUR
    LoadNcgrData(&data_ov001_021ca400->mUnk_038[0], FindSceneFile("logo_end_marioKart_m_b_02.ncgr"));
    LoadNscrData(&data_ov001_021ca400->mUnk_040[0], FindSceneFile("logo_end_marioKart_m_bg_02.nscr"));
#else
    LoadNcgrData(&data_ov001_021ca400->mLogoEndMarioKartMBAndThanksYouMBNcgrs[0],
                 FindSceneFile("logo_end_marioKart_m_b_01.ncgr"));
    LoadNscrData(&data_ov001_021ca400->mLogoEndMarioKartMBgAndThanksYouMBgNscrs[0],
                 FindSceneFile("logo_end_marioKart_m_bg_01.nscr"));
#endif
    LoadNclrData(&data_ov001_021ca400->mLogoEndMarioKartMBAndThanksYouMBNclrs[0],
                 FindSceneFile("logo_end_marioKart_m_b.nclr"));
    switch (data_ov001_021ca400->mKind) {
        case 0:
            LoadNcgrData(&data_ov001_021ca400->mLogoEndMarioKartMBAndThanksYouMBNcgrs[1],
                         FindSceneFile("thanksYou_m_b_00.ncgr"));
            LoadNscrData(&data_ov001_021ca400->mLogoEndMarioKartMBgAndThanksYouMBgNscrs[1],
                         FindSceneFile("thanksYou_m_bg_00.nscr"));
            LoadNclrData(&data_ov001_021ca400->mLogoEndMarioKartMBAndThanksYouMBNclrs[1],
                         FindSceneFile("thanksYou_m_b_00.nclr"));
            break;
        case 1:
            LoadNcgrData(&data_ov001_021ca400->mLogoEndMarioKartMBAndThanksYouMBNcgrs[1],
                         FindSceneFile("thanksYou_m_b_01_2.ncgr"));
            LoadNscrData(&data_ov001_021ca400->mLogoEndMarioKartMBgAndThanksYouMBgNscrs[1],
                         FindSceneFile("thanksYou_m_bg_01_2.nscr"));
            LoadNclrData(&data_ov001_021ca400->mLogoEndMarioKartMBAndThanksYouMBNclrs[1],
                         FindSceneFile("thanksYou_m_b_01.nclr"));
            break;
    }
    LoadNcgrData(&data_ov001_021ca400->mEndAllRightsReservedSBAndLogoEndNintendoSBNcgrs[0],
                 FindSceneFile("end_allRightsReserved_s_b.ncgr"));
    LoadNscrData(&data_ov001_021ca400->mEndAllRightsReservedSBgAndLogoEndNintendoSBgNscrs[0],
                 FindSceneFile("end_allRightsReserved_s_bg.nscr"));
    LoadNclrData(&data_ov001_021ca400->mEndAllRightsReservedSBAndLogoEndNintendoSBNclrs[0],
                 FindSceneFile("end_allRightsReserved_s_b.nclr"));
    LoadNcgrData(&data_ov001_021ca400->mEndAllRightsReservedSBAndLogoEndNintendoSBNcgrs[1],
                 FindSceneFile("logo_end_Nintendo_s_b.ncgr"));
    LoadNscrData(&data_ov001_021ca400->mEndAllRightsReservedSBgAndLogoEndNintendoSBgNscrs[1],
                 FindSceneFile("logo_end_Nintendo_s_bg.nscr"));
    LoadNclrData(&data_ov001_021ca400->mEndAllRightsReservedSBAndLogoEndNintendoSBNclrs[1],
                 FindSceneFile("logo_end_Nintendo_s_b.nclr"));
    LoadNcerData(&data_ov001_021ca400->mThanksYouMNcer, FindSceneFile("thanksYou_m.nce.ncer"));
    LoadNclrData(&data_ov001_021ca400->mThanksYouMO00Nclr, FindSceneFile("thanksYou_m_o_00.nclr"));
    switch (data_ov001_021ca400->mKind) {
        case 0:
            data_ov001_021ca400->mEndingThanksBncl = FindSceneFile("ending_thanks_00.bncl");
            data_ov001_021ca400->mEndingThanksBnll = FindSceneFile("ending_thanks_00.bnll");
            break;
        case 1:
            data_ov001_021ca400->mEndingThanksBncl = FindSceneFile("ending_thanks_01.bncl");
            data_ov001_021ca400->mEndingThanksBnll = FindSceneFile("ending_thanks_01.bnll");
            break;
    }
    if (data_0217b488->mUnk_70 != 0) {
        func_ov001_0219e5a0();
    } else {
        func_ov001_0219e5d4(0);
    }
    func_02016468(0xe, 0, data_ov001_021ca400->mThanksYouMO00Nclr->mData,
                  data_ov001_021ca400->mThanksYouMO00Nclr->mDataSize);
}

void func_ov001_0219e34c(void) {
    if (func_02036c5c() != 0) {
        if (data_0217b488->mUnk_70 != 0) {
            data_ov001_021ca400->mNextState = 5;
            data_0217b488->mUnk_70 = 0;
            return;
        }
        data_ov001_021ca400->mNextState = 1;
    }
}

void func_ov001_0219e310(void) {
    data_ov001_021ca400->mUnk_008++;
    if (data_ov001_021ca400->mUnk_008 > data_ov001_021a6c50[data_ov001_021ca400->mState]) {
        data_ov001_021ca400->mNextState = 2;
        data_ov001_021ca400->mUnk_008 = 0;
        func_02036f10((s16) (data_ov001_021a6c50[2]));
    }
}

void func_ov001_0219e2f0(void) {
    int v1;
    v1 = func_02036d08();
    if (v1 != 0) {
        data_ov001_021ca400->mNextState = 3;
    }
    return;
}

void func_ov001_0219e2b4(void) {
    Unk021ca400 *p;

    data_ov001_021ca400->mUnk_008++;
    p = data_ov001_021ca400;
    if (p->mUnk_008 > data_ov001_021a6c50[3]) {
        p->mNextState = 4;
        data_ov001_021ca400->mUnk_008 = 0;
        func_020370d4(data_ov001_021a6c50[4]);
        func_ov001_0219e5a0();
    }
}

void func_ov001_0219e294(void) {
    int v1;
    v1 = func_02036c5c();
    if (v1 != 0) {
        data_ov001_021ca400->mNextState = 5;
    }
    return;
}

void func_ov001_0219e1f8(void) {
    Unk02175628Index idx = UNK_02175628_INDEX_8;
    u16 flags;
    BOOL a;
    BOOL b;
    u16 x;

    data_ov001_021ca400->mUnk_008++;
    if (data_ov001_021ca400->mUnk_008 > data_ov001_021a6c50[data_ov001_021ca400->mState]) {
        data_ov001_021ca400->mUnk_008 = data_ov001_021a6c50[data_ov001_021ca400->mState];
        flags = data_02175628[idx].mUnk_00 & 0xc0f;
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
        data_ov001_021ca400->mNextState = 6;
        data_ov001_021ca400->mUnk_008 = 0;
        func_02036f10((s16) (data_ov001_021a6c50[6]));
    }
}

void func_ov001_0219e1d4(void) {
    if (func_02036d08() != 0) {
        data_ov001_021ca400->mNextState = 7;
        data_ov001_021ca400->mUnk_008 = 0;
    }
}

void func_ov001_0219e1b0(void) {
    data_ov001_021ca400->mUnk_008++;
    if (data_ov001_021ca400->mUnk_008 > data_ov001_021a6c50[7]) {
        data_ov001_021ca400->mUnk_014 = 0;
    }
}

void func_ov001_0219e118(void) {
    data_ov001_021ca400->mState = data_ov001_021ca400->mNextState;
    func_020ae6ac((void *) (data_ov001_021ca400->mUnk_068), NULL);
    switch (data_ov001_021ca400->mState) {
        case 0:
            func_ov001_0219e34c();
            break;
        case 1:
            func_ov001_0219e310();
            break;
        case 2:
            func_ov001_0219e2f0();
            break;
        case 3:
            func_ov001_0219e2b4();
            break;
        case 4:
            func_ov001_0219e294();
            break;
        case 5:
            func_ov001_0219e1f8();
            break;
        case 6:
            func_ov001_0219e1d4();
            break;
        case 7:
            func_ov001_0219e1b0();
            break;
    }
    func_02124c30(data_ov001_021ca400->mEndingThanksBncl, data_ov001_021ca400->mThanksYouMNcer,
                  data_ov001_021ca400->mEndingThanksBnll, data_ov001_021ca400->mUnk_068, data_ov001_021ca400->mUnk_020);
    func_020ae630((void *) (data_ov001_021ca400->mUnk_068), NULL);
}

void func_ov001_0219e0d4(void) {
    u32 bits;

    if (data_ov001_021ca400->mUnk_018 != FALSE) {
        bits = (*(vu32 *) 0x4000000 & 0x1f00) >> 8;
        *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | ((bits | 0x10) << 8);
    }
    func_020ae5f0((void *) (data_ov001_021ca400->mUnk_068), NULL);
}

void func_ov001_0219e0c4(void) {
    data_0217b488->mUnk_70 = 1;
}

s32 func_ov001_0219e0b8(void) {
    return data_0217b488->mUnk_70;
}

int func_ov001_0219e0a8(void) {
    return data_ov001_021ca400->mUnk_014;
}
