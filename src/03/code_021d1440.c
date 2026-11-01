#include "03/code_021d1440.h"
#include "03/code_021d1d4c.h"
#include "03/code_021d1cd4.h"
#include "03/code_021d27d8.h"
#include "03/unk_021d7bd4.h"
#include "Main/Unknown/code_02004d80.h"
#include "code_02004270.h"
#include "code_02134d30.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "code_0200fd1c.h"

void *func_ov003_021d14b8(const u8 *param_1, u32 *param_2, s32 param_3) {
    Unk02003024 a;
    void *b;
    u32 c;
    s32 e;

    func_ov003_021d1cd4(data_ov003_021da2b0->mUnk_84);
    func_02004d80(&a);
    if (func_02004a30(&a, param_1) == 0) {
        func_0200fd1c();
    }
    c = a.mUnk_20.w.mUnk_08 - a.mUnk_20.w.mUnk_04;
    if (param_2 != 0) {
        *param_2 = c;
    }
    if (func_ov003_021d1440(param_1, data_ov003_021d7bd4, 2) != 0) {
        e = -4;
    } else {
        e = param_3;
    }
    b = func_ov003_021d285c(c, e);
    func_020048ac(&a, b, c);
    func_020049e8(&a);
    if (e > 0) {
        return b;
    }
    c = *(u32 *) b >> 8;
    if (param_2 != 0) {
        *param_2 = c;
    }
    {
        void *d = func_ov003_021d285c(c, param_3);

        func_0214d344(b, d);
        func_ov003_021d2808(&b);
        return d;
    }
}

void func_ov003_021d1490(void *param_1, ...) {
    func_ov003_021d2808(&param_1);
    func_ov003_021d1d0c(data_ov003_021da2b0->mUnk_84, param_1);
}

u32 func_ov003_021d1440(const u8 *param_1, const u8 *param_2, s32 param_3) {
    s32 a = func_0213a434(param_1);
    s32 b = func_0213a434(param_2);

    if (a < param_3 || b < param_3) {
        return 0;
    }
    if (func_02134d30(param_1 + (a - param_3), param_2 + (b - param_3), param_3) == 0) {
        return 1;
    }
    return 0;
}
