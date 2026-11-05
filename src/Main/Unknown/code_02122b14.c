#include "Main/Unknown/code_02122b14.h"
#include "00/code_0219b000.h"
#include "00/code_0219b580.h"
#include "00/code_021a2000.h"
#include "00/code_021a2ccc.h"
#include "00/code_021a3000.h"
#include "00/code_021a3264.h"
#include "00/unk_021b5000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_02121e84.h"
#include "Main/Unknown/code_02122794.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_0211f6cc.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "01/code_021956dc.h"
#include "code_0200f5ac.h"
#include "code_0214d018.h"

void func_02123a48(u32 a) {
    u8 i;
    u8 c;
    func_0211fe44();
    switch (a) {
        case 0:
            MemFill(&gWiFiSession->mStep, 0, 0x60);
            MemFill(gWiFiSession->mUnk_1e10, 0, 0x110);
            MemFill(gWiFiSession->mReceiveBuffers, 0, 0x110);
            for (i = 0; i < gWiFiSession->mStartKartCount; i++) {
                if (i != func_ov000_0219bb50()) {
                    SetPeerReceiveBuffer(i, &gWiFiSession->mPlayerRecords[i], 0x244);
                    func_02029930()->mUnk_00[i].mUnk_08 = 3;
                } else {
                    gWiFiSession->mPlayerRecords[i].mUnk_238 = data_0217aa08->mUnk_00->mUnk_34[4];
                    gWiFiSession->mPlayerRecords[i].mUnk_23c = data_0217aa08->mUnk_00->mUnk_34[5];
                    func_02029930()->mUnk_00[i].mUnk_08 = 0;
                }
                func_02029930()->mUnk_00[i].mCharacterIndex = -1;
                func_02029930()->mUnk_00[i].mKartIndex = -1;
                func_02029930()->mCourseId = 0;
                gWiFiSession->mUnk_1e10[i].mCharacterIndex = -1;
                gWiFiSession->mUnk_1e10[i].mKartIndex = -1;
                gWiFiSession->mUnk_1e10[i].mPickedCourseId = 0;
                gWiFiSession->mReceiveBuffers[i].mCharacterIndex = -1;
                gWiFiSession->mReceiveBuffers[i].mKartIndex = -1;
                gWiFiSession->mReceiveBuffers[i].mPickedCourseId = 0;
            }
            gWiFiSession->mStepFrames = 0;
            gWiFiSession->mSendRecordMask = 0;
            gWiFiSession->mReceivedMask = 0;
            func_ov000_021a323c(ReceiveWiFiSessionMessage);
            c = func_ov000_0219bb50();
            gWiFiSession->mPlayerRecords[c].mSeed = func_0200f5ac();
            PackWiFiSessionIndices();
            gWiFiSession->mStep = 0;
            func_02029454((u8) gWiFiSession->mPackedIndices[func_ov000_0219bb50()]);
            func_02029440(gWiFiSession->mStartKartCount);
            break;
        case 1:
            PackWiFiSessionIndices();
            gWiFiSession->mKartCount = 0;
            for (i = 0; i < gWiFiSession->mStartKartCount; i++) {
                if ((gWiFiSession->mKartMask & (1 << i)) != 0) {
                    gWiFiSession->mKartCount++;
                }
            }
            func_02029454((u8) gWiFiSession->mPackedIndices[func_ov000_0219bb50()]);
            func_02029440(gWiFiSession->mKartCount);
            break;
        case 2:
            for (i = 0; i < gWiFiSession->mStartKartCount; i++) {
                if (i != func_ov000_0219bb50() && (gWiFiSession->mKartMask & (1 << i)) != 0) {
                    SetPeerReceiveBuffer(i, &gWiFiSession->mReceiveBuffers[i], 0x44);
                }
                func_02029930()->mCourseId = 0;
                gWiFiSession->mUnk_1e10[i].mPickedCourseId = 0;
                gWiFiSession->mReceiveBuffers[i].mPickedCourseId = 0;
            }
            func_ov000_021a323c(ReceiveWiFiSessionMessage);
            gWiFiSession->mStep = 7;
            gWiFiSession->mStepFrames = 0;
            gWiFiSession->mSendRecordMask = 0;
            gWiFiSession->mReceivedMask = 0;
            PackWiFiSessionIndices();
            gWiFiSession->mKartCount = 0;
            for (i = 0; i < gWiFiSession->mStartKartCount; i++) {
                if ((gWiFiSession->mKartMask & (1 << i)) != 0) {
                    gWiFiSession->mKartCount++;
                }
            }
            func_02029454((u8) gWiFiSession->mPackedIndices[func_ov000_0219bb50()]);
            func_02029440(gWiFiSession->mKartCount);
            break;
        case 3:
            for (i = 0; i < gWiFiSession->mStartKartCount; i++) {
                if (i != func_ov000_0219bb50() && (gWiFiSession->mKartMask & (1 << i)) != 0) {
                    SetPeerReceiveBuffer(i, &gWiFiSession->mReceiveBuffers[i], 0x44);
                }
                gWiFiSession->mStepFrames = 0;
                gWiFiSession->mSendRecordMask = 0;
                gWiFiSession->mReceivedMask = 0;
                func_02029930()->mUnk_00[i].mCharacterIndex = -1;
                func_02029930()->mUnk_00[i].mKartIndex = -1;
                func_02029930()->mCourseId = 0;
                gWiFiSession->mUnk_1e10[i].mCharacterIndex = -1;
                gWiFiSession->mUnk_1e10[i].mKartIndex = -1;
                gWiFiSession->mUnk_1e10[i].mPickedCourseId = 0;
                gWiFiSession->mUnk_1e10[i].mUnk_40 = 0;
                gWiFiSession->mReceiveBuffers[i].mCharacterIndex = -1;
                gWiFiSession->mReceiveBuffers[i].mKartIndex = -1;
                gWiFiSession->mReceiveBuffers[i].mPickedCourseId = 0;
                gWiFiSession->mReceiveBuffers[i].mUnk_40 = 0;
            }
            func_ov000_021a323c(ReceiveWiFiSessionMessage);
            gWiFiSession->mStep = 3;
            break;
    }
}

s32 func_021236f8(void) {
    u8 a;
    u8 b;
    u8 c;
    s32 v;
    Unk0217d384_1d00 *p;
    Unk021759d4 *r;
    UpdateWiFiSessionKartTimeouts();
    RemoveWiFiSessionKarts();
    switch (gWiFiSession->mStep) {
        case 0:
            func_0212357c();
            break;
        case 1:
            func_02123384();
            break;
        case 2:
            UpdateWiFiSessionStepTimeout(0x1c20);
            if (data_0217aa08->mUnk_28 == 0) {
                r = data_021759d4;
                if (r->mUnk_0c != 0) {
                    v = r->mUnk_10;
                } else {
                    v = 0;
                }
            } else {
                v = 1;
            }
            if (v == 0) {
                gWiFiSession->mStepFrames = 0;
                gWiFiSession->mStep = 5;
            }
            break;
        case 3:
            func_0212320c();
            break;
        case 4:
            func_02123098();
            break;
        case 5:
            func_02122f38();
            break;
        case 6:
            UpdateWiFiSessionStepTimeout(0x1c20);
            a = func_021216a8();
            if (a < gWiFiSession->mStartKartCount) {
                b = func_ov000_0219bb50();
                c = func_ov000_0219bb50();
                p = &gWiFiSession->mUnk_1e10[c];
                p->mKind = 4;
                p->mSize = 0x44;
                p->mFromIndex = b;
                p->mToIndex = a;
                p->mKartMask = gWiFiSession->mKartMask;
                func_ov000_021a32a0(a, &gWiFiSession->mUnk_1e10[func_ov000_0219bb50()], 0x44);
            }
            if (func_02121580() != FALSE) {
                gWiFiSession->mSendRecordMask = 0;
                gWiFiSession->mReceivedMask = 0;
                func_02122b14();
                gWiFiSession->mStep = 7;
                gWiFiSession->mStepFrames = 0;
            }
            break;
        case 7:
            UpdateWiFiSessionStepTimeout(0x1c20);
            a = func_021216a8();
            if (a < gWiFiSession->mStartKartCount) {
                b = func_ov000_0219bb50();
                c = func_ov000_0219bb50();
                p = &gWiFiSession->mUnk_1e10[c];
                p->mKind = 5;
                p->mSize = 0x44;
                p->mFromIndex = b;
                p->mToIndex = a;
                p->mKartMask = gWiFiSession->mKartMask;
                func_ov000_021a32a0(a, &gWiFiSession->mUnk_1e10[func_ov000_0219bb50()], 0x44);
            }
            if (func_02121580() != FALSE) {
                c = func_ov000_0219bb50();
                if (gWiFiSession->mUnk_1e10[c].mPickedCourseId != 0) {
                    gWiFiSession->mSendRecordMask = 0;
                    gWiFiSession->mReceivedMask = 0;
                    gWiFiSession->mStep = 8;
                    gWiFiSession->mStepFrames = 0;
                }
            }
            break;
        case 8:
            func_02122d74();
            break;
        case 9:
            func_02122bf0();
            break;
        case 11:
            UpdateWiFiSessionStepTimeout(0x1c20);
            if (func_ov000_0219bb68() <= 1) {
                gWiFiSession->mStepFrames = 0;
                gWiFiSession->mStep = 12;
            }
            break;
        case 12:
            break;
    }
    return 0;
}

void func_0212357c(void) {
    u8 a;
    u8 b;
    u8 c;
    u32 m;
    Unk0217d384_021c *q;
    Unk02123384 t;
    UpdateWiFiSessionStepTimeout(0x1c20);
    a = func_021216a8();
    if (a < gWiFiSession->mStartKartCount) {
        m = 1 << a;
        if ((gWiFiSession->mSendRecordMask & m) != 0) {
            b = func_ov000_0219bb50();
            c = func_ov000_0219bb50();
            q = &gWiFiSession->mPlayerRecords[c];
            q->mKind = 1;
            q->mSize = 0x244;
            q->mFromIndex = b;
            q->mToIndex = a;
            q->mKartMask = gWiFiSession->mKartMask;
            c = func_ov000_0219bb50();
            func_ov000_021a32a0(a, &gWiFiSession->mPlayerRecords[c], 0x244);
            gWiFiSession->mSendRecordMask &= ~m;
        } else if ((gWiFiSession->mReceivedMask & m) == 0) {
            t.mFromIndex = func_ov000_0219bb50();
            t.mSize = 0xc;
            t.mToIndex = a;
            t.mKind = 0;
            t.mKartMask = gWiFiSession->mKartMask;
            func_ov000_021a32a0(a, &t, 0xc);
        }
    }
    if (func_02121580() == FALSE) {
        return;
    }
    gWiFiSession->mSendRecordMask = 0;
    gWiFiSession->mReceivedMask = 0;
    gWiFiSession->mStepFrames = 0;
    gWiFiSession->mStep = 1;
}

void func_02123384(void) {
    u8 a;
    u8 b;
    u8 c;
    u8 i;
    u32 m;
    u32 n;
    WiFiSession *p;
    Unk0217d384_021c *q;
    Unk0217d384_1954 *r;
    Unk02123384 t;
    UpdateWiFiSessionStepTimeout(0x1c20);
    a = func_021216a8();
    if (a < gWiFiSession->mStartKartCount) {
        m = 1 << a;
        if ((gWiFiSession->mSendRecordMask & m) != 0) {
            b = func_ov000_0219bb50();
            c = func_ov000_0219bb50();
            q = &gWiFiSession->mPlayerRecords[c];
            q->mKind = 1;
            q->mSize = 0x244;
            q->mFromIndex = b;
            q->mToIndex = a;
            q->mKartMask = gWiFiSession->mKartMask;
            c = func_ov000_0219bb50();
            func_ov000_021a32a0(a, &gWiFiSession->mPlayerRecords[c], 0x244);
            gWiFiSession->mSendRecordMask &= ~m;
        } else {
            t.mFromIndex = func_ov000_0219bb50();
            t.mSize = 0xc;
            t.mToIndex = a;
            t.mKind = 2;
            t.mKartMask = gWiFiSession->mKartMask;
            func_ov000_021a32a0(a, &t, 0xc);
        }
    }
    if (func_02121580() == FALSE) {
        return;
    }
    p = gWiFiSession;
    n = 0;
    for (i = 0; i < p->mStartKartCount; i++) {
        n += p->mPlayerRecords[i].mSeed;
    }
    r = &p->mUnk_1954;
    r->mValue = n;
    r->mMultiplier = 0x5d588b656c078965;
    r->mIncrement = 0x269ec3;
    func_0205e5c4(0);
    gWiFiSession->mSendRecordMask = 0;
    gWiFiSession->mReceivedMask = 0;
    gWiFiSession->mStepFrames = 0;
    gWiFiSession->mStep = 2;
}

void func_0212320c(void) {
    u8 a;
    u8 b;
    u8 c;
    Unk0217d384_1d00 *p;
    UpdateWiFiSessionStepTimeout(0x1c20);
    c = func_ov000_0219bb50();
    if (gWiFiSession->mUnk_1e10[c].mUnk_40 == 2) {
        func_ov000_021a2ccc();
        func_ov000_0219bbfc();
        gWiFiSession->mStep = 11;
        return;
    }
    a = func_021216a8();
    if (a < gWiFiSession->mStartKartCount) {
        b = func_ov000_0219bb50();
        c = func_ov000_0219bb50();
        p = &gWiFiSession->mUnk_1e10[c];
        p->mKind = 8;
        p->mSize = 0x44;
        p->mFromIndex = b;
        p->mToIndex = a;
        p->mKartMask = gWiFiSession->mKartMask;
        func_ov000_021a32a0(a, &gWiFiSession->mUnk_1e10[func_ov000_0219bb50()], 0x44);
    }
    if (func_02121580() == FALSE) {
        return;
    }
    c = func_ov000_0219bb50();
    if (gWiFiSession->mUnk_1e10[c].mUnk_40 == 0) {
        return;
    }
    gWiFiSession->mSendRecordMask = 0;
    gWiFiSession->mReceivedMask = 0;
    gWiFiSession->mStep = 4;
    gWiFiSession->mStepFrames = 0;
}

void func_02123098(void) {
    u8 a;
    u8 b;
    u8 c;
    Unk0217d384_1d00 *p;
    Unk0217d384_08 *q;
    UpdateWiFiSessionStepTimeout(0x1c20);
    a = func_021216a8();
    if (a < gWiFiSession->mStartKartCount) {
        b = func_ov000_0219bb50();
        c = func_ov000_0219bb50();
        p = &gWiFiSession->mUnk_1e10[c];
        p->mKind = 9;
        p->mSize = 0x44;
        p->mFromIndex = b;
        p->mToIndex = a;
        p->mKartMask = gWiFiSession->mKartMask;
        func_ov000_021a32a0(a, &gWiFiSession->mUnk_1e10[func_ov000_0219bb50()], 0x44);
    }
    if (func_02121580() == FALSE) {
        return;
    }
    if (gWiFiSession->mKartCount == 1) {
        func_ov000_021a2ccc();
        func_ov000_0219bbfc();
        q = &gWiFiSession->mUnk_0008;
        q->mNextState = 2;
        q->mNextStateRequested = 1;
        return;
    }
    gWiFiSession->mSendRecordMask = 0;
    gWiFiSession->mReceivedMask = 0;
    gWiFiSession->mStep = 5;
    gWiFiSession->mStepFrames = 0;
    c = func_ov000_0219bb50();
    func_02029454((u8) gWiFiSession->mPackedIndices[c]);
    func_02029440(gWiFiSession->mKartCount);
}

void func_02122f38(void) {
    u8 a;
    u8 b;
    u8 c;
    Unk0217d384_1d00 *p;
    UpdateWiFiSessionStepTimeout(0x1c20);
    a = func_021216a8();
    if (a < gWiFiSession->mStartKartCount) {
        b = func_ov000_0219bb50();
        c = func_ov000_0219bb50();
        p = &gWiFiSession->mUnk_1e10[c];
        p->mKind = 3;
        p->mSize = 0x44;
        p->mFromIndex = b;
        p->mToIndex = a;
        p->mKartMask = gWiFiSession->mKartMask;
        func_ov000_021a32a0(a, &gWiFiSession->mUnk_1e10[func_ov000_0219bb50()], 0x44);
    }
    if (func_02121580() == FALSE) {
        return;
    }
    c = func_ov000_0219bb50();
    if (gWiFiSession->mUnk_1e10[c].mCharacterIndex == -1) {
        return;
    }
    c = func_ov000_0219bb50();
    if (gWiFiSession->mUnk_1e10[c].mKartIndex == -1) {
        return;
    }
    gWiFiSession->mSendRecordMask = 0;
    gWiFiSession->mReceivedMask = 0;
    gWiFiSession->mStep = 6;
    gWiFiSession->mStepFrames = 0;
}

void func_02122d74(void) {
    u8 a;
    u8 b;
    u8 c;
    u8 i;
    Unk0217d384_1d00 *p;
    UpdateWiFiSessionStepTimeout(0x1c20);
    a = func_021216a8();
    if (a < gWiFiSession->mStartKartCount) {
        b = func_ov000_0219bb50();
        c = func_ov000_0219bb50();
        p = &gWiFiSession->mUnk_1e10[c];
        p->mKind = 6;
        p->mSize = 0x44;
        p->mFromIndex = b;
        p->mToIndex = a;
        p->mKartMask = gWiFiSession->mKartMask;
        func_ov000_021a32a0(a, &gWiFiSession->mUnk_1e10[func_ov000_0219bb50()], 0x44);
    }
    if (func_02121580() == FALSE) {
        return;
    }
    gWiFiSession->mSendRecordMask = 0;
    gWiFiSession->mReceivedMask = 0;
    func_02122b14();
    TallyPickedCourse();
    for (i = 0; i < gWiFiSession->mStartKartCount; i++) {
        c = func_ov000_0219bb50();
        gWiFiSession->mUnk_1e10[c].mKartIndices[i] = gWiFiSession->mUnk_1e10[i].mKartIndex;
        c = func_ov000_0219bb50();
        gWiFiSession->mUnk_1e10[c].mCharacterIndices[i] = gWiFiSession->mUnk_1e10[i].mCharacterIndex;
    }
    c = func_ov000_0219bb50();
    gWiFiSession->mUnk_1e10[c].mTalliedCourseId = func_02029930()->mCourseId;
    gWiFiSession->mStep = 9;
    gWiFiSession->mStepFrames = 0;
}

void func_02122bf0(void) {
    u8 a;
    u8 b;
    u8 c;
    u8 i;
    Unk0217d384_1d00 *p;
    a = func_021216a8();
    if (a < gWiFiSession->mStartKartCount) {
        b = func_ov000_0219bb50();
        c = func_ov000_0219bb50();
        p = &gWiFiSession->mUnk_1e10[c];
        p->mKind = 7;
        p->mSize = 0x44;
        p->mFromIndex = b;
        p->mToIndex = a;
        p->mKartMask = gWiFiSession->mKartMask;
        func_ov000_021a32a0(a, &gWiFiSession->mUnk_1e10[func_ov000_0219bb50()], 0x44);
    }
    if (UpdateWiFiSessionStepTimeout(0x78) == FALSE) {
        return;
    }
    for (i = 0; i < gWiFiSession->mStartKartCount; i++) {
        if (i != func_ov000_0219bb50() && (gWiFiSession->mKartMask & (1 << i)) != 0) {
            if (SetPeerReceiveBuffer(i, gWiFiSession->mUnk_001c[i], 0x80) == FALSE) {
                return;
            }
        }
    }
    gWiFiSession->mSendRecordMask = 0;
    gWiFiSession->mReceivedMask = 0;
    gWiFiSession->mStep = 10;
    gWiFiSession->mStepFrames = 0;
}

void func_02122b14(void) {
    u8 i;
    u8 m = 0xff;
    if (gWiFiSession->mStep < 5) {
        return;
    }
    if (gWiFiSession->mStep >= 9) {
        return;
    }
    for (i = 0; i < gWiFiSession->mStartKartCount; i++) {
        if ((gWiFiSession->mKartMask & (1 << i)) != 0) {
            m &= gWiFiSession->mUnk_1e10[i].mKartMask;
        }
    }
    for (i = 0; i < gWiFiSession->mStartKartCount; i++) {
        if ((gWiFiSession->mKartMask & (1 << i)) != 0) {
            if ((m & (1 << i)) == 0) {
                gWiFiSession->mKartRemoveMask |= 1 << i;
            }
        }
    }
}
