#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0205d0bc.h"
#include "Main/Unknown/unk_0217a000.h"

u32 func_0205d0bc(void *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = 0xau;
    value0 = (u32) HeapAlloc((void *) value0, value1);
    value1 = (u32) &data_0217aa18;
    *(u32 *) ((value1) + (0)) = value0;
    value0 = 0xau;
    return value0;
}
