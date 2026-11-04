#include "code_02020e3c.h"

#include "code_0200e77c.h"
#include "code_0200edc0.h"
#include "code_02020eb0.h"
#include "code_02021764.h"

u32 data_021732ac;
ThreadLock data_021732b0;

void func_02020e64(void) {
    if (data_021732ac != 0) {
        return;
    }
    data_021732ac = 1;
    ThreadLockInit(&data_021732b0);
    func_020215bc();
    func_02021784();
}

void func_02020e50(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &ThreadLockWait;
    value0 = (u32) &data_021732b0;
    ThreadLockWait((void *) value0);
}

void func_02020e3c(void) {
    u32 value0;
    u32 value12;
    value12 = (u32) &ThreadLockUnlock;
    value0 = (u32) &data_021732b0;
    ThreadLockUnlock((void *) value0);
}
