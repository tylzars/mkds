#include "Main/Unknown/code_020d0ee8.h"

#include "Main/Unknown/code_020d0efc.h"
#include "Main/Unknown/code_020d0e3c.h"
#include "Main/Unknown/code_020d0f60.h"
#include "Main/Unknown/code_020d0f78.h"
#include "Main/Unknown/unk_0216a000.h"
#include "Main/Unknown/code_02057000.h"

u32 func_020d0f60(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217aa0c;
    value1 = 1u;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    *(u32 *) ((value0) + (248)) = value1;
    return value0;
}

#pragma thumb on
u32 func_020d0efc(int a) {
    u32 r;

    r = 1;
    if (data_0216aeac[a * 2] == 0) {
        r = 0;
    } else if (func_020d0ec4() != 0) {
        if (data_0217b4a4->mUnk_0c != a) {
            data_0217b4a4->mUnk_0c = a;
            func_02057df0(func_020d1080);
            func_02057df0(func_020d0ffc);
            func_02057df0(func_020d0f78);
            func_020d0f60();
        }
    } else {
        r = 0;
    }
    return r;
}
#pragma thumb off

u32 func_020d0ee8(void) {
    return ((u32) data_0217aa0c->mUnk_f8);
}
