#pragma once

#include "types.h"

typedef struct Unk020176c0 Unk020176c0;

// 8-byte entries of two words: a string and a number.
typedef struct Unk02154228 {
    /* 00 */ const char *mUnk_00;
    /* 04 */ u8 mUnk_04;
    /* 05 */ u8 mUnk_05[0x3];
} Unk02154228;

extern Unk02154228 data_usa_02154228[];
extern const char data_usa_02165164[];
extern const char data_usa_02165168[];
extern const char data_usa_0216516c[];
extern const char data_usa_02165170[];
extern const char data_usa_02165174[];

void func_020483e4(char *a, u8 *b);
void func_0204840c(char *a, u8 *b);
u32 func_02048440(void);
u32 func_02048474(void);
void func_02048498(char *a, s32 b, s32 c);
void *func_02048504(const char *a, s32 b);
u32 func_02048590(char *a, Unk020176c0 *b, void **c);
u32 func_0204863c(void *a, void *b, u32 c);
int func_02048684(const char *a, void *b, u32 c);
void func_020486d4(void *a);
