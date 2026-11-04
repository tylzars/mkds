#pragma once

#include "types.h"

typedef struct Unk020e6514 Unk020e6514;

// 0x10-byte slot of the two tables at data_0217baec and data_0217baf0; the
// slot's first word points at an object with a word at 0x0c, a u16 at 0x1a and
// a pointer to the u32 array at 0x1c.
typedef struct Unk0217baec {
    /* 00 */ Unk020e6514 *mUnk_00;
    /* 04 */ u8 mUnk_04[0x0c];
} Unk0217baec;

// Object at 0x00 of a data_0217bae8 row, as func_020e9810 reads it: the word at 0x04.
typedef struct Unk020e9810 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ void *mUnk_04;
} Unk020e9810;

extern Unk0217baec data_0217baec[];
extern Unk0217baec data_0217baf0[];

void func_020e7a84(void);
void func_020e7b7c(void);
void func_020e7d90(void);
void func_020e7e58(void);
void func_020e7ed0(void);
void func_020e7fa8(void);
void func_020e827c(void);
void func_020e82dc(void);
void func_020e8368(void);
void func_020e8418(void);
void func_020e84b0(void);
void func_020e8790(void);
unsigned int func_020e8a74(unsigned int p0);
void func_020e8ac8(void);
void func_020e9658(void);
void func_020e9810(void);
void func_020e9d10(void);
void func_020ea1d4(Vec3 *param_1, const Vec3 *param_2, const Vec3 *param_3);
void func_020ea37c(void);
void func_020ea4bc(u32 param_1, void *param_2, void **param_3, void *param_4, void *param_5);
