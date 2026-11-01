#include "01/code_0218dce4.h"
#include "01/code_0218dde8.h"
#include "01/code_02187098.h"
#include "01/code_02188158.h"
#include "01/code_02188218.h"
#include "01/code_02188e24.h"
#include "01/code_0218de50.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020d2000.h"
#include "01/code_02188000.h"
#include "01/code_0218d000.h"
#include "01/code_0218e000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_0209bef0.h"

void *func_ov001_0218ddcc(void) {
    return (void *) func_0209bf1c(func_ov001_0218de50, func_ov001_0218de14, func_ov001_02187098);
}

void *func_ov001_0218ddb4(void) {
    return (void *) func_0209bf48(func_ov001_0218e208, func_ov001_0218df20, 0);
}

void func_ov001_0218dd9c(Unk02188950 *param_1) {
    param_1->mUnk_2e0 = 0;
    func_ov001_021881f4(param_1, (UnkFunc *) func_ov001_0218dd9c);
}

void func_ov001_0218dd50(Unk02188950 *param_1) {
    if (func_ov001_02188220(param_1) >= 2) {
        func_020d2774(&param_1->mUnk_000, (u32) (0x248));
    } else if (func_ov001_02188220(param_1) >= 1) {
        func_020d2774(&param_1->mUnk_000, (u32) (0x249));
    } else {
        func_020d2774(&param_1->mUnk_000, (u32) (0x24a));
    }
}

void func_ov001_0218dd04(Unk02188950 *param_1) {
    if (func_ov001_02188220(param_1) >= 2) {
        func_020d2774(&param_1->mUnk_000, (u32) (0x248));
    } else if (func_ov001_02188220(param_1) >= 1) {
        func_020d2774(&param_1->mUnk_000, (u32) (0x249));
    } else {
        func_020d2774(&param_1->mUnk_000, (u32) (0x24a));
    }
}

void func_ov001_0218dce4(Unk02188950 *param_1) {
    func_ov001_02188e48(param_1, 0xc, func_ov001_0218dd50, 0x20, func_ov001_0218dd04);
}
