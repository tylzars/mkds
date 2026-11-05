#include "Main/Unknown/code_020ec884.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/unk_0216c000.h"

void func_020ec884(Unk020e43a8 *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 value4;
    value4 = value0;
    value1 = (u32) &data_0216c414;
    value3 = value4;
    value0 = (value4) + (0x80u);
    value2 = 3u;
    func_02046be8((void *) value0, (UnkFunc *const *) value1, (s32) value2, (void *) value3);
    value0 = 0u;
    *(u16 *) ((value4) + (144)) = (u16) value0;
    value0 = 1u;
    *(u16 *) ((value4) + (146)) = (u16) value0;
}
