#pragma once

#include "types.h"

typedef struct OamEntry OamEntry;
typedef struct OamRange OamRange;
typedef struct TaskEntry TaskEntry;

// Object behind gEditAddrKeyboard.
typedef struct EditAddrKeyboard {
    /* 00 */ void *mRowTexts[4];
    /* 10 */ OamEntry *mDigitKeys[10];
    /* 38 */ OamEntry *mExtraKeys[2];
    /* 40 */ OamRange *mRow4Keys[2];
    /* 48 */ OamRange *mUnk_48[4];
    /* 58 */ struct OamRange *mCursor;
    /* 5c */ TaskEntry *mStepTask;
    /* 60 */ u8 mInput;
    /* 61 */ s8 mPressedKeyIndex;
    /* 62 */ s8 mHighlightedKeyIndex;
    /* 63 */ s8 mCursorKeyIndex;
    /* 64 */ s8 mUnk_64;
    /* 65 */ u8 mRepeatCalls;
    /* 66 */ u8 mRemoveCharEnabled;
    /* 67 */ u8 mAddCharEnabled;
    /* 68 */ u8 mNextGroupEnabled;
    /* 69 */ u8 mRemoveDisabledSoundPlayed;
} EditAddrKeyboard;

// Five bytes moved as one value.
typedef struct Unk021c1364_05 {
    /* 0 */ u8 mUnk_00[5];
} Unk021c1364_05;

void ReleaseEditAddrKeyboard(u32 task);
void AdvanceEditAddrKeyboardSlideOutRow0(TaskEntry *task);
void AdvanceEditAddrKeyboardSlideOutRow1(TaskEntry *task);
void AdvanceEditAddrKeyboardSlideOutRow2(TaskEntry *task);
void AdvanceEditAddrKeyboardSlideOutRow3(TaskEntry *task);
void AdvanceEditAddrKeyboardSlideOutRow4(TaskEntry *task);
void MoveEditAddrKeyboardCursor(u32 direction);
void PlaceEditAddrKeyboardCursor(void);
void SetEditAddrKeyboardKeyHighlight(int keyIndex, int highlight);
void SetEditAddrKeyboardRowY(int row, u32 yPos);
void AdvanceEditAddrKeyboardKeys(void);
void ChangeEditAddrKeyboardHighlight(int keyIndex);
void AdvanceEditAddrKeyboardTouchDown(void);
void AdvanceEditAddrKeyboardTouchReleased(void);
void AdvanceEditAddrKeyboardTouchPressed(void);
void AdvanceEditAddrKeyboardInput(void);
void AdvanceEditAddrKeyboardSlideInRow4(TaskEntry *task);
void AdvanceEditAddrKeyboardSlideInRow3(TaskEntry *task);
void AdvanceEditAddrKeyboardSlideInRow2(TaskEntry *task);
void AdvanceEditAddrKeyboardSlideInRow1(TaskEntry *task);
void AdvanceEditAddrKeyboardSlideInRow0(TaskEntry *task);
BOOL HasEditAddrKeyboard(void);
void SetEditAddrKeyboardNextGroupEnabled(u8 canNextGroup);
void SetEditAddrKeyboardAddCharEnabled(u8 canAdd);
void SetEditAddrKeyboardRemoveCharEnabled(u8 canRemove);
u8 GetEditAddrKeyboardInput(void);
void StartEditAddrKeyboardSlideOut(void);
void CreateEditAddrKeyboard(void);
