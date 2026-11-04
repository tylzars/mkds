#pragma once

#include "types.h"
#include "code_0212da38.h" // LinkedList
#include "Main/Unknown/code_0210bafc.h" // Unk0217cd30

// Addressed at the byte offset LinkedList::mUnk_0a of the pointer passed to func_0210bc54.
typedef struct Unk0210bc54 {
    /* 0 */ u8 mUnk_00[8];
    /* 8 */ u32 mUnk_08;
} Unk0210bc54;

u32 func_0210bc8c(int a, int b);
void func_0210bc54(LinkedList *a, void *b);
void func_0210bc14(void);
