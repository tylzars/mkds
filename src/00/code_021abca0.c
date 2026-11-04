#include "00/code_021abca0.h"
#include "00/code_021abc04.h"
#include "00/code_021abd68.h"
#include "code_0214d018.h"

void func_ov000_021abca0(void *f, const u8 *b, u32 c) {
    Unk021abca0 *a = f;
    u32 d;
    u32 e;
    d = (a->mUnk_18 >> 3) & 0x3f;
    a->mUnk_18 += c << 3;
    if (a->mUnk_18 < (c << 3)) {
        a->mUnk_14++;
    }
    a->mUnk_14 += c >> 29;
    e = 64 - d;
    if (c >= e) {
        MemCopy(b, &a->mUnk_1c[d], e);
        d = 0;
        func_ov000_021abd68(a, a->mUnk_1c);
        for (; e + 63 < c; e += 64) {
            func_ov000_021abd68(a, b + e);
        }
    } else {
        e = 0;
    }
    MemCopy(b + e, &a->mUnk_1c[d], c - e);
}
