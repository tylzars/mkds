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
    SelectRaceRule *selectRaceRule;
    s32 i;
    s16 returnOffsetY;
    s16 rowsOffsetY;
    s32 j;
    s32 c;
    gSelectRaceRule->mStateFrames++;
    selectRaceRule = gSelectRaceRule;
    c = InterpolateS16(1, 0, -192, selectRaceRule->mStateFrames, 10);
    rowsOffsetY = selectRaceRule->mOffsetY + c;
    returnOffsetY = -LookupSelectReturnState4Bg2Offset(selectRaceRule->mStateFrames);
    gSelectRaceRule->mBg3Offset = rowsOffsetY;
    c = gSelectRaceRule->mBncl->mUnk_06;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mTable[data_0215cd88[i][j]].mOffsetY = rowsOffsetY;
            gSelectRaceRule->mTable[data_0215cdb0[i][j]].mOffsetY = rowsOffsetY;
            gSelectRaceRule->mTable[data_0215cdc4[i][j]].mOffsetY = rowsOffsetY;
        }
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mTable[c + gSelectRaceRuleRowEntries[i].mEntryIndices[j]].mOffsetY = rowsOffsetY;
        }
    }
    gSelectRaceRule->mTable[c + 10].mOffsetY = rowsOffsetY;
    gSelectRaceRule->mTable[c + 12].mOffsetY = rowsOffsetY;
    gSelectRaceRule->mTable[34].mOffsetY = rowsOffsetY;
    gSelectRaceRule->mTable[37].mOffsetY = rowsOffsetY;
    gSelectRaceRule->mTable[35].mOffsetY = rowsOffsetY;
    gSelectRaceRule->mTable[38].mOffsetY = rowsOffsetY;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mTable[data_0215ccac[i][j]].mOffsetY = rowsOffsetY;
        }
    }
    if (data_021759d0->mUnk_20 != 2) {
        gSelectRaceRule->mTable[40].mOffsetY = returnOffsetY;
        gSelectRaceRule->mTable[41].mOffsetY = returnOffsetY;
        gSelectRaceRule->mTable[c + 13].mOffsetY = returnOffsetY;
        c += 8;
        gSelectRaceRule->mTable[c].mOffsetY = rowsOffsetY;
        gSelectRaceRule->mTable[30].mOffsetY = rowsOffsetY;
        gSelectRaceRule->mTable[31].mOffsetY = rowsOffsetY;
    } else {
        gSelectRaceRule->mTable[42].mOffsetY = returnOffsetY;
        c += 14;
        gSelectRaceRule->mTable[c].mOffsetY = returnOffsetY;
    }
}

void func_0211a964(s32 labelIndex) {
    s32 tableIndex;
    tableIndex = gSelectRaceRule->mBncl->mUnk_06 + labelIndex;
    gSelectRaceRule->mTable[tableIndex].mOffsetY++;
    func_02124100(labelIndex, 1, gSelectRaceRule->mBnll, gSelectRaceRule->mTable, gSelectRaceRule->mBncl);
    DrawLayoutTableEntry(tableIndex, gSelectRaceRule->mBncl, gSelectRaceRule->mNcer, gSelectRaceRule->mBnll,
                         gSelectRaceRule->mOamList, gSelectRaceRule->mTable);
    gSelectRaceRule->mTable[tableIndex].mOffsetY--;
    func_02124100(labelIndex, 0, gSelectRaceRule->mBnll, gSelectRaceRule->mTable, gSelectRaceRule->mBncl);
}

void func_0211a908(s32 row) {
    if (row == 3) {
        if (data_021759d0->mUnk_20 != 2) {
            func_0211a964(data_0215cd4e[row * 2]);
        }
        func_0211a964(10);
    } else if (row == 4) {
        func_0211a964(data_0215cd4e[row * 2]);
        func_0211a964(12);
    } else {
        func_0211a964(data_0215cd4e[row * 2]);
    }
}

s32 AdvanceSelectRaceRule(void) {
    SelectRaceRule *selectRaceRule;
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
            SetPlayerEntryListUseTeams(0);
            break;
        case 1:
        case 2:
            SetPlayerEntryListUseTeams(1);
            break;
    }
    AdvancePlayerEntryList();
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        AdvancePaletteBlend();
    }
    AdvanceSelectRaceRuleHighlight();
    AdvanceSelectRaceRuleValueObjects();
    func_0211c0cc();
    selectRaceRule = gSelectRaceRule;
    DrawLayoutTable(selectRaceRule->mBncl, selectRaceRule->mNcer, selectRaceRule->mBnll, selectRaceRule->mOamList,
                    selectRaceRule->mTable);
    for (i = 0; i < 5; i++) {
        func_0211a908(i);
    }
    selectRaceRule = gSelectRaceRule;
    if (selectRaceRule->mState == 8) {
        if (selectRaceRule->mResult == 1 && (selectRaceRule->mMode == 3 || selectRaceRule->mRowValues[2] == 1)) {
            if (selectRaceRule->mStateFrames >= 10 && IsSelectReturnState0NoState1Request() != 0) {
                return gSelectRaceRule->mResult;
            }
        } else if (selectRaceRule->mStateFrames >= 10) {
            return selectRaceRule->mResult;
        }
    }
    return 0;
}

void WriteSelectRaceRuleRegisters(void) {
    reg_G2S_DB_BG3OFS = (-gSelectRaceRule->mBg3Offset << 16) & 0x1ff0000;
    WritePlayerEntryListRegisters();
}

void LoadSelectCupCourseData(void) {
    Ncgr *cellChars = NULL;
    Unk02021dc8 *cells = NULL;
    Nclr *cellPalette = NULL;
    Ncgr *bgChars = NULL;
    Nscr *screenMap = NULL;
    Nclr *bgPalette = NULL;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        LoadNcgrData(&bgChars, FindSceneFile(data_0216d894));
        LoadNclrData(&bgPalette, FindSceneFile(data_0216d88c));
        LoadNscrData(&screenMap, FindSceneFile(data_0216d8a4));
        LoadNcgrData(&bgChars, FindSceneFile(data_0216d87c));
        LoadNclrData(&bgPalette, FindSceneFile(data_0216d86c));
        LoadNscrData(&screenMap, FindSceneFile(data_0216d884));
        LoadNcgrData2(&cellChars, FindSceneFile(data_0216d8a0));
        LoadNcerData(&cells, FindSceneFile(data_0216d890));
        LoadNclrData(&cellPalette, FindSceneFile(data_0216d878));
    }
}

void LocateAndQueueSelectCupCourse(void) {
    Ncgr *courseCellChars = NULL;
    Nclr *courseCellPalette = NULL;
    Ncgr *cupCellChars = NULL;
    Nclr *cupCellPalette = NULL;
    Ncgr *modeChars = NULL;
    Nscr *modeScreenMap = NULL;
    Nclr *modePalette = NULL;
    Ncgr *fixedChars = NULL;
    Nscr *fixedScreenMap = NULL;
    Nclr *fixedPalette = NULL;
    u16 *courseCellPaletteData;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        gSelectCupCourse->mSelectCupMBnbl = FindSceneFile(data_0216d864);
        return;
    }
    if (gSelectCupCourse->mMode == 0) {
        LocateNcgr(&modeChars, FindSceneFile(data_0216d894));
        LocateNclr(&modePalette, FindSceneFile(data_0216d88c));
        LocateNscr(&modeScreenMap, FindSceneFile(data_0216d8a4));
    } else {
        LocateNcgr(&modeChars, FindSceneFile(data_0216d87c));
        LocateNclr(&modePalette, FindSceneFile(data_0216d86c));
        LocateNscr(&modeScreenMap, FindSceneFile(data_0216d884));
    }
    LocateNcgr(&fixedChars, FindSceneFile(data_0216d874));
    LocateNclr(&fixedPalette, FindSceneFile(data_0216d854));
    LocateNscr(&fixedScreenMap, FindSceneFile(data_0216d858));
    gSelectCupCourse->mUnk_24 = HeapAlloc(gSelectCupCourse->mHeap, 0x800);
    if (gSelectCupCourse->mMode == 0) {
        gSelectCupCourse->mSelectCupCourseTaOrVsMBncl = FindSceneFile(data_0216d880);
        gSelectCupCourse->mSelectCupCourseTaOrVsMBnll = FindSceneFile(data_0216d89c);
    } else {
        gSelectCupCourse->mSelectCupCourseTaOrVsMBncl = FindSceneFile(data_0216d868);
        gSelectCupCourse->mSelectCupCourseTaOrVsMBnll = FindSceneFile(data_0216d870);
    }
    LocateNcgr2(&courseCellChars, FindSceneFile(data_0216d8a0));
    LocateNcer(&gSelectCupCourse->mSelectCupCourseMNcer, FindSceneFile(data_0216d890));
    LocateNclr(&courseCellPalette, FindSceneFile(data_0216d878));
    gSelectCupCourse->mSelectCupMBncl = FindSceneFile(data_0216d888);
    gSelectCupCourse->mSelectCupMBnbl = FindSceneFile(data_0216d864);
    gSelectCupCourse->mSelectCupMBnll = FindSceneFile(data_0216d860);
    LocateNcgr2(&cupCellChars, FindSceneFile(data_0216d898));
    LocateNcer(&gSelectCupCourse->mSelectCupMNcer, FindSceneFile(data_0216d8a8));
    LocateNclr(&cupCellPalette, FindSceneFile(data_0216d85c));
    courseCellPaletteData = courseCellPalette->mData;
    CallQueueAppend(4, 0, modeChars->mData, modeChars->mDataSize);
    CallQueueAppend(0xf, 0, modePalette->mData, 0x140);
    CallQueueAppend(8, 0, modeScreenMap->mData, modeScreenMap->mDataSize);
    CallQueueAppend(8, 0x800, gSelectCupCourse->mUnk_24, 0x800);
    if (GetPreviousMenuScreenNumber() != 0x18 && GetPreviousMenuScreenNumber() != 0xc) {
        CallQueueAppend(0x17, 0, fixedChars->mData, fixedChars->mDataSize);
        CallQueueAppend(0x1f, 0, fixedPalette->mData, 0x140);
        CallQueueAppend(0x1b, 0, fixedScreenMap->mData, fixedScreenMap->mDataSize);
        CallQueueAppend(0x1b, 0x800, gSelectCupCourse->mUnk_24, 0x800);
    }
    CallQueueAppend(0x13, 0, courseCellChars->mData, courseCellChars->mDataSize);
    CallQueueAppend(0xe, 0, courseCellPalette->mData, 0x1a0);
    CallQueueAppend(0xe, 0x1c0, courseCellPaletteData + 0xe0, 0x40);
    CallQueueAppend(0x23, 0, cupCellChars->mData, cupCellChars->mDataSize);
    CallQueueAppend(0x1e, 0, cupCellPalette->mData, cupCellPalette->mDataSize);
}

void SetupSelectCupCourseObjects(void) {
    s32 i;
    u32 courseEntryCount;
    u32 cupEntryCount;
    SelectCupCourse *selectCupCourse;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        courseEntryCount = gSelectCupCourse->mSelectCupCourseTaOrVsMBncl->mUnk_06;
        cupEntryCount = gSelectCupCourse->mSelectCupMBncl->mUnk_06;
        for (i = 0; i < 8; i++) {
            gSelectCupCourse->mSelectCupMTable[data_0215cacc[i]].mVisible = 0;
        }
        for (i = 0; i < 4; i++) {
            gSelectCupCourse->mSelectCupMTable[data_0215ca9c[i]].mVisible = 0;
        }
        for (i = 0; i < 4; i++) {
            gSelectCupCourse->mSelectCupMTable[data_0215caa4[i]].mVisible = 0;
            gSelectCupCourse->mSelectCupMTable[cupEntryCount + data_0215cab4[i]].mVisible = 1;
        }
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[0].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[2].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[1].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[4].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[3].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[5].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount + 1].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount + 2].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount + 3].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount + 4].mVisible = 1;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount + 5].mVisible = 1;
        gSelectCupCourse->mSelectCupMTable[0x14].mVisible = 0;
        gSelectCupCourse->mSelectCupMTable[0x13].mVisible = 1;
        selectCupCourse = gSelectCupCourse;
        QueueSelectCupNameM(data_0215cadc[GetCupIndex()], selectCupCourse->mSelectCupCourseMNcer,
                            selectCupCourse->mSelectCupCourseTaOrVsMBncl, 0, 0);
        selectCupCourse = gSelectCupCourse;
        QueueSelectCupNameM(data_0215cadc[GetCupIndex()], selectCupCourse->mSelectCupMNcer,
                            selectCupCourse->mSelectCupMBncl, 0x13, 1);
        selectCupCourse = gSelectCupCourse;
        i = GetCupIndex();
        QueueCupMark(
            data_0215cadc[i], selectCupCourse->mSelectCupCourseMNcer, selectCupCourse->mSelectCupCourseTaOrVsMBncl, 5,
            func_02124a68(5, selectCupCourse->mSelectCupCourseMNcer, selectCupCourse->mSelectCupCourseTaOrVsMBncl), 0);
        for (i = 0; i < 4; i++) {
            selectCupCourse = gSelectCupCourse;
            func_0212426c(
                1, data_0215cab4[i], gSelectCupCourse->mSelectCupMBnll,
                GetBmgEntry(gSelectCupCourse->mCommonMessages, data_0215cafc[data_0215cadc[GetCupIndex()]][i]),
                selectCupCourse->mSelectCupMBncl, selectCupCourse->mSelectCupMTable);
        }
        selectCupCourse = gSelectCupCourse;
        func_0212426c(0, 2, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll,
                      GetBmgEntry(selectCupCourse->mCommonMessages, 0x73), selectCupCourse->mSelectCupCourseTaOrVsMBncl,
                      selectCupCourse->mSelectCupCourseTaOrVsMTable);
        selectCupCourse = gSelectCupCourse;
        func_0212426c(0, 4, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll,
                      GetBmgEntry(selectCupCourse->mCommonMessages, 0x74), selectCupCourse->mSelectCupCourseTaOrVsMBncl,
                      selectCupCourse->mSelectCupCourseTaOrVsMTable);
        func_02124140(0, 0, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll,
                      gSelectCupCourse->mSelectCupCourseTaOrVsMTable, gSelectCupCourse->mSelectCupCourseTaOrVsMBncl);
        func_02124140(1, 0, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll,
                      gSelectCupCourse->mSelectCupCourseTaOrVsMTable, gSelectCupCourse->mSelectCupCourseTaOrVsMBncl);
        func_02124140(2, 0, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll,
                      gSelectCupCourse->mSelectCupCourseTaOrVsMTable, gSelectCupCourse->mSelectCupCourseTaOrVsMBncl);
        func_02124140(4, 0, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll,
                      gSelectCupCourse->mSelectCupCourseTaOrVsMTable, gSelectCupCourse->mSelectCupCourseTaOrVsMBncl);
        selectCupCourse = gSelectCupCourse;
        switch (selectCupCourse->mMode) {
            case 1:
            case 2:
            case 3:
                selectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount + 2].mVisible = 0;
                gSelectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount + 3].mVisible = 0;
                gSelectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount + 4].mVisible = 0;
                gSelectCupCourse->mSelectCupCourseTaOrVsMTable[courseEntryCount + 5].mVisible = 0;
                break;
        }
    }
}

void AdvanceSelectCupCourseHighlight(void) {
    s32 i;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        for (i = 0; i < 4; i++) {
            if (gSelectCupCourse->mIndex == i && gSelectCupCourse->mUnk_54 != FALSE) {
                gSelectCupCourse->mSelectCupMTable[data_0215caa4[i]].mVisible = 1;
                func_02124100(data_0215cab4[i], 0xe, gSelectCupCourse->mSelectCupMBnll,
                              gSelectCupCourse->mSelectCupMTable, gSelectCupCourse->mSelectCupMBncl);
            } else {
                gSelectCupCourse->mSelectCupMTable[data_0215caa4[i]].mVisible = 0;
                func_02124100(data_0215cab4[i], 0xf, gSelectCupCourse->mSelectCupMBnll,
                              gSelectCupCourse->mSelectCupMTable, gSelectCupCourse->mSelectCupMBncl);
            }
        }
    }
}

void RefreshSelectCupCourseForIndex(void) {
    SelectCupCourse *selectCupCourse;
    u32 recordTime;
    u8 timeText[0x24];
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        selectCupCourse = gSelectCupCourse;
        func_0212426c(0, 0, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll,
                      GetBmgEntry(gSelectCupCourse->mCommonMessages,
                                  data_0215cafc[data_0215cadc[GetCupIndex()]][selectCupCourse->mIndex]),
                      selectCupCourse->mSelectCupCourseTaOrVsMBncl, selectCupCourse->mSelectCupCourseTaOrVsMTable);
        selectCupCourse = gSelectCupCourse;
        func_0212426c(0, 1, gSelectCupCourse->mSelectCupCourseTaOrVsMBnll,
                      GetBmgEntry(gSelectCupCourse->mCommonMessages,
                                  data_0215cafc[data_0215cadc[GetCupIndex()]][selectCupCourse->mIndex]),
                      selectCupCourse->mSelectCupCourseTaOrVsMBncl, selectCupCourse->mSelectCupCourseTaOrVsMTable);
        if (IsTimeRecordFilled(data_0215cbec[data_0215cadc[GetCupIndex()]][gSelectCupCourse->mIndex], 0)) {
            GetTimeRecordTime(data_0215cbec[data_0215cadc[GetCupIndex()]][gSelectCupCourse->mIndex], 0, &recordTime);
            func_02116b80(&recordTime, timeText);
            selectCupCourse = gSelectCupCourse;
            func_02124224(0, 3, selectCupCourse->mSelectCupCourseTaOrVsMBnll, timeText,
                          selectCupCourse->mSelectCupCourseTaOrVsMBncl, selectCupCourse->mSelectCupCourseTaOrVsMTable,
                          9);
        } else {
            selectCupCourse = gSelectCupCourse;
            func_02124224(0, 3, selectCupCourse->mSelectCupCourseTaOrVsMBnll, data_0216dbac,
                          selectCupCourse->mSelectCupCourseTaOrVsMBncl, selectCupCourse->mSelectCupCourseTaOrVsMTable,
                          9);
        }
        if (IsTimeRecordFilled(data_0215cbec[data_0215cadc[GetCupIndex()]][gSelectCupCourse->mIndex], 5)) {
            GetTimeRecordTime(data_0215cbec[data_0215cadc[GetCupIndex()]][gSelectCupCourse->mIndex], 5, &recordTime);
            func_02116b80(&recordTime, timeText);
            selectCupCourse = gSelectCupCourse;
            func_02124224(0, 5, selectCupCourse->mSelectCupCourseTaOrVsMBnll, timeText,
                          selectCupCourse->mSelectCupCourseTaOrVsMBncl, selectCupCourse->mSelectCupCourseTaOrVsMTable,
                          9);
        } else {
            selectCupCourse = gSelectCupCourse;
            func_02124224(0, 5, selectCupCourse->mSelectCupCourseTaOrVsMBnll, data_0216dbc0,
                          selectCupCourse->mSelectCupCourseTaOrVsMBncl, selectCupCourse->mSelectCupCourseTaOrVsMTable,
                          9);
        }
        TrySetCupPictureIndexAndQueueLoads(data_0215cbec[data_0215cadc[GetCupIndex()]][gSelectCupCourse->mIndex]);
        gSelectCupCourse->mCupPicturePending = TRUE;
    }
}

void SetCourseIdFromSelectCupCourse(void) {
    SetCourseId(data_0215cbec[data_0215cadc[GetCupIndex()]][gSelectCupCourse->mIndex]);
}

void func_02119e14(void) {
    SetupGhostRecordSetForCourse(data_0215cbec[data_0215cadc[GetCupIndex()]][gSelectCupCourse->mIndex]);
    func_0202949c(0);
}

#pragma thumb off
