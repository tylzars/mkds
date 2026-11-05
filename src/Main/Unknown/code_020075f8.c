#include "Main/Unknown/code_020075f8.h"
#include "Main/Unknown/code_02008908.h"
#include "Main/Unknown/code_0200c0d8.h"
#include "Main/Unknown/unk_0216f000.h"

#pragma thumb on

int func_020075f8(u8 a, u32 b) {
    u8 v1[8];
    v1[0] = a;
    func_0200c3a4(v1, (u8 *) data_0216fdac);
    return func_02008908(6, b, (u32) data_0216fdac);
}

#pragma thumb off
