#include "03/code_021bb03c.h"

u32 func_ov003_021bb070(u32 *param_1) {
    int v1;
    *param_1 = *(u32 *) &data_ov003_021d8c08;
    if ((*(int *) &data_ov003_021d68b8) == -1) {
        param_1[1] = 0xffffffff;
    } else {
        v1 = func_ov003_021bb354();
        param_1[1] = (*(int *) &data_ov003_021d68b8) - v1;
    }
    param_1[2] = *(u32 *) &data_ov003_021d8c48;
    return 1;
}

u32 func_ov003_021bb058(Unk021d8dc8 *param_1) {
    func_02134eb8((u32 *) ((u32 *) (u32) (param_1)), (const void *) &data_ov003_021d8dc8, 0xe8);
    return 1;
}

void func_ov003_021bb03c(void) {
    u8 v1[8];
    func_ov003_021bb070((u32 *) ((u32 *) (void *) (v1)));
    (*(UnkFunc *) (u32) data_ov003_021d8c4c)(v1);
    return;
}
