#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0205dc54.h"
#include "Main/Unknown/unk_0217a000.h"

u32 func_0205dc54(void *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = 0x168u;
    value0 = (u32) HeapAlloc((void *) value0, value1);
    value1 = (u32) &data_0217aa1c;
    *(u32 *) ((value1) + (0)) = value0;
    return value0;
}
