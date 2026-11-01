#include "03/code_021cfde4.h"
#include "03/code_021cfc4c.h"
#include "03/unk_021da000.h"

int func_ov003_021cfe40(u16 param_1) {
    s16 a;
    s16 i;
    u16 b;
    u16 n;
    s16 j;

    a = 0;
    b = 0;
    for (i = 0; i < 16; i++) {
        if ((param_1 & (1 << i)) != 0) {
            a = i + 1;
            b++;
        }
    }
    if (b > 1) {
        data_ov003_021da2a8->mUnk_58 = data_ov003_021da2a8->mUnk_58 * 0x10dcd + 0x3039;
        n = (b * (data_ov003_021da2a8->mUnk_58 & 0xff)) >> 8;
        for (j = 0; j < 16; j++) {
            if ((param_1 & 1) != 0) {
                if (n == 0) {
                    return (s16) (j + 1);
                }
                n--;
            }
            param_1 = param_1 >> 1;
        }
        return 0;
    }
    return a;
}

s32 func_ov003_021cfde4(void) {
    data_ov003_021da2a8->mUnk_12a4 = 0;
    data_ov003_021da2a8->mUnk_12a0 = 0;
    data_ov003_021da2a8->mUnk_48 = 0;
    data_ov003_021da2a8->mUnk_50 = 0;
    data_ov003_021da2a8->mUnk_52 = 1;
    data_ov003_021da2a8->mUnk_54 = 0;
    data_ov003_021da2a8->mUnk_00 = 0;
    data_ov003_021da2a8->mUnk_04 = 0;
    data_ov003_021da2a8->mUnk_4c = 0;
    if (func_ov003_021cfd88() != 0) {
        return 1;
    }
    return 0;
}
