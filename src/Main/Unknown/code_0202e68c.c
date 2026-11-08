#include "Main/Unknown/code_0202e68c.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0202ecac.h"
#include "Main/Unknown/code_0202ecd4.h"
#include "Main/Unknown/code_0202edfc.h"
#include "Main/Unknown/code_0202ee3c.h"
#include "Main/Unknown/code_0202ee68.h"
#include "Main/Unknown/code_0202f0a8.h"
#include "Main/Unknown/unk_02174000.h"
#include "code_0214d018.h"

#pragma optimize_for_size on

u16 func_0202ec98(InputSlot *slot, u32 mask) {
    return slot->mBits & mask;
}

u16 func_0202ec7c(u32 slotIndex, u32 mask) {
    return func_0202ec98(&data_02175628[slotIndex], mask);
}

#pragma thumb on

// State 0: starts a pick, a selection move or a scroll from the keys and the touch.
void AdvanceScrollListState0(void) {
    u32 slotIndex = func_020435bc();
    BOOL rowChanged;
    if (gScrollList->mEnabled == 0) {
        return;
    }
    gScrollList->mScrollFrameCount = gScrollList->mHeldMoveCount > 2 ? 5 : 0xf;
    if (func_0202ecd4(slotIndex, PAD_KEY_A) != 0) {
        gScrollList->mState = 5;
        gScrollList->mPickedVisibleRow = gScrollList->mSelectedVisibleRow;
        gScrollList->mEntries[gScrollList->mCursorEntry].mVisible = 0;
        gScrollList->mTimer = 10;
        gScrollList->mDownHeldFrames = 0;
        gScrollList->mUpHeldFrames = gScrollList->mDownHeldFrames;
        gScrollList->mHeldMoveCount = 0;
        PlaceScrollListCursor();
        CallScrollListCallback(0, -1, -1, -1);
        return;
    }
    if (gScrollList->mFirstRowRectIndex <= gScrollList->mPressedRectIndex &&
        gScrollList->mPressedRectIndex < gScrollList->mFirstRowRectIndex + 5 &&
        gScrollList->mPressedRectIndex - gScrollList->mFirstRowRectIndex < gScrollList->mRowCount) {
        gScrollList->mState = 5;
        gScrollList->mPickedVisibleRow = gScrollList->mPressedRectIndex - gScrollList->mFirstRowRectIndex;
        rowChanged = gScrollList->mPickedVisibleRow != gScrollList->mSelectedVisibleRow;
        gScrollList->mEntries[gScrollList->mCursorEntry].mVisible = rowChanged;
        gScrollList->mTimer = 10;
        gScrollList->mDownHeldFrames = 0;
        gScrollList->mUpHeldFrames = gScrollList->mDownHeldFrames;
        gScrollList->mHeldMoveCount = 0;
        gScrollList->mSelectedRow =
            gScrollList->mSelectedRow + (gScrollList->mPickedVisibleRow - gScrollList->mSelectedVisibleRow);
        gScrollList->mSelectedVisibleRow = gScrollList->mPickedVisibleRow;
        PlaceScrollListCursor();
        CallScrollListCallback(0, -1, -1, rowChanged != FALSE ? GetScrollListSelectedSlot() : -1);
        return;
    }
    if ((func_0202ecd4(slotIndex, PAD_KEY_UP) != 0 || gScrollList->mPressedRectIndex == gScrollList->mUpRectIndex ||
         gScrollList->mUpHeldFrames > gScrollList->mScrollFrameCount) &&
        gScrollList->mSelectedRow > 0) {
        if (gScrollList->mSelectedVisibleRow == 0) {
            gScrollList->mTimer = gScrollList->mScrollFrameCount;
            gScrollList->mEntries[gScrollList->mCursorEntry].mVisible = 0;
            gScrollList->mState = 3;
            SetScrollListSlotVisible(gScrollList->mHiddenTopSlot, 1);
            CallScrollListCallback(0, -1, -1, -1);
            CallScrollListCallback(2, gScrollList->mHiddenTopSlot,
                                   gScrollList->mSelectedRow - gScrollList->mSelectedVisibleRow - 1, -1);
        } else {
            gScrollList->mState = 1;
        }
        gScrollList->mUpHeldFrames = 0;
        gScrollList->mHeldMoveCount = gScrollList->mHeldMoveCount + 1;
        if (gScrollList->mTouchRectIndex == gScrollList->mUpRectIndex) {
            SetScrollListRightColumnHighBits(1);
        }
        func_0202ecac(3);
        return;
    }
    if ((func_0202ecd4(slotIndex, PAD_KEY_DOWN) != 0 || gScrollList->mPressedRectIndex == gScrollList->mDownRectIndex ||
         gScrollList->mDownHeldFrames > gScrollList->mScrollFrameCount) &&
        gScrollList->mSelectedRow < gScrollList->mRowCount - 1) {
        if (gScrollList->mSelectedVisibleRow == 4) {
            gScrollList->mTimer = gScrollList->mScrollFrameCount;
            gScrollList->mEntries[gScrollList->mCursorEntry].mVisible = 0;
            gScrollList->mState = 4;
            SetScrollListSlotVisible(GetScrollListHiddenBottomSlot(), 1);
            CallScrollListCallback(0, -1, -1, -1);
            {
                ScrollList *list = gScrollList;
                CallScrollListCallback(2, GetScrollListHiddenBottomSlot(),
                                       list->mSelectedRow - list->mSelectedVisibleRow + 5, -1);
            }
        } else {
            gScrollList->mState = 2;
        }
        gScrollList->mDownHeldFrames = 0;
        gScrollList->mHeldMoveCount = gScrollList->mHeldMoveCount + 1;
        if (gScrollList->mTouchRectIndex == gScrollList->mDownRectIndex) {
            SetScrollListRightColumnHighBits(2);
        }
        func_0202ecac(3);
        return;
    }
    if (func_0202ec7c(slotIndex, PAD_KEY_UP | PAD_KEY_DOWN) == 0 &&
        gScrollList->mTouchRectIndex != gScrollList->mUpRectIndex &&
        gScrollList->mTouchRectIndex != gScrollList->mDownRectIndex) {
        gScrollList->mHeldMoveCount = 0;
    }
}

void AdvanceScrollListSelectUp(void) {
    gScrollList->mSelectedVisibleRow = gScrollList->mSelectedVisibleRow - 1;
    gScrollList->mSelectedRow = gScrollList->mSelectedRow - 1;
    PlaceScrollListCursor();
    CallScrollListCallback(0, -1, -1, GetScrollListSelectedSlot());
    gScrollList->mState = 0;
}

void AdvanceScrollListSelectDown(void) {
    gScrollList->mSelectedVisibleRow = gScrollList->mSelectedVisibleRow + 1;
    gScrollList->mSelectedRow = gScrollList->mSelectedRow + 1;
    PlaceScrollListCursor();
    CallScrollListCallback(0, -1, -1, GetScrollListSelectedSlot());
    gScrollList->mState = 0;
}

void AdvanceScrollListScrollUp(void) {
    s32 groupIndex;
    s32 slotIndex;
    s32 firstEntry;
    s32 distance;
    LayoutTableEntry *entry;
    BOOL zero = FALSE;
    s32 hiddenBottomSlot = GetScrollListHiddenBottomSlot();
    gScrollList->mTimer = gScrollList->mTimer - 1;
    for (groupIndex = 0; groupIndex < gScrollList->mGroupCount; groupIndex++) {
        for (slotIndex = zero; slotIndex < 7; slotIndex++) {
            firstEntry = gScrollList->mGroupFirstEntries[groupIndex];
            distance = GetScrollListPositionYDifference(slotIndex + firstEntry, (slotIndex + 1) % 7 + firstEntry);
            entry = &gScrollList->mEntries[slotIndex + firstEntry];
            if (slotIndex == hiddenBottomSlot) {
                entry->mOffsetY = distance;
            } else {
                entry->mOffsetY =
                    InterpolateS16(1, distance, zero, gScrollList->mTimer, gScrollList->mScrollFrameCount);
            }
        }
    }
    if (gScrollList->mTimer == 0) {
        for (groupIndex = 0; groupIndex < gScrollList->mGroupCount; groupIndex++) {
            for (slotIndex = zero; slotIndex < 7; slotIndex++) {
                entry = &gScrollList->mEntries[slotIndex + gScrollList->mGroupFirstEntries[groupIndex]];
                entry->mPositionY = entry->mPositionY + entry->mOffsetY;
                entry->mOffsetY = 0;
            }
        }
        gScrollList->mEntries[gScrollList->mCursorEntry].mVisible = 1;
        gScrollList->mSelectedRow = gScrollList->mSelectedRow - 1;
        gScrollList->mHiddenTopSlot = hiddenBottomSlot;
        CallScrollListCallback(1, gScrollList->mHiddenTopSlot, gScrollList->mSelectedRow - 1, -1);
        {
            ScrollList *list = gScrollList;
            CallScrollListCallback(0, list->mHiddenTopSlot, list->mSelectedRow - 1, GetScrollListSelectedSlot());
        }
        gScrollList->mState = 0;
        SetScrollListSlotVisible(gScrollList->mHiddenTopSlot, 0);
    }
}

void AdvanceScrollListScrollDown(void) {
    s32 groupIndex;
    s32 slotIndex;
    s32 firstEntry;
    s32 distance;
    LayoutTableEntry *entry;
    BOOL zero = FALSE;
    gScrollList->mTimer = gScrollList->mTimer - 1;
    for (groupIndex = 0; groupIndex < gScrollList->mGroupCount; groupIndex++) {
        for (slotIndex = zero; slotIndex < 7; slotIndex++) {
            firstEntry = gScrollList->mGroupFirstEntries[groupIndex];
            distance = GetScrollListPositionYDifference(slotIndex + firstEntry, (slotIndex + 6) % 7 + firstEntry);
            entry = &gScrollList->mEntries[slotIndex + firstEntry];
            if (slotIndex == gScrollList->mHiddenTopSlot) {
                entry->mOffsetY = distance;
            } else {
                entry->mOffsetY =
                    InterpolateS16(1, distance, zero, gScrollList->mTimer, gScrollList->mScrollFrameCount);
            }
        }
    }
    if (gScrollList->mTimer == 0) {
        for (groupIndex = 0; groupIndex < gScrollList->mGroupCount; groupIndex++) {
            for (slotIndex = zero; slotIndex < 7; slotIndex++) {
                entry = &gScrollList->mEntries[slotIndex + gScrollList->mGroupFirstEntries[groupIndex]];
                entry->mPositionY = entry->mPositionY + entry->mOffsetY;
                entry->mOffsetY = 0;
            }
        }
        gScrollList->mEntries[gScrollList->mCursorEntry].mVisible = 1;
        gScrollList->mSelectedRow = gScrollList->mSelectedRow + 1;
        CallScrollListCallback(1, gScrollList->mHiddenTopSlot, gScrollList->mSelectedRow + 1, -1);
        {
            ScrollList *list = gScrollList;
            list->mHiddenTopSlot = (list->mHiddenTopSlot + 1) % 7;
        }
        {
            ScrollList *list = gScrollList;
            CallScrollListCallback(0, list->mHiddenTopSlot, list->mSelectedRow - 1, GetScrollListSelectedSlot());
        }
        gScrollList->mState = 0;
        SetScrollListSlotVisible(GetScrollListHiddenBottomSlot(), 0);
    }
}

void AdvanceScrollListPick(void) {
    if (gScrollList->mTimer == 10) {
        gScrollList->mPickStarted = 1;
    }
    gScrollList->mTimer = gScrollList->mTimer - 1;
    if (gScrollList->mTimer == 0) {
        CallScrollListCallback(0, -1, -1, GetScrollListSelectedSlot());
        gScrollList->mEntries[gScrollList->mCursorEntry].mVisible = 1;
        gScrollList->mState = 0;
        gScrollList->mPickFinished = 1;
    }
}

#pragma thumb off

void func_0202e6a0(void *dest, u32 value, u32 size) {
    volatile u32 valueCopy = value;
    MIi_CpuClearFast(valueCopy, dest, size);
}

void func_0202e68c(void *dest, u32 size) {
    func_0202e6a0(dest, 0, size);
}
