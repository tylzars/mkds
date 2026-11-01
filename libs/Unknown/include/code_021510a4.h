#pragma once

#include "types.h"
#include "Main/Unknown/unk_02180000.h"

// Fields read from or written to the 14-byte object at data_021804a0 by func_021510a4 and func_02151910.
typedef struct Unk021510a4 {
    /* 00 */ u64 mUnk_00;
    /* 08 */ u64 mUnk_08;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
} Unk021510a4;

extern u16 data_usa_02180474;
extern u32 data_usa_02180478;
extern u8 data_usa_021804a0;

u8 *func_021510a4(const Unk021510a4 *a);
u16 func_02151128(u32 a, u32 b, u32 c);
u32 func_02151154(void);
u32 func_0215119c(const u8 *a, u32 b, u32 c, const u8 *d);
void func_021511d8(u32 a, u16 b, void *c);
u32 func_0215122c(u32 a, u32 b, void *c);
u32 func_02151288(u32 a, u32 b, u16 c, u32 d);
u32 func_02151620(const u8 *a);
u32 func_02151640(const u8 *a, const u8 *b);
u32 func_02151698(const u8 *a);
void func_021516b0(u32 a, u8 *b);
u8 func_021516d8(const u8 *a);
