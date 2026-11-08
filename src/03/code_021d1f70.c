#include "03/code_021d1f70.h"
#include "registers.h"

#include "03/code_021d1da8.h"
#include "03/code_021d27d8.h"
#include "03/unk_021da000.h"
#include "code_0214a390.h"

void InitBlendBrightnessFadeSlotsFaded(void) {
    gBlendBrightnessFadeSlots = AllocZeroedExpHeapBlock(0x18, 4);
    G2x_SetBlendBrightness_(&reg_G2_BLDCNT, 0x3f, 0x10);
    G2x_SetBlendBrightness_(&reg_G2S_DB_BLDCNT, 0x3f, 0x10);
}

void FreeBlendBrightnessFadeSlots(void) {
    FreeExpHeapBlockAndClearPointer(&gBlendBrightnessFadeSlots);
}

u8 IsBlendBrightnessFadeSlotBusy(int screen) {
    BlendBrightnessFadeSlot *slot;
    if (screen == 1) {
        slot = gBlendBrightnessFadeSlots;
    } else {
        slot = gBlendBrightnessFadeSlots + 1;
    }
    return slot->mEnabled;
}
