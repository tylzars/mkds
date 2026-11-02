#include "Main/Unknown/code_020cb11c.h"
#include "Main/Unknown/code_020cb1c4.h"

#pragma optimize_for_size on

BOOL func_020cb194(u16 *a) {
    if (func_020cb1c4(a) == 0 && a[8] < 5) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_020cb170(u16 *a) {
    if (a[6] == 0 && a[2] != 0) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_020cb13c(u16 *a) {
    if (func_020cb194(a) == FALSE && func_020cb170(a) != FALSE) {
        return TRUE;
    }
    return FALSE;
}

s32 func_020cb11c(u32 a) {
    return func_020cb13c(&data_02175628[a].mUnk_48);
}
