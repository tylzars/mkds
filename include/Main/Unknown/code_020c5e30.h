#pragma once

#include "types.h"
#include "Main/Unknown/code_02056b30.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

// Time-attack record handling of the race (mode 1 only), one record behind gRaceNewRecordTa (0xe8 bytes, allocated by
// InitRaceNewRecordTa, set NULL by ClearRaceNewRecordTaPointer): mUnk_00 is the function it runs every frame
// (UpdateRaceNewRecordTa), which compares the finished run with the course's saved records, inserts and saves a new one
// (SetCourseTimeRecord) and slides in and draws the new-record page (DrawRaceNewRecordTa).
typedef struct RaceNewRecordTa {
    /* 00 */ void (*mUpdate)(void);
    /* 04 */ s32 mUpdateFrames;
    /* 08 */ s32 mFinishTimeIsRecord;
    /* 0c */ s32 mFinishRecordIndex;
    /* 10 */ s32 mBestLapIsRecord;
    /* 14 */ u16 mBestLapNumber;
    /* 16 */ u8 mUnk_16[2];
    /* 18 */ s32 mUnk_18;
    // The course's six time records, copied from the save by InitRaceNewRecordTa (GetCourseTimeRecord): slots 0..4 are
    // the ranked list (an insert shifts them down and writes through SetCourseTimeRecord), slot 5 is a further record
    // shown in a sixth row: the best lap time.
    /* 1c */ TimeRecord mRecords[6];
    /* dc */ s32 mUnk_dc;
    // X of the whole page: -0x100 at allocation, eased to 0 over 0x14 frames by SlideInRaceNewRecordTa, added to every
    // sprite and row x in the draw.
    /* e0 */ s32 mOffsetX;
    /* e4 */ s32 mCycleFrames;
} RaceNewRecordTa;

s32 func_020c70bc(void);
s32 func_020c70a0(void);
void InitRaceNewRecordTa(void);
void ClearRaceNewRecordTaPointer(void);
void UpdateRaceNewRecordTa(void);
void DrawRaceNewRecordTaTime(RaceHudOamBuffer *oamBuffer, s32 x, s32 y, TimeRecord *record);
void DrawRaceNewRecordTaRow(RaceHudOamBuffer *oamBuffer, s32 b, s32 x, s32 y);
void DrawRaceNewRecordTa(RaceHudOamBuffer *oamBuffer);
BOOL func_020c657c(s32 store);
BOOL func_020c6428(s32 store);
void func_020c610c(void);
void func_020c5f7c(void);
void func_020c5f08(void);
void ShowRaceNewRecordTaSubScreen(void);
void SlideInRaceNewRecordTa(void);
