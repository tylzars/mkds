#include "Main/Unknown/code_020ad230.h"
#include "Main/Unknown/code_020ad268.h"
#include "Main/Unknown/code_020adad0.h"
#include "Main/Unknown/code_020adaf8.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on

u32 func_020ad264(u32 value) {
    return value;
}

void UpdateTitleState0(void) {
    int stateFrames;
    int waitFrames;
    waitFrames = 0;
    if (gTitleScene->mBlendDone == FALSE) {
        waitFrames = 0x6b;
    }
    stateFrames = GetTitleStateFrames();
    if (stateFrames >= waitFrames) {
        SetTitleState(1, 8);
    }
    AdvanceTitleBlend();
}

u32 func_020ad230(u32 value) {
    return value;
}

#pragma thumb off
