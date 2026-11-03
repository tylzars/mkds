#include "Main/Unknown/code_02122794.h"
#include "00/code_02182fdc.h"
#include "00/code_0219b000.h"
#include "00/code_0219bb68.h"
#include "00/code_021a2000.h"
#include "00/code_021a2ccc.h"

void func_02122ab0(void) {
    Unk0217d384_08 *p;
    data_0217d384->mUnk_19ad = 0;
    p = &data_0217d384->mUnk_0008;
    p->mNextState = 2;
    p->mNextStateRequested = 1;
}

void func_02122960(void) {
    u8 i;
    u32 m;
    if (data_0217d384->mStep == 11 || data_0217d384->mStep == 12) {
        return;
    }
    for (i = 0; i < data_0217d384->mStartKartCount; i++) {
        m = 1 << i;
        if ((data_0217d384->mKartMask & m) != 0 && (data_0217d384->mKartRemoveMask & m) != 0) {
            if (i == func_ov000_0219bb50()) {
                data_0217d384->mUnk_19ad = 1;
                func_ov000_021a2ccc();
                func_ov000_0219bbfc();
                data_0217d384->mStep = 11;
                return;
            }
            data_0217d384->mKartMask &= ~m;
            data_0217d384->mKartRemoveMask &= ~m;
            data_0217d384->mKartCount--;
        }
    }
    if (data_0217d384->mKartCount <= 1) {
        data_0217d384->mUnk_19ad = 1;
        func_ov000_021a2ccc();
        func_ov000_0219bbfc();
        data_0217d384->mStep = 11;
    }
}

void func_02122818(void) {
    u8 i;
    u8 n;
    if (data_0217d384->mStep > 2 && data_0217d384->mStep < 9) {
        if (data_0217d384->mStep == 3) {
            n = func_ov000_0219bb50();
            if (data_0217d384->mUnk_1e10[n].mUnk_40 != 1) {
                return;
            }
        }
        for (i = 0; i < data_0217d384->mStartKartCount; i++) {
            if (i != func_ov000_0219bb50() && (data_0217d384->mKartMask & (1 << i)) != 0) {
                if (data_0217d384->mSinceCallbackFrames[i] > 300) {
                    data_0217d384->mKartRemoveMask |= 1 << i;
                }
            }
        }
    }
    for (i = 0; i < data_0217d384->mStartKartCount; i++) {
        if (i != func_ov000_0219bb50() && (data_0217d384->mKartMask & (1 << i)) != 0) {
            data_0217d384->mSinceCallbackFrames[i]++;
        }
    }
}

u32 func_021227f8(u32 a) {
    return data_0217d384->mKartMask & (1 << a);
}

u32 func_02122794(u8 a) {
    s8 i;
    for (i = 0; i < 4; i++) {
        if (a == data_0217d384->mUnk_1f4e[i]) {
            goto found;
        }
    }
    i = -1;
found:
    if (i == -1) {
        return 0;
    }
    return data_0217d384->mKartMask & (1 << (u8) i);
}
