#pragma once

#include "types.h"

// Returns the scene number the Keyboard screen asks for (-1 = none yet); UpdateKeyboardScene copies it into
// SceneNumbers.mNextScene when it is not -1.
u32 GetKeyboardNextScene(void);
void func_0212899c(void);
// Advances the Keyboard screen by one step: takes mNextState as mState, runs the handler of that state
// (AdvanceKeyboardState0 to AdvanceKeyboardState13) and then runs the cell and drawing helpers of the screen.
void AdvanceKeyboard(void);
void ShowKeyboardLayoutObject(void);
void func_02128b54(void);
void ShowKeyboardTextIndexObject(void);
void ShowKeyboardDisabledButtonObjects(void);
void ShowKeyboardCursorButtonObjects(void);
void PrintKeyboardTextChars(void);
// Handler of state 13 of the Keyboard mState switch in AdvanceKeyboard.
void AdvanceKeyboardState13(void);
// Handler of state 12 of the Keyboard mState switch in AdvanceKeyboard.
void AdvanceKeyboardState12(void);
// Handler of state 11 of the Keyboard mState switch in AdvanceKeyboard.
void AdvanceKeyboardState11(void);
// Handler of state 10 of the Keyboard mState switch in AdvanceKeyboard.
void AdvanceKeyboardState10(void);
// Handler of state 9 of the Keyboard mState switch in AdvanceKeyboard.
void AdvanceKeyboardState9(void);
// Handler of state 8 of the Keyboard mState switch in AdvanceKeyboard.
void AdvanceKeyboardState8(void);
// Handler of state 7 of the Keyboard mState switch in AdvanceKeyboard.
void AdvanceKeyboardState7(void);
// Handler of state 6 of the Keyboard mState switch in AdvanceKeyboard.
void AdvanceKeyboardState6(void);
void UpdateKeyboardNameButtons(void);
