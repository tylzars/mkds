#include "03/code_021cd4ac.h"

u32 func_ov003_021cd4dc(void) {
    return (u32) data_ov003_021da270;
}

void func_ov003_021cd4ac(int param_1) {
    int v1;
    v1 = (int) data_ov003_021da270 + param_1 * 0x100;
    func_0214d168((void *) ((u32 *) (u32) (v1)), (u8) (0), 0xef);
    *(u8 *) (v1 + 0xe7) = 0xff;
    func_ov003_021cd338((u32) (param_1));
    return;
}
