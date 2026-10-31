#include "Main/Unknown/code_02079014.h"
#include "code_02012b30.h"

#pragma thumb on

void func_02079078(void *param_1, void *param_2, void *param_3, Unk020136f0 *param_4, Unk020136f0 *param_5,
                   void *param_6) {
    u32 v2;
    u32 v3;
    void *v1;
    v2 = (u32) func_02084d3c(param_2, param_4, param_5);
    func_020849c0(param_2, 3);
    func_0207a14c((Unk0201290c *) v2, (u32) 1);
    func_0208823c(0, param_3, param_2, 1, param_1, 0);
    v1 = func_02013a4c(func_02013a30(param_6), 0);
    v3 = func_0207b8dc(2);
    func_020881b0(param_3, 0, v1, v3, param_1);
    func_02087f84(param_3, 0);
}

void func_02079038(void *param_1, Unk020136f0 *param_2, Unk020136f0 *param_3) {
    int v1;
    u32 v2;
    v1 = (int) func_02084d3c(param_1, param_2, param_3);
    func_020849c0(param_1, 3);
    func_0207a14c((Unk0201290c *) v1, (u32) 1);
    v2 = func_02013754((const void *) (v1 + *(int *) (v1 + 8) + 4), (const u32 *) (&data_02155098));
    func_02013468((Unk0201290c *) v1, v2, (u32) 0);
}

void func_02079014(void *param_1, Unk020136f0 *param_2, Unk020136f0 *param_3) {
    u32 v1;
    v1 = (u32) func_02084d3c(param_1, param_2, param_3);
    func_020849c0(param_1, 3);
    func_0207a14c((Unk0201290c *) v1, (u32) 1);
}

#pragma thumb off
