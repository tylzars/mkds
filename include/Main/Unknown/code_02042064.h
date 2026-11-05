#pragma once

#include "types.h"

// Header of the file returned by FindCourseFile in CreateCourseMap: a word array at 0x08 holds offsets from 0x06's
// value. The halfword at 4 is the format version (copied to CourseMap.mVersion).
typedef struct CourseMapHeader {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mVersion;
    /* 06 */ u16 mBaseOffset;
    /* 08 */ s32 mSectionOffsets[1];
} CourseMapHeader;

extern s32 (*gCourseMapSectionLoaders[17])(void *a, ...);

#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"

void CreateCourseMap(void *a);

typedef struct Unk020f41c4_B Unk020f41c4_B;

typedef struct CourseMapRoute CourseMapRoute;
typedef struct Unk02175620_a0 Unk02175620_a0;
typedef struct Unk020f371c Unk020f371c;

s32 func_02042170(void *a, ...);
s32 func_02042280(void *a, ...);
void CountCourseMapKind2ShapesInMode4(void);
void CountCourseMapKind4Shapes(void);
void BuildCourseMapKind3ShapeLists(void);
CourseMapShape *GetCourseMapShape(u32 a);
s32 func_02042410(void *a, ...);
s32 func_02042498(void *a, ...);
s32 func_02042520(void *a, ...);
s32 func_02042558(void *a, ...);
s32 LoadCourseMapCheckpointRoutesData(void *a, ...);
s32 LoadCourseMapCheckpointsData(void *a, ...);
s32 func_020426ac(void *a, ...);
s32 func_02042708(void *a, ...);
void func_0204274c(void);
s32 func_020427ac(void *a, ...);
void ShuffleCourseMapRespawnSlots(Unk020f41c4_B *a);
s32 LoadCourseMapRespawnsData(void *a, ...);
s32 LoadCourseMapStartPlacementsData(void *a, ...);
u32 LoadCourseMapSettingsData(u32 arg0);
void func_020429c8(void *a);
void func_02042a10(void *a);
void func_02042c3c(void *a);
void func_02042d34(Unk02175620_a0 *a, CourseMapRoute *b, u16 c);
void func_02042e0c(void *a);
void func_02042ec0(Unk020f371c *a, CourseMapRoute *b, u16 c);
unsigned int func_02042fc4(unsigned int p0);
void func_02042fd8(void *a);
void func_02043038(void);
s32 func_02043078(u16 a);
s32 LoadCourseMapGroupEntriesData(void *a, ...);
s32 LoadCourseMapEntryGroupsData(void *a, ...);
s32 LoadCourseMapRowsData(void *a, ...);
u16 ReadCourseMapSectionCount(void **a);
