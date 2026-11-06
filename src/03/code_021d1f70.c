#include "03/code_021d1f70.h"
#include "registers.h"

#include "03/code_021d1da8.h"
#include "03/code_021d27d8.h"
#include "03/unk_021da000.h"
#include "code_0214a390.h"

void func_ov003_021d1f98(void) {
    data_ov003_021da2c0 = func_ov003_021d283c(0x18, 4);
    G2x_SetBlendBrightness_(&reg_G2_BLDCNT, 0x3f, 0x10);
    G2x_SetBlendBrightness_(&reg_G2S_DB_BLDCNT, 0x3f, 0x10);
}

void func_ov003_021d1f88(void) {
    func_ov003_021d2808(&data_ov003_021da2c0);
}

u8 func_ov003_021d1f70(int a) {
    Unk021d1da8 *v1;
    if (a == 1) {
        v1 = data_ov003_021da2c0;
    } else {
        v1 = data_ov003_021da2c0 + 1;
    }
    return v1->mEnabled;
}
