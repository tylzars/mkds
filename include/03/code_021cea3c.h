#pragma once

#include "types.h"

typedef struct TaskEntry TaskEntry;

typedef struct Unk021d1770 Unk021d1770;

void func_ov003_021cea3c(u32 a);
void func_ov003_021ceab8(TaskEntry *a);
void func_ov003_021ceaf8(TaskEntry *a);
void func_ov003_021ceb54(TaskEntry *a);
void func_ov003_021ceb80(s32 a);
void func_ov003_021cec00(Unk021d1770 *a, s32 b);
void func_ov003_021cec50(s32 a);
void func_ov003_021ced78(u32 a);
void func_ov003_021cedbc(void);
void func_ov003_021cee98(u32 a);
void func_ov003_021cef28(TaskEntry *a);
u32 func_ov003_021cef6c(void);
int func_ov003_021cef80(void);
// K&R on purpose: a caller passes a u8 array where the definition takes a u16 *.
void func_ov003_021d2658();
