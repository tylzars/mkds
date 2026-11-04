#include "00/code_02193634.h"
#include "00/code_021948f8.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_021906e4.h"
#include "00/code_021965a0.h"
#include "00/code_021967b4.h"
#include "00/code_02194b9c.h"
#include "00/code_02194ba4.h"
#include "code_0213a460.h"
#include "00/code_02196590.h"
#include "00/code_021a3690.h"
#include "code_0213442c.h"
#include "00/code_02196000.h"
#include "00/code_0218d000.h"
#include "00/unk_021b2000.h"
#include "00/code_0218dd8c.h"

void func_ov000_02194b4c(Unk02194934 *a) {
    if (a->mUnk_08 != NULL) {
        func_ov000_021a3668(a->mUnk_08->mUnk_08);
        a->mUnk_08->mUnk_08 = NULL;
        func_ov000_021a3668(a->mUnk_08->mUnk_0c);
        a->mUnk_08->mUnk_0c = NULL;
        func_ov000_021a3668(a->mUnk_08);
        a->mUnk_08 = NULL;
    }
    func_ov000_0219210c((Unk021919ac_node *) a);
    func_ov000_021a3668(a->mUnk_10);
    a->mUnk_10 = NULL;
    func_ov000_021a3668(a->mUnk_18);
    a->mUnk_18 = NULL;
}

BOOL func_ov000_02194af4(GpConnection *a) {
    GpiConnection *r;

    r = a->mGpiConnection;
    r->mBuddyCount = 0;
    r->mProfileList.mUnk_04 = 0;
    r->mProfileList.mTable =
        func_ov000_0218e0e0(0x1c, 4, func_ov000_02194ba4, func_ov000_02194b9c, func_ov000_02194b4c);
    if (r->mProfileList.mTable != NULL) {
        return TRUE;
    }
    return FALSE;
}

s32 func_ov000_02194a0c(GpConnection *a, Unk021937c0Node *b, const char *c) {
    Unk02190ed4Cb p;
    u32 *m;
    s32 v;
    s32 t;
    char d[0x10];

    if (func_ov000_02196870(a, c, 1) != 0) {
        return 4;
    }
    if (strncmp(c, data_ov000_021b3564, 5) != 0) {
        func_ov000_021965a0(a, 1, data_ov000_021b356c);
        func_ov000_02190f4c(a, 3, 1);
        return 3;
    }
    if (func_ov000_021967b4(c, data_ov000_021b359c, d, 0x10) == 0) {
        func_ov000_021965a0(a, 1, data_ov000_021b356c);
        func_ov000_02190f4c(a, 3, 1);
        return 3;
    }
    v = func_0213bf90(d);
    p = b->mUnk_0c;
    if (p.mUnk_00 != NULL) {
        m = func_ov000_021a3690(8);
        if (m == NULL) {
            func_ov000_02196590(a, data_ov000_021b35a8);
            return 1;
        }
        m[1] = v;
        m[0] = 0;
        t = func_ov000_02190ed4(a, p, m, b, 0);
        if (t != 0) {
            return t;
        }
    }
    func_ov000_02193818(a, b);
    return 0;
}

Unk02194934 *func_ov000_0219496c(GpConnection *a, s32 b) {
    Unk0218f960_428 *c;
    Unk02194934 *e;

    c = &a->mGpiConnection->mProfileList;
    if (b <= 0) {
        func_0213442c(data_ov000_021b354c, data_ov000_021b3554, NULL, 0x2b5);
    }
    if (b <= 0) {
        return NULL;
    }
    if (func_ov000_02194934(a, b, &e) != 0) {
        return e;
    }
    {
        Unk02194934 s = {0};

        s.mUnk_00 = b;
        s.mUnk_04 = 0;
        s.mUnk_0c = 0;
        s.mUnk_10 = NULL;
        s.mUnk_18 = NULL;
        s.mUnk_14 = 0;
        func_ov000_0218def0(c->mTable, &s);
    }
    c->mUnk_04 = c->mUnk_04 + 1;
    if (func_ov000_02194934(a, b, &e) != 0) {
        return e;
    }
    return NULL;
}

u32 func_ov000_02194934(GpConnection *a, u32 b, Unk02194934 **c) {
    GpiConnection *r;
    Unk02194934 d;
    Unk02194934 *e;

    r = a->mGpiConnection;
    d.mUnk_00 = b;
    e = func_ov000_0218de28(r->mProfileList.mTable, &d);
    if (c != NULL) {
        *c = e;
    }
    if (e != NULL) {
        return 1;
    }
    return 0;
}

void func_ov000_0219490c(GpConnection *a, u32 b) {
    GpiConnection *r;
    Unk02194934 *e;

    r = a->mGpiConnection;
    if (func_ov000_02194934(a, b, &e) != 0) {
        func_ov000_0218de8c(r->mProfileList.mTable, e);
    }
}

void func_ov000_021948f8(GpConnection *a, Unk02194934 *b) {
    func_ov000_0218de8c(a->mGpiConnection->mProfileList.mTable, b);
}
