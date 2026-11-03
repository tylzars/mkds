#include "code_0200fc8c.h"
#include "code_0214e6e4.h"
#include "code_0214e308.h"
#include "code_0214d5b8.h"
#include "code_0200fd1c.h"
#include "Main/Unknown/code_0200f000.h"

u16 data_021803d4;

void func_0214ec18(u32 a, u32 b, u32 c) {
    u16 x = b;
    u16 k = (x & 0x7f00) >> 8;
    u32 n;
    Unk0214ec18 w;
    Unk0214ec18 v;
    Unk0214e334_b *e;

    if (c != 0) {
        data_021803d8.mUnk_34 |= 1 << k;
        if (data_021803d8.mUnk_00 != 0) {
            data_021803d8.mUnk_00(k, 4, 0);
        }
        return;
    }
    if (k == 0x10) {
        data_021803d8.mUnk_0c++;
        if (data_021803d8.mUnk_0c >= data_021803d8.mUnk_14) {
            data_021803d8.mUnk_0c = 0;
        }
        e = data_021803d8.mUnk_10 + data_021803d8.mUnk_0c;
        w.h[0] = *(u16 *) 0x27fffaa;
        w.h[1] = *(u16 *) 0x27fffac;
        e->mUnk_00 = w.f.mUnk_00_0;
        e->mUnk_02 = w.f.mUnk_00_12;
        e->mUnk_04 = (u8) w.f.mUnk_00_24;
        e->mUnk_06 = (u8) w.f.mUnk_00_25;
        if (data_021803d8.mUnk_00 != 0) {
            data_021803d8.mUnk_00(k, 0, data_021803d8.mUnk_0c);
        }
        return;
    }
    if ((b & 0x1000000) == 0) {
        return;
    }
    switch (x & 0xff) {
        case 0:
            switch (k) {
                case 0:
                    v.h[0] = *(u16 *) 0x27fffaa;
                    v.h[1] = *(u16 *) 0x27fffac;
                    data_021803d8.mUnk_32 = 0;
                    data_021803d8.mUnk_04.mUnk_00 = v.f.mUnk_00_0;
                    data_021803d8.mUnk_04.mUnk_02 = v.f.mUnk_00_12;
                    data_021803d8.mUnk_04.mUnk_04 = (u8) v.f.mUnk_00_24;
                    data_021803d8.mUnk_04.mUnk_06 = (u8) v.f.mUnk_00_25;
                    break;
                case 1:
                    data_021803d8.mUnk_32 = 2;
                    break;
                case 2:
                    data_021803d8.mUnk_32 = 0;
                    break;
            }
            data_021803d8.mUnk_36 &= ~(1 << k);
            if (data_021803d8.mUnk_00 != 0) {
                data_021803d8.mUnk_00(k, 0, 0);
            }
            return;
        case 4:
            n = 3;
            break;
        case 2:
            n = 1;
            break;
        case 3:
            n = 2;
            break;
        default:
            goto fail;
    }
    data_021803d8.mUnk_34 |= 1 << k;
    data_021803d8.mUnk_36 &= ~(1 << k);
    if (data_021803d8.mUnk_00 != 0) {
        data_021803d8.mUnk_00(k, n, 0);
    }
    return;
fail:
    func_0200fd1c();
}

void func_0214eb88(void) {
    if (data_021803d4 != 0) {
        return;
    }
    data_021803d4 = 1;
    func_0214d5b8();
    data_021803d8.mUnk_32 = 0;
    data_021803d8.mUnk_36 = 0;
    data_021803d8.mUnk_0c = 0;
    data_021803d8.mUnk_00 = 0;
    data_021803d8.mUnk_10 = 0;
    data_021803d8.mUnk_30 = 0;
    data_021803d8.mUnk_34 = 0;
    while (!func_0214d79c(6, 1)) {
    }
    func_0214d7c4(6, func_0214ec18);
}

u32 func_0214eadc(Unk0214e334 *p) {
    Unk0214eadc *s = (Unk0214eadc *) 0x27ffc80;
    u16 e;
    u16 f;
    u8 d;
    u16 a;
    u16 b;
    u8 c;
    u8 g;
    u8 h;

    a = s->mUnk_58;
    b = s->mUnk_5a;
    c = s->mUnk_5c;
    d = s->mUnk_5d;
    e = s->mUnk_5e;
    f = s->mUnk_60;
    g = s->mUnk_62;
    h = s->mUnk_63;
    if ((a == 0 && e == 0 && b == 0 && f == 0) || func_0214e464(p, a, b, c, d, e, f, g, h) != 0) {
        p->mUnk_00 = 0;
        p->mUnk_02 = 0;
        p->mUnk_04 = 0;
        p->mUnk_06 = 0;
        return 1;
    }
    return 1;
}

void func_0214e994(Unk0214e334 *p) {
    u32 v;
    s16 a;
    s16 b;
    vu32 *den;

    if (p == 0) {
        data_021803d8.mUnk_30 = 0;
        return;
    }
    v = func_0200fca0();
    a = p->mUnk_04;
    if (a != 0) {
        *(vu16 *) 0x4000280 = 0;
        *(vu32 *) 0x4000290 = 0x10000000;
        den = (vu32 *) 0x4000298;
        den[0] = a;
        den[1] = 0;
        data_021803d8.mUnk_18.mUnk_00 = p->mUnk_00;
        data_021803d8.mUnk_18.mUnk_04 = p->mUnk_04;
        while (*(vu16 *) 0x4000280 & 0x8000) {
        }
        data_021803d8.mUnk_18.mUnk_08 = *(vu32 *) 0x40002a0;
    } else {
        data_021803d8.mUnk_18.mUnk_00 = 0;
        data_021803d8.mUnk_18.mUnk_04 = 0;
        data_021803d8.mUnk_18.mUnk_08 = 0;
    }
    b = p->mUnk_06;
    if (b != 0) {
        *(vu16 *) 0x4000280 = 0;
        *(vu32 *) 0x4000290 = 0x10000000;
        den = (vu32 *) 0x4000298;
        den[0] = b;
        den[1] = 0;
        data_021803d8.mUnk_18.mUnk_0c = p->mUnk_02;
        data_021803d8.mUnk_18.mUnk_10 = p->mUnk_06;
        while (*(vu16 *) 0x4000280 & 0x8000) {
        }
        data_021803d8.mUnk_18.mUnk_14 = *(vu32 *) 0x40002a0;
    } else {
        data_021803d8.mUnk_18.mUnk_0c = 0;
        data_021803d8.mUnk_18.mUnk_10 = 0;
        data_021803d8.mUnk_18.mUnk_14 = 0;
    }
    func_0200fcb4(v);
    data_021803d8.mUnk_30 = 1;
}

// non-matching: in the second arm the original loads mUnk_36, stores it, then loads mUnk_34; this loads both first
void func_0214e8f4(void) {
    u32 v = func_0200fca0();
    s32 r = func_0214d6e8(6, 0x3000000, 0);
    u32 ok = r >= 0 ? 1 : 0;

    if (ok == 0) {
        func_0200fcb4(v);
        data_021803d8.mUnk_34 |= 1;
        if (data_021803d8.mUnk_00 != 0) {
            data_021803d8.mUnk_00(0, 4, 0);
        }
    } else {
        data_021803d8.mUnk_36 |= 1;
        data_021803d8.mUnk_34 &= ~1;
        func_0200fcb4(v);
    }
}

// Waits for mUnk_36 bit 0x1 to clear; returns 1 when mUnk_34 bit 0x1 is set, otherwise copies mUnk_04 to out and
// returns 0.
u32 func_0214e89c(Unk0214e334_b *out) {
    func_0214e31c(1);
    if (data_021803d8.mUnk_34 & 1) {
        return 1;
    }
    *out = data_021803d8.mUnk_04;
    return 0;
}

// Stores p, b and n (clearing mUnk_04 of each entry), sends two words through func_0214d6e8 and sets bit 2 of mUnk_34
// (calling mUnk_00 with (1, 4, 0)) when either call returns a negative value, or bit 2 of mUnk_36 otherwise.
void func_0214e788(u32 a, u32 b, Unk0214e334_b *p, u32 n) {
    u32 i;
    u32 s;
    u8 ok;
    void (*f)(u32, u8, u8);

    data_021803d8.mUnk_10 = p;
    data_021803d8.mUnk_0c = 0;
    data_021803d8.mUnk_0e = b;
    data_021803d8.mUnk_14 = n;
    for (i = 0; i < n; i++) {
        data_021803d8.mUnk_10[i].mUnk_04 = 0;
    }
    s = func_0200fca0();
    if (func_0214d6e8(6, (b & 0xff) | 0x2000100, 0) < 0) {
        ok = 0;
    } else {
        if (func_0214d6e8(6, a | 0x1010000, 0) < 0) {
            ok = 0;
        } else {
            ok = 1;
        }
    }
    if ((ok & 0xff) == 0) {
        func_0200fcb4(s);
        data_021803d8.mUnk_34 |= 2;
        f = data_021803d8.mUnk_00;
        if (f != 0) {
            f(1, 4, 0);
        }
    } else {
        data_021803d8.mUnk_36 |= 2;
        data_021803d8.mUnk_34 &= ~2;
        func_0200fcb4(s);
    }
}

// Sends one word through func_0214d6e8 and sets bit 4 of mUnk_34 (calling mUnk_00 with (2, 4, 0)) when the call
// returns a negative value, or bit 4 of mUnk_36 otherwise.
void func_0214e6e4(void) {
    u32 s;
    s32 ok;
    void (*f)(u32, u8, u8);

    s = func_0200fca0();
    ok = func_0214d6e8(6, 0x3000200, 0) >= 0;
    if ((ok & 0xff) == 0) {
        func_0200fcb4(s);
        data_021803d8.mUnk_34 |= 4;
        f = data_021803d8.mUnk_00;
        if (f != 0) {
            f(2, 4, 0);
        }
    } else {
        data_021803d8.mUnk_36 |= 4;
        data_021803d8.mUnk_34 &= ~4;
        func_0200fcb4(s);
    }
}
