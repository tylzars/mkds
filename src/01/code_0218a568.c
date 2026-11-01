#include "01/code_0218a568.h"
#include "01/code_02187000.h"
#include "01/code_0218a000.h"
#include "01/code_0218b000.h"
#include "Main/Unknown/code_020fd000.h"

void func_ov001_0218aba0(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 3, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_198), (s32) (param_1->mUnk_0a0->mUnk_19c));
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
    func_ov001_02188e24(param_1, (s32) (param_1->mUnk_0a0->mUnk_1a0), (UnkFunc *) ((int) &func_ov001_0218ac04));
    func_020d2774(&param_1->mUnk_000, (u32) (0x238));
}

void func_ov001_0218ab04(Unk02188950 *param_1) {
    func_ov001_02187e78(param_1);
    func_ov001_02187218(param_1, 3, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_17c), (s32) (param_1->mUnk_0a0->mUnk_180));
    func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_18c, param_1->mUnk_0a0->mUnk_190);
    func_ov001_02188998(param_1, (Vec3 *) func_ov001_02187fc0(param_1));
    func_ov001_02188cd8(param_1, (s32) (param_1->mUnk_0a0->mUnk_184), (s32) (param_1->mUnk_0a0->mUnk_188));
    func_ov001_02188e24(param_1, (s32) (param_1->mUnk_0a0->mUnk_194), (UnkFunc *) ((int) &func_ov001_0218aba0));
    func_ov001_0218b278(param_1);
}

void func_ov001_0218aaac(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 3, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(param_1, (s32) (param_1->mUnk_0a0->mUnk_140), (s32) (param_1->mUnk_0a0->mUnk_144),
                        (UnkFunc *) (0));
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
    func_ov001_02188e74(param_1, (s32) (param_1->mUnk_0a0->mUnk_148), func_ov001_0218b034);
}

void func_ov001_0218aa34(Unk02188950 *param_1) {
    void *b;

    if (func_ov001_02187c4c((int) param_1) == 0) {
        b = func_020fd428();
        if (b != 0) {
            func_ov001_02187c60(param_1, (void *) (b));
        }
    }
    if (func_ov001_02187c4c((int) param_1) != 0) {
        func_ov001_02187218(param_1, 3, (s32(*)(Unk02188950 *))(0));
        func_ov001_02188d30(param_1, (s32) (param_1->mUnk_0a0->mUnk_0d4), (s32) (param_1->mUnk_0a0->mUnk_0d8),
                            (UnkFunc *) (0));
        func_ov001_02188cec(param_1, 0);
        func_ov001_02188e74(param_1, (s32) (param_1->mUnk_0a0->mUnk_0dc), func_ov001_0218b1d8);
    }
    func_020d2774(&param_1->mUnk_000, (u32) (0x23c));
}

void func_ov001_0218a970(Unk02188950 *param_1) {
    u8 *a;

    a = (u8 *) func_ov001_02188104(param_1, (s32) (param_1->mUnk_0a0->mUnk_0c0), (s32) (param_1->mUnk_0a0->mUnk_0c4));
    if (a != 0) {
        func_ov001_02187218(param_1, 3, (s32(*)(Unk02188950 *))(0));
        func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_104), (s32) (param_1->mUnk_0a0->mUnk_108));
        func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_0bc, param_1->mUnk_0a0->mUnk_0bc);
        func_ov001_02188998(param_1, (Vec3 *) (a + 0x80));
        func_ov001_02188cec(param_1, (s32) (param_1->mUnk_0a0->mUnk_0b8));
        func_ov001_02188de0(param_1, (s32) (param_1->mUnk_0a0->mUnk_0cc), (s32) (param_1->mUnk_0a0->mUnk_0d0),
                            (Vec3 *) (a + 0x80), (UnkFunc *) &func_ov001_0218aa34);
        func_ov001_02188e24(param_1, (s32) (param_1->mUnk_0a0->mUnk_0c8), (UnkFunc *) (0));
        func_ov001_0218b278(param_1);
    } else {
        func_ov001_02188e88(param_1);
    }
}

void func_ov001_0218a910(Unk02188950 *param_1) {
    if (func_ov001_02187c4c((int) param_1) != 0) {
        func_ov001_02187218(param_1, 3, (s32(*)(Unk02188950 *))(0));
        func_ov001_02188d30(param_1, (s32) (param_1->mUnk_0a0->mUnk_0d4), (s32) (param_1->mUnk_0a0->mUnk_0d8),
                            (UnkFunc *) (0));
        func_ov001_02188cec(param_1, 0);
        func_ov001_02188e74(param_1, (s32) (param_1->mUnk_0a0->mUnk_0dc), func_ov001_0218b1d8);
        func_020d2774(&param_1->mUnk_000, (u32) (0x23c));
    }
}

void func_ov001_0218a828(Unk02188950 *param_1) {
    u8 *a;
    u8 *c;

    a = (u8 *) func_ov001_02188158(param_1, param_1->mUnk_0a0->mUnk_11c, param_1->mUnk_0a0->mUnk_120);
    if (a != 0) {
        c = (u8 *) func_ov001_02188104(param_1, (s32) (param_1->mUnk_0a0->mUnk_0c0),
                                       (s32) (param_1->mUnk_0a0->mUnk_0c4));
        if (c != 0) {
            func_020fd754(a);
            func_ov001_02187c60(param_1, (void *) (a));
            func_ov001_02187218(param_1, 3, (s32(*)(Unk02188950 *))(0));
            func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_0ec), (s32) (param_1->mUnk_0a0->mUnk_0f0));
            func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_0f8, param_1->mUnk_0a0->mUnk_0f8);
            func_ov001_02188998(param_1, (Vec3 *) (c + 0x80));
            func_ov001_02188cec(param_1, (s32) (param_1->mUnk_0a0->mUnk_0f4));
            func_ov001_02188de0(param_1, (s32) (param_1->mUnk_0a0->mUnk_0cc), (s32) (param_1->mUnk_0a0->mUnk_0d0),
                                (Vec3 *) (c + 0x80), (UnkFunc *) &func_ov001_0218a910);
            func_ov001_0218b278(param_1);
        } else {
            func_020fd754(a);
            func_ov001_02187c60(param_1, (void *) (a));
            func_ov001_0218a910(param_1);
        }
    }
}

void func_ov001_0218a75c(Unk02188950 *param_1) {
    int a;

    a = func_ov001_02188158(param_1, param_1->mUnk_0a0->mUnk_114, param_1->mUnk_0a0->mUnk_118);
    if (a != 0) {
        func_ov001_02187218(param_1, 3, (s32(*)(Unk02188950 *))(0));
        func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_104), (s32) (param_1->mUnk_0a0->mUnk_108));
        func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_110, param_1->mUnk_0a0->mUnk_110);
        func_ov001_02188998(param_1, (Vec3 *) (a + 0x50));
        func_ov001_02188cec(param_1, (s32) (param_1->mUnk_0a0->mUnk_10c));
        func_ov001_02188de0(param_1, (s32) (param_1->mUnk_0a0->mUnk_11c), (s32) (param_1->mUnk_0a0->mUnk_120),
                            (Vec3 *) (a + 0x50), (UnkFunc *) &func_ov001_0218a828);
        func_ov001_02188e24(param_1, (s32) (param_1->mUnk_0a0->mUnk_124), (UnkFunc *) (0));
        func_ov001_0218b278(param_1);
    }
}

void func_ov001_0218a6b0(Unk02188950 *param_1) {
    u32 n;
    u64 *a;
    u32 b;

    n = (u16) param_1->mUnk_0a0->mUnk_208;
    if (n == 0x10000) {
        a = (u64 *) func_020d22d0();
        a[0] = (s64) a[1] * (s64) a[0] + a[2];
        b = (u16) (((u64) (u32) (a[0] >> 32) * 0x10000) >> 32);
    } else {
        a = (u64 *) func_020d22d0();
        if ((u16) n == 0) {
            b = 0;
        } else {
            a[0] = (s64) a[1] * (s64) a[0] + a[2];
            if ((u16) n == 0) {
                b = (u32) (a[0] >> 32);
            } else {
                b = (u32) (((s64) (u32) (a[0] >> 32) * (s64) (u16) n) >> 32);
            }
        }
        b = (u16) b;
    }
    if (b != 0) {
        func_ov001_0218aaac(param_1);
    } else {
        func_ov001_0218a970(param_1);
    }
}

void func_ov001_0218a60c(Unk02188950 *param_1) {
    Unk02188950_a0 *a;

    func_ov001_02187e78(param_1);
    func_ov001_02187218(param_1, 2, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_084), (s32) (param_1->mUnk_0a0->mUnk_088));
    func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_090, param_1->mUnk_0a0->mUnk_090);
    func_ov001_02188998(param_1, (Vec3 *) func_ov001_02187fc0(param_1));
    func_ov001_02188cec(param_1, (s32) (param_1->mUnk_0a0->mUnk_08c));
    func_ov001_02188e24(param_1, (s32) (param_1->mUnk_0a0->mUnk_09c), (UnkFunc *) ((int) &func_ov001_0218a6b0));
    a = param_1->mUnk_0a0;
    func_ov001_02188de0(param_1, (s32) (a->mUnk_094), (s32) (a->mUnk_098), (Vec3 *) func_ov001_02187fc0(param_1),
                        (UnkFunc *) &func_ov001_0218aaac);
    func_ov001_0218b278(param_1);
}

int func_ov001_0218a590(Unk02188950 *param_1) {
    if ((param_1->mUnk_2c8 & 0x1e34ef) != 0) {
        if (param_1->mUnk_1c8.y > 0x3333) {
            func_ov001_02187af4(param_1);
            func_ov001_02187518(param_1, 0, 0, 0, 0x411, 0);
            func_ov001_02187518(param_1, 0, 0, 0, 0x412, 0);
        }
        if (param_1->mUnk_1c8.y > 0) {
            func_020d2774(&param_1->mUnk_000, (u32) (0x23b));
        }
    }
    return 0;
}

int func_ov001_0218a568(Unk02188950 *param_1) {
    if ((param_1->mUnk_2c8 & 0x1e34ef) != 0) {
        param_1->mUnk_158 = func_ov001_0218a590;
    }
    return 0;
}
