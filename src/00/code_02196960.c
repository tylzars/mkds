#include "00/code_02196960.h"

#include "00/code_0218d818.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/code_02196000.h"
#include "00/unk_021b3000.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "00/code_0218e2dc.h"
#include "00/code_021a3a18.h"
#include "00/code_021a3668.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "code_021382a8.h"
#include "00/code_0218e0fc.h"
#include "00/code_0219742c.h"
#include "00/code_021a6d5c.h"

s32 func_ov000_0219735c(const s8 *a, u32 b) {
    char f[0x21];
    Unk021b3bdc c = data_ov000_021b3bdc;
    const s8 *d;
    s32 e;
    s8 g[0x80];
    data_ov000_021b3b40[0] = 0x63;
    d = func_ov000_021970fc(a, data_ov000_021b3b40);
    if (d == NULL) {
        func_ov000_0218e53c(data_ov000_021b3b2c);
        return 5;
    }
    e = func_ov000_021971c8(d, strlen((const char *) d));
    e = sprintf((char *) g, data_ov000_021b3e0c, e, data_ov000_021b4f84);
    func_ov000_0218e0fc((const char *) g, e, f);
    data_ov000_021b3b30 = data_ov000_021b3b98;
    func_ov000_021971ec(c.mUnk_00, 0x2b);
    e = sprintf((char *) g, (const char *) c.mUnk_00, data_ov000_021b4e84, f, b);
    if (func_ov000_02197220(g, e) <= 0) {
        func_ov000_0218e53c(data_ov000_021b3b2c);
        return 3;
    }
    return 0;
}

s32 func_ov000_021972b4(void) {
    s8 a[0x80];
    s32 b = func_ov000_0218e460(data_ov000_021b3b2c, a, 0x80, 0);
    const s8 *c;
    s32 d;
    if (b == -1) {
        d = func_ov000_0218e368(data_ov000_021b3b2c);
        if (d != -6 && d != -0x4c && d != -0x1a) {
            func_ov000_0218e53c(data_ov000_021b3b2c);
            return 3;
        }
    }
    a[b] = 0;
    data_ov000_021b3b30 = data_ov000_021b3b88;
    func_ov000_021971ec(a, b);
    data_ov000_021b3b38[0] = 0x73;
    c = func_ov000_021970fc(a, data_ov000_021b3b38);
    if (c == NULL) {
        func_ov000_0218e53c(data_ov000_021b3b2c);
        return 5;
    }
    data_ov000_021b4e4c = StrtolBase10((const char *) c);
    return 0;
}

s32 func_ov000_02197220(s8 *a, s32 b) {
    s32 c = 0;
    s32 d;
    data_ov000_021b3b30 = data_ov000_021b3b88;
    func_ov000_021971ec(a, b);
    strcpy((char *) (a + b), data_ov000_021b3b4c);
    if (b + 7 > 0) {
        do {
            d = func_ov000_0218e420(data_ov000_021b3b2c, a + c, b + 7 - c, 0);
            if (d == -1) {
                d = func_ov000_0218e368(data_ov000_021b3b2c);
                if (d != -6 && d != -0x4c && d != -0x1a) {
                    return d;
                }
            } else if (d == 0) {
                return -1;
            } else {
                c += d;
            }
        } while (c < b + 7);
    }
    return c;
}

void func_ov000_021971ec(s8 *a, s32 b) {
    s32 d;
    s8 *c = (s8 *) data_ov000_021b3b30;
    d = 0;
    if (b > 0) {
        do {
            a[d] ^= *c++;
            if (*c == 0) {
                c = (s8 *) data_ov000_021b3b30;
            }
            d++;
        } while (d < b);
    }
}

int func_ov000_021971c8(const s8 *a, int b) {
    int v1;
    int v2;
    v2 = 0;
    v1 = 0;
    if (0 < b) {
        do {
            v2 = (0x9ccf9319u) * v2 + a[v1];
            v1 = v1 + 1;
        } while (v1 < b);
    }
    return v2;
}

void func_ov000_02197190(u32 a, s8 *b) {
    s8 *c = b;
    sprintf((char *) b, data_ov000_021b3e04, a);
    while (*c != 0) {
        *c = *c + 0x11 + (c - b);
        c++;
    }
}

const s8 *func_ov000_021970fc(const s8 *v1, const char *v2) {
    Unk021b3c88 a = data_ov000_021b3c88;
    const s8 *b;
    s8 *c;
    s8 *e;
    data_ov000_021b4e70 ^= 1;
    strcat((char *) a.mUnk_00, v2);
    strcat((char *) a.mUnk_00, data_ov000_021b3e00);
    b = (const s8 *) strstr((const char *) v1, (const char *) a.mUnk_00);
    if (b == NULL) {
        return NULL;
    }
    b += strlen((const char *) a.mUnk_00);
    e = data_ov000_021b5084 + (data_ov000_021b4e70 << 8);
    c = e;
    while (*b != 0 && *b != '\\') {
        *c++ = *b++;
    }
    *c = 0;
    return e;
}

const s8 *func_ov000_021970e4(const s8 *text, const char *v1) {
    const s8 *result = func_ov000_021970fc(text, v1);
    if (result == NULL) {
        result = data_ov000_021b3de4;
    }
    return result;
}

BOOL func_ov000_02197064(const s8 *a, u32 b, u8 *c, Unk021a8f84 **d) {
    Unk021a8f84 *f = NULL;
    u16 e = b;
    c[0] = 0;
    c[1] = 0;
    c[2] = 0;
    c[3] = 0;
    c[4] = 0;
    c[5] = 0;
    c[6] = 0;
    c[7] = 0;
    c[1] = 2;
    *OFFSET_PTR(u16, c, 2) = ((e >> 8) & 0xff) | ((e << 8) & 0xff00);
    if (a == NULL) {
        *OFFSET_PTR(u32, c, 4) = 0;
    } else {
        *OFFSET_PTR(u32, c, 4) = func_ov000_0218e374((u32) a);
    }
    if (*OFFSET_PTR(u32, c, 4) == -1) {
        f = func_ov000_021a8f84((const char *) a);
        if (f == NULL) {
            return FALSE;
        }
        *OFFSET_PTR(u32, c, 4) = **f->mUnk_0c;
    }
    if (d != NULL) {
        *d = f;
    }
    return TRUE;
}

void func_ov000_02197020(s32 a, s32 b, s32 c, s32 d, s32 e, UnkFunc *f, s32 g) {
    Unk02197020 h;
    h.mUnk_18 = f;
    h.mUnk_14 = g;
    h.mUnk_04 = b;
    h.mUnk_00 = a;
    h.mUnk_08 = c;
    h.mUnk_0c = d;
    h.mUnk_10 = e;
    if (data_ov000_021b4e5c == NULL) {
        data_ov000_021b4e5c = DarrayCreate(0x1c, 2, NULL);
    }
    DarrayAppend(data_ov000_021b4e5c, &h);
}

void func_ov000_02196f8c(s8 *a, s32 b, s32 c, UnkFunc *d, s32 e) {
    s32 g = 0;
    Unk021b3b68 f = data_ov000_021b3b68;
    if (data_ov000_021b3b2c != -1) {
        g = func_ov000_02197220(a, b);
    }
    if (g <= 0) {
        GstatsClose();
        data_ov000_021b3b30 = data_ov000_021b3b98;
        func_ov000_021971ec(f.mUnk_00, 0xf);
        if (d != NULL) {
            d(c, 0, 0, f.mUnk_00, e);
        }
    } else {
        func_ov000_02197020(0, c, 0, 0, 0, d, e);
    }
}

void func_ov000_02196e50(s32 a, s32 b, s32 c, s32 d, const u8 *e, s32 f, UnkFunc *g, s32 h, s32 i) {
    Unk021b3c08 j = data_ov000_021b3c08;
    s8 k[0x200];
    s32 m;
    s8 *n;
    s32 l;
    data_ov000_021b3b30 = data_ov000_021b3b98;
    func_ov000_021971ec(j.mUnk_00, 0x3e);
    if (c == 0 || c == 2) {
        if (g != NULL) {
            g(a, b, c, d, 0, 0, h);
        }
        return;
    }
    m = sprintf((char *) k, (const char *) j.mUnk_00, b, c, d, i, a, f);
    l = m + f;
    if (l < 0x1e0) {
        memcpy(k + m, e, f);
        n = k;
    } else {
        n = func_ov000_021a3690(l + 0x100);
        memcpy(n, k, m);
        memcpy(n + m, e, f);
    }
    if (data_ov000_021b3b2c != -1) {
        m = func_ov000_02197220(n, l);
    }
    if (m <= 0) {
        GstatsClose();
        if (g != NULL) {
            g(a, b, c, d, 0, 0, h);
        }
    } else {
        func_ov000_02197020(2, a, b, c, d, g, h);
    }
    if (n != k) {
        func_ov000_021a3668(n);
    }
}

u32 func_ov000_02196e48(u32 arg0) {
    u32 value0 = arg0;
    u32 value3;
    value3 = (u32) &func_ov000_0218e668;
    value0 = func_ov000_0218e668(value0);
    return value0;
}

const s8 *func_ov000_02196df0(const s8 *a, s32 b) {
    const s8 *c = a;
    s32 d = b - 6;
    if (d > 0) {
        do {
            if (c[0] == '\\' && c[1] == 'f' && c[2] == 'i' && c[3] == 'n' && c[4] == 'a' && c[5] == 'l' &&
                c[6] == '\\') {
                return c;
            }
            c++;
        } while (c - a < d);
    }
    return NULL;
}

s32 func_ov000_02196d84(s32 a, s32 b, s32 c) {
    s32 d;
    Unk02196d84 *e;
    if (data_ov000_021b4e5c == NULL) {
        return -1;
    }
    d = 0;
    if (DarrayGetCount((u32 *) data_ov000_021b4e5c) > 0) {
        do {
            e = DarrayGetElement(data_ov000_021b4e5c, d);
            if (e->mUnk_00 == a && e->mUnk_04 == b && e->mUnk_08 == c) {
                return d;
            }
            d++;
        } while (d < DarrayGetCount((u32 *) data_ov000_021b4e5c));
    }
    return -1;
}

void func_ov000_02196d0c(u8 *f, s32 g) {
    s32 a = StrtolBase10((const char *) func_ov000_021970e4((const s8 *) f, data_ov000_021b3df0));
    s32 b = StrtolBase10((const char *) func_ov000_021970e4((const s8 *) f, data_ov000_021b3dc4));
    const s8 *c = func_ov000_021970e4((const s8 *) f, data_ov000_021b3df8);
    s32 d = func_ov000_02196d84(0, b, 0);
    if (d != -1) {
        Unk02196d84 *e = DarrayGetElement(data_ov000_021b4e5c, d);
        e->mUnk_08 = a;
        func_ov000_021969d8(d, a > 0 ? 1 : 0, 0, (const u8 *) c, 0);
    }
}

void func_ov000_02196ca4(u8 *c, s32 d) {
    s32 a;
    s32 b;
    s32 t;
    Unk021969d8Entry *p;

    a = StrtolBase10((const char *) func_ov000_021970e4((const s8 *) c, data_ov000_021b3de8));
    b = StrtolBase10((const char *) func_ov000_021970e4((const s8 *) c, data_ov000_021b3dc4));
    t = func_ov000_02196d84(3, b, 0);
    if (t != -1) {
        p = DarrayGetElement(data_ov000_021b4e5c, t);
        p->mUnk_08 = a;
        func_ov000_021969d8(t, (a > 0) ? 1 : 0, 0, NULL, 0);
    }
}

void func_ov000_02196c00(u8 *f, s32 g) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 t;
    s32 e;
    u8 *q;
    const u8 *s;

    a = StrtolBase10((const char *) func_ov000_021970e4((const s8 *) f, data_ov000_021b3dcc));
    b = StrtolBase10((const char *) func_ov000_021970e4((const s8 *) f, data_ov000_021b3dc4));
    c = StrtolBase10((const char *) func_ov000_021970e4((const s8 *) f, data_ov000_021b3dc0));
    d = StrtolBase10((const char *) func_ov000_021970e4((const s8 *) f, data_ov000_021b3dc8));
    t = func_ov000_02196d84(1, b, c);
    if (t != -1) {
        e = StrtolBase10((const char *) func_ov000_021970e4((const s8 *) f, data_ov000_021b3dd4));
        q = (u8 *) strstr((const char *) f, data_ov000_021b3ddc);
        if (q == NULL) {
            e = 0;
            s = (const u8 *) data_ov000_021b3de4;
        } else {
            s = q + 6;
        }
        func_ov000_021969d8(t, a, d, s, e);
    }
}

void func_ov000_02196b90(u8 *e, s32 f) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 t;

    a = StrtolBase10((const char *) func_ov000_021970e4((const s8 *) e, data_ov000_021b3db8));
    b = StrtolBase10((const char *) func_ov000_021970e4((const s8 *) e, data_ov000_021b3dc0));
    c = StrtolBase10((const char *) func_ov000_021970e4((const s8 *) e, data_ov000_021b3dc4));
    d = StrtolBase10((const char *) func_ov000_021970e4((const s8 *) e, data_ov000_021b3dc8));
    t = func_ov000_02196d84(2, c, b);
    if (t != -1) {
        func_ov000_021969d8(t, a, d, NULL, 0);
    }
}

void func_ov000_02196ae0(u8 *a, s32 b) {
    a[b] = 0;
    if (strncmp((const char *) a, data_ov000_021b3d88, 8) == 0) {
        func_ov000_02196d0c(a, b);
        return;
    }
    if (strncmp((const char *) a, data_ov000_021b3d94, 9) == 0) {
        func_ov000_02196ca4(a, b);
        return;
    }
    if (strncmp((const char *) a, data_ov000_021b3d94, 9) == 0) {
        func_ov000_02196ca4(a, b);
        return;
    }
    if (strncmp((const char *) a, data_ov000_021b3da0, 8) == 0) {
        func_ov000_02196c00(a, b);
        return;
    }
    if (strncmp((const char *) a, data_ov000_021b3dac, 8) == 0) {
        func_ov000_02196b90(a, b);
    }
}

s32 func_ov000_02196a84(u8 *a, s32 b) {
    u8 *p;
    s32 c;
    s32 n;

    c = b;
    p = (u8 *) func_ov000_02196df0((const s8 *) a, b);
    while (b > 0 && p != NULL) {
        data_ov000_021b3b30 = data_ov000_021b3b88;
        n = p - a;
        func_ov000_021971ec((s8 *) a, n);
        func_ov000_02196ae0(a, n);
        b = b - (n + 7);
        a = p + 7;
        if (b > 0) {
            p = (u8 *) func_ov000_02196df0((const s8 *) a, b);
        }
    }
    return c - b;
}

void func_ov000_021969d8(s32 a, s32 b, s32 c, const u8 *d, s32 e) {
    Unk021969d8Entry *p;

    if (a >= 0 && a < DarrayGetCount(data_ov000_021b4e5c)) {
        p = DarrayGetElement(data_ov000_021b4e5c, a);
        if (p->mUnk_18.mUnk_00 != NULL) {
            switch (p->mUnk_00) {
                case 0:
                    p->mUnk_18.mUnk_00(p->mUnk_04, p->mUnk_08, b, d, p->mUnk_14);
                    break;
                case 1:
                    p->mUnk_18.mUnk_01(p->mUnk_04, p->mUnk_08, p->mUnk_0c, p->mUnk_10, b, c, d, e, p->mUnk_14);
                    break;
                case 2:
                    p->mUnk_18.mUnk_02(p->mUnk_04, p->mUnk_08, p->mUnk_0c, p->mUnk_10, b, c, p->mUnk_14);
                    break;
                case 3:
                    p->mUnk_18.mUnk_03(p->mUnk_04, p->mUnk_08, b, p->mUnk_14);
                    break;
            }
        }
        DarrayRemove(data_ov000_021b4e5c, a);
    }
}

void func_ov000_02196960(void) {
    s32 i;
    Unk02196960Key k;

    if (data_ov000_021b4e5c != NULL) {
        for (i = DarrayGetCount(data_ov000_021b4e5c) - 1; i >= 0; i--) {
            k = data_ov000_021b3b78;
            data_ov000_021b3b30 = data_ov000_021b3b98;
            func_ov000_021971ec((s8 *) k.mUnk_00, 0xf);
            func_ov000_021969d8(i, 0, 0, k.mUnk_00, 0);
        }
        DarrayDelete(data_ov000_021b4e5c);
        data_ov000_021b4e5c = NULL;
    }
}
