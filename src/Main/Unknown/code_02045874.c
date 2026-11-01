#include "Main/Unknown/code_02045874.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/code_02029aa0.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_0204a000.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"

extern const u32 data_usa_021540c0[];
extern const u32 data_usa_021540c8[];
extern const u32 data_usa_021540d4[];
extern const u32 data_usa_02154108[];

s32 func_02045874(void) {
    data_0217b488->mUnk_5c[data_021759c0->mUnk_60] = data_021759c0->mUnk_00;
    data_021759c0->mUnk_1e8.mUnk_60++;
    return data_021759c0->mUnk_1e8.mUnk_60 <= 4;
}

s32 func_020458cc(void) {
    if (data_021759d0->mUnk_1c_2) {
        data_021759c0->mUnk_1e8.mUnk_0c = 0;
    } else {
        data_021759c0->mUnk_1e8.mUnk_0c = 4;
    }
    return func_02045920();
}

s32 func_02045914(void) {
    return func_02045920();
}

// non-matching: size 0x114 against 0x10c; the original keeps the constant 1 (the return value) in r0 for the store in
// the loop and branches around a single moveq, ours uses separate registers for 1 and 0 and predicates both
s32 func_02045920(void) {
    s32 r;
    s32 i;
    s32 v;
    s32 x;
    r = 1;
    data_021759c0->mUnk_1e8.mUnk_60++;
    if (data_021759c0->mUnk_3d4 > 1) {
        for (i = 0; i < data_021759c0->mUnk_3d0; i++) {
            x = data_021759c0->mUnk_68[i].mUnk_08.mUnk_08;
            v = 3;
            if (x == 0) {
                v = 1;
            } else if (x == 1) {
                v = 0;
            }
            data_021759c0->mUnk_250[i].mUnk_08.mUnk_08 = v;
        }
    }
    switch (data_021759c0->mUnk_020) {
        case 0:
            return 0;
        case 1:
        case 2:
            data_021759c0->mUnk_3e0++;
            if (data_021759c0->mUnk_3dc[data_021759c0->mUnk_3e0] == 0) {
                data_021759c0->mUnk_3e0 = 0;
            }
            data_021759c0->mUnk_1e8.mUnk_00 = data_021759c0->mUnk_3dc[data_021759c0->mUnk_3e0];
            return r;
        default:
            return r;
    }
}

void func_02045a2c(s32 a) {
    u8 i;
    s8 j;
    s32 x;
    s32 y;
    if (a != 0) {
        data_021759c0->mUnk_1e8.mUnk_00 = 0x36;
    } else {
        data_021759c0->mUnk_1e8.mUnk_00 = 0x35;
    }
    data_021759c0->mUnk_1e8.mUnk_0c = 6;
    data_021759c0->mUnk_1e8.mUnk_10 = 1;
    data_021759c0->mUnk_1e8.mUnk_63 = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < data_021759c0->mUnk_3d0; j++) {
            if (func_0205d4e8((u16) j) == i + 1) {
                break;
            }
        }
        if (data_021759c0->mUnk_08 == 4) {
            if ((data_021759c0->mUnk_08 == 4 ? data_021759c0->mUnk_54 : -1) == 6 &&
                (data_021759c0->mUnk_08 == 4 ? data_021759c0->mUnk_55 : -1) == 9) {
                if (i == 0) {
                    x = 7;
                    y = 0x15;
                } else if (i == 7) {
                    x = 0;
                    y = x;
                } else {
                    x = i;
                    y = i * 3;
                }
            } else {
                x = i;
                y = i * 3;
            }
        } else if (data_021759c0->mUnk_08 == 0) {
            if (func_020909cc() != 2) {
                x = i;
                y = i * 3;
            } else {
                x = data_0217b488->mUnk_ac[i];
                y = data_0217b488->mUnk_cc[i];
            }
        } else {
            x = i;
            y = i * 3;
        }
        func_020468b0(i, x, y, 1, -1, 3);
    }
}

// non-matching: 3 instructions swapped at the mUnk_a8 load; the original does mla (b * 0x50 + base) before mul (c *
// 10), ours mul then mla
s32 func_02045bd4(void) {
    s8 t;
    u8 i;
    s8 j;
    u8 b;
    u32 c;
    s32 n;
    t = data_021759c0->mUnk_62;
    data_0217b488->mUnk_7c = func_0205d4e8((u16) t) - 1;
    data_0217b488->mUnk_80 = func_0205d190();
    data_0217b488->mUnk_90 = data_021759c0->mUnk_68[(u8) t].mUnk_00;
    data_0217b488->mUnk_84 = data_021759c0->mUnk_004;
    data_0217b488->mUnk_88 = data_021759c0->mUnk_010;
    data_0217b488->mUnk_8c = data_021759c0->mUnk_57;
    c = func_0205dc7c((u8) t);
    b = func_0205db28();
    c = func_0205dc7c(c);
    data_0217b488->mUnk_a8 = data_0217aa1c->mUnk_000[b][c].mUnk_00;
    data_0217b488->mUnk_94 = data_021759c0->mUnk_68[(u8) t].mUnk_04;
    for (i = 0; i < 4; i++) {
        Unk0217aa1c_144_00 d;
        func_0205d7c8(&d, (u16) data_021759c0->mUnk_62, i);
        data_0217b488->mUnk_98[i] = d;
    }
    if ((u32) func_0205d4e8((u16) data_021759c0->mUnk_62) > 3) {
        return 0;
    }
    data_021759c0->mUnk_1e8.mUnk_00 = 0x34;
    data_021759c0->mUnk_1e8.mUnk_0c = 5;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < data_021759c0->mUnk_3d0; j++) {
            if (func_0205d4e8((u16) j) == i + 1) {
                break;
            }
        }
        func_020468b0(i, data_021759c0->mUnk_68[(u16) j].mUnk_00, data_021759c0->mUnk_68[(u16) j].mUnk_04, 1, -1, 3);
    }
    for (; i < 8; i++) {
        func_020468b0(i, i, i * 3, 4, -1, 3);
    }
    for (i = 0; i < 8; i++) {
        n = func_0205d4e8(i) - 1;
        data_0217b488->mUnk_cc[n] = data_021759c0->mUnk_68[i].mUnk_04;
        data_0217b488->mUnk_ac[n] = data_021759c0->mUnk_68[i].mUnk_00;
    }
    data_021759c0->mUnk_1e8.mUnk_63 = func_0205d4e8((u16) data_021759c0->mUnk_62) - 1;
    return 1;
}

void func_02045ed0(void) {
    u8 i;
    u8 r;
    func_02046594();
    switch (data_021759c0->mUnk_1e8.mUnk_08) {
        case 0:
            func_0205db50();
            data_021759c0->mUnk_1e8.mUnk_60 = 1;
            data_021759c0->mUnk_1e8.mUnk_0c = 3;
            data_021759c0->mUnk_1e8.mUnk_00 =
                data_02154128[data_021759c0->mUnk_1e8.mUnk_04][data_021759c0->mUnk_1e8.mUnk_60 - 1];
            break;
        case 3:
            func_02046024(1);
            break;
        case 2:
            func_02046024(0);
            break;
        case 5:
            r = 0xff;
            func_0205db50();
            data_021759c0->mUnk_1e8.mUnk_60 = 1;
            data_021759c0->mUnk_1e8.mUnk_0c = 0;
            for (i = 0; i < 4; i++) {
                if (data_021759c0->mUnk_250[i].mUnk_08.mUnk_00 == 0) {
                    r = i;
                    break;
                }
            }
            data_021759c0->mUnk_1e8.mUnk_63 = r;
            break;
        case 4:
            func_0205db50();
            if (data_021759c0->mUnk_1e8.mUnk_55 == 9) {
                data_021759c0->mUnk_1e8.mUnk_0c = 3;
            } else {
                data_021759c0->mUnk_1e8.mUnk_0c = 0;
            }
            data_021759c0->mUnk_1e8.mUnk_60 = 1;
            break;
    }
}

static inline u32 func_02046524_inline(Unk020f41c4_B *a, u32 b) {
    u64 r;
    if (b == 0) {
        r = 0;
    } else {
        a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
        if (b == 0) {
            r = a->mUnk_00 >> 32;
        } else {
            r = ((a->mUnk_00 >> 32) * b) >> 32;
        }
    }
    return (u16) r;
}

// non-matching: size 0x4ec against 0x500; the original keeps different registers in the two case 1 loops (index and
// counter in r9/r8 and r1, ours r7/r6 and r2) and holds a zero constant in r4 where ours spills it to the stack offset
// 0, and it differs again in the case 2 shuffle loops
void func_02046024(s32 a) {
    s32 f;
    u32 m;
    const u32 *t;
    u32 i;
    u32 n;
    f = 0;
    func_0205db50();
    data_021759c0->mUnk_3e0 = 0;
    data_021759c0->mUnk_1e8.mUnk_60 = 1;
    if (a != 0) {
        data_021759c0->mUnk_1e8.mUnk_0c = 0;
    } else if (data_021759d0->mUnk_1c_2) {
        data_021759c0->mUnk_1e8.mUnk_0c = 0;
    } else {
        data_021759c0->mUnk_1e8.mUnk_0c = 4;
    }
    for (i = 0; i < 0x21; i++) {
        data_021759c0->mUnk_3dc[i] = 0;
    }
    switch (data_021759d0->mUnk_20) {
        case 1:
        case 2:
            f = (data_0217aa00->mUnk_0454 & 0x40) != 0;
            break;
    }
    switch (data_021759c0->mUnk_1e8.mUnk_20) {
        case 1:
            if (a != 0) {
                u8 p;
                u8 q;
                s32 e;
                s32 k;
                s32 c;
                m = f != 0 ? 2 : 8;
                t = f != 0 ? data_usa_021540c0 : data_usa_02154108;
                e = data_021759c0->mUnk_1e8.mUnk_00;
                n = m * 4;
                for (k = 0; k < n; k++) {
                    p = k / 4;
                    q = k % 4;
                    if (e == data_02154128[t[p]][q]) {
                        break;
                    }
                }
                c = 0;
                for (k = 0; k < n; k++) {
                    if (func_02046648(t[p]) != 0) {
                        data_021759c0->mUnk_3dc[c] = data_02154128[t[p]][q];
                        c = (u8) (c + 1);
                    }
                    q = q + 1;
                    if (q >= 4) {
                        p = p + 1;
                        if (p >= m) {
                            p = 0;
                        }
                        q = 0;
                    }
                }
                return;
            } else {
                s32 e;
                u32 k;
                u32 s;
                n = f != 0 ? 3 : 6;
                t = f != 0 ? data_usa_021540c8 : data_usa_021540d4;
                e = data_021759c0->mUnk_1e8.mUnk_00;
                s = 0;
                for (k = 0; k < n; k++) {
                    s = k;
                    if (e == t[k]) {
                        break;
                    }
                }
                for (k = 0; k < n; k++) {
                    data_021759c0->mUnk_3dc[k] = t[s];
                    s++;
                    if (s >= n) {
                        s = 0;
                    }
                }
                return;
            }
        case 2:
            if (a != 0) {
                Unk020f41c4_B *g;
                u32 k;
                s32 c;
                u8 p;
                u8 q;
                s32 h;
                s32 z;
                u8 w;
                u8 x;
                g = (Unk020f41c4_B *) func_0204aa60();
                c = 0;
                m = f != 0 ? 2 : 8;
                t = f != 0 ? data_usa_021540c0 : data_usa_02154108;
                n = m * 4;
                for (k = 0; k < n; k++) {
                    p = k / 4;
                    q = k % 4;
                    if (func_02046648(t[p]) != 0) {
                        data_021759c0->mUnk_3dc[c] = data_02154128[t[p]][q];
                        c = (u8) (c + 1);
                    }
                }
                h = c * 2;
                for (z = 0; z < h; z++) {
                    w = func_02046524(g, (u16) (c - 1));
                    x = z % c;
                    if (w >= x) {
                        w = w + 1;
                    }
                    {
                        u8 y = data_021759c0->mUnk_3dc[x];
                        data_021759c0->mUnk_3dc[x] = data_021759c0->mUnk_3dc[w];
                        data_021759c0->mUnk_3dc[w] = y;
                    }
                }
            } else {
                u32 k;
                u32 z;
                Unk020f41c4_B *g;
                g = (Unk020f41c4_B *) func_0204aa60();
                n = f != 0 ? 3 : 6;
                t = f != 0 ? data_usa_021540c8 : data_usa_021540d4;
                for (k = 0; k < n; k++) {
                    data_021759c0->mUnk_3dc[k] = t[k];
                }
                if (n > 0) {
                    for (z = 0; z < n; z++) {
                        u8 w;
                        u8 y;
                        w = func_02046524_inline(g, (u16) (n - 1));
                        if (w >= z) {
                            w = w + 1;
                        }
                        y = data_021759c0->mUnk_3dc[z];
                        data_021759c0->mUnk_3dc[z] = data_021759c0->mUnk_3dc[w];
                        data_021759c0->mUnk_3dc[w] = y;
                    }
                }
            }
            data_021759c0->mUnk_1e8.mUnk_00 = data_021759c0->mUnk_3dc[0];
            break;
    }
}

u32 func_02046524(Unk020f41c4_B *a, u32 b) {
    u64 r;
    if (b == 0) {
        r = 0;
    } else {
        a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
        if (b == 0) {
            r = a->mUnk_00 >> 32;
        } else {
            r = ((a->mUnk_00 >> 32) * b) >> 32;
        }
    }
    return (u16) r;
}

void func_02046594(void) {
    u8 k;
    s32 f;
    u8 i;
    k = 1;
    f = 0;
    switch (data_021759c0->mUnk_1e8.mUnk_08) {
        case 0:
        case 1:
        case 4:
        case 5:
            f = 1;
            break;
    }
    for (i = 0; i < 8; i++) {
        if (f == 0 && data_021759c0->mUnk_250[i].mUnk_08.mUnk_00 == 1) {
            data_021759c0->mUnk_250[i].mUnk_08.mUnk_16 = k;
            k = k + 1;
        } else {
            data_021759c0->mUnk_250[i].mUnk_08.mUnk_16 = -1;
        }
    }
    data_021759c0->mUnk_3e1 = k;
}

s32 func_02046648(s32 a) {
    u32 n;
    n = (u8) data_021759c0->mUnk_1e8.mUnk_10;
    if (data_021759c0->mUnk_1e8.mUnk_57 != 0) {
        n = 3;
    }
    switch (a) {
        case 0:
        case 1:
        case 4:
        case 5:
            return 1;
        case 2:
            if (func_0205fbb8(n)) {
                return 1;
            }
            break;
        case 3:
            if (func_0205fbb8(n + 4)) {
                return 1;
            }
            break;
        case 6:
            if (func_0205fbb8(n + 8)) {
                return 1;
            }
            break;
        case 7:
            if (func_0205fbb8(n + 12)) {
                return 1;
            }
            break;
    }
    return 0;
}
