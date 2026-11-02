#include "01/code_02187bfc.h"

#include "Main/Unknown/code_0208b6b0.h"
#include "01/unk_021a7000.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_02042000.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_020da000.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/code_020fd000.h"
#include "Main/Unknown/code_02147000.h"

void func_ov001_02187bfc(Unk02188950 *param_1, Vec3 *param_2, s32 param_3) {
    Vec3 zero;
    s32 *z;

    if (param_1->mUnk_300 != 0) {
        if (((Unk02188950_300 *) param_1->mUnk_300)->mUnk_54 < 0x64000) {
            func_020fd494(&param_1->mUnk_300);
        } else if (param_2 != 0) {
            func_020fd540(&param_1->mUnk_300, param_2, param_3);
        } else {
            z = (s32 *) &zero;
            z[0] = 0;
            z[1] = 0;
            z[2] = 0;
            func_020fd540(&param_1->mUnk_300, &zero, param_3);
        }
    }
}
