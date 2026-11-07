#include "Main/Unknown/code_0211952c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_020ade08.h"

#include "Main/Unknown/code_02119544.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_02119ac4.h"
#include "Main/Unknown/code_0211f4b0.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_021196dc.h"
#include "Main/Unknown/code_02119e14.h"
#include "Main/Unknown/code_021196f4.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0211de34.h"
#include "Main/Unknown/code_0211de00.h"
#include "Main/Unknown/code_0211df44.h"
#include "Main/Unknown/code_0211e0c4.h"
#include "Main/Unknown/code_0211f000.h"
#include "Main/Unknown/code_0211f380.h"
#include "Main/Unknown/code_0211f498.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02125f88.h"
#include "Main/Unknown/code_02127000.h"
#include "Main/Unknown/code_0212775c.h"
#include "code_02148950.h"
#include "registers.h"
#include "Main/Unknown/code_02119a90.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02125ebc.h"
#include "Main/Unknown/code_02119dfc.h"
#include "Main/Unknown/code_021266e4.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020ccc74.h"

#pragma thumb on

u32 func_02119dfc(void) {
    if (gSelectCupCourse->mIndexChangeTimer != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on
void func_02119d78(void) {
    s32 w;
    s16 r;

    if (func_02119dfc() != 0) {
        if (gSelectCupCourse->mIndexChangeTimer == 7) {
            gSelectCupCourse->mShownIndex = gSelectCupCourse->mIndex;
            func_02119e88();
        } else if (*(vu16 *) 0x027ffc40 != 2) {
            w = gSelectCupCourse->mSelectCupCourseTaOrVsMBncl->mUnk_06;
            r = func_02116d10(7 - gSelectCupCourse->mIndexChangeTimer, 1);
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[w].mUnk_06 = r;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[w + 1].mUnk_06 = r;
        }
        gSelectCupCourse->mIndexChangeTimer--;
    } else if (gSelectCupCourse->mIndex != gSelectCupCourse->mShownIndex) {
        gSelectCupCourse->mIndexChangeTimer = 7;
    }
}

void func_02119c20(void) {
    s16 v;
    s32 w;
    s32 i;
    s32 u;

    gSelectCupCourse->mNextState = 0;
    gSelectCupCourse->mStateFrames = 0;
    if (*(vu16 *) 0x027ffc40 != 2) {
        if (func_020cccb4() != SCREEN_SELECT_GHOST) {
            w = gSelectCupCourse->mSelectCupCourseTaOrVsMBncl->mUnk_06;
            gSelectCupCourse->mBg0Offset = -0xc0;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[0].mUnk_06 = -0xc0;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[2].mUnk_06 = -0xc0;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[1].mUnk_06 = -0xc0;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[4].mUnk_06 = -0xc0;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[3].mUnk_06 = -0xc0;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[5].mUnk_06 = -0xc0;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[w].mUnk_06 = -0xc0;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[w + 1].mUnk_06 = -0xc0;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[w + 2].mUnk_06 = -0xc0;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[w + 3].mUnk_06 = -0xc0;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[w + 4].mUnk_06 = -0xc0;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[w + 5].mUnk_06 = -0xc0;
        }
        if (func_020cccb4() != SCREEN_SELECT_GHOST) {
            v = -0x20;
        } else {
            v = -0xe0;
        }
        u = gSelectCupCourse->mSelectCupMBncl->mUnk_06;
        gSelectCupCourse->mBg3Offset = v;
        gSelectCupCourse->mSelectCupMTable[0x14].mUnk_06 = v;
        gSelectCupCourse->mSelectCupMTable[0x13].mUnk_06 = v;
        gSelectCupCourse->mSelectCupMTable[2].mUnk_06 = v;
        gSelectCupCourse->mSelectCupMTable[1].mUnk_06 = v;
        gSelectCupCourse->mSelectCupMTable[0].mUnk_06 = v;
        for (i = 0; i < 8; i++) {
            gSelectCupCourse->mSelectCupMTable[data_0215cacc[i]].mUnk_06 = v;
        }
        for (i = 0; i < 4; i++) {
            gSelectCupCourse->mSelectCupMTable[data_0215caa4[i]].mUnk_06 = v;
            gSelectCupCourse->mSelectCupMTable[u + data_0215cab4[i]].mUnk_06 = v;
        }
    }
}

// Requests state 1: stores mNextState = 1 and zeroes mStateFrames; the next AdvanceSelectCupCourse call copies it to
// mState and runs AdvanceSelectCupCourseState1.
void RequestSelectCupCourseState1(void) {
    gSelectCupCourse->mNextState = 1;
    gSelectCupCourse->mStateFrames = 0;
}

void func_02119bf0(void) {
    gSelectCupCourse->mNextState = 2;
    gSelectCupCourse->mStateFrames = 0;
    func_02128374();
}

// Requests state 3: stores mNextState = 3 and zeroes mStateFrames; the next AdvanceSelectCupCourse call copies it to
// mState and runs AdvanceSelectCupCourseState3.
void RequestSelectCupCourseState3(void) {
    gSelectCupCourse->mNextState = 3;
    gSelectCupCourse->mStateFrames = 0;
}

void func_02119ba8(void) {
    gSelectCupCourse->mNextState = 4;
    gSelectCupCourse->mStateFrames = 0;
    if (*(vu16 *) 0x027ffc40 != 2) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
    }
}

void func_02119ac4(void) {
    u16 buf[0x100];
    SelectCupCourse *d;

    gSelectCupCourse->mNextState = 5;
    gSelectCupCourse->mStateFrames = 0;
    d = gSelectCupCourse;
    switch (d->mMode) {
        case 0:
        case 1:
        case 3:
            StartSelectChoises(GetBmgEntry(d->mCommonMessages, 4), GetBmgEntry(d->mCommonMessages, 2), 0);
            break;
        case 2:
            StartSelectChoises(GetBmgEntry(d->mCommonMessages, 4), GetBmgEntry(d->mCommonMessages, 2), 0);
            if (*(vu16 *) 0x027ffc40 == 2) {
                func_0212513c(GetBmgEntry(gSelectCupCourse->mGhostMessages,
                                          data_0215cb3c[data_0215cadc[func_0202968c()]][gSelectCupCourse->mIndex]),
                              GetBmgEntry(gSelectCupCourse->mCommonMessages, 0x8b), buf, 0x200);
                SetTxtSystemOpenSoundId(0x23);
                func_021266e4(buf);
            }
            break;
    }
}
#pragma thumb off

#pragma thumb on

void func_02119a90(void) {
    gSelectCupCourse->mNextState = 6;
    gSelectCupCourse->mStateFrames = 0;
    SetSelectChoisesSoundId(0, 7);
    SetSelectChoisesSoundId(1, 0x10);
    SetSelectChoisesSoundId(0xffffffff, 0x10);
}

#pragma thumb off

#pragma thumb on
void func_02119a38(void) {
    gSelectCupCourse->mNextState = 7;
    gSelectCupCourse->mStateFrames = 0;
    switch (gSelectCupCourse->mMode) {
        case 0:
        case 1:
        case 3:
            RequestSelectChoisesState0();
            break;
        case 2:
            RequestSelectChoisesState0();
            if (*(vu16 *) 0x027ffc40 == 2) {
                RequestTxtSystemClose();
            }
            break;
    }
}

void func_021199f8(void) {
    gSelectCupCourse->mNextState = 8;
    gSelectCupCourse->mStateFrames = 0;
    if (gSelectCupCourse->mMode == 0) {
        if (gSelectCupCourse->mResult == 1) {
            if (func_0211e130() != FALSE) {
                func_021282c8();
            }
        }
    } else {
        func_021282c8();
    }
}

void InitSelectCupCourse(void *b, void *c, void *d, s32 e) {
    void *a;
    s32 x;
    s32 i;
    u32 v;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0x9004;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x8300;
    a = CreateFrmHeapFromMaxFree(b);
    gSelectCupCourse = HeapAlloc(a, 0x70);
    gSelectCupCourse->mHeap = a;
    gSelectCupCourse->mState = 0;
    gSelectCupCourse->mIndex = data_0215cb7c[func_020296e4()];
    gSelectCupCourse->mUnk_54 = TRUE;
    gSelectCupCourse->mIndexChangeTimer = 0;
    gSelectCupCourse->mMode = e;
    gSelectCupCourse->mShownIndex = gSelectCupCourse->mIndex;
    gSelectCupCourse->mCupPicturePending = FALSE;
    gSelectCupCourse->mUnk_64 = c;
    gSelectCupCourse->mUnk_68 = d;
    gSelectCupCourse->mResult = 0;
    func_0211a3bc();
    gSelectCupCourse->mCommonMessages = func_02047a28("common.bmg");
    if (*(vu16 *) 0x027ffc40 != 2) {
        func_02124ed0(gSelectCupCourse->mHeap, gSelectCupCourse->mSelectCupCourseTaOrVsMBncl,
                      gSelectCupCourse->mSelectCupCourseTaOrVsMBnll, &gSelectCupCourse->mSelectCupCourseTaOrVsMTable);
        func_02124ed0(gSelectCupCourse->mHeap, gSelectCupCourse->mSelectCupMBncl, gSelectCupCourse->mSelectCupMBnll,
                      &gSelectCupCourse->mSelectCupMTable);
        x = 0x8000;
        x -= func_021243ac(gSelectCupCourse->mHeap, 0, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll, 0xb4, 0xd, 0,
                           gSelectCupCourse->mSelectCupCourseMNcer, gSelectCupCourse->mSelectCupCourseTaOrVsMBncl,
                           gSelectCupCourse->mSelectCupCourseTaOrVsMTable, x);
        x -= func_021243ac(gSelectCupCourse->mHeap, 1, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll, 0xb4, 0xd, 1,
                           gSelectCupCourse->mSelectCupCourseMNcer, gSelectCupCourse->mSelectCupCourseTaOrVsMBncl,
                           gSelectCupCourse->mSelectCupCourseTaOrVsMTable, x);
        x -= func_021243ac(gSelectCupCourse->mHeap, 2, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll, 0x96, 0xd, 2,
                           gSelectCupCourse->mSelectCupCourseMNcer, gSelectCupCourse->mSelectCupCourseTaOrVsMBncl,
                           gSelectCupCourse->mSelectCupCourseTaOrVsMTable, x);
        x -= func_021243ac(gSelectCupCourse->mHeap, 3, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll, 0x50, 0xd, 3,
                           gSelectCupCourse->mSelectCupCourseMNcer, gSelectCupCourse->mSelectCupCourseTaOrVsMBncl,
                           gSelectCupCourse->mSelectCupCourseTaOrVsMTable, x);
        x -= func_021243ac(gSelectCupCourse->mHeap, 4, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll, 0x96, 0xd, 4,
                           gSelectCupCourse->mSelectCupCourseMNcer, gSelectCupCourse->mSelectCupCourseTaOrVsMBncl,
                           gSelectCupCourse->mSelectCupCourseTaOrVsMTable, x);
        func_021243ac(gSelectCupCourse->mHeap, 5, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll, 0x50, 0xd, 5,
                      gSelectCupCourse->mSelectCupCourseMNcer, gSelectCupCourse->mSelectCupCourseTaOrVsMBncl,
                      gSelectCupCourse->mSelectCupCourseTaOrVsMTable, x);
        v = GX_GetSizeOfSubOBJ();
        for (i = 0; i < 4; i++) {
            v -= func_021243ac(gSelectCupCourse->mHeap, data_0215cab4[i], gSelectCupCourse->mSelectCupMBnll,
                               data_0215cabc[i], data_0215cac4[i], data_0215caa4[i], gSelectCupCourse->mSelectCupMNcer,
                               gSelectCupCourse->mSelectCupMBncl, gSelectCupCourse->mSelectCupMTable, v);
        }
        CreateSelectCupNameM(gSelectCupCourse->mHeap);
        CreateCommonCupMark(gSelectCupCourse->mHeap);
    } else {
        gSelectCupCourse->mGhostMessages = FindSceneFile("ghost.bmg");
        func_0211f4b0(gSelectCupCourse->mHeap, gSelectCupCourse->mUnk_68);
        func_0211f380();
    }
    func_0211a100();
    func_02119e88();
    func_02119c20();
    FrmHeapShrinkInParent(gSelectCupCourse->mHeap);
}

void ReleaseSelectCupCourse(void) {
    if (gSelectCupCourse->mResult == 1) {
        if (gSelectCupCourse->mMode == 0) {
            if (func_0211e130() != FALSE) {
                reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1800;
            }
        } else {
            reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1800;
        }
    }
    if (*(vu16 *) 0x027ffc40 != 2) {
        func_0211de34();
        func_0211df38();
    } else {
        func_0211f498();
    }
    HeapDestroy(gSelectCupCourse->mHeap);
    gSelectCupCourse = NULL;
}
#pragma thumb off

#pragma thumb on

void AdvanceSelectCupCourseState0(void) {
    int v1;
    v1 = AreBrightnessFadesClear();
    if (v1 != 0) {
        RequestSelectCupCourseState1();
    }
}

#pragma thumb off

#pragma thumb on
void AdvanceSelectCupCourseState1(void) {
    s16 v;
    s32 w;
    s32 i;

    gSelectCupCourse->mStateFrames++;
    if (*(vu16 *) 0x027ffc40 != 2) {
        InterpolateS16(1, 0x100, 0, gSelectCupCourse->mStateFrames, 10);
        v = InterpolateS16(1, -0xc0, 0, gSelectCupCourse->mStateFrames, 10);
        if (func_020cccb4() != SCREEN_SELECT_GHOST) {
            w = gSelectCupCourse->mSelectCupCourseTaOrVsMBncl->mUnk_06;
            gSelectCupCourse->mBg0Offset = v;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[0].mUnk_06 = v;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[2].mUnk_06 = v;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[1].mUnk_06 = v;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[4].mUnk_06 = v;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[3].mUnk_06 = v;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[5].mUnk_06 = v;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[w].mUnk_06 = v;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[w + 1].mUnk_06 = v;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[w + 2].mUnk_06 = v;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[w + 3].mUnk_06 = v;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[w + 4].mUnk_06 = v;
            gSelectCupCourse->mSelectCupCourseTaOrVsMTable[w + 5].mUnk_06 = v;
        }
        if (func_020cccb4() == SCREEN_SELECT_GHOST) {
            w = gSelectCupCourse->mSelectCupMBncl->mUnk_06;
            gSelectCupCourse->mBg3Offset = v - 0x20;
            gSelectCupCourse->mSelectCupMTable[0x14].mUnk_06 = v - 0x20;
            gSelectCupCourse->mSelectCupMTable[0x13].mUnk_06 = v - 0x20;
            gSelectCupCourse->mSelectCupMTable[2].mUnk_06 = v - 0x20;
            gSelectCupCourse->mSelectCupMTable[1].mUnk_06 = v - 0x20;
            gSelectCupCourse->mSelectCupMTable[0].mUnk_06 = v - 0x20;
            for (i = 0; i < 8; i++) {
                gSelectCupCourse->mSelectCupMTable[data_0215cacc[i]].mUnk_06 = v - 0x20;
            }
            v -= 0x20;
            for (i = 0; i < 4; i++) {
                gSelectCupCourse->mSelectCupMTable[data_0215caa4[i]].mUnk_06 = v;
                gSelectCupCourse->mSelectCupMTable[w + data_0215cab4[i]].mUnk_06 = v;
            }
        }
    }
    if (gSelectCupCourse->mStateFrames >= 10) {
        func_02119bf0();
    }
}
#pragma thumb off

#pragma thumb on

void AdvanceSelectCupCourseState2(void) {
    int v1;
    v1 = IsSelectReturnState2NoState3Or4Request();
    if (v1 != 0) {
        RequestSelectCupCourseState3();
    }
}

#pragma thumb off
