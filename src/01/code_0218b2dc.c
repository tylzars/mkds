#include "01/code_0218b2dc.h"

#include "Main/Unknown/code_0209bef0.h"
#include "01/unk_021a6000.h"
#include "01/code_02188000.h"
#include "01/code_0218c000.h"
#include "Main/Unknown/code_020d4000.h"
#include "01/code_02185ef4.h"
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
                    func_ov001_02188200(param_2, func_ov001_0218b6f8);
                }
            } else if (var >= 100) {
                if (func_ov001_021871f8(param_2, 7)) {
                    func_ov001_0218bbac(param_2);
                    func_ov001_02188200(param_2, func_ov001_0218b6f8);
                }
            } else if (var >= 1) {
                if (func_ov001_021871f8(param_2, 1)) {
                    func_ov001_0218bde8(param_2);
                    func_ov001_02188200(param_2, func_ov001_0218b6f8);
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
                func_ov001_02188200(param_2, func_ov001_0218b640);
            }
        }
        if (func_ov001_021871f8(param_2, 1)) {
            func_ov001_0218c354(param_2);
            func_ov001_02188200(param_2, func_ov001_0218b640);
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
            func_ov001_02188200(obj, func_ov001_0218b6f8);
        }
    }
}

void func_ov001_0218b33c(u32 param_1, u32 param_2) {
    func_ov001_02186368((void *) param_1, (Unk02188950 *) param_2);
    func_ov001_021861f4((void *) param_1, (Unk02188950 *) param_2, 0);
}

void func_ov001_0218b310(void) {
    void *v7 = &func_ov001_02185fb0;
    void *v8 = &func_ov001_02185f04;
    void *v9 = &func_ov001_021860cc;
    u32 v11 =
        (u32) func_ov001_0219b510(v7, v8, v9, (u32) 0x2u, (u16) ((u32) 0x1u), (u16) ((u32) 0x0u), (u16) ((u32) 0x0u));
}

void *func_ov001_0218b2f4(void) {
    return (void *) func_0209bf1c(func_ov001_0218b35c, func_ov001_0218b33c, func_ov001_02187098);
}

void *func_ov001_0218b2dc(void) {
    return (void *) func_0209bf48(func_ov001_0218b5d8, func_ov001_0218b404, 0);
}
