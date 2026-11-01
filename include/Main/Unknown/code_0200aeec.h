#pragma once

#include "types.h"
#include "code_0200dc3c.h"
#include "Main/Unknown/code_0200b018.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200fd1c.h"

// 0x10-byte object func_0200aeec links by the bits above bit 0 of its member 4, in increasing order.
typedef struct Unk0200aeec {
    /* 00 */ struct Unk0200aeec *mUnk_00;
    /* 04 */ union {
        u32 mUnk_04;
        struct {
            u32 mUnk_04_0 : 1;
            u32 mUnk_04_1 : 31;
        };
    };
    /* 08 */ void *mUnk_08;
    /* 0c */ void *mUnk_0c;
} Unk0200aeec;

// What data_0216fde0 points to: the Unk0200db5c, then the first and the last object of the list.
typedef struct Unk0200aeec_head {
    /* 00 */ Unk0200db5c mUnk_00;
    /* b8 */ u8 mUnk_b8[8];
    /* c0 */ Unk0200aeec *volatile mUnk_c0;
    /* c4 */ Unk0200aeec mUnk_c4;
} Unk0200aeec_head;

void func_0200aeec(Unk0200aeec *a, void *b, void *c, u32 d);
u32 func_0200aff8(Unk0200aeec *a);
