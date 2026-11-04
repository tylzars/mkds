#include "Main/Unknown/code_02046ad0.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_020a1748.h"
#include "Main/Unknown/code_020fa4c8.h"

#include "Main/Unknown/code_020fc2e8.h"
#include "Main/Unknown/code_020fcbb8.h"
#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/unk_02159000.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01fff000.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020fc000.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffd000.h"
#include "ITCM/code_01fff434.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/code_0208eb10.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020f73fc.h"
#include "Main/Unknown/code_020f81c0.h"
#include "Main/Unknown/code_020f830c.h"
#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_020f9334.h"
#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020fc2c0.h"
#include "Main/Unknown/code_020fcb9c.h"
#include "Main/Unknown/code_020fcedc.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_020ff000.h"
#include "Main/Unknown/code_02103890.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_0210e000.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020f2000.h"
#include "Main/Unknown/code_020fa000.h"

#pragma thumb off

void func_020fc268(Unk020fc2e8 *param_1) {
    func_020f2228((Unk020f1d70 *) param_1, 0xd000);
    if (param_1->mUnk_000.mUnk_74 & 1) {
        return;
    }
    func_0210b7ec(&param_1->mUnk_300, param_1->mUnk_000.mUnk_d4 & ~0xc000001f);
    if (param_1->mUnk_270 == 1) {
        return;
    }
    func_02109078(&param_1->mUnk_000.mUnk_00, param_1->mUnk_270, 0x7f, 0);
}

static inline Vec3 *func_020fbd98_inline(Unk020fc2e8 *p) {
    if (p->mUnk_2f6 >= 3) {
        if (p->mUnk_228->mUnk_1fc->mUnk_48 & 1) {
            return &p->mUnk_228->mUnk_1fc->mUnk_244;
        }
    } else if (p->mUnk_000.mUnk_74 & 0x40000000) {
        return &p->mUnk_000.mUnk_f0;
    }
    return NULL;
}

void func_020fbd98(Unk020fc2e8 *param_1) {
    u32 i;
    s32 r;
    s32 v;
    void *q;
    Unk0206bcb0 *p;

    if (param_1->mUnk_2ec == 8) {
        param_1->mUnk_26c = func_0208ec64((u32) param_1->mUnk_000.mUnk_d0);
    }
    func_020ec918((Unk020ec8bc *) param_1, param_1->mUnk_27c, 0x21, param_1->mUnk_276, 1);
    if (!(param_1->mUnk_000.mUnk_74 & 1)) {
        func_0210b7ec(&param_1->mUnk_300, param_1->mUnk_000.mUnk_d4 & ~0xc000001f);
        if (param_1->mUnk_270 != 1) {
            func_02109078(&param_1->mUnk_000.mUnk_00, param_1->mUnk_270, 0x7f, 0);
        }
    }
    param_1->mUnk_000.mUnk_5c.y -= (s32) (((s64) * (s32 *) param_1->mUnk_12c * 0x66) >> 12);
    if (param_1->mUnk_000.mUnk_74 & 1) {
        return;
    }
    func_020fc654(param_1);
    q = func_020fbd98_inline(param_1);
    func_020fc2e8(param_1, &param_1->mUnk_000.mUnk_5c, 1, q);
    if (param_1->mUnk_278 == 0) {
        if (data_0217561c->mUnk_4cc != 0) {
            param_1->mUnk_274 = 1;
            param_1->mUnk_276 = data_0217561c->mUnk_474[(u8) param_1->mUnk_274 - 1];
        } else {
            param_1->mUnk_276 = data_0217561c->mUnk_474[(u8) param_1->mUnk_274 - 1];
            while (func_0203c880(param_1->mUnk_276) != 0 && (u32) param_1->mUnk_274 < (u8) data_021759c0->mKartCount) {
                (param_1->mUnk_274)++;
                param_1->mUnk_276 = data_0217561c->mUnk_474[(u8) param_1->mUnk_274 - 1];
            }
        }
        if (param_1->mUnk_276 ==
                (u16) (!(param_1->mUnk_000.mUnk_78 & 0x8000) ? (u16) (param_1->mUnk_000.mUnk_78 & ~0xff00) : 8) ||
            func_02068eac(func_0207a974(param_1->mUnk_276)) != 0) {
            param_1->mUnk_278 = 1;
        } else {
            param_1->mUnk_280 |= 1 << param_1->mUnk_276;
        }
    }
    if (param_1->mUnk_278 != 0) {
        u32 n;
        n = (u8) data_021759c0->mKartCount;
        for (i = 1; i <= n; i = (u16) (i + 1)) {
            param_1->mUnk_276 = data_0217561c->mUnk_474[(u8) i - 1];
            if (func_02068eac(func_0207a974(param_1->mUnk_276)) == 0) {
                break;
            }
        }
        param_1->mUnk_280 |= 1 << param_1->mUnk_276;
    }
    if (func_020fcbb8(param_1, param_1->mUnk_276) != 0) {
        p = param_1->mUnk_228->mUnk_1fc;
        r = ((param_1->mUnk_000.mUnk_74 & 0x40000000) || (p->mUnk_48 & 1)) ? 2 : 3;
        param_1->mUnk_2f8 = r;
        param_1->mUnk_2fa = 1;
        if (param_1->mUnk_000.mUnk_74 & 0x8000000) {
            func_020fe71c(5, param_1->mUnk_228->mUnk_1f8, param_1->mUnk_000.mUnk_4e);
        }
        return;
    }
    r = (u16) func_02061f90();
    if ((param_1->mUnk_280 & (1 << r)) != 0 && param_1->mUnk_276 != r && func_0203c880(r) != 0 &&
        func_020fcbb8(param_1, r) != 0) {
        p = param_1->mUnk_228->mUnk_1fc;
        v = ((param_1->mUnk_000.mUnk_74 & 0x40000000) || (p->mUnk_48 & 1)) ? 2 : 3;
        param_1->mUnk_2f8 = v;
        param_1->mUnk_2fa = 1;
        if (param_1->mUnk_000.mUnk_74 & 0x8000000) {
            func_020fe71c(5, param_1->mUnk_228->mUnk_1f8, param_1->mUnk_000.mUnk_4e);
        }
        return;
    }
    if (param_1->mUnk_2ec <= 0xa8c) {
        return;
    }
    v = (u16) data_0217561c->mUnk_474[0];
    if (param_1->mUnk_228 != NULL) {
        return;
    }
    if ((u32) v >= 8) {
        v = 0;
    }
    func_020fcb9c((s32) param_1, (u16) v);
    p = param_1->mUnk_228->mUnk_1fc;
    r = ((param_1->mUnk_000.mUnk_74 & 0x40000000) || (p->mUnk_48 & 1)) ? 2 : 3;
    param_1->mUnk_2f8 = r;
    param_1->mUnk_2fa = 1;
}

void func_020fbd4c(Unk020fc2e8 *param_1) {
    param_1->mUnk_27c = Vec3Length(&param_1->mUnk_000.mUnk_5c);
    param_1->mUnk_284 = 0x1e000;
    if (param_1->mUnk_228->mUnk_1f8 == data_021759c0->mUnk_62) {
        param_1->mUnk_270 = 0xdd;
    }
}

void func_020fbc18(Unk020fc2e8 *param_1) {
    s32 r;
    void *q;
    Unk0206bcb0 *p;

    p = param_1->mUnk_228->mUnk_1fc;
    r = 0x800;
    if ((param_1->mUnk_000.mUnk_74 & 0x10000000) && (p->mUnk_7c & 1)) {
        r += 0x19a;
    }
    if (param_1->mUnk_27c > 0xd000) {
        param_1->mUnk_27c -= 0xccd;
    } else {
        param_1->mUnk_27c += 0xccd;
    }
    func_020fcedc((u32) param_1, r, param_1->mUnk_27c, param_1->mUnk_284);
    if (!(param_1->mUnk_000.mUnk_74 & 1)) {
        func_0210b7ec(&param_1->mUnk_300, param_1->mUnk_000.mUnk_d4 & ~0xc000001f);
        if (param_1->mUnk_270 != 1) {
            func_02109078(&param_1->mUnk_000.mUnk_00, param_1->mUnk_270, 0x7f, 0);
        }
    }
    if ((s64) param_1->mUnk_238.x * param_1->mUnk_238.x + (s64) param_1->mUnk_238.z * param_1->mUnk_238.z <
        0x1900000000LL) {
        param_1->mUnk_2f8 = 4;
        param_1->mUnk_2fa = 1;
    }
    func_020fc654(param_1);
    q = func_020fbd98_inline(param_1);
    func_020fc2e8(param_1, &param_1->mUnk_000.mUnk_5c, 1, q);
}

void func_020fbae0(Unk020fc2e8 *param_1) {
    s32 i;
    void *q;
    Unk020f371c *p;

    if (param_1->mUnk_27c > 0xd000) {
        param_1->mUnk_27c -= 0xccd;
    } else {
        param_1->mUnk_27c += 0xccd;
    }
    func_020ec918((Unk020ec8bc *) param_1, param_1->mUnk_27c, 0x21, param_1->mUnk_276, 1);
    if (!(param_1->mUnk_000.mUnk_74 & 1)) {
        func_0210b7ec(&param_1->mUnk_300, param_1->mUnk_000.mUnk_d4 & ~0xc000001f);
        if (param_1->mUnk_270 != 1) {
            func_02109078(&param_1->mUnk_000.mUnk_00, param_1->mUnk_270, 0x7f, 0);
        }
    }
    if (param_1->mUnk_000.mUnk_74 & 1) {
        return;
    }
    func_020fc654(param_1);
    q = func_020fbd98_inline(param_1);
    func_020fc2e8(param_1, &param_1->mUnk_000.mUnk_5c, 1, q);
    p = param_1->mUnk_228->mUnk_1f0.mUnk_00;
    for (i = 0; i < 4; i++) {
        if (p == param_1->mUnk_168) {
            param_1->mUnk_2f8 = 3;
            param_1->mUnk_2fa = 1;
        }
        p = p->mUnk_00[0];
    }
}

void func_020fba6c(Unk020fc2e8 *param_1) {
    param_1->mUnk_264 = 0x5000;
    param_1->mUnk_288 = 0x3e8;
    Vec3Sub(&param_1->mUnk_238, &param_1->mUnk_298, &param_1->mUnk_28c);
    if (param_1->mUnk_26c != 0) {
        func_0208eb10(param_1->mUnk_26c);
        param_1->mUnk_26c = 0;
    }
    if (param_1->mUnk_000.mUnk_74 & 0x8000000) {
        func_020fe71c(5, param_1->mUnk_228->mUnk_1f8, param_1->mUnk_000.mUnk_4e);
    }
}

void func_020fb7f8(Unk020fc2e8 *param_1) {
    Vec3 v;
    void *q;

    if (param_1->mUnk_27c > 0xd000) {
        param_1->mUnk_27c -= 0xccd;
    } else {
        param_1->mUnk_27c += 0xccd;
    }
    param_1->mUnk_260 -= 0xccd;
    param_1->mUnk_288 += 0x2d;
    if ((u32) param_1->mUnk_25c < 0x8000) {
        param_1->mUnk_284 -= 0x666;
    } else {
        param_1->mUnk_284 -= 0xccd;
    }
    func_020fce94(param_1, 0x4cd, param_1->mUnk_27c, param_1->mUnk_284, param_1->mUnk_288);
    if (!(param_1->mUnk_000.mUnk_74 & 1)) {
        func_0210b7ec(&param_1->mUnk_300, param_1->mUnk_000.mUnk_d4 & ~0xc000001f);
        if (param_1->mUnk_270 != 1) {
            func_02109078(&param_1->mUnk_000.mUnk_00, param_1->mUnk_270, 0x7f, 0);
        }
    }
    func_020fc654(param_1);
    if ((u32) param_1->mUnk_25c < 0x11f40) {
        q = func_020fbd98_inline(param_1);
        if (q != NULL) {
            v.x = param_1->mUnk_250.x * 2;
            v.y = param_1->mUnk_250.y * 2;
            v.z = param_1->mUnk_250.z * 2;
            func_020397a8(q, &v, &v);
            Vec3AddScaled((s32) (((s64) (param_1->mUnk_25c - 0x10000) * 0xccd) >> 12), q, &v, &v);
        } else {
            v.x = (s32) (((s64) param_1->mUnk_250.z * 0x2000) >> 12);
            v.y = (s32) (((s64) (param_1->mUnk_25c - 0x10000) * 0xccd) >> 12);
            v.z = -(s32) (((s64) param_1->mUnk_250.x * 0x2000) >> 12);
        }
        if (param_1->mUnk_2ec == 0) {
            Vec3Sub(&v, &param_1->mUnk_298, &param_1->mUnk_28c);
        }
        func_020fc2e8(param_1, &v, 1, q);
        return;
    }
    param_1->mUnk_2f8 = 5;
    param_1->mUnk_2fa = 1;
}

void func_020fb770(Unk020fc2e8 *param_1) {
    enum { K0 } k;

    if (param_1->mUnk_000.mUnk_d0 == &param_1->mUnk_000.mUnk_0c4) {
        param_1->mUnk_000.mUnk_50 = param_1->mUnk_000.mUnk_0c4;
        param_1->mUnk_000.mUnk_d0 = &param_1->mUnk_000.mUnk_50;
    }
    param_1->mUnk_260 = 0x28000;
    param_1->mUnk_264 = 0x333;
    k = param_1->mUnk_000.mUnk_44;
    param_1->mUnk_000.mUnk_100 = data_0217bc34[k].mUnk_74;
    param_1->mUnk_000.mUnk_74 |= 0x800000;
    param_1->mUnk_2a4 = param_1->mUnk_28c;
    param_1->mUnk_27c = 0x3000;
    param_1->mUnk_284 = 0x59a;
}

void func_020fb61c(Unk020fc2e8 *param_1) {
    Vec3 v;
    Vec3 *q;
    s32 x;
    s32 y;
    s32 z;

    param_1->mUnk_260 += 0x4cd;
    func_020fcce4(param_1, param_1->mUnk_264, param_1->mUnk_260);
    if ((s32) param_1->mUnk_264 < 0xb33) {
        param_1->mUnk_264 += 0x52;
    }
    if (param_1->mUnk_260 > 0x2d000) {
        param_1->mUnk_2f8 = 6;
        param_1->mUnk_2fa = 1;
    }
    param_1->mUnk_27c -= 0xa14;
    param_1->mUnk_284 -= 0x102;
    if (param_1->mUnk_284 < 0x7b) {
        param_1->mUnk_284 = 0x7b;
    }
    q = func_020fbd98_inline(param_1);
    if (q != NULL) {
        Vec3AddScaled(param_1->mUnk_27c, q, &param_1->mUnk_22c, &v);
    } else {
        z = param_1->mUnk_22c.z;
        y = param_1->mUnk_27c;
        x = param_1->mUnk_22c.x;
        v.x = x;
        v.y = y;
        v.z = z;
    }
    Vec3Sub(&v, &param_1->mUnk_2a4, &v);
    Vec3AddScaled(param_1->mUnk_284, &v, &param_1->mUnk_2a4, &param_1->mUnk_2a4);
    func_020fc2e8(param_1, &param_1->mUnk_2a4, 0, q);
}

void func_020fb5dc(Unk020fc2e8 *param_1) {
    enum { K0 } k;

    param_1->mUnk_260 = 0x28000;
    k = param_1->mUnk_000.mUnk_44;
    param_1->mUnk_000.mUnk_100 = data_0217bc34[k].mUnk_74;
    param_1->mUnk_000.mUnk_100 += 0x800;
    func_020f9c6c(&param_1->mUnk_000);
}

void func_020fb46c(Unk020fc2e8 *param_1) {
    s32 r;
    Vec3 v;

    param_1->mUnk_260 -= 0x7000;
    func_020fcce4(param_1, 0xb33, param_1->mUnk_260);
    if (param_1->mUnk_260 < -0x32000) {
        func_020f7104(&param_1->mUnk_000, 0);
        if (param_1->mUnk_000.mUnk_74 & 0x8000000) {
            func_020fe71c(5, param_1->mUnk_228->mUnk_1f8, param_1->mUnk_000.mUnk_4e);
        }
    } else {
        Vec3 *pv;

        pv = &param_1->mUnk_000.mUnk_50;
        if (func_01ffdee4(pv, &param_1->mUnk_000.mUnk_0e4, 0, param_1->mUnk_000.mUnk_dc, 4, param_1->mUnk_000.mUnk_da,
                          &v, NULL, NULL, &param_1->mUnk_000.mUnk_fc, NULL, NULL, NULL, NULL) != 0) {
            Vec3Add(&v, pv, pv);
            func_020f7104(&param_1->mUnk_000, 0);
            if (param_1->mUnk_000.mUnk_74 & 0x8000000) {
                func_020fe71c(5, param_1->mUnk_228->mUnk_1f8, param_1->mUnk_000.mUnk_4e);
            }
        }
    }
    r = func_020fa0b8(param_1, data_0217bc34[param_1->mUnk_000.mUnk_44].mUnk_74,
                      data_0217bc34[param_1->mUnk_000.mUnk_44].mUnk_78);
    if (func_020f9ce8(&param_1->mUnk_000) != 0) {
        return;
    }
    if (r) {
        func_020fa030(&param_1->mUnk_000);
    }
}

void func_020fb35c(Unk020fc2e8 *param_1) {
    Unk0212c400 **p;
    struct Unk0208e490 *q;
    s32 *v;

    param_1->mUnk_000.mUnk_74 |= 0x800000;
    param_1->mUnk_000.mUnk_100 = 0;
    param_1->mUnk_000.mUnk_68 = data_02159d84;
    param_1->mUnk_2b0 = func_0208e490(1, &param_1->mUnk_000.mUnk_50, func_020f9160(&param_1->mUnk_000) == 0 ? 1 : 0);
    q = param_1->mUnk_2b0;
    if (q != NULL) {
        v = q->mUnk_9c;
        v[0] = 0x1000;
        v[1] = 0x1000;
        v[2] = 0x1000;
    }
    func_020f91fc(param_1, 0xdf);
    if (data_0217c780 & 1) {
        p = func_0210e128(func_02108ea0(0));
        if (data_0217d084.mUnk_0c != 0) {
            if (*p != NULL) {
                func_0212c6f0(p, 0);
            }
            if (*p != NULL) {
                func_0212c6f0(p, 0);
            }
            func_0212ecc0(p, 0, 0xe0);
        }
    }
    func_02073fb0(param_1->mUnk_000.mUnk_d4 & ~0xc000001f, 0x1000);
}

void func_020fb2b4(Unk020fc2e8 *param_1) {
    u32 v;

    v = param_1->mUnk_2ec;
    if (func_020fa0b8(param_1, data_0217bd3c, data_0217bd44)) {
        func_020f9fa8(&param_1->mUnk_000);
    }
    if (v < 0x16) {
        return;
    }
    if (v == 0x16) {
        param_1->mUnk_2e4 = 1;
    } else if (v == 0x2a) {
        func_020f9c40((s32) param_1);
    }
    if (v <= 0x55) {
        return;
    }
    func_020f0f70(&data_027e00cc[param_1->mUnk_000.mUnk_44], &param_1->mUnk_000);
}

void *func_020fb208(void *param_1, Unk020fc2e8 *param_2, void *param_3) {
    void *r;
    void *t;

    if (param_2 != NULL && param_3 != NULL) {
        func_020ff1b8(func_02039828(&param_2->mUnk_000.mUnk_5c, (Vec3 *) &param_2->mUnk_130) < 0 ? 1 : 0,
                      &param_2->mUnk_000.mUnk_5c.y);
    }
    t = func_020fecdc(param_1, param_2, param_3);
    r = func_020ff040(t, param_2 != NULL ? (void *) &param_2->mUnk_21c : 0, param_3);
    if (param_2 != NULL && param_3 == NULL) {
        func_020ff1a0(param_2->mUnk_000.mUnk_5c.y, &param_2->mUnk_2fc);
    }
    if (param_2 != NULL && param_3 != NULL) {
        return func_020fe8ac(param_2->mUnk_000.mUnk_44);
    }
    return r;
}

void func_020fb038(Unk020fc2e8 *param_1) {
    s32 v;
    Unk020fb038 s;
    Unk0206bcb0 *q;
    s32 r;

    func_020f8e78(param_1);
    if (param_1->mUnk_21c != 0) {
        func_020ec8bc((Unk020ec8bc *) param_1, 0x14, 0xcc, 1, 0, param_1->mUnk_2fc, (u16) data_0217561c->mUnk_474[0],
                      1);
        func_02046bcc(&param_1->mUnk_2e8, 1);
    } else if (param_1->mUnk_000.mUnk_74 & 0x8000000) {
        v = (u16) data_0217561c->mUnk_474[0];
        if (param_1->mUnk_228 == NULL) {
            func_020fcb9c((s32) param_1, v);
            q = param_1->mUnk_228->mUnk_1fc;
            r = ((param_1->mUnk_000.mUnk_74 & 0x40000000) || (q->mUnk_48 & 1)) ? 2 : 3;
            param_1->mUnk_2f8 = r;
            param_1->mUnk_2fa = 1;
        }
    } else {
        v = (u16) data_0217561c->mUnk_474[0];
        func_020fcb9c((s32) param_1, v);
        q = param_1->mUnk_228->mUnk_1fc;
        r = ((param_1->mUnk_000.mUnk_74 & 0x40000000) || (q->mUnk_48 & 1)) ? 2 : 3;
        param_1->mUnk_2f8 = r;
        param_1->mUnk_2fa = 1;
        if (param_1->mUnk_000.mUnk_74 & 0x8000000) {
            func_020fe71c(5, param_1->mUnk_228->mUnk_1f8, param_1->mUnk_000.mUnk_4e);
        }
    }
    func_020fc94c(param_1);
    if ((s64) param_1->mUnk_000.mUnk_5c.x * param_1->mUnk_000.mUnk_5c.x +
            (s64) param_1->mUnk_000.mUnk_5c.y * param_1->mUnk_000.mUnk_5c.y +
            (s64) param_1->mUnk_000.mUnk_5c.z * param_1->mUnk_000.mUnk_5c.z >=
        0x10) {
        func_02039860(&param_1->mUnk_000.mUnk_5c, &s.mUnk_00);
    }
    func_020d7b88((Vec3 *) &s.mUnk_00, &s.mUnk_0c);
    func_01ffccd0(&param_1->mUnk_000.mUnk_94, &s.mUnk_0c);
}

void func_020faed0(Unk020fc2e8 *param_1, s32 param_2, s32 param_3) {
    u32 n;
    Vec3 v;
    void *q;

    if (param_1->mUnk_000.mUnk_74 & 0x2000) {
        if (func_020f91c4(&param_1->mUnk_000, 0x6a4) != 0) {
            return;
        }
    }
    v.x = v.z = param_1->mUnk_000.mUnk_68.x;
    v.y = param_1->mUnk_000.mUnk_68.y;
    if (param_1->mUnk_000.mUnk_d8 != 0x1f) {
        u32 i;
        Unk0201290c *o;

        o = data_0217bd38->mUnk_004;
        n = (u16) param_1->mUnk_000.mUnk_d8;
        for (i = 0; i < o->mEntryCount; i++) {
            func_02013468(o, i, n);
        }
    }
    if (param_1->mUnk_000.mUnk_74 & 0x80000) {
        q = func_020ed98c(&param_1->mUnk_000, (Vec3 *) param_2);
    } else {
        Vec3 *pv;

        pv = param_1->mUnk_000.mUnk_d0;
        param_1->mUnk_000.mUnk_94.mUnk_00[3].x = pv->x >> 4;
        param_1->mUnk_000.mUnk_94.mUnk_00[3].y = pv->y >> 4;
        param_1->mUnk_000.mUnk_94.mUnk_00[3].z = pv->z >> 4;
        q = &param_1->mUnk_000.mUnk_94;
    }
    func_020ea8a8(data_0217bd38, q, &v, 0x1f);
    if (param_1->mUnk_000.mUnk_d8 == 0x1f) {
        return;
    }
    {
        u32 i;
        Unk0201290c *o;

        o = data_0217bd38->mUnk_004;
        for (i = 0; i < o->mEntryCount; i++) {
            func_02013468(o, i, 0x1f);
        }
    }
}

void func_020fae74(Unk020fc2e8 *param_1, s32 param_2, s32 param_3) {
    Unk0208e490 *q;

    if (param_1->mUnk_2f6 != 7) {
        func_020faed0(param_1, param_2, param_3);
        return;
    }
    q = param_1->mUnk_2b0;
    if (q == NULL) {
        return;
    }
    q->mUnk_b4 = (param_1->mUnk_000.mUnk_74 & 0x10000) == 0;
}

s32 func_020fade4(Unk020fc2e8 *param_1) {
    if (param_1->mUnk_2f6 != 7) {
        func_02046be8(&param_1->mUnk_2e8, (UnkFunc *const *) data_0216c6b4, 8, param_1);
        param_1->mUnk_2f8 = 7;
        param_1->mUnk_2fa = 1;
        if ((param_1->mUnk_000.mUnk_74 & 0x180000) == 0) {
            param_1->mUnk_000.mUnk_120 = (void (*)(struct Unk020f41c4_A *)) func_020fc2c0;
        }
        param_1->mUnk_000.mUnk_74 &= ~0x8000;
        param_1->mUnk_000.mUnk_74 |= 0x80000;
        func_020f9c6c(&param_1->mUnk_000);
        param_1->mUnk_000.mUnk_78 &= ~0x4000;
    }
    return 1;
}

BOOL func_020fadcc(Unk020fc2e8 *param_1) {
    return param_1->mUnk_2f6 == 7;
}

Vec3 *func_020fad9c(Unk020fc2e8 *param_1, s32 *param_2, s32 *param_3) {
    *param_2 = param_1->mUnk_2ec;
    *param_3 = (s32) (((s64) param_1->mUnk_000.mUnk_68.z * data_0217bd40) >> 12);
    return &param_1->mUnk_000.mUnk_50;
}

#pragma thumb on

void func_020fad00(void) {
    s32 a;
    s32 b;
    s32 v;

    data_0217bd3c = 0x1e000;
    data_0217bd40 = DivFixed12(0x1000, data_0217bd3c);
    data_0217bd44 = 0x299a;
    a = data_0217bd3c;
    b = data_0217bc34[5].mUnk_6c;
    v = (s32) (((s64) a * b) >> 12);
    data_0217bd34 = v;
    v >>= 12;
    data_0217bd34 = v;
    data_0217bd34 = v * v;
    data_0217bd38 = func_020ed490(data_0216c6f4, data_0216c704);
    if (data_021759c0->mCourseId == 0x1d) {
        func_02013044(data_0217bd38->mUnk_004, 0);
    }
}

#pragma thumb off

BOOL func_020faca4(s32 param_1) {
    if (param_1 != 0x13) {
        return data_027e00cc[data_0217bc48[param_1].mUnk_08].mUnk_0c -
                   data_027e00cc[data_0217bc48[param_1].mUnk_08].mUnk_1c >=
               data_0217bc48[param_1].mUnk_0c;
    }
    return FALSE;
}

static inline BOOL func_020fab34_inline(s32 param_1) {
    if (param_1 != 0x13) {
        return data_027e00cc[data_0217bc48[param_1].mUnk_08].mUnk_0c -
                   data_027e00cc[data_0217bc48[param_1].mUnk_08].mUnk_1c >=
               data_0217bc48[param_1].mUnk_0c;
    }
    return FALSE;
}

BOOL func_020fab34(s32 *param_1) {
    s32 i;
    s32 v;
    Unk0217bc48 *e;
    s32 n;

    i = *param_1;
    if (i == 0x13) {
        goto done;
    }
    if (data_021759c0->mUnk_08 == 5) {
        e = &data_0217bc48[i];
        n = e->mUnk_0c;
        v = n * func_020fa0e8(e->mUnk_08, 0);
        if (func_020fab34_inline(i) != FALSE && data_0217aa14->mUnk_724 >= v) {
            return FALSE;
        }
    } else {
        if (func_020fab34_inline(i) != FALSE) {
            return FALSE;
        }
    }
done:
    *param_1 = data_021759c0->mUnk_08 == 5 ? 4 : 2;
    return TRUE;
}

BOOL func_020faa78(s32 param_1) {
    Unk0217bc48 *e;
    s32 n;
    Unk027e00cc *r;
    enum { K0 } k;

    e = &data_0217bc48[param_1];
    k = e->mUnk_08;
    r = &data_027e00cc[k];
    n = e->mUnk_0c;
    while (r->mUnk_0c - r->mUnk_1c < n) {
        if (data_0217bc34[k].mUnk_04 == 1) {
            return FALSE;
        }
        if (func_020f03bc(r) == 0) {
            return FALSE;
        }
    }
    return TRUE;
}

void func_020fa9e4(void) {
    enum { K0 } i;
    u16 j;

    for (i = 0; i < 0xe; i++) {
        func_020f03bc(&data_027e00cc[i]);
    }
    for (j = 0; j < data_027e00c4; j++) {
        func_020f0044(&(data_027e00c8)[j]);
    }
}

void func_020fa920(void) {
    enum { K0 } i;
    u16 j;

    if (data_021759c0->mUnk_08 == 5) {
        func_020fec30();
        func_020feb44();
    }
    for (i = 0; i < 0xe; i++) {
        if (data_027e00cc[i].mUnk_14 != 0) {
            func_020f03f8(&data_027e00cc[i]);
        }
    }
    for (j = 0; j < data_027e00c4; j++) {
        func_01fff694(&(data_027e00c8)[j]);
    }
    func_020f8258();
    func_02104368();
    func_02104ff8();
}

void func_020fa8ac(void *a) {
    enum { K0 } i;
    void *q;

    q = &((Unk020e6b38 *) func_020e6b38())->mUnk_18;
    func_020e6a74();
    for (i = 0; i < 0xe; i++) {
        if (data_027e00cc[i].mUnk_10 > 0 && data_027e00cc[i].mUnk_40 == 0) {
            func_020f0df8(&data_027e00cc[i], q);
        }
    }
}

void func_020fa78c(s32 param_1, s32 param_2, s32 param_3) {
    s32 v;
    BOOL c;

    if ((data_027e00c8)[param_1].mUnk_030.mUnk_00 != 0x13) {
        return;
    }
    v = data_021759c0->mUnk_68[param_1].mUnk_08.mUnk_00;
    if (v == 3) {
        return;
    }
    if (data_021759c0->mUnk_08 == 2) {
        c = FALSE;
        if ((u32) v > 3) {
        } else if ((1 << v) & 0xd) {
            c = TRUE;
        }
        func_020f87a8(&(data_027e00c8)[param_1], param_2, func_020a1cd8(param_1), c ? 1 : 0, param_3);
    } else {
        c = FALSE;
        if ((u32) v > 3) {
        } else if ((1 << v) & 0xd) {
            c = TRUE;
        }
        func_020f87a8(&(data_027e00c8)[param_1], param_2, func_0203c8dc(param_1), c ? 1 : 0, param_3);
    }
}

static inline s32 func_020fa4c8_inline(Unk020f41c4_A *e, Unk0206bcb0 *a) {
    Vec3 b;
    Vec3 c;
    s32 d1;
    s32 d2;
    s32 r;
    s32 x;
    s64 f;

    if (!(e->mUnk_74 & 0x8000)) {
        return 1;
    }
    if ((u16) a->mIndex != (u16) (!(e->mUnk_78 & 0x8000) ? (u16) (e->mUnk_78 & ~0xff00) : 8)) {
        return 1;
    }
    if (e->mUnk_5c.x != 0 || e->mUnk_5c.y != 0 || e->mUnk_5c.z != 0 || a->mUnk_2a8 != 0) {
        Vec3Sub(&e->mUnk_0e4, &a->mUnk_1e4, &b);
        b.y = 0;
        Vec3Sub(&e->mUnk_50, &a->mUnk_1d8, &c);
        c.y = 0;
        d1 = func_02039828(&b, &b);
        d2 = func_02039828(&c, &c);
        if (d1 - 0x1000 > d2) {
            return 1;
        }
    }
    r = e->mUnk_e0;
    x = e->mUnk_50.x - a->mUnk_1d8.x;
    f = (s64) (e->mUnk_50.z - a->mUnk_1d8.z) * (e->mUnk_50.z - a->mUnk_1d8.z) +
        ((s64) x * x + (s64) (e->mUnk_50.y - a->mUnk_1d8.y) * (e->mUnk_50.y - a->mUnk_1d8.y));
    return f < (s64) r * r ? 1 : 0;
}

s32 func_020fa4c8(Unk0206bcb0 *param_1) {
    s32 i;
    s32 n;
    BOOL fl;
    s32 v;
    s32 lim;
    Unk020f41c4_A *e;
    enum { K0 } k;

    n = 0;
    fl = (param_1->mUnk_48 & 0x8000000) != 0;
    lim = 0xf;
    for (i = 0; i < data_0217b5a8; i++) {
        if (!(data_0217b5bc[i] & 0x4000)) {
            continue;
        }
        e = data_0217b5c4[i];
        if (fl && !(e->mUnk_74 & 0x200000)) {
            continue;
        }
        if (!func_020f97e0(e, param_1)) {
            continue;
        }
        v = func_020fa4c8_inline(e, param_1);
        if (v == 0) {
            continue;
        }
        if ((param_1->mUnk_7c & 0x2000) && func_020f9880(e) != 0) {
            continue;
        }
        data_0217bd30[n++] = e;
        if (e->mUnk_74 & 0x1000) {
            func_020eda5c(&(data_027e00c8)[(u16) (e->mUnk_78 & ~0xff00)].mUnk_058, e);
        }
        k = e->mUnk_44;
        if (data_0217bc34[k].mUnk_88 != 0) {
            if (func_020f9880(e) != 0) {
                func_020f6be8(e, &param_1->mUnk_1b8, &param_1->mUnk_a4, &param_1->mUnk_05c);
                func_020f6f10(e, 1, (u16) param_1->mIndex);
            } else {
                func_020f7430(e, 1);
            }
        }
        if (n >= 0x10) {
            n = lim;
        }
    }
    return n;
}

#pragma thumb on
