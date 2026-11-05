#include "01/code_0218dce4.h"

#include "01/code_02185ef4.h"
#include "01/code_02188158.h"
#include "01/code_02188218.h"
#include "01/code_02188e24.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020d2000.h"
#include "01/code_02188000.h"
#include "01/code_0218d000.h"
#include "01/code_0218e000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_0209bef0.h"

void func_ov001_0218dd9c(Unk02188950 *a) {
    a->mUnk_2e0 = 0;
    func_ov001_021881f4(a, (UnkFunc *) func_ov001_0218dd9c);
}

void func_ov001_0218dd50(Unk02188950 *a) {
    if (func_ov001_02188220(a) >= 2) {
        StartMapObjectSound(&a->mUnk_000, (u32) (0x248));
    } else if (func_ov001_02188220(a) >= 1) {
        StartMapObjectSound(&a->mUnk_000, (u32) (0x249));
    } else {
        StartMapObjectSound(&a->mUnk_000, (u32) (0x24a));
    }
}

void func_ov001_0218dd04(Unk02188950 *a) {
    if (func_ov001_02188220(a) >= 2) {
        StartMapObjectSound(&a->mUnk_000, (u32) (0x248));
    } else if (func_ov001_02188220(a) >= 1) {
        StartMapObjectSound(&a->mUnk_000, (u32) (0x249));
    } else {
        StartMapObjectSound(&a->mUnk_000, (u32) (0x24a));
    }
}

void func_ov001_0218dce4(Unk02188950 *a) {
    func_ov001_02188e48(a, 0xc, func_ov001_0218dd50, 0x20, func_ov001_0218dd04);
}
