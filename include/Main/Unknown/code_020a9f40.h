#pragma once

#include "types.h"
#include "Main/Unknown/code_020b4000.h"

typedef struct KeyboardRect KeyboardRect;

void SetupKeyboardLayoutOther3(KeyboardRect *a, struct Ncgr *b, u32 c);
void SetupKeyboardLayoutOther2(KeyboardRect *a, struct Ncgr *b, u32 c);
void SetupKeyboardLayoutOther1(KeyboardRect *a, struct Ncgr *b, u32 c);
void SetupKeyboardLayoutAscii(KeyboardRect *a, struct Ncgr *b, u32 c);
