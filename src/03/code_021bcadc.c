#include "03/code_021bcadc.h"

// non-matching: stack offsets of the spilled locals differ (frame 0x1ac against 0x1b4), the 64-bit product is computed
// before the loop guard instead of after it, and the 8-byte copy loops end in bgt/bhi instead of bne; size 0x1fc
// against 0x1f4
int func_ov003_021bcadc(u8 *param_1, u8 *param_2, u32 param_3, u8 *param_4, int param_5) {
    u8 a[16];
    u64 b;
    u32 c[80];
    u32 d[2];
    int i, h, f, g, e;
    int k;
    s64 t;
    u8 *p, *q;

    e = 1;
    d[0] = 0xa6a6a6a6;
    d[1] = 0xa6a6a6a6;
    if ((param_3 & 7) != 0 || (param_5 & 7) != 0) {
        return 0;
    }
    f = (param_3 - 1) >> 3;
    if (f < 2) {
        return 0;
    }
    g = func_ov003_021bc5e4(c, param_4, param_5 << 3);
    p = a;
    q = param_2;
    k = 8;
    do {
        *p++ = *q++;
    } while (--k != 0);
    func_02134eb8(param_1, param_2 + 8, param_3 - 1);
    for (h = 5; h >= 0; h--) {
        for (i = f; i > 0; i--) {
            t = (s64) f * h + i;
            b = ((((u64) t & 0xff00000000000000ULL) >> 56) | (((u64) t & 0x00ff000000000000ULL) >> 40) |
                 (((u64) t & 0x0000ff0000000000ULL) >> 24) | (((u64) t & 0x000000ff00000000ULL) >> 8) |
                 (((u64) t & 0x00000000ff000000ULL) << 8) | (((u64) t & 0x0000000000ff0000ULL) << 24) |
                 (((u64) t & 0x000000000000ff00ULL) << 40) | (((u64) t & 0x00000000000000ffULL) << 56));
            func_ov003_021bca90(a, (u8 *) &b, a);
            p = param_1 + (i - 1) * 8;
            q = p;
            {
                u8 *r = a + 8;
                k = 8;
                do {
                    *r++ = *q++;
                } while (--k != 0);
            }
            func_ov003_021bbd9c(c, g, a, a);
            {
                u8 *r = a + 8;
                k = 8;
                do {
                    *p++ = *r++;
                } while (--k != 0);
            }
        }
    }
    if (func_02134d30((u8 *) d, a, 8) != 0) {
        e = 0;
    }
    return e;
}

// non-matching: 8-byte copy loops end in bgt instead of bne (counter in a different register), stack offsets of the
// locals differ (frame 0x1cc against 0x1d4); size 0x21c against 0x20c
int func_ov003_021bccd0(u8 *param_1, u8 *param_2, u32 param_3, u8 *param_4, int param_5) {
    u8 a[16];
    u64 b;
    u32 c[80];
    u32 d[2];
    int i, h, f, g;
    int k;
    s64 t;
    u8 *p, *q, *r;

    d[0] = 0xa6a6a6a6;
    d[1] = 0xa6a6a6a6;
    if ((param_3 & 7) != 0 || (param_5 & 7) != 0) {
        return 0;
    }
    f = param_3 >> 3;
    if (f < 2) {
        return 0;
    }
    g = func_ov003_021bc7a8(c, param_4, param_5 << 3);
    func_02134eb8(param_1 + 8, param_2, param_3);
    p = a;
    q = (u8 *) d;
    k = 8;
    do {
        *p++ = *q++;
    } while (--k != 0);
    for (h = 0; h < 6; h++) {
        for (i = 1; i <= f; i++) {
            p = param_1 + i * 8;
            q = p;
            r = a + 8;
            k = 8;
            do {
                *r++ = *q++;
            } while (--k != 0);
            func_ov003_021bc1c4(c, g, a, a);
            t = (s64) f * h + i;
            b = ((((u64) t & 0xff00000000000000ULL) >> 56) | (((u64) t & 0x00ff000000000000ULL) >> 40) |
                 (((u64) t & 0x0000ff0000000000ULL) >> 24) | (((u64) t & 0x000000ff00000000ULL) >> 8) |
                 (((u64) t & 0x00000000ff000000ULL) << 8) | (((u64) t & 0x0000000000ff0000ULL) << 24) |
                 (((u64) t & 0x000000000000ff00ULL) << 40) | (((u64) t & 0x00000000000000ffULL) << 56));
            func_ov003_021bca90(a, (u8 *) &b, a);
            r = a + 8;
            k = 8;
            do {
                *p++ = *r++;
            } while (--k != 0);
        }
    }
    q = a;
    k = 8;
    do {
        *param_1++ = *q++;
    } while (--k != 0);
    return 1;
}

void func_ov003_021bcedc(void) {
    int a;

    a = func_ov003_021bcf1c();
    *(int *) &data_ov003_021d8c48 = a;
    func_ov003_021be1fc();
    if (a == 1) {
        *(int *) &data_ov003_021d8c08 = 6;
    } else {
        *(int *) &data_ov003_021d8c08 = 7;
    }
    *(int *) &data_ov003_021d68b8 = -1;
    func_ov003_021bb03c();
}
