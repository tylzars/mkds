#include "03/code_021bd884.h"

#include "03/code_021b7bb4.h"
#include "03/code_021bd000.h"
#include "03/code_021bdaa4.h"
#include "03/unk_021d6000.h"
#include "03/unk_021d8000.h"
#include "code_02134d30.h"

s32 func_ov003_021bda78(u8 *p, u32 a, const void *b, u32 c) {
    s32 d;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    d = func_ov003_021bdaa4(p + 8, a, b, c) - p;
    *(u16 *) p = d - 8;
    return d;
}

typedef struct Unk021bd894_buf {
    /* 0 */ u16 mUnk_00;
    /* 2 */ Unk021d68c8 mUnk_02;
} Unk021bd894_buf;

s32 func_ov003_021bd998(const u8 *p, s32 *a) {
    u32 b;
    u32 g;
    s32 h;
    u32 i;
    s32 j;
    u32 c;
    s32 k;
    u8 *f;
    u8 *d;
    u8 *e;
    f = func_ov003_021bdc5c(p, &i, &j);
    b = 0;
    g = 0;
    h = 0;
    if (f == 0) {
        return 0;
    }
    if (i != 1) {
        return 0;
    }
    d = f + j;
    f += 8;
    e = func_ov003_021bdc08(&f, d, &c, &k);
    if (e != 0) {
        do {
            switch (c) {
                case 1:
                    b = func_ov003_021b7c44_inline(*(u16 *) e);
                    break;
                case 2:
                    g = func_ov003_021b7c44_inline(*(u16 *) e);
                    break;
                case 5:
                    h = func_ov003_021b7c44_inline(*(u16 *) e);
                    break;
            }
            e = func_ov003_021bdc08(&f, d, &c, &k);
        } while (e != 0);
    }
    if (b != 1 || g != 1) {
        return 0;
    }
    if (h >= 1) {
        *a = 1;
    } else {
        *a = 0;
    }
    return 1;
}

s32 func_ov003_021bd938(const u8 *p, u32 a, u8 *b, const void *c) {
    u32 d;
    s32 e;
    u8 *f;
    f = func_ov003_021bdc5c(p, &d, &e);
    if (f == 0) {
        return 0;
    }
    if (d != a) {
        return 0;
    }
    if (c != 0) {
        func_ov003_021bcadc(b, f, e, c, 0x10);
        e -= 8;
    } else {
        func_02134eb8(b, f, e);
    }
    return e;
}

s32 func_ov003_021bd894(u8 *p) {
    Unk021bd894_buf a;
    u8 *b;
    a.mUnk_00 = 0x100;
    a.mUnk_02 = data_ov003_021d68c8;
    b = func_ov003_021bdaa4(data_ov003_021d68ac, 1, &a, 2);
    b = func_ov003_021bdaa4(b, 2, &a, 2);
    if (data_ov003_021d8c20 != 0) {
        b = func_ov003_021bdaa4(b, 5, &a, 2);
    }
    b = func_ov003_021bdaa4(b, 3, &a.mUnk_02, 7);
    if (data_ov003_021d8c20 != 0) {
        b = func_ov003_021bdaa4(b, 4, &data_ov003_021d8c54, 6);
    }
    return func_ov003_021bdb0c(p, 2, data_ov003_021d9104, b - data_ov003_021d68ac + 8, 0);
}

u32 func_ov003_021bd884(void *p) {
    func_0200fe58(p);
    return 0x1u;
}
