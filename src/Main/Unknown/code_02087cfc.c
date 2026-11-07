#include "Main/Unknown/code_02087cfc.h"

void func_02087cfc(void *animation, u32 entryIndex, u32 loopFlag) {
    u32 animationAddress = (u32) animation;
    u32 entryIndexCopy = entryIndex;
    u32 loopFlagCopy = loopFlag;
    u32 loopFlags;
    loopFlags = *(const u32 *) ((animationAddress) + (32));
    *(u32 *) ((loopFlags) + ((entryIndexCopy << 2))) = loopFlagCopy;
    *(u16 *) ((animationAddress) + (0)) = loopFlagCopy;
}
