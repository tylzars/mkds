#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02087934.h"
#include "Main/Unknown/code_02087d0c.h"
#include "code_020109c4.h"
#include "code_02010c84.h"

#include "Main/Unknown/code_02087cd0.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02036bec.h"
#include "code_02013740.h"
#include "code_02013bdc.h"

u32 func_0208832c(Unk020882fc *p0) {
    return p0->mUnk_08->mUnk_04;
}

u32 func_02088320(Unk020882fc *p0) {
    return p0->mUnk_08->mUnk_04;
}

u32 func_02088314(Unk020882fc *p0) {
    return p0->mUnk_08->mUnk_04;
}

u32 func_02088308(Unk020882fc *p0) {
    return p0->mUnk_08->mUnk_04;
}

u32 func_020882fc(Unk020882fc *p0) {
    return p0->mUnk_08->mUnk_04;
}

void func_0208823c(u32 a, void *b, void *c, u32 d, void *e, void *f) {
    Unk02087d0c *p = b;
    Unk02010ab4 *q = c;
    u16 i;

    if (d != 0) {
        i = 0;
        if (e != NULL) {
            p->mUnk_1c = HeapAlloc(e, d * 4);
            p->mUnk_20 = HeapAlloc(e, d * 4);
            for (; i < d; i++) {
                p->mUnk_1c[i] = NULL;
                p->mUnk_20[i] = 0;
            }
        }
    }
    func_02087cd0(p, 0);
    q->mUnk_58 = 0;
    p->mUnk_14 = q;
    p->mUnk_18 = d;
    p->mUnk_1a = 0;
    p->mUnk_28 = a;
    p->mUnk_2c = 0;
    p->mUnk_30 = 0x19a;
    p->mUnk_34 = NULL;
}

void func_020881b0(void *a, s32 b, void *c, u32 d, void *e) {
    Unk02087d0c *p = a;
    Unk02010b50 *x;

    if (e == NULL) {
        x = p->mUnk_1c[b];
        p->mUnk_20[b] = d;
    } else {
        data_0217af20 = func_02010d98(c, p->mUnk_14->mUnk_04);
        x = HeapAlloc(e, data_0217af20);
        p->mUnk_1c[b] = x;
        p->mUnk_20[b] = d;
    }
    func_02010cec((Unk02010c84 *) x, c, (u32) p->mUnk_14->mUnk_04, p->mUnk_14->mUnk_68);
}

void func_0208805c(void *a, void *b, void *c) {
    Unk02087d0c *p = a;
    void *v = NULL;
    u8 i = 0;
    Unk02010b50 *x;

    for (i = 0; i < p->mUnk_18; i++) {
        switch (p->mUnk_28) {
            case 0:
                v = func_02013a4c(func_02013a30(b), i);
                break;
            case 2:
                v = func_02013b00(func_02013ae4(b), i);
                break;
            case 1:
                v = func_02013ac4(func_02013aa8(b), i);
                break;
            case 3:
                v = func_02013bf8(func_02013bdc(b), i);
                break;
            case 4:
                v = func_02013a88(func_02013a6c(b), i);
                break;
        }
        if (c != NULL) {
            data_0217af20 = func_02010d98(v, p->mUnk_14->mUnk_04);
            x = HeapAlloc(c, data_0217af20);
            p->mUnk_1c[i] = x;
            p->mUnk_20[i] = 0;
        } else {
            x = p->mUnk_1c[i];
            p->mUnk_20[i] = 0;
        }
        func_02010cec((Unk02010c84 *) x, v, (u32) p->mUnk_14->mUnk_04, p->mUnk_14->mUnk_68);
    }
}

void func_02087f84(void *b, s32 a) {
    Unk02087d0c *p = b;
    s32 v;

    if (p->mUnk_1c[a] == NULL) {
        return;
    }
    p->mUnk_2c = 0;
    if (p->mUnk_34 != NULL) {
        func_020109d8(p->mUnk_14, p->mUnk_34);
        p->mUnk_34 = NULL;
    }
    func_020109d8(p->mUnk_14, p->mUnk_1c[p->mUnk_1a]);
    p->mUnk_1a = a;
    func_02010ab4(p->mUnk_14, p->mUnk_1c[p->mUnk_1a]);
    p->mUnk_1c[p->mUnk_1a]->mUnk_04 = 0x1000;
    v = data_02155cd8[p->mUnk_28](p->mUnk_1c[p->mUnk_1a]) << 12;
    func_02087c9c(p, v, (u16) p->mUnk_20[p->mUnk_1a]);
}

void func_02087e90(void *b, u16 a) {
    Unk02087d0c *p = b;
    s32 v;

    if (p->mUnk_1c[a] == NULL) {
        return;
    }
    if (p->mUnk_1a == a) {
        return;
    }
    p->mUnk_2c = 1;
    if (p->mUnk_34 != NULL) {
        func_020109d8(p->mUnk_14, p->mUnk_34);
        p->mUnk_34 = NULL;
    }
    p->mUnk_34 = p->mUnk_1c[p->mUnk_1a];
    p->mUnk_34->mUnk_04 = 0x1000;
    p->mUnk_1a = a;
    func_02010ab4(p->mUnk_14, p->mUnk_1c[p->mUnk_1a]);
    p->mUnk_1c[p->mUnk_1a]->mUnk_04 = 0;
    v = data_02155cd8[p->mUnk_28](p->mUnk_1c[p->mUnk_1a]) << 12;
    func_02087c9c(p, v, (u16) p->mUnk_20[p->mUnk_1a]);
}

void func_02087de0(void *a) {
    Unk02087d0c *p = a;

    if (p->mUnk_2c != 0) {
        p->mUnk_1c[p->mUnk_1a]->mUnk_04 += p->mUnk_30;
        p->mUnk_34->mUnk_04 -= p->mUnk_30;
        if (p->mUnk_1c[p->mUnk_1a]->mUnk_04 >= 0x1000) {
            p->mUnk_2c = 0;
            p->mUnk_1c[p->mUnk_1a]->mUnk_04 = 0x1000;
            func_020109d8(p->mUnk_14, p->mUnk_34);
            p->mUnk_34 = NULL;
        }
    }
    func_02087b78(p);
    p->mUnk_1c[p->mUnk_1a]->mUnk_00 = p->mUnk_0c;
}

void func_02087d44(Unk02087d0c *p) {
    if (p->mUnk_2c == 0) {
        return;
    }
    p->mUnk_1c[p->mUnk_1a]->mUnk_04 += p->mUnk_30;
    p->mUnk_34->mUnk_04 -= p->mUnk_30;
    if (p->mUnk_1c[p->mUnk_1a]->mUnk_04 >= 0x1000) {
        p->mUnk_2c = 0;
        p->mUnk_1c[p->mUnk_1a]->mUnk_04 = 0x1000;
        func_020109d8(p->mUnk_14, p->mUnk_34);
        p->mUnk_34 = NULL;
    }
}

s32 func_02087d0c(void *a) {
    Unk02087d0c *p = a;
    enum { K0 } k = p->mUnk_28;

    return data_02155cd8[k](p->mUnk_1c[p->mUnk_1a]) << 12;
}
