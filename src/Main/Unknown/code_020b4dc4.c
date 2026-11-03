#include "Main/Unknown/code_0207a68c.h"
#include "Main/Unknown/code_020b4dc4.h"
#include "Main/Unknown/unk_021759c0.h"

u32 func_020b4df8(void) {
    return ((u32) data_021759c0->mUnk_08);
}

u32 func_020b4dc4(int a) {
    int v1;
    u32 v2;
    v1 = func_020b4df8();
    if ((v1 == 1) && (a != 0)) {
        return 1;
    }
    v2 = func_0207a68c(a);
    return v2;
}
