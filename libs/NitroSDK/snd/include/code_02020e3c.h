#pragma once

#include "types.h"

typedef struct OSMutex OSMutex;

extern u32 data_021732ac;
extern OSMutex data_021732b0;

void SNDi_UnlockMutex(void);
void SNDi_LockMutex(void);
void SND_Init(void);
