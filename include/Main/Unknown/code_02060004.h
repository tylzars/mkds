#pragma once

#include "types.h"

typedef struct Unk0217d384_19f0 Unk0217d384_19f0;

void ClearCourseTimeRecords(s32 courseId);
BOOL func_02060268(s32 courseId);
BOOL GetBuddyFriendKeyText(u8 recordIndex, void *textOut);
s32 RemoveBuddyRecord(u8 recordIndex);
BOOL SetBuddyRecordFlag(u8 recordIndex, s32 flag);
BOOL GetBuddyRecordName(u8 recordIndex, void *nameOut);
BOOL GetBuddyRecordDate(u8 recordIndex, u8 *dateOut);
s32 func_020609c4(u8 recordIndex);
s32 func_020609f8(u8 recordIndex);
s32 func_02060a2c(u8 recordIndex);
s32 func_02060a60(u8 recordIndex);
s32 func_02060a94(u8 recordIndex);
s32 func_02060ac8(u8 recordIndex);
s32 IsBuddyRecordFlagged(u8 recordIndex);
BOOL IsBuddyRecordFilled(u8 recordIndex);
s32 func_02060364(s32 cup, s32 engineClass);
s32 IsGrandPrixRecordFilled(s32 cup, s32 engineClass);
s32 GetGrandPrixRecordCupRank(s32 cup, s32 engineClass);
s32 GetGrandPrixRecordCharacterIndex(s32 cup, s32 engineClass);
s32 GetGrandPrixRecordKartIndex(s32 cup, s32 engineClass);
s32 GetGrandPrixRecordTotalPoints(s32 cup, s32 engineClass);
BOOL GetGrandPrixRecordTime(s32 cup, s32 engineClass, void *timeOut);
BOOL IsTimeRecordFilled(s32 courseId, s32 recordIndex);
s32 GetTimeRecordCharacterIndex(s32 courseId, s32 recordIndex);
s32 GetTimeRecordKartIndex(s32 courseId, s32 recordIndex);
BOOL GetTimeRecordTime(s32 courseId, s32 recordIndex, void *timeRecord);
BOOL GetTimeRecordName(s32 courseId, s32 recordIndex, void *timeRecord);
s32 func_020600b4(s32 courseId);
void MergeBuddyRecords(u8 keptIndex, u8 mergedIndex);
void RefreshNotYetBuddyFlags(void);
void CopyWiFiBuddiesToRecordBlock(Unk0217d384_19f0 *buddies);
