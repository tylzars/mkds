#include "Main/Unknown/code_020b2c80.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020b24e4.h"
#include "Main/Unknown/code_020b252c.h"
#include "Main/Unknown/code_020b2a4c.h"
#include "Main/Unknown/code_020b2d90.h"
#include "Main/Unknown/code_020b32ec.h"
#include "Main/Unknown/code_020b41e8.h"
#include "Main/Unknown/code_020c3000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020b1de4.h"

s32 func_020b2d54(void) {
    if (func_0203c880((u16) func_020b2d90()) != 0) {
        return data_0217561c->mUnk_4e0;
    }
    return 6;
}

#pragma thumb on
#pragma optimize_for_size on
u32 func_020b2d04(void) {
    if (func_020b24e4() == 2 && func_020b2a4c() == 0) {
        return 3;
    }
    if (func_020b2a4c() != 0) {
        if (func_020b252c() == 4) {
            if (func_020b2d54() == 0) {
                return 2;
            }
            return 1;
        }
        if (func_020c3db4() != 0) {
            return 2;
        }
        return 1;
    }
    return 0;
}

void func_020b2c80(s32 a) {
    s32 n;
    s32 b;
    u16 *p;

    n = data_0217b354->mUnk_038[func_020b2d04()].mUnk_18;
    p = (u16 *) func_020b32f8();
    if (p != NULL) {
        if (data_0217b354->mUnk_010 == 0 || data_0217b354->mUnk_014 >= 5) {
            b = 0xd - n * 2 + a * 4;
            if (data_0217b354->mUnk_034 < 0x1e) {
                func_020b4428(p, 2, b, 1, 1, 0x21);
                func_020b4428(p, 2, b + 1, 1, 1, 0x41);
            }
            func_020b44a4(p, 0, b - 1, 0x20, 4, 0xe);
        }
    }
}
#pragma thumb off
