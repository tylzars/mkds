#pragma once

#include "types.h"

typedef struct Interpolation Interpolation;

void AdvanceInterpolation(Interpolation *interpolation);
void func_02025f14(Interpolation *interpolation, s32 requestedState);
