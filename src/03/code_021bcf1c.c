#include "03/code_021bcf1c.h"
#include "03/code_021b7bb4.h"
#include "03/code_021bb000.h"
#include "03/code_021bb03c.h"
#include "03/code_021bd000.h"
#include "03/code_021bd884.h"
#include "03/code_021bdaa4.h"
#include "03/code_021bdccc.h"
#include "03/code_021bdcd8.h"
#include "03/code_021be000.h"
#include "03/code_021be4e0.h"
#include "00/code_021a8aa8.h"
#include "code_0200dc3c.h"
#include "code_02134d30.h"
#include "code_02139f70.h"
#include "03/code_021be264.h"

// non-matching: the original keeps the tick base (m) at stack offset 0x40 and the address of data_ov003_021d8bec in r6,
// with the receive buffer address reloaded from the constant words; ours keeps m and the buffer address in registers,
// so the frame is 0x5c bytes against 0x64 and the code is 0x410 bytes against 0x41c
s32 func_ov003_021bcf1c(void) {
    u32 m;
    s32 b;
    s32 a;
    s32 e;
    s32 c;
    u8 *g;
    Unk021bdcd8 k;
    Unk021bdcd8 l;
    u32 h;
    s32 i;
    u32 j;
    b = 0;
    a = -5;
    m = 0;
    e = 0;
    c = 0;
    data_ov003_021d8bec = 1;
    while (c == 0 && data_ov003_021d8be0 == 0) {
        func_0200dc3c(500);
        switch (data_ov003_021d8bec) {
            case 1:
                a = func_ov003_021bdd3c();
                if (a != 1) {
                    c = 1;
                } else {
                    data_ov003_021d8c08 = 3;
                    func_ov003_021bb03c();
                    data_ov003_021d8bec = 2;
                }
                break;
            case 2:
                a = func_ov003_021be264();
                if (a != 1) {
                    c = 1;
                } else {
                    data_ov003_021d8bec = 3;
                }
                break;
            case 3:
                b = func_ov000_021a918c(2, 2, 0);
                if (b < 0) {
                    a = -2;
                    c = 1;
                    break;
                }
                __clear(&k, 8);
                k.mUnk_00 = 8;
                k.mUnk_01 = 2;
                k.mUnk_02 = 0x1e6;
                k.mUnk_04 = 0;
                a = func_ov000_021a916c(b, &k);
                if (a < 0) {
                    a = -2;
                    c = 1;
                } else {
                    data_ov003_021d8bec = 4;
                }
                break;
            case 4:
                if (func_ov003_021bb354() >= data_ov003_021d68b8) {
                    func_ov000_021a9008(b);
                    a = -3;
                    c = 1;
                    break;
                }
                l.mUnk_00 = 8;
                func_ov003_021bd768(data_ov003_021d8c7c, &l);
                if (func_ov000_021a90a0(b, data_ov003_021d9904, 0x800, 4, &l) > 0) {
                    if (func_ov003_021bd998(data_ov003_021d9904, (s32 *) &data_ov003_021d8c20) != 0) {
                        data_ov003_021d68b8 = func_ov003_021bb354() + 30000;
                        data_ov003_021d8bec = 5;
                        data_ov003_021d8c08 = 4;
                        func_ov003_021bb03c();
                    }
                }
                break;
            case 5:
                data_ov003_021d8be4 = func_ov003_021bd894(data_ov003_021d9904);
                func_ov003_021bdccc(b, &l, data_ov003_021d9904, data_ov003_021d8be4);
                m = func_ov003_021bb354();
                data_ov003_021d8bec = 6;
                break;
            case 6:
                if (func_ov003_021bb354() >= data_ov003_021d68b8) {
                    func_ov000_021a9008(b);
                    a = -4;
                    c = 1;
                    break;
                }
                if (func_ov000_021a90a0(b, data_ov003_021d9904, 0x800, 4, &l) > 0 &&
                    func_ov003_021bd938(data_ov003_021d9904, 3, data_ov003_021d9104, data_ov003_021d8c7c) != 0) {
                    g = func_ov003_021bdbd0(data_ov003_021d9104, &h, &i);
                    if (h == 0x101) {
                        j = func_ov003_021bb354();
                        *(Unk021d8ca4 *) data_ov003_021d8ca4 = *(Unk021d8ca4 *) g;
                        func_ov003_021bb378(data_ov003_021d8cac, (const u8 *) &j, 4);
                        e = 0;
                        data_ov003_021d8bec = 7;
                        data_ov003_021d8c08 = 5;
                        data_ov003_021d68b8 = -1;
                        func_ov003_021bb03c();
                    }
                } else if (func_ov003_021bb354() >= m + 1000) {
                    data_ov003_021d8bec = 5;
                }
                break;
            case 7:
                data_ov003_021d8c04 = func_ov003_021bda78(data_ov003_021d9104, 0x102, data_ov003_021d8cac, 8);
                data_ov003_021d8be4 = func_ov003_021bdb0c(data_ov003_021d9904, 4, data_ov003_021d9104,
                                                          data_ov003_021d8c04, data_ov003_021d8c7c);
                func_ov003_021bdccc(b, &l, data_ov003_021d9904, data_ov003_021d8be4);
                m = func_ov003_021bb354();
                __clear(data_ov003_021d8eb0, 0x254);
                data_ov003_021d8bec = 8;
                break;
            case 8:
                if (func_ov000_021a90a0(b, data_ov003_021d9904, 0x800, 4, &l) > 0) {
                    data_ov003_021d8c04 =
                        func_ov003_021bd938(data_ov003_021d9904, 5, data_ov003_021d9104, data_ov003_021d8ca4);
                    if (data_ov003_021d8c04 != 0 && func_ov003_021bd59c(data_ov003_021d9104) != 0) {
                        if (data_ov003_021d8fb0.mUnk_00[0] != 0) {
                            data_ov003_021d8bd0 = 1;
                        } else {
                            data_ov003_021d8bd0 = 0;
                        }
                        e = 0;
                        data_ov003_021d8bec = 9;
                        break;
                    }
                }
                if (func_ov003_021bb354() >= m + 1000) {
                    e++;
                    if (e >= 10) {
                        func_ov000_021a9008(b);
                        a = -2;
                        c = 1;
                    } else {
                        data_ov003_021d8bec = 7;
                    }
                }
                break;
            case 9:
                data_ov003_021d8c04 = func_ov003_021bda78(data_ov003_021d9104, 0x301, &data_ov003_021d8bd0, 1);
                data_ov003_021d8be4 = func_ov003_021bdb0c(data_ov003_021d9904, 6, data_ov003_021d9104,
                                                          data_ov003_021d8c04, data_ov003_021d8ca4);
                if (func_ov003_021be604() != 7) {
                    m = func_ov003_021bb354() + 1000;
                    e = 10;
                    data_ov003_021d8bec = 10;
                } else {
                    func_ov003_021bdccc(b, &l, data_ov003_021d9904, data_ov003_021d8be4);
                    m = func_ov003_021bb354();
                    data_ov003_021d8bec = 10;
                }
                break;
            case 10:
                if (func_ov003_021bb354() >= m + 1000) {
                    e++;
                    if (e >= 10) {
                        c = 1;
                        a = func_ov003_021bd338();
                    } else {
                        data_ov003_021d8bec = 9;
                    }
                }
                break;
        }
    }
    if (b != 0) {
        func_ov000_021a9008(b);
    }
    if (data_ov003_021d8be0 != 0) {
        a = -8;
    }
    return a;
}

// non-matching: the two 0x40-byte struct copies (cases 2 and 3) use r4 as source and r3 as destination (ldmia r4!,
// stmia r3!); the original has the destination in r4 and the source in r3 (ldmia r3!, stmia r4!), 4 words differ
s32 func_ov003_021bd338(void) {
    s32 a;
    s32 b;
    u8 c[0x21];
    u8 *d;
    u8 *e;
    u8 *f;
    a = 1;
    strcpy((char *) data_ov003_021d8dc8.mUnk_00, data_ov003_021d8fb0.mUnk_00);
    switch (data_ov003_021d8fb0.mUnk_2c) {
        case 0:
            data_ov003_021d8dc8.mUnk_20 = 0;
            break;
        case 1:
            if (data_ov003_021d8fb0.mUnk_30 == 0) {
                a = -7;
                break;
            }
            data_ov003_021d8dc8.mUnk_24 = data_ov003_021d8fb0.mUnk_30;
            b = 0;
            d = c;
            e = data_ov003_021d9014;
            f = data_ov003_021d8dc8.mUnk_28[0];
            for (; b < 4; b++) {
                memcpy(d, e, 0x20);
                c[0x20] = 0;
                switch (strlen(d)) {
                    case 0:
                        break;
                    case 5:
                        data_ov003_021d8dc8.mUnk_20 = 1;
                        *(Unk021bd338_5 *) f = *(Unk021bd338_5 *) d;
                        break;
                    case 10:
                        data_ov003_021d8dc8.mUnk_20 = 1;
                        func_ov003_021bd4cc(f, (s8 *) d, 10);
                        break;
                    case 13:
                        data_ov003_021d8dc8.mUnk_20 = 2;
                        *(Unk021bd338_13 *) f = *(Unk021bd338_13 *) d;
                        break;
                    case 26:
                        data_ov003_021d8dc8.mUnk_20 = 2;
                        func_ov003_021bd4cc(f, (s8 *) d, 26);
                        break;
                    case 16:
                        data_ov003_021d8dc8.mUnk_20 = 3;
                        *(Unk021bd338_16 *) f = *(Unk021bd338_16 *) d;
                        break;
                    case 32:
                        data_ov003_021d8dc8.mUnk_20 = 3;
                        func_ov003_021bd4cc(f, (s8 *) d, 32);
                        break;
                    default:
                        a = -7;
                        break;
                }
                e += 0x28;
                f += 0x20;
            }
            break;
        case 2:
            data_ov003_021d8dc8.mUnk_20 = 4;
            data_ov003_021d8dc8.mUnk_a8 = data_ov003_021d90ac.mUnk_00;
            break;
        case 3:
            data_ov003_021d8dc8.mUnk_20 = 5;
            data_ov003_021d8dc8.mUnk_a8 = data_ov003_021d90ac.mUnk_00;
            break;
        default:
            a = -7;
            break;
    }
    return a;
}

s32 func_ov003_021bd4cc(u8 *a, const s8 *b, s32 c) {
    u32 d;
    s32 e;
    d = 0;
    e = 0;
    for (; e < c; e++) {
        switch (b[e]) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                d += b[e] - '0';
                break;
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
                d += b[e] - 'W';
                break;
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
                d += b[e] - '7';
                break;
            default:
                return 0;
        }
        if (e % 2 == 0) {
            d <<= 4;
        } else {
            a[e / 2] = d;
            d = 0;
        }
    }
    return 1;
}

// non-matching: the parse pointer is in r4 and the walk pointer in r5 (original: r5 and r4), and the two four-entry
// loops (0x203, 0x204) use other registers for value, counter and pointer than the original (r1/r3/r2 and r2/r1/r3), 24
// words differ
s32 func_ov003_021bd59c(u8 *p) {
    u8 *c;
    s32 b;
    u8 *a;
    u32 d;
    s32 e;
    u8 *f;
    a = p + 8;
    b = 0;
    c = a + func_ov003_021b7c44_inline(*(u16 *) p);
    f = func_ov003_021bdc08(&a, c, &d, &e);
    while (f != 0) {
        switch (d) {
            case 0x201:
                __clear(&data_ov003_021d8fb0, 0x20);
                memcpy(&data_ov003_021d8fb0, f, e);
                b = 1;
                break;
            case 0x202:
                data_ov003_021d8fb0.mUnk_2c = func_ov003_021b7c44_inline(*(u16 *) f);
                break;
            case 0x203: {
                u32 g;
                s32 h;
                u8 *i;
                g = func_ov003_021b7c44_inline(*(u16 *) f);
                h = 0;
                i = data_ov003_021d8eb0;
                for (; h < 4; h++) {
                    *(u32 *) (i + 0x15c) = g;
                    i += 0x28;
                }
                break;
            }
            case 0x204: {
                u32 g;
                s32 h;
                u8 *i;
                g = func_ov003_021b7c44_inline(*(u16 *) f);
                h = 0;
                i = data_ov003_021d8eb0;
                for (; h < 4; h++) {
                    *(u32 *) (i + 0x160) = g;
                    i += 0x28;
                }
                break;
            }
            case 0x205:
                data_ov003_021d8fb0.mUnk_30 = func_ov003_021b7c44_inline(*(u16 *) f);
                break;
            case 0x206:
            case 0x207:
            case 0x208:
            case 0x209:
                memset(data_ov003_021d9014 + (d - 0x206) * 0x28, 0, 0x20);
                if (data_ov003_021d8fb0.mUnk_5c == 1) {
                    u8 *k;
                    s32 j;
                    k = data_ov003_021d9014 + (d - 0x206) * 0x28;
                    for (j = 0; j < e; j++) {
                        k += func_ov003_021bb2d8(k, *f);
                        f++;
                    }
                } else {
                    memcpy(data_ov003_021d9014 + (d - 0x206) * 0x28, f, e);
                }
                break;
            case 0x20a:
                __clear(&data_ov003_021d90ac, 0x48);
                memcpy(&data_ov003_021d90ac, f, e);
                break;
        }
        f = func_ov003_021bdc08(&a, c, &d, &e);
    }
    return b;
}

// non-matching: the original computes the destination address first (adds r2, r4, #12) and reads the six-byte local
// through a pointer built as sp + 4 + 2; ours loads the source first and addresses the locals from sp, size 0x10c
// against 0x11c
s32 func_ov003_021bd768(u8 *a, void *b) {
    u8 c[6];
    u8 d[6];
    u8 e[0x20];
    u8 f[0x20];
    *(Unk021d6974 *) (a + 0xc) = data_ov003_021d6974;
    *(Unk021d8c54 *) c = data_ov003_021d8c5c;
    c[0] &= 0xfd;
    func_ov003_021bd884(d);
    data_ov003_021d8c54 = *(Unk021d8c54 *) d;
    if (memcmp(c, d, 6) <= 0) {
        *(Unk021d8c54 *) a = *(Unk021d8c54 *) d;
        *(Unk021d8c54 *) (a + 6) = *(Unk021d8c54 *) c;
    } else {
        *(Unk021d8c54 *) a = *(Unk021d8c54 *) c;
        *(Unk021d8c54 *) (a + 6) = *(Unk021d8c54 *) d;
    }
    if (data_ov003_021d68b0 != 0) {
        func_ov003_021bb29c(e, (const s8 *) d);
        func_ov003_021bb29c(f, (const s8 *) c);
    }
    return 1;
}
