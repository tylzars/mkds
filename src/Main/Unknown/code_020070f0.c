#include "Main/Unknown/code_020070f0.h"
#include "Main/Unknown/code_02007624.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/code_02007000.h"

#pragma thumb on

u32 IsChildIndexInRange(u32 a) {
    if ((a >= 1) && (a <= 15)) {
        return 1;
    }
    return 0;
}

void func_02007120(u32 a, u16 b) {
    u16 value[1];
    value[0] = b;
    func_02007cf8(a, 0xd, value);
}

u32 GetRequestId(void) {
    return gRequestId[0];
}

#pragma thumb off

#pragma thumb on

void AdvanceRequestId(void) {
    gRequestId[0]++;
    if (gRequestId[0] == 0) {
        gRequestId[0]++;
    }
}

void ResetRequestId(void) {
    gRequestId[0] = 0;
}

#pragma thumb off
