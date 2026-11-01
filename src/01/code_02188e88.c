#include "01/code_02188e88.h"
#include "01/code_02187000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020c0000.h"
#include "code_02147cd8.h"

#pragma thumb off

s32 func_ov001_02189290(void) {
    return func_020c0c2c(&data_ov001_021a9ba8, 0x1f6);
}

void func_ov001_0218927c(void) {
    func_020c0b84(&data_ov001_021a9ba8);
}

void func_ov001_02189160(void) {
    s32 i;
    s32 n = 0;
    u32 v = func_020c0db0();
    Unk0217b498_00 *el;
    Vec3 *pos;

    for (i = 0; i < data_ov001_021a9ba8->mUnk_08; i++) {
        el = data_ov001_021a9ba8->mUnk_00[i];
        if (!(el->mUnk_02 & 1)) {
            pos = &el->mUnk_04;
            if (func_020b5ae8(pos, &data_ov001_021a9ba8->mUnk_10[n].mUnk_00, v, 1, 1) != 0) {
                data_ov001_021a9ba8->mUnk_10[n].mUnk_08 = func_020b83dc(0xc5);
                data_ov001_021a9ba8->mUnk_10[n].mUnk_0c = func_020b4e70(pos) ? 2 : 3;
                data_ov001_021a9ba8->mUnk_10[n].mUnk_0e = el->mUnk_02 & 0x20;
                data_ov001_021a9ba8->mUnk_10[n].mUnk_10 = el->mUnk_7e;
                n++;
            }
        }
    }
    data_ov001_021a9ba8->mUnk_04 = n;
}

void func_ov001_02189144(void *param_1) {
    func_020c092c(param_1, data_ov001_021a9ba8, 0);
}

s32 func_ov001_02189128(void) {
    return func_020c0c2c(&data_ov001_021a9ba4, 0x1fd);
}

void func_ov001_02189114(void) {
    func_020c0b84(&data_ov001_021a9ba4);
}

void func_ov001_02188ff8(void) {
    s32 i;
    s32 n = 0;
    u32 v = func_020c0db0();
    Unk0217b498_00 *el;
    Vec3 *pos;

    for (i = 0; i < data_ov001_021a9ba4->mUnk_08; i++) {
        el = data_ov001_021a9ba4->mUnk_00[i];
        if (!(el->mUnk_02 & 1)) {
            pos = &el->mUnk_04;
            if (func_020b5ae8(pos, &data_ov001_021a9ba4->mUnk_10[n].mUnk_00, v, 1, 1) != 0) {
                data_ov001_021a9ba4->mUnk_10[n].mUnk_08 = func_020b83dc(0xc5);
                data_ov001_021a9ba4->mUnk_10[n].mUnk_0c = func_020b4e70(pos) ? 2 : 3;
                data_ov001_021a9ba4->mUnk_10[n].mUnk_0e = el->mUnk_02 & 0x20;
                data_ov001_021a9ba4->mUnk_10[n].mUnk_10 = el->mUnk_7e;
                n++;
            }
        }
    }
    data_ov001_021a9ba4->mUnk_04 = n;
}

void func_ov001_02188fdc(void *param_1) {
    func_020c092c(param_1, data_ov001_021a9ba4, 0);
}

#pragma thumb on

u32 func_ov001_02188f04(Unk02188950 *param_1, Vec3 *param_2, s32 param_3) {
    Vec3 local;
    s32 dx;
    s32 dz;
    float f1;
    float f2;

    if (param_2 != 0) {
        func_021484d0(param_2, &param_1->mUnk_000.mUnk_04, &local);
        dx = param_1->mUnk_000.mUnk_04.x - param_2->x;
        dz = param_1->mUnk_000.mUnk_04.z - param_2->z;
        if (param_3 > 0) {
            f1 = 0.5f + (float) (param_3 << 12);
        } else {
            f1 = (float) (param_3 << 12) - 0.5f;
        }
        if (param_3 > 0) {
            f2 = 0.5f + (float) (param_3 << 12);
        } else {
            f2 = (float) (param_3 << 12) - 0.5f;
        }
        if ((s64) dx * dx + (s64) dz * dz < (s64) (s32) f2 * (s32) f1) {
            return 1;
        }
        return 0;
    }
    return 0;
}

u32 func_ov001_02188eac(Unk02188950 *param_1, s32 param_2, Vec3 *param_3, s32 param_4) {
    s32 v;

    if (param_3 != 0) {
        v = (u16) (func_02148714(param_3->x - param_1->mUnk_000.mUnk_04.x, param_3->z - param_1->mUnk_000.mUnk_04.z) -
                   param_2);
        if (v > 0x8000) {
            v -= 0x10000;
        }
        if (-param_4 <= v && v <= param_4) {
            return 1;
        }
        return 0;
    }
    return 0;
}

void func_ov001_02188e94(Unk02188950 *param_1, void (**param_2)()) {
    void (*fn)() = *param_2;

    *param_2 = 0;
    if (fn != 0) {
        fn(param_1, param_2, 0);
    }
}

void func_ov001_02188e88(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 0, (s32(*)(Unk02188950 *))(0));
}
