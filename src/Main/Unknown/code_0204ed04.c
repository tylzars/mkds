#include "Main/Unknown/code_0204ed04.h"
#include "Main/Unknown/code_0200692c.h"
#include "Main/Unknown/code_02006380.h"
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200eddc.h"
#include "code_0214d018.h"

#pragma thumb on
u32 func_0204ee4c(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 value3;
    value2 = (u32) &data_0217aa00;
    value3 = *(const u32 *) ((value2) + 0u);
    value2 = 136u;
    value0 = (value0) * (value2);
    value2 = (value3) + (value0);
    value0 = 0x1714u;
    *(u32 *) ((value2) + (value0)) = value1;
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 func_0204ee30(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value0 = (u32) &data_0217aa00;
    value1 = *(const u32 *) ((value0) + 0u);
    value0 = 0x1e44u;
    value1 = (value1) + (value0);
    value2 = *(const u8 *) ((value1) + 0u);
    value0 = 1u;
    value2 = (value2) & ~(value0);
    *(u8 *) ((value1) + 0u) = value2;
    return value0;
}
#pragma thumb off

#pragma thumb on

void func_0204ed84(void) {
    u16 b;
    u16 c;
    if (!(data_0217aa00->mUnk_1e44 & 1)) {
        u32 v;
        if (data_0217aa00 == NULL) {
            v = 0;
        } else {
            v = data_0217aa00->mUnk_0000;
        }
        switch (v) {
            case 1:
                data_usa_0216522c.mMaxDataSize = 0x192;
                b = func_02006954(data_0217aa00->mUnk_1e30, 0x192);
                c = data_0217aa00->mUnk_0044.mChildMask;
                break;
            case 2:
                data_usa_0216522c.mMaxDataSize = 0xe;
                b = func_02006914(data_0217aa00->mUnk_1e30, 0xe);
                c = 1;
                break;
        }
        if (QueueMPDataToPort(data_0217aa00->mUnk_1e30, b, c, NULL, &data_usa_0216522c) == FALSE) {
            data_0217aa00->mUnk_1e42 = data_usa_02165228;
            data_0217aa00->mUnk_1e44 &= ~1;
        }
    }
}

void func_0204ed04(Unk0204ed04 *a) {
    u8 b[0x192];
    u32 v;
    if (a->mUnk_02 == 0 && a->mUnk_0c != NULL && a->mUnk_10 <= 0x192) {
        DC_InvalidateRange(a->mUnk_0c, a->mUnk_10);
        MI_CpuCopy8(a->mUnk_0c, b, a->mUnk_10);
        if (a->mUnk_04 == 7) {
            return;
        }
        if (a->mUnk_04 == 9) {
            return;
        }
        if (a->mUnk_04 == 0x15) {
            if (data_0217aa00 == NULL) {
                v = 0;
            } else {
                v = data_0217aa00->mUnk_0000;
            }
            switch (v) {
                case 1:
                    func_0200692c(b, a->mUnk_10, a->mUnk_12);
                    break;
                case 2:
                    func_020068f4(b, a->mUnk_10);
                    break;
            }
        }
    }
}

#pragma thumb off
