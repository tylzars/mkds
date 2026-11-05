#include "Main/Unknown/code_020cb340.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
#pragma optimize_for_size on
void func_020cb340(void) {
    Unk02124b1c *a;
    s32 b;
    s32 i;

    a = data_0217b43c->mUnk_948;
    b = data_0217b43c->mUnk_930;
    for (i = 0; i <= 9; i++) {
        a[i].mUnk_00 = 1;
    }
    for (i = 10; i <= 14; i++) {
        a[i].mUnk_00 = 0;
    }
    if (func_020ccca8() != 3 || data_0217b43c->mUnk_934 == FALSE || func_020ccccc() >= 5) {
        a[b + 5].mUnk_00 = 0;
        a[b + 10].mUnk_00 = 1;
    }
    if (data_0217b43c->mUnk_00c == 3) {
        a[b].mUnk_04 = data_0217b43c->mUnk_938;
        a[b + 5].mUnk_04 = data_0217b43c->mUnk_938;
        a[b + 10].mUnk_04 = data_0217b43c->mUnk_938;
    }
}
