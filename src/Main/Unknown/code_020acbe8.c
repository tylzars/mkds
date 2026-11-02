#include "Main/Unknown/code_020acbe8.h"

#include "Main/Unknown/code_020acbf0.h"
#include "Main/Unknown/code_020acbf8.h"
#include "Main/Unknown/code_020acdc4.h"
#include "Main/Unknown/code_020acdec.h"
#include "Main/Unknown/code_020ace14.h"
#include "Main/Unknown/code_020acec4.h"
#include "Main/Unknown/code_020acef4.h"
#include "Main/Unknown/code_020acf04.h"
#include "Main/Unknown/code_020acff4.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020291c4.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_0210f72c.h"
#include "Main/Unknown/code_0210f744.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020acde4.h"
#include "Main/Unknown/code_020ace0c.h"

u32 func_020ace0c(u32 p0) {
    return ((u32) * (const u16 *) ((u8 *) p0 + 0));
}

u32 func_020acdec(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value2 = (u32) &data_02175628;
    value1 = 0x5cu;
    value1 = (value0) * (value1) + (value2);
    value12 = (u32) &func_020ace0c;
    value0 = (value1) + (0x48u);
    value0 = (u32) func_020ace0c(value0);
    return value0;
}

u32 func_020acde4(u32 p0) {
    return ((u32) * (const u16 *) ((u8 *) p0 + 2));
}

u32 func_020acdc4(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value2 = (u32) &data_02175628;
    value1 = 0x5cu;
    value1 = (value0) * (value1) + (value2);
    value12 = (u32) &func_020acde4;
    value0 = (value1) + (0x48u);
    value0 = (u32) func_020acde4(value0);
    return value0;
}

#pragma thumb on

void func_020acbf8(Unk020aca24 *a) {
    u32 i;
    s32 j;
    s32 n;

    if (a != 0) {
        i = func_020acef4();
        if (func_020acec4(i, 1) != 0) {
            func_020adad0(4, 8);
            func_020acf04();
            data_0217b340->mUnk_58 = 1;
        } else if (func_020ae408(i, 0x30) != 0) {
            switch (data_0217b340->mUnk_54) {
                case 3:
                    data_0217b340->mUnk_54 = 4;
                    data_0217b340->mUnk_5c = 1;
                    func_02105ac0(0);
                    break;
                case 4:
                    data_0217b340->mUnk_54 = 3;
                    data_0217b340->mUnk_5c = 0;
                    func_02105ac0(0);
                    break;
            }
            data_0217b340->mUnk_4c = 0;
        } else if (func_020ae408(i, 0x40) != 0) {
            switch (data_0217b340->mUnk_54) {
                case 0:
                    if (data_0217b340->mUnk_5c != 0) {
                        data_0217b340->mUnk_54 = 4;
                    } else {
                        data_0217b340->mUnk_54 = 3;
                    }
                    break;
                case 1:
                    data_0217b340->mUnk_54 = 0;
                    break;
                case 2:
                    data_0217b340->mUnk_54 = 1;
                    break;
                case 3:
                case 4:
                    data_0217b340->mUnk_54 = 2;
                    break;
            }
            func_02105ac0(0);
            data_0217b340->mUnk_4c = 0;
        } else if (func_020ae408(i, 0x80) != 0) {
            switch (data_0217b340->mUnk_54) {
                case 0:
                    data_0217b340->mUnk_54 = 1;
                    break;
                case 1:
                    data_0217b340->mUnk_54 = 2;
                    break;
                case 2:
                    if (data_0217b340->mUnk_5c != 0) {
                        data_0217b340->mUnk_54 = 4;
                    } else {
                        data_0217b340->mUnk_54 = 3;
                    }
                    break;
                case 3:
                case 4:
                    data_0217b340->mUnk_54 = 0;
                    break;
            }
            func_02105ac0(0);
            data_0217b340->mUnk_4c = 0;
        } else if (func_020ace14(i) != 0) {
            u32 x = func_020acdec(i);
            u32 y = func_020acdc4(i);
            j = data_0217b340->mUnk_54;
            n = func_020291c4(x, y, data_0217b340->mUnk_70);
            if (n != -1) {
                if (j == n) {
                    data_0217b340->mUnk_58 = 1;
                }
                data_0217b340->mUnk_54 = n;
                func_020adad0(4, 8);
                func_020acf04();
            }
        } else {
            s32 m = func_0210f738();
            data_0217b340->mUnk_4c++;
            if (data_0217b340->mUnk_4c > m) {
                if (func_0210f75c(0) != 0) {
                    a->mUnk_04 = 2;
                    func_0203b6ac(data_0217b340->mUnk_8b8);
                }
            }
        }
    }
    func_020acff4();
}

#pragma thumb off

#pragma thumb on
u32 func_020acbf0(u32 arg0) {
    u32 value0 = arg0;
    u32 value3;
    value3 = (u32) &func_020ad230;
    value0 = (u32) func_020ad230(value0);
    return value0;
}
#pragma thumb off

u32 func_020acbe8(u32 p0) {
    return ((u32) * (const u16 *) ((u8 *) p0 + 6));
}
