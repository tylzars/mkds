#include "Main/Unknown/code_0208ab00.h"

void func_0208ab4c(u16 *param_1) {
    u32 v1;
    u32 v2;
    v1 = (u32) *param_1;
    func_01ff9048((u32) 0x33, (void *) ((u32) (&v1)), 1);
    v2 = *param_1 | 0x40000000;
    func_01ff9048((u32) 0x33, (void *) ((u32) (&v2)), 1);
}

void func_0208ab00(void) {
    u32 v1;
    u32 v2[1];
    v1 = ((u32) 0x00007fffu);
    func_01ff9048((u32) 0x33, (void *) ((u32) (&v1)), 1);
    v2[0] = ((u32) 0x40007fffu);
    func_01ff9048((u32) 0x33, (void *) v2, 1);
}
