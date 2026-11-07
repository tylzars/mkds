#pragma once

#include "types.h"

// One data set: the stations still expected and the stations whose data has arrived, then the data of every station.
typedef struct WMDataSet {
    // Stations whose data is still expected while the set fills; the stations of the share once it is finished.
    /* 00 */ u16 mAidBitmap;
    // Bit n is set when the data of station n has arrived in this set.
    /* 02 */ u16 mArrivedMembers;
    /* 04 */ u8 mData[0x1fc];
} WMDataSet;

// Work area of one data sharing, 0x820 bytes: four data sets, then the sequence numbers and the state.
typedef struct WMDataSharingInfo {
    /* 000 */ WMDataSet mDs[4];
    /* 800 */ u16 mSeqNum[4];
    /* 808 */ u16 mWriteIndex;
    /* 80a */ u16 mSendIndex;
    /* 80c */ u16 mReadIndex;
    // Stations taking part, bit n for station n; 0 when no sharing is running.
    /* 80e */ u16 mMemberMask;
    // Bytes of data per station.
    /* 810 */ u16 mMemberDataSize;
    /* 812 */ u16 mStationNumber;
    /* 814 */ u16 mDataSetLength;
    // Port the sharing uses.
    /* 816 */ u16 mPort;
    /* 818 */ u16 mDoubleMode;
    /* 81a */ u16 mCurrentSeqNum;
    // 0 not running, 1 running, 4 send must be retried, 5 error.
    /* 81c */ u16 mStatus;
    /* 81e */ u16 mReserved;
} WMDataSharingInfo;

// Message passed to the data sharing callbacks. The first two members are the same as in Unk021425e8.
typedef struct Unk02144920 {
    /* 00 */ u16 mCommand;
    /* 02 */ u16 mResultCode;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 *mUnk_0c;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
    /* 14 */ u8 mUnk_14[6];
    /* 1a */ u16 mUnk_1a;
    /* 1c */ WMDataSharingInfo *mUnk_1c;
    /* 20 */ WMDataSharingInfo *mUnk_20;
} Unk02144920;

u8 *WmGetSharedDataAddress(WMDataSharingInfo *dsInfo, u32 aidBitmap, u8 *receiveBuf, u32 aid);
u8 *WM_GetSharedDataAddress(WMDataSharingInfo *dsInfo, WMDataSet *receiveData, u32 aid);
void WmDataSharingSendDataSet(WMDataSharingInfo *dsInfo, u32 delayed);
void WmDataSharingReceiveData(WMDataSharingInfo *dsInfo, u32 aid, const void *data);
void WmDataSharingReceiveCallback_Child(Unk02144920 *callback);
void WmDataSharingReceiveCallback_Parent(Unk02144920 *callback);
void WmDataSharingSetDataCallback(Unk02144920 *callback);
int WM_StepDataSharing(WMDataSharingInfo *dsInfo, void *sendData, WMDataSet *receiveData);
int WM_EndDataSharing(WMDataSharingInfo *dsInfo);
int WM_StartDataSharing(WMDataSharingInfo *dsInfo, u16 port, u16 aidBitmap, u16 dataLength, BOOL doubleMode);
int WM_EndKeySharing(WMDataSharingInfo *buf);
int WM_StartKeySharing(WMDataSharingInfo *buf, u16 port);
