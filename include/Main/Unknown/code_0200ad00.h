#pragma once

#include "types.h"
#include "code_02142eac.h"

// 0x180-byte entries from 0x600 of WirelessWork.
typedef struct ScanEntry {
    /* 000 */ u8 mUnk_000[0xc0];
    /* 0c0 */ Unk021425e8 mMessage;
    /* 178 */ u8 mUnk_178[8];
} ScanEntry;

// Object behind gWirelessWork (0x1e00 bytes).
typedef struct WirelessWork {
    /* 000 */ u8 mUnk_000[8];
    /* 008 */ u32 mGgid;
    /* 00c */ u16 mTgid;
    /* 00e */ u16 mUnk_00e;
    /* 010 */ u16 mMaxChildren;
    /* 012 */ u16 mUnk_012;
    /* 014 */ u16 mUnk_014;
    /* 016 */ u16 mUnk_016;
    /* 018 */ u16 mBeaconPeriod;
    /* 01a */ u8 mUnk_01a[0x32 - 0x1a];
    /* 032 */ u16 mChannel;
    /* 034 */ u16 mUnk_034;
    /* 036 */ u16 mUnk_036;
    /* 038 */ u8 mUnk_038[8];
    /* 040 */ u8 mSendBuffer[0x400];
    /* 440 */ u8 mScanBuffer[0xc0];
    /* 500 */ u16 mSendDataSize;
    /* 502 */ u16 mReceiveDataSize;
    /* 504 */ void *mReceiveBuffer;
    /* 508 */ Unk021425e8Func mCommandCallback;
    /* 50c */ u8 mDataQueued;
    /* 50d */ u8 mUnk_50d;
    /* 50e */ u8 mUnk_50e[0x518 - 0x50e];
    /* 518 */ u16 mSendBufferSize;
    /* 51a */ u16 mReceiveBufferSize;
    /* 51c */ void (*mCallback)(s32, Unk021425e8 *);
    /* 520 */ u16 *mUnk_520;
    /* 524 */ u16 mMode;
    /* 526 */ u16 mResetting;
    /* 528 */ u16 mMPStarted;
    /* 52a */ u16 mConnectedAids;
    /* 52c */ u16 mUnk_52c;
    /* 52e */ u8 mUnk_52e[2];
    /* 530 */ u16 mUnk_530[4];
    /* 538 */ u16 mUnk_538[16];
    /* 558 */ u8 mUnk_558[0x5e0 - 0x558];
    /* 5e0 */ u16 mScanEntryCount;
    /* 5e2 */ u16 mUnk_5e2;
    /* 5e4 */ u32 mRepeatScan;
    /* 5e8 */ u32 mUnk_5e8;
    /* 5ec */ u32 mLastScanEntry;
    /* 5f0 */ u8 mUnk_5f0[0x10];
    /* 600 */ ScanEntry mScanEntries[16];
} WirelessWork;

// 0x10-byte entries from 0x30 of DataRangeTable.
typedef struct DataRange {
    /* 00 */ u32 mOffset;
    /* 04 */ u32 mSize;
    /* 08 */ u8 *mData;
    /* 0c */ u32 mUnk_0c;
} DataRange;

typedef struct DataRangeTable {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 mUnk_04[0xc];
    /* 10 */ u8 mUnk_10[4];
    /* 14 */ s32 mUnk_14;
    /* 18 */ u8 mUnk_18[0x18];
    /* 30 */ DataRange mUnk_30[4];
} DataRangeTable;

void func_0200ad00(void);
u32 IsMPReadyToSendData(void);
u32 AdvanceScanChannel(Unk02143a78 *scanParams);
u32 CopyFromDataRanges(DataRangeTable *table, u32 offset, void *destination, u32 byteCount);
void AddDataRange(DataRangeTable *table, u32 offset, u32 size, u8 *data, u32 value);
