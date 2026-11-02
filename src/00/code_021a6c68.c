#include "00/code_021a6c68.h"

#include "00/unk_021b5000.h"
#include "00/code_021a574c.h"
#include "code_02133048.h"
#include "code_0200fc8c.h"

u32 func_ov000_021a6ce4(void) {
    u32 a;
    Unk021b5f50 *b;
    u32 c;

    a = func_0200fca0();
    b = func_ov000_021a5b30();
    c = 0;
    if (b != NULL && b->mUnk_2260 == 9) {
        c = func_ov000_021a6c68();
    }
    func_0200fcb4(a);
    return c;
}

u8 func_ov000_021a6c90(void) {
    s32 a = 0;
    u32 b = data_ov000_021b5f80;
    s32 i;

    if (b > 16) {
        for (i = 0; i < 16; i++) {
            a += data_ov000_021b5f84[i];
        }
        a = a / 16;
    } else if (b != 0) {
        for (i = 0; i < (s32) b; i++) {
            a += data_ov000_021b5f84[i];
        }
        a = a / (s32) b;
    }
    return a;
}

s32 func_ov000_021a6c68(void) {
    u32 value = func_ov000_021a6c90();
    s32 level = 0;
    if (value >= 28) {
        level = 3;
    } else if (value >= 22) {
        level = 2;
    } else if (value >= 16) {
        level = 1;
    }
    return level;
}
