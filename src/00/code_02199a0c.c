#include "00/code_02199a0c.h"
#include "00/code_02199ad8.h"
#include "00/code_02197e58.h"

u32 func_ov000_02199a0c(Gt2Connection *a, int b, u32 c, u32 d) {
    int v1;
    a->mUnk_66 = a->mUnk_66 + 1;
    if (b == 0) {
        v1 = func_ov000_02199dd0(a, c, d);
        if (v1 == 0) {
            return 0;
        }
    } else if (b == 1) {
        v1 = func_ov000_02199d4c(a, c, d);
        if (v1 == 0) {
            return 0;
        }
    } else if (b == 2) {
        v1 = func_ov000_02199c98(a, c, d);
        if (v1 == 0) {
            return 0;
        }
    } else if (b == 3) {
        v1 = func_ov000_02199bb4(a, c, d);
        if (v1 == 0) {
            return 0;
        }
    } else if (b == 4) {
        v1 = func_ov000_02199b70(a);
        if (v1 == 0) {
            return 0;
        }
    } else if (b == 5) {
        v1 = func_ov000_02199b14(a, c, d);
        if (v1 == 0) {
            return 0;
        }
    } else if ((b == 6) && (v1 = func_ov000_02199ad8(a), v1 == 0)) {
        return 0;
    }
    return 1;
}
