#include "01/code_0218c0a4.h"
#include "01/code_02185ef4.h"
#include "01/code_02187000.h"
#include "01/code_02188000.h"
#include "01/code_02188218.h"
#include "01/code_02188e24.h"
#include "01/code_0218c5fc.h"
#include "01/code_0219b1c4.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/code_02187d14.h"
#include "01/code_0218c000.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/unk_0217c000.h"

void func_ov001_0218c490(Unk02188950 *param_1) {
    Unk0206bcb0 *p = func_0207a974((u16) data_021759c0->mUnk_62);

    func_ov001_02187218(param_1, 2, func_ov001_0218c5d4);
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_104), (s32) (param_1->mUnk_0a0->mUnk_108));
    func_ov001_0219b1c4(param_1->mUnk_304, param_1->mUnk_0a0->mUnk_10c, param_1->mUnk_0a0->mUnk_108, 0);
    func_ov001_02188cd8(param_1, (s32) (param_1->mUnk_0a0->mUnk_110), (s32) (param_1->mUnk_0a0->mUnk_114));
    func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_118, param_1->mUnk_0a0->mUnk_11c);
    func_ov001_02188998(param_1, &p->mUnk_80);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_12c, 0);
    func_ov001_0218c5fc(param_1);
}

void func_ov001_0218c3ac(Unk02188950 *param_1) {
    if (func_ov001_02188220(param_1) == 0) {
        func_ov001_02188cd8(param_1, (s32) (param_1->mUnk_0a0->mUnk_0a4), (s32) (param_1->mUnk_0a0->mUnk_0a8));
        func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_0ac, param_1->mUnk_0a0->mUnk_0b0);
    } else if (func_ov001_02188220(param_1) == 1) {
        func_ov001_02188cd8(param_1, (s32) (param_1->mUnk_0a0->mUnk_0bc), (s32) (param_1->mUnk_0a0->mUnk_0c0));
        func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_0c4, param_1->mUnk_0a0->mUnk_0c8);
    } else {
        func_ov001_02188cd8(param_1, (s32) (param_1->mUnk_0a0->mUnk_0cc), (s32) (param_1->mUnk_0a0->mUnk_0d0));
        func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_0d4, param_1->mUnk_0a0->mUnk_0d8);
    }
    func_ov001_02188998(param_1, (Vec3 *) func_ov001_02187fc0(param_1));
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_0b8, 0);
    func_ov001_02188de0(param_1, (s32) (param_1->mUnk_0a0->mUnk_0b4), 0, (Vec3 *) func_ov001_02187fc0(param_1),
                        (UnkFunc *) (0));
}

void func_ov001_0218c354(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 1, func_ov001_0218c5ac);
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_098), (s32) (param_1->mUnk_0a0->mUnk_09c));
    func_ov001_0219b1c4(param_1->mUnk_304, param_1->mUnk_0a0->mUnk_0a0, param_1->mUnk_0a0->mUnk_09c, 0);
    func_ov001_0218c3ac(param_1);
    func_ov001_0218c5fc(param_1);
}

void func_ov001_0218c0a4(Unk02188950 *param_1) {
    Unk02188950_a0 *a0;
    Unk020f41c4_B *r;
    u32 n1;
    u32 n2;
    u32 m1;
    u32 m2;
    u32 t1;
    u32 t2;
    u16 res1;
    u16 res2;
    s32 sel;
    s32 angle;
    s32 radius;
    s32 i;

    a0 = param_1->mUnk_0a0;
    angle = param_1->mUnk_184 - a0->mUnk_1a4 * (param_1->mUnk_138 / 2);
    n1 = a0->mUnk_1a8;
    if (n1 == 0x10000) {
        r = func_020d22d0();
        r->mUnk_00 = r->mUnk_10 + (s64) r->mUnk_08 * (s64) r->mUnk_00;
        res1 = (r->mUnk_00 >> 32) * 0x10000 >> 32;
    } else {
        r = func_020d22d0();
        if ((u16) n1 == 0) {
            t1 = 0;
        } else {
            r->mUnk_00 = r->mUnk_10 + (s64) r->mUnk_08 * (s64) r->mUnk_00;
            m1 = (u16) n1;
            if (m1 == 0) {
                t1 = r->mUnk_00 >> 32;
            } else {
                t1 = ((s64) (r->mUnk_00 >> 32) * m1) >> 32;
            }
        }
        res1 = t1;
    }
    if (res1 == 0) {
        n2 = param_1->mUnk_138;
        if (n2 == 0x10000) {
            r = func_020d22d0();
            r->mUnk_00 = r->mUnk_10 + (s64) r->mUnk_08 * (s64) r->mUnk_00;
            res2 = (r->mUnk_00 >> 32) * 0x10000 >> 32;
        } else {
            r = func_020d22d0();
            if ((u16) n2 == 0) {
                t2 = 0;
            } else {
                r->mUnk_00 = r->mUnk_10 + (s64) r->mUnk_08 * (s64) r->mUnk_00;
                m2 = (u16) n2;
                if (m2 == 0) {
                    t2 = r->mUnk_00 >> 32;
                } else {
                    t2 = ((s64) (r->mUnk_00 >> 32) * m2) >> 32;
                }
            }
            res2 = t2;
        }
        sel = res2;
    } else {
        sel = -1;
    }
    radius = param_1->mUnk_0a0->mUnk_198;
    for (i = 0; i < param_1->mUnk_138; i++) {
        Vec3 pos;
        Vec3 vel = {0, 0, 0};

        pos.x = param_1->mUnk_000.mUnk_04.x + (((s64) radius * data_0215d4b4[((u16) angle >> 4) * 2]) >> 12);
        pos.y = param_1->mUnk_000.mUnk_04.y + param_1->mUnk_0a0->mUnk_194;
        pos.z = param_1->mUnk_000.mUnk_04.z + (((s64) radius * data_0215d4b4[((u16) angle >> 4) * 2 + 1]) >> 12);
        vel.x = ((s64) param_1->mUnk_0a0->mUnk_1a0 * data_0215d4b4[((u16) angle >> 4) * 2]) >> 12;
        vel.y = param_1->mUnk_0a0->mUnk_19c;
        vel.z = ((s64) param_1->mUnk_0a0->mUnk_1a0 * data_0215d4b4[((u16) angle >> 4) * 2 + 1]) >> 12;
        if (i == sel) {
            func_ov001_02187b2c(func_020f4ee8(), &pos, &vel, param_1->mUnk_0a0->mUnk_1ac);
        } else {
            func_ov001_02187b94(func_ov001_02187dd4(), &pos, &vel, param_1->mUnk_0a0->mUnk_1b0);
        }
        angle += param_1->mUnk_0a0->mUnk_1a4;
        func_0208b7bc(0x3f7, &pos);
        func_0208b7bc(0x3f6, &pos);
    }
    func_020d2774(&param_1->mUnk_000, (u32) (0x222));
}
