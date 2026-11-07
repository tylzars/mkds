#include "Main/Unknown/code_020b2e34.h"
#include "Main/Unknown/code_020b2000.h"
#include "Main/Unknown/code_020b29c4.h"
#include "Main/Unknown/code_020b1de4.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020c3db4.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_020b2ecc.h"

#pragma thumb on

void func_020b2e64(u32 a) {
    int v1;
    int v2;
    v1 = func_020b2ec0();
    v2 = func_020b29c4();
    if (v2 != 0) {
        func_020b2f88(a);
    }
    v2 = func_020b2ec0();
    if ((v1 == 0) && (v2 != 0)) {
        func_02105d70();
    }
}

u32 func_020b2e58(void) {
    return (gChoisesS->mPrevOpenDuringRace);
}

int func_020b2e34(void) {
    int v1;
    int v2;
    v2 = gChoisesS->mPickedValue;
    if ((v2 == 2) && (v1 = func_020c3db4(), v1 != 0)) {
        v2 = 7;
    }
    return v2;
}

#pragma thumb off
