#include "00/code_0218b280.h"
#include "00/code_021a2950.h"
#include "00/code_0218b000.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_0218dc44.h"
#include "00/code_0218cdc4.h"
#include "00/code_0218b434.h"
#include "00/unk_021b5000.h"
#include "00/code_0219b580.h"
#include "00/code_0219c39c.h"
#include "00/code_0219eac8.h"
#include "00/code_021a1000.h"
#include "00/code_021a3264.h"
#include "03/code_021b94b8.h"
#include "00/code_021a369c.h"
#include "00/code_021a4b84.h"
#include "code_02139f70.h"
#include "00/code_021a01dc.h"

u32 func_ov000_021a2c64(void) {
    if (func_ov000_0219c39c() != 0) {
        return 0;
    }
    if (data_ov000_021b566c == NULL || func_ov000_0219bab4() != 5 || data_ov000_021b566c->mUnk_1a1 != 0) {
        return 0;
    }
    return 1;
}

u32 func_ov000_021a2b9c(u32 a, char *b, void *c) {
    u32 i;
    if (b == NULL || c == NULL) {
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
    if (*(void **) &data_ov000_021b569c[i * 12] != NULL) {
        func_ov000_021a3704(4, *(u32 *) &data_ov000_021b569c[i * 12], 0);
    }
    *(void **) &data_ov000_021b569c[i * 12] = func_ov000_021a372c(4, strlen(b) + 1);
    if (*(void **) &data_ov000_021b569c[i * 12] == NULL) {
        func_ov000_021a1a38(0xb, 0xfffec77f);
        return 0;
    }
    strcpy(*(char **) &data_ov000_021b569c[i * 12], b);
    *(void **) &data_ov000_021b56a0[i * 12] = c;
    func_ov000_021a4b84(a, b);
    return a;
}

u32 func_ov000_021a2ad0(u32 a, char *b, void *c) {
    u32 i;
    if (b == NULL || c == NULL) {
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
    if (*(void **) &data_ov000_021b569c[i * 12] != NULL) {
        func_ov000_021a3704(4, *(u32 *) &data_ov000_021b569c[i * 12], 0);
    }
    *(void **) &data_ov000_021b569c[i * 12] = func_ov000_021a372c(4, strlen(b) + 1);
    if (*(void **) &data_ov000_021b569c[i * 12] == NULL) {
        func_ov000_021a1a38(0xb, 0xfffec77f);
        return 0;
    }
    strcpy(*(char **) &data_ov000_021b569c[i * 12], b);
    *(void **) &data_ov000_021b56a0[i * 12] = c;
    func_ov000_021a4b84(a, b);
    return a;
}

s32 func_ov000_021a2a88(u32 a, void *b, s32 c) {
    u32 r;
    if (data_ov000_021b566c == NULL || func_ov000_0219c39c() != 0) {
        return c;
    }
    r = func_ov000_0218b480((u32) data_ov000_021b566c->mUnk_e4, a);
    if (r != 0) {
        c = func_ov000_0218b2a8((Unk0218af28 *) r, b, c);
    }
    return c;
}

u32 func_ov000_021a299c(u32 a, void *b, u32 c) {
    Unk021b566c *p = data_ov000_021b566c;
    Unk021b5670 *q;
    if (p == NULL) {
        return 1;
    }
    if (b == NULL) {
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
            if (q == NULL) {
                q = func_ov000_021a372c(4, 0x20);
                data_ov000_021b5670 = q;
                if (q == NULL) {
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

s32 func_ov000_021a2950(u64 *a) {
    Unk021b5670 *p = data_ov000_021b5670;
    u64 t;
    if (p == NULL || p->mUnk_00 == 0) {
        return -1;
    }
    t = func_ov000_021a350c() - p->mUnk_10;
    if (a != NULL) {
        *a = t;
    }
    return t >= p->mUnk_04;
}
