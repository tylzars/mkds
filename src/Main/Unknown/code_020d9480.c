#include "Main/Unknown/code_020d9480.h"
#include "Main/Unknown/code_020d94dc.h"

void func_020d9480(u32 points, u32 fraction, u32 result) {
    u32 weight0;
    u32 weight1;
    u32 weight2;
    u32 weight3[2];
    func_020d9810(fraction, (s32 *) &weight0, (s32 *) &weight1, (s32 *) &weight2, (s32 *) weight3);
    func_020d95c0((const Vec3 *) points, (Vec3 *) result, weight0, weight1, weight2, weight3[0]);
}
