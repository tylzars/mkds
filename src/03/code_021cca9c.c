#include "03/code_021cca9c.h"
#include "03/code_021cca74.h"
#include "03/unk_021d6000.h"
#include "03/unk_021da000.h"

void func_ov003_021cca9c(s32 param_1, u16 *param_2) {
    param_2[0] = data_ov003_021da268->mX;
    param_2[2] = param_2[0] + 0xc;
    switch (param_1) {
        case 1:
            param_2[1] = data_ov003_021da268->mY + data_ov003_021da268->mOffset;
            param_2[3] = param_2[1] + data_ov003_021d6630[data_ov003_021da268->mUnk_1b];
            break;
        case 2:
            param_2[1] = data_ov003_021da268->mY - 0xd;
            param_2[3] = data_ov003_021da268->mY;
            break;
        case 3:
            param_2[1] = data_ov003_021da268->mY + data_ov003_021da268->mUnk_19;
            param_2[3] = param_2[1] + 0xd;
            break;
        case 4:
            param_2[1] = data_ov003_021da268->mY;
            param_2[3] = param_2[1] + data_ov003_021da268->mUnk_19;
            break;
    }
}
