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

extern Unk0217baec data_0217baf0[];

extern Unk0217baec data_0217baec[];

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
