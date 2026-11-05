#include "code_0212ba34.h"
#include "code_020207ec.h"

void func_0212ba34(int a) {
    if (a != 0) {
        SND_SetMasterPan((u32) 0x40);
        return;
    }
    SND_ResetMasterPan();
}
