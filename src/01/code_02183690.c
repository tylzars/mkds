#include "01/code_02183690.h"
#include "01/unk_021a6000.h"

void func_ov001_02183848(void) {
    func_ov001_021882b8();
}

int func_ov001_02183780(Unk02188950 *param_1) {
    if (param_1->mUnk_000.mUnk_00 == 0x1f6) {
        if (func_0209b620((int)param_1->mUnk_304) == 2 || func_0209b620((int)param_1->mUnk_304) == 3) {
            func_ov001_02187af4(param_1);
            func_ov001_021872e0(param_1, 0x1000, 0, 0, 0, 0x666, -0x1000, 0x428, 0);
            func_ov001_021872e0(param_1, 0x1000, 0, 0, 0, 0x666, -0x1000, 0x429, 0);
            func_ov001_021872e0(param_1, 0x1000, 0, 0, 0, 0x800, -0x1000, 0x42a, 0);
            func_020d2774(&param_1->mUnk_000, (u32) (0x240));
        }
    }
    if (func_02061fec() == 1) {
        func_ov001_02183b9c(param_1);
    }
    return 0;
}

int func_ov001_02183690(Unk02188950 *param_1) {
    if (param_1->mUnk_000.mUnk_00 == 0x1f6) {
        if (func_0209b620((int)param_1->mUnk_304) == 2) {
            func_ov001_02187af4(param_1);
            func_ov001_021872e0(param_1, 0x1000, 0, 0, 0, 0x666, -0x1000, 0x428, 0);
            func_ov001_021872e0(param_1, 0x1000, 0, 0, 0, 0x666, -0x1000, 0x429, 0);
            func_ov001_021872e0(param_1, 0x1000, 0, 0, 0, 0x800, -0x1000, 0x42a, 0);
            func_020d2774(&param_1->mUnk_000, (u32) (0x240));
        }
    } else if (param_1->mUnk_000.mUnk_00 == 0x1f5) {
        if (func_0209b620((int)param_1->mUnk_304) == 0x2b || func_0209b620((int)param_1->mUnk_304) == 0x48) {
            func_ov001_02187af4(param_1);
            func_ov001_02187518(param_1, 0, 0, 0, 0x410, 0);
        }
    }
    return 0;
}
