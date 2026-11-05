#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/code_0210cf20.h"

void func_02109110(Unk0210bfbc *p, u32 a, Vec3 *v) {
    u32 value0 = (u32) p;
    u32 value1 = a;
    u32 value2 = (u32) v;
    u32 value3;
    u32 value12;
    value12 = (u32) &func_0210cf20;
    *(u8 *) ((value0) + (60)) = (u8) value1;
    value3 = ~(0u);
    value1 = value2;
    *(u32 *) ((value0) + (64)) = value3;
    func_0210cf20(p, value1);
}
