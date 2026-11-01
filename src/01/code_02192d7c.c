#include "01/code_02192d7c.h"
#include "01/code_02193000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020f9c6c.h"

void func_ov001_02192e10(Unk02188950 *param_1) {
    s32 m[9];
    func_020d2450(param_1);
    param_1->mUnk_000.mUnk_7e =
        (u16) (((s64) param_1->mUnk_000.mUnk_9c->mUnk_0c.y * 0xb60b60b60bLL + 0x80000000000LL) >> 44);
    func_02146d44(m, data_0215d4b4[(param_1->mUnk_000.mUnk_7e >> 4) * 2],
                  data_0215d4b4[(param_1->mUnk_000.mUnk_7e >> 4) * 2 + 1]);
    func_02146dfc(m, &param_1->mUnk_000.mUnk_28.mUnk_00.x, &param_1->mUnk_000.mUnk_28.mUnk_00.x);
}

void func_ov001_02192dd4(Unk0219b478 *param_1) {
    data_ov001_021a9bcc = func_ov001_0219b478(param_1, "StopSign.nsbmd");
    func_0209b940(data_ov001_021a9bcc, 0x3f);
    func_0209ba08(data_ov001_021a9bcc, 2);
    func_020849a0(data_ov001_021a9bcc->mUnk_10, 0x294a);
}

void func_ov001_02192d7c(void *param_1, Unk02192d7c *param_2) {
    s32 v = 0x1e;
    func_01ff9048(0x14, &v, 1);
    param_2->mUnk_4c = param_2->mUnk_04 >> 4;
    param_2->mUnk_50 = param_2->mUnk_08 >> 4;
    param_2->mUnk_54 = param_2->mUnk_0c >> 4;
    func_01ff9048(0x19, param_2->mUnk_28, 0xc);
    func_01ff9048(0x1b, param_2->mUnk_1c, 3);
    func_0209bb2c(param_1, data_ov001_021a9bcc, param_2);
}
