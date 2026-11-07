#include "Main/Unknown/code_020b252c.h"
#include "Main/Unknown/code_020364e0.h"

#include "Main/Unknown/code_020b2540.h"
#include "Main/Unknown/code_020b255c.h"
#include "Main/Unknown/code_020b2c68.h"
#include "Main/Unknown/code_020b2e98.h"
#include "Main/Unknown/unk_021759c0.h"

#pragma thumb on

void func_020b255c(void) {
    int v1;
    v1 = func_020b2e98();
    if (v1 != 0) {
        func_020b2c68();
    }
}

#pragma thumb off

void *func_020b2540(void) {
    return GetHeap(func_020364e8());
}

u32 func_020b252c(void) {
    return (gRaceSetup->mMode);
}
