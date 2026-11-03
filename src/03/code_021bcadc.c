#include "03/code_021bb03c.h"
#include "03/code_021bbc94.h"
#include "03/code_021bcadc.h"
#include "03/unk_021d8000.h"
#include "code_02134d30.h"

int func_ov003_021bcadc(u8 *param_1, u8 *param_2, u32 param_3, u8 *param_4, int param_5) {
    u8 a[16];
    u64 b;
    u32 c[80];
    u32 d[2];
    int i;
    int h;
    int f;
    int g;
    BOOL e;
    s64 t;
    u8 *p;
    u8 *q;
    enum { K0 } k;

    e = TRUE;
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
    memcpy(param_1, param_2 + 8, param_3 - 1);
    for (h = 5; h >= 0; h--) {
        for (i = f; i > 0; i--) {
            t = (s64) f * (s32) h + (s32) i;
            b = ((((u64) t & 0x00000000000000ffULL) << 56) | (((u64) t & 0x000000000000ff00ULL) << 40) |
                 (((u64) t & 0x0000000000ff0000ULL) << 24) | (((u64) t & 0x00000000ff000000ULL) << 8) |
                 (((u64) t & 0x000000ff00000000ULL) >> 8) | (((u64) t & 0x0000ff0000000000ULL) >> 24) |
                 (((u64) t & 0x00ff000000000000ULL) >> 40) | (((u64) t & 0xff00000000000000ULL) >> 56));
            func_ov003_021bca90(a, (u8 *) &b, a);
            p = param_1 + (i - 1) * 8;
            {
                u8 *r = p;
                q = a + 8;
                k = 8;
                do {
                    *q++ = *r++;
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
    if (memcmp((u8 *) d, a, 8) != 0) {
        e = FALSE;
    }
    return e;
}

// non-matching: the original spills p (offset 0x2c) and gives r4 to a byte swap term, here p stays in r4 and that
// term is spilled; size 0x210 against 0x20c. The (u32) cast keeps i * 8 recomputed each pass as
// in the original, but is not proven to be the original spelling
BOOL func_ov003_021bccd0(u8 *param_1, u8 *param_2, u32 param_3, u8 *param_4, int param_5) {
    u8 a[16];
    u64 b;
    u32 c[80];
    u32 d[2];
    int i;
    int h;
    int f;
    int g;
    s64 t;
    u8 *p;
    u8 *q;
    u8 *r;
    enum { K0 } k;

    d[0] = 0xa6a6a6a6;
    d[1] = 0xa6a6a6a6;
    if ((param_3 & 7) != 0 || (param_5 & 7) != 0) {
        return FALSE;
    }
    f = param_3 >> 3;
    if (f < 2) {
        return FALSE;
    }
    g = func_ov003_021bc7a8(c, param_4, param_5 << 3);
    memcpy(param_1 + 8, param_2, param_3);
    p = a;
    q = (u8 *) d;
    k = 8;
    do {
        *p++ = *q++;
    } while (--k != 0);
    for (h = 0; h < 6; h++) {
        for (i = 1; i <= f; i++) {
            p = param_1 + (u32) i * 8;
            r = p;
            q = a + 8;
            k = 8;
            do {
                *q++ = *r++;
            } while (--k != 0);
            func_ov003_021bc1c4(c, g, a, a);
            t = (s64) f * (s32) h + (s32) i;
            b = ((((u64) t & 0x00000000000000ffULL) << 56) | (((u64) t & 0x000000000000ff00ULL) << 40) |
                 (((u64) t & 0x0000000000ff0000ULL) << 24) | (((u64) t & 0x00000000ff000000ULL) << 8) |
                 (((u64) t & 0x000000ff00000000ULL) >> 8) | (((u64) t & 0x0000ff0000000000ULL) >> 24) |
                 (((u64) t & 0x00ff000000000000ULL) >> 40) | (((u64) t & 0xff00000000000000ULL) >> 56));
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
    return TRUE;
}

void func_ov003_021bcedc(void) {
    int a;

    a = func_ov003_021bcf1c();
    *(s32 *) &data_ov003_021d8c48 = a;
    func_ov003_021be1fc();
    if (a == 1) {
        *(s32 *) &data_ov003_021d8c08 = 6;
    } else {
        *(s32 *) &data_ov003_021d8c08 = 7;
    }
    *(s32 *) &data_ov003_021d68b8 = -1;
    func_ov003_021bb03c();
}
