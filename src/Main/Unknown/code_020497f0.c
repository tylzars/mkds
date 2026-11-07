#include "Main/Unknown/code_020497f0.h"
#include "Main/Unknown/unk_02175000.h"

#include "code_021488e8.h"
#include "registers.h"

u32 func_02049838(void) {
    return (gSceneRunState->mUnk_10c);
}

u32 func_02049820(void) {
    u32 value0;
    value0 = 0x27fffa8u;
    value0 = *(const u16 *) ((value0) + (0));
    value0 = (value0) & (0x8000u);
    value0 = ((s32) value0 >> 15);
    return value0;
}

void func_02049808(s32 a) {
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, a);
}

void func_020497f0(s32 a) {
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, a);
}
