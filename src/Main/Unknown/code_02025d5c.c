#include "Main/Unknown/code_02025d5c.h"

#include "Main/Unknown/unk_02153000.h"

#pragma thumb on
u32 GetKartMessageIndex(u32 kartIndex) {
    u32 value0 = (u32) kartIndex;
    u32 byteOffset;
    byteOffset = (value0 << 2);
    value0 = (u32) &gKartMessageIndexTable;
    value0 = *(const u32 *) ((value0) + (byteOffset));
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 GetCourseMessageIndex(u32 courseId) {
    u32 value0 = (u32) courseId;
    u32 byteOffset;
    byteOffset = (value0 << 2);
    value0 = (u32) &gCourseMessageIndexTable;
    value0 = *(const u32 *) ((value0) + (byteOffset));
    return value0;
}
#pragma thumb off

#pragma thumb on

int func_02025d74(int a) {
    int v1;
    v1 = ((s32 *) &gCourseMessageIndexTable)[a];
    if (v1 != -1) {
        v1 = v1 + -0x1a;
    }
    return v1;
}

int func_02025d5c(int a) {
    int v1;
    v1 = ((s32 *) &gCourseMessageIndexTable)[a];
    if (v1 != -1) {
        v1 = v1 + 4;
    }
    return v1;
}

#pragma thumb off
