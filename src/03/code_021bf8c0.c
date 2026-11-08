#include "03/code_021bf8c0.h"
#include "03/code_021bf4dc.h"
#include "03/code_021c0fd8.h"
#include "03/code_021bf000.h"
#include "03/code_021bf810.h"
#include "03/code_021c0000.h"
#include "03/code_021c209c.h"
#include "03/code_021c04ec.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1790.h"
#include "03/code_021d197c.h"
#include "03/unk_021da000.h"
#include "03/code_021d2940.h"
#include "code_02147cd8.h"
#include "03/code_021d1000.h"
#include "03/code_021d1970.h"
#include "03/code_021d1c18.h"
#include "03/code_021d2ecc.h"
#include "03/code_021d3000.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d27d8.h"
#include "03/code_021d3488.h"
#include "03/code_021d1770.h"
#include "03/unk_021d5f00.h"
#include "code_02142eac.h"
#include "code_0214b824.h"
#include "03/unk_021d67d8.h"
#include "registers.h"

static inline void func_ov003_021bfbd0_inline(Unk021bf920 *object, u32 *x, u32 *y) {
    *x = (object->mUnk_00 & 0x1ff0000) >> 16;
    *y = object->mUnk_00 & 0xff;
}

void func_ov003_021c0318(void) {
    s32 cursorKeyIndex;
    if (func_ov003_021d2ae8(0x20) != 0) {
        MoveEditKeyboardCursor(0);
    }
    if (func_ov003_021d2ae8(0x40) != 0) {
        MoveEditKeyboardCursor(1);
    }
    if (func_ov003_021d2ae8(0x10) != 0) {
        MoveEditKeyboardCursor(2);
    }
    if (func_ov003_021d2ae8(0x80) != 0) {
        MoveEditKeyboardCursor(3);
    }
    if (func_ov003_021d2b04(1) != 0) {
        cursorKeyIndex = gEditKeyboard->mCursorKeyIndex;
        if (cursorKeyIndex < 0x2f) {
            if (gEditKeyboard->mAddCharEnabled == 0) {
                StartSoundSeq(9);
                return;
            }
            gEditKeyboard->mInput = data_ov003_021d6bdc[gEditKeyboard->mPage][cursorKeyIndex];
            if (gEditKeyboard->mPage == 1) {
                ChangeEditKeyboardPage(0);
            }
            return;
        }
        if (cursorKeyIndex - 0x2f < 4) {
            switch (cursorKeyIndex - 0x2f) {
                case 0:
                    ToggleEditKeyboardPage2();
                    return;
                case 1:
                    ToggleEditKeyboardPage1();
                    return;
                case 2:
                    if (gEditKeyboard->mAddCharEnabled == 0) {
                        StartSoundSeq(9);
                        return;
                    }
                    break;
                case 3:
                    if (gEditKeyboard->mRemoveCharEnabled == 0) {
                        StartSoundSeq(9);
                        return;
                    }
                    break;
            }
            if (gEditKeyboard->mPage == 1) {
                ChangeEditKeyboardPage(0);
            }
            gEditKeyboard->mInput = data_ov003_021d5f80[cursorKeyIndex - 0x2f];
            return;
        }
        gEditKeyboard->mInput = data_ov003_021d5f6c[cursorKeyIndex - 0x33];
    }
    if (func_ov003_021d2ae8(2) != 0) {
        if (gEditKeyboard->mRemoveCharEnabled == 0) {
            if (gEditKeyboard->mRemoveDisabledSoundPlayed != 0) {
                return;
            }
            StartSoundSeq(9);
            gEditKeyboard->mRemoveDisabledSoundPlayed = 1;
            return;
        }
        gEditKeyboard->mInput = 0x80;
    } else if (func_ov003_021d2acc(2) != 0) {
        gEditKeyboard->mRemoveDisabledSoundPlayed = 0;
    }
    if (func_ov003_021d2b04(0x400) != 0) {
        ToggleEditKeyboardPage2();
    }
    if (func_ov003_021d2b04(0x800) != 0) {
        ToggleEditKeyboardPage1();
    }
}

void SetEditKeyboardRowY(u32 page, s32 row, u32 yPos) {
    u8 keyCounts[5];
    u8 extraKeyCounts[5];
    u8 row4KeyCounts[5];
    s32 i;
    s32 keyIndex;
    s32 extraKeyIndex;
    Unk021bf920 *key;
    *(Unk021c1364_05 *) keyCounts = *(Unk021c1364_05 *) data_ov003_021d6bcc;
    *(Unk021c1364_05 *) extraKeyCounts = *(Unk021c1364_05 *) data_ov003_021d6bd4;
    *(Unk021c1364_05 *) row4KeyCounts = *(Unk021c1364_05 *) data_ov003_021d6bc4;
    keyIndex = row * 12;
    for (i = 0; i < keyCounts[(u32) row]; i++, keyIndex++) {
        key = gEditKeyboard->mKeys[keyIndex];
        key->mUnk_00 = key->mUnk_00 & 0xc1fffcff;
        key = gEditKeyboard->mKeys[keyIndex];
        key->mUnk_00 =
            ((data_ov003_021d5fb0[keyIndex][0] & 0x1ff) << 16) | ((key->mUnk_00 & 0xfe00ff00) | (yPos & 0xff));
    }
    if (row < 4) {
        func_ov003_021d1ffc(gEditKeyboard->mRowTexts[page][row], data_ov003_021d5fb0[row * 12][0], yPos,
                            gEditKeyboard->mUnk_104[row], 2);
    }
    extraKeyIndex = FX_ModS32(row + 3, 4);
    for (i = 0; i < extraKeyCounts[(u32) row]; i++) {
        key = gEditKeyboard->mExtraKeys[extraKeyIndex];
        key->mUnk_00 = key->mUnk_00 & 0xc1fffcff;
        key = gEditKeyboard->mExtraKeys[extraKeyIndex];
        key->mUnk_00 =
            ((data_ov003_021d5f90[extraKeyIndex][0] & 0x1ff) << 16) | ((key->mUnk_00 & 0xfe00ff00) | (yPos & 0xff));
    }
    for (i = 0; i < row4KeyCounts[(u32) row]; i++) {
        func_ov003_021d18f0(gEditKeyboard->mRow4Keys[i], -1, 0, 0);
        func_ov003_021d17d4(gEditKeyboard->mRow4Keys[i], -1, data_ov003_021d5f88[i][0], yPos);
    }
}

void ChangeEditKeyboardPage(int page) {
    BOOL page2Selected;
    BOOL page1Selected;
    s32 i;
    s32 firstKeyIndex;
    page2Selected = FALSE;
    page1Selected = FALSE;
    gEditKeyboard->mPage = page;
    i = 0;
    if (i < 4) {
        firstKeyIndex = 0;
        do {
            SetEditKeyboardRowY(page, i, data_ov003_021d5fb0[firstKeyIndex][1]);
            firstKeyIndex = (s32) (firstKeyIndex + 12);
            i++;
        } while (i < 4);
    }
    if (page == 2) {
        page2Selected = TRUE;
    } else if (page == 1) {
        page1Selected = TRUE;
    }
    SetEditKeyboardKeyHighlight(0x2f, page2Selected);
    SetEditKeyboardKeyHighlight(0x30, page1Selected);
}

void SetEditKeyboardKeyHighlight(int keyIndex, int highlight) {
    Unk021bf920 *key;
    s32 extraKeyIndex;
    if (keyIndex < 0) {
        return;
    }
    if (keyIndex < 0x2f) {
        key = gEditKeyboard->mKeys[keyIndex];
        key->mUnk_00 = key->mUnk_00 & 0xfffff3ff;
        key->mUnk_04 = (key->mUnk_04 & 0xffff0fff) | (data_ov003_021d5f60[highlight] << 12);
        return;
    }
    extraKeyIndex = keyIndex - 0x2f;
    if (extraKeyIndex < 4) {
        key = gEditKeyboard->mExtraKeys[extraKeyIndex];
        key->mUnk_00 = key->mUnk_00 & 0xfffff3ff;
        key->mUnk_04 = (key->mUnk_04 & 0xffff0fff) | (data_ov003_021d5f60[highlight] << 12);
        return;
    }
    func_ov003_021d1890(gEditKeyboard->mRow4Keys[keyIndex - 0x33], -1, 0, data_ov003_021d5f64[highlight]);
}

void PlaceEditKeyboardCursor(void) {
    u32 imageIndex;
    switch (gEditKeyboard->mCursorKeyIndex) {
        case 0x2f:
            imageIndex = 0x42;
            break;
        case 0x30:
            imageIndex = 0x41;
            break;
        case 0x31:
            imageIndex = 0x43;
            break;
        case 0x32:
            imageIndex = 0x41;
            break;
        case 0x33:
        case 0x34:
            imageIndex = 0x45;
            break;
        default:
            imageIndex = 0x40;
            break;
    }
    func_ov003_021d1c3c(0, imageIndex, func_ov003_021d1974(gEditKeyboard->mCursor, 0));
    func_ov003_021d1790(gEditKeyboard->mCursor, -1, 2);
    func_ov003_021d17d4(gEditKeyboard->mCursor, -1, data_ov003_021d606c[gEditKeyboard->mCursorKeyIndex][0],
                        data_ov003_021d606e[gEditKeyboard->mCursorKeyIndex][0]);
}

void MoveEditKeyboardCursor(int direction) {
    s8 previousKeyIndex;
    previousKeyIndex = gEditKeyboard->mCursorKeyIndex;
    gEditKeyboard->mCursorKeyIndex = data_ov003_021d6140[previousKeyIndex][direction];
    if (gEditKeyboard->mCursorKeyIndex == 0x2e && direction == 3) {
        gEditKeyboard->mUnk_120 = previousKeyIndex;
    } else if (gEditKeyboard->mCursorKeyIndex == 0x33 && (direction == 1 || direction == 3)) {
        gEditKeyboard->mUnk_120 = previousKeyIndex;
    } else if (gEditKeyboard->mCursorKeyIndex == 0x34 && (direction == 1 || direction == 3)) {
        if (previousKeyIndex != 0x2e) {
            gEditKeyboard->mUnk_120 = previousKeyIndex;
        }
    } else if (gEditKeyboard->mCursorKeyIndex == -1) {
        if (gEditKeyboard->mUnk_120 == 0x23 || gEditKeyboard->mUnk_120 == 0x32) {
            gEditKeyboard->mCursorKeyIndex = 0x23;
        } else {
            gEditKeyboard->mCursorKeyIndex = 0x22;
        }
    } else if (gEditKeyboard->mCursorKeyIndex == -2) {
        switch (gEditKeyboard->mUnk_120) {
            case 0:
            case 0x31:
                gEditKeyboard->mCursorKeyIndex = 0x31;
                break;
            case 1:
            case 0x24:
                gEditKeyboard->mCursorKeyIndex = 0x24;
                break;
            case 3:
            case 0x26:
                gEditKeyboard->mCursorKeyIndex = 0x26;
                break;
            case 4:
            case 0x27:
                gEditKeyboard->mCursorKeyIndex = 0x27;
                break;
            case 5:
            case 0x28:
                gEditKeyboard->mCursorKeyIndex = 0x28;
                break;
            default:
                gEditKeyboard->mCursorKeyIndex = 0x25;
                break;
        }
    } else if (gEditKeyboard->mCursorKeyIndex == -3) {
        switch (gEditKeyboard->mUnk_120) {
            case 6:
            case 0x29:
                gEditKeyboard->mCursorKeyIndex = 0x29;
                break;
            case 7:
            case 0x2a:
                gEditKeyboard->mCursorKeyIndex = 0x2a;
                break;
            case 9:
            case 0x2c:
                gEditKeyboard->mCursorKeyIndex = 0x2c;
                break;
            case 10:
            case 0x2d:
                gEditKeyboard->mCursorKeyIndex = 0x2d;
                break;
            case 11:
            case 0x22:
            case 0x23:
            case 0x32:
                gEditKeyboard->mCursorKeyIndex = 0x2e;
                break;
            default:
                gEditKeyboard->mCursorKeyIndex = 0x2b;
                break;
        }
    } else if (gEditKeyboard->mCursorKeyIndex == -4) {
        switch (gEditKeyboard->mUnk_120) {
            case 0:
            case 0x31:
                gEditKeyboard->mCursorKeyIndex = 0;
                break;
            case 1:
            case 0x24:
                gEditKeyboard->mCursorKeyIndex = 1;
                break;
            case 3:
            case 0x26:
                gEditKeyboard->mCursorKeyIndex = 3;
                break;
            case 4:
            case 0x27:
                gEditKeyboard->mCursorKeyIndex = 4;
                break;
            case 5:
            case 0x28:
                gEditKeyboard->mCursorKeyIndex = 5;
                break;
            default:
                gEditKeyboard->mCursorKeyIndex = 2;
                break;
        }
    } else if (gEditKeyboard->mCursorKeyIndex == -5) {
        switch (gEditKeyboard->mUnk_120) {
            case 6:
            case 0x29:
                gEditKeyboard->mCursorKeyIndex = 6;
                break;
            case 7:
            case 0x2a:
                gEditKeyboard->mCursorKeyIndex = 7;
                break;
            case 9:
            case 0x2c:
                gEditKeyboard->mCursorKeyIndex = 9;
                break;
            case 10:
            case 0x2d:
                gEditKeyboard->mCursorKeyIndex = 10;
                break;
            case 11:
            case 0x22:
                gEditKeyboard->mCursorKeyIndex = 11;
                break;
            case 0x23:
            case 0x32:
                gEditKeyboard->mCursorKeyIndex = 0x32;
                break;
            default:
                gEditKeyboard->mCursorKeyIndex = 8;
                break;
        }
    }
    PlaceEditKeyboardCursor();
    StartSoundSeq(8);
}

void AdvanceEditKeyboardSlideOutRow4(TaskEntry *task) {
    s32 xPos;
    s32 yPos;
    func_ov003_021bfbd0_inline(func_ov003_021d1974(gEditKeyboard->mRow4Keys[0], 0), (u32 *) &xPos, (u32 *) &yPos);
    yPos += 12;
    SetEditKeyboardRowY(gEditKeyboard->mPage, 4, yPos);
    if (yPos >= 0xc0) {
        func_ov003_021d34e0(task, AdvanceEditKeyboardSlideOutRow3);
    }
}

void AdvanceEditKeyboardSlideOutRow3(TaskEntry *task) {
    s32 xPos;
    s32 y;
    func_ov003_021bfbd0_inline(gEditKeyboard->mKeys[36], (u32 *) &xPos, (u32 *) &y);
    y += 12;
    SetEditKeyboardRowY(gEditKeyboard->mPage, 3, y);
    if (y >= 0xc0) {
        func_ov003_021d34e0(task, AdvanceEditKeyboardSlideOutRow2);
    }
}

void AdvanceEditKeyboardSlideOutRow2(TaskEntry *task) {
    s32 xPos;
    s32 yPos;
    func_ov003_021bfbd0_inline(gEditKeyboard->mKeys[24], (u32 *) &xPos, (u32 *) &yPos);
    yPos += 12;
    SetEditKeyboardRowY(gEditKeyboard->mPage, 2, yPos);
    if (yPos >= 0xc0) {
        func_ov003_021d34e0(task, AdvanceEditKeyboardSlideOutRow1);
    }
}

void AdvanceEditKeyboardSlideOutRow1(TaskEntry *task) {
    s32 x;
    s32 y;
    func_ov003_021bfbd0_inline(gEditKeyboard->mKeys[12], (u32 *) &x, (u32 *) &y);
    y += 12;
    SetEditKeyboardRowY(gEditKeyboard->mPage, 1, y);
    if (y >= 0xc0) {
        func_ov003_021d34e0(task, AdvanceEditKeyboardSlideOutRow0);
    }
}

void AdvanceEditKeyboardSlideOutRow0(TaskEntry *task) {
    s32 xPos;
    s32 y;
    func_ov003_021bfbd0_inline(gEditKeyboard->mKeys[0], (u32 *) &xPos, (u32 *) &y);
    y += 12;
    SetEditKeyboardRowY(gEditKeyboard->mPage, 0, y);
    if (y >= 0xc0) {
        func_ov003_021d34e0(task, ReleaseEditKeyboard);
    }
}

void ReleaseEditKeyboard(u32 task) {
    s32 i;
    s32 j;
    func_ov003_021d34c8(0, task);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            func_ov003_021d2388(gEditKeyboard->mRowTexts[i][j]);
            if (i == 0) {
                func_ov003_021d197c(gEditKeyboard->mUnk_104[j]);
            }
        }
    }
    for (i = 0; i < 2; i++) {
        func_ov003_021d197c(gEditKeyboard->mRow4Keys[i]);
    }
    for (i = 0; i < 4; i++) {
        func_ov003_021d2f00((u32 *) gEditKeyboard->mExtraKeys[i]);
    }
    for (i = 0; i < 0x2f; i++) {
        func_ov003_021d2f00((u32 *) gEditKeyboard->mKeys[i]);
    }
    func_ov003_021d2808(&gEditKeyboard);
}

void CreateLinkLevel(int row) {
    if (gLinkLevel == NULL) {
        gLinkLevel = func_ov003_021d285c(0xc, 4);
        gLinkLevel->mUnk_08 = row;
        gLinkLevel->mUnk_00 = func_ov003_021d1c18(0, data_ov003_021d5f58[row][0]);
        gLinkLevel->mUnk_00->mUnk_00 = ((data_ov003_021d5f54[0] & 0x1ff) << 16) |
                                       ((gLinkLevel->mUnk_00->mUnk_00 & 0xfe00ff00) | (data_ov003_021d5f54[1] & 0xff));
        gLinkLevel->mUnk_00->mUnk_04 = (gLinkLevel->mUnk_00->mUnk_04 & 0xfffff3ff) | 0x800;
        gLinkLevel->mTask = func_ov003_021d3544(0, UpdateLinkLevel, NULL, 0x78);
    }
}

void ReleaseLinkLevel(void) {
    if (gLinkLevel != NULL) {
        func_ov003_021d34c0(0, gLinkLevel->mTask);
        func_ov003_021d2f00((u32 *) gLinkLevel->mUnk_00);
        func_ov003_021d2808(&gLinkLevel);
    }
}

void UpdateLinkLevel(void) {
    u32 linkLevel;
    u16 savedIme;
    linkLevel = 0;
    savedIme = reg_OS_IME;
    reg_OS_IME = 0;
    if (WM_GetAllowedChannel() != 0x8000) {
        linkLevel = WM_GetLinkLevel();
    }
    reg_OS_IME;
    reg_OS_IME = savedIme;
    func_ov003_021d1c3c(0, data_ov003_021d5f58[gLinkLevel->mUnk_08][linkLevel], (u8 *) gLinkLevel->mUnk_00);
    gLinkLevel->mUnk_00->mUnk_00 = ((data_ov003_021d5f54[0] & 0x1ff) << 16) |
                                   ((gLinkLevel->mUnk_00->mUnk_00 & 0xfe00ff00) | (data_ov003_021d5f54[1] & 0xff));
    gLinkLevel->mUnk_00->mUnk_04 = (gLinkLevel->mUnk_00->mUnk_04 & 0xfffff3ff) | 0x800;
}

void InitHlScr(void) {
    gHlScr = func_ov003_021d285c(0xc0, 4);
    LoadFileToVram(gJbBgHlNcgName, GX_LoadBG1Char);
    switch (GetMode()) {
        case 0:
            LoadFileToVram(gHlNscNames[0], GX_LoadBG1Scr);
            break;
        case 1:
            LoadFileToVram(gHlNscNames[1], GX_LoadBG1Scr);
            break;
    }
}
