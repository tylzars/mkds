#include "Main/Unknown/code_0215228c.h"

#pragma thumb on

u32 ComputeSecondsOfDay(const void *values) {
    return (
        ((*OFFSET_PTR(const u32, values, 8))) +
        (((0x3cu) * ((((*OFFSET_PTR(const u32, values, 4))) + (((0x3cu) * ((*OFFSET_PTR(const u32, values, 0))))))))));
}

#pragma thumb off
