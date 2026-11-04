#pragma once

#include "types.h"

typedef struct MapObject MapObject;
typedef struct CourseMapRow CourseMapRow;

MapObject *CreateMapObject(u32 kind, CourseMapRow *courseRow, MapObject *source);
MapObject *CreateMapObjectFromObject(MapObject *source, s32 kind);
MapObject *CreateMapObjectFromCourseMapRow(CourseMapRow *courseRow, s32 kind);
void InitMapObjects(void);
void func_020d2e24(void);
void func_020d2dec(void);
