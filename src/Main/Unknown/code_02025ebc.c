#include "Main/Unknown/code_02025ebc.h"
#include "Main/Unknown/code_020ade08.h"

#pragma thumb on

s16 GetInterpolatedValue(Interpolation *interpolation) {
    return InterpolateS16(1, interpolation->mStartValue, interpolation->mEndValue, interpolation->mCounter,
                          interpolation->mCounterLimit);
}

#pragma thumb off
