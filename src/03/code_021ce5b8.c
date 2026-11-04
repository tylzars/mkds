#include "03/code_021ce5b8.h"
#include "03/code_021ce000.h"
#include "03/unk_021da000.h"
#include "code_02142eac.h"
#include "03/code_021ce834.h"
#include "string.h"
#include "code_02134398.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"

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
        func_0200ee3c(e, 0xc0);
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
    func_0200ee3c(d->mUnk_0f00, 0x400);
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
