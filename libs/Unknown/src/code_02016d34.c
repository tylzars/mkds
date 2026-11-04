#include "code_02016d34.h"
#include "code_020170e4.h"

#include "code_020169a4.h"
#include "code_02016d28.h"
#include "code_02015f98.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02173000.h"

int func_020170dc(int v) {
    return v << 4;
}

void func_02017070(u32 a, u32 b, RangeEntry *c, u32 d, int e) {
    data_02173234.mUnk_0c = a;
    data_02173234.mUnk_10 = b;
    data_02173234.mUnk_14 = c;
    data_02173234.mUnk_18 = d;
    func_02016d34();
    if (e != 0) {
        data_021619ec = (u32(*)(s32, s32, s32)) func_02016fbc;
        data_021619f0 = (void (*)(void *)) func_02016f2c;
    }
}

u32 func_02016fbc(u32 a, s32 b) {
    u32 n;
    u32 out;
    s32 r;

    if (a == 0) {
        n = 0x10;
    } else {
        n = (a + 0xf) & ~0xf;
    }
    if (n >= 0x7fff0) {
        return 0;
    }
    if (b != 0) {
        r = RangeListAlloc(&data_02173238, &data_0217323c, &out, n);
    } else {
        r = RangeListAlloc(&data_02173234.mUnk_00, &data_0217323c, &out, n);
    }
    if (r == 0) {
        return 0;
    }
    return ((n >> 4) << 16) | ((out >> 3) & 0xffff) | (b << 31);
}

s32 func_02016f2c(u32 v) {
    u32 start;
    u32 len;
    u32 hi;
    s32 r;

    start = (v & 0xffff) << 3;
    len = ((v & 0x7fff0000) >> 16) << 4;
    hi = (v & 0x80000000) >> 31;
    if (len != 0) {
        if (hi != 0) {
            r = RangeListFree(&data_02173238, &data_0217323c, start, len);
        } else {
            r = RangeListFree(&data_02173234.mUnk_00, &data_0217323c, start, len);
        }
        if (r != 0) {
            return 0;
        }
        return 1;
    }
    return 2;
}

void func_02016d34(void) {
    Unk02161a90 t[4] = {{0x20000, 0, 0}, {0x20000, 0, 0}, {0x20000, 0, 0}, {0x20000, 0, 0}};
    u32 a;
    Unk02161a90 *p;
    u32 i;
    u32 b;
    u32 h;
    u32 n;
    u32 x;
    u32 y;
    u32 z;

    a = data_02173234.mUnk_10;
    b = data_02173234.mUnk_0c;
    h = a >> 1;
    b = b - (a + h);
    p = t;
    for (i = 0; i < 4; i++) {
        if (i == 0 || i == 2) {
            if (p->mUnk_00 != 0 && a != 0) {
                n = p->mUnk_00;
                if (n > a) {
                    n = a;
                }
                p->mUnk_08 += n;
                a -= n;
                p->mUnk_00 -= n;
            }
        }
        p++;
    }
    t[1].mUnk_00 -= h;
    p = t;
    for (i = 0; i < 4; i++) {
        if (p->mUnk_00 != 0 && b != 0) {
            n = p->mUnk_00;
            if (n > b) {
                n = b;
            }
            p->mUnk_04 += n;
            b -= n;
            p->mUnk_00 -= n;
        }
        p++;
    }
    func_02016d28(&data_02173234.mUnk_00);
    func_02016d28(&data_02173238);
    data_02173234.mUnk_08 = RangeEntryPoolInit(data_02173234.mUnk_14, data_02173234.mUnk_18 >> 4);
    if (t[0].mUnk_08 != 0) {
        RangeListAdd(&data_02173238, &data_0217323c, 0, t[0].mUnk_08);
    }
    x = t[0].mUnk_08;
    if (t[0].mUnk_04 != 0) {
        RangeListAdd(&data_02173234.mUnk_00, &data_0217323c, x, t[0].mUnk_04);
    }
    if (t[2].mUnk_08 != 0) {
        RangeListAdd(&data_02173238, &data_0217323c, 0x40000, t[2].mUnk_08);
    }
    z = t[2].mUnk_04;
    y = t[2].mUnk_08 + 0x40000;
    if (z != 0) {
        RangeListAdd(&data_02173234.mUnk_00, &data_0217323c, y, z);
    }
    if (t[3].mUnk_04 != 0) {
        RangeListAdd(&data_02173234.mUnk_00, &data_0217323c, 0x60000, t[3].mUnk_04);
    }
    if (t[1].mUnk_04 != 0) {
        RangeListAdd(&data_02173234.mUnk_00, &data_0217323c, h + 0x20000, t[1].mUnk_04);
    }
}
