#pragma once

#include "types.h"
#include "os_thread.h"

BOOL OS_SaveContext(OSThread *t);
void OS_LoadContext(OSThread *t);
