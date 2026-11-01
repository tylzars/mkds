#include "03/code_021d11a0.h"
#include "03/code_021cf5ac.h"

u32 func_ov003_021d11a0(void) {
    if (data_ov003_021da2ac->mUnk_a90 == 5) {
        data_ov003_021da2ac->mUnk_a90 = 6;
        func_ov003_021cf69c();
        return 1;
    }
    return 0;
}
