#include "Main/Unknown/code_02073e04.h"
#include "code_02147cd8.h"

u32 func_02073e88(void) {
    return ((u32) * (const u32 *) ((u8 *) (u32) (((u32) (&data_0217aca8))) + 0));
}

int func_02073e4c(u32 param_1) {
    int v1;
    u8 v2[12];
    v1 = ((u32) func_02061808());
    func_021484d0((const Vec3 *) param_1, (const Vec3 *) (v1 + 0x24), (Vec3 *) ((int *) (void *) v2));
    return func_02039828((const Vec3 *) (v1 + 0x15c), (const Vec3 *) v2);
}

int func_02073e04(u32 param_1) {
    int v1;
    int v2;
    u8 v3[12];
    v1 = ((u32) func_02061808());
    func_021484d0((const Vec3 *) param_1, (const Vec3 *) (v1 + 0x24), (Vec3 *) ((int *) (void *) v3));
    v2 = ((u32) func_02039828((const Vec3 *) (v1 + 0xc), (const Vec3 *) v3));
    return *(short *) (v1 + 0x26c) * v2;
}
