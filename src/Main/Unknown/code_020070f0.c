#include "Main/Unknown/code_020070f0.h"
#include "Main/Unknown/code_02007624.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/code_02007000.h"

#pragma thumb on

u32 func_02007138(u32 a) {
    if ((a >= 1) && (a <= 15)) {
        return 1;
    }
    return 0;
}

void func_02007120(u32 a, u16 b) {
    u16 v1[1];
    v1[0] = b;
    func_02007cf8(a, 0xd, v1);
}

u32 func_02007114(void) {
    return (u32) data_0216f3cc[0];
}

#pragma thumb off

#pragma thumb on

void func_020070fc(void) {
    data_0216f3cc[0]++;
    if (data_0216f3cc[0] == 0) {
        data_0216f3cc[0]++;
    }
}

void func_020070f0(void) {
    data_0216f3cc[0] = 0;
}

#pragma thumb off
