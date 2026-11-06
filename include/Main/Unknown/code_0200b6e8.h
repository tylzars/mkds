#pragma once

#include "types.h"
#include "Main/Unknown/code_02008934.h"

// Block the callback behind mScanCallback receives from CallScanCallbackWithEntry.
typedef struct ScanEntryArgs {
    /* 00 */ u16 mEntryIndex;
    /* 04 */ Unk02008934 *mEntry;
    /* 08 */ u8 *mScanBuffer;
    /* 0c */ u32 mUnk_0c;
} ScanEntryArgs;

// Block the callback behind mScanCallback receives from ReportScanError.
typedef struct ScanErrorArgs {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
} ScanErrorArgs;

#include "code_02142eac.h"

typedef struct ScanConnectWork {
    /* 0000 */ u8 mUnk_0000[0x20];
    /* 0020 */ u8 mReceiveBuffer[0x480];
    /* 04a0 */ u8 mMessageBuffer[0x20];
    /* 04c0 */ u8 mScanBuffer[0xc0];
    /* 0580 */ Unk02143a78 mScanParams;
    /* 0590 */ u8 mUnk_0590[0x10];
    /* 05a0 */ u8 mMPLink[0x24];
    /* 05c4 */ u8 mUnk_05c4[0x18];
    /* 05dc */ void (*mScanCallback)(u32, void *);
    /* 05e0 */ void (*mStateCallback)(u32, void *);
    /* 05e4 */ u32 mUnk_05e4;
    /* 05e8 */ u8 mUnk_05e8[0x5ee - 0x5e8];
    /* 05ee */ u16 mUnk_05ee;
    /* 05f0 */ u8 mUnk_05f0[0x5ef8 - 0x5f0];
    /* 5ef8 */ u32 mRepeatScan;
    /* 5efc */ u32 mEndScanRequested;
    /* 5f00 */ u32 mUseScanBssid;
    /* 5f04 */ u32 mEndRequested;
    /* 5f08 */ u32 mUnk_5f08;
    /* 5f0c */ u16 mUnk_5f0c;
    /* 5f0e */ u16 mState;
} ScanConnectWork;

typedef struct MPLink {
    /* 00 */ UnkFunc *mCallback;
    /* 04 */ void *mSendBuffer;
    /* 08 */ u8 *mReceiveBuffer;
    /* 0c */ u8 mUnk_0c[4];
    /* 10 */ u16 mSendBufferSize;
    /* 12 */ u16 mReceiveBufferSize;
    /* 14 */ u16 mUnk_14;
    /* 16 */ u16 mUnk_16;
    /* 18 */ u16 mUnk_18;
    /* 1a */ u16 mMPStarted;
    /* 1c */ u16 mResetting;
    /* 1e */ u16 mUnk_1e;
    /* 20 */ u16 mDataQueued;
} MPLink;

// Two halfwords that are passed on to the function at mUnk_00 of an MPLink.
typedef struct CommandResult {
    /* 00 */ u16 mCommand;
    /* 02 */ u16 mResultCode;
} CommandResult;

extern u8 gDefaultScanBssid[6];

// Declared here until the code that defines it is decompiled.
void ScanConnectEndScan(void);
void RequestEndScan(void);
u32 PickScanChannel(void);
void EntryCallback(u32 a, void *entry, u32 entryIndex);
u32 ClearUseScanBssid(void);
void SetScanBssid(const u8 *a);
void ReportScanError(u16 a, u16 b);
void CallScanCallbackWithEntry(u32 a, Unk02008934 *entry, u32 entryIndex);
void ScanConnectStartScanCallback(Unk021425e8 *a);
void ScanConnectStartScan(void);
void StartRepeatedScan(UnkFunc *callback, u32 b);
void SetScanConnectStateAndNotify(u32 state, void *b);
void SetScanConnectStateCallback(UnkFunc *callback);
unsigned int GetScanConnectWorkSize(void);
void FinishScanConnect(void);
void CloseScanConnect(void);
void InitScanConnectWork(ScanConnectWork *a, void *b);
void ClearPortCallback(void);
void QueueMPDataCallback(Unk021425e8 *a);
s32 QueueMPDataIfReady(u32 a, u16 b, u8 *c);
void PortCallback(Unk021425e8 *a);
u32 IsMPReadyToQueueData(void);
void StartResetCallback(Unk021425e8 *a);
void StartReset(void);
void StartResetWithFlagCallback(Unk021425e8 *a);
void StartResetWithFlag(void);
void ScanConnectStartMPCallback(Unk021425e8 *a);
void SetPortCallbackAndStartMP(void *sendBuffer, u8 *receiveBuffer);
void ScanConnectStartConnectCallback(Unk021425e8 *a);
void ScanConnectStartConnect(u8 *scanBuffer);
void SetMPLinkCallback(unsigned int callback);
u32 SetupMPLink(u32 arg0);
