#pragma once

#include "types.h"

typedef struct ThreadLock ThreadLock;

extern u32 data_021732ac;
extern ThreadLock data_021732b0;

void SharedLockUnlock(void);
void SharedLockWait(void);
// Returns when data_021732ac is not 0. Otherwise sets it to 1, calls ThreadLockInit(&data_021732b0), then
// SND_CommandInit and SND_AlarmInit.
void SND_Init(void);
