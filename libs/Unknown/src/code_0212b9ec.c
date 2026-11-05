#include "code_0212b9ec.h"
#include "code_020207ec.h"
#include "code_02020eb0.h"
#include "code_0212c9d4.h"
#include "code_0201ec30.h"
#include "Main/Unknown/code_02021000.h"

void func_0212b9f8(void *a) {
    u32 v;

    func_0212cb78();
    SND_StopTimer(0, 0, 0, 0);
    v = SND_GetCurrentCommandTag();
    PxiCommandSendPending(1);
    PxiCommandWaitForSequence(v);
}

void func_0212b9ec(void *a) {
    func_0212cad8();
}
