#pragma once

#include "types.h"

typedef struct MissionRecord MissionRecord;

// Two bytes: a flag and a value.
typedef struct UnpackedMissionRecord {
    /* 00 */ u8 mFilled;
    /* 01 */ u8 mValue;
} UnpackedMissionRecord;

// Two bytes and a halfword that GetKartFinishTime and GetKartLapTime fill.
typedef struct KartTime {
    /* 00 */ u8 mMinute;
    /* 01 */ u8 mSecond;
    /* 02 */ u16 mMillisecond;
} KartTime;

void ReadCourseGhostRecord(u32 courseId);
void FillAndWriteCourseGhostRecord(s32 courseId, u16 entryIndex);
void SetEmblemRecordAndWriteBackup(void *emblemData);
s32 GetMissionRecord(s32 row, s32 column, UnpackedMissionRecord *unpackedMissionRecord);
void SetMissionRecord(s32 row, s32 column, UnpackedMissionRecord *unpackedMissionRecord);
void UnpackMissionRecord(MissionRecord *missionRecord, UnpackedMissionRecord *unpackedMissionRecord);
void PackMissionRecord(MissionRecord *missionRecord, UnpackedMissionRecord *unpackedMissionRecord);
