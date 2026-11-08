#include "Main/Unknown/code_021189f4.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020d0e3c.h"
#include "Main/Unknown/code_02119e14.h"
#include "Main/Unknown/code_0211f394.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/code_02119a90.h"

#include "00/code_02181f98.h"
#include "Main/Unknown/code_02047104.h"
#include "code_02016468.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_0205f000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020d0000.h"
#include "Main/Unknown/code_02119544.h"
#include "Main/Unknown/code_021196f4.h"
#include "Main/Unknown/code_0211952c.h"
#include "Main/Unknown/code_021196dc.h"
#include "Main/Unknown/code_02119ac4.h"
#include "Main/Unknown/code_0211de00.h"
#include "Main/Unknown/code_0211df44.h"
#include "Main/Unknown/code_0211e0c4.h"
#include "Main/Unknown/code_0211f000.h"
#include "Main/Unknown/code_0211f2b8.h"
#include "Main/Unknown/code_0211f378.h"
#include "Main/Unknown/code_02119dfc.h"
#include "Main/Unknown/code_02127000.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0201ea58.h"
#include "code_0212df7c.h"
#include "registers.h"

#pragma thumb on
static inline s32 func_02119340_inline(Unk02175628Index i) {
    BOOL g;
    BOOL f;
    u16 v;

    g = FALSE;
    f = FALSE;
    v = data_02175674[i].mUnk_00;
    if (v == 0 && data_02175680[i].mUnk_00 < 5) {
        f = TRUE;
    }
    if (f == FALSE && data_0217567c[i].mUnk_00 == 0 && v != 0) {
        g = TRUE;
    }
    return g;
}

void AdvanceSelectCupCourseState3(void) {
    s32 a;
    Unk02175628Index i;
    s16 w;

    a = -1;
    i = UNK_02175628_INDEX_8;
    func_02119d78();
    if (func_02119340_inline(i) != 0) {
        a = RectTableFindContaining(gSelectCupCourse->mSelectCupMBnbl, data_02175670[i].mUnk_00,
                                    data_02175672[i].mUnk_00 + 0x20);
    }
    if ((u16) (data_02175628[i].mUnk_00 & PAD_KEY_B) != 0 ||
        (func_02119340_inline(i) != 0 && IsSelectReturnState2NoState3Or4RequestAndInRect(
                                             data_02175670[i].mUnk_00, data_02175672[i].mUnk_00) != FALSE)) {
        if (func_02119dfc() == 0) {
            if (*(vu16 *) 0x027ffc40 == 2) {
                SetSelectReturnSoundId(-1);
            } else {
                SetSelectReturnSoundId(0xe);
            }
            func_021199f8();
            gSelectCupCourse->mResult = 2;
            RequestSelectReturnState3WithSound(0);
        }
        return;
    }
    if ((u32) a <= 3) {
        w = data_0215caac[a];
        if (gSelectCupCourse->mIndex == w) {
            gSelectCupCourse->mUnk_54 = FALSE;
        }
        gSelectCupCourse->mIndex = w;
        func_02119ba8();
        return;
    }
    if (a == 4) {
        func_02119ba8();
        return;
    }
    if ((u16) (data_02175628[i].mUnk_00 & PAD_KEY_A) != 0) {
        func_02119ba8();
        gSelectCupCourse->mUnk_54 = FALSE;
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
        gSelectCupCourse->mIndex = gSelectCupCourse->mIndex - 1;
        if (gSelectCupCourse->mIndex < 0) {
            gSelectCupCourse->mIndex = 3;
        }
        if (*(vu16 *) 0x027ffc40 != 2) {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
        }
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
        gSelectCupCourse->mIndex = gSelectCupCourse->mIndex + 1;
        if (gSelectCupCourse->mIndex >= 4) {
            gSelectCupCourse->mIndex = 0;
        }
        if (*(vu16 *) 0x027ffc40 != 2) {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
        }
    }
}

void AdvanceSelectCupCourseState4(void) {
    func_02119d78();
    if (gSelectCupCourse->mStateFrames == 5) {
        gSelectCupCourse->mUnk_54 = TRUE;
    }
    gSelectCupCourse->mStateFrames++;
    if (gSelectCupCourse->mStateFrames >= 10) {
        if (func_02119dfc() == 0) {
            if (gSelectCupCourse->mMode == 0) {
                func_02119e14();
                if (func_0211e130() != FALSE) {
                    func_0211e0c4(0);
                    func_02119ac4();
                    return;
                }
                func_02119e50();
                gSelectCupCourse->mResult = 1;
                func_021199f8();
                return;
            }
            func_02119ac4();
        }
    }
}

void AdvanceSelectCupCourseState5(void) {
    switch (gSelectCupCourse->mMode) {
        case 0:
        case 1:
        case 3:
            if (IsSelectChoisesState1NoState0Request() != 0) {
                func_02119a90();
            }
            break;
        case 2:
            gSelectCupCourse->mStateFrames++;
            if (gSelectCupCourse->mStateFrames >= 0xf) {
                if (IsSelectChoisesState1NoState0Request() != 0 || GetSelectChoisesDone() != 0) {
                    func_02119a90();
                }
            }
            break;
    }
}

void AdvanceSelectCupCourseState6(void) {
    s32 v;

    if (GetSelectChoisesDone() != 0) {
        func_02119a38();
        if (*(vu16 *) 0x027ffc40 == 2) {
            v = GetSelectChoisesIndex();
            switch (v) {
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
}

void AdvanceSelectCupCourseState7(void) {
    s32 v;

    switch (gSelectCupCourse->mMode) {
        case 0:
        case 1:
        case 3:
            if (IsSelectChoisesState0NoState1Request() != 0) {
                v = GetSelectChoisesIndex();
                switch (v) {
                    case 0:
                        func_02119e50();
                        gSelectCupCourse->mResult = 1;
                        func_021199f8();
                        break;
                    case -1:
                    case 1:
                        RequestSelectCupCourseState3();
                        break;
                }
            }
            break;
        case 2:
            gSelectCupCourse->mStateFrames++;
            if (gSelectCupCourse->mStateFrames >= 0xf) {
                if (IsSelectChoisesState0NoState1Request() != 0) {
                    v = GetSelectChoisesIndex();
                    switch (v) {
                        case 0:
                            func_02119e50();
                            gSelectCupCourse->mResult = 1;
                            func_021199f8();
                            if (*(vu16 *) 0x027ffc40 == 2) {
                                func_0211f378();
                            }
                            break;
                        case -1:
                        case 1:
                            RequestSelectCupCourseState3();
                            break;
                    }
                }
            }
            break;
    }
}

void AdvanceSelectCupCourseState8(void) {
    BOOL a;
    s16 v;
    s32 w;
    s32 i;

    gSelectCupCourse->mStateFrames++;
    if (*(vu16 *) 0x027ffc40 == 2) {
        return;
    }
    if (gSelectCupCourse->mMode == 0) {
        if (gSelectCupCourse->mResult == 1) {
            if (func_0211e130() != FALSE) {
                a = TRUE;
            } else {
                a = FALSE;
            }
        } else {
            a = TRUE;
        }
    } else {
        a = TRUE;
    }
    InterpolateS16(1, 0, 0x100, gSelectCupCourse->mStateFrames, 10);
    v = InterpolateS16(1, 0, -0xc0, gSelectCupCourse->mStateFrames, 10);
    if (a != FALSE) {
        w = gSelectCupCourse->mSelectCupCourseTaOrVsMBncl->mUnk_06;
        gSelectCupCourse->mBg0Offset = v;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[0].mOffsetY = v;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[2].mOffsetY = v;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[1].mOffsetY = v;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[4].mOffsetY = v;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[3].mOffsetY = v;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[5].mOffsetY = v;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[w].mOffsetY = v;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[w + 1].mOffsetY = v;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[w + 2].mOffsetY = v;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[w + 3].mOffsetY = v;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[w + 4].mOffsetY = v;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[w + 5].mOffsetY = v;
    }
    if (gSelectCupCourse->mResult != 2) {
        w = gSelectCupCourse->mSelectCupMBncl->mUnk_06;
        gSelectCupCourse->mBg3Offset = v - 0x20;
        gSelectCupCourse->mSelectCupMTable[0x14].mOffsetY = v - 0x20;
        gSelectCupCourse->mSelectCupMTable[0x13].mOffsetY = v - 0x20;
        gSelectCupCourse->mSelectCupMTable[2].mOffsetY = v - 0x20;
        gSelectCupCourse->mSelectCupMTable[1].mOffsetY = v - 0x20;
        gSelectCupCourse->mSelectCupMTable[0].mOffsetY = v - 0x20;
        for (i = 0; i < 8; i++) {
            gSelectCupCourse->mSelectCupMTable[data_0215cacc[i]].mOffsetY = v - 0x20;
        }
        v -= 0x20;
        for (i = 0; i < 4; i++) {
            gSelectCupCourse->mSelectCupMTable[data_0215caa4[i]].mOffsetY = v;
            gSelectCupCourse->mSelectCupMTable[w + data_0215cab4[i]].mOffsetY = v;
        }
    }
}

s32 AdvanceSelectCupCourse(void) {
    s32 i;
    u16 *p;

    gSelectCupCourse->mState = gSelectCupCourse->mNextState;
    switch (gSelectCupCourse->mState) {
        case 0:
            AdvanceSelectCupCourseState0();
            break;
        case 1:
            AdvanceSelectCupCourseState1();
            break;
        case 2:
            AdvanceSelectCupCourseState2();
            break;
        case 3:
            AdvanceSelectCupCourseState3();
            break;
        case 4:
            AdvanceSelectCupCourseState4();
            break;
        case 5:
            AdvanceSelectCupCourseState5();
            break;
        case 6:
            AdvanceSelectCupCourseState6();
            break;
        case 7:
            AdvanceSelectCupCourseState7();
            break;
        case 8:
            AdvanceSelectCupCourseState8();
            break;
    }
    func_0211a07c();
    if (*(vu16 *) 0x027ffc40 != 2) {
        if (gSelectCupCourse->mCupPicturePending != FALSE && func_020d0ec4() != FALSE) {
            p = GetCupPictureNscrData();
            CallQueueAppend(0x1f, 0, GetCupPictureNclrData(), 0xe0);
            CallQueueAppend(0x17, 0x20, GetCupPictureNcgrData(), 0xdc0);
            for (i = 0; i < 11; i++) {
                CallQueueAppend(0x1b, ((i + 8) * 0x20 + 0x16) * 2, p + ((i + 8) * 0x20 + 0x16), 0x14);
            }
            gSelectCupCourse->mCupPicturePending = FALSE;
        }
        DrawLayoutTable(gSelectCupCourse->mSelectCupCourseTaOrVsMBncl, gSelectCupCourse->mSelectCupCourseMNcer,
                        gSelectCupCourse->mSelectCupCourseTaOrVsMBnll, gSelectCupCourse->mUnk_64,
                        gSelectCupCourse->mSelectCupCourseTaOrVsMTable);
        DrawLayoutTable(gSelectCupCourse->mSelectCupMBncl, gSelectCupCourse->mSelectCupMNcer,
                        gSelectCupCourse->mSelectCupMBnll, gSelectCupCourse->mUnk_68,
                        gSelectCupCourse->mSelectCupMTable);
    } else {
        func_0211f39c();
    }
    if (gSelectCupCourse->mState == 8 && gSelectCupCourse->mStateFrames >= 10) {
        return gSelectCupCourse->mResult;
    }
    return 0;
}

void func_02118e30(void) {
    reg_G2_BG0OFS = (-gSelectCupCourse->mBg0Offset << 16) & 0x1ff0000;
    reg_G2S_DB_BG3OFS = (-gSelectCupCourse->mBg3Offset << 16) & 0x1ff0000;
}

void func_02118d44(void) {
    Ncgr *a = NULL;
    Unk02021dc8 *b = NULL;
    Nclr *c = NULL;
    Ncgr *d = NULL;
    Unk02021dc8 *e = NULL;
    Nclr *f = NULL;
    Ncgr *g = NULL;
    Nscr *h = NULL;
    Nclr *i = NULL;

    if (*(vu16 *) 0x027ffc40 != 2) {
        LoadNcgrData(&g, FindSceneFile(data_0216d690));
        LoadNclrData(&i, FindSceneFile(data_0216d6b8));
        LoadNscrData(&h, FindSceneFile(data_0216d6bc));
        LoadNcgrData2(&a, FindSceneFile(data_0216d6ac));
        LoadNcerData(&b, FindSceneFile(data_0216d694));
        LoadNclrData(&c, FindSceneFile(data_0216d6a0));
        LoadNcgrData2(&d, FindSceneFile(data_0216d69c));
        LoadNcerData(&e, FindSceneFile(data_0216d6b4));
        LoadNclrData(&f, FindSceneFile(data_0216d68c));
        LoadSelectCupNameMData();
        LoadCommonCupMarkData();
        LoadTrophyIconData();
    }
}

void func_02118b48(void) {
    Ncgr *a = NULL;
    Nclr *b = NULL;
    Ncgr *c = NULL;
    Nclr *d = NULL;
    Ncgr *e = NULL;
    Nscr *f = NULL;
    Nclr *g = NULL;
    u16 *p;

    if (*(vu16 *) 0x027ffc40 == 2) {
        gSelectCupGrid->mSelectCupSBnbl = FindSceneFile(data_0216d6a4);
        return;
    }
    LocateNcgr(&e, FindSceneFile(data_0216d690));
    LocateNclr(&g, FindSceneFile(data_0216d6b8));
    LocateNscr(&f, FindSceneFile(data_0216d6bc));
    gSelectCupGrid->mUnk_20 = HeapAlloc(gSelectCupGrid->mHeap, 0x800);
    gSelectCupGrid->mSelectCupMBncl = FindSceneFile(data_0216d698);
    gSelectCupGrid->mSelectCupMBnll = FindSceneFile(data_0216d6a8);
    LocateNcgr2(&a, FindSceneFile(data_0216d6ac));
    LocateNcer(&gSelectCupGrid->mSelectCupMNcer, FindSceneFile(data_0216d694));
    LocateNclr(&b, FindSceneFile(data_0216d6a0));
    gSelectCupGrid->mSelectCupSBncl = FindSceneFile(data_0216d6b0);
    gSelectCupGrid->mSelectCupSBnbl = FindSceneFile(data_0216d6a4);
    LocateNcgr2(&c, FindSceneFile(data_0216d69c));
    LocateNcer(&gSelectCupGrid->mSelectCupSNcer, FindSceneFile(data_0216d6b4));
    LocateNclr(&d, FindSceneFile(data_0216d68c));
    p = b->mData;
    if (GetPreviousMenuScreenNumber() != 0x18 && GetPreviousMenuScreenNumber() != 0xc) {
        CallQueueAppend(4, 0, e->mData, e->mDataSize);
        CallQueueAppend(0xf, 0, g->mData, 0x100);
        CallQueueAppend(8, 0, &f->mData, f->mDataSize);
        CallQueueAppend(8, 0x800, gSelectCupGrid->mUnk_20, 0x800);
    }
    CallQueueAppend(0x13, 0, a->mData, a->mDataSize);
    CallQueueAppend(0xe, 0, b->mData, 0x1a0);
    CallQueueAppend(0xe, 0x1c0, p + 0xe0, 0x40);
    CallQueueAppend(0x23, 0, c->mData, c->mDataSize);
    CallQueueAppend(0x1e, 0, d->mData, d->mDataSize);
}

u32 GetSelectCupGridCupEnabled(u32 a) {
    u32 r;
    s32 i;

    r = 0;
    switch (gSelectCupGrid->mMode) {
        case 0:
        case 2:
            switch (a) {
                case 0:
                case 1:
                case 4:
                case 5:
                    r = 1;
                    break;
                default:
                    if (GetMirrorMode() != 0) {
                        r = func_02056dec(data_0215c8bc[a]);
                    } else {
                        r = func_02056dec(data_0215c95c[a][data_0215c7f0[GetEngineIndex()]]);
                    }
                    break;
            }
            break;
        case 1:
            switch (a) {
                case 0:
                case 1:
                case 4:
                case 5:
                    r = 1;
                    break;
                default:
                    r = 0;
                    for (i = 0; i < 4; i++) {
                        if (i == 3) {
                            r |= func_02056dec(data_0215c8bc[a]);
                        } else {
                            r |= func_02056dec(data_0215c95c[a][i]);
                        }
                    }
                    break;
            }
            break;
        case 3:
            if (a == 0 || a == 4) {
                r = 1;
            }
            break;
        case 4:
            switch (a) {
                case 0:
                case 1:
                case 4:
                case 5:
                    r = 1;
                    break;
                default:
                    if (GetMirrorMode() != 0) {
                        r = func_0205fbb8(data_0215c8bc[a]);
                    } else {
                        r = func_0205fbb8(data_0215c95c[a][data_0215c7f0[GetEngineIndex()]]);
                    }
                    break;
            }
            break;
    }
    return r;
}
#pragma thumb off
