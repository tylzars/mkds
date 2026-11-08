#include "Main/Unknown/code_02008908.h"
#include "Main/Unknown/code_020099d8.h"
#include "code_0200eddc.h"

#pragma thumb on

int FlushAndSendMPData(int size, u32 childMask, u32 data) {
    DC_FlushRange((const void *) data, (size + 0x1fU & 0xffffffe0));
    DC_WaitWriteBufferEmpty();
    return SendMPData((void *) data, size, childMask);
}

#pragma thumb off
