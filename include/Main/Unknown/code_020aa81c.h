#pragma once

#include "types.h"

typedef struct TPData TPData;
typedef struct KeyboardRect KeyboardRect;
typedef struct KeyboardLayout KeyboardLayout;
typedef struct KeyboardKeys KeyboardKeys;

typedef struct KeyboardRect KeyboardRect;
typedef struct RepeatCounter RepeatCounter;
typedef struct KeyboardKeys KeyboardKeys;

typedef struct RepeatCounter RepeatCounter;

void PollKeyboard(void);
void AdvanceKeyboardKeys(u16 keys, TPData touchPoint);
u32 IsKeyboardTouchOnStartKeyId(KeyboardKeys *keyboardKeys);
void MarkKeyboardRects(KeyboardKeys *keyboardKeys);
void DrawKeyboardGlyphs(KeyboardKeys *keyboardKeys);
KeyboardRect *FindKeyboardRectAt(KeyboardKeys *keyboardKeys, s32 pointX, s32 pointY);
u16 FindFirstCharRectIndex(KeyboardLayout *keyboardLayout);
void FillKeyboardBg2Scr(KeyboardKeys *keyboardKeys);
void CallKeyboardKeyCallback(s32 a);
void SetKeyboardKeyCallback(s32 (*arg0)(u32, s32));
void SetKeyboardCursorCallback(u16 (*arg0)(s32, u16));
void func_020ab070(u32 arg0);
void func_020ab07c(u32 arg0);
void SetupKeyboardInputMasks(u16 a, u16 b, u16 c);
s32 GetKeyboardValueForKeyId(u32 keyId);
s32 GetKeyboardRectValue(KeyboardRect *keyboardRect);
KeyboardRect *FindKeyboardRectByValue(u16 value);
void HiraganaKatakanaLayoutCallback(KeyboardKeys *keyboardKeys);
void AsciiLayoutCallback(KeyboardKeys *keyboardKeys);
u16 GetKeyboardKeysPressedOrRepeated(void);
u16 GetKeyboardRepeatedKeys(void);
void AdvanceKeyboardKeyRepeat(void);
void SetupKeyboardKeyRepeat(u16 keyMask);
BOOL IsRepeatCounterFiring(RepeatCounter *repeatCounter);
void ResetRepeatCounter(RepeatCounter *repeatCounter);
void AdvanceKeyboardTextEntry(void);
void InitKeyboardTextEntry(s32 a, s32 b, s32 textCapacity);
u16 KeyboardCursorCallback(s32 rectValue, u16 b);
s32 KeyboardKeyCallback(u32 keyValue, s32 b);
s32 GetKeyboardLastCharIndex(void);
void SplitBytesIntoNibbles(u8 *src, u8 *dst, s32 n);
