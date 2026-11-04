#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_02100094.h" // Unk02100094

// Object of the list func_02100138(0x6b): the shared MapObject part, then three words.
typedef struct Unk020a6cb4 {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ s32 mUnk_a8;
} Unk020a6cb4;

void func_020a6cb4(s32 a);
void *func_020a6d20(void);
s32 func_020a6d40(void);
void func_020a6d8c(Unk02100094 *a, Unk020a6cb4 *b);
void func_020a6e70(Unk02100094 *a);
BOOL func_020a6f94(Unk02100094 *a);
