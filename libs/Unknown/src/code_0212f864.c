#include "code_0212f864.h"

void InterpolatorInit(NNSSndFader *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = 0u;
    arg0->mTarget = value2;
    value1 = (u32) arg0->mTarget;
    arg0->mOrigin = value1;
    arg0->mFrame = value2;
    value1 = (u32) arg0->mFrame;
    arg0->mCounter = value1;
}
