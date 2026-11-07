#include "Main/Unknown/code_020cb11c.h"
#include "Main/Unknown/code_020cb1c4.h"
#include "Main/Unknown/unk_02175628.h"

#pragma optimize_for_size on

BOOL func_020cb194(u16 *pair) {
    if (func_020cb1c4(pair) == 0 && pair[8] < 5) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_020cb170(u16 *pair) {
    if (pair[6] == 0 && pair[2] != 0) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_020cb13c(u16 *pair) {
    if (func_020cb194(pair) == FALSE && func_020cb170(pair) != FALSE) {
        return TRUE;
    }
    return FALSE;
}

s32 func_020cb11c(u32 slotIndex) {
    return func_020cb13c(&data_02175628[slotIndex].mPairX);
}
