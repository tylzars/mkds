#pragma once

#include "types.h"
#include "Main/Unknown/unk_02174000.h"

typedef struct RaceSetupCopy RaceSetupCopy;

void func_02029890(unsigned int courseListMode);
void func_020298a4(unsigned int ruleKind);
void func_020298b8(unsigned int useTeams);
void func_020298cc(unsigned int mirrorMode);
void func_020298e0(unsigned int engineIndex);
void func_020298f4(unsigned int courseId);
void func_02029908(unsigned int mode);
void func_0202991c(unsigned int cpuDifficulty);
RaceSetupCopy *GetRaceSetupCopy(void);
