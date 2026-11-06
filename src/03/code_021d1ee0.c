#include "03/code_021d1dd0.h"
#include "registers.h"
#include "03/code_021d1da8.h"
#include "03/code_021d3488.h"
#include "code_02147cd8.h"
#include "code_0214a348.h"
#include "code_0214a390.h"

u32 func_ov003_021d1ee0(s32 param_1, s32 param_2, u32 param_3, u16 param_4) {
    s8 a[4] = {-0x10, 0x00, 0x10, 0x00};
    Unk021d1da8 *b;

    if (param_2 == 1) {
        b = data_ov003_021da2c0;
    } else {
        b = data_ov003_021da2c0 + 1;
    }
    if (b->mEnabled != 0) {
        return 0;
    }
    if (param_2 == 1) {
        G2x_SetBlendBrightness_(&reg_G2S_DB_BLDCNT, param_3, a[param_1]);
    } else {
        G2x_SetBlendBrightness_(&reg_G2_BLDCNT, param_3, a[param_1]);
    }
    b->mUnk_00 = func_ov003_021d3544(1, func_ov003_021d1e14, b, 200);
    b->mFrames = 0;
    b->mUnk_08 = param_1;
    b->mFrameCount = param_4;
    b->mEnabled = 1;
    return 1;
}
