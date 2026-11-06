#pragma once

#include "types.h"

typedef struct OSLockWord OSLockWord;

// Returns the owner id of a lock word.
u16 OS_ReadOwnerOfLockWord(OSLockWord *lockp);
