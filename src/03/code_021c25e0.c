#include "03/code_021c25e0.h"
#include "03/code_021d083c.h"
#include "03/code_021d1000.h"
#include "03/code_021d3000.h"

#include "03/code_021d27d8.h"
#include "03/code_021d3488.h"
#include "code_0214cfe4.h"
#include "03/code_021c209c.h"
#include "03/code_021c2530.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d5000.h"
#include "03/unk_021da000.h"
#include "03/code_021bf410.h"
#include "code_0200fc8c.h"

void func_ov003_021c2840(u32 a) {
    Unk021d6e24 b;
    data_ov003_021da194 = func_ov003_021d285c(0x1e2a4, 0x20);
    data_ov003_021da194->mUnk_1e298 = (void (*)(s32)) a;
    data_ov003_021da194->mUnk_1e2a0 = 0;
    data_ov003_021da194->mUnk_1e2a1 = 0;
    b = data_ov003_021d6e24;
    b.mUnk_04 = func_ov003_021c2530(data_ov003_021da19c, 0xf);
    b.mUnk_08 = func_ov003_021c2530(data_ov003_021da19c, 0x10);
    b.mUnk_18 = func_ov003_021c20d0() + 0x31;
    func_ov003_021d1358((Unk021da2ac *) data_ov003_021da194, (Unk021d1358 *) &b);
    if (func_ov003_021d11d4() == 0) {
        OS_Terminate();
    }
    data_ov003_021da194->mUnk_1e29c = func_ov003_021d3544(0, func_ov003_021c25e0, NULL, 0x78);
}

void func_ov003_021c2824(void) {
    func_ov003_021d3544((u32) 0, &func_ov003_021c27f8, NULL, (u32) 0x78);
}

void func_ov003_021c27f8(u32 a) {
    int v1;
    v1 = func_ov003_021d1290();
    if (v1 != 0) {
        data_ov003_021da194->mUnk_1e2a1 = 1;
        func_ov003_021d34c8(0, a);
    }
}

u32 func_ov003_021c27e4(void) {
    if (data_ov003_021da194 == NULL) {
        return 1;
    }
    return 0;
}

void func_ov003_021c27d0(void *a) {
    data_ov003_021da194->mUnk_1e298 = (void (*)(s32)) a;
}

u32 func_ov003_021c27c8(void) {
    u32 value0;
    u32 value3;
    value3 = (u32) &func_ov003_021d11a0;
    value0 = (u32) func_ov003_021d11a0();
    return value0;
}

u8 *func_ov003_021c27b4(void) {
    return data_ov003_021da194->mUnk_1e280;
}

static inline void func_ov003_021c25e0_inline(const void *s, void *d, s32 n) {
    MemCopyHalfwords(s, d, n);
}

void func_ov003_021c25e0(u32 a) {
    u8 b[2];
    Unk021da194 *p;
    func_ov003_021d0ee0();
    p = data_ov003_021da194;
    if (p->mUnk_1e2a0 != 0 && p->mUnk_1e2a1 == 0) {
        if (p->mUnk_1e298 == NULL) {
            return;
        }
        p->mUnk_1e298(0);
        return;
    }
    func_ov003_021d0e9c(&b[0], &b[1]);
    switch (b[0]) {
        case 1:
        case 2:
        case 3:
        case 4:
            break;
        case 5:
            if (b[1] == 0) {
                break;
            }
            func_ov003_021c25e0_inline(func_ov003_021d0e90(), data_ov003_021da194->mUnk_1e280, 0x16);
            if (data_ov003_021da194->mUnk_1e298 != NULL) {
                data_ov003_021da194->mUnk_1e298(0);
            } else {
                data_ov003_021da194->mUnk_1e2a0 = 1;
            }
            break;
        case 13:
            if (b[1] == 0) {
                break;
            }
            if (data_ov003_021da194->mUnk_1e298 != NULL) {
                data_ov003_021da194->mUnk_1e298(1);
            } else {
                data_ov003_021da194->mUnk_1e2a0 = 1;
            }
            break;
        case 20:
        case 23:
            if (b[1] == 0) {
                break;
            }
            if (data_ov003_021da194->mUnk_1e298 != NULL) {
                data_ov003_021da194->mUnk_1e298(3);
            } else {
                data_ov003_021da194->mUnk_1e2a0 = 1;
            }
            break;
        case 26:
        case 29:
            if (b[1] == 0) {
                break;
            }
            if (data_ov003_021da194->mUnk_1e298 != NULL) {
                data_ov003_021da194->mUnk_1e298(4);
            } else {
                data_ov003_021da194->mUnk_1e2a0 = 1;
            }
            break;
        case 12:
            if (b[1] == 0) {
                break;
            }
            if (data_ov003_021da194->mUnk_1e298 != NULL) {
                data_ov003_021da194->mUnk_1e298(2);
            } else {
                data_ov003_021da194->mUnk_1e2a0 = 1;
            }
            break;
        case 34:
            func_ov003_021d34c8(0, a);
            func_ov003_021d2808(&data_ov003_021da194);
            break;
    }
}
