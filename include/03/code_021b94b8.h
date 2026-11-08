#pragma once

#include "03/code_021b7ba0.h"
#include "03/code_021b7ba8.h"

#include "types.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200f790.h"
#include "Main/Unknown/code_0214d000.h"
#include "os_thread.h"
#include "code_0200e77c.h"

typedef struct ValueRecordsRequest {
    /* 000 */ u16 mWantedRecordMask;
    /* 002 */ u8 mItemType;
    /* 003 */ u8 pad_003;
    /* 004 */ u16 mItemLength;
    /* 006 */ u8 mItemBytes[0x100];
    /* 106 */ s16 mScanRetryLimit;
    /* 108 */ s16 mScanRetryDelayMs;
    /* 10a */ s16 mSendAttemptLimit;
    /* 10c */ s16 mSendAttemptDelayMs;
    /* 10e */ s16 mReceiveTimeoutMs;
    /* 110 */ u8 mMacAddress[6];
    /* 116 */ u8 mResultCode;
    /* 117 */ u8 mUnk_117;
} ValueRecordsRequest;

typedef struct RequestState {
    /* 00 */ u8 *mItemBytes;
    /* 04 */ u32 mItemLength;
    /* 08 */ u32 mWantedRecordMask;
    /* 0c */ s32 mFoundRecordMask;
    /* 10 */ u32 mDestinationAddress;
    /* 14 */ u32 mAddressMask;
    /* 18 */ s8 mAddressApplied;
    /* 19 */ s8 mItemType;
    /* 1a */ u8 pad_1a[2];
} RequestState;

typedef struct Unk021ba778Src {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[6];
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u8 mUnk_0c[0x20];
    /* 2c */ u16 mUnk_2c;
    /* 2e */ u16 mUnk_2e;
    /* 30 */ u16 mUnk_30;
    /* 32 */ u16 mUnk_32;
    /* 34 */ u16 mUnk_34;
    /* 36 */ u16 mUnk_36;
    /* 38 */ u8 pad_38[0x88];
} Unk021ba778Src;

typedef struct EssidEntry {
    /* 00 */ u32 mEssidLength;
    /* 04 */ u8 mEssid[0x20];
    /* 24 */ u32 mUnk_24;
    /* 28 */ u8 pad_28[8];
    /* 30 */ u8 mUnk_30[6];
    /* 36 */ u8 pad_36[2];
    /* 38 */ u32 mCodeCount;
    /* 3c */ u8 mCodes[0x10];
    /* 4c */ u32 mUnk_4c;
    /* 50 */ u32 mUnk_50;
} EssidEntry;

typedef struct EssidEntryList {
    /* 00 */ s32 mCount;
    /* 04 */ EssidEntry mEntries[1];
} EssidEntryList;

/* Search request handed to RunEssidMelcoRequest. */
typedef struct EssidMelcoRequest {
    /* 00 */ u32 mEssidLength;
    /* 04 */ u8 mEssid[0x20];
    /* 24 */ BOOL mUnk_24;
    /* 28 */ s32 mMelcoLength;
    /* 2c */ u8 mMelcoBytes[0x10];
} EssidMelcoRequest;

typedef struct MaskCodeEntry {
    u16 mMask;
    u8 mCode;
    u8 pad_3;
} MaskCodeEntry;

typedef struct MelcoBlock {
    /* 00 */ u8 mLengthKind;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mMelcoBytes[0x5e];
} MelcoBlock;

typedef struct RetryLimit {
    /* 0 */ s16 mCount;
    /* 2 */ s16 mDelayMs;
} RetryLimit;

typedef struct WaitTimeout {
    /* 0 */ s32 mSeconds;
    /* 4 */ s32 mUnk_04;
} WaitTimeout;

typedef struct Unk021b7cec {
    /* 0 */ u8 mUnk_00;
    /* 1 */ u8 mUnk_01;
    /* 2 */ u16 mUnk_02;
    /* 4 */ u32 mUnk_04;
} Unk021b7cec;

typedef struct PacketTag {
    /* 0 */ u8 mBytes[6];
    /* 6 */ u16 mSequence;
} PacketTag;

typedef struct Unk021b86e4 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 pad_04[0xc];
    /* 10 */ u32 mUnk_10;
} Unk021b86e4;

typedef struct PacketBuffer {
    /* 00 */ s32 mDescriptor;
    /* 04 */ u32 mReceivedLength;
    /* 08 */ u8 pad_08[4];
    /* 0c */ u8 mBytes[0x5ec];
} PacketBuffer;

extern s32 gSocketDescriptor;
extern RetryLimit data_ov003_021d6808;
extern EssidEntryList *gScannedEssidList;
extern EssidEntryList *gRequestedEssidList;
extern s32 gErrorCode;
extern PacketBuffer *gRequestPacketBuffer;
extern u8 gSavedTagBytes[8];
extern RequestState gRequestState;
extern void *(*data_ov003_021d8a0c)(u32);
extern void (*data_ov003_021d8a10)(s32);
extern void *data_ov003_021d8a14;
extern void (*data_ov003_021d8a18)(void *);
extern void *gMessageQueueSlots[4];
extern OSMessageQueue gMessageQueue;
extern MelcoBlock data_ov003_021d8a4c;
extern Unk021ba778Src data_ov003_021d8ac0;

void SetErrorCode(s32 code);
void InitRequestState(ValueRecordsRequest *req);
void ReleaseEssidEntryLists(void);
u32 GetNextAddressInMask(u32 addr, u32 mask);
s32 func_ov003_021b9570(ValueRecordsRequest *req);
s32 func_ov003_021ba05c(ValueRecordsRequest *req);
void func_ov003_021ba164(void *ptr);
void *func_ov003_021ba178(u32 size);
s32 func_ov003_021ba18c(s32 state);
void func_ov003_021ba1a8(u32 ms);
s32 RunEssidMelcoRequest(EssidMelcoRequest *request, EssidEntryList *out);
s32 ScanEssidEntries(EssidEntryList **out);
s32 func_ov003_021ba524(void);
s32 func_ov003_021ba560(void);
s32 func_ov003_021ba61c(void *(*alloc)(u32), void (*release)(void *));
s32 func_ov003_021ba70c(void *msg);
s32 func_ov003_021ba720(void *msg);
void FillEssidEntryListFromRecord(EssidEntryList *list, Unk021ba778Src *src, s32 count);
void SetRecordEssidFromRequest(EssidMelcoRequest *request, Unk021ba778Src *rec);
void ConvertRecordToEssidEntry(Unk021ba778Src *src, EssidEntry *dst);

#include "03/code_021b7000.h"
#include "03/unk_021d8000.h"
#include "Main/Unknown/code_02133000.h"
#include "03/code_021b7bb4.h"
#include "03/code_021ba818.h"
