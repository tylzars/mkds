#include "Main/Unknown/code_0209f5cc.h"

void func_0209f5cc(u32 a, int b) {
    u32 v1;
    u32 v2;
    v2 = 0x1e;
    func_01ff9048((u32) 0x14, (void *) ((u32) (&v2)), 1);
    v1 = (u32) func_020e6cbc((Vec3 *) (b + 4));
    func_01ff9048((u32) 0x19, (void *) v1, 0xc);
    func_01ff9048((u32) 0x1b, (void *) (b + 0x1c), 3);
    func_0209b77c((void *) (*(u32 *) &gChandelier), (u16) (*(u16 *) (b + 0xa0)));
    func_0209bb2c((void *) a, (void *) ((int) (*(u32 *) &gChandelier)), (void *) b);
}
