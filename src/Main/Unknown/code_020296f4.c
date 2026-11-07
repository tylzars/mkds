#include "Main/Unknown/code_020296f4.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0205b0f4.h"
#include "Main/Unknown/code_02122734.h"
#include "Main/Unknown/code_02122794.h"
#include "Main/Unknown/unk_02174000.h"
#include "00/code_02181f98.h"

#pragma optimize_for_size on

#pragma thumb on

void func_020297bc(void) {
    u16 b;
    u16 a = 0;
    u8 d;
    u8 c;
    func_0202991c(0);
    for (b = 0; b < 4; b++) {
        if (func_02122794(b) != 0) {
            func_020468b0(a, gRaceSetupCopy->mEntries[b].mCharacterIndex, gRaceSetupCopy->mEntries[b].mKartIndex,
                          gRaceSetupCopy->mEntries[b].mPlayerKind, -1, 3);
            a++;
        }
    }
    for (; a < 8; a++) {
        func_020468b0(a, -1, -1, PLAYER_KIND_NONE, -1, 3);
    }
    func_02029908(5);
    func_020298f4(gRaceSetupCopy->mCourseId);
    func_020298e0(1);
    func_020298cc(0);
    func_020298b8(0);
    func_020298a4(0);
    func_02029890(0);
    d = 0;
    for (c = 0; c < 4; c++) {
        if (GetKartMaskBit(c) != 0) {
            d |= 1 << c;
        }
    }
    func_0205cfd4(d);
}

void func_02029758(void) {
    u8 i;
    s32 j;
    for (i = 0; i < 4; i++) {
        if (func_02122794(i) != 0) {
            j = func_02122734(i);
            data_0217b488->mUnk_20[j].mUnk_00 = gRaceSetupCopy->mEntries[i].mCharacterIndex;
            data_0217b488->mUnk_20[j].mUnk_04 = gRaceSetupCopy->mEntries[i].mKartIndex;
            data_0217b488->mUnk_20[j].mUnk_08 = gRaceSetupCopy->mEntries[i].mPlayerKind;
        }
    }
}

void func_020296f4(void) {
    u8 i;
    s32 j;
    for (i = 0; i < 4; i++) {
        if (GetKartMaskBit(i) != 0) {
            j = GetPackedIndex(i);
            gRaceSetupCopy->mEntries[j].mCharacterIndex = data_0217b488->mUnk_20[i].mUnk_00;
            gRaceSetupCopy->mEntries[j].mKartIndex = data_0217b488->mUnk_20[i].mUnk_04;
            gRaceSetupCopy->mEntries[j].mPlayerKind = data_0217b488->mUnk_20[i].mUnk_08;
        }
    }
}

#pragma thumb off
