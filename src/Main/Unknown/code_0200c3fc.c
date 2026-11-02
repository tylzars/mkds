#include "Main/Unknown/code_0200c3fc.h"
#include "03/code_021b94b8.h"
#include "Main/Unknown/unk_0216f000.h"

#pragma thumb on

void func_0200c448(s32 a) {
    data_0216fdf8.mUnk_00 = a - 2;
    data_0216fdf8.mUnk_04 = 0x1e / data_0216fdf8.mUnk_00;
    data_0216fdf8.mUnk_08 = 0x1e;
}

#pragma thumb off

#pragma thumb on
void func_0200c430(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value3;
    value1 = (u32) &data_0216fdf4;
    *(u32 *) ((value1) + 0u) = value0;
    value1 = 0u;
    value2 = 0x21cu;
    value3 = (u32) &func_0214d168;
    func_0214d168((void *) value0, (u8) value1, value2);
}
#pragma thumb off

#pragma thumb on

void func_0200c3fc(s32 a) {
    s32 i;

    if (data_0216fdf4 != NULL) {
        i = a - 1;
        func_0214d168(&data_0216fdf4->mUnk_000[i * 0x20], 0, 0x1e);
        data_0216fdf4->mUnk_1e0[i] = 0;
    }
}

#pragma thumb off
