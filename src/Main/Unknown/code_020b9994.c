#include "Main/Unknown/code_0204a5f8.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_020b33d8.h"
#include "Main/Unknown/code_020b9994.h"

#include "Main/Unknown/code_020d0280.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020b85dc.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b3000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020a2204.h"
#include "Main/Unknown/code_020a10d4.h"
#include "Main/Unknown/code_020a1000.h"
#include "01/code_0218155c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_0204a000.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_020ba50c.h"

u32 func_020ba50c(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217b3c8;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

void func_020ba3ec(void) {
    s32 v;

    v = data_021759c0->mUnk_08;
    switch (v) {
        case 4:
            data_0217b3c8->mUnk_00 = v == 4 ? func_ov001_02181820() : 0;
            break;
        case 2:
            if (data_021759c0->mUnk_18 == 0) {
                if (func_020a2204(func_020b4d9c()) != 0) {
                    data_0217b3c8->mUnk_00_h[0] += 1;
                    if (data_0217b3c8->mUnk_00_h[0] >= 9) {
                        data_0217b3c8->mUnk_00_h[0] = 0;
                    }
                } else {
                    data_0217b3c8->mUnk_00_h[0] = 0;
                }
                data_0217b3c8->mUnk_00_h[1] = func_020a10d4(func_020b4d9c());
            } else {
                data_0217b3c8->mUnk_00_h[0] = func_020a1154(func_020b4d9c());
            }
            break;
        case 1:
            break;
        default:
            data_0217b3c8->mUnk_00 = func_0203c8dc(func_020b4d9c()) - 1;
            break;
    }
}

void func_020b9dfc(Unk020d029c *p) {
    s32 a[2];
    s32 b[2];
    s32 c[2];
    s32 d[2];
    s32 e[2];
    s32 f[2];
    s32 g[2];
    s32 h[2];
    s32 j[2];
    u16 k;
    u16 n;
    s32 i;
    s32 l;
    Unk020224e0_o *q;
    Unk020224e0_c *t;

    if (data_021759c0->mUnk_00c == 4) {
        return;
    }
    if (data_021759c0->mUnk_00c == 1) {
        return;
    }
    switch (data_021759c0->mUnk_08) {
        case 4:
            func_020b9994(p);
            return;
        case 2:
            if (func_0203c880(func_020b4d9c()) == 0) {
                if (data_021759c0->mUnk_18 == 0) {
                    i = 0;
                    n = data_0217b3c8->mUnk_00_h[1];
                    k = data_0217b3c8->mUnk_00_h[0];
                    for (; i < n; i++) {
                        t = GetRaceBattleMNcerEntry(10);
                        b[0] = (0xfe - i * 0xe) << 12;
                        b[1] = 0xc000;
                        p->mUnk_400 += func_020224e0(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, b, 0, 1);
                    }
                    if (k == 0) {
                        return;
                    }
                    if (k >= 6) {
                        return;
                    }
                    t = GetRaceBattleMNcerEntry(10);
                    c[0] = (0xfe - i * 0xe) << 12;
                    c[1] = 0xc000;
                    p->mUnk_400 += func_020224e0(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, c, 0, 1);
                } else {
                    i = func_020b33f4() % 16;
                    if (func_020a1048(func_020b4d9c()) != 0 && i >= 10) {
                        return;
                    }
                    n = data_0217b3c8->mUnk_00_h[0];
                    t = GetRaceBattleMNcerEntry(0xb);
                    d[0] = 0xcd000;
                    d[1] = 0xf000;
                    p->mUnk_400 += func_020224e0(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, d, 0, 1);
                    t = GetRaceBattleMNcerEntry(n / 10);
                    e[0] = 0xe1000;
                    e[1] = 0x10000;
                    p->mUnk_400 += func_020224e0(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, e, 0, 1);
                    t = GetRaceBattleMNcerEntry(n % 10);
                    f[0] = 0xf0000;
                    f[1] = 0x10000;
                    p->mUnk_400 += func_020224e0(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, f, 0, 1);
                }
            } else {
                if (data_0217561c->mUnk_000[func_020b4d9c()].mUnk_14 != 2) {
                    return;
                }
                if ((func_0207a974(func_020b4d9c())->mUnk_7c & 0x402000) == 0) {
                    return;
                }
                t = GetRaceBattleMNcerEntry(0xc);
                a[0] = 0x80000;
                a[1] = 0x60000;
                p->mUnk_400 += func_020224e0(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, a, 0, 1);
            }
            break;
        case 1:
            if (data_02175628[0].mUnk_3c != 2) {
                return;
            }
            if (func_0204a650(&data_02175650[0]) == 0) {
                return;
            }
            data_0217b3c8->mUnk_08 = 0;
            t = GetRaceTaMNcerEntry(0xd);
            l = p->mUnk_400;
            g[0] = 0x80000;
            g[1] = 0x60000;
            q = &p->mUnk_000[l];
            p->mUnk_400 += func_020224e0(q, 0x80 - l, t, NULL, g, 0, 1);
            for (; l < p->mUnk_400; l++, q++) {
                ((u32 *) q)[0] = (((u32 *) q)[0] & ~0xc00) | 0x800;
                ((u32 *) q)[1] = (((u32 *) q)[1] & ~0xc00) | 0x400;
            }
            t = GetRaceTaMNcerEntry(0xd);
            h[0] = 0x80000;
            h[1] = 0x60000;
            p->mUnk_400 += func_020224e0(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, h, 0, 1);
            break;
        default:
            t = GetRaceMNcerEntry(data_0217b3c8->mUnk_00);
            j[0] = 0x18000;
            j[1] = 0xa8000;
            p->mUnk_400 += func_020224e0(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, j, 0, 1);
            break;
    }
}

void func_020b9994(Unk020d029c *p) {
    s32 a[2];
    s32 b[2];
    s32 c[2];
    s32 d[2];
    s32 e[2];
    s32 f[2];
    s32 g[2];
    s32 h[2];
    s32 i[2];
    s32 m;
    s32 n;
    Unk0217b3c8 *q;
    Unk020224e0_c *t;

    q = data_0217b3c8;
    n = q->mUnk_04;
    if (n <= 0) {
        return;
    }
    m = q->mUnk_00;
    if (m > n) {
        m = n;
    }
    t = GetRaceMrMNcerEntry(0x15);
    a[0] = 0xc000;
    a[1] = 0xb0000;
    p->mUnk_400 += func_020224e0(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, a, 0, 1);
    if (data_0217b3c8->mUnk_04 >= 10) {
        t = GetRaceMrMNcerEntry(m / 10);
        b[0] = 0x1b000;
        b[1] = 0xb4000;
        p->mUnk_400 += func_020224e0(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, b, 0, 1);
        t = GetRaceMrMNcerEntry(m % 10);
        c[0] = 0x2e000;
        c[1] = 0xb4000;
        p->mUnk_400 += func_020224e0(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, c, 0, 1);
        t = GetRaceMrMNcerEntry(10);
        d[0] = 0x42000;
        d[1] = 0xb4000;
        p->mUnk_400 += func_020224e0(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, d, 0, 1);
        t = GetRaceMrMNcerEntry(n / 10 + 0xb);
        e[0] = 0x4d000;
        e[1] = 0xb4000;
        p->mUnk_400 += func_020224e0(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, e, 0, 1);
        t = GetRaceMrMNcerEntry(n % 10 + 0xb);
        f[0] = 0x5b000;
        f[1] = 0xb4000;
        p->mUnk_400 += func_020224e0(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, f, 0, 1);
    } else {
        t = GetRaceMrMNcerEntry(m % 10);
        g[0] = 0x1b000;
        g[1] = 0xb4000;
        p->mUnk_400 += func_020224e0(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, g, 0, 1);
        t = GetRaceMrMNcerEntry(10);
        h[0] = 0x2f000;
        h[1] = 0xb4000;
        p->mUnk_400 += func_020224e0(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, h, 0, 1);
        t = GetRaceMrMNcerEntry(n % 10 + 0xb);
        i[0] = 0x3a000;
        i[1] = 0xb4000;
        p->mUnk_400 += func_020224e0(&p->mUnk_000[p->mUnk_400], 0x80 - p->mUnk_400, t, NULL, i, 0, 1);
    }
}
