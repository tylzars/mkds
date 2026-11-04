#include "00/code_0219d128.h"
#include "00/code_0219e4e8.h"
#include "00/code_0219f4c4.h"
#include "00/code_021a10b0.h"
#include "00/code_021a1000.h"
#include "00/code_021a4000.h"
#include "00/code_021a4b84.h"
#include "00/unk_021b4000.h"
#include "00/unk_021b5000.h"
#include "00/code_0219d000.h"
#include "00/code_021a3000.h"
#include "code_0200d118.h"

#include "00/code_02188720.h"
#include "00/code_021a3264.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "00/code_0219e000.h"
#include "03/code_021b94b8.h"
#include "00/code_021a369c.h"
#include "00/code_0219de4c.h"
#include "00/code_0219f9bc.h"

void func_ov000_021a1798(u32 value) {
    if (data_ov000_021b566c->mUnk_1a0 != 2) {
        func_ov000_0219f9bc(value);
    }
}

u32 func_ov000_021a1754(int a, int b) {
    int v1;
    int v2;
    v2 = *(s32 *) &data_ov000_021b566c;
    if (0 == v2) {
        return 0;
    }
    v1 = 0;
    if (0 < b) {
        do {
            if (a == *(s32 *) (v2 + 0xf4)) {
                func_ov000_021a1620(v1, b);
                return 1;
            }
            v2 = v2 + 4;
            v1 = v1 + 1;
        } while (v1 < b);
    }
    return 0;
}

u32 func_ov000_021a1620(s32 b, s32 c) {
    Unk021b566c *p;
    u32 v1;
    u32 *m;
    s32 i;
    s32 n;
    s32 k;
    p = data_ov000_021b566c;
    if (p == NULL) {
        return 0;
    }
    v1 = p->mUnk_f4[b];
    m = &p->mUnk_2d8;
    *m = *m & ~(1 << p->mUnk_2b8[b]);
    func_ov000_021a15b0();
    if (b < c - 1) {
        i = 0;
        n = c - b;
        if (n > 0) {
            do {
                s32 a = b + i;
                data_ov000_021b566c->mUnk_24[a] = data_ov000_021b566c->mUnk_24[a + 1];
                data_ov000_021b566c->mUnk_a4[a] = data_ov000_021b566c->mUnk_a4[a + 1];
                data_ov000_021b566c->mUnk_f4[a] = data_ov000_021b566c->mUnk_f4[a + 1];
                data_ov000_021b566c->mUnk_1f8[a] = data_ov000_021b566c->mUnk_1f8[a + 1];
                data_ov000_021b566c->mUnk_278[a] = data_ov000_021b566c->mUnk_278[a + 1];
                data_ov000_021b566c->mUnk_2b8[a] = data_ov000_021b566c->mUnk_2b8[a + 1];
                i++;
            } while (i < n);
        }
    }
    if (c > 0) {
        k = c - 1;
        data_ov000_021b566c->mUnk_24[k] = 0;
        data_ov000_021b566c->mUnk_a4[k] = 0;
        data_ov000_021b566c->mUnk_f4[k] = 0;
        data_ov000_021b566c->mUnk_1f8[k] = 0;
        data_ov000_021b566c->mUnk_278[k] = 0;
        data_ov000_021b566c->mUnk_2b8[k] = 0;
    }
    return v1;
}

u8 func_ov000_021a160c(void) {
    if (data_ov000_021b566c != NULL) {
        return data_ov000_021b566c->mUnk_0d;
    }
    return 0;
}

u8 func_ov000_021a15f8(void) {
    if (data_ov000_021b566c != NULL) {
        return data_ov000_021b566c->mUnk_0e;
    }
    return 0;
}

void func_ov000_021a15b0(void) {
    Unk021b566c *p;
    s32 n;
    s32 i;
    u32 m;
    i = 0;
    n = -1;
    p = data_ov000_021b566c;
    m = p->mUnk_2d8;
    for (; i < 32; i++) {
        if ((m & (1 << i)) != 0) {
            n++;
        }
    }
    if (n == -1) {
        p->mUnk_0e = 0;
    } else {
        p->mUnk_0e = n;
    }
}

u32 func_ov000_021a158c(void **output) {
    if (data_ov000_021b566c == NULL) {
        return 0;
    }
    *output = data_ov000_021b566c->mUnk_2b8;
    return data_ov000_021b566c->mUnk_0d + 1;
}

u32 func_ov000_021a1514(void **a) {
    s32 i;
    u8 *c;
    u8 *q;
    Unk021b566c *p;
    u8 b;
    if (data_ov000_021b566c == NULL) {
        return 0;
    }
    MemFill(data_ov000_021b5678, 0, 0x20);
    i = 0;
    c = (u8 *) data_ov000_021b566c;
    if (i <= ((Unk021b566c *) c)->mUnk_0e) {
        q = data_ov000_021b5678;
        p = (Unk021b566c *) c;
        do {
            b = c[0x2b8];
            if ((p->mUnk_2d8 & (1 << b)) == 0) {
                break;
            }
            *q = b;
            c++;
            q++;
            i++;
        } while (i <= p->mUnk_0e);
    }
    *a = data_ov000_021b5678;
    return data_ov000_021b566c->mUnk_0e + 1;
}

u32 func_ov000_021a1488(void) {
    char name[12];
    u8 buffer[32];
    if (data_ov000_021b566c->mUnk_15 != 2) {
        return 0;
    }
    StringFormatBounded(name, 0xc, data_ov000_021b40b8, data_ov000_021b566c->mUnk_16 + 1);
    func_ov000_021a363c(data_ov000_021b41a8, name, buffer, 0x2f);
    StringFormatBounded(name, 0xc, data_ov000_021b40b8, data_ov000_021b566c->mUnk_0d + 1);
    func_ov000_021a360c(data_ov000_021b41ac, name, buffer, 0x2f);
    StringFormatBounded(name, 0xc, data_ov000_021b40b8, 3);
    func_ov000_021a360c(data_ov000_021b4118, name, buffer, 0x2f);
    return func_ov000_0219d558(6, buffer, NULL);
}

void func_ov000_021a1430(void) {
    data_ov000_021b566c = NULL;
    if (data_ov000_021b5674 != NULL) {
        func_ov000_021a3704(4, (u32) data_ov000_021b5674, 0);
        data_ov000_021b5674 = NULL;
    }
    func_ov000_0219ea88();
    if (data_ov000_021b5670 != NULL) {
        func_ov000_021a3704(4, (u32) data_ov000_021b5670, 0);
        data_ov000_021b5670 = NULL;
    }
    data_ov000_021b5668.mUnk_00 = 0;
    data_ov000_021b5668.mUnk_01 = 0;
}

u32 func_ov000_021a141c(void) {
    if (data_ov000_021b566c == NULL) {
        return 1;
    }
    return 0;
}

void func_ov000_021a1140(s32 a) {
    vu16 h;
    vu16 g;

    data_ov000_021b566c->mUnk_0c = 0;
    data_ov000_021b566c->mUnk_174[0] = 0;
    data_ov000_021b566c->mUnk_176 = func_ov000_021a3448(0x10000);
    data_ov000_021b566c->mUnk_178 = 0;
    data_ov000_021b566c->mUnk_17c = 0;
    data_ov000_021b566c->mUnk_184 = 0;
    data_ov000_021b566c->mUnk_19c = 0;
    data_ov000_021b566c->mUnk_1a1 = 0;
    data_ov000_021b566c->mUnk_1a2 = 0;
    data_ov000_021b566c->mUnk_1a3[0] = 0;
    data_ov000_021b566c->mUnk_1a3[1] = 0;
    data_ov000_021b566c->mUnk_19f = 0;
    data_ov000_021b566c->mUnk_1a0 = 0;
    data_ov000_021b566c->mUnk_1a8 = 0;
    data_ov000_021b566c->mUnk_1aa = 0;
    data_ov000_021b566c->mUnk_1ac = 0;
    data_ov000_021b566c->mUnk_1d0 = 0;
    data_ov000_021b566c->mUnk_1e0 = 0;
    func_0214d018_inline(&data_ov000_021b566c->mUnk_3b4, 0x98);
    if (a == 2) {
        data_ov000_021b566c->mUnk_14 = data_ov000_021b566c->mUnk_0d;
        if (data_ov000_021b566c->mUnk_15 == 3) {
            data_ov000_021b566c->mUnk_198 = 1;
            return;
        }
        if (data_ov000_021b566c->mUnk_15 == 2) {
            data_ov000_021b566c->mUnk_198 = 10;
            return;
        }
    } else {
        data_ov000_021b566c->mUnk_0d = 0;
        data_ov000_021b566c->mUnk_0e = 0;
        data_ov000_021b566c->mUnk_14 = 0;
        data_ov000_021b566c->mUnk_17 = 0;
        data_ov000_021b566c->mUnk_20 = 0;
        data_ov000_021b566c->mUnk_e8 = 0;
        data_ov000_021b566c->mUnk_19d = 0;
        data_ov000_021b566c->mUnk_1a6 = 0;
        data_ov000_021b566c->mUnk_1b0 = 0;
        data_ov000_021b566c->mUnk_1b4 = 0;
        data_ov000_021b566c->mUnk_1bc = 0;
        data_ov000_021b566c->mUnk_1c0 = 0;
        data_ov000_021b566c->mUnk_1c8 = 0;
        data_ov000_021b566c->mUnk_1ec = 0;
        data_ov000_021b566c->mUnk_1f0 = 0;
        data_ov000_021b566c->mUnk_2d8 = 0;
        func_0214d018_inline(data_ov000_021b566c->mUnk_24, 0x80);
        h = 0;
        MemFillHalfwords(h, data_ov000_021b566c->mUnk_a4, 0x40);
        func_0214d018_inline(data_ov000_021b566c->mUnk_f4, 0x80);
        func_0214d018_inline(data_ov000_021b566c->mUnk_18c, 0xc);
        func_0214d018_inline(data_ov000_021b566c->mUnk_1f8, 0x80);
        g = 0;
        MemFillHalfwords(g, data_ov000_021b566c->mUnk_278, 0x40);
        MemFill(data_ov000_021b566c->mUnk_2b8, 0, 0x20);
        func_0214d018_inline(data_ov000_021b566c->mUnk_330, 0x84);
        if (a == 1) {
            if (data_ov000_021b566c->mUnk_15 == 0) {
                data_ov000_021b566c->mUnk_198 = 3;
                return;
            }
            if (data_ov000_021b566c->mUnk_15 == 1) {
                data_ov000_021b566c->mUnk_198 = 4;
                return;
            }
        } else {
            data_ov000_021b566c->mUnk_15 = 0;
            data_ov000_021b566c->mUnk_16 = 0;
            data_ov000_021b566c->mUnk_18 = 0;
            data_ov000_021b566c->mUnk_1f4 = 0;
            data_ov000_021b566c->mUnk_19e = 0;
            data_ov000_021b566c->mUnk_454 = NULL;
            data_ov000_021b566c->mUnk_458 = 0;
        }
    }
}

void func_ov000_021a10b0(u8 a, u8 b, u32 c, u32 d) {
    Unk021b566c **v1;
    func_ov000_021a1140(0);
    v1 = &data_ov000_021b566c;
    data_ov000_021b566c->mUnk_15 = a;
    (*v1)->mUnk_16 = b;
    (*v1)->mUnk_44c = (UnkFunc *) c;
    (*v1)->mUnk_450 = d;
    (*v1)->mUnk_174[1] = 0;
    (*v1)->mUnk_2b8[0] = 0;
    func_ov000_021a4b84(0x32, data_ov000_021b40c4);
    func_ov000_021a4b84(0x33, data_ov000_021b40f0);
    func_ov000_021a4b84(0x34, data_ov000_021b40fc);
    func_ov000_021a4b84(0x35, data_ov000_021b4108);
    func_ov000_021a4b84(0x36, data_ov000_021b40cc);
}
