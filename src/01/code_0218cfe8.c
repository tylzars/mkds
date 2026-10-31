#include "01/code_0218cfe8.h"

u32 func_ov001_0218d264(Unk02188950 *param_1) {
    int v1;
    v1 = func_02061fec();
    if (v1 == 1) {
        func_ov001_0218d4c8(param_1);
    }
    return 0;
}

void func_ov001_0218d23c(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8,
                        (s32(*)(Unk02188950 *))((int) &func_ov001_0218d264));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 100)), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x68)));
}

void func_ov001_0218d214(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_02188d30(param_1, (s32) (param_1->mUnk_0a0->mUnk_058),
                        (s32) (param_1->mUnk_0a0->mUnk_05c),
                        (UnkFunc *) &func_ov001_0218d23c);
}

void func_ov001_0218d1e0(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_04c), (s32) (param_1->mUnk_0a0->mUnk_050));
    func_ov001_02188e24(param_1, (s32) ((u32) (param_1->mUnk_0a0->mUnk_054)),
                        (UnkFunc *) ((int) &func_ov001_0218d214));
}

void func_ov001_0218d1bc(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x40)), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x44)));
}

void func_ov001_0218d188(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_034), (s32) (param_1->mUnk_0a0->mUnk_038));
    func_ov001_02188e24(param_1, (s32) ((u32) (param_1->mUnk_0a0->mUnk_03c)),
                        (UnkFunc *) ((int) &func_ov001_0218d1bc));
}

u32 func_ov001_0218d16c(Unk02188950 *param_1) {
    int v1;
    v1 = func_02061fec();
    if (v1 == 1) {
        func_ov001_0218d950(param_1);
    }
    return 0;
}

u32 func_ov001_0218d0fc(Unk02188950 *param_1) {
    int v1;
    v1 = func_0209b620((int) (param_1->mUnk_304));
    if (v1 == 0x33) {
        func_ov001_02187af4(param_1);
        func_ov001_021875c0(param_1, (u32) (((u32) 0xfffff666u)), (u32) 0, (u32) (((u32) 0x00000400u)),
                            (u32) (((u32) 0x00000434u)), (u32) 0);
    } else {
        v1 = func_0209b620((int) (param_1->mUnk_304));
        if (v1 == 0x66) {
            func_ov001_02187af4(param_1);
            func_ov001_021875c0(param_1, (u32) (((u32) 0x0000099au)), (u32) 0, (u32) (((u32) 0x00000400u)),
                                (u32) (((u32) 0x00000434u)), (u32) 0);
        }
    }
    return 0;
}

void func_ov001_0218d0d4(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8,
                        (s32(*)(Unk02188950 *))((int) &func_ov001_0218d16c));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 100)), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x68)));
}

void func_ov001_0218d0a8(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8,
                        (s32(*)(Unk02188950 *))((int) &func_ov001_0218d0fc));
    func_ov001_02188d30(param_1, (s32) (param_1->mUnk_0a0->mUnk_058),
                        (s32) (param_1->mUnk_0a0->mUnk_05c),
                        (UnkFunc *) &func_ov001_0218d0d4);
}

void func_ov001_0218d074(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_04c), (s32) (param_1->mUnk_0a0->mUnk_050));
    func_ov001_02188e24(param_1, (s32) ((u32) (param_1->mUnk_0a0->mUnk_054)),
                        (UnkFunc *) ((int) &func_ov001_0218d0a8));
}

void func_ov001_0218d050(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x40)), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x44)));
}

void func_ov001_0218d01c(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_034), (s32) (param_1->mUnk_0a0->mUnk_038));
    func_ov001_02188e24(param_1, (s32) ((u32) (param_1->mUnk_0a0->mUnk_03c)),
                        (UnkFunc *) ((int) &func_ov001_0218d050));
}

void func_ov001_0218cfe8(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 100)), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x68)));
    func_ov001_02188e24((Unk02188950 *) (param_1), (s32) ((u32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x54))),
                        (UnkFunc *) ((int) &func_ov001_0218d0a8));
}
