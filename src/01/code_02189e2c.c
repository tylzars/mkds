#include "01/code_02189e2c.h"
#include "01/code_0218a41c.h"
#include "01/code_0218a2d4.h"
#include "01/code_02181b54.h"
#include "01/code_02187098.h"
#include "01/code_02187c4c.h"
#include "01/code_02188218.h"
#include "01/code_021864ac.h"
#include "01/code_0218a19c.h"
#include "01/code_0218a2dc.h"
#include "01/code_0218a3ec.h"
#include "01/code_0218a568.h"
#include "01/code_02188158.h"
#include "01/code_02188484.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_02062eb0.h"
#include "Main/Unknown/code_020a2300.h"
#include "01/code_02187000.h"
#include "01/code_0218a000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_020fd000.h"

void func_ov001_0218a120(Unk0218d87c *param_1) {
    int i;
    Unk02188950 *obj;

    if (param_1 != 0) {
        for (i = 0; i < param_1->mUnk_04 && (obj = param_1->mUnk_00[i]) != 0; i++) {
            Vec3 v = {0, 0, 0};
            v.x = obj->mUnk_0a0->mUnk_0fc;
            v.y = obj->mUnk_0a0->mUnk_100;
            func_ov001_02187c88(obj, 5, (const Vec3 *) (&v));
            if (func_02062ec4() != 0) {
                func_ov001_0218a19c(obj);
            } else {
                func_ov001_0218a20c(obj);
            }
        }
    }
    func_020a2314((void (*)(void)) func_ov001_0218a2d4);
}

void func_ov001_0218a074(u32 param_1, Unk02188950 *param_2) {
    int active;

    if (data_021759c0->mUnk_08 == 4) {
        active = func_020a126c();
    } else {
        active = 0;
    }
    if (active != 0) {
        if (func_ov001_021871f8(param_2, 1) != 0) {
            if (data_021759c0->mUnk_08 == 4) {
                active = func_020a1084((u16) data_021759c0->mUnk_62);
            } else {
                active = 0;
            }
            if (active != 0) {
                func_ov001_0218a3ec(param_2);
            } else {
                func_ov001_0218a2dc(param_2);
            }
        }
    } else {
        if (func_ov001_021871f8(param_2, 3) != 0) {
            if (func_ov001_02188220(param_2) >= 2) {
                func_ov001_0218ab04(param_2);
            }
        }
        if (func_ov001_021871f8(param_2, 3) != 0) {
            func_ov001_0218a75c(param_2);
        }
        if (func_ov001_021871f8(param_2, 2) != 0) {
            func_ov001_0218a60c(param_2);
        }
    }
    func_ov001_021864ac(param_1, param_2);
}

void func_ov001_0218a034(Unk02188950 *param_1) {
    func_020ac588((u32) (0xc9), 0xa, (void *) param_1);
    param_1->mUnk_000.mUnk_94 = func_02036bec((void *) func_020364e0(func_020364e8()), 0x44);
    func_02109110((Unk0210bfbc *) (param_1->mUnk_000.mUnk_94), (u32) (0xc), (Vec3 *) (&param_1->mUnk_000.mUnk_04));
    param_1->mUnk_000.mUnk_70 = data_0217cbec[0x50 / 4];
}

void func_ov001_0218a028(Unk0206c1ac *param_1) {
    param_1->mUnk_6c = 0x2000;
}

void func_ov001_02189fe0(Unk02188950 *param_1, Unk0206bcb0 *param_2) {
    if (param_2->mUnk_44 == 9) {
        if (func_020fd528(param_2) == 0) {
            func_0208b748(0x3a, &param_2->mUnk_50, 0, func_ov001_0218a028);
        }
    }
    param_1->mUnk_2e0 = 1;
    func_ov001_021881f4(param_1, (UnkFunc *) func_ov001_02189fe0);
}

void func_ov001_02189ed8(Unk02188950 *param_1, Unk0206bcb0 *param_2) {
    Vec3 v;
    s64 scale;

    if (func_ov001_02187c4c((int) param_1) != 0) {
        func_ov001_02187bfc(param_1, (Vec3 *) (0), 0);
    }
    param_1->mUnk_2e0 = 2;
    func_ov001_021881f4(param_1, (UnkFunc *) func_ov001_02189ed8);
    if (func_ov001_021871f8(param_1, 7) != 0) {
        v.x = param_1->mUnk_000.mUnk_04.x - param_2->mUnk_50.x;
        v.y = 0;
        v.z = param_1->mUnk_000.mUnk_04.z - param_2->mUnk_50.z;
        if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 0x10) {
            func_02039860(&v, &v);
        }
        scale = param_1->mUnk_0a0->mUnk_16c;
        v.x = (s64) v.x * scale >> 12;
        v.y = (s64) v.y * scale >> 12;
        v.z = (s64) v.z * scale >> 12;
        v.y = param_1->mUnk_0a0->mUnk_170;
        func_ov001_02188950(param_1, &v);
        func_ov001_0218a41c(param_1);
    }
}
void func_ov001_02189e2c(Unk0218d87c *param_1) {
    Unk02188950 *obj;
    Unk02188950_a0 *a0;
    int i;

    if (param_1 != 0) {
        for (i = 0; i < param_1->mUnk_04 && (obj = param_1->mUnk_00[i]) != 0; i++) {
            if (data_021759c0->mUnk_08 == 4) {
                func_ov001_02181b8c(obj);
            }
            func_ov001_021870e4(param_1, obj, (const char *) data_ov001_021a7b14, (const char *) data_ov001_021a7b24,
                                (const char *) data_ov001_021a7b34);
            func_ov001_021870b0(param_1, obj, (const char *) data_ov001_021a7b44);
            a0 = obj->mUnk_0a0;
            func_ov001_0218875c(obj, (s32) (a0->mUnk_008), (s32) (a0->mUnk_00c), (s32) (a0->mUnk_20c));
            func_ov001_021888a4(obj, 0, 0x23000);
            func_ov001_021881f4(obj, (UnkFunc *) func_ov001_02189ed8);
        }
    }
}
