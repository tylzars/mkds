#include "Main/Unknown/code_0200b6e8.h"

#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200b200.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/code_020091fc.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020091e0.h"
#include "Main/Unknown/code_02008e10.h"
#include "code_0200eddc.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02009908.h"
#include "Main/Unknown/code_0200c0d8.h"
#include "03/code_021b94b8.h"

#pragma thumb on
u32 SetupMPLink(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = (u32) &gMPLink;
    *(u32 *) ((value2) + 0u) = value0;
    value1 = 0u;
    *(u32 *) ((value0) + 12u) = value1;
    gMPLink->mMPStarted = (u16) value1;
    gMPLink->mUnk_1e = (u16) value1;
    gMPLink->mDataQueued = (u16) value1;
    gMPLink->mResetting = (u16) value1;
    value0 = (u32) * (const u32 *) ((value2) + 0u);
    *(u32 *) ((value0) + 4u) = value1;
    value0 = (u32) * (const u32 *) ((value2) + 0u);
    *(u32 *) ((value0) + 8u) = value1;
    value0 = (u32) * (const u32 *) ((value2) + 0u);
    *(u32 *) ((value0) + 0u) = value1;
    return value0;
}
#pragma thumb off

#pragma thumb on

void SetMPLinkCallback(u32 callback) {
    u32 v1 = ((callback) + (0x0u));
    u32 v2 = ((u32) OS_DisableInterrupts());
    u32 v3 = ((u32) (&gMPLink));
    u32 v4 = ((u32) * (u32 *) ((v3) + (0)));
    u32 v6;
    *(u32 *) ((v4) + (0)) = v1;
    v6 = ((u32) OS_RestoreInterrupts(v2));
}

#pragma thumb off

#pragma thumb on

void ScanConnectStartConnect(u8 *scanBuffer) {
    s32 r;
    gMPLink->mMPStarted = 0;
    gMPLink->mResetting = 0;
    gMPLink->mSendBufferSize = (*(u16 *) (scanBuffer + 0x4e) + 0x21) & ~0x1f;
    gMPLink->mReceiveBufferSize = ((*(u16 *) (scanBuffer + 0x4c) + 0x55) & ~0x1f) * 2;
    gMPLink->mUnk_14 = *(u16 *) (scanBuffer + 0x4c);
    gMPLink->mUnk_16 = *(u16 *) (scanBuffer + 0x4e);
    gMPLink->mUnk_18 = gMPLink->mUnk_14 - 6;
    func_0200c448(gMPLink->mUnk_16);
    r = WM_StartConnectEx(ScanConnectStartConnectCallback, (u16 *) scanBuffer, NULL, 1, 0);
    if (r != 2) {
        if (gMPLink->mCallback != NULL) {
            gMPLink->mCallback(11, 0);
        }
    }
}

void ScanConnectStartConnectCallback(Unk021425e8 *a) {
    if (a->mResultCode != 0) {
        if (gMPLink->mCallback != NULL) {
            gMPLink->mCallback(11, a);
        }
    } else {
        switch (a->mUnk_08_0) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 8:
                break;
            case 9:
                if (gMPLink->mCallback != NULL) {
                    gMPLink->mCallback(10, 0);
                }
                break;
            case 7:
                if (gMPLink->mCallback != NULL) {
                    gMPLink->mCallback(6, a);
                }
                break;
        }
    }
}

void SetPortCallbackAndStartMP(void *sendBuffer, u8 *receiveBuffer) {
    CommandResult v;
    CommandResult w;
    s32 r;
    MPLink *p;
    gMPLink->mSendBuffer = sendBuffer;
    gMPLink->mReceiveBuffer = receiveBuffer;
    r = WM_SetPortCallback(1, PortCallback, NULL);
    if (r != 0) {
        p = gMPLink;
        if (p->mCallback != NULL) {
            v.mCommand = 14;
            v.mResultCode = r;
            p->mCallback(0xff, &v);
        }
        return;
    }
    p = gMPLink;
    r = WM_StartMPEx(ScanConnectStartMPCallback, (u32) receiveBuffer, p->mReceiveBufferSize, (u32) sendBuffer,
                     p->mSendBufferSize, 1, 0, 0, 0, 1, 1);
    if (r != 2) {
        p = gMPLink;
        if (p->mCallback != NULL) {
            w.mCommand = 14;
            w.mResultCode = r;
            p->mCallback(0xff, &w);
        }
    }
}

void ScanConnectStartMPCallback(Unk021425e8 *a) {
    CommandResult v;
    CommandResult w;
    MPLink *p;
    u16 c;
    u16 b = a->mResultCode;
    if (b != 0) {
        if (b != 15 && b != 9 && b != 13) {
            c = a->mCommand;
            p = gMPLink;
            if (p->mCallback != NULL) {
                v.mCommand = c;
                v.mResultCode = b;
                p->mCallback(0x100, &v);
            }
        }
    } else {
        switch (a->mUnk_04) {
            case 10:
                gMPLink->mMPStarted = 1;
                gMPLink->mDataQueued = 0;
                gMPLink->mUnk_1e = 0;
                if (gMPLink->mCallback != NULL) {
                    gMPLink->mCallback(20, 0);
                }
                if (gMPLink->mCallback != NULL) {
                    gMPLink->mCallback(25, 0);
                }
                break;
            case 11:
            default:
                c = a->mCommand;
                p = gMPLink;
                if (p->mCallback != NULL) {
                    w.mCommand = c;
                    w.mResultCode = 1;
                    p->mCallback(0x100, &w);
                }
                break;
            case 12:
            case 13:
                break;
        }
    }
}

void StartResetWithFlag(void) {
    CommandResult v;
    s32 r;
    gMPLink->mResetting = 1;
    r = WM_Reset(StartResetWithFlagCallback);
    if (r != 2) {
        MPLink *p;
        gMPLink->mResetting = 0;
        p = gMPLink;
        if (p->mCallback != NULL) {
            v.mCommand = 1;
            v.mResultCode = r;
            p->mCallback(0xff, &v);
        }
    }
}

void StartResetWithFlagCallback(Unk021425e8 *a) {
    CommandResult v;
    u16 b;
    gMPLink->mResetting = 0;
    b = a->mResultCode;
    if (b != 0) {
        u16 c = a->mCommand;
        MPLink *p = gMPLink;
        if (p->mCallback != NULL) {
            v.mCommand = c;
            v.mResultCode = b;
            p->mCallback(0x100, &v);
        }
    } else {
        if (gMPLink->mCallback != NULL) {
            gMPLink->mCallback(15, 0);
        }
    }
}

void StartReset(void) {
    CommandResult v;
    s32 r = WM_Reset(StartResetCallback);
    if (r != 2) {
        MPLink *p = gMPLink;
        if (p->mCallback != NULL) {
            v.mCommand = 1;
            v.mResultCode = r;
            p->mCallback(0xff, &v);
        }
    }
}

void StartResetCallback(Unk021425e8 *a) {
    CommandResult v;
    u16 b = a->mResultCode;
    if (b != 0) {
        u16 c = a->mCommand;
        MPLink *p = gMPLink;
        if (p->mCallback != NULL) {
            v.mCommand = c;
            v.mResultCode = b;
            p->mCallback(0x100, &v);
        }
    } else {
        if (gMPLink->mCallback != NULL) {
            gMPLink->mCallback(15, 0);
        }
    }
}

u32 IsMPReadyToQueueData(void) {
    u32 r = 0;
    u32 v = 0;
    MPLink *p = gMPLink;
    if (p->mMPStarted == 1 && p->mDataQueued == 0) {
        v = 1;
    }
    if (v != 0 && p->mResetting == 0) {
        r = 1;
    }
    return r;
}

void PortCallback(Unk021425e8 *a) {
    if (a->mResultCode == 0) {
        switch (a->mUnk_04) {
            case 7:
            case 9:
                break;
            case 21:
                if (gMPLink->mCallback != NULL) {
                    gMPLink->mCallback(9, a);
                }
                break;
        }
    }
}

s32 QueueMPDataIfReady(u32 a, u16 b, u8 *c) {
    s32 r;
    DC_FlushRange(c, 4);
    DC_WaitWriteBufferEmpty();
    if (IsMPReadyToQueueData() == 0) {
        return 1;
    }
    r = WM_SetMPDataToPortEx(QueueMPDataCallback, NULL, c, (u16) a, b, 1, 3);
    if (r == 2) {
        gMPLink->mDataQueued = 1;
        return 2;
    }
    return r;
}

void QueueMPDataCallback(Unk021425e8 *a) {
    gMPLink->mDataQueued = 0;
    if (a->mResultCode == 0) {
        if (gMPLink->mCallback != NULL) {
            gMPLink->mCallback(8, a);
        }
    } else if (a->mResultCode == 9) {
        if (gMPLink->mCallback != NULL) {
            gMPLink->mCallback(0x29, a);
        }
    } else {
        if (gMPLink->mCallback != NULL) {
            gMPLink->mCallback(0x12, a);
        }
    }
    if (gMPLink->mCallback != NULL) {
        gMPLink->mCallback(0x19, 0);
    }
}

void ClearPortCallback(void) {
    WM_SetPortCallback(1, NULL, NULL);
}

void InitScanConnectWork(ScanConnectWork *a, void *b) {
    if (*(u16 *) &gScanConnectInitialized == 0) {
        *(u16 *) &gScanConnectInitialized = 1;
        MI_CpuFill8(a, 0, 0x5f20);
        gScanConnectWork = a;
        a->mState = 0;
        MI_CpuCopy8(b, gScanConnectWork->mUnk_05c4, 0x16);
        func_0200991c(gScanConnectWork->mUnk_05e8);
        func_020092a4();
        func_02009908((UnkFunc *) SetScanBssid, (UnkFunc *) ClearUseScanBssid);
    }
}

void CloseScanConnect(void) {
    if (gScanConnectWork->mEndRequested == 0) {
        gScanConnectWork->mEndRequested = 1;
        switch (gScanConnectWork->mState) {
            case 0:
                if (gScanConnectWork->mRepeatScan != 0) {
                    gScanConnectWork->mRepeatScan = 0;
                    return;
                }
                if (gScanConnectWork->mEndScanRequested == 0) {
                    FinishScanConnect();
                    return;
                }
                break;
            case 1:
            case 2:
            case 3:
            case 4:
            case 6:
            case 14:
            case 19:
                StartReset();
                break;
            case 5:
            case 7:
            case 8:
            case 9:
                StartResetWithFlag();
                break;
            case 10:
                break;
            case 11:
            case 12:
                FinishScanConnect();
                break;
            default:
                OS_Terminate();
                break;
        }
    }
}

#pragma thumb off

#pragma thumb on

void FinishScanConnect(void) {
    *(u16 *) &gScanConnectInitialized = 0;
    gScanConnectWork->mEndRequested = 0;
    ClearPortCallback();
    SetScanConnectStateAndNotify((u32) 0x14, (void *) 0);
}

u32 GetScanConnectWorkSize(void) {
    return 0x5f20u;
}

void SetScanConnectStateCallback(UnkFunc *callback) {
    u32 v1 = (u32) callback;
    u32 v2 = ((u32) OS_DisableInterrupts());
    u32 v3 = ((u32) (&gScanConnectWork));
    u32 v4 = ((u32) * (u32 *) ((v3) + (0)));
    u32 v5 = 0x5e0u;
    u32 v7;
    *(u32 *) ((v4) + (0 + (v5))) = v1;
    v7 = ((u32) OS_RestoreInterrupts(v2));
}

#pragma thumb off

#pragma thumb on

void SetScanConnectStateAndNotify(u32 state, void *b) {
    u32 v1;
    v1 = OS_DisableInterrupts();
    gScanConnectWork->mState = state;
    OS_RestoreInterrupts(v1);
    if (gScanConnectWork->mStateCallback != NULL) {
        gScanConnectWork->mStateCallback(state, b);
    }
}

#pragma thumb off

#pragma thumb on

void StartRepeatedScan(UnkFunc *callback, u32 b) {
    gScanConnectWork->mScanCallback = callback;
    gScanConnectWork->mUnk_05e4 = b;
    gScanConnectWork->mScanParams.mUnk_04 = 0;
    gScanConnectWork->mScanParams.mUnk_00 = gScanConnectWork->mScanBuffer;
    gScanConnectWork->mRepeatScan = 1;
    gScanConnectWork->mUseScanBssid = 0;
    gScanConnectWork->mUnk_05ee = 0;
    ScanConnectStartScan();
}

#pragma thumb off

#pragma thumb on

void ScanConnectStartScan(void) {
    s32 r;
    ScanConnectWork *d;
    u8 *p;
    u8 *q;
    d = gScanConnectWork;
    if (d->mUseScanBssid != 0) {
        d->mScanParams.mUnk_06 = 0xdc;
    } else {
        p = d->mScanParams.mUnk_08;
        q = gDefaultScanBssid;
        p[0] = q[0];
        p[1] = q[1];
        p[2] = q[2];
        p[3] = q[3];
        p[4] = q[4];
        p[5] = q[5];
        gScanConnectWork->mScanParams.mUnk_06 = 10;
        if (PickScanChannel() == 0) {
            ReportScanError(0x1e, 0);
            return;
        }
    }
    if (gScanConnectWork->mScanParams.mUnk_04 == 0) {
        gScanConnectWork->mScanParams.mUnk_04 = 1;
    }
    r = WM_StartScan(ScanConnectStartScanCallback, &gScanConnectWork->mScanParams);
    if (r != 2) {
        ReportScanError(0xa, r);
    }
}

void ScanConnectStartScanCallback(Unk021425e8 *a) {
    if (a->mResultCode != 0) {
        ReportScanError(0xa, a->mResultCode);
        return;
    }
    switch (a->mUnk_08_0) {
        case 3:
            break;
        case 5:
            if (a->mUnk_38.mUnk_00[1] == gScanConnectWork->mUnk_05e4) {
                DC_InvalidateRange(gScanConnectWork->mScanBuffer, 0xc0);
                func_0200921c(EntryCallback, a->mUnk_12, (Unk02007ec4 *) gScanConnectWork->mScanBuffer);
                func_02008f00(EntryCallback, 1);
            }
        case 4:
            func_02008f00(EntryCallback, 0);
            if (gScanConnectWork->mRepeatScan != 0) {
                ScanConnectStartScan();
            } else {
                ScanConnectEndScan();
            }
            break;
        default:
            ReportScanError(0xa, 1);
            break;
    }
}

void CallScanCallbackWithEntry(u32 a, Unk02008934 *entry, u32 entryIndex) {
    ScanEntryArgs v;
    ScanConnectWork *d;
    d = gScanConnectWork;
    if (d->mScanCallback != NULL) {
        v.mEntryIndex = entryIndex;
        if (entry != NULL) {
            v.mEntry = entry;
            v.mScanBuffer = entry->mUnk_4c0;
        } else {
            v.mEntry = NULL;
            v.mScanBuffer = NULL;
        }
        d->mScanCallback(a, &v);
    }
}

void ReportScanError(u16 a, u16 b) {
    ScanErrorArgs v;
    if (gScanConnectWork->mScanCallback != NULL) {
        v.mUnk_00 = a;
        v.mUnk_02 = b;
        gScanConnectWork->mScanCallback(2, &v);
    }
}

void SetScanBssid(const u8 *a) {
    u8 *p;
    gScanConnectWork->mUseScanBssid = 1;
    p = gScanConnectWork->mScanParams.mUnk_08;
    p[0] = a[0];
    p[1] = a[1];
    p[2] = a[2];
    p[3] = a[3];
    p[4] = a[4];
    p[5] = a[5];
}

#pragma thumb off

#pragma thumb on
u32 ClearUseScanBssid(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value2 = 0u;
    value0 = (u32) &gScanConnectWork;
    value1 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = 0x5f00u;
    *(u32 *) ((value1) + (value0)) = value2;
    return value0;
}
#pragma thumb off

#pragma thumb on

void EntryCallback(u32 a, void *entry, u32 entryIndex) {
    switch (a) {
        case 0:
        case 2:
        case 4:
            break;
        case 1:
            CallScanCallbackWithEntry(0, entry, entryIndex);
            break;
        case 3:
            CallScanCallbackWithEntry(1, entry, entryIndex);
            break;
    }
}

u32 PickScanChannel(void) {
    u16 a;
    a = WM_GetAllowedChannel();
    if (a == 0x8000 || a == 0) {
        return 0;
    }
    gScanConnectWork->mScanParams.mUnk_04++;
    do {
        gScanConnectWork->mScanParams.mUnk_04++;
        if (gScanConnectWork->mScanParams.mUnk_04 > 0x10) {
            gScanConnectWork->mScanParams.mUnk_04 = 1;
        }
    } while ((a & (1 << (gScanConnectWork->mScanParams.mUnk_04 - 1))) == 0);
    return 1;
}

void RequestEndScan(void) {
    gScanConnectWork->mRepeatScan = 0;
    gScanConnectWork->mEndScanRequested = 1;
}

#pragma thumb off

#pragma thumb on

void ScanConnectEndScan(void) {
    u32 v1;
    v1 = WM_EndScan(ScanConnectEndScanCallback);
    if (v1 != 2) {
        ReportScanError((u16) 0xb, (u16) (v1 & 0xffff));
    }
}

#pragma thumb off
