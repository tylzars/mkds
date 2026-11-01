#include "00/code_021a9018.h"
#include "00/code_021a8db8.h"
#include "00/code_021a911c.h"
#include "00/code_021a7bfc.h"

s32 func_ov000_021a9018(s32 v1, void *v2, s32 v3, s32 v4, void *v5) {
    Unk021a8e18 *a = v5;
    u16 b;
    u32 c;
    if (a != 0) {
        b = ((a->mUnk_02 >> 8) & 0xff) | ((a->mUnk_02 << 8) & 0xff00);
        c = ((a->mUnk_04 << 24) & 0xff000000) |
            (((a->mUnk_04 << 8) & 0xff0000) | (((a->mUnk_04 >> 24) & 0xff) | ((a->mUnk_04 >> 8) & 0xff00)));
    } else {
        b = 0;
        c = 0;
    }
    return func_ov000_021a8268(v1, (u32) v2, v3, b, c, v4);
}
