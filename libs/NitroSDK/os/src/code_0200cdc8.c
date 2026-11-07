#include "code_0200cdc8.h"
#include "registers.h"

void OSi_AllocateCardBus(void) {
    reg_MI_EXMEMCNT &= ~0x800;
}

void OSi_FreeCardBus(void) {
    reg_MI_EXMEMCNT |= 0x800;
}
