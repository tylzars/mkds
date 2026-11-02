#include "Main/Unknown/code_0200b1b0.h"

#pragma thumb on

u32 func_0200b1b0(u32 a, struct Unk0217aa00_24 *b) {
    u32 v1;
    Unk02008934 *v2;
    if (16 <= a) {
        return 0;
    }
    v1 = ((s64) func_0200fca0());
    v2 = func_02008934(a);
    if (v2 == NULL) {
        func_0200fcb4(v1);
        return 0;
    }
    func_0214d1fc(v2->mUnk_4c0, (void *) ((u32 *) (u32) b), (u32) 0xc0);
    func_0200fcb4(v1);
    return 1;
}

#pragma thumb off
