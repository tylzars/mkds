#include "01/code_0218e690.h"

void func_ov001_0218ead0(Unk02188950 *param_1) {
    int v1;
    u32 v2;

    func_ov001_02187218(param_1, 5, (s32 (*)(Unk02188950 *)) func_ov001_0218edb8);
    func_ov001_0218f850((int) param_1);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_1a8, (UnkFunc *) func_ov001_0218eb94);
    func_ov001_02182a3c(0);
    func_ov001_02187e48(param_1, param_1->mUnk_0a0->mUnk_140);
    v1 = param_1->mUnk_0a8;
    if (v1 == 1) {
        v2 = 2;
    } else if (v1 == 2) {
        v2 = 3;
    } else if (v1 == 3) {
        v2 = 3;
    } else {
        v2 = 1;
    }
    param_1->mUnk_0a8 = v2;
    if (data_0217d20c != 3) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 3;
    param_1->mUnk_270 = param_1->mUnk_0a0->mUnk_00c;
    param_1->mUnk_264 = param_1->mUnk_270;
    param_1->mUnk_268 = param_1->mUnk_264;
    param_1->mUnk_25c = param_1->mUnk_268;
}

u32 func_ov001_0218ea98(int param_1) {
    int v1;
    int v2;
    v2 = *(int *) (*(int *) (param_1 + 0x9c) + 4) + *(int *) (*(int *) (param_1 + 0xa0) + 0x84);
    v1 = *(int *) (param_1 + 8) - *(int *) (*(int *) (param_1 + 0xa0) + 0x88);
    if (v1 <= v2) {
        v1 = v2;
    }
    *(int *) (param_1 + 8) = v1;
    func_02061860();
    return 0;
}

void func_ov001_0218e92c(Unk02188950 *p) {
    func_ov001_02187218(p, 5, (s32 (*)(Unk02188950 *))func_ov001_0218ea98);
    func_ov001_02188d64(p, p->mUnk_0a0->mUnk_170, p->mUnk_0a0->mUnk_174);
    func_ov001_02188d1c(p, p->mUnk_0a0->mUnk_178, p->mUnk_0a0->mUnk_17c);
    func_ov001_02188c90(p);
    func_ov001_02188cec(p, 0);
    func_ov001_02188e24(p, p->mUnk_0a0->mUnk_194, func_ov001_0218ead0);
    func_ov001_021875c0(p, 0, 0, 0, 0x431, 0);
    func_ov001_021875c0(p, 0, 0, 0, 0x430, 0);
    func_ov001_021875c0(p, 0, 0, 0, 0x432, 0);
    if (data_0217d20c != 4) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 4;
    func_ov001_02188200(p, func_ov001_0218e38c);
    p->mUnk_000.mUnk_02 |= data_ov001_021a65b0;
    func_ov001_02182a3c(p->mUnk_0a0->mUnk_18c < (data_021759c0->mUnk_08 == 4 ? (s32)func_ov001_02181800() : 0)
                            ? p->mUnk_0a0->mUnk_18c
                            : (data_021759c0->mUnk_08 == 4 ? (s32)func_ov001_02181800() : 0));
    p->mUnk_25c = p->mUnk_268 = p->mUnk_264 = p->mUnk_270 = (s32)p->mUnk_0a0->mUnk_00c / 2;
}

void func_ov001_0218e8d8(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 5, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_02188d30((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x168)),
                        (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x16c)),
                        (UnkFunc *) &func_ov001_0218e92c);
    func_ov001_02188c90((Unk02188950 *) param_1);
    func_ov001_02188cec((Unk02188950 *) param_1, 0);
    func_ov001_02182a3c(0);
    func_020d2774((Unk020e71a0 *) (param_1), (u32) (((u32) 0x00000230u)));
}

void func_ov001_0218e8b0(u32 param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 1, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_021888a4((Unk02188950 *) param_1, 0, (s32) (((u32) 0x00019000u)));
    func_0206184c();
    func_ov001_021827f0();
}

void func_ov001_0218e860(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 5, (s32 (*)(Unk02188950 *)) func_ov001_0218f688);
    func_ov001_0218f850((int) param_1);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_1a8, (UnkFunc *) func_ov001_0218e8b0);
    if (data_0217d20c != 3) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 3;
}

void func_ov001_0218e7d0(Unk02188950 *p) {
    func_ov001_02187218(p, 1, 0);
    func_ov001_021888a4(p, 0, 0x19000);
    func_ov001_02188d64(p, p->mUnk_0a0->mUnk_198, p->mUnk_0a0->mUnk_19c);
    func_ov001_02188d1c(p, p->mUnk_0a0->mUnk_1a0, p->mUnk_0a0->mUnk_1a4);
    func_ov001_02188cec(p, 0);
    func_ov001_02188c90(p);
    if (data_0217d20c != 3) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 3;
    p->mUnk_000.mUnk_02 |= data_ov001_021a65bc;
}

void func_ov001_0218e7b0(u32 param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 1, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_021888a4((Unk02188950 *) param_1, 0, (s32) (((u32) 0x00019000u)));
}

void func_ov001_0218e760(Unk02188950 *p) {
    func_ov001_02187218(p, 5, func_ov001_0218f688);
    func_ov001_0218f850((int)p);
    func_ov001_02188e24(p, p->mUnk_0a0->mUnk_1a8, func_ov001_0218e7b0);
    if (data_0217d20c != 3) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 3;
}

void func_ov001_0218e710(Unk02188950 *p) {
    func_ov001_02187218(p, 8, 0);
    func_ov001_02188d64(p, p->mUnk_0a0->mUnk_078, p->mUnk_0a0->mUnk_07c);
    func_ov001_02188c90(p);
    func_ov001_02188cec(p, 0);
    if (data_0217d20c != 6) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 6;
    func_0206184c();
}

void func_ov001_0218e690(Unk02188950 *p) {
    func_ov001_02187218(p, 8, 0);
    func_ov001_02188d64(p, p->mUnk_0a0->mUnk_070, p->mUnk_0a0->mUnk_074);
    func_0208b7bc(0x3fe, &p->mUnk_000.mUnk_04);
    func_0208b7bc(0x3fd, &p->mUnk_000.mUnk_04);
    if (data_0217d20c != 7) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 7;
    p->mUnk_000.mUnk_02 |= data_ov001_021a65b4;
    p->mUnk_000.mUnk_02 |= data_ov001_021a65b8;
    p->mUnk_000.mUnk_02 |= data_ov001_021a65bc;
}
