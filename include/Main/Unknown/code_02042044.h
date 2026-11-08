#pragma once

#include "types.h"

// One entry of the table returned by GetCourseMapGroupEntry.
typedef struct CourseMapGroupEntry {
    /* 00 */ Vec3 mPos;
    /* 0c */ u8 mUnk_0c;
    /* 0d */ u8 mUnk_0d;
    /* 0e */ s16 mUnk_0e;
    /* 10 */ s16 mUnk_10;
    /* 12 */ s16 mUnk_12;
} CourseMapGroupEntry;

CourseMapGroupEntry *GetCourseMapGroupEntry(u16 arg0, u16 arg1);
