#include "00/code_021988e8.h"
#include "00/code_021a1ae0.h"
#include "00/code_021a2ccc.h"
#include "03/code_021b94b8.h"
#include "Main/Unknown/code_0200f000.h"

#include "00/code_0219b8bc.h"
#include "00/unk_021b5000.h"
#include "00/code_0219c39c.h"
#include "00/code_021a1000.h"
#include "00/code_021a2000.h"
#include "00/code_021a31d4.h"
#include "code_0200f5ac.h"
#include "code_0200fd1c.h"
#include "code_0214d018.h"
#include "00/code_0219b000.h"
#include "00/code_0219bb50.h"
#include "code_021329f8.h"

void func_ov000_021a317c(Unk0219887c *a, void *b, s32 c, u32 d) {
    if (data_ov000_021b5dd0 != NULL) {
        if (d != 0) {
            func_ov000_021a2eec(a, b, c);
        } else {
            func_ov000_021a2e7c(a, (u32) b, c);
        }
    }
}

void func_ov000_021a314c(Unk0219887c *a, u32 b) {
    if (data_ov000_021b5dd0->mUnk_60c != NULL) {
        data_ov000_021b5dd0->mUnk_60c(b, func_ov000_0219b9c4(a));
    }
}

void func_ov000_021a3030(void) {
    u8 *l;
    s32 n;
    s32 i;
    u8 d;
    Unk021a2d68 *e;
    s32 m;
    s32 k;
    u64 t;
    if (data_ov000_021b5dd0 != NULL) {
        n = func_ov000_0219bb04(&l);
        for (i = 0; i < n; i++) {
            d = l[i];
            if (d != func_ov000_0219bb50() && func_ov000_021a2fc8(d) == 1) {
                e = func_ov000_021a2fdc(d);
                m = e->mUnk_14 - e->mUnk_0c;
                k = data_ov000_021b5dd0->mUnk_610;
                if (m <= k) {
                    k = m;
                }
                if (func_ov000_021a2d18(d) < k) {
                    continue;
                }
                func_ov000_021a2f98(d, (u32) (e->mUnk_00 + e->mUnk_0c), k, 1);
                e->mUnk_0c += k;
                if (e->mUnk_0c == e->mUnk_14) {
                    if (data_ov000_021b5dd0->mUnk_600 != NULL) {
                        data_ov000_021b5dd0->mUnk_600(e->mUnk_14, d);
                    }
                    e->mUnk_1c = 0;
                    e->mUnk_00 = NULL;
                    e->mUnk_0c = 0;
                    e->mUnk_14 = 0;
                }
            }
            if (func_ov000_0219bac8(d) != 0) {
                e = func_ov000_021a2fdc(d);
                if (data_ov000_021b5dd0->mUnk_608 != NULL && e->mUnk_2c != 0) {
                    t = func_0200f5ac();
                    if ((u32) _ll_udiv((t - e->mUnk_24) << 6, 0x82ea) > e->mUnk_2c) {
                        data_ov000_021b5dd0->mUnk_608(d);
                        e->mUnk_24 = t;
                    }
                }
            }
        }
    }
}

void func_ov000_021a2ff8(int a) {
    if (data_ov000_021b5dd0 != NULL) {
        data_ov000_021b5dd0->mUnk_000[a].mUnk_0c = 0;
        data_ov000_021b5dd0->mUnk_000[a].mUnk_10 = 0;
        data_ov000_021b5dd0->mUnk_000[a].mUnk_14 = 0;
        data_ov000_021b5dd0->mUnk_000[a].mUnk_18 = 0;
        data_ov000_021b5dd0->mUnk_000[a].mUnk_1c = 0;
        data_ov000_021b5dd0->mUnk_000[a].mUnk_22 = 0;
    }
    return;
}

void func_ov000_021a2fec(void) {
    data_ov000_021b5dd0 = NULL;
    return;
}

Unk021a2d68 *func_ov000_021a2fdc(int a) {
    return &data_ov000_021b5dd0->mUnk_000[a];
}

u8 func_ov000_021a2fc8(int a) {
    return data_ov000_021b5dd0->mUnk_000[a].mUnk_1c;
}

u8 func_ov000_021a2fb4(int a) {
    return data_ov000_021b5dd0->mUnk_000[a].mUnk_1d;
}

void func_ov000_021a2f98(u32 a, u32 b, u32 c, u32 d) {
    u32 v1;
    v1 = func_ov000_0219b9d4(a);
    func_ov000_02198914((Unk02197fe8 *) v1, (u8 *) b, c, d);
    return;
}

void func_ov000_021a2eec(Unk0219887c *a, void *b, s32 c) {
    u8 v1 = func_ov000_0219b9c4(a);
    switch (func_ov000_021a2fb4(v1)) {
        case 0: {
            u16 n = func_ov000_021a31e8(b);
            if (n >= 2 && n <= 4) {
                func_ov000_021a2dfc(v1, b, c);
            }
            break;
        }
        case 1:
            func_ov000_021a2dfc(v1, b, c);
            break;
        case 2:
            func_ov000_021a2d68(v1, b, c);
            break;
        case 3:
            func_ov000_021a2d38(v1, b, c);
            break;
        case 4:
            data_ov000_021b5dd0->mUnk_000[v1].mUnk_1d = 1;
            data_ov000_021b5dd0->mUnk_000[v1].mUnk_10 = 0;
            data_ov000_021b5dd0->mUnk_000[v1].mUnk_18 = 0;
            break;
        default:
            func_0200fd1c();
            break;
    }
}

void func_ov000_021a2e7c(Unk0219887c *a, u32 b, int c) {
    int v1;
    u32 v2;
    u64 v3;
    v1 = func_ov000_0219b9c4(a);
    v2 = (s32) data_ov000_021b5dd0 + v1 * 0x30;
    if ((*(s32 *) (v2 + 4) != 0) && (*(s32 *) (v2 + 8) >= c)) {
        func_0214d1fc((u16 *) b, (u32 *) (*(s32 *) (v2 + 4)), c);
        if (data_ov000_021b5dd0->mUnk_604 != NULL) {
            data_ov000_021b5dd0->mUnk_604(v1, (u8 *) *(u32 *) (v2 + 4), c);
        }
        if ((data_ov000_021b5dd0->mUnk_608 != NULL) && (*(s32 *) (v2 + 0x2c) != 0)) {
            v3 = func_0200f5ac();
            *(u64 *) (v2 + 0x24) = v3;
        }
    }
}

void func_ov000_021a2dfc(int a, void *b, s32 c) {
    Unk021a2d68 *e = &data_ov000_021b5dd0->mUnk_000[a];
    u32 t[2];
    u16 n;
    e->mUnk_1e = func_ov000_021a2fb4(a);
    n = func_ov000_021a31e8(b);
    switch (n) {
        case 1:
            if (c != 8) {
                return;
            }
            func_0214d1fc(b, t, 8);
            e->mUnk_18 = t[0];
            e->mUnk_10 = 0;
            if (e->mUnk_04 != NULL && e->mUnk_08 >= e->mUnk_18) {
                e->mUnk_1d = 2;
            } else {
                e->mUnk_1d = 4;
            }
            break;
        case 2:
        case 3:
        case 4:
            e->mUnk_1d = 3;
            break;
    }
    e->mUnk_22 = n;
}

void func_ov000_021a2d68(int a, void *b, s32 c) {
    Unk021a2d68 *e = &data_ov000_021b5dd0->mUnk_000[a];
    s32 n;
    if (func_ov000_021a2fb4(a) == 2) {
        if (e->mUnk_10 + c > e->mUnk_08) {
            func_0200fd1c();
        }
        func_0214d1fc(b, e->mUnk_04 + e->mUnk_10, c);
    }
    e->mUnk_10 += c;
    n = e->mUnk_18;
    if (e->mUnk_10 == n) {
        e->mUnk_1d = 1;
        e->mUnk_10 = 0;
        e->mUnk_18 = 0;
        if (data_ov000_021b5dd0->mUnk_604 != NULL) {
            data_ov000_021b5dd0->mUnk_604(a, e->mUnk_04, n);
        }
    }
    if (data_ov000_021b5dd0->mUnk_608 != NULL && e->mUnk_2c != 0) {
        e->mUnk_24 = func_0200f5ac();
    }
}

void func_ov000_021a2d38(u32 a, void *b, s32 c) {
    Unk021a2d68 *e = func_ov000_021a2fdc(a);
    e->mUnk_1d = e->mUnk_1e;
    switch (e->mUnk_22) {
        case 2:
        case 3:
        case 4:
            func_ov000_021a18e0(a, e->mUnk_22, b);
            break;
    }
}

s32 func_ov000_021a2d18(u32 a) {
    s32 n = func_ov000_021988dc(func_ov000_0219b9d4(a)) - 0x207;
    if (n <= 0) {
        n = 0;
    }
    return n;
}

BOOL func_ov000_021a2ccc(void) {
    if (data_ov000_021b566c == NULL || data_ov000_021b566c->mUnk_1e8 == 0 || func_ov000_0219c39c() != 0) {
        return FALSE;
    }
    if (func_ov000_021a2768(data_ov000_021b566c->mUnk_1e8) == 0) {
        return TRUE;
    }
    return FALSE;
}
