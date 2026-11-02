#include "00/code_021a377c.h"
#include "00/code_02188000.h"
#include "00/code_021a6fa8.h"
#include "00/code_021a86bc.h"

s32 func_ov000_021a377c(void) {
    Unk021b5df4 *p = data_ov000_021b5df4;
    if (p == 0) {
        return 1;
    }
    if (p->mUnk_04 == 4) {
        p->mUnk_04 = 5;
    } else if (p->mUnk_04 != 5) {
        return 1;
    }
    if (func_ov000_021a86e8() != 0) {
        return 0;
    }
    if (func_ov000_02188720() != 0) {
        data_ov000_021b5df4 = 0;
        return 1;
    }
    return 0;
}
