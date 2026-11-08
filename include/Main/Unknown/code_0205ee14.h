#pragma once

#include "types.h"

typedef struct BuddyRecord BuddyRecord;

typedef struct TimeRecord TimeRecord;

// The word at 0 points to rows of 13 bytes from 6.
typedef struct KartAppearFile {
    /* 00 */ u8 mUnk_00[6];
    /* 06 */ u8 mValues[1][13];
} KartAppearFile;

typedef struct KartAppear {
    /* 00 */ KartAppearFile *mFileData;
} KartAppear;

extern u32 gResultTotalMax;
extern u8 gTimeRecordCharTable[];

u32 GetBuddyRecord(u32 recordIndex, BuddyRecord *buddyRecordOut);
void SetBuddyRecord(u32 recordIndex, BuddyRecord *buddyRecord);
void SetRaceResultRecords(void);
void func_0205ef70(void);
void func_0205f218(void);
void AddBattleBuddyRecordResults(void);
void AddVSBuddyRecordResults(void);
void AddBuddyRecordResult(u32 entryIndex, s32 *date, u32 matchKind, u32 resultKind);
s32 IsBitSetInAnyParticipant(s32 bitIndex);
s32 IsBitSetInAllParticipants(s32 bitIndex);
BOOL func_0205fc98(KartAppear *kartAppear, u32 characterIndex, u32 kartIndex);
BOOL IsKartAppearWithinLimit(KartAppear *kartAppear, u32 characterIndex, u32 kartIndex);
BOOL GetMissionRecordValue(s32 row, s32 column, s32 *out);
BOOL FormatFirstCourseTimeRecord(s32 courseId, void *charsOut);
BOOL FormatTimeRecordChars(u8 *charsOut, TimeRecord *timeRecord, s32 courseId);
