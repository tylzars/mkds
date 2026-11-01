#include "Main/Unknown/code_0203c5f8.h"
#include "Main/Unknown/code_020b502c.h"
#include "code_0214d018.h"

// non-matching: the original (0x178 bytes, 0x1c stack bytes) keeps the address of the local pair in r5, the constants 0
// and 4 in r6 and r4 and spills the entry offset and the constant 1 to stack offsets 0xc and 0x10; ours is 0x154 bytes
// with 0x14 stack bytes and forms the address in the loop
u16 func_0203c5f8(u16 a, u8 *b, u8 *c, u16 *d) {
    u16 r = 1;
    s32 f = 1;
    u16 i = 1;
    u32 v1 = a * 0x8c;
    Unk0217aa1c_144_00 v2;
    Unk0217aa1c_144_00 *p = &v2;
    if (data_02175620->mUnk_018->mUnk_02 >= 1) {
        do {
            Unk0217aa1c_144_00 *q =
                (Unk0217aa1c_144_00 *) ((u8 *) &data_0217561c->mUnk_14[0].mUnk_0c[0] + v1) + (i - 1);
            if (f != 0) {
                f = 0;
                r = i;
                v2 = *q;
            } else {
                s32 k = 0;
                if ((q->mUnk_02 * 60 + q->mUnk_03) * 1000 + q->mUnk_00 <=
                    (v2.mUnk_02 * 60 + v2.mUnk_03) * 1000 + v2.mUnk_00) {
                    k = 1;
                    if (q != p) {
                        func_0214d1fc(q, p, 4);
                    }
                } else {
                    if (p != &v2) {
                        func_0214d1fc(q, p, 4);
                    }
                }
                if (k != 0) {
                    r = i;
                    v2 = *q;
                }
            }
            i++;
        } while (i <= data_02175620->mUnk_018->mUnk_02);
    }
    *b = v2.mUnk_02;
    *c = v2.mUnk_03;
    *d = v2.mUnk_00;
    return r;
}

// non-matching: same instructions and order; registers differ (b - 1 in r4, the entry base in r5 and the element in lr
// where the original has lr, r4 and r5)
void func_0203c778(s32 a, u16 b, u8 *c, u8 *d, u16 *e) {
    s32 k = b - 1;
    Unk0217aa1c_144_00 *p = (Unk0217aa1c_144_00 *) ((u8 *) &data_0217561c->mUnk_14[0].mUnk_0c[0] + a * 0x8c);
    Unk0217aa1c_144_00 *q = &p[k];
    *c = q->mUnk_02;
    *d = q->mUnk_03;
    *e = p[k].mUnk_00;
}

void func_0203c7cc(s32 a, u8 *b, u8 *c, u16 *d) {
    Unk0217561c_14 *p = (Unk0217561c_14 *) ((u8 *) &data_0217561c->mUnk_14[0] + a * 0x8c);
    s32 g = 1;
    if (data_021759c0->mUnk_08 == 2) {
        if (data_021759c0->mUnk_18 == 1) {
            g = 0;
        }
    }
    if (g != 0) {
        s32 h = 0;
        switch (p->mUnk_00) {
            case 1:
            case 2:
            case 3:
                h = 1;
                break;
        }
        if (h != 0) {
            Unk0217aa1c_144_00 *t = &p->mUnk_0c[5];
            *b = t->mUnk_02;
            *c = t->mUnk_03;
            *d = t->mUnk_00;
            return;
        }
    }
    *b = 0;
    *c = 0;
    *d = 0;
}

s32 func_0203c880(u32 param_1) {
    s32 f = 0;
    switch (data_0217561c->mUnk_000[param_1].mUnk_14) {
        case 1:
        case 2:
        case 3:
            f = 1;
            break;
    }
    return f;
}
