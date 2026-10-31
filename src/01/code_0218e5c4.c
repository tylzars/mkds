#include "01/code_0218e5c4.h"

#include "01/code_0218e690.h"
#include "01/code_02187098.h"
#include "01/code_02188000.h"
#include "01/code_02188e24.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_0210b708.h"
#include "Main/Unknown/unk_0217d000.h"
#include "01/code_0218f000.h"

s32 func_ov001_0218e650(Unk02188950 *param_1) {
    if (param_1->mUnk_0b0 == 50) {
        Unk021a7c08 local = {0x22f, 0, 0xe, 0};
        local.mUnk_04 = &param_1->mUnk_000.mUnk_04;
        local.mUnk_0c = func_020d4ef4(&param_1->mUnk_000.mUnk_04);
        func_0210b734(&local, func_02108e7c());
    }
    return 0;
}

void func_ov001_0218e5c4(Unk02188950 *param_1) {
    param_1->mUnk_000.mUnk_04.y += param_1->mUnk_0a0->mUnk_080;
    param_1->mUnk_168 = param_1->mUnk_16c = 0x1f000;
    param_1->mUnk_170 = 0;
    func_ov001_02187218(param_1, 8, func_ov001_0218e650);
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_070), (s32) (param_1->mUnk_0a0->mUnk_074));
    func_ov001_02188e24(param_1, 0x3c, func_ov001_0218e690);
    if (data_0217d20c != 7) {
        data_0217d21c = data_0217d20c;
    }
    data_0217d20c = 7;
    param_1->mUnk_000.mUnk_02 &= ~1;
}
