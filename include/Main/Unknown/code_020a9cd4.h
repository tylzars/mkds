#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020a8ed8.h" // IronBall, Unk020a9224
#include "Main/Unknown/unk_0217b000.h"

void DrawIronBall(void *a, IronBall *p);
void func_020a9d98(void *a);
void CreateIronBall(void *a);
u32 func_020a9de4(Unk020a9224 *p, void *a, u8 *b, u8 *c);
void InitIronBall(IronBall *p);
s32 GetKeyboardChosenKeyValue(void);
s32 GetKeyboardCursorValue(void);
void MoveKeyboardCursorToValue(u16 a);
