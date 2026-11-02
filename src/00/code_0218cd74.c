#include "00/code_0218cd74.h"

void func_ov000_0218cd74(u8 **arg0, const void *arg1, s32 arg2, s32 *arg3) {
    memcpy(*arg0, arg1, arg2);
    *arg3 = *arg3 + arg2;
    *arg0 = *arg0 + arg2;
    return;
}
