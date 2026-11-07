#include "Main/Unknown/code_0209b60c.h"
#include "01/code_0219b250.h"

// Current frame of the .nsbca animation in slot 0: the whole-frame part of its 20.12 position.
u32 GetMapObjectModelNsbcaFrameIndex(Unk0219b250 *model) {
    u32 value0 = model->mNsbcaAnimation->mUnk_0c;
    value0 = (value0 << 4);
    value0 = (value0 >> 16);
    return value0;
}

u32 GetMapObjectModelNsbtpFrameIndex(Unk0219b250 *model) {
    u32 value0 = model->mNsbtpAnimation->mUnk_0c;
    value0 = (value0 << 4);
    value0 = (value0 >> 16);
    return value0;
}
