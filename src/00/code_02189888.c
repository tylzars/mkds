#include "00/code_02188ec0.h"
#include "00/code_0218973c.h"
#include "00/code_02189888.h"
#include "00/code_021898dc.h"

u32 func_ov000_02189888(Unk02188ec0 *a) {
    u8 v1;
    int v2;
    u32 v3;
    if ((a->mUnk_d16 != 0) && (v2 = func_ov000_0218973c(2), v2 != 0)) {
        v1 = func_ov000_02189df8(0);
        a->mUnk_d11 = v1;
        return 5;
    }
    if (a->mUnk_d0b_4 < 1) {
        v3 = func_ov000_02189c04(a);
        return v3;
    }
    return 6;
}
