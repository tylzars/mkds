#include "Main/Unknown/code_0205e2cc.h"
#include "Main/Unknown/code_0202d000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02042064.h"
#include "Main/Unknown/code_020431cc.h"
#include "Main/Unknown/code_02057304.h"
#include "Main/Unknown/code_020574c8.h"
#include "Main/Unknown/code_02057000.h"
#include "Main/Unknown/code_02057ca4.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_020576b8.h"
#include "Main/Unknown/code_02060c68.h"
#include "Main/Unknown/code_0212030c.h"
#include "Main/Unknown/code_0214d000.h"
#include "00/code_0219bb50.h"
#include "code_021458c4.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_02182fdc.h"

#pragma opt_rebuildconditionals off

Unk0205ec14 *func_0205eda0(void *a) {
    Unk0205ec14 *p = func_02036bec(a, 0xb04);
    if (p != 0) {
        p->mUnk_00 = -1;
    }
    return p;
}

s32 func_0205eca4(Unk0205ec14 *a, u8 b, void *c) {
    Unk0217aa08_20_04 e;
    u8 d;
    u8 m;
    d = b / 5;
    m = b % 5;
    if (d != a->mUnk_00) {
        return 0;
    }
    func_0214d1fc(&data_0217aa08->mUnk_20->mUnk_04[b], &e, 0x24);
    if (e.mUnk_22_0 == 0 || e.mUnk_22_2 == 0) {
        return 0;
    }
    ((u8 *) c)[0x200] = (a->mUnk_04.mUnk_004 & (1 << m)) != 0;
    if (((u8 *) c)[0x200] != 0) {
        func_0214d1fc(a->mUnk_04.mUnk_008[m], c, 0x200);
    }
    return 1;
}

void func_0205ec14(Unk0205ec14 *a, u8 b) {
    u8 c = b / 5;
    if (func_0205743c(c, &data_0217aa08->mUnk_00->mUnk_2c[2], 2) == 0) {
        a->mUnk_00 = -1;
        return;
    }
    if (c == a->mUnk_00) {
        return;
    }
    func_020576b8(&a->mUnk_04, c);
    a->mUnk_00 = c;
}

// non-matching: 6 instructions differ: in the second loop the constant 1 and the pointer to the byte at 4 of the object
// are in each other's registers (r6 and r5 in the original).
void func_0205e900(void) {
    u8 i;
    u16 j;
    Unk0217aa00_45c *e;
    u8 c[12];
    s8 d[8];
    Unk0217aa08_24 *r;
    s32 v1;
    s32 v2;
    u16 k;
    u8 *q;
    s32 m;
    s32 f = 0;
    s32 t;
    u8 x;
    for (i = 0; i < 12; i++) {
        c[i] = 0;
    }
    for (j = 0; j < 8; j++) {
        d[j] = -1;
        if (data_0217aa00->mUnk_0000 == 2) {
            m = data_0217aa00->mUnk_0432;
        } else {
            m = 0;
        }
        if (j != (u16) m) {
            if ((data_0217aa00->mUnk_0457 & (1 << data_0217aa00->mUnk_1e8c[j])) == 0) {
                if ((data_0217aa00->mUnk_15f6 & (1 << j)) != 0) {
                    e = &data_0217aa00->mUnk_045c[j];
                    t = func_02060c68(e, 1);
                    if (t != -1) {
                        if (e->mUnk_214 != 0) {
                            d[j] = t;
                            c[t / 5] = 1;
                        }
                    }
                }
            }
        }
    }
    func_020577b4(data_0217aa08->mUnk_20);
    if (data_021759d4->mUnk_0c != 0) {
        func_02145d38();
    }
    for (i = 0; i < 12; i++) {
        if (c[i] != 0) {
            r = data_0217aa08->mUnk_24;
            if (func_0205743c(i, &data_0217aa08->mUnk_00->mUnk_2c[2], 2) != 0) {
                func_020576b8(r, i);
                if (data_021759d4->mUnk_0c != 0) {
                    func_02145d38();
                }
            } else {
                func_0214d168(r, 0, 0xb00);
                func_0205746c(i, &data_0217aa08->mUnk_00->mUnk_2c[2], 2);
                f = 1;
            }
            q = (u8 *) r + 4;
            v1 = i * 5;
            v2 = (i + 1) * 5;
            for (k = 0; k < 8; k++) {
                t = d[k];
                if (t >= v1 && t < v2) {
                    x = t % 5;
                    *q = *q | (1 << x);
                    func_0214d1fc((u8 *) &data_0217aa00->mUnk_045c[k] + 0x14, r->mUnk_008[x], 0x200);
                }
            }
            func_02057710(r, i);
            if (data_021759d4->mUnk_0c != 0) {
                func_02145d38();
            }
        }
    }
    if (f != 0) {
        func_02057ca4(data_0217aa08->mUnk_00);
        if (data_021759d4->mUnk_0c != 0) {
            func_02145d38();
        }
    }
    func_02057504();
}

void func_0205e67c(void) {
    u8 i;
    u16 j;
    Unk0217aa00_45c *e;
    u8 c[12];
    s8 d[4];
    Unk0217aa08_24 *r;
    s32 v1;
    s32 v2;
    u8 x;
    u16 k;
    u8 *q;
    s32 t;
    for (i = 0; i < 12; i++) {
        c[i] = 0;
    }
    for (j = 0; j < 4; j++) {
        d[j] = -1;
        if (j != func_ov000_0219bb50()) {
            e = func_0212030c(j & 0xff);
            if (e != 0) {
                t = func_02060c68(e, 0);
                if (t != -1) {
                    if (e->mUnk_214 != 0) {
                        d[j] = t;
                        c[t / 5] = 1;
                    }
                }
            }
        }
    }
    func_020577b4(data_0217aa08->mUnk_20);
    if (data_021759d4->mUnk_0c != 0) {
        func_02145d38();
    }
    for (i = 0; i < 12; i++) {
        if (c[i] != 0) {
            r = data_0217aa08->mUnk_24;
            if (func_0205743c(i, &data_0217aa08->mUnk_00->mUnk_2c[2], 2) != 0) {
                func_020576b8(r, i);
                if (data_021759d4->mUnk_0c != 0) {
                    func_02145d38();
                }
            } else {
                func_0214d168(r, 0, 0xb00);
                func_0205746c(i, &data_0217aa08->mUnk_00->mUnk_2c[2], 2);
            }
            v1 = i * 5;
            v2 = (i + 1) * 5;
            q = (u8 *) r + 4;
            for (k = 0; k < 4; k++) {
                t = d[k];
                if (t >= v1 && t < v2) {
                    x = t % 5;
                    *q = *q | (1 << x);
                    func_0214d1fc((u8 *) func_0212030c(k & 0xff) + 0x14, r->mUnk_008[x], 0x200);
                }
            }
            func_02057710(r, i);
            if (data_021759d4->mUnk_0c != 0) {
                func_02145d38();
            }
        }
    }
    func_02057504();
}

static inline s32 func_0205e5c4_inline(void) {
    if (data_0217aa00 == 0) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

void func_0205e5c4(s32 a) {
    void (*f)(void);
    s32 c;
    s32 d;
    if (a != 0) {
        c = 0;
        d = func_0205e5c4_inline();
        if (d != 0) {
            if (data_0217aa00->mUnk_0004 != 13) {
                c = 1;
            }
        }
        if (c == 0) {
            return;
        }
        f = func_0205e900;
    } else {
        d = 0;
        if (data_0217d384 != 0) {
            if (data_0217d384->mUnk_1f30 != 0) {
                d = 1;
            }
        }
        if (d == 0) {
            return;
        }
        f = func_0205e67c;
    }
    func_02057514();
    func_02057df0(f);
    data_0217aa0c->mUnk_f8 = 1;
}

static inline u8 func_0205e548_inline(void *a) {
    u8 n = 0;
    u8 i = 0;
    do {
        if (a != 0) {
            func_0214d1fc(&data_0217aa08->mUnk_20->mUnk_04[i], a, 0x24);
        }
        if (data_0217aa08->mUnk_20->mUnk_04[i].mUnk_22_0 != 0) {
            n = n + 1;
        }
        i = i + 1;
    } while (i < 60);
    return n;
}

u8 func_0205e548(void) {
    return func_0205e548_inline(0);
}

#pragma thumb on

void func_0205e530(void) {
    func_0202dfd4(func_020364e0(func_020364e8()));
}

void func_0205e528(void) {
    func_0202defc();
}

void func_0205e520(void) {
    func_0202dec8();
}

void func_0205e518(u32 a) {
    func_0202df34(a);
}

s32 func_0205e4e4(Unk020487fc *a) {
    Unk021a9034 b = data_021653c0;

    func_020487fc(a, &b);
    return 0;
}

#pragma thumb off

static inline s32 func_0205e2cc_inline(s32 a, s32 b) {
    return (s32) (((s64) a * b + 0x800) >> 12);
}

void func_0205e2cc(void *a) {
    u16 n;
    u16 i;
    u16 k;
    u16 j;
    u16 m;
    Unk02175620_74 *p;
    Unk0217aa24_00 *e;
    s32 u;
    s32 v;
    s32 w;
    s32 y;
    n = data_02175620->mUnk_78;
    m = 0;
    data_0217aa24 = func_02036bec(a, 8);
    for (i = 0; i < n; i++) {
        if (func_020423fc(i)->mUnk_44 == 5) {
            m = m + 1;
        }
    }
    if (m != 0) {
        data_0217aa24->mUnk_00 = func_02036bec(a, m * 0xc);
    }
    k = 0;
    data_0217aa24->mUnk_04 = m;
    for (j = 0; j < n; j++) {
        p = func_020423fc(j);
        if (p->mUnk_44 == 5) {
            e = &data_0217aa24->mUnk_00[k];
            e->mUnk_00 = j;
            u = 0;
            switch (p->mUnk_42) {
                case 0:
                    u = func_0205e2cc_inline(func_020431cc(), p->mUnk_0c.x);
                    v = func_0205e2cc_inline(func_020431d4(), p->mUnk_0c.y) >> 1;
                    y = func_0205e2cc_inline(func_020431cc(), p->mUnk_0c.z);
                    w = func_0205e2cc_inline(u, u) + func_0205e2cc_inline(v, v);
                    y = func_0205e2cc_inline(y, y);
                    u = func_02147e8c(y + w);
                    break;
                case 1:
                    u = func_0205e2cc_inline(func_020431dc(), p->mUnk_0c.x);
                    break;
            }
            e->mUnk_04 = u;
            e->mUnk_09 = 0;
            e->mUnk_08 = 0;
            k = k + 1;
        }
    }
}
