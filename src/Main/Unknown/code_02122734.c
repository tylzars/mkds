#include "Main/Unknown/code_02122734.h"
#include "00/code_021832d8.h"

s32 GetPackedIndex(s32 index) {
    return gWiFiSession->mPackedIndices[index];
}

s32 GetIndexOfPackedIndex(u8 packedIndex) {
    s8 i;
    for (i = 0; i < 4; i++) {
        if (packedIndex == gWiFiSession->mPackedIndices[i]) {
            return i;
        }
    }
    return -1;
}
