#include "03/code_021ce834.h"
#include "03/unk_021da000.h"
#include "03/code_021ce000.h"
#include "03/code_021d3488.h"

#include "03/code_021d27d8.h"
#include "code_02142eac.h"
#include "03/code_021ce5b8.h"
#include "03/unk_021d6000.h"
#include "code_0200f5ac.h"
#include "code_0200fd1c.h"
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
        MemCopy(data_ov003_021d66c4, &data_ov003_021da280->mUnk_1374.mUnk_14[0], 8);
        data_ov003_021da280->mUnk_1374.mUnk_14[9] = 1;
        MemCopy(s.mUnk_04, &data_ov003_021da280->mUnk_1374.mUnk_14[0xc], s.mUnk_18 * 2);
        if (func_ov003_021ce8ec() != 0) {
            data_ov003_021da280->mUnk_1b7c = func_ov003_021d3544(0, func_ov003_021ce4d4, NULL, 0x78);
            return 1;
        }
    }
    func_ov003_021d2808(&data_ov003_021da280);
    return 0;
}

u32 func_ov003_021ce8ec(void) {
    int v1;
    v1 = func_021438f0(func_ov003_021ce7c0, &data_ov003_021da280->mUnk_1374);
    if (v1 == 2) {
        return 1;
    }
    return 0;
}

u32 func_ov003_021ce848(void) {
    Unk021da280 *d;

    data_ov003_021da280->mUnk_1b80 = 1;
    func_02143520(&data_ov003_021da280->mUnk_13b8);
    if (data_ov003_021da280->mUnk_13b8.mUnk_000 != 2) {
        if (func_02143dd0(func_ov003_021ce7c0) != 2) {
            return 0;
        }
        do {
            func_02143520(&data_ov003_021da280->mUnk_13b8);
        } while (data_ov003_021da280->mUnk_13b8.mUnk_000 != 2);
    }
    if (func_02143d88(func_ov003_021ce7c0) != 2) {
        return 0;
    }
    d = data_ov003_021da280;
    if (d->mUnk_1b7c != 0) {
        func_ov003_021d34c0(0, d->mUnk_1b7c);
    }
    d = data_ov003_021da280;
    while (*(vu8 *) &d->mUnk_1b80 != 2) {
    }
    func_ov003_021d2808(&data_ov003_021da280);
    return 1;
}

void func_ov003_021ce834(u32 a) {
    data_ov003_021da280->mUnk_1370 = (void (*)(u32)) a;
}
