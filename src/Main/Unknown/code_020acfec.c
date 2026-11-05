#include "Main/Unknown/code_020acfec.h"

#include "Main/Unknown/code_020acff4.h"
#include "Main/Unknown/code_020ad028.h"
#include "Main/Unknown/code_020ad230.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on

void func_020acff4(void) {
    Unk020ad344 *v1;
    func_020ad028();
    v1 = data_0217b340;
    func_02124c30(v1->mUnk_6c, v1->mUnk_a8, v1->mUnk_74, &v1->mUnk_4b4, v1->mUnk_68);
}

#pragma thumb off

#pragma thumb on
u32 func_020acfec(u32 arg0) {
    u32 value0 = arg0;
    u32 value3;
    value3 = (u32) &func_020ad230;
    value0 = (u32) func_020ad230(value0);
    return value0;
}
#pragma thumb off
