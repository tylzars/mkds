#include "03/code_021d23b0.h"
#include "03/code_021d1000.h"
#include "03/code_021d2490.h"
#include "03/unk_021da000.h"
#include "code_020231e4.h"
#include "code_02022aa8.h"
#include "code_02023374.h"

Unk021d23b0 *func_ov003_021d23b0(u32 a, u16 b, u16 c, s32 d, u32 *e, s32 f) {
    Unk021d23b0 *g = func_ov003_021d1cd4((Unk021d1d88 *) (*(Unk021d2490 **) data_ov003_021da2c4)->mUnk_788);
    u32 h;
    u32 i;
    Unk02022aa8 *j;

    g->mUnk_36 = b;
    g->mUnk_37 = c;
    g->mUnk_30 = func_ov003_021d309c(a, b * c, d, &h);
    g->mUnk_34 = h;
    *e = func_020231e4(b, c);
    if (a == 1) {
        i = 0x6600000;
    } else {
        i = 0x6400000;
    }
    i += h << 7;
    func_02023374(g, (void *) i, b, c, 4);
    g->mUnk_18(g, 0);
    j = &(*(Unk021d2490 **) data_ov003_021da2c4)->mUnk_000[f];
    g->mUnk_20 = g;
    g->mUnk_24 = j;
    g->mUnk_28 = 1;
    g->mUnk_2c = 1;
    return g;
}
