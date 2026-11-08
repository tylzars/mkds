#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/unk_021759c0.h"

s32 RaceHudSubScreenGetCurrentCourseId(void) {
    u32 courseId;
    courseId = gRaceSetup->mCourseId;
    return courseId;
}
