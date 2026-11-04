#include "Main/Unknown/code_02046740.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_021759c0.h"

void func_02046740(void) {
    data_021759c0->mNextHeader.mCourseNumber = data_021759c0->mCourseNumber + 1;
    if (data_021759c0->mNextHeader.mCourseNumber <= 4) {
        data_021759c0->mNextHeader.mCourseId =
            data_02154128[data_021759c0->mNextHeader.mCupIndex][data_021759c0->mNextHeader.mCourseNumber - 1];
    }
    data_021759c0->mNextHeader.mUnk_0c = 3;
}
