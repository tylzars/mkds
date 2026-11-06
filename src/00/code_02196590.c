#include "00/code_02196590.h"
#include "00/code_02196594.h"

void GpiSetErrorMessage(void *arg0, void *arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    u32 value3;
    value0 = *(const u32 *) ((value0) + 0u);
    value2 = 0x100u;
    value3 = (u32) &GpiCopyString;
    GpiCopyString((char *) value0, (const char *) value1, value2);
    return;
}
