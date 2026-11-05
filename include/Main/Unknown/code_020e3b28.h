#pragma once

#include "types.h"
#include "Main/Unknown/code_020f9c6c.h"

typedef struct Unk020e1e98_154 Unk020e1e98_154;
typedef struct Unk020e3ef4 Unk020e3ef4;
typedef struct Unk020e1dc0 Unk020e1dc0;
typedef struct Bridge Bridge;

// Block of twelve words.
typedef struct Unk020e3e48 {
    /* 00 */ u32 mUnk_00[12];
} Unk020e3e48;

void func_020e4380(Unk020e3ef4 *a);
void func_020e435c(void *a);
BOOL func_020e4320(s32 a);
void func_020e4184(Unk020e1dc0 *a);
void func_020e410c(Unk020e1dc0 *a);
void func_020e3ef4(Unk020e3ef4 *a, struct CourseMapRow *b, Unk020e1e98_154 *c);
void *func_020e3ea4(void);
void *func_020e3e48(void);
void *func_020e3dec(void);
void UpdateBridge(s32 a, Bridge *b); /* skipped for objects with mFlags & 4 (parked pool objects) */
void func_020e3b4c(Unk020e3ef4 *a, void *b, u32 c);
void func_020e3b28(void *a);
