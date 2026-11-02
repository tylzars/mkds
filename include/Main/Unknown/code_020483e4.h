#pragma once

#include "types.h"

// 8-byte entries of two words: a string and a number.
typedef struct Unk02154228 {
    /* 00 */ const char *mUnk_00;
    /* 04 */ u8 mUnk_04;
    /* 05 */ u8 mUnk_05[0x3];
} Unk02154228;

#include "code_02003024.h"

extern Unk02154228 data_usa_02154228[];
extern const char data_usa_02165164[];
extern const char data_usa_02165168[];
extern const char data_usa_0216516c[];
extern const char data_usa_02165170[];
extern const char data_usa_02165174[];

void func_020483e4(u32 param_1, u8 *param_2);
void func_0204840c(u32 param_1, u8 *param_2);
u32 func_02048440(void);
u32 func_02048474(void);
void func_02048498(char *a, s32 b, s32 c);
void *func_02048504(const char *a, s32 b);
u32 func_02048590(char *param_1, u32 param_2, void **param_3);
u32 func_0204863c(void *a, void *b, u32 c);
int func_02048684(const char *param_1, void *param_2, u32 param_3);
void func_020486d4(void *a);
