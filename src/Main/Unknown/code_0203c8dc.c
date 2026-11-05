#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_0204a904.h"
#include "Main/Unknown/code_0204a978.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02175628.h"

void func_0203c98c(void) {
    u32 i;
    func_02043544(1);
    for (i = 0; i < data_021759c0->mKartCount; i = (u16) (i + 1)) {
        Unk02175628 *e = &data_02175628[data_021759c0->mCurrentEntries[i].mPlayer.mIndex];
        if (e->mSourceKind != 1) {
            if (e->mSourceKind == 2) {
                func_0204a978((Unk02175650 *) &e->mUnk_28);
            }
        } else {
            func_0204a910((Unk02175650 *) &e->mUnk_28);
        }
    }
}

void GetRaceClockTime(u8 *a, u8 *b, u16 *c) {
    Unk0217aa1c_144_00 *t;

    t = &gRaceProgress->mUnk_000[0].mUnk_08_view;
    *a = t->mUnk_02;
    *b = t->mUnk_03;
    *c = t->mUnk_00;
}

u32 GetKartRank(u32 param_1) {
    if (data_021759c0->mMode == 5) {
        return data_0217aa14->mUnk_104[data_0217aa18->mUnk_00[param_1 & 0xff]].mUnk_86_1;
    }
    return gRaceProgress->mKarts[param_1].mUnk_3c_0;
}
