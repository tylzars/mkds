#include "Main/Unknown/code_02038cb0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02036820.h"

void func_02038e6c(void *a, u32 b) {
    Unk02038e6c *p = a;
    u32 c;
    p->mUnk_00 = 0;
    p->mUnk_02 = 0;
    p->mUnk_04 = 0;
    p->mUnk_06 = 0;
    p->mUnk_08 = 0;
    p->mUnk_0a = 0;
    p->mUnk_0c = 0;
    p->mUnk_10 = 1;
    p->mUnk_14 = 0;
    p->mUnk_16 = 0;
    p->mUnk_12 = 0;
    p->mUnk_18 = 0;
    p->mUnk_1a = 0;
    p->mUnk_1c = 0;
    c = 6;
    switch (b) {
        case 0:
        case 1:
        case 3:
            c = 1;
            break;
        case 2:
        case 4:
            c = 2;
            break;
        case 5:
            c = 3;
            break;
        case 6:
            break;
    }
    p->mUnk_20 = c;
    switch (c) {
        case 1:
            p->mUnk_24 = 2;
            p->mUnk_28 = 0;
            p->mUnk_2a = 0;
            p->mUnk_26 = 0;
            p->mUnk_2c = 0;
            p->mUnk_2e = 0;
            break;
        case 2:
            p->mUnk_24 = 2;
            p->mUnk_28 = 0;
            p->mUnk_26 = 0;
            p->mUnk_2a = 0;
            p->mUnk_2c = 0;
            p->mUnk_2e = 0;
            break;
        case 3:
            p->mUnk_24 = 2;
            p->mUnk_26 = 0;
            p->mUnk_28 = 0;
            p->mUnk_2a = 0;
            p->mUnk_2c = 0;
            break;
    }
    c = 6;
    switch (b) {
        case 0:
            c = 1;
            break;
        case 1:
        case 2:
            c = 2;
            break;
        case 3:
        case 4:
        case 5:
            c = 3;
            break;
        case 6:
            break;
    }
    p->mUnk_30 = c;
    switch (c) {
        case 1:
            p->mUnk_34 = 2;
            p->mUnk_38 = 0;
            p->mUnk_3a = 0;
            p->mUnk_36 = 0;
            p->mUnk_3c = 0;
            p->mUnk_3e = 0;
            break;
        case 2:
            p->mUnk_34 = 2;
            p->mUnk_38 = 0;
            p->mUnk_36 = 0;
            p->mUnk_3a = 0;
            p->mUnk_3c = 0;
            p->mUnk_3e = 0;
            break;
        case 3:
            p->mUnk_34 = 2;
            p->mUnk_36 = 0;
            p->mUnk_38 = 0;
            p->mUnk_3a = 0;
            p->mUnk_3c = 0;
            break;
    }
    p->mUnk_40 = 0;
    p->mUnk_42 = 0;
}

void func_02038de4(Unk021755a0 *a, void *b) {
    Unk02038de4 *c = b;
    *(Unk02038de4 *) a = *c;
    func_02038e6c(&a->mUnk_28, c->mUnk_08);
    func_02038e6c(&a->mUnk_70, c->mUnk_0c);
    a->mUnk_6c = 0;
    a->mUnk_bc = 0;
    a->mUnk_c4 = 0;
    a->mUnk_cc = 0;
    a->mUnk_d0 = 0;
    a->mUnk_d4 = 0;
    a->mUnk_b4 = 0;
    a->mUnk_b8 = 0;
    a->mUnk_d8 = 0;
}

void *func_02038d88(void *a, void *b) {
    Unk021755a0 *p = func_02036bec(a, 0xdc);
    Unk021755a0_6c *q;
    func_02038de4(p, b);
    if (p->mUnk_0a == 1) {
        q = func_02036bec(a, 8);
        q->mUnk_00 = 0x5000;
        q->mUnk_02 = 1;
        q->mUnk_03 = 1;
        p->mUnk_6c = q;
    }
    return p;
}

void func_02038d58(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h) {
    Unk02038e6c *p = a;
    p->mUnk_00 = b;
    p->mUnk_04 = d;
    p->mUnk_06 = e;
    p->mUnk_02 = c;
    p->mUnk_08 = f;
    p->mUnk_0a = g;
    p->mUnk_0c = h;
}

void func_02038d28(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h) {
    Unk02038e6c *p = a;
    p->mUnk_10 = b;
    p->mUnk_14 = d;
    p->mUnk_16 = e;
    p->mUnk_12 = c;
    p->mUnk_18 = f;
    p->mUnk_1a = g;
    p->mUnk_1c = h;
}

void func_02038d00(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    Unk02038e6c *p = a;
    p->mUnk_24 = b;
    p->mUnk_26 = c;
    p->mUnk_28 = d;
    p->mUnk_2a = e;
    p->mUnk_2c = f;
    p->mUnk_2e = g;
}

void func_02038cd8(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    Unk02038e6c *p = a;
    p->mUnk_34 = b;
    p->mUnk_36 = c;
    p->mUnk_38 = d;
    p->mUnk_3a = e;
    p->mUnk_3c = f;
    p->mUnk_3e = g;
}

void func_02038cb0(void *a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    Unk02038e6c *p = a;
    p->mUnk_20 = 5;
    p->mUnk_24 = b;
    p->mUnk_26 = c;
    p->mUnk_28 = d;
    p->mUnk_2a = e;
    p->mUnk_2c = f;
}
