#pragma once

#include "types.h"

typedef struct EmblemRecord EmblemRecord;

typedef struct GrandPrixRecordBlock GrandPrixRecordBlock;

typedef struct MissionRecordBlock MissionRecordBlock;

typedef struct CourseTimeRecordBlock CourseTimeRecordBlock;

void ReadBackupMissionRecordBlock(void *block);
void WriteBackupMissionRecordBlock(MissionRecordBlock *block);
void ReadBackupCourseTimeRecordBlock(void *block);
void WriteBackupCourseTimeRecordBlock(CourseTimeRecordBlock *block);
void ReadBackupGrandPrixRecordBlock(void *block);
void WriteBackupGrandPrixRecordBlock(GrandPrixRecordBlock *block);
void ReadBackupEmblemRecord(void *block);
void WriteBackupEmblemRecord(EmblemRecord *block);
void func_02057c60(void *block);
