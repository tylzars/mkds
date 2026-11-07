#include "Main/Unknown/code_0205905c.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_0205928c.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma opt_rebuildconditionals off

static inline u32 func_0205905c_inline(void) {
    if (data_0217aa00 == NULL) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

static inline s32 func_0205905c_inline2(void) {
    BOOL r = FALSE;
    if (func_0205905c_inline() != 0 && data_0217aa00->mUnk_0004 != 13) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_0205905c_inline3(void) {
    BOOL r = FALSE;
    if (func_0205905c_inline2() && !(data_0217aa00->mUnk_0454 & 0x80)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_0205905c_inline4(void) {
    BOOL r = FALSE;
    if (func_0205905c_inline3() && data_0217aa00->mUnk_0008 != 9) {
        r = TRUE;
    }
    return r;
}

#pragma thumb on

BOOL func_020591cc(void) {
    BOOL r;

    r = FALSE;
    if (!func_0205905c_inline2()) {
        return TRUE;
    }
    func_02046b40(&data_0217aa00->mUnk_1608);
    if (!func_0205905c_inline4()) {
        if (func_0205905c_inline() == 1 && data_0217aa00->mUnk_0044.mChildCount == 0) {
            func_02050e60(7);
        }
    }
    if (data_0217aa00->mUnk_1608.mState == 0xf) {
        r = TRUE;
    }
    return r;
}

s32 func_020591c4(void) {
    return func_020591cc();
}

s32 func_020591bc(void) {
    return func_020591cc();
}

u32 func_0205910c(void) {
    if (func_0205905c_inline4()) {
        return 3;
    }
    if (!func_0205905c_inline2()) {
        return 1;
    }
    switch (func_0205905c_inline()) {
        case 1:
            return func_02059700();
        case 2:
            return func_020595e8(3, NULL, NULL);
        default:
            return 3;
    }
}

u32 func_0205905c(void) {
    if (func_0205905c_inline4()) {
        return 3;
    }
    if (!func_0205905c_inline2()) {
        return 1;
    }
    switch (func_0205905c_inline()) {
        case 1:
            return func_02059700();
        case 2:
            return func_020595e8(2, NULL, NULL);
        default:
            return 3;
    }
}

#pragma thumb off
