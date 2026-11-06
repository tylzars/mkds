#include "Main/Unknown/code_020ad268.h"
#include "Main/Unknown/code_020ad2dc.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma optimize_for_size on
#pragma thumb on

void AdvanceTitleBlend(void) {
    s32 n;
    s32 m;

    n = gTitleScene->mBlendFrames++;
    if (n < 30) {
        func_020ad2f0(4, 8, 0, 16);
    } else if (n < 47) {
        m = n - 30;
        func_020ad2f0(4, 8, m, 16 - m);
    } else if (n < 107) {
        func_020ad2f0(0, 0, 0, 0);
    } else {
        func_020ad2f0(0, 0, 0, 0);
        func_020ad2dc(1);
        gTitleScene->mBlendDone = TRUE;
        gTitleScene->mBlendFrames--;
    }
}

#pragma thumb off
