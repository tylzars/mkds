#include "Main/Unknown/code_02042fd8.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02133000.h"

#pragma thumb on
u16 func_020431a4(void **a) {
    u32 *p;
    u16 v;

    *a = (u32 *) *a + 1;
    p = *a;
    v = *p;
    *a = p + 1;
    return v;
}

s32 func_02043170(void *a, ...) {
    data_02175620->mUnk_04 = func_020431a4(&a);
    if (data_02175620->mUnk_04 == 0) {
        data_02175620->mUnk_00 = 0;
    } else {
        data_02175620->mUnk_00 = a;
    }
    return 1;
}

s32 func_0204313c(void *a, ...) {
    data_02175620->mUnk_0c = func_020431a4(&a);
    if (data_02175620->mUnk_0c == 0) {
        data_02175620->mUnk_08 = 0;
    } else {
        data_02175620->mUnk_08 = a;
    }
    return 1;
}

s32 func_02043108(void *a, ...) {
    data_02175620->mUnk_014 = func_020431a4(&a);
    if (data_02175620->mUnk_014 == 0) {
        data_02175620->mUnk_010 = 0;
    } else {
        data_02175620->mUnk_010 = (s32) a;
    }
    return 1;
}

// non-matching: the original loads the entry index before the table pointer inside the first loop, and copies the zero
// start values with movs where adds is emitted here
s32 func_02043078(u16 a) {
    u16 n;
    s32 s;
    Unk02175620_4c *e;
    s32 t;
    u16 k;
    u16 m;
    s8 c;

    e = data_02175620->mUnk_4c + a;
    n = 0;
    s = n;
    t = s;
    for (k = 0; k < e->mUnk_02; k++) {
        t += data_02175620->mUnk_44[(u16) (e->mUnk_00 + k)].mUnk_18;
    }
    for (m = 0; m < 3; m++) {
        c = ((s8 *) e->mUnk_04)[m];
        if (c != -1 && c != 0) {
            s += func_02043078(c);
            n++;
        }
    }
    if (n != 0) {
        t += s / n;
    }
    return t;
}

void func_02043038(void) {
    u32 a;
    u32 b;

    a = 0;
    b = 0;
    if (data_02175620->mUnk_020 <= 1) {
        a = func_02043078(0);
        b = a / 15000;
    }
    data_02175620->mUnk_104 = a;
    data_02175620->mUnk_108 = b;
}

void func_02042fd8(void *a) {
    Unk02175620 *g;
    Unk02175620_94 *t;
    u16 n;
    s32 d;
    u32 z;
    u16 i;
    Unk02175620_08 *r;

    g = data_02175620;
    n = g->mUnk_0c;
    z = n << 3;
    d = g->mUnk_010;
    if (z != 0) {
        t = func_02036bec(a, z);
        data_02175620->mUnk_94 = t;
        for (i = 0; i < n; i++) {
            r = data_02175620->mUnk_08 + i;
            t->mUnk_00 = r;
            t->mUnk_04 = (void *) d;
            d += r->mUnk_02 * 0x14;
            t++;
        }
    } else {
        g->mUnk_94 = 0;
    }
    func_02043038();
}
#pragma thumb off
