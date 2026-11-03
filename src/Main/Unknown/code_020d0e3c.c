#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020d0e3c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020d0ee8.h"
#include "Main/Unknown/code_020d0f78.h"

#pragma optimize_for_size on

#pragma thumb on
BOOL func_020d0ec4(void) {
    if (gCupPicture != NULL && func_020d0ee8() == 0) {
        return TRUE;
    }
    return FALSE;
}

void *func_020d0ea0(void) {
    if (func_020d0ec4() != FALSE) {
        return gCupPicture->mCupPictureNclr->mData;
    }
    return NULL;
}

void *func_020d0e7c(void) {
    if (func_020d0ec4() != FALSE) {
        return gCupPicture->mCupPictureNcgr->mData;
    }
    return NULL;
}

void *func_020d0e58(void) {
    if (func_020d0ec4() != FALSE) {
        return &gCupPicture->mCupPictureNscr->mData;
    }
    return NULL;
}
#pragma thumb off

s32 func_020d0e3c(void) {
    return func_020c0c2c(&data_0217b4a0, 0x1af);
}
