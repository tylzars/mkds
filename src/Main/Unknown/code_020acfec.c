#include "Main/Unknown/code_020acfec.h"

#include "Main/Unknown/code_020acff4.h"

#pragma thumb on

void func_020acff4(void) {
    int v1;
    func_020ad028();
    v1 = *(s32 *) &data_0217b340;
    func_02124c30((void *) (*(u32 *) (v1 + 0x6c)), (void *) (*(u32 *) (v1 + 0xa8)), (void *) (*(u32 *) (v1 + 0x74)),
                  (void *) (v1 + 0x4b4), (void *) (*(u32 *) (v1 + 0x68)));
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
