#include "01/code_021830b4.h"

#include "Main/Unknown/code_0209bef0.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_0210b000.h"

void func_ov001_021841e0(Unk02188950 *param_1) {
    Vec3 sp = {0, 0, 0};

    sp.y = param_1->mUnk_0a0->mUnk_238;
    func_ov001_02187218(param_1, 8, func_ov001_02184274);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_224, param_1->mUnk_0a0->mUnk_228);
    func_ov001_02188950(param_1, &sp);
    func_ov001_02188c90(param_1);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_230, param_1->mUnk_0a0->mUnk_234);
    func_ov001_02188db8(param_1, func_ov001_021842ec);
    param_1->mUnk_000.mUnk_02 |= data_ov001_021a6578;
}

void func_ov001_02184160(int param_1) {
    u32 v1;
    func_ov001_02187218((Unk02188950 *) param_1, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x210)),
                        (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x214)));
    v1 = *(u32 *) (*(int *) (param_1 + 0xa0) + 0x21c);
    func_ov001_02188c48((Unk02188950 *) param_1, (s32) v1, (s32) v1);
    func_ov001_02188998((Unk02188950 *) param_1, (Vec3 *) ((u32 *) (u32) (*(u32 *) (param_1 + 0x9c))));
    v1 = *(u32 *) (*(int *) (param_1 + 0xa0) + 0x218);
    func_ov001_02188cd8((Unk02188950 *) param_1, (s32) v1, (s32) v1);
    func_ov001_02188e24((Unk02188950 *) (param_1), (s32) ((u32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x220))),
                        (UnkFunc *) ((int) &func_ov001_021841e0));
}

void func_ov001_02183ff4(Unk02188950 *param_1) {
    Vec3 sp;
    s32 scale;

    sp.x = param_1->mUnk_000.mUnk_04.x;
    sp.y = 0;
    sp.z = param_1->mUnk_000.mUnk_04.z;
    if ((s64) sp.z * sp.z + ((s64) sp.x * sp.x + (s64) sp.y * sp.y) >= 16) {
        func_02039860(&sp, &sp);
    }
    scale = param_1->mUnk_0a0->mUnk_204;
    sp.x = (s64) sp.x * scale >> 12;
    sp.y = (s64) sp.y * scale >> 12;
    sp.z = (s64) sp.z * scale >> 12;
    sp.y = -param_1->mUnk_0a0->mUnk_208;
    func_ov001_02187218(param_1, 8, 0);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_1fc, param_1->mUnk_0a0->mUnk_200);
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
    func_ov001_02188950(param_1, &sp);
    func_ov001_0218720c(param_1);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_20c, func_ov001_02184160);
    func_ov001_021874c4(param_1, 0, 0, 0, 0x423, 0);
    func_ov001_021874c4(param_1, 0, 0, 0, 0x425, 0);
    func_ov001_02187444(param_1, 4, 0);
    func_020d2774(&param_1->mUnk_000, (u32) (0x244));
    param_1->mUnk_000.mUnk_02 |= data_ov001_021a6578;
}

void func_ov001_02183f0c(Unk02188950 *param_1) {
    Vec3 sp8 = {0, 0, 0};

    func_ov001_02187218(param_1, 8, 0);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_070, param_1->mUnk_0a0->mUnk_074);
    func_ov001_02188950(param_1, &sp8);
    func_ov001_0218720c(param_1);
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
    if (param_1->mUnk_000.mUnk_00 == 0x1f5) {
        func_ov001_021874c4(param_1, 0, 0, 0, 0x423, 0);
        func_ov001_021874c4(param_1, 0, 0, 0, 0x425, 0);
    } else if (param_1->mUnk_000.mUnk_00 == 0x1f6) {
        func_ov001_021874c4(param_1, 0, 0, 0, 0x423, 0);
        func_ov001_021874c4(param_1, 0, 0, 0, 0x425, 0);
    }
    {
        Unk021a78d8 sp14 = {0x212, 0, 0xc, 0};

        sp14.mUnk_04 = &param_1->mUnk_000.mUnk_04;
        sp14.mUnk_0c = func_020d4ef4(&param_1->mUnk_000.mUnk_04);
        func_0210b734(&sp14, func_02108e7c());
    }
    param_1->mUnk_000.mUnk_02 |= data_ov001_021a6578;
}

void func_ov001_02183ed4(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 5, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(param_1, (s32) (param_1->mUnk_0a0->mUnk_160), (s32) (param_1->mUnk_0a0->mUnk_164),
                        (UnkFunc *) 0);
    func_ov001_02188cec(param_1, 0);
}

u32 func_ov001_02183ebc(Unk02188950 *param_1) {
    func_020d275c(&param_1->mUnk_000, (u32) (((u32) 0x00000243u)));
    return 0;
}

void func_ov001_02183e40(Unk02188950 *param_1) {
    Vec3 sp = {0, 0, 0};

    sp.y = param_1->mUnk_0a0->mUnk_154;
    func_ov001_02187218(param_1, 5, (s32(*)(Unk02188950 *)) func_ov001_02183ebc);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_14c, param_1->mUnk_0a0->mUnk_150);
    func_ov001_02188a8c(param_1, param_1->mUnk_0a0->mUnk_158, param_1->mUnk_0a0->mUnk_158);
    func_ov001_02188950(param_1, &sp);
    func_ov001_02188db8(param_1, func_ov001_02183ed4);
}

void func_ov001_02183dec(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 5, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(param_1, (s32) (param_1->mUnk_0a0->mUnk_12c), (s32) (param_1->mUnk_0a0->mUnk_130),
                        (UnkFunc *) 0);
    func_ov001_02188e24(param_1, (s32) ((u32) (param_1->mUnk_0a0->mUnk_134)), (UnkFunc *) ((int) &func_ov001_02183e40));
    func_ov001_02188cec(param_1, 0);
}

s32 func_ov001_02183d94(Unk02188950 *param_1) {
    func_ov001_02188998(param_1, &func_0207a974((u16) data_021759c0->mUnk_62)->mUnk_80);
    if (param_1->mUnk_174 < param_1->mUnk_0a0->mUnk_108) {
        func_ov001_02188200(param_1, func_ov001_02184874);
        func_ov001_02184e6c(param_1);
    }
    return 0;
}

void func_ov001_02183cc8(Unk02188950 *param_1) {
    Unk0206bcb0 *r4;

    r4 = func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(param_1, 2, func_ov001_02183d94);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_10c, param_1->mUnk_0a0->mUnk_110);
    func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_118, param_1->mUnk_0a0->mUnk_118);
    func_ov001_02188998(param_1, &r4->mUnk_80);
    func_ov001_021889c8(param_1);
    func_ov001_02188cd8(param_1, 0, param_1->mUnk_0a0->mUnk_114);
    func_ov001_02188dcc(param_1, func_ov001_02184cc8);
    func_ov001_02188200(param_1, func_ov001_021843b0);
    if (param_1->mUnk_174 < param_1->mUnk_0a0->mUnk_114) {
        func_ov001_02188200(param_1, func_ov001_02184874);
    }
    func_ov001_02184e18((u16 *) param_1);
}

void func_ov001_02183c54(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 2, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_0f4), (s32) (param_1->mUnk_0a0->mUnk_0f8));
    func_ov001_02188c90(param_1);
    func_ov001_02188cd8(param_1, (s32) (param_1->mUnk_0a0->mUnk_0fc), (s32) (param_1->mUnk_0a0->mUnk_100));
    func_ov001_02188e24(param_1, (s32) ((u32) (param_1->mUnk_0a0->mUnk_104)), (UnkFunc *) ((int) &func_ov001_02183cc8));
    func_ov001_02188200(param_1, func_ov001_021843b0);
    func_ov001_02184e18((u16 *) param_1);
}

void func_ov001_02183c08(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 2, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_0e8), (s32) (param_1->mUnk_0a0->mUnk_0ec));
    func_ov001_02188c90(param_1);
    func_ov001_02188e24(param_1, (s32) ((u32) (param_1->mUnk_0a0->mUnk_0f0)), (UnkFunc *) ((int) &func_ov001_02183c54));
    func_ov001_02184e6c(param_1);
}

void func_ov001_02183b9c(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 2, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_080), (s32) (param_1->mUnk_0a0->mUnk_084));
    func_ov001_02188c90(param_1);
    func_ov001_02188cd8(param_1, (s32) (param_1->mUnk_0a0->mUnk_088), (s32) (param_1->mUnk_0a0->mUnk_08c));
    func_ov001_02188e24(param_1, (s32) ((u32) (param_1->mUnk_0a0->mUnk_090)), (UnkFunc *) ((int) &func_ov001_02183cc8));
    func_ov001_02188200(param_1, func_ov001_021843b0);
    func_ov001_02184e18((u16 *) param_1);
}

void func_ov001_02183ad8(Unk02188950 *param_1) {
    Unk0206bcb0 *r4;

    r4 = func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(param_1, 3, 0);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_0cc, param_1->mUnk_0a0->mUnk_0d0);
    func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_0d8, param_1->mUnk_0a0->mUnk_0d8);
    func_ov001_02188998(param_1, &r4->mUnk_80);
    func_ov001_02188cec(param_1, param_1->mUnk_0a0->mUnk_0d4);
    func_ov001_02188de0(param_1, 0, param_1->mUnk_0a0->mUnk_0e4, &r4->mUnk_80, func_ov001_02183c08);
    if (param_1->mUnk_000.mUnk_00 == 0x1f5) {
        func_020d2774(&param_1->mUnk_000, (u32) (0x214));
    } else if (param_1->mUnk_000.mUnk_00 == 0x1f6) {
        func_020d2774(&param_1->mUnk_000, (u32) (0x245));
    }
    func_ov001_02184e6c(param_1);
}

void func_ov001_021839ac(Unk02188950 *param_1) {
    if (func_ov001_021881a8(param_1, (Vec3 *) param_1->mUnk_000.mUnk_9c, (s32) (param_1->mUnk_0a0->mUnk_180 + 0x28),
                            0)) {
        func_ov001_02187218(param_1, 3, 0);
        func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_168, param_1->mUnk_0a0->mUnk_16c);
        func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_178, 0x270f000);
        func_ov001_02188998(param_1, &param_1->mUnk_000.mUnk_9c->mUnk_00);
        func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_174, param_1->mUnk_0a0->mUnk_170);
        func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_17c, 0);
        func_ov001_02188200(param_1, func_ov001_02184874);
    } else {
        func_ov001_02187218(param_1, 3, 0);
        func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_168, param_1->mUnk_0a0->mUnk_16c << 2);
        func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_178, 0x270f000);
        func_ov001_02188998(param_1, &param_1->mUnk_000.mUnk_9c->mUnk_00);
        func_ov001_02188cd8(param_1, -param_1->mUnk_0a0->mUnk_174, param_1->mUnk_0a0->mUnk_170);
        func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_17c, 0);
        func_ov001_02188200(param_1, func_ov001_02184874);
    }
    func_ov001_02184e6c(param_1);
}

void func_ov001_02183894(Unk02188950 *param_1) {
    Unk02188950_a0 *a0;

    a0 = param_1->mUnk_0a0;
    if (func_ov001_021881a8(param_1, (Vec3 *) func_ov001_02187fc0(param_1), (s32) (a0->mUnk_0ac),
                            (s32) (a0->mUnk_0b0))) {
        func_ov001_02187218(param_1, 1, 0);
        func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_0b8, param_1->mUnk_0a0->mUnk_0bc);
        func_ov001_02188b2c(param_1, param_1->mUnk_0a0->mUnk_0c4, param_1->mUnk_0a0->mUnk_0c4, 0);
        func_ov001_02188998(param_1, &func_ov001_02187fc0(param_1)->mUnk_00);
        func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_0c0, param_1->mUnk_0a0->mUnk_0c0);
        func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_0c8, 0);
    } else {
        func_ov001_02187e78(param_1);
        func_ov001_02187218(param_1, 1, 0);
        func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_09c, param_1->mUnk_0a0->mUnk_0a0);
        func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_0a8, param_1->mUnk_0a0->mUnk_0a8);
        func_ov001_02188998(param_1, &func_ov001_02187fc0(param_1)->mUnk_00);
        func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_0a4, param_1->mUnk_0a0->mUnk_0a4);
        a0 = param_1->mUnk_0a0;
        func_ov001_02188de0(param_1, a0->mUnk_0ac, a0->mUnk_0b0, &func_ov001_02187fc0(param_1)->mUnk_00, 0);
    }
    func_ov001_02184e6c(param_1);
}

void func_ov001_02183880(Unk02188950 *param_1) {
    func_ov001_02183ff4(param_1);
    func_ov001_02188260(param_1);
    return;
}

void func_ov001_02183850(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_078), (s32) (param_1->mUnk_0a0->mUnk_07c));
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
    return;
}

void func_ov001_02183848(void) {
    func_ov001_021882b8();
}

int func_ov001_02183780(Unk02188950 *param_1) {
    if (param_1->mUnk_000.mUnk_00 == 0x1f6) {
        if (func_0209b620((int) param_1->mUnk_304) == 2 || func_0209b620((int) param_1->mUnk_304) == 3) {
            func_ov001_02187af4(param_1);
            func_ov001_021872e0(param_1, 0x1000, 0, 0, 0, 0x666, -0x1000, 0x428, 0);
            func_ov001_021872e0(param_1, 0x1000, 0, 0, 0, 0x666, -0x1000, 0x429, 0);
            func_ov001_021872e0(param_1, 0x1000, 0, 0, 0, 0x800, -0x1000, 0x42a, 0);
            func_020d2774(&param_1->mUnk_000, (u32) (0x240));
        }
    }
    if (func_02061fec() == 1) {
        func_ov001_02183b9c(param_1);
    }
    return 0;
}

int func_ov001_02183690(Unk02188950 *param_1) {
    if (param_1->mUnk_000.mUnk_00 == 0x1f6) {
        if (func_0209b620((int) param_1->mUnk_304) == 2) {
            func_ov001_02187af4(param_1);
            func_ov001_021872e0(param_1, 0x1000, 0, 0, 0, 0x666, -0x1000, 0x428, 0);
            func_ov001_021872e0(param_1, 0x1000, 0, 0, 0, 0x666, -0x1000, 0x429, 0);
            func_ov001_021872e0(param_1, 0x1000, 0, 0, 0, 0x800, -0x1000, 0x42a, 0);
            func_020d2774(&param_1->mUnk_000, (u32) (0x240));
        }
    } else if (param_1->mUnk_000.mUnk_00 == 0x1f5) {
        if (func_0209b620((int) param_1->mUnk_304) == 0x2b || func_0209b620((int) param_1->mUnk_304) == 0x48) {
            func_ov001_02187af4(param_1);
            func_ov001_02187518(param_1, 0, 0, 0, 0x410, 0);
        }
    }
    return 0;
}

u32 func_ov001_021835e0(Unk02188950 *param_1) {
    int v1;
    if ((param_1->mUnk_000.mUnk_00 == ((u32) 0x000001f6u)) &&
        (v1 = func_0209b620((int) (*(u32 *) ((int) param_1 + 0x304))), v1 == 2)) {
        func_ov001_02187af4(param_1);
        func_ov001_021872e0(param_1, (int) (((u32) 0x00001000u)), 0, 0, 0, (int) ((u16) (((u32) 0x00000666u))),
                            (int) (((u32) 0xfffff000u)), (int) (((u32) 0x00000428u)), (u32) 0);
        func_ov001_021872e0(param_1, (int) (((u32) 0x00001000u)), 0, 0, 0, (int) ((u16) (((u32) 0x00000666u))),
                            (int) (((u32) 0xfffff000u)), (int) (((u32) 0x00000429u)), (u32) 0);
        func_ov001_021872e0(param_1, (int) (((u32) 0x00001000u)), 0, 0, 0, (int) ((u16) (((u32) 0x00000800u))),
                            (int) (((u32) 0xfffff000u)), (int) (((u32) 0x0000042au)), (u32) 0);
        func_020d2774(&param_1->mUnk_000, (u32) (((u32) 0x00000240u)));
    }
    return 0;
}

void func_ov001_021835b8(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8, (s32(*)(Unk02188950 *))((int) &func_ov001_02183780));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 100)),
                        (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x68)));
}

void func_ov001_0218355c(u16 *param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8, (s32(*)(Unk02188950 *))((int) &func_ov001_02183690));
    if (*param_1 == ((u32) 0x000001f6u)) {
        func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0x50) + 0x58)),
                            (s32) (*(u32 *) (*(int *) (param_1 + 0x50) + 0x5c)));
        func_ov001_02188e24((Unk02188950 *) param_1, (s32) ((u32) (*(u32 *) (*(int *) (param_1 + 0x50) + 0x60))),
                            (UnkFunc *) ((int) &func_ov001_021835b8));
        return;
    }
    func_ov001_02188d30((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0x50) + 0x58)),
                        (s32) (*(u32 *) (*(int *) (param_1 + 0x50) + 0x5c)), (UnkFunc *) &func_ov001_021835b8);
}

void func_ov001_02183524(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8, (s32(*)(Unk02188950 *))((int) &func_ov001_021835e0));
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_04c), (s32) (param_1->mUnk_0a0->mUnk_050));
    func_ov001_02188e24(param_1, (s32) ((u32) (param_1->mUnk_0a0->mUnk_054)), (UnkFunc *) ((int) &func_ov001_0218355c));
}

void func_ov001_021834fc(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8, (s32(*)(Unk02188950 *))((int) &func_ov001_021835e0));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x40)),
                        (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x44)));
}

void func_ov001_021834c4(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8, (s32(*)(Unk02188950 *))((int) &func_ov001_021835e0));
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_034), (s32) (param_1->mUnk_0a0->mUnk_038));
    func_ov001_02188e24(param_1, (s32) ((u32) (param_1->mUnk_0a0->mUnk_03c)), (UnkFunc *) ((int) &func_ov001_021834fc));
}

void func_ov001_02183450(Unk0218fa78 *param_1) {
    s32 i;
    Unk02188950 *o;

    if (param_1 != 0) {
        for (i = 0; i < param_1->mUnk_04 && (o = param_1->mUnk_00[i]) != 0; i++) {
            func_ov001_02187eb0(o);
            o->mUnk_000.mUnk_9c->mUnk_00.x = 0;
            o->mUnk_000.mUnk_9c->mUnk_00.z = 0;
            if (func_02062ec4() != 0) {
                func_ov001_021834c4(o);
            } else {
                func_ov001_02183524(o);
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
                            func_ov001_02183dec(param_2);
                        }
                    }
                }
            }
        }
        if (func_ov001_021871f8(param_2, 3) != 0) {
            if (func_ov001_021881a8(param_2, (Vec3 *) param_2->mUnk_000.mUnk_9c, (s32) (param_2->mUnk_0a0->mUnk_180),
                                    0) == 0) {
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
            func_ov001_021870e4(param_1, o, (const char *) data_ov001_021a79a8, (const char *) data_ov001_021a79bc,
                                (const char *) data_ov001_021a79d0);
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
            func_ov001_021870e4(param_1, o, (const char *) data_ov001_021a7950, (const char *) data_ov001_021a7968,
                                (const char *) data_ov001_021a7980);
            func_ov001_021870b0(param_1, o, (const char *) data_ov001_021a7998);
            func_ov001_0218875c(o, (s32) (o->mUnk_0a0->mUnk_008), (s32) (o->mUnk_0a0->mUnk_00c), 0);
            func_ov001_021888a4(o, 0, 0x21000);
            func_ov001_02188200(o, func_ov001_02184874);
        }
    }
}

void func_ov001_02183138(u32 param_1, u32 param_2) {
    func_ov001_02186368((void *) param_1, (Unk02188950 *) param_2);
    func_ov001_021861f4((void *) param_1, (Unk02188950 *) param_2, 0);
}

void func_ov001_02183104(void) {
    u32 v4 = 0x23eu;
    void *v8 = &func_ov001_02185fb0;
    void *v9 = &func_ov001_02185f04;
    void *v10 = &func_ov001_021860cc;
    u32 v12 = (u32) func_ov001_0219b510(v8, v9, v10, (u32) 0x2u, (u16) ((u32) 0x1u), (u16) (v4), (u16) ((u32) 0x0u));
}

void *func_ov001_021830e8(void) {
    return (void *) func_0209bf1c(func_ov001_021831f0, func_ov001_02183138, func_ov001_02187098);
}

void *func_ov001_021830cc(void) {
    return (void *) func_0209bf1c(func_ov001_02183158, func_ov001_02183138, func_ov001_02187098);
}

void *func_ov001_021830b4(void) {
    return (void *) func_0209bf48(func_ov001_02183450, func_ov001_021832cc, 0);
}
