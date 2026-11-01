#include "01/code_02190df8.h"

void func_ov001_02190eb0(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_070), (s32) (param_1->mUnk_0a0->mUnk_074));
    func_ov001_02188e24(param_1, (s32) ((u32) 0x3c), (UnkFunc *) ((int) &func_ov001_02190ee0));
}

void func_ov001_02190df8(Unk02188950 *param_1) {
    if (param_1->mUnk_0a8 == 1) {
        func_ov001_02187218(param_1, 8, (s32(*)(Unk02188950 *))(0));
        func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_078), (s32) (param_1->mUnk_0a0->mUnk_07c));
        func_ov001_02188c90(param_1);
        func_ov001_02188cec(param_1, 0);
        return;
    }
    func_ov001_02187218(param_1, 3, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(param_1, (s32) (param_1->mUnk_0a0->mUnk_2b4), (s32) (param_1->mUnk_0a0->mUnk_2b8),
                        (UnkFunc *) &func_ov001_02190df8);
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
    func_ov001_02192358(param_1);
    func_ov001_021875c0(param_1, (u32) 0, (u32) (((u32) 0x000044cdu)), (u32) (((u32) 0x00002000u)),
                        (u32) (((u32) 0x0000042du)), (u32) 0);
    func_ov001_021875c0(param_1, (u32) 0, (u32) (((u32) 0x000044cdu)), (u32) (((u32) 0x00002000u)),
                        (u32) (((u32) 0x0000042eu)), (u32) 0);
}
