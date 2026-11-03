#pragma once

#include "types.h"

// 0x18-byte entries.
typedef struct Unk021543e0 {
    /* 00 */ const char *mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s8 mUnk_08;
    /* 09 */ u8 mUnk_09[0x3];
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
} Unk021543e0;

extern const char data_usa_02165058[];
extern Unk021543e0 data_usa_021543e0[];

void func_02047b88(void);
void func_02047ba0(s32 a);
void func_02047cf0(int a);
void func_02047db8(void);
void func_02047e0c(void);
void func_02047e94(void);
void func_02047f7c(s32 a, const char *b, u32 *c, void *d, s32 e, s32 f, s32 g);
void func_02048050(int a, int b);
