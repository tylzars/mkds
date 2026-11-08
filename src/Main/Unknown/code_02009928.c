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
void AddDataRange(DataRangeTable *table, u32 offset, u32 size, u8 *data, u32 value) {
    u32 savedInterrupts;
    DataRange *range;
    savedInterrupts = OS_DisableInterrupts();
    range = table->mUnk_30;
    for (;;) {
        if (range >= table->mUnk_30 + 4) {
            OS_Terminate();
        }
        if (range->mUnk_0c == 0) {
            range->mOffset = offset;
            range->mSize = size;
            range->mData = data;
            range->mUnk_0c = value;
            break;
        }
        range++;
    }
    OS_RestoreInterrupts(savedInterrupts);
}

u32 CopyFromDataRanges(DataRangeTable *table, u32 offset, void *destination, u32 byteCount) {
    u32 savedInterrupts;
    u32 found;
    DataRange *range;
    s32 offsetInRange;
    found = 0;
    savedInterrupts = OS_DisableInterrupts();
    for (range = table->mUnk_30; range < table->mUnk_30 + 4; range++) {
        if (range->mUnk_0c >= 2) {
            offsetInRange = offset - range->mOffset;
            if (offsetInRange >= 0 && offsetInRange + byteCount <= range->mSize) {
                MI_CpuCopy8(range->mData + offsetInRange, destination, byteCount);
                found = 1;
                table->mUnk_00 = found;
                break;
            }
        }
    }
    OS_RestoreInterrupts(savedInterrupts);
    return found;
}

// Moves the scan to the next allowed channel; returns 0 when no channel is allowed.
u32 AdvanceScanChannel(Unk02143a78 *scanParams) {
    u16 candidate;
    u16 i;
    u16 currentChannel;
    u32 allowedMask;
    allowedMask = WM_GetAllowedChannel();
    if (allowedMask == 0) {
        return 0;
    }
    i = 0;
    currentChannel = scanParams->mUnk_04;
    candidate = currentChannel;
    for (; i < 16;) {
        if ((allowedMask & (1 << (candidate - 1))) != 0 && currentChannel != candidate) {
            scanParams->mUnk_04 = candidate;
            break;
        }
        i++;
        candidate = candidate == 16 ? 1 : candidate + 1;
    }
    return 1;
}

u32 IsMPReadyToSendData(void) {
    u32 result;
    u32 v2;
    u32 v3;
    WirelessWork *work;
    result = 0;
    v2 = 0;
    v3 = 0;
    work = gWirelessWork;
    if (work->mMPStarted == 1) {
        if (work->mDataQueued == 0) {
            v3 = 1;
        }
    }
    if (v3 != 0) {
        if (work->mResetting == 0) {
            v2 = 1;
        }
    }
    if (v2 != 0) {
        if (work->mConnectedAids != 0) {
            result = 1;
        }
    }
    return result;
}

#pragma thumb off

#pragma thumb on

void func_0200ad00(void) {
    u32 result;
    result = WM_SetIndCallback(ParentCallback);
    ReportCommandError(0x80, result);
    result = WM_SetLifeTime(ParentCallback, data_0216179c, data_02161794, data_02161790, data_02161798);
    ReportCommandError(0x1d, result);
}

#pragma thumb off

#pragma thumb on

// Handles the results of the parent start-up steps, then child connects, disconnects and sent data.
void ParentCallback(Unk021425e8 *result) {
    u32 nonZeroCount;
    u32 i;
    Unk0216fdac *parentWork;
    u32 x;
    switch (result->mCommand) {
        case 0:
            if (result->mResultCode != 0) {
                gWirelessWork->mCallback(0x100, result);
                return;
            }
            func_0200ad00();
            return;
        case 0x1d:
            if (result->mResultCode != 0) {
                gWirelessWork->mCallback(0x100, result);
                return;
            }
            ReportCommandError(7, WM_SetParentParameter(ParentCallback, (Unk02143c30 *) gWirelessWork));
            return;
        case 7:
            gWirelessWork->mCallback(0x15, result);
            ReportCommandError(0x19, WM_SetBeaconIndication(ParentCallback, 1));
            return;
        case 0x19:
            if (result->mResultCode != 0) {
                gWirelessWork->mCallback(0x100, result);
                return;
            }
            ReportCommandError(8, WMi_StartParentEx(ParentCallback, data_usa_021617a4));
            return;
        case 8:
            if (result->mResultCode != 0) {
                gWirelessWork->mCallback(0x100, result);
                return;
            }
            switch (result->mUnk_08_0) {
                case 0:
                    gWirelessWork->mConnectedAids = 0;
                    gWirelessWork->mMPStarted = 0;
                    return;
                case 7:
                    if (gWirelessWork->mResetting == 1) {
                        return;
                    }
                    gWirelessWork->mConnectedAids |= 1 << result->mUnk_10;
                    gWirelessWork->mCallback(0, result);
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
                    gWirelessWork->mConnectedAids &= ~(1 << result->mUnk_10);
                    gWirelessWork->mCallback(1, result);
                    return;
                case 2:
                    if (gWirelessWork->mResetting == 1) {
                        return;
                    }
                    gWirelessWork->mCallback(0x1c, result);
                    return;
                default:
                    gWirelessWork->mCallback(0x100, result);
                    return;
            }
        case 14:
            data_0216fdac->mUnk_131c = 0;
            switch (result->mUnk_04) {
                case 10:
                    gWirelessWork->mMPStarted = 1;
                    gWirelessWork->mCallback(0x19, NULL);
                    return;
                case 11:
                    gWirelessWork->mCallback(3, result->mUnk_08);
                    return;
                default:
                    gWirelessWork->mCallback(0x100, result);
                    return;
            }
        case 15:
            parentWork = data_0216fdac;
            if (parentWork->mUnk_74c8 != 0) {
                nonZeroCount = 0;
                for (i = 0; i < 15; i++) {
                    if (parentWork->mUnk_14e8[i] != 0) {
                        nonZeroCount++;
                        if (nonZeroCount >= 2) {
                            break;
                        }
                    }
                }
                if (nonZeroCount == 1) {
                    OS_SpinWait(0x32c8);
                }
            }
            gWirelessWork->mDataQueued = 0;
            if (result->mResultCode == 0) {
                gWirelessWork->mCallback(2, result);
                gWirelessWork->mCallback(0x19, NULL);
                return;
            }
            if (result->mResultCode == 10) {
                gWirelessWork->mCallback(0x2a, result);
                return;
            }
            gWirelessWork->mCallback(0x13, result);
            gWirelessWork->mCallback(0x19, NULL);
            return;
        case 1:
            if (data_0216fdac->mUnk_1320 == 0) {
                if (result->mResultCode != 0) {
                    gWirelessWork->mResetting = 0;
                    gWirelessWork->mCallback(0x100, result);
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
            if (result->mResultCode != 0) {
                gWirelessWork->mResetting = 0;
                gWirelessWork->mCallback(0x100, result);
                return;
            }
            gWirelessWork->mUnk_50d = 0;
            data_0216fdac->mUnk_1316 = 0;
            gWirelessWork->mCallback(0x11, result);
            return;
        case 13:
            if (result->mResultCode == 0) {
                gWirelessWork->mConnectedAids &= ~result->mUnk_08_2;
            }
            return;
        case 0x80:
            switch (result->mUnk_04) {
                case 0x10:
                    gWirelessWork->mCallback(0x1d, result);
                    return;
                case 0x11:
                    gWirelessWork->mCallback(0x1f, result);
                    return;
                case 0x12:
                    gWirelessWork->mCallback(0x20, result);
                    return;
                case 0x13:
                    gWirelessWork->mCallback(0x21, result);
                    return;
                case 0x16:
                    OS_Terminate();
                    break;
                case 0x17:
                    break;
            }
            break;
        default:
            gWirelessWork->mCallback(0x100, result);
            return;
    }
}

void ChildPortCallback(Unk021425e8 *result) {
    if (result->mResultCode == 0) {
        if (result->mUnk_04 == 7) {
        } else if (result->mUnk_04 == 9) {
        } else if (result->mUnk_04 == 0x15) {
            gWirelessWork->mCallback(9, result);
        }
    }
}

// Child side (scan, connect, MP data); mMode is only ever 1, so this does not run in this build.
void ChildCallback(Unk021425e8 *result) {
    ScanEntry *entry;
    u8 c;
    WirelessWork *work;
    s32 i;
    s32 entryCount;
    u32 entryOffset;
    u8 *entries;
    work = gWirelessWork;
    switch (result->mCommand) {
        case 0:
            if (result->mResultCode != 0) {
                work->mCallback(0x100, result);
                return;
            }
            work->mCallback(0x15, result);
            ReportCommandError(
                0x1d, WM_SetLifeTime(ChildCallback, data_0216179c, data_02161794, data_02161790, data_02161798));
            return;
        case 0x1d:
            if (result->mResultCode != 0) {
                work->mCallback(0x100, result);
                return;
            }
            gScanParams.mUnk_00 = work->mScanBuffer;
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
            work->mRepeatScan = 1;
            work->mUnk_5e8 = 1;
            ReportCommandError(0xa, WM_StartScan(ChildCallback, &gScanParams));
            return;
        case 10:
            if (result->mResultCode != 0) {
                work->mCallback(0x100, result);
                return;
            }
            switch (result->mUnk_08_0) {
                case 3:
                    return;
                case 5:
                    entries = (u8 *) work->mScanEntries;
                    i = 0;
                    entryCount = work->mScanEntryCount;
                    if (entryCount > 0) {
                        entry = (ScanEntry *) entries;
                        c = result->mUnk_0a[0];
                        do {
                            if (c == entry->mMessage.mUnk_0a[0] && result->mUnk_0a[1] == entry->mMessage.mUnk_0a[1] &&
                                result->mUnk_0a[2] == entry->mMessage.mUnk_0a[2] &&
                                result->mUnk_0a[3] == entry->mMessage.mUnk_0a[3] &&
                                result->mUnk_0a[4] == entry->mMessage.mUnk_0a[4] &&
                                result->mUnk_0a[5] == entry->mMessage.mUnk_0a[5]) {
                                entryOffset = i * 0x180;
                                ((ScanEntry *) (entries + entryOffset))->mMessage.mUnk_36 = result->mUnk_36;
                                ((ScanEntry *) (entries + (s32) entryOffset))->mMessage.mUnk_38 = result->mUnk_38;
                                DC_InvalidateRange((ScanEntry *) ((u8 *) work->mScanEntries + entryOffset), 0xc0);
                                MI_DmaCopy16(gWirelessDmaNo, work->mScanBuffer,
                                             (ScanEntry *) ((u8 *) work->mScanEntries + entryOffset), 0xc0);
                                work->mLastScanEntry = i;
                                goto done;
                            }
                            entry++;
                            i++;
                        } while (i < entryCount);
                    }
                    if (i < 16) {
                        work->mScanEntryCount = i + 1;
                        entryOffset = i * 0x180;
                        MIi_CpuCopy16(result, entries + entryOffset + 0xc0, 0xb8);
                        entry = (ScanEntry *) ((u8 *) work->mScanEntries + entryOffset);
                        DC_InvalidateRange(entry, 0xc0);
                        MI_DmaCopy16(gWirelessDmaNo, work->mScanBuffer, entry, 0xc0);
                        work->mLastScanEntry = i;
                    }
                done:
                    work->mCallback(4, result);
                    if (work->mRepeatScan == 0) {
                        return;
                    }
                    if (work->mUnk_5e8 != 0) {
                        if (AdvanceScanChannel(&gScanParams) == 0) {
                            RequestWirelessReset();
                        }
                    }
                    ReportCommandError(0xa, WM_StartScan(ChildCallback, &gScanParams));
                    return;
                case 4:
                    work->mCallback(5, result);
                    if (work->mRepeatScan == 0) {
                        return;
                    }
                    if (work->mUnk_5e8 != 0) {
                        if (AdvanceScanChannel(&gScanParams) == 0) {
                            RequestWirelessReset();
                        }
                    }
                    ReportCommandError(0xa, WM_StartScan(ChildCallback, &gScanParams));
                    return;
                default:
                    work->mCallback(0x100, result);
                    return;
            }
        case 11:
            if (result->mResultCode != 0) {
                work->mCallback(0x100, result);
                return;
            }
            ReportCommandError(0xc, WM_StartConnectEx(ChildCallback, work->mUnk_520, NULL, 1, 0));
            return;
        case 12:
            if (result->mResultCode != 0) {
                work->mScanEntryCount = 0;
                work->mCallback(0xb, result);
                return;
            }
            switch (result->mUnk_08_0) {
                case 6:
                    work->mConnectedAids = 0;
                    work->mMPStarted = 1;
                    return;
                case 7:
                    work->mUnk_5e2 = result->mUnk_08_2;
                    work->mCallback(6, result);
                    work->mConnectedAids = 1;
                    if (WM_SetPortCallback(1, (UnkFunc *) ChildPortCallback, NULL) != 0) {
                        return;
                    }
                    ReportCommandError(0xe, WM_StartMPEx(ChildCallback, work->mReceiveBuffer, work->mReceiveBufferSize,
                                                         work->mSendBuffer, work->mSendBufferSize,
                                                         work->mUnk_52c == 0 ? 1 : 0, 0, 0, 0, 1, 1));
                    return;
                case 9:
                    work->mCallback(10, result);
                    work->mConnectedAids = 0;
                    work->mMPStarted = 0;
                    return;
                default:
                    work->mCallback(0x100, result);
                    return;
            }
        case 14:
            switch (result->mUnk_04) {
                case 10:
                    work->mMPStarted = 1;
                    if (IsMPReadyToSendData() == 0) {
                        return;
                    }
                    work->mCallback(0x19, NULL);
                    return;
                case 12:
                case 13:
                    return;
                default:
                    work->mCallback(0x100, result);
                    return;
            }
        case 15:
            work->mDataQueued = 0;
            if (result->mResultCode == 0) {
                work->mCallback(8, result);
            } else if (result->mResultCode == 9) {
                work->mCallback(0x29, result);
            } else {
                work->mCallback(0x12, result);
            }
            work->mCallback(0x19, NULL);
            return;
        case 1:
            if (result->mResultCode != 0) {
                work->mResetting = 0;
                work->mCallback(0x100, result);
                return;
            }
            work->mConnectedAids = 0;
            gWirelessWork->mMPStarted = 0;
            ReportCommandError(2, WM_End(ChildCallback));
            return;
        case 2:
            if (result->mResultCode != 0) {
                work->mResetting = 0;
                work->mCallback(0x100, result);
                return;
            }
            work->mUnk_50d = 0;
            data_0216fdac->mUnk_1316 = 0;
            work->mCallback(0x11, result);
            return;
        case 21:
            if (IsMPReadyToSendData() == 0) {
                return;
            }
            work->mCallback(0x19, NULL);
            return;
        case 0x80:
            switch (result->mUnk_04) {
                case 0x16:
                    OS_Terminate();
                    break;
                case 0x17:
                    break;
            }
            return;
        default:
            work->mCallback(0x100, result);
            return;
    }
}

// A value from 0 to 19 made from the MAC address; the caller adds 200 for the beacon period.
u32 GetBeaconDispersion(void) {
    u8 macAddress[6];
    u32 byteSum;
    s32 i;
    OS_GetMacAddress(macAddress);
    i = 0;
    byteSum = 0;
    for (; i < 6; i++) {
        byteSum += macAddress[i];
    }
    return (byteSum + *(vu32 *) 0x27ffc3c) * 7 % 0x14;
}

s32 InitWirelessWork(void *buffer, Unk02009ff4 *b, u32 ggid, u32 tgid, u32 dmaNo) {
    WirelessWork *wirelessWork;
    Unk0216fdac *parentWork;
    u32 savedInterrupts;
    vu16 clearValue16;
    vu32 clearValue32;
    s32 i;
    u16 *w;
    if (data_0216fdac != NULL && data_0216fdac->mUnk_1316 != 0) {
        return 2;
    }
    wirelessWork = (WirelessWork *) (((u32) buffer + 0x1f) & ~0x1f);
    parentWork = (Unk0216fdac *) (((u32) wirelessWork + 0x1e1f) & ~0x1f);
    if (tgid == 0x10000) {
        tgid = WM_GetNextTgid();
    }
    savedInterrupts = OS_DisableInterrupts();
    gWirelessDmaNo = dmaNo;
    gWirelessWork = wirelessWork;
    data_0216fdac = parentWork;
    clearValue32 = 0;
    MIi_CpuClear32(clearValue32, wirelessWork, 0x1e00);
    clearValue16 = 0;
    MIi_CpuClear16(clearValue16, parentWork, 0x1340);
    w = wirelessWork->mUnk_530;
    for (i = 0; i < b->mUnk_01; i++) {
        *w = b->mUnk_02[i];
        w++;
    }
    w = wirelessWork->mUnk_538;
    for (i = 0; i < 16; i++) {
        if (*data_usa_021617a0 == 0) {
            break;
        }
        *w = *data_usa_021617a0++;
        w++;
    }
    MI_CpuCopy8(b, &parentWork->mUnk_1300, 0x16);
    if (b->mUnk_01 < 10) {
        parentWork->mUnk_1300.mUnk_02[b->mUnk_01] = 0;
    }
    wirelessWork->mSendDataSize = 0x100;
    wirelessWork->mReceiveDataSize = 8;
    wirelessWork->mSendBufferSize = 0;
    wirelessWork->mReceiveBufferSize = 0;
    wirelessWork->mUnk_52c = 1;
    wirelessWork->mReceiveBuffer = parentWork->mUnk_0000 + 0x400;
    wirelessWork->mUnk_00e = 1;
    wirelessWork->mUnk_012 = 0;
    wirelessWork->mUnk_016 = 1;
    wirelessWork->mUnk_014 = 0;
    wirelessWork->mGgid = ggid;
    wirelessWork->mTgid = tgid;
    wirelessWork->mBeaconPeriod = GetBeaconDispersion() + 0xc8;
    wirelessWork->mMaxChildren = 0xf;
    wirelessWork->mDataQueued = 0;
    wirelessWork->mUnk_50d = 0;
    parentWork->mUnk_1316 = 1;
    parentWork->mUnk_131c = 0;
    OS_RestoreInterrupts(savedInterrupts);
    return 0;
}

u32 IsMPSizeValid(u32 sendDataSize, u32 receiveDataSize, u32 maxChildren) {
    s32 totalSize;
    if (sendDataSize > 0x1fe || sendDataSize < 0xe4) {
        return 0;
    }
    if (receiveDataSize > 0x10 || receiveDataSize < 8) {
        return 0;
    }
    totalSize = (sendDataSize + 0x26) * 4 + 0x14a + maxChildren * ((receiveDataSize + 0x20) * 4 + 0x70);
    if (totalSize < 0x15e0) {
        return 1;
    }
    return 0;
}

// Sets the send size and child limit before the parent starts; returns 0 when the start-up already ran or they do not
// fit.
u32 SetMPLimits(u32 sendDataSize, u32 maxChildren) {
    u32 savedInterrupts;
    savedInterrupts = OS_DisableInterrupts();
    if (gWirelessWork->mUnk_50d != 0) {
        OS_RestoreInterrupts(savedInterrupts);
        return 0;
    }
    if (IsMPSizeValid(sendDataSize, 8, maxChildren) == 0) {
        OS_RestoreInterrupts(savedInterrupts);
        return 0;
    }
    gWirelessWork->mMaxChildren = maxChildren;
    gWirelessWork->mSendDataSize = sendDataSize;
    gWirelessWork->mReceiveDataSize = 8;
    OS_RestoreInterrupts(savedInterrupts);
    return 1;
}

s32 StartWirelessInitialize(void) {
    gWirelessWork->mMPStarted = 0;
    gWirelessWork->mConnectedAids = 0;
    gWirelessWork->mResetting = 0;
    gWirelessWork->mUnk_538[8] = 0;
    SetMaxChannelTime(10);
    if (data_0216fdac->mUnk_1320 == 0) {
        s32 result;
        do {
            result = WM_Initialize(gWMSysBuf, gWirelessWork->mCommandCallback, gWirelessDmaNo);
        } while (result == 4);
        if (result != 2) {
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
s32 StartParentOnChannel(u16 channel) {
    u32 savedInterrupts;
    vu16 clearValues[2];
    s32 v4;
    s32 i;
    Unk0216fdac *parentWork;
    WirelessWork *wirelessWork;
    savedInterrupts = OS_DisableInterrupts();
    gWirelessWork->mChannel = channel;
    parentWork = data_0216fdac;
    gWMSysBuf = (void *) (((u32) parentWork + 0x7d1f) & ~0x1f);
    v4 = (s32) parentWork->mCallback;
    clearValues[0] = 0;
    MIi_CpuClear16(clearValues[0], parentWork->mUnk_1340, 0x69c0);
    SetCallback((UnkFunc *) v4);
    data_0216fdac->mUnk_1318 = gWirelessWork->mSendDataSize - 6;
    SetupPieceSizes(gWirelessWork->mReceiveDataSize);
    SetupPieceBuffer((u32) data_0216fdac->mUnk_1538);
    for (i = 0; i < 15; i++) {
        data_0216fdac->mUnk_14e8[i] = 0;
        data_0216fdac->mChildEntryIndex[i] = -1;
    }
    data_0216fdac->mEntryCount = 0;
    clearValues[1] = 0;
    MIi_CpuClear16(clearValues[1], data_0216fdac->mUnk_1788, 0x5d40);
    MI_CpuFill8(data_0216fdac->mUnk_1754, 0, 0x1e);
    gWirelessWork->mMode = 1;
    gWirelessWork->mCallback = func_020079c4;
    gWirelessWork->mCommandCallback = ParentCallback;
    gWirelessWork->mUnk_034 = gWirelessWork->mSendDataSize;
    wirelessWork = gWirelessWork;
    wirelessWork->mSendBufferSize = (wirelessWork->mUnk_034 + 0x23) & ~0x1f;
    gWirelessWork->mUnk_036 = gWirelessWork->mReceiveDataSize;
    wirelessWork = gWirelessWork;
    wirelessWork->mReceiveBufferSize = (((wirelessWork->mUnk_036 + 0xe) * 0xf + 0x29) & ~0x1f) << 1;
    InitGameInfoList();
    v4 = StartWirelessInitialize();
    OS_RestoreInterrupts(savedInterrupts);
    data_0216fdac->mUnk_74c8 = PXI_IsCallbackReady(0xf, 1);
    return v4;
}

s32 func_02009cc8(u16 channel) {
    data_0216fdac->mUnk_1320 = 1;
    return StartParentOnChannel(channel);
}

#pragma thumb off

#pragma thumb on

int StartWirelessReset(void) {
    int result;
    result = WM_Reset(gWirelessWork->mCommandCallback);
    ReportCommandError(1, result);
    if (result == 2) {
        result = 0;
    }
    return result;
}

#pragma thumb off

#pragma thumb on
u32 func_02009c90(void) {
    u32 result;
    u32 value3;
    value3 = (u32) &StartWirelessReset;
    result = StartWirelessReset();
    return result;
}
#pragma thumb off

#pragma thumb on

// Starts a reset, on the worker when there is one; returns 1 when a reset is already under way.
u32 RequestWirelessReset(void) {
    u32 result;
    u32 savedInterrupts;
    result = 1;
    savedInterrupts = OS_DisableInterrupts();
    if (gWirelessWork->mResetting == 0) {
        result = 0;
        // the address of mRepeatScan is computed with a 64-bit add; its low half is the same address, and the leftover
        // flag-setting add (removed after register allocation) is what gives the original's registers
        *(u32 *) ((u32) gWirelessWork + 0x5e4LL) = result;
        gWirelessWork->mResetting = 1;
        if (IsWorkerActive() != 0) {
            RequestWorkerStop(func_02009c90);
        } else {
            result = StartWirelessReset();
        }
    }
    OS_RestoreInterrupts(savedInterrupts);
    return result;
}

#pragma thumb off

#pragma thumb on

void func_02009c04(void) {
    u32 savedInterrupts;
    savedInterrupts = ((s64) OS_DisableInterrupts());
    if (data_0216fdac->mUnk_1320 == 0) {
        OS_Terminate();
    }
    RequestWirelessReset();
    OS_RestoreInterrupts(savedInterrupts);
}

#pragma thumb off

#pragma thumb on

void DisconnectChild(u32 childIndex) {
    u32 slot;
    u32 v2;
    s32 entryIndex;
    u32 childBit;
    WM_Disconnect(ParentCallback, childIndex);
    if (childIndex != 0 && childIndex < 16) {
        slot = childIndex - 1;
        data_0216fdac->mUnk_148a[slot] = 0;
        MI_CpuFill8(data_0216fdac->mUnk_14a8 + slot, 0, 4);
        MI_CpuFill8(data_0216fdac->mUnk_1340 + slot * 0x16, 0, 0x16);
        ClearChildPieces(childIndex);
        v2 = 0;
        data_0216fdac->mUnk_1754[slot] = v2;
        entryIndex = data_0216fdac->mChildEntryIndex[slot];
        v2 = ~v2;
        if (entryIndex != v2) {
            childBit = 1 << childIndex;
            entryIndex = (u8) entryIndex;
            ((Unk0216fdac *) ((u8 *) data_0216fdac + entryIndex * 0x5d4))->mUnk_1d4e &= ~childBit;
            ((Unk0216fdac *) ((u8 *) data_0216fdac + entryIndex * 0x5d4))->mUnk_1d50 |= childBit;
            data_0216fdac->mChildEntryIndex[childIndex - 1] = v2;
            ((Unk0216fdac *) ((u8 *) data_0216fdac + entryIndex * 0x5d4))->mUnk_1d4c &= ~childBit;
        }
        if ((data_0216fdac->mUnk_1536 & (1 << childIndex)) != 0) {
            data_0216fdac->mUnk_1535--;
            data_0216fdac->mUnk_1536 &= ~(1 << childIndex);
        }
        data_0216fdac->mUnk_14e8[slot] = 0;
    }
}

#pragma thumb off

#pragma thumb on
void SetMaxChannelTime(u32 maxChannelTime) {
    u32 value0 = maxChannelTime;
    u32 value1;
    gScanParams.mUnk_06 = value0;
}
#pragma thumb off

#pragma thumb on

s32 SetMPDataToPort(Unk021425e8Func callback, void *data, s32 dataSize, u16 d, u16 e) {
    s32 result;
    result = WM_SetMPDataToPortEx((UnkFunc *) callback, NULL, data, dataSize, e, 1, 3);
    ReportCommandError(0xf, result);
    return result;
}

int SendMPData(void *data, u32 size, u32 childMask) {
    WirelessWork *work;
    u32 v2;
    s32 result;
    u16 sizeHalfword;
    u16 childMaskHalfword;
    sizeHalfword = size;
    childMaskHalfword = childMask;
    work = gWirelessWork;
    if (work->mMPStarted == 0 || work->mResetting == 1) {
        return 1;
    }
    switch (work->mMode) {
        case 1:
            if (work->mUnk_52c == 0) {
                v2 = 0x3e8;
            } else {
                v2 = 0;
            }
            result = SetMPDataToPort(work->mCommandCallback, data, sizeHalfword, v2, childMaskHalfword);
            if (result == 2) {
                gWirelessWork->mDataQueued = 1;
            }
            if (result == 2) {
                result = 0;
            }
            return result;
        case 2:
            result = SetMPDataToPort(ChildCallback, data, sizeHalfword, 0, childMaskHalfword);
            if (result == 2) {
                gWirelessWork->mDataQueued = 1;
            }
            if (result == 2) {
                result = 0;
            }
            return result;
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
    WirelessWork *work;
    u32 bit2;
    u32 bit1;
    u32 bit4;
    u32 bit8;
    work = gWirelessWork;
    if (work->mUnk_012 != 0) {
        bit2 = 2;
    } else {
        bit2 = 0;
    }
    if (work->mUnk_00e != 0) {
        bit1 = 1;
    } else {
        bit1 = 0;
    }
    if (work->mUnk_014 != 0) {
        bit4 = 4;
    } else {
        bit4 = 0;
    }
    if (work->mUnk_016 != 0) {
        bit8 = 8;
    } else {
        bit8 = 0;
    }
    return bit8 | (bit4 | (bit1 | bit2));
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

void ReportCommandError(u16 command, s32 resultCode) {
    u16 report[2];
    if (resultCode != 2 && resultCode != 0) {
        report[0] = command;
        report[1] = resultCode;
        gWirelessWork->mCallback(0xff, (Unk021425e8 *) report);
    }
}

#pragma thumb off
