#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020adb04.h"
#include "Main/Unknown/code_020b1de4.h"
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
    return func_02024340(a, b, c, d, e, f);
}

#pragma thumb on
#pragma optimize_for_size on

void InitChoisesS(void) {
    ChoisesS *p;
    u32 n;
    s32 i;

    gChoisesS = HeapAlloc(func_020b2540(), 0x1a4);
    gChoisesS->mUnk_000 = 0;
    gChoisesS->mUnk_004 = 0;
    gChoisesS->mUnk_008 = 0;
    gChoisesS->mUnk_00c = 0;
    gChoisesS->mUnk_014 = 0;
    gChoisesS->mUnk_010 = FALSE;
    gChoisesS->mUnk_01c = 0;
    if (func_020b252c() == 4) {
        gChoisesS->mUnk_020 = func_020adb34();
    } else {
        gChoisesS->mUnk_020 = FALSE;
    }
    gChoisesS->mUnk_02c = 0;
    gChoisesS->mUnk_030 = 0;
    func_020b3008();
    func_020b31e4();
    switch (func_020b252c()) {
        case 0:
            func_020b31b8(0, 0);
            func_020b31b8(0, 9);
            if (func_020b250c() != FALSE) {
                func_020b31b8(1, 7);
                func_020b31b8(1, 8);
            } else {
                func_020b31b8(1, 2);
                func_020b31b8(1, 8);
                func_020b31b8(1, 9);
            }
            if (func_020b250c() != FALSE) {
                func_020b31b8(3, 0);
                func_020b31b8(3, 7);
                func_020b31b8(3, 8);
            } else {
                func_020b31b8(3, 0);
                func_020b31b8(3, 2);
                func_020b31b8(3, 8);
                func_020b31b8(3, 9);
            }
            break;
        case 1:
            func_020b31b8(0, 0);
            func_020b31b8(0, 3);
            func_020b31b8(0, 4);
            func_020b31b8(0, 5);
            func_020b31b8(0, 9);
            func_020b31b8(1, 1);
            func_020b31b8(1, 4);
            func_020b31b8(1, 5);
            func_020b31b8(1, 8);
            func_020b31b8(1, 9);
            func_020b31b8(3, 0);
            func_020b31b8(3, 1);
            func_020b31b8(3, 4);
            func_020b31b8(3, 5);
            func_020b31b8(3, 8);
            func_020b31b8(3, 9);
            break;
        case 2:
            func_020b31b8(0, 0);
            func_020b31b8(0, 9);
            func_020b31b8(1, 2);
            func_020b31b8(1, 9);
            func_020b31b8(2, 7);
            break;
        case 3:
            func_020b31b8(0, 0);
            func_020b31b8(0, 9);
            func_020b31b8(1, 2);
            func_020b31b8(1, 9);
            func_020b31b8(2, 7);
            break;
        case 4:
            func_020b31b8(0, 0);
            func_020b31b8(0, 3);
            func_020b31b8(0, 6);
            func_020b31b8(0, 9);
            if (func_020b2f58() != 0) {
                if (func_020adc04() != 0) {
                    func_020b31b8(1, 1);
                    func_020b31b8(1, 6);
                    func_020b31b8(1, 9);
                    func_020b31b8(2, 6);
                    func_020b31b8(2, 1);
                    func_020b31b8(2, 10);
                    func_020b31b8(2, 9);
                } else {
                    func_020b31b8(1, 1);
                    func_020b31b8(1, 6);
                    func_020b31b8(1, 9);
                    func_020b31b8(2, 6);
                    func_020b31b8(2, 1);
                    func_020b31b8(2, 9);
                }
            } else {
                func_020b31b8(1, 1);
                func_020b31b8(1, 6);
                func_020b31b8(1, 9);
                func_020b31b8(2, 6);
                func_020b31b8(2, 1);
                func_020b31b8(2, 9);
            }
            break;
        case 5:
            func_020b31b8(0, 0);
            if (func_020b24f8() != 4) {
                func_020b31b8(1, 2);
            } else {
                func_020b31b8(1, 7);
            }
            break;
    }
    if (func_020b24e4() != 3 && func_020b24e4() != 6) {
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
        gChoisesS->mUnk_174 = HeapAlloc(func_020b2540(), func_020b3260(gChoisesS->mLists[1].mValueCount));
        switch (func_020b252c()) {
            case 2:
            case 3:
            case 4:
                gChoisesS->mUnk_178 = HeapAlloc(func_020b2540(), func_020b3260(gChoisesS->mLists[2].mValueCount));
                break;
        }
        gChoisesS->mUnk_0a8 = func_020b403c(2);
        func_02023408(gChoisesS->mUnk_0ac[0], func_020b3374()->mData, 0x20, 0xc, 4);
        p = gChoisesS;
        func_020b24cc(&p->mUnk_12c[0], p->mUnk_0ac[0], p->mUnk_0a8, func_020b4acc(), 0);
        func_02023408(gChoisesS->mUnk_0ac[1], gChoisesS->mUnk_174, 0x20, 0xc, 4);
        p = gChoisesS;
        func_020b24cc(&p->mUnk_12c[1], p->mUnk_0ac[1], p->mUnk_0a8, func_020b4acc(), 0);
        n = func_020b3260(gChoisesS->mLists[1].mValueCount) >> 1;
        for (i = 0; i < n; i++) {
            gChoisesS->mUnk_174[i] = func_020b3374()->mData[i];
        }
        if (gChoisesS->mUnk_178 != NULL) {
            func_02023408(gChoisesS->mUnk_0ac[2], gChoisesS->mUnk_178, 0x20, 0xc, 4);
            p = gChoisesS;
            func_020b24cc(&p->mUnk_12c[2], p->mUnk_0ac[2], p->mUnk_0a8, func_020b4acc(), 0);
            n = func_020b3260(gChoisesS->mLists[2].mValueCount) >> 1;
            for (i = 0; i < n; i++) {
                gChoisesS->mUnk_178[i] = func_020b3374()->mData[i];
            }
        }
        func_02023408(gChoisesS->mUnk_0ac[3], func_020b3374()->mData, 0x20, 0xc, 4);
        p = gChoisesS;
        func_020b24cc(&p->mUnk_12c[3], p->mUnk_0ac[3], p->mUnk_0a8, func_020b4acc(), 0);
        if (func_020b24e4() != 2) {
            for (i = 0; i < gChoisesS->mLists[0].mValueCount; i++) {
                func_020b24a4(&gChoisesS->mUnk_12c[0], 0x90, i * 16 + 9, 0xc, 0x412,
                              func_020b320c(0, gChoisesS->mLists[0].mValues[i]));
            }
        } else {
            for (i = 0; i < gChoisesS->mLists[3].mValueCount; i++) {
                func_020b24a4(&gChoisesS->mUnk_12c[3], 0x90, i * 16 + 9, 0xc, 0x412,
                              func_020b320c(3, gChoisesS->mLists[3].mValues[i]));
            }
        }
        for (i = 0; i < gChoisesS->mLists[1].mValueCount; i++) {
            func_020b24a4(&gChoisesS->mUnk_12c[1], 0x90, i * 16 + 9, 0xc, 0x412,
                          func_020b320c(1, gChoisesS->mLists[1].mValues[i]));
        }
        for (i = 0; i < gChoisesS->mLists[2].mValueCount; i++) {
            func_020b24a4(&gChoisesS->mUnk_12c[2], 0x90, i * 16 + 9, 0xc, 0x412,
                          func_020b320c(2, gChoisesS->mLists[2].mValues[i]));
        }
    } else {
        gChoisesS->mChoisesSBNclr = NULL;
        gChoisesS->mChoisesSBNcgr = NULL;
        gChoisesS->mUnk_174 = NULL;
        gChoisesS->mUnk_178 = NULL;
        gChoisesS->mList0Nscr = NULL;
        gChoisesS->mList1Nscr = NULL;
        gChoisesS->mList2Nscr = NULL;
        gChoisesS->mList3Nscr = NULL;
    }
}

void func_020b1de4(void) {
    gChoisesS = NULL;
}

#pragma thumb off
