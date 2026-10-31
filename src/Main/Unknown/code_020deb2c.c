#include "Main/Unknown/code_020deb2c.h"

void func_020deb2c(Vec3 *param_1, void *param_2, u32 param_3, int param_4, u32 param_5) {
    int v1;
    u32 v2;
    v2 = (u32) * (u16 *) ((u32) param_2 + 0x74);
    if (param_4 == 0) {
        if (v2 == (int) data_021759c0->mUnk_62) {
            v1 = (int) func_0208b7bc((u32) 0x2d, (const Vec3 *) param_1);
            if (v1 != 0) {
                func_02081f10((u32) v1, v2, (u32) 0x1e);
            }
            v1 = (int) func_0208b7bc((u32) 0x2e, (const Vec3 *) param_1);
            if (v1 != 0) {
                func_02081f10((u32) v1, v2, (u32) 0x1e);
            }
        }
        v1 = (int) func_0208b7bc((u32) 0x2f, (const Vec3 *) param_1);
        if (v1 != 0) {
            func_02081f10((u32) v1, v2, (u32) 0x1e);
        }
    }
    func_020d26ec(param_2, 0xd4);
    func_020fa78c(v2, param_3, param_5);
}
