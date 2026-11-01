#include "00/code_021a2950.h"
#include "00/code_0218b000.h"
#include "00/code_0218b474.h"
#include "00/code_0219bab4.h"
#include "00/code_0219c39c.h"
#include "00/code_0219eac8.h"
#include "00/code_021a1000.h"
#include "00/code_021a3264.h"
#include "00/code_021a369c.h"
#include "00/code_021a4b84.h"
#include "code_02139f70.h"
#include "00/code_021a01dc.h"

s32 func_ov000_021a2950(u64 *a) {
    Unk021b5670 *p = data_ov000_021b5670;
    u64 t;
    if (p == 0 || p->mUnk_00 == 0) {
        return -1;
    }
    t = func_ov000_021a350c() - p->mUnk_10;
    if (a != 0) {
        *a = t;
    }
    return t >= p->mUnk_04;
}

u32 func_ov000_021a299c(u32 a, void *b, u32 c) {
    Unk021b566c *p = data_ov000_021b566c;
    Unk021b5670 *q;
    if (p == 0) {
        return 1;
    }
    if (b == 0) {
        return 3;
    }
    switch (a) {
        case 0:
            if (p->mUnk_198 == 0x13) {
                return 1;
            }
            if (*(u8 *) b != 0 && ((u8 *) b)[1] <= 1) {
                return 3;
            }
            q = data_ov000_021b5670;
            if (q == 0) {
                q = func_ov000_021a372c(4, 0x20);
                data_ov000_021b5670 = q;
                if (q == 0) {
                    return 4;
                }
            }
            q->mUnk_00 = *(u8 *) b;
            data_ov000_021b5670->mUnk_01 = ((u8 *) b)[1];
            data_ov000_021b5670->mUnk_02 = 0;
            data_ov000_021b5670->mUnk_03 = 0;
            data_ov000_021b5670->mUnk_04 = *(u32 *) ((u8 *) b + 4);
            data_ov000_021b5670->mUnk_08 = 0;
            data_ov000_021b5670->mUnk_0c = 0;
            data_ov000_021b5670->mUnk_10 = func_ov000_021a350c();
            data_ov000_021b5670->mUnk_18 = func_ov000_021a350c();
            return 0;
        case 1:
            if (*(u32 *) b != 0) {
                data_ov000_021b5668.mUnk_00 = 1;
            } else {
                data_ov000_021b5668.mUnk_00 = 0;
            }
            data_ov000_021b5668.mUnk_01 = 0;
            return 0;
        default:
            return 2;
    }
}

s32 func_ov000_021a2a88(u32 a, void *b, s32 c) {
    u32 r;
    if (data_ov000_021b566c == 0 || func_ov000_0219c39c() != 0) {
        return c;
    }
    r = func_ov000_0218b480((u32) data_ov000_021b566c->mUnk_e4, a);
    if (r != 0) {
        c = func_ov000_0218b2a8((Unk0218af28 *) r, b, c);
    }
    return c;
}

u32 func_ov000_021a2ad0(u32 a, u8 *b, void *c) {
    u32 i;
    if (b == 0 || c == 0) {
        return 0;
    }
    if (a >= 100) {
        i = a - 100;
        if (data_ov000_021b5698[i][0] != 0) {
            return a;
        }
    }
    a = func_ov000_0219eac8();
    if (a == 0) {
        return 0;
    }
    i = a - 100;
    data_ov000_021b5698[i][0] = a;
    data_ov000_021b5699[i * 12] = 1;
    *(u16 *) &data_ov000_021b569a[i * 12] = 0;
    if (*(void **) &data_ov000_021b569c[i * 12] != 0) {
        func_ov000_021a3704(4, *(u32 *) &data_ov000_021b569c[i * 12], 0);
    }
    *(void **) &data_ov000_021b569c[i * 12] = func_ov000_021a372c(4, func_0213a434(b) + 1);
    if (*(void **) &data_ov000_021b569c[i * 12] == 0) {
        func_ov000_021a1a38(0xb, 0xfffec77f);
        return 0;
    }
    func_0213a2d0(*(char **) &data_ov000_021b569c[i * 12], b);
    *(void **) &data_ov000_021b56a0[i * 12] = c;
    func_ov000_021a4b84(a, b);
    return a;
}

u32 func_ov000_021a2b9c(u32 a, u8 *b, void *c) {
    u32 i;
    if (b == 0 || c == 0) {
        return 0;
    }
    if (a >= 100) {
        i = a - 100;
        if (data_ov000_021b5698[i][0] != 0) {
            return a;
        }
    }
    a = func_ov000_0219eac8();
    if (a == 0) {
        return 0;
    }
    i = a - 100;
    data_ov000_021b5698[i][0] = a;
    data_ov000_021b5699[i * 12] = 0;
    *(u16 *) &data_ov000_021b569a[i * 12] = 0;
    if (*(void **) &data_ov000_021b569c[i * 12] != 0) {
        func_ov000_021a3704(4, *(u32 *) &data_ov000_021b569c[i * 12], 0);
    }
    *(void **) &data_ov000_021b569c[i * 12] = func_ov000_021a372c(4, func_0213a434(b) + 1);
    if (*(void **) &data_ov000_021b569c[i * 12] == 0) {
        func_ov000_021a1a38(0xb, 0xfffec77f);
        return 0;
    }
    func_0213a2d0(*(char **) &data_ov000_021b569c[i * 12], b);
    *(void **) &data_ov000_021b56a0[i * 12] = c;
    func_ov000_021a4b84(a, b);
    return a;
}

u32 func_ov000_021a2c64(void) {
    if (func_ov000_0219c39c() != 0) {
        return 0;
    }
    if (data_ov000_021b566c == 0 || func_ov000_0219bab4() != 5 || data_ov000_021b566c->mUnk_1a1 != 0) {
        return 0;
    }
    return 1;
}
