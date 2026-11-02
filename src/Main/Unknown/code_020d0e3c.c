#include "Main/Unknown/code_020d0e3c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020d0ee8.h"

#pragma optimize_for_size on

#pragma thumb on
s32 func_020d0ec4(void) {
    if (gCupPicture != 0 && func_020d0ee8() == 0) {
        return 1;
    }
    return 0;
}

void *func_020d0ea0(void) {
    if (func_020d0ec4() != 0) {
        return gCupPicture->mCupPictureNclr->mUnk_0c;
    }
    return 0;
}

void *func_020d0e7c(void) {
    if (func_020d0ec4() != 0) {
        return gCupPicture->mCupPictureNcgr->mUnk_14;
    }
    return 0;
}

void *func_020d0e58(void) {
    if (func_020d0ec4() != 0) {
        return &gCupPicture->mCupPictureNscr->mUnk_0c;
    }
    return 0;
}
#pragma thumb off

s32 func_020d0e3c(void) {
    return func_020c0c2c(&data_0217b4a0, 0x1af);
}
