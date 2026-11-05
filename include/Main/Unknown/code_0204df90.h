#pragma once

#include "types.h"

typedef struct Unk0217aa00_1658 Unk0217aa00_1658;

// Twenty bytes after a two-byte head.
typedef struct Unk0204e4d8 {
    /* 00 */ union {
        u8 mUnk_00;
        struct {
            u8 mUnk_00_0 : 4;
            u8 mUnk_00_4 : 4;
        };
    };
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02[0x14];
} Unk0204e4d8;

void func_0204df90(void);
void func_0204dfe0(u32 a);
void func_0204e03c(u32 a);
void func_0204e074(void);
void func_0204e090(void);
void func_0204e0bc(void);
void func_0204e128(void);
s32 func_0204e1a8(s32 a);
s32 func_0204e204(void);
s32 func_0204e29c(void);
void func_0204e304(u32 a);
void func_0204e3b4(u32 a);
s32 func_0204e3f0(u32 a);
void func_0204e474(void);
void func_0204e498(void);
void func_0204e4bc(void);
void func_0204e4d8(void);
void func_0204e568(void);
void func_0204e65c(Unk0217aa00_1658 *a);
void func_0204e6e8(u32 a, u32 b, Unk0204e4d8 *c);
void func_0204e928(void *a, u32 b, u32 c);
