#include "00/code_02193818.h"
#include "00/code_02196240.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_021906e4.h"
#include "00/code_021965a0.h"
#include "00/code_02196590.h"
#include "00/code_021967b4.h"

#include "00/code_021a3690.h"
#include "code_0213442c.h"
#include "code_02134d30.h"
#include "code_02135014.h"
#include "code_021384cc.h"
#include "00/code_0218e49c.h"
#include "00/unk_021b4000.h"
#include "00/code_0218e368.h"

s32 func_ov000_021964e4(GpConnection *a, Unk021937c0Node *b, const char *c) {
    Unk02190ed4Cb p;
    u32 *m;
    s32 t;

    if (func_ov000_02196870(a, c, 1) != 0) {
        return 4;
    }
    if (strncmp(c, data_ov000_021b39c4, 4) != 0) {
        func_ov000_021965a0(a, 1, data_ov000_021b39cc);
        func_ov000_02190f4c(a, 3, 1);
        return 3;
    }
    p = b->mUnk_0c;
    if (p.mUnk_00 != NULL) {
        m = func_ov000_021a3690(4);
        if (m == NULL) {
            func_ov000_02196590(a, data_ov000_021b39fc);
            return 1;
        }
        m[0] = 0;
        t = func_ov000_02190ed4(a, p, m, b, 0);
        if (t != 0) {
            return t;
        }
    }
    func_ov000_02193818(a, b);
    return 0;
}

s32 func_ov000_02196480(GpConnection *a, s32 *b, Unk02193f2cNode *c, s32 d, const char *e) {
    char f[0x24];
    s32 t;

    if (e == NULL) {
        e = data_ov000_021b39a8;
    }
    t = func_ov000_02193c20(a, c, 0xc9, (Unk02193c20 *) b);
    if (t != 0) {
        return t;
    }
    sprintf(f, data_ov000_021b39ac, 1, d);
    t = func_ov000_02190968(a, (Unk02190988 *) c, f);
    if (t != 0) {
        return t;
    }
    t = func_ov000_02193b88(a, c, e, -1);
    if (t != 0) {
        return t;
    }
    return 0;
}

void func_ov000_02196434(GpConnection *a, Unk02193f2cNode *b, s32 c, const char *d, s32 e, s32 f) {
    char s[0x40];
    s32 v[3];

    if (func_ov000_021967b4(d, data_ov000_021b3994, s, 0x40) != 0) {
        if (sscanf(s, data_ov000_021b399c, &v[0], &v[1], &v[2]) == 3) {
            func_ov000_02196480(a, v, b, 2, NULL);
        }
    }
}

s32 func_ov000_021962d4(GpConnection *a, Unk021937c0Node *b) {
    Unk02196240 *c;
    Unk021a8f84 *h;
    s32 t;

    c = b->mUnk_04;
    c->mUnk_00c = 0x1000;
    c->mUnk_008 = func_ov000_021a3690(c->mUnk_00c + 1);
    if (c->mUnk_008 == NULL) {
        func_ov000_02196590(a, data_ov000_021b35f8);
        return 1;
    }
    c->mUnk_004 = func_ov000_0218e554(2, 1, 0);
    if (c->mUnk_004 == -1) {
        func_ov000_021965a0(a, 5, data_ov000_021b38c0);
        func_ov000_02190f4c(a, 3, 1);
        return 3;
    }
    if (func_ov000_0218e80c(c->mUnk_004, 0) == 0) {
        func_ov000_021965a0(a, 5, data_ov000_021b38e8);
        func_ov000_02190f4c(a, 3, 1);
        return 3;
    }
    h = func_ov000_021a8f84(data_ov000_021b35b8);
    if (h == NULL) {
        func_ov000_021965a0(a, 5, data_ov000_021b391c);
        func_ov000_02190f4c(a, 3, 1);
        return 3;
    }
    {
        Unk021962d4Addr s = {0};

        s.mUnk_01 = 2;
        s.mUnk_04 = h->mUnk_0c[0][0];
        if (s.mUnk_04 == 0) {
            func_0213442c(data_ov000_021b394c, data_ov000_021b3628, NULL, 0x59);
        }
        s.mUnk_02 = 0xcd74;
        if (func_ov000_0218e4b4(c->mUnk_004, &s, 8) == -1) {
            t = func_ov000_0218e368(c->mUnk_004);
            if (t != -6 && t != -0x1a && t != -0x4c) {
                func_ov000_021965a0(a, 5, data_ov000_021b396c);
                func_ov000_02190f4c(a, 3, 1);
                return 3;
            }
        }
    }
    b->mUnk_14 = 1;
    return 0;
}

BOOL func_ov000_02196240(GpConnection *a, Unk02196240 **b, u32 c) {
    Unk02196240 *d;

    d = func_ov000_021a3690(0x144);
    if (d == NULL) {
        func_ov000_02196590(a, data_ov000_021b35f8);
        return TRUE;
    }
    memset(d, 0, 0x144);
    d->mUnk_000 = c;
    d->mUnk_004 = -1;
    d->mUnk_008 = NULL;
    d->mUnk_010 = 0;
    d->mUnk_014 = 0;
    d->mUnk_00c = 0;
    d->mUnk_020 = 0;
    d->mUnk_024 = 0;
    d->mUnk_01c = 0x1000;
    d->mUnk_018 = func_ov000_021a3690(d->mUnk_01c + 1);
    if (d->mUnk_018 == NULL) {
        func_ov000_02196590(a, data_ov000_021b35f8);
        return TRUE;
    }
    d->mUnk_13c = 0;
    d->mUnk_140 = 0;
    *b = d;
    return FALSE;
}
