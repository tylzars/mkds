#include "Main/Unknown/code_0210aa14.h"
#include "Main/Unknown/code_02079b40.h"
#include "Main/Unknown/code_0210f000.h"
#include "Main/Unknown/code_0210faac.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0212bcac.h"
#include "code_0212d254.h"
#include "code_0212df7c.h"

void func_0210aa14(Unk0206bcb0 *a, Unk0210bf24 *b, s32 c) {
    u32 d;
    u32 e;
    s32 f;
    Unk0212d580 *p;
    u32 g;

    d = b->mUnk_18;
    e = b->mUnk_16;
    f = -1;
    if (a->mUnk_74 == data_021759c0->mUnk_62) {
        p = func_0212d580(d, e);
        g = p->mUnk_05;
        if (g == 2) {
            f = 4;
        } else if (g == 3) {
            f = 5;
        } else if (g == 6) {
            if (func_0210fad4() != 0 || func_0210fac4() != 0) {
                f = 7;
            }
        }
    }
    if ((b->mUnk_19 & 0x20) && (b->mUnk_19 & 0x40)) {
        g = func_02079b40(a->mUnk_74) + 0x2d;
        func_0212ec04(&b->mUnk_00, f, g, c, d, e);
        if (b == 0) {
            return;
        }
        func_0212c3c8(&b->mUnk_00, 0, (s16) a->mUnk_4b8);
    } else {
        func_0212ec04(&b->mUnk_00, f, -1, c, d, e);
    }
}
