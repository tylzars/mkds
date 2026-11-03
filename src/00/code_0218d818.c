#include "00/code_0218d818.h"
#include "code_02133048.h"
#include "code_02134d30.h"
#include "00/code_0218db48.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/code_0218dc44.h"
#include "Main/Unknown/code_02133000.h"

#include "code_021382a8.h"

void func_ov000_0218daf8(Unk0218dc94 *a, const void *b, int c) {
    u8 *v1;
    u32 v2;
    s32 v3[2];
    if (c == 0) {
        func_0213442c(data_ov000_021b2308, data_ov000_021b22dc, NULL, 0xb7);
    }
    v1 = func_ov000_0218d818(b, a->mUnk_14, a->mUnk_00, a->mUnk_08, (UnkCompare *) c, v3);
    v2 = _s32_div_f(v1 - a->mUnk_14, a->mUnk_08);
    func_ov000_0218db48(a, b, v2);
    return;
}

void func_ov000_0218da9c(Unk0218dc94 *a, int b) {
    s32 v1;
    if (b < 0 || b >= a->mUnk_00) {
        func_0213442c(data_ov000_021b22e8, data_ov000_021b22dc, NULL, 0xc0);
    }
    v1 = a->mUnk_00 - 1;
    if (b < v1) {
        memmove(func_ov000_0218dbf8(a, b), func_ov000_0218dbf8(a, b + 1), a->mUnk_08 * (v1 - b));
    }
    a->mUnk_00 = a->mUnk_00 - 1;
}

void func_ov000_0218da5c(Unk0218dc94 *a, s32 b) {
    if ((b < 0) || (b >= a->mUnk_00)) {
        func_0213442c(data_ov000_021b22e8, data_ov000_021b22dc, NULL, 0xca);
    }
    func_ov000_0218dd74(a, b);
    func_ov000_0218da9c(a, b);
}

void func_ov000_0218da1c(Unk0218dc94 *a, const void *b, s32 c) {
    if ((c < 0) || (c >= a->mUnk_00)) {
        func_0213442c(data_ov000_021b22e8, data_ov000_021b22dc, NULL, 0xd3);
    }
    func_ov000_0218dd74(a, c);
    func_ov000_0218dd18(a, b, c);
}

void func_ov000_0218da04(u32 p0, u32 p1) {
    u32 v2 = ((p0) + (0x0u));
    u32 v3 = ((p1) + (0x0u));
    u32 v4 = ((u32) * (u32 *) ((v2) + (20)));
    u32 v5 = ((u32) * (u32 *) ((v2) + (0)));
    u32 v6 = ((u32) * (u32 *) ((v2) + (8)));
    qsort((u8 *) v4, v5, v6, (int (*)(void *, void *))(v3));
}

s32 func_ov000_0218d980(Unk0218dc94 *a, const void *b, UnkCompare *c, s32 d, s32 e) {
    s32 v1 = 1;
    s32 n;
    u8 *r;
    if (a == NULL || (n = a->mUnk_00) == 0) {
        return -1;
    }
    if (e != 0) {
        r = func_ov000_0218d818(b, func_ov000_0218dbf8(a, d), n - d, a->mUnk_08, c, &v1);
    } else {
        r = func_ov000_0218d86c(b, func_ov000_0218dbf8(a, d), n - d, a->mUnk_08, c);
    }
    if (r != NULL && v1 != 0) {
        return (r - a->mUnk_14) / a->mUnk_08;
    }
    return -1;
}

void func_ov000_0218d938(Unk0218dc94 *a, UnkCompare *b, const void *c) {
    s32 i;
    if (b == NULL) {
        func_0213442c(data_ov000_021b22d8, data_ov000_021b22dc, NULL, 0x104);
    }
    for (i = a->mUnk_00 - 1; i >= 0; i--) {
        b(func_ov000_0218dbf8(a, i), c);
    }
}

void *func_ov000_0218d8dc(Unk0218dc94 *a, UnkCompare *b, const void *c) {
    s32 i;
    void *e;
    if (b == NULL) {
        func_0213442c(data_ov000_021b22d8, data_ov000_021b22dc, NULL, 0x121);
    }
    for (i = a->mUnk_00 - 1; i >= 0; i--) {
        e = func_ov000_0218dbf8(a, i);
        if (b(e, c) == 0) {
            return e;
        }
    }
    return NULL;
}

void func_ov000_0218d8b4(Unk0218dc94 *a) {
    s32 i;
    for (i = func_ov000_0218dc44(a) - 1; i >= 0; i--) {
        func_ov000_0218da5c(a, i);
    }
}

void *func_ov000_0218d86c(const void *a, u8 *b, s32 c, s32 d, UnkCompare *e) {
    s32 i;
    s32 v1;
    i = 0;
    if (c > 0) {
        v1 = 0;
        do {
            if (e(a, b + v1) == 0) {
                return b + d * i;
            }
            v1 += d;
            i++;
        } while (i < c);
    }
    return NULL;
}

void *func_ov000_0218d818(const void *a, u8 *b, s32 c, s32 d, UnkCompare *e, s32 *f) {
    s32 v1 = 0;
    s32 v2 = c - 1;
    s32 v3;
    s32 r;
    *f = 0;
    if (v2 >= 0) {
        do {
            v3 = (v1 + v2) >> 1;
            r = e(b + v3 * d, a);
            if (r == 0) {
                *f = 1;
            }
            if (r < 0) {
                v1 = v3 + 1;
            } else {
                v2 = v3 - 1;
            }
        } while (v1 <= v2);
    }
    return b + v1 * d;
}
