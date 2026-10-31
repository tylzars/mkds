#include "01/code_0218a19c.h"

u32 func_ov001_0218a2b8(u32 param_1) {
    int v1;
    v1 = func_02061fec();
    if (v1 == 1) {
        func_ov001_02188e88((Unk02188950 *) (param_1));
    }
    return 0;
}

void func_ov001_0218a290(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8,
                        (s32(*)(Unk02188950 *))((int) &func_ov001_0218a2b8));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 100)), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x68)));
}

void func_ov001_0218a250(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_02188d30((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x58)),
                        (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x5c)),
                        (UnkFunc *) &func_ov001_0218a290);
    func_ov001_02188e74((Unk02188950 *) (param_1),
                        (s32) ((u32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x148))),
                        (UnkFunc *) ((u32) &func_ov001_0218b034));
}

void func_ov001_0218a20c(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x4c)), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x50)));
    func_ov001_02188e24((Unk02188950 *) (param_1), (s32) ((u32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x54))),
                        (UnkFunc *) ((int) &func_ov001_0218a250));
    func_020d2774((Unk020e71a0 *) (param_1), (u32) (((u32) 0x00000235u)));
}

void func_ov001_0218a1d0(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x40)), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x44)));
    func_ov001_02188e74((Unk02188950 *) (param_1),
                        (s32) ((u32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x148))),
                        func_ov001_0218affc);
}

void func_ov001_0218a19c(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x34)), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x38)));
    func_ov001_02188e24((Unk02188950 *) (param_1), (s32) ((u32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x3c))),
                        (UnkFunc *) ((int) &func_ov001_0218a1d0));
}
