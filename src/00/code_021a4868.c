#include "00/code_021a4868.h"
#include "00/code_0218e3c4.h"
#include "00/code_0218e644.h"
#include "00/code_021a3000.h"
#include "00/unk_021b4000.h"
#include "00/code_0218e8c4.h"

void func_ov000_021a4940(Unk021a4a08 *a) {
    u8 b[8];
    s32 c;
    s32 d;
    s32 e;

    c = 8;
    if (a->mUnk_0c4 != 0 && func_ov000_0218e668(a->mUnk_000) != 0) {
        d = 0;
        do {
            e = func_ov000_0218e438(a->mUnk_000, data_ov000_021b5e50, 0xff, d, b, &c);
            if (e != ~d) {
                data_ov000_021b5e50[e] = d;
                func_ov000_021a3c14((Unk021a3a18 *) a, (s8 *) data_ov000_021b5e50, e, b);
            }
        } while (func_ov000_0218e668(a->mUnk_000) != 0);
    }
}

void func_ov000_021a4868(Unk021a4a08 *a) {
    u32 b;
    s32 c;

    b = func_ov000_0218e8c4();
    if (a->mUnk_000 != -1) {
        c = a->mUnk_0b8;
        if (c > 0 && b - a->mUnk_0ac > 10000) {
            if (c >= 4) {
                a->mUnk_0b8 = 0;
                a->mUnk_09c(5, data_ov000_021b442c, a->mUnk_10c);
                return;
            }
            func_ov000_021a3a18((Unk021a3a18 *) a, 3);
            a->mUnk_0b8 = a->mUnk_0b8 + 1;
        } else if (a->mUnk_0b4 != 0 && b - a->mUnk_0ac > 10000) {
            func_ov000_021a3a18((Unk021a3a18 *) a, 1);
        } else if (b - a->mUnk_0ac > 60000 || a->mUnk_0ac == 0 || b < a->mUnk_0ac) {
            func_ov000_021a3a18((Unk021a3a18 *) a, 0);
        }
        if (b - a->mUnk_0b0 > 20000) {
            func_ov000_021a3bbc((Unk021a3a18 *) a);
        }
    }
}
