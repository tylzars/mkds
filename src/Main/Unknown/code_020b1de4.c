#include "Main/Unknown/code_020b1de4.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020adb04.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_020b250c.h"
#include "Main/Unknown/code_020b252c.h"
#include "Main/Unknown/code_020b24e4.h"
#include "Main/Unknown/code_020b2540.h"
#include "Main/Unknown/code_020b2ecc.h"
#include "Main/Unknown/code_020b3260.h"
#include "Main/Unknown/code_020b32ec.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ad000.h"
#include "Main/Unknown/code_020b2000.h"
#include "Main/Unknown/code_020b3000.h"
#include "code_02023374.h"

void func_020b24cc(Unk02180728 *a, void *b, void *c, s32 d, s32 e) {
    a->mUnk_00 = b;
    a->mUnk_04 = c;
    a->mUnk_08 = d;
    a->mUnk_0c = e;
}

u32 func_020b24a4(Unk02180728 *a, s32 b, s32 c, u32 d, u32 e, void *f) {
    return NNSi_G2dTextCanvasDrawText(a, b, c, d, e, f);
}

#pragma thumb on
#pragma optimize_for_size on

void InitChoisesS(void) {
    ChoisesS *p;
    u32 n;
    s32 i;

    gChoisesS = HeapAlloc(func_020b2540(), 0x1a4);
    gChoisesS->mOpenDuringRace = 0;
    gChoisesS->mPrevOpenDuringRace = 0;
    gChoisesS->mUnk_008 = 0;
    gChoisesS->mPickLocked = 0;
    gChoisesS->mPickFrames = 0;
    gChoisesS->mUnk_010 = FALSE;
    gChoisesS->mAutoPickFrames = 0;
    if (func_020b252c() == MODE_MISSION_RUN) {
        gChoisesS->mUnk_020 = func_020adb34();
    } else {
        gChoisesS->mUnk_020 = FALSE;
    }
    gChoisesS->mUnk_02c = 0;
    gChoisesS->mUnk_030 = 0;
    ResetChoisesSSelection();
    ClearChoisesSListValueCounts();
    switch (func_020b252c()) {
        case MODE_GRAND_PRIX:
            AppendChoisesSListValue(0, 0);
            AppendChoisesSListValue(0, 9);
            if (func_020b250c() != FALSE) {
                AppendChoisesSListValue(1, 7);
                AppendChoisesSListValue(1, 8);
            } else {
                AppendChoisesSListValue(1, 2);
                AppendChoisesSListValue(1, 8);
                AppendChoisesSListValue(1, 9);
            }
            if (func_020b250c() != FALSE) {
                AppendChoisesSListValue(3, 0);
                AppendChoisesSListValue(3, 7);
                AppendChoisesSListValue(3, 8);
            } else {
                AppendChoisesSListValue(3, 0);
                AppendChoisesSListValue(3, 2);
                AppendChoisesSListValue(3, 8);
                AppendChoisesSListValue(3, 9);
            }
            break;
        case MODE_TIME_ATTACK:
            AppendChoisesSListValue(0, 0);
            AppendChoisesSListValue(0, 3);
            AppendChoisesSListValue(0, 4);
            AppendChoisesSListValue(0, 5);
            AppendChoisesSListValue(0, 9);
            AppendChoisesSListValue(1, 1);
            AppendChoisesSListValue(1, 4);
            AppendChoisesSListValue(1, 5);
            AppendChoisesSListValue(1, 8);
            AppendChoisesSListValue(1, 9);
            AppendChoisesSListValue(3, 0);
            AppendChoisesSListValue(3, 1);
            AppendChoisesSListValue(3, 4);
            AppendChoisesSListValue(3, 5);
            AppendChoisesSListValue(3, 8);
            AppendChoisesSListValue(3, 9);
            break;
        case MODE_BATTLE:
            AppendChoisesSListValue(0, 0);
            AppendChoisesSListValue(0, 9);
            AppendChoisesSListValue(1, 2);
            AppendChoisesSListValue(1, 9);
            AppendChoisesSListValue(2, 7);
            break;
        case MODE_VS:
            AppendChoisesSListValue(0, 0);
            AppendChoisesSListValue(0, 9);
            AppendChoisesSListValue(1, 2);
            AppendChoisesSListValue(1, 9);
            AppendChoisesSListValue(2, 7);
            break;
        case MODE_MISSION_RUN:
            AppendChoisesSListValue(0, 0);
            AppendChoisesSListValue(0, 3);
            AppendChoisesSListValue(0, 6);
            AppendChoisesSListValue(0, 9);
            if (func_020b2f58() != 0) {
                if (func_020adc04() != 0) {
                    AppendChoisesSListValue(1, 1);
                    AppendChoisesSListValue(1, 6);
                    AppendChoisesSListValue(1, 9);
                    AppendChoisesSListValue(2, 6);
                    AppendChoisesSListValue(2, 1);
                    AppendChoisesSListValue(2, 10);
                    AppendChoisesSListValue(2, 9);
                } else {
                    AppendChoisesSListValue(1, 1);
                    AppendChoisesSListValue(1, 6);
                    AppendChoisesSListValue(1, 9);
                    AppendChoisesSListValue(2, 6);
                    AppendChoisesSListValue(2, 1);
                    AppendChoisesSListValue(2, 9);
                }
            } else {
                AppendChoisesSListValue(1, 1);
                AppendChoisesSListValue(1, 6);
                AppendChoisesSListValue(1, 9);
                AppendChoisesSListValue(2, 6);
                AppendChoisesSListValue(2, 1);
                AppendChoisesSListValue(2, 9);
            }
            break;
        case 5:
            AppendChoisesSListValue(0, 0);
            if (GetCourseNumber() != 4) {
                AppendChoisesSListValue(1, 2);
            } else {
                AppendChoisesSListValue(1, 7);
            }
            break;
    }
    if (func_020b24e4() != RACE_KIND_START_GP && func_020b24e4() != RACE_KIND_STAFF_ROLL) {
        const char *nscrNames[6] = {
            "choises_s_1.NSCR", "choises_s_2.NSCR", "choises_s_3.NSCR",
            "choises_s_4.NSCR", "choises_s_5.NSCR", "choises_s_6.NSCR",
        };

        LoadNclrData(&gChoisesS->mChoisesSBNclr, FindSceneFileWrapper("choises_s_b.NCLR"));
        LoadNcgrData(&gChoisesS->mChoisesSBNcgr, FindSceneFileWrapper("choises_s_b.NCGR"));
        for (i = 0; i < 6; i++) {
            LoadNscrData(&gChoisesS->mChoisesSNscrs[i], FindSceneFileWrapper(nscrNames[i]));
        }
        gChoisesS->mList0Nscr = gChoisesS->mChoisesSNscrs[gChoisesS->mLists[0].mValueCount - 1];
        gChoisesS->mList1Nscr = gChoisesS->mChoisesSNscrs[gChoisesS->mLists[1].mValueCount - 1];
        gChoisesS->mList2Nscr = gChoisesS->mChoisesSNscrs[gChoisesS->mLists[2].mValueCount - 1];
        gChoisesS->mList3Nscr = gChoisesS->mChoisesSNscrs[gChoisesS->mLists[3].mValueCount - 1];
        gChoisesS->mList1Chars = HeapAlloc(func_020b2540(), func_020b3260(gChoisesS->mLists[1].mValueCount));
        switch (func_020b252c()) {
            case MODE_BATTLE:
            case MODE_VS:
            case MODE_MISSION_RUN:
                gChoisesS->mList2Chars = HeapAlloc(func_020b2540(), func_020b3260(gChoisesS->mLists[2].mValueCount));
                break;
        }
        gChoisesS->mFont = func_020b403c(2);
        NNS_G2dCharCanvasInitForBG(gChoisesS->mCharCanvases[0], func_020b3374()->mData, 0x20, 0xc, 4);
        p = gChoisesS;
        func_020b24cc(&p->mTextCanvases[0], p->mCharCanvases[0], p->mFont, func_020b4acc(), 0);
        NNS_G2dCharCanvasInitForBG(gChoisesS->mCharCanvases[1], gChoisesS->mList1Chars, 0x20, 0xc, 4);
        p = gChoisesS;
        func_020b24cc(&p->mTextCanvases[1], p->mCharCanvases[1], p->mFont, func_020b4acc(), 0);
        n = func_020b3260(gChoisesS->mLists[1].mValueCount) >> 1;
        for (i = 0; i < n; i++) {
            gChoisesS->mList1Chars[i] = func_020b3374()->mData[i];
        }
        if (gChoisesS->mList2Chars != NULL) {
            NNS_G2dCharCanvasInitForBG(gChoisesS->mCharCanvases[2], gChoisesS->mList2Chars, 0x20, 0xc, 4);
            p = gChoisesS;
            func_020b24cc(&p->mTextCanvases[2], p->mCharCanvases[2], p->mFont, func_020b4acc(), 0);
            n = func_020b3260(gChoisesS->mLists[2].mValueCount) >> 1;
            for (i = 0; i < n; i++) {
                gChoisesS->mList2Chars[i] = func_020b3374()->mData[i];
            }
        }
        NNS_G2dCharCanvasInitForBG(gChoisesS->mCharCanvases[3], func_020b3374()->mData, 0x20, 0xc, 4);
        p = gChoisesS;
        func_020b24cc(&p->mTextCanvases[3], p->mCharCanvases[3], p->mFont, func_020b4acc(), 0);
        if (func_020b24e4() != 2) {
            for (i = 0; i < gChoisesS->mLists[0].mValueCount; i++) {
                func_020b24a4(&gChoisesS->mTextCanvases[0], 0x90, i * 16 + 9, 0xc, 0x412,
                              func_020b320c(0, gChoisesS->mLists[0].mValues[i]));
            }
        } else {
            for (i = 0; i < gChoisesS->mLists[3].mValueCount; i++) {
                func_020b24a4(&gChoisesS->mTextCanvases[3], 0x90, i * 16 + 9, 0xc, 0x412,
                              func_020b320c(3, gChoisesS->mLists[3].mValues[i]));
            }
        }
        for (i = 0; i < gChoisesS->mLists[1].mValueCount; i++) {
            func_020b24a4(&gChoisesS->mTextCanvases[1], 0x90, i * 16 + 9, 0xc, 0x412,
                          func_020b320c(1, gChoisesS->mLists[1].mValues[i]));
        }
        for (i = 0; i < gChoisesS->mLists[2].mValueCount; i++) {
            func_020b24a4(&gChoisesS->mTextCanvases[2], 0x90, i * 16 + 9, 0xc, 0x412,
                          func_020b320c(2, gChoisesS->mLists[2].mValues[i]));
        }
    } else {
        gChoisesS->mChoisesSBNclr = NULL;
        gChoisesS->mChoisesSBNcgr = NULL;
        gChoisesS->mList1Chars = NULL;
        gChoisesS->mList2Chars = NULL;
        gChoisesS->mList0Nscr = NULL;
        gChoisesS->mList1Nscr = NULL;
        gChoisesS->mList2Nscr = NULL;
        gChoisesS->mList3Nscr = NULL;
    }
}

void ClearChoisesSPointer(void) {
    gChoisesS = NULL;
}

#pragma thumb off
