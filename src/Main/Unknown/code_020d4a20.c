#include "Main/Unknown/code_020d4a20.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02039860.h"

#pragma thumb on
void func_020d4a20(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    data_0217b550.mUnk_00 = e << 4;
    data_0217b4f8.mUnk_00 = e << 4;
    data_0217b550.mUnk_04 = f << 4;
    data_0217b4f8.mUnk_04 = f << 4;

    data_0217b550.mUnk_20.x = e;
    data_0217b550.mUnk_20.y = 0;
    data_0217b550.mUnk_20.z = -c;
    if ((s64) data_0217b550.mUnk_20.z * data_0217b550.mUnk_20.z +
            ((s64) data_0217b550.mUnk_20.x * data_0217b550.mUnk_20.x +
             (s64) data_0217b550.mUnk_20.y * data_0217b550.mUnk_20.y) >=
        0x10) {
        func_02039860(&data_0217b550.mUnk_20, &data_0217b550.mUnk_20);
    }
    if (data_021759c0->mUnk_57 != 0) {
        data_0217b550.mUnk_20.x = -data_0217b550.mUnk_20.x;
        data_0217b550.mUnk_20.y = -data_0217b550.mUnk_20.y;
        data_0217b550.mUnk_20.z = -data_0217b550.mUnk_20.z;
    }

    data_0217b550.mUnk_2c.x = -e;
    data_0217b550.mUnk_2c.y = 0;
    data_0217b550.mUnk_2c.z = d;
    if ((s64) data_0217b550.mUnk_2c.z * data_0217b550.mUnk_2c.z +
            ((s64) data_0217b550.mUnk_2c.x * data_0217b550.mUnk_2c.x +
             (s64) data_0217b550.mUnk_2c.y * data_0217b550.mUnk_2c.y) >=
        0x10) {
        func_02039860(&data_0217b550.mUnk_2c, &data_0217b550.mUnk_2c);
    }
    if (data_021759c0->mUnk_57 != 0) {
        data_0217b550.mUnk_2c.x = -data_0217b550.mUnk_2c.x;
        data_0217b550.mUnk_2c.y = -data_0217b550.mUnk_2c.y;
        data_0217b550.mUnk_2c.z = -data_0217b550.mUnk_2c.z;
    }

    data_0217b550.mUnk_38.x = 0;
    data_0217b550.mUnk_38.y = -e;
    data_0217b550.mUnk_38.z = a;
    if ((s64) data_0217b550.mUnk_38.z * data_0217b550.mUnk_38.z +
            ((s64) data_0217b550.mUnk_38.x * data_0217b550.mUnk_38.x +
             (s64) data_0217b550.mUnk_38.y * data_0217b550.mUnk_38.y) >=
        0x10) {
        func_02039860(&data_0217b550.mUnk_38, &data_0217b550.mUnk_38);
    }

    data_0217b550.mUnk_44.x = 0;
    data_0217b550.mUnk_44.y = e;
    data_0217b550.mUnk_44.z = -b;
    if ((s64) data_0217b550.mUnk_44.z * data_0217b550.mUnk_44.z +
            ((s64) data_0217b550.mUnk_44.x * data_0217b550.mUnk_44.x +
             (s64) data_0217b550.mUnk_44.y * data_0217b550.mUnk_44.y) >=
        0x10) {
        func_02039860(&data_0217b550.mUnk_44, &data_0217b550.mUnk_44);
    }
}
#pragma thumb off
