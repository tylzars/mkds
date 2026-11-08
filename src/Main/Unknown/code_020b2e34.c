#include "Main/Unknown/code_020b2e34.h"
#include "Main/Unknown/code_020b2000.h"
#include "Main/Unknown/code_020b29c4.h"
#include "Main/Unknown/code_020b1de4.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020c3db4.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_020b2ecc.h"

#pragma thumb on

void func_020b2e64(u32 openFlag) {
    int wasOpen;
    int v2;
    wasOpen = GetChoisesSOpenDuringRace();
    v2 = func_020b29c4();
    if (v2 != 0) {
        func_020b2f88(openFlag);
    }
    v2 = GetChoisesSOpenDuringRace();
    if ((wasOpen == 0) && (v2 != 0)) {
        func_02105d70();
    }
}

u32 GetChoisesSPrevOpenDuringRace(void) {
    return (gChoisesS->mPrevOpenDuringRace);
}

int func_020b2e34(void) {
    int v1;
    int pickedValue;
    pickedValue = gChoisesS->mPickedValue;
    if ((pickedValue == 2) && (v1 = func_020c3db4(), v1 != 0)) {
        pickedValue = 7;
    }
    return pickedValue;
}

#pragma thumb off
