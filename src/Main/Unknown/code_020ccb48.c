#include "Main/Unknown/code_020ccb48.h"

#include "Main/Unknown/code_020ccb78.h"
#include "Main/Unknown/code_020ccbb8.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_0203ba70.h"
#include "Main/Unknown/code_0203be48.h"
#include "Main/Unknown/code_020ae3b4.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_02029890.h"

#pragma thumb on
void func_020ccbb8(void) {
    u8 i;
    s32 a;
    s32 b;
    u32 x;
    u32 y;

    a = func_020ae3b4(7) + 1;
    b = func_020ae3b4(6) + 1;
    if (a <= b) {
        b++;
    }
    func_0203be6c(data_0217b43c->mUnk_954, 0, func_02029930()->mUnk_00[0].mUnk_00, func_02029930()->mUnk_00[0].mUnk_04);
    func_0203ba70(data_0217b43c->mUnk_954);
    func_020468b0(0, func_02029930()->mUnk_00[0].mUnk_00, func_02029930()->mUnk_00[0].mUnk_04, 0, -1, 3);
    for (i = 1; i < 8; i++) {
        func_0203be48(data_0217b43c->mUnk_954, i, &x, &y);
        func_020468b0(i, x, y, 1, -1, i == a ? 0 : i == b ? 1 : 3);
    }
}
#pragma thumb off

#pragma thumb on

void func_020ccb78(void) {
    u8 v1;
    u32 *v2;
    int v3;
    v2 = (u32 *) ((u32) func_02029930());
    v3 = ((u32) func_02029930());
    func_020468b0(0, (u32) (*v2), (u32) (*(u32 *) (v3 + 4)), 0, (u32) 0xffffffff, 3);
    v1 = 1;
    do {
        func_020ccb48((u32) v1);
        v1 = v1 + 1;
    } while (v1 < 8);
}

#pragma thumb off

void func_020ccb48(u32 a) {
    func_020468b0(a, 0xffffffff, 0xffffffff, 4, 0xffffffff, 3);
}
