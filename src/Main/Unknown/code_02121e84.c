#include "Main/Unknown/code_02121e84.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "00/code_021832d8.h"
#include "00/code_02181f98.h"
#include "00/code_0219b000.h"
#include "00/code_0219b580.h"
#include "00/code_021a2000.h"
#include "00/code_021a2ccc.h"
#include "00/code_021a3000.h"
#include "00/code_021a3264.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"

#pragma opt_arithtransformation off

void func_02122728(void) {
    PackWiFiSessionIndices();
}

// Gives each index in mKartMask the next running number in mPackedIndices (others -1) and tells CopyKartCupRecords the
// old and new number.
void PackWiFiSessionIndices(void) {
    u8 i;
    s8 a = 0;
    u8 t;
    for (i = 0; i < 4; i++) {
        if (i < gWiFiSession->mStartKartCount) {
            if ((gWiFiSession->mKartMask & (1 << i)) == 0) {
                gWiFiSession->mPackedIndices[i] = -1;
            } else {
                t = gWiFiSession->mPackedIndices[i];
                gWiFiSession->mPackedIndices[i] = a;
                a++;
                CopyKartCupRecords(t, gWiFiSession->mPackedIndices[i]);
            }
        } else {
            gWiFiSession->mPackedIndices[i] = -1;
        }
    }
}

BOOL UpdateWiFiSessionStepTimeout(u32 a) {
    s32 n;
    s32 s;
    n = gWiFiSession->mStepFrames;
    gWiFiSession->mStepFrames = n + 1;
    if (n > a) {
        gWiFiSession->mStepFrames = 0;
        s = gWiFiSession->mStep;
        if (s == 0 || s == 1 || s == 2) {
            gWiFiSession->mUnk_194e = 1;
            func_ov000_021a2ccc();
            func_ov000_0219bbfc();
            gWiFiSession->mStep = 11;
        } else {
            if (s == 9 || s == 10) {
                return TRUE;
            }
            gWiFiSession->mUnk_19ad = 1;
            func_ov000_021a2ccc();
            func_ov000_0219bbfc();
            gWiFiSession->mStep = 11;
        }
        return TRUE;
    }
    return FALSE;
}

static inline BOOL func_02121f4c_inline(const Unk0217d384_1d00 *p, u32 a, u32 c, u8 n) {
    if (p->mKind < 10) {
        if (p->mSize == c) {
            if (p->mFromIndex == a) {
                if (p->mToIndex == n) {
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

// Receive callback of the net layer: validates the header, checks the kind against the step, copies the message into
// the own array and sets mReceivedMask.
void ReceiveWiFiSessionMessage(u32 a, void *b, u32 c) {
    Unk0217d384_1d00 *p;
    u8 n;
    p = b;
    if (gWiFiSession->mStep >= 5 && (gWiFiSession->mKartMask & (1 << a)) == 0) {
        return;
    }
    gWiFiSession->mSinceCallbackFrames[a] = 0;
    n = func_ov000_0219bb50();
    if (func_02121f4c_inline(p, a, c, n) == FALSE) {
        return;
    }
    if (IsWiFiSessionMessageKindAllowed(p->mKind) == FALSE) {
        return;
    }
    switch (p->mKind) {
        case 0:
            gWiFiSession->mSendRecordMask |= 1 << a;
            break;
        case 1:
            gWiFiSession->mReceivedMask |= 1 << a;
            SetPeerReceiveBuffer(a, &gWiFiSession->mReceiveBuffers[a], 0x44);
            break;
        case 2:
            if (gWiFiSession->mStep == 1) {
                gWiFiSession->mReceivedMask |= 1 << a;
            }
            break;
        case 8:
            if (gWiFiSession->mStep != 3) {
                return;
            }
            if (p->mUnk_40 == 0) {
                return;
            }
            MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[a], &gWiFiSession->mUnk_1e10[a], 0x44);
            gWiFiSession->mReceivedMask |= 1 << a;
            break;
        case 9:
            if (gWiFiSession->mStep == 3) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[a], &gWiFiSession->mUnk_1e10[a], 0x44);
                gWiFiSession->mReceivedMask |= 1 << a;
            } else if (gWiFiSession->mStep == 4) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[a], &gWiFiSession->mUnk_1e10[a], 0x44);
                gWiFiSession->mReceivedMask |= 1 << a;
            }
            break;
        case 3:
            if (gWiFiSession->mStep == 1) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[a], &gWiFiSession->mUnk_1e10[a], 0x44);
                gWiFiSession->mReceivedMask = 0xff;
            } else if (gWiFiSession->mStep == 5) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[a], &gWiFiSession->mUnk_1e10[a], 0x44);
                if (p->mCharacterIndex == -1) {
                    return;
                }
                if (p->mKartIndex == -1) {
                    return;
                }
                gWiFiSession->mReceivedMask |= 1 << a;
            } else if (gWiFiSession->mStep == 4) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[a], &gWiFiSession->mUnk_1e10[a], 0x44);
                gWiFiSession->mReceivedMask = 0xff;
            }
            break;
        case 4:
            if (gWiFiSession->mStep == 5) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[a], &gWiFiSession->mUnk_1e10[a], 0x44);
                gWiFiSession->mReceivedMask |= 1 << a;
            } else if (gWiFiSession->mStep == 6) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[a], &gWiFiSession->mUnk_1e10[a], 0x44);
                gWiFiSession->mReceivedMask |= 1 << a;
            }
            break;
        case 5:
            if (gWiFiSession->mStep == 6) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[a], &gWiFiSession->mUnk_1e10[a], 0x44);
                gWiFiSession->mReceivedMask = 0xff;
            } else if (gWiFiSession->mStep == 7) {
                if (p->mPickedCourseId == 0) {
                    return;
                }
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[a], &gWiFiSession->mUnk_1e10[a], 0x44);
                gWiFiSession->mReceivedMask |= 1 << a;
            }
            break;
        case 6:
            if (gWiFiSession->mStep == 7) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[a], &gWiFiSession->mUnk_1e10[a], 0x44);
                gWiFiSession->mReceivedMask |= 1 << a;
            } else if (gWiFiSession->mStep == 8) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[a], &gWiFiSession->mUnk_1e10[a], 0x44);
                gWiFiSession->mReceivedMask |= 1 << a;
            }
            break;
        case 7:
            if (gWiFiSession->mStep == 8) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[a], &gWiFiSession->mUnk_1e10[a], 0x44);
                gWiFiSession->mReceivedMask |= 1 << a;
            } else if (gWiFiSession->mStep == 9) {
                MI_CpuCopy8(&gWiFiSession->mReceiveBuffers[a], &gWiFiSession->mUnk_1e10[a], 0x44);
                func_0212145c(a);
                gWiFiSession->mReceivedMask |= 1 << a;
            }
            break;
    }
}

void SetWiFiSessionOwnCharacterIndex(s32 a) {
    gWiFiSession->mUnk_1e10[func_ov000_0219bb50()].mCharacterIndex = a;
}

void SetWiFiSessionOwnCharacterIndexNone(void) {
    gWiFiSession->mUnk_1e10[func_ov000_0219bb50()].mCharacterIndex = -1;
}

void SetWiFiSessionOwnKartIndex(s32 a) {
    gWiFiSession->mUnk_1e10[func_ov000_0219bb50()].mKartIndex = a;
}

void SetWiFiSessionOwnPickedCourseId(s32 a) {
    gWiFiSession->mUnk_1e10[func_ov000_0219bb50()].mPickedCourseId = a;
}
