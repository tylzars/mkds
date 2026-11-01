#include "01/code_0218fef8.h"

void func_ov001_0219006c(u32 param_1) {
    func_ov001_021900ac((Unk02188950 *) (param_1));
    func_ov001_02188260((Unk02188950 *) (param_1));
    return;
}

void func_ov001_02190030(u32 param_1) {
    func_ov001_02187518((Unk02188950 *) (param_1), (u32) (((u32) 0x00002ccdu)), (u32) (0), (u32) (0),
                        (u32) (((u32) 0x00000411u)), (u32) (0));
    func_ov001_02187518((Unk02188950 *) (param_1), (u32) (((u32) 0x00002ccdu)), (u32) (0), (u32) (0),
                        (u32) (((u32) 0x00000412u)), (u32) (0));
    return;
}

void func_ov001_0218ffd4(int param_1) {
    func_ov001_02187218((Unk02188950 *) (param_1), 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64((Unk02188950 *) (param_1), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 100)),
                        (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x68)));
    func_ov001_021875c0((Unk02188950 *) (param_1), (u32) (0), (u32) (((u32) 0x000044cdu)), (u32) (((u32) 0x00000400u)),
                        (u32) (((u32) 0x0000042du)), (u32) (0));
    func_ov001_021875c0((Unk02188950 *) (param_1), (u32) (0), (u32) (((u32) 0x000044cdu)), (u32) (((u32) 0x00000400u)),
                        (u32) (((u32) 0x0000042eu)), (u32) (0));
    return;
}

void func_ov001_0218ff98(int param_1) {
    func_ov001_02187218((Unk02188950 *) (param_1), 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30((Unk02188950 *) (param_1), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x58)),
                        (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x5c)), (UnkFunc *) &func_ov001_0218ffd4);
    func_ov001_021923e0((int) (param_1));
    func_020d2774((Unk020e71a0 *) ((int) (param_1)), (u32) (((u32) 0x0000021bu)));
    return;
}

void func_ov001_0218ff64(int param_1) {
    func_ov001_02187218((Unk02188950 *) (param_1), 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64((Unk02188950 *) (param_1), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x4c)),
                        (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x50)));
    func_ov001_02188e24((Unk02188950 *) ((int) (param_1)), (s32) ((u32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x54))),
                        (UnkFunc *) ((int) &func_ov001_0218ff98));
    return;
}

void func_ov001_0218ff34(int param_1) {
    func_ov001_02187218((Unk02188950 *) (param_1), 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64((Unk02188950 *) (param_1), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x40)),
                        (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x44)));
    func_ov001_02188db8((Unk02188950 *) ((int) (param_1)), (UnkFunc *) ((int) &func_ov001_02190030));
    return;
}

void func_ov001_0218fef8(int param_1) {
    func_ov001_02187218((Unk02188950 *) (param_1), 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64((Unk02188950 *) (param_1), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x34)),
                        (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x38)));
    func_ov001_0218720c((Unk02188950 *) (param_1));
    func_ov001_02188e24((Unk02188950 *) ((int) (param_1)), (s32) ((u32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x3c))),
                        (UnkFunc *) ((int) &func_ov001_0218ff34));
    return;
}
