#pragma once

#include "types.h"

typedef struct Unk0217d384_19f0 Unk0217d384_19f0;

void ClearCourseTimeRecords(s32 a);
s32 func_02060268(s32 a);
s32 GetBuddyFriendKeyText(u8 a, void *b);
s32 RemoveBuddyRecord(u8 a);
BOOL SetBuddyRecordFlag(u8 a, s32 b);
BOOL GetBuddyRecordName(u8 a, void *b);
BOOL GetBuddyRecordDate(u8 a, u8 *b);
s32 func_020609c4(u8 a);
s32 func_020609f8(u8 a);
s32 func_02060a2c(u8 a);
s32 func_02060a60(u8 a);
s32 func_02060a94(u8 a);
s32 func_02060ac8(u8 a);
s32 IsBuddyRecordFlagged(u8 a);
BOOL IsBuddyRecordFilled(u8 a);
s32 func_02060364(s32 a, s32 b);
s32 IsGrandPrixRecordFilled(s32 a, s32 b);
s32 GetGrandPrixRecordCupRank(s32 a, s32 b);
s32 GetGrandPrixRecordCharacterIndex(s32 a, s32 b);
s32 GetGrandPrixRecordKartIndex(s32 a, s32 b);
s32 func_02060390(s32 a, s32 b);
BOOL GetGrandPrixRecordTime(s32 a, s32 b, void *c);
BOOL IsTimeRecordFilled(s32 a, s32 b);
s32 GetTimeRecordCharacterIndex(s32 a, s32 b);
s32 GetTimeRecordKartIndex(s32 a, s32 b);
BOOL GetTimeRecordTime(s32 a, s32 b, void *c);
BOOL GetTimeRecordName(s32 a, s32 b, void *c);
s32 func_020600b4(s32 a);
void MergeBuddyRecords(u8 a, u8 b);
void RefreshNotYetBuddyFlags(void);
void CopyWiFiBuddiesToRecordBlock(Unk0217d384_19f0 *a);
