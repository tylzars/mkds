#include "Main/Unknown/code_0200b1b0.h"

#pragma thumb on

u32 func_0200b1b0(u32 param_1, struct Unk0217aa00_24 *param_2) {
    u32 v1;
    Unk02008934 *v2;
    if (16 <= param_1) {
        return 0;
    }
    v1 = ((s64) func_0200fca0());
    v2 = func_02008934(param_1);
    if (v2 == 0) {
        func_0200fcb4(v1);
        return 0;
    }
    func_0214d1fc(v2->mUnk_4c0, (void *) ((u32 *) (u32) param_2),
                  (u32) 0xc0);
    func_0200fcb4(v1);
    return 1;
}

#pragma thumb off
