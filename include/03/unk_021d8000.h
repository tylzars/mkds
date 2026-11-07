#pragma once

#include "types.h"
#include "code_0200db4c.h"
#include "03/unk_021d6000.h"
#include "00/code_021a574c.h"
#include "00/code_021a5b3c.h"
#include "00/code_02188de4.h"

// Six bytes moved as one value.
typedef struct MacAddress {
    /* 0 */ u8 mBytes[6];
} MacAddress;

// Eight bytes moved as one value.
typedef struct Bytes8 {
    /* 0 */ u8 mBytes[8];
} Bytes8;

// 0x40 bytes moved as one value.
typedef struct Words16 {
    /* 0 */ u32 mWords[16];
} Words16;

// 0xe8 bytes.
typedef struct ExchangeResult {
    /* 00 */ char mText[0x20];
    /* 20 */ s32 mKind;
    /* 24 */ s32 mUnk_24;
    /* 28 */ u8 mValueBytes[4][0x20];
    /* a8 */ Words16 mItem20aWords;
} ExchangeResult;

// 0x60 bytes.
typedef struct Kind5Record {
    /* 00 */ char mText[0x2c];
    /* 2c */ u32 mItem202Value;
    /* 30 */ s32 mItem205Value;
    /* 34 */ u8 mUnk_34[0x28];
    /* 5c */ s32 mStoreValuesAsHex;
} Kind5Record;

// 0x48 bytes.
typedef struct Kind5Item20a {
    /* 00 */ Words16 mBytes;
    /* 40 */ u32 mUnk_40[2];
} Kind5Item20a;

// Entry of the list at gRawEntries, 0xc0 bytes.
typedef struct RawEntry {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ MacAddress mAddress;
    /* 0a */ u16 mSsidLength;
    /* 0c */ u8 mSsid[0x20];
    /* 2c */ u16 mFlags;
    /* 2e */ u8 mUnk_2e[0x92];
} RawEntry;

// Objects whose layout isn't known yet.
extern UnkWordFunc *gAllocFunction;
extern UnkFunc *gFreeFunction;
extern s32 gStopRequested;
extern u32 data_ov003_021d8bfc;
extern void *gThreadStack;
extern s32 gThreadStarted;
extern s32 data_ov003_021d8c44;
extern OSThread gExchangeThread;
extern s32 gExchangeStatus;
extern s32 gExchangeResultCode;
extern UnkFunc *gStatusCallback;
extern OSMutex gAllocMutex;
extern ExchangeResult gExchangeResult;
extern u8 gReceivedTextNonEmpty;
extern u32 gPacketLength;
extern u32 gSelectedEntryIndex;
extern u32 gExchangeState;
extern u32 data_ov003_021d8bf0;
extern u32 data_ov003_021d8bf4;
extern u32 gBodyLength;
extern u32 gKind1Item5Flag;
extern RawEntry *gRawEntries;
extern s32 gEntryCountMax;
extern MacAddress gMacAddress;
extern MacAddress gSelectedEntryAddress;
extern u8 gFirstKey[0x10];
extern Bytes8 gSecondKeyReceivedPart;
extern char gSelectedEntryName[];
extern u8 gSecondKeyHashedPart[];
extern u32 gKind5Words[0x95];
extern Kind5Record gKind5Record;
extern u8 gKind5Values[];
extern Kind5Item20a gKind5Item20a;
extern u8 gBodyBuffer[];
extern u8 gPacketBuffer[0x800];

extern Unk02188de4 *data_ov003_021d8bf8;
extern Unk021a5a78 *data_ov003_021d8bd8;
extern void *data_ov003_021d8c0c;
extern u8 *data_ov003_021d8c14;
extern u8 *data_ov003_021d8c18;
extern Unk021a5e84 *data_ov003_021d8c1c;
extern u32 data_ov003_021d8c28;
extern u32 data_ov003_021d8c30;
extern UnkFunc *data_ov003_021d8c50;
extern u8 data_ov003_021d8c64[6];
extern u8 data_ov003_021d8cc4[0x20];
extern void *gAlignedBuffer;
extern void *gAllocatedBuffer;
extern s32 gEventWriteIndex;
extern s32 gEventReadIndex;
extern u32 gEvents[4];

#include "03/code_021b94b8.h"
