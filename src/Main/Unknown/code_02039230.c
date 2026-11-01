#include "Main/Unknown/code_02039230.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/unk_02175000.h"

// non-matching: instructions identical; only registers differ: the original keeps the element size in r4 (here ip), the
// byte in r2 (lr), the loop counter in lr (ip), the mask in r3 (r2) and the bit selector in ip (r3).
u32 func_02039230(void) {
    u32 a = data_usa_021755a0.mUnk_14;
    u32 b;
    u32 c;
    u32 d;
    u16 e;
    u16 f;
    if (data_usa_021755a0.mUnk_08 + a > data_usa_021755a0.mUnk_04) {
        return 0;
    }
    if (a == 1) {
        b = *data_usa_021755a0.mUnk_08;
        c = 1;
        f = data_usa_021755a0.mUnk_18;
        d = 1;
        a = 0;
        for (; c < 0x10000; c <<= 1) {
            e = c;
            if (e & f) {
                if (d & b) {
                    a |= e;
                }
                d = (d << 1) & 0xff;
                if (d == 0) {
                    break;
                }
            }
        }
    } else {
        a = *(u16 *) data_usa_021755a0.mUnk_08;
    }
    func_02039378(1, 1);
    return a;
}

// non-matching: instructions identical; only registers differ: the original addresses data_usa_021755a0 through r1 and
// keeps the element size in ip, the position in lr, the end in r2 and the sum in r3 (here r2, lr, r1, r3 and ip), and
// the mask in r3 (lr).
void func_020392c8(u32 a) {
    u32 b = data_usa_021755a0.mUnk_14;
    u8 *c = data_usa_021755a0.mUnk_08;
    u32 d;
    u32 e;
    u16 f;
    u16 g;
    if (c + b > data_usa_021755a0.mUnk_04) {
        return;
    }
    if (b == 1) {
        f = data_usa_021755a0.mUnk_18;
        d = 1;
        e = 1;
        b = 0;
        for (; d < 0x10000; d <<= 1) {
            g = d;
            if (g & f) {
                if (g & a) {
                    b |= e;
                }
                e = (e << 1) & 0xff;
                if (e == 0) {
                    break;
                }
            }
        }
        *c = b;
    } else {
        *(u16 *) c = a;
    }
    func_02039378(1, 1);
    if (data_usa_021755a0.mUnk_08 > data_usa_021755a0.mUnk_0c) {
        data_usa_021755a0.mUnk_0c = data_usa_021755a0.mUnk_08;
    }
}

void func_02039378(u32 a, u32 b) {
    u32 c = data_usa_021755a0.mUnk_14;
    u8 *d;
    u8 *s;
    switch (b) {
        case 2:
            d = data_usa_021755a0.mUnk_0c - a * c;
            break;
        case 0:
            d = data_usa_021755a0.mUnk_00 + a * c;
            break;
        case 1:
            d = data_usa_021755a0.mUnk_08 + a * c;
            break;
    }
    s = data_usa_021755a0.mUnk_00;
    if (d < s) {
        d = s;
    }
    if (data_usa_021755a0.mUnk_04 < d + c) {
        d = s + c * ((u32) (data_usa_021755a0.mUnk_04 - s) / c);
    }
    data_usa_021755a0.mUnk_08 = d;
}

void func_0203940c(void) {
    u32 a;
    if (data_021755dc.mUnk_24 != 0) {
        a = func_02039230();
    } else {
        a = (u16) (((*(vu16 *) 0x4000130 | *(vu16 *) 0x27fffa8) ^ 0x2fff) & 0x2fff);
    }
    func_02039530(a, &data_021755dc);
}

void func_02039478(void) {
    data_021755dc.mUnk_00 = 0;
    data_021755dc.mUnk_02 = 0;
    data_021755dc.mUnk_04 = 0;
    data_021755dc.mUnk_06 = 0;
    data_021755dc.mUnk_08 = 0;
    data_021755dc.mUnk_0a = 0;
    data_021755dc.mUnk_0c = 0;
    data_021755dc.mUnk_0e = 0x14;
    data_021755dc.mUnk_10 = 8;
    data_021755dc.mUnk_12 = 0;
    data_021755dc.mUnk_14 = 0;
    data_021755dc.mUnk_18 = 0;
    data_021755dc.mUnk_20 = 0;
    data_021755dc.mUnk_24 = 0;
}

void func_020394cc(void) {
    data_021755dc.mUnk_00 = 0;
    data_021755dc.mUnk_02 = 0;
    data_021755dc.mUnk_04 = 0;
    data_021755dc.mUnk_06 = 0;
    data_021755dc.mUnk_08 = 0;
    data_021755dc.mUnk_0a = 0;
    data_021755dc.mUnk_0c = 0;
    data_021755dc.mUnk_0e = 0x14;
    data_021755dc.mUnk_10 = 8;
    data_021755dc.mUnk_12 = 0;
    data_021755dc.mUnk_14 = 0;
    data_021755dc.mUnk_18 = 0;
    data_021755dc.mUnk_20 = 0;
    data_021755dc.mUnk_24 = 0;
}
