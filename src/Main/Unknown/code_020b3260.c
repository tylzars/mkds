#include "Main/Unknown/code_020b3260.h"

#pragma thumb on

u32 GetChoisesSListCharsSize(int valueCount) {
    if (valueCount < 0) {
        return 0;
    }
    if (valueCount < 2) {
        return 0x1000;
    }
    return valueCount << 0xb;
}

#pragma thumb off
