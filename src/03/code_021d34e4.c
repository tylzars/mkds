#include "03/code_021d34e4.h"
#include "03/code_021d1000.h"
#include "03/code_021d2e68.h"
#include "03/unk_021da000.h"
#include "03/code_021d34c8.h"
#include "code_0200c914.h"

Unk021d34e4 *func_ov003_021d34e4(u32 a, void (*b)(Unk021d34e4 *a, u32 b), u32 c, u32 d, u8 e) {
    Unk021d34e4 *f;
    Unk021d34e4 *g;
    u32 h;

    f = func_ov003_021d1cd4((Unk021d1d88 *) data_ov003_021da32c[a].mUnk_00);
    f->mUnk_08 = b;
    f->mUnk_0c = c;
    f->mUnk_10 = d;
    f->mUnk_11 = e;
    h = func_0200ca9c(1);
    g = data_ov003_021da32c[a].mUnk_0c.mUnk_04;
    while (1) {
        if (d < g->mUnk_10) {
            func_ov003_021d2e68((u32) g, (u32) f);
            break;
        }
        g = g->mUnk_04;
    }
    func_0200cae4(h);
    return f;
}
