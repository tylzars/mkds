#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_02042064.h"

Unk02042044 *GetCourseMapGroupEntry(u16 arg0, u16 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value4;
    value4 = value1;
    value0 = func_02042fc4(value0);
    value1 = *(const u32 *) ((value0) + (4));
    value0 = 0x14u;
    value0 = (value4) * (value0) + (value1);
    return (Unk02042044 *) value0;
}
