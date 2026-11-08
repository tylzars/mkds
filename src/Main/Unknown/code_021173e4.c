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

void RefreshSelectCupGridCupsEnabled(void) {
    int cupIndex;
    u32 enabled;
    cupIndex = 0;
    do {
        enabled = GetSelectCupGridCupEnabled(cupIndex);
        gSelectCupGrid->mCupsEnabled[cupIndex] = enabled;
        cupIndex = cupIndex + 1;
    } while (cupIndex < 8);
}

#pragma thumb off

#pragma thumb on
void func_021188dc(void) {
    s32 cupCellIndex;
    s32 i;
    u16 mainCellCount;
    u16 *cellIndices;
    SelectCupGrid *grid;

    if (*(vu16 *) 0x027ffc40 != 2) {
        mainCellCount = gSelectCupGrid->mSelectCupMBncl->mUnk_06;
        for (i = 0; i < 4; i++) {
            gSelectCupGrid->mSelectCupMTable[data_0215c7d0[i]].mVisible = 0;
            gSelectCupGrid->mSelectCupMTable[mainCellCount + data_0215c7d8[i]].mVisible = 1;
        }
        for (i = 0; i < 8; i++) {
            for (cupCellIndex = 0, cellIndices = gSelectCupGridCupCellIndices[i]; cupCellIndex < 6; cupCellIndex++) {
                gSelectCupGrid->mSelectCupSTable[cellIndices[cupCellIndex]].mVisible = 0;
            }
        }
        gSelectCupGrid->mSelectCupMTable[0x14].mVisible = 1;
        gSelectCupGrid->mSelectCupMTable[0x13].mVisible = 1;
        gSelectCupGrid->mSelectCupSTable[2].mVisible = 1;
        gSelectCupGrid->mSelectCupSTable[3].mVisible = 1;
        for (i = 0; i < 8; i++) {
            gSelectCupGrid->mSelectCupSTable[gSelectCupGridCupCellIndices[i][0]].mVisible = 1;
        }
        for (i = 0; i < 8; i++) {
            grid = gSelectCupGrid;
            QueueCupMark(
                i, grid->mSelectCupSNcer, grid->mSelectCupSBncl, gSelectCupGridCupCellIndices[i][4],
                GetCellPaletteIndex(gSelectCupGridCupCellIndices[i][4], grid->mSelectCupSNcer, grid->mSelectCupSBncl),
                1);
        }
    }
}

void UpdateSelectCupGridCupCells(void) {
    s32 i;
    BOOL visible;

    if (*(vu16 *) 0x027ffc40 != 2) {
        visible = FALSE;
        for (i = 0; i < 8; i++) {
            u16 *cellIndices = gSelectCupGridCupCellIndices[i];
            gSelectCupGrid->mSelectCupSTable[cellIndices[1]].mVisible = 0;
            gSelectCupGrid->mSelectCupSTable[cellIndices[2]].mVisible = 0;
            gSelectCupGrid->mSelectCupSTable[cellIndices[3]].mVisible = 0;
            gSelectCupGrid->mSelectCupSTable[cellIndices[4]].mVisible = 0;
            gSelectCupGrid->mSelectCupSTable[cellIndices[5]].mVisible = 0;
            if (gSelectCupGrid->mCupsEnabled[i] == 0) {
                gSelectCupGrid->mSelectCupSTable[cellIndices[3]].mVisible = 1;
                gSelectCupGrid->mSelectCupSTable[cellIndices[5]].mVisible = 1;
            } else {
                if (gSelectCupGrid->mIndex == i && gSelectCupGrid->mUnk_68 != FALSE) {
                    gSelectCupGrid->mSelectCupSTable[cellIndices[2]].mVisible = 1;
                } else {
                    gSelectCupGrid->mSelectCupSTable[cellIndices[1]].mVisible = 1;
                }
                gSelectCupGrid->mSelectCupSTable[cellIndices[4]].mVisible = 1;
            }
            if (gSelectCupGrid->mMode == 3) {
                gSelectCupGrid->mSelectCupSTable[cellIndices[5]].mVisible = visible;
            }
        }
    }
}

void RequestSelectCupGridCupPicture(void) {
    if (*(vu16 *) 0x027ffc40 != 2) {
        TrySetCupPictureIndexAndQueueLoads(
            gSelectCupGridCourseIds[gSelectCupGrid->mIndex][gSelectCupGrid->mShownCourseIndex]);
        gSelectCupGrid->mCupPicturePending = TRUE;
    }
}

void SetupSelectCupGridIndex(void) {
    u32 a;
    s32 recordSlot;
    s32 c;
    s32 i;
    u16 *cellIndexCursor;
    s32 j;
    SelectCupGrid *grid;
    u32 engineOrMirrorSlot;

    a = 0;
    if (*(vu16 *) 0x027ffc40 == 2) {
        return;
    }
    QueueSelectCupNameM(gSelectCupGrid->mIndex, gSelectCupGrid->mSelectCupMNcer, gSelectCupGrid->mSelectCupMBncl, 0x13,
                        a);
    j = 0;
    for (i = 0; i < 4; i++) {
        grid = gSelectCupGrid;
        func_0212426c(j, data_0215c7d8[i], gSelectCupGrid->mSelectCupMBnll,
                      GetBmgEntry(grid->mCommonMessages, gSelectCupGridCupMessageIndices[grid->mIndex][i]),
                      grid->mSelectCupMBncl, grid->mSelectCupMTable);
    }
    for (j = 0, cellIndexCursor = data_0215c83c; j < 8; cellIndexCursor++, j++) {
        gSelectCupGrid->mSelectCupMTable[*cellIndexCursor].mVisible = 0;
    }
    for (i = 0; i < 4; i++) {
        gSelectCupGrid->mSelectCupMTable[data_0215c7c8[i]].mVisible = 0;
    }
    if (gSelectCupGrid->mMode == 0) {
        if (GetMirrorMode() != 0) {
            engineOrMirrorSlot = 3;
        } else {
            engineOrMirrorSlot = data_0215c7f0[GetEngineIndex()];
        }
        recordSlot = data_0215c81c[engineOrMirrorSlot];
        if (IsGrandPrixRecordFilled(data_0215c85c[gSelectCupGrid->mIndex], recordSlot) != 0) {
            c = func_02060364(data_0215c85c[gSelectCupGrid->mIndex], recordSlot);
            gSelectCupGrid->mSelectCupMTable[data_0215c83c[data_0215c87c[c]]].mVisible = 1;
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
            gSelectCupGrid->mSelectCupMTable[a].mVisible = 1;
            c = GetGrandPrixRecordCupRank(data_0215c85c[gSelectCupGrid->mIndex], recordSlot);
            grid = gSelectCupGrid;
            QueueTrophyIcon(data_0215c85c[grid->mIndex], c, grid->mSelectCupMNcer, grid->mSelectCupMBncl, a, 4, 0);
        }
    }
    RequestSelectCupGridCupPicture();
}

void func_021185ec(void) {
    SetCupIndex(data_0215c85c[gSelectCupGrid->mIndex]);
    SetCourseId(gSelectCupGridFirstCourseIds[gSelectCupGrid->mIndex]);
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
    u16 mainCellCount;
    s16 offsetY;
    int i;

    if (IsSelectCupGridIndexChangeRunning() != 0) {
        if (gSelectCupGrid->mIndexChangeTimer == 7) {
            gSelectCupGrid->mShownIndex = gSelectCupGrid->mIndex;
            SetupSelectCupGridIndex();
        } else if (*(vu16 *) 0x027ffc40 != 2) {
            mainCellCount = gSelectCupGrid->mSelectCupMBncl->mUnk_06;
            offsetY = LookupIndexChangeOffset(7 - gSelectCupGrid->mIndexChangeTimer, 1);
            gSelectCupGrid->mBg0Offset = offsetY;
            gSelectCupGrid->mSelectCupMTable[19].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[2].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[1].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[0].mOffsetY = offsetY;
            for (i = 0; i < 8; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c83c[i]].mOffsetY = offsetY;
            }
            for (i = 0; i < 4; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c7c8[i]].mOffsetY = offsetY;
            }
            for (i = 0; i < 4; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c7d0[i]].mOffsetY = offsetY;
                gSelectCupGrid->mSelectCupMTable[mainCellCount + data_0215c7d8[i]].mOffsetY = offsetY;
            }
        }
        gSelectCupGrid->mIndexChangeTimer = gSelectCupGrid->mIndexChangeTimer - 1;
    } else if (gSelectCupGrid->mIndex != gSelectCupGrid->mShownIndex) {
        gSelectCupGrid->mIndexChangeTimer = 7;
    }
}

void UpdateSelectCupGridCourseCells(void) {
    int i;

    if (*(vu16 *) 0x027ffc40 != 2) {
        for (i = 0; i < 4; i++) {
            if (gSelectCupGrid->mShownCourseIndex == i) {
                gSelectCupGrid->mSelectCupMTable[data_0215c7d0[i]].mVisible = 1;
                SetLabelPaletteIndex(data_0215c7d8[i], 0xe, gSelectCupGrid->mSelectCupMBnll,
                                     gSelectCupGrid->mSelectCupMTable, gSelectCupGrid->mSelectCupMBncl);
            } else {
                gSelectCupGrid->mSelectCupMTable[data_0215c7d0[i]].mVisible = 0;
                SetLabelPaletteIndex(data_0215c7d8[i], 0xf, gSelectCupGrid->mSelectCupMBnll,
                                     gSelectCupGrid->mSelectCupMTable, gSelectCupGrid->mSelectCupMBncl);
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

void RequestSelectCupGridState0(void) {
    u16 mainCellCount;
    s32 offsetY;
    s32 offsetX;
    int i;
    int j;

    gSelectCupGrid->mNextState = 0;
    gSelectCupGrid->mStateFrames = 0;
    if (*(vu16 *) 0x027ffc40 != 2) {
        mainCellCount = gSelectCupGrid->mSelectCupMBncl->mUnk_06;
        if (GetPreviousMenuScreenNumber() == 0x18 || GetPreviousMenuScreenNumber() == 0xc) {
            offsetY = 0;
            gSelectCupGrid->mBg0Offset = offsetY;
            gSelectCupGrid->mSelectCupMTable[20].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[19].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[2].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[1].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[0].mOffsetY = offsetY;
            for (i = 0; i < 8; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c83c[i]].mOffsetY = offsetY;
            }
            for (i = 0; i < 4; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c7c8[i]].mOffsetY = offsetY;
            }
            for (i = 0; i < 4; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c7d0[i]].mOffsetY = offsetY;
                gSelectCupGrid->mSelectCupMTable[mainCellCount + data_0215c7d8[i]].mOffsetY = offsetY;
            }
        } else {
            offsetY = -192;
            gSelectCupGrid->mBg0Offset = offsetY;
            gSelectCupGrid->mSelectCupMTable[20].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[19].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[2].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[1].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[0].mOffsetY = offsetY;
            for (i = 0; i < 8; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c83c[i]].mOffsetY = offsetY;
            }
            for (i = 0; i < 4; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c7c8[i]].mOffsetY = offsetY;
            }
            for (i = 0; i < 4; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c7d0[i]].mOffsetY = offsetY;
                gSelectCupGrid->mSelectCupMTable[mainCellCount + data_0215c7d8[i]].mOffsetY = offsetY;
            }
        }
        offsetY = -192;
        gSelectCupGrid->mSelectCupMTable[20].mOffsetY = offsetY;
        offsetX = -224;
        gSelectCupGrid->mSelectCupSTable[0].mOffsetX = offsetX;
        gSelectCupGrid->mSelectCupSTable[1].mOffsetX = 0xe0;
        gSelectCupGrid->mSelectCupSTable[2].mOffsetX = offsetX;
        gSelectCupGrid->mSelectCupSTable[3].mOffsetX = 0xe0;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 6; j++) {
                gSelectCupGrid->mSelectCupSTable[gSelectCupGridCupCellIndices[i][j]].mOffsetX = offsetX;
            }
        }
        for (i = 4; i < 8; i++) {
            for (j = 0; j < 6; j++) {
                gSelectCupGrid->mSelectCupSTable[gSelectCupGridCupCellIndices[i][j]].mOffsetX = 0xe0;
            }
        }
    }
}

void RequestSelectCupGridState1(void) {
    gSelectCupGrid->mNextState = 1;
    gSelectCupGrid->mStateFrames = 0;
}

void RequestSelectCupGridState2(void) {
    gSelectCupGrid->mNextState = 2;
    gSelectCupGrid->mStateFrames = 0;
    RequestSelectReturnState1();
}

void RequestSelectCupGridState3(void) {
    gSelectCupGrid->mNextState = 3;
    gSelectCupGrid->mStateFrames = 0;
}

void RequestSelectCupGridState4(void) {
    gSelectCupGrid->mNextState = 4;
    gSelectCupGrid->mStateFrames = 0;
    if (*(vu16 *) 0x027ffc40 != 2) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
    }
}

void RequestSelectCupGridState5(void) {
    void *firstChoiceText;

    gSelectCupGrid->mNextState = 5;
    gSelectCupGrid->mStateFrames = 0;
    firstChoiceText = GetBmgEntry(gSelectCupGrid->mCommonMessages, 4);
    StartSelectChoises(firstChoiceText, GetBmgEntry(gSelectCupGrid->mCommonMessages, 2), 0);
}

#pragma thumb off

#pragma thumb on

void RequestSelectCupGridState6(void) {
    gSelectCupGrid->mNextState = 6;
    gSelectCupGrid->mStateFrames = 0;
    SetSelectChoisesSoundId(0, 7);
    SetSelectChoisesSoundId(1, 0x10);
    SetSelectChoisesSoundId(0xffffffff, 0x10);
}

#pragma thumb off

#pragma thumb on

void RequestSelectCupGridState7(void) {
    gSelectCupGrid->mNextState = 7;
    gSelectCupGrid->mStateFrames = 0;
    RequestSelectChoisesState0();
}

void RequestSelectCupGridState8(void) {
    void *firstChoiceText;

    gSelectCupGrid->mNextState = 8;
    gSelectCupGrid->mStateFrames = 0;
    if (*(vu16 *) 0x027ffc40 == 2) {
        firstChoiceText = GetBmgEntry(gSelectCupGrid->mCommonMessages, 0x5d);
        StartSelectChoises(firstChoiceText, GetBmgEntry(gSelectCupGrid->mCommonMessages, 0x5f), 0);
    } else {
        firstChoiceText = GetBmgEntry(gSelectCupGrid->mMenuMessages, 0x14);
        StartSelectChoises(firstChoiceText, GetBmgEntry(gSelectCupGrid->mMenuMessages, 0x15), 0);
    }
}

#pragma thumb off

#pragma thumb on

void RequestSelectCupGridState9(void) {
    gSelectCupGrid->mNextState = 9;
    gSelectCupGrid->mStateFrames = 0;
    SetSelectChoisesSoundId(0, 5);
    SetSelectChoisesSoundId(1, 0xf);
    SetSelectChoisesSoundId(0xffffffff, 0x10);
}

#pragma thumb off

#pragma thumb on

void RequestSelectCupGridState10(void) {
    gSelectCupGrid->mNextState = 0xa;
    gSelectCupGrid->mStateFrames = 0;
    RequestSelectChoisesState0();
}

void RequestSelectCupGridState11(void) {
    gSelectCupGrid->mNextState = 0xb;
    gSelectCupGrid->mStateFrames = 0;
}

void InitSelectCupGrid(void *heap, void *mainOam, void *subOam, s32 mode) {
    s32 remainingSize;
    int i;

    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0x9004;
    if (GetPreviousMenuScreenNumber() != 0x18 && GetPreviousMenuScreenNumber() != 0xc) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1800;
    }
    heap = CreateFrmHeapFromMaxFree(heap);
    gSelectCupGrid = HeapAlloc(heap, 0x8c);
    gSelectCupGrid->mHeap = heap;
    gSelectCupGrid->mState = 0;
    gSelectCupGrid->mIndex = data_0215c8fc[GetCupIndex()];
    gSelectCupGrid->mUnk_68 = TRUE;
    gSelectCupGrid->mIndexChangeTimer = 0;
    gSelectCupGrid->mMode = mode;
    gSelectCupGrid->mShownIndex = gSelectCupGrid->mIndex;
    gSelectCupGrid->mCupPicturePending = FALSE;
    gSelectCupGrid->mMainOam = mainOam;
    gSelectCupGrid->mSubOam = subOam;
    gSelectCupGrid->mResult = 0;
    ResetSelectCupGridShownCourse();
    RefreshSelectCupGridCupsEnabled();
    func_02118b48();
    if (GetPreviousMenuScreenNumber() != 0x18 && GetPreviousMenuScreenNumber() != 0xc) {
        func_020ae6d4(gSelectCupGrid->mMainOam, gSelectCupGrid->mSubOam);
    }
    gSelectCupGrid->mCommonMessages = FindFileInLoadedArchives("common.bmg");
    if (*(vu16 *) 0x027ffc40 != 2) {
        gSelectCupGrid->mMenuMessages = FindSceneFile("menu.bmg");
        InitLayoutTable(gSelectCupGrid->mHeap, gSelectCupGrid->mSelectCupMBncl, gSelectCupGrid->mSelectCupMBnll,
                        &gSelectCupGrid->mSelectCupMTable);
        InitLayoutTable(gSelectCupGrid->mHeap, gSelectCupGrid->mSelectCupSBncl, NULL,
                        &gSelectCupGrid->mSelectCupSTable);
        remainingSize = 0x8000;
        for (i = 0; i < 4; i++) {
            remainingSize -=
                InitLabelCanvas(gSelectCupGrid->mHeap, data_0215c7d8[i], gSelectCupGrid->mSelectCupMBnll,
                                data_0215c7e0[i], data_0215c7e8[i], data_0215c7d0[i], gSelectCupGrid->mSelectCupMNcer,
                                gSelectCupGrid->mSelectCupMBncl, gSelectCupGrid->mSelectCupMTable, remainingSize);
        }
        CreateSelectCupNameM(gSelectCupGrid->mHeap);
        CreateCommonCupMark(gSelectCupGrid->mHeap);
        CreateTrophyIcon(gSelectCupGrid->mHeap);
    } else {
        InitSelectRaceRuleWait(gSelectCupGrid->mHeap, gSelectCupGrid->mSubOam);
        if (GetPreviousMenuScreenNumber() != 0xc) {
            func_0211f394();
        } else {
            func_0211f380();
        }
    }
    func_021188dc();
    SetupSelectCupGridIndex();
    RequestSelectCupGridState0();
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
        ClearSelectCupNameMPointer();
        ClearCupMarkPointer();
        ClearTrophyIconPointer();
    } else {
        func_0211f498();
    }
    HeapDestroy(gSelectCupGrid->mHeap);
    gSelectCupGrid = NULL;
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridState0(void) {
    int fadesClear;
    fadesClear = AreBrightnessFadesClear();
    if (fadesClear != 0) {
        RequestSelectCupGridState1();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridState1(void) {
    u16 mainCellCount;
    s16 offsetX;
    s16 offsetY;
    s16 negatedOffsetX;
    int i;
    int j;

    gSelectCupGrid->mStateFrames = gSelectCupGrid->mStateFrames + 1;
    if (*(vu16 *) 0x027ffc40 != 2) {
        mainCellCount = gSelectCupGrid->mSelectCupMBncl->mUnk_06;
        offsetX = InterpolateS16(1, 0xe0, 0, gSelectCupGrid->mStateFrames, 0xa);
        offsetY = InterpolateS16(1, -192, 0, gSelectCupGrid->mStateFrames, 0xa);
        if (GetPreviousMenuScreenNumber() != 0x18 && GetPreviousMenuScreenNumber() != 0xc) {
            gSelectCupGrid->mBg0Offset = offsetY;
            gSelectCupGrid->mSelectCupMTable[19].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[2].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[1].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[0].mOffsetY = offsetY;
            for (i = 0; i < 8; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c83c[i]].mOffsetY = offsetY;
            }
            for (i = 0; i < 4; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c7c8[i]].mOffsetY = offsetY;
            }
            for (i = 0; i < 4; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c7d0[i]].mOffsetY = offsetY;
                gSelectCupGrid->mSelectCupMTable[mainCellCount + data_0215c7d8[i]].mOffsetY = offsetY;
            }
        }
        gSelectCupGrid->mSelectCupMTable[20].mOffsetY = offsetY;
        negatedOffsetX = -offsetX;
        gSelectCupGrid->mSelectCupSTable[0].mOffsetX = negatedOffsetX;
        gSelectCupGrid->mSelectCupSTable[1].mOffsetX = offsetX;
        gSelectCupGrid->mSelectCupSTable[2].mOffsetX = negatedOffsetX;
        gSelectCupGrid->mSelectCupSTable[3].mOffsetX = offsetX;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 6; j++) {
                gSelectCupGrid->mSelectCupSTable[gSelectCupGridCupCellIndices[i][j]].mOffsetX = -offsetX;
            }
        }
        for (i = 4; i < 8; i++) {
            for (j = 0; j < 6; j++) {
                gSelectCupGrid->mSelectCupSTable[gSelectCupGridCupCellIndices[i][j]].mOffsetX = offsetX;
            }
        }
    }
    if (gSelectCupGrid->mStateFrames >= 0xa) {
        RequestSelectCupGridState2();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridState2(void) {
    int isReturnState2NoState3Or4Request;
    isReturnState2NoState3Or4Request = IsSelectReturnState2NoState3Or4Request();
    if (isReturnState2NoState3Or4Request != 0) {
        RequestSelectCupGridState3();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridState3(void) {
    InputSlotIndex inputIndex;
    s32 touchedRectIndex;
    s32 neighborIndex;
    s32 touchedCupIndex;
    int b;
    int a;
    u16 x;
    InputSlot *p;
    InputSlot *q;

    touchedRectIndex = -1;
    inputIndex = UNK_02175628_INDEX_8;
    AdvanceSelectCupGridIndexChange();
    AdvanceSelectCupGridShownCourse();
    b = 0;
    a = 0;
    p = &data_02175674[inputIndex];
    x = data_02175674[inputIndex].mUnk_00;
    if (x == 0 && data_02175680[inputIndex].mUnk_00 < 5) {
        a = 1;
    }
    if (a == 0 && data_0217567c[inputIndex].mUnk_00 == 0 && x != 0) {
        b = 1;
    }
    if (b != 0) {
        touchedRectIndex = RectTableFindContaining(gSelectCupGrid->mSelectCupSBnbl, data_02175670[inputIndex].mUnk_00,
                                                   data_02175672[inputIndex].mUnk_00);
    }
    q = &data_02175628[inputIndex];
    if ((u16) (data_02175628[inputIndex].mUnk_00 & PAD_KEY_B) != 0) {
        goto L1;
    }
    b = 0;
    a = 0;
    x = p->mUnk_00;
    if (x == 0 && data_02175680[inputIndex].mUnk_00 < 5) {
        a = 1;
    }
    if (a == 0 && data_0217567c[inputIndex].mUnk_00 == 0 && x != 0) {
        b = 1;
    }
    if (b == 0) {
        goto L2;
    }
    if (IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175670[inputIndex].mUnk_00,
                                                        data_02175672[inputIndex].mUnk_00) == FALSE) {
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
                RequestSelectCupGridState8();
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
    if ((u32) touchedRectIndex <= 7) {
        touchedCupIndex = data_0215c8dc[touchedRectIndex];
        if (gSelectCupGrid->mCupsEnabled[touchedCupIndex] == 0) {
            if (*(vu16 *) 0x027ffc40 != 2) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x16);
            }
            return;
        }
        if (gSelectCupGrid->mIndex == touchedCupIndex) {
            gSelectCupGrid->mUnk_68 = FALSE;
        }
        gSelectCupGrid->mIndex = touchedCupIndex;
        RequestSelectCupGridState4();
        return;
    }
    if ((u16) (q->mUnk_00 & PAD_KEY_A) != 0) {
        RequestSelectCupGridState4();
        gSelectCupGrid->mUnk_68 = FALSE;
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
        a = gSelectCupGrid->mIndex;
        b = gSelectCupGridUpOffsets[a];
        if (b != 0) {
            neighborIndex = a + b;
            if (gSelectCupGrid->mCupsEnabled[neighborIndex] != 0) {
                gSelectCupGrid->mIndex = neighborIndex;
                ResetSelectCupGridShownCourse();
                if (*(vu16 *) 0x027ffc40 != 2) {
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
                }
            }
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
        a = gSelectCupGrid->mIndex;
        b = gSelectCupGridDownOffsets[a];
        if (b != 0) {
            neighborIndex = a + b;
            if (gSelectCupGrid->mCupsEnabled[neighborIndex] != 0) {
                gSelectCupGrid->mIndex = neighborIndex;
                ResetSelectCupGridShownCourse();
                if (*(vu16 *) 0x027ffc40 != 2) {
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
                }
            }
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_LEFT) != 0) {
        a = gSelectCupGrid->mIndex;
        b = gSelectCupGridLeftOffsets[a];
        if (b != 0) {
            neighborIndex = a + b;
            if (gSelectCupGrid->mCupsEnabled[neighborIndex] != 0) {
                gSelectCupGrid->mIndex = neighborIndex;
                ResetSelectCupGridShownCourse();
                if (*(vu16 *) 0x027ffc40 != 2) {
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
                }
            }
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_RIGHT) != 0) {
        a = gSelectCupGrid->mIndex;
        b = gSelectCupGridRightOffsets[a];
        if (b != 0) {
            neighborIndex = a + b;
            if (gSelectCupGrid->mCupsEnabled[neighborIndex] != 0) {
                gSelectCupGrid->mIndex = neighborIndex;
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
            RequestSelectCupGridState5();
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
    int isChoisesState1NoState0Request;
    AdvanceSelectCupGridShownCourse();
    isChoisesState1NoState0Request = IsSelectChoisesState1NoState0Request();
    if (isChoisesState1NoState0Request != 0) {
        RequestSelectCupGridState6();
    }
}

void AdvanceSelectCupGridState6(void) {
    int isDone;
    AdvanceSelectCupGridShownCourse();
    isDone = GetSelectChoisesDone();
    if (isDone != 0) {
        RequestSelectCupGridState7();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridState7(void) {
    s32 choiceIndex;

    AdvanceSelectCupGridShownCourse();
    if (IsSelectChoisesState0NoState1Request() != 0) {
        choiceIndex = GetSelectChoisesIndex();
        switch (choiceIndex) {
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
    int isChoisesState1NoState0Request;
    AdvanceSelectCupGridShownCourse();
    isChoisesState1NoState0Request = IsSelectChoisesState1NoState0Request();
    if (isChoisesState1NoState0Request != 0) {
        RequestSelectCupGridState9();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectCupGridState9(void) {
    s32 choiceIndex;

    AdvanceSelectCupGridShownCourse();
    if (GetSelectChoisesDone() != 0) {
        RequestSelectCupGridState10();
        if (*(vu16 *) 0x027ffc40 == 2) {
            choiceIndex = GetSelectChoisesIndex();
            switch (choiceIndex) {
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
    s32 choiceIndex;

    AdvanceSelectCupGridShownCourse();
    if (IsSelectChoisesState0NoState1Request() != 0) {
        choiceIndex = GetSelectChoisesIndex();
        switch (choiceIndex) {
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
    s16 offsetX;
    s16 offsetY;
    s16 negatedOffsetX;
    u16 mainCellCount;
    int i;
    int j;
    int k;

    gSelectCupGrid->mStateFrames = gSelectCupGrid->mStateFrames + 1;
    if (*(vu16 *) 0x027ffc40 != 2) {
        mainCellCount = gSelectCupGrid->mSelectCupMBncl->mUnk_06;
        offsetX = InterpolateS16(1, 0, 0xe0, gSelectCupGrid->mStateFrames, 0xa);
        offsetY = InterpolateS16(1, 0, -192, gSelectCupGrid->mStateFrames, 0xa);
        if (gSelectCupGrid->mResult == 2 || gSelectCupGrid->mResult == 3 || gSelectCupGrid->mMode == 0) {
            gSelectCupGrid->mBg0Offset = offsetY;
            gSelectCupGrid->mSelectCupMTable[19].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[2].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[1].mOffsetY = offsetY;
            gSelectCupGrid->mSelectCupMTable[0].mOffsetY = offsetY;
            for (i = 0; i < 8; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c83c[i]].mOffsetY = offsetY;
            }
            for (i = 0; i < 4; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c7c8[i]].mOffsetY = offsetY;
            }
            for (i = 0; i < 4; i++) {
                gSelectCupGrid->mSelectCupMTable[data_0215c7d0[i]].mOffsetY = offsetY;
                gSelectCupGrid->mSelectCupMTable[mainCellCount + data_0215c7d8[i]].mOffsetY = offsetY;
            }
        }
        gSelectCupGrid->mSelectCupMTable[20].mOffsetY = offsetY;
        negatedOffsetX = -offsetX;
        gSelectCupGrid->mSelectCupSTable[0].mOffsetX = negatedOffsetX;
        gSelectCupGrid->mSelectCupSTable[1].mOffsetX = offsetX;
        gSelectCupGrid->mSelectCupSTable[2].mOffsetX = negatedOffsetX;
        gSelectCupGrid->mSelectCupSTable[3].mOffsetX = offsetX;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 6; j++) {
                gSelectCupGrid->mSelectCupSTable[gSelectCupGridCupCellIndices[i][j]].mOffsetX = -offsetX;
            }
        }
        for (i = 4; i < 8; i++) {
            for (j = 0; j < 6; j++) {
                gSelectCupGrid->mSelectCupSTable[gSelectCupGridCupCellIndices[i][j]].mOffsetX = offsetX;
            }
        }
    }
}

s32 AdvanceSelectCupGrid(void) {
    int i;
    int screenMapIndex;
    u16 *screenMap;

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
    UpdateSelectCupGridCupCells();
    UpdateSelectCupGridCourseCells();
    if (*(vu16 *) 0x027ffc40 != 2) {
        if (gSelectCupGrid->mCupPicturePending != FALSE && func_020d0ec4() != FALSE) {
            screenMap = GetCupPictureNscrData();
            CallQueueAppend(0xf, 0, GetCupPictureNclrData(), 0xe0);
            CallQueueAppend(4, 0x20, GetCupPictureNcgrData(), 0xdc0);
            for (i = 0; i < 11; i++) {
                screenMapIndex = (i + 8) * 0x20 + 0x16;
                CallQueueAppend(8, screenMapIndex * 2, screenMap + screenMapIndex, 0x14);
            }
            gSelectCupGrid->mCupPicturePending = FALSE;
        }
        DrawLayoutTable(gSelectCupGrid->mSelectCupMBncl, gSelectCupGrid->mSelectCupMNcer,
                        gSelectCupGrid->mSelectCupMBnll, gSelectCupGrid->mMainOam, gSelectCupGrid->mSelectCupMTable);
        DrawLayoutTable(gSelectCupGrid->mSelectCupSBncl, gSelectCupGrid->mSelectCupSNcer, NULL, gSelectCupGrid->mSubOam,
                        gSelectCupGrid->mSelectCupSTable);
    } else {
        AdvanceSelectRaceRuleWait();
    }
    if (gSelectCupGrid->mState == 0xb && gSelectCupGrid->mStateFrames >= 0xa) {
        return gSelectCupGrid->mResult;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on
void WriteSelectCupGridRegisters(void) {
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
