#include "03/code_021cd0d0.h"
#include "03/unk_021d6000.h"
#include "code_02134d30.h"
#include "03/code_021cd000.h"

#include "03/types_021da26c.h"
#include "03/code_021cce78.h"
#include "code_02142eac.h"
#include "code_0214cfe4.h"
#include "03/code_021d27d8.h"
#include "03/unk_021da000.h"

void func_ov003_021cd2a4(void) {
    if (data_ov003_021da26c == NULL) {
        data_ov003_021da26c = func_ov003_021d283c(0x1e60, 32);
    }
}

void func_ov003_021cd27c(void) {
    if (data_ov003_021da26c != NULL) {
        while (func_02143280() != 0x8000) {
        }
        func_ov003_021d2808(&data_ov003_021da26c);
    }
}

u32 func_ov003_021cd1c4(void) {
    Unk021da26c *p;
    // volatile: the only spelling found that stores and reloads the argument on the stack.
    volatile u16 a = 0;
    MemFillHalfwords(a, data_ov003_021da26c->mUnk_1300, 0x348);
    if (func_02143e10(data_ov003_021da26c, func_ov003_021cd080, 3) != 2) {
        return 0;
    }
    do {
        func_02143520(&data_ov003_021da26c->mUnk_168c);
    } while (data_ov003_021da26c->mUnk_168c.mUnk_00 != 2);
    p = data_ov003_021da26c;
    p->mUnk_1648 = data_ov003_021d6640;
    p->mUnk_1648.mUnk_00.mUnk_00 = p->mUnk_0f00;
    data_ov003_021da26c->mUnk_1648.mUnk_00.mUnk_08 = func_02143090();
    if (func_ov003_021cd190() != 0) {
        return 1;
    }
    return 0;
}

u32 func_ov003_021cd190(void) {
    int v1;
    v1 = func_021438f0(func_ov003_021cd080, &data_ov003_021da26c->mUnk_1648.mUnk_00);
    if (v1 == 2) {
        return 1;
    }
    return 0;
}

u32 func_ov003_021cd118(void) {
    data_ov003_021da26c->mUnk_1e48 = 1;
    func_02143520(&data_ov003_021da26c->mUnk_168c);
    if (data_ov003_021da26c->mUnk_168c.mUnk_00 != 2) {
        if (func_02143dd0(func_ov003_021cd080) != 2) {
            return 0;
        }
        do {
            func_02143520(&data_ov003_021da26c->mUnk_168c);
        } while (data_ov003_021da26c->mUnk_168c.mUnk_00 != 2);
    }
    if (func_02143d88(func_ov003_021cd080) != 2) {
        return 0;
    }
    return 1;
}

int func_ov003_021cd0d0(int *a) {
    int v1;
    int v2;
    int v3;
    int v4;
    v2 = 0;
    *a = (s32) data_ov003_021da26c->mUnk_1300;
    v1 = 0;
    v3 = *a;
    do {
        v4 = memcmp((const u8 *) (v3 + 0x20), data_ov003_021d6638, 6);
        if (v4 != 0) {
            v2 = v2 + 1;
        }
        v3 = v3 + 0x2a;
        v1 = v1 + 1;
    } while (v1 < 0x14);
    return v2;
}
