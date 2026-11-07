#include "Main/Unknown/code_02046740.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_021759c0.h"

void SetNextGrandPrixCourse(void) {
    gRaceSetup->mNextHeader.mCourseNumber = gRaceSetup->mCourseNumber + 1;
    if (gRaceSetup->mNextHeader.mCourseNumber <= 4) {
        gRaceSetup->mNextHeader.mCourseId =
            data_02154128[gRaceSetup->mNextHeader.mCupIndex][gRaceSetup->mNextHeader.mCourseNumber - 1];
    }
    gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_START_GP;
}
