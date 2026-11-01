#include "00/code_0218e3c4.h"
#include "00/code_0218e56c.h"
#include "00/code_021a8db8.h"
#include "00/code_021a911c.h"
#include "00/unk_021b5000.h"
#include "00/code_021a9018.h"
#include "00/code_021a9088.h"
#include "00/code_021a90a0.h"
#include "00/code_021a9104.h"
#include "code_0214d018.h"

#pragma opt_propagation off

s32 func_ov000_0218e3c4(s32 param_1, s32 param_2, s32 param_3, void *param_4, s32 *param_5) {
    func_0214d168(param_4, 0, *param_5);
    return func_ov000_0218e56c(0, -1);
}

// non-matching: the byte copy loop has its source in r5 and its destination in r6, swapped here (same instructions
// otherwise)
s32 func_ov000_0218e3e4(s32 param_1, void *param_2, s32 param_3, s32 param_4, void *param_5, s32 param_6) {
    Unk0218e3c4 b;
    Unk0218e3c4 *a = param_5;
    b = *a;
    b.mUnk_00 = param_6;
    return func_ov000_0218e56c(func_ov000_021a9018(param_1, param_2, param_3, param_4, &b), -1);
}

s32 func_ov000_0218e420(s32 param_1, void *param_2, s32 param_3, s32 param_4) {
    return func_ov000_0218e56c(func_ov000_021a9088(param_1, param_2, param_3, param_4), -1);
}

s32 func_ov000_0218e438(s32 param_1, void *param_2, s32 param_3, s32 param_4, void *param_5, s32 *param_6) {
    u8 *a = param_5;
    s32 *b = param_6;
    s32 c;
    *a = *b;
    c = func_ov000_021a90a0(param_1, param_2, param_3, param_4, a);
    *b = *a;
    return func_ov000_0218e56c(c, -1);
}

s32 func_ov000_0218e460(s32 param_1, void *param_2, s32 param_3, s32 param_4) {
    return func_ov000_0218e56c(func_ov000_021a9104(param_1, param_2, param_3, param_4), -1);
}

s32 func_ov000_0218e478(s32 param_1, void *param_2, s32 *param_3) {
    u8 *a = param_2;
    s32 *b = param_3;
    s32 c = *b;
    s32 d;
    *a = c;
    d = func_ov000_021a8e18((Unk021a6fa8 *) param_1, (Unk021a8e18 *) a, c);
    *b = *a;
    return func_ov000_0218e56c(d, -1);
}
