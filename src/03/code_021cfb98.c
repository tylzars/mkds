#include "03/code_021cfb98.h"
#include "03/code_021d079c.h"
#include "03/unk_021d7000.h"
#include "code_021445e0.h"

u8 *func_ov003_021cfc1c(u32 param_1) {
    return func_0214461c(&data_ov003_021da2a8->mUnk_13e0, &data_ov003_021da2a8->mUnk_1c00, param_1);
}

s32 func_ov003_021cfb98(void *param_1) {
    s32 r = func_02144c6c(&data_ov003_021da2a8->mUnk_13e0, param_1, &data_ov003_021da2a8->mUnk_1c00);
    if (r == 7) {
        if (data_ov003_021da2a4 != 0) {
            data_ov003_021da2a4(0x08000000, data_ov003_021d7a18);
        }
        return 0;
    }
    if (r == 5) {
        if (data_ov003_021da2a4 != 0) {
            data_ov003_021da2a4(0x08000000, data_ov003_021d7a48);
        }
        func_ov003_021d079c(r);
        return 0;
    }
    if (r != 0) {
        func_ov003_021d079c(r);
        return 0;
    }
    return 1;
}
