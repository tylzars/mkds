#include "03/code_021d2188.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d2060.h"
#include "03/code_021d27d8.h"
#include "03/code_021d34c0.h"
#include "03/code_021d3544.h"
#include "03/unk_021d67d8.h"
#include "03/unk_021da000.h"
#include "Main/Unknown/code_0200eddc.h"
#include "code_0214a054.h"
#include "code_0214a314.h"
#include "Main/Unknown/code_0214a2f4.h"
#include "code_0214b824.h"
#include "code_0214cfe4.h"
#include "code_020231e4.h"

void func_ov003_021d2188(Unk021d2188 *param_1) {
    // placeholders: the values are sent through the stack
    volatile u16 a;
    volatile u16 b;
    void *c;

    func_ov003_021d34c0(1, param_1->mUnk_34);
    if (param_1 == (*(Unk021d1fd0 **) &data_ov003_021da2c4)->mUnk_718) {
        c = (void *) func_0214a054();
        a = 0;
        func_0214cfe4(a, c, (data_ov003_021d67e0[0] * data_ov003_021d67e0[1]) << 5);
    } else {
        c = (void *) func_0214a054();
        b = 0;
        func_0214cfe4(b, c, (data_ov003_021d67e0[2] * data_ov003_021d67e0[3]) << 5);
    }
    func_ov003_021d2808(&param_1->mUnk_30);
}

void func_ov003_021d21f8(u32 param_1, u8 *param_2) {
    Unk021d1fd0 *a;
    u32 b;

    if (*param_2 != 0) {
        a = *(Unk021d1fd0 **) &data_ov003_021da2c4;
        if (param_2 == &a->mUnk_794) {
            b = (data_ov003_021d67e0[0] * data_ov003_021d67e0[1]) << 5;
            func_0200ee74(a->mUnk_718[0].mUnk_30, b);
            func_0214bafc((*(Unk021d1fd0 **) &data_ov003_021da2c4)->mUnk_718[0].mUnk_30, data_ov003_021d67dc[0] << 5,
                          b);
        } else {
            b = (data_ov003_021d67e0[2] * data_ov003_021d67e0[3]) << 5;
            func_0200ee74(a->mUnk_718[1].mUnk_30, b);
            func_0214ba94((*(Unk021d1fd0 **) &data_ov003_021da2c4)->mUnk_718[1].mUnk_30, data_ov003_021d67dc[1] << 5,
                          b);
        }
        *param_2 = 0;
    }
}

Unk021d2188 *func_ov003_021d2288(u32 param_1, u32 param_2) {
    Unk021d2188 *a = &(*(Unk021d1fd0 **) &data_ov003_021da2c4)->mUnk_718[param_1];
    u32 b = data_ov003_021d67e2[param_1 * 2];
    u32 c = data_ov003_021d67e0[param_1 * 2];
    vu16 *d;
    u32 e;
    u8 *f;

    a->mUnk_30 = func_ov003_021d285c((c * b) << 5, 0x20);
    if (param_1 == 1) {
        d = (vu16 *) 0x4001008;
        *d &= ~0x40;
        *d = (*d & 0x43) | 0xc00;
    } else {
        d = (vu16 *) 0x4000008;
        *d &= ~0x40;
        *d = (*d & 0x43) | 0xc00;
    }
    func_02023408(a, a->mUnk_30, c, b, 4);
    f = (*(Unk021d1fd0 **) &data_ov003_021da2c4)->mUnk_000 + param_2 * 12;
    a->mUnk_20.mUnk_00 = a;
    a->mUnk_20.mUnk_04 = f;
    a->mUnk_20.mUnk_08 = 1;
    a->mUnk_20.mUnk_0c = 1;
    if (param_1 == 1) {
        e = func_0214a2f4();
    } else {
        e = func_0214a314();
    }
    func_020232b0((u16 *) e, c, b, 0, 0, 0x20, data_ov003_021d67dc[param_1], 0xf);
    func_ov003_021d2060(a, 0);
    a->mUnk_34 =
        func_ov003_021d3544(1, func_ov003_021d21f8, &(*(Unk021d1fd0 **) &data_ov003_021da2c4)->mUnk_794 + param_1, 200);
    return a;
}
