#include "Main/Unknown/code_02122734.h"
#include "00/code_021832d8.h"

s32 func_02122778(s32 a) {
    return gWiFiSession->mPackedIndices[a];
}

s32 func_02122734(u8 a) {
    s8 i;
    for (i = 0; i < 4; i++) {
        if (a == gWiFiSession->mPackedIndices[i]) {
            return i;
        }
    }
    return -1;
}
