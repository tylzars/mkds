#include "code_0200ce30.h"

void OSi_AllocateCartridgeBus(void) {
    *(vu16 *) 0x4000204 &= ~0x80;
}

void OSi_FreeCartridgeBus(void) {
    *(vu16 *) 0x4000204 |= 0x80;
}
