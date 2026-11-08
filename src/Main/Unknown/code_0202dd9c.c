#include "Main/Unknown/code_0202dd9c.h"

#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025d5c.h"
#include "Main/Unknown/code_021171a0.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_0202e274.h"
#include "Main/Unknown/code_0202e43c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0204f7f4.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_02061428.h"
#include "Main/Unknown/code_0206152c.h"
#include "Main/Unknown/code_02061540.h"
#include "Main/Unknown/code_02061644.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/code_02117218.h"
#include "Main/Unknown/code_021172a8.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_02125da0.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/code_02125f2c.h"
#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/code_0212abd0.h"
#include "Main/Unknown/code_0212a910.h"
#include "Main/Unknown/unk_02153bec.h"
#include "Main/Unknown/unk_02162c74.h"
#include "code_0214d018.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02025cd0.h"
#include "registers.h"

#pragma thumb on

void InitGhostScene(void *heap) {
    Unk02125de0Arg arg;
    u8 *displaySettings;
    s32 i;
    u32 courseId;
    u8 *courseRecords;
    s32 cupCourseIndex;
    gGhostScene = HeapAlloc(heap, 0x8dc);
    MemFillWordsByBlock_inline(gGhostScene, 0x8dc);
    gGhostScene->mCourseGhostBuffer = HeapAllocAligned(heap, 0xe00, 0x20);
    gGhostScene->mSlotGhostBuffer = HeapAllocAligned(heap, 0x1000, 0x20);
    displaySettings = CreateDisplaySettings(heap, gGhostSceneDisplaySettingsDesc);
    SetBg0Record(displaySettings + 0x28, 1, 0, 0, 0, 0, 1, 0);
    SetBg3RecordParams(displaySettings + 0x70, 2, 0, 0, 0, 0xf, 0);
    InitDisplayFromSettings(displaySettings);
    LoadGhostSceneFiles();
    arg.mUnk_00 = 1;
    arg.mUnk_04 = func_020b403c(1);
    arg.mUnk_08 = 1;
    arg.mUnk_0c = 1;
    arg.mUnk_10 = 0;
    arg.mUnk_14 = 0;
    arg.mUnk_18 = NULL;
    arg.mUnk_1c = 1;
    arg.mUnk_20 = 1;
    arg.mUnk_24 = 0;
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    func_02125de0(heap, &arg);
    SetTxtSystemMode(1);
    InitLinkLevelIcons(heap, gGhostScene);
    CreateKartIcon(heap);
    for (i = 0; i < 0x20; i++) {
        gGhostScene->mCupCourseIndices[i] = -1;
    }
    for (i = 0; i < 10; i++) {
        gGhostScene->mSlotIndices[i] = -1;
    }
    gGhostScene->mCourseGhostRecords = (u8 *) CreateCourseGhostRecords((u32) heap);
    func_02061540(gGhostScene->mCourseGhostRecords);
    WaitThreadFunctionsDone();
    for (i = 0; i < 0x20; i++) {
        courseId = func_0202e43c(i);
        courseRecords = gGhostScene->mCourseGhostRecords;
        cupCourseIndex = FindCupCourseIndex(courseId);
        if (IsGhostRecordFilled(courseRecords + cupCourseIndex * 0x30) != FALSE) {
            gGhostScene->mCupCourseIndices[gGhostScene->mCourseGhostCount] = i;
            gGhostScene->mGhostCount++;
            gGhostScene->mCourseGhostCount++;
        }
    }
    gGhostScene->mSlotGhostRecords = (u8 *) func_0206152c((u32) heap);
    func_02061428(gGhostScene->mSlotGhostRecords);
    WaitThreadFunctionsDone();
    for (i = 0; i < 10; i++) {
        if (IsGhostRecordFilled(gGhostScene->mSlotGhostRecords + (u8) i * 0x230) != FALSE) {
            gGhostScene->mSlotIndices[gGhostScene->mSlotGhostCount] = i;
            gGhostScene->mGhostCount++;
            gGhostScene->mSlotGhostCount++;
        }
    }
    func_020ae6d4(gGhostScene, gGhostScene->mSubOam);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | 0x10;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffcfffef) | 0x10;
    switch (data_0217b488->mUnk_0c) {
        case 0:
            gGhostScene->mRequestedCallbacksIndex = 0;
            break;
        case 1:
            gGhostScene->mRequestedCallbacksIndex = 1;
            break;
    }
    gGhostScene->mCurrentCallbacksIndex = gGhostScene->mRequestedCallbacksIndex;
    gGhostScene->mCurrentCallbacks = gGhostSceneCallbacks[gGhostScene->mRequestedCallbacksIndex];
    gGhostScene->mHeap = CreateExpHeapFromMaxFree(heap);
    gGhostScene->mCurrentCallbacks->mInit(gGhostScene->mHeap, gGhostScene, gGhostScene->mSubOam);
}

void AdvanceGhostScene(s32 sceneNumbers) {
    s32 requestedIndex;
    s32 currentIndex;
    s32 nextIndex;
    GhostSceneCallbacks *oldCallbacks;
    requestedIndex = gGhostScene->mRequestedCallbacksIndex;
    currentIndex = gGhostScene->mCurrentCallbacksIndex;
    if (currentIndex != requestedIndex) {
        oldCallbacks = gGhostScene->mCurrentCallbacks;
        gGhostScene->mCurrentCallbacks = gGhostSceneCallbacks[requestedIndex];
        gGhostScene->mCurrentCallbacksIndex = gGhostScene->mRequestedCallbacksIndex;
        oldCallbacks->mRelease();
        gGhostScene->mCurrentCallbacks->mInit(gGhostScene->mHeap, gGhostScene, gGhostScene->mSubOam);
    } else {
        func_020ae6ac(gGhostScene, gGhostScene->mSubOam);
        nextIndex = gGhostScene->mCurrentCallbacks->mAdvance(sceneNumbers);
        if (nextIndex != -1) {
            gGhostScene->mRequestedCallbacksIndex = nextIndex;
        }
        func_020ae630(gGhostScene, gGhostScene->mSubOam);
    }
    func_02125928();
    AdvanceLinkLevelIcons();
}

void ReleaseGhostScene(void) {
    reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
    reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
    func_02125da0();
    ClearLinkLevelIconsPointer();
    ClearKartIconPointer();
    func_0204f7f4();
}

void func_0202dec8(void) {
    func_021258f0();
    gGhostScene->mCurrentCallbacks->mUnk_0c();
    func_020ae5f0(gGhostScene, gGhostScene->mSubOam);
}

#pragma thumb off

#pragma thumb on

void PrintGhostRecordInfo(SelectCharacter *fileSets, s16 (*labelRows)[4], void *name, s32 characterIndex, s32 kartIndex,
                          s32 courseId, MinuteSecondMillisecondTime *time) {
    u16 timeText[10];
    u16 terminatedName[11];
    CellFileSet *cellFileSet;
    cellFileSet = &fileSets->mUnk_038;
    func_0212426c(0, labelRows[0][0], fileSets->mUnk_000.mLabelLayout,
                  GetBmgEntry(fileSets->mUnk_058, GetCourseMessageIndex(courseId)), fileSets->mUnk_000.mCellLayout,
                  fileSets->mUnk_000.mCellTable);
    WriteMinuteSecondMillisecondText((s16 *) timeText, time->mMinute, time->mSecond, time->mMillisecond);
    func_02124224(0, labelRows[1][0], fileSets->mUnk_000.mLabelLayout, timeText, fileSets->mUnk_000.mCellLayout,
                  fileSets->mUnk_000.mCellTable, 7);
    MIi_CpuCopy16(name, terminatedName, 0x14);
    terminatedName[10] = 0;
    func_0212426c(0, labelRows[2][0], fileSets->mUnk_000.mLabelLayout, terminatedName, fileSets->mUnk_000.mCellLayout,
                  fileSets->mUnk_000.mCellTable);
    QueueCellCharsAndFirstPalette(characterIndex, cellFileSet->mCells, fileSets->mUnk_038.mChars, cellFileSet->mPalette,
                                  cellFileSet->mCellLayout, 0, labelRows[0][3], fileSets->mUnk_000.mCells,
                                  fileSets->mUnk_000.mCellLayout);
    QueueKartIcon(kartIndex, fileSets->mUnk_000.mCells, fileSets->mUnk_000.mCellLayout, labelRows[1][3],
                  GetCellPaletteIndex(labelRows[1][3], fileSets->mUnk_000.mCells, fileSets->mUnk_000.mCellLayout), 0);
}

#pragma thumb off

#pragma thumb on

void *GetCourseGhostBuffer(void) {
    return gGhostScene->mCourseGhostBuffer;
}

u32 GetSlotGhostBuffer(void) {
    return ((u32) gGhostScene->mSlotGhostBuffer);
}

u32 GetGhostCount(void) {
    return (gGhostScene->mGhostCount);
}

u32 GetCourseGhostCount(void) {
    return (gGhostScene->mCourseGhostCount);
}

u32 GetSlotGhostCount(void) {
    return (gGhostScene->mSlotGhostCount);
}

#pragma thumb off
