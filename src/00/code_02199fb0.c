#include "00/code_02199fb0.h"
#include "00/code_021985ec.h"
#include "00/code_021988e8.h"
#include "00/code_02198a8c.h"
#include "00/code_02197e8c.h"

u32 func_ov000_02199fb0(int c, u32 d, u32 e) {
    Gt2Connection *a = (Gt2Connection *) c;
    s32 b = a->mUnk_0c;
    if (b < 5) {
        if (a->mUnk_10 != 0) {
            func_ov000_02198514(a);
            if (Gt2SetResultAndCallResultCallback(a, d, NULL, 0) == 0) {
                return 0;
            }
        } else {
            if (b == 4) {
                a->mUnk_14 = 1;
            }
            func_ov000_02198514(a);
        }
    } else if (b != 7) {
        func_ov000_02198514(a);
        if (func_ov000_021981d0(a, (void *) e) == 0) {
            return 0;
        }
    }
    return 1;
}
