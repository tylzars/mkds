#include "Main/Unknown/code_020336ec.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bc8.h"
#include "code_02148950.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02016468.h"
#include "code_0214cfe4.h"

// Fills with 0 through a halfword stack offset of its own.
static inline void func_020338f8_inline(void *buffer, s32 byteCount) {
    volatile u16 fillValue = 0;
    MIi_CpuClear16(fillValue, buffer, byteCount);
}

#pragma thumb on

void func_02033c80(s32 entryIndex) {
    CellFileSet *subCellFileSet;
    s32 orderIndex;
    BOOL isTeamIndex1;
    BOOL c;
    BOOL d;
    BOOL e;

    subCellFileSet = &gResultsBattle->mCellFileSets[1];
    if (gResultsBattle->mOwnEntryIndex == entryIndex) {
        d = TRUE;
    } else {
        d = FALSE;
    }
    orderIndex = gResultsBattle->mEntries[entryIndex].mOrderIndex;
    if (gRaceSetup->mUseTeams != 0) {
        if (gRaceSetup->mCurrentEntries[(u16) entryIndex].mPlayer.mTeamIndex == 1) {
            isTeamIndex1 = TRUE;
        } else {
            isTeamIndex1 = FALSE;
        }
        e = FALSE;
        if (isTeamIndex1 == FALSE) {
            c = TRUE;
        } else {
            c = FALSE;
        }
        if (c != FALSE && d != FALSE) {
            e = TRUE;
        }
        subCellFileSet->mCellTable[orderIndex + 0x10].mVisible = e;
        if (c != FALSE && d == FALSE) {
            c = TRUE;
        } else {
            c = FALSE;
        }
        subCellFileSet->mCellTable[orderIndex + 0x18].mVisible = c;
        if (isTeamIndex1 != FALSE && d != FALSE) {
            c = TRUE;
        } else {
            c = FALSE;
        }
        subCellFileSet->mCellTable[orderIndex + 0x20].mVisible = c;
        if (isTeamIndex1 != FALSE && d == FALSE) {
            d = TRUE;
        } else {
            d = FALSE;
        }
        subCellFileSet->mCellTable[orderIndex + 0x28].mVisible = d;
        subCellFileSet->mCellTable[orderIndex + 8].mVisible = 0;
        subCellFileSet->mCellTable[orderIndex].mVisible = subCellFileSet->mCellTable[orderIndex + 8].mVisible;
    } else {
        subCellFileSet->mCellTable[orderIndex].mVisible = d;
        if (d == FALSE) {
            d = TRUE;
        } else {
            d = FALSE;
        }
        subCellFileSet->mCellTable[orderIndex + 8].mVisible = d;
        subCellFileSet->mCellTable[orderIndex + 0x28].mVisible = 0;
        subCellFileSet->mCellTable[orderIndex + 0x20].mVisible = subCellFileSet->mCellTable[orderIndex + 0x28].mVisible;
        subCellFileSet->mCellTable[orderIndex + 0x18].mVisible = subCellFileSet->mCellTable[orderIndex + 0x20].mVisible;
        subCellFileSet->mCellTable[orderIndex + 0x10].mVisible = subCellFileSet->mCellTable[orderIndex + 0x18].mVisible;
    }
}

void func_02033b80(s32 entryIndex) {
    CellFileSet *subCellFileSet;
    s32 r;
    s32 score;
    s32 length;
    u16 scoreText[4];

    subCellFileSet = &gResultsBattle->mCellFileSets[1];
    r = gResultsBattle->mEntries[entryIndex].mOrderIndex;
    score = gResultsBattle->mEntries[entryIndex].mScore;
    if (gRaceSetup->mMode == MODE_BATTLE && gRaceSetup->mUseTeams != 0 && gRaceSetup->mRuleKind == 1) {
        subCellFileSet->mCellTable[r + 0x38].mVisible = 0;
        subCellFileSet->mCellTable[r + 0x48].mVisible = 0;
        return;
    }
    length = 0;
    func_020338f8_inline(scoreText, 8);
    if (score >= 100) {
        scoreText[length++] = 0x30 + (score / 100) % 10;
    }
    if (score >= 10) {
        scoreText[length++] = 0x30 + (score / 10) % 10;
    }
    scoreText[length++] = 0x30 + score % 10;
    scoreText[length] = 0;
    func_02124224(1, r + 8, subCellFileSet->mLabelLayout, scoreText, subCellFileSet->mCellLayout,
                  subCellFileSet->mCellTable, 6);
    r += 0x38;
    subCellFileSet->mCellTable[r].mVisible = 1;
    func_02025c48(r, gResultsBattle->mEntries[entryIndex].mRank + 0x40, subCellFileSet->mCellLayout);
}

void func_02033ab8(s32 cellFileSetIndex, s32 entryIndex, s32 cellIndex, s32 d) {
    CellFileSet *iconCellFileSet;
    CellFileSet *cellFileSet;
    s32 characterIndex;
    Nclr *palette;
    u8 *paletteBlock;
    u8 v;
    u32 shuffledIndex;

    cellFileSet = &gResultsBattle->mCellFileSets[cellFileSetIndex];
    if (d == 1) {
        iconCellFileSet = &gResultsBattle->mCellFileSets[2];
    } else {
        iconCellFileSet = &gResultsBattle->mCellFileSets[3];
    }
    characterIndex = gRaceSetup->mCurrentEntries[(u16) entryIndex].mCharacterIndex;
    func_0212463c(characterIndex, iconCellFileSet->mCells, iconCellFileSet->mChars, iconCellFileSet->mPalette,
                  iconCellFileSet->mCellLayout, cellFileSetIndex, cellIndex, cellFileSet->mCells,
                  cellFileSet->mCellLayout);
    if (characterIndex == 0xc) {
        if (d == 1) {
            palette = gResultsBattle->mUnk_0c0;
        } else {
            palette = gResultsBattle->mUnk_0c4;
        }
        v = func_02124a68(cellIndex, cellFileSet->mCells, cellFileSet->mCellLayout);
        shuffledIndex = data_0217b488->mShuffledIndices[entryIndex];
        paletteBlock = shuffledIndex * 0x20 + (u8 *) palette->mData;
        if (cellFileSetIndex == 0) {
            CallQueueAppend(0xe, v << 5, paletteBlock, 0x20);
        } else {
            CallQueueAppend(0x1e, v << 5, paletteBlock, 0x20);
        }
    }
}

void func_02033a0c(void *heap) {
    s32 index;
    u32 remainingObjSize;
    CellFileSet *mainCellFileSet;
    u8 *labelEntry;
    u16 entryName[11];

    remainingObjSize = GX_GetSizeOfOBJ();
    mainCellFileSet = &gResultsBattle->mCellFileSets[0];
    gResultsBattle->mTimerDigitCellBase = 1;
    gResultsBattle->mTimerTensCell = 0xb;
    index = 0;
    if ((s32) mainCellFileSet->mLabelLayout->mUnk_06 > 0) {
        labelEntry = data_usa_02153e98;
        do {
            remainingObjSize -= func_02025a00(0, heap, mainCellFileSet, labelEntry, remainingObjSize);
            labelEntry += 8;
            index++;
        } while (index < mainCellFileSet->mLabelLayout->mUnk_06);
    }
    func_020338f8_inline(entryName, 0x16);
    CopyKartEntryName((u16) gResultsBattle->mOwnEntryIndex, entryName, 1);
    func_0212426c(0, 0, mainCellFileSet->mLabelLayout, entryName, mainCellFileSet->mCellLayout,
                  mainCellFileSet->mCellTable);
    func_02033ab8(0, gResultsBattle->mOwnEntryIndex, 0, 1);
}

void func_020338f8(void *heap) {
    CellFileSet *mainCellFileSet;
    s32 n;
    s32 j;
    s32 entryIndex;
    s32 cellCount;
    u32 remainingObjSize;
    u8 *labelEntry;
    u16 entryName[11];
    s32 labelCount;
    LayoutTableEntry *cell;

    mainCellFileSet = &gResultsBattle->mCellFileSets[0];
    remainingObjSize = GX_GetSizeOfOBJ();
    n = 0;
    cellCount = mainCellFileSet->mCellLayout->mUnk_06;
    gResultsBattle->mTimerDigitCellBase = 8;
    gResultsBattle->mTimerTensCell = 0x12;
    j = 0;
    labelCount = mainCellFileSet->mLabelLayout->mUnk_06;
    if (labelCount > 0) {
        labelEntry = data_usa_02153ec0;
        do {
            remainingObjSize -= func_02025a00(n, heap, mainCellFileSet, labelEntry, remainingObjSize);
            labelEntry += 8;
            j++;
        } while (j < mainCellFileSet->mLabelLayout->mUnk_06);
    }
    func_0212426c(0, 0, mainCellFileSet->mLabelLayout, GetBmgEntry(gResultsBattle->mCommonMessages, 0x7a),
                  mainCellFileSet->mCellLayout, mainCellFileSet->mCellTable);
    for (entryIndex = 0; entryIndex < gResultsBattle->mKartCount; entryIndex++) {
        if (gResultsBattle->mEntries[entryIndex].mRank == 0) {
            func_020338f8_inline(entryName, 0x16);
            CopyKartEntryName((u16) entryIndex, entryName, 1);
            n++;
            func_0212426c(0, n, mainCellFileSet->mLabelLayout, entryName, mainCellFileSet->mCellLayout,
                          mainCellFileSet->mCellTable);
        }
    }
    while (n < 7) {
        n = n + 1;
        mainCellFileSet->mCellTable[n].mVisible = 0;
        n = (u32) n;
        cell = &mainCellFileSet->mCellTable[n + cellCount];
        cell->mVisible = 0;
    }
}

void func_02033840(void *heap) {
    CellFileSet *mainCellFileSet;
    s32 count;
    s32 iconCellBase;
    BOOL e;
    s32 i;

    mainCellFileSet = &gResultsBattle->mCellFileSets[0];
    count = gResultsBattle->mUnk_0d4;
    iconCellBase = count + data_usa_02153ea0[count - 2];
    if (count > 4) {
        e = FALSE;
    } else {
        e = TRUE;
    }
    gResultsBattle->mTimerDigitCellBase = 0x46;
    gResultsBattle->mTimerTensCell = 0x50;
    for (i = 0; i < 0x46; i++) {
        mainCellFileSet->mCellTable[i].mVisible = 0;
    }
    for (i = data_usa_02153ea0[gResultsBattle->mUnk_0d4 - 2];
         i < data_usa_02153ea0[gResultsBattle->mUnk_0d4 - 2] + gResultsBattle->mUnk_0d4 * 2; i++) {
        mainCellFileSet->mCellTable[i].mVisible = 1;
    }
    for (i = 0; i < gResultsBattle->mUnk_0d4; i++) {
        func_02033ab8(0, i, iconCellBase + i, e);
    }
}

void func_020336ec(void *heap) {
    ResultsBattle *results;
    CellFileSet *mainCellFileSet;
    s32 teamIndex;
    s32 count;
    s32 iconCellBase;
    s32 f;
    s32 placedCount;
    s32 i;
    BOOL e;
    s32 j;
    s32 k;
    s32 entryIndex;

    results = gResultsBattle;
    mainCellFileSet = &results->mCellFileSets[0];
    switch (results->mFileSetKind) {
        case 3:
            teamIndex = 0;
            break;
        default:
            teamIndex = 1;
            break;
    }
    placedCount = 0;
    count = results->mUnk_0d4;
    iconCellBase = count + data_usa_02153eb0[count - 1];
    if (count <= 5) {
        e = TRUE;
        f = 0x38;
    } else {
        e = FALSE;
        f = 0x39;
    }
    results->mTimerDigitCellBase = 0x3a;
    gResultsBattle->mTimerTensCell = 0x44;
    for (i = 0; i < 0x38; i++) {
        mainCellFileSet->mCellTable[i].mVisible = 0;
    }
    j = data_usa_02153eb0[gResultsBattle->mUnk_0d4 - 1];
    j = (u32) j;
    if (j < data_usa_02153eb0[gResultsBattle->mUnk_0d4 - 1] + gResultsBattle->mUnk_0d4 * 2) {
        do {
            mainCellFileSet->mCellTable[j].mVisible = 1;
            j++;
        } while (j < data_usa_02153eb0[gResultsBattle->mUnk_0d4 - 1] + gResultsBattle->mUnk_0d4 * 2);
    }
    if (gResultsBattle->mFileSetKind == 3) {
        for (k = data_usa_02153eb0[gResultsBattle->mUnk_0d4 - 1];
             k < gResultsBattle->mUnk_0d4 + data_usa_02153eb0[gResultsBattle->mUnk_0d4 - 1]; k++) {
            func_02025c48(k, f, mainCellFileSet->mCellLayout);
        }
    }
    for (entryIndex = 0; entryIndex < gResultsBattle->mKartCount; entryIndex++) {
        if (teamIndex == gRaceSetup->mCurrentEntries[(u16) entryIndex].mPlayer.mTeamIndex) {
            func_02033ab8(0, entryIndex, iconCellBase + placedCount, e);
            placedCount++;
        }
    }
    mainCellFileSet->mCellTable[0x39].mVisible = 0;
    mainCellFileSet->mCellTable[0x38].mVisible = mainCellFileSet->mCellTable[0x39].mVisible;
}

#pragma thumb off
