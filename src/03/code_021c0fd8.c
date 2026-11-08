#include "03/code_021c0fd8.h"

#include "03/code_021d197c.h"
#include "03/code_021d27d8.h"
#include "03/code_021d2ecc.h"
#include "03/code_021bf8c0.h"
#include "03/code_021c0000.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1000.h"
#include "03/code_021d1790.h"
#include "03/code_021d1970.h"
#include "03/code_021d1c18.h"
#include "03/unk_021da000.h"
#include "03/code_021d2940.h"
#include "03/unk_021d6000.h"
#include "03/code_021d1fd0.h"
#include "03/code_021c1000.h"
#include "03/code_021d250c.h"
#include "03/code_021d1770.h"
#include "03/code_021d3488.h"
#include "03/code_021c04ec.h"

void CreateEditAddrKeyboard(void) {
    Unk021c0d2c textArgs;
    EditAddrKeyboard *keyboard;
    int i;
    int textIndex;
    int column;
    textArgs.mUnk_00[0] = data_ov003_021d6dd8[0];
    textArgs.mUnk_00[1] = data_ov003_021d6dd8[1];
    textArgs.mUnk_00[2] = data_ov003_021d6dd8[2];
    textArgs.mUnk_00[3] = data_ov003_021d6dd8[3];
    textArgs.mUnk_00[2] = gEditAddrKeyboardDigitKeySize[0];
    textArgs.mUnk_00[3] = gEditAddrKeyboardDigitKeySize[1];
    keyboard = AllocZeroedExpHeapBlock(0x6c, 4);
    gEditAddrKeyboard = keyboard;
    keyboard->mInput = 0x1f;
    gEditAddrKeyboard->mCursorKeyIndex = 0;
    gEditAddrKeyboard->mRemoveCharEnabled = 1;
    gEditAddrKeyboard->mAddCharEnabled = 1;
    gEditAddrKeyboard->mNextGroupEnabled = 1;
    for (i = 0; i < 10; i++) {
        gEditAddrKeyboard->mDigitKeys[i] = CreateOamEntryFromNceImage(0, 0x36);
        gEditAddrKeyboard->mDigitKeys[i]->mUnk_00 = (gEditAddrKeyboard->mDigitKeys[i]->mUnk_00 & 0xc1fffcff) | 0x200;
        gEditAddrKeyboard->mDigitKeys[i]->mUnk_04 = (gEditAddrKeyboard->mDigitKeys[i]->mUnk_04 & 0xfffff3ff) | 0xc00;
    }
    for (i = 0; i < 2; i++) {
        gEditAddrKeyboard->mExtraKeys[i] = CreateOamEntryFromNceImage(0, data_ov003_021d6218[i]);
        gEditAddrKeyboard->mExtraKeys[i]->mUnk_00 = (gEditAddrKeyboard->mExtraKeys[i]->mUnk_00 & 0xc1fffcff) | 0x200;
        gEditAddrKeyboard->mExtraKeys[i]->mUnk_04 = (gEditAddrKeyboard->mExtraKeys[i]->mUnk_04 & 0xfffff3ff) | 0xc00;
    }
    for (i = 0; i < 2; i++) {
        gEditAddrKeyboard->mRow4Keys[i] = CreateOamRangeFromNceImage(0, data_ov003_021d621c[i], 1);
        SetOamRangeEffect(gEditAddrKeyboard->mRow4Keys[i], -1, 0x200, 0);
        func_ov003_021d1790(gEditAddrKeyboard->mRow4Keys[i], -1, 3);
    }
    textArgs.mUnk_0c[1] = 0;
    for (i = 0; i < 4; i++) {
        gEditAddrKeyboard->mRowTexts[i] =
            CreateObjTextCanvas(0, data_ov003_021d6230[0], data_ov003_021d6230[1], 0, &textArgs.mUnk_08, 0);
        textIndex = i * 3;
        for (column = 0, textArgs.mUnk_00[0] = 0; column < 3; column++, textIndex++, textArgs.mUnk_00[0] += 0x20) {
            textArgs.mUnk_0c[0] = gEditAddrKeyboardKeyTexts[textIndex];
            DrawCanvasTextRect(gEditAddrKeyboard->mRowTexts[i], textArgs.mUnk_00[0], textArgs.mUnk_00[1],
                               textArgs.mUnk_00[2], textArgs.mUnk_00[3], 2, 0x480, textArgs.mUnk_0c);
        }
        gEditAddrKeyboard->mUnk_48[i] = CreateOamRange(0, textArgs.mUnk_08, 0);
    }
    gEditAddrKeyboard->mCursor = CreateOamRangeFromNceImage(0, 0x44, 1);
    SetOamRangeEffect(gEditAddrKeyboard->mCursor, -1, 0x200, 0);
    func_ov003_021d1790(gEditAddrKeyboard->mCursor, -1, 2);
    gEditAddrKeyboard->mStepTask = (TaskEntry *) func_ov003_021d3544(0, AdvanceEditAddrKeyboardSlideInRow0, NULL, 0x78);
    SetEditAddrKeyboardRowY(0, 0xc0);
}

void StartEditAddrKeyboardSlideOut(void) {
    DeleteOamRange(gEditAddrKeyboard->mCursor);
    func_ov003_021d34e0(gEditAddrKeyboard->mStepTask, AdvanceEditAddrKeyboardSlideOutRow4);
}

u8 GetEditAddrKeyboardInput(void) {
    return gEditAddrKeyboard->mInput;
}

void SetEditAddrKeyboardRemoveCharEnabled(u8 canRemove) {
    gEditAddrKeyboard->mRemoveCharEnabled = canRemove;
}

void SetEditAddrKeyboardAddCharEnabled(u8 canAdd) {
    gEditAddrKeyboard->mAddCharEnabled = canAdd;
}

void SetEditAddrKeyboardNextGroupEnabled(u8 canNextGroup) {
    gEditAddrKeyboard->mNextGroupEnabled = canNextGroup;
}

BOOL HasEditAddrKeyboard(void) {
    if (gEditAddrKeyboard != NULL) {
        return 1;
    }
    return 0;
}

static inline void func_ov003_021c1b8c_inline(OamEntry *object, u32 *x, u32 *y) {
    *x = (object->mUnk_00 & 0x1ff0000) >> 16;
    *y = object->mUnk_00 & 0xff;
}

void AdvanceEditAddrKeyboardSlideInRow0(TaskEntry *task) {
    s32 xPos;
    s32 yPos;
    func_ov003_021c1b8c_inline(gEditAddrKeyboard->mDigitKeys[0], (u32 *) &xPos, (u32 *) &yPos);
    yPos = yPos - 0xc;
    if (yPos > gEditAddrKeyboardDigitKeyPositions[0][1]) {
        SetEditAddrKeyboardRowY(0, yPos);
        return;
    }
    SetEditAddrKeyboardRowY(0, gEditAddrKeyboardDigitKeyPositions[0][1]);
    SetEditAddrKeyboardRowY(1, 0xc0);
    func_ov003_021d34e0(task, AdvanceEditAddrKeyboardSlideInRow1);
}

void AdvanceEditAddrKeyboardSlideInRow1(TaskEntry *task) {
    s32 xPos;
    s32 yPos;
    func_ov003_021c1b8c_inline(gEditAddrKeyboard->mDigitKeys[3], (u32 *) &xPos, (u32 *) &yPos);
    yPos = yPos - 0xc;
    if (yPos > gEditAddrKeyboardDigitKeyPositions[3][1]) {
        SetEditAddrKeyboardRowY(1, yPos);
        return;
    }
    SetEditAddrKeyboardRowY(1, gEditAddrKeyboardDigitKeyPositions[3][1]);
    SetEditAddrKeyboardRowY(2, 0xc0);
    func_ov003_021d34e0(task, AdvanceEditAddrKeyboardSlideInRow2);
}

void AdvanceEditAddrKeyboardSlideInRow2(TaskEntry *task) {
    s32 xPos;
    s32 yPos;
    func_ov003_021c1b8c_inline(gEditAddrKeyboard->mDigitKeys[6], (u32 *) &xPos, (u32 *) &yPos);
    yPos = yPos - 0xc;
    if (yPos > gEditAddrKeyboardDigitKeyPositions[6][1]) {
        SetEditAddrKeyboardRowY(2, yPos);
        return;
    }
    SetEditAddrKeyboardRowY(2, gEditAddrKeyboardDigitKeyPositions[6][1]);
    SetEditAddrKeyboardRowY(3, 0xc0);
    func_ov003_021d34e0(task, AdvanceEditAddrKeyboardSlideInRow3);
}

void AdvanceEditAddrKeyboardSlideInRow3(TaskEntry *task) {
    s32 xPos;
    s32 yPos;
    func_ov003_021c1b8c_inline(gEditAddrKeyboard->mDigitKeys[9], (u32 *) &xPos, (u32 *) &yPos);
    yPos = yPos - 0xc;
    if (yPos > gEditAddrKeyboardDigitKeyPositions[9][1]) {
        SetEditAddrKeyboardRowY(3, yPos);
        return;
    }
    SetEditAddrKeyboardRowY(3, gEditAddrKeyboardDigitKeyPositions[9][1]);
    SetEditAddrKeyboardRowY(4, 0xc0);
    func_ov003_021d34e0(task, AdvanceEditAddrKeyboardSlideInRow4);
}

void AdvanceEditAddrKeyboardSlideInRow4(TaskEntry *task) {
    u32 xPos;
    s32 yPos;
    GetOamRangeEntryPosition(gEditAddrKeyboard->mRow4Keys[0], 0, &xPos, &yPos);
    yPos = yPos - 0xc;
    if (yPos > gEditAddrKeyboardRow4KeyPositions[0][1]) {
        SetEditAddrKeyboardRowY(4, yPos);
        return;
    }
    SetEditAddrKeyboardRowY(4, gEditAddrKeyboardRow4KeyPositions[0][1]);
    PlaceEditAddrKeyboardCursor();
    func_ov003_021d34e0(task, AdvanceEditAddrKeyboardInput);
}

void AdvanceEditAddrKeyboardInput(void) {
    AdvanceEditAddrKeyboardTouchPressed();
    AdvanceEditAddrKeyboardTouchReleased();
    AdvanceEditAddrKeyboardTouchDown();
    AdvanceEditAddrKeyboardKeys();
}

void AdvanceEditAddrKeyboardTouchPressed(void) {
    Rect keyRect;
    u16 *extraKeyOrigin;
    int j;
    int i;
    u16 *p;
    if (IsTouchPressedInRect(&data_ov003_021d67e8) == 0) {
        return;
    }
    gEditAddrKeyboard->mPressedKeyIndex = -1;
    for (i = 0, p = gEditAddrKeyboardDigitKeyPositions[0]; i < 10; p += 2, i++) {
        ComputeRectFromOriginAndSize(p, gEditAddrKeyboardDigitKeySize, &keyRect);
        if (IsTouchPressedInRect(&keyRect) != 0) {
            if (gEditAddrKeyboard->mAddCharEnabled == 0) {
                StartSoundSeq(9);
                return;
            }
            StartSoundSeq(0);
            gEditAddrKeyboard->mPressedKeyIndex = i;
            return;
        }
    }
    for (j = 0, extraKeyOrigin = gEditAddrKeyboardExtraKeyPositions[0]; j < 2; extraKeyOrigin += 2, j++) {
        ComputeRectFromOriginAndSize(extraKeyOrigin, gEditAddrKeyboardExtraKeySize, &keyRect);
        if (IsTouchPressedInRect(&keyRect) != 0) {
            if ((j == 0 && gEditAddrKeyboard->mRemoveCharEnabled == 0) ||
                (j == 1 && gEditAddrKeyboard->mNextGroupEnabled == 0)) {
                StartSoundSeq(9);
                return;
            }
            StartSoundSeq(0);
            gEditAddrKeyboard->mPressedKeyIndex = j + 10;
            return;
        }
    }
    for (j = 0, p = gEditAddrKeyboardRow4KeyPositions[0]; j < 2; p += 2, j++) {
        ComputeRectFromOriginAndSize(p, gEditAddrKeyboardRow4KeySize, &keyRect);
        if (IsTouchPressedInRect(&keyRect) != 0) {
            StartSoundSeq(0);
            gEditAddrKeyboard->mPressedKeyIndex = j + 12;
            return;
        }
    }
}

void AdvanceEditAddrKeyboardTouchReleased(void) {
    Rect keyRect;
    u16 *extraKeyOrigin;
    int j;
    int i;
    u16 *p;
    gEditAddrKeyboard->mInput = 0;
    if (IsTouchReleasedInRect(&data_ov003_021d67e8) == 0) {
        return;
    }
    for (i = 0, p = gEditAddrKeyboardDigitKeyPositions[0]; i < 10; p += 2, i++) {
        ComputeRectFromOriginAndSize(p, gEditAddrKeyboardDigitKeySize, &keyRect);
        if (IsTouchReleasedInRect(&keyRect) != 0) {
            if (gEditAddrKeyboard->mPressedKeyIndex != i) {
                return;
            }
            gEditAddrKeyboard->mInput = gEditAddrKeyboardDigitInputs[i];
            gEditAddrKeyboard->mCursorKeyIndex = i;
            PlaceEditAddrKeyboardCursor();
            return;
        }
    }
    for (j = 0, extraKeyOrigin = gEditAddrKeyboardExtraKeyPositions[0]; j < 2; extraKeyOrigin += 2, j++) {
        ComputeRectFromOriginAndSize(extraKeyOrigin, gEditAddrKeyboardExtraKeySize, &keyRect);
        if (IsTouchReleasedInRect(&keyRect) != 0) {
            if (gEditAddrKeyboard->mPressedKeyIndex != j + 10) {
                return;
            }
            gEditAddrKeyboard->mInput = gEditAddrKeyboardExtraKeyInputs[j];
            gEditAddrKeyboard->mCursorKeyIndex = j + 10;
            PlaceEditAddrKeyboardCursor();
            return;
        }
    }
    for (j = 0, p = gEditAddrKeyboardRow4KeyPositions[0]; j < 2; p += 2, j++) {
        ComputeRectFromOriginAndSize(p, gEditAddrKeyboardRow4KeySize, &keyRect);
        if (IsTouchReleasedInRect(&keyRect) != 0) {
            if (gEditAddrKeyboard->mPressedKeyIndex != j + 12) {
                return;
            }
            gEditAddrKeyboard->mInput = gEditAddrKeyboardRow4KeyInputs[j];
            gEditAddrKeyboard->mCursorKeyIndex = j + 12;
            PlaceEditAddrKeyboardCursor();
            return;
        }
    }
}

void AdvanceEditAddrKeyboardTouchDown(void) {
    Rect keyRect;
    u16 *extraKeyOrigin;
    int j;
    int i;
    u16 *p;
    if (IsTouchDownInRect(&data_ov003_021d67e8) == 0) {
        goto label_1;
    }
    for (i = 0, p = gEditAddrKeyboardDigitKeyPositions[0]; i < 10; p += 2, i++) {
        ComputeRectFromOriginAndSize(p, gEditAddrKeyboardDigitKeySize, &keyRect);
        if (IsTouchDownInRect(&keyRect) != 0) {
            if (gEditAddrKeyboard->mPressedKeyIndex != i) {
                goto label_1;
            }
            ChangeEditAddrKeyboardHighlight(i);
            goto label_2;
        }
    }
    for (j = 0, extraKeyOrigin = gEditAddrKeyboardExtraKeyPositions[0]; j < 2; extraKeyOrigin += 2, j++) {
        ComputeRectFromOriginAndSize(extraKeyOrigin, gEditAddrKeyboardExtraKeySize, &keyRect);
        if (IsTouchDownInRect(&keyRect) != 0) {
            if (gEditAddrKeyboard->mPressedKeyIndex != j + 10) {
                goto label_1;
            }
            ChangeEditAddrKeyboardHighlight(j + 10);
            if (j != 0) {
                goto label_2;
            }
            gEditAddrKeyboard->mRepeatCalls = gEditAddrKeyboard->mRepeatCalls + 1;
            if (gEditAddrKeyboard->mRepeatCalls >= 0x28) {
                if (gEditAddrKeyboard->mRemoveCharEnabled == 0) {
                    StartSoundSeq(9);
                    gEditAddrKeyboard->mPressedKeyIndex = -1;
                    return;
                }
                gEditAddrKeyboard->mInput = 0x10;
                gEditAddrKeyboard->mRepeatCalls = gEditAddrKeyboard->mRepeatCalls - 7;
                return;
            }
            return;
        }
    }
    for (j = 0, p = gEditAddrKeyboardRow4KeyPositions[0]; j < 2; p += 2, j++) {
        ComputeRectFromOriginAndSize(p, gEditAddrKeyboardRow4KeySize, &keyRect);
        if (IsTouchDownInRect(&keyRect) != 0) {
            j += 12;
            if (gEditAddrKeyboard->mPressedKeyIndex != j) {
                goto label_1;
            }
            ChangeEditAddrKeyboardHighlight(j);
            goto label_2;
        }
    }
label_1:
    ChangeEditAddrKeyboardHighlight(-1);
label_2:
    gEditAddrKeyboard->mRepeatCalls = 0;
}

void ChangeEditAddrKeyboardHighlight(int keyIndex) {
    if (keyIndex != gEditAddrKeyboard->mHighlightedKeyIndex) {
        SetEditAddrKeyboardKeyHighlight(keyIndex, 1);
        SetEditAddrKeyboardKeyHighlight(gEditAddrKeyboard->mHighlightedKeyIndex, 0);
        gEditAddrKeyboard->mHighlightedKeyIndex = keyIndex;
    }
}

static inline void func_ov003_021c105c_inline(OamEntry *object, u32 *x, u32 *y) {
    *x = (object->mUnk_00 & 0x1ff0000) >> 16;
    *y = object->mUnk_00 & 0xff;
}

void AdvanceEditAddrKeyboardKeys(void) {
    int keyIndex;
    if (AreKeysPressedOrRepeated(0x20) != 0) {
        MoveEditAddrKeyboardCursor(0);
    }
    if (AreKeysPressedOrRepeated(0x40) != 0) {
        MoveEditAddrKeyboardCursor(1);
    }
    if (AreKeysPressedOrRepeated(0x10) != 0) {
        MoveEditAddrKeyboardCursor(2);
    }
    if (AreKeysPressedOrRepeated(0x80) != 0) {
        MoveEditAddrKeyboardCursor(3);
    }
    if (AreKeysPressed(1) != 0) {
        keyIndex = gEditAddrKeyboard->mCursorKeyIndex;
        if (keyIndex < 10) {
            if (gEditAddrKeyboard->mAddCharEnabled != 0) {
                gEditAddrKeyboard->mInput = gEditAddrKeyboardDigitInputs[keyIndex];
                return;
            }
            StartSoundSeq(9);
            return;
        }
        if (keyIndex - 10 < 2) {
            if ((keyIndex - 10 == 0 && gEditAddrKeyboard->mRemoveCharEnabled == 0) ||
                (keyIndex - 10 == 1 && gEditAddrKeyboard->mNextGroupEnabled == 0)) {
                StartSoundSeq(9);
                return;
            }
            gEditAddrKeyboard->mInput = gEditAddrKeyboardExtraKeyInputs[keyIndex - 10];
            return;
        }
        gEditAddrKeyboard->mInput = gEditAddrKeyboardRow4KeyInputs[keyIndex - 12];
    }
    if (AreKeysPressedOrRepeated(2) != 0) {
        if (gEditAddrKeyboard->mRemoveCharEnabled == 0) {
            if (gEditAddrKeyboard->mRemoveDisabledSoundPlayed == 0) {
                StartSoundSeq(9);
                gEditAddrKeyboard->mRemoveDisabledSoundPlayed = 1;
            }
        } else {
            gEditAddrKeyboard->mInput = 0x10;
        }
    } else if (AreKeysReleased(2) != 0) {
        gEditAddrKeyboard->mRemoveDisabledSoundPlayed = 0;
    }
}

void SetEditAddrKeyboardRowY(int row, u32 yPos) {
    u8 digitKeyCounts[5];
    u8 extraKeyCounts[5];
    u8 row4KeyCounts[5];
    BOOL b;
    int i;
    int keyIndex;
    OamEntry *key;
    *(Unk021c1364_05 *) digitKeyCounts = *(Unk021c1364_05 *) gEditAddrKeyboardDigitKeyCounts;
    *(Unk021c1364_05 *) extraKeyCounts = *(Unk021c1364_05 *) gEditAddrKeyboardExtraKeyCounts;
    *(Unk021c1364_05 *) row4KeyCounts = *(Unk021c1364_05 *) gEditAddrKeyboardRow4KeyCounts;
    keyIndex = row * 3;
    for (i = 0; i < digitKeyCounts[(u32) row]; i++, keyIndex++) {
        key = gEditAddrKeyboard->mDigitKeys[keyIndex];
        key->mUnk_00 = key->mUnk_00 & 0xc1fffcff;
        key = gEditAddrKeyboard->mDigitKeys[keyIndex];
        key->mUnk_00 = ((gEditAddrKeyboardDigitKeyPositions[keyIndex][0] & 0x1ff) << 16) |
                       ((key->mUnk_00 & 0xfe00ff00) | (yPos & 0xff));
    }
    if (row < 4) {
        ArrangeObjTextCanvasRange(gEditAddrKeyboard->mRowTexts[row], gEditAddrKeyboardDigitKeyPositions[row * 3][0],
                                  yPos, gEditAddrKeyboard->mUnk_48[row], 2);
    }
    for (i = 0; i < extraKeyCounts[(u32) row]; i++) {
        key = gEditAddrKeyboard->mExtraKeys[i];
        key->mUnk_00 = key->mUnk_00 & 0xc1fffcff;
        key = gEditAddrKeyboard->mExtraKeys[i];
        key->mUnk_00 =
            ((gEditAddrKeyboardExtraKeyPositions[i][0] & 0x1ff) << 16) | ((key->mUnk_00 & 0xfe00ff00) | (yPos & 0xff));
    }
    b = FALSE;
    for (i = 0; i < row4KeyCounts[(u32) row]; i++) {
        SetOamRangeEffect(gEditAddrKeyboard->mRow4Keys[i], -1, b, b);
        SetOamRangePosition(gEditAddrKeyboard->mRow4Keys[i], -1, gEditAddrKeyboardRow4KeyPositions[i][0], yPos);
    }
}

void SetEditAddrKeyboardKeyHighlight(int keyIndex, int highlight) {
    OamEntry *key;
    int extraKeyIndex;
    if (keyIndex < 0) {
        return;
    }
    if (keyIndex < 10) {
        key = gEditAddrKeyboard->mDigitKeys[keyIndex];
        key->mUnk_00 &= 0xfffff3ff;
        key->mUnk_04 = (key->mUnk_04 & 0xffff0fff) | (data_ov003_021d6220[highlight] << 12);
        return;
    }
    extraKeyIndex = keyIndex - 10;
    if (extraKeyIndex < 2) {
        key = gEditAddrKeyboard->mExtraKeys[extraKeyIndex];
        key->mUnk_00 &= 0xfffff3ff;
        key->mUnk_04 = (key->mUnk_04 & 0xffff0fff) | (data_ov003_021d6220[highlight] << 12);
        return;
    }
    func_ov003_021d1890(gEditAddrKeyboard->mRow4Keys[keyIndex - 12], -1, 0, data_ov003_021d6214[highlight]);
}

void PlaceEditAddrKeyboardCursor(void) {
    int imageIndex;
    if (gEditAddrKeyboard->mCursorKeyIndex <= 11) {
        imageIndex = 0x44;
    } else {
        imageIndex = 0x45;
    }
    CopyNceImageToOamEntries(0, imageIndex, GetOamRangeEntry(gEditAddrKeyboard->mCursor, 0));
    func_ov003_021d1790(gEditAddrKeyboard->mCursor, -1, 2);
    SetOamRangePosition(gEditAddrKeyboard->mCursor, -1,
                        gEditAddrKeyboardCursorX[gEditAddrKeyboard->mCursorKeyIndex * 2],
                        gEditAddrKeyboardCursorY[gEditAddrKeyboard->mCursorKeyIndex * 2]);
}

void MoveEditAddrKeyboardCursor(u32 direction) {
    s8 previousKeyIndex;
    s8 nextKeyIndex;
    previousKeyIndex = gEditAddrKeyboard->mCursorKeyIndex;
    gEditAddrKeyboard->mCursorKeyIndex = (gEditAddrKeyboardCursorMoves + previousKeyIndex * 4)[direction];
    nextKeyIndex = gEditAddrKeyboard->mCursorKeyIndex;
    if (nextKeyIndex == 0xd && (direction == 1 || direction == 3)) {
        gEditAddrKeyboard->mUnk_64 = previousKeyIndex;
    } else if (nextKeyIndex == -1) {
        if (gEditAddrKeyboard->mUnk_64 == 1 || gEditAddrKeyboard->mUnk_64 == 10) {
            gEditAddrKeyboard->mCursorKeyIndex = 10;
        } else {
            gEditAddrKeyboard->mCursorKeyIndex = 11;
        }
    } else if (nextKeyIndex == -2) {
        if (gEditAddrKeyboard->mUnk_64 == 1 || gEditAddrKeyboard->mUnk_64 == 10) {
            gEditAddrKeyboard->mCursorKeyIndex = 1;
        } else {
            gEditAddrKeyboard->mCursorKeyIndex = 2;
        }
    }
    PlaceEditAddrKeyboardCursor();
    StartSoundSeq(8);
}

void AdvanceEditAddrKeyboardSlideOutRow4(TaskEntry *task) {
    s32 xPos;
    s32 yPos;
    func_ov003_021c105c_inline(GetOamRangeEntry(gEditAddrKeyboard->mRow4Keys[0], 0), (u32 *) &xPos, (u32 *) &yPos);
    yPos = yPos + 0xc;
    SetEditAddrKeyboardRowY(4, yPos);
    if (yPos >= 0xc0) {
        func_ov003_021d34e0(task, AdvanceEditAddrKeyboardSlideOutRow3);
    }
}

void AdvanceEditAddrKeyboardSlideOutRow3(TaskEntry *task) {
    s32 xPos;
    s32 yPos;
    func_ov003_021c105c_inline(gEditAddrKeyboard->mDigitKeys[9], (u32 *) &xPos, (u32 *) &yPos);
    yPos = yPos + 0xc;
    SetEditAddrKeyboardRowY(3, yPos);
    if (yPos >= 0xc0) {
        func_ov003_021d34e0(task, AdvanceEditAddrKeyboardSlideOutRow2);
    }
}

void AdvanceEditAddrKeyboardSlideOutRow2(TaskEntry *task) {
    s32 xPos;
    s32 yPos;
    func_ov003_021c105c_inline(gEditAddrKeyboard->mDigitKeys[6], (u32 *) &xPos, (u32 *) &yPos);
    yPos = yPos + 0xc;
    SetEditAddrKeyboardRowY(2, yPos);
    if (yPos >= 0xc0) {
        func_ov003_021d34e0(task, AdvanceEditAddrKeyboardSlideOutRow1);
    }
}

void AdvanceEditAddrKeyboardSlideOutRow1(TaskEntry *task) {
    s32 xPos;
    s32 yPos;
    func_ov003_021c105c_inline(gEditAddrKeyboard->mDigitKeys[3], (u32 *) &xPos, (u32 *) &yPos);
    yPos = yPos + 0xc;
    SetEditAddrKeyboardRowY(1, yPos);
    if (yPos >= 0xc0) {
        func_ov003_021d34e0(task, AdvanceEditAddrKeyboardSlideOutRow0);
    }
}

void AdvanceEditAddrKeyboardSlideOutRow0(TaskEntry *task) {
    s32 xPos;
    s32 yPos;
    func_ov003_021c105c_inline(gEditAddrKeyboard->mDigitKeys[0], (u32 *) &xPos, (u32 *) &yPos);
    yPos = yPos + 0xc;
    SetEditAddrKeyboardRowY(0, yPos);
    if (yPos >= 0xc0) {
        func_ov003_021d34e0(task, ReleaseEditAddrKeyboard);
    }
}

void ReleaseEditAddrKeyboard(u32 task) {
    int index;
    func_ov003_021d34c8(0, task);
    index = 0;
    do {
        DeleteOamRange(gEditAddrKeyboard->mUnk_48[index]);
        DeleteObjTextCanvas(gEditAddrKeyboard->mRowTexts[index]);
        index = index + 1;
    } while (index < 4);
    index = 0;
    do {
        DeleteOamRange(gEditAddrKeyboard->mRow4Keys[index]);
        index = index + 1;
    } while (index < 2);
    index = 0;
    do {
        func_ov003_021d2f00((u32 *) gEditAddrKeyboard->mExtraKeys[index]);
        index = index + 1;
    } while (index < 2);
    index = 0;
    do {
        func_ov003_021d2f00((u32 *) gEditAddrKeyboard->mDigitKeys[index]);
        index = index + 1;
    } while (index < 10);
    FreeExpHeapBlockAndClearPointer(&gEditAddrKeyboard);
}
