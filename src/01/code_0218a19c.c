#include "01/code_0218a19c.h"

u32 func_ov001_0218a2b8(Unk02188950 *param_1) {
    int v1;
    v1 = func_02061fec();
    if (v1 == 1) {
        func_ov001_02188e88(param_1);
    }
    return 0;
}

void func_ov001_0218a290(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8, (s32(*)(Unk02188950 *))((int) &func_ov001_0218a2b8));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 100)),
                        (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x68)));
}

void func_ov001_0218a250(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(param_1, (s32) (param_1->mUnk_0a0->mUnk_058), (s32) (param_1->mUnk_0a0->mUnk_05c),
                        (UnkFunc *) &func_ov001_0218a290);
    func_ov001_02188e74(param_1, (s32) ((u32) (param_1->mUnk_0a0->mUnk_148)), (UnkFunc *) ((u32) &func_ov001_0218b034));
}

void func_ov001_0218a20c(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_04c), (s32) (param_1->mUnk_0a0->mUnk_050));
    func_ov001_02188e24(param_1, (s32) ((u32) (param_1->mUnk_0a0->mUnk_054)), (UnkFunc *) ((int) &func_ov001_0218a250));
    func_020d2774(&param_1->mUnk_000, (u32) (((u32) 0x00000235u)));
}

void func_ov001_0218a1d0(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x40)),
                        (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x44)));
    func_ov001_02188e74((Unk02188950 *) (param_1), (s32) ((u32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x148))),
                        func_ov001_0218affc);
}

void func_ov001_0218a19c(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_034), (s32) (param_1->mUnk_0a0->mUnk_038));
    func_ov001_02188e24(param_1, (s32) ((u32) (param_1->mUnk_0a0->mUnk_03c)), (UnkFunc *) ((int) &func_ov001_0218a1d0));
}
