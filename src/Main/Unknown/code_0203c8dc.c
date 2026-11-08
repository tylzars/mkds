#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_0204a904.h"
#include "Main/Unknown/code_0204a978.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02175628.h"

void func_0203c98c(void) {
    u32 entryIndex;
    func_02043544(1);
    for (entryIndex = 0; entryIndex < gRaceSetup->mKartCount; entryIndex = (u16) (entryIndex + 1)) {
        InputSlot *inputSlot = &data_02175628[gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mIndex];
        if (inputSlot->mSourceKind != 1) {
            if (inputSlot->mSourceKind == 2) {
                func_0204a978((KeyRecording *) &inputSlot->mUnk_28);
            }
        } else {
            func_0204a910((KeyRecording *) &inputSlot->mUnk_28);
        }
    }
}

void GetRaceClockTime(u8 *outMinute, u8 *outSecond, u16 *outMillisecond) {
    Unk0217aa1c_144_00 *clockTime;

    clockTime = &gRaceProgress->mUnk_000[0].mUnk_08_view;
    *outMinute = clockTime->mUnk_02;
    *outSecond = clockTime->mUnk_03;
    *outMillisecond = clockTime->mUnk_00;
}

u32 GetKartRank(u32 kartIndex) {
    if (gRaceSetup->mMode == 5) {
        return data_0217aa14->mUnk_104[data_0217aa18->mUnk_00[kartIndex & 0xff]].mUnk_86_1;
    }
    return gRaceProgress->mKarts[kartIndex].mRank;
}
