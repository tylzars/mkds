#include "code_02146a50.h"
#include "code_0200fc8c.h"
#include "code_0214d5b8.h"
#include "code_0214f4a4.h"
#include "Main/Unknown/code_02000000.h"
#include "Main/Unknown/code_0200007e.h"

void func_02146ab4(void) {
    if (((s32) (*(vu16 *) 0x027FFFA8 & 0x8000)) >> 15 != 0) {
        PM_ForceToPowerOff();
    }
    func_02146a50(1, 1);
    IrqDisableLoopForever();
}

void func_02146a50(u32 a, s32 b) {
    while (PxiSendFifoWord(14, a, 0) != 0) {
        WaitByLoop(b);
    }
}
