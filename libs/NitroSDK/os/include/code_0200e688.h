#pragma once

#include "types.h"
#include "os_thread.h"

void ThreadInitContext(OSThread *t, void (*f)(void *), u32 v);
