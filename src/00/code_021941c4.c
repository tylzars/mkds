#include "00/code_021941c4.h"
#include "00/code_0218d000.h"
#include "00/code_02196590.h"
#include "00/code_021a3690.h"
#include "code_0213442c.h"
#include "code_02135014.h"
#include "code_0213a460.h"
#include "00/code_0218fca8.h"
#include "00/code_0218da04.h"
#include "00/code_02196714.h"

s32 func_ov000_02194590(Unk0218f960 *a, Unk02193f2cNode *b) {
    Unk0218f960_00 *r;
    Unk02193f2cNode *p;
    s32 f;
    s32 t;
    s32 x;
    s32 y;
    s32 z;
    Unk02194934 *e;
    u8 *q;
    u8 *w;

    r = a->mUnk_00;
    switch (b->mUnk_00) {
        case 0x65:
            break;
        case 0x66:
            t = func_ov000_02193d64(a, b);
            if (t != 0) {
                return t;
            }
            break;
        case 0x67:
            t = func_ov000_02196714(a, b->mUnk_08, (u32 *) &x);
            if (t != 0) {
                return t;
            }
            if (x == 4) {
                func_ov000_02196590(a, data_ov000_021b33a0);
                return 3;
            } else if (x == 3) {
                f = 1;
                if (func_ov000_02194934(a, b->mUnk_0c, &e) == 0) {
                    func_ov000_02196590(a, data_ov000_021b33a0);
                    return 3;
                }
                func_ov000_02190b80(a, b->mUnk_28, data_ov000_021b34d0);
                func_ov000_02190b80(a, b->mUnk_28, data_ov000_021b34d8);
                func_ov000_02190b58(a, b->mUnk_28, r->mUnk_1a0);
                func_ov000_02190b80(a, b->mUnk_28, data_ov000_021b34e0);
                func_ov000_02190b80(a, b->mUnk_28, r->mUnk_110);
                func_ov000_02190b80(a, b->mUnk_28, data_ov000_021b34e8);
                func_ov000_02190b80(a, b->mUnk_28, e->mUnk_18);
                func_ov000_02190b80(a, b->mUnk_28, data_ov000_021b34c8);
                for (p = r->mUnk_434; p != 0; p = p->mNext) {
                    if (p->mUnk_0c == b->mUnk_0c && p != b && p->mUnk_00 <= 0x67) {
                        f = 0;
                    }
                }
                if (f != 0) {
                    func_ov000_021a3668(e->mUnk_18);
                    e->mUnk_18 = 0;
                    if (func_ov000_021947e4(e) != 0) {
                        func_ov000_021948f8(a, e);
                    }
                }
                b->mUnk_00 = 0x68;
            }
            break;
        case 0x68:
            t = func_ov000_021907e8(a, b->mUnk_08, (Unk021906e4 *) &b->mUnk_18, (s32 *) &y, (u32 *) &z,
                                    (const s8 *) data_ov000_021b3490);
            if (t != 0) {
                return t;
            }
            w = func_02139f70(b->mUnk_18, data_ov000_021b34c8);
            if (w == 0) {
                break;
            }
            *w = 0;
            q = b->mUnk_18;
            if (func_0213a038(q, data_ov000_021b34f8, 7) == 0) {
                b->mUnk_14 = b->mUnk_14 + 1;
                if (b->mUnk_14 > 1) {
                    func_ov000_02196590(a, data_ov000_021b3508);
                    return 3;
                }
                t = func_ov000_02193e70(a, b);
                if (t != 0) {
                    return t;
                }
            } else if (func_0213a038(q, data_ov000_021b3500, 6) != 0) {
                func_ov000_02196590(a, data_ov000_021b352c);
                return 3;
            }
            b->mUnk_00 = 0x69;
            b->mUnk_20 = 0;
            break;
        default:
            func_0213442c(data_ov000_021b3440, data_ov000_021b333c, 0, 0x9f);
            break;
    }
    if (b->mUnk_30 > 0) {
        t = func_ov000_021906e4(a, b->mUnk_08, (Unk021906e4 *) b->mUnk_28, (u32 *) &z, 1,
                                (const s8 *) data_ov000_021b3490);
        if (z != 0 || t != 0) {
            b->mUnk_00 = 0x6a;
        }
    }
    return 0;
}

s32 func_ov000_021943f0(Unk0218f960 *a, Unk02193f2cNode *b) {
    Unk0218f960_00 *r;
    s32 x;
    s32 y;
    s32 t;
    s32 v;
    u8 *p;
    u8 *q;
    u8 c0[0x10];
    u8 c1[0x1f];
    u8 c2[0x21];
    u8 c3[0x21];
    u8 c4[0x103];

    r = a->mUnk_00;
    if (b->mUnk_00 != 0x68) {
        func_0213442c(data_ov000_021b34a8, data_ov000_021b333c, 0, 0xc1);
    }
    t = func_ov000_021907e8(a, b->mUnk_08, (Unk021906e4 *) &b->mUnk_18, (s32 *) &x, (u32 *) &y,
                            (const s8 *) data_ov000_021b3490);
    if (t != 0) {
        return t;
    }
    if (y != 0) {
        b->mUnk_00 = 0x6a;
        return 0;
    }
    p = func_02139f70(b->mUnk_18, data_ov000_021b34c8);
    if (p != 0) {
        *p = 0;
        q = b->mUnk_18;
        if (func_0213a038(q, data_ov000_021b34d0, 6) == 0) {
            if (func_ov000_021967b4(q, data_ov000_021b34d8, c0, 0x10) == 0) {
                b->mUnk_00 = 0x6a;
                return 0;
            }
            v = func_0213bf90(c0);
            if (func_ov000_021967b4(b->mUnk_18, data_ov000_021b34e0, c1, 0x1f) == 0) {
                b->mUnk_00 = 0x6a;
                return 0;
            }
            if (func_ov000_021967b4(b->mUnk_18, data_ov000_021b34e8, c2, 0x21) == 0) {
                b->mUnk_00 = 0x6a;
                return 0;
            }
            func_02135014(c4, data_ov000_021b34f0, r->mUnk_177, r->mUnk_1a0, v);
            func_ov000_0218e0fc(c4, func_0213a434(c4), c3);
            if (func_0213a074(c2, c3) != 0) {
                func_ov000_02190b80(a, b->mUnk_28, data_ov000_021b34f8);
                func_ov000_02190b80(a, b->mUnk_28, data_ov000_021b34c8);
                b->mUnk_00 = 0x6a;
                return 0;
            }
            func_ov000_02190b80(a, b->mUnk_28, data_ov000_021b3500);
            func_ov000_02190b80(a, b->mUnk_28, data_ov000_021b34c8);
            b->mUnk_00 = 0x69;
            b->mUnk_0c = v;
        } else {
            b->mUnk_00 = 0x6a;
            return 0;
        }
        b->mUnk_20 = 0;
    }
    return 0;
}

s32 func_ov000_02194370(Unk0218f960 *a, Unk02193f2cNode *b) {
    Unk02194370Entry *c;
    s32 y;
    s32 t;

    if (b->mUnk_30 != 0) {
        return 0;
    }
    if (func_ov000_0218dc44(b->mUnk_38) != 0) {
        do {
            c = func_ov000_0218dbf8(b->mUnk_38, 0);
            t = func_ov000_021906e4(a, b->mUnk_08, (Unk021906e4 *) c, (u32 *) &y, 0, (const s8 *) data_ov000_021b3490);
            if (y != 0 || t != 0) {
                b->mUnk_00 = 0x6a;
                return 0;
            }
            if (c->mUnk_0c != c->mUnk_08) {
                break;
            }
            func_ov000_0218da5c(b->mUnk_38, 0);
        } while (func_ov000_0218dc44(b->mUnk_38) != 0);
    }
    return 0;
}

s32 func_ov000_021941c4(Unk0218f960 *a, Unk02193f2cNode *b) {
    Unk0218f960_00 *r;
    Unk021941c4Msg *s;
    s32 x;
    s32 y;
    Unk02190ed4Cb p;
    s32 m;
    s32 n;
    s32 o;
    s32 t;

    r = a->mUnk_00;
    if (b->mUnk_30 != 0) {
        t = func_ov000_021906e4(a, b->mUnk_08, (Unk021906e4 *) b->mUnk_28, (u32 *) &y, 1,
                                (const s8 *) data_ov000_021b3490);
        if (y != 0 || t != 0) {
            b->mUnk_00 = 0x6a;
            return 0;
        }
    }
    if (b->mUnk_30 == 0) {
        t = func_ov000_02194370(a, b);
        if (t != 0) {
            return t;
        }
        if (b->mUnk_00 == 0x6a) {
            return 0;
        }
    }
    t = func_ov000_021907e8(a, b->mUnk_08, (Unk021906e4 *) &b->mUnk_18, (s32 *) &x, (u32 *) &y,
                            (const s8 *) data_ov000_021b3490);
    if (t != 0) {
        b->mUnk_00 = 0x6a;
        return 0;
    }
    if (x > 0) {
        b->mUnk_10 = func_ov000_0218e320(0) + 0x12c;
    }
    do {
        t = func_ov000_02190618(a, (Unk021906e4 *) &b->mUnk_18, &m, &n, &o);
        if (t != 0) {
            return t;
        }
        if (m != 0) {
            switch (n) {
                case 1:
                    p = r->mUnk_1a4[3];
                    if (p.mUnk_00 != 0) {
                        s = func_ov000_021a3690(0xc);
                        if (s == 0) {
                            func_ov000_02196590(a, data_ov000_021b3494);
                            return 1;
                        }
                        s->mUnk_00 = b->mUnk_0c;
                        s->mUnk_08 = (u32) func_ov000_0218e880((u8 *) m);
                        s->mUnk_04 = func_ov000_0218e320(0);
                        t = func_ov000_02190ed4(a, p, s, 0, 2);
                        if (t != 0) {
                            return t;
                        }
                    }
                    break;
                case 0x66:
                    func_ov000_0218fb3c(a, b->mUnk_0c, 0x67, data_ov000_021b34a4);
                    break;
                case 200:
                case 201:
                case 202:
                case 203:
                case 204:
                case 205:
                case 206:
                case 207:
                case 208:
                    func_ov000_02196434(a, b, n, b->mUnk_18, m, o);
                    break;
            }
            func_ov000_021905d4(a, (Unk021906e4 *) &b->mUnk_18);
        }
    } while (m != 0);
    if (y != 0) {
        b->mUnk_00 = 0x6a;
    }
    return 0;
}
