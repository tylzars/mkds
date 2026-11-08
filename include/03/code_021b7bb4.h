#pragma once

#include "types.h"

static inline u16 SwapBytes16_inline(u16 value) {
    return ((value >> 8) & 0xff) | ((value << 8) & 0xff00);
}

typedef struct Unk021d6810 {
    /* 00 */ u8 pad_00[0x10];
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
} Unk021d6810;

#include "03/code_021b94b8.h"

typedef struct PacketTag PacketTag;
typedef struct Unk021b86e4 Unk021b86e4;

typedef struct KeyStreamState {
    /* 00 */ u32 mIndex;
    /* 04 */ u32 mSwapIndex;
    /* 08 */ u8 *mTable;
    /* 0c */ u32 mTableCount;
} KeyStreamState;

typedef struct PayloadRecord {
    /* 00 */ u16 mLength;
    /* 02 */ u8 mKeyPrefix[2];
    /* 04 */ u8 mBytes[1];
} PayloadRecord;

typedef struct PacketHeader {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mKind;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mPayloadLength;
    /* 0c */ u16 mFlags;
    /* 0e */ s8 mPayloadCrc;
    /* 0f */ s8 mUnk_0f;
    /* 10 */ u8 mTag[8];
} PacketHeader;

typedef struct OutgoingPacketItem {
    /* 00 */ s8 mType;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mLength;
    /* 04 */ u16 mNextOffset;
    /* 06 */ u8 mValue[1];
} OutgoingPacketItem;

typedef struct ItemContainer {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 pad_01;
    /* 02 */ u16 mLength;
    /* 04 */ u8 mItems[1];
} ItemContainer;

typedef struct PacketFieldValues {
    /* 00 */ s8 mPayloadCrc;
    /* 02 */ s16 mPayloadLength;
    /* 04 */ s16 mFlags;
    /* 06 */ u8 mTag[8];
} PacketFieldValues;

typedef struct PacketItem {
    /* 00 */ u8 mType;
    /* 01 */ u8 pad_01;
    /* 02 */ u16 mLength;
    /* 04 */ u16 mNextOffset;
    /* 06 */ u8 mValue[1];
} PacketItem;

typedef struct SingleValueRecord {
    /* 00 */ u8 pad_00[4];
    /* 04 */ u32 mValueLength;
    /* 08 */ u8 mString[0x28];
    /* 30 */ u8 mValue[0x40];
} SingleValueRecord;

typedef struct FourValueRecord {
    /* 000 */ u8 pad_000[4];
    /* 004 */ u32 mValueLength;
    /* 008 */ u8 mString[0x28];
    /* 030 */ u8 mValue0[0x40];
    /* 070 */ u8 mValue1[0x40];
    /* 0b0 */ u8 mValue2[0x40];
    /* 0f0 */ u8 mValue3[0x40];
} FourValueRecord;

typedef struct ParsedItems {
    /* 000 */ u8 pad_000[8];
    /* 008 */ FourValueRecord mFourValueRecord0;
    /* 138 */ FourValueRecord mFourValueRecord1;
    /* 268 */ SingleValueRecord mSingleValueRecord0;
    /* 2d8 */ SingleValueRecord mSingleValueRecord1;
    /* 348 */ u8 pad_348[8];
} ParsedItems;

typedef struct EssidEntryList EssidEntryList;
typedef struct EssidMelcoRequest EssidMelcoRequest;
typedef struct PacketTag PacketTag;
typedef struct PacketBuffer PacketBuffer;

typedef struct Packet {
    /* 00 */ u8 pad_00[6];
    /* 06 */ u16 mKind;
    /* 08 */ u8 pad_08[2];
    /* 0a */ u16 mPayloadLength;
    /* 0c */ u16 mFlags;
    /* 0e */ u8 mPayloadCrc;
    /* 0f */ u8 mUnk_0f;
    /* 10 */ PacketTag mTag;
    /* 18 */ u8 mPayload[1];
} Packet;

typedef struct ParsedRecordView {
    /* 00 */ u8 pad_00[4];
    /* 04 */ s32 mValueLength;
    /* 08 */ u8 mString[0x28];
    /* 30 */ u8 mValue0[0x40];
    /* 70 */ u8 mValue1[0x40];
    /* b0 */ u8 mValue2[0x40];
    /* f0 */ u8 mValue3[0x40];
} ParsedRecordView;

extern u8 gItemTypesToFind[];
extern s32 gReportedState;
extern Unk021d6810 data_ov003_021d6810;
extern s8 gMelcoString[];
extern u8 gEssidAossString[];
extern s32 gFlagBit4OfKind1010Packet;
extern s32 gRandomSeeded;
extern u32 gRandomState[3];
extern u8 gKeyStreamKeyPrefix[2];
extern u8 gKeyStreamKeyTail[];
extern u8 gItemSlots[];
extern ParsedItems gParsedItems[2];
// The four records below are the parts of gParsedItems[0] at 0x8, 0x138, 0x268 and 0x2d8.
extern ParsedRecordView gParsedFourValueRecord0;
extern ParsedRecordView gParsedFourValueRecord1;
extern ParsedRecordView gParsedSingleValueRecord0;
extern ParsedRecordView gParsedSingleValueRecord1;

u16 NextRandomValue(void);
int GetStringLength(const void *string);
u16 SwapBytes16(u16 value);
u32 func_ov003_021b7c5c(u32 input);
u16 func_ov003_021b7c94(u16 value);
u32 SwapBytes32(u32 input);
s32 func_ov003_021b7ce4(s32 descriptor);
s32 func_ov003_021b7cec(s32 id, Unk021b7cec *addr, u32 length);
s32 func_ov003_021b7cf8(s32 domain, s32 type, s32 protocol);
s32 func_ov003_021b7d00(s32 id, s32 arg1, s32 arg2, void *value, s32 length);
s32 func_ov003_021b7d04(s32 descriptor, void *buffer, s32 length, s32 d, Unk021b7cec *address, u32 addressLength);
s32 func_ov003_021b7d1c(s32 count, Unk021b7ba0 *set, void *arg2, void *arg3, WaitTimeout *arg4);
s32 func_ov003_021b7d68(s32 id, void *buffer, s32 length, s32 flags, Unk021b7cec *out, s32 *outLength);
void FillBytes(void *destination, s32 fillValue, u32 size);
void CopyBytes(void *destination, const void *source, u32 size);
s32 CompareBytes(const u8 *left, const u8 *right, s32 count);
s32 func_ov003_021b7dc8(void);
s32 func_ov003_021b7df4(u32 address, u32 mask, u32 c);
void func_ov003_021b7e58(u32 a, u32 pointer);
u32 func_ov003_021b7e70(u32 a, int size);
void SwapBufferHalves(u8 *buffer, u32 size, u8 *scratch);
void XorSecondHalf(const s8 *key, u8 *buffer, s32 size);
void FillIndexXorKeyBytes(s32 round, s8 *output, s32 size, const s8 *key, s32 keyLength);
s32 XorAndSwapBytesWithKey(u8 *buffer, s32 size, const s8 *key, s32 keyLength);
void InitCrcTable(s32 a, u32 *table);
u32 ComputeCrc(u32 crc, const u8 *bytes, s32 count, s32 tableBuilt, u32 *table);
u8 ComputeCrcLowByte(const u8 *bytes, s32 count);
u32 NextKeyStreamByte(KeyStreamState *state);
void XorWithKeyStream(KeyStreamState *state, u8 *dst, const u8 *src, u32 count);
void InitKeyStream(KeyStreamState *state, const u8 *key, u32 keyLength, u32 count);
s32 XorBytesWithKeyStreamAndCheckCrc(const u8 *src, u8 *dst, s32 length, u32 expectedCrc, const u8 *keyPrefix,
                                     const u8 *keyTail, s32 keyTailLength);
s32 XorBytesWithRandomKeyStreamAndComputeCrc(const u8 *src, u8 *dst, s32 length, s8 *crc, u8 *keyPrefix,
                                             const u8 *keyTail, s32 keyTailLength);
s32 SendPacket(void *packet, s32 length, u32 target, s32 descriptor);
void FillPacketHeader(void *buffer, s32 kind, s32 payloadLength, s32 flags, s8 payloadCrc, s8 f, const u8 *tagBytes);
void FillPayloadRecord(s32 useKeyStream, void *destination, const void *source, s16 *length, s16 *flags, s8 *crc);
s16 BuildTwoItemChain(void *buffer);
s32 SendPacketKind3000(Unk021b86e4 *buf, PacketTag *list, s32 descriptor);
s32 SendPacketKind2000(Unk021b86e4 *buf, PacketTag *list, s32 descriptor);
s32 SendPacketKind1000(Unk021b86e4 *buf, PacketTag *list, s32 descriptor);
s32 ReportStateAndSendPacketForMode(s32 mode, Unk021b86e4 *buf, PacketTag *list, s32 id);
s32 IsBit4Set(u32 value);
s32 FindItemAndParseSubItems(s32 index, PacketItem *item, s32 remaining, ParsedItems *parsedItems, u8 *slots);
s32 CopyFirstItemValueIfType0x70(PacketItem *container, u8 *output);
s32 ParseSingleValueItems(PacketItem *container, SingleValueRecord *record);
s32 ParseFourValueItems(PacketItem *container, FourValueRecord *record);
u32 ReadLittleEndianValue(const u8 *bytes, s32 count);
s32 ParseItemChain(PacketItem *firstItem, u8 *slots);
s32 XorSwapAndCheckTag(PacketTag *expectedTag, PacketTag *incomingTag);
s32 CheckTagAgainstSavedBytesOrKind1000(s32 kind, const u8 *tag);
s32 CheckPacketAndXorPayload(Packet *packet);
s32 AdvanceStepForKind3010(s32 mode, PacketBuffer *buffer, s32 *attempts, PacketTag *list);
s32 AdvanceStepForKind2010(s32 mode, PacketBuffer *buffer, s32 *attempts, PacketTag *list);
s32 AdvanceStepForKind1010(s32 mode, PacketBuffer *buffer, s32 *attempts, PacketTag *list);
s32 AdvanceStepByKind(s32 mode, PacketBuffer *buffer, s32 *attempts, PacketTag *list, s32 descriptor);
s32 ReportStateChange(s32 state);
void FillPacketTags(s32 count, PacketTag *tags, const u8 *tagBytes);
s32 FillEssidAossAndMelcoRequest(EssidMelcoRequest *request);
s32 CheckSingleEssidAossEntry(EssidEntryList *entryList);
s32 CheckBytesInRange0x20To0x7f(const u8 *bytes, s32 count);
s32 CheckAndCopyValueRecordsToRequest(ValueRecordsRequest *request);
s32 GetErrorCode(void);
