#include "Main/Unknown/code_02009928.h"

#include "Main/Unknown/unk_0216f000.h"
#include "code_02142eac.h"
#include "Main/Unknown/code_0200ad00.h"
#include "Main/Unknown/code_020099d8.h"
#include "Main/Unknown/code_02009cc8.h"
#include "Main/Unknown/code_02009adc.h"
#include "Main/Unknown/code_02009c34.h"
#include "Main/Unknown/code_02007148.h"
#include "Main/Unknown/code_0200a000.h"
#include "Main/Unknown/code_0200c0d8.h"
#include "Main/Unknown/code_0214d000.h"
#include "03/code_021b94b8.h"
#include "Main/Unknown/code_02009000.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_02009c90.h"
#include "Main/Unknown/code_0200aeb4.h"
#include "Main/Unknown/code_020091fc.h"
#include "code_0200eddc.h"
#include "code_0214d5b8.h"
#include "code_0214d018.h"

#pragma thumb on

// Stores one block (offset, size, buffer, state) in the first free entry.
void AddDataRange(DataRangeTable *a, u32 b, u32 c, u8 *d, u32 e) {
    u32 v1;
    DataRange *v2;
    v1 = OS_DisableInterrupts();
    v2 = a->mUnk_30;
    for (;;) {
        if (v2 >= a->mUnk_30 + 4) {
            OS_Terminate();
        }
        if (v2->mUnk_0c == 0) {
            v2->mOffset = b;
            v2->mSize = c;
            v2->mData = d;
            v2->mUnk_0c = e;
            break;
        }
        v2++;
    }
    OS_RestoreInterrupts(v1);
}

u32 CopyFromDataRanges(DataRangeTable *a, u32 b, void *c, u32 d) {
    u32 v1;
    u32 v2;
    DataRange *v3;
    s32 v4;
    v2 = 0;
    v1 = OS_DisableInterrupts();
    for (v3 = a->mUnk_30; v3 < a->mUnk_30 + 4; v3++) {
        if (v3->mUnk_0c >= 2) {
            v4 = b - v3->mOffset;
            if (v4 >= 0 && v4 + d <= v3->mSize) {
                MI_CpuCopy8(v3->mData + v4, c, d);
                v2 = 1;
                a->mUnk_00 = v2;
                break;
            }
        }
    }
    OS_RestoreInterrupts(v1);
    return v2;
}

// Moves the scan to the next allowed channel; returns 0 when no channel is allowed.
u32 AdvanceScanChannel(Unk02143a78 *a) {
    u16 v3;
    u16 i;
    u16 v2;
    u32 v1;
    v1 = WM_GetAllowedChannel();
    if (v1 == 0) {
        return 0;
    }
    i = 0;
    v2 = a->mUnk_04;
    v3 = v2;
    for (; i < 16;) {
        if ((v1 & (1 << (v3 - 1))) != 0 && v2 != v3) {
            a->mUnk_04 = v3;
            break;
        }
        i++;
        v3 = v3 == 16 ? 1 : v3 + 1;
    }
    return 1;
}

u32 IsMPReadyToSendData(void) {
    u32 v1;
    u32 v2;
    u32 v3;
    WirelessWork *v4;
    v1 = 0;
    v2 = 0;
    v3 = 0;
    v4 = gWirelessWork;
    if (v4->mMPStarted == 1) {
        if (v4->mDataQueued == 0) {
            v3 = 1;
        }
    }
    if (v3 != 0) {
        if (v4->mResetting == 0) {
            v2 = 1;
        }
    }
    if (v2 != 0) {
        if (v4->mConnectedAids != 0) {
            v1 = 1;
        }
    }
    return v1;
}

#pragma thumb off

#pragma thumb on

void func_0200ad00(void) {
    u32 v1;
    v1 = WM_SetIndCallback(ParentCallback);
    ReportCommandError(0x80, v1);
    v1 = WM_SetLifeTime(ParentCallback, data_0216179c, data_02161794, data_02161790, data_02161798);
    ReportCommandError(0x1d, v1);
}

#pragma thumb off

#pragma thumb on

// Handles the results of the parent start-up steps, then child connects, disconnects and sent data.
void ParentCallback(Unk021425e8 *a) {
    u32 n;
    u32 i;
    Unk0216fdac *p;
    u32 x;
    switch (a->mCommand) {
        case 0:
            if (a->mResultCode != 0) {
                gWirelessWork->mCallback(0x100, a);
                return;
            }
            func_0200ad00();
            return;
        case 0x1d:
            if (a->mResultCode != 0) {
                gWirelessWork->mCallback(0x100, a);
                return;
            }
            ReportCommandError(7, WM_SetParentParameter(ParentCallback, (Unk02143c30 *) gWirelessWork));
            return;
        case 7:
            gWirelessWork->mCallback(0x15, a);
            ReportCommandError(0x19, WM_SetBeaconIndication(ParentCallback, 1));
            return;
        case 0x19:
            if (a->mResultCode != 0) {
                gWirelessWork->mCallback(0x100, a);
                return;
            }
            ReportCommandError(8, WMi_StartParentEx(ParentCallback, data_usa_021617a4));
            return;
        case 8:
            if (a->mResultCode != 0) {
                gWirelessWork->mCallback(0x100, a);
                return;
            }
            switch (a->mUnk_08_0) {
                case 0:
                    gWirelessWork->mConnectedAids = 0;
                    gWirelessWork->mMPStarted = 0;
                    return;
                case 7:
                    if (gWirelessWork->mResetting == 1) {
                        return;
                    }
                    gWirelessWork->mConnectedAids |= 1 << a->mUnk_10;
                    gWirelessWork->mCallback(0, a);
                    if (gWirelessWork->mMPStarted == 0 && data_0216fdac->mUnk_131c == 0) {
                        data_0216fdac->mUnk_131c = 1;
                        x = 1;
                        if (gWirelessWork->mUnk_52c != 0) {
                            x = 0;
                        }
                        ReportCommandError(0xe,
                                           WM_StartMPEx(ParentCallback, gWirelessWork->mReceiveBuffer,
                                                        gWirelessWork->mReceiveBufferSize, gWirelessWork->mSendBuffer,
                                                        gWirelessWork->mSendBufferSize, x, 0, 0, 0, 1, 1));
                        return;
                    }
                    if (IsMPReadyToSendData() == 0) {
                        return;
                    }
                    gWirelessWork->mCallback(0x19, NULL);
                    return;
                case 9:
                    gWirelessWork->mConnectedAids &= ~(1 << a->mUnk_10);
                    gWirelessWork->mCallback(1, a);
                    return;
                case 2:
                    if (gWirelessWork->mResetting == 1) {
                        return;
                    }
                    gWirelessWork->mCallback(0x1c, a);
                    return;
                default:
                    gWirelessWork->mCallback(0x100, a);
                    return;
            }
        case 14:
            data_0216fdac->mUnk_131c = 0;
            switch (a->mUnk_04) {
                case 10:
                    gWirelessWork->mMPStarted = 1;
                    gWirelessWork->mCallback(0x19, NULL);
                    return;
                case 11:
                    gWirelessWork->mCallback(3, a->mUnk_08);
                    return;
                default:
                    gWirelessWork->mCallback(0x100, a);
                    return;
            }
        case 15:
            p = data_0216fdac;
            if (p->mUnk_74c8 != 0) {
                n = 0;
                for (i = 0; i < 15; i++) {
                    if (p->mUnk_14e8[i] != 0) {
                        n++;
                        if (n >= 2) {
                            break;
                        }
                    }
                }
                if (n == 1) {
                    OS_SpinWait(0x32c8);
                }
            }
            gWirelessWork->mDataQueued = 0;
            if (a->mResultCode == 0) {
                gWirelessWork->mCallback(2, a);
                gWirelessWork->mCallback(0x19, NULL);
                return;
            }
            if (a->mResultCode == 10) {
                gWirelessWork->mCallback(0x2a, a);
                return;
            }
            gWirelessWork->mCallback(0x13, a);
            gWirelessWork->mCallback(0x19, NULL);
            return;
        case 1:
            if (data_0216fdac->mUnk_1320 == 0) {
                if (a->mResultCode != 0) {
                    gWirelessWork->mResetting = 0;
                    gWirelessWork->mCallback(0x100, a);
                    return;
                }
                gWirelessWork->mConnectedAids = 0;
                gWirelessWork->mMPStarted = 0;
                ReportCommandError(2, WM_End(ParentCallback));
                return;
            }
            WM_SetPortCallback(1, NULL, NULL);
            WM_SetIndCallback(NULL);
        case 2:
            if (a->mResultCode != 0) {
                gWirelessWork->mResetting = 0;
                gWirelessWork->mCallback(0x100, a);
                return;
            }
            gWirelessWork->mUnk_50d = 0;
            data_0216fdac->mUnk_1316 = 0;
            gWirelessWork->mCallback(0x11, a);
            return;
        case 13:
            if (a->mResultCode == 0) {
                gWirelessWork->mConnectedAids &= ~a->mUnk_08_2;
            }
            return;
        case 0x80:
            switch (a->mUnk_04) {
                case 0x10:
                    gWirelessWork->mCallback(0x1d, a);
                    return;
                case 0x11:
                    gWirelessWork->mCallback(0x1f, a);
                    return;
                case 0x12:
                    gWirelessWork->mCallback(0x20, a);
                    return;
                case 0x13:
                    gWirelessWork->mCallback(0x21, a);
                    return;
                case 0x16:
                    OS_Terminate();
                    break;
                case 0x17:
                    break;
            }
            break;
        default:
            gWirelessWork->mCallback(0x100, a);
            return;
    }
}

void ChildPortCallback(Unk021425e8 *a) {
    if (a->mResultCode == 0) {
        if (a->mUnk_04 == 7) {
        } else if (a->mUnk_04 == 9) {
        } else if (a->mUnk_04 == 0x15) {
            gWirelessWork->mCallback(9, a);
        }
    }
}

// Child side (scan, connect, MP data); mMode is only ever 1, so this does not run in this build.
void ChildCallback(Unk021425e8 *a) {
    ScanEntry *e;
    u8 c;
    WirelessWork *v1;
    s32 i;
    s32 n;
    u32 v2;
    u8 *v3;
    v1 = gWirelessWork;
    switch (a->mCommand) {
        case 0:
            if (a->mResultCode != 0) {
                v1->mCallback(0x100, a);
                return;
            }
            v1->mCallback(0x15, a);
            ReportCommandError(
                0x1d, WM_SetLifeTime(ChildCallback, data_0216179c, data_02161794, data_02161790, data_02161798));
            return;
        case 0x1d:
            if (a->mResultCode != 0) {
                v1->mCallback(0x100, a);
                return;
            }
            gScanParams.mUnk_00 = v1->mScanBuffer;
            if (gScanParams.mUnk_04 == 0) {
                gScanParams.mUnk_04 = 1;
            }
            if (gScanParams.mUnk_06 == 0) {
                gScanParams.mUnk_06 = 0xc8;
            }
            gScanParams.mUnk_08[0] = 0xff;
            gScanParams.mUnk_08[1] = 0xff;
            gScanParams.mUnk_08[2] = 0xff;
            gScanParams.mUnk_08[3] = 0xff;
            gScanParams.mUnk_08[4] = 0xff;
            gScanParams.mUnk_08[5] = 0xff;
            v1->mRepeatScan = 1;
            v1->mUnk_5e8 = 1;
            ReportCommandError(0xa, WM_StartScan(ChildCallback, &gScanParams));
            return;
        case 10:
            if (a->mResultCode != 0) {
                v1->mCallback(0x100, a);
                return;
            }
            switch (a->mUnk_08_0) {
                case 3:
                    return;
                case 5:
                    v3 = (u8 *) v1->mScanEntries;
                    i = 0;
                    n = v1->mScanEntryCount;
                    if (n > 0) {
                        e = (ScanEntry *) v3;
                        c = a->mUnk_0a[0];
                        do {
                            if (c == e->mMessage.mUnk_0a[0] && a->mUnk_0a[1] == e->mMessage.mUnk_0a[1] &&
                                a->mUnk_0a[2] == e->mMessage.mUnk_0a[2] && a->mUnk_0a[3] == e->mMessage.mUnk_0a[3] &&
                                a->mUnk_0a[4] == e->mMessage.mUnk_0a[4] && a->mUnk_0a[5] == e->mMessage.mUnk_0a[5]) {
                                v2 = i * 0x180;
                                ((ScanEntry *) (v3 + v2))->mMessage.mUnk_36 = a->mUnk_36;
                                ((ScanEntry *) (v3 + (s32) v2))->mMessage.mUnk_38 = a->mUnk_38;
                                DC_InvalidateRange((ScanEntry *) ((u8 *) v1->mScanEntries + v2), 0xc0);
                                MI_DmaCopy16(gWirelessDmaNo, v1->mScanBuffer,
                                             (ScanEntry *) ((u8 *) v1->mScanEntries + v2), 0xc0);
                                v1->mLastScanEntry = i;
                                goto done;
                            }
                            e++;
                            i++;
                        } while (i < n);
                    }
                    if (i < 16) {
                        v1->mScanEntryCount = i + 1;
                        v2 = i * 0x180;
                        MIi_CpuCopy16(a, v3 + v2 + 0xc0, 0xb8);
                        e = (ScanEntry *) ((u8 *) v1->mScanEntries + v2);
                        DC_InvalidateRange(e, 0xc0);
                        MI_DmaCopy16(gWirelessDmaNo, v1->mScanBuffer, e, 0xc0);
                        v1->mLastScanEntry = i;
                    }
                done:
                    v1->mCallback(4, a);
                    if (v1->mRepeatScan == 0) {
                        return;
                    }
                    if (v1->mUnk_5e8 != 0) {
                        if (AdvanceScanChannel(&gScanParams) == 0) {
                            RequestWirelessReset();
                        }
                    }
                    ReportCommandError(0xa, WM_StartScan(ChildCallback, &gScanParams));
                    return;
                case 4:
                    v1->mCallback(5, a);
                    if (v1->mRepeatScan == 0) {
                        return;
                    }
                    if (v1->mUnk_5e8 != 0) {
                        if (AdvanceScanChannel(&gScanParams) == 0) {
                            RequestWirelessReset();
                        }
                    }
                    ReportCommandError(0xa, WM_StartScan(ChildCallback, &gScanParams));
                    return;
                default:
                    v1->mCallback(0x100, a);
                    return;
            }
        case 11:
            if (a->mResultCode != 0) {
                v1->mCallback(0x100, a);
                return;
            }
            ReportCommandError(0xc, WM_StartConnectEx(ChildCallback, v1->mUnk_520, NULL, 1, 0));
            return;
        case 12:
            if (a->mResultCode != 0) {
                v1->mScanEntryCount = 0;
                v1->mCallback(0xb, a);
                return;
            }
            switch (a->mUnk_08_0) {
                case 6:
                    v1->mConnectedAids = 0;
                    v1->mMPStarted = 1;
                    return;
                case 7:
                    v1->mUnk_5e2 = a->mUnk_08_2;
                    v1->mCallback(6, a);
                    v1->mConnectedAids = 1;
                    if (WM_SetPortCallback(1, (UnkFunc *) ChildPortCallback, NULL) != 0) {
                        return;
                    }
                    ReportCommandError(0xe, WM_StartMPEx(ChildCallback, v1->mReceiveBuffer, v1->mReceiveBufferSize,
                                                         v1->mSendBuffer, v1->mSendBufferSize,
                                                         v1->mUnk_52c == 0 ? 1 : 0, 0, 0, 0, 1, 1));
                    return;
                case 9:
                    v1->mCallback(10, a);
                    v1->mConnectedAids = 0;
                    v1->mMPStarted = 0;
                    return;
                default:
                    v1->mCallback(0x100, a);
                    return;
            }
        case 14:
            switch (a->mUnk_04) {
                case 10:
                    v1->mMPStarted = 1;
                    if (IsMPReadyToSendData() == 0) {
                        return;
                    }
                    v1->mCallback(0x19, NULL);
                    return;
                case 12:
                case 13:
                    return;
                default:
                    v1->mCallback(0x100, a);
                    return;
            }
        case 15:
            v1->mDataQueued = 0;
            if (a->mResultCode == 0) {
                v1->mCallback(8, a);
            } else if (a->mResultCode == 9) {
                v1->mCallback(0x29, a);
            } else {
                v1->mCallback(0x12, a);
            }
            v1->mCallback(0x19, NULL);
            return;
        case 1:
            if (a->mResultCode != 0) {
                v1->mResetting = 0;
                v1->mCallback(0x100, a);
                return;
            }
            v1->mConnectedAids = 0;
            gWirelessWork->mMPStarted = 0;
            ReportCommandError(2, WM_End(ChildCallback));
            return;
        case 2:
            if (a->mResultCode != 0) {
                v1->mResetting = 0;
                v1->mCallback(0x100, a);
                return;
            }
            v1->mUnk_50d = 0;
            data_0216fdac->mUnk_1316 = 0;
            v1->mCallback(0x11, a);
            return;
        case 21:
            if (IsMPReadyToSendData() == 0) {
                return;
            }
            v1->mCallback(0x19, NULL);
            return;
        case 0x80:
            switch (a->mUnk_04) {
                case 0x16:
                    OS_Terminate();
                    break;
                case 0x17:
                    break;
            }
            return;
        default:
            v1->mCallback(0x100, a);
            return;
    }
}

// A value from 0 to 19 made from the MAC address; the caller adds 200 for the beacon period.
u32 GetBeaconDispersion(void) {
    u8 v1[6];
    u32 v2;
    s32 i;
    OS_GetMacAddress(v1);
    i = 0;
    v2 = 0;
    for (; i < 6; i++) {
        v2 += v1[i];
    }
    return (v2 + *(vu32 *) 0x27ffc3c) * 7 % 0x14;
}

s32 InitWirelessWork(void *a, Unk02009ff4 *b, u32 c, u32 d, u32 e) {
    WirelessWork *v1;
    Unk0216fdac *v2;
    u32 v3;
    vu16 v4;
    vu32 v5;
    s32 i;
    u16 *w;
    if (data_0216fdac != NULL && data_0216fdac->mUnk_1316 != 0) {
        return 2;
    }
    v1 = (WirelessWork *) (((u32) a + 0x1f) & ~0x1f);
    v2 = (Unk0216fdac *) (((u32) v1 + 0x1e1f) & ~0x1f);
    if (d == 0x10000) {
        d = WM_GetNextTgid();
    }
    v3 = OS_DisableInterrupts();
    gWirelessDmaNo = e;
    gWirelessWork = v1;
    data_0216fdac = v2;
    v5 = 0;
    MIi_CpuClear32(v5, v1, 0x1e00);
    v4 = 0;
    MIi_CpuClear16(v4, v2, 0x1340);
    w = v1->mUnk_530;
    for (i = 0; i < b->mUnk_01; i++) {
        *w = b->mUnk_02[i];
        w++;
    }
    w = v1->mUnk_538;
    for (i = 0; i < 16; i++) {
        if (*data_usa_021617a0 == 0) {
            break;
        }
        *w = *data_usa_021617a0++;
        w++;
    }
    MI_CpuCopy8(b, &v2->mUnk_1300, 0x16);
    if (b->mUnk_01 < 10) {
        v2->mUnk_1300.mUnk_02[b->mUnk_01] = 0;
    }
    v1->mSendDataSize = 0x100;
    v1->mReceiveDataSize = 8;
    v1->mSendBufferSize = 0;
    v1->mReceiveBufferSize = 0;
    v1->mUnk_52c = 1;
    v1->mReceiveBuffer = v2->mUnk_0000 + 0x400;
    v1->mUnk_00e = 1;
    v1->mUnk_012 = 0;
    v1->mUnk_016 = 1;
    v1->mUnk_014 = 0;
    v1->mGgid = c;
    v1->mTgid = d;
    v1->mBeaconPeriod = GetBeaconDispersion() + 0xc8;
    v1->mMaxChildren = 0xf;
    v1->mDataQueued = 0;
    v1->mUnk_50d = 0;
    v2->mUnk_1316 = 1;
    v2->mUnk_131c = 0;
    OS_RestoreInterrupts(v3);
    return 0;
}

u32 IsMPSizeValid(u32 a, u32 b, u32 c) {
    s32 v;
    if (a > 0x1fe || a < 0xe4) {
        return 0;
    }
    if (b > 0x10 || b < 8) {
        return 0;
    }
    v = (a + 0x26) * 4 + 0x14a + c * ((b + 0x20) * 4 + 0x70);
    if (v < 0x15e0) {
        return 1;
    }
    return 0;
}

// Sets the send size and child limit before the parent starts; returns 0 when the start-up already ran or they do not
// fit.
u32 SetMPLimits(u32 a, u32 b) {
    u32 v;
    v = OS_DisableInterrupts();
    if (gWirelessWork->mUnk_50d != 0) {
        OS_RestoreInterrupts(v);
        return 0;
    }
    if (IsMPSizeValid(a, 8, b) == 0) {
        OS_RestoreInterrupts(v);
        return 0;
    }
    gWirelessWork->mMaxChildren = b;
    gWirelessWork->mSendDataSize = a;
    gWirelessWork->mReceiveDataSize = 8;
    OS_RestoreInterrupts(v);
    return 1;
}

s32 StartWirelessInitialize(void) {
    gWirelessWork->mMPStarted = 0;
    gWirelessWork->mConnectedAids = 0;
    gWirelessWork->mResetting = 0;
    gWirelessWork->mUnk_538[8] = 0;
    SetMaxChannelTime(10);
    if (data_0216fdac->mUnk_1320 == 0) {
        s32 v;
        do {
            v = WM_Initialize(gWMSysBuf, gWirelessWork->mCommandCallback, gWirelessDmaNo);
        } while (v == 4);
        if (v != 2) {
            return 8;
        }
        WM_SetIndCallback(gWirelessWork->mCommandCallback);
        gWirelessWork->mUnk_50d = 1;
        return 0;
    }
    WM_SetIndCallback(gWirelessWork->mCommandCallback);
    gWirelessWork->mUnk_50d = 1;
    func_0200ad00();
    return 0;
}

// Starts the parent on channel a: sets up the buffers and callbacks, then the callbacks bring the parent up.
s32 StartParentOnChannel(u16 a) {
    u32 v1;
    vu16 v2[2];
    s32 v4;
    s32 i;
    Unk0216fdac *v5;
    WirelessWork *v6;
    v1 = OS_DisableInterrupts();
    gWirelessWork->mChannel = a;
    v5 = data_0216fdac;
    gWMSysBuf = (void *) (((u32) v5 + 0x7d1f) & ~0x1f);
    v4 = (s32) v5->mCallback;
    v2[0] = 0;
    MIi_CpuClear16(v2[0], v5->mUnk_1340, 0x69c0);
    SetCallback((UnkFunc *) v4);
    data_0216fdac->mUnk_1318 = gWirelessWork->mSendDataSize - 6;
    SetupPieceSizes(gWirelessWork->mReceiveDataSize);
    SetupPieceBuffer((u32) data_0216fdac->mUnk_1538);
    for (i = 0; i < 15; i++) {
        data_0216fdac->mUnk_14e8[i] = 0;
        data_0216fdac->mChildEntryIndex[i] = -1;
    }
    data_0216fdac->mEntryCount = 0;
    v2[1] = 0;
    MIi_CpuClear16(v2[1], data_0216fdac->mUnk_1788, 0x5d40);
    MI_CpuFill8(data_0216fdac->mUnk_1754, 0, 0x1e);
    gWirelessWork->mMode = 1;
    gWirelessWork->mCallback = func_020079c4;
    gWirelessWork->mCommandCallback = ParentCallback;
    gWirelessWork->mUnk_034 = gWirelessWork->mSendDataSize;
    v6 = gWirelessWork;
    v6->mSendBufferSize = (v6->mUnk_034 + 0x23) & ~0x1f;
    gWirelessWork->mUnk_036 = gWirelessWork->mReceiveDataSize;
    v6 = gWirelessWork;
    v6->mReceiveBufferSize = (((v6->mUnk_036 + 0xe) * 0xf + 0x29) & ~0x1f) << 1;
    func_020096d4();
    v4 = StartWirelessInitialize();
    OS_RestoreInterrupts(v1);
    data_0216fdac->mUnk_74c8 = PXI_IsCallbackReady(0xf, 1);
    return v4;
}

s32 func_02009cc8(u16 a) {
    data_0216fdac->mUnk_1320 = 1;
    return StartParentOnChannel(a);
}

#pragma thumb off

#pragma thumb on

int StartWirelessReset(void) {
    int v1;
    v1 = WM_Reset(gWirelessWork->mCommandCallback);
    ReportCommandError(1, v1);
    if (v1 == 2) {
        v1 = 0;
    }
    return v1;
}

#pragma thumb off

#pragma thumb on
u32 func_02009c90(void) {
    u32 value0;
    u32 value3;
    value3 = (u32) &StartWirelessReset;
    value0 = StartWirelessReset();
    return value0;
}
#pragma thumb off

#pragma thumb on

// Starts a reset, on the worker when there is one; returns 1 when a reset is already under way.
u32 RequestWirelessReset(void) {
    u32 v1;
    u32 v2;
    v1 = 1;
    v2 = OS_DisableInterrupts();
    if (gWirelessWork->mResetting == 0) {
        v1 = 0;
        // the address of mRepeatScan is computed with a 64-bit add; its low half is the same address, and the leftover
        // flag-setting add (removed after register allocation) is what gives the original's registers
        *(u32 *) ((u32) gWirelessWork + 0x5e4LL) = v1;
        gWirelessWork->mResetting = 1;
        if (func_0200b018() != 0) {
            func_0200aeb4(func_02009c90);
        } else {
            v1 = StartWirelessReset();
        }
    }
    OS_RestoreInterrupts(v2);
    return v1;
}

#pragma thumb off

#pragma thumb on

void func_02009c04(void) {
    u32 v1;
    v1 = ((s64) OS_DisableInterrupts());
    if (data_0216fdac->mUnk_1320 == 0) {
        OS_Terminate();
    }
    RequestWirelessReset();
    OS_RestoreInterrupts(v1);
}

#pragma thumb off

#pragma thumb on

void DisconnectChild(u32 a) {
    u32 v1;
    u32 v2;
    s32 v3;
    u32 v4;
    WM_Disconnect(ParentCallback, a);
    if (a != 0 && a < 16) {
        v1 = a - 1;
        data_0216fdac->mUnk_148a[v1] = 0;
        MI_CpuFill8(data_0216fdac->mUnk_14a8 + v1, 0, 4);
        MI_CpuFill8(data_0216fdac->mUnk_1340 + v1 * 0x16, 0, 0x16);
        ClearChildPieces(a);
        v2 = 0;
        data_0216fdac->mUnk_1754[v1] = v2;
        v3 = data_0216fdac->mChildEntryIndex[v1];
        v2 = ~v2;
        if (v3 != v2) {
            v4 = 1 << a;
            v3 = (u8) v3;
            ((Unk0216fdac *) ((u8 *) data_0216fdac + v3 * 0x5d4))->mUnk_1d4e &= ~v4;
            ((Unk0216fdac *) ((u8 *) data_0216fdac + v3 * 0x5d4))->mUnk_1d50 |= v4;
            data_0216fdac->mChildEntryIndex[a - 1] = v2;
            ((Unk0216fdac *) ((u8 *) data_0216fdac + v3 * 0x5d4))->mUnk_1d4c &= ~v4;
        }
        if ((data_0216fdac->mUnk_1536 & (1 << a)) != 0) {
            data_0216fdac->mUnk_1535--;
            data_0216fdac->mUnk_1536 &= ~(1 << a);
        }
        data_0216fdac->mUnk_14e8[v1] = 0;
    }
}

#pragma thumb off

#pragma thumb on
void SetMaxChannelTime(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    gScanParams.mUnk_06 = value0;
}
#pragma thumb off

#pragma thumb on

s32 SetMPDataToPort(Unk021425e8Func a, void *b, s32 c, u16 d, u16 e) {
    s32 v;
    v = WM_SetMPDataToPortEx((UnkFunc *) a, NULL, b, c, e, 1, 3);
    ReportCommandError(0xf, v);
    return v;
}

int SendMPData(void *a, u32 b, u32 c) {
    WirelessWork *v1;
    u32 v2;
    s32 v3;
    u16 v4;
    u16 v5;
    v4 = b;
    v5 = c;
    v1 = gWirelessWork;
    if (v1->mMPStarted == 0 || v1->mResetting == 1) {
        return 1;
    }
    switch (v1->mMode) {
        case 1:
            if (v1->mUnk_52c == 0) {
                v2 = 0x3e8;
            } else {
                v2 = 0;
            }
            v3 = SetMPDataToPort(v1->mCommandCallback, a, v4, v2, v5);
            if (v3 == 2) {
                gWirelessWork->mDataQueued = 1;
            }
            if (v3 == 2) {
                v3 = 0;
            }
            return v3;
        case 2:
            v3 = SetMPDataToPort(ChildCallback, a, v4, 0, v5);
            if (v3 == 2) {
                gWirelessWork->mDataQueued = 1;
            }
            if (v3 == 2) {
                v3 = 0;
            }
            return v3;
        default:
            return 1;
    }
}

#pragma thumb off

#pragma thumb on

u32 GetGgid(void) {
    return gWirelessWork->mGgid;
}

u16 GetTgid(void) {
    return gWirelessWork->mTgid;
}

#pragma thumb off

#pragma thumb on

u8 GetGameInfoAttr(void) {
    WirelessWork *v1;
    u32 v2;
    u32 v3;
    u32 v4;
    u32 v5;
    v1 = gWirelessWork;
    if (v1->mUnk_012 != 0) {
        v2 = 2;
    } else {
        v2 = 0;
    }
    if (v1->mUnk_00e != 0) {
        v3 = 1;
    } else {
        v3 = 0;
    }
    if (v1->mUnk_014 != 0) {
        v4 = 4;
    } else {
        v4 = 0;
    }
    if (v1->mUnk_016 != 0) {
        v5 = 8;
    } else {
        v5 = 0;
    }
    return v5 | (v4 | (v3 | v2));
}

#pragma thumb off

#pragma thumb on

u32 func_02009958(void) {
    if (gWirelessWork->mUnk_50d == 1) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

void ReportCommandError(u16 a, s32 b) {
    u16 v[2];
    if (b != 2 && b != 0) {
        v[0] = a;
        v[1] = b;
        gWirelessWork->mCallback(0xff, (Unk021425e8 *) v);
    }
}

#pragma thumb off
