#include "00/code_0219c79c.h"
#include "00/code_0218f000.h"

void func_ov000_0219c80c(char *param_1, char *param_2) {
    func_ov000_0219c79c(param_1, param_2, func_ov000_0219c824, 2);
}

void func_ov000_0219c79c(char *param_1, char *param_2, void (*param_3)(), s32 param_4) {
    u32 *v1;
    u32 v2;
    u64 v3;
    func_0213a2d0((char *) ((u32 *) (u32) ((int) data_ov000_021b565c + 0x4c)), (const u8 *) param_1);
    func_0213a2d0((char *) ((u32 *) (u32) ((int) data_ov000_021b565c + 0x14c)), (const u8 *) param_2);
    v2 = *(int *) &data_ov000_021b565c;
    v3 = func_0200f5ac();
    *(u64 *) (v2 + 0x38) = v3;
    *(u32 *) (v2 + 0x34) = 1;
    v1 = (u32 *) (int) data_ov000_021b565c;
    v2 = func_ov000_0219c8dc(func_ov000_0218f15c((int *) (u32) (*v1), (s8 *) (void *) (v1 + 0x13),
                                                 (s8 *) (u32) ((int) v1 + 0x14c), 1, 0, param_3, 0));
    if (v2 == 0) {
        data_ov000_021b565c->mUnk_04 = param_4;
    }
}
