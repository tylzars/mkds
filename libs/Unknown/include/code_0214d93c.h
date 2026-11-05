#pragma once

#include "types.h"

// The one clock request in flight; its lock, callback, output pointers and result. 0x24 bytes.
typedef struct ClockRequest {
    // Nonzero while a request is in flight.
    /* 00 */ vu32 mLocked;
    // Called once with the result and mCallbackArg when the request finishes (cleared first); 0 when there is none.
    /* 04 */ UnkFunc *mCallback;
    // Where ReceiveClockReply writes the decoded words.
    /* 08 */ u32 *mOutput;
    // Second destination of the kind-2 case (time words; the date goes to mOutput); cleared by RTC_Init, nothing sets
    // it.
    /* 0c */ u32 *mSecondOutput;
    // Second argument of mCallback.
    /* 10 */ u32 mCallbackArg;
    // Which request: 0 date, 1 time. The handler also knows 2 and 6 to 10; nothing in this build selects them.
    /* 14 */ u32 mKind;
    // Set just before the handler sends command 0x27, cleared by the next reply; only kinds 9 and 10 set it.
    /* 18 */ u32 mWriteReplyPending;
    // Called without arguments when command 0x30 arrives; nothing in this build sets it.
    /* 1c */ UnkFunc *mEventCallback;
    // Result of the last waiting call (0 read, 1 busy, 3 not sent, 4 to 6 from the reply).
    /* 20 */ u32 mResult;
} ClockRequest;

// The date as the other processor leaves it at 0x027ffde8: year, month, day (decimal-nibble coded) and weekday.
typedef struct ClockDateWord {
    // Year since 2000, 0 to 99.
    /* 00 */ u32 mYear : 8;
    // Month, 1 to 12.
    /* 00 */ u32 mMonth : 5;
    /* 00 */ u32 : 3;
    // Day of the month, 1 to 31.
    /* 00 */ u32 mDay : 6;
    /* 00 */ u32 : 2;
    // Plain 3-bit value, 0 to 6 (DateToDays rejects 7 or more); no game code reads it.
    /* 00 */ u32 mWeekday : 3;
    /* 00 */ u32 : 5;
} ClockDateWord;

// Fixed-address halfword that ReceiveClockReply reads and changes.
typedef struct Unk027ffdea {
    /* 00 */ u16 mUnk_00_0 : 4;
    /* 00 */ u16 : 2;
    /* 00 */ u16 mUnk_00_6 : 1;
    /* 00 */ u16 : 9;
} Unk027ffdea;

// The time as the other processor leaves it at 0x027ffdec: hour, minute, second (decimal-nibble coded).
typedef struct ClockTimeWord {
    // Hour; TimeToSeconds takes hour, minute, second in that order.
    /* 00 */ u32 mHour : 6;
    /* 00 */ u32 : 2;
    // Minute.
    /* 00 */ u32 mMinute : 7;
    /* 00 */ u32 : 1;
    // Second.
    /* 00 */ u32 mSecond : 7;
    /* 00 */ u32 : 9;
} ClockTimeWord;

// The word of ClockTimeWord as ReceiveClockReply reads it for mKind 8.
typedef struct Unk027ffdec_b {
    /* 00 */ u32 mUnk_00_0 : 3;
    /* 00 */ u32 : 4;
    /* 00 */ u32 mUnk_00_7 : 1;
    /* 00 */ u32 mUnk_00_8 : 6;
    /* 00 */ u32 : 1;
    /* 00 */ u32 mUnk_00_15 : 1;
    /* 00 */ u32 mUnk_00_16 : 7;
    /* 00 */ u32 mUnk_00_23 : 1;
    /* 00 */ u32 : 8;
} Unk027ffdec_b;

u32 DecimalNibblesToValue(u32 x);

// Set to 1 by RTC_Init; a second call returns at once.
extern u16 gClockInitialized;
// The one request object.
extern ClockRequest gClockRequest;

// Spins while mLocked of gClockRequest is 1.
void WaitClockRequestDone(void);
// Stores a into mResult of gClockRequest; the callback of the two waiting forms.
void SetClockResult(u32 arg0);
// Receive handler of the clock channel. A transport error finishes the request with 6. Command 0x30 calls
// mEventCallback. Otherwise a zero status byte fills the output words by mKind (0: the date word, 1: the time word,
// each part decimal-nibble decoded except the weekday; the other kinds read more shared words and nothing in this
// build selects them) and a nonzero byte maps 1, 2, 3 and anything else to 4, 5, 1 and 6. Then clears mLocked and calls
// mCallback once with the result and mCallbackArg, unless a write reply is pending.
void ReceiveClockReply(u32 a, u32 b, s32 c);
// RTC_GetTimeAsync, then waits for the reply; returns the result.
u32 RTC_GetTime(u32 *a);
// Starts a read of the time into the three words at a (hour, minute, second) and returns at once; same arguments and
// return values as RTC_GetDateAsync.
u32 RTC_GetTimeAsync(u32 *a, UnkFunc *b, u32 c);
// RTC_GetDateAsync, then waits for the reply; returns the result (0 read, 1 busy, 3 not sent, 4 to 6 from the reply).
u32 RTC_GetDate(u32 *a);
// Starts a read of the date into the four words at a (year since 2000, month, day, weekday) and returns at once; b is
// called with the result and c when the reply is in. Returns 1 when a request is already in flight, 3 when the command
// could not be sent, 0 otherwise.
u32 RTC_GetDateAsync(u32 *a, UnkFunc *b, u32 c);
// Runs once: clears the request object, opens the clock channel (PXI tag 5), waits for the other processor and installs
// ReceiveClockReply as its handler.
void RTC_Init(void);
// Sends command number a on tag 5; returns 1 when the FIFO accepted the word, 0 when not.
s32 TrySendClockCommand(u32 a);
s32 func_0214e1b0(void);
// Sends command 0x12; the reply is decoded as the time word.
s32 TrySendReadTimeCommand(void);
// Sends command 0x11; the reply is decoded as the date word.
s32 TrySendReadDateCommand(void);
