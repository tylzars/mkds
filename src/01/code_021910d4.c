#include "01/code_021910d4.h"
#include "01/code_021910fc.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"

s32 func_ov001_021910d4(Unk02188950 *param_1) {
    if (param_1->mUnk_2c8 & 0x1e34ef) {
        param_1->mUnk_158 = (s32(*)(Unk02188950 *)) func_ov001_021910fc;
    }
    return 0;
}
