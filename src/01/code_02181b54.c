#include "01/code_02181b54.h"

void func_ov001_02181b8c(Unk02188950 *a) {
    u8 n;
    u16 k;

    n = data_021759c0->mUnk_3d0;
    k = data_ov001_021a9b90->mUnk_44 + n;
    data_ov001_021a9b90->mUnk_48[k - n] = a;
    func_020a1728(k);
    data_ov001_021a9b90->mUnk_44++;
}

Unk02188950 *func_ov001_02181b68(int param_1) {
    return data_ov001_021a9b90->mUnk_48[param_1 - data_021759c0->mUnk_3d0];
}

u8 func_ov001_02181b54(void) {
    return data_021759c0->mUnk_3d0;
}
