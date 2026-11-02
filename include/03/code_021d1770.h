#pragma once

#include "types.h"

// 8-byte object at index i of Unk021d1770.mUnk_08: func_ov003_021d1770 reads bits 16-24 and bits 0-7 of its word
// at 0x00.
typedef struct Unk021d1770_08 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk021d1770_08;

// Object passed to func_ov003_021d1770: a pointer at 0x08 to Unk021d1770_08 objects, indexed by its second
// argument, and their number at 0x0c. The two pointers at 0x00 and 0x04 link the objects of a list.
typedef struct Unk021d1770 {
    /* 00 */ struct Unk021d1770 *mUnk_00;
    /* 04 */ struct Unk021d1770 *mUnk_04;
    /* 08 */ Unk021d1770_08 *mUnk_08;
    /* 0c */ u8 mUnk_0c;
} Unk021d1770;

void func_ov003_021d1770(Unk021d1770 *a, int b, u32 *c, s32 *d);
