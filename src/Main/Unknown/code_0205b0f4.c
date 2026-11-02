#include "Main/Unknown/code_0205b0f4.h"
#include "Main/Unknown/code_0205b000.h"
#include "Main/Unknown/code_0205a000.h"
#include "Main/Unknown/code_0205c000.h"
#include "Main/Unknown/code_02056d40.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_021201e4.h"
#include "Main/Unknown/code_0205a908.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_0219bb50.h"
#include "00/code_02182fdc.h"
#include "01/code_021956dc.h"
#include "code_0200f5ac.h"
#include "code_0202056c.h"
#include "code_021458c4.h"

u32 func_0205bba8(void) {
    u32 r;
    Unk0217aa14 *p;

    p = data_0217aa14;
    r = 0;
    if (p->mUnk_758 != 3) {
        if (p->mUnk_758 != 5) {
            return r;
        }
        if ((p->mUnk_75c & 0x100) != 0) {
            r = 2;
        }
        return r;
    }
    return 9;
}

// non-matching: the register of the data pointer (r4) and of the byte read from 0x749 in the value-5 arm (r3) are
// swapped (r3 and r4 here); nothing else differs (7 words).
void func_0205ba60(void) {
    Unk0217aa14 *p;
    u8 a;
    u8 b;
    u8 i;
    u32 v1;

    a = 0;
    b = 0;
    p = data_0217aa14;
    switch (p->mUnk_758) {
        case 3:
        case 4:
            for (i = 0; i < 4; i++) {
                v1 = 1 << i;
                if ((data_0217aa14->mUnk_749 & v1) != 0 && i != func_ov000_0219bb50()) {
                    if (data_0217aa14->mUnk_74e[i] != 4 && data_0217aa14->mUnk_74e[i] != 5) {
                        a = a | v1;
                    }
                }
            }
            if (a == 0) {
                data_0217aa14->mUnk_758 = 5;
            }
            break;
        case 5:
            for (a = 0; a < 4; a++) {
                v1 = 1 << a;
                if ((p->mUnk_749 & v1) != 0 && p->mUnk_74e[a] == 5) {
                    b = b | v1;
                }
            }
            if ((p->mUnk_749 & ~b) == 0) {
                p->mUnk_75c = p->mUnk_75c | 0x100;
            }
            if ((data_0217aa14->mUnk_749 | ~b) != 0) {
                data_0217aa14->mUnk_75c = data_0217aa14->mUnk_75c | 0x100;
            }
            break;
    }
    if ((data_0217aa14->mUnk_749 & ~b) == 0) {
        data_0217aa14->mUnk_758 = 5;
    }
}

void func_0205b9a8(void) {
    u16 v;
    Unk0217aa14 *p;
    Unk0217aa14_754 *q;
    Unk0217aa14_754_04 *r;
    s32 t;

    func_0205a908();
    func_0205a350();
    p = data_0217aa14;
    q = p->mUnk_754;
    r = &q->mUnk_04;
    v = 0x68 - p->mUnk_724;
    q->mUnk_04.mUnk_00_0 = p->mUnk_728;
    r->mUnk_00_b[3] = v;
    if (data_0217aa18->mUnk_06[func_ov000_0219bb50()] < 0) {
        r->mUnk_04 = 0;
    } else {
        t = func_0205afa8();
        r->mUnk_04 = t | ((data_0217aa14->mUnk_73e << 23) & 0x7800000);
    }
    func_0205c234(v);
    func_0205be0c();
    func_0205ba60();
}

Unk0217aa14_104 *func_0205b978(s32 a, u32 b) {
    Unk0217aa14_104 *e;

    e = &data_0217aa14->mUnk_104[a];
    if (b != e->mUnk_00_0) {
        return 0;
    }
    return e;
}

s32 func_0205b954(s32 a) {
    return data_0217aa14->mUnk_104[a].mUnk_00_0;
}

void func_0205b824(const u64 *a, s32 b) {
    u8 n;
    u64 d;
    Unk0217aa14 *p;
    s32 f;

    p = data_0217aa14;
    n = p->mUnk_014[b].mUnk_34;
    if (n >= 12) {
        return;
    }
    if (n != 0) {
        d = (a[3] - a[0]) - (a[2] - a[1]);
        if (d * 64 / 0x82ea < 1000) {
            *(u64 *) &p->mUnk_014[b].mUnk_28 += d;
            f = 1;
        } else {
            f = 0;
            data_0217aa14->mUnk_014[b].mUnk_35++;
            if (data_0217aa14->mUnk_014[b].mUnk_35 > 0x40) {
                data_0217aa14->mUnk_748 |= 1 << b;
            }
        }
    } else {
        f = 1;
    }
    if (f != 0) {
        n = n + 1;
    }
    data_0217aa14->mUnk_014[b].mUnk_34 = n;
}

void func_0205b778(u32 a, Unk0205b504 *b) {
    Unk0217aa14 *p;
    Unk0217aa14_104 *e;
    u8 *s;
    u32 y;
    u32 v1;
    u8 n;
    u32 x;

    v1 = b->mUnk_00_0;
    p = data_0217aa14;
    s = b->mUnk_04.mUnk_00_b;
    y = b->mUnk_04.mUnk_00_0;
    x = p->mUnk_104[v1].mUnk_00_0;
    e = &p->mUnk_104[v1];
    n = s[3];
    if (p->mUnk_00e != 4 && p->mUnk_00e != 5) {
        return;
    }
    if (x != 0 && x >= y) {
        return;
    }
    if (p->mUnk_104[v1].mUnk_86_0 == 0) {
        p->mUnk_104[v1].mUnk_86_0 = 1;
    }
    func_0214d1fc(s, e, n);
}

// non-matching: the original keeps the new 0xf4 value in r2 and reuses it for the 0x800 step (add r2, r2, r1, asr #1);
// here it is built in r1 and the byte index and the 0xfa byte swap r0 and r1 (16 words).
void func_0205b6bc(u32 a, Unk0205b504 *b) {
    s32 t;
    Unk0217aa14 *p;
    s16 x;
    s16 v;
    s16 d;
    u32 v1;
    u8 f;

    x = b->mUnk_04.mUnk_00_s;
    p = data_0217aa14;
    v = p->mUnk_736;
    if (p->mUnk_00e == 2) {
        v1 = 1 << b->mUnk_00_0;
        f = p->mUnk_0fa;
        if ((f & v1) == 0) {
            p->mUnk_0fa = f | v1;
        }
        return;
    }
    if (v < 0) {
        return;
    }
    d = x - v;
    if (d > 0) {
        d = (d + 1) >> 1;
    } else if (d < 0) {
        d = (d - 1) >> 1;
    }
    t = (d << 11) + (data_0217aa14->mUnk_0f4 >> 1);
    data_0217aa14->mUnk_0f4 = t;
    data_0217aa14->mUnk_736 = data_0217aa14->mUnk_736 + (((t + 0x800) << 4) >> 16);
}

// non-matching: the original also pushes r7 and a stack pad (index in r7, 0x1b8 bytes); here the same code uses r5 and
// lr and is 0x18c bytes.
void func_0205b504(u32 a, Unk0205b504 *b, u32 c, u32 d) {
    u32 v1;
    Unk0217aa14 *p;
    Unk0205b504_04 *m;
    Unk0217aa14_014 *e;
    u32 i;
    u64 t;
    u8 v;

    p = data_0217aa14;
    if (p == 0) {
        return;
    }
    v1 = b->mUnk_00_0;
    if ((p->mUnk_749 & (1 << v1)) == 0) {
        return;
    }
    p->mUnk_740[v1] = 0;
    data_0217aa14->mUnk_74a[b->mUnk_00_0] = b->mUnk_02_0;
    data_0217aa14->mUnk_74e[b->mUnk_00_0] = b->mUnk_01;
    switch (b->mUnk_00_4) {
        case 0:
            m = &b->mUnk_04;
            i = b->mUnk_00_0;
            v = func_ov000_0219bb50();
            if (m->mUnk_00 == v) {
                m->mUnk_04[3] = func_0200f5ac();
                func_0205b824(m->mUnk_04, i);
                return;
            }
            if (m->mUnk_00 >= 4) {
                return;
            }
            e = &data_0217aa14->mUnk_014[i];
            func_0214d1fc(m, e, 0x28);
            t = func_0200f5ac();
            e->mUnk_0c = t;
            e->mUnk_10 = t >> 32;
            data_0217aa14->mUnk_014[i].mUnk_30 = 1;
            break;
        case 1:
            data_0217aa14->mUnk_0fa = data_0217aa14->mUnk_0fa | (1 << b->mUnk_00_0);
            break;
        case 2:
            func_0205b6bc(a, b);
            break;
        case 3:
            func_0205b778(a, b);
            break;
        case 4:
        case 5:
            break;
    }
}

void func_0205b32c(void) {
    s16 a[4];
    s16 v1[4];
    s32 v2;
    u8 i;
    u8 j;
    u8 k;
    u8 v3;
    s32 s;
    s8 m;
    u32 x;
    u32 y;
    s16 d;

    for (i = 0; i < 4; i++) {
        if (data_0217aa18->mUnk_06[i] == -1) {
            a[i] = 5000;
        } else {
            a[i] = func_02120220(i);
        }
    }
    for (i = 0; i < 4; i++) {
        s = data_0217aa18->mUnk_06[i];
        if (s == -1) {
            continue;
        }
        v1[i] = a[i];
        for (j = 0; j < 4; j++) {
            k = 1;
            m = data_0217aa18->mUnk_06[j];
            if (m == -1 || s == m) {
                continue;
            }
            x = func_0203c8dc((u16) s);
            y = func_0203c8dc((u16) m);
            if (x > y) {
                k = 0;
            }
            d = a[j] - a[i];
            for (v3 = 0; v3 < 9; v3++) {
                if (d > data_021548e0[v3].mUnk_00) {
                    if (k != 0) {
                        v2 = data_021548e0[v3].mUnk_02;
                    } else {
                        v2 = data_021548e0[v3].mUnk_03;
                    }
                    break;
                }
            }
            v1[i] += v2;
            if (v1[i] < 0) {
                v1[i] = 0;
                continue;
            }
            if (v1[i] > 10000) {
                v1[i] = 10000;
            }
        }
        func_02120200(i, v1[i]);
    }
}

void func_0205b0f4(void) {
    u8 i;
    u32 a;
    u32 v1;
    u32 v2;
    u8 t;
    u16 v;
    u32 n;
    Unk0217aa08_00 *q;

    for (i = 0; i < 4; i++) {
        v1 = 1 << i;
        if ((data_0217aa14->mUnk_749 & v1) != 0 && i != func_ov000_0219bb50() && (data_0217aa14->mUnk_748 & v1) == 0) {
            v2 = 300;
            if (data_0217aa14->mUnk_014[i].mUnk_34 == 0) {
                v2 = 600;
            }
            data_0217aa14->mUnk_740[i]++;
            if (data_0217aa14->mUnk_740[i] > v2) {
                data_0217aa14->mUnk_748 |= v1;
            }
        }
    }
    a = data_0217aa14->mUnk_748;
    for (i = 0; i < 4; i++) {
        if ((data_0217aa14->mUnk_749 & (1 << i)) != 0) {
            if (i != func_ov000_0219bb50()) {
                if ((data_0217aa14->mUnk_748 & (1 << i)) == 0) {
                    t = data_0217aa14->mUnk_74a[i] | (1u << i);
                    a = a & t;
                }
            }
        }
    }
    if (a == 0) {
        return;
    }
    for (i = 0; i < 4; i++) {
        v1 = 1 << i;
        if ((a & v1) != 0 && (data_0217aa14->mUnk_749 & v1) != 0 && data_0217aa18->mUnk_06[i] != -1) {
            func_0203c2e4(data_0217aa18->mUnk_06[i]);
            data_0217aa14->mUnk_749 = data_0217aa14->mUnk_749 & ~v1;
        }
    }
    if (func_0202056c(data_0217aa14->mUnk_749) > 1) {
        return;
    }
    v = data_0217d384->mUnk_0008.mUnk_0e;
    q = data_0217aa08->mUnk_00;
    n = q->mUnk_48;
    if (v != 0) {
        s8 c = data_0217d384->mUnk_1f54 - 1;
        if (c > 0) {
            if (n < c) {
                n = 0;
            } else {
                n = n - c;
            }
        }
        q->mUnk_48 = n;
        func_02056d40();
        func_02057d9c();
        if (data_021759d4->mUnk_0c != 0) {
            func_02145d38();
        }
    }
    func_021208e8(2);
}
