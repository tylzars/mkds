#include "code_0200cdc8.h"

void OSi_AllocateCardBus(void) {
    *(vu16 *) 0x4000204 &= ~0x800;
}

void OSi_FreeCardBus(void) {
    *(vu16 *) 0x4000204 |= 0x800;
}
