#include "01/code_02183158.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_0210b000.h"

void func_ov001_02183450(Unk0218fa78 *param_1) {
    s32 i;
    Unk02188950 *o;

    if (param_1 != 0) {
        for (i = 0; i < param_1->mUnk_04 && (o = param_1->mUnk_00[i]) != 0; i++) {
            func_ov001_02187eb0(o);
            o->mUnk_000.mUnk_9c->mUnk_00.x = 0;
            o->mUnk_000.mUnk_9c->mUnk_00.z = 0;
            if (func_02062ec4() != 0) {
                func_ov001_021834c4((int) o);
            } else {
                func_ov001_02183524((int) o);
            }
            func_ov001_02188da4(o, func_ov001_02183b9c);
        }
    }
    func_020a2314((void (*)(void)) func_ov001_02183848);
}

void func_ov001_021832cc(u32 param_1, Unk02188950 *param_2) {
    Unk02188950_a0 *a;
    Unk0206bcb0 *c;

    if (data_021759c0->mUnk_08 == 4 ? func_020a126c() : 0) {
        if (func_ov001_021871f8(param_2, 1) != 0) {
            if (data_021759c0->mUnk_08 == 4 ? func_020a1084((u16) data_021759c0->mUnk_62) : 0) {
                func_ov001_02183850(param_2);
            } else {
                func_ov001_02183f0c(param_2);
            }
        }
    } else {
        if (func_ov001_021871f8(param_2, 8) != 0) {
            if (func_ov001_021871d0(param_2) != 0) {
                func_ov001_02183880(param_2);
            }
        }
        if (func_ov001_021871f8(param_2, 5) != 0) {
            a = param_2->mUnk_0a0;
            if (func_ov001_02188220(param_2) >= a->mUnk_148) {
                a = param_2->mUnk_0a0;
                if (func_ov001_02188104(param_2, a->mUnk_138, a->mUnk_13c) != 0) {
                    a = param_2->mUnk_0a0;
                    c = func_ov001_02188000(param_2, a->mUnk_140, a->mUnk_144);
                    if (c != 0) {
                        if ((func_0207a974(c->mUnk_74)->mUnk_48 & 0x100000) != 0 && c->mUnk_238 > 0) {
                            func_ov001_02183dec((int) param_2);
                        }
                    }
                }
            }
        }
        if (func_ov001_021871f8(param_2, 3) != 0) {
            if (func_ov001_021881a8(param_2, (Vec3 *) param_2->mUnk_000.mUnk_9c,
                                    (s32) (param_2->mUnk_0a0->mUnk_180), 0) == 0) {
                func_ov001_021839ac(param_2);
            }
        }
        if (func_ov001_021871f8(param_2, 2) != 0) {
            a = param_2->mUnk_0a0;
            if (func_ov001_02188104(param_2, a->mUnk_0dc, a->mUnk_0e0) != 0) {
                func_ov001_02183ad8(param_2);
            }
        }
        if (func_ov001_021871f8(param_2, 1) != 0) {
            func_ov001_02183894(param_2);
        }
    }
    func_ov001_021864ac(param_1, param_2);
}

void func_ov001_02183294(Unk02188950 *param_1) {
    param_1->mUnk_000.mUnk_94 = func_02036bec((void *) func_020364e0(func_020364e8()), 0x44);
    func_02109110((Unk0210bfbc *) (param_1->mUnk_000.mUnk_94), (u32) (0xc), (Vec3 *) (&param_1->mUnk_000.mUnk_04));
    param_1->mUnk_000.mUnk_70 = data_0217cbec[20];
}

void func_ov001_021831f0(Unk0218fa78 *param_1) {
    Unk02188950 *o;
    s32 i;

    if (param_1 != 0) {
        for (i = 0; i < param_1->mUnk_04 && (o = param_1->mUnk_00[i]) != 0; i++) {
            if (data_021759c0->mUnk_08 == 4) {
                func_ov001_02181b8c(o);
            }
            func_ov001_021870e4(param_1, o, (const char *) data_ov001_021a79a8, (const char *) data_ov001_021a79bc, (const char *) data_ov001_021a79d0);
            func_ov001_021870b0(param_1, o, (const char *) data_ov001_021a79e4);
            func_ov001_0218875c(o, (s32) (o->mUnk_0a0->mUnk_008), (s32) (o->mUnk_0a0->mUnk_00c), 0);
            func_ov001_021888a4(o, 0, 0x11000);
            func_ov001_02188200(o, func_ov001_02184874);
            o->mUnk_2b8 = 2;
        }
    }
}

void func_ov001_02183158(Unk0218fa78 *param_1) {
    Unk02188950 *o;
    s32 i;

    if (param_1 != 0) {
        for (i = 0; i < param_1->mUnk_04 && (o = param_1->mUnk_00[i]) != 0; i++) {
            if (data_021759c0->mUnk_08 == 4) {
                func_ov001_02181b8c(o);
            }
            func_ov001_021870e4(param_1, o, (const char *) data_ov001_021a7950, (const char *) data_ov001_021a7968, (const char *) data_ov001_021a7980);
            func_ov001_021870b0(param_1, o, (const char *) data_ov001_021a7998);
            func_ov001_0218875c(o, (s32) (o->mUnk_0a0->mUnk_008), (s32) (o->mUnk_0a0->mUnk_00c), 0);
            func_ov001_021888a4(o, 0, 0x21000);
            func_ov001_02188200(o, func_ov001_02184874);
        }
    }
}
