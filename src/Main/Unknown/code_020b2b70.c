#include "Main/Unknown/code_020b2b70.h"
#include "Main/Unknown/code_02055000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020b19f8.h"
#include "Main/Unknown/code_020b24e4.h"
#include "Main/Unknown/code_020b2a4c.h"
#include "Main/Unknown/code_020b2b54.h"
#include "Main/Unknown/code_020b2c54.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020b33d8.h"
#include "Main/Unknown/code_020c3da0.h"
#include "Main/Unknown/code_020c5db0.h"
#include "Main/Unknown/code_020c5e30.h"
#include "Main/Unknown/code_020c7000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "01/code_021956dc.h"

#pragma optimize_for_size on
s32 func_020b2c24(void) {
    if (func_020b2c54() != 0) {
        return data_021759d4->mUnk_10;
    }
    return 0;
}

s32 func_020b2bf0(void) {
    if (data_0217aa08->mUnk_28 != 0) {
        return 1;
    }
    return func_020b2c24();
}

#pragma thumb on
u32 func_020b2bc8(void) {
    if (func_020b2a4c() != 0 || (func_020b24e4() == 2 && func_020b33f4() > 0xf0)) {
        return 1;
    }
    return 0;
}

u32 func_020b2b70(void) {
    if (func_020b33d8() != 0 && func_020b2bc8() != 0 && func_020c5dc4() != 0 && func_020c3da0() == 0 &&
        func_020c70bc() == 0 && func_020c70a0() == 0 && func_020b1a20() == 0 &&
        (func_020b2ec0() != 0 || func_02055b1c() == 0)) {
        return 1;
    }
    return 0;
}
#pragma thumb off
