#pragma once

#include "types.h"

// 0xc-byte object built on the stack by func_02123384.
typedef struct Unk02123384 {
    /* 00 */ s32 mKind;
    /* 04 */ s32 mSize;
    /* 08 */ u8 mFromIndex;
    /* 09 */ u8 mToIndex;
    // The sender's mKartMask; written, not read through this struct.
    /* 0a */ u8 mKartMask;
} Unk02123384;

void func_02122b14(void);
void func_02122bf0(void);
void func_02122d74(void);
void func_02122f38(void);
void func_02123098(void);
void func_0212320c(void);
void func_02123384(void);
void func_0212357c(void);
s32 func_021236f8(void);
void func_02123a48(u32 a);
