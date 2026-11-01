#include "00/code_02192e04.h"
#include "00/code_02190000.h"
#include "00/code_02193818.h"
#include "00/code_021935bc.h"
#include "00/code_021965a0.h"
#include "00/code_02196590.h"
#include "00/code_02196914.h"
#include "00/code_021a3668.h"
#include "00/code_021a3690.h"
#include "00/unk_021b2000.h"
#include "00/unk_021b3000.h"
#include "code_02139f70.h"
#include "code_0213442c.h"
#include "code_0213a460.h"
#include "00/code_0219218c.h"

void func_ov000_0219338c(Unk02192e04 *param_1, Unk0219338c *param_2) {
    if (param_1->mUnk_00 != 0) {
        func_ov000_02196914(param_2->mUnk_008, param_1->mUnk_00, 0x1f);
    } else {
        param_2->mUnk_008[0] = 0;
    }
    if (param_1->mUnk_04 != 0) {
        func_ov000_02196914(param_2->mUnk_027, param_1->mUnk_04, 0x15);
    } else {
        param_2->mUnk_027[0] = 0;
    }
    if (param_1->mUnk_08 != 0) {
        func_ov000_02196914(param_2->mUnk_03c, param_1->mUnk_08, 0x33);
    } else {
        param_2->mUnk_03c[0] = 0;
    }
    if (param_1->mUnk_0c != 0) {
        func_ov000_02196914(param_2->mUnk_06f, param_1->mUnk_0c, 0x1f);
    } else {
        param_2->mUnk_06f[0] = 0;
    }
    if (param_1->mUnk_10 != 0) {
        func_ov000_02196914(param_2->mUnk_08e, param_1->mUnk_10, 0x1f);
    } else {
        param_2->mUnk_08e[0] = 0;
    }
    if (param_1->mUnk_14 != 0) {
        func_ov000_02196914(param_2->mUnk_0ad, param_1->mUnk_14, 0x4c);
    } else {
        param_2->mUnk_0ad[0] = 0;
    }
    param_2->mUnk_0fc = param_1->mUnk_18;
    func_ov000_02196914(param_2->mUnk_100, param_1->mUnk_1c, 0xb);
    func_ov000_02196914(param_2->mUnk_10b, param_1->mUnk_27, 3);
    param_2->mUnk_110 = param_1->mUnk_2c;
    param_2->mUnk_114 = param_1->mUnk_30;
    if (param_1->mUnk_34 != 0) {
        func_ov000_02196914(param_2->mUnk_118, param_1->mUnk_34, 0x80);
    } else {
        param_2->mUnk_118[0] = 0;
    }
    param_2->mUnk_198 = param_1->mUnk_b4;
    param_2->mUnk_19c = param_1->mUnk_b8;
    param_2->mUnk_1a0 = param_1->mUnk_bc;
    param_2->mUnk_1a4 = param_1->mUnk_c0;
    param_2->mUnk_1a8 = param_1->mUnk_c4;
    if (param_1->mUnk_c8 != 0) {
        func_ov000_02196914(param_2->mUnk_1ac, param_1->mUnk_c8, 0x33);
    } else {
        param_2->mUnk_1ac[0] = 0;
    }
    param_2->mUnk_0fc = param_1->mUnk_18;
    param_2->mUnk_110 = param_1->mUnk_2c;
    param_2->mUnk_114 = param_1->mUnk_30;
    param_2->mUnk_198 = param_1->mUnk_b4;
    param_2->mUnk_19c = param_1->mUnk_b8;
    param_2->mUnk_1a0 = param_1->mUnk_bc;
    param_2->mUnk_1a4 = param_1->mUnk_c0;
    param_2->mUnk_1a8 = param_1->mUnk_c4;
    param_2->mUnk_1e0 = param_1->mUnk_cc;
    param_2->mUnk_1e4 = param_1->mUnk_d0;
    param_2->mUnk_1e8 = param_1->mUnk_d4;
    param_2->mUnk_1ec = param_1->mUnk_d8;
    param_2->mUnk_1f0 = param_1->mUnk_dc;
    param_2->mUnk_1f4 = param_1->mUnk_e0;
    param_2->mUnk_1f8 = param_1->mUnk_e4;
    param_2->mUnk_1fc = param_1->mUnk_e8;
    param_2->mUnk_200 = param_1->mUnk_ec;
}

s32 func_ov000_02192e04(Unk0218f960 *param_1, Unk021937c0Node *param_2, const u8 *param_3) {
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

    a = param_1->mUnk_00;
    if (func_ov000_02196870(param_1, param_3, 1) != 0) {
        return 4;
    }
    if (func_0213a038(param_3, data_ov000_021b31b0, 4) != 0) {
        func_ov000_021965a0(param_1, 1, data_ov000_021b31b8);
        func_ov000_02190f4c(param_1, 3, 1);
        return 3;
    }
    if (func_ov000_021967b4(param_3, data_ov000_021b2f80, d, 0x40) == 0) {
        func_ov000_021965a0(param_1, 1, data_ov000_021b31b8);
        func_ov000_02190f4c(param_1, 3, 1);
        return 3;
    }
    n = func_0213bf90(d);
    if (n <= 0) {
        func_0213442c(data_ov000_021b31e8, data_ov000_021b31f8, 0, 0x15a);
    }
    func_ov000_02194934(param_1, n, &b);
    {
        Unk02192e04 k = {0};
        u8 m[0x4c];
        k.mUnk_00 = e;
        k.mUnk_04 = f;
        k.mUnk_08 = g;
        k.mUnk_0c = h;
        k.mUnk_10 = i;
        k.mUnk_14 = m;
        k.mUnk_c8 = j;
        if (func_ov000_021967b4(param_3, data_ov000_021b2fcc, k.mUnk_00, 0x1f) == 0) {
            k.mUnk_00[0] = 0;
        }
        if (func_ov000_021967b4(param_3, data_ov000_021b2fd4, k.mUnk_04, 0x15) == 0) {
            k.mUnk_04[0] = 0;
        }
        if (func_ov000_021967b4(param_3, data_ov000_021b2fe4, k.mUnk_08, 0x33) == 0) {
            k.mUnk_08[0] = 0;
        }
        if (func_ov000_021967b4(param_3, data_ov000_021b2ff8, k.mUnk_0c, 0x1f) == 0) {
            k.mUnk_0c[0] = 0;
        }
        if (func_ov000_021967b4(param_3, data_ov000_021b3004, k.mUnk_10, 0x1f) == 0) {
            k.mUnk_10[0] = 0;
        }
        if (func_ov000_021967b4(param_3, data_ov000_021b3064, d, 0x40) == 0) {
            k.mUnk_18 = -1;
        } else {
            k.mUnk_18 = func_0213bf90(d);
        }
        if (func_ov000_021967b4(param_3, data_ov000_021b3010, k.mUnk_14, 0x4c) == 0) {
            k.mUnk_14[0] = 0;
        }
        if (func_ov000_021967b4(param_3, data_ov000_021b301c, k.mUnk_1c, 0xb) == 0) {
            k.mUnk_1c[0] = 0;
        }
        if (func_ov000_021967b4(param_3, data_ov000_021b3040, k.mUnk_27, 3) == 0) {
            k.mUnk_27[0] = 0;
        }
        if (func_ov000_021967b4(param_3, data_ov000_021b3204, d, 0x40) == 0) {
            k.mUnk_2c = 0;
        } else {
            k.mUnk_2c = func_0213a450(d);
        }
        if (func_ov000_021967b4(param_3, data_ov000_021b320c, d, 0x40) == 0) {
            k.mUnk_30 = 0;
        } else {
            k.mUnk_30 = func_0213a450(d);
        }
        if (func_ov000_021967b4(param_3, data_ov000_021b3214, k.mUnk_34, 0x80) == 0) {
            k.mUnk_34[0] = 0;
        }
        if (func_ov000_021967b4(param_3, data_ov000_021b2fb0, d, 0x40) == 0) {
            k.mUnk_b4 = 0;
            k.mUnk_b8 = 0;
            k.mUnk_bc = 0;
        } else {
            o = func_ov000_021935bc((u32) param_1, func_0213bf90(d), &k.mUnk_b4, &k.mUnk_b8, &k.mUnk_bc);
            if (o != 0) {
                return o;
            }
        }
        if (func_ov000_021967b4(param_3, data_ov000_021b305c, d, 0x40) == 0) {
            k.mUnk_c0 = 0x502;
        } else if ((s8) d[0] == 0x30) {
            k.mUnk_c0 = 0x500;
        } else if ((s8) d[0] == 0x31) {
            k.mUnk_c0 = 0x501;
        } else {
            k.mUnk_c0 = 0x502;
        }
        if (func_ov000_021967b4(param_3, data_ov000_021b321c, d, 0x40) == 0) {
            k.mUnk_c4 = -1;
        } else {
            k.mUnk_c4 = func_0213bf90(d);
        }
        if (func_ov000_021967b4(param_3, data_ov000_021b30a4, k.mUnk_c8, 0x33) == 0) {
            k.mUnk_c8[0] = 0;
        }
        if (func_ov000_021967b4(param_3, data_ov000_021b30ac, d, 0x40) == 0) {
            k.mUnk_cc = 0;
        } else {
            k.mUnk_cc = func_0213bf90(d);
        }
        if (func_ov000_021967b4(param_3, data_ov000_021b30b4, d, 0x40) == 0) {
            k.mUnk_d0 = 0;
        } else {
            k.mUnk_d0 = func_0213bf90(d);
        }
        if (func_ov000_021967b4(param_3, data_ov000_021b30bc, d, 0x40) == 0) {
            k.mUnk_d4 = 0;
        } else {
            k.mUnk_d4 = func_0213bf90(d);
        }
        if (func_ov000_021967b4(param_3, data_ov000_021b30c4, d, 0x40) == 0) {
            k.mUnk_d8 = 0;
        } else {
            k.mUnk_d8 = func_0213bf90(d);
        }
        if (func_ov000_021967b4(param_3, data_ov000_021b30cc, d, 0x40) == 0) {
            k.mUnk_dc = 0;
        } else {
            k.mUnk_dc = func_0213bf90(d);
        }
        if (func_ov000_021967b4(param_3, data_ov000_021b30d4, d, 0x40) == 0) {
            k.mUnk_e0 = 0;
        } else {
            k.mUnk_e0 = func_0213bf90(d);
        }
        if (func_ov000_021967b4(param_3, data_ov000_021b30dc, d, 0x40) == 0) {
            k.mUnk_e4 = 0;
        } else {
            k.mUnk_e4 = func_0213bf90(d);
        }
        if (func_ov000_021967b4(param_3, data_ov000_021b3224, d, 0x40) == 0) {
            k.mUnk_e8 = 0;
        } else {
            k.mUnk_e8 = func_0213bf90(d);
        }
        if (func_ov000_021967b4(param_3, data_ov000_021b322c, d, 0x40) == 0) {
            k.mUnk_ec = 0;
        } else {
            k.mUnk_ec = func_0213bf90(d);
        }
        if (func_ov000_021967b4(param_3, data_ov000_021b3234, d, 0x40) == 0) {
            func_ov000_021965a0(param_1, 1, data_ov000_021b31b8);
            func_ov000_02190f4c(param_1, 3, 1);
            return 3;
        }
        p = a->mUnk_100;
        q = a->mUnk_434;
        while (q != 0) {
            if (q->mUnk_0c == n && q->mUnk_00 == 0x65) {
                if (b == 0) {
                    b = func_ov000_0219496c(param_1, n);
                }
                q->mUnk_00 = 0x66;
                p = 1;
            }
            q = q->mNext;
        }
        if (b == 0 && a->mUnk_100 != 0) {
            b = func_ov000_0219496c(param_1, n);
        }
        if (p != 0) {
            func_ov000_021a3668(b->mUnk_18);
            b->mUnk_18 = 0;
            b->mUnk_18 = func_ov000_0218e880(d);
        }
        if (a->mUnk_100 != 0) {
            func_ov000_0219218c(param_1, (Unk021919ac_node *) b, (Unk021919ac_f0 *) &k);
        }
        c = param_2->mUnk_0c;
        if (c.mUnk_00 != 0) {
            l = func_ov000_021a3690(0x204);
            if (l == 0) {
                func_ov000_02196590(param_1, data_ov000_021b2f58);
                return 1;
            }
            func_ov000_0219338c(&k, l);
            l->mUnk_000 = 0;
            l->mUnk_004 = n;
            o = func_ov000_02190ed4(param_1, c, l, param_2, 0);
            if (o != 0) {
                return o;
            }
        }
        func_ov000_02193818(param_1, param_2);
        return 0;
    }
}
