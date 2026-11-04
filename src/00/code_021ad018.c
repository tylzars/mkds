#include "00/code_021ad018.h"
#include "00/code_021ad3b8.h"
#include "00/code_021ad734.h"
#include "00/unk_021b6380.h"
#include "code_0200f5ac.h"

BOOL func_ov000_021ad2b8(u32 *a, s32 b) {
    s32 c;
    s32 d;
    u32 e;

    func_ov000_021ae270();
    func_ov000_021ae2d8();
    if (b == 1) {
        func_ov000_021ae290(0x44, 0x43, data_ov000_021b638c);
    } else {
        func_ov000_021ae290(0x44, 0x43, -1);
    }
    for (d = 0; d < 4; d++) {
        c = func_ov000_021ad3b8(func_ov000_021ad620(b), d);
        if (c != 0) {
            break;
        }
    }
    func_ov000_021ae258();
    if (c == 2) {
        *a = data_ov000_021b63b8 >> 1;
        data_ov000_021b63a0 = data_ov000_021b63b8 * 3 >> 3;
        return TRUE;
    }
    e = data_ov000_021b63a0 >> 1;
    data_ov000_021b63a0 = e;
    *a = e;
    switch (b) {
        case 1:
            if (e < 0x3c) {
                *a = 1;
                data_ov000_021b63a0 = data_ov000_021b63b8 >> 3;
            }
            break;
        case 2:
            if (e < 0x3c) {
                *a = 1;
            }
            break;
    }
    return FALSE;
}

void func_ov000_021ad264(void) {
    u8 *p;
    u8 *r;
    u8 *q;

    func_ov000_021ae270();
    func_ov000_021ae2d8();
    func_ov000_021ae290(0x44, 0x43, data_ov000_021b638c);
    r = (u8 *) &data_ov000_021b6706;
    p = func_ov000_021ad754(r, 7, NULL);
    *p = 0xff;
    p++;
    q = func_ov000_021ad734(0, 0x12c, p, p - r);
    func_ov000_021adbf4(r, q - r);
    func_ov000_021ae258();
}

u8 *func_ov000_021ad240(u8 *a) {
    u32 b;

    b = *a++;
    while (b != 0) {
        if ((b & 0xc0) == 0xc0) {
            return a + 1;
        }
        a += b;
        b = *a++;
    }
    return a;
}

s32 func_ov000_021ad0a4(const char *a, u32 b, s32 c) {
    struct {
        /* 00 */ u32 mUnk_00;
        /* 04 */ u16 mUnk_04;
        /* 06 */ u16 mUnk_06;
        /* 08 */ u16 mUnk_08;
        /* 0a */ u16 mUnk_0a;
        /* 0c */ u16 mUnk_0c;
        /* 0e */ u16 mUnk_0e;
        /* 10 */ u8 mUnk_10[0x30];
    } v;
    u8 *q;
    u8 *p;
    u8 d;
    u8 *r;
    s32 e;
    s32 f;
    u32 g;
    u32 h;
    u16 i;
    u16 j;
    u32 k;

    v.mUnk_04 = (c >> 8) | (c << 8);
    if (b == 1) {
        v.mUnk_06 = 1;
    } else {
        v.mUnk_06 = 0x1001;
    }
    v.mUnk_08 = 0x100;
    v.mUnk_0a = 0;
    v.mUnk_0c = 0;
    v.mUnk_0e = 0;
    p = v.mUnk_10;
    q = p + 1;
    v.mUnk_00 = 0;
    d = *a++;
    while (d != 0) {
        if (d != '.') {
            if (q - (u8 *) &v.mUnk_04 >= 0x3c) {
                return -1;
            }
            *q = d;
            q++;
            v.mUnk_00++;
        } else {
            *p = v.mUnk_00;
            p = q;
            q++;
            v.mUnk_00 = 0;
        }
        d = *a++;
    }
    *p = v.mUnk_00;
    q[0] = 0;
    q[1] = b >> 8;
    q[2] = b;
    q[3] = 0;
    q[4] = 1;
    func_ov000_021adbf4((u8 *) &v.mUnk_04, q + 5 - (u8 *) &v.mUnk_04);
    e = 0;
    g = func_0200f5ac() >> 16;
    f = -1;
    while (data_ov000_021b6388() != 0 && e == 0 && (s32) ((u32) (func_0200f5ac() >> 16) - g) < 0xf) {
        if (func_ov000_021adbac() == 0) {
            func_ov000_021b04d4();
            continue;
        }
        r = func_ov000_021adf78(&v.mUnk_00);
        if (v.mUnk_00 > 0xc && c == (u16) ((*(u16 *) r >> 8) | (*(u16 *) r << 8))) {
            k = r[3] & 0xf;
            if (k == 3) {
                e = f;
            } else if (k == 0) {
                p = r + v.mUnk_00;
                i = r[4] << 8 | r[5];
                r += 12;
                h = i;
                while (h-- != 0) {
                    r = func_ov000_021ad240(r);
                    r += 4;
                }
                while (r < p) {
                    r = func_ov000_021ad240(r);
                    j = r[8] << 8 | r[9];
                    if (b == (u16) (r[0] << 8 | r[1])) {
                        e = (u16) (((u8 *) (r + 6) + j)[0] << 8 | ((u8 *) (r + 6) + j)[1]) << 16 |
                            (u16) (((u8 *) (r + 8) + j)[0] << 8 | ((u8 *) (r + 8) + j)[1]);
                        break;
                    }
                    r += j + 10;
                }
            }
        }
        func_ov000_021adf00(v.mUnk_00);
    }
    return e;
}

u32 func_ov000_021ad07c(const char *a, const char **b) {
    u32 c;
    u8 d;

    *b = a;
    c = 0;
    for (;;) {
        d = *a - '0';
        if (d > 9) {
            break;
        }
        c = c * 10 + d;
        a++;
        *b = a;
    }
    return c;
}

BOOL func_ov000_021ad018(const char *a, u32 *b) {
    const char *p;
    const char *q;
    u32 c;
    u32 d;
    s32 i;

    c = 0;
    i = 0;
    p = a;
    do {
        c <<= 8;
        d = func_ov000_021ad07c(p, &q);
        if (p == q) {
            return FALSE;
        }
        p = q;
        if (d > 0xff || (i != 3 && (p++, *q != '.')) || (i == 3 && *p != 0)) {
            return FALSE;
        }
        c |= d;
        i++;
    } while (i < 4);
    *b = c;
    return TRUE;
}
