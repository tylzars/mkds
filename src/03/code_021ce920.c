#include "03/code_021ce920.h"
#include "03/code_021ce8ec.h"
#include "03/code_021d2388.h"
#include "03/code_021d27d8.h"
#include "03/code_021d34c8.h"
#include "03/code_021d3544.h"
#include "03/unk_021d6000.h"
#include "code_02134d30.h"
#include "code_0200f5ac.h"
#include "code_0200fd1c.h"
#include "code_0214a348.h"
#include "code_0214d018.h"
#include "registers.h"

u32 func_ov003_021ce920(void (*a)(u32)) {
    Unk021da280 *d;
    Unk0200fddc s;
    u64 t;

    data_ov003_021da280 = func_ov003_021d283c(0x1ba0, 0x20);
    data_ov003_021da280->mUnk_1370 = a;
    d = data_ov003_021da280;
    t = func_0200f5ac();
    d->mUnk_1b74 = (u32) t;
    d->mUnk_1b78 = (u32) (t >> 32);
    if (func_02143e10(d, func_ov003_021ce7c0, 3) == 2) {
        do {
            func_02143520(&data_ov003_021da280->mUnk_13b8);
        } while (data_ov003_021da280->mUnk_13b8.mUnk_000 != 2);
        d = data_ov003_021da280;
        *(Unk021d66d0 *) &d->mUnk_1374 = data_ov003_021d66d0;
        d->mUnk_1374.mUnk_00 = d->mUnk_0f00;
        data_ov003_021da280->mUnk_1374.mUnk_08 = func_02143090();
        func_0200fddc(&s);
        func_0214d1fc(data_ov003_021d66c4, &data_ov003_021da280->mUnk_1374.mUnk_14[0], 8);
        data_ov003_021da280->mUnk_1374.mUnk_14[9] = 1;
        func_0214d1fc(s.mUnk_04, &data_ov003_021da280->mUnk_1374.mUnk_14[0xc], s.mUnk_18 * 2);
        if (func_ov003_021ce8ec() != 0) {
            data_ov003_021da280->mUnk_1b7c = func_ov003_021d3544(0, func_ov003_021ce4d4, 0, 0x78);
            return 1;
        }
    }
    func_ov003_021d2808(&data_ov003_021da280);
    return 0;
}

void func_ov003_021cea3c(u32 a) {
    s32 i;

    reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
    func_ov003_021d197c(data_ov003_021da284->mUnk_00);
    func_ov003_021d197c(data_ov003_021da284->mUnk_04);
    for (i = 0; i < data_ov003_021d6720[data_ov003_021da284->mUnk_1c]; i++) {
        if (data_ov003_021da284->mUnk_08[i] != 0) {
            func_ov003_021d197c(data_ov003_021da284->mUnk_08[i]);
        }
    }
    func_ov003_021d2388((int) data_ov003_021da284->mUnk_10);
    func_ov003_021d34c8(1, a);
    func_ov003_021d2808(&data_ov003_021da284);
}

void func_ov003_021ceab8(Unk021d34e0 *a) {
    data_ov003_021da284->mUnk_1a++;
    func_0214a348((u16 *) 0x04000050, data_ov003_021da284->mUnk_1a);
    if (data_ov003_021da284->mUnk_1a >= 0) {
        func_ov003_021d34e0(a, func_ov003_021cea3c);
    }
}
