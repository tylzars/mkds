#include "Main/Unknown/code_02122794.h"
#include "00/code_021832d8.h"
#include "00/code_02181f98.h"
#include "00/code_0219b000.h"
#include "00/code_0219b580.h"
#include "00/code_021a2000.h"
#include "00/code_021a2ccc.h"

void func_02122ab0(void) {
    Unk0217d384_08 *p;
    gWiFiSession->mUnk_19ad = 0;
    p = &gWiFiSession->mUnk_0008;
    p->mNextState = 2;
    p->mNextStateRequested = 1;
}

// Drops the indices set in mKartRemoveMask from the roster; ends the run (step 11) if the own index is removed or one
// kart or none remains.
void RemoveWiFiSessionKarts(void) {
    u8 i;
    u32 m;
    if (gWiFiSession->mStep == 11 || gWiFiSession->mStep == 12) {
        return;
    }
    for (i = 0; i < gWiFiSession->mStartKartCount; i++) {
        m = 1 << i;
        if ((gWiFiSession->mKartMask & m) != 0 && (gWiFiSession->mKartRemoveMask & m) != 0) {
            if (i == func_ov000_0219bb50()) {
                gWiFiSession->mUnk_19ad = 1;
                func_ov000_021a2ccc();
                func_ov000_0219bbfc();
                gWiFiSession->mStep = 11;
                return;
            }
            gWiFiSession->mKartMask &= ~m;
            gWiFiSession->mKartRemoveMask &= ~m;
            gWiFiSession->mKartCount--;
        }
    }
    if (gWiFiSession->mKartCount <= 1) {
        gWiFiSession->mUnk_19ad = 1;
        func_ov000_021a2ccc();
        func_ov000_0219bbfc();
        gWiFiSession->mStep = 11;
    }
}

void UpdateWiFiSessionKartTimeouts(void) {
    u8 i;
    u8 n;
    if (gWiFiSession->mStep > 2 && gWiFiSession->mStep < 9) {
        if (gWiFiSession->mStep == 3) {
            n = func_ov000_0219bb50();
            if (gWiFiSession->mUnk_1e10[n].mUnk_40 != 1) {
                return;
            }
        }
        for (i = 0; i < gWiFiSession->mStartKartCount; i++) {
            if (i != func_ov000_0219bb50() && (gWiFiSession->mKartMask & (1 << i)) != 0) {
                if (gWiFiSession->mSinceCallbackFrames[i] > 300) {
                    gWiFiSession->mKartRemoveMask |= 1 << i;
                }
            }
        }
    }
    for (i = 0; i < gWiFiSession->mStartKartCount; i++) {
        if (i != func_ov000_0219bb50() && (gWiFiSession->mKartMask & (1 << i)) != 0) {
            gWiFiSession->mSinceCallbackFrames[i]++;
        }
    }
}

u32 GetKartMaskBit(u32 a) {
    return gWiFiSession->mKartMask & (1 << a);
}

u32 func_02122794(u8 a) {
    s8 i;
    for (i = 0; i < 4; i++) {
        if (a == gWiFiSession->mPackedIndices[i]) {
            goto found;
        }
    }
    i = -1;
found:
    if (i == -1) {
        return 0;
    }
    return gWiFiSession->mKartMask & (1 << (u8) i);
}
