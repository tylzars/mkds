#include "00/code_02188008.h"
#include "00/code_02186000.h"
#include "00/unk_021b1000.h"
#include "03/code_021b94b8.h"
#include "00/code_02186d04.h"
#include "00/code_02188694.h"
#include "00/unk_021b4000.h"
#include "code_0200dc3c.h"
#include "code_0200e0ec.h"
#include "code_02133048.h"
#include "code_02133274.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "code_0200edc0.h"

void func_ov000_02188008(void) {
    if (data_ov000_021b4cb0->mUnk_11c.mUnk_6c == 0 || func_0200e070(&data_ov000_021b4cb0->mUnk_11c) != 0) {
        func_0200e28c(&data_ov000_021b4cb0->mUnk_11c, (void (*)(void *)) func_ov000_021874ec, data_ov000_021b4cb0,
                      data_ov000_021b4cb0->mUnk_1200, 0x1000, 0x10);
        func_0200df68(&data_ov000_021b4cb0->mUnk_11c);
    }
}

void func_ov000_02188068(void) {
    if (data_ov000_021b4cac != NULL) {
        func_ov000_02186d04((Unk021868d0 *) data_ov000_021b4cac);
        data_ov000_021b4cb0->mUnk_108.mUnk_04(data_ov000_021b1474, data_ov000_021b4cac, 0);
        data_ov000_021b4cac = NULL;
    }
    func_ov000_02186430();
    if (data_ov000_021b4cb0 != NULL) {
        if (data_ov000_021b4cb0->mUnk_114 != NULL) {
            data_ov000_021b4cb0->mUnk_108.mUnk_04(data_ov000_021b13ac, data_ov000_021b4cb0->mUnk_114, 0);
            data_ov000_021b4cb0->mUnk_114 = NULL;
        }
        if (data_ov000_021b4cb0->mUnk_118 != NULL) {
            data_ov000_021b4cb0->mUnk_108.mUnk_04(data_ov000_021b13d8, data_ov000_021b4cb0->mUnk_118, 0);
            data_ov000_021b4cb0->mUnk_118 = NULL;
        }
        data_ov000_021b4cb0->mUnk_108.mUnk_04(data_ov000_021b147c, data_ov000_021b4cb0, 0);
        data_ov000_021b4cb0 = NULL;
    }
}

u32 func_ov000_02188114(Unk02188114 *p) {
    if (data_ov000_021b4cb0 != NULL) {
        return 4;
    }
    data_ov000_021b4cb0 = p->mUnk_00(data_ov000_021b147c, 0x1200);
    if (data_ov000_021b4cb0 == NULL) {
        return 4;
    }
    func_0214d168(data_ov000_021b4cb0, 0, 0x1200);
    data_ov000_021b4cb0->mUnk_04 = -99999;
    data_ov000_021b4cb0->mUnk_108 = *p;
    if (data_ov000_021b4cac != NULL) {
        return 4;
    }
    data_ov000_021b4cac = data_ov000_021b4cb0->mUnk_108.mUnk_00(data_ov000_021b1474, 0x1a60);
    if (data_ov000_021b4cac == NULL) {
        return 4;
    }
    func_0200edc0(&data_ov000_021b4cb0->mUnk_1dc);
    func_ov000_02188008();
    return 0;
}

s32 func_ov000_021881d0(const s8 *a, u32 b, u8 *c, u32 d) {
    s32 n;
    s32 m;
    u32 i;
    s32 w;
    u8 *v1;
    s8 v2[4];
    s8 *q;
    s8 v;
    s32 j;

    if ((b & 3) != 0) {
        return -1;
    }
    m = 0;
    for (i = 0; i < b; i++) {
        if (a[i] != '*') {
            m += 6;
        }
    }
    if (c == NULL) {
        return m / 8;
    }
    n = m / 8;
    if (d < n) {
        return -1;
    }
    if (b == 0) {
        *c = 0;
        return 0;
    }
    v1 = c;
    i = 0;
    do {
        j = i;
        q = v2;
        for (; j < 4; j++) {
            v = a[j];
            if (v >= 'A' && v <= 'Z') {
                *q = v - 'A';
            } else if (v >= 'a' && v <= 'z') {
                *q = v - 0x47;
            } else if (v >= '0' && v <= '9') {
                *q = v + 4;
            } else if (v == '.') {
                *q = 0x3e;
            } else if (v == '-') {
                *q = 0x3f;
            } else {
                *q = i;
            }
            q++;
        }
        a += 4;
        w = v2[i] * 4;
        w |= v2[1] >> 4;
        v1[0] = w;
        if (v1 + 1 - c >= n) {
            return v1 + 1 - c;
        }
        w = v2[1] * 16;
        w |= v2[2] >> 2;
        v1[1] = w;
        if (v1 + 2 - c >= n) {
            return v1 + 2 - c;
        }
        w = v2[2] * 64;
        w |= v2[3];
        v1[2] = w;
        v1 += 3;
    } while (v1 - c < n);
    return v1 - c;
}

s32 func_ov000_021882f8(const u8 *a, u32 b, s8 *c, u32 d) {
    const u8 *v1;
    s32 e;
    u32 r;
    s32 k;
    s32 l;
    s8 *v2;
    u8 v3[3];

    r = b / 3 * 4 + (b % 3 != 0 ? 4 : 0);
    if (c == NULL) {
        return r;
    }
    if (d < r) {
        return -1;
    }
    v1 = a + b;
    v2 = c;
    while (a != v1) {
        l = v1 - a;
        e = l * 8;
        k = e / 6 + (e % 6 != 0 ? 1 : 0);
        if (l >= 3) {
            l = 3;
        }
        func_0214d168(v3, 0, 3);
        func_0214d1fc(a, v3, l);
        v2[0] = data_ov000_021b1488[v3[0] >> 2];
        if (k >= 2) {
            v2[1] = data_ov000_021b1488[(v3[0] << 4 & 0x3f) | v3[1] >> 4];
        } else {
            v2[1] = '*';
        }
        if (k >= 3) {
            v2[2] = data_ov000_021b1488[(v3[1] << 2 & 0x3f) | v3[2] >> 6];
        } else {
            v2[2] = '*';
        }
        if (k >= 4) {
            v2[3] = data_ov000_021b1488[v3[2] & 0x3f];
        } else {
            v2[3] = '*';
        }
        v2 += 4;
        a += l;
    }
    return v2 - c;
}

s32 func_ov000_02188408(void) {
    Unk02188408 *s;
    u8 *k;
    u32 i;
    u8 j;
    u8 n;

    s = data_ov000_021b4d00;
    k = s->mUnk_470[0].mUnk_04;
    i = s->mUnk_d13;
    k += i * 0xc0;
    if (s->mUnk_d0d >= 6) {
        return 1;
    }
    for (j = 0, n = s->mUnk_d12; j < n; j++) {
        if (j != i) {
            if (s->mUnk_444[j].mUnk_01 < 6) {
                if (strncmp(k, s->mUnk_470[j].mUnk_04, s->mUnk_470[j].mUnk_0a) == 0) {
                    return 2;
                }
            }
        }
    }
    return 1;
}

void func_ov000_021884a8(void) {
    func_ov000_02188694(8, data_ov000_021b4d0c, 0xc);
    func_ov000_02188694(0x10, data_ov000_021b4d00, 0xd18);
}
