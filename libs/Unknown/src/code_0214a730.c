#include "code_0214a730.h"
#include "code_0214cfe4.h"

// Copies the 32 color entries of toonTable to the toon table registers.
void G3X_SetToonTable(const u16 *toonTable) {
    MIi_CpuCopy16(toonTable, (void *) 0x4000380, 0x40);
}
