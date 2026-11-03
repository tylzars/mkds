#include "00/code_021a3e5c.h"
#include "00/code_021a39d8.h"

u32 func_ov000_021a3e5c(Unk021a3a18 *a, int b) {
    int v1;
    int v2;
    int *v4;
    v1 = 0;
    do {
        if (b == a->mUnk_d8[v1]) {
            return 1;
        }
        v1 = v1 + 1;
    } while (v1 < 10);
    v2 = (a->mUnk_100 + 1) % (10);
    v4 = &a->mUnk_100;
    *v4 = v2;
    a->mUnk_d8[*v4] = b;
    return 0;
}
