#include "Main/Unknown/code_02116174.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02114158.h"

#include "Main/Unknown/code_0211621c.h"
#include "Main/Unknown/code_02116244.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02114000.h"
#include "Main/Unknown/code_02116844.h"
#include "Main/Unknown/code_02116870.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_0212426c.h"
#include "00/code_02181f98.h"
#include "code_02016468.h"
#include "Main/Unknown/code_02116888.h"

#pragma thumb on

void LocateAndQueueRecordVSErase(void) {
    void *sceneFile;
    Nclr *emblemPalette;
    Ncgr *sbChars;
    Nclr *sbPalette;
    Nscr *eraseScreenMap[2];
    sbChars = NULL;
    sbPalette = NULL;
    eraseScreenMap[0] = NULL;
    sceneFile = FindSceneFile(gRecordVSMNcgrName);
    LocateNcgr2((Ncgr **) gRecordVSErase, sceneFile);
    sceneFile = FindSceneFile(gRecordVSMNcerName);
    LocateNcer(&gRecordVSErase->mRecordVSMNcer, sceneFile);
    sceneFile = FindSceneFile(gRecordVSMBnclName);
    gRecordVSErase->mRecordVSMBncl = sceneFile;
    sceneFile = FindSceneFile(gRecordVSMBnllName);
    gRecordVSErase->mRecordVSMBnll = sceneFile;
    sceneFile = FindSceneFile(gRecordVSMTransientBnclName);
    gRecordVSErase->mRecordVSMTransientBncl = sceneFile;
    sceneFile = FindSceneFile(gRecordVSMTransientBnllName);
    gRecordVSErase->mRecordVSMTransientBnll = sceneFile;
    sceneFile = FindSceneFile(gRecordVSSNcgrName);
    LocateNcgr2(&gRecordVSErase->mRecordVSSNcgr, sceneFile);
    sceneFile = FindSceneFile(gRecordVSSNcerName);
    LocateNcer(&gRecordVSErase->mRecordVSSNcer, sceneFile);
    sceneFile = FindSceneFile(gRecordVSSEraseBnclName);
    gRecordVSErase->mRecordVSSEraseBncl = sceneFile;
    sceneFile = FindSceneFile(gRecordVSSEraseBnblName);
    gRecordVSErase->mRecordVSSEraseBnbl = sceneFile;
    sceneFile = FindSceneFile(gRecordVSSEraseBnllName);
    gRecordVSErase->mRecordVSSEraseBnll = sceneFile;
    sceneFile = HeapAlloc(gRecordVSErase->mHeap, (0x00000800u));
    gRecordVSErase->mUnk_4c = sceneFile;
    sceneFile = FindSceneFile(gRecordVSSBNcgrName);
    LocateNcgr(&sbChars, sceneFile);
    sceneFile = FindSceneFile(gRecordVSSEraseNscrName);
    LocateNscr(eraseScreenMap, sceneFile);
    sceneFile = FindSceneFile(gRecordVSSBNclrName);
    LocateNclr(&sbPalette, sceneFile);
    sceneFile = FindSceneFile(gRecordVSM02NscrName);
    LocateNscr(&gRecordVSErase->mRecordVSM02Nscr, sceneFile);
    sceneFile = FindSceneFile(gRecordVSM03NscrName);
    LocateNscr(&gRecordVSErase->mRecordVSM03Nscr, sceneFile);
    emblemPalette = GetEmblemSBNclr();
    CallQueueAppend(0x17, 0, sbChars->mData, sbChars->mDataSize);
    CallQueueAppend(0x1b, 0, eraseScreenMap[0]->mData, eraseScreenMap[0]->mDataSize);
    CallQueueAppend(0x1b, (0x00000800u), gRecordVSErase->mUnk_4c, (0x00000800u));
    CallQueueAppend(0x1f, 0, sbPalette->mData, 0x40);
    CallQueueAppend(0xe, 0x40, emblemPalette->mData, 0x20);
}

#pragma thumb off

#pragma thumb on

u16 GetRecordVSEraseFirstRecordIndex(void) {
    return gRecordVSErase->mPageIndex * 5;
}

#pragma thumb off

#pragma thumb on

u32 IsRecordVSEraseRowFilled(int row) {
    int firstRecordIndex;
    int recordCount;
    firstRecordIndex = GetRecordVSEraseFirstRecordIndex();
    recordCount = GetRecordCount();
    if (recordCount > firstRecordIndex + row) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

void UpdateRecordVSEraseRows(void) {
    s32 i;
    s32 eraseCellCount;
    s32 firstRecordIndex;

    eraseCellCount = gRecordVSErase->mRecordVSSEraseBncl->mUnk_06;
    firstRecordIndex = GetRecordVSEraseFirstRecordIndex();
    for (i = 0; i < 5; i++) {
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4e8[i]].mVisible = 0;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c4f4[i]].mVisible = 0;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c500[i]].mVisible = 0;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c50c[i]].mVisible = 0;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c518[i]].mVisible = 0;
        gRecordVSErase->mRecordVSSEraseTable[data_0215c524[i]].mVisible = 0;
        gRecordVSErase->mRecordVSSEraseTable[eraseCellCount + data_0215c4b8[i]].mVisible = 0;
    }
    for (i = 0; i < 5; i++) {
        if (IsRecordVSEraseRowFilled((s16) i)) {
            if (gRecordVSErase->mIndex == i) {
                if (IsRecordFlagged(firstRecordIndex)) {
                    gRecordVSErase->mRecordVSSEraseTable[data_0215c50c[i]].mVisible = 1;
                    SetLabelPaletteIndex(data_0215c4b8[i], 0xe, gRecordVSErase->mRecordVSSEraseBnll,
                                         gRecordVSErase->mRecordVSSEraseTable, gRecordVSErase->mRecordVSSEraseBncl);
                } else {
                    gRecordVSErase->mRecordVSSEraseTable[data_0215c4f4[i]].mVisible = 1;
                    SetLabelPaletteIndex(data_0215c4b8[i], 0xe, gRecordVSErase->mRecordVSSEraseBnll,
                                         gRecordVSErase->mRecordVSSEraseTable, gRecordVSErase->mRecordVSSEraseBncl);
                }
            } else {
                if (IsRecordFlagged(firstRecordIndex)) {
                    gRecordVSErase->mRecordVSSEraseTable[data_0215c500[i]].mVisible = 1;
                    SetLabelPaletteIndex(data_0215c4b8[i], 0xe, gRecordVSErase->mRecordVSSEraseBnll,
                                         gRecordVSErase->mRecordVSSEraseTable, gRecordVSErase->mRecordVSSEraseBncl);
                } else {
                    gRecordVSErase->mRecordVSSEraseTable[data_0215c4e8[i]].mVisible = 1;
                    SetLabelPaletteIndex(data_0215c4b8[i], 0xf, gRecordVSErase->mRecordVSSEraseBnll,
                                         gRecordVSErase->mRecordVSSEraseTable, gRecordVSErase->mRecordVSSEraseBncl);
                }
            }
            gRecordVSErase->mRecordVSSEraseTable[data_0215c518[i]].mVisible = IsRecordFlagged(firstRecordIndex) ? 0 : 1;
            gRecordVSErase->mRecordVSSEraseTable[data_0215c524[i]].mVisible = IsRecordFlagged(firstRecordIndex);
            gRecordVSErase->mRecordVSSEraseTable[eraseCellCount + data_0215c4b8[i]].mVisible = 1;
        }
        firstRecordIndex++;
    }
}

void PrintRecordVSEraseShownRecord(void) {
    s32 firstRecordIndex;
    s32 i;
    s32 j;
    BOOL z;
    u16 text[0x10];
    u32 counts[3][3] = {0};
    u8 friendKeyText[0x14];
    DateBytes date;

    firstRecordIndex = GetRecordVSEraseFirstRecordIndex();
    if (GetRecordFriendKeyText(firstRecordIndex + gRecordVSErase->mShownIndex, friendKeyText)) {
        gRecordVSErase->mTransientDrawn = 1;
        CallQueueAppend(9, 0, gRecordVSErase->mRecordVSM03Nscr->mData, gRecordVSErase->mRecordVSM03Nscr->mDataSize);
    } else {
        gRecordVSErase->mTransientDrawn = 0;
        CallQueueAppend(9, 0, gRecordVSErase->mRecordVSM02Nscr->mData, gRecordVSErase->mRecordVSM02Nscr->mDataSize);
    }
    switch (gRecordVSErase->mTransientDrawn) {
        case 0:
            CopyRecordText(firstRecordIndex + gRecordVSErase->mShownIndex, text, 0x20);
            func_0212426c(0, 0, gRecordVSErase->mRecordVSMBnll, text, gRecordVSErase->mRecordVSMBncl,
                          gRecordVSErase->mRecordVSMTable);
            counts[1][0] = func_0211437c(firstRecordIndex + gRecordVSErase->mShownIndex);
            counts[1][1] = func_02114360(firstRecordIndex + gRecordVSErase->mShownIndex);
            counts[1][2] = func_02114344(firstRecordIndex + gRecordVSErase->mShownIndex);
            counts[2][0] = func_02114328(firstRecordIndex + gRecordVSErase->mShownIndex);
            counts[2][1] = func_0211430c(firstRecordIndex + gRecordVSErase->mShownIndex);
            counts[2][2] = func_021142f0(firstRecordIndex + gRecordVSErase->mShownIndex);
            for (i = 1; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    if (counts[i][j] > 0x270f) {
                        counts[i][j] = 0x270f;
                    }
                }
            }
            FormatAsciiNumber(counts[1][0], text);
            func_02124248(0, data_0215c530[1][0], gRecordVSErase->mRecordVSMBnll, text, gRecordVSErase->mRecordVSMBncl,
                          gRecordVSErase->mRecordVSMTable, 6);
            FormatAsciiNumber(counts[1][1], text);
            func_02124248(0, data_0215c530[1][1], gRecordVSErase->mRecordVSMBnll, text, gRecordVSErase->mRecordVSMBncl,
                          gRecordVSErase->mRecordVSMTable, 6);
            FormatAsciiNumber(counts[1][2], text);
            func_02124248(0, data_0215c530[1][2], gRecordVSErase->mRecordVSMBnll, text, gRecordVSErase->mRecordVSMBncl,
                          gRecordVSErase->mRecordVSMTable, 6);
            FormatAsciiNumber(counts[2][0], text);
            func_02124248(0, data_0215c530[2][0], gRecordVSErase->mRecordVSMBnll, text, gRecordVSErase->mRecordVSMBncl,
                          gRecordVSErase->mRecordVSMTable, 6);
            FormatAsciiNumber(counts[2][1], text);
            func_02124248(0, data_0215c530[2][1], gRecordVSErase->mRecordVSMBnll, text, gRecordVSErase->mRecordVSMBncl,
                          gRecordVSErase->mRecordVSMTable, 6);
            FormatAsciiNumber(counts[2][2], text);
            func_02124248(0, data_0215c530[2][2], gRecordVSErase->mRecordVSMBnll, text, gRecordVSErase->mRecordVSMBncl,
                          gRecordVSErase->mRecordVSMTable, 6);
            GetRecordDate(firstRecordIndex + gRecordVSErase->mShownIndex, &date);
            FormatDate(&date, text);
            func_02124224(0, 0xc, gRecordVSErase->mRecordVSMBnll, text, gRecordVSErase->mRecordVSMBncl,
                          gRecordVSErase->mRecordVSMTable, 6);
            ReadRecordEmblem(firstRecordIndex + gRecordVSErase->mShownIndex, gRecordVSErase->mEmblem,
                             gRecordVSErase->mEmblemConverted);
            CallQueueAppend(0x13,
                            GetCellCharIndex(3, gRecordVSErase->mRecordVSMNcer, gRecordVSErase->mRecordVSMBncl) << 5,
                            gRecordVSErase->mEmblemConverted, 0x200);
            break;
        case 1:
            CopyRecordText(firstRecordIndex + gRecordVSErase->mShownIndex, text, 0x20);
            func_0212426c(0, 0, gRecordVSErase->mRecordVSMTransientBnll, text, gRecordVSErase->mRecordVSMTransientBncl,
                          gRecordVSErase->mRecordVSMTransientTable);
            z = FALSE;
            for (i = 0; i < 12; i++) {
                FormatAsciiNumber(friendKeyText[i] - 0x30, text);
                func_0212426c(z, data_0215c584[i], gRecordVSErase->mRecordVSMTransientBnll, text,
                              gRecordVSErase->mRecordVSMTransientBncl, gRecordVSErase->mRecordVSMTransientTable);
            }
            ReadRecordEmblem(firstRecordIndex + gRecordVSErase->mShownIndex, gRecordVSErase->mEmblem,
                             gRecordVSErase->mEmblemConverted);
            CallQueueAppend(
                0x13, GetCellCharIndex(1, gRecordVSErase->mRecordVSMNcer, gRecordVSErase->mRecordVSMTransientBncl) << 5,
                gRecordVSErase->mEmblemConverted, 0x200);
            break;
    }
}

void func_02116244(void) {
    s32 firstRecordIndex;
    s32 i;
    u8 nameText[0x20];

    firstRecordIndex = GetRecordVSEraseFirstRecordIndex();
    for (i = 0; i < 5; i++) {
        if (GetRecordCount() > firstRecordIndex + i) {
            CopyRecordText(firstRecordIndex + i, nameText, 0x20);
            func_0212426c(1, data_0215c4b8[i], gRecordVSErase->mRecordVSSEraseBnll, nameText,
                          gRecordVSErase->mRecordVSSEraseBncl, gRecordVSErase->mRecordVSSEraseTable);
        }
    }
    if (GetRecordCount() <= firstRecordIndex + gRecordVSErase->mIndex) {
        gRecordVSErase->mIndex = GetRecordCount() % 5 - 1;
        gRecordVSErase->mShownIndex = gRecordVSErase->mIndex;
    }
    PrintRecordVSEraseShownRecord();
}

#pragma thumb off

#pragma thumb on
u32 IncrementRecordVSErasePageIndex(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gRecordVSErase;
    value1 = *(const u32 *) ((value0) + 0u);
    value0 = 118u;
    value0 = *(const s16 *) ((value1) + (value0));
    value0 = (value0) + (1u);
    value1 = (value1) + 118u;
    *(u16 *) ((value1) + 0u) = value0;
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 DecrementRecordVSErasePageIndex(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gRecordVSErase;
    value1 = *(const u32 *) ((value0) + 0u);
    value0 = 118u;
    value0 = *(const s16 *) ((value1) + (value0));
    value0 = (value0) - (1u);
    value1 = (value1) + 118u;
    *(u16 *) ((value1) + 0u) = value0;
    return value0;
}
#pragma thumb off

#pragma thumb on

void IncrementRecordVSEraseIndex(void) {
    int rowFilled;
    int nextIndex;
    nextIndex = (gRecordVSErase->mIndex + 1) * 0x10000 >> 0x10;
    rowFilled = IsRecordVSEraseRowFilled(nextIndex);
    if ((rowFilled == 0) || (5 <= nextIndex)) {
        nextIndex = 0;
    }
    if (gRecordVSErase->mIndex != nextIndex) {
        NNS_SndArcPlayerStartSeqArc((const void *) (((u32) ((u8 *) &data_0217d068))), 0, 0);
    }
    gRecordVSErase->mIndex = nextIndex;
}

void DecrementRecordVSEraseIndex(void) {
    int rowFilled;
    int recordCount;
    int recordsOnLastPage;
    int previousIndex;
    previousIndex = (gRecordVSErase->mIndex + -1) * 0x10000 >> 0x10;
    if (previousIndex < 0) {
        previousIndex = 4;
        rowFilled = IsRecordVSEraseRowFilled(4);
        if (rowFilled == 0) {
            recordCount = GetRecordCount();
            recordsOnLastPage = (recordCount) % 5;
            previousIndex = (recordsOnLastPage + -1) * 0x10000 >> 0x10;
        }
    }
    if (gRecordVSErase->mIndex != previousIndex) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
    }
    gRecordVSErase->mIndex = previousIndex;
}

#pragma thumb off
