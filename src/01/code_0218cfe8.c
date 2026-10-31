#include "01/code_0218cfe8.h"

u32 func_ov001_0218d264(u32 param_1) {
    int v1;
    v1 = func_02061fec();
    if (v1 == 1) {
        func_ov001_0218d4c8((int) param_1);
    }
    return 0;
}

void func_ov001_0218d23c(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8,
                        (s32(*)(Unk02188950 *))((int) &func_ov001_0218d264));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 100)), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x68)));
}

void func_ov001_0218d214(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_02188d30((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x58)),
                        (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x5c)),
                        (UnkFunc *) &func_ov001_0218d23c);
}

void func_ov001_0218d1e0(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x4c)), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x50)));
    func_ov001_02188e24((Unk02188950 *) (param_1), (s32) ((u32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x54))),
                        (UnkFunc *) ((int) &func_ov001_0218d214));
}

void func_ov001_0218d1bc(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x40)), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x44)));
}

void func_ov001_0218d188(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x34)), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x38)));
    func_ov001_02188e24((Unk02188950 *) (param_1), (s32) ((u32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x3c))),
                        (UnkFunc *) ((int) &func_ov001_0218d1bc));
}

u32 func_ov001_0218d16c(u32 param_1) {
    int v1;
    v1 = func_02061fec();
    if (v1 == 1) {
        func_ov001_0218d950((Unk02188950 *) param_1);
    }
    return 0;
}

u32 func_ov001_0218d0fc(int param_1) {
    int v1;
    v1 = func_0209b620((int) (*(u32 *) (param_1 + 0x304)));
    if (v1 == 0x33) {
        func_ov001_02187af4((Unk02188950 *) (param_1));
        func_ov001_021875c0((Unk02188950 *) param_1, (u32) (((u32) 0xfffff666u)), (u32) 0, (u32) (((u32) 0x00000400u)),
                            (u32) (((u32) 0x00000434u)), (u32) 0);
    } else {
        v1 = func_0209b620((int) (*(u32 *) (param_1 + 0x304)));
        if (v1 == 0x66) {
            func_ov001_02187af4((Unk02188950 *) (param_1));
            func_ov001_021875c0((Unk02188950 *) param_1, (u32) (((u32) 0x0000099au)), (u32) 0, (u32) (((u32) 0x00000400u)),
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

void func_ov001_0218d0a8(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8,
                        (s32(*)(Unk02188950 *))((int) &func_ov001_0218d0fc));
    func_ov001_02188d30((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x58)),
                        (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x5c)),
                        (UnkFunc *) &func_ov001_0218d0d4);
}

void func_ov001_0218d074(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x4c)), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x50)));
    func_ov001_02188e24((Unk02188950 *) (param_1), (s32) ((u32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x54))),
                        (UnkFunc *) ((int) &func_ov001_0218d0a8));
}

void func_ov001_0218d050(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x40)), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x44)));
}

void func_ov001_0218d01c(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x34)), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x38)));
    func_ov001_02188e24((Unk02188950 *) (param_1), (s32) ((u32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x3c))),
                        (UnkFunc *) ((int) &func_ov001_0218d050));
}

void func_ov001_0218cfe8(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8, (s32 (*)(Unk02188950 *)) (0));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 100)), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x68)));
    func_ov001_02188e24((Unk02188950 *) (param_1), (s32) ((u32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x54))),
                        (UnkFunc *) ((int) &func_ov001_0218d0a8));
}
