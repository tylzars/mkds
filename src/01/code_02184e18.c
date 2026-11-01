#include "01/code_02184e18.h"

void func_ov001_02184f40(Unk02188950 *param_1) {
    func_020d2774(&param_1->mUnk_000, (u32) (((u32) 0x0000020fu)));
    func_ov001_02187af4(param_1);
    func_ov001_02187518(param_1, (u32) (((u32) 0x000008cdu)), (u32) (0), (u32) (((u32) 0x0000119au)),
                        (u32) (((u32) 0x00000413u)), (u32) (0));
    return;
}

void func_ov001_02184f04(Unk02188950 *param_1) {
    func_020d2774(&param_1->mUnk_000, (u32) (((u32) 0x0000020fu)));
    func_ov001_02187af4(param_1);
    func_ov001_02187518(param_1, (u32) (((u32) 0xfffff733u)), (u32) (0), (u32) (((u32) 0x0000119au)),
                        (u32) (((u32) 0x00000413u)), (u32) (0));
    return;
}

void func_ov001_02184ec8(Unk02188950 *param_1) {
    func_020d2774(&param_1->mUnk_000, (u32) (((u32) 0x0000020fu)));
    func_ov001_02187af4(param_1);
    func_ov001_02187518(param_1, (u32) (((u32) 0xfffff000u)), (u32) (0), (u32) (((u32) 0x00001333u)),
                        (u32) (((u32) 0x00000444u)), (u32) (0));
    return;
}

void func_ov001_02184e8c(Unk02188950 *param_1) {
    func_020d2774(&param_1->mUnk_000, (u32) (((u32) 0x0000020fu)));
    func_ov001_02187af4(param_1);
    func_ov001_02187518(param_1, (u32) (((u32) 0x00001000u)), (u32) (0), (u32) (((u32) 0x00001333u)),
                        (u32) (((u32) 0x00000444u)), (u32) (0));
    return;
}

void func_ov001_02184e6c(Unk02188950 *param_1) {
    func_ov001_02188e48(param_1, (s32) ((u32) (0x19)), func_ov001_02184f8c, (s32) ((u32) (0x36)), func_ov001_02184f7c);
    return;
}

void func_ov001_02184e18(u16 *param_1) {
    if (*param_1 == ((u32) 0x000001f5u)) {
        func_ov001_02188e48((Unk02188950 *) ((int) ((int) (u32) (param_1))), (s32) ((u32) (0x19)), func_ov001_02184f40,
                            (s32) ((u32) (0x36)), func_ov001_02184f04);
        return;
    }
    if (*param_1 == ((u32) 0x000001f6u)) {
        func_ov001_02188e48((Unk02188950 *) ((int) ((int) (u32) (param_1))), (s32) ((u32) (9)), func_ov001_02184ec8,
                            (s32) ((u32) (0x26)), func_ov001_02184e8c);
    }
    return;
}
