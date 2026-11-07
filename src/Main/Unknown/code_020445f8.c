#include "Main/Unknown/code_020445f8.h"
#include "Main/Unknown/code_0205928c.h"
#include "Main/Unknown/unk_021759c0.h"

void RequestMPState16ForNextRace(void) {
    u32 courseId;
    u32 mode;
    u32 value12;
    courseId = gRaceSetup->mNextHeader.mCourseId;
    mode = gRaceSetup->mNextHeader.mMode;
    RequestMPState16((void *) courseId, (void *) mode);
}
