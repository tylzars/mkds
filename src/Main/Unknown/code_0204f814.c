#include "Main/Unknown/code_0204f814.h"
#include "code_0200f59c.h"
#include "Main/Unknown/code_02007624.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_0204bca0.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02154000.h"

#pragma opt_rebuildconditionals off

static inline u32 func_0204f814_inline(void) {
    if (data_0217aa00 == 0) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

void func_0204f814(void) {
    s32 i;
    s32 m;
    s8 b;
    s32 v;

    b = -1;
    m = 0x7fff;
    for (i = 1; i < 14; i++) {
        v = data_0217aa00->mUnk_008c[i];
        if (v != -1 && v < m) {
            m = v;
            b = i;
        }
    }
    if (b != -1) {
        data_0217aa00->mUnk_0088 = b;
        return;
    }
    data_0217aa00->mUnk_0088 = -1;
    data_0217aa00->mUnk_0008 = 3;
    data_0217aa00->mUnk_0010 = 0;
}

void func_0204f8a0(u8 a) {
    s32 r;
    s32 b;

    r = 0;
    if ((data_0217aa00->mUnk_0454 & 0x40) != 0) {
        b = 1;
        if (func_0204f814_inline() != 1) {
            if (*(u16 *) 0x027ffc40 != 2) {
                b = 0;
            }
        }
        if (b != 0) {
            r = 1;
        }
    }
    if (r == 0) {
        return;
    }
    if (func_0204f814_inline() != 1) {
        return;
    }
    func_0204bcb4(a);
}

void func_0204f938(Unk0217aa08_14 *a) {
    Unk02143c30 *q;
    Unk0217aa00_24_50 *e;
    Unk0203bfc4 t;
    u32 h;
    u16 m;
    u64 x;
    u64 y;

    q = data_0217aa00->mUnk_0018;
    func_0214d02c(data_02154788, q, 0x40);
    e = data_0217aa00->mUnk_0044.mUnk_38;
    e->mUnk_0e.mUnk_07_0 = 1;
    func_0214d1fc(a->mUnk_0c, e, 0x14);
    e->mUnk_0e.mUnk_07_1 = (u8) a->mUnk_04_4;
    e->mUnk_18_0 = a->mUnk_04_0;
    e->mUnk_18_4 = (u8) func_0204684c(a->mUnk_04_10);
    e->mUnk_18_9 = a->mUnk_08_8;
    e->mUnk_18_16 = a->mUnk_08_15;
    e->mUnk_18_22 = a->mUnk_08_22;
    func_0203bfc4(&t);
    h = t.mUnk_00;
    if (h >= 0x12) {
        h -= 0x12;
    }
    m = (h * 0x3c + t.mUnk_04) * 0x3c + t.mUnk_08;
    x = func_0200f59c() | m << 16;
    x = x * 0x5d588b656c078965ull + 0x269ec3;
    y = x >> 32;
    q->mUnk_0c = (u16) (y * 0x10000 >> 32) | 0x8000;
    q->mUnk_32 = data_0217aa00->mUnk_0088;
    q->mUnk_18 = func_02143134();
    q->mUnk_00 = data_0217aa00->mUnk_0044.mUnk_38;
    q->mUnk_04 = 0x1c;
    q->mUnk_10 = 1;
    q->mUnk_34 = 0x1b6;
    q->mUnk_36 = 0x2e;
}

void func_0204fb40(s32 a) {
    Unk02143c30 *q;
    Unk0217aa00_24_50 *e;
    Unk0203bfc4 t;
    u32 h;
    u16 m;
    u64 x;
    u64 y;

    q = data_0217aa00->mUnk_0018;
    func_0214d02c(data_02154788, q, 0x40);
    e = data_0217aa00->mUnk_0044.mUnk_38;
    e->mUnk_0e.mUnk_07_0 = 0;
    e->mUnk_0e.mUnk_07_1 = 0;
    e->mUnk_18_0 = 0;
    e->mUnk_18_4 = 0;
    e->mUnk_18_9 = 0;
    e->mUnk_18_16 = 0;
    e->mUnk_18_22 = 0;
    e->mUnk_0e.mUnk_06_0 = 0;
    if ((data_0217aa00->mUnk_0454 & 0x40) != 0) {
        q->mUnk_0c = (data_0217aa00->mUnk_1690 + 7) & 0x7fff;
    } else {
        func_0203bfc4(&t);
        h = t.mUnk_00;
        if (h >= 0x12) {
            h -= 0x12;
        }
        m = (h * 0x3c + t.mUnk_04) * 0x3c + t.mUnk_08;
        x = func_0200f59c() | m << 16;
        x = x * 0x5d588b656c078965ull + 0x269ec3;
        y = x >> 32;
        q->mUnk_0c = (u16) (y * 0x10000 >> 32) | 0x8000;
    }
    q->mUnk_32 = data_0217aa00->mUnk_0088;
    q->mUnk_18 = func_02143134();
    q->mUnk_00 = data_0217aa00->mUnk_0044.mUnk_38;
    q->mUnk_04 = 0x1c;
    q->mUnk_10 = 7;
    q->mUnk_0e = a != 0 ? 1 : 0;
}

s32 func_0204fcec(u16 a, void *b) {
    s32 r;
    void *p;

    r = 0;
    switch (func_0204f814_inline()) {
        case 1:
            r = 0;
            if ((data_0217aa00->mUnk_0454 & 0x40) != 0) {
                p = func_02007e38(a);
                if ((data_0217aa00->mUnk_1696 & (1 << a)) != 0 && p != 0) {
                    if (b != 0) {
                        func_0214d1fc((u8 *) p + 2, b, 0x14);
                    }
                    r = 1;
                }
            } else if ((data_0217aa00->mUnk_0044.mUnk_43 & (1 << a)) != 0) {
                if (b != 0) {
                    func_0214d1fc(&data_0217aa00->mUnk_045c[a], b, 0x14);
                }
                r = 1;
            }
            break;
        case 2:
            r = 0;
            if ((data_0217aa00->mUnk_043d & (1 << a)) != 0) {
                if (b != 0) {
                    func_0214d1fc(&data_0217aa00->mUnk_045c[a], b, 0x14);
                }
                r = 1;
            }
            break;
    }
    return r;
}

s32 func_0204fe1c(u16 a) {
    s32 r;
    s32 b;

    r = 0;
    b = 0;
    if (func_0204f814_inline() != 2) {
        b = 0;
    } else if (*(u16 *) 0x027ffc40 == 2) {
        b = 0;
    } else if (data_0217aa00->mUnk_00ac[a].mUnk_dc_0 != 0) {
        b = 1;
    }
    if (b != 0) {
        r = data_0217aa00->mUnk_00ac[a].mUnk_da;
    }
    return r;
}

s32 func_0204fe90(u16 a) {
    s32 r;
    s32 b;

    r = 0;
    b = 0;
    if (func_0204f814_inline() != 2) {
        b = 0;
    } else if (*(u16 *) 0x027ffc40 == 2) {
        b = 0;
    } else if (data_0217aa00->mUnk_00ac[a].mUnk_dc_0 != 0) {
        b = 1;
    }
    if (b != 0) {
        if (data_0217aa00->mUnk_00ac[a].mUnk_dc_5 != 0) {
            r = 1;
        }
    }
    return r;
}

static inline u32 func_0204ff14_inline(Unk0217aa00 *p) {
    if (p == 0) {
        return 0;
    }
    return p->mUnk_0000;
}

s32 func_0204ff14(u16 a, void *b) {
    Unk0217aa00 *t;
    s32 r;

    t = data_0217aa00;
    r = 0;
    if (func_0204ff14_inline(t) != 2) {
        return 0;
    }
    if (*(u16 *) 0x027ffc40 == 2) {
        return 0;
    }
    if (t->mUnk_00ac[a].mUnk_dc_0 != 0) {
        if (b != 0) {
            func_0214d1fc(t->mUnk_00ac[a].mUnk_c6, b, 0x14);
        }
        r = 1;
    }
    return r;
}

s32 func_0204ffbc(void) {
    s32 r;

    r = 0;
    switch (data_0217aa00->mUnk_0004) {
        case 8:
        case 9:
            r = 1;
            break;
    }
    return r;
}

u16 func_0204ffe8(u32 a) {
    s32 f;
    u32 r;

    f = 0;
    switch (data_0217aa00->mUnk_0004) {
        case 8:
        case 9:
            f = 1;
            break;
    }
    if (f != 0) {
        r = data_0217aa00->mUnk_15c8[a].mUnk_00_0;
    } else {
        r = 0;
    }
    return r;
}
