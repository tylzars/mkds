#include "00/code_021a37dc.h"
#include "00/unk_021b5000.h"
#include "03/code_021b94b8.h"
#include "00/code_021a377c.h"
#include "00/code_021a3000.h"

#include "00/code_02188000.h"
#include "00/code_0219c384.h"
#include "00/code_021a5000.h"
#include "00/unk_021b1000.h"
#include "00/code_02186628.h"
#include "00/code_021a369c.h"
#include "00/unk_021b4000.h"
#include "code_0214d018.h"

void func_ov000_021a39c4(void *a) {
    func_ov000_021a39d8((Unk021b5df4 *) (a), (u16) (3), (u32) (1), (u32) (0x14));
    return;
}

void func_ov000_021a397c(s32 a) {
    switch (a) {
        case 0:
            func_ov000_02186628(data_ov000_021b4200);
            break;
        case 1:
            func_ov000_02186628(data_ov000_021b4228);
            break;
        case 2:
            func_ov000_02186628(data_ov000_021b424c);
            break;
    }
}

void func_ov000_021a3910(void) {
    Unk021a3910 t;
    if (data_ov000_021b5df4 != NULL) {
        if (data_ov000_021b5df4->mUnk_04 != 1) {
            return;
        }
        func_0214d168(&t, 0, 12);
        t.mUnk_08 = data_ov000_021b5df4->mUnk_08;
        t.mUnk_09 = data_ov000_021b5df4->mUnk_0a;
        t.mUnk_00 = func_ov000_021a372c;
        t.mUnk_04 = func_ov000_021a3704;
        data_ov000_021b5df4->mUnk_04 = 2;
        if (func_ov000_02188868((Unk02188868 *) &t) != 0) {
            return;
        }
        func_ov000_0219c384(0xb, -6);
        return;
    }
    func_ov000_0219c384(0xb, -4);
}

u32 func_ov000_021a38d8(void) {
    int *v1;
    v1 = (s32 *) data_ov000_021b5df4;
    if (v1 == NULL) {
        return 0;
    }
    if (*v1 != 0) {
        *(u16 *) (v1 + 1) = 3;
        func_ov000_021a3810();
        return 1;
    }
    return 0;
}

void func_ov000_021a3884(void) {
    Unk021b5df4 *p = data_ov000_021b5df4;
    if (p != NULL && p->mUnk_04 == 2) {
        data_ov000_021b5df4->mUnk_00 = func_ov000_021887cc();
    } else if (p != NULL && p->mUnk_04 == 4 && p->mUnk_06 != 0 && func_ov000_021a5bfc() != 9) {
        data_ov000_021b5df4->mUnk_06 = 0;
        data_ov000_021b5df4->mUnk_04 = 6;
    }
}

u32 func_ov000_021a3810(void) {
    u32 v = 0;
    s32 r;
    if (data_ov000_021b5df4 != NULL) {
        r = func_ov000_02188758();
        if (r == 5) {
            data_ov000_021b5df4->mUnk_04 = 4;
            data_ov000_021b5df4->mUnk_06 = 1;
            return 4;
        }
        if (r < 0) {
            if (r >= -10) {
                func_ov000_0219c384(0xb, r - 0x2bc);
                data_ov000_021b5df4->mUnk_04 = 8;
                return 8;
            }
            func_ov000_0219c384(5, r);
            data_ov000_021b5df4->mUnk_04 = 7;
            return 7;
        }
        v = 2;
    }
    return v;
}

void func_ov000_021a37dc(void) {
    int v1;
    if (data_ov000_021b5df4 != NULL) {
        v1 = func_ov000_02188720();
        while (v1 == 0) {
            func_0200dc3c(10);
            v1 = func_ov000_02188720();
        }
        *(s32 *) &data_ov000_021b5df4 = 0;
    }
    return;
}
