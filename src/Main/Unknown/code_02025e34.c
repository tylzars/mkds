#include "Main/Unknown/code_02025e34.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/unk_02153000.h"

#pragma thumb on
s32 func_02025e60(s32 a) {
    s32 r = -1;
    switch (func_02029930()->mUnk_c8) {
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

s32 func_02025e34(u32 a) {
    s32 i = 0;
    s32 r = -1;
    if (a != 0x24) {
        for (; i < 0x24; i++) {
            if (a == data_0215336c[i]) {
                r = i;
                break;
            }
        }
    }
    return r;
}
#pragma thumb off
