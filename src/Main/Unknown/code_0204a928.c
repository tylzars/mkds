#include "Main/Unknown/code_0204a928.h"
#include "code_0200eddc.h"

void FinishKeyRecording(void *record) {
    u32 value0 = (u32) record;
    u32 value1;
    u32 buffer;
    u32 value3;
    u32 status;
    u32 compareRight0;
    value1 = *(const u32 *) ((value0) + (8));
    status = value1;
    compareRight0 = 1u;
    if (status != compareRight0) {
    }
    if (status != compareRight0) {
    }
    if (status != compareRight0) {
        return;
    }
    value3 = *(const u16 *) ((value0) + (4));
    buffer = *(const u32 *) ((value0) + (0));
    value1 = 0u;
    value3 = (value3 << 1);
    *(u32 *) ((buffer) + (0)) = value3;
    *(u32 *) ((value0) + (8)) = value1;
    value0 = *(const u32 *) ((value0) + (0));
    value1 = 0xdccu;
    DC_StoreRange((void *) value0, value1);
}
