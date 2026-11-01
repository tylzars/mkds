#include "01/code_02190ee0.h"
#include "01/code_02187af4.h"
#include "01/code_02187098.h"
#include "01/code_021874c4.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_0210b708.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"

void func_ov001_02190ee0(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02187af4(param_1);
    func_ov001_021875c0(param_1, (u32) 0, (u32) 0x1000, (u32) 0xffffdccd, (u32) 0x3ef, (u32) 0);
    func_ov001_021875c0(param_1, (u32) 0, (u32) 0x1000, (u32) 0xffffdccd, (u32) 0x3ee, (u32) 0);
    func_ov001_021875c0(param_1, (u32) 0, (u32) 0x1000, (u32) 0xffffdccd, (u32) 0x3f0, (u32) 0);
    func_ov001_021875c0(param_1, (u32) 0, (u32) 0x1000, (u32) 0xffffdccd, (u32) 0x3f1, (u32) 0);
    func_ov001_021875c0(param_1, (u32) 0, (u32) 0x1000, (u32) 0xffffdccd, (u32) 0x3f2, (u32) 0);
    {
        Unk02190ee0 local = data_ov001_021a7de8;

        local.mUnk_04 = &param_1->mUnk_000.mUnk_04;
        local.mUnk_0c = func_020d4ef4(&param_1->mUnk_000.mUnk_04);
        func_0210b734(&local, (u32) (func_02108e7c()));
    }
    param_1->mUnk_000.mUnk_02 |= data_ov001_021a65c8;
    param_1->mUnk_000.mUnk_02 |= data_ov001_021a65cc;
    param_1->mUnk_000.mUnk_02 |= data_ov001_021a65d0;
}
