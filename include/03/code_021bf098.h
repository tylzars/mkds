#pragma once

#include "types.h"
#include "03/code_021d1770.h"
#include "03/code_021d3488.h"

typedef struct Unk021d34e0 Unk021d34e0;

typedef struct SlideButtons {
    /* 00 */ Unk021d1770 *mButtons[2];
    /* 08 */ Unk021d1770 *mUnk_08;
    /* 0c */ Unk021d34e0 *mStepTask;
    /* 10 */ u32 mResetTask;
    /* 14 */ u16 mStepFrames;
    /* 16 */ s8 mButtonResult;
    /* 17 */ u8 mKind;
    /* 18 */ u8 mTouchDisabled;
    /* 19 */ u8 mSlidingOut;
} SlideButtons;

void AdvanceSlideButtonsOut(Unk021d34e0 *task);
void AdvanceButtonTouch(void);
void AdvanceSlideButtonsWait(Unk021d34e0 *task);
void AdvanceSlideButtonsIn(Unk021d34e0 *task);
void SetSlideButtonsY(s32 yPosition);
void DisableButtonTouch(void);
void EnableButtonTouch(void);
BOOL func_ov003_021bf2f0(void);
void SetButtonResult(s8 result);
void SetButtonResultIfNone(s32 result);
int GetButtonResult(void);
void StartSlideButtonsOut(void);
void CreateSlideButtons(u32 kind);
