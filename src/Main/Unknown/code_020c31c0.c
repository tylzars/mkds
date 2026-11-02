#include "Main/Unknown/code_020c31c0.h"

#include "Main/Unknown/code_020c31ec.h"

u32 func_020c31ec(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217b3e0;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

void func_020c31c0(void) {
    u32 v2 = ((u32) (&data_0217b3e0));
    u32 v3 = ((u32) * (u32 *) ((v2) + (0)));
    u32 v4 = ((u32) * (u32 *) ((v3) + (172)));
    u32 v5 = ((u32(*)(void))(v4))();
    func_020c3654();
}
