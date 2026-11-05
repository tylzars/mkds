#pragma once

#include "types.h"
#include "Main/Unknown/code_020b03bc.h"
#include "Main/Unknown/code_020ae770.h"

// Stores in *a the address of the mTimeDifferenceSign member of gRaceHud and in *b the address of its
// mTimeDifferenceDigits member.
void GetRaceHudTimeDifference(s32 **a, TimeDigits **b);
