#include "Main/Unknown/code_02095f38.h"
#include "Main/Unknown/code_02095fec.h"
#include "Main/Unknown/code_020968c0.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/unk_0217b000.h"

void func_02095f9c(void) {
    Unk0209bf70 *o;
    o = func_0209bf70(func_0209702c, func_02096f54, func_02096df0, 0, 1, 0x16d);
    o->mUnk_28 = 0x1b0;
}

u32 func_02095f7c(void) {
    return func_0209bef0(func_02096d68, func_02096a04, 0);
}

u32 func_02095f5c(void) {
    return func_0209bf48(func_020968f4, func_02095fec, 0);
}

s32 func_02095f38(Unk0217b498_00 *a) {
    if (a->mUnk_b0 == 1 || a->mUnk_b0 == 4) {
        return 1;
    }
    return 0;
}
