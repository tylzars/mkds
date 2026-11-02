#include "Main/Unknown/code_020f1180.h"

#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f1258.h"

BOOL func_020f1180(Unk020f5d6c *a, u32 b) {
    u16 i;
    u32 r;
    u32 n;
    int v;

    r = 0;
    n = data_021759c0->mUnk_3d0;
    for (i = 0; i < n; i++) {
        v = func_020f1258((s32) a, i, r, b);
        if (v != 0) {
            r = v;
        }
    }
    return r != 0;
}
