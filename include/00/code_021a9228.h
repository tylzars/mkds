#pragma once

#include "types.h"

typedef struct HttpsState HttpsState;

struct Unk021a998c;
typedef s32 (*Unk021a998cFunc)(void *param_1, u32 param_2, struct Unk021a998c *param_3);

// Record the https functions take; its mHttpsState is the https layer's own state.
typedef struct Unk021a998c {
    /* 00 */ struct OSThread *mThread;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u8 mState;
    /* 09 */ u8 mUseHttps;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ HttpsState *mHttpsState;
    /* 10 */ u32 mStateStartTime;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u16 mUnk_18;
    /* 1a */ u16 mUnk_1a;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
    /* 28 */ u32 mUnk_28;
    /* 2c */ u16 mUnk_2c;
    /* 2e */ u16 mUnk_2e;
    /* 30 */ u32 mUnk_30;
    /* 34 */ u32 mUnk_34;
    /* 38 */ Unk021a998cFunc mReceiveCallback;
    /* 3c */ u32 mReceiveBufferSize;
    /* 40 */ u8 *mReceiveBuffer;
    /* 44 */ u32 mReceiveBufferLength;
    /* 48 */ u32 mSendBufferSize;
    /* 4c */ u8 *mSendBuffer;
    /* 50 */ u8 mUnk_50[0xc];
    /* 5c */ u8 *mUnk_5c;
    /* 60 */ u32 mUnk_60;
} Unk021a998c;

#include "00/unk_021b4000.h"
#include "Main/Unknown/unk_0216f000.h"

typedef struct Unk021a998c Unk021a998c;

typedef struct HttpsState HttpsState;

typedef struct HttpsState HttpsState;

typedef struct HttpsState HttpsState;

typedef struct HttpsState HttpsState;

typedef struct HttpsState HttpsState;

typedef struct HttpsState HttpsState;

typedef struct HttpsState HttpsState;

// Six length and pointer pairs.
typedef struct Unk021aa880 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ const u8 *mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ const u8 *mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ const u8 *mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ const u8 *mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ const u8 *mUnk_24;
    /* 28 */ u32 mUnk_28;
    /* 2c */ const u8 *mUnk_2c;
} Unk021aa880;

typedef struct HttpsState HttpsState;

typedef struct Unk021aaf38 Unk021aaf38;
typedef struct HttpsState HttpsState;

typedef struct HttpsState HttpsState;

typedef struct HttpsEntry HttpsEntry;

#include "00/code_021ad734.h"
#include "00/unk_021b6380.h"
#include "00/code_021ac3e4.h"

// Set to 1 once bytes have been mixed into gRandomByteState.
extern u8 gRandomByteStateMixed;
// Counts the entries made while sending the kind 2 record; its value is written as the last four bytes of each new
// entry's first 0x20 bytes.
extern u32 gKind2NewEntryCount;
extern u8 gRandomByteState[0x14];
extern u8 gRandomByteStateLast;

void func_ov000_021a9228(Unk021a998c *a);
s32 SendHttpsBytesInChunks(u8 *a, u32 b, u8 *c, u32 d, Unk021a998c *e);
s32 ReadHttpsRecordIfBufferedAndGetUnreadByteCount(Unk021a998c *a);
void SkipHttpsReceivedBytes(u32 count, Unk021a998c *b);
u8 *ReadHttpsRecordsUntilBytesReceived(s32 *unreadCount, Unk021a998c *b);
BOOL func_ov000_021a943c(Unk021a998c *a);
BOOL RunSetupAfterSendingKind1Record(Unk021a998c *a);
void RunSetupAfterReadingKind1RecordUntilDone(Unk021a998c *a);
BOOL RunSetupAfterReadingKind1Record(Unk021a998c *a);
u32 ReadRecordsExpectingStates7And6(Unk021a998c *a);
void func_ov000_021a9640(Unk021a998c *a);
void SendKind1Record(Unk021a998c *a);
void SendOneByteRecordAndMessageDigests(Unk021a998c *a);
u8 SendKind2Record(Unk021a998c *a);
void MixBytesIntoRandomState(void *bytes, u32 n);
void FillNonzeroRandomBytes(u8 *out, s32 count);
u8 ReadHttpsRecordAndSetState(Unk021a998c *a);
u32 ReadExactReceivedBytes(u8 *dest, s32 count, Unk021a998c *c);
s32 AppendDigestAndXorSentRecordWithKeyStream(void *g, u8 *h);
s32 XorReceivedRecordWithKeyStreamAndCheckDigest(HttpsState *a, u8 *b);
unsigned int XorReceivedBytesWithKeyStream(unsigned int p0, u8 *bytes, unsigned int count);
void IncrementBigEndianBytes(u8 *bytes, s32 count);
void CheckMessageDigestsAndSetState(HttpsState *a, u8 *b);
void ComputeLabeledMessageDigest20(HttpsState *a, u8 *b, u32 c);
void ComputeLabeledMessageDigest16(HttpsState *a, u8 *b, u32 c);
void func_ov000_021aa5b0(HttpsState *a, const u8 *b);
void DeriveBytesAndInitKeyStreamStates(HttpsState *a);
void ReplaceEntryBytesWithLabeledDigests(HttpsState *a);
void ComputeLabeledDigest16(u8 *a, const u8 *b, HttpsState *c);
void func_ov000_021aa880(u8 *a, const u8 *b, Unk021aa880 *c);
void ParseKind1Message(HttpsState *a, const u8 *b);
void ParseKind1MessageWithThreeByteValues(HttpsState *a, u8 *b);
u32 IsFirstArgumentThree(int a, int b);
u32 FindOfferedValueInList(const u8 *list, s32 count, s32 width);
BOOL IsBigEndianValueInList(const u8 *list, s32 count, s32 width, u32 value);
void ParseKind2Message(HttpsState *a, u8 *b);
void ParseAndCheckItemListMessage(HttpsState *a, u8 *b);
BOOL CompareTextWithWildcard(const s8 *text, const s8 *pattern);
s32 GetTextLengthUpToDot(const s8 *text);
u32 ComputeParsedItemCheckFlags(HttpsState *a);
u32 CheckTransformedBytesHoldPaddedDigest(HttpsState *a, Unk021aaf38 *b);
BOOL ParseTaggedItem(HttpsState *a, u8 **b, s32 depth, s32 index, s32 mode);
u32 ParseDateText(const u8 *digits, u32 tag);
void AppendCommaSeparatedText(s8 *dest, const s8 *source, s32 count);
s32 ReadLengthAndAdvance(u8 **a);
u32 FindAuthorityByName(HttpsState *a, const s8 *b);
void SetAuthorityTable(u32 table, u32 count);
u32 GetRtcSecondsPlusFixedOffset(void);
HttpsEntry *AddEntryOrReplaceLongestUnused(const u8 *a);
HttpsEntry *FindEntryByValuePairAndSetLastUseTime(u32 a, u32 b);
HttpsEntry *FindEntryByBytesAndSetLastUseTime(const u8 *a);
// Declared here until the code that defines them is decompiled.
