#include "Main/Unknown/code_020cb234.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020cb2d4.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_0212775c.h"
#include "00/code_02181f98.h"
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
        a->mUnk_06 = InterpolateS16(1, -0x28, 0, n, 10);
        v = InterpolateS16(1, 0xf0, 0, n, 10);
        for (i = 0; i <= 14; i++) {
            b[i].mUnk_04 = v;
        }
        RequestSelectReturnState1();
    } else {
        a->mUnk_06 = 0;
        for (i = 0; i <= 14; i++) {
            b[i].mUnk_04 = 0;
        }
        func_020ccc74(1, 0x1f);
        SetSelectReturnSoundId(0xf);
        data_0217b43c->mUnk_934 = FALSE;
    }
    func_020cb2d4();
}
#pragma thumb off
