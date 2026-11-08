#include "Main/Unknown/code_02060c38.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

void CopyBuddyFriendDataList(void *destination) {
    u32 value0 = (u32) destination;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 value12;
    value1 = (u32) &data_0217aa08;
    value3 = 0x874u;
    value2 = *(const u32 *) ((value1) + (0));
    value1 = value0;
    value0 = *(const u32 *) ((value2) + (32));
    value2 = 0x2d0u;
    value0 = (value0) + (value3);
    MI_CpuCopy8((const void *) value0, (void *) value1, value2);
}
