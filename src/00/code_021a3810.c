#include "00/code_021a3810.h"
#include "00/code_02188000.h"
#include "00/code_0219c384.h"
#include "00/code_021a5000.h"

void func_ov000_021a3884(void) {
    Unk021b5df4 *p = data_ov000_021b5df4;
    if (p != 0 && p->mUnk_04 == 2) {
        data_ov000_021b5df4->mUnk_00 = func_ov000_021887cc();
    } else if (p != 0 && p->mUnk_04 == 4 && p->mUnk_06 != 0 && func_ov000_021a5bfc() != 9) {
        data_ov000_021b5df4->mUnk_06 = 0;
        data_ov000_021b5df4->mUnk_04 = 6;
    }
}

u32 func_ov000_021a3810(void) {
    u32 v = 0;
    s32 r;
    if (data_ov000_021b5df4 != 0) {
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
