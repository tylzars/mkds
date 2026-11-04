#pragma once

#include "types.h"

typedef struct ThreadLock ThreadLock;

extern u32 data_021732ac;
extern ThreadLock data_021732b0;

void SharedLockUnlock(void);
void SharedLockWait(void);
void func_02020e64(void);
