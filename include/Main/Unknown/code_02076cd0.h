#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217a000.h" // Unk02061808, Unk0217ad08
#include "Main/Unknown/code_020748b8.h" // Unk020748b8_218
#include "Main/Unknown/code_0207b960.h" // Unk0207b960
#include "Main/Unknown/code_02077f00.h" // data_usa_0217ace4
#include "Main/Unknown/code_020790e0.h"

// 0x88-byte object built from an entry of the table at Unk02175620::mUnk_7c: the entry, two Unk0207b960 and two
// halfwords.
typedef struct Unk02077750 {
    /* 00 */ Unk020748b8_218 *mUnk_00;
    /* 04 */ Unk0207b960 mUnk_04;
    /* 40 */ Unk0207b960 mUnk_40;
    /* 7c */ s16 mUnk_7c;
    /* 7e */ s16 mUnk_7e;
    /* 80 */ s32 mUnk_80;
    /* 84 */ s32 mUnk_84;
} Unk02077750;

// Declared here until the code that defines them is decompiled.
extern const char data_usa_02165714[];
void func_02077d68(void);

void func_02076cd0(Unk02061808 *p);
void func_02076ed4(Unk02061808 *p);
void func_02077060(Unk02061808 *p);
void func_0207729c(Unk02061808 *p);
void func_020775e4(void);
void func_0207767c(void);
void func_02077750(Unk02077750 *a, Unk020748b8_218 *b);
void func_020777ac(u32 a);
void func_02077944(void);
void func_02077998(void);
void func_02077a28(void *a);
u16 func_02077a4c(void);
u16 func_02077a5c(void);
u32 func_02077a70(s32 *a, u32 b);
void func_02077b1c(void);
void func_02077b3c(void);
