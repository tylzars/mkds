#include "00/code_0218d818.h"
#include "00/code_02197e8c.h"
#include "00/code_021985ec.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_02134398.h"
#include "00/code_02198a8c.h"
#include "00/code_02198ba8.h"
#include "00/code_02198d04.h"
#include "00/code_021981d0.h"

BOOL func_ov000_021986ac(Gt2Connection *a, u32 b) {
    if (a->mUnk_0c < 5) {
        BOOL r = FALSE;
        if (a->mUnk_10 != 0) {
            if (a->mTimeSinceCreateLimit != 0 && b - a->mCreateTime > a->mTimeSinceCreateLimit) {
                r = TRUE;
            }
        } else if (a->mUnk_0c < 4) {
            if (b - a->mCreateTime > 60000) {
                r = TRUE;
            }
        }
        if (r != FALSE) {
            func_ov000_02198b8c(a);
            func_ov000_02198514(a);
            if (Gt2SetResultAndCallResultCallback(a, 6, NULL, 0) == 0) {
                return FALSE;
            }
        }
    }
    return TRUE;
}

BOOL func_ov000_02198658(Gt2Connection *a, u32 b) {
    int n;
    int i;
    Unk02198af4 *p;
    n = DarrayGetCount((u32 *) a->mUnk_60);
    for (i = 0; i < n; i++) {
        p = DarrayGetElement(a->mUnk_60, i);
        if (b - p->mUnk_0c > 1000) {
            if (func_ov000_02198af4(a, p) == 0) {
                return FALSE;
            }
        }
    }
    return TRUE;
}

BOOL func_ov000_0219861c(Gt2Connection *a, u32 b) {
    if (a->mUnk_90 == 0) {
        return TRUE;
    }
    if (b - a->mUnk_94 > 100) {
        if (func_ov000_02198c08(a) == 0) {
            return FALSE;
        }
    }
    return TRUE;
}

BOOL func_ov000_021985ec(Gt2Connection *a, u32 b) {
    if (b - a->mLastSendTime > 30000) {
        if (func_ov000_02198d04((u32) a) == 0) {
            return FALSE;
        }
    }
    return TRUE;
}
