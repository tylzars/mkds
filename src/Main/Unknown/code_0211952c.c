#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_0211952c.h"

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

#pragma thumb on

u32 func_02119dfc(void) {
    if (gSelectCup->mUnk_58 != 0) {
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
        if (gSelectCup->mUnk_58 == 7) {
            gSelectCup->mUnk_5c = gSelectCup->mIndex;
            func_02119e88();
        } else if (*(vu16 *) 0x027ffc40 != 2) {
            w = gSelectCup->mSelectCupCourseTaOrVsMBncl->mUnk_06;
            r = func_02116d10(7 - gSelectCup->mUnk_58, 1);
            gSelectCup->mSelectCupCourseTaOrVsMTable[w].mUnk_06 = r;
            gSelectCup->mSelectCupCourseTaOrVsMTable[w + 1].mUnk_06 = r;
        }
        gSelectCup->mUnk_58--;
    } else if (gSelectCup->mIndex != gSelectCup->mUnk_5c) {
        gSelectCup->mUnk_58 = 7;
    }
}

void func_02119c20(void) {
    s16 v;
    s32 w;
    s32 i;
    s32 u;

    gSelectCup->mNextState = 0;
    gSelectCup->mStateFrames = 0;
    if (*(vu16 *) 0x027ffc40 != 2) {
        if (func_020cccb4() != 0x1a) {
            w = gSelectCup->mSelectCupCourseTaOrVsMBncl->mUnk_06;
            gSelectCup->mBg0Offset = -0xc0;
            gSelectCup->mSelectCupCourseTaOrVsMTable[0].mUnk_06 = -0xc0;
            gSelectCup->mSelectCupCourseTaOrVsMTable[2].mUnk_06 = -0xc0;
            gSelectCup->mSelectCupCourseTaOrVsMTable[1].mUnk_06 = -0xc0;
            gSelectCup->mSelectCupCourseTaOrVsMTable[4].mUnk_06 = -0xc0;
            gSelectCup->mSelectCupCourseTaOrVsMTable[3].mUnk_06 = -0xc0;
            gSelectCup->mSelectCupCourseTaOrVsMTable[5].mUnk_06 = -0xc0;
            gSelectCup->mSelectCupCourseTaOrVsMTable[w].mUnk_06 = -0xc0;
            gSelectCup->mSelectCupCourseTaOrVsMTable[w + 1].mUnk_06 = -0xc0;
            gSelectCup->mSelectCupCourseTaOrVsMTable[w + 2].mUnk_06 = -0xc0;
            gSelectCup->mSelectCupCourseTaOrVsMTable[w + 3].mUnk_06 = -0xc0;
            gSelectCup->mSelectCupCourseTaOrVsMTable[w + 4].mUnk_06 = -0xc0;
            gSelectCup->mSelectCupCourseTaOrVsMTable[w + 5].mUnk_06 = -0xc0;
        }
        if (func_020cccb4() != 0x1a) {
            v = -0x20;
        } else {
            v = -0xe0;
        }
        u = gSelectCup->mSelectCupMBncl->mUnk_06;
        gSelectCup->mBg3Offset = v;
        gSelectCup->mSelectCupMTable[0x14].mUnk_06 = v;
        gSelectCup->mSelectCupMTable[0x13].mUnk_06 = v;
        gSelectCup->mSelectCupMTable[2].mUnk_06 = v;
        gSelectCup->mSelectCupMTable[1].mUnk_06 = v;
        gSelectCup->mSelectCupMTable[0].mUnk_06 = v;
        for (i = 0; i < 8; i++) {
            gSelectCup->mSelectCupMTable[data_0215cacc[i]].mUnk_06 = v;
        }
        for (i = 0; i < 4; i++) {
            gSelectCup->mSelectCupMTable[data_0215caa4[i]].mUnk_06 = v;
            gSelectCup->mSelectCupMTable[u + data_0215cab4[i]].mUnk_06 = v;
        }
    }
}

// Requests state 1: stores mNextState = 1 and zeroes mStateFrames; the next AdvanceSelectCup call copies it to mState
// and runs AdvanceSelectCupState1.
void RequestSelectCupState1(void) {
    gSelectCup->mNextState = 1;
    gSelectCup->mStateFrames = 0;
}

void func_02119bf0(void) {
    gSelectCup->mNextState = 2;
    gSelectCup->mStateFrames = 0;
    func_02128374();
}

// Requests state 3: stores mNextState = 3 and zeroes mStateFrames; the next AdvanceSelectCup call copies it to mState
// and runs AdvanceSelectCupState3.
void RequestSelectCupState3(void) {
    gSelectCup->mNextState = 3;
    gSelectCup->mStateFrames = 0;
}

void func_02119ba8(void) {
    gSelectCup->mNextState = 4;
    gSelectCup->mStateFrames = 0;
    if (*(vu16 *) 0x027ffc40 != 2) {
        func_0212ecc0(&data_0217d068, 0, 5);
    }
}

void func_02119ac4(void) {
    u16 buf[0x100];
    SelectCup *d;

    gSelectCup->mNextState = 5;
    gSelectCup->mStateFrames = 0;
    d = gSelectCup;
    switch (d->mMode) {
        case 0:
        case 1:
        case 3:
            func_021277f8(GetBmgEntry(d->mCommonMessages, 4), GetBmgEntry(d->mCommonMessages, 2), 0);
            break;
        case 2:
            func_021277f8(GetBmgEntry(d->mCommonMessages, 4), GetBmgEntry(d->mCommonMessages, 2), 0);
            if (*(vu16 *) 0x027ffc40 == 2) {
                func_0212513c(GetBmgEntry(gSelectCup->mGhostMessages,
                                          data_0215cb3c[data_0215cadc[func_0202968c()]][gSelectCup->mIndex]),
                              GetBmgEntry(gSelectCup->mCommonMessages, 0x8b), buf, 0x200);
                func_02125ebc(0x23);
                func_021266e4(buf);
            }
            break;
    }
}
#pragma thumb off

#pragma thumb on

void func_02119a90(void) {
    gSelectCup->mNextState = 6;
    gSelectCup->mStateFrames = 0;
    func_0212775c(0, (u32) 7);
    func_0212775c(1, (u32) 0x10);
    func_0212775c(0xffffffff, 0x10);
}

#pragma thumb off

#pragma thumb on
void func_02119a38(void) {
    gSelectCup->mNextState = 7;
    gSelectCup->mStateFrames = 0;
    switch (gSelectCup->mMode) {
        case 0:
        case 1:
        case 3:
            func_021277e4();
            break;
        case 2:
            func_021277e4();
            if (*(vu16 *) 0x027ffc40 == 2) {
                func_02125fc0();
            }
            break;
    }
}

void func_021199f8(void) {
    gSelectCup->mNextState = 8;
    gSelectCup->mStateFrames = 0;
    if (gSelectCup->mMode == 0) {
        if (gSelectCup->mResult == 1) {
            if (func_0211e130() != FALSE) {
                func_021282c8();
            }
        }
    } else {
        func_021282c8();
    }
}

void InitSelectCup(void *b, void *c, void *d, s32 e) {
    void *a;
    s32 x;
    s32 i;
    u32 v;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0x9004;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x8300;
    a = CreateFrmHeapFromMaxFree(b);
    gSelectCup = HeapAlloc(a, 0x70);
    gSelectCup->mHeap = a;
    gSelectCup->mState = 0;
    gSelectCup->mIndex = data_0215cb7c[func_020296e4()];
    gSelectCup->mUnk_54 = TRUE;
    gSelectCup->mUnk_58 = 0;
    gSelectCup->mMode = e;
    gSelectCup->mUnk_5c = gSelectCup->mIndex;
    gSelectCup->mUnk_60 = FALSE;
    gSelectCup->mUnk_64 = c;
    gSelectCup->mUnk_68 = d;
    gSelectCup->mResult = 0;
    func_0211a3bc();
    gSelectCup->mCommonMessages = func_02047a28("common.bmg");
    if (*(vu16 *) 0x027ffc40 != 2) {
        func_02124ed0(gSelectCup->mHeap, gSelectCup->mSelectCupCourseTaOrVsMBncl,
                      gSelectCup->mSelectCupCourseTaOrVsMBnll, &gSelectCup->mSelectCupCourseTaOrVsMTable);
        func_02124ed0(gSelectCup->mHeap, gSelectCup->mSelectCupMBncl, gSelectCup->mSelectCupMBnll,
                      &gSelectCup->mSelectCupMTable);
        x = 0x8000;
        x -= func_021243ac(gSelectCup->mHeap, 0, gSelectCup->mSelectCupCourseTaOrVsMBnll, 0xb4, 0xd, 0,
                           gSelectCup->mSelectCupCourseMNcer, gSelectCup->mSelectCupCourseTaOrVsMBncl,
                           gSelectCup->mSelectCupCourseTaOrVsMTable, x);
        x -= func_021243ac(gSelectCup->mHeap, 1, gSelectCup->mSelectCupCourseTaOrVsMBnll, 0xb4, 0xd, 1,
                           gSelectCup->mSelectCupCourseMNcer, gSelectCup->mSelectCupCourseTaOrVsMBncl,
                           gSelectCup->mSelectCupCourseTaOrVsMTable, x);
        x -= func_021243ac(gSelectCup->mHeap, 2, gSelectCup->mSelectCupCourseTaOrVsMBnll, 0x96, 0xd, 2,
                           gSelectCup->mSelectCupCourseMNcer, gSelectCup->mSelectCupCourseTaOrVsMBncl,
                           gSelectCup->mSelectCupCourseTaOrVsMTable, x);
        x -= func_021243ac(gSelectCup->mHeap, 3, gSelectCup->mSelectCupCourseTaOrVsMBnll, 0x50, 0xd, 3,
                           gSelectCup->mSelectCupCourseMNcer, gSelectCup->mSelectCupCourseTaOrVsMBncl,
                           gSelectCup->mSelectCupCourseTaOrVsMTable, x);
        x -= func_021243ac(gSelectCup->mHeap, 4, gSelectCup->mSelectCupCourseTaOrVsMBnll, 0x96, 0xd, 4,
                           gSelectCup->mSelectCupCourseMNcer, gSelectCup->mSelectCupCourseTaOrVsMBncl,
                           gSelectCup->mSelectCupCourseTaOrVsMTable, x);
        func_021243ac(gSelectCup->mHeap, 5, gSelectCup->mSelectCupCourseTaOrVsMBnll, 0x50, 0xd, 5,
                      gSelectCup->mSelectCupCourseMNcer, gSelectCup->mSelectCupCourseTaOrVsMBncl,
                      gSelectCup->mSelectCupCourseTaOrVsMTable, x);
        v = func_02148ca0();
        for (i = 0; i < 4; i++) {
            v -= func_021243ac(gSelectCup->mHeap, data_0215cab4[i], gSelectCup->mSelectCupMBnll, data_0215cabc[i],
                               data_0215cac4[i], data_0215caa4[i], gSelectCup->mSelectCupMNcer,
                               gSelectCup->mSelectCupMBncl, gSelectCup->mSelectCupMTable, v);
        }
        func_0211de40(gSelectCup->mHeap);
        func_0211df44(gSelectCup->mHeap);
    } else {
        gSelectCup->mGhostMessages = FindSceneFile("ghost.bmg");
        func_0211f4b0(gSelectCup->mHeap, gSelectCup->mUnk_68);
        func_0211f380();
    }
    func_0211a100();
    func_02119e88();
    func_02119c20();
    FrmHeapShrinkInParent(gSelectCup->mHeap);
}

void ReleaseSelectCup(void) {
    if (gSelectCup->mResult == 1) {
        if (gSelectCup->mMode == 0) {
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
    HeapDestroy(gSelectCup->mHeap);
    gSelectCup = NULL;
}
#pragma thumb off

#pragma thumb on

void AdvanceSelectCupState0(void) {
    int v1;
    v1 = func_02036c5c();
    if (v1 != 0) {
        RequestSelectCupState1();
    }
}

#pragma thumb off

#pragma thumb on
void AdvanceSelectCupState1(void) {
    s16 v;
    s32 w;
    s32 i;

    gSelectCup->mStateFrames++;
    if (*(vu16 *) 0x027ffc40 != 2) {
        func_020ae4c0(1, 0x100, 0, gSelectCup->mStateFrames, 10);
        v = func_020ae4c0(1, -0xc0, 0, gSelectCup->mStateFrames, 10);
        if (func_020cccb4() != 0x1a) {
            w = gSelectCup->mSelectCupCourseTaOrVsMBncl->mUnk_06;
            gSelectCup->mBg0Offset = v;
            gSelectCup->mSelectCupCourseTaOrVsMTable[0].mUnk_06 = v;
            gSelectCup->mSelectCupCourseTaOrVsMTable[2].mUnk_06 = v;
            gSelectCup->mSelectCupCourseTaOrVsMTable[1].mUnk_06 = v;
            gSelectCup->mSelectCupCourseTaOrVsMTable[4].mUnk_06 = v;
            gSelectCup->mSelectCupCourseTaOrVsMTable[3].mUnk_06 = v;
            gSelectCup->mSelectCupCourseTaOrVsMTable[5].mUnk_06 = v;
            gSelectCup->mSelectCupCourseTaOrVsMTable[w].mUnk_06 = v;
            gSelectCup->mSelectCupCourseTaOrVsMTable[w + 1].mUnk_06 = v;
            gSelectCup->mSelectCupCourseTaOrVsMTable[w + 2].mUnk_06 = v;
            gSelectCup->mSelectCupCourseTaOrVsMTable[w + 3].mUnk_06 = v;
            gSelectCup->mSelectCupCourseTaOrVsMTable[w + 4].mUnk_06 = v;
            gSelectCup->mSelectCupCourseTaOrVsMTable[w + 5].mUnk_06 = v;
        }
        if (func_020cccb4() == 0x1a) {
            w = gSelectCup->mSelectCupMBncl->mUnk_06;
            gSelectCup->mBg3Offset = v - 0x20;
            gSelectCup->mSelectCupMTable[0x14].mUnk_06 = v - 0x20;
            gSelectCup->mSelectCupMTable[0x13].mUnk_06 = v - 0x20;
            gSelectCup->mSelectCupMTable[2].mUnk_06 = v - 0x20;
            gSelectCup->mSelectCupMTable[1].mUnk_06 = v - 0x20;
            gSelectCup->mSelectCupMTable[0].mUnk_06 = v - 0x20;
            for (i = 0; i < 8; i++) {
                gSelectCup->mSelectCupMTable[data_0215cacc[i]].mUnk_06 = v - 0x20;
            }
            v -= 0x20;
            for (i = 0; i < 4; i++) {
                gSelectCup->mSelectCupMTable[data_0215caa4[i]].mUnk_06 = v;
                gSelectCup->mSelectCupMTable[w + data_0215cab4[i]].mUnk_06 = v;
            }
        }
    }
    if (gSelectCup->mStateFrames >= 10) {
        func_02119bf0();
    }
}
#pragma thumb off

#pragma thumb on

void AdvanceSelectCupState2(void) {
    int v1;
    v1 = IsSelectReturnState2NoState3Or4Request();
    if (v1 != 0) {
        RequestSelectCupState3();
    }
}

#pragma thumb off
