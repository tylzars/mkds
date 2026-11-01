#include "01/code_0218edc8.h"

#include "01/code_02181820.h"
#include "01/code_02182000.h"
#include "01/code_02187000.h"
#include "01/code_02188000.h"
#include "01/code_02188158.h"
#include "01/code_02188950.h"
#include "01/code_02188e24.h"
#include "01/code_0218e000.h"
#include "01/code_0218f000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217d000.h"

void func_ov001_0218f57c(Unk02188950 *param_1) {
    Unk0206bcb0 *p;

    p = func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(param_1, 5, func_ov001_0218f634);
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_1fc), (s32) (param_1->mUnk_0a0->mUnk_200));
    func_ov001_02188cd8(param_1, (s32) (param_1->mUnk_0a0->mUnk_204), (s32) (param_1->mUnk_0a0->mUnk_208));
    func_ov001_02188bc4(param_1, param_1->mUnk_0a0->mUnk_20c, param_1->mUnk_0a0->mUnk_210);
    func_ov001_02188998(param_1, &p->mUnk_80);
    func_ov001_021889c8(param_1);
    func_ov001_02188e24(param_1, (s32) (param_1->mUnk_0a0->mUnk_214), (UnkFunc *) (0));
    func_ov001_02188200(param_1, (UnkFunc *) func_ov001_0218f9a8);
}

void func_ov001_0218f51c(Unk02188950 *param_1) {
    func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(param_1, 5, func_ov001_0218f634);
    func_ov001_02188d30(param_1, (s32) (param_1->mUnk_0a0->mUnk_1f4), (s32) (param_1->mUnk_0a0->mUnk_1f8),
                        (UnkFunc *) (func_ov001_0218f57c));
    func_ov001_02188200(param_1, (UnkFunc *) func_ov001_0218f9a8);
    func_ov001_021828f0();
}

void func_ov001_0218f454(Unk02188950 *param_1) {
    Unk0206bcb0 *p;

    p = func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(param_1, 5, func_ov001_0218f634);
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_1d8), (s32) (param_1->mUnk_0a0->mUnk_1dc));
    func_ov001_02188cd8(param_1, (s32) (param_1->mUnk_0a0->mUnk_1e0), (s32) (param_1->mUnk_0a0->mUnk_1e4));
    func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_1e8, param_1->mUnk_0a0->mUnk_1ec);
    func_ov001_02188998(param_1, &p->mUnk_80);
    func_ov001_021889c8(param_1);
    func_ov001_02188e24(param_1, (s32) (param_1->mUnk_0a0->mUnk_1f0), (UnkFunc *) func_ov001_0218f51c);
    func_ov001_02188200(param_1, (UnkFunc *) func_ov001_0218f9a8);
    func_020d2774(&param_1->mUnk_000, (u32) (0x229));
}

s32 func_ov001_0218f3ec(Unk02188950 *param_1) {
    Unk0206bcb0 *p;
    Vec3 v;

    p = func_0207a974((u16) data_021759c0->mUnk_62);
    if ((p->mUnk_48 & 0x200) == 0) {
        func_02147fd8(param_1->mUnk_0a0->mUnk_21c, &p->mUnk_68, &p->mUnk_80, &v);
        func_ov001_02188998(param_1, &v);
        func_ov001_02188d8c(param_1, (Vec3 *) (&v));
    }
    func_ov001_0218f6d8(param_1);
    func_02061860();
    return 0;
}

s32 func_ov001_0218f3ac(Unk02188950 *param_1) {
    Unk0206bcb0 *p;

    p = func_0207a974((u16) data_021759c0->mUnk_62);
    if ((p->mUnk_48 & 0x200) == 0) {
        func_ov001_02188998(param_1, &p->mUnk_80);
    }
    func_ov001_0218f6d8(param_1);
    return 0;
}

void func_ov001_0218f2a8(Unk02188950 *param_1) {
    Unk0206bcb0 *p;
    Vec3 v;

    p = func_0207a974((u16) data_021759c0->mUnk_62);
    func_02147fd8(param_1->mUnk_0a0->mUnk_21c, &p->mUnk_68, &p->mUnk_80, &v);
    func_ov001_02187218(param_1, 5, func_ov001_0218f3ac);
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_0ec), (s32) (param_1->mUnk_0a0->mUnk_0f0));
    func_ov001_02188d1c(param_1, (s32) (param_1->mUnk_0a0->mUnk_0f4), (s32) (param_1->mUnk_0a0->mUnk_0f8));
    func_ov001_02188cd8(param_1, (s32) (param_1->mUnk_0a0->mUnk_0fc), (s32) (param_1->mUnk_0a0->mUnk_100));
    func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_104, param_1->mUnk_0a0->mUnk_108);
    func_ov001_02188de0(param_1, (s32) (param_1->mUnk_0a0->mUnk_218), 0, (Vec3 *) (&v),
                        (UnkFunc *) (func_ov001_0218f454));
    if (data_0217d20c != 2) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 2;
    func_ov001_02188200(param_1, (UnkFunc *) func_ov001_0218e298);
    param_1->mUnk_000.mUnk_02 |= data_ov001_021a65b0;
}

s32 func_ov001_0218f244(Unk02188950 *param_1) {
    Unk0206bcb0 *p;
    Vec3 v;

    p = func_0207a974((u16) data_021759c0->mUnk_62);
    if ((p->mUnk_48 & 0x200) == 0) {
        func_02147fd8(-param_1->mUnk_0a0->mUnk_0e8, &p->mUnk_68, &p->mUnk_80, &v);
        func_ov001_02188998(param_1, &v);
        func_ov001_02188d8c(param_1, (Vec3 *) (&v));
    }
    func_ov001_0218f6d8(param_1);
    return 0;
}

void func_ov001_0218f16c(Unk02188950 *param_1) {
    Unk0206bcb0 *p;
    Vec3 v;

    p = func_0207a974((u16) data_021759c0->mUnk_62);
    func_02147fd8(-param_1->mUnk_0a0->mUnk_0e8, &p->mUnk_68, &p->mUnk_80, &v);
    func_ov001_02187218(param_1, 3, func_ov001_0218f244);
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_0c4), (s32) (param_1->mUnk_0a0->mUnk_0c8));
    func_ov001_02188d1c(param_1, (s32) (param_1->mUnk_0a0->mUnk_0cc), (s32) (param_1->mUnk_0a0->mUnk_0d0));
    func_ov001_02188cd8(param_1, (s32) (param_1->mUnk_0a0->mUnk_0d4), (s32) (param_1->mUnk_0a0->mUnk_0d8));
    func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_0dc, param_1->mUnk_0a0->mUnk_0e0);
    func_ov001_02188de0(param_1, (s32) (param_1->mUnk_0a0->mUnk_0e4), 0, (Vec3 *) (&v),
                        (UnkFunc *) (func_ov001_0218f2a8));
    if (data_0217d20c != 1) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 1;
}

s32 func_ov001_0218efc4(Unk02188950 *param_1) {
    Unk0206bcb0 *p;
    float f;

    p = func_0207a974((u16) data_021759c0->mUnk_62);
    if ((p->mUnk_48 & 0x200) == 0) {
        func_ov001_02188998(param_1, &p->mUnk_80);
        func_ov001_02188d8c(param_1, (Vec3 *) (&p->mUnk_80));
    }
    func_ov001_0218f724(param_1);
    if (func_ov001_02188104(param_1, (s32) (param_1->mUnk_0a0->mUnk_0b8), 0) == 0) {
        param_1->mUnk_1c4 = param_1->mUnk_0a0->mUnk_0c0;
    } else {
        param_1->mUnk_1c4 = 0;
    }
    param_1->mUnk_170 = param_1->mUnk_0a0->mUnk_09c;
    if (param_1->mUnk_0a0->mUnk_1cc - (data_021759c0->mUnk_08 == 4 ? (s32) func_ov001_02181838() : 0) > 0) {
        f = 0.5f +
            (float) ((param_1->mUnk_0a0->mUnk_1cc - (data_021759c0->mUnk_08 == 4 ? (s32) func_ov001_02181838() : 0))
                     << 12);
    } else {
        f = (float) ((param_1->mUnk_0a0->mUnk_1cc - (data_021759c0->mUnk_08 == 4 ? (s32) func_ov001_02181838() : 0))
                     << 12) -
            0.5f;
    }
    param_1->mUnk_16c = (s32) f / param_1->mUnk_0a0->mUnk_1d4;
    if ((data_021759c0->mUnk_08 == 4 ? (s32) func_ov001_02181838() : 0) <= param_1->mUnk_0a0->mUnk_1d0 &&
        func_ov001_02188000(param_1, 0, (s32) (param_1->mUnk_0a0->mUnk_0bc)) != 0) {
        func_ov001_02188200(param_1, (UnkFunc *) func_ov001_0218f9a8);
        param_1->mUnk_000.mUnk_02 |= data_ov001_021a65b0;
        func_ov001_0218f16c(param_1);
    } else if ((data_021759c0->mUnk_08 == 4 ? (s32) func_ov001_02181838() : 0) > param_1->mUnk_0a0->mUnk_1cc) {
        func_ov001_02188e88(param_1);
    }
    return 0;
}

void func_ov001_0218ef30(Unk02188950 *param_1) {
    func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(param_1, 3, func_ov001_0218efc4);
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_090), (s32) (param_1->mUnk_0a0->mUnk_094));
    func_ov001_02188cec(param_1, (s32) (param_1->mUnk_0a0->mUnk_0a0));
    func_ov001_02188adc(param_1, param_1->mUnk_0a0->mUnk_0b0, 0x270f000, param_1->mUnk_0a0->mUnk_0a8, 0x270f000, 0);
    if (data_0217d20c != 0) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 0;
}

void func_ov001_0218ee88(Unk02188950 *param_1) {
    Unk0206bcb0 *p;
    Vec3 v;

    p = func_0207a974((u16) data_021759c0->mUnk_62);
    func_02147fd8(-param_1->mUnk_0a0->mUnk_0e8, &p->mUnk_68, &p->mUnk_80, &v);
    param_1->mUnk_000.mUnk_04.x = v.x;
    param_1->mUnk_000.mUnk_04.y = param_1->mUnk_000.mUnk_9c->mUnk_00.y + param_1->mUnk_0a0->mUnk_080;
    param_1->mUnk_000.mUnk_04.z = v.z;
    param_1->mUnk_1a8 =
        (u16) (func_02148714(p->mUnk_80.x - param_1->mUnk_000.mUnk_04.x, p->mUnk_80.z - param_1->mUnk_000.mUnk_04.z) +
               0x4000);
    param_1->mUnk_184 = param_1->mUnk_1a8;
    func_ov001_0218ef30(param_1);
    func_ov001_02182a3c(0);
    param_1->mUnk_000.mUnk_02 &= ~1;
}

void func_ov001_0218edc8(Unk02188950 *param_1) {
    Unk0206bcb0 *p;

    p = func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(param_1, 3, func_ov001_0218f634);
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_144), (s32) (param_1->mUnk_0a0->mUnk_148));
    func_ov001_02188d1c(param_1, (s32) (param_1->mUnk_0a0->mUnk_14c), (s32) (param_1->mUnk_0a0->mUnk_150));
    func_ov001_02188cd8(param_1, (s32) (param_1->mUnk_0a0->mUnk_154), (s32) (param_1->mUnk_0a0->mUnk_158));
    func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_15c, param_1->mUnk_0a0->mUnk_160);
    func_ov001_02188998(param_1, &p->mUnk_80);
    func_ov001_02188e24(param_1, (s32) (param_1->mUnk_0a0->mUnk_164), (UnkFunc *) (0));
}
