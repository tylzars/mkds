#include "Main/Unknown/code_0202e4b0.h"
#include "Main/Unknown/code_0202e680.h"
#include "Main/Unknown/code_0202e68c.h"
#include "Main/Unknown/code_0202ecd4.h"
#include "Main/Unknown/code_0202edfc.h"
#include "Main/Unknown/code_0202ee3c.h"
#include "Main/Unknown/code_0202ee88.h"
#include "Main/Unknown/code_0202f0a8.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"

#pragma optimize_for_size on

#pragma thumb on

void InitScrollList(void *heap, s32 b, const void *groupFirstEntries, u16 cursorEntry, u16 e, s32 f,
                    Unk02124b1c *entries, void *rects, const void *screenMap, s32 upRectIndex, s32 downRectIndex,
                    s32 firstRowRectIndex, s32 rowCount,
                    void (*callback)(int heap, int b, int groupFirstEntries, int cursorEntry)) {
    s32 row;
    gScrollList = HeapAlloc(heap, 0x674);
    func_0202e68c(gScrollList, 0x674);
    gScrollList->mGroupCount = b;
    b = b * 2;
    gScrollList->mGroupFirstEntries = HeapAllocAligned(heap, b, 0x20);
    func_0202e680(groupFirstEntries, gScrollList->mGroupFirstEntries, b);
    func_0202e680(screenMap, gScrollList->mScreenMap, 0x600);
    gScrollList->mCursorEntry = cursorEntry;
    gScrollList->mUnk_02e = e;
    gScrollList->mUnk_030 = f;
    gScrollList->mEntries = entries;
    gScrollList->mRowCount = rowCount;
    gScrollList->mCallback = callback;
    gScrollList->mRects = rects;
    gScrollList->mUpRectIndex = upRectIndex;
    gScrollList->mDownRectIndex = downRectIndex;
    gScrollList->mFirstRowRectIndex = firstRowRectIndex;
    gScrollList->mEnabled = 1;
    gScrollList->mTouchRectIndex = -1;
    gScrollList->mPressedRectIndex = gScrollList->mTouchRectIndex;
    func_0202edd0();
    func_0202f120(0, -1, -1, GetScrollListSelectedSlot());
    for (row = 0; row < 6 && row < gScrollList->mRowCount; row++) {
        func_0202f120(1, row + 1, row, -1);
    }
    func_0202ee3c(0, 0);
    func_0202ee3c(6, 0);
    for (row = gScrollList->mRowCount; row < 5; row++) {
        func_0202ee3c(row + 1, 0);
    }
    gScrollList->mEntries[gScrollList->mUnk_02e].mUnk_00 = gScrollList->mRowCount > 5;
    if (gScrollList->mRowCount == 0) {
        gScrollList->mEntries[gScrollList->mCursorEntry].mUnk_00 = 0;
    }
    gScrollList->mScrollFrameCount = 0xf;
}

void AdvanceScrollList(void) {
    gScrollList->mPickStarted = 0;
    gScrollList->mPickFinished = gScrollList->mPickStarted;
    func_0202eec0();
    func_0202ed04();
    switch (gScrollList->mState) {
        case 0:
            AdvanceScrollListState0();
            break;
        case 1:
            AdvanceScrollListSelectUp();
            break;
        case 2:
            AdvanceScrollListSelectDown();
            break;
        case 3:
            AdvanceScrollListScrollUp();
            break;
        case 4:
            AdvanceScrollListScrollDown();
            break;
        case 5:
            AdvanceScrollListPick();
            break;
    }
    func_0202ee88();
}

#pragma thumb off
