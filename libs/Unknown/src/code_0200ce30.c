#include "code_0200ce30.h"
#include "registers.h"

void OSi_AllocateCartridgeBus(void) {
    reg_MI_EXMEMCNT &= ~0x80;
}

void OSi_FreeCartridgeBus(void) {
    reg_MI_EXMEMCNT |= 0x80;
}
