#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f5008.h"
#include "Main/Unknown/code_020f504c.h"
#include "Main/Unknown/code_020f73fc.h"
#include "Main/Unknown/code_020f81c0.h"
#include "Main/Unknown/code_020f830c.h"
#include "Main/Unknown/code_020fc2e8.h"
#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/code_021001ac.h"
#include "Main/Unknown/unk_02159000.h"
#include "ITCM/code_01fff000.h"
#include "ITCM/code_01fff95c.h"
#include "Main/Unknown/code_02071000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/code_020f5000.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f7000.h"
#include "Main/Unknown/code_020f8000.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/code_020fa000.h"
#include "Main/Unknown/code_020fc000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_02100000.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/code_020f5cc4.h"
#include "Main/Unknown/code_020f82c4.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020f8d9c.h"
#include "Main/Unknown/code_020b502c.h"
#include "code_02147cd8.h"

void func_020f1048(Unk027e00cc *v1, s32 v2, Unk020f41c4_A **out, u16 v3, Vec3 *v) {
    s32 i;

    if (v1->mUnk_10 + v2 > v1->mUnk_08) {
        while (v1->mUnk_10 + v2 > v1->mUnk_08) {
            if (v1->mUnk_14 > 0) {
                func_020f0f70(v1, v1->mUnk_04[0]);
            }
        }
    }
    i = 0;
    while (i < v2) {
        out[i] = v1->mUnk_04[v1->mUnk_10++];
        func_020f99b8(out[i], v1->mUnk_00, v3, v);
        i++;
    }
}

void func_020f0f70(Unk027e00cc *v1, Unk020f41c4_A *v) {
    s32 i;
    Unk020f41c4_A **p;
    s32 n;

    i = 0;
    p = v1->mUnk_04;
    while (i < v1->mUnk_10) {
        if (p[i] == v) {
            goto found;
        }
        i++;
    }
    i = v1->mUnk_10;
found:
    if (i < v1->mUnk_18) {
        v1->mUnk_18 = v1->mUnk_18 - 1;
        n = v1->mUnk_18;
        for (; i < n; i++) {
            p[i] = p[i + 1];
        }
    }
    if (i < v1->mUnk_14) {
        v1->mUnk_14 = v1->mUnk_14 - 1;
        p[i] = p[v1->mUnk_14];
        i = v1->mUnk_14;
    }
    if (i < v1->mUnk_10) {
        v1->mUnk_10 = v1->mUnk_10 - 1;
        p[i] = p[v1->mUnk_10];
        i = v1->mUnk_10;
    }
    p[i] = v;
    func_020f992c(v);
    v1->mUnk_1c = v1->mUnk_1c - 1;
}

void func_020f0ea0(Unk027e00cc *v1, Unk020f41c4_A *v) {
    s32 i;
    s32 n;
    Unk020f41c4_A **p;
    s32 c;
    Unk0217bc34 *t;
    enum { K0 } k;

    c = v1->mUnk_14;
    n = v1->mUnk_10;
    i = c;
    p = v1->mUnk_04;
    if (c < n) {
        do {
            if (p[i] == v) {
                goto found;
            }
            i++;
        } while (i < n);
    }
    i = n;
found:
    if (c < i) {
        p[i] = p[c];
        p[v1->mUnk_14] = v;
    }
    v1->mUnk_14 = v1->mUnk_14 + 1;
    v->mUnk_74 |= 0x2000;
    k = v1->mUnk_00;
    t = data_0217bc34 + k;
    if (t->mUnk_6c != 0) {
        func_020f9ca8(v);
    }
    v->mUnk_11c = 0;
    k = v->mUnk_44;
    t = data_0217bc34 + k;
    if (t->mUnk_1c != NULL) {
        t->mUnk_1c(v);
    }
}

void func_020f0e2c(Unk027e00cc *v1, Unk020f41c4_A *v) {
    s32 i;
    s32 n;
    Unk020f41c4_A **p;

    n = v1->mUnk_14;
    i = 0;
    p = v1->mUnk_04;
    while (i < n) {
        if (p[i] == v) {
            goto found;
        }
        i++;
    }
    i = n;
found:
    n = v1->mUnk_18;
    if (i < n) {
        return;
    }
    p[i] = p[n];
    p[v1->mUnk_18] = v;
    v1->mUnk_18 = v1->mUnk_18 + 1;
}

void func_020f0df8(Unk027e00cc *v1, void *a) {
    if (v1->mUnk_24 != NULL) {
        func_020ed718((Unk020ed718 *) v1, a, (void (*)(void *, void *, void *)) v1->mUnk_24);
    } else {
        func_020ed79c((Unk020ed718 *) v1, (Vec3 *) a);
    }
}

void func_020f0d04(Unk020f41c4_A *p) {
    void *(*f)(void *, void *, s32);
    s32 i;
    void *z;

    z = NULL;
    i = p->mUnk_44;
    if ((p->mUnk_78 & 0xf00) != 0) {
        z = func_020fe4c0(z, p, 1);
        func_020fe4c0(z, p, 0);
        func_020fe4b4(p);
        if (p->mUnk_78 & 0x800) {
            func_020f70f0(p);
        }
        if (p->mUnk_78 & 0x400) {
            func_020f705c(p);
        }
        if (p->mUnk_78 & 0x200) {
            func_020f7600(p);
        }
        if (p->mUnk_78 & 0x100) {
            func_020f73fc(p);
        }
    } else {
        f = data_0217bc34[i].mUnk_48;
        z = f(z, p, 1);
        f(z, p, 0);
        data_0217bc34[i].mUnk_50(p);
    }
    p->mUnk_74 |= 0x20000000;
}

void func_020f0b00(Unk027e00cc *v1, s32 a, void *b, s32 c) {
    Unk020f41c4_A *e;
    s32 i;
    s32 m;
    s32 n;
    Unk020f41c4_A **p;
    s32 k;
    enum { J0 } j;
    void (*g)(void *);

    i = v1->mUnk_10;
    v1->mUnk_10 = i + 1;
    e = v1->mUnk_04[i];
    func_020f9054(e, v1->mUnk_00, b, c);
    v1->mUnk_1c = v1->mUnk_1c + 1;
    k = v1->mUnk_14;
    n = v1->mUnk_10;
    p = v1->mUnk_04;
    m = k;
    if (k < n) {
        do {
            if (p[m] == e) {
                goto found;
            }
            m++;
        } while (m < n);
    }
    m = n;
found:
    if (k < m) {
        p[m] = p[k];
        p[v1->mUnk_14] = e;
    }
    v1->mUnk_14 = v1->mUnk_14 + 1;
    e->mUnk_74 |= 0x2000;
    j = v1->mUnk_00;
    if (data_0217bc34[j].mUnk_6c != 0) {
        func_020f9ca8(e);
    }
    e->mUnk_11c = 0;
    j = e->mUnk_44;
    if (data_0217bc34[j].mUnk_1c != NULL) {
        data_0217bc34[j].mUnk_1c(e);
    }
    if (c != 0) {
        g = func_020fe4b4;
    } else {
        j = e->mUnk_44;
        g = data_0217bc34[j].mUnk_50;
    }
    g(e);
    e->mUnk_74 |= 0x20000000;
    if (c != 0) {
        if (e->mUnk_78 & 0x800) {
            func_020f70f0(e);
        }
        if (e->mUnk_78 & 0x400) {
            func_020f705c(e);
        }
        if (e->mUnk_78 & 0x200) {
            func_020f7600(e);
        }
        if (e->mUnk_78 & 0x100) {
            func_020f73fc(e);
        }
    } else if ((e->mUnk_78 & 0x1000) == 0) {
        k = (u16) ((e->mUnk_78 & 0x8000) == 0 ? (u16) (e->mUnk_78 & ~0xff00) : 8);
        if (k != 8) {
            func_02071894(func_0207a974(k));
        }
    }
    if (a > 0) {
        e->mUnk_7a = a;
        e->mUnk_7a |= data_02159618;
    }
}

// non-matching: the switch arms hold the case values in other registers (0x1a8 vs 0x1b0 bytes)
s32 func_020f0950(Unk027e00cc *a, s32 b, s32 c) {
    s32 k;
    s32 i;
    Unk020f41c4_A *e;
    s32 n;
    BOOL r;
    BOOL z0;
    BOOL z1;
    BOOL z2;
    BOOL z3;
    BOOL z4;
    BOOL z5;
    u32 h;

    k = b;
    h = ((u32) (k & 0xf0) << 12) >> 16;
    n = a->mUnk_14;
    r = FALSE;
    i = 0;
    k &= 0xf;
    z0 = FALSE;
    z1 = FALSE;
    z2 = FALSE;
    z3 = FALSE;
    z4 = FALSE;
    z5 = FALSE;
    for (; i < n; i++) {
        e = a->mUnk_04[i];
        if (e->mUnk_4e != c) {
            continue;
        }
        r = TRUE;
        if (k < 4) {
            e->mUnk_5c.x = (s32) (((s64) e->mUnk_5c.x * 0x4cd) >> 12);
            e->mUnk_5c.y = (s32) (((s64) e->mUnk_5c.y * 0x4cd) >> 12);
            e->mUnk_5c.z = (s32) (((s64) e->mUnk_5c.z * 0x4cd) >> 12);
        }
        switch (k) {
            case 0:
                func_020f7104(e, z0);
                break;
            case 1:
                func_020f7070(e, z1);
                break;
            case 2:
                func_020f6fc4(e, z2);
                break;
            case 3:
                if (a->mUnk_00 == 1) {
                    if (func_020f5324(e, h) == 0) {
                        break;
                    }
                }
                func_020f6f10(e, z3, h);
                break;
            case 4:
                func_020f7658(e, z4);
                break;
            case 5:
                func_020f7430(e, z5);
                break;
        }
    }
    return r;
}

s32 func_020f0898(Unk027e00cc *a, u8 *b) {
    s32 k;
    s32 i;
    s32 n;
    Unk020f41c4_A *e;
    s32 c;
    Unk020f41c4_A **p;
    BOOL m;

    n = a->mUnk_14;
    i = 0;
    m = FALSE;
    k = b[1];
    p = a->mUnk_04;
    for (; i < n; i++) {
        e = p[i];
        if (k != e->mUnk_4e) {
            continue;
        }
        m = TRUE;
        c = b[2];
        if (a->mUnk_00 == 1) {
            func_020f5cc4((u32) e, c);
        }
        if (a->mUnk_00 == 5) {
            func_020fc8ec((Unk020fc2e8 *) e, c);
        }
        if (a->mUnk_00 == 0xb) {
            func_021003e8((Unk02101c84 *) e, c, b[3]);
        }
    }
    return m;
}

void func_020f0758(Unk027e00cc *a, s32 m, s32 b, u8 *c, s32 d) {
    enum { K0 } k;

    switch (m) {
        case 0:
            k = a->mUnk_00;
            if (!data_0217bc34[k].mUnk_48) {
                return;
            }
            if (c[1] == 0xff) {
                return;
            }
            func_020f0b00(a, b, c, 0);
            if (a->mUnk_00 == 6) {
                func_020f82e8(0);
            }
            if (a->mUnk_00 == 0xa) {
                func_020f82a4(0);
            }
            return;
        case 1:
            func_020f0b00(a, b, c, 1);
            return;
        case 2:
            if (func_020f0950(a, c[2], c[1]) != 0) {
                return;
            }
            break;
        case 3:
            if (func_020f0898(a, c) != 0) {
                return;
            }
            break;
        default:
            return;
    }
    func_020fe56c(a->mUnk_00, m, b, c, d);
}

void func_020f0684(Unk020f41c4_A **p, s32 i, s32 n, s32 v1) {
    Unk020f41c4_A *v;
    Unk020f41c4_A *w;
    s32 j;

    if (i >= n) {
        return;
    }
    do {
        v = p[i - 1];
        w = p[i];
        if ((v->mUnk_74 & 0x180000) != 0) {
            goto next;
        }
        if (func_020f9c08(v) != 0) {
            if (func_020f9c08(w) == 0) {
                goto next;
            }
            j = 0;
            do {
                if ((w->mUnk_fc & data_021595e4[j]) != 0) {
                    goto next;
                }
                if ((v->mUnk_fc & data_021595e4[j]) != 0) {
                    p[i - 1] = w;
                    p[i] = v;
                    goto next;
                }
                j++;
            } while (j < 0xd);
        } else if (func_020f9c08(w) != 0) {
            p[i - 1] = w;
            p[i] = v;
        }
    next:
        i += v1;
    } while (i < n);
}

void func_020f03f8(Unk027e00cc *a) {
    Unk020f41c4_A **e;
    Unk020f41c4_A *p;
    Unk0206bcb0 *q;
    s32 k;
    s32 min;
    Vec3 *b;
    Vec3 *c;
    s32 n;
    s32 i;
    s32 t;
    s32 v;
    s32 w;
    s32 d;
    s32 z;
    s32 m;
    s32 g;
    s32 h;
    u16 u;

    e = a->mUnk_04;
    n = a->mUnk_14;
    if (a->mUnk_20 > 1 && a->mUnk_20 - a->mUnk_1c < 2) {
        m = a->mUnk_18;
        if ((t = func_02061f90()) == 0) {
            if (a->mUnk_20 - a->mUnk_1c < 1 && a->mUnk_14 > 0) {
                func_020f9ba8(a->mUnk_04[0]);
            }
        } else {
            if (a->mUnk_00 == 2) {
                m -= 3;
            }
            func_020f0684(e, t, m, 7);
        }
    }
    if (data_021759c0->mUnk_08 != 5) {
        for (i = 0; i < n; i++) {
            if (func_01fff95c(a, e[i], 0) != 0) {
                n = a->mUnk_14, i--;
            }
        }
        return;
    }
    for (i = 0; i < n; i++) {
        p = e[i];
        v = (u16) (p->mUnk_7a & ~0x8000);
        if (v <= 0) {
            if (func_01fff95c(a, p, 0) != 0) {
                n = a->mUnk_14;
                i--;
            }
        } else {
            w = p->mUnk_7a & 0x8000;
            k = 1;
            if (w != 0) {
                min = 0x5f592e1;
                p->mUnk_7a &= ~0x8000;
                k += v;
            } else {
                k++;
                for (z = v >> 2; z != 0; z >>= 2) {
                    k++;
                }
            }
            func_020d5180(&p->mUnk_50, p->mUnk_e0 + k * 0xa000, 0x6000);
            p->mUnk_7a++;
            do {
                p->mUnk_7a--;
                if (func_01fff95c(a, p, 1) != 0) {
                    n = a->mUnk_14;
                    i--;
                    break;
                }
                if (w != 0) {
                    b = p->mUnk_d0;
                    u = p->mUnk_78 & ~0xff00;
                    q = func_0207a974(u);
                    c = &q->mUnk_98;
                    d = ((c->x - b->x) >> 12) * ((c->x - b->x) >> 12);
                    g = (c->y - b->y) >> 12;
                    h = (c->z - b->z) >> 12;
                    d += g * g;
                    d += h * h;
                    if (min <= d) {
                        break;
                    }
                    min = d;
                }
            } while (--k > 0);
        }
    }
}

BOOL func_020f03bc(Unk027e00cc *v1) {
    if (v1->mUnk_14 <= 0) {
        return FALSE;
    }
    func_020f0f70(v1, v1->mUnk_04[0]);
    return TRUE;
}

#pragma thumb on
void func_020f02c0(Unk027e00cc *q, s32 a, s32 *b) {
    void *v;
    s32 n;
    s32 s;
    s32 k;
    s32 i;

    v = GetHeap(func_020364e8());
    k = *b;
    n = data_0217bc34[a].mUnk_0c;
    s = data_0217bc34[a].mUnk_00;
    q->mUnk_00 = a;
    q->mUnk_04 = n != 0 ? (Unk020f41c4_A **) HeapAlloc(v, n * 4) : 0;
    q->mUnk_08 = n;
    q->mUnk_0c = data_0217bc34[a].mUnk_10;
    q->mUnk_10 = 0;
    q->mUnk_14 = 0;
    q->mUnk_18 = 0;
    q->mUnk_1c = 0;
    q->mUnk_20 = data_0217bc34[a].mUnk_04;
    for (i = 0; i < n; i++) {
        q->mUnk_04[i] = HeapAlloc(v, s);
        func_020f8d9c((s32) q->mUnk_04[i], k, a);
        k++;
        q->mUnk_04[i]->mUnk_4c = i;
    }
    q->mUnk_24 = data_0217bc34[a].mUnk_2c;
    q->mUnk_28 = data_0217bc34[a].mUnk_30;
    q->mUnk_2c = data_0217bc34[a].mUnk_70;
    q->mUnk_30 = data_0217bc34[a].mUnk_74;
    q->mUnk_34 = data_0217bc34[a].mUnk_78;
    q->mUnk_38 = data_0217bc34[a].mUnk_5c;
    q->mUnk_3c = data_0217bc34[a].mUnk_a4;
    *b = k;
}

#pragma thumb off
BOOL func_020f0154(Unk020ee684 *p) {
    Unk0206bcb0 *b;
    u16 v;
    enum { K0 } i;

    b = p->mUnk_1fc;
    if (func_02061fec() == 0) {
        return FALSE;
    }
    if (b->mState != 0) {
        return FALSE;
    }
    if ((b->mUnk_4c & 0x20000000) != 0) {
        return FALSE;
    }
    if (p->mUnk_058.mUnk_000 != 0xf) {
        p->mUnk_1ec |= data_021595b8;
    } else if (p->mUnk_030.mUnk_00 != 0x13) {
        p->mUnk_1ec |= data_021595bc;
    } else if (p->mUnk_000 != 0) {
        p->mUnk_1ec |= data_021595c0;
    }
    i = p->mUnk_200;
    v = data_0217562a[i].mBits & 0x40;
    if (v != 0) {
        p->mUnk_1ec |= data_021595c4;
    }
    i = p->mUnk_200;
    v = data_0217562a[i].mBits & 0x80;
    if (v != 0) {
        p->mUnk_1ec |= data_021595c8;
    }
    return TRUE;
}

void func_020f00f0(Unk020ee684 *p) {
    if ((p->mUnk_1fc->mUnk_7c & 0x400) != 0) {
        return;
    }
    if (data_021759c0->mUnk_08 == 5) {
        return;
    }
    if (p->mUnk_000 == 0) {
        return;
    }
    func_020f81c0(p);
}

void func_020f0044(Unk020ee684 *p) {
    if ((p->mUnk_1fc->mUnk_7c & 0x400) != 0) {
        return;
    }
    if (p->mUnk_030.mUnk_00 != 0x13) {
        func_020f45f0(&p->mUnk_030, 0);
    }
    if (data_021759c0->mUnk_08 == 5) {
        return;
    }
    if (p->mUnk_000 != 0) {
        func_020f81c0(p);
    }
    if (p->mUnk_014 != 0x13) {
        p->mUnk_014 = 0x13;
    }
    if (data_021759c0->mUnk_08 == 5) {
        return;
    }
    if (p->mUnk_058.mUnk_000 == 0xf) {
        return;
    }
    func_020edb00(&p->mUnk_058);
}

void func_020eff40(Unk020ee684 *p) {
    BOOL f;

    f = data_021759c0->mUnk_08 == 5;
    if ((p->mUnk_1fc->mUnk_7c & 0x400) != 0) {
        return;
    }
    if ((u32) (p->mUnk_1fc->mUnk_29c - 2) <= 1) {
        return;
    }
    if (f && p->mUnk_014 != 0x13) {
        return;
    }
    if (p->mUnk_030.mUnk_00 != 0x13 && p->mUnk_030.mUnk_20 == 0) {
        func_020f41b0(&p->mUnk_030);
    }
    if (f) {
        return;
    }
    if (p->mUnk_000 != 0) {
        func_020f81c0(p);
    }
    if (f) {
        return;
    }
    if (p->mUnk_058.mUnk_000 == 0xf) {
        return;
    }
    if (p->mUnk_058.mUnk_024 != 0) {
        return;
    }
    func_020edad8(&p->mUnk_058);
}

void func_020efea4(Unk020ee684 *p) {
    if ((u32) (p->mUnk_1fc->mUnk_29c - 2) <= 1) {
        return;
    }
    if (data_021759c0->mUnk_08 == 5) {
        return;
    }
    if (p->mUnk_058.mUnk_000 == 0xf) {
        return;
    }
    if (p->mUnk_058.mUnk_024 != 0) {
        return;
    }
    if (p->mUnk_058.mUnk_008 != 1 && p->mUnk_058.mUnk_008 != 2) {
        return;
    }
    func_020edad8(&p->mUnk_058);
}

BOOL func_020efd84(Unk020ee684 *p, s32 a) {
    Unk020f40dc *r;
    Unk027e00cc *q;
    enum { K0 } i;

    r = &p->mUnk_030;
    if (a == 0x13) {
        return TRUE;
    }
    if (p->mUnk_014 != 0x13) {
        p->mUnk_014 = 0x13;
    }
    if (p->mUnk_000 != 0) {
        if (p->mUnk_000 == 1 && p->mUnk_004 < 0x3c) {
            i = data_0217bc48[a].mUnk_08;
            q = &data_027e00cc[i];
            q->mUnk_1c--;
            return TRUE;
        }
        func_020f8418(p);
        func_020f47e4(r, a);
    } else {
        if (r->mUnk_00 == 0x13 && r->mUnk_08 == 0) {
            i = data_0217bc48[a].mUnk_08;
            q = &data_027e00cc[i];
            q->mUnk_1c--;
        }
    }
    func_020f4754(r, 1);
    return r->mUnk_00 == 0x13;
}

void func_020efd1c(Unk020ee684 *p, Unk020f41c4_A *a) {
    Unk0206bcb0 *b;
    Vec3 *v;

    b = p->mUnk_1fc;
    if ((b->mUnk_48 & 1) != 0) {
        v = &b->mUnk_15c;
    } else {
        v = &data_021595d8;
    }
    func_020f98a0(a, &b->mUnk_98, v, &b->mKartModelsEntry->mUnk_040, func_0206c0a8(b));
    if ((b->mUnk_48 & 1) != 0) {
        a->mUnk_74 |= 0x40000000;
    }
}

void func_020efc74(Unk020ee684 *p, s32 a) {
    Unk020f371c_Ref *r;
    Unk0206bcb0 *b;
    Vec3 *v;
    s64 d;
    s32 t;
    if ((t = func_020f4090(a)) != 0) {
        p->mUnk_1f0.mUnk_00 = (Unk020f371c *) t;
        p->mUnk_1f0.mUnk_04 = 1;
    }
    if ((r = &p->mUnk_1f0)->mUnk_00 == NULL) {
        return;
    }
    b = p->mUnk_1fc;
    v = &b->mUnk_98;
    func_020f3c54(r, r, v);
    d = (s64) (r->mUnk_00->mUnk_18->x - v->x) * (r->mUnk_00->mUnk_18->x - v->x);
    d += (s64) (r->mUnk_00->mUnk_18->z - v->z) * (r->mUnk_00->mUnk_18->z - v->z);
    if (d < ((s64) 0x15f9 << 32)) {
        return;
    }
    func_020f3a58(r, r, v);
}

#pragma thumb on
void func_020efbd4(Unk020ee684 *a, s32 n) {
    Unk02175620_060 *q;

    a->mUnk_1f8 = n;
    a->mUnk_1fc = func_0207a974(n);
    a->mUnk_200 = ((Unk021759c0_000 *) data_021759c0)->mUnk_07c[n].mUnk_00;
    func_020f89b0(a, a);
    func_020f4b20(&a->mUnk_030, a);
    func_020ee684(&a->mUnk_058, a);
    q = (Unk02175620_060 *) gCourseMap;
    a->mUnk_1f0.mUnk_00 = q->mUnk_060 != 0 ? q->mUnk_0b0 : 0;
    a->mUnk_1f0.mUnk_04 = 1;
    a->mUnk_204 = 0;
    a->mUnk_208 = 0;
    a->mUnk_20c = 0;
}

#pragma thumb off
void func_020efb84(Unk020eda5c *p, Unk020f41c4_A *v) {
    func_020f0ea0(&data_027e00cc[v->mUnk_44], v);
    func_020efd1c(p->mUnk_00c, v);
    v->mUnk_74 &= ~0x1000;
}

void func_020efa60(Unk020eda5c *a, s32 f) {
    Unk020f41c4_A *b;
    s32 (*cb)(void *, void *);
    void (*v)(struct Unk020f41c4_A *);

    a->mUnk_020--;
    b = a->mUnk_014[a->mUnk_020];
    cb = data_0217bc34[b->mUnk_44].mUnk_24;
    func_020efb84(a, b);
    if (cb(a, b) == 0) {
        if (a->mUnk_00c->mUnk_208 != 0) {
            b->mUnk_78 |= data_021595ac;
            f = 0;
        }
    }
    b->mUnk_d4 = data_0217bc34[b->mUnk_44].mUnk_30(b->mUnk_d0, b->mUnk_e0 << 1, data_0217bc34[b->mUnk_44].mUnk_5c,
                                                   data_0217bc34[b->mUnk_44].mUnk_a4, 0x1f);
    if (b->mUnk_74 & 0x400000) {
        func_020f90bc(b);
    }
    v = data_0217bc34[b->mUnk_44].mUnk_28;
    if ((b->mUnk_74 & 0x180000) == 0) {
        b->mUnk_120 = v;
    }
    if (f != 0) {
        func_02071894(a->mUnk_010);
    }
}

void func_020efa48(Unk020eda5c *a, Unk020f41c4_A *v) {
    a->mUnk_020 = a->mUnk_020 - 1;
    func_020efb84(a, v);
}

void func_020ef9a8(Unk020eda5c *a) {
    Unk020eda5c *p;
    Unk020f41c4_A *b;
    Vec3 *v;
    s32 d;

    p = a;
    b = a->mUnk_014[0];
    v = &a->mUnk_02c.mUnk_18;
    p->mUnk_090 = *v;
    p->mUnk_09c.x = -v->x;
    p->mUnk_09c.y = -v->y;
    p->mUnk_09c.z = -v->z;
    d = (s32) (((s64) a->mUnk_084.z << 14) >> 12);
    func_02147fd8(a->mUnk_078 + d, &p->mUnk_09c, &a->mUnk_050, &p->mUnk_0a8);
    func_02147fd8((s32) (((s64) a->mUnk_0e8 * a->mUnk_084.z) >> 12), &a->mUnk_02c.mUnk_0c, &p->mUnk_0a8, &b->mUnk_50);
}

void func_020ef8c4(Unk020eda5c *a) {
    Unk020eda5c *p;
    Unk020f41c4_A *b;
    Vec3 *v;
    s32 d;

    p = a;
    b = a->mUnk_014[0];
    v = &a->mUnk_02c.mUnk_18;
    p->mUnk_090 = *v;
    p->mUnk_09c.x = -v->x;
    p->mUnk_09c.y = -v->y;
    p->mUnk_09c.z = -v->z;
    d = (s32) (((s64) a->mUnk_084.z << 14) >> 12);
    func_02147fd8(a->mUnk_078 + d, &p->mUnk_09c, &a->mUnk_050, &p->mUnk_0a8);
    func_02147fd8((s32) (((s64) a->mUnk_0e8 * a->mUnk_084.z) >> 12), &a->mUnk_02c.mUnk_0c, &p->mUnk_0a8, &b->mUnk_50);
    b->mUnk_94.mUnk_00[1] = a->mUnk_02c.mUnk_0c;
    b->mUnk_94.mUnk_00[2].x = -p->mUnk_09c.x;
    b->mUnk_94.mUnk_00[2].y = -p->mUnk_09c.y;
    b->mUnk_94.mUnk_00[2].z = -p->mUnk_09c.z;
    func_020397a8(&b->mUnk_94.mUnk_00[1], &b->mUnk_94.mUnk_00[2], &b->mUnk_94.mUnk_00[0]);
}

void func_020ef65c(Unk020eda5c *a, Vec3 *v, Vec3 *w) {
    Unk020eda5c *p;
    Vec3 *q;
    Vec3 t;
    s32 d;
    s64 sq;

    p = a;
    q = &p->mUnk_090;
    t = a->mUnk_02c.mUnk_18;
    if (a->mUnk_080 != 0) {
        func_02147fd8(0x19a, &a->mUnk_06c, &t, &t);
    }
    q->x = (s32) (((s64) q->x * 0xccd) >> 12);
    q->y = (s32) (((s64) q->y * 0xccd) >> 12);
    q->z = (s32) (((s64) q->z * 0xccd) >> 12);
    func_02147fd8(0x333, &t, q, q);
    sq = (s64) q->x * q->x + (s64) q->y * q->y + (s64) q->z * q->z;
    if (sq >= 0x10) {
        func_02039860(q, &t);
    }
    p->mUnk_09c.x = -t.x;
    p->mUnk_09c.y = -t.y;
    p->mUnk_09c.z = -t.z;
    d = (s32) (((s64) a->mUnk_084.z << 14) >> 12);
    func_02147fd8(a->mUnk_078 + d, &p->mUnk_09c, &a->mUnk_050, w);
    if (a->mUnk_020 > 1) {
        p->mUnk_0e4 += (s32) (((s64) a->mUnk_07c * 0x333) >> 12);
        p->mUnk_0e4 -= (s32) (((s64) p->mUnk_0e4 * 0x266) >> 12);
    } else {
        p->mUnk_0e4 += (s32) (((s64) a->mUnk_07c * 0xd1f) >> 12);
        p->mUnk_0e4 -= (s32) (((s64) p->mUnk_0e4 * 0x68f) >> 12);
    }
    func_02147fd8(p->mUnk_0e4 - a->mUnk_07c + (s32) (((s64) a->mUnk_0e8 * a->mUnk_084.z) >> 12), &a->mUnk_02c.mUnk_0c,
                  w, v);
}

void func_020ef4a0(Unk020eda5c *a) {
    Unk020f41c4_A *b;
    Unk020ee684 *c;
    s32 n;
    enum { K0 } k, i;

    b = a->mUnk_014[0];
    c = a->mUnk_00c;
    n = b->mUnk_68.z;
    func_020ef65c(a, &b->mUnk_50, &a->mUnk_0a8);
    if (b->mUnk_11c > 0xc) {
        k = b->mUnk_44;
        if (func_020fa0b8(b, data_0217bc34[k].mUnk_70, 0x333) != 0) {
            func_020f9f08(b, a->mUnk_084.x, a->mUnk_084.y);
        }
    }
    if (n < 0xccd && b->mUnk_68.z >= 0xccd && a->mUnk_028 == data_021759c0->mUnk_62) {
        func_020719bc(&c->mUnk_1fc->mUnk_00, 0xe7);
    }
    if ((c->mUnk_1ec & 0x284) == 0x284 && a->mUnk_000 != 0xf && a->mUnk_024 == 0) {
        func_020efa60(a, 1);
    }
    if (a->mUnk_170 != NULL) {
        c->mUnk_014 = 0x13;
        i = c->mUnk_200;
        if ((u16) (data_0217562a[i].mBits & 0x40) != 0) {
            c->mUnk_1ec |= data_021595a0;
        }
        i = c->mUnk_200;
        if ((u16) (data_0217562a[i].mBits & 0x80) != 0) {
            c->mUnk_1ec |= data_021595a4;
        }
        func_020efa60(a, 1);
    }
    c->mUnk_1ec |= data_021595a8;
}

void func_020ef350(Unk020eda5c *a) {
    Unk020eda5c *c;
    Unk020f41c4_A *b;
    Vec3 v;
    s64 t;
    s64 sq;
    enum { K0 } k;

    c = a;
    b = a->mUnk_014[0];
    func_020ef4a0(a);
    if ((b->mUnk_74 & 0x1000) != 0) {
        v.x = (s32) (((s64) c->mUnk_09c.x << 13) >> 12);
        v.y = (s32) (((s64) c->mUnk_09c.y << 13) >> 12);
        v.z = (s32) (((s64) c->mUnk_09c.z << 13) >> 12);
        func_02148504(&v, &a->mUnk_02c.mUnk_18, &v);
        sq = (s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z;
        if (sq >= 0x10) {
            func_02039860(&v, &v);
        }
        b->mUnk_94.mUnk_00[2].x = -v.x;
        b->mUnk_94.mUnk_00[2].y = -v.y;
        b->mUnk_94.mUnk_00[2].z = -v.z;
        b->mUnk_94.mUnk_00[1] = a->mUnk_02c.mUnk_0c;
        func_020397a8(&b->mUnk_94.mUnk_00[1], &b->mUnk_94.mUnk_00[2], &b->mUnk_94.mUnk_00[0]);
    }
    k = b->mUnk_44;
    if (data_0217bc34[k].mUnk_20 != NULL) {
        data_0217bc34[k].mUnk_20(a, b);
    }
}

void func_020ef340(Unk020eda5c *a, Unk020f41c4_A *b, Unk020f41c4_A *c) {
    func_020efa48(a, c);
}

void func_020ef1cc(Unk020eda5c *p) {
    Unk020f41c4_A *b;
    Vec3 *q;
    s32 d;
    s32 i;
    Vec3 *u;
    Unk020f41c4_A **l;

    l = p->mUnk_014;
    b = l[0];
    q = &b->mUnk_50;
    u = &p->mUnk_02c.mUnk_18;
    p->mUnk_090 = *u;
    p->mUnk_09c.x = -p->mUnk_02c.mUnk_18.x;
    p->mUnk_09c.y = -u->y;
    p->mUnk_09c.z = -u->z;
    d = (s32) (((s64) p->mUnk_084.z << 14) >> 12);
    func_02147fd8(p->mUnk_078 + d, &p->mUnk_09c, &p->mUnk_050, &p->mUnk_0a8);
    func_02147fd8((s32) (((s64) p->mUnk_0e8 * p->mUnk_084.z) >> 12), &p->mUnk_02c.mUnk_0c, &p->mUnk_0a8, q);
    l[1]->mUnk_50 = p->mUnk_014[0]->mUnk_50;
    l[2]->mUnk_50 = l[1]->mUnk_50;
    p->mUnk_0b4 = p->mUnk_0a8;
    p->mUnk_0c0 = p->mUnk_0b4;
    p->mUnk_0cc[0] = 0xee1;
    p->mUnk_0cc[1] = p->mUnk_0cc[0];
    p->mUnk_0cc[2] = p->mUnk_0cc[1];
    p->mUnk_0d8 = p->mUnk_02c.mUnk_18;
    p->mUnk_16c = 0;
    for (i = 0; i < 0x10; i++) {
        p->mUnk_0ec[0][i] = 0;
        p->mUnk_0ec[1][i] = 0;
    }
    if (p->mUnk_028 == data_021759c0->mUnk_62) {
        func_020719bc(&p->mUnk_00c->mUnk_1fc->mUnk_00, 0xe7);
    }
}

// non-matching: registers differ (a=r10 vs r9, the 0x1800 accumulator spilled vs r5, stack 0x6c vs 0x64)
void func_020eecdc(Unk020eda5c *a) {
    Unk020ee684 *c;
    Unk020f41c4_A **q;
    s32 n;
    s32 k;
    Vec3 *v;
    s32 s14;
    s32 k70;
    s32 f;
    s32 k267;
    s32 k2;
    s32 d;
    s64 f2;
    s32 s;
    Vec3 v40;
    Vec3 v4c;
    Vec3 v58;
    Vec3 *w;
    s32 i;
    s32 x;
    Vec3 *t;
    s32 d0;
    Unk020f41c4_A *b;
    Unk020eda5c *p;

    p = a;
    c = a->mUnk_00c;
    b = a->mUnk_014[0];
    n = a->mUnk_020;
    v40 = c->mUnk_1fc->mUnk_1fc;
    q = a->mUnk_014;
    f = (s32) (((s64) a->mUnk_084.z * 0x3000) >> 12);
    x = a->mUnk_078 + (s32) (((s64) a->mUnk_084.z << 14) >> 12);
    v = &p->mUnk_09c;
    k70 = data_0217bc34[b->mUnk_44].mUnk_70;
    w = &p->mUnk_0a8;
    func_020ef65c(a, &b->mUnk_50, w);
    if (func_020fa0b8(b, k70, 0x19a) != 0) {
        func_020f9f08(b, a->mUnk_084.x, a->mUnk_084.y);
    }
    if (n > 1) {
        if (a->mUnk_080 != 0) {
            func_021484d0(&p->mUnk_0d8, v, &v58);
            s = (s32) (((s64) a->mUnk_068 * a->mUnk_068) >> 12);
            v58.x = (s32) (((s64) v58.x * s) >> 12);
            v58.y = (s32) (((s64) v58.y * s) >> 12);
            v58.z = (s32) (((s64) v58.z * s) >> 12);
        }
        p->mUnk_0d8 = p->mUnk_09c;
        k = p->mUnk_16c & 0xf;
        p->mUnk_16c = p->mUnk_16c + 1;
        p->mUnk_0ec[0][k] = p->mUnk_0e4;
        s14 = (s32) (((s64) a->mUnk_068 << 9) >> 12);
        if (s14 > 0x1000) {
            s14 = 0x1000;
        }
    }
    f2 = (s64) f * f;
    k267 = 0x267;
    k2 = (k - 6) & 0xf;
    d0 = 0x1800;
    t = &p->mUnk_0b4;
    for (i = 1; i < n; i++) {
        b = q[i];
        func_02148504(t, &v40, t);
        if (a->mUnk_024 != 0) {
            func_02148504(&q[i - 1]->mUnk_5c, &b->mUnk_5c, &b->mUnk_5c);
        }
        if (a->mUnk_080 != 0) {
            func_02147fd8(d0, &v58, t, t);
        }
        if (p->mUnk_0cc[i] > 0) {
            func_02147fd8(p->mUnk_0cc[i], &a->mUnk_06c, t, t);
        }
        func_021484d0(t, &a->mUnk_050, &v4c);
        if (i > 1) {
            x -= (i - 1) << 13;
        }
        d = x - func_02039828(&v4c, v);
        if (d > 0) {
            func_02147fd8(d, v, t, t);
        }
        d = (s32) (((s64) (w->y - t->y) * 0x666) >> 12);
        if (d < 0) {
            t->y = t->y + d;
        }
        s = (s32) (((s64) (p->mUnk_0ec[i - 1][k2] - a->mUnk_07c) * s14) >> 12);
        if (i == 1) {
            p->mUnk_0ec[i][k] = p->mUnk_0ec[i - 1][k2];
        }
        func_021484d0(t, w, &v4c);
        if ((s64) v4c.x * v4c.x + (s64) v4c.y * v4c.y + (s64) v4c.z * v4c.z >= f2) {
            if ((s64) v4c.x * v4c.x + (s64) v4c.y * v4c.y + (s64) v4c.z * v4c.z >= 0x10) {
                func_02039860(&v4c, &v4c);
            }
            func_02147fd8(f, &v4c, w, t);
            if (p->mUnk_0cc[i] > 0) {
                p->mUnk_0cc[i] -= 0x3d;
            }
        }
        func_02147fd8(s + (s32) (((s64) a->mUnk_084.z * 0x4333) >> 12), &a->mUnk_02c.mUnk_0c, t, &b->mUnk_50);
        if (func_020fa0b8(b, k70, k267) != 0) {
            func_020f9f08(b, a->mUnk_084.x, a->mUnk_084.y);
        }
        k267 += 0xcd;
        t++;
        d0 += 0x1800;
    }
    if ((c->mUnk_1ec & 0x244) == 0x244 && a->mUnk_000 != 0xf && a->mUnk_024 == 0) {
        func_020efa60(a, 1);
    }
}

// non-matching: 6 words from +0x14: the original sets k (r9) after the first cmp and sum (r7) after the 0x4cd load,
// here both are set before the cmp
void func_020eec48(Unk020eda5c *a, s32 i, Unk020f41c4_A *v) {
    s32 k;
    Unk020f41c4_A *e;
    s32 sum;

    k = 0;
    sum = 0;
    while (a->mUnk_020 > i + 1) {
        e = a->mUnk_014[a->mUnk_020 - 1];
        func_020efa60(a, 0);
        sum = sum + 0x4cd;
        if (k++ > 0) {
            func_02147fd8(sum, &e->mUnk_f0, &e->mUnk_5c, &e->mUnk_5c);
        }
    }
    func_020efa48(a, v);
}

// non-matching: the loop body keeps the table base and the vector pointers in other registers (84 words)
void func_020eea6c(Unk020eda5c *a) {
    const s16 *v1;
    s32 c;
    s32 x;
    s32 y;
    s32 k;
    s32 m;
    s32 d0;
    s32 d1;
    s32 d2;
    s32 d3;
    s32 i;
    s32 n;
    Vec3 *p0;
    Vec3 *p1;
    Vec3 *p2;
    Unk020f41c4_A *e;

    v1 = data_0215d4b4;
    c = a->mUnk_178;
    p0 = &a->mUnk_02c.mUnk_00;
    p1 = &a->mUnk_02c.mUnk_18;
    p2 = &a->mUnk_180;
    i = a->mUnk_174 >> 4;
    n = a->mUnk_020;
    y = (s32) (((s64) c * v1[i * 2 + 1]) >> 12);
    x = (s32) (((s64) c * v1[i * 2]) >> 12);
    m = (s32) (((s64) x * 0xddb) >> 12);
    k = (s32) (((s64) y * 0xddb) >> 12);
    d0 = (-y >> 1) - m;
    d1 = (-y >> 1) + m;
    d2 = (-x >> 1) + k;
    d3 = (-x >> 1) - k;
    if (n <= 0) {
        return;
    }
    for (i = 0; i < n; i++) {
        e = a->mUnk_014[i];
        if (a->mUnk_18c[i] == 0) {
            func_02147fd8(y, p1, p2, &e->mUnk_50);
            func_02147fd8(x, p0, &e->mUnk_50, &e->mUnk_50);
        } else if (a->mUnk_18c[i] == 1) {
            func_02147fd8(d0, p1, p2, &e->mUnk_50);
            func_02147fd8(d2, p0, &e->mUnk_50, &e->mUnk_50);
        } else {
            func_02147fd8(d1, p1, p2, &e->mUnk_50);
            func_02147fd8(d3, p0, &e->mUnk_50, &e->mUnk_50);
        }
    }
}

void func_020ee9b0(Unk020eda5c *a) {
    u16 i;

    a->mUnk_174 = 0;
    a->mUnk_176 = 0x258;
    a->mUnk_178 = 0;
    a->mUnk_17c = 0;
    for (i = 0; i < 3; i++) {
        a->mUnk_18c[i] = i;
    }
    func_02147fd8((s32) (((s64) a->mUnk_084.z * 0x4333) >> 12), &a->mUnk_02c.mUnk_0c, &a->mUnk_050, &a->mUnk_180);
    func_020eea6c(a);
    if (a->mUnk_028 == (s32) data_021759c0->mUnk_62) {
        func_020719bc(&a->mUnk_00c->mUnk_1fc->mUnk_00, 0xe7);
    }
}

// non-matching: the word at 0x04 uses r1 where the original uses r2 (0x264 vs 0x268 bytes)
void func_020ee748(Unk020eda5c *a) {
    Unk020ee684 *c;
    s32 e;
    s32 n;
    s32 i;
    u32 d;
    Unk020f41c4_A *q;

    c = a->mUnk_00c;
    n = a->mUnk_020;
    d = (u16) (((u32) (a->mUnk_068 * 0x1e)) >> 12);
    if (a->mUnk_010->mState != 0) {
        a->mUnk_176 = 0;
    } else {
        if (a->mUnk_176 < 0x578) {
            a->mUnk_176 = a->mUnk_176 + 0x46;
        }
        if (d >= 0x12c) {
            d = 0x12c;
        }
        a->mUnk_174 = a->mUnk_174 + a->mUnk_176;
        a->mUnk_174 = a->mUnk_174 + (s32) d;
    }
    a->mUnk_17c = a->mUnk_17c + (s32) (((s64) a->mUnk_07c * 0x666) >> 12);
    a->mUnk_17c = a->mUnk_17c - (s32) (((s64) a->mUnk_17c * 0x666) >> 12);
    func_02147fd8((a->mUnk_17c - a->mUnk_07c) + (s32) (((s64) a->mUnk_084.z * 0x4333) >> 12), &a->mUnk_02c.mUnk_0c,
                  &a->mUnk_050, &a->mUnk_180);
    a->mUnk_178 =
        a->mUnk_178 +
        (s32) (((s64) ((a->mUnk_078 + (s32) (((s64) a->mUnk_084.z * 0x3000) >> 12)) - a->mUnk_178) * 0x333) >> 12);
    func_020eea6c(a);
    e = data_0217bc34[a->mUnk_000].mUnk_70;
    for (i = 0; i < n; i++) {
        q = a->mUnk_014[i];
        if (func_020fa0b8(q, e, 0x19a) != 0) {
            func_020f9f08(q, a->mUnk_084.x, a->mUnk_084.y);
        }
    }
    if (a->mUnk_028 == (s32) data_021759c0->mUnk_62) {
        func_020719a8((u32) c->mUnk_1fc, n + 0xe0);
    }
    if ((c->mUnk_1ec & 0x244) != 0x244) {
        return;
    }
    if (a->mUnk_000 == 0xf) {
        return;
    }
    if (a->mUnk_024 != 0) {
        return;
    }
    func_020efa60(a, 1);
}

void func_020ee6e8(Unk020eda5c *a, s32 i, Unk020f41c4_A *v) {
    s32 n;
    u16 h;
    Unk020f41c4_A *t;

    n = a->mUnk_020 - 1;
    if (i != n) {
        t = a->mUnk_014[n];
        h = a->mUnk_18c[n];
        a->mUnk_014[n] = v;
        a->mUnk_18c[n] = a->mUnk_18c[i];
        a->mUnk_014[i] = t;
        a->mUnk_18c[i] = h;
    }
    func_020efa48(a, v);
}

void func_020ee6a8(Unk020eda5c *a) {
    s32 i;

    a->mUnk_000 = 0xf;
    a->mUnk_008 = 5;
    a->mUnk_004 = 0x13;
    for (i = 0; i < 3; i++) {
        a->mUnk_014[i] = NULL;
    }
    a->mUnk_020 = 0;
    a->mUnk_024 = 0;
}

void func_020ee684(Unk020eda5c *a, Unk020ee684 *b) {
    a->mUnk_00c = b;
    a->mUnk_010 = b->mUnk_1fc;
    a->mUnk_028 = b->mUnk_1f8;
    func_020ee6a8(a);
}
