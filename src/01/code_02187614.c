#include "01/code_02187614.h"
#include "01/code_02187684.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_0208b6b0.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_02021000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020e6000.h"

void func_ov001_02187614(Unk02188950 *param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, u32 param_6,
                         s32 param_7) {
    Vec3 pos;

    param_1->mUnk_0bc[param_2].mUnk_04 = param_7;
    if ((param_1->mUnk_000.mUnk_02 & 0x400) != 0) {
        param_3 = -param_3;
    }
    param_1->mUnk_0bc[param_2].mUnk_08.x = param_3 << 4;
    param_1->mUnk_0bc[param_2].mUnk_08.y = param_4 << 4;
    param_1->mUnk_0bc[param_2].mUnk_08.z = param_5 << 4;
    func_ov001_02187684(param_1, param_2, &pos);
    if (param_6 != 0) {
        if (param_1->mUnk_0bc[param_2].mUnk_14 != 0) {
            func_0208b6b0(&param_1->mUnk_0bc[param_2].mUnk_14);
        }
        param_1->mUnk_0bc[param_2].mUnk_14 = func_0208b7bc(param_6, &pos);
    }
}
