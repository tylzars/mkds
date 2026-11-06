#include "code_02146a00.h"
#include "code_0200db4c.h"
#include "Main/Unknown/unk_0217f000.h"

void ReceiveRequestReply(u32 arg0, u32 arg1, u32 arg2) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2 = arg2;
    u32 compareLeft0;
    u32 compareRight0;
    u32 compareLeft1;
    u32 compareRight1;
    compareLeft0 = value0;
    compareRight0 = 0xbu;
    if (compareLeft0 != compareRight0) {
    }
    if (compareLeft0 != compareRight0) {
    }
    if (compareLeft0 != compareRight0) {
        return;
    }
    compareLeft1 = value2;
    compareRight1 = 0u;
    if (compareLeft1 == compareRight1) {
    }
    if (compareLeft1 == compareRight1) {
    }
    if (compareLeft1 == compareRight1) {
        return;
    }
    value1 = (u32) &gAccessState;
    value0 = (u32) * (const u32 *) ((value1) + (276));
    value0 = (value0) & ~(0x20u);
    *(u32 *) ((value1) + (276)) = value0;
    value0 = (u32) * (const u32 *) ((value1) + (260));
    OS_WakeupThreadDirect((OSThread *) value0);
}
