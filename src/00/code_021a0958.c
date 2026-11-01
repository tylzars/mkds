#include "00/code_021a0958.h"
#include "00/code_0218b228.h"
#include "00/code_0218b244.h"
#include "00/code_0218b260.h"
#include "00/code_0218b27c.h"
#include "00/code_0218b570.h"
#include "00/code_0218b64c.h"
#include "00/code_0219887c.h"
#include "00/code_0219a000.h"
#include "00/code_0219d000.h"
#include "00/code_0219dd48.h"
#include "00/code_0219eac8.h"
#include "00/code_0219e000.h"
#include "00/code_021a3264.h"
#include "00/code_021a369c.h"
#include "00/code_021a8e78.h"
#include "00/unk_021b4000.h"
#include "00/unk_021b5000.h"
#include "code_0200d118.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "00/code_0218b458.h"
#include "00/code_0218b4f8.h"
#include "00/code_0219a654.h"
#include "00/code_0219e4e8.h"

s32 func_ov000_021a0958(u8 *a, const u8 *b, s32 c) {
    const u8 *e;
    const u8 *p;
    s32 i;
    s32 n;

    e = func_02139ffc(b, 0);
    for (i = 0; i < c; i++) {
        p = func_02139ffc(b, 0x2f);
        if (p == 0) {
            return -1;
        }
        b = p + 1;
    }
    p = func_02139ffc(b, 0x2f);
    if (p == 0) {
        p = e;
    }
    if (b == p) {
        return -1;
    }
    n = p - b;
    func_0214d1fc(b, a, n);
    a[n] = 0;
    return n;
}

s32 func_ov000_021a09d0(int *a, u32 b, u32 c, const u8 *d) {
    char v1[0x200];
    char *e;
    char *g;
    s32 n;
    s32 i;

    i = func_0200d9e0(v1, 0x200, data_ov000_021b4124, data_ov000_021b412c, 3, data_ov000_021b4134);
    v1[i] = b;
    g = v1 + 1;
    e = g + i;
    g[i] = 0;
    if (d != 0) {
        n = func_0213a434(d);
        func_0214d1fc(d, e, n);
        e[n] = 0;
    }
    return func_ov000_0218e908((Unk0218f960 *) a, c, (const u8 *) v1);
}

u32 func_ov000_021a0a40(u32 a, u32 b, u32 c, u32 *d, u32 e) {
    u32 v1[0x21];
    Unk021a0a40 s;
    u32 r;
    s32 i;

    if (d != 0 && e != 0) {
        func_0214d02c(d, v1, e * 4);
    } else {
        e = 0;
    }
    *(Unk021b40bc *) &s = *(Unk021b40bc *) data_ov000_021b40bc;
    s.mUnk_04 = 3;
    s.mUnk_08 = a;
    s.mUnk_09 = e * 4;
    s.mUnk_0a = data_ov000_021b566c->mUnk_1a;
    s.mUnk_0c = (u32) data_ov000_021b566c->mUnk_1c;
    s.mUnk_10 = data_ov000_021b566c->mUnk_1e8;
    for (i = 0; i < 5; i++) {
        r = func_ov000_0218b530(data_ov000_021b566c->mUnk_e4, func_ov000_0219a760(b, 0, 0), c, (u8 *) &s,
                                s.mUnk_09 + 0x14);
        if (r == 0 || r != 2) {
            break;
        }
    }
    return r;
}

u32 func_ov000_021a0ae8(u32 a, u32 b, u32 c, u32 d, void *e, s32 f) {
    char v1[0x10];
    char v2[0x200];
    u32 *w;
    s32 n;
    s32 k;
    s32 j;

    n = 0;
    if (data_ov000_021b566c->mUnk_15 == 0 ||
        ((data_ov000_021b566c->mUnk_15 == 3 || data_ov000_021b566c->mUnk_19e != 0) && a == 6)) {
        n = func_ov000_021a0a40(a, c, d, e, f);
    } else {
        if (e != 0 && f != 0) {
            w = e;
            n = func_0200d9e0(v2, 0x200, data_ov000_021b40b8, w[0]);
            for (k = 1; k < f; k++) {
                j = func_0200d9e0(v1, 0x10, data_ov000_021b4138, w[k]);
                func_0214d1fc(v1, v2 + n, j);
                n += j;
            }
        }
        v2[n] = 0;
        n = func_ov000_021a09d0(data_ov000_021b566c->mUnk_00, a, b, (u8 *) v2);
    }
    if (a == 2 || a == 6 || (u8) (a + 0xf8) <= 1) {
        data_ov000_021b566c->mUnk_3b4 = a;
        data_ov000_021b566c->mUnk_3b6 = d;
        data_ov000_021b566c->mUnk_3b8 = c;
        data_ov000_021b566c->mUnk_43c = b;
        data_ov000_021b566c->mUnk_440 = f;
        data_ov000_021b566c->mUnk_444 = func_ov000_021a350c();
        if (e != 0 && f != 0) {
            func_0214d02c(e, data_ov000_021b566c->mUnk_3bc, f * 4);
        }
    }
    return n;
}

u32 func_ov000_021a0c30(Unk021a0c30 *a) {
    u32 r;
    s32 i;

    if (a->mUnk_00 == 0) {
        if (func_ov000_0219e594(func_ov000_0218b4f8(data_ov000_021b566c->mUnk_e4, func_ov000_0219a760(a->mUnk_04, 0, 0),
                                                    a->mUnk_02, a->mUnk_08)) != 0) {
            return 2;
        }
    }
    for (i = 0; i < 5; i++) {
        r = func_ov000_0219ac7c(func_ov000_021988d8(*data_ov000_021b566c->mUnk_04), a->mUnk_08, a->mUnk_00,
                                (void (*)(s32, void *)) func_ov000_0219dd48,
                                (void (*)(s32, s32, void *, void *)) func_ov000_0219db18, a);
        if (r == 0 || r != 3) {
            break;
        }
    }
    return r;
}

// non-matching: original keeps the flag in r7 and the return value at [sp, #8] (frame 0x14, 0x22c bytes); ours keeps
// the return value in r6 and the flag at [sp, #8] with an extra stack word (frame 0x1c, 0x238 bytes)
u32 func_ov000_021a0cac(s32 a, s32 b, u32 c) {
    u32 t[2];
    u16 v1;
    u32 k;
    s32 x;
    u32 v2;

    k = data_ov000_021b566c->mUnk_14;
    v2 = 0;
    if (a == 0) {
        b = (data_ov000_021b566c->mUnk_1e8 & 0xffff) | (data_ov000_021b566c->mUnk_176 << 16);
        if (func_ov000_0218b248(c) != 0) {
            if (func_ov000_0218b27c((u32 *) c) == func_ov000_0218b458((int) data_ov000_021b566c->mUnk_e4)) {
                data_ov000_021b566c->mUnk_1f8[k] = func_ov000_0218b244(c);
                data_ov000_021b566c->mUnk_278[k] = func_ov000_0218b228(c);
                x = 0;
            } else {
                x = 1;
            }
        } else {
            v1 = func_ov000_021a8ed4();
            if ((v1 & 0xffff) == 0xa8c0 ||
                ((v1 & 0xff) == 0xac && (v1 & 0xff00) >= 0x1000 && (v1 & 0xff00) <= 0x1f00) || (v1 & 0xff) == 0x10) {
                x = 1;
            } else {
                data_ov000_021b566c->mUnk_1f8[k] = func_ov000_0218b27c((u32 *) c);
                data_ov000_021b566c->mUnk_278[k] = func_ov000_0218b260(c);
                x = 0;
            }
        }
        if (x != 0) {
            data_ov000_021b566c->mUnk_176 = func_ov000_021a3448(0x10000);
            data_ov000_021b566c->mUnk_194 = b;
        } else {
            t[0] = func_ov000_021a8ed4();
            t[1] = func_ov000_021988e4(*data_ov000_021b566c->mUnk_04);
            v2 = func_ov000_021a0ae8(6, data_ov000_021b566c->mUnk_f4[k], func_ov000_0218b27c((u32 *) c),
                                     func_ov000_0218b260(c), t, 2);
            data_ov000_021b566c->mUnk_3b5 = 0;
            if (v2 != 0) {
                return 2;
            }
            data_ov000_021b566c->mUnk_194 = 0;
        }
        data_ov000_021b566c->mUnk_18c[0] = 0;
        data_ov000_021b566c->mUnk_18c[1] = 0;
        *(u16 *) &data_ov000_021b566c->mUnk_18c[2] = func_ov000_0218b260(c);
        *(u32 *) &data_ov000_021b566c->mUnk_18c[4] = func_ov000_0218b27c((u32 *) c);
    } else {
        x = 1;
        data_ov000_021b566c->mUnk_18c[0] = 1;
        data_ov000_021b566c->mUnk_18c[1] = v2;
        *(u16 *) &data_ov000_021b566c->mUnk_18c[2] = v2;
        *(u32 *) &data_ov000_021b566c->mUnk_18c[4] = v2;
        data_ov000_021b566c->mUnk_194 = b;
    }
    if (x != 0) {
        v2 = func_ov000_021a0c30((Unk021a0c30 *) data_ov000_021b566c->mUnk_18c);
    } else {
        func_ov000_0219db18(0, func_ov000_021988d8(*data_ov000_021b566c->mUnk_04), 0, data_ov000_021b566c->mUnk_18c);
        data_ov000_021b566c->mUnk_184 = 0;
    }
    return v2;
}

s32 func_ov000_021a0ed8(u8 *a, s32 b, s32 c, s32 d) {
    return func_0200d9e0((char *) a, 0x100, data_ov000_021b413c, data_ov000_021b4108, 3, data_ov000_021b40c4, b, c, c,
                         data_ov000_021b40f0, d, data_ov000_021b40fc, data_ov000_021b40c4);
}

u32 func_ov000_021a0f20(u32 a) {
    char v1[0x100];
    u8 v2[0xa8];
    s32 i;
    u8 *e;
    u8 *w;
    u32 n;
    u32 r;

    n = 7;
    v2[0] = 8;
    v2[1] = 0xa;
    v2[2] = 0x32;
    v2[3] = 0x33;
    v2[4] = 0x34;
    v2[5] = 0x35;
    v2[6] = 0x36;
    if (data_ov000_021b566c->mUnk_15 == 0 || data_ov000_021b566c->mUnk_15 == 1) {
        i = 0;
        e = data_ov000_021b5698[0];
        w = v2 + 7;
        for (; i < 0x9a; i++) {
            if (e[0] != 0) {
                *w = e[0];
                w++;
                n++;
            }
            e += 12;
        }
    }
    switch (data_ov000_021b566c->mUnk_198) {
        case 3:
            a = data_ov000_021b566c->mUnk_1f0;
            if (a == 0) {
                func_ov000_021a0ed8((u8 *) v1, data_ov000_021b566c->mUnk_1e8, data_ov000_021b566c->mUnk_16,
                                    data_ov000_021b566c->mUnk_15);
                if (data_ov000_021b5674 != 0) {
                    func_0200d9e0(v1, 0x100, data_ov000_021b4194, v1, data_ov000_021b5674);
                }
                break;
            }
        case 2:
        case 4:
        case 5:
            func_0200d9e0(v1, 0x100, data_ov000_021b41a0, data_ov000_021b40c4, a);
            data_ov000_021b566c->mUnk_1ec = a;
            break;
    }
    func_ov000_0218b48c(data_ov000_021b566c->mUnk_e4);
    for (i = 0; i < 5; i++) {
        r = func_ov000_0218b570((u32) data_ov000_021b566c->mUnk_e4, 1, 0, (u32) v2, n, (u32) v1, 0x10);
        if (r == 0 || r != 2) {
            break;
        }
    }
    return r;
}

void func_ov000_021a104c(void) {
    if (data_ov000_021b566c != 0) {
        if (data_ov000_021b566c->mUnk_e4 != 0) {
            func_ov000_0218b64c(data_ov000_021b566c->mUnk_e4);
            data_ov000_021b566c->mUnk_e4 = 0;
        }
        func_ov000_0219b110();
        data_ov000_021b566c->mUnk_198 = 0;
        if (data_ov000_021b5674 != 0) {
            func_ov000_021a3704(4, (u32) data_ov000_021b5674, 0);
            data_ov000_021b5674 = 0;
        }
        func_ov000_0219ea88();
        data_ov000_021b566c->mUnk_18 = 1;
    }
}
