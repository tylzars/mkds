#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020b4000.h" // Ncgr

void SetupKeyboardLayoutHiragana(KeyboardRect *a, Ncgr *b, u32 c);
void SetupKeyboardLayout(KeyboardRect *a, Ncgr *b, void (*c)(KeyboardKeys *), s32 d, u32 e, u16 *f);
u16 LookupCharInTablePair(u16 **a, u16 b);
KeyboardRect *FindKeyboardRectInDirection(u32 a, KeyboardRect *b, KeyboardRect *c);
void RefreshKeyboardCursor(KeyboardKeys *a);
void AddToNonzeroNibblesInRect(u32 (*a)[8], s32 b, u32 c, s32 d, s32 e, s32 f, s32 g);
void AddToNonzeroNibblesOnRectEdge(u32 (*a)[8], s32 b, u32 c, s32 d, s32 e, s32 f, s32 g);
void AddToNonzeroNibblesInTile(u32 *a, u32 b, s32 c, s32 d, s32 e, s32 f);
u32 IsCharInTable3(u16 a);
u32 IsCharInTable2(u16 a);
u32 IsCharInTable1(u16 a);
u16 CycleCharTables(u16 a);
u16 ConvertCharPair3(u16 a);
u16 ConvertCharPair2(u16 a);
u16 ConvertCharPair1(u16 a);
