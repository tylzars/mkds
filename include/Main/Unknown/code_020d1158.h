#pragma once

#include "types.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

// The two values func_020d1198 passes to GetRaceStartBattleMNcerEntry.
enum {
    VALUE_0 = 0,
    VALUE_1 = 1,
};

void func_020d1198(RaceHudOamBuffer *a);
u16 *func_020d118c(void);
u32 func_020d1164(void);
u32 func_020d1158(void);
