#include "Main/Unknown/code_0210fb88.h"
#include "Main/Unknown/code_02110100.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_02108eb4.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_0212c668.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_021100dc.h"
#include "Main/Unknown/code_0207a000.h"
#include "code_0212c478.h"
#include "code_0212c6ac.h"
#include "code_0212df7c.h"

void func_021100d0(Unk0212c400 **a, u32 b) {
    func_0212c6f0(a, b);
}

void func_0211003c(u32 a, Unk0212c400 **b) {
    if ((data_0217c780 & 1) == 0) {
        return;
    }
    if (data_0217d084.mUnk_0c == 0) {
        return;
    }
    if (*b != 0) {
        func_0212c6f0(b, 0);
    }
    if (*b != 0) {
        func_0212c6f0(b, 0);
    }
    func_0212ecc0(b, 0, a);
}

// Fades the object at data_0217d234 towards t, then writes the value that was reached.
static inline void func_0210fb88_inline(Unk0212c400 **p, s32 v, s32 k, s32 t) {
    s32 m;
    s32 c;
    s32 r;
    s32 x;
    func_02108eb4(1, v);
    func_0212c524(p, 0xffff, k);
    c = data_0217d234.mUnk_04 >> 12;
    if (t == c) {
        r = -1;
    } else {
        if (c <= t) {
            x = data_0217d234.mUnk_04 + data_0217d234.mUnk_00;
            if ((x >> 12) > t) {
                x = t << 12;
            }
        } else {
            x = data_0217d234.mUnk_04 - data_0217d234.mUnk_00;
            if ((x >> 12) < t) {
                x = t << 12;
            }
        }
        c = x >> 12;
        r = c;
        data_0217d234.mUnk_04 = x;
    }
    data_0217d218 = c;
    m = data_0216cb28;
    if (c <= m) {
        if (c < 0) {
            c = 0;
        }
        m = c;
    }
    data_0217d218 = m;
    if (r != -1) {
        func_0212c678(p, r);
    }
}

void func_0210fb88(Unk0217d244 *a, Unk0212c400 **b) {
    u32 i;
    s32 j;
    s32 k;
    s32 l;
    s32 n;
    s32 x;
    s32 y;
    s64 w;
    s32 z;
    Unk0212c400 **p;
    k = 0;
    i = k;
    l = 0x7f;
    n = -1;
    if (a->mUnk_00 > 0) {
        switch (a->mUnk_00) {
            case 1:
                l = k;
                break;
            case 2:
                break;
        }
        func_0210fb88_inline(b, 0x7f, 0, l);
        return;
    }
    if (data_0217d1ec != 0) {
        func_02110114(b);
        return;
    }
    a->mUnk_0c = (func_0207a2a8(&x) != 0 && x < 0x8d04) ? 1 : 0;
    if ((a->mUnk_08 >> 2) & 1) {
        j = 0;
        l = 0x1e;
        n = 0xff;
        i = 0x7f;
    } else if (a->mUnk_0c != 0) {
        y = (x - 2500) << 12;
        w = y;
        z = (s32) (((s64) data_0217d208 * y + 0x800) >> 12) >> 12;
        z += 0x1e;
        if (z < 0) {
            z = 0;
        } else if (z > 0x7f) {
            z = 0x7f;
        }
        l = z & 0xff;
        z = (s32) ((data_0217d200 * w + 0x800) >> 12) >> 12;
        i = (0x9d - l) & 0xff;
        j = z + 0x14;
        n = 0xfe;
        if (j < 0) {
            j = 0;
        } else if (j > 0x7f) {
            j = 0x7f;
        }
    } else {
        j = data_0216cb28;
    }
    if (data_0217c814.mUnk_0c != 1) {
        k = 0;
    } else if ((a->mUnk_08 >> 1) & 1) {
        a->mUnk_04 += 0x1111;
        a->mUnk_04 &= 0xffff;
        k = (s32) (((s64) data_0215d4b4[(a->mUnk_04 >> 4) * 2] * 0x30000 + 0x800) >> 12) >> 12;
        k += 0x80;
        if (j > 0x3c) {
            j = 0x3c;
        }
    } else if ((a->mUnk_08 >> 3) & 1) {
        k = 0x40;
        if (j == data_0216cb28) {
            j = data_0216cb28 - 10;
        }
    }
    func_0210fb88_inline(b, l, k, j);
    p = func_02108e6c(5);
    if (n != -1 && i != 0) {
        l = func_02110100(p);
        if (l != 0 && func_021100dc(p, 0, n) == 0) {
            func_021100d0(p, 0);
            func_0211003c(n & 0xff, p);
        } else if (l == 0) {
            func_0211003c(n & 0xff, p);
        }
        if (func_02110100(p) == 0) {
            return;
        }
        if (i > 0x7f) {
            i = 0x7f;
        }
        func_02105b28(p, i);
    } else {
        if (func_02110100(p) == 0) {
            return;
        }
        func_021100d0(p, 0x1e);
    }
}
