#include "Main/Unknown/code_0207d814.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0203c5ac.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_0207e000.h"
#include "Main/Unknown/code_0207f000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"

void func_0207d814(struct Unk02089a24 *a, struct Unk020888b4 *b) {
    s32 t;

    a->mUnk_00 = b->mUnk_00->mUnk_2cc->mUnk_10;
    a->mUnk_04 = a->mUnk_00;
    a->mUnk_08 = 0;
    a->mUnk_0c = 0;
    a->mUnk_10 = a->mUnk_00;
    a->mUnk_14 = -1;
    a->mUnk_18 = 0;
    a->mUnk_10 = 0;
    if (data_021759c0->mUnk_00c == 5) {
        b->mUnk_00->mUnk_2a8 = a->mUnk_00;
        return;
    }
    if (data_021759c0->mUnk_00c == 6) {
        t = func_0207fe70((Unk02080b1c *) &b->mUnk_08.mUnk_00);
        b->mUnk_00->mUnk_2a8 = (s32) (((s64) b->mUnk_00->mUnk_2cc->mUnk_10 * t + 0x800) >> 12);
        b->mUnk_00->mUnk_cc = b->mUnk_00->mUnk_2a8;
        b->mUnk_00->mUnk_d0 = b->mUnk_00->mUnk_cc;
        return;
    }
    func_0207e088(a, b);
}

u16 func_0207d8e4(s32 a) {
    u16 v[9];
    u16 *p;
    s32 i;
    Unk0217aebc_128 *r;

    v[0] = data_usa_021658f8[0];
    v[1] = data_usa_021658f8[1];
    v[2] = data_usa_021658f8[2];
    v[3] = data_usa_02165908[0];
    v[4] = data_usa_02165908[1];
    v[5] = data_usa_02165908[2];
    v[6] = data_usa_02165900[0];
    v[7] = data_usa_02165900[1];
    v[8] = data_usa_02165900[2];
    p = &v[6];
    if (a != 0) {
        i = 2;
    } else {
        r = func_0208537c();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        i = (u16) (((r->mUnk_00 >> 32) * 3) >> 32);
    }
    switch (data_021759c0->mUnk_014) {
        case 1:
            p = &v[0];
            break;
        case 2:
            p = &v[3];
            break;
    }
    return p[i];
}

void func_0207d9f0(struct Unk02089a24 *a, struct Unk020888b4 *b, s32 c) {
    s32 n = a->mUnk_14;
    u16 m = b->mUnk_04;
    u16 i;
    BOOL f;
    s32 v;
    s32 d;
    s32 *k = &a->mUnk_1c;
    Unk0217aec0 *r = func_02085424();
    s32 e;
    s32 g;
    const s32 *t;

    a->mUnk_18 = 0;
    f = FALSE;
    v = data_021759c0->mUnk_68[m].mUnk_08.mUnk_00;
    if ((u32) v <= 3) {
        if ((1 << v) & 0xd) {
            f = TRUE;
        }
    }
    if (f != FALSE) {
        return;
    }
    if (k[0] > 2) {
        if (n > 2) {
            k[1] = n;
        }
    }
    if (k[0] == 1) {
        if (data_021759c0->mUnk_08 == 0) {
            if (func_020853a4(m) >= 0x28f) {
                if (func_0203c8dc(m) >= 4) {
                    for (i = 1; i < 4; i++) {
                        d = func_02085408(i);
                        if (d >= 0) {
                            Unk020888b4 *u = func_0207a974(d)->mUnk_310;
                            Unk02089a24 *s = &u->mUnk_e8;

                            if (u->mUnk_154 != 0) {
                                if (s->mUnk_1c == 2) {
                                    k[0] = 2;
                                    k[1] = k[0];
                                    s->mUnk_20 = 1;
                                    s->mUnk_1c = s->mUnk_20;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    e = k[1];
    if (func_0203c880(m) != 0) {
        t = data_usa_021658f4;
    } else {
        t = data_usa_0217ae34;
    }
    v = t[n - 1];
    k[2] = (s32) (((s64) v * r->mUnk_04) >> 12);
    if (func_02085390() != 0) {
        n = r->mUnk_04;
        d = func_02085434();
        if (d >= 0) {
            e = func_020853a4(b->mUnk_04);
            e -= func_020853a4((u16) d);
            if (func_0203c880(b->mUnk_04) != 0) {
                t = data_usa_021658f4;
            } else {
                t = data_usa_0217ae34;
            }
            v = t[func_0203c8dc((s32) (u16) d)];
            if (e > (s32) (((s64) v * n) >> 12)) {
                a->mUnk_10 = (s32) (((s64) a->mUnk_10 * 0xf85) >> 12);
                a->mUnk_18 = 1;
            }
        }
    } else if (n < e) {
        a->mUnk_10 = (s32) (((s64) a->mUnk_10 * 0xe66) >> 12);
        a->mUnk_18 = 1;
    } else if (n == e) {
        if (n == 1) {
            d = func_020854a0((u16) n, data_usa_021658f0);
            if (d >= 0) {
                g = func_020853a4(m);
                g -= func_020853a4((u16) d);
                if (g > func_0207a974(d)->mUnk_310->mUnk_e8.mUnk_24) {
                    a->mUnk_10 = (s32) (((s64) a->mUnk_10 * 0xf85) >> 12);
                    a->mUnk_18 = 1;
                }
            }
        } else {
            g = func_020853a4(m);
            d = func_02085478();
            if (d >= 0) {
                e = func_020853a4((u16) d) - g;
                e -= (s32) (((s64) k[2] * func_0208548c()) >> 12);
                if (e > 0) {
                    a->mUnk_10 = a->mUnk_10 + (s32) (((s64) e * 0x3000) >> 12);
                } else {
                    d = func_02085458(n);
                    if (d >= 0) {
                        Unk0206bcb0 *q = func_0207a974(d);
                        s32 w = r->mUnk_08;

                        if (q->mUnk_310->mUnk_e8.mUnk_04 > (s32) (((s64) w * 0xcd0) >> 12)) {
                            e = func_020853a4((u16) d) - g;
                            if (e < (s32) (((s64) k[2] * func_0208548c()) >> 12)) {
                                a->mUnk_10 = (s32) (((s64) a->mUnk_10 * 0xfae) >> 12);
                                a->mUnk_18 = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    if (a->mUnk_18 == 0) {
        a->mUnk_10 = (s32) (((s64) a->mUnk_10 * 0x10cd) >> 12);
        if (a->mUnk_10 >= c) {
            a->mUnk_10 = c;
        }
    } else {
        if (a->mUnk_10 < r->mUnk_08) {
            a->mUnk_10 = r->mUnk_08;
        }
    }
}

void func_0207de84(struct Unk02089a24 *a, struct Unk020888b4 *b) {
    BOOL f;
    s32 v;
    s32 t;
    s32 s;
    Unk0206bcb0 *q;

    if (b->mUnk_04 == func_02061f90()) {
        a->mUnk_08 = 0;
        a->mUnk_18 = 0;
        f = FALSE;
        v = data_021759c0->mUnk_68[b->mUnk_04].mUnk_08.mUnk_00;
        if ((u32) v <= 3) {
            if ((1 << v) & 0xd) {
                f = TRUE;
            }
        }
        if (f != FALSE) {
            a->mUnk_14 = func_0203c8dc(b->mUnk_04);
        } else {
            a->mUnk_14 = func_020854c0(b->mUnk_04);
        }
        a->mUnk_08 = func_02085424()->mUnk_00;
        if (func_02085390() != 0) {
            a->mUnk_08 = a->mUnk_08 >> 1;
        }
        q = b->mUnk_00;
        t = a->mUnk_08 + q->mUnk_cc;
        if (b->mUnk_a8 == 2) {
            t = 0x3000;
        }
        if (t > 0xa000) {
            t = 0xa000;
        }
        if (q->mUnk_4c & 0x8000000) {
            t = (s32) (((s64) t * 0xb33 + 0x800) >> 12);
        }
        if (b->mUnk_90 == 0) {
            a->mUnk_0c = t;
            if (b->mUnk_70 > 0x5000) {
                s = (s32) (((s64) (b->mUnk_70 - 0x5000) * 0x5b) >> 12);
                if (s > 0x1000) {
                    s = 0x1000;
                }
                a->mUnk_0c = (s32) (((s64) (0x1000 - (s32) (((s64) s * 0x668) >> 12)) * 0xa000) >> 12);
            }
            func_0207d9f0(a, b, t);
            t = a->mUnk_10;
        }
        if (a->mUnk_0c < t) {
            t = a->mUnk_0c;
        }
        if (t > 0xa000) {
            t = 0xa000;
        }
        a->mUnk_04 = t;
    }
    q = b->mUnk_00;
    if (q->mUnk_180 != 0) {
        return;
    }
    if (q->mUnk_4c & 0x10000000) {
        return;
    }
    if ((q->mUnk_48 & 0x10000020) == 0) {
        q->mUnk_cc = a->mUnk_04;
    }
}

void func_0207e088(struct Unk02089a24 *a, struct Unk020888b4 *b) {
    BOOL f = FALSE;
    s32 v;
    BOOL r6;
    s32 r5;
    s32 r4;
    s32 t;
    Unk0217aebc_128 *r;
    Unk020888b4 *u;

    v = data_021759c0->mUnk_68[b->mUnk_04].mUnk_08.mUnk_00;
    if ((u32) v <= 3) {
        if ((1 << v) & 0xd) {
            f = TRUE;
        }
    }
    if (f != FALSE) {
        return;
    }
    r6 = FALSE;
    r = func_0208537c();
    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    r4 = (s16) (u16) (r->mUnk_00 >> 52);
    r5 = func_020853f0(b->mUnk_04);
    u = func_0207a974(b->mUnk_04)->mUnk_310;
    if (u->mUnk_154 != 0) {
        r5 = r6;
    }
    t = data_usa_0217ae30[r5];
    if (r4 < t || t >= 0x1000) {
        a->mUnk_2c = 1;
        a->mUnk_30 = func_0207d8e4(u->mUnk_154);
        r6 = TRUE;
    }
    if (r6 != FALSE) {
        return;
    }
    t = data_usa_0217ae2c[r5];
    if (r4 >= t) {
        if (!((float) t >= 1.0f)) {
            return;
        }
    }
    a->mUnk_28 = 1;
}
