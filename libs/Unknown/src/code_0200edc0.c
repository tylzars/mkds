#include "code_0200edc0.h"

void ThreadLockInit(ThreadLock *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    value2 = 0u;
    *(u32 *) ((value0) + (4)) = value2;
    value1 = (u32) * (const u32 *) ((value0) + (4));
    *(u32 *) ((value0) + (0)) = value1;
    *(u32 *) ((value0) + (8)) = value2;
    *(u32 *) ((value0) + (12)) = value2;
}
