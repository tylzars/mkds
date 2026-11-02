#include "Main/Unknown/code_020aa81c.h"
#include "Main/Unknown/code_020a9ff4.h"
#include "Main/Unknown/code_020ab000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020ab5b4.h"
#include "Main/Unknown/code_020ab604.h"
#include "Main/Unknown/code_020ab660.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02133000.h"
#include "Main/Unknown/unk_02167000.h"
#include "code_0214e308.h"
#include "code_0214cfe4.h"

#pragma thumb on

void func_020ab028(s32 a) {
    if (data_0217b278.mUnk_50 != NULL) {
        if (data_0217b278.mUnk_50(func_020ab1d0(data_0217b278.mUnk_3c), a) != 0) {
            data_0217b278.mUnk_3c = 0;
        }
    }
}

// non-matching: the original stores the zero start of the running offset (sp+4) after the loop guard; here it is
// stored before the guard (1 instruction moved).
void func_020aafa8(Unk0217b278 *a) {
    s32 w;
    s32 h;
    s32 i;
    s32 v1;
    BOOL j0;
    s32 j;
    volatile u16 n;

    h = a->mUnk_2c->mUnk_04->mUnk_02;
    w = a->mUnk_2c->mUnk_04->mUnk_00;
    n = h * w;
    func_0214cfe4(n, data_0217b254.mUnk_0c, data_0217b254.mUnk_14 * (data_0217b254.mUnk_10 * 2));
    for (i = 0, v1 = 0, j0 = FALSE; i < w; i++) {
        for (j = j0; j < h; j++) {
            data_0217b254.mUnk_0c[j + i * data_0217b254.mUnk_14 / 2] =
                (data_0217b254.mUnk_18 << 12) | (j + (data_0217b254.mUnk_1c + v1));
        }
        v1 += h;
    }
}

u16 func_020aaf70(Unk0217b278_1c *a) {
    u16 i;
    const Unk0217b278_1c *p = a;

    for (i = 0; i < p->mUnk_0e; i++) {
        if (a->mUnk_0c + 1 == a->mUnk_00[i].mUnk_06) {
            return i;
        }
    }
    return 0;
}

// non-matching: register allocation only: the original moves the x and y arguments to r3 and r1, keeps the table
// pointer at sp+4 and the count at sp+0 with the index in r7; here y is in r5 and the stack offsets of the two are
// swapped.
Unk0217b278_10 *func_020aaea0(Unk0217b278 *a, s32 b, s32 c) {
    s32 n;
    s32 v1;
    Unk0217b278_10 *e;
    Unk0217b278_10 *v2;
    Unk0217b278_1c *q;
    s32 i;
    s32 v3;

    e = &a->mUnk_00;
    if (e->mUnk_02 > 1 && e->mUnk_03 > 1 && e->mUnk_01 <= c && c < e->mUnk_01 + e->mUnk_03 && e->mUnk_00 <= b &&
        b < e->mUnk_00 + e->mUnk_02) {
        return e;
    }
    e = &a->mUnk_08;
    if (e->mUnk_02 > 1 && e->mUnk_03 > 1 && e->mUnk_01 <= c && c < e->mUnk_01 + e->mUnk_03 && e->mUnk_00 <= b &&
        b < e->mUnk_00 + e->mUnk_02) {
        return e;
    }
    q = a->mUnk_2c;
    v2 = q->mUnk_00;
    n = q->mUnk_0e;
    v1 = data_0217b238;
    v3 = data_0217b234;
    for (i = 0, e = v2; i < n; i++, e++) {
        if (e->mUnk_02 > 1 && e->mUnk_03 > 1 && v1 + e->mUnk_01 <= c && c < v1 + (e->mUnk_01 + e->mUnk_03) &&
            v3 + e->mUnk_00 <= b && b < v3 + (e->mUnk_00 + e->mUnk_02)) {
            return v2 + i;
        }
    }
    return NULL;
}

// non-matching: the two locals at stack offsets 0x0c and 0x10 are swapped, and the original reloads the entry
// index and shifts it at every use instead of stepping an entry pointer.
void func_020aad9c(Unk0217b278 *a) {
    Unk02022aa8 *f;
    Unk0217b278_1c *q;
    Unk0217b278_10 *e;
    Unk02022ce4_08 *u;
    Unk02022c80 *t;
    Unk02023374_24 v1;
    Unk02023374 v2;
    s32 c;
    u32 g;
    s32 v;
    s32 n;
    s32 v3;
    s32 h;
    s32 i;
    s32 k;

    f = data_0217b254.mUnk_00;
    c = f->mUnk_00->mUnk_08->mUnk_01;
    q = a->mUnk_2c;
    func_0214d0a8(q->mUnk_04->mUnk_14, data_0217b254.mUnk_04, q->mUnk_04->mUnk_10);
    func_02023408(&v2, data_0217b254.mUnk_04, q->mUnk_04->mUnk_02, q->mUnk_04->mUnk_00, 4);
    n = func_020aaf70(q);
    k = n;
    if (q->mUnk_0e - n > 0) {
        v3 = 0;
        for (i = 0; i < q->mUnk_0e - k; i++) {
            e = q->mUnk_00 + n;
            g = a->mUnk_30[v3 / 2];
            if (e->mUnk_02 > 1 && e->mUnk_03 > 1) {
                v = func_02022ce4(f, g);
                if (v == 0xffff) {
                    v = f->mUnk_00->mUnk_02;
                }
                t = func_02022c80(f, v);
                v1.mUnk_00 = t;
                u = f->mUnk_00->mUnk_08;
                v1.mUnk_04 = u->mUnk_08 + v * u->mUnk_02;
                h = (e->mUnk_02 - t->mUnk_01) / 2;
                v2.mUnk_14(&v2, f, e->mUnk_00 + h, e->mUnk_01 + (e->mUnk_03 - c) / 2, data_0217b254.mUnk_20, &v1);
            }
            n++;
            v3 += 2;
        }
    }
}

void func_020aab70(Unk0217b278 *a) {
    Unk0217b278_1c *q;
    Unk0217b278_10 *e;
    Unk0217b278_10 *r;

    q = a->mUnk_2c;
    func_0214d0a8(data_0217b254.mUnk_04, data_0217b254.mUnk_08, q->mUnk_04->mUnk_10);
    func_0214d05c_inline((u8 *) data_0217b254.mUnk_08 + (q->mUnk_04->mUnk_10 << 5), 0x20);
    if (a->mUnk_40 != 0) {
        e = q->mUnk_00 + (a->mUnk_40 - 1);
        r = e;
        do {
            func_020aa3a0(data_0217b254.mUnk_08, data_0217b278.mUnk_2c->mUnk_04->mUnk_02 << 3, 8, r->mUnk_00,
                          r->mUnk_01, r->mUnk_00 + r->mUnk_02, r->mUnk_01 + r->mUnk_03);
            r += r->mUnk_04;
        } while (r != e);
    }
    if (a->mUnk_42 != 0) {
        e = q->mUnk_00 + (a->mUnk_42 - 1);
        r = e;
        do {
            func_020aa3a0(data_0217b254.mUnk_08, data_0217b278.mUnk_2c->mUnk_04->mUnk_02 << 3, 8, r->mUnk_00,
                          r->mUnk_01, r->mUnk_00 + r->mUnk_02, r->mUnk_01 + r->mUnk_03);
            r += r->mUnk_04;
        } while (r != e);
    }
    e = a->mUnk_44;
    if (e != NULL && e->mUnk_06 != 0 && e->mUnk_06 <= 0xff && e->mUnk_06 != data_0217b2b8[1] &&
        e->mUnk_06 != data_0217b2b8[0] && e != a->mUnk_10 && e != a->mUnk_18) {
        r = e;
        do {
            func_020aa47c(data_0217b254.mUnk_08, data_0217b278.mUnk_2c->mUnk_04->mUnk_02 << 3, 8, r->mUnk_00,
                          r->mUnk_01, r->mUnk_00 + r->mUnk_02, r->mUnk_01 + r->mUnk_03);
            r += r->mUnk_04;
        } while (r != e);
    }
    e = a->mUnk_18;
    if (e != NULL && e->mUnk_06 != 0 && e->mUnk_06 <= 0xff && e->mUnk_06 != data_0217b2b8[1] &&
        e->mUnk_06 != data_0217b2b8[0]) {
        r = e;
        do {
            func_020aa3a0(data_0217b254.mUnk_08, data_0217b278.mUnk_2c->mUnk_04->mUnk_02 << 3, 8, r->mUnk_00,
                          r->mUnk_01, r->mUnk_00 + r->mUnk_02, r->mUnk_01 + r->mUnk_03);
            r += r->mUnk_04;
        } while (r != e);
    }
    e = a->mUnk_10;
    if (e != NULL && e->mUnk_06 != 0 && e->mUnk_06 <= 0xff && e->mUnk_06 != data_0217b2b8[1] &&
        e->mUnk_06 != data_0217b2b8[0] && e != a->mUnk_18) {
        if (a->mUnk_14 != NULL && e->mUnk_06 == a->mUnk_14->mUnk_06) {
            r = e;
            do {
                func_020aa3a0(data_0217b254.mUnk_08, data_0217b278.mUnk_2c->mUnk_04->mUnk_02 << 3, 8, r->mUnk_00,
                              r->mUnk_01, r->mUnk_00 + r->mUnk_02, r->mUnk_01 + r->mUnk_03);
                r += r->mUnk_04;
            } while (r != e);
            return;
        }
        r = e;
        do {
            func_020aa47c(data_0217b254.mUnk_08, data_0217b278.mUnk_2c->mUnk_04->mUnk_02 << 3, 8, r->mUnk_00,
                          r->mUnk_01, r->mUnk_00 + r->mUnk_02, r->mUnk_01 + r->mUnk_03);
            r += r->mUnk_04;
        } while (r != e);
    }
}

u32 func_020aab40(Unk0217b278 *a) {
    u32 r;
    u32 b;
    Unk0217b278_10 *p;

    r = 0;
    b = 0;
    p = a->mUnk_10;
    if (p != NULL && a->mUnk_14 != NULL) {
        b = 1;
    }
    if (b != 0) {
        if (a->mUnk_14->mUnk_06 == p->mUnk_06) {
            r = 1;
        }
    }
    return r;
}

void func_020aa89c(u16 a, Unk0214e334_b b) {
    u16 h;
    u16 k;
    void (*fn)(Unk0217b278 *);

    func_020ab660(a, b);
    func_020ab528();
    data_0217b278.mUnk_3c = 0;
    data_0217b278.mUnk_3e = 0;
    if (data_0217b278.mUnk_2c != NULL && data_0217b278.mUnk_30 != NULL) {
        if (func_020ab640(data_021679fc[0]) != 0) {
            data_0217b278.mUnk_18 = data_0217b278.mUnk_44;
        } else if (func_020ab640(data_021679fc[1]) != 0) {
            data_0217b278.mUnk_18 = data_0217b278.mUnk_2c->mUnk_00;
        } else {
            data_0217b278.mUnk_18 = NULL;
        }
        k = data_021679fc[0];
        if ((func_020ab4d4() & k) != 0) {
            data_0217b278.mUnk_3c = data_0217b278.mUnk_44->mUnk_06;
            func_020ab028(func_020ab650(k));
        } else {
            k = data_021679fc[1];
            if ((func_020ab4d4() & k) != 0) {
                data_0217b278.mUnk_3c = 1;
                func_020ab028(func_020ab650(k));
            } else {
                k = data_021679fc[2];
                if ((func_020ab4d4() & k) != 0) {
                    fn = data_0217b278.mUnk_2c->mUnk_08;
                    if (fn == func_020ab45c) {
                        h = data_0217b2b8[1];
                        if (h == 0) {
                            data_0217b278.mUnk_3c = 4;
                        } else if (h == 4) {
                            data_0217b278.mUnk_3c = 5;
                        } else if (h == 5) {
                            data_0217b278.mUnk_3c = 5;
                        }
                        func_020ab028(func_020ab650(k));
                    } else if (fn == func_020ab3ec) {
                        data_0217b278.mUnk_3c = 0xffff;
                        func_020ab028(func_020ab650(k));
                    }
                }
            }
        }
        if ((func_020ab4d4() & 0x40) != 0) {
            data_0217b278.mUnk_44 = func_020aa0ec(0x40, data_0217b278.mUnk_44, data_0217b278.mUnk_2c->mUnk_00);
        } else if ((func_020ab4d4() & 0x80) != 0) {
            data_0217b278.mUnk_44 = func_020aa0ec(0x80, data_0217b278.mUnk_44, data_0217b278.mUnk_2c->mUnk_00);
        } else if ((func_020ab4d4() & 0x20) != 0) {
            data_0217b278.mUnk_44 = func_020aa0ec(0x20, data_0217b278.mUnk_44, data_0217b278.mUnk_2c->mUnk_00);
        } else if ((func_020ab4d4() & 0x10) != 0) {
            data_0217b278.mUnk_44 = func_020aa0ec(0x10, data_0217b278.mUnk_44, data_0217b278.mUnk_2c->mUnk_00);
        }
        if (func_020ab634() != 0) {
            data_0217b278.mUnk_14 = func_020aaea0(&data_0217b278, func_020ab61c(), func_020ab610());
        }
        if (func_020ab628() == 1) {
            data_0217b278.mUnk_10 = func_020aaea0(&data_0217b278, func_020ab61c(), func_020ab610());
            if (data_0217b278.mUnk_10 != NULL) {
                data_0217b278.mUnk_3c = data_0217b278.mUnk_10->mUnk_06;
                func_020ab028(1);
            }
        } else if (func_020ab628() == 3) {
            data_0217b278.mUnk_10 = NULL;
        }
        if (func_020aab40(&data_0217b278) != 0) {
            func_020ab5bc(&data_0217b2ac);
            if (func_020ab59c(&data_0217b2ac) != 0) {
                data_0217b278.mUnk_3c = data_0217b278.mUnk_10->mUnk_06;
                func_020ab028(0);
            }
        } else {
            func_020ab5b4(&data_0217b2ac);
        }
        data_0217b278.mUnk_3e = func_020ab1d0(data_0217b278.mUnk_3c);
        if (data_0217b278.mUnk_3e >= 0x20) {
            fn = data_0217b278.mUnk_2c->mUnk_08;
            if (fn == func_020ab45c) {
                if (data_0217b2b8[1] == 4) {
                    data_0217b2b8[1] = 0;
                }
            } else if (fn == func_020ab3ec) {
                data_0217b2b8[1] = 0;
            }
        }
        if (data_0217b278.mUnk_3c != 0 && data_0217b278.mUnk_2c->mUnk_08 != NULL) {
            data_0217b278.mUnk_2c->mUnk_08(&data_0217b278);
        }
        func_020aad9c(&data_0217b278);
        func_020aab70(&data_0217b278);
    }
}

void func_020aa81c(void) {
    Unk0214e334_b a;
    Unk0214e334_b b;

    if (func_020ab604() != 0) {
        do {
            func_0214e8f4();
        } while (func_0214e89c(&a) != 0);
        func_0214e334((Unk0214e334 *) &b, &a);
    } else {
        b.mUnk_04 = 0;
        b.mUnk_06 = 3;
    }
    func_020aa89c(((*(vu16 *) 0x4000130 | *(vu16 *) 0x27fffa8) ^ 0x2fff) & 0x2fff, b);
}

#pragma thumb off
