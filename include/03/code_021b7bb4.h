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

typedef struct Unk021b916c Unk021b916c;
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

typedef struct Unk021ba734 Unk021ba734;
typedef struct Unk021ba1b0 Unk021ba1b0;
typedef struct Unk021b916c Unk021b916c;
typedef struct Unk021d7c54 Unk021d7c54;

typedef struct Packet {
    /* 00 */ u8 pad_00[6];
    /* 06 */ u16 mKind;
    /* 08 */ u8 pad_08[2];
    /* 0a */ u16 mPayloadLength;
    /* 0c */ u16 mFlags;
    /* 0e */ u8 mPayloadCrc;
    /* 0f */ u8 mUnk_0f;
    /* 10 */ Unk021b916c mTag;
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
int GetStringLength(const void *a);
u16 SwapBytes16(u16 value);
u32 func_ov003_021b7c5c(u32 arg0);
u16 func_ov003_021b7c94(u16 value);
u32 SwapBytes32(u32 arg0);
s32 func_ov003_021b7ce4(s32 descriptor);
s32 func_ov003_021b7cec(s32 id, Unk021b7cec *addr, u32 length);
s32 func_ov003_021b7cf8(s32 domain, s32 type, s32 protocol);
s32 func_ov003_021b7d00(s32 id, s32 arg1, s32 arg2, void *value, s32 length);
s32 func_ov003_021b7d04(s32 a, void *b, s32 c, s32 d, Unk021b7cec *e, u32 f);
s32 func_ov003_021b7d1c(s32 count, Unk021b7ba0 *set, void *arg2, void *arg3, Unk021b7d1c *arg4);
s32 func_ov003_021b7d68(s32 id, void *buffer, s32 length, s32 flags, Unk021b7cec *out, s32 *outLength);
void FillBytes(void *arg0, s32 arg1, u32 arg2);
void CopyBytes(void *arg0, const void *arg1, u32 arg2);
s32 CompareBytes(const u8 *left, const u8 *right, s32 count);
s32 func_ov003_021b7dc8(void);
s32 func_ov003_021b7df4(u32 a, u32 b, u32 c);
void func_ov003_021b7e58(u32 a, u32 b);
u32 func_ov003_021b7e70(u32 a, int b);
void SwapBufferHalves(u8 *a, u32 b, u8 *c);
void XorSecondHalf(const s8 *key, u8 *buffer, s32 size);
void FillIndexXorKeyBytes(s32 a, s8 *b, s32 c, const s8 *d, s32 e);
s32 XorAndSwapBytesWithKey(u8 *a, s32 b, const s8 *c, s32 d);
void InitCrcTable(s32 a, u32 *b);
u32 ComputeCrc(u32 a, const u8 *b, s32 c, s32 d, u32 *e);
u8 ComputeCrcLowByte(const u8 *p0, s32 p1);
u32 NextKeyStreamByte(KeyStreamState *p);
void XorWithKeyStream(KeyStreamState *p, u8 *dst, const u8 *src, u32 n);
void InitKeyStream(KeyStreamState *p, const u8 *key, u32 keyLength, u32 n);
s32 XorBytesWithKeyStreamAndCheckCrc(const u8 *a, u8 *b, s32 c, u32 d, const u8 *e, const u8 *f, s32 g);
s32 XorBytesWithRandomKeyStreamAndComputeCrc(const u8 *a, u8 *b, s32 c, s8 *d, u8 *e, const u8 *f, s32 g);
s32 SendPacket(void *a, s32 b, u32 c, s32 d);
void FillPacketHeader(void *p, s32 b, s32 c, s32 d, s8 e, s8 f, const u8 *g);
void FillPayloadRecord(s32 a, void *b, const void *c, s16 *d, s16 *e, s8 *f);
s16 BuildTwoItemChain(void *a);
s32 SendPacketKind3000(Unk021b86e4 *a, Unk021b916c *b, s32 c);
s32 SendPacketKind2000(Unk021b86e4 *a, Unk021b916c *b, s32 c);
s32 SendPacketKind1000(Unk021b86e4 *a, Unk021b916c *b, s32 c);
s32 ReportStateAndSendPacketForMode(s32 mode, Unk021b86e4 *buf, Unk021b916c *list, s32 id);
s32 IsBit4Set(u32 value);
s32 FindItemAndParseSubItems(s32 a, PacketItem *b, s32 c, ParsedItems *d, u8 *e);
s32 CopyFirstItemValueIfType0x70(PacketItem *a, u8 *b);
s32 ParseSingleValueItems(PacketItem *a, SingleValueRecord *b);
s32 ParseFourValueItems(PacketItem *a, FourValueRecord *b);
u32 ReadLittleEndianValue(const u8 *bytes, s32 count);
s32 ParseItemChain(PacketItem *a, u8 *b);
s32 XorSwapAndCheckTag(Unk021b916c *a, Unk021b916c *b);
s32 CheckTagAgainstSavedBytesOrKind1000(s32 a, const u8 *b);
s32 CheckPacketAndXorPayload(Packet *a);
s32 AdvanceStepForKind3010(s32 mode, Unk021d7c54 *buffer, s32 *attempts, Unk021b916c *list);
s32 AdvanceStepForKind2010(s32 mode, Unk021d7c54 *buffer, s32 *attempts, Unk021b916c *list);
s32 AdvanceStepForKind1010(s32 mode, Unk021d7c54 *buffer, s32 *attempts, Unk021b916c *list);
s32 AdvanceStepByKind(s32 a, Unk021d7c54 *b, s32 *c, Unk021b916c *d, s32 e);
s32 ReportStateChange(s32 a);
void FillPacketTags(s32 a, Unk021b916c *b, const u8 *c);
s32 FillEssidAossAndMelcoRequest(Unk021ba1b0 *a);
s32 CheckSingleEssidAossEntry(Unk021ba734 *a);
s32 CheckBytesInRange0x20To0x7f(const u8 *bytes, s32 count);
s32 CheckAndCopyValueRecordsToRequest(Unk021b94c4 *a);
s32 func_ov003_021b94ac(void);
