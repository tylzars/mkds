#include "03/code_021c0528.h"
#include "03/code_021c04ec.h"
#include "03/code_021cdc10.h"
#include "03/code_021d2a80.h"
#include "03/code_021d250c.h"
#include "03/unk_021d5f00.h"
#include "03/unk_021da000.h"

void func_ov003_021c0528(void) {
    Unk021d299c a;
    s32 i;
    s32 j;

    if (func_ov003_021d2a80(&data_ov003_021d67e8) == 0) {
        goto fail;
    }
    for (i = 0; i < 0x2f; i++) {
        func_ov003_021d250c(data_ov003_021d5fb0[i], data_ov003_021d5f7c[0], (short *) &a);
        if (func_ov003_021d2a80(&a) != 0) {
            if (data_ov003_021da15c->mUnk_11e != i) {
                goto fail;
            }
            func_ov003_021c04ec(i);
            goto done;
        }
    }
    for (j = 2; j < 4; j++) {
        func_ov003_021d250c(data_ov003_021d5f90[j], data_ov003_021d5fa0[j], (short *) &a);
        if (func_ov003_021d2a80(&a) != 0) {
            if (data_ov003_021da15c->mUnk_11e != j + 0x2f) {
                goto fail;
            }
            func_ov003_021c04ec(j + 0x2f);
            if (j == 3) {
                data_ov003_021da15c->mUnk_122++;
                if (data_ov003_021da15c->mUnk_122 >= 0x28) {
                    if (data_ov003_021da15c->mUnk_123 == 0) {
                        func_ov003_021cdc10(9);
                        data_ov003_021da15c->mUnk_11e = -1;
                        return;
                    }
                    data_ov003_021da15c->mUnk_11c = 0x80;
                    data_ov003_021da15c->mUnk_122 -= 7;
                    return;
                }
            }
            return;
        }
    }
    for (i = 0; i < 2; i++) {
        func_ov003_021d250c(data_ov003_021d5f88[i], data_ov003_021d5f78[0], (short *) &a);
        if (func_ov003_021d2a80(&a) != 0) {
            if (data_ov003_021da15c->mUnk_11e != i + 0x33) {
                goto fail;
            }
            func_ov003_021c04ec(i + 0x33);
            goto done;
        }
    }
fail:
    func_ov003_021c04ec(-1);
done:
    data_ov003_021da15c->mUnk_122 = 0;
}
