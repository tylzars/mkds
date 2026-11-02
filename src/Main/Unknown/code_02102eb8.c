#include "Main/Unknown/code_02102eb8.h"

#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020f8000.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02102674.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_020f8e3c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_02074854.h"

void func_021031ac(Unk02102674 *p) {
    s32 i;

    p->mUnk_12c = 0;
    for (i = 0; i < 8; i++) {
        p->mUnk_130[i] = 0;
    }
    p->mUnk_138 = -1;
    p->mUnk_000.mUnk_d8 = 0x1f;
    p->mUnk_19c = 0;
    p->mUnk_160 = 0;
}

s32 func_0210300c(Unk02102674 *p) {
    Unk0215a3b0 *e;
    s32 i;
    s32 f;

    p->mUnk_138 = p->mUnk_138 + 1;
    if (p->mUnk_138 >= 0x11) {
        goto done;
    }
    e = &data_0215a3b0[p->mUnk_138];
    p->mUnk_154 = e->mUnk_00;
    p->mUnk_158 = e->mUnk_02;
    p->mUnk_164 = e->mUnk_04;
    p->mUnk_168 = e->mUnk_06;
    p->mUnk_16c = e->mUnk_08;
    p->mUnk_170 = e->mUnk_0a;
    i = p->mUnk_138;
    if (i != 0xc && i != 0xd) {
        if (p->mUnk_158 > 0) {
            p->mUnk_174 = 0xe66;
            p->mUnk_178 = 0x1266;
            p->mUnk_184.z = 0x4cd;
        } else if (i == 4) {
            p->mUnk_174 = 0x1000;
            p->mUnk_178 = 0x1000;
            p->mUnk_184.z = 0x1000;
        } else {
            p->mUnk_174 = 0x1333;
            p->mUnk_178 = 0xc29;
            p->mUnk_184.z = 0x28f;
        }
    } else if (i == 0xc) {
        p->mUnk_174 = 0x199a;
        p->mUnk_178 = 0x119a;
        p->mUnk_184.z = 0x800;
    } else {
        p->mUnk_174 = 0x800;
        p->mUnk_178 = 0x800;
        p->mUnk_184.z = 0x99a;
    }
    i = p->mUnk_138;
    f = 1;
    if (i != 2 && i != 0x10) {
        f = 0;
    }
    p->mUnk_194 = f;
    if (e->mUnk_02 > 0 && p->mUnk_138 != 0 && p->mUnk_138 != 0xe && p->mUnk_198 != 0) {
        func_020f8e3c((u32) p->mUnk_12c, 0xf1);
    }
    return 0;
done:
    return 1;
}

u32 func_02102eb8(Unk02102674 *p, s32 param_1) {
    Unk020748a8 *s;
    s32 a;
    s32 b2;

    a = data_021759c0->mUnk_62;
    s = func_020748a8();
    func_020f82a4(0);
    if (a < 0) {
        b2 = (u16) (p->mUnk_000.mUnk_78 & ~0xff00);
    } else {
        b2 = a;
    }
    p->mUnk_12c = func_0207a974(b2);
    p->mUnk_000.mUnk_50 = p->mUnk_12c->mUnk_98;
    func_02147fd8(0x5800, &s->mUnk_00, &p->mUnk_000.mUnk_50, &p->mUnk_000.mUnk_50);
    func_02147fd8(func_0203c5e4() != 0 ? 0x5800 : 0xa800, &s->mUnk_15c, &p->mUnk_000.mUnk_50, &p->mUnk_000.mUnk_50);
    func_021484d0(&p->mUnk_000.mUnk_50, &s->mUnk_24, &p->mUnk_13c);
    func_02146d78(&p->mUnk_13c, s->mUnk_030, &p->mUnk_13c);
    if (param_1 != 0) {
        if (p->mUnk_000.mUnk_74 & 0x10000000) {
            func_0210300c(p);
            p->mUnk_16c = p->mUnk_16c - 1;
        }
    } else {
        func_0210300c(p);
    }
    p->mUnk_148 = p->mUnk_154;
    p->mUnk_14c = p->mUnk_158;
    p->mUnk_180 = p->mUnk_174;
    p->mUnk_184.x = p->mUnk_178;
    if ((p->mUnk_000.mUnk_78 & 0x8000) == 0) {
        b2 = (u16) (p->mUnk_000.mUnk_78 & ~0xff00);
    } else {
        b2 = 8;
    }
    p->mUnk_198 = a == (u16) b2;
    func_020f9c40((int) p);
    return (u32) func_0208adc8(&p->mUnk_000.mUnk_7c, 1);
}
