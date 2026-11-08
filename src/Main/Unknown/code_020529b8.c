#include "Main/Unknown/code_020529b8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_02046c10.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200f59c.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_0204a52c.h"
#include "Main/Unknown/code_0204b000.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_0204bca0.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_0204f5e4.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_02053000.h"
#include "Main/Unknown/code_02055000.h"
#include "Main/Unknown/code_02059878.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200fc8c.h"
#include "code_02142eac.h"
#include "code_021445e0.h"
#include "wm_etc.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0203c25c.h"

void func_02053d00(void) {
    Unk02143a78 *scanParams;
    Unk021438f0 *scanExParams;
    Unk0217aa00_16a0_view *blocks;
    BlockEntry *blockEntry;
    s32 i;

    if (data_0217aa00 == NULL) {
        return;
    }
    data_0217aa00->mUnk_0000 = 0;
    data_0217aa00->mUnk_0004 = 0;
    data_0217aa00->mUnk_0008 = 9;
    data_0217aa00->mUnk_000c = 0;
    data_0217aa00->mRequestPending = 0;
    data_0217aa00->mUnk_0454 = 0;
    scanParams = data_0217aa00->mUnk_001c;
    scanParams->mUnk_00 = data_0217aa00->mUnk_0028;
    scanParams->mUnk_04 = 0;
    scanParams->mUnk_06 = 0;
    for (i = 0; i < 6; i++) {
        scanParams->mUnk_08[i] = 0xff;
    }
    scanExParams = data_0217aa00->mUnk_0020;
    scanExParams->mUnk_00 = data_0217aa00->mUnk_002c;
    scanExParams->mUnk_04 = 0x400;
    scanExParams->mUnk_06 = 0;
    scanExParams->mUnk_08 = 0;
    scanExParams->mUnk_10 = 1;
    scanExParams->mUnk_12 = 0;
    for (i = 0; i < 6; i++) {
        scanExParams->mUnk_0a[i] = 0xff;
    }
    ResetConnectionData();
    blocks = &data_0217aa00->mUnk_16a0_view;
    blockEntry = &blocks->mBlockEntries[0];
    for (i = 0; i < 0xc; i++) {
        blockEntry->mPath = 0;
        blockEntry->mBuffer = NULL;
        blockEntry++;
    }
    blocks->mUnk_6b4 = 0;
    blocks->mUnk_660 = 0;
    blocks->mUnk_798 = FALSE;
    blocks->mUnk_79c = FALSE;
    func_0204e65c(&data_0217aa00->mUnk_1658_view);
    func_02059878();
    FillParentParameter(1);
}

// Fills the record handed to WM_StepDataSharing, steps the data sharing with it and keeps the result.
void StepDataSharing(void) {
    Unk0217aa00_15c4 *sendData;
    u32 role;
    s32 result;

    GetSceneFrames();
    sendData = data_0217aa00->mUnk_15c4;
    if (data_0217aa00->mUnk_0004 == 8) {
        sendData->mUnk_05 = data_0217aa00->mUnk_15f7;
    } else {
        sendData->mUnk_05 = 0;
    }
    sendData->mUnk_04 = (data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000) == 1 ? data_0217aa00->mUnk_1eac[0] : 0;
    sendData->mUnk_00 = GetPadKeys();
    sendData->mUnk_06_0 = 0;
    sendData->mUnk_07 = 0;
    role = 0;
    if (data_0217aa00->mUnk_0004 == 9) {
        if (data_0217aa00 != NULL) {
            role = data_0217aa00->mUnk_0000;
        }
        if (role == 1) {
            if (func_02055afc() != FALSE) {
                sendData->mUnk_06_0 |= 4;
            } else {
                sendData->mUnk_06_0 &= ~4;
            }
        }
    }
    role = data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000;
    if (role != 1 || (data_0217aa00->mUnk_008b & 1) != 0) {
        if (data_0217aa00->mUnk_15ec == 0) {
            sendData->mUnk_06_0 |= 1;
            sendData->mUnk_06_0 &= ~2;
        } else {
            sendData->mUnk_06_0 |= 2;
            sendData->mUnk_06_0 &= ~1;
        }
    }
    sendData->mUnk_06_7 = gTouchMicInput->mMicOverThreshold;
    sendData->mUnk_02 = GetPackedTouchPoint();
    result = WM_StepDataSharing(data_0217aa00->mUnk_15bc, sendData, data_0217aa00->mUnk_15c0);
    if (result == 0) {
        if (data_0217aa00->mUnk_0004 == 8) {
            data_0217aa00->mUnk_15f7 = 0;
        }
    }
    data_0217aa00->mUnk_15f0 = result;
}

BOOL UpdateDataSharing(void) {
    DataSharing *dataSharing;
    BOOL allRead;
    u16 i;
    u16 j;
    u8 m;
    u8 *sharedData;
    u8 buf[8][8];
    u32 participantMask;
    u32 bit;
    u16 entryIndex;

    dataSharing = &data_0217aa00->mUnk_15bc_view;
    data_0217aa00->mUnk_1606 = data_0217aa00->mUnk_15bc->mDs[data_0217aa00->mUnk_15bc->mWriteIndex].mArrivedMembers;
    data_0217aa00->mUnk_0454 &= ~0x10;
    switch (data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000) {
        case 1:
            if (data_0217aa00->mUnk_0044.mChildCount != 0) {
                StepDataSharing();
            } else {
                return FALSE;
            }
            break;
        case 2:
            if (data_0217aa00->mOwnIndex != 0xffff) {
                StepDataSharing();
            } else {
                return FALSE;
            }
            break;
    }
    switch (data_0217aa00->mUnk_0004) {
        case 8:
            if (dataSharing->mUnk_34 != 0 && dataSharing->mUnk_34 == 5) {
                return FALSE;
            }
            break;
        case 9:
            if (dataSharing->mUnk_34 != 0) {
                if (dataSharing->mUnk_34 == 5) {
                    return FALSE;
                }
            } else {
                if ((data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000) == 1) {
                    for (j = 1; j < 8; j++) {
                        if ((data_0217aa00->mParticipantMask & (1 << j)) != 0) {
                            data_0217aa00->mUnk_15f8[j - 1] = 0;
                        }
                    }
                }
            }
            break;
    }
    allRead = TRUE;
    sharedData = WM_GetSharedDataAddress(data_0217aa00->mUnk_15bc, data_0217aa00->mUnk_15c0, 0);
    if (sharedData != NULL) {
        m = sharedData[4];
        if (m != 0) {
            for (i = 0; i < 8; i++) {
                bit = 1 << i;
                participantMask = data_0217aa00->mParticipantMask;
                entryIndex = data_0217aa00->mUnk_1e52[i].mEntryIndex;
                if ((participantMask & bit) != 0 && (m & bit) != 0) {
                    data_0217aa00->mParticipantMask = participantMask & ~bit;
                    if (data_0217aa00->mUnk_0004 == 9) {
                        RemoveRaceProgressKart(entryIndex);
                    }
                    if ((data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000) == 1) {
                        data_0217aa00->mUnk_1eac[0] &= ~bit;
                    }
                }
            }
        }
        MI_CpuCopy8(sharedData, &buf[0], 8);
    } else {
        allRead = FALSE;
    }
    if (allRead != FALSE) {
        for (i = 1; i < 8; i++) {
            if ((data_0217aa00->mParticipantMask & (1 << i)) != 0) {
                sharedData = WM_GetSharedDataAddress(data_0217aa00->mUnk_15bc, data_0217aa00->mUnk_15c0, i);
                if (sharedData != NULL) {
                    MI_CpuCopy8(sharedData, &buf[i], 8);
                } else {
                    allRead = FALSE;
                    break;
                }
            }
        }
    }
    for (i = 0; i < 8; i++) {
        if (allRead != FALSE && (data_0217aa00->mParticipantMask & (1 << i)) != 0) {
            MI_CpuCopy8(&buf[i], &dataSharing->mUnk_0c[i], 8);
            dataSharing->mSharedDataCopied[i] = 1;
        } else {
            dataSharing->mSharedDataCopied[i] = 0;
        }
    }
    return allRead != FALSE;
}

void Initialize(void) {
    data_0217aa00->mUnk_000c = 1;
    data_0217aa00->mRequestPending = 1;
    if (WM_Initialize(data_0217aa00->mUnk_0014, InitializeCallback, 2) != 2) {
        data_0217aa00->mRequestPending = 0;
    }
}

void InitializeCallback(Unk021425e8 *event) {
    s32 result;

    result = WM_SetPortCallback(0xf, MPDataPortCallback, NULL);
    data_0217aa00->mRequestPending = 0;
    if (result != 0) {
        return;
    }
    if (event->mResultCode != 0) {
        return;
    }
    if (data_0217aa00->mUnk_1d00 != 0) {
        WM_SetPortCallback(1, PacketPortCallback, NULL);
    }
    ResetConnectionData();
}

void func_020533a0(void) {
    u32 role;
    BOOL shouldStop;
    BOOL c;

    if ((data_0217aa00->mUnk_0454 & 0x100) != 0) {
        data_0217aa00->mUnk_000c = 0x26;
        data_0217aa00->mRequestPending = 1;
        shouldStop = FALSE;
        if ((data_0217aa00->mUnk_0454 & 0x40) != 0) {
            c = TRUE;
            role = data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000;
            if (role != 1 && ((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
                c = FALSE;
            }
            if (c != FALSE) {
                shouldStop = TRUE;
            }
        }
        if (shouldStop != FALSE) {
            StopRomArchive();
            data_0217aa00->mUnk_0454 &= ~0x100;
        }
        data_0217aa00->mRequestPending = 0;
        return;
    }
    if ((data_0217aa00->mUnk_0454 & 0x200) != 0) {
        func_0204eca0();
        return;
    }
    data_0217aa00->mUnk_000c = 2;
    data_0217aa00->mRequestPending = 1;
    if (WM_Reset(ResetCallback) == 2) {
        return;
    }
    data_0217aa00->mUnk_000c = 0x15;
    data_0217aa00->mRequestPending = 1;
    if (WM_End(EndCallback) == 2) {
        return;
    }
    if ((data_0217aa00->mUnk_0454 & 0x100) != 0) {
        data_0217aa00->mUnk_000c = 0x26;
        data_0217aa00->mRequestPending = 1;
        if (func_020510e4() != FALSE && (func_020510c8() == 1 || func_020510ac() != FALSE)) {
            c = TRUE;
        } else {
            c = FALSE;
        }
        if (c != FALSE) {
            StopRomArchive();
            data_0217aa00->mUnk_0454 &= ~0x100;
        }
        data_0217aa00->mRequestPending = 0;
        return;
    }
    if ((data_0217aa00->mUnk_0454 & 0x200) != 0) {
        func_0204eca0();
        return;
    }
    data_0217aa00->mUnk_000c = 2;
    data_0217aa00->mRequestPending = 1;
    if (WM_Reset(ResetCallback) == 2) {
        return;
    }
    data_0217aa00->mUnk_000c = 0x15;
    data_0217aa00->mRequestPending = 1;
    if (WM_End(EndCallback) == 2) {
        return;
    }
    if ((data_0217aa00->mUnk_0454 & 0x100) != 0) {
        StopRomArchiveTransfer();
        return;
    }
    if ((data_0217aa00->mUnk_0454 & 0x200) != 0) {
        func_0204eca0();
        return;
    }
    SetStepAndRequestPending(2);
    if (WM_Reset(ResetCallback) == 2) {
        return;
    }
    End();
}

void ResetCallback(Unk021425e8 *event) {
    data_0217aa00->mRequestPending = 0;
    if (event->mResultCode != 0) {
        data_0217aa00->mUnk_0008 = 1;
        data_0217aa00->mRequestPending = 0;
    } else {
        ResetConnectionData();
    }
}

void SetLifeTime(s32 camLifeTime) {
    data_0217aa00->mUnk_000c = 3;
    data_0217aa00->mRequestPending = 1;
    if (WM_SetLifeTime(func_0205329c, 0xffff, camLifeTime, 0xffff, 0xf) != 2) {
        func_020533a0();
    }
}

void func_0205329c(Unk021425e8 *event) {
    data_0217aa00->mRequestPending = 0;
    if (event->mResultCode != 0) {
        func_020533a0();
    }
}

// Measures each allowed channel 7 times in a row, in two passes over channels 1 to 14; a is the one just measured.
void MeasureChannel(u16 measuredChannel) {
    u16 allowedChannels;
    u16 channel;
    s32 i;

    data_0217aa00->mUnk_000c = 4;
    data_0217aa00->mRequestPending = 1;
    channel = measuredChannel;
    allowedChannels = WM_GetAllowedChannel();
    if (allowedChannels == 0) {
        data_0217aa00->mRequestPending = 0;
        data_0217aa00->mUnk_0008 = 3;
        data_0217aa00->mRequestPending = 0;
    } else if (allowedChannels == 0x8000) {
        data_0217aa00->mRequestPending = 0;
        data_0217aa00->mUnk_0008 = 8;
        data_0217aa00->mRequestPending = 0;
    }
    if (channel == 0) {
        data_0217aa00->mUnk_0089_0 = 1;
        data_0217aa00->mUnk_0089_4 = 1;
        for (i = 1; i < 0xe; i++) {
            data_0217aa00->mUnk_008c[i] = -1;
        }
        channel = 1;
    } else if (data_0217aa00->mUnk_0089_0 >= 7) {
        channel = channel + 1;
        data_0217aa00->mUnk_0089_0 = 1;
        if (((1 << (channel - 1)) & allowedChannels) == 0) {
            do {
                channel = channel + 1;
                if (channel > 0xe) {
                    if (data_0217aa00->mUnk_0089_4 >= 2) {
                        data_0217aa00->mRequestPending = 0;
                        return;
                    }
                    data_0217aa00->mUnk_0089_4 += 1;
                    channel = 1;
                    data_0217aa00->mUnk_0089_0 = 1;
                }
            } while (((1 << (channel - 1)) & allowedChannels) == 0);
        }
    } else {
        data_0217aa00->mUnk_0089_0 += 1;
    }
    if (WM_MeasureChannel(MeasureChannelCallback, 3, 0x11, channel, 0x14) != 2) {
        func_020533a0();
    }
}

void MeasureChannelCallback(Unk021425e8 *event) {
    s16 *channelSum;

    if (event->mResultCode != 0) {
        func_020533a0();
        return;
    }
    channelSum = &data_0217aa00->mUnk_008c[event->mUnk_08_0];
    if (*channelSum < 0) {
        *channelSum = 0;
    }
    *channelSum = *channelSum + event->mUnk_08_2;
    MeasureChannel(event->mUnk_08_0);
}

void *RomArchiveAllocFunc(s32 a, u32 size, void *block) {
    u32 savedInterrupts;
    void *allocated;

    allocated = NULL;
    savedInterrupts = OS_DisableInterrupts();
    if (block != NULL) {
        HeapFree(data_0217aa00->mHeap, block);
    } else {
        allocated = HeapAllocAligned(data_0217aa00->mHeap, size, -0x20);
    }
    OS_RestoreInterrupts(savedInterrupts);
    return allocated;
}

void StartRomArchiveTransfer(void) {
    u32 role;
    BOOL c;
    BOOL shouldStart;

    data_0217aa00->mUnk_000c = 0x24;
    data_0217aa00->mRequestPending = 1;
    shouldStart = FALSE;
    if ((data_0217aa00->mUnk_0454 & 0x40) != 0) {
        c = TRUE;
        role = data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000;
        if (role != 1 && ((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
            c = FALSE;
        }
        if (c != FALSE) {
            shouldStart = TRUE;
        }
    }
    if (shouldStart != FALSE) {
        role = data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000;
        StartRomArchive(role == 1 ? 1 : 0, 4, 0x154, RomArchiveStateCallback, RomArchiveAllocFunc, 0);
    }
    data_0217aa00->mRequestPending = 0;
    ResetPendingFiles();
}

void RomArchiveStateCallback(s32 a) {
    if (data_0217aa00->mUnk_000c == 0x24) {
        if (GetRomArchiveState() == 2) {
            data_0217aa00->mRequestPending = 0;
            ResetPendingFiles();
        }
    } else {
        data_0217aa00->mRequestPending = 0;
    }
}

void func_02052da4(void) {
    u32 role;
    BOOL c;
    BOOL shouldStart;

    data_0217aa00->mUnk_000c = 0x25;
    data_0217aa00->mRequestPending = 1;
    shouldStart = FALSE;
    if ((data_0217aa00->mUnk_0454 & 0x40) != 0) {
        c = TRUE;
        role = data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000;
        if (role != 1 && ((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
            c = FALSE;
        }
        if (c != FALSE) {
            shouldStart = TRUE;
        }
    }
    if (shouldStart != FALSE) {
        func_0204be0c();
        data_0217aa00->mUnk_1e34 = 0;
        data_0217aa00->mUnk_0454 |= 0x100;
    }
    data_0217aa00->mRequestPending = 0;
}

void StopRomArchiveTransfer(void) {
    u32 role;
    BOOL c;
    BOOL shouldStop;

    data_0217aa00->mUnk_000c = 0x26;
    data_0217aa00->mRequestPending = 1;
    shouldStop = FALSE;
    if ((data_0217aa00->mUnk_0454 & 0x40) != 0) {
        c = TRUE;
        role = data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000;
        if (role != 1 && ((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
            c = FALSE;
        }
        if (c != FALSE) {
            shouldStop = TRUE;
        }
    }
    if (shouldStop != FALSE) {
        StopRomArchive();
        data_0217aa00->mUnk_0454 &= ~0x100;
    }
    data_0217aa00->mRequestPending = 0;
}

u16 func_02052c5c(u32 a) {
    RTCTime time;
    u32 h;
    u16 seconds;
    u64 x;
    u64 y;

    GetClockTimeOrZero(&time);
    h = time.mHour;
    if (h >= 0x12) {
        h -= 0x12;
    }
    seconds = (h * 0x3c + time.mMinute) * 0x3c + time.mSecond;
    x = OS_GetTickLo() | seconds << 16;
    x = x * 0x5d588b656c078965ull + 0x269ec3;
    y = x >> 32;
    return (u16) (y * 0x10000 >> 32) | 0x8000;
}

// Calls WM_SetParentParameter; also stores 1 in the first session word.
void SetParentParameter(void) {
    data_0217aa00->mUnk_0000 = 1;
    data_0217aa00->mUnk_000c = 5;
    data_0217aa00->mRequestPending = 1;
    if (WM_SetParentParameter(func_02052bb8, data_0217aa00->mParentParameter) != 2) {
        func_020533a0();
    }
}

void func_02052bb8(Unk021425e8 *event) {
    data_0217aa00->mRequestPending = 0;
    if (event->mResultCode != 0) {
        func_020533a0();
    }
}

void StartParent(Unk021425e8Func callback) {
    if (callback == NULL) {
        callback = StartParentCallback;
    }
    data_0217aa00->mUnk_000c = 6;
    data_0217aa00->mRequestPending = 1;
    if (WM_StartParent(callback) != 2) {
        func_020533a0();
    }
}

// Callback of WM_StartParent: code 7 adds a child, 9 removes one, 0 copies the own data into the first member record.
void StartParentCallback(Unk021425e8 *event) {
    RandomState64 *randomState;
    u32 role;
    u16 v;
    u32 aid;

    if (event->mResultCode == 0) {
        switch (event->mUnk_08_0) {
            case 7:
                AddChild(event->mUnk_10, &event->mUnk_0a[0], (Unk0217aa00_45c *) event->mUnk_14);
                break;
            case 0:
                MI_CpuCopy8(&data_0217aa08->mUnk_00->mUnk_0c, &data_0217aa00->mUnk_045c[0], 0x14);
                MI_CpuCopy8(&data_0217aa08->mUnk_00->mUnk_20, &data_0217aa00->mUnk_045c[0].mBits, 4);
                v = 0;
                role = data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000;
                switch (role) {
                    case 1:
                        v = data_0217aa00->mParentParameter->mUnk_0c;
                        break;
                    case 2:
                        v = data_0217aa00->mUnk_0024->mUnk_48;
                        break;
                }
                randomState = &data_0217aa00->mUnk_1ee8;
                randomState->mValue = (u32) (v * 3 | v << 16);
                randomState->mMultiplier = 0x5d588b656c078965ull;
                randomState->mIncrement = 0x269ec3;
                data_0217aa00->mRequestPending = 0;
                break;
            case 9:
                RemoveChild(event->mUnk_10);
                aid = event->mUnk_10;
                role = data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000;
                if (role == 1 && data_0217aa00->mUnk_0004 == 9) {
                    data_0217aa00->mUnk_1eac[0] |= 1 << aid;
                }
                break;
        }
    } else {
        func_020533a0();
    }
}
