#include "code_0212f864.h"

void InterpolatorInit(Interpolator *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = 0u;
    arg0->mToValue = value2;
    value1 = (u32) arg0->mToValue;
    arg0->mFromValue = value1;
    arg0->mTotalCount = value2;
    value1 = (u32) arg0->mTotalCount;
    arg0->mDoneCount = value1;
}
