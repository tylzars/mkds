#include "Main/Unknown/code_02008908.h"
#include "Main/Unknown/code_020099d8.h"
#include "code_0200eddc.h"

#pragma thumb on

int func_02008908(int a, u32 b, u32 c) {
    DC_FlushRange((const void *) c, (a + 0x1fU & 0xffffffe0));
    DC_WaitWriteBufferEmpty();
    return SendMPData((void *) c, a, b);
}

#pragma thumb off
