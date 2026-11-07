#pragma once

#include "types.h"

// A colour that fades between course colours: the colour at 0x00, its three 5-bit parts when the fade began at
// 0x02 to 0x06, their differences to the new colour at 0x08 to 0x0c, its bit at 0x0e and the fade factor at 0x10.
typedef struct CourseColorBlend {
    /* 00 */ u16 mColor;
    /* 02 */ s16 mStartComponent0;
    /* 04 */ s16 mStartComponent1;
    /* 06 */ s16 mStartComponent2;
    /* 08 */ s16 mComponentDelta0;
    /* 0a */ s16 mComponentDelta1;
    /* 0c */ s16 mComponentDelta2;
    /* 0e */ u16 mColorBit;
    /* 10 */ s16 mBlendFactor;
} CourseColorBlend;

void AdvanceCourseColorBlend(void *object, u16 colorMask, s32 c);
void SetCourseColorBlendColor(void *object, u32 colorMask);
void *InitCourseColorBlend(void *object, u32 colorMask);
