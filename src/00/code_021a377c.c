#include "00/code_02188720.h"
#include "00/code_021a377c.h"
#include "00/code_02188000.h"
#include "00/code_021a6fa8.h"
#include "00/code_021a86bc.h"

BOOL func_ov000_021a377c(void) {
    Unk021b5df4 *p = data_ov000_021b5df4;
    if (p == NULL) {
        return TRUE;
    }
    if (p->mUnk_04 == 4) {
        p->mUnk_04 = 5;
    } else if (p->mUnk_04 != 5) {
        return TRUE;
    }
    if (func_ov000_021a86e8() != 0) {
        return FALSE;
    }
    if (func_ov000_02188720() != 0) {
        data_ov000_021b5df4 = NULL;
        return TRUE;
    }
    return FALSE;
}
