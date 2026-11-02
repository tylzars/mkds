#pragma once

#include "types.h"

// 8-byte entries of a string and a number.
typedef struct Unk021541a8 {
    /* 00 */ const char *mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk021541a8;

extern Unk021541a8 data_usa_021541a8[];
extern const char data_usa_021650e0[];
extern const char data_usa_021650e4[];
extern const char data_usa_021650e8[];
extern const char data_usa_02165100[];
extern const char data_usa_02165108[];
extern const char data_usa_0216510c[];
extern const char data_usa_02165110[];
extern const char data_usa_02165124[];

void func_02048284(u32 param_1, u32 param_2);
void func_020482ac(int param_1, u8 *param_2, int param_3);
void func_020482f0(u32 param_1, u8 *param_2, int param_3);
void func_02048324(u32 param_1);
void func_02048350(char *a);
void func_020483a0(char *a);
