#include "Main/Unknown/code_02090088.h"
#include "Main/Unknown/code_0207c000.h"
#include "Main/Unknown/code_0208537c.h"

void func_02090088(Unk0208fd8c *a, Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    s32 v;

    if (func_0207c078(a) != 0) {
        r = func_0208537c();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (s16) (u16) (r->mUnk_00 >> 52);
        if (v < 0xb33) {
            func_0207c548(a, b);
        } else {
            func_0207c47c(a, b);
        }
    } else {
        if (b->mUnk_b0 == NULL) {
            return;
        }
        if (b->mUnk_b8 >= 0x15f90) {
            return;
        }
        if (b->mUnk_b4 != 0 && b->mUnk_bc > 0xb33) {
            func_0207c548(a, b);
        } else {
            func_0207c47c(a, b);
        }
    }
}
