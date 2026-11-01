#include "00/code_021a4818.h"
#include "00/code_0218e8c4.h"

void func_ov000_021a4818(Unk021a4a08 *param_1) {
    int v1;
    if (param_1 == 0) {
        param_1 = data_ov000_021b426c;
    }
    if (param_1->mUnk_0bc != 0) {
        v1 = func_ov000_0218e8c4();
        if ((u32) (v1 - param_1->mUnk_0ac) < ((u32) 0x00002710u)) {
            param_1->mUnk_0b4 = 1;
            return;
        }
        func_ov000_021a3a18((Unk021a3a18 *) param_1, 1);
        param_1->mUnk_0b4 = 0;
    }
    return;
}
