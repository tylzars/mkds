#include "Main/Unknown/code_02073e98.h"
#include "Main/Unknown/unk_0217a000.h"

u32 ClearCameraEntryFlags(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    value1 = (u32) &gCameraEntryChanged;
    value2 = 0u;
    value0 = (u32) &gEntryCameraUpdateRan;
    *(u32 *) ((value1) + (0)) = value2;
    *(u32 *) ((value0) + (0)) = value2;
    return value0;
}
