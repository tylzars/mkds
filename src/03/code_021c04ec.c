#include "03/code_021c04ec.h"

#include "03/code_021c0000.h"
#include "03/unk_021da000.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d2940.h"
#include "03/code_021d250c.h"
#include "03/unk_021d5f00.h"
#include "03/unk_021d6000.h"
#include "03/code_021bf8c0.h"
#include "03/code_021d1770.h"
#include "03/code_021d3488.h"
#include "03/code_021bf000.h"
#include "03/code_021d1790.h"
#include "03/code_021d197c.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d1000.h"
#include "03/code_021d27d8.h"
#include "03/code_021d1c18.h"
#include "03/unk_021d5000.h"

void CreateEditKeyboard(void) {
    u16 textRect[4] = {0};
    u32 w;
    u16 text[2];
    EditKeyboard *keyboard;
    int i;
    int j;
    int k;
    int charIndex;

    textRect[2] = data_ov003_021d5f7c[0][0];
    textRect[3] = data_ov003_021d5f7c[0][1];
    keyboard = func_ov003_021d283c(0x128, 4);
    gEditKeyboard = keyboard;
    keyboard->mInput = 0xff;
    gEditKeyboard->mCursorKeyIndex = 0;
    gEditKeyboard->mRemoveCharEnabled = 1;
    gEditKeyboard->mAddCharEnabled = 1;
    for (i = 0; i < 0x2f; i++) {
        gEditKeyboard->mKeys[i] = func_ov003_021d1c18(0, 0x34);
        gEditKeyboard->mKeys[i]->mUnk_00 = (gEditKeyboard->mKeys[i]->mUnk_00 & 0xc1fffcff) | 0x200;
        gEditKeyboard->mKeys[i]->mUnk_04 = (gEditKeyboard->mKeys[i]->mUnk_04 & 0xfffff3ff) | 0xc00;
    }
    for (i = 0; i < 4; i++) {
        gEditKeyboard->mExtraKeys[i] = func_ov003_021d1c18(0, data_ov003_021d5f70[i]);
        gEditKeyboard->mExtraKeys[i]->mUnk_00 = (gEditKeyboard->mExtraKeys[i]->mUnk_00 & 0xc1fffcff) | 0x200;
        gEditKeyboard->mExtraKeys[i]->mUnk_04 = (gEditKeyboard->mExtraKeys[i]->mUnk_04 & 0xfffff3ff) | 0xc00;
    }
    for (i = 0; i < 2; i++) {
        gEditKeyboard->mRow4Keys[i] = func_ov003_021d1be4(0, data_ov003_021d5f68[i], 1);
        func_ov003_021d18f0(gEditKeyboard->mRow4Keys[i], -1, 0x200, 0);
        func_ov003_021d1790(gEditKeyboard->mRow4Keys[i], -1, 3);
    }
    text[1] = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            gEditKeyboard->mRowTexts[i][j] =
                func_ov003_021d23b0(0, data_ov003_021d5f74[0], data_ov003_021d5f74[1], 0, &w, 0);
            charIndex = j * 12;
            for (k = 0, textRect[0] = 0; k < 12; k++, charIndex++, textRect[0] += 0x12) {
                text[0] = data_ov003_021d6be8[i][charIndex];
                func_ov003_021d2070(gEditKeyboard->mRowTexts[i][j], textRect[0], textRect[1], textRect[2], textRect[3],
                                    2, 0x480, text);
            }
            if (i == 0) {
                gEditKeyboard->mUnk_104[j] = func_ov003_021d19e0(0, w, 1);
            }
        }
    }
    gEditKeyboard->mCursor = func_ov003_021d1be4(0, 0x40, 1);
    func_ov003_021d18f0(gEditKeyboard->mCursor, -1, 0x200, 0);
    func_ov003_021d1790(gEditKeyboard->mCursor, -1, 2);
    gEditKeyboard->mStepTask = (TaskEntry *) func_ov003_021d3544(0, AdvanceEditKeyboardSlideInRow0, NULL, 0x78);
    SetEditKeyboardRowY(gEditKeyboard->mPage, 0, 0xc0);
}

void StartEditKeyboardSlideOut(void) {
    func_ov003_021d197c(gEditKeyboard->mCursor);
    func_ov003_021d34e0(gEditKeyboard->mStepTask, AdvanceEditKeyboardSlideOutRow4);
}

u8 GetEditKeyboardInput(void) {
    return gEditKeyboard->mInput;
}

void SetEditKeyboardRemoveCharEnabled(u8 canRemove) {
    gEditKeyboard->mRemoveCharEnabled = canRemove;
}

void SetEditKeyboardAddCharEnabled(u8 canAdd) {
    gEditKeyboard->mAddCharEnabled = canAdd;
}

BOOL HasEditKeyboard(void) {
    if (gEditKeyboard != NULL) {
        return 1;
    }
    return 0;
}

static inline void func_ov003_021c0ab0_inline(Unk021bf920 *object, u32 *x, u32 *y) {
    *x = (object->mUnk_00 & 0x1ff0000) >> 16;
    *y = object->mUnk_00 & 0xff;
}

void AdvanceEditKeyboardSlideInRow0(TaskEntry *task) {
    s32 xPos;
    s32 y;
    func_ov003_021c0ab0_inline(gEditKeyboard->mKeys[0], (u32 *) &xPos, (u32 *) &y);
    y -= 12;
    if (y > data_ov003_021d5fb0[0][1]) {
        SetEditKeyboardRowY(gEditKeyboard->mPage, 0, y);
        return;
    }
    SetEditKeyboardRowY(gEditKeyboard->mPage, 0, data_ov003_021d5fb0[0][1]);
    SetEditKeyboardRowY(gEditKeyboard->mPage, 1, 0xc0);
    func_ov003_021d34e0(task, AdvanceEditKeyboardSlideInRow1);
}

void AdvanceEditKeyboardSlideInRow1(TaskEntry *task) {
    s32 xPos;
    s32 y;
    func_ov003_021c0ab0_inline(gEditKeyboard->mKeys[12], (u32 *) &xPos, (u32 *) &y);
    y -= 12;
    if (y > data_ov003_021d5fb0[12][1]) {
        SetEditKeyboardRowY(gEditKeyboard->mPage, 1, y);
        return;
    }
    SetEditKeyboardRowY(gEditKeyboard->mPage, 1, data_ov003_021d5fb0[12][1]);
    SetEditKeyboardRowY(gEditKeyboard->mPage, 2, 0xc0);
    func_ov003_021d34e0(task, AdvanceEditKeyboardSlideInRow2);
}

void AdvanceEditKeyboardSlideInRow2(TaskEntry *task) {
    s32 xPos;
    s32 y;
    func_ov003_021c0ab0_inline(gEditKeyboard->mKeys[24], (u32 *) &xPos, (u32 *) &y);
    y -= 12;
    if (y > data_ov003_021d5ff0[8][1]) {
        SetEditKeyboardRowY(gEditKeyboard->mPage, 2, y);
        return;
    }
    SetEditKeyboardRowY(gEditKeyboard->mPage, 2, data_ov003_021d5ff0[8][1]);
    SetEditKeyboardRowY(gEditKeyboard->mPage, 3, 0xc0);
    func_ov003_021d34e0(task, AdvanceEditKeyboardSlideInRow3);
}

void AdvanceEditKeyboardSlideInRow3(TaskEntry *task) {
    s32 xPos;
    s32 yPos;
    func_ov003_021c0ab0_inline(gEditKeyboard->mKeys[36], (u32 *) &xPos, (u32 *) &yPos);
    yPos -= 12;
    if (yPos > data_ov003_021d6030[4][1]) {
        SetEditKeyboardRowY(gEditKeyboard->mPage, 3, yPos);
        return;
    }
    SetEditKeyboardRowY(gEditKeyboard->mPage, 3, data_ov003_021d6030[4][1]);
    SetEditKeyboardRowY(gEditKeyboard->mPage, 4, 0xc0);
    func_ov003_021d34e0(task, AdvanceEditKeyboardSlideInRow4);
}

void AdvanceEditKeyboardSlideInRow4(TaskEntry *task) {
    u32 x;
    s32 y;
    func_ov003_021d1770(gEditKeyboard->mRow4Keys[0], 0, &x, &y);
    y -= 12;
    if (y > data_ov003_021d5f88[0][1]) {
        SetEditKeyboardRowY(gEditKeyboard->mPage, 4, y);
        return;
    }
    SetEditKeyboardRowY(gEditKeyboard->mPage, 4, data_ov003_021d5f88[0][1]);
    PlaceEditKeyboardCursor();
    func_ov003_021d34e0(task, AdvanceEditKeyboardInput);
}

void AdvanceEditKeyboardInput(void) {
    AdvanceEditKeyboardTouchPressed();
    AdvanceEditKeyboardTouchReleased();
    AdvanceEditKeyboardTouchDown();
    func_ov003_021c0318();
}

void AdvanceEditKeyboardTouchPressed(void) {
    Rect keyRect;
    s32 i;
    s32 j;
    if (func_ov003_021d2a34(&data_ov003_021d67e8) == 0) {
        return;
    }
    i = 0;
    gEditKeyboard->mPressedKeyIndex = -1;
    for (; i < 0x2f; i++) {
        func_ov003_021d250c(data_ov003_021d5fb0[i], data_ov003_021d5f7c[0], &keyRect);
        if (func_ov003_021d2a34(&keyRect) != 0) {
            if (gEditKeyboard->mAddCharEnabled == 0) {
                StartSoundSeq(9);
                return;
            }
            StartSoundSeq(0);
            gEditKeyboard->mPressedKeyIndex = i;
            return;
        }
    }
    for (j = 0; j < 4; j++) {
        func_ov003_021d250c(data_ov003_021d5f90[j], data_ov003_021d5fa0[j], &keyRect);
        if (func_ov003_021d2a34(&keyRect) != 0) {
            if ((j == 3 && gEditKeyboard->mRemoveCharEnabled == 0) || (j == 2 && gEditKeyboard->mAddCharEnabled == 0)) {
                StartSoundSeq(9);
                return;
            }
            StartSoundSeq(data_ov003_021d6bf4[j]);
            gEditKeyboard->mPressedKeyIndex = j + 0x2f;
            return;
        }
    }
    for (i = 0; i < 2; i++) {
        func_ov003_021d250c(data_ov003_021d5f88[i], data_ov003_021d5f78[0], &keyRect);
        if (func_ov003_021d2a34(&keyRect) != 0) {
            StartSoundSeq(0);
            gEditKeyboard->mPressedKeyIndex = i + 0x33;
            return;
        }
    }
}

void AdvanceEditKeyboardTouchReleased(void) {
    Rect keyRect;
    s32 i;
    u16(*extraKeySizes)[2];
    u16(*extraKeyOrigins)[2];
    s32 extraKeyIndex;
    gEditKeyboard->mInput = 0;
    if (func_ov003_021d299c(&data_ov003_021d67e8) == 0) {
        return;
    }
    for (i = 0; i < 0x2f; i++) {
        func_ov003_021d250c(data_ov003_021d5fb0[i], data_ov003_021d5f7c[0], &keyRect);
        if (func_ov003_021d299c(&keyRect) != 0) {
            if (gEditKeyboard->mPressedKeyIndex != i) {
                return;
            }
            gEditKeyboard->mInput = data_ov003_021d6bdc[gEditKeyboard->mPage][i];
            if (gEditKeyboard->mPage == 1) {
                ChangeEditKeyboardPage(0);
            }
            gEditKeyboard->mCursorKeyIndex = i;
            PlaceEditKeyboardCursor();
            return;
        }
    }
    extraKeyIndex = 2;
    extraKeySizes = data_ov003_021d5fa8;
    extraKeyOrigins = data_ov003_021d5f98;
    for (; extraKeyIndex < 4; extraKeySizes++, extraKeyOrigins++, extraKeyIndex++) {
        func_ov003_021d250c(*extraKeyOrigins, *extraKeySizes, &keyRect);
        if (func_ov003_021d299c(&keyRect) != 0) {
            if (gEditKeyboard->mPressedKeyIndex != extraKeyIndex + 0x2f) {
                return;
            }
            gEditKeyboard->mInput = data_ov003_021d5f80[extraKeyIndex];
            if (gEditKeyboard->mPage == 1) {
                ChangeEditKeyboardPage(0);
            }
            gEditKeyboard->mCursorKeyIndex = extraKeyIndex + 0x2f;
            PlaceEditKeyboardCursor();
            return;
        }
    }
    for (i = 0; i < 2; i++) {
        func_ov003_021d250c(data_ov003_021d5f88[i], data_ov003_021d5f78[0], &keyRect);
        if (func_ov003_021d299c(&keyRect) != 0) {
            if (gEditKeyboard->mPressedKeyIndex != i + 0x33) {
                return;
            }
            gEditKeyboard->mInput = data_ov003_021d5f6c[i];
            gEditKeyboard->mCursorKeyIndex = i + 0x33;
            PlaceEditKeyboardCursor();
            return;
        }
    }
    func_ov003_021d250c(data_ov003_021d5f90[0], data_ov003_021d5fa0[0], &keyRect);
    if (func_ov003_021d299c(&keyRect) != 0) {
        if (gEditKeyboard->mPressedKeyIndex != 0x2f) {
            return;
        }
        ToggleEditKeyboardPage2();
        gEditKeyboard->mCursorKeyIndex = 0x2f;
        PlaceEditKeyboardCursor();
        return;
    }
    func_ov003_021d250c(data_ov003_021d5f94[0], data_ov003_021d5fa4[0], &keyRect);
    if (func_ov003_021d299c(&keyRect) != 0) {
        if (gEditKeyboard->mPressedKeyIndex != 0x30) {
            return;
        }
        ToggleEditKeyboardPage1();
        gEditKeyboard->mCursorKeyIndex = 0x30;
        PlaceEditKeyboardCursor();
    }
}

void ToggleEditKeyboardPage2(void) {
    u32 page;
    if (gEditKeyboard->mPage == 2) {
        page = 0;
    } else {
        page = 2;
    }
    ChangeEditKeyboardPage(page);
    StartSoundSeq(1);
}

void ToggleEditKeyboardPage1(void) {
    ChangeEditKeyboardPage((gEditKeyboard->mPage != 1));
    StartSoundSeq(1);
}

void AdvanceEditKeyboardTouchDown(void) {
    Rect keyRect;
    s32 i;
    s32 extraKeyIndex;

    if (func_ov003_021d2a80(&data_ov003_021d67e8) == 0) {
        goto fail;
    }
    for (i = 0; i < 0x2f; i++) {
        func_ov003_021d250c(data_ov003_021d5fb0[i], data_ov003_021d5f7c[0], &keyRect);
        if (func_ov003_021d2a80(&keyRect) != 0) {
            if (gEditKeyboard->mPressedKeyIndex != i) {
                goto fail;
            }
            ChangeEditKeyboardHighlight(i);
            goto done;
        }
    }
    for (extraKeyIndex = 2; extraKeyIndex < 4; extraKeyIndex++) {
        func_ov003_021d250c(data_ov003_021d5f90[extraKeyIndex], data_ov003_021d5fa0[extraKeyIndex], &keyRect);
        if (func_ov003_021d2a80(&keyRect) != 0) {
            if (gEditKeyboard->mPressedKeyIndex != extraKeyIndex + 0x2f) {
                goto fail;
            }
            ChangeEditKeyboardHighlight(extraKeyIndex + 0x2f);
            if (extraKeyIndex == 3) {
                gEditKeyboard->mRepeatCalls++;
                if (gEditKeyboard->mRepeatCalls >= 0x28) {
                    if (gEditKeyboard->mRemoveCharEnabled == 0) {
                        StartSoundSeq(9);
                        gEditKeyboard->mPressedKeyIndex = -1;
                        return;
                    }
                    gEditKeyboard->mInput = 0x80;
                    gEditKeyboard->mRepeatCalls -= 7;
                    return;
                }
            }
            return;
        }
    }
    for (i = 0; i < 2; i++) {
        func_ov003_021d250c(data_ov003_021d5f88[i], data_ov003_021d5f78[0], &keyRect);
        if (func_ov003_021d2a80(&keyRect) != 0) {
            if (gEditKeyboard->mPressedKeyIndex != i + 0x33) {
                goto fail;
            }
            ChangeEditKeyboardHighlight(i + 0x33);
            goto done;
        }
    }
fail:
    ChangeEditKeyboardHighlight(-1);
done:
    gEditKeyboard->mRepeatCalls = 0;
}

void ChangeEditKeyboardHighlight(int keyIndex) {
    if (keyIndex != gEditKeyboard->mHighlightedKeyIndex) {
        SetEditKeyboardKeyHighlight(keyIndex, 1);
        SetEditKeyboardKeyHighlight(gEditKeyboard->mHighlightedKeyIndex, 0);
        gEditKeyboard->mHighlightedKeyIndex = keyIndex;
    }
}
