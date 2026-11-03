#include "code_0200ef10.h"

#include "Main/Unknown/unk_02170000.h"
#include "code_0200c914.h"
#include "code_0200e77c.h"
#include "Main/Unknown/unk_00000000.h"
#include "Main/Unknown/unk_00002000.h"
#include "Main/Unknown/unk_02400000.h"
#include "code_0200f328.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"

u32 data_021701b8;

// On the first call fills the tables of func_0200ef24 and func_0200ef38 for indices 0 and 3 to 6 from
// func_0200ef4c and func_0200f038, and clears index 2.
void func_0200f210(void) {
    if (data_021701b4 != 0) {
        return;
    }
    data_021701b4 = 1;
    func_0200ef38(0, func_0200f038(0));
    func_0200ef24(0, func_0200ef4c(0));
    func_0200ef24(2, 0);
    func_0200ef38(2, 0);
    func_0200ef38(3, func_0200f038(3));
    func_0200ef24(3, func_0200ef4c(3));
    func_0200ef38(4, func_0200f038(4));
    func_0200ef24(4, func_0200ef4c(4));
    func_0200ef38(5, func_0200f038(5));
    func_0200ef24(5, func_0200ef4c(5));
    func_0200ef38(6, func_0200f038(6));
    func_0200ef24(6, func_0200ef4c(6));
}

// Fills index 2 of both tables, then unless data_021701b8 is nonzero and the low two bits of func_0200e884() are
// not 1, passes one constant each to func_0200f35c and func_0200f364.
void func_0200f190(void) {
    func_0200ef38(2, func_0200f038(2));
    func_0200ef24(2, func_0200ef4c(2));
    if (data_021701b8 != 0 && (func_0200e884() & 3) != 1) {
        return;
    }
    func_0200f35c(0x200002b);
    func_0200f364(0x23e0021);
}

u32 func_0200f17c(int arg0) {
    u32 value0 = (u32) arg0;
    value0 = (value0 << 2);
    value0 = (value0) + (0x2700000u);
    value0 = (value0) + (0xff000u);
    value0 = (u32) * (const u32 *) ((value0) + (3524));
    return value0;
}

u32 func_0200f168(int arg0) {
    u32 value0 = (u32) arg0;
    value0 = (value0 << 2);
    value0 = (value0) + (0x2700000u);
    value0 = (value0) + (0xff000u);
    value0 = (u32) * (const u32 *) ((value0) + (3488));
    return value0;
}

u32 func_0200f038(u32 i) {
    u32 a;
    s32 n;
    u32 c;

    switch (i) {
        case 0:
            return 0x23e0000;
        case 2:
            if (data_021701b8 == 0 || (func_0200e884() & 3) == 1) {
                return 0;
            }
            return 0x2700000;
        case 3:
            return 0x2000000;
        case 4:
            a = (u32) &data_027e0000;
            c = a + 0x3f80 - (u32) data_00000c00;
            n = (s32) data_00002800;
            if (n == 0) {
                return a < 0x27e00e0 ? 0x27e00e0 : a;
            }
            if (n < 0) {
                return 0x27e00e0 - n;
            }
            return c - n;
        case 5:
            return 0x27ff680;
        case 6:
            return 0x37f8000;
    }
    return 0;
}

u32 func_0200ef4c(u32 i) {
    switch (i) {
        case 0:
            return 0x21da300;
        case 2:
            if (data_021701b8 == 0 || (func_0200e884() & 3) == 1) {
                return 0;
            }
            return (u32) data_02400000;
        case 3:
            return 0x1ffffa0;
        case 4:
            return 0x27e00e0;
        case 5:
            return 0x27ff000;
        case 6:
            return 0x37f8000;
    }
    return 0;
}

void func_0200ef38(u32 i, u32 v) {
    ((vu32 *) 0x027ffdc4)[i] = v;
}

void func_0200ef24(u32 i, u32 v) {
    ((vu32 *) 0x027ffda0)[i] = v;
}

u32 func_0200ef10(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_021701b8;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}
