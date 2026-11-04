#include "code_0200c46c.h"
#include "code_0214d5b8.h"
#include "Main/Unknown/code_02000000.h"

#pragma thumb on

// Calls PxiSendFifoWord(13, a, 0) and, while it returns nonzero, WaitByLoop(1) and the call again.
void func_0200c46c(u32 a) {
    if (PxiSendFifoWord(13, a, 0) != 0) {
        do {
            WaitByLoop(1);
        } while (PxiSendFifoWord(13, a, 0) != 0);
    }
}
