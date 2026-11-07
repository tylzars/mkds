#pragma once

#include "types.h"

typedef struct ExchangeResult ExchangeResult;

typedef struct HashContext HashContext;

// Four hash words, two bit-count words and the 0x40-byte block being filled.
typedef struct HashContext {
    /* 00 */ u32 mHashWords[4];
    /* 10 */ u32 mBitCountLow;
    /* 14 */ u32 mBitCountHigh;
    /* 18 */ u8 mBuffer[0x40];
} HashContext;

// Five, thirteen and sixteen bytes moved as one value.
typedef struct Bytes5 {
    /* 0 */ u8 mBytes[5];
} Bytes5;

typedef struct Bytes13 {
    /* 0 */ u8 mBytes[13];
} Bytes13;

typedef struct Bytes16 {
    /* 0 */ u8 mBytes[16];
} Bytes16;

#include "03/unk_021d8000.h"

// Eight bytes passed by address.
typedef struct SocketAddress {
    /* 0 */ u8 mLength;
    /* 1 */ u8 mUnk_01;
    /* 2 */ u16 mPort;
    /* 4 */ u32 mAddress;
} SocketAddress;

// One 0x30-byte record cut from a RawEntry: name, its length, address and the bit-4 flag.
typedef struct EntrySummary {
    /* 00 */ u32 mSsidLength;
    /* 04 */ char mSsid[0x20];
    /* 24 */ u8 mUnk_24[4];
    /* 28 */ MacAddress mAddress;
    /* 2e */ u16 mBit4Set;
} EntrySummary;

typedef struct EntrySummaryList {
    /* 0 */ u32 mCount;
    /* 4 */ EntrySummary mEntries[1];
} EntrySummaryList;

extern u8 gHashPadding[];

void CallStatusCallback(void);
u32 CopyExchangeResult(ExchangeResult *a);
u32 GetExchangeStatus(u32 *output);
s32 StopExchange(void);
s32 StartExchange(u32 priority, s32 count, UnkFunc *callback, UnkWordFunc *allocFunction, UnkFunc *freeFunction,
                  u32 stackSize);
s32 FormatMacAddress(u8 *output, const s8 *address);
s32 FormatByteAsHex(u8 *output, s8 value);
void CallFreeFunction(void *p0);
void *CallAllocFunctionAndClear(s32 count, s32 size);
u32 GetTickMilliseconds(void);
void ComputeHash(u8 *digest, const u8 *input, u32 size);
void FillBytesWithLoop(void *buffer, s32 value, u32 count);
void CopyBytesWithLoop(void *destination, const void *source, u32 count);
void CopyBytesToWordsLittleEndian(u32 *output, const u8 *input, u32 size);
void CopyWordsToBytesLittleEndian(u8 *output, const u32 *input, u32 size);
void ProcessHashBlock(HashContext *a, const u8 *b);
void FinishHash(u8 *digest, HashContext *context);
void AddBytesToHash(HashContext *context, const u8 *bytes, u32 count);
void ResetHashContext(HashContext *context);
void func_ov003_021bbd9c(u32 *a, int b, u8 *c, u8 *d);
void func_ov003_021bc1c4(u32 *a, int b, u8 *c, u8 *d);
int ExpandKeyReversedWithTables(u32 *a, u8 *b, int c);
int ExpandKey(u32 *a, u8 *b, int c);
void XorEightBytes(u8 *a, u8 *b, u8 *c);
BOOL func_ov003_021bcadc(u8 *param_1, u8 *param_2, u32 param_3, u8 *param_4, int param_5);
BOOL func_ov003_021bccd0(u8 *param_1, u8 *param_2, u32 param_3, u8 *param_4, int param_5);
void RunExchangeThread(void);
int RunExchange(void);
s32 FillExchangeResultFromKind5Data(void);
BOOL ParseHexText(u8 *output, const s8 *text, s32 length);
s32 ParseExchangePacketKind5Items(u8 *body);
s32 StoreMacAddressAndBuildKey(u8 *key, void *b);
unsigned int GetMacAddress(void *address);
s32 BuildExchangePacketKind2(u8 *packet);
s32 ReadExchangePacketPayloadOfKind(const u8 *packet, u32 kind, u8 *output, const void *key);
BOOL ParseAndCheckExchangePacketKind1(const u8 *packet, s32 *item5Flag);
s32 BuildSingleItemBody(u8 *out, u32 type, const void *value, u32 length);
u8 *AppendItem(u8 *out, u32 type, const void *value, u32 length);
s32 BuildExchangePacket(u8 *packet, u32 kind, u8 *body, u32 length, const void *key);
u8 *ReadFirstItem(const u8 *body, u32 *type, s32 *length);
u8 *ReadNextItem(u8 **cursor, u8 *end, u32 *type, s32 *length);
u8 *ReadExchangePacketAndCheckSum(const u8 *packet, u32 *kind, s32 *length);
s32 func_ov003_021bdccc(s32 descriptor, const void *unused, const void *data, u32 size);
s32 SendBytesToAllOnesAddress(s32 descriptor, const void *data, u32 size);
s32 SendBytesToAddress(s32 descriptor, const SocketAddress *address, const u8 *param_2, const void *data, u32 size);
s32 SearchEntriesAndStoreEntryWithNewlyClearedBit4(void);
s32 FindEntryWithNewlyClearedBit4(EntrySummaryList *current, EntrySummaryList *previous, u32 *foundIndex);
void func_ov003_021be1fc(void);
s32 func_ov003_021be264(void);
u32 func_ov003_021be3b8(void);
s32 func_ov003_021be418(u32 param_0);
void EnqueueEvent(u32 value);
void EnqueueEventEx(u32 value, u32 unused);
u32 DequeueEvent(void);
void ClearEventQueue(void);
void CallFreeFunctionWithMutex(u32 a, s32 block, s32 size);
u32 CallAllocFunctionWithMutex(u32 a, s32 size);
u32 func_ov003_021be604(void);
