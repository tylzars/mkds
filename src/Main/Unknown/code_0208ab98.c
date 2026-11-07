#include "Main/Unknown/code_0208ab98.h"
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

void *InitCourseColorBlend(void *object, u32 colorMask) {
    CourseColorBlend *blend = object;
    u16 colorIndex;
    u16 color;

    for (colorIndex = 0; colorIndex < 4; colorIndex++) {
        if (colorMask & (1 << colorIndex)) {
            break;
        }
    }
    color = gCourseMap->mSettings->mColors[colorIndex];
    blend->mColor = color;
    blend->mColorBit = 1 << colorIndex;
    blend->mStartComponent0 = blend->mColor & 0x1f;
    blend->mStartComponent1 = (blend->mColor >> 5) & 0x1f;
    blend->mStartComponent2 = (blend->mColor >> 10) & 0x1f;
    blend->mComponentDelta0 = 0;
    blend->mComponentDelta1 = 0;
    blend->mComponentDelta2 = 0;
    blend->mBlendFactor = 0x1000;
    return object;
}

void SetCourseColorBlendColor(void *object, u32 colorMask) {
    CourseColorBlend *blend = object;
    u16 colorIndex;

    for (colorIndex = 0; colorIndex < 4; colorIndex++) {
        if (colorMask & (1 << colorIndex)) {
            break;
        }
    }
    blend->mColor = gCourseMap->mSettings->mColors[colorIndex];
    blend->mColorBit = 1 << colorIndex;
}

void AdvanceCourseColorBlend(void *object, u16 colorMask, s32 c) {
    CourseColorBlend *blend = object;
    u16 newColorBits = ~blend->mColorBit & colorMask;
    u16 colorIndex;
    u16 color;
    s32 n;

    if (newColorBits != 0) {
        for (colorIndex = 0; colorIndex < 4; colorIndex++) {
            if (newColorBits & (1 << colorIndex)) {
                break;
            }
        }
        color = gCourseMap->mSettings->mColors[colorIndex];
        blend->mStartComponent0 = blend->mColor & 0x1f;
        blend->mComponentDelta0 = (s16) (color & 0x1f) - blend->mStartComponent0;
        blend->mStartComponent1 = (blend->mColor >> 5) & 0x1f;
        blend->mComponentDelta1 = (s16) ((color >> 5) & 0x1f) - blend->mStartComponent1;
        blend->mStartComponent2 = (blend->mColor >> 10) & 0x1f;
        blend->mComponentDelta2 = (s16) ((color >> 10) & 0x1f) - blend->mStartComponent2;
        blend->mBlendFactor = 0;
        blend->mColorBit = 1 << colorIndex;
    }
    if (blend->mBlendFactor == 0x1000) {
        return;
    }
    blend->mBlendFactor = blend->mBlendFactor + ((s32) (((s64) c * 0xa4 + 0x800) >> 12) + 0x29);
    if (blend->mBlendFactor >= 0x1000) {
        blend->mBlendFactor = 0x1000;
    }
    blend->mColor =
        (s16) (blend->mStartComponent0 + (s32) (((s64) blend->mComponentDelta0 * blend->mBlendFactor + 0x800) >> 12)) +
        ((s16) (blend->mStartComponent1 + (s32) (((s64) blend->mComponentDelta1 * blend->mBlendFactor + 0x800) >> 12))
         << 5) +
        ((s16) (blend->mStartComponent2 + (s32) (((s64) blend->mComponentDelta2 * blend->mBlendFactor + 0x800) >> 12))
         << 10);
}
