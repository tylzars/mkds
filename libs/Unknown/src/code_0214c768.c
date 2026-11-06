#include "code_0214c768.h"

// Writes bank to the WRAM bank control byte at 0x4000247.
void MI_SetWramBank(u32 bank) {
    *(u8 *) 0x4000247 = bank;
}
