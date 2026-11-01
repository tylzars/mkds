#include "03/code_021cd4ac.h"
#include "03/code_021cd5e0.h"

u32 func_ov003_021cd4dc(void) {
    return (u32) data_ov003_021da270;
}

void func_ov003_021cd4ac(int param_1) {
    Unk021cd5e0_entry *v1;
    v1 = &data_ov003_021da270->mUnk_000[param_1].mUnk_00;
    func_0214d168(v1, (u8) (0), 0xef);
    v1->mUnk_e7 = 0xff;
    func_ov003_021cd338((u32) (param_1));
    return;
}
