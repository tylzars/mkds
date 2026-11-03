#include "code_02015eb8.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"

s32 func_02015f90(void) {
    return 0;
}

s32 func_02015f88(void) {
    return -1;
}

s32 func_02015f80(void) {
    return 0;
}

s32 func_02015f78(void) {
    return -1;
}

void func_02015ef4(Unk02015eb8 *a) {
    u32 v;

    v = a->mUnk_00;
    if ((v & 4) == 0) {
        if ((v & 2) == 0) {
            func_01ff9048(0x19, a->mUnk_28, 0xc);
        } else {
            func_01ff9048(0x1c, a->mUnk_4c, 3);
        }
    } else if ((v & 2) == 0) {
        func_01ff9048(0x1a, a->mUnk_28, 9);
    }
    if ((a->mUnk_00 & 1) == 0) {
        func_01ff9048(0x1b, &a->mUnk_04, 3);
    }
}

void func_02015eb8(Unk02015eb8 *a, u32 *b, u32 c, u32 d) {
    if (d & 4) {
        a->mUnk_00 |= 1;
    } else {
        a->mUnk_04 = b[0];
        a->mUnk_08 = b[1];
        a->mUnk_0c = b[2];
    }
    a->mUnk_00 |= 0x18;
}
