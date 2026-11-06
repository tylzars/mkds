#include "code_021445e0.h"
#include "code_0200eddc.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0201ec30.h"
#include "code_0214259c.h"
#include "code_02142eac.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214cfe4.h"
#include "code_0202056c.h"
#include "code_0214d018.h"

// Starts key sharing on port: data sharing of 2 bytes per station for all stations in double mode.
int WM_StartKeySharing(Unk021450ec *buf, u16 port) {
    return WM_StartDataSharing(buf, port, 0xffff, 2, 1);
}

// Ends key sharing.
int WM_EndKeySharing(Unk021450ec *buf) {
    return WM_EndDataSharing(buf);
}

// Starts sharing dataLength bytes per station on port between the stations in aidBitmap, using dsInfo as the work area.
// The parent sends the first data sets itself; a child waits for them.
int WM_StartDataSharing(Unk021450ec *dsInfo, u16 port, u16 aidBitmap, u16 dataLength, BOOL doubleMode) {
    u32 readyMembers;
    u32 ownIndex;
    Unk02142988 *status;
    int result;
    int i;
    u16 mask;
    u32 count;
    Unk0214461c *block;

    readyMembers = 1;
    status = WMi_GetSystemWork()->mStatusArea;
    result = WMi_CheckStateEx(2, 9, 10);
    if (result != 0) {
        return result;
    }
    DC_InvalidateRange(&status->mMpFlag, 4);
    if (status->mMpFlag == 0) {
        return 3;
    }
    if (dsInfo == 0) {
        return 6;
    }
    if (port >= 16) {
        return 6;
    }
    if (aidBitmap == 0) {
        return 6;
    }
    DC_InvalidateRange(&status->mOwnMemberIndex, 2);
    ownIndex = status->mOwnMemberIndex;
    if (ownIndex == 0) {
        DC_InvalidateRange(&status->mMpReadyBitmap, 2);
        readyMembers = status->mMpReadyBitmap;
    }
    MemFillWordsByBlock_inline(dsInfo, 0x820);
    dsInfo->mWriteIndex = 0;
    dsInfo->mSendIndex = 0;
    dsInfo->mReadIndex = 0;
    dsInfo->mMemberDataSize = dataLength;
    dsInfo->mPort = port;
    dsInfo->mMemberMask = 0;
    dsInfo->mDoubleMode = doubleMode != 0;
    mask = aidBitmap | (1 << ownIndex);
    dsInfo->mMemberMask = mask;
    count = CountSetBits(mask);
    dsInfo->mStationNumber = count;
    dsInfo->mDataSetLength = dataLength * count;
    if (dsInfo->mDataSetLength > 0x1fc) {
        dsInfo->mMemberMask = 0;
        return 6;
    }
    dsInfo->mDataSetLength += 4;
    dsInfo->mStatus = 1;
    if (ownIndex == 0) {
        for (i = 0; i < 4; i++) {
            dsInfo->mDs[i].mAidBitmap = dsInfo->mMemberMask & (readyMembers | 1);
        }
        WM_SetPortCallback(port, (UnkFunc *) WmDataSharingReceiveCallback_Parent, dsInfo);
        block = dsInfo->mDs;
        for (i = 0; i < (dsInfo->mDoubleMode == 1 ? 2 : 1); block++, i++) {
            dsInfo->mWriteIndex = (dsInfo->mWriteIndex + 1) & 3;
            result = WM_SetMPDataToPortEx((UnkFunc *) WmDataSharingSetDataCallback, dsInfo, block,
                                          dsInfo->mDataSetLength, dsInfo->mMemberMask & readyMembers, dsInfo->mPort, 1);
            if (result == 7) {
                dsInfo->mSeqNum[i] = 0xffff;
                dsInfo->mSendIndex = (dsInfo->mSendIndex + 1) & 3;
            } else if (result != 0 && result != 2) {
                dsInfo->mStatus = 5;
                return 1;
            }
        }
    } else {
        dsInfo->mSendIndex = 3;
        WM_SetPortCallback(port, (UnkFunc *) WmDataSharingReceiveCallback_Child, dsInfo);
    }
    return 0;
}

// Ends data sharing and removes the port callback; returns 3 when dsInfo is not running data sharing.
int WM_EndDataSharing(Unk021450ec *dsInfo) {
    Unk02142aa8 *work;
    UnkFunc *registered;
    int result;

    work = WMi_GetSystemWork();
    result = WMi_CheckStateEx(2, 9, 10);
    if (result != 0) {
        return result;
    }
    if (dsInfo == 0) {
        return 6;
    }
    if (dsInfo->mMemberMask == 0 ||
        ((registered = work->mPortCallbacks[dsInfo->mPort]) != (UnkFunc *) WmDataSharingReceiveCallback_Parent &&
         registered != (UnkFunc *) WmDataSharingReceiveCallback_Child)) {
        return 3;
    }
    WM_SetPortCallback(dsInfo->mPort, 0, 0);
    dsInfo->mMemberMask = 0;
    dsInfo->mStatus = 0;
    return 0;
}

// Takes the next complete data set of all stations into receiveData and sends sendData for the next round. Returns 0
// when a data set was delivered, 5 when there is none yet and 1 after a send failure.
int WM_StepDataSharing(Unk021450ec *dsInfo, void *sendData, Unk0214461c *receiveData) {
    int late;
    int result;
    Unk02142988 *status;
    u32 readyMembers;
    u32 mode;
    int delivered;
    u32 ownIndex;
    int sendOwn;
    int sendResult;
    u16 previous;
    u8 *outgoing;

    status = WMi_GetSystemWork()->mStatusArea;
    result = WMi_CheckStateEx(2, 9, 10);
    if (result != 0) {
        return result;
    }
    DC_InvalidateRange(&status->mMpFlag, 4);
    if (status->mMpFlag == 0) {
        return 3;
    }
    if (dsInfo == 0) {
        return 6;
    }
    if (sendData == 0) {
        return 6;
    }
    if (receiveData == 0) {
        return 6;
    }
    DC_InvalidateRange(&status->mOwnMemberIndex, 2);
    ownIndex = status->mOwnMemberIndex;
    if (ownIndex == 0) {
        DC_InvalidateRange(&status->mMpReadyBitmap, 2);
        readyMembers = status->mMpReadyBitmap;
    }
    mode = dsInfo->mStatus;
    if (mode == 5) {
        return 1;
    }
    if (mode != 1) {
        if (mode != 4) {
            return 3;
        }
    }
    result = 5;
    if (ownIndex == 0) {
        delivered = 0;
        late = 0;
        if (mode == 4) {
            dsInfo->mStatus = 1;
            previous = (dsInfo->mWriteIndex + 3) & 3;
            sendResult =
                WM_SetMPDataToPortEx((UnkFunc *) WmDataSharingSetDataCallback, dsInfo, &dsInfo->mDs[previous],
                                     dsInfo->mDataSetLength, dsInfo->mMemberMask & readyMembers, dsInfo->mPort, 1);
            if (sendResult == 7) {
                dsInfo->mSeqNum[previous] = 0xffff;
                dsInfo->mSendIndex = (dsInfo->mSendIndex + 1) & 3;
            } else if (sendResult != 0) {
                if (sendResult != 2) {
                    dsInfo->mStatus = result;
                    return 1;
                }
            }
        }
        if (dsInfo->mReadIndex != dsInfo->mSendIndex) {
            dsInfo->mDs[dsInfo->mReadIndex].mAidBitmap |= 1;
            MIi_CpuCopy16(&dsInfo->mDs[dsInfo->mReadIndex], receiveData, 0x200);
            dsInfo->mCurrentSeqNum = dsInfo->mSeqNum[dsInfo->mReadIndex];
            dsInfo->mReadIndex = (dsInfo->mReadIndex + 1) & 3;
            delivered = 1;
            result = 0;
            if (dsInfo->mDoubleMode == 0 && readyMembers != 0 && dsInfo->mDs[dsInfo->mWriteIndex].mAidBitmap == 1) {
                late = delivered;
            } else {
                late = 0;
            }
        }
        WmDataSharingSendDataSet(dsInfo, 0);
        if (delivered != 0) {
            WmDataSharingReceiveData(dsInfo, 0, sendData);
            if (dsInfo->mDoubleMode == 0) {
                WmDataSharingSendDataSet(dsInfo, late);
            }
        }
    } else {
        sendOwn = 0;
        if (mode == 4) {
            dsInfo->mStatus = 1;
            sendOwn = 1;
        } else if (dsInfo->mReadIndex != dsInfo->mWriteIndex) {
            if ((dsInfo->mDs[dsInfo->mReadIndex].mAidBitmap & 1) == 0) {
                dsInfo->mDs[dsInfo->mReadIndex].mAidBitmap |= 1;
            } else {
                MIi_CpuCopy16(&dsInfo->mDs[dsInfo->mReadIndex], receiveData, 0x200);
                dsInfo->mCurrentSeqNum = dsInfo->mSeqNum[dsInfo->mReadIndex];
                dsInfo->mReadIndex = (dsInfo->mReadIndex + 1) & 3;
                sendOwn = 1;
                result = 0;
            }
        }
        if (sendOwn != 0) {
            outgoing = &dsInfo->mDs[dsInfo->mSendIndex].mData[0x1c];
            MIi_CpuCopy16(sendData, outgoing, dsInfo->mMemberDataSize);
            sendResult = WM_SetMPDataToPortEx((UnkFunc *) WmDataSharingSetDataCallback, dsInfo, outgoing,
                                              dsInfo->mMemberDataSize, dsInfo->mMemberMask, dsInfo->mPort, 1);
            dsInfo->mSendIndex = (dsInfo->mSendIndex + 1) & 3;
            if (sendResult != 2) {
                if (sendResult != 0) {
                    dsInfo->mStatus = 5;
                    result = 1;
                }
            }
        }
    }
    return result;
}

// Send result callback of the data sharing sends: records the sequence number on success and the retry or error state
// otherwise.
void WmDataSharingSetDataCallback(Unk02144920 *callback) {
    Unk02142aa8 *work;
    Unk02142988 *status;
    Unk021450ec *share;
    UnkFunc *registered;
    u32 code;
    u32 ownIndex;

    work = WMi_GetSystemWork();
    status = work->mStatusArea;
    registered = work->mPortCallbacks[callback->mUnk_0a];
    share = work->mPortCallbackArgs[callback->mUnk_0a];
    if (registered != (UnkFunc *) WmDataSharingReceiveCallback_Parent &&
        registered != (UnkFunc *) WmDataSharingReceiveCallback_Child) {
        return;
    }
    if (share == 0) {
        return;
    }
    if (share != callback->mUnk_20) {
        return;
    }
    DC_InvalidateRange(&status->mOwnMemberIndex, 2);
    code = callback->mResultCode;
    ownIndex = status->mOwnMemberIndex;
    if (code == 0) {
        if (ownIndex != 0) {
            return;
        }
        share->mSeqNum[share->mSendIndex] = callback->mUnk_1a >> 1;
        share->mSendIndex = (share->mSendIndex + 1) & 3;
        return;
    }
    if (code == 10) {
        if (ownIndex != 0) {
            share->mSendIndex = (share->mSendIndex + 3) & 3;
        }
        share->mStatus = 4;
        return;
    }
    share->mStatus = 5;
}

// Port callback of a parent: sends the next data set when the previous send finished (7), a child's data arrived (0x15)
// or a child dropped out (9).
void WmDataSharingReceiveCallback_Parent(Unk02144920 *callback) {
    Unk021450ec *share;
    u32 enabled;
    enum { K0 } bit;
    u32 member;
    u32 current;
    u32 mask;
    u16 next;

    share = callback->mUnk_1c;
    if (share == 0) {
        return;
    }
    if (callback->mResultCode == 0) {
        switch (callback->mUnk_04) {
            case 0x15:
                WmDataSharingReceiveData(share, callback->mUnk_12, callback->mUnk_0c);
                WmDataSharingSendDataSet(share, 0);
                return;
            case 7:
                WmDataSharingSendDataSet(share, 0);
                return;
            case 9:
                member = callback->mUnk_12;
                bit = 1;
                enabled = OS_DisableInterrupts();
                current = share->mWriteIndex;
                mask = ~(bit << member);
                share->mDs[current].mAidBitmap &= mask;
                if (share->mDoubleMode == 1) {
                    next = (current + 1) & 3;
                    share->mDs[next].mAidBitmap &= mask;
                }
                OS_RestoreInterrupts(enabled);
                WmDataSharingSendDataSet(share, 0);
                if (share->mDoubleMode == 1) {
                    WmDataSharingSendDataSet(share, 0);
                }
                return;
        }
    } else {
        share->mStatus = 5;
    }
}

// Port callback of a child: stores the data set the parent sent (0x15) as the next one to read.
void WmDataSharingReceiveCallback_Child(Unk02144920 *callback) {
    Unk02142988 *status;
    Unk021450ec *share;
    u32 size;
    u32 blockMask;
    u32 ownIndex;
    u16 *data;

    status = WMi_GetSystemWork()->mStatusArea;
    share = callback->mUnk_1c;
    if (share == 0) {
        return;
    }
    if (callback->mResultCode == 0) {
        if (callback->mUnk_04 == 7) {
            return;
        }
        if (callback->mUnk_04 == 9) {
            return;
        }
        if (callback->mUnk_04 != 0x15) {
            return;
        }
        data = callback->mUnk_0c;
        blockMask = *data;
        size = callback->mUnk_10;
        DC_InvalidateRange(&status->mOwnMemberIndex, 2);
        ownIndex = status->mOwnMemberIndex;
        if (size != share->mDataSetLength) {
            if (size > 0x200) {
                size = 0x200;
            }
        }
        if (size < 4) {
            return;
        }
        if ((blockMask & (1 << ownIndex)) == 0) {
            return;
        }
        MIi_CpuCopy16(data, &share->mDs[share->mWriteIndex], size);
        share->mSeqNum[share->mWriteIndex] = callback->mUnk_1a >> 1;
        share->mWriteIndex = (share->mWriteIndex + 1) & 3;
    } else {
        share->mStatus = 5;
    }
}

// Stores the data of station aid (zero when data is NULL) in the current data set and marks the station as arrived.
void WmDataSharingReceiveData(Unk021450ec *dsInfo, u32 aid, const void *data) {
    u32 mask;
    u16 block;
    u32 enabled;
    u8 *target;
    volatile u16 zero;

    mask = (u16) (1 << aid);
    if ((dsInfo->mMemberMask & mask) == 0) {
        return;
    }
    block = dsInfo->mWriteIndex;
    if ((mask & dsInfo->mDs[block].mAidBitmap) == 0) {
        if (dsInfo->mDoubleMode != 1) {
            return;
        }
        block = (block + 1) & 3;
        if ((mask & dsInfo->mDs[block].mAidBitmap) == 0) {
            return;
        }
    }
    target = WmGetSharedDataAddress(dsInfo, dsInfo->mMemberMask, dsInfo->mDs[block].mData, aid);
    if (data != 0) {
        MIi_CpuCopy16(data, target, dsInfo->mMemberDataSize);
    } else {
        zero = 0;
        MIi_CpuClear16(zero, target, dsInfo->mMemberDataSize);
    }
    enabled = OS_DisableInterrupts();
    dsInfo->mDs[block].mAidBitmap &= ~mask;
    dsInfo->mDs[block].mArrivedMembers |= mask;
    OS_RestoreInterrupts(enabled);
}

// When the current data set is complete, makes the next one current and sends the finished one to the other stations.
void WmDataSharingSendDataSet(Unk021450ec *dsInfo, u32 delayed) {
    u32 enabled;
    u16 done;
    u32 ready;
    Unk02142988 *status;
    u16 next;
    u16 ahead;
    int result;
    volatile u16 zero;

    status = WMi_GetSystemWork()->mStatusArea;
    enabled = OS_DisableInterrupts();
    if (dsInfo->mDs[dsInfo->mWriteIndex].mAidBitmap == 0) {
        DC_InvalidateRange(&status->mMpReadyBitmap, 2);
        done = dsInfo->mWriteIndex;
        ready = status->mMpReadyBitmap;
        next = (done + 1) & 3;
        if (dsInfo->mDoubleMode == 1) {
            ahead = (next + 1) & 3;
        } else {
            ahead = next;
        }
        zero = 0;
        MIi_CpuClear16(zero, &dsInfo->mDs[ahead], 0x200);
        dsInfo->mDs[ahead].mAidBitmap = dsInfo->mMemberMask & (ready | 1);
        dsInfo->mWriteIndex = next;
        dsInfo->mDs[done].mAidBitmap = dsInfo->mMemberMask;
        if (delayed == 1) {
            dsInfo->mDs[done].mAidBitmap &= ~1;
        }
        OS_RestoreInterrupts(enabled);
        result = WM_SetMPDataToPortEx((UnkFunc *) WmDataSharingSetDataCallback, dsInfo, &dsInfo->mDs[done],
                                      dsInfo->mDataSetLength, dsInfo->mMemberMask & ready, dsInfo->mPort, 1);
        if (result == 7) {
            dsInfo->mSeqNum[done] = 0xffff;
            dsInfo->mSendIndex = (dsInfo->mSendIndex + 1) & 3;
        } else if (result != 0) {
            if (result != 2) {
                dsInfo->mStatus = 5;
            }
        }
    } else {
        OS_RestoreInterrupts(enabled);
    }
}

// Returns the data of station aid in receiveData, or NULL when the station has no data in it.
u8 *WM_GetSharedDataAddress(Unk021450ec *dsInfo, Unk0214461c *receiveData, u32 aid) {
    u32 mask;
    u32 held;
    u32 arrived;

    arrived = receiveData->mArrivedMembers;
    mask = 1 << aid;
    held = receiveData->mAidBitmap;
    if (dsInfo == 0) {
        return 0;
    }
    if (receiveData == 0) {
        return 0;
    }
    if ((held & mask) == 0) {
        return 0;
    }
    if ((arrived & mask) == 0) {
        return 0;
    }
    return WmGetSharedDataAddress(dsInfo, held, receiveData->mData, aid);
}

// Returns the data of station aid in receiveBuf: the data of the stations in aidBitmap that come before it are skipped.
u8 *WmGetSharedDataAddress(Unk021450ec *dsInfo, u32 aidBitmap, u8 *receiveBuf, u32 aid) {
    return receiveBuf + dsInfo->mMemberDataSize * CountSetBits(aidBitmap & ((1 << aid) - 1));
}
