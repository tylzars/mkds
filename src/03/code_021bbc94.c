#include "03/code_021bbc94.h"
#include "03/code_021bb3a4.h"
#include "03/code_021bb3bc.h"
#include "03/code_021bb408.h"
#include "03/code_021bb438.h"

void func_ov003_021bbcf0(Unk021bbd70 *a, const u8 *b, u32 c) {
    u32 i;
    u32 d;
    u32 e;
    d = (a->mUnk_10 >> 3) & 0x3f;
    a->mUnk_10 += c << 3;
    if (a->mUnk_10 < (c << 3)) {
        a->mUnk_14++;
    }
    a->mUnk_14 += c >> 29;
    e = 0x40 - d;
    if (c >= e) {
        func_ov003_021bb3bc(a->mUnk_18 + d, b, e);
        func_ov003_021bb438(a, a->mUnk_18);
        for (i = e; i + 63 < c; i += 64) {
            func_ov003_021bb438(a, b + i);
        }
        d = 0;
    } else {
        i = 0;
    }
    func_ov003_021bb3bc(a->mUnk_18 + d, b + i, c - i);
}

void func_ov003_021bbc94(u8 *a, Unk021bbd70 *b) {
    u8 c[8];
    u32 i;
    u32 d;
    func_ov003_021bb408(c, &b->mUnk_10, 8);
    i = (b->mUnk_10 >> 3) & 0x3f;
    if (i < 0x38) {
        d = 0x38 - i;
    } else {
        d = 0x78 - i;
    }
    func_ov003_021bbcf0(b, data_ov003_021d68dc, d);
    func_ov003_021bbcf0(b, c, 8);
    func_ov003_021bb408(a, b->mUnk_00, 0x10);
    func_ov003_021bb3a4(b, 0, 0x58);
}
