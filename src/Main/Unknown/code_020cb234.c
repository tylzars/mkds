#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/code_020cb234.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020cb2d4.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_021281b4.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/code_020cc000.h"
#include "Main/Unknown/code_020ccc9c.h"

#pragma thumb on
#pragma optimize_for_size on
void func_020cb234(void) {
    s32 n;
    Unk02124b1c *a;
    Unk02124b1c *b;
    s32 i;
    s16 v;

    n = func_020ccccc();
    a = data_0217b43c->mUnk_93c;
    b = data_0217b43c->mUnk_948;
    if (n < 10) {
        a->mUnk_06 = func_020ae4c0(1, -0x28, 0, n, 10);
        v = func_020ae4c0(1, 0xf0, 0, n, 10);
        for (i = 0; i <= 14; i++) {
            b[i].mUnk_04 = v;
        }
        func_02128374();
    } else {
        a->mUnk_06 = 0;
        for (i = 0; i <= 14; i++) {
            b[i].mUnk_04 = 0;
        }
        func_020ccc74(1, 0x1f);
        func_021281c8(0xf);
        data_0217b43c->mUnk_934 = 0;
    }
    func_020cb2d4();
}
#pragma thumb off
