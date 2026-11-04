#include "00/code_021ad3b8.h"
#include "00/code_021a8878.h"
#include "00/code_021ad734.h"
#include "00/unk_021b6380.h"
#include "code_0200f5ac.h"

// non-matching: size 0x264 against 0x268; the original keeps the buffer pointer in r5 and the table pointer in r4
// (swapped here), the code byte in r3, and reads the last byte through the buffer pointer after forming the second
// pointer
s32 func_ov000_021ad3b8(u32 a, s32 b) {
    u32 c;
    s32 d;
    s32 e;
    u32 *m;
    u8 *f;
    u8 *g;
    u8 *h;
    u32 i;
    u32 j;
    s32 k;

    e = (b + 1) * 15;
    c = func_0200f5ac() >> 16;
    d = 0;
    m = data_ov000_021b63d8;
    while (data_ov000_021b6388() != 0 && d == 0 && (s32) ((u32) (func_0200f5ac() >> 16) - c) < e) {
        if (func_ov000_021adbac() == 0) {
            func_ov000_021b04d4();
            continue;
        }
        f = func_ov000_021adf78(&j);
        if (j > 0xf0 && f[0] == 2 &&
            a == ((u16) (*(u16 *) (f + 4) >> 8 | *(u16 *) (f + 4) << 8) << 16 |
                  (u16) (*(u16 *) (f + 6) >> 8 | *(u16 *) (f + 6) << 8)) &&
            func_ov000_021b0014((const u16 *) (f + 0x1c), data_ov000_021b63d0) == 0) {
            d = 3;
            i = (u16) (f[0x10] << 8 | f[0x11]) << 16 | (u16) (f[0x12] << 8 | f[0x13]);
            h = f + j;
            if (f[0xec] == 0x63 && f[0xed] == 0x82 && f[0xee] == 0x53 && f[0xef] == 0x63) {
                g = f + 0xf0;
                while (g < h && (k = *g++) != 0xff) {
                    if (k == 0) {
                        continue;
                    }
                    switch (k) {
                        case 1:
                            data_ov000_021b6380 = (u16) (g[1] << 8 | g[2]) << 16 | (u16) (g[3] << 8 | g[4]);
                            break;
                        case 3:
                            data_ov000_021b639c = (u16) (g[1] << 8 | g[2]) << 16 | (u16) (g[3] << 8 | g[4]);
                            break;
                        case 6:
                            if (g[0] < 8) {
                                m[1] = 0;
                            } else {
                                m[1] = (u16) (g[5] << 8 | g[6]) << 16 | (u16) (g[7] << 8 | g[8]);
                            }
                            m[0] = (u16) (g[1] << 8 | g[2]) << 16 | (u16) (g[3] << 8 | g[4]);
                            break;
                        case 0x33:
                            data_ov000_021b63b8 = (u16) (g[1] << 8 | g[2]) << 16 | (u16) (g[3] << 8 | g[4]);
                            break;
                        case 0x35:
                            if (g[1] == 2) {
                                data_ov000_021b63bc = i;
                                d = 1;
                            } else if (g[1] == 5) {
                                data_ov000_021b63b4 = i;
                                d = 2;
                            }
                            break;
                        case 0x36:
                            data_ov000_021b638c = (u16) (g[1] << 8 | g[2]) << 16 | (u16) (g[3] << 8 | g[4]);
                            break;
                    }
                    g += *g + 1;
                }
            }
        }
        func_ov000_021adf00(j);
    }
    return d;
}

u32 func_ov000_021ad620(s32 a) {
    u32 b;
    u8 *c;
    u8 *d;

    d = data_ov000_021b6706;
    c = func_ov000_021ad754(d, 3, &b);
    if (a == 0) {
        c[0] = 0x32;
        c[1] = 4;
        c[2] = (u16) (data_ov000_021b63bc >> 16) >> 8;
        c[3] = data_ov000_021b63bc >> 16;
        c[4] = (u16) data_ov000_021b63bc >> 8;
        c[5] = data_ov000_021b63bc;
        c[6] = 0x36;
        c[7] = 4;
        c[8] = (u16) (data_ov000_021b638c >> 16) >> 8;
        c[9] = data_ov000_021b638c >> 16;
        c[10] = (u16) data_ov000_021b638c >> 8;
        c[11] = data_ov000_021b638c;
        c += 12;
    }
    *c = 0xff;
    c++;
    c = func_ov000_021ad734(0, 0x12c, c, c - d);
    func_ov000_021adbf4(d, c - d);
    return b;
}

u32 func_ov000_021ad6c0(void) {
    u32 a;
    u8 *b;
    u8 *c;

    c = data_ov000_021b6706;
    b = func_ov000_021ad754(c, 1, &a);
    if (data_ov000_021b63bc != 0) {
        b[0] = 0x32;
        b[1] = 4;
        b[2] = (u16) (data_ov000_021b63bc >> 16) >> 8;
        b[3] = data_ov000_021b63bc >> 16;
        b[4] = (u16) data_ov000_021b63bc >> 8;
        b[5] = data_ov000_021b63bc;
        b += 6;
    }
    *b = 0xff;
    b++;
    b = func_ov000_021ad734(0, 0x12c, b, b - c);
    func_ov000_021adbf4(c, b - c);
    return a;
}
