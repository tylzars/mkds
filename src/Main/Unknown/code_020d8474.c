#include "Main/Unknown/code_020d8474.h"
#include "Main/Unknown/code_020d9340.h"
#include "Main/Unknown/code_020d9480.h"

void func_020d8488(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 value12;
    value12 = (u32) &func_020d9480;
    value2 = value1;
    value1 = (u32) * (const u32 *) ((value0) + (92));
    func_020d9480(value0, value1, value2);
}

void func_020d8474(Unk020d849c *arg0, Vec3 *arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value2;
    u32 value12;
    value12 = (u32) &func_020d9340;
    value2 = value1;
    value1 = (u32) * (const u32 *) ((value0) + (92));
    func_020d9340(value0, value1, value2);
}
