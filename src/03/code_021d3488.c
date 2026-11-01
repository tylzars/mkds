#include "03/code_021d3488.h"
#include "03/code_021d27d8.h"

void func_ov003_021d3488(int param_1, int param_2) {
    if (*(u8 *) (param_2 + 0x11) != 0) {
        func_ov003_021d2808((int *) (u32) (param_2 + 0xc));
    }
    func_ov003_021d2e90((u32) ((int *) (u32) param_2));
    func_ov003_021d1d0c((Unk021d1d88 *) (*(u32 *) ((int) data_ov003_021da32c + param_1 * 0x3c)), (void *) param_2);
}
