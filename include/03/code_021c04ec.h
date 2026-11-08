#pragma once

#include "types.h"
#include "03/code_021d3488.h"

// Stack object of CreateEditKeyboard.
typedef struct Unk021c0d2c {
    /* 00 */ u16 mUnk_00[4];
    /* 08 */ u32 mUnk_08;
    /* 0c */ u16 mUnk_0c[2];
} Unk021c0d2c;

void ChangeEditKeyboardHighlight(int keyIndex);
void AdvanceEditKeyboardTouchDown(void);
void ToggleEditKeyboardPage1(void);
void ToggleEditKeyboardPage2(void);
void AdvanceEditKeyboardTouchReleased(void);
void AdvanceEditKeyboardTouchPressed(void);
void AdvanceEditKeyboardInput(void);
void AdvanceEditKeyboardSlideInRow4(TaskEntry *task);
void AdvanceEditKeyboardSlideInRow3(TaskEntry *task);
void AdvanceEditKeyboardSlideInRow2(TaskEntry *task);
void AdvanceEditKeyboardSlideInRow1(TaskEntry *task);
void AdvanceEditKeyboardSlideInRow0(TaskEntry *task);
BOOL HasEditKeyboard(void);
void SetEditKeyboardAddCharEnabled(u8 canAdd);
void SetEditKeyboardRemoveCharEnabled(u8 canRemove);
u8 GetEditKeyboardInput(void);
void StartEditKeyboardSlideOut(void);
void CreateEditKeyboard(void);
