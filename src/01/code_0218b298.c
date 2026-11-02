#include "01/code_0218b298.h"

#include "01/unk_021a6000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0209bef0.h"

u16 func_ov001_0218b2d4(Unk02188950 *param_1) {
    return func_ov001_02188220(param_1);
}

void func_ov001_0218b2b8(Unk02188950 *param_1) {
    param_1->mUnk_2d8 = 0xb;
    param_1->mUnk_000.mUnk_78 |= data_ov001_021a6598;
}

void func_ov001_0218b2a8(Unk02188950 *param_1) {
    func_020d2774(&param_1->mUnk_000, (u32) (0x237));
}

void func_ov001_0218b298(Unk02188950 *param_1) {
    func_020d2774(&param_1->mUnk_000, (u32) (0x237));
}
