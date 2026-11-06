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
void AdvanceKeyboardKeys(u16 a, TPData b);
u32 IsKeyboardTouchOnStartKeyId(KeyboardKeys *a);
void MarkKeyboardRects(KeyboardKeys *a);
void DrawKeyboardGlyphs(KeyboardKeys *a);
KeyboardRect *FindKeyboardRectAt(KeyboardKeys *a, s32 b, s32 c);
u16 FindFirstCharRectIndex(KeyboardLayout *a);
void FillKeyboardBg2Scr(KeyboardKeys *a);
void CallKeyboardKeyCallback(s32 a);
void SetKeyboardKeyCallback(s32 (*arg0)(u32, s32));
void SetKeyboardCursorCallback(u16 (*arg0)(s32, u16));
void func_020ab070(u32 arg0);
void func_020ab07c(u32 arg0);
void SetupKeyboardInputMasks(u16 a, u16 b, u16 c);
s32 GetKeyboardValueForKeyId(u32 a);
s32 GetKeyboardRectValue(KeyboardRect *p);
KeyboardRect *FindKeyboardRectByValue(u16 a);
void HiraganaKatakanaLayoutCallback(KeyboardKeys *p);
void AsciiLayoutCallback(KeyboardKeys *p);
u16 GetKeyboardKeysPressedOrRepeated(void);
u16 GetKeyboardRepeatedKeys(void);
void AdvanceKeyboardKeyRepeat(void);
void SetupKeyboardKeyRepeat(u16 a);
BOOL IsRepeatCounterFiring(RepeatCounter *p);
void ResetRepeatCounter(RepeatCounter *p0);
void AdvanceKeyboardTextEntry(void);
void InitKeyboardTextEntry(s32 a, s32 b, s32 c);
u16 KeyboardCursorCallback(s32 a, u16 b);
s32 KeyboardKeyCallback(u32 a, s32 b);
s32 GetKeyboardLastCharIndex(void);
void SplitBytesIntoNibbles(u8 *src, u8 *dst, s32 n);
