#include "Main/Unknown/code_02063b50.h"
#include "Main/Unknown/code_0206bcb0.h"

u32 func_02063b50(Kart *arg0, Vec3 *arg1) {
    Vec3 *value3;
    s32 value0;
    s32 value2 = arg0->mUnk_120.x;
    value3 = &arg0->mUnk_120;
    arg1->x = value2;
    value0 = value3->y;
    arg1->y = value0;
    value0 = value3->z;
    arg1->z = value0;
    return value0;
}
