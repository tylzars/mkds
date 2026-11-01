#include "03/code_021b7d04.h"
#include "00/code_021a8b20.h"
#include "00/code_021a9018.h"
#include "00/code_021a90a0.h"

s32 func_ov003_021b7d68(s32 v1, void *v2, s32 v3, s32 v4, Unk021b7cec *v5, s32 *v6) {
    v5->mUnk_00 = *v6;
    return func_ov000_021a90a0(v1, v2, v3, v4, v5);
}

s32 func_ov003_021b7d1c(s32 v1, Unk021b7ba0 *v2, void *v3, void *v4, Unk021b7d1c *v5) {
    Unk021b7ba0 t;
    s64 s;
    s = 0;
    t = *v2;
    s += v5->mUnk_00 * 0x1ff6210 / 0x40;
    s += v5->mUnk_04 * 0x1ff6210 / 0x40;
    return func_ov000_021a8b20(&t, 1, s);
}

s32 func_ov003_021b7d04(s32 a, void *b, s32 c, s32 d, Unk021b7cec *e, u32 f) {
    e->mUnk_00 = f;
    return func_ov000_021a9018(a, b, c, d, e);
}
