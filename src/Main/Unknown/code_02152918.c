#include "Main/Unknown/code_02152918.h"
#include "Main/Unknown/unk_0216f000.h"
#include "os_printf.h"

#pragma thumb on

void FormatFriendKey(u32 low, u32 high, u32 buffer) {
    OS_SNPrintf((char *) buffer, 0xd, data_0216f2d4, low, high);
}

#pragma thumb off
