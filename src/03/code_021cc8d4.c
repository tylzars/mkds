#include "03/code_021cc8d4.h"

void func_ov003_021cc900(u32 param_1) {
    *(u32 *) &data_ov003_021da260 = param_1;
    func_ov003_021d3544((u32) 1, &func_ov003_021cc8d4, 0, (u32) 0x78);
}

void func_ov003_021cc8d4(u32 param_1) {
    func_0214cffc((const void *) ((*(u32 *) &data_ov003_021da260)), (void *) (((u32) 0x05000000u)),
                  (u32) (((u32) 0x00000200u)));
    func_ov003_021d34c8(1, param_1);
}
