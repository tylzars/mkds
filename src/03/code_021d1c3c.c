#include "03/code_021d1c3c.h"
#include "03/code_021d1440.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"

void func_ov003_021d1cb0(u32 param_1, const u8 *param_2) {
    u32 a;

    data_ov003_021da2b8[param_1] = func_ov003_021d14b8(param_2, &a, 4);
}

void func_ov003_021d1c90(u32 param_1) {
    func_ov003_021d1490(data_ov003_021da2b8[param_1]);
    data_ov003_021da2b8[param_1] = 0;
}

void func_ov003_021d1c3c(u32 param_1, u32 param_2, u8 *param_3) {
    Unk021da2b8 *a = data_ov003_021da2b8[param_1];
    u8 *b = (u8 *) a + a[param_2].mUnk_04;
    u16 c = a[param_2].mUnk_00;
    s32 i;
    u8 e[8];
    // placeholder: the value is sent through the stack
    volatile u32 d = 0;

    func_0214d018(d, e, 8);
    for (i = 0; i < c; i++, b += 6, param_3 += 8) {
        func_0214cffc(b, e, 6);
        func_0214d02c(e, param_3, 8);
    }
}
