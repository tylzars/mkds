#include "03/code_021cfed8.h"
#include "03/code_021cfde4.h"

int func_ov003_021cff38(Unk021425e8Func param_1, u16 param_2) {
    return func_0214544c(param_1, (u16) (3), (u16) (0x11), (u16) (param_2), (u16) (0x1e));
}

u16 func_ov003_021cfed8(void) {
    int *v1;
    u16 v2;
    if (data_ov003_021da2a8->mUnk_40 != 7) {
        func_0200fd1c();
    }
    func_ov003_021d07b0(1);
    v2 = func_ov003_021cfe40((u32) (data_ov003_021da2a8->mUnk_60));
    v1 = (int *) &data_ov003_021da2a8;
    data_ov003_021da2a8->mUnk_5c = v2;
    if ((UnkFunc *) (*(u32 *) &data_ov003_021da2a4) != (UnkFunc *) 0x0) {
        (*(UnkFunc *) (*(u32 *) &data_ov003_021da2a4))(((u32) 0x08000000u), (u32) &data_ov003_021d7ac8,
                                                       *(u16 *) (*v1 + 0x5c));
    }
    return data_ov003_021da2a8->mUnk_5c;
}
