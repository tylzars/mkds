#include "03/code_021bf098.h"
#include "03/code_021bf000.h"

#include "03/code_021be610.h"
#include "03/code_021d1000.h"
#include "03/code_021d1770.h"
#include "03/code_021d1790.h"
#include "03/code_021d1970.h"
#include "03/code_021d197c.h"
#include "03/code_021d1c18.h"
#include "03/code_021d250c.h"
#include "03/code_021d2940.h"
#include "03/code_021d3000.h"
#include "03/code_021d3488.h"
#include "03/unk_021d5000.h"
#include "03/unk_021da000.h"
#include "03/code_021d27d8.h"

void CreateSlideButtons(u32 kind) {
    s32 buttonCount;
    s32 i;
    u8 *imageCursor;

    buttonCount = data_ov003_021d5ecc[kind];
    data_ov003_021da108 = func_ov003_021d283c(0x1c, 4);
    data_ov003_021da108->mButtonResult = -2;
    data_ov003_021da108->mKind = kind;
    i = 0;
    if (buttonCount > 0) {
        imageCursor = data_ov003_021d5edc + kind * 2;
        do {
            data_ov003_021da108->mButtons[i] = func_ov003_021d1be4(0, *imageCursor, 1);
            func_ov003_021d1790(data_ov003_021da108->mButtons[i], -1, 1);
            imageCursor++;
            i++;
        } while (i < buttonCount);
    }
    data_ov003_021da108->mUnk_08 = func_ov003_021d1be4(0, 1, 1);
    func_ov003_021d1790(data_ov003_021da108->mUnk_08, -1, 1);
    SetSlideButtonsY(0xc0);
    data_ov003_021da108->mStepTask = (TaskEntry *) func_ov003_021d3544(0, AdvanceSlideButtonsIn, NULL, 0x78);
}

void StartSlideButtonsOut(void) {
    data_ov003_021da108->mSlidingOut = 1;
    func_ov003_021d34e0(data_ov003_021da108->mStepTask, AdvanceSlideButtonsOut);
}

int GetButtonResult(void) {
    return data_ov003_021da108->mButtonResult;
}

void SetButtonResultIfNone(s32 result) {
    SlideButtons *slideButtons = data_ov003_021da108;
    if (slideButtons->mButtonResult == -1) {
        slideButtons->mButtonResult = result;
    }
}

void SetButtonResult(s8 result) {
    data_ov003_021da108->mButtonResult = result;
}

BOOL func_ov003_021bf2f0(void) {
    if (data_ov003_021da108 == NULL) {
        return 1;
    }
    if (data_ov003_021da108->mSlidingOut == 0) {
        return 1;
    }
    return 0;
}

void EnableButtonTouch(void) {
    data_ov003_021da108->mTouchDisabled = 0;
}

void DisableButtonTouch(void) {
    data_ov003_021da108->mTouchDisabled = 1;
}

void SetSlideButtonsY(s32 yPosition) {
    s32 buttonCount;
    s32 i;
    s32 buttonY;

    buttonCount = data_ov003_021d5ecc[data_ov003_021da108->mKind];
    buttonY = yPosition + data_ov003_021d5ed4[1] - data_ov003_021d5ec4[1];
    func_ov003_021d17d4(data_ov003_021da108->mUnk_08, -1, data_ov003_021d5ec4[0], yPosition);
    for (i = 0; i < buttonCount; i++) {
        func_ov003_021d17d4(data_ov003_021da108->mButtons[i], -1,
                            data_ov003_021d5ed4[(data_ov003_021d5eec + data_ov003_021da108->mKind * 2)[i] * 2],
                            buttonY);
    }
}

void AdvanceSlideButtonsIn(TaskEntry *task) {
    u32 a;
    s32 yPosition;

    func_ov003_021d1770(data_ov003_021da108->mUnk_08, 0, &a, &yPosition);
    yPosition = yPosition - 4;
    SetSlideButtonsY(yPosition);
    if (yPosition <= data_ov003_021d5ec4[1]) {
        SetSlideButtonsY(data_ov003_021d5ec4[1]);
        func_ov003_021d34e0(task, AdvanceSlideButtonsWait);
    }
}

void AdvanceSlideButtonsWait(TaskEntry *task) {
    u32 a = 0;

    data_ov003_021da108->mButtonResult = -1;
    data_ov003_021da108->mStepFrames = data_ov003_021da108->mStepFrames + 1;
    if (data_ov003_021da108->mStepFrames >= 4) {
        data_ov003_021da108->mStepFrames = a;
        func_ov003_021d34e0(task, AdvanceButtonTouch);
    }
}

void AdvanceButtonTouch(void) {
    Rect rect;
    s32 buttonCount;
    s32 i;
    u32 positionIndex;
    u32 touchedImage;

    buttonCount = data_ov003_021d5ecc[data_ov003_021da108->mKind];
    if (data_ov003_021da108->mTouchDisabled == 0) {
        if (data_ov003_021da108->mButtonResult != -1) {
            return;
        }
        for (i = 0; i < buttonCount; i++) {
            func_ov003_021d250c(&data_ov003_021d5ed4[(data_ov003_021d5eec + data_ov003_021da108->mKind * 2)[i] * 2],
                                data_ov003_021d5ec8, &rect);
            if (func_ov003_021d2a34(&rect) != 0) {
                if (data_ov003_021da108->mResetTask != 0) {
                    break;
                }
                touchedImage = (data_ov003_021d5edc + data_ov003_021da108->mKind * 2)[i] + 1;
                func_ov003_021d1c3c(0, touchedImage, func_ov003_021d1974(data_ov003_021da108->mButtons[i], 0));
                positionIndex = (data_ov003_021d5eec + data_ov003_021da108->mKind * 2)[i];
                func_ov003_021d17d4(data_ov003_021da108->mButtons[i], -1, data_ov003_021d5ed4[positionIndex * 2],
                                    data_ov003_021d5ed6[positionIndex * 2]);
                func_ov003_021d1790(data_ov003_021da108->mButtons[i], -1, 1);
                data_ov003_021da108->mResetTask = func_ov003_021d3544(0, AdvanceButtonReset, NULL, 0x6e);
                data_ov003_021da108->mButtonResult = i;
                return;
            }
        }
    }
    data_ov003_021da108->mButtonResult = -1;
}

void AdvanceSlideButtonsOut(TaskEntry *task) {
    u32 stackValue;
    int yPosition;
    func_ov003_021d1770(data_ov003_021da108->mUnk_08, 0, &stackValue, &yPosition);
    yPosition = yPosition + 4;
    SetSlideButtonsY(yPosition);
    if (192 <= yPosition) {
        func_ov003_021d34e0(task, ReleaseSlideButtons);
    }
}
