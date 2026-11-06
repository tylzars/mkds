#include "Main/Unknown/code_0209b60c.h"
#include "01/code_0219b250.h"

// Current frame of the .nsbca animation in slot 0: the whole-frame part of its 20.12 position.
u32 GetMapObjectModelNsbcaFrameIndex(Unk0219b250 *arg0) {
    u32 value0 = arg0->mNsbcaAnimation->mUnk_0c;
    value0 = (value0 << 4);
    value0 = (value0 >> 16);
    return value0;
}

u32 func_0209b60c(Unk0219b250 *arg0) {
    u32 value0 = arg0->mNsbtpAnimation->mUnk_0c;
    value0 = (value0 << 4);
    value0 = (value0 >> 16);
    return value0;
}
