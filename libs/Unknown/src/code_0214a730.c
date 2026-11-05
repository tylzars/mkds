#include "code_0214a730.h"
#include "code_0214cfe4.h"

void G3X_SetToonTable(const u16 *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value1 = 0x4000380u;
    value2 = 0x40u;
    MemCopyHalfwords((const void *) value0, (void *) value1, value2);
}
