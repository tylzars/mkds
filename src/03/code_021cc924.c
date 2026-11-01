#include "03/code_021cc924.h"
#include "03/code_021d3544.h"
#include "03/code_021d34c8.h"
#include "03/unk_021da000.h"
#include "code_0214cfe4.h"

void func_ov003_021cc948(u8 *param_1, u32 param_2, u32 param_3) {
    ((u8 **) data_ov003_021da260)[0] = param_1 + (param_2 << 5);
    ((u8 **) data_ov003_021da260)[1] = (u8 *) 0x5000000 + (param_3 << 5);
    func_ov003_021d3544(1, func_ov003_021cc924, 0, 0x78);
}

void func_ov003_021cc924(u32 param_1) {
    func_0214cffc(((const void **) data_ov003_021da260)[0], ((void **) data_ov003_021da260)[1], 0x20);
    func_ov003_021d34c8(1, param_1);
}
