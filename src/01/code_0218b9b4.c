#include "01/code_0218b9b4.h"

#include "01/code_0218b298.h"
#include "01/code_0218b2dc.h"
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

void func_ov001_0218bee4(Unk02188950 *a) {
    Unk0206bcb0 *unk;

    unk = func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(a, 2, (s32(*)(Unk02188950 *)) func_ov001_0218c55c);
    func_ov001_02188d30(a, (s32) (a->mUnk_0a0->mUnk_184), (s32) (a->mUnk_0a0->mUnk_188),
                        (UnkFunc *) func_ov001_0218bfc8);
    func_ov001_0219b1c4(a->mUnk_304, (s32) (a->mUnk_0a0->mUnk_18c), (s32) (a->mUnk_0a0->mUnk_188), 0);
    func_ov001_02188cd8(a, 0, (s32) (a->mUnk_0a0->mUnk_144));
    func_ov001_02188a30(a, 0, a->mUnk_0a0->mUnk_154, a->mUnk_0a0->mUnk_148, a->mUnk_0a0->mUnk_14c);
    func_ov001_02188968(a, &unk->mUnk_80);
    func_ov001_02188980(a, (Vec3 *) func_ov001_02187fc0(a));
    func_ov001_02188e74(a, (s32) ((u32) (a->mUnk_0a0->mUnk_190)), func_ov001_0218c0a4);
}

void func_ov001_0218bde8(Unk02188950 *a) {
    Unk0206bcb0 *unk;

    unk = func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(a, 2, (s32(*)(Unk02188950 *)) func_ov001_0218c55c);
    func_ov001_02188d64(a, (s32) (a->mUnk_0a0->mUnk_134), (s32) (a->mUnk_0a0->mUnk_138));
    func_ov001_0219b1c4(a->mUnk_304, (s32) (a->mUnk_0a0->mUnk_13c), (s32) (a->mUnk_0a0->mUnk_138), 0);
    func_ov001_02188cd8(a, (s32) (a->mUnk_0a0->mUnk_140), (s32) (a->mUnk_0a0->mUnk_144));
    func_ov001_02188a30(a, a->mUnk_0a0->mUnk_150, a->mUnk_0a0->mUnk_154, a->mUnk_0a0->mUnk_148, a->mUnk_0a0->mUnk_14c);
    func_ov001_02188968(a, &unk->mUnk_80);
    func_ov001_02188980(a, (Vec3 *) func_ov001_02187fc0(a));
    func_ov001_02188e24(a, (s32) ((u32) (a->mUnk_0a0->mUnk_158)), (UnkFunc *) func_ov001_0218bee4);
    a->mUnk_138 = func_ov001_02187f7c(a);
    func_ov001_0218c5fc((Unk02188950 *) ((u32) a));
}

void func_ov001_0218bd80(Unk02188950 *a) {
    func_ov001_02187218(a, 7, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(a, (s32) (a->mUnk_0a0->mUnk_1f8), (s32) (a->mUnk_0a0->mUnk_1fc), NULL);
    func_ov001_0219b1c4(a->mUnk_304, (s32) (a->mUnk_0a0->mUnk_200), (s32) (a->mUnk_0a0->mUnk_1fc), 0);
    func_ov001_02188c90(a);
    func_ov001_02188cec(a, 0);
    a->mUnk_000.mUnk_02 &= ~0x20;
}

void func_ov001_0218bcc4(Unk02188950 *a) {
    Vec3 local = {0, 0, 0};

    local.y = a->mUnk_0a0->mUnk_1f4;
    func_ov001_02187218(a, 7, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(a, (s32) (a->mUnk_0a0->mUnk_1e0), (s32) (a->mUnk_0a0->mUnk_1e4));
    func_ov001_0219b1c4(a->mUnk_304, (s32) (a->mUnk_0a0->mUnk_1e8), (s32) (a->mUnk_0a0->mUnk_1e4), 0);
    func_ov001_02188950(a, &local);
    func_ov001_02188c90(a);
    func_ov001_02188cd8(a, (s32) (a->mUnk_0a0->mUnk_1ec), (s32) (a->mUnk_0a0->mUnk_1f0));
    func_ov001_02188db8(a, (UnkFunc *) func_ov001_0218bd80);
    func_020d2774(&a->mUnk_000, (u32) 0x226);
    a->mUnk_000.mUnk_02 |= data_ov001_021a65a8;
}

void func_ov001_0218bc60(Unk02188950 *a) {
    func_ov001_02187218(a, 7, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(a, (s32) (a->mUnk_0a0->mUnk_1d4), (s32) (a->mUnk_0a0->mUnk_1d8),
                        (UnkFunc *) func_ov001_0218bcc4);
    func_ov001_0219b1c4(a->mUnk_304, (s32) (a->mUnk_0a0->mUnk_1dc), (s32) (a->mUnk_0a0->mUnk_1d8), 0);
    func_ov001_02188c90(a);
    func_ov001_02188cec(a, 0);
}

void func_ov001_0218bbac(Unk02188950 *a) {
    func_ov001_02187218(a, 7, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(a, (s32) (a->mUnk_0a0->mUnk_1b4), (s32) (a->mUnk_0a0->mUnk_1b8));
    func_ov001_0219b1c4(a->mUnk_304, (s32) (a->mUnk_0a0->mUnk_1bc), (s32) (a->mUnk_0a0->mUnk_1b8), 0);
    func_ov001_02188c48(a, a->mUnk_0a0->mUnk_1c8, a->mUnk_0a0->mUnk_1cc);
    func_ov001_02188998(a, &a->mUnk_000.mUnk_9c->mUnk_00);
    func_ov001_02188cd8(a, (s32) (a->mUnk_0a0->mUnk_1c0), (s32) (a->mUnk_0a0->mUnk_1c4));
    func_ov001_02188e24(a, (s32) ((u32) (a->mUnk_0a0->mUnk_1d0)), (UnkFunc *) func_ov001_0218bc60);
    func_ov001_0218c5fc((Unk02188950 *) ((u32) a));
}

int func_ov001_0218bb74(Unk02188950 *a) {
    if (func_ov001_02188220(a) == 1) {
        func_020d275c(&a->mUnk_000, (u32) 0x220);
    } else if (func_ov001_02188220(a) == 2) {
        func_020d275c(&a->mUnk_000, (u32) 0x221);
    }
    return 0;
}

void func_ov001_0218ba48(Unk02188950 *a) {
    func_ov001_02187218(a, 8, func_ov001_0218bb74);
    func_ov001_02188d64(a, (s32) (a->mUnk_0a0->mUnk_0dc), (s32) (a->mUnk_0a0->mUnk_0e0));
    func_ov001_0219b1c4(a->mUnk_304, (s32) (a->mUnk_0a0->mUnk_0e4), (s32) (a->mUnk_0a0->mUnk_0e0), 0);
    func_ov001_02188cd8(a, (s32) (a->mUnk_0a0->mUnk_0e8), (s32) (a->mUnk_0a0->mUnk_0ec));
    func_ov001_02188c48(a, a->mUnk_0a0->mUnk_0f0, a->mUnk_0a0->mUnk_0f4);
    func_ov001_02188998(a, (Vec3 *) func_ov001_02187fc0(a));
    func_ov001_02188e24(a, (s32) ((u32) (a->mUnk_0a0->mUnk_100)), (UnkFunc *) func_ov001_0218c354);
    func_ov001_02188d08(a, (s32) (a->mUnk_000.mUnk_1c.x + a->mUnk_0a0->mUnk_0f8), (s32) (a->mUnk_0a0->mUnk_0fc));
    func_ov001_02188cec(a, 0);
    func_0209b688((void *) (a->mUnk_304), (u16) (func_ov001_02188220(a)));
    if (func_ov001_02188220(a) == 0) {
        func_ov001_0218c6b4(a);
        func_ov001_0218756c(a, 0, 0x1800, 0, 0x419, 0);
    } else if (func_ov001_02188220(a) == 1) {
        func_ov001_0218c63c(a);
        func_ov001_0218756c(a, 0, 0x1800, 0, 0x41a, 0);
    }
}

void func_ov001_0218ba34(Unk02188950 *a) {
    func_ov001_0218ba48(a);
    func_ov001_02188230(a);
}

void func_ov001_0218b9b4(Unk02188950 *a) {
    Unk0206bcb0 *unk;

    unk = func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(a, (s32) (a->mUnk_0a0->mUnk_078), (s32) (a->mUnk_0a0->mUnk_07c));
    func_ov001_02188c48(a, a->mUnk_0a0->mUnk_20c, a->mUnk_0a0->mUnk_210);
    func_ov001_02188998(a, &unk->mUnk_80);
    func_ov001_02188cd8(a, (s32) (a->mUnk_0a0->mUnk_204), (s32) (a->mUnk_0a0->mUnk_208));
}
