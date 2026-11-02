#include "00/code_02193e70.h"
#include "00/code_02192000.h"
#include "00/code_0218e3c4.h"
#include "00/code_0218eb9c.h"
#include "00/code_0218f15c.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_021947e4.h"

#include "00/code_02193818.h"
#include "00/code_0218d000.h"
#include "00/code_021a3690.h"
#include "code_02134d30.h"
#include "00/code_02194000.h"
#include "00/code_02196000.h"
#include "00/code_0218e49c.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_021a3678.h"
#include "00/code_0218dc44.h"
#include "00/code_021a3668.h"
#include "00/unk_021b3000.h"
#include "code_021382a8.h"
#include "00/code_0218d818.h"
#include "00/code_02196590.h"
#include "code_02135014.h"
#include "code_0213a460.h"
#include "00/code_0218fca8.h"
#include "00/code_021965a0.h"
#include "00/code_021965c8.h"

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
            w = strstr(b->mUnk_18, data_ov000_021b34c8);
            if (w == 0) {
                break;
            }
            *w = 0;
            q = b->mUnk_18;
            if (strncmp(q, data_ov000_021b34f8, 7) == 0) {
                b->mUnk_14 = b->mUnk_14 + 1;
                if (b->mUnk_14 > 1) {
                    func_ov000_02196590(a, data_ov000_021b3508);
                    return 3;
                }
                t = func_ov000_02193e70(a, b);
                if (t != 0) {
                    return t;
                }
            } else if (strncmp(q, data_ov000_021b3500, 6) != 0) {
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
    p = strstr(b->mUnk_18, data_ov000_021b34c8);
    if (p != 0) {
        *p = 0;
        q = b->mUnk_18;
        if (strncmp(q, data_ov000_021b34d0, 6) == 0) {
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
            func_ov000_0218e0fc(c4, strlen(c4), c3);
            if (strcmp(c2, c3) != 0) {
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

s32 func_ov000_02194160(Unk0218f960 *param_1, Unk02193f2cNode *param_2) {
    s32 a = 0;

    if (param_2->mUnk_00 == 0x64) {
        func_0213442c(data_ov000_021b3468, data_ov000_021b333c, 0, 0x1d9);
    }
    if (param_2->mUnk_00 != 0x69) {
        if (param_2->mUnk_04 != 0) {
            a = func_ov000_02194590(param_1, param_2);
        } else {
            a = func_ov000_021943f0(param_1, param_2);
        }
    }
    if (a == 0 && param_2->mUnk_00 == 0x69) {
        a = func_ov000_021941c4(param_1, param_2);
    }
    return a;
}

void func_ov000_02194120(Unk0218f960 *param_1, Unk02193f2cNode *param_2) {
    func_ov000_0218e524(param_2->mUnk_08, 2);
    func_ov000_0218e53c(param_2->mUnk_08);
    func_ov000_021a3668(param_2->mUnk_18);
    param_2->mUnk_18 = 0;
    func_ov000_021a3668(*(void **) param_2->mUnk_28);
    *(void **) param_2->mUnk_28 = 0;
    if (param_2->mUnk_38 != 0) {
        func_ov000_0218dc48(param_2->mUnk_38);
        param_2->mUnk_38 = 0;
    }
    func_ov000_021a3668(param_2);
}

void func_ov000_0219405c(Unk0218f960 *param_1, Unk02193f2cNode *param_2) {
    Unk0218f960_00 *a = param_1->mUnk_00;
    Unk02193f2cNode *b;
    Unk02193f2cNode *c;
    Unk0219405c *d;
    s32 e;

    if (param_2 == 0) {
        func_0213442c(data_ov000_021b332c, data_ov000_021b333c, 0, 0x213);
    }
    b = a->mUnk_434;
    if (b == param_2) {
        a->mUnk_434 = param_2->mNext;
    } else {
        c = b->mNext;
        while (c != param_2) {
            if (c == 0) {
                func_0213442c(data_ov000_021b3440, data_ov000_021b333c, 0, 0x225);
                func_ov000_0219690c(param_1, data_ov000_021b3444);
                return;
            }
            b = c;
            c = c->mNext;
        }
        b->mNext = param_2->mNext;
    }
    if (func_ov000_0218dc44(param_2->mUnk_38) != 0) {
        do {
            d = func_ov000_0218dbf8(param_2->mUnk_38, 0);
            if (d->mUnk_10 < 0x64) {
                func_ov000_0218fbe0(param_1, param_2->mUnk_0c, d->mUnk_10, (const u8 *) (d->mUnk_00 + d->mUnk_14));
            }
            func_ov000_0218da5c(param_2->mUnk_38, 0);
        } while (func_ov000_0218dc44(param_2->mUnk_38) != 0);
    }
    func_ov000_02194120(param_1, param_2);
}

void func_ov000_02193ff4(s32 param_1) {
    func_ov000_0218e7dc(param_1, 0x4000);
    func_ov000_0218e7dc(param_1, 0x8000);
    func_ov000_0218e7dc(param_1, 0x10000);
    func_ov000_0218e7dc(param_1, 0x20000);
    func_ov000_0218e7dc(param_1, 0x40000);
    func_ov000_0218e7ac(param_1, 0x4000);
    func_ov000_0218e7ac(param_1, 0x8000);
    func_ov000_0218e7ac(param_1, 0x10000);
    func_ov000_0218e77c(param_1);
    func_ov000_0218e74c(param_1);
}

s32 func_ov000_02193f50(Unk0218f960 *param_1) {
    Unk0218f960_00 *a = param_1->mUnk_00;
    Unk02193f2cNode *b;
    Unk02193f2cNode *c;
    s32 d;

    if (a->mUnk_204 != -1 && func_ov000_0218e668(a->mUnk_204) != 0) {
        d = func_ov000_0218e478(a->mUnk_204, 0, 0);
        if (d != -1) {
            b = func_ov000_02193eac(param_1, -1, 0);
            if (b != 0) {
                b->mUnk_00 = 0x68;
                b->mUnk_08 = d;
                func_ov000_0218e80c(d, 0);
                func_ov000_02193ff4(b->mUnk_08);
            } else {
                func_ov000_0218e53c(d);
            }
        }
    }
    b = a->mUnk_434;
    while (b != 0) {
        c = b->mNext;
        d = func_ov000_02194160(param_1, b);
        if (b->mUnk_00 == 0x6a || d != 0 || (s32) func_ov000_0218e320(0) > b->mUnk_10) {
            func_ov000_0219405c(param_1, b);
        }
        b = c;
    }
    return 0;
}

Unk02193f2cNode *func_ov000_02193f2c(Unk0218f960 *object, u32 key) {
    Unk02193f2cNode *node = object->mUnk_00->mUnk_434;
    while (node != 0) {
        if (node->mUnk_0c == key && node->mUnk_00 == 0x69) {
            return node;
        }
        node = node->mNext;
    }
    return 0;
}

void func_ov000_02193f18(u32 *param_1) {
    func_ov000_021a3668((void *) (*param_1));
    *param_1 = 0;
    return;
}

Unk02193f2cNode *func_ov000_02193eac(Unk0218f960 *param_1, u32 param_2, u32 param_3) {
    Unk0218f960_00 *a = param_1->mUnk_00;
    Unk02193f2cNode *b = func_ov000_021a3690(0x40);

    if (b == 0) {
        return 0;
    }
    memset(b, 0, 0x40);
    b->mUnk_00 = 0x64;
    b->mUnk_04 = param_3;
    b->mUnk_08 = -1;
    b->mUnk_0c = param_2;
    b->mUnk_10 = func_ov000_0218e320(0) + 0x12c;
    b->mNext = a->mUnk_434;
    b->mUnk_38 = (void *) func_ov000_0218dc94(0x18, 0, (void (*)(void *)) func_ov000_02193f18);
    a->mUnk_434 = b;
    return b;
}

int func_ov000_02193e70(Unk0218f960 *param_1, Unk02193f2cNode *param_2) {
    int v1;
    int v2[2];
    v1 = func_ov000_021938cc(param_1, 2, 0, (int *) (v2), 0, 0, 0);
    if ((v1 == 0) &&
        (v1 = func_ov000_02192330(param_1, (u32) (param_2->mUnk_0c), (u32) (*(u32 *) (v2[0] + 0x18))), v1 == 0)) {
        param_2->mUnk_00 = 0x65;
        v1 = 0;
    }
    return v1;
}
