#include "00/code_021ab728.h"
#include "00/code_021ab7e8.h"
#include "00/code_021abc04.h"
#include "code_0214d018.h"

void func_ov000_021ab728(void *f, const u8 *b, u32 c) {
    Unk021ab728 *a = f;
    u32 d;
    u32 e;
    d = (a->mUnk_10 >> 3) & 0x3f;
    a->mUnk_10 += c << 3;
    if (a->mUnk_10 < (c << 3)) {
        a->mUnk_14++;
    }
    a->mUnk_14 += c >> 29;
    e = 64 - d;
    if (c >= e) {
        MemCopy(b, &a->mUnk_18[d], e);
        d = 0;
        func_ov000_021ab7e8(a, a->mUnk_18);
        for (; e + 63 < c; e += 64) {
            func_ov000_021ab7e8(a, b + e);
        }
    } else {
        e = 0;
    }
    MemCopy(b + e, &a->mUnk_18[d], c - e);
}
