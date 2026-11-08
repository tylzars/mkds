#include "Main/Unknown/code_020307b8.h"
#include "Main/Unknown/code_020302a0.h"
#include "Main/Unknown/code_0202f688.h"
#include "Main/Unknown/code_02030a10.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_0204f7f4.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_0212775c.h"
#include "code_02148950.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02163000.h"
#include "Main/Unknown/unk_02174000.h"
#include "code_02016468.h"
#include "code_0214d018.h"

#pragma optimize_for_size on

#pragma thumb on

void SetMultiSelectNSCellTableOffsetY(void) {
    MultiSelectNS *multiSelectNS;
    s32 i;
    s32 entryCount;

    multiSelectNS = gMultiSelectNS;
    entryCount = func_02030a18(multiSelectNS->mBncl) + func_02030a10(multiSelectNS->mBnll);
    for (i = 0; i < entryCount; i++) {
        multiSelectNS->mCellTable[i].mOffsetY = gMultiSelectNS->mOffset;
    }
}

void RefreshMultiSelectNS(s32 showSelected) {
    u32 valueTable[2];
    s32 i;
    MultiSelectNS *multiSelectNS;
    s32 rowSelected;
    s32 rowNotSelected;
    BOOL z1;
    BOOL z2;
    u16 *rowCellIndices;
    u32 firstValue;
    u32 secondValue;

    multiSelectNS = gMultiSelectNS;
    firstValue = *(volatile u32 *) &gMultiSelectNSLabelValues[0];
    secondValue = *(volatile u32 *) &gMultiSelectNSLabelValues[1];
    valueTable[0] = firstValue;
    valueTable[1] = secondValue;
    z1 = FALSE;
    z2 = FALSE;
    for (i = 0; i < 2; i++) {
        if (gMultiSelectNS->mIndex == i && showSelected != 0) {
            rowSelected = 1;
        } else {
            rowSelected = z1;
        }
        rowCellIndices = gMultiSelectNSRowCellIndices[i];
        multiSelectNS->mCellTable[rowCellIndices[0]].mVisible = rowSelected;
        if (rowSelected == 0) {
            rowNotSelected = 1;
        } else {
            rowNotSelected = z2;
        }
        multiSelectNS->mCellTable[rowCellIndices[1]].mVisible = rowNotSelected;
        SetLabelPaletteIndex(rowCellIndices[2], valueTable[rowSelected], multiSelectNS->mBnll,
                             multiSelectNS->mCellTable, multiSelectNS->mBncl);
    }
}

#pragma thumb off

void func_02030930(void *destination, u32 value, u32 size) {
    volatile u32 valueCopy = value;
    MIi_CpuClearFast(valueCopy, destination, size);
}

void func_0203091c(void *destination, u32 size) {
    func_02030930(destination, 0, size);
}

#pragma thumb on

void InitMultiSelectNS(void *parentHeap, void *scene, void *oamList) {
    void *heap;
    MultiSelectNS *multiSelectNS;
    Unk02153d2c *labelMessageRow;
    s32 i;
    u32 subObjSizeLeft;
    s32 labelIndex;

    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gMultiSelectNS = HeapAlloc(heap, 0x40);
    func_0203091c(gMultiSelectNS, 0x40);
    gMultiSelectNS->mHeap = heap;
    gMultiSelectNS->mUnk_1c = scene;
    gMultiSelectNS->mOamList = oamList;
    gMultiSelectNS->mBannerMessages = FindSceneFile(data_0216362c);
    gMultiSelectNS->mOffset = -0xc0;
    subObjSizeLeft = GX_GetSizeOfSubOBJ();
    multiSelectNS = gMultiSelectNS;
    LocateNcgr2(&multiSelectNS->mNcgr, FindSceneFile(data_02163638));
    LocateNcer(&multiSelectNS->mNcer, FindSceneFile(data_02163654));
    LocateNclr(&multiSelectNS->mNclr, FindSceneFile(data_02163670));
    multiSelectNS->mBncl = FindSceneFile(gMultiSelectNSSBnclName);
    multiSelectNS->mBnbl = FindSceneFile(gMultiSelectNSSBnblName);
    multiSelectNS->mBnll = FindSceneFile(gMultiSelectNSSBnllName);
    InitLayoutTable(gMultiSelectNS->mHeap, multiSelectNS->mBncl, multiSelectNS->mBnll, &multiSelectNS->mCellTable);
    for (i = 0; i < 2; i++) {
        labelMessageRow = &gMultiSelectNSLabelMessageRows[i];
        labelIndex = labelMessageRow->mUnk_00;
        subObjSizeLeft -=
            InitLabelCanvas(gMultiSelectNS->mHeap, labelIndex, multiSelectNS->mBnll, labelMessageRow->mUnk_02,
                            labelMessageRow->mUnk_04, labelMessageRow->mUnk_06, multiSelectNS->mNcer,
                            multiSelectNS->mBncl, multiSelectNS->mCellTable, subObjSizeLeft);
        func_0212426c(1, labelIndex, multiSelectNS->mBnll,
                      GetBmgEntry(gMultiSelectNS->mBannerMessages, labelMessageRow->mUnk_08), multiSelectNS->mBncl,
                      multiSelectNS->mCellTable);
    }
    CallQueueAppend(0x23, 0, multiSelectNS->mNcgr->mData, multiSelectNS->mNcgr->mDataSize);
    CallQueueAppend(0x1e, 0, multiSelectNS->mNclr->mData, multiSelectNS->mNclr->mDataSize);
    RefreshMultiSelectNS(1);
    SetSelectReturnSoundId(0xe);
    func_0204f804();
    FrmHeapShrinkInParent(gMultiSelectNS->mHeap);
}

#pragma thumb off
