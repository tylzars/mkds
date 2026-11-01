#include "00/code_021985ec.h"
#include "00/code_0218d000.h"
#include "00/code_0218dc44.h"
#include "00/code_02198a8c.h"
#include "00/code_02198ba8.h"
#include "00/code_02198d04.h"
#include "00/code_021981d0.h"

int func_ov000_021986ac(Unk02197fe8 *a, u32 b) {
    if (a->mUnk_0c < 5) {
        int r = 0;
        if (a->mUnk_10 != 0) {
            if (a->mUnk_20 != 0 && b - a->mUnk_1c > a->mUnk_20) {
                r = 1;
            }
        } else if (a->mUnk_0c < 4) {
            if (b - a->mUnk_1c > 60000) {
                r = 1;
            }
        }
        if (r != 0) {
            func_ov000_02198b8c(a);
            func_ov000_02198514(a);
            if (func_ov000_021982f4(a, 6, 0, 0) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int func_ov000_02198658(Unk02197fe8 *a, u32 b) {
    int n;
    int i;
    Unk02198af4 *p;
    n = func_ov000_0218dc44((u32 *) a->mUnk_60);
    for (i = 0; i < n; i++) {
        p = func_ov000_0218dbf8(a->mUnk_60, i);
        if (b - p->mUnk_0c > 1000) {
            if (func_ov000_02198af4(a, p) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int func_ov000_0219861c(Unk02197fe8 *a, u32 b) {
    if (a->mUnk_90 == 0) {
        return 1;
    }
    if (b - a->mUnk_94 > 100) {
        if (func_ov000_02198c08(a) == 0) {
            return 0;
        }
    }
    return 1;
}

int func_ov000_021985ec(Unk02197fe8 *a, u32 b) {
    if (b - a->mUnk_88 > 30000) {
        if (func_ov000_02198d04((u32) a) == 0) {
            return 0;
        }
    }
    return 1;
}
