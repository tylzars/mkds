#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0203c07c.h"
#include "Main/Unknown/code_02062ed8.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/code_020649ec.h"
#include "Main/Unknown/code_0206d020.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_0206d000.h"
#include "Main/Unknown/code_02064000.h"
#include "Main/Unknown/code_02065000.h"
#include "Main/Unknown/code_0207a870.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02036bec.h"
#include "code_02010f98.h"
#include "code_02010fac.h"
#include "code_02012b30.h"
#include "code_02013740.h"
#include "Main/Unknown/code_02087cfc.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_02147000.h"

s32 func_02062ed8(void) {
    if (data_usa_0217aafc.mUnk_20 != 0) {
        return data_usa_0217aafc.mUnk_14 >> 12;
    }
    return -1;
}

void func_02062ef8(u32 a) {
    u32 i;
    Unk0201290c *b;
    u32 j;

    if (data_usa_0217aafc.mUnk_04 != NULL) {
        if (data_usa_0217aafc.mUnk_ec != 0 && a == 0) {
            b = data_usa_0217aafc.mUnk_04->mUnk_04;
            for (i = 0; i < b->mUnk_18; i++) {
                func_02013424(b, i, (data_usa_0217aafc.mUnk_f0 & (1 << i)) != 0 ? 1 : 0);
            }
        } else {
            func_02013044(data_usa_0217aafc.mUnk_04->mUnk_04, a);
        }
    }
    if (data_usa_0217aafc.mUnk_e0 == 0) {
        return;
    }
    if (a != 0) {
        func_02013044(data_usa_0217aafc.mUnk_00->mUnk_04, 1);
        return;
    }
    b = data_usa_0217aafc.mUnk_00->mUnk_04;
    for (j = 0; j < b->mUnk_18; j++) {
        if ((data_usa_0217aafc.mUnk_e4 & (s64) (1 << j)) == 0) {
            func_02013424(b, j, 0);
        }
    }
}

void func_0206302c(void) {
    u32 i;
    Unk0201290c *b;
    u32 j;
    Unk0201290c *c;

    data_usa_0217aafc.mUnk_e0 = 0;
    data_usa_0217aafc.mUnk_e4 = 0;
    data_usa_0217aafc.mUnk_ec = 0;
    data_usa_0217aafc.mUnk_f0 = 0;
    switch (data_021759c0->mCourseId) {
        case 0x12:
        case 0x1b:
        case 0x2d:
            data_usa_0217aafc.mUnk_e0 = 1;
            break;
        case 0x1d:
            data_usa_0217aafc.mUnk_ec = 1;
            break;
    }
    if (data_usa_0217aafc.mUnk_e0 != 0) {
        b = data_usa_0217aafc.mUnk_00->mUnk_04;
        for (i = 0; i < b->mUnk_18; i++) {
            if (func_02013314(b, i) != 0) {
                data_usa_0217aafc.mUnk_e4 |= (s64) (1 << i);
            }
        }
    } else {
        func_02013044(data_usa_0217aafc.mUnk_00->mUnk_04, 1);
    }
    if (data_usa_0217aafc.mUnk_04 == NULL) {
        return;
    }
    if (data_usa_0217aafc.mUnk_ec == 0) {
        return;
    }
    c = data_usa_0217aafc.mUnk_04->mUnk_04;
    for (j = 0; j < c->mUnk_18; j++) {
        if (func_02013314(c, j) != 0) {
            data_usa_0217aafc.mUnk_f0 |= 1 << j;
        }
    }
}

void func_020631b0(void) {
    UnkVec16 a;

    if (data_021759c0->mCourseId != 0x20) {
        return;
    }
    a = data_usa_021653fc;
    func_02010fac(2, a.x, a.y, a.z);
    func_02010f98(2, 0x7fff);
}

void func_02063228(void) {
    if (data_usa_0217aafc.mUnk_04 == NULL) {
        return;
    }
    func_020849f8(data_usa_0217aafc.mUnk_04, &data_usa_0217abac, data_usa_02154a20);
}

void func_0206326c(void) {
    func_020849f8(data_usa_0217aafc.mUnk_00, &data_usa_0217abac, data_usa_02154a20);
}

void func_02063294(void) {
    if (data_usa_0217aafc.mUnk_20 != 0) {
        func_02087de0(data_usa_0217ab04);
    }
    if (data_usa_0217aafc.mUnk_58 != 0) {
        func_02087de0(data_usa_0217ab3c);
    }
    if (data_usa_0217aafc.mUnk_04 != NULL && data_usa_0217aafc.mUnk_90 != 0) {
        func_02087de0(data_usa_0217ab74);
    }
}

static inline void func_0206331c_inline(u32 a, u8 *b, Unk02084b2c *c, void *d, const char *e, const char *f, u16 *g) {
    if (f == NULL) {
        *g = 0;
    } else {
        func_0208823c(a, b, c, 1, d, (void *) e);
        func_0208805c(b, (void *) f, d);
        func_02087cfc(b, 0, 1);
        func_02087f84(b, 0);
    }
}

void func_0206331c(void *a) {
    const char *b;
    const char *c;
    const char *d;
    Unk0201290c *e;
    s32 f;
    s32 g[6];
    s32 i;

    b = FindCourseFile(data_usa_02165404);
    c = FindCourseFile(data_usa_02165418);
    data_usa_0217aafc.mUnk_00 = func_02036bec(a, 0x6c);
    e = func_02084b2c(a, data_usa_0217aafc.mUnk_00, (Unk020136f0 *) b, (Unk020136f0 *) c);
    d = FindCourseFile(data_usa_0216542c);
    func_0206331c_inline(2, data_usa_0217ab04, data_usa_0217aafc.mUnk_00, a, b, d, &data_usa_0217aafc.mUnk_20);
    d = FindCourseFile(data_usa_02165440);
    func_0206331c_inline(1, data_usa_0217ab3c, data_usa_0217aafc.mUnk_00, a, b, d, &data_usa_0217aafc.mUnk_58);
    func_020849c0(data_usa_0217aafc.mUnk_00, 8);
    func_02012ffc(e, 1);
    switch (data_021759c0->mCourseId) {
        case 0xc:
            f = func_02013754((u8 *) e + e->mUnk_08 + 4, data_usa_02154a00);
            if (f >= 0) {
                func_02013468(e, f, 0x1e);
                func_020133e0(e, f, 0);
            }
            break;
        case 0x16:
            f = func_02013754((u8 *) e + e->mUnk_08 + 4, data_usa_02154990);
            if (f >= 0) {
                func_020133e0(e, f, 0);
            }
            f = func_02013754((u8 *) e + e->mUnk_08 + 4, data_usa_02154a10);
            if (f >= 0) {
                func_020133e0(e, f, 0);
            }
            break;
    }
    data_usa_0217aafc.mUnk_04 = NULL;
    b = FindCourseFile(data_usa_02165454);
    c = FindCourseFile(data_usa_0216546c);
    if (b != NULL) {
        data_usa_0217aafc.mUnk_04 = func_02036bec(a, 0x6c);
        func_02084b2c(a, data_usa_0217aafc.mUnk_04, (Unk020136f0 *) b, (Unk020136f0 *) c);
        func_020849c0(data_usa_0217aafc.mUnk_04, 8);
        d = FindCourseFile(data_usa_02165484);
        func_0206331c_inline(1, data_usa_0217ab74, data_usa_0217aafc.mUnk_04, a, b, d, &data_usa_0217aafc.mUnk_90);
    }
    g[0] = func_02013754((u8 *) e + e->mUnk_08 + 4, data_usa_021549f0);
    g[1] = func_02013754((u8 *) e + e->mUnk_08 + 4, data_usa_021549c0);
    g[2] = func_02013754((u8 *) e + e->mUnk_08 + 4, data_usa_021549d0);
    g[3] = func_02013754((u8 *) e + e->mUnk_08 + 4, data_usa_021549e0);
    g[4] = func_02013754((u8 *) e + e->mUnk_08 + 4, data_usa_021549b0);
    g[5] = func_02013754((u8 *) e + e->mUnk_08 + 4, data_usa_021549a0);
    for (i = 0; i < 6; i++) {
        if (g[i] >= 0) {
            func_020134b0(e, g[i], 7);
        }
    }
    func_021471bc(&data_usa_0217abac);
    func_0206302c();
}

void func_020636f8(Unk0206bcb0 *a) {
    Unk0206bcb0_514 *b;
    Unk0217aa14_754_04 *c;
    Unk020636f8_B *d;

    c = &data_0217aa14->mUnk_754->mUnk_04;
    d = (Unk020636f8_B *) ((u8 *) c + 8);
    b = a->mUnk_514;
    d->mUnk_00 = a->mUnk_80.x >> 10;
    d->mUnk_02 = (a->mUnk_80.y - a->mUnk_2bc) >> 10;
    d->mUnk_04 = a->mUnk_80.z >> 10;
    d->mUnk_06 = a->mUnk_2a8 >> 2;
    d->mUnk_0a = a->mUnk_236;
    d->mUnk_10 = a->mUnk_44;
    d->mUnk_10 = d->mUnk_10 | (((b->mUnk_98.x >> 6) & 0xff) << 24 | ((b->mUnk_98.y >> 6) & 0xff) << 16 |
                               ((b->mUnk_98.z >> 6) & 0xff) << 8);
    d->mUnk_14 = a->mUnk_48;
    d->mUnk_0c = b->mUnk_2c;
    d->mUnk_08 = a->mUnk_388;
}

void func_020637c4(Unk0206bcb0 *a) {
    func_02064f50(a);
    func_020641f0(a);
}

void func_020637e0(Unk0206bcb0 *a) {
    if (func_0207a870() != 0) {
        func_0203c1a8(&a->mUnk_80, a->mUnk_74);
    }
    if ((a->mUnk_4c & 0x1000) != 0) {
        func_0206d138(a);
    }
    a->mUnk_4c = a->mUnk_4c & ~0x1000;
    func_020651fc(a);
}

void func_02063830(Unk0206bcb0 *a) {
    if (func_0207a870() != 0) {
        func_0203c1a8(&a->mUnk_80, a->mUnk_74);
    }
    if ((a->mUnk_4c & 0x1000) != 0) {
        func_0206d138(a);
    }
    a->mUnk_4c = a->mUnk_4c & ~0x1000;
    func_01ffcc50(a);
}

void func_02063880(Unk0206bcb0 *a) {
    func_01ffcb58(a);
    if ((data_0217aa14->mUnk_75c & 2) != 0) {
        func_020636f8(a);
    }
    func_020641f0(a);
}
