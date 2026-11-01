#include "00/code_021a2e7c.h"

void func_ov000_021a2e7c(Unk0219887c *param_1, u32 param_2, int param_3) {
    int v1;
    u32 v2;
    u64 v3;
    v1 = func_ov000_0219b9c4(param_1);
    v2 = (int) data_ov000_021b5dd0 + v1 * 0x30;
    if ((*(int *) (v2 + 4) != 0) && (*(int *) (v2 + 8) >= param_3)) {
        func_0214d1fc((const void *) ((u16 *) param_2), (void *) ((u32 *) (u32) (*(int *) (v2 + 4))), (u32) param_3);
        if (*(UnkFunc **) ((int) data_ov000_021b5dd0 + 0x604) != (UnkFunc *) 0x0) {
            (**(UnkFunc **) ((int) data_ov000_021b5dd0 + 0x604))(v1, *(u32 *) (v2 + 4), param_3);
        }
        if ((*(int *) ((int) data_ov000_021b5dd0 + 0x608) != 0) && (*(int *) (v2 + 0x2c) != 0)) {
            v3 = func_0200f5ac();
            *(u64 *) (v2 + 0x24) = v3;
        }
    }
}
