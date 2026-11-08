#include "Main/Unknown/code_0202ee88.h"
#include "Main/Unknown/code_020291c4.h"
#include "Main/Unknown/code_0202e68c.h"
#include "Main/Unknown/code_0202f020.h"
#include "Main/Unknown/code_0202f028.h"
#include "Main/Unknown/code_0202f058.h"
#include "Main/Unknown/code_0202f0a8.h"
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
#include "Main/Unknown/code_0202edfc.h"
#include "Main/Unknown/unk_02174000.h"

#pragma optimize_for_size on

u32 func_0202efe8(InputSlotPair *pair) {
    u32 result;
    if (func_0202f028(pair) != 0 || func_0202f020(pair) != 0) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

u32 func_0202efc8(u32 slotIndex) {
    return func_0202efe8((InputSlotPair *) &data_02175628[slotIndex].mPairX);
}

#pragma thumb on

void AdvanceScrollListInput(void) {
    u32 slotIndex = func_020435bc();
    u32 pairX;
    u32 pairY;
    s32 rectIndex;
    if (func_0202f0a8(slotIndex) != 0) {
        pairX = func_0202f080(slotIndex);
        pairY = func_0202f058(slotIndex);
        gScrollList->mTouchRectIndex = FindRectContainingPoint(pairX, pairY, gScrollList->mRects);
        gScrollList->mPressedRectIndex = gScrollList->mTouchRectIndex;
        gScrollList->mTouchHeld = TRUE;
    } else {
        gScrollList->mPressedRectIndex = -1;
    }
    if (gScrollList->mTouchHeld != FALSE) {
        if (func_0202efc8(slotIndex) != 0) {
            pairX = func_0202f080(slotIndex);
            pairY = func_0202f058(slotIndex);
            rectIndex = FindRectContainingPoint(pairX, pairY, gScrollList->mRects);
            if (rectIndex != gScrollList->mTouchRectIndex) {
                gScrollList->mTouchRectIndex = -1;
                gScrollList->mTouchHeld = FALSE;
            }
        } else {
            gScrollList->mTouchRectIndex = -1;
            gScrollList->mTouchHeld = FALSE;
        }
    }
    if (func_0202ec7c(slotIndex, PAD_KEY_UP) != 0 || gScrollList->mTouchRectIndex == gScrollList->mUpRectIndex) {
        gScrollList->mUpHeldFrames = gScrollList->mUpHeldFrames + 1;
    } else {
        gScrollList->mUpHeldFrames = 0;
    }
    if (func_0202ec7c(slotIndex, PAD_KEY_DOWN) != 0 || gScrollList->mTouchRectIndex == gScrollList->mDownRectIndex) {
        gScrollList->mDownHeldFrames = gScrollList->mDownHeldFrames + 1;
    } else {
        gScrollList->mDownHeldFrames = 0;
    }
}

void func_0202ee88(void) {
    if (gScrollList->mEntries[gScrollList->mUnk_02e].mVisible != 0) {
        gScrollList->mEntries[gScrollList->mUnk_02e].mOffsetY =
            gScrollList->mUnk_030 * (gScrollList->mSelectedRow - gScrollList->mSelectedVisibleRow) /
            (gScrollList->mRowCount - 5);
    }
}
