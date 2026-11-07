#include "Main/Unknown/code_02025e28.h"

#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/code_02029890.h"

#pragma thumb on
s32 func_02025e60(s32 a) {
    s32 r = -1;
    switch (GetRaceSetupCopy()->mMode) {
        case 0:
        case 1:
        case 3:
        case 5:
            r = data_usa_02153274[a];
            break;
        case 2:
            r = data_usa_02153240[a];
            break;
    }
    return r;
}

s32 FindKartTableIndex(u32 kartIndex) {
    s32 i = 0;
    s32 r = -1;
    if (kartIndex != 0x24) {
        for (; i < 0x24; i++) {
            if (kartIndex == gKartIndexTable[i]) {
                r = i;
                break;
            }
        }
    }
    return r;
}
#pragma thumb off

#pragma thumb on
u32 GetKartIndexAtTableIndex(u32 tableIndex) {
    u32 value0 = (u32) tableIndex;
    u32 byteOffset;
    byteOffset = (value0 << 2);
    value0 = (u32) &gKartIndexTable;
    value0 = *(const u32 *) ((value0) + (byteOffset));
    return value0;
}
#pragma thumb off
