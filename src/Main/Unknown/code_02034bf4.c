#include "Main/Unknown/code_02034bf4.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_0202dd9c.h"
#include "Main/Unknown/code_0202db04.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025b84.h"
#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_02025d5c.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02125ed0.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_0212775c.h"
#include "code_02148950.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02163000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02174000.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02025edc.h"
#include "Main/Unknown/code_02025f80.h"
#include "Main/Unknown/code_0204f240.h"

#pragma thumb on

void func_02035114(void) {
    Unk02174e64 *object;
    CellFileSet *subCellFileSet;
    s32 i;

    object = data_02174e64;
    subCellFileSet = &object->mCellFileSets[1];
    if (object->mSelectedIndex < 0) {
        for (i = 0; i < 4; i++) {
            if (object->mGhostInfoEntries[i].mFilled != FALSE) {
                object->mSelectedIndex = i;
                subCellFileSet->mCellTable[4].mVisible = 1;
                func_02025c6c(4, data_02164254[i][3], subCellFileSet->mCellLayout);
                return;
            }
        }
    } else {
        if (object->mFilledCount == 0) {
            subCellFileSet->mCellTable[4].mVisible = 0;
            data_02174e64->mSelectedIndex = -1;
            return;
        }
        if (object->mGhostInfoEntries[object->mSelectedIndex].mFilled == FALSE) {
            for (i = 0; i < 4; i++) {
                if (object->mGhostInfoEntries[i].mFilled != FALSE) {
                    object->mSelectedIndex = i;
                    return;
                }
            }
        }
    }
}

void func_02035060(void) {
    CellFileSet *subCellFileSet;
    s32 cellCount;
    s32 i;
    s16 interpolatedValue;
    s16 v;

    subCellFileSet = &data_02174e64->mCellFileSets[1];
    cellCount = subCellFileSet->mCellLayout->mUnk_06;
    for (i = 0; i < 4; i++) {
        AdvanceInterpolation(&data_02174e64->mGhostInfoEntries[i].mInterpolation);
        interpolatedValue = GetInterpolatedValue(&data_02174e64->mGhostInfoEntries[i].mInterpolation);
        subCellFileSet->mCellTable[cellCount + data_02164254[i + 4][0]].mOffsetX = interpolatedValue;
        v = subCellFileSet->mCellTable[cellCount + ((const s16(*)[4]) data_02164254)[i + 4][0]].mOffsetX;
        subCellFileSet->mCellTable[cellCount + data_02164254[i][0]].mOffsetX = v;
        v = subCellFileSet->mCellTable[cellCount + data_02164254[i][0]].mOffsetX;
        subCellFileSet->mCellTable[data_02164254[i][3]].mOffsetX = v;
        if (data_02174e64->mSelectedIndex == i) {
            subCellFileSet->mCellTable[4].mOffsetX = interpolatedValue;
        }
    }
}

void func_02034fec(void) {
    CellFileSet *mainCellFileSet;
    CellFileSet *subCellFileSet;
    s32 mainEntryCount;
    s32 subEntryCount;
    s32 i;
    s16 offset;

    mainCellFileSet = &data_02174e64->mCellFileSets[0];
    subCellFileSet = &data_02174e64->mCellFileSets[1];
    mainEntryCount = mainCellFileSet->mCellLayout->mUnk_06 + mainCellFileSet->mLabelLayout->mUnk_06;
    subEntryCount = subCellFileSet->mCellLayout->mUnk_06 + subCellFileSet->mLabelLayout->mUnk_06;
    offset = GetInterpolatedValue(&data_02174e64->mUnk_194);
    for (i = 0; i < mainEntryCount; i++) {
        mainCellFileSet->mCellTable[i].mOffsetY = -offset;
    }
    for (i = 0; i < subEntryCount; i++) {
        subCellFileSet->mCellTable[i].mOffsetY = offset;
    }
}

void func_02034f60(void) {
    GhostInfoEntry *selectedEntry;
    s32 i;
    CellFileSet *mainCellFileSet;
    s32 entryCount;
    BOOL hasSelection;

    mainCellFileSet = &data_02174e64->mCellFileSets[0];
    selectedEntry = &data_02174e64->mGhostInfoEntries[data_02174e64->mSelectedIndex];
    entryCount = mainCellFileSet->mCellLayout->mUnk_06 + mainCellFileSet->mLabelLayout->mUnk_06;
    for (i = 0; i < entryCount; i++) {
        if (data_02174e64->mSelectedIndex >= 0) {
            hasSelection = TRUE;
        } else {
            hasSelection = FALSE;
        }
        mainCellFileSet->mCellTable[i].mVisible = hasSelection;
    }
    if (data_02174e64->mSelectedIndex >= 0) {
        PrintGhostRecordInfo((Unk02174e14 *) &data_02174e64->mCellFileSets[0], data_02154034, selectedEntry,
                             selectedEntry->mInfo.mUnk_18[0], selectedEntry->mInfo.mUnk_18[1],
                             selectedEntry->mInfo.mUnk_18[2],
                             (MinuteSecondMillisecondTime *) &selectedEntry->mInfo.mMillisecond);
    }
}

void func_02034ef0(void) {
    s32 i;
    CellFileSet *subCellFileSet;
    s32 v;
    s32 w;

    subCellFileSet = &data_02174e64->mCellFileSets[1];
    for (i = 0; i < 4; i++) {
        w = i + 4;
        if (i == data_02174e64->mSelectedIndex) {
            v = 14;
        } else {
            v = 15;
        }
        SetLabelPaletteIndex(w, v, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable,
                             subCellFileSet->mCellLayout);
        SetLabelPaletteIndex(i, v, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable,
                             subCellFileSet->mCellLayout);
    }
    if (data_02174e64->mSelectedIndex >= 0) {
        func_02025c6c(4, data_02164254[data_02174e64->mSelectedIndex][3], subCellFileSet->mCellLayout);
    }
}

BOOL AreGhostRecordInfosDifferent(GhostRecordInfo *storedInfo, GhostRecordInfo *newInfo) {
    s32 i;
    s32 nameDiffers;
    BOOL halfwordDiffers;

    nameDiffers = 0;
    for (i = 0; i < 11; i++) {
        if (storedInfo->mName[i] != newInfo->mName[i]) {
            halfwordDiffers = TRUE;
        } else {
            halfwordDiffers = FALSE;
        }
        nameDiffers |= halfwordDiffers;
    }
    if (nameDiffers != 0 || storedInfo->mUnk_18[1] != newInfo->mUnk_18[1] ||
        storedInfo->mUnk_18[0] != newInfo->mUnk_18[0] || storedInfo->mUnk_18[2] != newInfo->mUnk_18[2] ||
        storedInfo->mMinute != newInfo->mMinute || storedInfo->mSecond != newInfo->mSecond ||
        storedInfo->mMillisecond != newInfo->mMillisecond) {
        return TRUE;
    }
    return FALSE;
}

void func_02034bf4(void *parentHeap, void *b, void *c) {
    void *heap;
    CellFileSet *cellFileSet;
    u32 remainingObjSize;
    s32 i;
    s32 j;
    s32 assignedCount;
    s32 cellCount;
    s16 *row;
    BOOL z;

    heap = CreateFrmHeapFromMaxFree(parentHeap);
    data_02174e64 = HeapAlloc(heap, 0x1a8);
    MemFillWordsByBlock_inline(data_02174e64, 0x1a8);
    data_02174e64->mHeap = heap;
    data_02174e64->mUnk_024[0] = b;
    data_02174e64->mUnk_024[1] = c;
    data_02174e64->mCommonMessages = FindFileInLoadedArchives(data_02164294);
    data_02174e64->mGhostMessages = FindSceneFile(data_021642a0);
    InitBlockEntries(data_02174e64->mHeap, 2);
    data_02174e64->mSelectedIndex = -1;
    for (i = 0; i < 4; i++) {
        SetupInterpolation(&data_02174e64->mGhostInfoEntries[i].mInterpolation, 3, 10, 0x100, 0);
    }
    func_020258d4(0, data_02174e64, data_021642ac, data_021642cc, data_021642ec, 0, FindSceneFile);
    cellFileSet = &data_02174e64->mCellFileSets[0];
    remainingObjSize = GX_GetSizeOfOBJ();
    LocateCellFileSet(cellFileSet, data_02164308, data_02164328, data_02164348, gTimeAttackGhostGetMBnclName,
                      gTimeAttackGhostGetMBnllName, NULL, FindSceneFile);
    z = FALSE;
    func_02025a50(0, data_02174e64->mHeap, cellFileSet);
    i = 0;
    if (i < cellFileSet->mLabelLayout->mUnk_06) {
        row = (s16 *) data_02154034;
        do {
            remainingObjSize -= func_02025a00(z, data_02174e64->mHeap, cellFileSet, row, remainingObjSize);
            row += 4;
            i++;
        } while (i < cellFileSet->mLabelLayout->mUnk_06);
    }
    j = cellFileSet->mCellLayout->mUnk_06 + cellFileSet->mLabelLayout->mUnk_06;
    for (i = 0; i < j; i++) {
        cellFileSet->mCellTable[i].mVisible = 0;
    }
    cellFileSet = &data_02174e64->mCellFileSets[1];
    remainingObjSize = GX_GetSizeOfSubOBJ();
    assignedCount = 0;
    LocateCellFileSet(cellFileSet, data_021643a0, data_021643c0, data_021643e0, gTimeAttackGhostGetSSelBnclName,
                      gTimeAttackGhostGetSSelBnllName, gTimeAttackGhostGetSSelBnblName, FindSceneFile);
    func_02025a50(1, data_02174e64->mHeap, cellFileSet);
    cellCount = cellFileSet->mCellLayout->mUnk_06;
    i = 0;
    if (i < cellFileSet->mLabelLayout->mUnk_06) {
        row = (s16 *) data_02164254;
        do {
            if (row[3] < 0) {
                row[3] = cellCount + assignedCount++;
            }
            remainingObjSize -= func_02025a00(1, data_02174e64->mHeap, cellFileSet, data_02164254[i], remainingObjSize);
            row += 4;
            i++;
        } while (i < cellFileSet->mLabelLayout->mUnk_06);
    }
    for (j = 0; j < cellCount; j++) {
        func_021249a8(j, 3, cellFileSet->mCells, cellFileSet->mCellLayout);
    }
    cellFileSet->mCellTable[4].mVisible = 0;
    func_02025b84(0, &data_02174e64->mUnk_064);
    SetupInterpolation(&data_02174e64->mUnk_194, 3, 10, -0xc0, 0);
    SetSelectReturnSoundId(0xf);
    FrmHeapShrinkInParent(data_02174e64->mHeap);
}

#pragma thumb off
