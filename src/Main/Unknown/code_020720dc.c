#include "Main/Unknown/code_020681f0.h"
#include "Main/Unknown/code_020720dc.h"
#include "Main/Unknown/code_02071ddc.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_02147000.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/code_02074854.h"
#include "Main/Unknown/code_020719d0.h"
#include "Main/Unknown/code_0207a104.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_02081338.h"
#include "Main/Unknown/code_020810e4.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_020815a0.h"
#include "Main/Unknown/code_0208ae60.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b6b0.h"
#include "Main/Unknown/code_0208c188.h"
#include "Main/Unknown/code_0208c4e8.h"
#include "Main/Unknown/code_0208c534.h"
#include "Main/Unknown/code_02089f9c.h"
#include "Main/Unknown/code_02103890.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_0210a664.h"
#include "Main/Unknown/code_0210b850.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0210fa40.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_027e0000.h"
#include "code_02146cbc.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "code_02148538.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_0206390c.h"

void func_020732d8(Unk0206bcb0 *p) {
    s32 i;
    enum { K0 } k;

    k = p->mUnk_78;
    data_0217566a[k].mBitMask = 0xff7;
    if (p->mUnk_7c & 0x20) {
        func_02068b98(p);
        return;
    }
    p->mUnk_3c8 = p->mUnk_3c8 + 1;
    i = p->mUnk_3c8;
    if (i >= 0x19) {
        p->mUnk_7c &= ~0x80;
        return;
    }
    p->mUnk_41c.x = data_usa_02154de4[i];
    p->mUnk_41c.y = data_usa_02154e48[i];
    p->mUnk_41c.z = data_usa_02154eac[i];
    p->mUnk_bc.x = (s32) (((s64) p->mUnk_428.x * p->mUnk_41c.x) >> 12);
    p->mUnk_bc.y = (s32) (((s64) p->mUnk_428.y * p->mUnk_41c.y) >> 12);
    p->mUnk_bc.z = (s32) (((s64) p->mUnk_428.z * p->mUnk_41c.z) >> 12);
    p->mUnk_bc.y = (s32) (((s64) p->mUnk_434 * p->mUnk_bc.y) >> 12);
}

void func_02072eb8(Unk0206bcb0 *p) {
    Vec3 a;
    Vec3 b;
    Vec3 c;
    Vec3 d;
    s32 m[9];
    Unk02175620_bc *r;
    s32 x;
    s32 y;
    s32 i;
    Unk020ee684 *e;
    s64 l;

    if (p->mUnk_3c4 == -1) {
        i = p->mIndex;
        if (data_021759c0->mUnk_08 == 2) {
            i = func_02041170(0);
        } else {
            i = func_02041170(data_0217561c->mUnk_000[i].mUnk_46);
        }
        p->mUnk_3c4 = i;
    }
    i = (u16) p->mUnk_3c4;
    if (data_021759c0->mUnk_08 == 2) {
        r = func_02040fd8(i, &a, &c);
    } else {
        r = func_020410a4(i, &a, &c);
    }
    i = ((u16) ((s32) (((s64) c.y * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12)) >> 4;
    Matrix3x3FromPairY(m, data_0215d4b4[i * 2], data_0215d4b4[i * 2 + 1]);
    Vec3MultiplyMatrix3x3(&data_02154f70, m, &b);
    if (data_021759c0->mUnk_08 != 2 && gCourseMap->mUnk_60 != 0) {
        (e = &(data_027e00c8)[p->mIndex])->mUnk_1f0.mUnk_00 = func_02040f78((u16) p->mUnk_3c4);
        e->mUnk_1f0.mUnk_04 = 1;
    }
    if (data_021759c0->mUnk_08 != 1) {
        x = data_usa_02154d4c[p->mIndex][0];
        y = data_usa_02154d50[p->mIndex][0];
        func_020397a8(&data_02154f7c, &b, &d);
        Vec3AddScaled((s32) (((s64) data_usa_02165504 * x) >> 12), &d, &a, &a);
        Vec3AddScaled((s32) (((s64) data_usa_02165504 * y) >> 12), &b, &a, &a);
        if (c.x != 0 && y != 0) {
            i = ((u16) ((s32) (((s64) c.x * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12)) >> 4;
            l = data_0215d4b4[i * 2];
            i = (s32) ((l * -y + 0x800) >> 12);
            a.y += (s32) (((s64) i * data_usa_02165504 + 0x800) >> 12);
        }
        if (c.z != 0 && x != 0) {
            i = ((u16) ((s32) (((s64) c.z * 0xb60b60b60bLL + 0x80000000LL) >> 32) >> 12)) >> 4;
            l = data_0215d4b4[i * 2];
            i = (s32) ((l * x + 0x800) >> 12);
            a.y += (s32) (((s64) i * data_usa_02165504 + 0x800) >> 12);
        }
    }
    a.y += 0x28000;
    x = p->mUnk_48;
    if (x & 0x800000) {
        func_02081f10(func_0208b7bc(0x71, &a), p->mIndex, 0x32);
    } else if (x & 0x1000000) {
        func_02081f10(func_0208b7bc(0x70, &a), p->mIndex, 0x32);
    }
    func_02072b94(p, &a, &b, r);
    if (p->mUnk_7c & 1) {
        func_0207a6b0()->mUnk_18++;
    } else {
        func_0210b850((Unk0210b7ec *) &p->mUnk_518);
    }
    p->mUnk_4c |= 0xc00;
    p->mUnk_48 |= 0x2000000;
    if (p->mUnk_7c & 1) {
        func_02055bd4(0x3c);
        func_02075d08(0);
    }
}

s32 func_02072d84(Unk0206bcb0 *p, s32 *a) {
    BOOL r;
    u32 f;

    f = p->mUnk_4c;
    r = FALSE;
    if (f & 0x4000000) {
        if (p->mUnk_4bc > 0x19a) {
            p->mUnk_4bc = (s32) (((s64) p->mUnk_4bc * 0xe66LL) >> 12);
        }
        *a = p->mUnk_4bc;
    } else if (f & 0x200000) {
        if (p->mUnk_4bc > 0x666) {
            p->mUnk_4bc = (s32) (((s64) p->mUnk_4bc * 0xe66LL) >> 12);
        }
        *a = p->mUnk_4bc;
    }
    p->mUnk_3c0 = p->mUnk_3c0 + 1;
    if (p->mUnk_7c & 1) {
        if (p->mUnk_3c0 == 0x16) {
            func_02055a94();
        } else if (p->mUnk_3c0 == 0x19) {
            func_02055c18(0x3c);
        }
    }
    if ((p->mUnk_7c & 1) && p->mUnk_3c0 == 0x55) {
        func_020e7a40();
    } else if (p->mUnk_3c0 > 0x78) {
        func_02063ad0(p);
        r = TRUE;
    }
    return r;
}

void func_02072b94(Unk0206bcb0 *p, const Vec3 *a, const Vec3 *b, Unk02175620_bc *c) {
    Unk0206bcb0_514 *q;
    Vec3 v;

    func_02072930(p);
    func_02079c0c(p->mKartModelsEntry);
    p->mUnk_210(p);
    p->mUnk_7c &= ~0xe000;
    func_02103890(p->mIndex);
    p->mUnk_48 |= 0x240;
    p->mUnk_80 = *a;
    if (p->mUnk_7c & 0x400) {
        q = p->mUnk_514;
        q->mUnk_00 = p->mUnk_80;
        q->mUnk_10 = q->mUnk_00;
        q->mUnk_4c = *(Vec4 *) &p->mUnk_108.z;
        q->mUnk_a8 = data_02154f94;
        q->mUnk_b4 = 0;
    }
    if (b != NULL) {
        p->mUnk_236 = (s32) (((s64) func_02148538(b->x, b->z) * 0x28be60dLL) >> 12) >> 12;
        v = data_02165524;
        func_01ffd190(&v, p->mUnk_236, &p->mUnk_e0_m);
    }
    func_01ffcd84(&p->mUnk_120, &p->mUnk_e0_m);
    func_02063b10(p, &p->mUnk_278);
    p->mUnk_50 = p->mUnk_278;
    p->mUnk_68 = p->mUnk_50;
    p->mUnk_8c = p->mUnk_80;
    p->mUnk_98 = p->mUnk_8c;
    p->mUnk_1c4 = p->mUnk_80;
    p->mUnk_1b8 = p->mUnk_80;
    p->mUnk_2ac = p->mUnk_80.y;
    if (p->mUnk_7c & 2) {
        if (c != NULL) {
            func_0208c23c(p->mUnk_310, c);
        } else {
            func_0208c260(p->mUnk_310, p->mIndex);
        }
    }
    if (p->mUnk_7c & 1) {
        func_0207409c(a, &p->mUnk_e0_m);
        func_02089f9c(((u32(*)(void)) func_02074828)());
        func_020747f4(0);
    }
}

void func_02072930(Unk0206bcb0 *p) {
    s32 i;
    Unk02165560 v;

    func_020f0044(&(data_027e00c8)[p->mIndex]);
    func_02083834(p);
    func_02081768(p->mIndex);
    func_020815a0(p->mIndex);
    func_02081338(p->mIndex);
    func_020810e4(p->mIndex);
    func_02080fb8(p);
    func_02080e9c(p);
    func_0208c5d0(func_0208c5b8(p->mIndex));
    func_020719d0(p);
    if (p->mIndex == data_021759c0->mUnk_62) {
        func_0210fa74(0);
    }
    func_0210a664(p);
    if (p->mUnk_4c & 0x2000) {
        func_0207b0d0(p);
    }
    if (p->mUnk_4c & 0x40) {
        p->mUnk_4c &= ~0x40;
        func_0207b1a8(p);
        p->mUnk_29c = 0;
        func_020817b8(p->mIndex);
        func_02068a64(p, 0, 1);
        if ((p->mUnk_7c & 1) && data_021759c0->mUnk_00c == 0) {
            func_02106dc8();
        }
        if (p->mUnk_4c & 0x2000) {
            func_0207b13c(p);
        }
    }
    if (p->mUnk_4c & 0x10000000) {
        p->mUnk_4c &= ~0x10000000;
        func_0210515c(p->mIndex);
        if (p->mUnk_7c & 1) {
            func_02074854();
        }
        p->mUnk_4c8 = 0x1000;
        p->mUnk_3dc = -1;
        i = 0;
        p->mUnk_29c = 0;
        if (p->mKartModelsEntry->mUnk_058 == 0) {
            v = data_usa_02165560;
            for (i = 0; i < 3; i++) {
                func_02081f10(func_0208b7bc(v.mUnk_00[i], &p->mUnk_80), p->mIndex, 0x14);
            }
        }
        func_020815dc(p->mIndex);
        func_021090c4(&p->mUnk_00, 0xfd, 0x7f, 0);
    }
    if (p->mUnk_7c & 0x2000) {
        p->mUnk_7c &= ~0x2000;
        p->mUnk_7c &= ~0xc000;
        p->mUnk_29c = 0;
        if (!(p->mUnk_7c & 1)) {
            func_0208c4e8(func_0208c5b8(p->mIndex));
        } else {
            func_021090c4(&p->mUnk_00, 0xf9, 0x7f, 0);
        }
        func_0210fa40(0, (p->mUnk_7c & 1) ? 1 : 0);
    }
}

void func_020727d4(Unk0206bcb0 *p) {
    Vec3 a;
    Vec3 b;
    Vec3 c;
    Vec3 *q;

    if (!(p->mUnk_7c & 0x20)) {
        return;
    }
    func_02041bb0(&a, &c, p->mIndex);
    p->mUnk_236 = (u32) (c.y * 0xb6) >> 12;
    func_01ffd190(&data_02154f7c, p->mUnk_236, &p->mUnk_e0_m);
    func_01ffcd84(&p->mUnk_120, &p->mUnk_e0_m);
    func_02063b10(p, &b);
    func_02072b94(p, &a, &b, NULL);
    if (data_021759c0->mUnk_08 == 5) {
        q = &p->mUnk_1d8;
    } else {
        q = &p->mUnk_1b8;
    }
    if (p->mUnk_2c8 == -1) {
        p->mUnk_2c8 = func_020d555c(q, p->mUnk_2cc->mUnk_00 + 0xd000, 0x8000, p);
    }
    if (p->mUnk_2ca == -1) {
        p->mUnk_2ca = func_020d555c(&p->mUnk_1f0, (s32) (((s64) p->mUnk_2cc->mUnk_00 << 15) >> 12), 0x800, p);
    }
    p->mUnk_7c |= 0x80;
    p->mUnk_7c &= ~0x60;
    p->mUnk_bc = data_02154f94;
}

void func_020726bc(Unk0206bcb0 *p) {
    s32 a;
    s32 b;
    s16 i;
    Unk0206cdd4_A *q;
    s32 *r;

    p->mUnk_2cc = func_0208ae8c(p->mIndex);
    a = 0x1000;
    b = 0;
    if (func_02062eb0() == 0) {
        switch (data_021759c0->mUnk_010) {
            case 0:
                a = 0xb33;
                b = -0x28;
                break;
            case 1:
                a = 0xd9a;
                b = -0x14;
                break;
        }
    }
    p->mUnk_2cc->mUnk_10 = (s32) (((s64) p->mUnk_2cc->mUnk_10 * a) >> 12);
    p->mUnk_2cc->mUnk_32 = p->mUnk_2cc->mUnk_32 + b;
    p->mUnk_3f4 = 0x1000 - p->mUnk_2cc->mUnk_68[4];
    p->mUnk_3f4 = DivFixed12(p->mUnk_3f4, p->mUnk_2cc->mUnk_00 << 1);
    p->mUnk_2d0 = func_0208ae74(p->mIndex);
    q = p->mUnk_2cc;
    r = p->mUnk_2d0;
    for (i = 0; i < 12; i++) {
        a = q->mUnk_68[i];
        if (a < 0x1000) {
            q->mUnk_68[i] = (s32) (((s64) a * *r + 0x800) >> 12);
        }
    }
}

void func_02072600(Unk0206bcb0 *p) {
    Vec3 v;

    p->mUnk_d4 = 0x1000;
    p->mUnk_d8 = 0x1000;
    p->mUnk_dc = 0x1000;
    p->mUnk_38c = 0x1000;
    v = data_02154f94;
    *(Vec3 *) &p->mUnk_25c = v;
    p->mUnk_268 = v;
    p->mUnk_274 = 0;
    p->mUnk_278 = v;
    p->mUnk_290 = v;
    p->mUnk_2d8 = v;
    p->mUnk_2e4 = v;
    p->mUnk_2f0 = v;
    *(Vec3 *) &p->mUnk_25c = v;
    p->mUnk_380 = 0;
    p->mUnk_388 = 0;
    p->mUnk_38a = 0;
    p->mUnk_240 = 0x1000;
    p->mUnk_386 = 0;
}

void func_020720dc(Unk0206bcb0 *p) {
    Vec3 v;
    u16 i;

    func_0207b8c4(p->mKartModelsEntry);
    p->mUnk_44 = 0;
    p->mUnk_48 = 0;
    p->mUnk_4c = 0;
    v = data_02154f94;
    p->mUnk_98 = v;
    p->mUnk_8c = p->mUnk_98;
    p->mUnk_80 = p->mUnk_8c;
    p->mUnk_a4 = v;
    p->mUnk_b0 = v;
    p->mUnk_bc.x = 0x1000;
    p->mUnk_bc.y = 0x1000;
    p->mUnk_bc.z = 0x1000;
    p->mUnk_41c.x = 0x1000;
    p->mUnk_41c.y = 0x1000;
    p->mUnk_41c.z = 0x1000;
    p->mUnk_428.x = 0x1000;
    p->mUnk_428.y = 0x1000;
    p->mUnk_428.z = 0x1000;
    p->mUnk_434 = 0x1000;
    p->mUnk_c8 = -0x2b9;
    p->mUnk_cc = 0;
    p->mUnk_d0 = 0xd000;
    p->mUnk_d4 = 0x1000;
    p->mUnk_d8 = 0x1000;
    p->mState = 0;
    func_02071ddc(&p->mUnk_538);
    Matrix4x3Identity(&p->mUnk_120_m);
    Matrix4x3Identity(&p->mUnk_150_m);
    Matrix4x3Identity(&p->mUnk_184_m);
    p->mUnk_1d8 = v;
    p->mUnk_1e4 = p->mUnk_1d8;
    p->mUnk_1c4 = p->mUnk_1e4;
    p->mUnk_1b8 = p->mUnk_1c4;
    p->mUnk_1f0 = v;
    p->mUnk_1fc = v;
    p->mUnk_dc = 0x1000;
    p->mUnk_e0_m = data_usa_02154f14;
    *(Vec4 *) &p->mUnk_f0 = data_usa_02154f24;
    *(Vec4 *) &p->mUnk_100 = data_usa_02154f34;
    *(Vec4 *) &p->mUnk_108.z = data_usa_02154f44;
    p->mUnk_234 = 0;
    p->mUnk_236 = 0;
    p->mUnk_238 = 0;
    p->mUnk_23a = 0;
    p->mUnk_23c = 0;
    p->mUnk_240 = 0x1000;
    p->mUnk_244 = data_02154f7c;
    p->mUnk_250 = v;
    *(Vec3 *) &p->mUnk_25c = v;
    p->mUnk_268 = v;
    p->mUnk_274 = 0;
    p->mUnk_278 = v;
    p->mUnk_290 = v;
    p->mUnk_50 = v;
    p->mUnk_68 = p->mUnk_50;
    p->mUnk_2a0 = 0;
    p->mUnk_2a4 = 0;
    p->mUnk_2a8 = 0;
    p->mUnk_2ac = 0;
    p->mUnk_2b0 = 0;
    p->mUnk_2b2 = 0;
    p->mUnk_2b4 = 0;
    p->mUnk_29c = 0;
    p->mUnk_2b8 = 0;
    p->mUnk_2bc = 0;
    p->mUnk_2c0 = 0;
    p->mUnk_2c4 = 0;
    p->mUnk_2d4 = 0;
    p->mUnk_2d8 = v;
    p->mUnk_334 = 0;
    p->mUnk_338 = 0;
    p->mUnk_33c = 0;
    p->mUnk_344 = 0;
    p->mUnk_340 = p->mUnk_80.y;
    p->mUnk_348 = 0;
    p->mUnk_2fc = 0;
    p->mUnk_302 = 0;
    p->mUnk_300 = p->mUnk_302;
    p->mUnk_308 = NULL;
    p->mUnk_304 = p->mUnk_308;
    p->mUnk_30c = 0;
    p->mUnk_314 = 0;
    p->mUnk_318 = 0;
    p->mUnk_31c = v;
    p->mUnk_34c = data_usa_02154f54;
    p->mUnk_35c = 0;
    p->mUnk_360 = 0;
    p->mUnk_364 = 0;
    p->mUnk_36c = 0;
    p->mUnk_366 = 0;
    p->mUnk_368 = 0;
    p->mUnk_370 = 0;
    p->mUnk_374 = v;
    p->mUnk_380 = 0;
    p->mUnk_384 = 0xffff;
    p->mUnk_386 = 0;
    p->mUnk_388 = 0;
    p->mUnk_38a = 0;
    p->mUnk_38c = 0x1000;
    p->mUnk_394 = 0x1000;
    p->mUnk_39c = 0;
    p->mUnk_3a0 = 0;
    p->mUnk_3a4 = 0;
    p->mUnk_3a8 = 0x1ec;
    p->mUnk_3ac = 0;
    p->mUnk_a4 = v;
    p->mUnk_3bc = 0;
    p->mUnk_3be = 0;
    p->mUnk_3c0 = 0;
    p->mUnk_3c4 = -1;
    p->mUnk_3c8 = 0;
    p->mUnk_3d2 = 0;
    p->mUnk_3d4 = 0;
    p->mUnk_3dc = -1;
    p->mUnk_3e0 = 0;
    p->mUnk_3e4 = 0;
    p->mUnk_3e8 = 0;
    p->mUnk_3ec = 0;
    p->mUnk_3f0 = 0;
    p->mUnk_3f8 = 0x1000;
    p->mUnk_3fc = 0;
    p->mUnk_3fe = 0;
    p->mUnk_400 = 0;
    p->mUnk_404 = 0x1000;
    p->mUnk_414 = 0x1000;
    p->mUnk_418 = 0x1000;
    for (i = 0; i < 2; i++) {
        p->mUnk_438[i] = NULL;
        p->mUnk_440[i] = 0;
        p->mUnk_444[i] = 0;
    }
    p->mUnk_44c = NULL;
    p->mUnk_408 = 0;
    p->mUnk_40c = 0;
    p->mUnk_410 = 0;
    p->mUnk_4bc = 0;
    p->mUnk_4c0 = 0;
    p->mUnk_4c4 = 0;
    p->mUnk_4c8 = 0x1000;
    p->mUnk_4d0 = 0;
    p->mUnk_4d4 = 0;
    p->mUnk_4d8 = -1;
    p->mUnk_4dc = 0;
    p->mUnk_4da = 0;
    p->mUnk_4de = 0;
    p->mUnk_4e0 = 0;
    p->mUnk_4e2 = 1;
    p->mUnk_4e4 = 0;
    p->mUnk_4ec = 0;
    p->mUnk_4e8 = 0x1000;
    p->mUnk_4f0 = data_usa_02154f64;
    p->mUnk_4f0.z = 0;
    p->mUnk_4fc = 0;
    p->mUnk_500 = 0;
    p->mUnk_506 = 0;
    p->mUnk_504 = p->mUnk_506;
    p->mUnk_59c = 0;
    p->mUnk_594 = p->mUnk_59c;
    p->mUnk_5a0 = 0;
    p->mUnk_3d8 = 0;
    func_02068a64(p, 0, 0);
    p->mUnk_4cc = 0;
}
