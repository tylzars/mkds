#pragma once

#include "types.h"

// Object at the start of the Unk021da104 allocation: the word at 0x00 and the halfword at 0x04 are written bit by
// bit.
typedef struct Unk021da104_04 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk021da104_04;

// 0xc bytes allocated by func_ov003_021beef8.
typedef struct Unk021da104 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ Unk021da104_04 *mUnk_04;
    /* 08 */ u8 mUnk_08;
    /* 09 */ u8 mUnk_09;
} Unk021da104;

// Message passed to func_ov003_021bea3c.
typedef struct Unk021bea3c {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
} Unk021bea3c;

extern Unk021da104 *data_ov003_021da104;

BOOL func_ov003_021be610(void (*callback)(u32, u32), void *buffer, u32 size);
BOOL func_ov003_021be708(void *entry, void *optionalBytes, u32 param_2);
BOOL func_ov003_021be7b8(void);
BOOL func_ov003_021be820(void);
BOOL func_ov003_021be860(u8 *address, u8 *name, s32 nameLength, u32 param_3);
s32 func_ov003_021be96c(u8 *output, s32 maxCount);
BOOL func_ov003_021be9b8(void);
void func_ov003_021bea3c(Unk021bea3c *message);
void func_ov003_021bee24(void);
void func_ov003_021beecc(void);
void func_ov003_021beef8(int index);
void AdvanceButtonReset(u32 task);
void ReleaseSlideButtons(u32 task);
