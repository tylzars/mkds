#include "Main/Unknown/code_020588d8.h"
#include "Main/Unknown/code_02050320.h"
#include "Main/Unknown/code_020474e4.h"
#include "Main/Unknown/code_0204bcdc.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_02059be4.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

static inline void func_02058910_inline(u16 v) {
    Unk0217aa00_1608 *p = &data_0217aa00->mUnk_1608;
    p->mUnk_10 = v;
    p->mUnk_12 = 1;
}

void func_0205896c(void) {
    s32 r;
    s32 a;
    s32 b;
    s32 v;
    Unk0217aa00 *p;

    r = 1;
    b = 0;
    p = data_0217aa00;
    if (p->mUnk_0454 & 0x40) {
        a = 1;
        if (p == 0) {
            v = 0;
        } else {
            v = p->mUnk_0000;
        }
        if (v != 1 && ((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
            a = 0;
        }
        if (a != 0) {
            b = 1;
        }
    }
    if (b != 0) {
        if (func_0204bcdc() == 2) {
            func_0204f8a0(data_0217aa00->mUnk_0457);
        } else {
            r = 0;
        }
    }
    if (r != 0) {
        func_02058910_inline(2);
    }
}

void func_02058950(void) {
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        func_02059ea4(2);
    }
}

void func_02058910(void) {
    if (func_02059ce8() != 0) {
        if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
            func_0205a108();
            func_020474e4();
        }
        func_02058910_inline(3);
    }
}

void func_020588d8(void) {
    data_0217aa00->mUnk_1e34 = 0;
    data_0217aa00->mUnk_1e44 &= ~2;
    data_0217aa00->mUnk_164f = 0;
}

#pragma thumb off
