#include "00/code_021a78a4.h"
#include "00/code_021a8000.h"
#include "00/code_021a6fb4.h"
#include "00/code_021a8db8.h"
#include "00/code_021a911c.h"
#include "00/code_021a7bfc.h"
#include "00/code_02186d7c.h"
#include "00/unk_021b5000.h"
#include "code_0200dc3c.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"

s32 func_ov000_021a78a4(void *param_1, u32 param_2, Unk021a6fa8 *param_3) {
    Unk021a71c0 *d = param_3->mUnk_64;
    u32 e = func_0200fca0();
    if (d->mUnk_10a >= d->mUnk_108 + param_2) {
        Unk021a78a4 *f = data_ov000_021b5f94->mUnk_18(param_2 + 0xc);
        if (f != 0) {
            d->mUnk_108 += param_2;
            f->mUnk_00 = 0;
            f->mUnk_04 = param_2;
            f->mUnk_06 = param_3->mUnk_18;
            f->mUnk_08 = param_3->mUnk_1c;
            func_0214d1fc(param_1, f->mUnk_0c, param_2);
            if (param_3->mUnk_74 == 0) {
                param_3->mUnk_74 = param_3->mUnk_0a;
            }
            param_3->mUnk_18 = param_3->mUnk_1a;
            param_3->mUnk_1c = param_3->mUnk_20;
            if (((const Unk021a71c0 *) d)->mUnk_100 != 0) {
                d->mUnk_100->mUnk_00 = f;
            }
            d->mUnk_100 = f;
            if (d->mUnk_104 == 0) {
                d->mUnk_104 = f;
            }
        } else {
            data_ov000_021b5ffc[0]++;
        }
    } else {
        data_ov000_021b5ffc[1]++;
    }
    func_0200df9c(&d->mUnk_10c);
    func_0200fcb4(e);
    return 1;
}

static inline s32 func_ov000_021a797c_inline(Unk021a6fa8 *a) {
    s32 b = 0;
    if (a != 0) {
        b = (a->mUnk_70 & 1) != 0;
    }
    return b;
}

// non-matching: the original loads the word at 0x104 once more ahead of the interrupt call (`ldr r0, [r4, r0]` before
// the first call), size 0xec against 0xf0
s32 func_ov000_021a797c(Unk021a6fa8 *a, void *b, s32 c, u16 *d, u32 *e, s32 f) {
    Unk021a71c0 *h = a->mUnk_64;
    u32 i;
    s32 g;
    Unk021a78a4 *j;
    i = func_0200fca0();
    j = h->mUnk_104;
    while (j == 0) {
        if (f == 0) {
            g = -6;
            break;
        }
        func_0200e01c(&h->mUnk_10c);
        if (func_ov000_021a8a80(a) != 0 || func_ov000_021a797c_inline(a) == 0) {
            g = -0x38;
            break;
        }
        j = h->mUnk_104;
    }
    if (j != 0) {
        if (c > j->mUnk_04) {
            c = j->mUnk_04;
        }
        func_0214d1fc(j->mUnk_0c, b, c);
        if (d != 0) {
            *d = j->mUnk_06;
        }
        if (e != 0) {
            *e = j->mUnk_08;
        }
        g = j->mUnk_04;
        if (h->mUnk_fe == 0) {
            h->mUnk_104 = j->mUnk_00;
            if (j->mUnk_00 == 0) {
                h->mUnk_100 = 0;
            }
            data_ov000_021b5f94->mUnk_1c(j);
            h->mUnk_108 -= g;
        }
    }
    func_0200fcb4(i);
    return g;
}

s32 func_ov000_021a7a6c(Unk021a6fa8 *a) {
    Unk021a71c0 *b = a->mUnk_64;
    u32 c = func_0200fca0();
    s32 d = b->mUnk_f8;
    if (d != 0) {
        b->mUnk_f8 = 0;
        func_ov000_021adf00(d);
    }
    func_0200fcb4(c);
    return d;
}

s32 func_ov000_021a7a9c(Unk021a7064 *a) {
    return func_ov000_021a7a6c(a->mUnk_04);
}

s32 func_ov000_021a7aa8(Unk021a6fa8 *a) {
    Unk021a71c0 *b = a->mUnk_64;
    Unk021a7064 *c;
    if (b->mUnk_f8 < b->mUnk_fc) {
        return 0;
    }
    c = func_ov000_021a7064(func_ov000_021a7a9c, a, 0);
    if (c == 0) {
        return -0x21;
    }
    return func_ov000_021a6fb4(a, c);
}

s32 func_ov000_021a7af0(Unk021a7064 *param_1) {
    Unk021a7af0 *a = (Unk021a7af0 *) param_1;
    Unk021a6fa8 *b = a->mUnk_04;
    Unk021a71c0 *c = b->mUnk_64;
    u8 *d = a->mUnk_10;
    u32 e = a->mUnk_14;
    u16 *f = a->mUnk_18;
    u32 *g = a->mUnk_1c;
    s32 h = c->mUnk_f8;
    const u8 *i;
    s32 j;
    s32 k;
    for (;;) {
        i = func_ov000_021adf78((u32 *) &j);
        if (i == 0) {
            break;
        }
        if (j - h > 0) {
            break;
        }
        k = 1;
        if (b->mUnk_73 != 0 && b->mUnk_73 != 4) {
            k = 0;
        }
        if (k != 0 && b->mUnk_08 != 4) {
            i = 0;
            break;
        }
        func_0200dc3c(10);
    }
    if (b->mUnk_73 == 4) {
        if (i == 0) {
            return 0;
        }
        if (e > j) {
            e = j;
        }
        func_0214d1fc(i, d, e);
        func_ov000_021adf00(e);
        return e;
    }
    if (i != 0) {
        h = func_ov000_021a7c4c(b, d, e, f, g);
    } else {
        h = 0;
    }
    if (h <= 0) {
        return h;
    }
    if (c->mUnk_f8 >= c->mUnk_fc) {
        func_ov000_021a7a6c(b);
    }
    return h;
}
