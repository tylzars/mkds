#include "01/code_0218b35c.h"
#include "01/code_0218b298.h"
#include "01/code_0218b310.h"
#include "01/unk_021a6000.h"
#include "01/code_02188000.h"
#include "01/code_0218c000.h"
#include "Main/Unknown/code_020d4000.h"
#include "01/code_02187af4.h"
#include "01/code_02187d14.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "01/code_02188158.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02109000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020f9c6c.h"

Unk021a7b64 data_ov001_021a7b64 = {
    0, 0x30c, func_ov001_0218b72c, func_ov001_0218b310, func_ov001_0218b2f4, 0, 0, func_ov001_0218b2dc, {0, 0, 0, 0, 0},
};

typedef struct Unk0218b928_local {
    s32 mUnk_00;
    Vec3 *mUnk_04;
    s32 mUnk_08;
    u32 mUnk_0c;
} Unk0218b928_local;

void func_ov001_0218bee4(Unk02188950 *param_1) {
    Unk0206bcb0 *unk;

    unk = func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(param_1, 2, (s32(*)(Unk02188950 *)) func_ov001_0218c55c);
    func_ov001_02188d30(param_1, (s32) (param_1->mUnk_0a0->mUnk_184), (s32) (param_1->mUnk_0a0->mUnk_188),
                        (UnkFunc *) func_ov001_0218bfc8);
    func_ov001_0219b1c4(param_1->mUnk_304, (s32) (param_1->mUnk_0a0->mUnk_18c), (s32) (param_1->mUnk_0a0->mUnk_188), 0);
    func_ov001_02188cd8(param_1, 0, (s32) (param_1->mUnk_0a0->mUnk_144));
    func_ov001_02188a30(param_1, 0, param_1->mUnk_0a0->mUnk_154, param_1->mUnk_0a0->mUnk_148,
                        param_1->mUnk_0a0->mUnk_14c);
    func_ov001_02188968(param_1, &unk->mUnk_80);
    func_ov001_02188980(param_1, (Vec3 *) func_ov001_02187fc0(param_1));
    func_ov001_02188e74(param_1, (s32) ((u32) (param_1->mUnk_0a0->mUnk_190)), (UnkFunc *) ((u32) func_ov001_0218c0a4));
}

void func_ov001_0218bde8(Unk02188950 *param_1) {
    Unk0206bcb0 *unk;

    unk = func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(param_1, 2, (s32(*)(Unk02188950 *)) func_ov001_0218c55c);
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_134), (s32) (param_1->mUnk_0a0->mUnk_138));
    func_ov001_0219b1c4(param_1->mUnk_304, (s32) (param_1->mUnk_0a0->mUnk_13c), (s32) (param_1->mUnk_0a0->mUnk_138), 0);
    func_ov001_02188cd8(param_1, (s32) (param_1->mUnk_0a0->mUnk_140), (s32) (param_1->mUnk_0a0->mUnk_144));
    func_ov001_02188a30(param_1, param_1->mUnk_0a0->mUnk_150, param_1->mUnk_0a0->mUnk_154, param_1->mUnk_0a0->mUnk_148,
                        param_1->mUnk_0a0->mUnk_14c);
    func_ov001_02188968(param_1, &unk->mUnk_80);
    func_ov001_02188980(param_1, (Vec3 *) func_ov001_02187fc0(param_1));
    func_ov001_02188e24(param_1, (s32) ((u32) (param_1->mUnk_0a0->mUnk_158)), (UnkFunc *) func_ov001_0218bee4);
    param_1->mUnk_138 = func_ov001_02187f7c(param_1);
    func_ov001_0218c5fc((Unk02188950 *) ((u32) param_1));
}

void func_ov001_0218bd80(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 7, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(param_1, (s32) (param_1->mUnk_0a0->mUnk_1f8), (s32) (param_1->mUnk_0a0->mUnk_1fc),
                        (UnkFunc *) 0);
    func_ov001_0219b1c4(param_1->mUnk_304, (s32) (param_1->mUnk_0a0->mUnk_200), (s32) (param_1->mUnk_0a0->mUnk_1fc), 0);
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
    param_1->mUnk_000.mUnk_02 &= ~0x20;
}

void func_ov001_0218bcc4(Unk02188950 *param_1) {
    Vec3 local = {0, 0, 0};

    local.y = param_1->mUnk_0a0->mUnk_1f4;
    func_ov001_02187218(param_1, 7, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_1e0), (s32) (param_1->mUnk_0a0->mUnk_1e4));
    func_ov001_0219b1c4(param_1->mUnk_304, (s32) (param_1->mUnk_0a0->mUnk_1e8), (s32) (param_1->mUnk_0a0->mUnk_1e4), 0);
    func_ov001_02188950(param_1, &local);
    func_ov001_02188c90(param_1);
    func_ov001_02188cd8(param_1, (s32) (param_1->mUnk_0a0->mUnk_1ec), (s32) (param_1->mUnk_0a0->mUnk_1f0));
    func_ov001_02188db8(param_1, (UnkFunc *) func_ov001_0218bd80);
    func_020d2774(&param_1->mUnk_000, (u32) 0x226);
    param_1->mUnk_000.mUnk_02 |= data_ov001_021a65a8;
}

void func_ov001_0218bc60(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 7, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(param_1, (s32) (param_1->mUnk_0a0->mUnk_1d4), (s32) (param_1->mUnk_0a0->mUnk_1d8),
                        (UnkFunc *) func_ov001_0218bcc4);
    func_ov001_0219b1c4(param_1->mUnk_304, (s32) (param_1->mUnk_0a0->mUnk_1dc), (s32) (param_1->mUnk_0a0->mUnk_1d8), 0);
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
}

void func_ov001_0218bbac(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 7, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_1b4), (s32) (param_1->mUnk_0a0->mUnk_1b8));
    func_ov001_0219b1c4(param_1->mUnk_304, (s32) (param_1->mUnk_0a0->mUnk_1bc), (s32) (param_1->mUnk_0a0->mUnk_1b8), 0);
    func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_1c8, param_1->mUnk_0a0->mUnk_1cc);
    func_ov001_02188998(param_1, &param_1->mUnk_000.mUnk_9c->mUnk_00);
    func_ov001_02188cd8(param_1, (s32) (param_1->mUnk_0a0->mUnk_1c0), (s32) (param_1->mUnk_0a0->mUnk_1c4));
    func_ov001_02188e24(param_1, (s32) ((u32) (param_1->mUnk_0a0->mUnk_1d0)), (UnkFunc *) func_ov001_0218bc60);
    func_ov001_0218c5fc((Unk02188950 *) ((u32) param_1));
}

int func_ov001_0218bb74(Unk02188950 *param_1) {
    if (func_ov001_02188220(param_1) == 1) {
        func_020d275c(&param_1->mUnk_000, (u32) 0x220);
    } else if (func_ov001_02188220(param_1) == 2) {
        func_020d275c(&param_1->mUnk_000, (u32) 0x221);
    }
    return 0;
}

void func_ov001_0218ba48(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8, func_ov001_0218bb74);
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_0dc), (s32) (param_1->mUnk_0a0->mUnk_0e0));
    func_ov001_0219b1c4(param_1->mUnk_304, (s32) (param_1->mUnk_0a0->mUnk_0e4), (s32) (param_1->mUnk_0a0->mUnk_0e0), 0);
    func_ov001_02188cd8(param_1, (s32) (param_1->mUnk_0a0->mUnk_0e8), (s32) (param_1->mUnk_0a0->mUnk_0ec));
    func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_0f0, param_1->mUnk_0a0->mUnk_0f4);
    func_ov001_02188998(param_1, (Vec3 *) func_ov001_02187fc0(param_1));
    func_ov001_02188e24(param_1, (s32) ((u32) (param_1->mUnk_0a0->mUnk_100)), (UnkFunc *) func_ov001_0218c354);
    func_ov001_02188d08(param_1, (s32) (param_1->mUnk_000.mUnk_1c.x + param_1->mUnk_0a0->mUnk_0f8),
                        (s32) (param_1->mUnk_0a0->mUnk_0fc));
    func_ov001_02188cec(param_1, 0);
    func_0209b688((void *) (param_1->mUnk_304), (u16) (func_ov001_02188220(param_1)));
    if (func_ov001_02188220(param_1) == 0) {
        func_ov001_0218c6b4(param_1);
        func_ov001_0218756c(param_1, 0, 0x1800, 0, 0x419, 0);
    } else if (func_ov001_02188220(param_1) == 1) {
        func_ov001_0218c63c(param_1);
        func_ov001_0218756c(param_1, 0, 0x1800, 0, 0x41a, 0);
    }
}

void func_ov001_0218ba34(Unk02188950 *param_1) {
    func_ov001_0218ba48(param_1);
    func_ov001_02188230(param_1);
}

void func_ov001_0218b9b4(Unk02188950 *param_1) {
    Unk0206bcb0 *unk;

    unk = func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(param_1, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_078), (s32) (param_1->mUnk_0a0->mUnk_07c));
    func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_20c, param_1->mUnk_0a0->mUnk_210);
    func_ov001_02188998(param_1, &unk->mUnk_80);
    func_ov001_02188cd8(param_1, (s32) (param_1->mUnk_0a0->mUnk_204), (s32) (param_1->mUnk_0a0->mUnk_208));
}

void func_ov001_0218b928(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8, (s32(*)(Unk02188950 *))(0));
    func_0208b7bc(0x418, &param_1->mUnk_000.mUnk_04);
    func_0208b7bc(0x417, &param_1->mUnk_000.mUnk_04);
    func_0208b7bc(0x416, &param_1->mUnk_000.mUnk_04);
    {
        Unk0218b928_local local = {0x225, 0, 0xf, 0};

        local.mUnk_04 = &param_1->mUnk_000.mUnk_04;
        local.mUnk_0c = func_020d4ef4(local.mUnk_04);
        func_0210b734(&local, func_02108e7c());
    }
    param_1->mUnk_000.mUnk_02 |= data_ov001_021a659c;
    param_1->mUnk_000.mUnk_02 |= data_ov001_021a65a0;
    param_1->mUnk_000.mUnk_02 |= data_ov001_021a65a4;
}

void func_ov001_0218b8f8(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_070), (s32) (param_1->mUnk_0a0->mUnk_074));
    func_ov001_02188e24(param_1, (s32) ((u32) 0x3c), (UnkFunc *) ((int) &func_ov001_0218b928));
}

void func_ov001_0218b8f0(void) {
    func_ov001_021882b8();
}

u32 func_ov001_0218b8d4(Unk02188950 *param_1) {
    int v1;
    v1 = func_02061fec();
    if (v1 == 1) {
        func_ov001_02188e88(param_1);
    }
    return 0;
}

u32 func_ov001_0218b850(Unk02188950 *param_1) {
    int v1;
    v1 = func_0209b620((int) (param_1->mUnk_304));
    if (v1 == 0x4d) {
        func_ov001_02187af4(param_1);
        func_ov001_02187518(param_1, (u32) (((u32) 0xfffff99au)), (u32) 0, (u32) (((u32) 0xfffff99au)),
                            (u32) (((u32) 0x0000042bu)), (u32) 0);
        func_020d2774(&param_1->mUnk_000, (u32) (((u32) 0x0000021eu)));
    } else {
        v1 = func_0209b620((int) (param_1->mUnk_304));
        if (v1 == 0x68) {
            func_ov001_02187af4(param_1);
            func_ov001_02187518(param_1, (u32) (((u32) 0xfffff99au)), (u32) 0, (u32) (((u32) 0xfffff99au)),
                                (u32) (((u32) 0x0000042cu)), (u32) 0);
            func_020d2774(&param_1->mUnk_000, (u32) (((u32) 0x0000021fu)));
        }
    }
    return 0;
}

void func_ov001_0218b828(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8, (s32(*)(Unk02188950 *))((int) &func_ov001_0218b8d4));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 100)),
                        (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x68)));
}

void func_ov001_0218b7fc(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8, (s32(*)(Unk02188950 *))((int) &func_ov001_0218b850));
    func_ov001_02188d30(param_1, (s32) (param_1->mUnk_0a0->mUnk_058), (s32) (param_1->mUnk_0a0->mUnk_05c),
                        (UnkFunc *) &func_ov001_0218b828);
}

void func_ov001_0218b7c8(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_04c), (s32) (param_1->mUnk_0a0->mUnk_050));
    func_ov001_02188e24(param_1, (s32) ((u32) (param_1->mUnk_0a0->mUnk_054)), (UnkFunc *) ((int) &func_ov001_0218b7fc));
}

void func_ov001_0218b7a4(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x40)),
                        (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x44)));
}

void func_ov001_0218b770(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_034), (s32) (param_1->mUnk_0a0->mUnk_038));
    func_ov001_02188e24(param_1, (s32) ((u32) (param_1->mUnk_0a0->mUnk_03c)), (UnkFunc *) ((int) &func_ov001_0218b7a4));
}

void func_ov001_0218b72c(Unk02188950 *param_1) {
    func_020ac588((u32) 0x191, 0x32, (void *) param_1);
    param_1->mUnk_000.mUnk_94 = func_02036bec((void *) func_020364e0(func_020364e8()), 0x44);
    func_02109110((Unk0210bfbc *) (param_1->mUnk_000.mUnk_94), (u32) 0xf, (Vec3 *) (&param_1->mUnk_000.mUnk_04));
    param_1->mUnk_000.mUnk_70 = data_0217cc6c[15];
}

void func_ov001_0218b6f8(Unk02188950 *param_1, void *param_2) {
    func_ov001_02188200(param_1, func_ov001_0218b6f8);
    if (param_1->mUnk_2d0 == 0) {
        func_020d26ec(param_2, (u32) 0x224);
    }
}

void func_ov001_0218b640(Unk02188950 *param_1, void *param_2) {
    param_1->mUnk_000.mUnk_10.x =
        (s64) param_1->mUnk_0a0->mUnk_130 * data_0215d4b4[((u16) param_1->mUnk_1a8 >> 4) * 2] >> 12;
    param_1->mUnk_000.mUnk_10.y = 0;
    param_1->mUnk_000.mUnk_10.z =
        (s64) param_1->mUnk_0a0->mUnk_130 * data_0215d4b4[((u16) param_1->mUnk_1a8 >> 4) * 2 + 1] >> 12;
    param_1->mUnk_2d8 = 0xd;
    func_02073fb0(param_1->mUnk_000.mUnk_78 & 0x3fffffe0, 0x1000);
    func_ov001_02188200(param_1, func_ov001_0218b6f8);
    if (param_1->mUnk_2d0 == 0) {
        func_020d26ec(param_2, (u32) 0x224);
    }
}

void func_ov001_0218b5d8(Unk0218d87c *param_1) {
    s32 i;
    Unk02188950 *obj;

    if (param_1 != 0) {
        for (i = 0; i < param_1->mUnk_04 && (obj = param_1->mUnk_00[i]) != 0; i++) {
            func_ov001_0219b1c4(obj->mUnk_304, obj->mUnk_0a0->mUnk_080, obj->mUnk_0a0->mUnk_050, 0);
            if (func_02062ec4()) {
                func_ov001_0218b770(obj);
            } else {
                func_ov001_0218b7c8(obj);
            }
        }
    }
    func_020a2314((void (*)(void)) func_ov001_0218b8f0);
}

void func_ov001_0218b404(u32 param_1, Unk02188950 *param_2) {
    s32 var;

    if (data_021759c0->mUnk_08 == 4 ? func_020a126c() : 0) {
        if (func_ov001_021871f8(param_2, 1)) {
            if (data_021759c0->mUnk_08 == 4 ? func_020a1084((u16) data_021759c0->mUnk_62) : 0) {
                func_ov001_0218b9b4(param_2);
            } else {
                func_ov001_0218b8f8(param_2);
            }
        }
    } else {
        if (func_ov001_021881a8(param_2, (Vec3 *) func_ov001_02187fc0(param_2), (s32) (param_2->mUnk_0a0->mUnk_0b4),
                                0)) {
            var = func_ov001_02187f7c(param_2);
            if (var >= 200) {
                if (func_ov001_021871f8(param_2, 8)) {
                    func_ov001_0218ba34(param_2);
                    func_ov001_02188200(param_2, (UnkFunc *) func_ov001_0218b6f8);
                }
            } else if (var >= 100) {
                if (func_ov001_021871f8(param_2, 7)) {
                    func_ov001_0218bbac(param_2);
                    func_ov001_02188200(param_2, (UnkFunc *) func_ov001_0218b6f8);
                }
            } else if (var >= 1) {
                if (func_ov001_021871f8(param_2, 1)) {
                    func_ov001_0218bde8(param_2);
                    func_ov001_02188200(param_2, (UnkFunc *) func_ov001_0218b6f8);
                }
            }
            func_ov001_02187e78(param_2);
            if (param_2->mUnk_14c == 0) {
                func_ov001_02187e48(param_2, 3);
            }
        }
        if (func_ov001_021871f8(param_2, 2)) {
            if (func_ov001_02188104(param_2, param_2->mUnk_0a0->mUnk_124, param_2->mUnk_0a0->mUnk_128)) {
                func_ov001_0218c490(param_2);
                func_ov001_02188200(param_2, (UnkFunc *) func_ov001_0218b640);
            }
        }
        if (func_ov001_021871f8(param_2, 1)) {
            func_ov001_0218c354(param_2);
            func_ov001_02188200(param_2, (UnkFunc *) func_ov001_0218b640);
        }
        param_2->mUnk_2b8 = 1;
    }
    func_ov001_021864ac(param_1, param_2);
    func_ov001_0219b1fc(param_2->mUnk_304);
    var = param_2->mUnk_134 + 1;
    if (var >= func_ov001_02188220(param_2) * 30) {
        var = func_ov001_02188220(param_2) * 30;
    }
    param_2->mUnk_134 = var;
    var = param_2->mUnk_134;
    if (var >= func_0209b710(param_2->mUnk_304) - 1) {
        var = func_0209b710(param_2->mUnk_304) - 1;
    }
    param_2->mUnk_134 = var;
    func_0209b734(param_2->mUnk_304, (u16) param_2->mUnk_134);
}

void func_ov001_0218b35c(Unk0218d87c *param_1) {
    s32 i;
    Unk02188950 *obj;

    if (param_1 != 0) {
        for (i = 0; i < param_1->mUnk_04 && (obj = param_1->mUnk_00[i]) != 0; i++) {
            if (data_021759c0->mUnk_08 == 4) {
                func_ov001_02181b8c(obj);
            }
            func_ov001_021870e4((void *) param_1, obj, (const char *) ("kuriking.nsbmd"),
                                (const char *) ("kuriking.nsbca"), (const char *) ("kuriking.prm"));
            func_ov001_021870b0((void *) param_1, obj, (const char *) ("sh_circle.nsbmd"));
            func_ov001_0219b31c(obj->mUnk_304, "kuriking.nsbta");
            func_ov001_0219b2e8(obj->mUnk_304, "kuriking.nsbtp");
            func_ov001_0219b380(obj->mUnk_304, "kuriking.nsbma");
            func_ov001_0218c728(obj);
            func_ov001_02188200(obj, (UnkFunc *) func_ov001_0218b6f8);
        }
    }
}
