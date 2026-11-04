#pragma once

#include "types.h"

// Entries are called with their index + 1 by raise, which compares them with 0 and 1 first.
typedef void (*Unk02139e20Func)(int a);

extern Unk02139e20Func gRaiseHandlers[];

int raise(int a);
