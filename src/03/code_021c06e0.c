#include "03/code_021c06e0.h"
#include "03/code_021bf8c0.h"
#include "03/code_021c0680.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d250c.h"
#include "03/code_021d2940.h"
#include "03/types_021d299c.h"
#include "03/unk_021d5f00.h"
#include "03/unk_021d6000.h"
#include "03/unk_021da000.h"

void func_ov003_021c08d0(void) {
    Unk021d299c a;
    s32 i;
    s32 j;
    if (func_ov003_021d2a34(&data_ov003_021d67e8) == 0) {
        return;
    }
    i = 0;
    data_ov003_021da15c->mUnk_11e = -1;
    for (; i < 0x2f; i++) {
        func_ov003_021d250c(data_ov003_021d5fb0[i], data_ov003_021d5f7c[0], (s16 *) &a);
        if (func_ov003_021d2a34(&a) != 0) {
            if (data_ov003_021da15c->mUnk_124 == 0) {
                func_ov003_021cdc10(9);
                return;
            }
            func_ov003_021cdc10(0);
            data_ov003_021da15c->mUnk_11e = i;
            return;
        }
    }
    for (j = 0; j < 4; j++) {
        func_ov003_021d250c(data_ov003_021d5f90[j], data_ov003_021d5fa0[j], (s16 *) &a);
        if (func_ov003_021d2a34(&a) != 0) {
            if ((j == 3 && data_ov003_021da15c->mUnk_123 == 0) || (j == 2 && data_ov003_021da15c->mUnk_124 == 0)) {
                func_ov003_021cdc10(9);
                return;
            }
            func_ov003_021cdc10(data_ov003_021d6bf4[j]);
            data_ov003_021da15c->mUnk_11e = j + 0x2f;
            return;
        }
    }
    for (i = 0; i < 2; i++) {
        func_ov003_021d250c(data_ov003_021d5f88[i], data_ov003_021d5f78[0], (s16 *) &a);
        if (func_ov003_021d2a34(&a) != 0) {
            func_ov003_021cdc10(0);
            data_ov003_021da15c->mUnk_11e = i + 0x33;
            return;
        }
    }
}

void func_ov003_021c06e0(void) {
    Unk021d299c a;
    s32 i;
    u16(*q)[2];
    u16(*p)[2];
    s32 j;
    data_ov003_021da15c->mUnk_11c = 0;
    if (func_ov003_021d299c(&data_ov003_021d67e8) == 0) {
        return;
    }
    for (i = 0; i < 0x2f; i++) {
        func_ov003_021d250c(data_ov003_021d5fb0[i], data_ov003_021d5f7c[0], (s16 *) &a);
        if (func_ov003_021d299c(&a) != 0) {
            if (data_ov003_021da15c->mUnk_11e != i) {
                return;
            }
            data_ov003_021da15c->mUnk_11c = data_ov003_021d6bdc[data_ov003_021da15c->mUnk_11d][i];
            if (data_ov003_021da15c->mUnk_11d == 1) {
                func_ov003_021c00ec(0);
            }
            data_ov003_021da15c->mUnk_121 = i;
            func_ov003_021bffb0();
            return;
        }
    }
    j = 2;
    q = data_ov003_021d5fa8;
    p = data_ov003_021d5f98;
    for (; j < 4; q++, p++, j++) {
        func_ov003_021d250c(*p, *q, (s16 *) &a);
        if (func_ov003_021d299c(&a) != 0) {
            if (data_ov003_021da15c->mUnk_11e != j + 0x2f) {
                return;
            }
            data_ov003_021da15c->mUnk_11c = data_ov003_021d5f80[j];
            if (data_ov003_021da15c->mUnk_11d == 1) {
                func_ov003_021c00ec(0);
            }
            data_ov003_021da15c->mUnk_121 = j + 0x2f;
            func_ov003_021bffb0();
            return;
        }
    }
    for (i = 0; i < 2; i++) {
        func_ov003_021d250c(data_ov003_021d5f88[i], data_ov003_021d5f78[0], (s16 *) &a);
        if (func_ov003_021d299c(&a) != 0) {
            if (data_ov003_021da15c->mUnk_11e != i + 0x33) {
                return;
            }
            data_ov003_021da15c->mUnk_11c = data_ov003_021d5f6c[i];
            data_ov003_021da15c->mUnk_121 = i + 0x33;
            func_ov003_021bffb0();
            return;
        }
    }
    func_ov003_021d250c(data_ov003_021d5f90[0], data_ov003_021d5fa0[0], (s16 *) &a);
    if (func_ov003_021d299c(&a) != 0) {
        if (data_ov003_021da15c->mUnk_11e != 0x2f) {
            return;
        }
        func_ov003_021c06b0();
        data_ov003_021da15c->mUnk_121 = 0x2f;
        func_ov003_021bffb0();
        return;
    }
    func_ov003_021d250c(data_ov003_021d5f94[0], data_ov003_021d5fa4[0], (s16 *) &a);
    if (func_ov003_021d299c(&a) != 0) {
        if (data_ov003_021da15c->mUnk_11e != 0x30) {
            return;
        }
        func_ov003_021c0680();
        data_ov003_021da15c->mUnk_121 = 0x30;
        func_ov003_021bffb0();
    }
}
