#include "03/code_021d15a4.h"
#include "03/code_021d1564.h"
#include "03/code_021d1574.h"
#include "03/code_021d1d60.h"
#include "03/code_021d27d8.h"
#include "03/unk_021d67d8.h"
#include "03/unk_021d7bd4.h"
#include "Main/Unknown/code_02004238.h"
#include "Main/Unknown/code_02004d80.h"
#include "code_0200cd1c.h"
#include "code_0200d118.h"
#include "code_0200fd1c.h"
#include "code_02003be0.h"
#include "code_02004270.h"
#include "code_0214578c.h"

void func_ov003_021d1654(void) {
    Unk02003024 a;
    u32 b[2];
    u32 c[2];
    char d[0x80];
    u32 e;
    u32 f;

    data_ov003_021da2b0 = func_ov003_021d283c(0xe8, 4);
    func_02004d80(&a);
    if (func_02004a30(&a, data_ov003_021d7be0) == 0) {
        func_0200fd1c();
    }
    data_ov003_021da2b0->mUnk_e4 = func_0200cd28();
    e = a.mUnk_20.w.mUnk_04;
    func_020048ac(&a, b, 8);
    func_020048ac(&a, c, 8);
    func_020049e8(&a);
    func_02004238(&data_ov003_021da2b0->mUnk_88);
    if (func_02004128(&data_ov003_021da2b0->mUnk_88, data_ov003_021d67d8, 3) == 0) {
        func_0200fd1c();
    }
    func_02003c60(&data_ov003_021da2b0->mUnk_88, func_ov003_021d15a4, 0x602);
    if (func_02004018(&data_ov003_021da2b0->mUnk_88, (u8 *) e, c[0], c[1], b[0], b[1],
                      (s32(*)(Unk02003a6c *, void *, u32, u32)) func_ov003_021d1574,
                      (s32(*)(Unk02003a6c *, void *, u32, u32)) func_ov003_021d1564) == 0) {
        func_0200fd1c();
    }
    f = func_02003e24(&data_ov003_021da2b0->mUnk_88, 0, 0);
    data_ov003_021da2b0->mUnk_00 = func_ov003_021d285c(f, 4);
    func_02003e24(&data_ov003_021da2b0->mUnk_88, (u32) data_ov003_021da2b0->mUnk_00, f);
    data_ov003_021da2b0->mUnk_84 = func_ov003_021d1d60(0x20, data_ov003_021da2b0->mUnk_04, 4);
    func_0200da28(d, data_ov003_021d7bf8, data_ov003_021d67d8);
    func_020047ec((u8 *) d);
}

void func_ov003_021d15f4(void) {
    func_020047ec(data_ov003_021d7bd8);
    ((u32(*)(Unk02003a6c *)) func_02003d8c)(&data_ov003_021da2b0->mUnk_88);
    func_02003f50(&data_ov003_021da2b0->mUnk_88);
    func_02004090(&data_ov003_021da2b0->mUnk_88);
    func_0200cd80(data_ov003_021da2b0->mUnk_e4);
    data_ov003_021da2b0->mUnk_e4 = 0;
    func_ov003_021d2808(data_ov003_021da2b0);
    data_ov003_021da2b0->mUnk_00 = 0;
    func_ov003_021d2808(&data_ov003_021da2b0);
}

s32 func_ov003_021d15a4(Unk02003024 *param_1, u32 param_2) {
    switch (param_2) {
        case 9:
            func_021457cc(data_ov003_021da2b0->mUnk_e4);
            return 0;
        case 10:
            func_021457ac(data_ov003_021da2b0->mUnk_e4);
            return 0;
        case 1:
            return 4;
        default:
            return 8;
    }
}
