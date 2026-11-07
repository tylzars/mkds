#include "Main/Unknown/code_0204aa04.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/unk_02175000.h"

u32 func_0204aa28(u32 flag) {
    u32 value0 = flag;
    u32 value1;
    u32 value2;
    u32 compareLeft0;
    u32 compareRight0;
    value1 = 0x27ffc40u;
    value1 = *(const u16 *) ((value1) + (0));
    compareLeft0 = value1;
    compareRight0 = 2u;
    if (compareLeft0 == compareRight0) {
        return value0;
    }
    value1 = (u32) &data_021759d0;
    value0 = (value0) & (1u);
    value2 = *(const u32 *) ((value1) + (0));
    value1 = *(const u32 *) ((value2) + (28));
    value1 = (value1) & ~(4u);
    value0 = (value1) | ((value0 << 2));
    *(u32 *) ((value2) + (28)) = value0;
    return value0;
}

u32 InitKeyRecordingBuffer(u32 recordAddress, u32 heap) {
    u32 value0 = recordAddress;
    u32 value1 = heap;
    u32 value4;
    value4 = value0;
    value0 = value1;
    value1 = 0xdccu;
    value0 = (u32) HeapAlloc((void *) value0, value1);
    *(u32 *) ((value4) + (0)) = value0;
    return value0;
}
