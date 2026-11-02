#include "Main/Unknown/code_02073e04.h"
#include "code_02147cd8.h"

u32 func_02073e88(void) {
    return (u32) data_0217aca8;
}

int func_02073e4c(u32 a) {
    Unk02061808 *v1;
    u8 v2[12];
    v1 = func_02061808();
    func_021484d0((const Vec3 *) a, &v1->mUnk_024, (Vec3 *) (v2));
    return func_02039828(&v1->mUnk_15c, (const Vec3 *) v2);
}

int func_02073e04(u32 a) {
    int v1;
    int v2;
    u8 v3[12];
    v1 = ((u32) func_02061808());
    func_021484d0((const Vec3 *) a, (const Vec3 *) (v1 + 0x24), (Vec3 *) (v3));
    v2 = ((u32) func_02039828((const Vec3 *) (v1 + 0xc), (const Vec3 *) v3));
    return *(s16 *) (v1 + 0x26c) * v2;
}
