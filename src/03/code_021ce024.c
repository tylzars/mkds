#include "03/code_021ce024.h"
#include "03/code_021cdcf0.h"
#include "03/code_021cdd48.h"
#include "03/code_021d1000.h"
#include "03/code_021d1970.h"
#include "03/code_021d3544.h"

// non-matching: original keeps a second zero in r5 for the object offset (movs r5, #0; str r5, [sp, #4]) and steps r5,
// r6, r7 before the counter at [sp, #4]; ours loads r5 from [sp, #4] each pass, 0xa4 bytes against 0xa0
void func_ov003_021ce024(u32 a) {
    s32 i;
    u8 *b;
    u8 *c;
    Unk021cdd48_66a8 *d;
    i = 0;
    b = data_ov003_021d6688 + a * 5;
    d = data_ov003_021d66a8;
    c = data_ov003_021d6698 + a * 5;
    for (; i < 5; i += 2) {
        func_ov003_021d1c3c(1, *b, (u8 *) func_ov003_021d1974((int) data_ov003_021da27c->mUnk_00[i], 0));
        func_ov003_021d1790(data_ov003_021da27c->mUnk_00[i], -1, 0);
        func_ov003_021d17d4(data_ov003_021da27c->mUnk_00[i], -1, d->mUnk_00, d->mUnk_02);
        func_ov003_021d1890(data_ov003_021da27c->mUnk_00[i], -1, 0, *c);
        b += 2;
        d += 2;
        c += 2;
    }
    func_ov003_021cdcf0(a);
}

void func_ov003_021ce0c4(void) {
    data_ov003_021da27c->mUnk_18 = 1;
    data_ov003_021da27c->mTask = func_ov003_021d3544(0, (u32) func_ov003_021cdf98, 0, 0x78);
}
