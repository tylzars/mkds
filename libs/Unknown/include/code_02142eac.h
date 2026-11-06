#pragma once

#include "types.h"

typedef struct Unk021450ec Unk021450ec;

typedef struct Unk021425e8 Unk021425e8;
typedef void (*Unk021425e8Func)(Unk021425e8 *);

// System work area set up by WmInitCore. The callback tables are indexed by the command number of the message that
// WmReceiveFifo takes.
typedef struct Unk02142aa8 {
    /* 000 */ void *mWM7;
    /* 004 */ struct Unk02142988 *mStatusArea;
    /* 008 */ u32 mUnk_008;
    // Command request area; the command functions fill it in and WMi_SendCommand copies it for a command with no words.
    /* 00c */ u16 *mRequestArea;
    // Message area for replies; WmReceiveFifo does not mark it free after handling.
    /* 010 */ Unk021425e8 *mMessageArea;
    /* 014 */ u16 mDmaNo;
    /* 016 */ u16 mScanOnlyFlag;
    /* 018 */ Unk021425e8Func mCommandCallbacks[0x2a];
    /* 0c0 */ Unk021425e8Func mIndicationCallback;
    /* 0c4 */ UnkFunc *mPortCallbacks[16];
    /* 104 */ void *mPortCallbackArgs[16];
} Unk02142aa8;

// Wireless status area written by the other processor; WM_ReadStatus copies 0x7bc bytes of it.
typedef struct Unk02142988 {
    /* 000 */ u16 mState;
    /* 002 */ u8 mUnk_002[2];
    /* 004 */ void *mUnk_004;
    /* 008 */ u8 mUnk_008[4];
    /* 00c */ u32 mMpFlag;
    /* 010 */ u32 mDcfFlag;
    /* 014 */ u8 mUnk_014[0x32];
    /* 046 */ u16 mMpRecvBufSize;
    /* 048 */ u8 mUnk_048[8];
    /* 050 */ void *mMpSendBuf;
    /* 054 */ u8 mUnk_054[0x32];
    /* 086 */ u16 mMpReadyBitmap;
    /* 088 */ u8 mUnk_088[0x30];
    /* 0b8 */ u16 mLinkLevel;
    /* 0ba */ u8 mUnk_0ba[8];
    /* 0c2 */ u16 mPwrMgtMode;
    /* 0c4 */ u8 mUnk_0c4[0x30];
    /* 0f4 */ u16 mUnk_0f4;
    /* 0f6 */ u8 mUnk_0f6[0x88];
    // Bit n is set while child n is connected.
    /* 17e */ u16 mConnectedChildren;
    /* 180 */ u8 mUnk_180[4];
    // This station's number: 0 for the parent.
    /* 184 */ u16 mOwnMemberIndex;
    /* 186 */ u8 mUnk_186[8];
    /* 18e */ u16 mMpMaxSendSize;
    /* 190 */ u16 mMpMaxRecvSize;
    /* 192 */ u8 mUnk_192[0x62a];
} Unk02142988;

// Message the other processor passes to WmReceiveFifo and to the callbacks.
struct Unk021425e8 {
    // Command number; 0x80, 0x81 and 0x82 are indications and port messages. Bit 15 marks a ring message as free.
    /* 00 */ u16 mCommand;
    // 0 on success, otherwise an error number.
    /* 02 */ u16 mResultCode;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ union {
        struct {
            void *mUnk_08;
            void *mUnk_0c;
        };
        struct {
            u16 mUnk_08_0;
            u16 mUnk_08_2;
        };
        struct {
            u8 mUnk_08_b[2];
            u8 mUnk_0a[6];
        };
    };
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
    /* 14 */ u8 mUnk_14[6];
    /* 1a */ u16 mUnk_1a;
    /* 1c */ void *mUnk_1c;
    /* 20 */ u16 mUnk_20;
    /* 22 */ u8 mUnk_22[2];
    /* 24 */ u8 mUnk_24[0x12];
    /* 36 */ u16 mUnk_36;
    /* 38 */ struct {
        u32 mUnk_00[0x20];
    } mUnk_38;
};

// Result of WM_GetOtherElements: mUnk_00 counts the filled entries of mUnk_04.
typedef struct Unk02142f24 {
    /* 00 */ u8 mUnk_00;
    /* 04 */ struct {
        /* 00 */ u8 mUnk_00;
        /* 01 */ u8 mUnk_01;
        /* 04 */ const u8 *mUnk_04;
    } mUnk_04[16];
} Unk02142f24;

// Header of the MP receive buffer: mUnk_04 is the number of records, mUnk_06 the size of each, and the records start at
// mUnk_0a.
typedef struct Unk021432ac {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u8 mUnk_08[2];
    /* 0a */ u8 mUnk_0a[1];
} Unk021432ac;

// Request WM_StartConnectEx writes into the request area.
typedef struct Unk021437d8 {
    /* 00 */ u16 mApiid;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ u16 *mPInfo;
    /* 08 */ u8 mSsid[0x18];
    /* 20 */ u32 mPowerSave;
    /* 24 */ u8 mUnk_24[2];
    /* 26 */ u16 mAuthMode;
} Unk021437d8;

// Scan parameters of WM_StartScanEx.
typedef struct Unk021438f0 {
    /* 00 */ void *mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u8 mUnk_0a[6];
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
    /* 14 */ u8 mUnk_14[0x20];
    /* 34 */ u16 mUnk_34;
} Unk021438f0;

// Request WM_StartScanEx writes into the request area.
typedef struct Unk021438f0_0c {
    /* 00 */ u16 mApiid;
    /* 02 */ u16 mChannelList;
    /* 04 */ void *mScanBuf;
    /* 08 */ u16 mScanBufSize;
    /* 0a */ u16 mMaxChannelTime;
    /* 0c */ u8 mBssid[6];
    /* 12 */ u16 mScanType;
    /* 14 */ u16 mSsidLength;
    /* 16 */ u8 mSsid[0x20];
    /* 36 */ u16 mSsidMatchLength;
} Unk021438f0_0c;

// Scan parameters of WM_StartScan.
typedef struct Unk02143a78 {
    /* 00 */ void *mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u8 mUnk_08[6];
} Unk02143a78;

// Request WM_StartScan writes into the request area.
typedef struct Unk02143a78_0c {
    /* 00 */ u16 mApiid;
    /* 02 */ u16 mChannel;
    /* 04 */ void *mScanBuf;
    /* 08 */ u16 mMaxChannelTime;
    /* 0a */ u8 mBssid[6];
} Unk02143a78_0c;

// Parent parameters of WM_SetParentParameter.
typedef struct Unk02143c30 {
    /* 00 */ struct Unk0217aa00_24_50 *mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[6];
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u8 mUnk_12[2];
    /* 14 */ u16 mUnk_14;
    /* 16 */ u8 mUnk_16[2];
    /* 18 */ u16 mUnk_18;
    /* 1a */ u8 mUnk_1a[0x18];
    /* 32 */ u16 mUnk_32;
    /* 34 */ u16 mUnk_34;
    /* 36 */ u16 mUnk_36;
} Unk02143c30;

s32 WM_StartDCF(Unk021425e8Func callback, void *recvBuf, u16 recvBufSize);
s32 WM_SetDCFData(Unk021425e8Func callback, const void *destAdr, void *sendData, u16 sendDataSize);
s32 WM_EndDCF(Unk021425e8Func callback);
s32 WM_StartMPEx(Unk021425e8Func callback, u32 recvBuf, u16 recvBufSize, u32 sendBuf, u16 sendBufSize, u16 mpFreq,
                 u16 defaultRetryCount, BOOL minPollBmpMode, BOOL singlePacketMode, BOOL fixFreqMode,
                 BOOL ignoreFatalError);
s32 WM_SetMPFrequency(Unk021425e8Func callback, u32 mpFreq);
s32 WM_SetMPDataToPortEx(UnkFunc *callback, void *arg, void *sendData, s32 sendDataSize, u16 destBitmap, u16 port,
                         u16 prio);
s32 WM_EndMP(Unk021425e8Func callback);
s32 WM_Enable(Unk021425e8Func callback);
s32 WM_Disable(Unk021425e8Func callback);
s32 WM_PowerOn(Unk021425e8Func callback);
s32 WM_PowerOff(Unk021425e8Func callback);
s32 WM_Initialize(void *wmSysBuf, Unk021425e8Func callback, u16 dmaNo);
s32 WM_Reset(Unk021425e8Func callback);
s32 WM_End(Unk021425e8Func callback);
s32 WM_SetParentParameter(Unk021425e8Func callback, Unk02143c30 *pparaBuf);
u32 WmCheckParentParameter(const Unk02143c30 *param);
s32 WMi_StartParentEx(Unk021425e8Func callback, BOOL powerSave);
s32 WM_StartParent(Unk021425e8Func callback);
s32 WM_EndParent(Unk021425e8Func callback);
s32 WM_StartScan(Unk021425e8Func callback, Unk02143a78 *param);
s32 WM_StartScanEx(Unk021425e8Func callback, Unk021438f0 *param);
s32 WM_EndScan(Unk021425e8Func callback);
s32 WM_StartConnectEx(Unk021425e8Func callback, u16 *pInfo, void *ssid, BOOL powerSave, u16 authMode);
s32 WM_Disconnect(Unk021425e8Func callback, u32 aid);
s32 WM_DisconnectChildren(Unk021425e8Func callback, u32 aidBitmap);
s32 WM_SetIndCallback(Unk021425e8Func callback);
s32 WM_SetPortCallback(u16 port, UnkFunc *callback, void *arg);
s32 WM_ReadStatus(void *statusBuf);
s32 WM_GetMPSendBufferSize(void);
s32 WM_GetMPReceiveBufferSize(void);
void *WM_ReadMPData(const Unk021432ac *header, u16 aid);
u16 WM_GetAllowedChannel(void);
u16 WM_GetLinkLevel(void);
u16 WM_GetDispersionBeaconPeriod(void);
u16 WM_GetDispersionScanPeriod(void);
Unk02142f24 WM_GetOtherElements(const u16 *bssDesc);
u16 WM_GetNextTgid(void);
