#include "Main/Unknown/code_02119e14.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02060004.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020d0efc.h"
#include "registers.h"
#include "Main/Unknown/code_0211e4e8.h"
#include "Main/Unknown/code_0211b23c.h"
#include "Main/Unknown/code_0211ac88.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/code_0212b1a8.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02016468.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_0202b000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020d0000.h"
#include "Main/Unknown/code_02116d24.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_0211ac70.h"
#include "Main/Unknown/code_0211b224.h"
#include "Main/Unknown/code_0211de00.h"
#include "Main/Unknown/code_0211e0c4.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02124bc8.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_02127000.h"
#include "Main/Unknown/code_02128244.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_0212b000.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_0202bb80.h"

#pragma thumb on

void AdvanceSelectRaceRuleState6(void) {
    if (GetSelectChoisesDone() != 0) {
        RequestSelectRaceRuleState7();
        switch (GetSelectChoisesIndex()) {
            case 0:
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 7);
                break;
            case -1:
            case 1:
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x10);
                break;
        }
    }
}

void AdvanceSelectRaceRuleState7(void) {
    if (IsSelectChoisesState0NoState1Request() != 0) {
        switch (GetSelectChoisesIndex()) {
            case 0:
                RequestSelectRaceRuleState8();
                gSelectRaceRule->mResult = 1;
                func_0202b7c0(3);
                RequestSelectReturnState4();
                break;
            case -1:
            case 1:
                RequestSelectRaceRuleState3();
                break;
        }
    }
}

void AdvanceSelectRaceRuleState8(void) {
    SelectRaceRule *p;
    s32 i;
    s16 a;
    s16 b;
    s32 j;
    s32 c;
    gSelectRaceRule->mStateFrames++;
    p = gSelectRaceRule;
    c = InterpolateS16(1, 0, -192, p->mStateFrames, 10);
    b = p->mOffsetY + c;
    a = -LookupSelectReturnState4Bg2Offset(p->mStateFrames);
    gSelectRaceRule->mBg3Offset = b;
    c = gSelectRaceRule->mBncl->mUnk_06;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mTable[data_0215cd88[i][j]].mUnk_06 = b;
            gSelectRaceRule->mTable[data_0215cdb0[i][j]].mUnk_06 = b;
            gSelectRaceRule->mTable[data_0215cdc4[i][j]].mUnk_06 = b;
        }
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mTable[c + data_0215cd4c[i].mUnk_00[j]].mUnk_06 = b;
        }
    }
    gSelectRaceRule->mTable[c + 10].mUnk_06 = b;
    gSelectRaceRule->mTable[c + 12].mUnk_06 = b;
    gSelectRaceRule->mTable[34].mUnk_06 = b;
    gSelectRaceRule->mTable[37].mUnk_06 = b;
    gSelectRaceRule->mTable[35].mUnk_06 = b;
    gSelectRaceRule->mTable[38].mUnk_06 = b;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mTable[data_0215ccac[i][j]].mUnk_06 = b;
        }
    }
    if (data_021759d0->mUnk_20 != 2) {
        gSelectRaceRule->mTable[40].mUnk_06 = a;
        gSelectRaceRule->mTable[41].mUnk_06 = a;
        gSelectRaceRule->mTable[c + 13].mUnk_06 = a;
        c += 8;
        gSelectRaceRule->mTable[c].mUnk_06 = b;
        gSelectRaceRule->mTable[30].mUnk_06 = b;
        gSelectRaceRule->mTable[31].mUnk_06 = b;
    } else {
        gSelectRaceRule->mTable[42].mUnk_06 = a;
        c += 14;
        gSelectRaceRule->mTable[c].mUnk_06 = a;
    }
}

void func_0211a964(s32 a) {
    s32 b;
    b = gSelectRaceRule->mBncl->mUnk_06 + a;
    gSelectRaceRule->mTable[b].mUnk_06++;
    func_02124100(a, 1, gSelectRaceRule->mBnll, gSelectRaceRule->mTable, gSelectRaceRule->mBncl);
    func_02124bc8(b, gSelectRaceRule->mBncl, gSelectRaceRule->mNcer, gSelectRaceRule->mBnll, gSelectRaceRule->mUnk_b4,
                  gSelectRaceRule->mTable);
    gSelectRaceRule->mTable[b].mUnk_06--;
    func_02124100(a, 0, gSelectRaceRule->mBnll, gSelectRaceRule->mTable, gSelectRaceRule->mBncl);
}

void func_0211a908(s32 a) {
    if (a == 3) {
        if (data_021759d0->mUnk_20 != 2) {
            func_0211a964(data_0215cd4e[a * 2]);
        }
        func_0211a964(10);
    } else if (a == 4) {
        func_0211a964(data_0215cd4e[a * 2]);
        func_0211a964(12);
    } else {
        func_0211a964(data_0215cd4e[a * 2]);
    }
}

s32 AdvanceSelectRaceRule(void) {
    SelectRaceRule *p;
    s32 i;
    gSelectRaceRule->mState = gSelectRaceRule->mNextState;
    gSelectRaceRule->mPrevRow = gSelectRaceRule->mRow;
    gSelectRaceRule->mPrevOnButton = gSelectRaceRule->mOnButton;
    switch (gSelectRaceRule->mState) {
        case 0:
            AdvanceSelectRaceRuleState0();
            break;
        case 1:
            AdvanceSelectRaceRuleState1();
            break;
        case 2:
            AdvanceSelectRaceRuleState2();
            break;
        case 3:
            AdvanceSelectRaceRuleState3();
            break;
        case 4:
            AdvanceSelectRaceRuleState4();
            break;
        case 5:
            AdvanceSelectRaceRuleState5();
            break;
        case 6:
            AdvanceSelectRaceRuleState6();
            break;
        case 7:
            AdvanceSelectRaceRuleState7();
            break;
        case 8:
            AdvanceSelectRaceRuleState8();
            break;
    }
    if (data_021759d0->mUnk_20 == 2) {
        AdvanceWait();
    }
    switch (gSelectRaceRule->mRowValues[4]) {
        case 0:
            func_0202b6f0(0);
            break;
        case 1:
        case 2:
            func_0202b6f0(1);
            break;
    }
    func_0202bb80();
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        AdvancePaletteBlend();
    }
    AdvanceSelectRaceRuleHighlight();
    func_0211d66c();
    func_0211c0cc();
    p = gSelectRaceRule;
    func_02124c30(p->mBncl, p->mNcer, p->mBnll, p->mUnk_b4, p->mTable);
    for (i = 0; i < 5; i++) {
        func_0211a908(i);
    }
    p = gSelectRaceRule;
    if (p->mState == 8) {
        if (p->mResult == 1 && (p->mMode == 3 || p->mRowValues[2] == 1)) {
            if (p->mStateFrames >= 10 && IsSelectReturnState0NoState1Request() != 0) {
                return gSelectRaceRule->mResult;
            }
        } else if (p->mStateFrames >= 10) {
            return p->mResult;
        }
    }
    return 0;
}

void func_0211a794(void) {
    reg_G2S_DB_BG3OFS = (-gSelectRaceRule->mBg3Offset << 16) & 0x1ff0000;
    func_0202ba14();
}

void func_0211a6bc(void) {
    Ncgr *a = NULL;
    Unk02021dc8 *b = NULL;
    Nclr *c = NULL;
    Ncgr *d = NULL;
    Nscr *e = NULL;
    Nclr *f = NULL;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        LoadNcgrData(&d, FindSceneFile(data_0216d894));
        LoadNclrData(&f, FindSceneFile(data_0216d88c));
        LoadNscrData(&e, FindSceneFile(data_0216d8a4));
        LoadNcgrData(&d, FindSceneFile(data_0216d87c));
        LoadNclrData(&f, FindSceneFile(data_0216d86c));
        LoadNscrData(&e, FindSceneFile(data_0216d884));
        LoadNcgrData2(&a, FindSceneFile(data_0216d8a0));
        LoadNcerData(&b, FindSceneFile(data_0216d890));
        LoadNclrData(&c, FindSceneFile(data_0216d878));
    }
}

void func_0211a3bc(void) {
    Ncgr *a = NULL;
    Nclr *b = NULL;
    Ncgr *c = NULL;
    Nclr *d = NULL;
    Ncgr *e = NULL;
    Nscr *f = NULL;
    Nclr *g = NULL;
    Ncgr *h = NULL;
    Nscr *i = NULL;
    Nclr *j = NULL;
    u16 *p;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        gSelectCupCourse->mSelectCupMBnbl = FindSceneFile(data_0216d864);
        return;
    }
    if (gSelectCupCourse->mMode == 0) {
        LocateNcgr(&e, FindSceneFile(data_0216d894));
        LocateNclr(&g, FindSceneFile(data_0216d88c));
        LocateNscr(&f, FindSceneFile(data_0216d8a4));
    } else {
        LocateNcgr(&e, FindSceneFile(data_0216d87c));
        LocateNclr(&g, FindSceneFile(data_0216d86c));
        LocateNscr(&f, FindSceneFile(data_0216d884));
    }
    LocateNcgr(&h, FindSceneFile(data_0216d874));
    LocateNclr(&j, FindSceneFile(data_0216d854));
    LocateNscr(&i, FindSceneFile(data_0216d858));
    gSelectCupCourse->mUnk_24 = HeapAlloc(gSelectCupCourse->mHeap, 0x800);
    if (gSelectCupCourse->mMode == 0) {
        gSelectCupCourse->mSelectCupCourseTaOrVsMBncl = FindSceneFile(data_0216d880);
        gSelectCupCourse->mSelectCupCourseTaOrVsMBnll = FindSceneFile(data_0216d89c);
    } else {
        gSelectCupCourse->mSelectCupCourseTaOrVsMBncl = FindSceneFile(data_0216d868);
        gSelectCupCourse->mSelectCupCourseTaOrVsMBnll = FindSceneFile(data_0216d870);
    }
    LocateNcgr2(&a, FindSceneFile(data_0216d8a0));
    LocateNcer(&gSelectCupCourse->mSelectCupCourseMNcer, FindSceneFile(data_0216d890));
    LocateNclr(&b, FindSceneFile(data_0216d878));
    gSelectCupCourse->mSelectCupMBncl = FindSceneFile(data_0216d888);
    gSelectCupCourse->mSelectCupMBnbl = FindSceneFile(data_0216d864);
    gSelectCupCourse->mSelectCupMBnll = FindSceneFile(data_0216d860);
    LocateNcgr2(&c, FindSceneFile(data_0216d898));
    LocateNcer(&gSelectCupCourse->mSelectCupMNcer, FindSceneFile(data_0216d8a8));
    LocateNclr(&d, FindSceneFile(data_0216d85c));
    p = b->mData;
    CallQueueAppend(4, 0, e->mData, e->mDataSize);
    CallQueueAppend(0xf, 0, g->mData, 0x140);
    CallQueueAppend(8, 0, f->mData, f->mDataSize);
    CallQueueAppend(8, 0x800, gSelectCupCourse->mUnk_24, 0x800);
    if (func_020cccb4() != 0x18 && func_020cccb4() != 0xc) {
        CallQueueAppend(0x17, 0, h->mData, h->mDataSize);
        CallQueueAppend(0x1f, 0, j->mData, 0x140);
        CallQueueAppend(0x1b, 0, i->mData, i->mDataSize);
        CallQueueAppend(0x1b, 0x800, gSelectCupCourse->mUnk_24, 0x800);
    }
    CallQueueAppend(0x13, 0, a->mData, a->mDataSize);
    CallQueueAppend(0xe, 0, b->mData, 0x1a0);
    CallQueueAppend(0xe, 0x1c0, p + 0xe0, 0x40);
    CallQueueAppend(0x23, 0, c->mData, c->mDataSize);
    CallQueueAppend(0x1e, 0, d->mData, d->mDataSize);
}

void func_0211a100(void) {
    s32 i;
    u32 a;
    u32 b;
    SelectCupCourse *p;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        a = gSelectCupCourse->mSelectCupCourseTaOrVsMBncl->mUnk_06;
        b = gSelectCupCourse->mSelectCupMBncl->mUnk_06;
        for (i = 0; i < 8; i++) {
            gSelectCupCourse->mSelectCupMTable[data_0215cacc[i]].mUnk_00 = 0;
        }
        for (i = 0; i < 4; i++) {
            gSelectCupCourse->mSelectCupMTable[data_0215ca9c[i]].mUnk_00 = 0;
        }
        for (i = 0; i < 4; i++) {
            gSelectCupCourse->mSelectCupMTable[data_0215caa4[i]].mUnk_00 = 0;
            gSelectCupCourse->mSelectCupMTable[b + data_0215cab4[i]].mUnk_00 = 1;
        }
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[0].mUnk_00 = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[2].mUnk_00 = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[1].mUnk_00 = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[4].mUnk_00 = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[3].mUnk_00 = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[5].mUnk_00 = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[a].mUnk_00 = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[a + 1].mUnk_00 = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[a + 2].mUnk_00 = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[a + 3].mUnk_00 = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[a + 4].mUnk_00 = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[a + 5].mUnk_00 = 1;
        gSelectCupCourse->mSelectCupMTable[0x14].mUnk_00 = 0;
        gSelectCupCourse->mSelectCupMTable[0x13].mUnk_00 = 1;
        p = gSelectCupCourse;
        QueueSelectCupNameM(data_0215cadc[GetCupIndex()], p->mSelectCupCourseMNcer, p->mSelectCupCourseTaOrVsMBncl, 0,
                            0);
        p = gSelectCupCourse;
        QueueSelectCupNameM(data_0215cadc[GetCupIndex()], p->mSelectCupMNcer, p->mSelectCupMBncl, 0x13, 1);
        p = gSelectCupCourse;
        i = GetCupIndex();
        QueueCupMark(data_0215cadc[i], p->mSelectCupCourseMNcer, p->mSelectCupCourseTaOrVsMBncl, 5,
                     func_02124a68(5, p->mSelectCupCourseMNcer, p->mSelectCupCourseTaOrVsMBncl), 0);
        for (i = 0; i < 4; i++) {
            p = gSelectCupCourse;
            func_0212426c(
                1, data_0215cab4[i], gSelectCupCourse->mSelectCupMBnll,
                GetBmgEntry(gSelectCupCourse->mCommonMessages, data_0215cafc[data_0215cadc[GetCupIndex()]][i]),
                p->mSelectCupMBncl, p->mSelectCupMTable);
        }
        p = gSelectCupCourse;
        func_0212426c(0, 2, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll, GetBmgEntry(p->mCommonMessages, 0x73),
                      p->mSelectCupCourseTaOrVsMBncl, p->mSelectCupCourseTaOrVsMTable);
        p = gSelectCupCourse;
        func_0212426c(0, 4, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll, GetBmgEntry(p->mCommonMessages, 0x74),
                      p->mSelectCupCourseTaOrVsMBncl, p->mSelectCupCourseTaOrVsMTable);
        func_02124140(0, 0, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll,
                      gSelectCupCourse->mSelectCupCourseTaOrVsMTable, gSelectCupCourse->mSelectCupCourseTaOrVsMBncl);
        func_02124140(1, 0, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll,
                      gSelectCupCourse->mSelectCupCourseTaOrVsMTable, gSelectCupCourse->mSelectCupCourseTaOrVsMBncl);
        func_02124140(2, 0, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll,
                      gSelectCupCourse->mSelectCupCourseTaOrVsMTable, gSelectCupCourse->mSelectCupCourseTaOrVsMBncl);
        func_02124140(4, 0, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll,
                      gSelectCupCourse->mSelectCupCourseTaOrVsMTable, gSelectCupCourse->mSelectCupCourseTaOrVsMBncl);
        p = gSelectCupCourse;
        switch (p->mMode) {
            case 1:
            case 2:
            case 3:
                p->mSelectCupCourseTaOrVsMTable[a + 2].mUnk_00 = 0;
                gSelectCupCourse->mSelectCupCourseTaOrVsMTable[a + 3].mUnk_00 = 0;
                gSelectCupCourse->mSelectCupCourseTaOrVsMTable[a + 4].mUnk_00 = 0;
                gSelectCupCourse->mSelectCupCourseTaOrVsMTable[a + 5].mUnk_00 = 0;
                break;
        }
    }
}

void func_0211a07c(void) {
    s32 i;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        for (i = 0; i < 4; i++) {
            if (gSelectCupCourse->mIndex == i && gSelectCupCourse->mUnk_54 != FALSE) {
                gSelectCupCourse->mSelectCupMTable[data_0215caa4[i]].mUnk_00 = 1;
                func_02124100(data_0215cab4[i], 0xe, gSelectCupCourse->mSelectCupMBnll,
                              gSelectCupCourse->mSelectCupMTable, gSelectCupCourse->mSelectCupMBncl);
            } else {
                gSelectCupCourse->mSelectCupMTable[data_0215caa4[i]].mUnk_00 = 0;
                func_02124100(data_0215cab4[i], 0xf, gSelectCupCourse->mSelectCupMBnll,
                              gSelectCupCourse->mSelectCupMTable, gSelectCupCourse->mSelectCupMBncl);
            }
        }
    }
}

void func_02119e88(void) {
    SelectCupCourse *p;
    u32 a;
    u8 b[0x24];
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        p = gSelectCupCourse;
        func_0212426c(
            0, 0, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll,
            GetBmgEntry(gSelectCupCourse->mCommonMessages, data_0215cafc[data_0215cadc[GetCupIndex()]][p->mIndex]),
            p->mSelectCupCourseTaOrVsMBncl, p->mSelectCupCourseTaOrVsMTable);
        p = gSelectCupCourse;
        func_0212426c(
            0, 1, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll,
            GetBmgEntry(gSelectCupCourse->mCommonMessages, data_0215cafc[data_0215cadc[GetCupIndex()]][p->mIndex]),
            p->mSelectCupCourseTaOrVsMBncl, p->mSelectCupCourseTaOrVsMTable);
        if (IsTimeRecordFilled(data_0215cbec[data_0215cadc[GetCupIndex()]][gSelectCupCourse->mIndex], 0)) {
            GetTimeRecordTime(data_0215cbec[data_0215cadc[GetCupIndex()]][gSelectCupCourse->mIndex], 0, &a);
            func_02116b80(&a, b);
            p = gSelectCupCourse;
            func_02124224(0, 3, p->mSelectCupCourseTaOrVsMBnll, b, p->mSelectCupCourseTaOrVsMBncl,
                          p->mSelectCupCourseTaOrVsMTable, 9);
        } else {
            p = gSelectCupCourse;
            func_02124224(0, 3, p->mSelectCupCourseTaOrVsMBnll, data_0216dbac, p->mSelectCupCourseTaOrVsMBncl,
                          p->mSelectCupCourseTaOrVsMTable, 9);
        }
        if (IsTimeRecordFilled(data_0215cbec[data_0215cadc[GetCupIndex()]][gSelectCupCourse->mIndex], 5)) {
            GetTimeRecordTime(data_0215cbec[data_0215cadc[GetCupIndex()]][gSelectCupCourse->mIndex], 5, &a);
            func_02116b80(&a, b);
            p = gSelectCupCourse;
            func_02124224(0, 5, p->mSelectCupCourseTaOrVsMBnll, b, p->mSelectCupCourseTaOrVsMBncl,
                          p->mSelectCupCourseTaOrVsMTable, 9);
        } else {
            p = gSelectCupCourse;
            func_02124224(0, 5, p->mSelectCupCourseTaOrVsMBnll, data_0216dbc0, p->mSelectCupCourseTaOrVsMBncl,
                          p->mSelectCupCourseTaOrVsMTable, 9);
        }
        TrySetCupPictureIndexAndQueueLoads(data_0215cbec[data_0215cadc[GetCupIndex()]][gSelectCupCourse->mIndex]);
        gSelectCupCourse->mCupPicturePending = TRUE;
    }
}

void func_02119e50(void) {
    SetCourseId(data_0215cbec[data_0215cadc[GetCupIndex()]][gSelectCupCourse->mIndex]);
}

void func_02119e14(void) {
    func_0211e418(data_0215cbec[data_0215cadc[GetCupIndex()]][gSelectCupCourse->mIndex]);
    func_0202949c(0);
}

#pragma thumb off
