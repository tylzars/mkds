#include "Main/Unknown/code_02042410.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02042fd8.h"
#include "Main/Unknown/code_02043000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/unk_021759c0.h"

#pragma thumb on
s32 func_02042990(void *a, ...) {
    data_02175620->mUnk_020 = func_020431a4(&a);
    data_02175620->mUnk_01c = (s32) a;
    return 1;
}

// non-matching: registers: the original keeps the count in r5 and the heap in r4 (swapped here), and holds the table
// pointer in r1 inside the second loop
s32 func_02042894(void *a, ...) {
    void *h;
    s32 i;
    s32 m;
    s32 n;
    s32 k;
    u16 t;
    Unk02175620_24 *p;

    h = func_020364e0(func_020364e8());
    data_02175620->mUnk_028 = func_020431a4(&a);
    data_02175620->mUnk_024 = a;
    if (data_021759c0->mUnk_08 == 2) {
        n = data_02175620->mUnk_028;
        data_02175620->mUnk_f8 = func_02036bec(h, n * 2);
        data_02175620->mUnk_100 = 0;
        for (i = 0; i < n; i++) {
            data_02175620->mUnk_f8[i] = i;
        }
    } else if (data_02175620->mUnk_028 != 0) {
        m = 0;
        p = data_02175620->mUnk_024;
        for (i = 0; i < data_02175620->mUnk_028; i++) {
            if (p->mUnk_1c > m) {
                m = p->mUnk_1c;
            }
            p++;
        }
        data_02175620->mUnk_f8 = func_02036bec(h, (m + 1) * 2);
        for (k = 0; k < m + 1; k++) {
            data_02175620->mUnk_f8[k] = 0xffff;
        }
        for (i = 0; i < data_02175620->mUnk_028; i++) {
            data_02175620->mUnk_f8[data_02175620->mUnk_024[i].mUnk_1c] = i;
        }
    }
    return 1;
}

static inline u16 func_020427d4_inline(Unk020f41c4_B *p, u16 n) {
    u32 t;
    if (n == 0) {
        t = 0;
    } else {
        p->mUnk_00 = (s64) p->mUnk_08 * (s64) p->mUnk_00 + p->mUnk_10;
        if (n == 0) {
            t = p->mUnk_00 >> 32;
        } else {
            t = ((s64) (p->mUnk_00 >> 32) * (u32) n) >> 32;
        }
    }
    return t;
}

void func_020427d4(Unk020f41c4_B *a) {
    s32 i;
    u16 n;
    u16 x;
    u16 y;
    u16 t;

    n = data_02175620->mUnk_028;
    for (i = 0; i < 100; i++) {
        x = func_020427d4_inline(a, n);
        y = func_020427d4_inline(a, n);
        t = data_02175620->mUnk_f8[y];
        data_02175620->mUnk_f8[y] = data_02175620->mUnk_f8[x];
        data_02175620->mUnk_f8[x] = t;
    }
}

s32 func_020427ac(void *a, ...) {
    data_02175620->mUnk_30 = func_020431a4(&a);
    data_02175620->mUnk_2c = a;
    return 1;
}

void func_0204274c(void) {
    u16 n;
    u16 i;

    n = data_02175620->mUnk_38;
    if (n == 0) {
        data_02175620->mUnk_fc = 0;
        return;
    }
    data_02175620->mUnk_fc = func_02036bec(func_020364e0(func_020364e8()), n * 2);
    for (i = 0; i < n; i++) {
        data_02175620->mUnk_fc[data_02175620->mUnk_34[i].mUnk_1a] = i;
    }
}

s32 func_02042708(void *a, ...) {
    s32 r = 0;

    if (data_02175620->mUnk_10c < 0x1f) {
        data_02175620->mUnk_38 = 0;
        data_02175620->mUnk_34 = 0;
    } else {
        data_02175620->mUnk_38 = func_020431a4(&a);
        data_02175620->mUnk_34 = a;
        r = 1;
    }
    func_0204274c();
    return r;
}

// non-matching: the original loads zero into r0 before the loads and uses it for the stores and the return value; here
// the zero is loaded after the comparison
s32 func_020426ac(void *a, ...) {
    s32 r = 0;

    if (data_02175620->mUnk_10c < 0x24) {
        data_02175620->mUnk_40 = r;
        data_02175620->mUnk_3c = 0;
        return r;
    }
    data_02175620->mUnk_40 = func_020431a4(&a);
    if (data_02175620->mUnk_40 != 0) {
        data_02175620->mUnk_3c = a;
    } else {
        data_02175620->mUnk_3c = 0;
    }
    return 1;
}

s32 func_02042628(void *a, ...) {
    u16 i;
    u16 j;

    data_02175620->mUnk_48 = func_020431a4(&a);
    if (data_02175620->mUnk_48 == 0) {
        data_02175620->mUnk_44 = 0;
        return 1;
    }
    data_02175620->mUnk_44 = a;
    j = 0;
    for (i = 0; i < data_02175620->mUnk_48; i++) {
        if (data_02175620->mUnk_44[i].mUnk_20 != -1) {
            j++;
        }
    }
    data_02175620->mUnk_98 = j;
    return 1;
}

s32 func_02042590(void *a, ...) {
    s32 i;
    Unk02175620_4c *t;
    Unk02175620_4c *e;
    s32 m;

    data_02175620->mUnk_50 = func_020431a4(&a);
    if (data_02175620->mUnk_50 == 0) {
        data_02175620->mUnk_4c = 0;
        data_02175620->mUnk_9a = 0;
        return 1;
    }
    data_02175620->mUnk_4c = a;
    for (i = 0; i < data_02175620->mUnk_50; i++) {
        if (data_02175620->mUnk_4c[(u16) i].mUnk_00 == 0) {
            t = data_02175620->mUnk_4c;
            e = &t[(u16) (s8) t[(u16) i].mUnk_07];
            m = t[(u16) (s8) t[(u16) i].mUnk_07].mUnk_00;
            data_02175620->mUnk_9a = m + e->mUnk_02 - 1;
            break;
        }
    }
    return 1;
}

s32 func_02042558(void *a, ...) {
    data_02175620->mUnk_58 = func_020431a4(&a);
    if (data_02175620->mUnk_58 == 0) {
        data_02175620->mUnk_54 = 0;
    } else {
        data_02175620->mUnk_54 = a;
    }
    return 1;
}

s32 func_02042520(void *a, ...) {
    data_02175620->mUnk_60 = func_020431a4(&a);
    if (data_02175620->mUnk_60 == 0) {
        data_02175620->mUnk_5c = 0;
    } else {
        data_02175620->mUnk_5c = a;
    }
    return 1;
}

s32 func_02042498(void *a, ...) {
    if (data_02175620->mUnk_020 > 1) {
        data_02175620->mUnk_88 = func_020431a4(&a);
        if (data_02175620->mUnk_88 == 0) {
            data_02175620->mUnk_84 = 0;
        } else {
            data_02175620->mUnk_84 = a;
            data_02175620->mUnk_64 = 0;
            data_02175620->mUnk_68 = 0;
        }
    } else {
        data_02175620->mUnk_68 = func_020431a4(&a);
        if (data_02175620->mUnk_68 == 0) {
            data_02175620->mUnk_64 = 0;
        } else {
            data_02175620->mUnk_64 = a;
            data_02175620->mUnk_84 = 0;
            data_02175620->mUnk_88 = 0;
        }
    }
    return 1;
}

s32 func_02042410(void *a, ...) {
    if (data_02175620->mUnk_020 > 1) {
        data_02175620->mUnk_90 = func_020431a4(&a);
        if (data_02175620->mUnk_90 == 0) {
            data_02175620->mUnk_8c = 0;
        } else {
            data_02175620->mUnk_8c = a;
            data_02175620->mUnk_6c = 0;
            data_02175620->mUnk_70 = 0;
        }
    } else {
        data_02175620->mUnk_70 = func_020431a4(&a);
        if (data_02175620->mUnk_70 == 0) {
            data_02175620->mUnk_6c = 0;
        } else {
            data_02175620->mUnk_6c = a;
            data_02175620->mUnk_8c = 0;
            data_02175620->mUnk_90 = 0;
        }
    }
    return 1;
}
#pragma thumb off
