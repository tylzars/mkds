#include "Main/Unknown/code_020d7d80.h"

#pragma thumb on

void func_020d7d80(Unk020e0144 *follower) {
    Unk020e0144_00 *path;
    int index;
    int segmentCount;
    int byteOffset;
    Unk020e0144_00_0 *segment;
    path = follower->mUnk_00;
    segmentCount = path->mUnk_04;
    index = 0;
    if (0 < segmentCount) {
        byteOffset = 0;
        do {
            segment = OFFSET_PTR(Unk020e0144_00_0, path->mUnk_00, byteOffset);
            segment->mUnk_30 = segment->mUnk_40;
            segment->mUnk_34 = segment->mUnk_44;
            byteOffset = byteOffset + 0x54;
            index = index + 1;
        } while (index < segmentCount);
    }
}

#pragma thumb off
