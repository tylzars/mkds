#include "00/code_02192d64.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/unk_021b2000.h"
#include "00/unk_021b3000.h"
#include "00/code_021947e4.h"
#include "00/code_02196914.h"
#include "00/code_021965a0.h"
#include "00/code_021a3690.h"
#include "00/code_02196590.h"
#include "code_0213442c.h"
#include "code_02135014.h"
#include "code_02134d30.h"
#include "code_0213a460.h"
#include "00/code_021919ac.h"
#include "00/code_02193818.h"
#include "00/code_021948f8.h"
#include "00/code_0218e0fc.h"
#include "00/code_021967b4.h"
#include "00/code_02191200.h"
#include "00/code_02196240.h"
#include "00/code_02193634.h"
#include "00/code_02190ba0.h"
#include "00/code_02193000.h"
#include "00/code_02196000.h"

#include "00/code_021a3668.h"
#include "00/code_0219218c.h"

u32 func_ov000_021935bc(u32 a, s32 b, u32 *c, u32 *d, u32 *e) {
    int v1;
    u32 v2;
    u32 v3;
    v2 = b >> 0x18 & 0xff;
    v3 = b >> 0x10 & 0xff;
    b = b & ((u32) 0x0000ffffu);
    v1 = func_ov000_02193634(v2, v3, b);
    if (v1 == 0) {
        func_0213442c(data_ov000_021b323c, data_ov000_021b31f8, NULL, 0xb7);
    }
    v1 = func_ov000_02193634(v2, v3, b);
    if (v1 == 0) {
        func_ov000_02196590((u32 *) (u32) (a), data_ov000_021b3254);
        return 2;
    }
    *c = v2;
    *d = v3;
    *e = b;
    return 0;
}

void func_ov000_0219338c(Unk02192e04 *a, Unk0219338c *b) {
    if (a->mUnk_00[0] != NULL) {
        func_ov000_02196914(b->mUnk_008, a->mUnk_00[0], 0x1f);
    } else {
        b->mUnk_008[0] = 0;
    }
    if (a->mUnk_00[1] != NULL) {
        func_ov000_02196914(b->mUnk_027, a->mUnk_00[1], 0x15);
    } else {
        b->mUnk_027[0] = 0;
    }
    if (a->mUnk_00[2] != NULL) {
        func_ov000_02196914(b->mUnk_03c, a->mUnk_00[2], 0x33);
    } else {
        b->mUnk_03c[0] = 0;
    }
    if (a->mUnk_00[3] != NULL) {
        func_ov000_02196914(b->mUnk_06f, a->mUnk_00[3], 0x1f);
    } else {
        b->mUnk_06f[0] = 0;
    }
    if (a->mUnk_00[4] != NULL) {
        func_ov000_02196914(b->mUnk_08e, a->mUnk_00[4], 0x1f);
    } else {
        b->mUnk_08e[0] = 0;
    }
    if (a->mUnk_00[5] != NULL) {
        func_ov000_02196914(b->mUnk_0ad, a->mUnk_00[5], 0x4c);
    } else {
        b->mUnk_0ad[0] = 0;
    }
    b->mUnk_0fc = a->mUnk_18;
    func_ov000_02196914(b->mUnk_100, a->mUnk_1c, 0xb);
    func_ov000_02196914(b->mUnk_10b, a->mUnk_27, 3);
    b->mUnk_110 = a->mUnk_2c;
    b->mUnk_114 = a->mUnk_30;
    if (a->mUnk_34 != NULL) {
        func_ov000_02196914(b->mUnk_118, a->mUnk_34, 0x80);
    } else {
        b->mUnk_118[0] = 0;
    }
    b->mUnk_198 = a->mUnk_b4;
    b->mUnk_19c = a->mUnk_b8;
    b->mUnk_1a0 = a->mUnk_bc;
    b->mUnk_1a4 = a->mUnk_c0;
    b->mUnk_1a8 = a->mUnk_c4;
    if (a->mUnk_c8 != NULL) {
        func_ov000_02196914(b->mUnk_1ac, a->mUnk_c8, 0x33);
    } else {
        b->mUnk_1ac[0] = 0;
    }
    b->mUnk_0fc = a->mUnk_18;
    b->mUnk_110 = a->mUnk_2c;
    b->mUnk_114 = a->mUnk_30;
    b->mUnk_198 = a->mUnk_b4;
    b->mUnk_19c = a->mUnk_b8;
    b->mUnk_1a0 = a->mUnk_bc;
    b->mUnk_1a4 = a->mUnk_c0;
    b->mUnk_1a8 = a->mUnk_c4;
    b->mUnk_1e0 = a->mUnk_cc[0];
    b->mUnk_1e4 = a->mUnk_cc[1];
    b->mUnk_1e8 = a->mUnk_cc[2];
    b->mUnk_1ec = a->mUnk_cc[3];
    b->mUnk_1f0 = a->mUnk_cc[4];
    b->mUnk_1f4 = a->mUnk_cc[5];
    b->mUnk_1f8 = a->mUnk_cc[6];
    b->mUnk_1fc = a->mUnk_cc[7];
    b->mUnk_200 = a->mUnk_cc[8];
}

s32 func_ov000_02192e04(Unk0218f960 *r, Unk021937c0Node *s, const u8 *t) {
    Unk0218f960_00 *a;
    Unk02194934 *b;
    Unk02190ed4Cb c;
    u8 d[0x40];
    u8 e[0x1f];
    u8 f[0x15];
    u8 g[0x33];
    u8 h[0x1f];
    u8 i[0x1f];
    u8 j[0x33];
    Unk0219338c *l;
    Unk02193f2cNode *q;
    s32 n;
    s32 o;
    s32 p;

    a = r->mUnk_00;
    if (func_ov000_02196870(r, t, 1) != 0) {
        return 4;
    }
    if (strncmp(t, data_ov000_021b31b0, 4) != 0) {
        func_ov000_021965a0(r, 1, data_ov000_021b31b8);
        func_ov000_02190f4c(r, 3, 1);
        return 3;
    }
    if (func_ov000_021967b4(t, data_ov000_021b2f80, d, 0x40) == 0) {
        func_ov000_021965a0(r, 1, data_ov000_021b31b8);
        func_ov000_02190f4c(r, 3, 1);
        return 3;
    }
    n = func_0213bf90(d);
    if (n <= 0) {
        func_0213442c(data_ov000_021b31e8, data_ov000_021b31f8, NULL, 0x15a);
    }
    func_ov000_02194934(r, n, &b);
    {
        Unk02192e04 k = {0};
        u8 m[0x4c];
        k.mUnk_00[0] = e;
        k.mUnk_00[1] = f;
        k.mUnk_00[2] = g;
        k.mUnk_00[3] = h;
        k.mUnk_00[4] = i;
        k.mUnk_00[5] = m;
        k.mUnk_c8 = j;
        if (func_ov000_021967b4(t, data_ov000_021b2fcc, k.mUnk_00[0], 0x1f) == 0) {
            k.mUnk_00[0][0] = 0;
        }
        if (func_ov000_021967b4(t, data_ov000_021b2fd4, k.mUnk_00[1], 0x15) == 0) {
            k.mUnk_00[1][0] = 0;
        }
        if (func_ov000_021967b4(t, data_ov000_021b2fe4, k.mUnk_00[2], 0x33) == 0) {
            k.mUnk_00[2][0] = 0;
        }
        if (func_ov000_021967b4(t, data_ov000_021b2ff8, k.mUnk_00[3], 0x1f) == 0) {
            k.mUnk_00[3][0] = 0;
        }
        if (func_ov000_021967b4(t, data_ov000_021b3004, k.mUnk_00[4], 0x1f) == 0) {
            k.mUnk_00[4][0] = 0;
        }
        if (func_ov000_021967b4(t, data_ov000_021b3064, d, 0x40) == 0) {
            k.mUnk_18 = -1;
        } else {
            k.mUnk_18 = func_0213bf90(d);
        }
        if (func_ov000_021967b4(t, data_ov000_021b3010, k.mUnk_00[5], 0x4c) == 0) {
            k.mUnk_00[5][0] = 0;
        }
        if (func_ov000_021967b4(t, data_ov000_021b301c, k.mUnk_1c, 0xb) == 0) {
            k.mUnk_1c[0] = 0;
        }
        if (func_ov000_021967b4(t, data_ov000_021b3040, k.mUnk_27, 3) == 0) {
            k.mUnk_27[0] = 0;
        }
        if (func_ov000_021967b4(t, data_ov000_021b3204, d, 0x40) == 0) {
            k.mUnk_2c = 0;
        } else {
            k.mUnk_2c = atof(d);
        }
        if (func_ov000_021967b4(t, data_ov000_021b320c, d, 0x40) == 0) {
            k.mUnk_30 = 0;
        } else {
            k.mUnk_30 = atof(d);
        }
        if (func_ov000_021967b4(t, data_ov000_021b3214, k.mUnk_34, 0x80) == 0) {
            k.mUnk_34[0] = 0;
        }
        if (func_ov000_021967b4(t, data_ov000_021b2fb0, d, 0x40) == 0) {
            k.mUnk_b4 = 0;
            k.mUnk_b8 = 0;
            k.mUnk_bc = 0;
        } else {
            o = func_ov000_021935bc((u32) r, func_0213bf90(d), &k.mUnk_b4, &k.mUnk_b8, &k.mUnk_bc);
            if (o != 0) {
                return o;
            }
        }
        if (func_ov000_021967b4(t, data_ov000_021b305c, d, 0x40) == 0) {
            k.mUnk_c0 = 0x502;
        } else if ((s8) d[0] == 0x30) {
            k.mUnk_c0 = 0x500;
        } else if ((s8) d[0] == 0x31) {
            k.mUnk_c0 = 0x501;
        } else {
            k.mUnk_c0 = 0x502;
        }
        if (func_ov000_021967b4(t, data_ov000_021b321c, d, 0x40) == 0) {
            k.mUnk_c4 = -1;
        } else {
            k.mUnk_c4 = func_0213bf90(d);
        }
        if (func_ov000_021967b4(t, data_ov000_021b30a4, k.mUnk_c8, 0x33) == 0) {
            k.mUnk_c8[0] = 0;
        }
        if (func_ov000_021967b4(t, data_ov000_021b30ac, d, 0x40) == 0) {
            k.mUnk_cc[0] = 0;
        } else {
            k.mUnk_cc[0] = func_0213bf90(d);
        }
        if (func_ov000_021967b4(t, data_ov000_021b30b4, d, 0x40) == 0) {
            k.mUnk_cc[1] = 0;
        } else {
            k.mUnk_cc[1] = func_0213bf90(d);
        }
        if (func_ov000_021967b4(t, data_ov000_021b30bc, d, 0x40) == 0) {
            k.mUnk_cc[2] = 0;
        } else {
            k.mUnk_cc[2] = func_0213bf90(d);
        }
        if (func_ov000_021967b4(t, data_ov000_021b30c4, d, 0x40) == 0) {
            k.mUnk_cc[3] = 0;
        } else {
            k.mUnk_cc[3] = func_0213bf90(d);
        }
        if (func_ov000_021967b4(t, data_ov000_021b30cc, d, 0x40) == 0) {
            k.mUnk_cc[4] = 0;
        } else {
            k.mUnk_cc[4] = func_0213bf90(d);
        }
        if (func_ov000_021967b4(t, data_ov000_021b30d4, d, 0x40) == 0) {
            k.mUnk_cc[5] = 0;
        } else {
            k.mUnk_cc[5] = func_0213bf90(d);
        }
        if (func_ov000_021967b4(t, data_ov000_021b30dc, d, 0x40) == 0) {
            k.mUnk_cc[6] = 0;
        } else {
            k.mUnk_cc[6] = func_0213bf90(d);
        }
        if (func_ov000_021967b4(t, data_ov000_021b3224, d, 0x40) == 0) {
            k.mUnk_cc[7] = 0;
        } else {
            k.mUnk_cc[7] = func_0213bf90(d);
        }
        if (func_ov000_021967b4(t, data_ov000_021b322c, d, 0x40) == 0) {
            k.mUnk_cc[8] = 0;
        } else {
            k.mUnk_cc[8] = func_0213bf90(d);
        }
        if (func_ov000_021967b4(t, data_ov000_021b3234, d, 0x40) == 0) {
            func_ov000_021965a0(r, 1, data_ov000_021b31b8);
            func_ov000_02190f4c(r, 3, 1);
            return 3;
        }
        p = a->mUnk_100;
        q = a->mUnk_434;
        while (q != NULL) {
            if (q->mUnk_0c == n && q->mUnk_00 == 0x65) {
                if (b == NULL) {
                    b = func_ov000_0219496c(r, n);
                }
                q->mUnk_00 = 0x66;
                p = 1;
            }
            q = q->mNext;
        }
        if (b == NULL && a->mUnk_100 != 0) {
            b = func_ov000_0219496c(r, n);
        }
        if (p != 0) {
            func_ov000_021a3668(b->mUnk_18);
            b->mUnk_18 = NULL;
            b->mUnk_18 = func_ov000_0218e880(d);
        }
        if (a->mUnk_100 != 0) {
            func_ov000_0219218c(r, (Unk021919ac_node *) b, (Unk021919ac_f0 *) &k);
        }
        c = s->mUnk_0c;
        if (c.mUnk_00 != NULL) {
            l = func_ov000_021a3690(0x204);
            if (l == NULL) {
                func_ov000_02196590(r, data_ov000_021b2f58);
                return 1;
            }
            func_ov000_0219338c(&k, l);
            l->mUnk_000 = 0;
            l->mUnk_004 = n;
            o = func_ov000_02190ed4(r, c, l, s, 0);
            if (o != 0) {
                return o;
            }
        }
        func_ov000_02193818(r, s);
        return 0;
    }
}

u32 func_ov000_02192d64(Unk0218f960 *a, Unk021906e4 *b) {
    Unk0218f960_00 *v1;
    v1 = a->mUnk_00;
    if (0 < v1->mUnk_448) {
        func_ov000_02190b80(a, b, data_ov000_021b3184);
        func_ov000_02190b58(a, b, v1->mUnk_198);
        func_ov000_02190b80(a, b, v1->mUnk_440);
        func_ov000_02190b80(a, b, data_ov000_021b2f94);
        v1->mUnk_448 = 0;
    }
    if (0 < v1->mUnk_458) {
        func_ov000_02190b80(a, b, data_ov000_021b319c);
        func_ov000_02190b58(a, b, v1->mUnk_198);
        func_ov000_02190b80(a, b, v1->mUnk_450);
        func_ov000_02190b80(a, b, data_ov000_021b2f94);
        v1->mUnk_458 = 0;
    }
    return 0;
}
