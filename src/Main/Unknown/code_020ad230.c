#include "Main/Unknown/code_020ad230.h"
#include "Main/Unknown/code_020ad268.h"
#include "Main/Unknown/code_020adad0.h"
#include "Main/Unknown/code_020adaf8.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on

u32 func_020ad264(u32 p0) {
    return p0;
}

void UpdateTitleState0(void) {
    int v1;
    int v2;
    v2 = 0;
    if (gTitleScene->mBlendDone == FALSE) {
        v2 = 0x6b;
    }
    v1 = GetTitleStateFrames();
    if (v1 >= v2) {
        SetTitleState((u32) 1, (u32) 8);
    }
    AdvanceTitleBlend();
}

u32 func_020ad230(u32 p0) {
    return p0;
}

#pragma thumb off
