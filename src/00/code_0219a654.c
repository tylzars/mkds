#include "00/code_0219a654.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_0218dc44.h"
#include "00/code_0218e3c4.h"
#include "00/unk_021b4000.h"
#include "00/code_0218e368.h"
#include "00/code_0218e49c.h"
#include "00/code_0219b1d4.h"
#include "00/code_0219b1f8.h"
#include "00/code_021a4654.h"
#include "00/code_021a39d8.h"
#include "00/code_021a4784.h"
#include "00/code_021a88a8.h"
#include "00/code_021a8aa8.h"
#include "00/unk_021b5000.h"
#include "code_02134d30.h"
#include "code_02135014.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "00/code_0218e8c4.h"

s32 func_ov000_0219a654(const u8 *a, u32 *b, u16 *c) {
    u8 d[0x100];
    const u8 *e;
    const u8 *f;
    s32 g;
    s32 h;
    u32 i;
    u32 j;
    Unk021a8f84 *k;

    if (a == 0 || *(s8 *) a == 0) {
        i = 0;
        j = 0;
    } else {
        e = func_02139ffc(a, 0x3a);
        if (e == 0) {
            j = 0;
        } else {
            if (e == a) {
                a = 0;
                i = 0;
            } else {
                g = e - a;
                if (g >= 0x100) {
                    func_0213442c(data_ov000_021b3fcc, data_ov000_021b3fec, 0, 0x81);
                }
                func_02134eb8(d, a, g);
                d[g] = 0;
                a = d;
            }
            f = e + 1;
            h = *(s8 *) (e + 1);
            if (h != 0) {
                do {
                    if (h < 0 || h >= 0x80) {
                        g = 0;
                    } else {
                        g = data_0215d284[h] & 8;
                    }
                    if (g == 0) {
                        return 0;
                    }
                    f++;
                    h = *(s8 *) f;
                } while (h != 0);
            }
            g = func_0213bf90(e + 1);
            if (g < 0 || g > 0xffff) {
                return 0;
            }
            j = (u16) g;
        }
        if (a != 0) {
            i = func_ov000_0218e374((u32) a);
            if (i == -1) {
                k = func_ov000_021a8f84(a);
                if (k == 0) {
                    return 0;
                }
                i = **k->mUnk_0c;
            }
        }
    }
    if (b != 0) {
        *b = i;
    }
    if (c != 0) {
        *c = j;
    }
    return 1;
}

u32 func_ov000_0219a760(u32 a, u32 b, u32 c) {
    Unk021b5dfc d;
    u8 *e;

    e = (u8 *) c;
    if (e == 0) {
        data_ov000_021b5284 ^= 1;
        e = data_ov000_021b5288[data_ov000_021b5284];
    }
    if (a != 0) {
        d.mUnk_00 = a;
        if (b != 0) {
            func_02135014(e, data_ov000_021b3ffc, func_ov000_021a8c6c(d), b);
        } else {
            func_02135014(e, data_ov000_021b4004, func_ov000_021a8c6c(d));
        }
    } else if (b != 0) {
        func_02135014(e, data_ov000_021b4008, b);
    } else {
        e[0] = 0;
    }
    return (u32) e;
}

void func_ov000_0219a7e4(u8 *a, s32 b, void *c) {
    Unk0219ade4 d;
    Unk0219aa64 e;
    u32 f;
    u32 g;
    Unk0219b1d4 *h;

    if (func_ov000_0219b0ec(a) != 0) {
        f = a[7];
        if (f == 5 || f == 7) {
            if (b >= 0x14) {
                d = *(Unk0219ade4 *) a;
                g = *(u32 *) d.mUnk_08;
                h = func_ov000_0219b1f8((g << 24 & 0xff000000) |
                                        ((g << 8 & 0xff0000) | ((g >> 24 & 0xff) | (g >> 8 & 0xff00))));
                if (h != 0) {
                    if (f == 5) {
                        func_ov000_0219a9e4(h, &d, c);
                    } else {
                        func_ov000_0219a958(h, &d, c);
                    }
                }
            }
        } else if (b >= 0x15) {
            e = *(Unk0219aa64 *) a;
            g = *(u32 *) e.mUnk_08;
            h = func_ov000_0219b1f8((g << 24 & 0xff000000) |
                                    ((g << 8 & 0xff0000) | ((g >> 24 & 0xff) | (g >> 8 & 0xff00))));
            if (h != 0) {
                func_ov000_0219a8bc(h, &e, c);
            }
        }
    }
}

void func_ov000_0219a8bc(Unk0219b1d4 *a, Unk0219aa64 *b, Unk021a4654 *c) {
    u32 d;

    switch (b->mUnk_07) {
        case 1:
            d = b->mUnk_0c;
            if (d <= 2) {
                a->mUnk_14[d] = 1;
                if (a->mUnk_10 == 0 && a->mUnk_14[1] != 0 && a->mUnk_14[2] != 0 &&
                    (a->mUnk_04 == -1 || a->mUnk_14[0] != 0)) {
                    a->mUnk_10 = 1;
                    a->mUnk_28 = func_ov000_0218e8c4() + 10000;
                    a->mUnk_34(a->mUnk_10, a->mUnk_3c);
                }
            }
            break;
        case 2:
            b->mUnk_07 = 3;
            func_ov000_0219b0b0(a->mDescriptor, c->mUnk_04, c->mUnk_02 >> 8 & 0xff | c->mUnk_02 << 8 & 0xff00, b, 0x15);
            break;
    }
}

void func_ov000_0219a958(Unk0219b1d4 *a, Unk0219ade4 *b, Unk021a4654 *c) {
    if (a->mUnk_10 >= 2) {
        a->mUnk_2c = c->mUnk_04;
        a->mUnk_30 = c->mUnk_02 >> 8 & 0xff | c->mUnk_02 << 8 & 0xff00;
        a->mUnk_32 = 1;
        if (b->mUnk_12 == 0) {
            func_ov000_0219ade4(a);
            return;
        }
        if (a->mUnk_10 == 2) {
            if (a->mUnk_33 == 0) {
                func_ov000_0219ade4(a);
            }
            a->mUnk_10 = 3;
            a->mUnk_28 = func_ov000_0218e8c4() + 5000;
            if (a->mUnk_04 != -1) {
                a->mUnk_38(0, a->mUnk_04, c, a->mUnk_3c);
            }
        } else if (b->mUnk_13 == 0) {
            func_ov000_0219ade4(a);
        }
    }
}

void func_ov000_0219a9e4(Unk0219b1d4 *a, Unk0219ade4 *b, Unk021a4654 *c) {
    s32 d;

    if (b->mUnk_13 == 0) {
        func_ov000_0219aa64(a, c);
    }
    if (a->mUnk_10 < 2) {
        if (b->mUnk_13 != 0) {
            d = 3;
            if (b->mUnk_13 == 1) {
                d = 1;
            } else if (b->mUnk_13 == 2) {
                d = 2;
            }
            a->mUnk_38(d, -1, 0, a->mUnk_3c);
            func_ov000_0219ac50(a->mUnk_08);
        } else {
            a->mUnk_2c = *(u32 *) b->mUnk_0c;
            a->mUnk_30 = *(u16 *) b->mUnk_10 >> 8 & 0xff | *(u16 *) b->mUnk_10 << 8 & 0xff00;
            a->mUnk_20 = 0;
            a->mUnk_10 = 2;
            a->mUnk_34(a->mUnk_10, a->mUnk_3c);
            func_ov000_0219ade4(a);
        }
    }
}

static inline void func_ov000_0219aa64_inline(void *a, const void *b) {
    u8 *p = (u8 *) a;
    const u8 *q = (const u8 *) b;
    p[0] = q[0];
    p[1] = q[1];
    p[2] = q[2];
    p[3] = q[3];
    p[4] = q[4];
    p[5] = q[5];
}

void func_ov000_0219aa64(Unk0219b1d4 *a, Unk021a4654 *b) {
    Unk0219aa64 c;
    u32 d;

    func_ov000_0219aa64_inline(&c.mUnk_00, data_ov000_021b400c);
    c.mUnk_06 = 2;
    c.mUnk_07 = 6;
    c.mUnk_0d = a->mUnk_0c;
    d = a->mUnk_08;
    *(u32 *) c.mUnk_08 = (d << 24 & 0xff000000) | ((d << 8 & 0xff0000) | ((d >> 24 & 0xff) | (d >> 8 & 0xff00)));
    func_ov000_0219b0b0(a->mDescriptor, b->mUnk_04, b->mUnk_02 >> 8 & 0xff | b->mUnk_02 << 8 & 0xff00, &c, 0x15);
}

void func_ov000_0219aaec(void) {
    s32 a;

    if (data_ov000_021b52c4 != 0) {
        for (a = func_ov000_0218dc44((u32 *) data_ov000_021b52c4) - 1; a >= 0; a--) {
            func_ov000_0219ab24(func_ov000_0218dbf8(data_ov000_021b52c4, a));
        }
    }
}

void func_ov000_0219ab24(Unk0219b1d4 *a) {
    Unk021a4654 c;
    s32 d;
    s32 f;
    Unk021a4654 h;

    d = 8;
    if (a->mUnk_10 == 4) {
        func_ov000_0219b130(a);
        return;
    }
    if (a->mDescriptor != -1) {
        do {
            if (func_ov000_0218e668(a->mDescriptor) == 0) {
                break;
            }
            f = func_ov000_0218e438(a->mDescriptor, data_ov000_021b52c8, 0x200, 0, (u8 *) &c, &d);
            if (f == -1) {
                break;
            }
            func_ov000_0219a7e4(data_ov000_021b52c8, f, &c);
            if (a->mUnk_10 == 4) {
                break;
            }
        } while (a->mDescriptor != -1);
    }
    if (a->mUnk_10 == 0 || a->mUnk_10 == 2) {
        if (func_ov000_0218e8c4() > a->mUnk_28) {
            if (a->mUnk_20 > a->mUnk_24) {
                a->mUnk_38(2, -1, 0, a->mUnk_3c);
                func_ov000_0219ac50(a->mUnk_08);
            } else {
                a->mUnk_20 = a->mUnk_20 + 1;
                if (a->mUnk_10 == 0) {
                    func_ov000_0219aeb0(a);
                } else {
                    func_ov000_0219ade4(a);
                }
            }
        }
    }
    if (a->mUnk_10 == 3) {
        if (func_ov000_0218e8c4() > a->mUnk_28) {
            if (a->mUnk_04 == -1) {
                h.mUnk_01 = 2;
                h.mUnk_02 = a->mUnk_30 >> 8 & 0xff | a->mUnk_30 << 8 & 0xff00;
                h.mUnk_04 = a->mUnk_2c;
                a->mUnk_38(0, a->mDescriptor, &h, a->mUnk_3c);
                a->mDescriptor = -1;
            }
            func_ov000_0219ac50(a->mUnk_08);
        }
    }
    if (a->mUnk_10 == 1) {
        if (func_ov000_0218e8c4() > a->mUnk_28) {
            a->mUnk_38(1, -1, 0, a->mUnk_3c);
            func_ov000_0219ac50(a->mUnk_08);
        }
    }
}

void func_ov000_0219ac50(u32 a) {
    Unk0219b1d4 *b;

    b = func_ov000_0219b1f8(a);
    if (b != 0) {
        if (b->mDescriptor != -1) {
            func_ov000_0218e53c(b->mDescriptor);
        }
        b->mDescriptor = -1;
        b->mUnk_10 = 4;
    }
}

s32 func_ov000_0219ac7c(u32 a, u32 b, u32 c, void (*d)(s32 a, void *b), void (*e)(s32 a, s32 b, void *c, void *d),
                        void *f) {
    Unk0219b1d4 *g;

    if (data_ov000_021b4d28 != 1) {
        return 2;
    }
    if (func_ov000_0219ad20() == 0) {
        return 3;
    }
    g = func_ov000_0219b178();
    if (g == 0) {
        return 1;
    }
    g->mUnk_04 = a;
    g->mUnk_0c = c;
    g->mUnk_08 = b;
    g->mUnk_34 = d;
    g->mUnk_38 = e;
    g->mUnk_3c = f;
    g->mDescriptor = func_ov000_0218e554(2, 2, 0);
    g->mUnk_20 = 0;
    g->mUnk_32 = 0;
    g->mUnk_33 = 0;
    g->mUnk_2c = 0;
    g->mUnk_30 = 0;
    g->mUnk_24 = 0;
    if (g->mDescriptor == -1) {
        func_ov000_0219b130(g);
        return 2;
    }
    func_ov000_0219aeb0(g);
    return 0;
}

s32 func_ov000_0219ad20(void) {
    if (data_ov000_021b52c0 == 0) {
        data_ov000_021b52c0 = func_ov000_0219ad88(data_ov000_021b52b8, data_ov000_021b4014);
    }
    if (data_ov000_021b52bc == 0) {
        data_ov000_021b52bc = func_ov000_0219ad88(data_ov000_021b52b4, data_ov000_021b4030);
    }
    if (data_ov000_021b52c0 == 0 || data_ov000_021b52bc == 0) {
        return 0;
    }
    return 1;
}

u32 func_ov000_0219ad88(u8 *a, const u8 *b) {
    u8 c[0x80];

    if (a == 0) {
        func_02135048((char *) c, 0x80, data_ov000_021b404c, data_ov000_021b4d6c, b);
        a = c;
    }
    return func_ov000_0219adb4(a);
}

u32 func_ov000_0219adb4(const u8 *a) {
    u32 b;
    Unk021a8f84 *c;

    b = func_ov000_0218e374((u32) a);
    if (b == -1) {
        c = func_ov000_021a8f84(a);
        if (c == 0) {
            return 0;
        }
        b = **c->mUnk_0c;
    }
    return b;
}

void func_ov000_0219ade4(Unk0219b1d4 *a) {
    Unk0219ade4 b;
    u32 c;
    s32 d;

    func_ov000_0219aa64_inline(&b.mUnk_00, data_ov000_021b400c);
    b.mUnk_06 = 2;
    b.mUnk_07 = 7;
    c = a->mUnk_08;
    *(u32 *) b.mUnk_08 = (c << 24 & 0xff000000) | ((c << 8 & 0xff0000) | ((c >> 24 & 0xff) | (c >> 8 & 0xff00)));
    *(u32 *) b.mUnk_0c = a->mUnk_2c;
    *(u16 *) b.mUnk_10 = a->mUnk_30 >> 8 & 0xff | a->mUnk_30 << 8 & 0xff00;
    b.mUnk_12 = a->mUnk_32;
    b.mUnk_13 = a->mUnk_10 != 2;
    d = a->mUnk_04;
    if (d == -1) {
        d = a->mDescriptor;
    }
    func_ov000_0219b0b0(d, a->mUnk_2c, a->mUnk_30, &b, 0x14);
    a->mUnk_28 = func_ov000_0218e8c4() + 700;
    a->mUnk_24 = 12;
    if (a->mUnk_32 != 0) {
        a->mUnk_33 = 1;
    }
}

// non-matching: the original holds the message address in r4 (add r4, sp, #12 first), spills two values at [sp+4] and
// [sp+8] and has a frame of 0x64; ours addresses it from sp, has no spills and a frame of 0x5c (4 bytes larger code)
void func_ov000_0219aeb0(Unk0219b1d4 *a) {
    Unk0219aeb0 b;
    u32 c;
    u32 d;
    u32 e;
    u16 f;

    b.mUnk_00 = *(Unk021b400c *) data_ov000_021b400c;
    b.mUnk_06 = 2;
    b.mUnk_07 = 0;
    b.mUnk_0d = a->mUnk_0c;
    c = a->mUnk_08;
    *(u32 *) b.mUnk_08 = (c << 24 & 0xff000000) | ((c << 8 & 0xff0000) | ((c >> 24 & 0xff) | (c >> 8 & 0xff00)));
    b.mUnk_0e = 0;
    if (a->mUnk_04 != -1) {
        b.mUnk_0e = 1;
    }
    c = (func_ov000_0219b05c() << 24 & 0xff000000) |
        ((func_ov000_0219b05c() << 8 & 0xff0000) |
         ((func_ov000_0219b05c() >> 24 & 0xff) | (func_ov000_0219b05c() >> 8 & 0xff00)));
    b.mUnk_0f = c >> 24;
    b.mUnk_10 = c >> 16;
    b.mUnk_11 = c >> 8;
    b.mUnk_12 = c;
    b.mUnk_13 = 0;
    b.mUnk_14 = 0;
    func_0213a2d0(b.mUnk_15, data_ov000_021b4d6c);
    d = func_0213a434(data_ov000_021b4d6c) + 0x16;
    if (b.mUnk_0e != 0 && a->mUnk_14[0] == 0) {
        b.mUnk_0c = 0;
        func_ov000_0219b0b0(a->mUnk_04, data_ov000_021b52c0, 0x6cfd, &b, d);
    }
    if (a->mUnk_14[1] == 0) {
        b.mUnk_0c = 1;
        func_ov000_0219b0b0(a->mDescriptor, data_ov000_021b52c0, 0x6cfd, &b, d);
    }
    if (b.mUnk_0e != 0) {
        e = a->mUnk_04;
    } else {
        e = a->mDescriptor;
    }
    f = (func_ov000_0219b038(b.mUnk_0e != 0 ? a->mUnk_04 : a->mDescriptor) >> 8 & 0xff) |
        (func_ov000_0219b038(e) << 8 & 0xff00);
    b.mUnk_13 = f >> 8;
    b.mUnk_14 = f;
    if (a->mUnk_14[2] == 0) {
        b.mUnk_0c = 2;
        func_ov000_0219b0b0(a->mDescriptor, data_ov000_021b52bc, 0x6cfd, &b, d);
    }
    a->mUnk_28 = func_ov000_0218e8c4() + 500;
    a->mUnk_24 = 30;
}

u16 func_ov000_0219b038(u32 a) {
    Unk021a4654 b;
    u32 c;
    s32 d;
    u16 e;

    c = 8;
    d = func_ov000_0218e394(a, &b, &c);
    e = 0;
    if (d != -1) {
        e = b.mUnk_02;
    }
    return e;
}

// non-matching: the original loads the constant 0x0100007f into r7 once before the loop and keeps the result in r6, the
// table pointer in r5 and the offset in r4; ours reloads the constant in the loop and uses r7, r6, r5, r4 for them
u32 func_ov000_0219b05c(void) {
    u32 a;
    u32 *c;
    Unk021a8f84 *d;
    s32 e;

    a = 0;
    d = func_ov000_0218e5e4();
    if (d == 0) {
        return a;
    }
    e = 0;
    while (1) {
        c = *(u32 **) ((u8 *) d->mUnk_0c + e);
        if (c == 0) {
            break;
        }
        if (*c != 0x0100007f) {
            a = *c;
            if (func_ov000_0218e57c(c) != 0) {
                return a;
            }
        }
        e += 4;
    }
    return a;
}

void func_ov000_0219b0b0(u32 a, u32 b, u16 c, void *d, s32 e) {
    Unk021a4654 f;

    f.mUnk_01 = 2;
    f.mUnk_02 = c >> 8 & 0xff | c << 8 & 0xff00;
    f.mUnk_04 = b;
    func_ov000_0218e3e4(a, d, e, 0, &f, 8);
}

s32 func_ov000_0219b0ec(const u8 *a) {
    if (func_02134d30(a, data_ov000_021b400c, 6) == 0) {
        return 1;
    }
    return 0;
}

void func_ov000_0219b110(void) {
    if (data_ov000_021b52c4 != 0) {
        func_ov000_0218dc48((int *) data_ov000_021b52c4);
        data_ov000_021b52c4 = 0;
    }
}

void func_ov000_0219b130(Unk0219b1d4 *a) {
    s32 b;

    for (b = 0; b < func_ov000_0218dc44((u32 *) data_ov000_021b52c4); b++) {
        if (a == func_ov000_0218dbf8(data_ov000_021b52c4, b)) {
            func_ov000_0218da9c((int *) data_ov000_021b52c4, b);
            return;
        }
    }
}

Unk0219b1d4 *func_ov000_0219b178(void) {
    Unk0219b1d4 a = {0};

    if (data_ov000_021b52c4 == 0) {
        data_ov000_021b52c4 = (void *) func_ov000_0218dc94(0x40, 4, (void (*)(void *)) func_ov000_0219b1d4);
    }
    func_ov000_0218dbc0(data_ov000_021b52c4, &a);
    return func_ov000_0218dbf8(data_ov000_021b52c4, func_ov000_0218dc44((u32 *) data_ov000_021b52c4) - 1);
}
