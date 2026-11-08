#pragma once

#include "types.h"
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
#include "Main/Unknown/code_020b502c.h" // UnkPair020b502c
#include "Main/Unknown/code_02056b30.h" // TimeRecord

void GetRaceHudSubScreenScrollLimits(UnkPair020b502c *outFirst, UnkPair020b502c *outSecond);
void GetRaceHudSubScreenCourseMinMax(UnkPair020b502c *outFirst, UnkPair020b502c *outSecond);
void SetFixed12MinMaxFromWhole(UnkPair020b502c *outFirst, UnkPair020b502c *outSecond, s32 firstX, s32 firstZ,
                               s16 secondX, s16 secondZ);
void GetRaceHudSubScreenState0MinMax(UnkPair020b502c *outFirst, UnkPair020b502c *outSecond);
void ComputeRaceHudSubScreenState0MinMax(UnkPair020b502c *outFirst, UnkPair020b502c *outSecond, s32 firstX, s32 firstZ,
                                         s16 secondX, s16 secondZ);
void CopyPlayerOrTimeRecordName(u32 rowIndex, u16 *nameOut, u32 copyFullLength);
