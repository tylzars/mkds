#include "00/code_0218dd8c.h"
#include "00/code_0218d000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"

#include "code_02134d30.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "00/code_021a3000.h"
#include "00/code_0218dc44.h"
#include "code_021382a8.h"
#include "00/code_0218d818.h"
#include "00/code_0218db48.h"
#include "00/code_021a3668.h"

Unk0218e004 *func_ov000_0218e004(s32 c, s32 d, s32 e, s32 (*f)(void *, s32), s32 (*g)(void *, void *),
                                 void (*h)(void *)) {
    Unk0218e004 *a;
    s32 b;
    if (f == 0) {
        func_0213442c(data_ov000_021b236c, data_ov000_021b2358, 0, 0x38);
    }
    if (g == 0) {
        func_0213442c(data_ov000_021b2374, data_ov000_021b2358, 0, 0x39);
    }
    if (c == 0) {
        func_0213442c(data_ov000_021b237c, data_ov000_021b2358, 0, 0x3a);
    }
    if (d == 0) {
        func_0213442c(data_ov000_021b2388, data_ov000_021b2358, 0, 0x3b);
    }
    a = func_ov000_021a3690(0x14);
    if (a == 0) {
        func_0213442c(data_ov000_021b2364, data_ov000_021b2358, 0, 0x3e);
    }
    a->mUnk_00 = func_ov000_021a3690(d * 4);
    if (a->mUnk_00 == 0) {
        func_0213442c(data_ov000_021b2394, data_ov000_021b2358, 0, 0x41);
    }
    for (b = 0; b < d; b++) {
        a->mUnk_00[b] = func_ov000_0218dc94(c, e, h);
    }
    a->mUnk_04 = d;
    a->mUnk_08 = h;
    a->mUnk_10 = g;
    a->mUnk_0c = f;
    return a;
}

void func_ov000_0218dfb4(void *c) {
    Unk0218e004 *a = c;
    s32 b;
    if (a == 0) {
        func_0213442c(data_ov000_021b2364, data_ov000_021b2358, 0, 0x51);
    }
    if (a != 0) {
        for (b = 0; b < a->mUnk_04; b++) {
            func_ov000_0218dc48(a->mUnk_00[b]);
        }
        func_ov000_021a3668(a->mUnk_00);
        func_ov000_021a3668(a);
    }
}

s32 func_ov000_0218df5c(Unk0218e004 *c) {
    s32 a = 0;
    s32 b;
    if (c == 0) {
        func_0213442c(data_ov000_021b2364, data_ov000_021b2358, 0, 0x61);
    }
    if (c == 0) {
        return 0;
    }
    for (b = 0; b < c->mUnk_04; b++) {
        a += func_ov000_0218dc44(c->mUnk_00[b]);
    }
    return a;
}

void func_ov000_0218def0(Unk0218e004 *c, void *d) {
    s32 a;
    s32 b;
    if (c == 0) {
        func_0213442c(data_ov000_021b2364, data_ov000_021b2358, 0, 0x71);
    }
    if (c != 0) {
        a = c->mUnk_0c(d, c->mUnk_04);
        b = func_ov000_0218d980((int *) c->mUnk_00[a], d, (UnkCompare *) c->mUnk_10, 0, 0);
        if (b == -1) {
            func_ov000_0218dbc0(c->mUnk_00[a], d);
            return;
        }
        func_ov000_0218da1c(c->mUnk_00[a], d, b);
    }
}

s32 func_ov000_0218de8c(Unk0218e004 *c, void *d) {
    s32 a;
    s32 b;
    if (c == 0) {
        func_0213442c(data_ov000_021b2364, data_ov000_021b2358, 0, 0x82);
    }
    if (c == 0) {
        return 0;
    }
    a = c->mUnk_0c(d, c->mUnk_04);
    b = func_ov000_0218d980((int *) c->mUnk_00[a], d, (UnkCompare *) c->mUnk_10, 0, 0);
    if (b != -1) {
        func_ov000_0218da5c(c->mUnk_00[a], b);
        return 1;
    }
    return 0;
}

void *func_ov000_0218de28(Unk0218e004 *c, void *d) {
    s32 a;
    s32 b;
    if (c == 0) {
        func_0213442c(data_ov000_021b2364, data_ov000_021b2358, 0, 0x94);
    }
    if (c == 0) {
        return 0;
    }
    a = c->mUnk_0c(d, c->mUnk_04);
    b = func_ov000_0218d980((int *) c->mUnk_00[a], d, (UnkCompare *) c->mUnk_10, 0, 0);
    if (b != -1) {
        return func_ov000_0218dbf8(c->mUnk_00[a], b);
    }
    return 0;
}

void func_ov000_0218dddc(Unk0218e004 *b, void (*c)(void *, void *), void *d) {
    s32 a;
    if (c == 0) {
        func_0213442c(data_ov000_021b2354, data_ov000_021b2358, 0, 0xb6);
    }
    for (a = 0; a < b->mUnk_04; a++) {
        func_ov000_0218d938((int *) b->mUnk_00[a], (UnkCompare *) c, d);
    }
}

int func_ov000_0218dd8c(int *a, int b, u32 c) {
    int v1;
    int v2;
    int v3;
    if (b == 0) {
        func_0213442c(data_ov000_021b2354, data_ov000_021b2358, 0, 0xd3);
    }
    v3 = 0;
    if (0 < a[1]) {
        v2 = 0;
        do {
            v1 = (int) func_ov000_0218d8dc((int *) (u32) (*(u32 *) (*a + v2)), (UnkCompare *) b, (void *) c);
            if (v1 != 0) {
                return v1;
            }
            v2 = v2 + 4;
            v3 = v3 + 1;
        } while (v3 < a[1]);
    }
    return 0;
}
