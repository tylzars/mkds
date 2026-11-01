#include "01/code_021834c4.h"

u32 func_ov001_021835e0(Unk02188950 *param_1) {
    int v1;
    if ((param_1->mUnk_000.mUnk_00 == ((u32) 0x000001f6u)) &&
        (v1 = func_0209b620((int) (*(u32 *) ((int) param_1 + 0x304))), v1 == 2)) {
        func_ov001_02187af4(param_1);
        func_ov001_021872e0(param_1, (int) (((u32) 0x00001000u)), 0, 0, 0, (int) ((u16) (((u32) 0x00000666u))),
                            (int) (((u32) 0xfffff000u)), (int) (((u32) 0x00000428u)), (u32) 0);
        func_ov001_021872e0(param_1, (int) (((u32) 0x00001000u)), 0, 0, 0, (int) ((u16) (((u32) 0x00000666u))),
                            (int) (((u32) 0xfffff000u)), (int) (((u32) 0x00000429u)), (u32) 0);
        func_ov001_021872e0(param_1, (int) (((u32) 0x00001000u)), 0, 0, 0, (int) ((u16) (((u32) 0x00000800u))),
                            (int) (((u32) 0xfffff000u)), (int) (((u32) 0x0000042au)), (u32) 0);
        func_020d2774(&param_1->mUnk_000, (u32) (((u32) 0x00000240u)));
    }
    return 0;
}

void func_ov001_021835b8(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8, (s32(*)(Unk02188950 *))((int) &func_ov001_02183780));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 100)),
                        (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x68)));
}

void func_ov001_0218355c(u16 *param_1) {
    func_ov001_02187218((Unk02188950 *) ((int) (u32) param_1), 8, (s32(*)(Unk02188950 *))((int) &func_ov001_02183690));
    if (*param_1 == ((u32) 0x000001f6u)) {
        func_ov001_02188d64((Unk02188950 *) ((int) (u32) param_1), (s32) (*(u32 *) (*(int *) (param_1 + 0x50) + 0x58)),
                            (s32) (*(u32 *) (*(int *) (param_1 + 0x50) + 0x5c)));
        func_ov001_02188e24((Unk02188950 *) ((int) ((int) (u32) param_1)),
                            (s32) ((u32) (*(u32 *) (*(int *) (param_1 + 0x50) + 0x60))),
                            (UnkFunc *) ((int) &func_ov001_021835b8));
        return;
    }
    func_ov001_02188d30((Unk02188950 *) ((int) (u32) param_1), (s32) (*(u32 *) (*(int *) (param_1 + 0x50) + 0x58)),
                        (s32) (*(u32 *) (*(int *) (param_1 + 0x50) + 0x5c)), (UnkFunc *) &func_ov001_021835b8);
}

void func_ov001_02183524(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8, (s32(*)(Unk02188950 *))((int) &func_ov001_021835e0));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x4c)),
                        (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x50)));
    func_ov001_02188e24((Unk02188950 *) (param_1), (s32) ((u32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x54))),
                        (UnkFunc *) ((int) &func_ov001_0218355c));
}

void func_ov001_021834fc(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8, (s32(*)(Unk02188950 *))((int) &func_ov001_021835e0));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x40)),
                        (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x44)));
}

void func_ov001_021834c4(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 8, (s32(*)(Unk02188950 *))((int) &func_ov001_021835e0));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x34)),
                        (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x38)));
    func_ov001_02188e24((Unk02188950 *) (param_1), (s32) ((u32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x3c))),
                        (UnkFunc *) ((int) &func_ov001_021834fc));
}
