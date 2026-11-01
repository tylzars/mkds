#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_020a1748.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"

u16 func_020a119c(void) {
    s32 i;
    s32 v1;
    s32 n;
    s32 v;

    v1 = 0;
    n = data_021759c0->mUnk_3d0;
    for (i = 0; i < n; i++) {
        v = data_0217b1fc->mUnk_000[(u16) i].mUnk_4c;
        if (v <= 0) {
            v = 0;
        }
        v1 += (u16) v;
    }
    return v1;
}

u16 func_020a1180(void) {
    return data_0217b1fc->mUnk_3ac;
}

u16 func_020a1154(u16 a) {
    s32 v;

    v = data_0217b1fc->mUnk_000[a].mUnk_4c;
    if (v <= 0) {
        v = 0;
    }
    return v;
}

void func_020a10f0(u16 a, s32 b) {
    data_0217b1fc->mUnk_000[a].mUnk_4c += b;
    if (b > 0) {
        func_020a1b6c(a);
    } else if (b < 0) {
        func_020a19f8(a);
    }
}
