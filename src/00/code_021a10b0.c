#include "00/code_021a10b0.h"

void func_ov000_021a10b0(u8 param_1, u8 param_2, u32 param_3, u32 param_4) {
    int *v1;
    func_ov000_021a1140(0);
    v1 = (int *) &data_ov000_021b566c;
    data_ov000_021b566c->mUnk_15 = param_1;
    *(u8 *) (*v1 + 0x16) = param_2;
    *(u32 *) (*v1 + 0x44c) = param_3;
    *(u32 *) (*v1 + 0x450) = param_4;
    *(u8 *) (*v1 + 0x175) = 0;
    *(u8 *) (*v1 + 0x2b8) = 0;
    func_ov000_021a4b84(0x32, data_ov000_021b40c4);
    func_ov000_021a4b84(0x33, data_ov000_021b40f0);
    func_ov000_021a4b84(0x34, data_ov000_021b40fc);
    func_ov000_021a4b84(0x35, data_ov000_021b4108);
    func_ov000_021a4b84(0x36, data_ov000_021b40cc);
}
