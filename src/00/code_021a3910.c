#include "00/code_021a3910.h"
#include "00/code_02186628.h"
#include "00/code_02188000.h"
#include "00/code_0219c384.h"
#include "00/code_021a369c.h"
#include "00/unk_021b4000.h"
#include "code_0214d018.h"

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
    if (data_ov000_021b5df4 != 0) {
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
