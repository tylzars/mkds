#include "01/code_0218a30c.h"
#include "01/code_02187098.h"
#include "01/code_021874c4.h"
#include "01/code_02187000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_0210b708.h"
#include "01/code_0218a000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_020fd000.h"

void func_ov001_0218a30c(Unk02188950 *param_1) {
    Unk021a7c08 local;

    func_ov001_02187218(param_1, 8, 0);
    func_ov001_02187af4(param_1);
    func_ov001_021875c0(param_1, 0, 0x2000, 0, 0x421, 0);
    func_ov001_021875c0(param_1, 0, 0x2000, 0, 0x40c, 0);
    func_ov001_021875c0(param_1, 0, 0x2000, 0, 0x40e, 0);
    func_ov001_021875c0(param_1, 0, 0x2000, 0, 0x40d, 0);
    func_ov001_021875c0(param_1, 0, 0x2000, 0, 0x40f, 0);
    local = data_ov001_021a7ad0;
    local.mUnk_04 = &param_1->mUnk_000.mUnk_04;
    local.mUnk_0c = func_020d4ef4(&param_1->mUnk_000.mUnk_04);
    func_0210b734(&local, func_02108e7c());
    param_1->mUnk_000.mUnk_02 |= data_ov001_021a6588;
    param_1->mUnk_000.mUnk_02 |= data_ov001_021a658c;
    param_1->mUnk_000.mUnk_02 |= data_ov001_021a6590;
}
