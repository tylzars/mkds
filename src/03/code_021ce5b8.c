#include "03/code_021ce5b8.h"
#include "03/unk_021d6000.h"

#include "03/code_021ce000.h"
#include "03/unk_021da000.h"
#include "code_02142eac.h"
#include "string.h"
#include "code_02134398.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"
#include "03/code_021d3488.h"
#include "03/code_021d27d8.h"
#include "code_0200f5ac.h"
#include "registers.h"
#include "03/code_021ce110.h"

u32 func_ov003_021ce920(void (*a)(u32)) {
    Unk021da280 *d;
    Unk0200fddc s;
    u64 t;

    data_ov003_021da280 = func_ov003_021d283c(0x1ba0, 0x20);
    data_ov003_021da280->mUnk_1370 = a;
    d = data_ov003_021da280;
    t = OS_GetTick();
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
        OS_GetOwnerInfo(&s);
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

void func_ov003_021ce7c0(Unk021425e8 *a) {
    Unk021da280 *d;

    if (a->mUnk_02 != 0) {
        return;
    }
    d = data_ov003_021da280;
    if (d->mUnk_1b80 != 0) {
        if (a->mUnk_00 == 2) {
            d->mUnk_1b80 = 2;
        }
        return;
    }
    if (a->mUnk_00 != 0x26) {
        return;
    }
    switch (a->mUnk_08_0) {
        case 5:
            if (d->mUnk_1b82 != 0) {
                func_ov003_021ce5b8((Unk021ce5b8 *) a);
            } else {
                func_ov003_021ce6ac((Unk021ce5b8 *) a);
            }
            func_ov003_021ce8ec();
            break;
        case 4:
            func_ov003_021ce8ec();
            break;
        default:
            IrqDisableLoopForever();
            break;
    }
}

void func_ov003_021ce6ac(Unk021ce5b8 *a) {
    s32 i;

    for (i = 0; i < a->mUnk_0e; i++) {
        Unk021ce5b8_10 *e;
        s32 j;
        u8 *p;
        u8 *q;
        s32 k;
        Unk021da280 *d;

        e = a->mUnk_10[i];
        DC_InvalidateRange(e, 0xc0);
        if (memcmp(e->mUnk_0c, data_ov003_021d66c4, 8) != 0) {
            continue;
        }
        j = 0;
        d = data_ov003_021da280;
        p = d->mUnk_1300[0].mUnk_00;
        for (; j < 16; j++) {
            if (memcmp(e->mUnk_04, p, 6) == 0) {
                if (d->mUnk_1300[j].mUnk_06 != 0) {
                    goto next;
                }
                if ((e->mUnk_15 & 1) == 0) {
                    goto next;
                }
                if (d->mUnk_1370 != NULL) {
                    d->mUnk_1370(1);
                }
                return;
            }
            p += 7;
        }
        k = 0;
        q = d->mUnk_1300[0].mUnk_00;
        for (; k < 16; k++) {
            if (memcmp(q, data_ov003_021d66bc, 6) == 0) {
                MemCopy(e->mUnk_04, d->mUnk_1300[k].mUnk_00, 6);
                data_ov003_021da280->mUnk_1300[k].mUnk_06 = (e->mUnk_15 & 1) ? 1 : 0;
                goto next;
            }
            q += 7;
        }
    next:;
    }
}

void func_ov003_021ce5b8(Unk021ce5b8 *a) {
    s32 i;
    Unk021da280 *q;
    s32 n;
    Unk021da280 *d;

    d = data_ov003_021da280;
    if (d->mUnk_1b81 != 0) {
        if (d->mUnk_1370 != NULL) {
            d->mUnk_1370(d->mUnk_1b81);
        }
        return;
    }
    DC_InvalidateRange(d->mUnk_0f00, 0x400);
    i = 0;
    n = a->mUnk_0e;
    if (n > 0) {
        q = data_ov003_021da280;
        do {
            s32 j;
            u8 *p;
            Unk021ce5b8_10 *e;

            e = a->mUnk_10[i];
            if (memcmp(e->mUnk_0c, data_ov003_021d66c4, 8) != 0) {
                continue;
            }
            if ((e->mUnk_15 & 1) == 0) {
                continue;
            }
            for (j = 0, p = q->mUnk_1300[0].mUnk_00; j < 16; j++) {
                if (memcmp(e->mUnk_04, p, 6) == 0) {
                    if (q->mUnk_1300[j].mUnk_06 != 0) {
                        break;
                    }
                    if (q->mUnk_1370 != NULL) {
                        q->mUnk_1370(1);
                        return;
                    }
                    q->mUnk_1b81 = 1;
                    return;
                }
                p += 7;
            }
        } while (++i < n);
    }
}
