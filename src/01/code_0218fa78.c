#include "01/code_0218fa78.h"
#include "01/code_02181b54.h"
#include "01/code_02187098.h"
#include "01/code_021864ac.h"
#include "01/code_02188158.h"
#include "01/code_02188218.h"
#include "01/code_0219b250.h"
#include "01/code_0218fef8.h"
#include "01/code_02190df8.h"
#include "01/code_021900ac.h"
#include "01/code_021921e4.h"
#include "01/code_021927c0.h"
#include "01/code_02190090.h"
#include "01/code_02190080.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/code_020a2300.h"
#include "Main/Unknown/code_02062eb0.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b502c.h"
#include "01/code_02190000.h"
#include "01/code_02191000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_020a128c.h"

void func_ov001_0218fee0(Unk02188950 *param_1) {
    param_1->mUnk_2e0 = 2;
    func_ov001_021881f4(param_1, (UnkFunc *) func_ov001_0218fee0);
}

void func_ov001_0218fd20(Unk02188950 *param_1, Unk0218fd20 *param_2) {
    int diff;
    int limit;
    Vec3 vec;

    diff = (u16) (func_02148714(param_2->mUnk_50.x - param_1->mUnk_000.mUnk_04.x,
                                param_2->mUnk_50.z - param_1->mUnk_000.mUnk_04.z) -
                  param_1->mUnk_184);
    if (diff > 0x8000) {
        diff -= 0x10000;
    }
    limit = param_1->mUnk_0a0->mUnk_088;
    if (diff <= limit && diff >= -limit && func_ov001_021871f8(param_1, 7)) {
        vec.x = (s32) (((s64) -param_1->mUnk_0a0->mUnk_224 * data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2]) >> 12);
        vec.y = param_1->mUnk_0a0->mUnk_228;
        vec.z =
            (s32) (((s64) -param_1->mUnk_0a0->mUnk_224 * data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2 + 1]) >> 12);
        func_ov001_02188950((data_021759c0->mUnk_08 == 4
                                 ? func_ov001_02181b68((u16) (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0))
                                 : 0),
                            &vec);
        func_ov001_02188950(
            (data_021759c0->mUnk_08 == 4
                 ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1))
                 : 0),
            &vec);
        func_0208b7bc(0x3eb, &param_2->mUnk_50);
        func_0208b7bc(0x3ec, &param_2->mUnk_50);
        func_0208b7bc(0x3ed, &param_2->mUnk_50);
        param_1->mUnk_000.mUnk_78 |= data_ov001_021a65c4;
        func_ov001_0219006c(
            data_021759c0->mUnk_08 == 4
                ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 2))
                : 0);
        func_ov001_021881f4(param_1, (UnkFunc *) func_ov001_0218fee0);
        param_1->mUnk_2e0 = 2;
    } else {
        param_1->mUnk_2e0 = 2;
        func_ov001_021881f4(param_1, (UnkFunc *) func_ov001_0218fd20);
    }
}

void func_ov001_0218fcc4(Unk0218fa78 *param_1) {
    int i;
    Unk02188950 *obj;
    int zero;

    if (param_1 != 0) {
        zero = 0;
        for (i = 0; i < param_1->mUnk_04 && (obj = param_1->mUnk_00[i]) != 0; i++) {
            func_ov001_021870e4((void *) zero, obj, (const char *) zero, (const char *) zero,
                                (const char *) data_ov001_021a7eb0);
            if (data_021759c0->mUnk_08 == 4) {
                func_ov001_02181b8c(obj);
            }
            func_ov001_02190080(obj);
        }
    }
}

void func_ov001_0218fc4c(u32 param_1, Unk02188950 *param_2) {
    if ((data_021759c0->mUnk_08 == 4 ? func_020a126c() : 0) == 0 && func_ov001_021871f8(param_2, 1)) {
        if (func_ov001_02188220(
                (data_021759c0->mUnk_08 == 4
                     ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 2))
                     : 0)) < 2) {
            func_ov001_02190468(param_2);
        } else {
            func_ov001_0219081c(param_2);
        }
    }
    func_ov001_021864ac(param_1, param_2);
}

void func_ov001_0218fbe0(Unk0218fa78 *param_1) {
    int i;
    Unk02188950 *obj;

    if (param_1 != 0) {
        for (i = 0; i < param_1->mUnk_04 && (obj = param_1->mUnk_00[i]) != 0; i++) {
            if (func_02062ec4()) {
                obj->mUnk_000.mUnk_04.y += obj->mUnk_0a0->mUnk_080;
                func_ov001_0218fef8(obj);
            } else {
                func_ov001_0218ff64(obj);
            }
            func_ov001_0219246c(obj);
            func_ov001_02188200(obj, func_ov001_02192878);
        }
    }
    func_020a2314((void (*)(void)) func_ov001_02190df0);
}

void func_ov001_0218fb24(u32 param_1, Unk02188950 *param_2) {
    s32 value;

    if ((data_021759c0->mUnk_08 == 4 ? func_020a128c() : 0) && func_ov001_021871f8(param_2, 3)) {
        if (data_021759c0->mUnk_08 == 4 ? func_020a1084((u16) data_021759c0->mUnk_62) : 0) {
            func_ov001_02190df8(param_2);
        } else {
            func_ov001_02190eb0(param_2);
        }
    }
    if (param_2->mUnk_0a8 == 1) {
        value = param_2->mUnk_134 + 1;
        if (value >= func_0209b634(param_2->mUnk_304) - 1) {
            value = func_0209b634(param_2->mUnk_304) - 1;
        }
        param_2->mUnk_134 = value;
    } else {
        value = param_2->mUnk_134 - 1;
        if (value <= 0) {
            value = 0;
        }
        param_2->mUnk_134 = value;
    }
    func_0209b688((void *) (param_2->mUnk_304), (u16) param_2->mUnk_134);
    func_ov001_021864ac(param_1, param_2);
}

void func_ov001_0218fa78(Unk0218fa78 *param_1) {
    int i;
    Unk02188950 *obj;

    if (param_1 != 0) {
        for (i = 0; i < param_1->mUnk_04 && (obj = param_1->mUnk_00[i]) != 0; i++) {
            if (data_021759c0->mUnk_08 == 4) {
                func_ov001_02181b8c(obj);
            }
            func_ov001_021870e4(param_1, obj, (const char *) data_ov001_021a7e60, (const char *) data_ov001_021a7e70,
                                (const char *) data_ov001_021a7e80);
            func_ov001_021870b0(param_1, obj, (const char *) data_ov001_021a7e90);
            func_ov001_0219b2e8(obj->mUnk_304, data_ov001_021a7ea0);
            obj->mUnk_234 = 1;
            if (i == 0) {
                obj->mUnk_000.mUnk_02 |= data_ov001_021a65c0;
            } else if (i == 1) {
                obj->mUnk_000.mUnk_02 &= 0xfffffbff;
            }
        }
    }
}
