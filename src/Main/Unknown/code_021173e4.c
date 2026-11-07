#include "Main/Unknown/code_021173e4.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020d0e3c.h"
#include "Main/Unknown/code_02117418.h"
#include "Main/Unknown/code_0211f000.h"
#include "Main/Unknown/code_0211f2ac.h"
#include "Main/Unknown/code_0211f394.h"
#include "Main/Unknown/code_0211f4b0.h"
#include "Main/Unknown/code_02127000.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_0211f378.h"
#include "Main/Unknown/code_020d0000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02117814.h"
#include "Main/Unknown/code_021177a4.h"
#include "Main/Unknown/code_02117be0.h"
#include "Main/Unknown/code_02117d98.h"
#include "Main/Unknown/code_02117bf8.h"
#include "Main/Unknown/code_021177c0.h"
#include "Main/Unknown/code_0211784c.h"
#include "Main/Unknown/code_02118148.h"
#include "Main/Unknown/code_02117db0.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/unk_0215c000.h"
#include "00/code_02181f98.h"
#include "code_02016468.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02118000.h"
#include "Main/Unknown/code_02117000.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_02118088.h"
#include "Main/Unknown/unk_02175628.h"
#include "code_0201ea58.h"
#include "Main/Unknown/code_021185d4.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_0211de34.h"
#include "Main/Unknown/code_0211de00.h"
#include "Main/Unknown/code_0211df44.h"
#include "Main/Unknown/code_0211f2b8.h"
#include "Main/Unknown/code_0211f380.h"
#include "Main/Unknown/code_0211f498.h"
#include "Main/Unknown/code_021189f4.h"
#include "Main/Unknown/code_021281fc.h"
#include "Main/Unknown/unk_02175000.h"
#include "registers.h"
#include "Main/Unknown/code_02118054.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02118114.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02060004.h"
#include "Main/Unknown/code_020d0efc.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_0211f240.h"

#pragma thumb on

void func_021189cc(void) {
    int v1;
    u32 v3;
    v1 = 0;
    do {
        v3 = GetSelectCupGridCupEnabled(v1);
        gSelectCupGrid->mCupsEnabled[v1] = v3;
        v1 = v1 + 1;
    } while (v1 < 8);
}

#pragma thumb off

#pragma thumb on
void func_021188dc(void) {
    s32 k;
    s32 i;
    u16 v;
    u16 *q;
    SelectCupGrid *p;

    if (*(vu16 *) 0x027ffc40 != 2) {
        v = gSelectCupGrid->mSelectCupMBncl->mUnk_06;
        for (i = 0; i < 4; i++) {
            gSelectCupGrid->mSelectCupMTable[data_0215c7d0[i]].mUnk_00 = 0;
            gSelectCupGrid->mSelectCupMTable[v + data_0215c7d8[i]].mUnk_00 = 1;
        }
        for (i = 0; i < 8; i++) {
            for (k = 0, q = data_0215c9bc[i]; k < 6; k++) {
                gSelectCupGrid->mSelectCupSTable[q[k]].mUnk_00 = 0;
            }
        }
        gSelectCupGrid->mSelectCupMTable[0x14].mUnk_00 = 1;
        gSelectCupGrid->mSelectCupMTable[0x13].mUnk_00 = 1;
        gSelectCupGrid->mSelectCupSTable[2].mUnk_00 = 1;
        gSelectCupGrid->mSelectCupSTable[3].mUnk_00 = 1;
        for (i = 0; i < 8; i++) {
            gSelectCupGrid->mSelectCupSTable[data_0215c9bc[i][0]].mUnk_00 = 1;
        }
        for (i = 0; i < 8; i++) {
            p = gSelectCupGrid;
            QueueCupMark(i, p->mSelectCupSNcer, p->mSelectCupSBncl, data_0215c9bc[i][4],
                         func_02124a68(data_0215c9bc[i][4], p->mSelectCupSNcer, p->mSelectCupSBncl), 1);
        }
    }
}

void func_02118814(void) {
    s32 i;
    BOOL z;

    if (*(vu16 *) 0x027ffc40 != 2) {
        z = FALSE;
        for (i = 0; i < 8; i++) {
            u16 *q = data_0215c9bc[i];
            gSelectCupGrid->mSelectCupSTable[q[1]].mUnk_00 = 0;
            gSelectCupGrid->mSelectCupSTable[q[2]].mUnk_00 = 0;
            gSelectCupGrid->mSelectCupSTable[q[3]].mUnk_00 = 0;
            gSelectCupGrid->mSelectCupSTable[q[4]].mUnk_00 = 0;
            gSelectCupGrid->mSelectCupSTable[q[5]].mUnk_00 = 0;
            if (gSelectCupGrid->mCupsEnabled[i] == 0) {
                gSelectCupGrid->mSelectCupSTable[q[3]].mUnk_00 = 1;
                gSelectCupGrid->mSelectCupSTable[q[5]].mUnk_00 = 1;
            } else {
                if (gSelectCupGrid->mIndex == i && gSelectCupGrid->mUnk_68 != FALSE) {
                    gSelectCupGrid->mSelectCupSTable[q[2]].mUnk_00 = 1;
                } else {
                    gSelectCupGrid->mSelectCupSTable[q[1]].mUnk_00 = 1;
                }
                gSelectCupGrid->mSelectCupSTable[q[4]].mUnk_00 = 1;
            }
            if (gSelectCupGrid->mMode == 3) {
                gSelectCupGrid->mSelectCupSTable[q[5]].mUnk_00 = z;
            }
        }
    }
}

void RequestSelectCupGridCupPicture(void) {
    if (*(vu16 *) 0x027ffc40 != 2) {
        TrySetCupPictureIndexAndQueueLoads(data_0215ca1c[gSelectCupGrid->mIndex][gSelectCupGrid->mShownCourseIndex]);
        gSelectCupGrid->mCupPicturePending = TRUE;
    }
}

void SetupSelectCupGridIndex(void) {
    u32 a;
    s32 b;
    s32 c;
    s32 i;
    u16 *q;
    s32 j;
    SelectCupGrid *p;
    u32 v;

    a = 0;
    if (*(vu16 *) 0x027ffc40 == 2) {
        return;
    }
    QueueSelectCupNameM(gSelectCupGrid->mIndex, gSelectCupGrid->mSelectCupMNcer, gSelectCupGrid->mSelectCupMBncl, 0x13,
                        a);
    j = 0;
    for (i = 0; i < 4; i++) {
        p = gSelectCupGrid;
        func_0212426c(j, data_0215c7d8[i], gSelectCupGrid->mSelectCupMBnll,
                      GetBmgEntry(p->mCommonMessages, data_0215c91c[p->mIndex][i]), p->mSelectCupMBncl,
                      p->mSelectCupMTable);
    }
    for (j = 0, q = data_0215c83c; j < 8; q++, j++) {
        gSelectCupGrid->mSelectCupMTable[*q].mUnk_00 = 0;
    }
    for (i = 0; i < 4; i++) {
        gSelectCupGrid->mSelectCupMTable[data_0215c7c8[i]].mUnk_00 = 0;
    }
    if (gSelectCupGrid->mMode == 0) {
        if (func_0202967c() != 0) {
            v = 3;
        } else {
            v = data_0215c7f0[GetEngineIndex()];
        }
        b = data_0215c81c[v];
        if (func_02060440(data_0215c85c[gSelectCupGrid->mIndex], b) != 0) {
            c = func_02060364(data_0215c85c[gSelectCupGrid->mIndex], b);
            gSelectCupGrid->mSelectCupMTable[data_0215c83c[data_0215c87c[c]]].mUnk_00 = 1;
            switch (c) {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                    a = data_0215c7c8[0];
                    break;
                case 5:
                    a = data_0215c7c8[1];
                    break;
                case 6:
                    a = data_0215c7c8[2];
                    break;
                case 7:
                    a = data_0215c7c8[3];
                    break;
            }
            gSelectCupGrid->mSelectCupMTable[a].mUnk_00 = 1;
            c = func_020603bc(data_0215c85c[gSelectCupGrid->mIndex], b);
            p = gSelectCupGrid;
            QueueTrophyIcon(data_0215c85c[p->mIndex], c, p->mSelectCupMNcer, p->mSelectCupMBncl, a, 4, 0);
        }
    }
    RequestSelectCupGridCupPicture();
}

void func_021185ec(void) {
    SetCupIndex(data_0215c85c[gSelectCupGrid->mIndex]);
    SetCourseId(data_0215c89c[gSelectCupGrid->mIndex]);
}
#pragma thumb off

#pragma thumb on

u32 IsSelectCupGridIndexChangeRunning(void) {
    if (gSelectCupGrid->mIndexChangeTimer != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridIndexChange(void) {
    u16 v;
    s16 b;
    int i;

    if (IsSelectCupGridIndexChangeRunning() != 0) {
        if (gSelectCupGrid->mIndexChangeTimer == 7) {
            gSelectCupGrid->mShownIndex = gSelectCupGrid->mIndex;
            SetupSelectCupGridIndex();
        } else if (*(vu16 *) 0x027ffc40 != 2) {
            v = gSelectCupGrid->mSelectCupMBncl->mUnk_06;
            b = func_02116d10(7 - gSelectCupGrid->mIndexChangeTimer, 1);
            gSelectCupGrid->mBg0Offset = b;
            gSelectCupGrid->mSelectCupMTable[19].mUnk_06 = b;
            gSelectCupGrid->mSelectCupMTable[2].mUnk_06 = b;
            gSelectCupGrid->mSelectCupMTable[1].mUnk_06 = b;
            gSelectCupGrid->mSelectCupMTable[0].mUnk_06 = b;
            for (i = 0; i < 8; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c83c[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c7c8[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c7d0[i]].mUnk_06 = b;
                gSelectCupGrid->mSelectCupMTable[v + data_0215c7d8[i]].mUnk_06 = b;
            }
        }
        gSelectCupGrid->mIndexChangeTimer = gSelectCupGrid->mIndexChangeTimer - 1;
    } else if (gSelectCupGrid->mIndex != gSelectCupGrid->mShownIndex) {
        gSelectCupGrid->mIndexChangeTimer = 7;
    }
}

void func_02118458(void) {
    int i;

    if (*(vu16 *) 0x027ffc40 != 2) {
        for (i = 0; i < 4; i++) {
            if (gSelectCupGrid->mShownCourseIndex == i) {
                gSelectCupGrid->mSelectCupMTable[data_0215c7d0[i]].mUnk_00 = 1;
                func_02124100(data_0215c7d8[i], 0xe, gSelectCupGrid->mSelectCupMBnll, gSelectCupGrid->mSelectCupMTable,
                              gSelectCupGrid->mSelectCupMBncl);
            } else {
                gSelectCupGrid->mSelectCupMTable[data_0215c7d0[i]].mUnk_00 = 0;
                func_02124100(data_0215c7d8[i], 0xf, gSelectCupGrid->mSelectCupMBnll, gSelectCupGrid->mSelectCupMTable,
                              gSelectCupGrid->mSelectCupMBncl);
            }
        }
    }
}

void AdvanceSelectCupGridShownCourse(void) {
    gSelectCupGrid->mShownCourseFrames = gSelectCupGrid->mShownCourseFrames + 1;
    if (gSelectCupGrid->mShownCourseFrames >= 0x4b) {
        gSelectCupGrid->mShownCourseIndex = gSelectCupGrid->mShownCourseIndex + 1;
        if (gSelectCupGrid->mShownCourseIndex >= 4) {
            gSelectCupGrid->mShownCourseIndex = 0;
        }
        gSelectCupGrid->mShownCourseFrames = 0;
        RequestSelectCupGridCupPicture();
    }
}

void ResetSelectCupGridShownCourse(void) {
    gSelectCupGrid->mShownCourseIndex = 0;
    gSelectCupGrid->mShownCourseFrames = 0;
}

void func_021181fc(void) {
    u16 v;
    s32 b;
    s32 c;
    int i;
    int j;

    gSelectCupGrid->mNextState = 0;
    gSelectCupGrid->mStateFrames = 0;
    if (*(vu16 *) 0x027ffc40 != 2) {
        v = gSelectCupGrid->mSelectCupMBncl->mUnk_06;
        if (func_020cccb4() == 0x18 || func_020cccb4() == 0xc) {
            b = 0;
            gSelectCupGrid->mBg0Offset = b;
            gSelectCupGrid->mSelectCupMTable[20].mUnk_06 = b;
            gSelectCupGrid->mSelectCupMTable[19].mUnk_06 = b;
            gSelectCupGrid->mSelectCupMTable[2].mUnk_06 = b;
            gSelectCupGrid->mSelectCupMTable[1].mUnk_06 = b;
            gSelectCupGrid->mSelectCupMTable[0].mUnk_06 = b;
            for (i = 0; i < 8; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c83c[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c7c8[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c7d0[i]].mUnk_06 = b;
                gSelectCupGrid->mSelectCupMTable[v + data_0215c7d8[i]].mUnk_06 = b;
            }
        } else {
            b = -192;
            gSelectCupGrid->mBg0Offset = b;
            gSelectCupGrid->mSelectCupMTable[20].mUnk_06 = b;
            gSelectCupGrid->mSelectCupMTable[19].mUnk_06 = b;
            gSelectCupGrid->mSelectCupMTable[2].mUnk_06 = b;
            gSelectCupGrid->mSelectCupMTable[1].mUnk_06 = b;
            gSelectCupGrid->mSelectCupMTable[0].mUnk_06 = b;
            for (i = 0; i < 8; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c83c[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c7c8[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c7d0[i]].mUnk_06 = b;
                gSelectCupGrid->mSelectCupMTable[v + data_0215c7d8[i]].mUnk_06 = b;
            }
        }
        b = -192;
        gSelectCupGrid->mSelectCupMTable[20].mUnk_06 = b;
        c = -224;
        gSelectCupGrid->mSelectCupSTable[0].mUnk_04 = c;
        gSelectCupGrid->mSelectCupSTable[1].mUnk_04 = 0xe0;
        gSelectCupGrid->mSelectCupSTable[2].mUnk_04 = c;
        gSelectCupGrid->mSelectCupSTable[3].mUnk_04 = 0xe0;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 6; j++) {
                gSelectCupGrid->mSelectCupSTable[data_0215c9bc[i][j]].mUnk_04 = c;
            }
        }
        for (i = 4; i < 8; i++) {
            for (j = 0; j < 6; j++) {
                gSelectCupGrid->mSelectCupSTable[data_0215c9bc[i][j]].mUnk_04 = 0xe0;
            }
        }
    }
}

void RequestSelectCupGridState1(void) {
    gSelectCupGrid->mNextState = 1;
    gSelectCupGrid->mStateFrames = 0;
}

void func_021181cc(void) {
    gSelectCupGrid->mNextState = 2;
    gSelectCupGrid->mStateFrames = 0;
    RequestSelectReturnState1();
}

void RequestSelectCupGridState3(void) {
    gSelectCupGrid->mNextState = 3;
    gSelectCupGrid->mStateFrames = 0;
}

void func_02118184(void) {
    gSelectCupGrid->mNextState = 4;
    gSelectCupGrid->mStateFrames = 0;
    if (*(vu16 *) 0x027ffc40 != 2) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
    }
}

void func_02118148(void) {
    void *a;

    gSelectCupGrid->mNextState = 5;
    gSelectCupGrid->mStateFrames = 0;
    a = GetBmgEntry(gSelectCupGrid->mCommonMessages, 4);
    StartSelectChoises(a, GetBmgEntry(gSelectCupGrid->mCommonMessages, 2), 0);
}

#pragma thumb off

#pragma thumb on

void func_02118114(void) {
    gSelectCupGrid->mNextState = 6;
    gSelectCupGrid->mStateFrames = 0;
    SetSelectChoisesSoundId(0, 7);
    SetSelectChoisesSoundId(1, 0x10);
    SetSelectChoisesSoundId(0xffffffff, 0x10);
}

#pragma thumb off

#pragma thumb on

void func_021180f8(void) {
    gSelectCupGrid->mNextState = 7;
    gSelectCupGrid->mStateFrames = 0;
    RequestSelectChoisesState0();
}

void func_02118088(void) {
    void *a;

    gSelectCupGrid->mNextState = 8;
    gSelectCupGrid->mStateFrames = 0;
    if (*(vu16 *) 0x027ffc40 == 2) {
        a = GetBmgEntry(gSelectCupGrid->mCommonMessages, 0x5d);
        StartSelectChoises(a, GetBmgEntry(gSelectCupGrid->mCommonMessages, 0x5f), 0);
    } else {
        a = GetBmgEntry(gSelectCupGrid->mMenuMessages, 0x14);
        StartSelectChoises(a, GetBmgEntry(gSelectCupGrid->mMenuMessages, 0x15), 0);
    }
}

#pragma thumb off

#pragma thumb on

void func_02118054(void) {
    gSelectCupGrid->mNextState = 9;
    gSelectCupGrid->mStateFrames = 0;
    SetSelectChoisesSoundId(0, 5);
    SetSelectChoisesSoundId(1, 0xf);
    SetSelectChoisesSoundId(0xffffffff, 0x10);
}

#pragma thumb off

#pragma thumb on

void func_02118038(void) {
    gSelectCupGrid->mNextState = 0xa;
    gSelectCupGrid->mStateFrames = 0;
    RequestSelectChoisesState0();
}

void RequestSelectCupGridState11(void) {
    gSelectCupGrid->mNextState = 0xb;
    gSelectCupGrid->mStateFrames = 0;
}

void InitSelectCupGrid(void *a, void *b, void *c, s32 d) {
    s32 rem;
    int i;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0x9004;
    if (func_020cccb4() != 0x18 && func_020cccb4() != 0xc) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1800;
    }
    a = CreateFrmHeapFromMaxFree(a);
    gSelectCupGrid = HeapAlloc(a, 0x8c);
    gSelectCupGrid->mHeap = a;
    gSelectCupGrid->mState = 0;
    gSelectCupGrid->mIndex = data_0215c8fc[GetCupIndex()];
    gSelectCupGrid->mUnk_68 = TRUE;
    gSelectCupGrid->mIndexChangeTimer = 0;
    gSelectCupGrid->mMode = d;
    gSelectCupGrid->mShownIndex = gSelectCupGrid->mIndex;
    gSelectCupGrid->mCupPicturePending = FALSE;
    gSelectCupGrid->mUnk_80 = b;
    gSelectCupGrid->mUnk_84 = c;
    gSelectCupGrid->mResult = 0;
    ResetSelectCupGridShownCourse();
    func_021189cc();
    func_02118b48();
    if (func_020cccb4() != 0x18 && func_020cccb4() != 0xc) {
        func_020ae6d4(gSelectCupGrid->mUnk_80, gSelectCupGrid->mUnk_84);
    }
    gSelectCupGrid->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    if (*(vu16 *) 0x027ffc40 != 2) {
        gSelectCupGrid->mMenuMessages = FindSceneFile("menu.bmg");
        func_02124ed0(gSelectCupGrid->mHeap, gSelectCupGrid->mSelectCupMBncl, gSelectCupGrid->mSelectCupMBnll,
                      &gSelectCupGrid->mSelectCupMTable);
        func_02124ed0(gSelectCupGrid->mHeap, gSelectCupGrid->mSelectCupSBncl, NULL, &gSelectCupGrid->mSelectCupSTable);
        rem = 0x8000;
        for (i = 0; i < 4; i++) {
            rem -= func_021243ac(gSelectCupGrid->mHeap, data_0215c7d8[i], gSelectCupGrid->mSelectCupMBnll,
                                 data_0215c7e0[i], data_0215c7e8[i], data_0215c7d0[i], gSelectCupGrid->mSelectCupMNcer,
                                 gSelectCupGrid->mSelectCupMBncl, gSelectCupGrid->mSelectCupMTable, rem);
        }
        CreateSelectCupNameM(gSelectCupGrid->mHeap);
        CreateCommonCupMark(gSelectCupGrid->mHeap);
        CreateTrophyIcon(gSelectCupGrid->mHeap);
    } else {
        func_0211f4b0(gSelectCupGrid->mHeap, gSelectCupGrid->mUnk_84);
        if (func_020cccb4() != 0xc) {
            func_0211f394();
        } else {
            func_0211f380();
        }
    }
    func_021188dc();
    SetupSelectCupGridIndex();
    func_021181fc();
    FrmHeapShrinkInParent(gSelectCupGrid->mHeap);
    if (data_021759d0->mUnk_20 == 2) {
        ClearSelectReturnDisplayBitOn();
    }
}

void ReleaseSelectCupGrid(void) {
    if ((gSelectCupGrid->mMode == 0 && gSelectCupGrid->mResult == 1) || gSelectCupGrid->mResult == 2) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1800;
    }
    if (*(vu16 *) 0x027ffc40 != 2) {
        func_0211de34();
        func_0211df38();
        func_0211f2ac();
    } else {
        func_0211f498();
    }
    HeapDestroy(gSelectCupGrid->mHeap);
    gSelectCupGrid = NULL;
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridState0(void) {
    int v1;
    v1 = AreBrightnessFadesClear();
    if (v1 != 0) {
        RequestSelectCupGridState1();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridState1(void) {
    u16 v;
    s16 a;
    s16 b;
    s16 c;
    int i;
    int j;

    gSelectCupGrid->mStateFrames = gSelectCupGrid->mStateFrames + 1;
    if (*(vu16 *) 0x027ffc40 != 2) {
        v = gSelectCupGrid->mSelectCupMBncl->mUnk_06;
        a = InterpolateS16(1, 0xe0, 0, gSelectCupGrid->mStateFrames, 0xa);
        b = InterpolateS16(1, -192, 0, gSelectCupGrid->mStateFrames, 0xa);
        if (func_020cccb4() != 0x18 && func_020cccb4() != 0xc) {
            gSelectCupGrid->mBg0Offset = b;
            gSelectCupGrid->mSelectCupMTable[19].mUnk_06 = b;
            gSelectCupGrid->mSelectCupMTable[2].mUnk_06 = b;
            gSelectCupGrid->mSelectCupMTable[1].mUnk_06 = b;
            gSelectCupGrid->mSelectCupMTable[0].mUnk_06 = b;
            for (i = 0; i < 8; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c83c[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c7c8[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c7d0[i]].mUnk_06 = b;
                gSelectCupGrid->mSelectCupMTable[v + data_0215c7d8[i]].mUnk_06 = b;
            }
        }
        gSelectCupGrid->mSelectCupMTable[20].mUnk_06 = b;
        c = -a;
        gSelectCupGrid->mSelectCupSTable[0].mUnk_04 = c;
        gSelectCupGrid->mSelectCupSTable[1].mUnk_04 = a;
        gSelectCupGrid->mSelectCupSTable[2].mUnk_04 = c;
        gSelectCupGrid->mSelectCupSTable[3].mUnk_04 = a;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 6; j++) {
                gSelectCupGrid->mSelectCupSTable[data_0215c9bc[i][j]].mUnk_04 = -a;
            }
        }
        for (i = 4; i < 8; i++) {
            for (j = 0; j < 6; j++) {
                gSelectCupGrid->mSelectCupSTable[data_0215c9bc[i][j]].mUnk_04 = a;
            }
        }
    }
    if (gSelectCupGrid->mStateFrames >= 0xa) {
        func_021181cc();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridState2(void) {
    int v1;
    v1 = IsSelectReturnState2NoState3Or4Request();
    if (v1 != 0) {
        RequestSelectCupGridState3();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridState3(void) {
    Unk02175628Index n;
    s32 s;
    s32 t;
    s32 d;
    int b;
    int a;
    u16 x;
    Unk02175628 *p;
    Unk02175628 *q;

    s = -1;
    n = UNK_02175628_INDEX_8;
    AdvanceSelectCupGridIndexChange();
    AdvanceSelectCupGridShownCourse();
    b = 0;
    a = 0;
    p = &data_02175674[n];
    x = data_02175674[n].mUnk_00;
    if (x == 0 && data_02175680[n].mUnk_00 < 5) {
        a = 1;
    }
    if (a == 0 && data_0217567c[n].mUnk_00 == 0 && x != 0) {
        b = 1;
    }
    if (b != 0) {
        s = RectTableFindContaining(gSelectCupGrid->mSelectCupSBnbl, data_02175670[n].mUnk_00,
                                    data_02175672[n].mUnk_00);
    }
    q = &data_02175628[n];
    if ((u16) (data_02175628[n].mUnk_00 & 2) != 0) {
        goto L1;
    }
    b = 0;
    a = 0;
    x = p->mUnk_00;
    if (x == 0 && data_02175680[n].mUnk_00 < 5) {
        a = 1;
    }
    if (a == 0 && data_0217567c[n].mUnk_00 == 0 && x != 0) {
        b = 1;
    }
    if (b == 0) {
        goto L2;
    }
    if (IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175670[n].mUnk_00, data_02175672[n].mUnk_00) == FALSE) {
        goto L2;
    }
L1:
    if (IsSelectCupGridIndexChangeRunning() != 0) {
        return;
    }
    SetSelectReturnSoundId(0xe);
    switch (gSelectCupGrid->mMode) {
        case 0:
        case 1:
            RequestSelectCupGridState11();
            gSelectCupGrid->mResult = 2;
            RequestSelectReturnState3WithSound(0);
            return;
        case 2:
        case 3:
        case 4:
            if (data_0217b488->mUnk_08 == 2 || data_0217b488->mUnk_08 == 3) {
                func_02118088();
                if (*(vu16 *) 0x027ffc40 == 2) {
                    SetSelectReturnSoundId(-1);
                }
                RequestSelectReturnState3WithSound(0);
                return;
            }
            RequestSelectCupGridState11();
            gSelectCupGrid->mResult = 2;
            if (gSelectCupGrid->mMode != 2) {
                RequestSelectReturnState3WithSound(1);
                if (*(vu16 *) 0x027ffc40 == 2) {
                    func_0211f378();
                }
            } else {
                RequestSelectReturnState3WithSound(0);
            }
            return;
    }
    return;
L2:
    if ((u32) s <= 7) {
        d = data_0215c8dc[s];
        if (gSelectCupGrid->mCupsEnabled[d] == 0) {
            if (*(vu16 *) 0x027ffc40 != 2) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x16);
            }
            return;
        }
        if (gSelectCupGrid->mIndex == d) {
            gSelectCupGrid->mUnk_68 = FALSE;
        }
        gSelectCupGrid->mIndex = d;
        func_02118184();
        return;
    }
    if ((u16) (q->mUnk_00 & 1) != 0) {
        func_02118184();
        gSelectCupGrid->mUnk_68 = FALSE;
        return;
    }
    if (GetNewOrRepeatBits(8, 0x40) != 0) {
        a = gSelectCupGrid->mIndex;
        b = data_0215c84c[a];
        if (b != 0) {
            t = a + b;
            if (gSelectCupGrid->mCupsEnabled[t] != 0) {
                gSelectCupGrid->mIndex = t;
                ResetSelectCupGridShownCourse();
                if (*(vu16 *) 0x027ffc40 != 2) {
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
                }
            }
        }
    } else if (GetNewOrRepeatBits(8, 0x80) != 0) {
        a = gSelectCupGrid->mIndex;
        b = data_0215c7fc[a];
        if (b != 0) {
            t = a + b;
            if (gSelectCupGrid->mCupsEnabled[t] != 0) {
                gSelectCupGrid->mIndex = t;
                ResetSelectCupGridShownCourse();
                if (*(vu16 *) 0x027ffc40 != 2) {
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
                }
            }
        }
    } else if (GetNewOrRepeatBits(8, 0x20) != 0) {
        a = gSelectCupGrid->mIndex;
        b = data_0215c80c[a];
        if (b != 0) {
            t = a + b;
            if (gSelectCupGrid->mCupsEnabled[t] != 0) {
                gSelectCupGrid->mIndex = t;
                ResetSelectCupGridShownCourse();
                if (*(vu16 *) 0x027ffc40 != 2) {
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
                }
            }
        }
    } else if (GetNewOrRepeatBits(8, 0x10) != 0) {
        a = gSelectCupGrid->mIndex;
        b = data_0215c82c[a];
        if (b != 0) {
            t = a + b;
            if (gSelectCupGrid->mCupsEnabled[t] != 0) {
                gSelectCupGrid->mIndex = t;
                ResetSelectCupGridShownCourse();
                if (*(vu16 *) 0x027ffc40 != 2) {
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
                }
            }
        }
    }
}

void AdvanceSelectCupGridState4(void) {
    AdvanceSelectCupGridIndexChange();
    AdvanceSelectCupGridShownCourse();
    if (gSelectCupGrid->mStateFrames == 5) {
        gSelectCupGrid->mUnk_68 = TRUE;
    }
    gSelectCupGrid->mStateFrames = gSelectCupGrid->mStateFrames + 1;
    if (gSelectCupGrid->mStateFrames >= 10 && IsSelectCupGridIndexChangeRunning() == 0) {
        if (gSelectCupGrid->mMode == 0) {
            func_02118148();
            return;
        }
        func_021185ec();
        gSelectCupGrid->mResult = 1;
        RequestSelectCupGridState11();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridState5(void) {
    int v1;
    AdvanceSelectCupGridShownCourse();
    v1 = IsSelectChoisesState1NoState0Request();
    if (v1 != 0) {
        func_02118114();
    }
}

void AdvanceSelectCupGridState6(void) {
    int v1;
    AdvanceSelectCupGridShownCourse();
    v1 = GetSelectChoisesDone();
    if (v1 != 0) {
        func_021180f8();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridState7(void) {
    s32 a;

    AdvanceSelectCupGridShownCourse();
    if (IsSelectChoisesState0NoState1Request() != 0) {
        a = GetSelectChoisesIndex();
        switch (a) {
            case 0:
                func_021185ec();
                gSelectCupGrid->mResult = 1;
                RequestSelectCupGridState11();
                RequestSelectReturnState4();
                break;
            case -1:
            case 1:
                RequestSelectCupGridState3();
                break;
        }
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridState8(void) {
    int v1;
    AdvanceSelectCupGridShownCourse();
    v1 = IsSelectChoisesState1NoState0Request();
    if (v1 != 0) {
        func_02118054();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridState9(void) {
    s32 a;

    AdvanceSelectCupGridShownCourse();
    if (GetSelectChoisesDone() != 0) {
        func_02118038();
        if (*(vu16 *) 0x027ffc40 == 2) {
            a = GetSelectChoisesIndex();
            switch (a) {
                case -1:
                case 0:
                    break;
                case 1:
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0xf);
                    break;
            }
        }
    }
}

void AdvanceSelectCupGridState10(void) {
    s32 a;

    AdvanceSelectCupGridShownCourse();
    if (IsSelectChoisesState0NoState1Request() != 0) {
        a = GetSelectChoisesIndex();
        switch (a) {
            case -1:
            case 0:
                RequestSelectCupGridState3();
                break;
            case 1:
                gSelectCupGrid->mResult = 3;
                RequestSelectCupGridState11();
                if (*(vu16 *) 0x027ffc40 == 2) {
                    func_0211f378();
                }
                break;
        }
    }
}

void AdvanceSelectCupGridState11(void) {
    s16 a;
    s16 b;
    s16 c;
    u16 v;
    int i;
    int j;
    int k;

    gSelectCupGrid->mStateFrames = gSelectCupGrid->mStateFrames + 1;
    if (*(vu16 *) 0x027ffc40 != 2) {
        v = gSelectCupGrid->mSelectCupMBncl->mUnk_06;
        a = InterpolateS16(1, 0, 0xe0, gSelectCupGrid->mStateFrames, 0xa);
        b = InterpolateS16(1, 0, -192, gSelectCupGrid->mStateFrames, 0xa);
        if (gSelectCupGrid->mResult == 2 || gSelectCupGrid->mResult == 3 || gSelectCupGrid->mMode == 0) {
            gSelectCupGrid->mBg0Offset = b;
            gSelectCupGrid->mSelectCupMTable[19].mUnk_06 = b;
            gSelectCupGrid->mSelectCupMTable[2].mUnk_06 = b;
            gSelectCupGrid->mSelectCupMTable[1].mUnk_06 = b;
            gSelectCupGrid->mSelectCupMTable[0].mUnk_06 = b;
            for (i = 0; i < 8; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c83c[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c7c8[i]].mUnk_06 = b;
            }
            for (i = 0; i < 4; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c7d0[i]].mUnk_06 = b;
                gSelectCupGrid->mSelectCupMTable[v + data_0215c7d8[i]].mUnk_06 = b;
            }
        }
        gSelectCupGrid->mSelectCupMTable[20].mUnk_06 = b;
        c = -a;
        gSelectCupGrid->mSelectCupSTable[0].mUnk_04 = c;
        gSelectCupGrid->mSelectCupSTable[1].mUnk_04 = a;
        gSelectCupGrid->mSelectCupSTable[2].mUnk_04 = c;
        gSelectCupGrid->mSelectCupSTable[3].mUnk_04 = a;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 6; j++) {
                gSelectCupGrid->mSelectCupSTable[data_0215c9bc[i][j]].mUnk_04 = -a;
            }
        }
        for (i = 4; i < 8; i++) {
            for (j = 0; j < 6; j++) {
                gSelectCupGrid->mSelectCupSTable[data_0215c9bc[i][j]].mUnk_04 = a;
            }
        }
    }
}

s32 AdvanceSelectCupGrid(void) {
    int i;
    int n;
    u16 *p;

    gSelectCupGrid->mState = gSelectCupGrid->mNextState;
    switch (gSelectCupGrid->mState) {
        case 0:
            AdvanceSelectCupGridState0();
            break;
        case 1:
            AdvanceSelectCupGridState1();
            break;
        case 2:
            AdvanceSelectCupGridState2();
            break;
        case 3:
            AdvanceSelectCupGridState3();
            break;
        case 4:
            AdvanceSelectCupGridState4();
            break;
        case 5:
            AdvanceSelectCupGridState5();
            break;
        case 6:
            AdvanceSelectCupGridState6();
            break;
        case 7:
            AdvanceSelectCupGridState7();
            break;
        case 8:
            AdvanceSelectCupGridState8();
            break;
        case 9:
            AdvanceSelectCupGridState9();
            break;
        case 10:
            AdvanceSelectCupGridState10();
            break;
        case 11:
            AdvanceSelectCupGridState11();
            break;
    }
    func_02118814();
    func_02118458();
    if (*(vu16 *) 0x027ffc40 != 2) {
        if (gSelectCupGrid->mCupPicturePending != FALSE && func_020d0ec4() != FALSE) {
            p = GetCupPictureNscrData();
            CallQueueAppend(0xf, 0, GetCupPictureNclrData(), 0xe0);
            CallQueueAppend(4, 0x20, GetCupPictureNcgrData(), 0xdc0);
            for (i = 0; i < 11; i++) {
                n = (i + 8) * 0x20 + 0x16;
                CallQueueAppend(8, n * 2, p + n, 0x14);
            }
            gSelectCupGrid->mCupPicturePending = FALSE;
        }
        func_02124c30(gSelectCupGrid->mSelectCupMBncl, gSelectCupGrid->mSelectCupMNcer, gSelectCupGrid->mSelectCupMBnll,
                      gSelectCupGrid->mUnk_80, gSelectCupGrid->mSelectCupMTable);
        func_02124c30(gSelectCupGrid->mSelectCupSBncl, gSelectCupGrid->mSelectCupSNcer, NULL, gSelectCupGrid->mUnk_84,
                      gSelectCupGrid->mSelectCupSTable);
    } else {
        func_0211f39c();
    }
    if (gSelectCupGrid->mState == 0xb && gSelectCupGrid->mStateFrames >= 0xa) {
        return gSelectCupGrid->mResult;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on
void func_021173e4(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value0 = gSelectCupGrid->mBg0Offset;
    value0 = 0u - (value0);
    value1 = (value0 << 16);
    value0 = 0x1ff0000u;
    value1 = (value1) & (value0);
    value0 = 0x4000010u;
    *(u32 *) ((value0) + 0u) = value1;
    value1 = 0x4000000u;
    value2 = *(const u32 *) ((value1) + 0u);
    value0 = 0xffff1fffu;
    value2 = (value2) & (value0);
    *(u32 *) ((value1) + 0u) = value2;
}
#pragma thumb off
