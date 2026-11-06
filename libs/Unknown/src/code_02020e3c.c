#include "code_02020e3c.h"

#include "code_0200e77c.h"
#include "code_0200edc0.h"
#include "code_02020eb0.h"
#include "code_02021764.h"

u32 data_021732ac;
OSMutex data_021732b0;

void SND_Init(void) {
    if (data_021732ac != 0) {
        return;
    }
    data_021732ac = 1;
    OS_InitMutex(&data_021732b0);
    SND_CommandInit();
    SND_AlarmInit();
}

void SharedLockWait(void) {
    OS_LockMutex(&data_021732b0);
}

void SharedLockUnlock(void) {
    OS_UnlockMutex(&data_021732b0);
}
