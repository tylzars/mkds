#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02056158.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_02060004.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

u8 func_02056208(void) {
    u8 i;
    s32 m;
    u8 j;
    s32 v;

    m = 7;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            v = func_02060364(i, j);
            if (v == 9 || v < m) {
                m = v;
            }
            if (m == 9 || m < 5) {
                return 0;
            }
        }
    }
    switch (m) {
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 3;
        default:
            return 0;
    }
}

#pragma thumb off

void func_02056158(void *a) {
    data_0217aa04 = HeapAlloc(a, 0x10);
    if (data_021759c0->mUnk_00c == 3 || data_021759c0->mUnk_00c == 5) {
        data_0217aa04->mUnk_04 = HeapAllocAligned(a, 0x400, 0x20);
    } else {
        data_0217aa04->mUnk_04 = NULL;
    }
    data_0217aa04->mUnk_08 = 0;
    data_0217aa04->mUnk_0a = 0;
    data_0217aa04->mUnk_0c = 0x1000;
    data_0217aa04->mUnk_00 = 0;
    if (data_02175614.mUnk_00 == 0) {
        data_0217aa04->mUnk_00 = 0;
    }
}

