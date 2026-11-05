#include "01/code_0218b298.h"
#include "01/code_02188218.h"

#include "01/unk_021a6000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d275c.h"

u16 func_ov001_0218b2d4(Unk02188950 *a) {
    return func_ov001_02188220(a);
}

void func_ov001_0218b2b8(Unk02188950 *a) {
    a->mUnk_2d8 = 0xb;
    a->mUnk_000.mUnk_78 |= data_ov001_021a6598;
}

void func_ov001_0218b2a8(Unk02188950 *a) {
    StartMapObjectSound(&a->mUnk_000, (u32) (0x237));
}

void func_ov001_0218b298(Unk02188950 *a) {
    StartMapObjectSound(&a->mUnk_000, (u32) (0x237));
}
