#include "03/code_021d1dd0.h"
#include "registers.h"
#include "03/code_021d1da8.h"
#include "03/code_021d3488.h"
#include "code_02147cd8.h"
#include "code_0214a348.h"
#include "code_0214a390.h"

// placeholder: two objects of the original file that are not known yet; they only set the order of the tables below
u8 data_ov003_021d1e14_pad1[1];
u8 data_ov003_021d1e14_pad2[8];

void AdvanceBlendBrightnessFade(u32 task, BlendBrightnessFadeSlot *slot) {
    u8 bitsByKind[4] = {0x11, 0x10, 0x01, 0x00};
    s8 finalLevels[4] = {0x00, -0x10, 0x00, 0x10};
    s32 level;
    u8 bits;

    slot->mFrames++;
    level = FX_DivS32(slot->mFrames << 4, slot->mFrameCount);
    bits = bitsByKind[slot->mKind];
    if (bits & 1) {
        level = 0x10 - level;
    }
    if (bits & 0x10) {
        level = -level;
    }
    if (slot == gBlendBrightnessFadeSlots) {
        G2x_ChangeBlendBrightness_(&reg_G2S_DB_BLDCNT, level);
    } else {
        G2x_ChangeBlendBrightness_(&reg_G2_BLDCNT, level);
    }
    if (slot->mFrames >= slot->mFrameCount) {
        if (slot == gBlendBrightnessFadeSlots) {
            G2x_ChangeBlendBrightness_(&reg_G2S_DB_BLDCNT, finalLevels[slot->mKind]);
        } else {
            G2x_ChangeBlendBrightness_(&reg_G2_BLDCNT, finalLevels[slot->mKind]);
        }
        slot->mEnabled = 0;
        RequestTaskRemoval(1, task);
    }
}

u32 StartBlendBrightnessFadeWait(u16 frameCount) {
    BlendBrightnessFadeSlot *slot = gBlendBrightnessFadeSlots;

    if (slot->mEnabled != 0) {
        return 0;
    }
    slot->mTask = AddTask(1, AdvanceBlendBrightnessFadeWait, slot, 200);
    slot->mFrames = 0;
    slot->mFrameCount = frameCount;
    slot->mEnabled = 1;
    return 1;
}
