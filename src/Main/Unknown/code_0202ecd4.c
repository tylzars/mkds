#include "Main/Unknown/code_0202ecd4.h"
#include "code_02016468.h"
#include "Main/Unknown/code_0202edfc.h"
#include "Main/Unknown/unk_02174000.h"

#pragma optimize_for_size on

#pragma thumb on

void PlaceScrollListCursor(void) {
    ScrollList *scrollList = gScrollList;
    s32 entryIndex;
    s16 positionY;
    entryIndex = scrollList->mGroupFirstEntries[0] + GetScrollListSelectedSlot();
    positionY = scrollList->mEntries[entryIndex].mPositionY;
    scrollList->mEntries[scrollList->mCursorEntry].mPositionY = positionY;
}

void SetScrollListRightColumnHighBits(s32 highBits) {
    s32 column;
    s32 row;
    for (row = 1; row < 0x13; row++) {
        for (column = 0x1c; column < 0x20; column++) {
            u8 *halfwordPointer = (u8 *) gScrollList + (column + row * 0x20) * 2;
            halfwordPointer += 0x58;
            *(u16 *) halfwordPointer = *(u16 *) halfwordPointer & 0xfff;
            halfwordPointer = (u8 *) gScrollList + (column + row * 0x20) * 2;
            halfwordPointer += 0x58;
            *(u16 *) halfwordPointer = *(u16 *) halfwordPointer | (highBits << 12);
        }
    }
    gScrollList->mRightColumnHighBitsTimer = 5;
    gScrollList->mRightColumnHighBits = highBits;
    CallQueueAppend(0x1b, 0, gScrollList->mScreenMap, 0x600);
}

void AdvanceScrollListRightColumnTimer(void) {
    if (gScrollList->mRightColumnHighBits != 0) {
        if (gScrollList->mRightColumnHighBitsTimer == 0) {
            SetScrollListRightColumnHighBits(0);
            gScrollList->mRightColumnHighBits = 0;
        } else {
            gScrollList->mRightColumnHighBitsTimer = gScrollList->mRightColumnHighBitsTimer - 1;
        }
    } else {
        gScrollList->mRightColumnHighBitsTimer = 0;
    }
}

#pragma thumb off

u16 func_0202ecf0(InputSlot *slot, u32 mask) {
    return slot->mUnk_00 & mask;
}

u16 func_0202ecd4(u32 slotIndex, u32 mask) {
    return func_0202ecf0(&data_02175628[slotIndex], mask);
}
