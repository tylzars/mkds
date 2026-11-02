#include "00/code_021a3264.h"
#include "00/code_0219b000.h"
#include "00/unk_021b5000.h"
#include "00/code_0219c39c.h"
#include "00/code_021a2ccc.h"
#include "00/unk_021b4000.h"
#include "code_02139f70.h"
#include "00/code_021a31d4.h"
#include "code_0200d118.h"
#include "code_0200f5ac.h"
#include "code_0200fd1c.h"
#include "code_021329f8.h"
#include "code_02134d30.h"

BOOL func_ov000_021a3264(u32 a, void *b, s32 c) {
    Unk021a2d68 *e = func_ov000_021a2fdc(a);
    if (func_ov000_021a2fb4(a) == 2) {
        return FALSE;
    }
    e->mUnk_04 = b;
    e->mUnk_08 = c;
    e->mUnk_1d = 1;
    e->mUnk_10 = 0;
    e->mUnk_18 = 0;
    return TRUE;
}

BOOL func_ov000_021a32a0(u32 a, void *b, s32 c) {
    if (func_ov000_0219c39c() != 0) {
        return FALSE;
    }
    if (func_ov000_0219bac8(a) == 0) {
        return FALSE;
    }
    if (c > data_ov000_021b5dd0->mUnk_610) {
        return FALSE;
    }
    func_ov000_021a2f98(a, (u32) b, c, 0);
    if (data_ov000_021b5dd0->mUnk_600 != NULL) {
        data_ov000_021b5dd0->mUnk_600(c, a);
    }
    return TRUE;
}

BOOL func_ov000_021a3310(u16 a, u32 b, u8 *c, s32 d) {
    Unk021a2d68 *e = func_ov000_021a2fdc(b);
    u32 t[2];
    s32 n;
    if (func_ov000_0219c39c() != 0) {
        return FALSE;
    }
    if (func_ov000_021a33e4(b, a) == 0) {
        return FALSE;
    }
    e->mUnk_1c = 1;
    e->mUnk_00 = c;
    e->mUnk_0c = 0;
    e->mUnk_14 = d;
    func_ov000_021a321c(t, a, d);
    func_ov000_021a2f98(b, (u32) t, 8, 1);
    n = data_ov000_021b5dd0->mUnk_610;
    if (d <= n) {
        n = d;
    }
    if (n > func_ov000_021a2d18(b)) {
        return TRUE;
    }
    func_ov000_021a2f98(b, (u32) c, n, 1);
    e->mUnk_0c += n;
    if (e->mUnk_0c == e->mUnk_14) {
        if (data_ov000_021b5dd0->mUnk_600 != NULL && a == 1) {
            data_ov000_021b5dd0->mUnk_600(e->mUnk_14, b);
        }
        e->mUnk_1c = 0;
        e->mUnk_00 = NULL;
        e->mUnk_0c = 0;
        e->mUnk_14 = 0;
    }
    return TRUE;
}

BOOL func_ov000_021a33e4(u32 a, s32 b) {
    if ((b == 1 && func_ov000_0219bac8(a) == 0) || func_ov000_0219b8bc(a) == 0) {
        return FALSE;
    }
    if (func_ov000_021a2fc8(a) == 1) {
        return FALSE;
    }
    if (func_ov000_021a2d18(a) >= func_ov000_021a31d4(b)) {
        return TRUE;
    }
    return FALSE;
}

u32 func_ov000_021a3448(u32 a) {
    u64 s;
    u64 t;
    if (data_ov000_021b5dd4.mUnk_00 == 0 && data_ov000_021b5dd4.mUnk_08 == 0 && data_ov000_021b5dd4.mUnk_10 == 0) {
        func_0200fe58(&s);
        t = func_0200f5ac();
        s = ((s >> 24) & 0xffffff) | (t << 24);
        data_ov000_021b5dd4.mUnk_00 = s;
        data_ov000_021b5dd4.mUnk_08 = 0x5d588b656c078965;
        data_ov000_021b5dd4.mUnk_10 = 0x269ec3;
    }
    data_ov000_021b5dd4.mUnk_00 =
        data_ov000_021b5dd4.mUnk_08 * data_ov000_021b5dd4.mUnk_00 + data_ov000_021b5dd4.mUnk_10;
    if (a == 0) {
        return (u32) (data_ov000_021b5dd4.mUnk_00 >> 32);
    }
    return (u32) (((data_ov000_021b5dd4.mUnk_00 >> 32) * a) >> 32);
}

u64 func_ov000_021a350c(void) {
    return _ll_udiv(func_0200f5ac() << 6, 0x82ea);
}

s32 func_ov000_021a3530(const u8 *a, u8 *b, const u8 *c, int d) {
    const u8 *p;
    const u8 *q;
    s32 n;
    enum { K1 = 1 } k;
    if (b == NULL) {
        return -1;
    }
    p = strchr(c, d);
    if (p == NULL) {
        return -1;
    }
    k = K1;
    while (1) {
        if (strncmp(p + 1, a, strlen(a)) == 0 && (n = strlen(a), n += (u32) p, d == *(s8 *) (n + k))) {
            break;
        }
        q = strchr(p + 1, d);
        if (q == NULL) {
            return -1;
        }
        p = strchr(q + 1, d);
        if (p == NULL) {
            return -1;
        }
    }
    p = strchr(p + 1, d);
    if (p == NULL) {
        return -1;
    }
    q = strchr(p + 1, d);
    if (q != NULL) {
        n = q - (p + 1);
    } else {
        n = strlen(p + 1);
    }
    strncpy(b, p + 1, n);
    b[n] = 0;
    return n;
}

u32 func_ov000_021a360c(void *param_1, void *param_2, void *param_3, u32 param_4) {
    func_ov000_021a363c(param_1, param_2, strchr(param_3, 0), param_4);
    return strlen(param_3);
}

u32 func_ov000_021a363c(void *param_1, void *param_2, void *param_3, u32 param_4) {
    func_0200d9e0(param_3, 0x1000, data_ov000_021b41f4, param_4, param_1, param_4, param_2);
    return strlen(param_3);
}
