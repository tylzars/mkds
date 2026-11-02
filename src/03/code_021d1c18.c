#include "03/code_021d1c18.h"
#include "03/code_021d1000.h"
#include "03/unk_021da000.h"
#include "Main/Unknown/code_0214d000.h"
#include "03/code_021d2ecc.h"

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

void *func_ov003_021d1c18(u32 param_1, u32 param_2) {
    u32 v1;
    u8 v2[8];
    v1 = func_ov003_021d2f44((int) (param_1), (u32) ((u32) (v2)));
    func_ov003_021d1c3c((int) (param_1), (int) (param_2), (u8 *) (v1));
    return (void *) v1;
}
