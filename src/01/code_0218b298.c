#include "01/code_0218b298.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0209bef0.h"

void *func_ov001_0218b2f4(void) {
    return (void *) func_0209bf1c(func_ov001_0218b35c, func_ov001_0218b33c, func_ov001_02187098);
}

void *func_ov001_0218b2dc(void) {
    return (void *) func_0209bf48(func_ov001_0218b5d8, func_ov001_0218b404, 0);
}

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
