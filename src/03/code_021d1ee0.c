#include "03/code_021d1dd0.h"
#include "registers.h"
#include "03/code_021d1da8.h"
#include "03/code_021d3488.h"
#include "code_02147cd8.h"
#include "code_0214a348.h"
#include "code_0214a390.h"

// Fade kinds: 0 from black, 1 to black, 2 from white, 3 to white.
u32 StartBlendBrightnessFade(s32 kind, s32 screen, u32 plane, u16 frameCount) {
    s8 startLevels[4] = {-0x10, 0x00, 0x10, 0x00};
    BlendBrightnessFadeSlot *slot;

    if (screen == 1) {
        slot = gBlendBrightnessFadeSlots;
    } else {
        slot = gBlendBrightnessFadeSlots + 1;
    }
    if (slot->mEnabled != 0) {
        return 0;
    }
    if (screen == 1) {
        G2x_SetBlendBrightness_(&reg_G2S_DB_BLDCNT, plane, startLevels[kind]);
    } else {
        G2x_SetBlendBrightness_(&reg_G2_BLDCNT, plane, startLevels[kind]);
    }
    slot->mTask = AddTask(1, AdvanceBlendBrightnessFade, slot, 200);
    slot->mFrames = 0;
    slot->mKind = kind;
    slot->mFrameCount = frameCount;
    slot->mEnabled = 1;
    return 1;
}
