#pragma once

#include "types.h"
#include "00/code_021ab6d4.h"
#include "00/code_021abca0.h"

typedef struct HttpsEntry HttpsEntry;
typedef struct Unk021aa880 Unk021aa880;

// A name and two byte strings: the rows of the table behind mAuthorities, and the copy an item fills (mItemRecord).
typedef struct AuthorityRecord {
    /* 00 */ u32 mName;
    /* 04 */ s32 mFirstLength;
    /* 08 */ u8 *mFirstBytes;
    /* 0c */ u32 mSecondLength;
    /* 10 */ u8 *mSecondBytes;
} AuthorityRecord;

// Length and pointer of the item list a reply sends (mItemList).
typedef struct ItemList {
    /* 0 */ u32 mLength;
    /* 4 */ u8 *mBytes;
} ItemList;

struct HttpsState;
typedef u32 (*Unk021a998c_Func)(u32 a, struct HttpsState *b, s32 c);

// State of the https layer of one Http thread (0x804 bytes), reached through mHttpsState; Http118 is the same object.
typedef struct HttpsState {
    // The entry in use, or NULL; may be data_ov000_021b6198, which is not in the table.
    /* 000 */ HttpsEntry *mEntry;
    /* 004 */ u8 mReusedEntry;
    /* 005 */ u8 mUnk_005;
    /* 006 */ u16 mCommonValue;
    /* 008 */ u8 mKind1Block[0x20];
    /* 028 */ u8 mKind2Block[0x20];
    /* 048 */ u8 mDerivedBytes[0x48];
    /* 090 */ u8 *mSendDigestBytes;
    /* 094 */ u8 *mSendKeyStreamBytes;
    /* 098 */ u8 *mUnk_098;
    /* 09c */ u8 mSendKeyStreamState[0x104];
    /* 1a0 */ u8 mSendRecordCount[8];
    /* 1a8 */ u8 *mReceiveDigestBytes;
    /* 1ac */ u8 *mReceiveKeyStreamBytes;
    /* 1b0 */ u8 *mUnk_1b0;
    /* 1b4 */ u8 mReceiveKeyStreamState[0x104];
    /* 2b8 */ u8 mReceiveRecordCount[8];
    /* 2c0 */ Hash20Context mMessageHash20;
    /* 31c */ Hash20Context mScratchHash20;
    /* 378 */ Unk021ab728 mMessageHash16;
    /* 3d0 */ Unk021ab728 mScratchHash16;
    // 1 on the side that receives the kind 1 message, 0 on the side that sends it.
    /* 428 */ u8 mReceivesKind1Record;
    // 0 at the start, 8 when the setup is complete, 9 after a failure; the record handlers set the values between.
    /* 429 */ u8 mSetupState;
    /* 42c */ s32 mDigestKind;
    // Table position (1 or 2) stored by ParseTaggedItem for the first item of a list; -1 when none was stored, which
    // makes the flags carry 4.
    /* 430 */ s32 mUnk_430;
    /* 434 */ u8 *mDigestStart;
    /* 438 */ u8 *mDigestEnd;
    /* 43c */ u8 mRangeDigest[0x14];
    /* 450 */ s32 mRangeDigestLength;
    /* 454 */ AuthorityRecord mItemRecord;
    /* 468 */ u8 mFirstValue[0x100];
    /* 568 */ u32 mFirstValueLength;
    /* 56c */ u8 mSecondValue[8];
    /* 574 */ u32 mSecondValueLength;
    /* 578 */ u8 *mCheckedBytes;
    /* 57c */ s32 mCheckedBytesLength;
    /* 580 */ u8 mDatesSeen;
    /* 581 */ u8 mCaptureValues;
    /* 582 */ u8 mCopyNextText;
    /* 583 */ u8 mDateInRange;
    /* 584 */ s8 mAuthorityName[0x100];
    // Text items seen after the dates, joined with ', '; written, never read.
    /* 684 */ s8 mUnk_684[0x100];
    /* 784 */ s8 mHostPattern[0x50];
    /* 7d4 */ s8 *mHost;
    /* 7d8 */ u8 *mItemBytes;
    /* 7dc */ s32 mItemLength;
    /* 7e0 */ u32 mCurrentDate;
    /* 7e4 */ Unk021a998c_Func mCheckFlagsCallback;
    // Pointer to the table of authority records.
    /* 7e8 */ u32 mAuthorities;
    /* 7ec */ u32 mAuthorityCount;
    /* 7f0 */ Unk021aa880 *mUnk_7f0;
    /* 7f4 */ ItemList *mItemList;
    /* 7f8 */ u8 *mReceivedBlock;
    /* 7fc */ u32 mReceivedBlockEnd;
    /* 800 */ u32 mReceivedBlockOffset;
} HttpsState;
