#include "00/code_0218a918.h"
#include "00/code_0218a000.h"
#include "00/code_0218a9bc.h"
#include "00/code_0218acf4.h"
#include "00/code_0218aea4.h"
#include "00/code_0218ae68.h"

void func_ov000_0218a98c(Unk0218a9bc *a) {
    SbServer *v1;
    while ((a->mUnk_08.mUnk_08 < a->mUnk_04 && (0 < a->mUnk_14.mUnk_08))) {
        v1 = func_ov000_0218aea4(&a->mUnk_14);
        func_ov000_0218ad44(a, v1);
    }
}

void func_ov000_0218a950(Unk0218b668 *a) {
    if (a->mUnk_000.mUnk_08.mUnk_08 != 0) {
        func_ov000_0218aa14(&a->mUnk_000, 0);
        func_ov000_0218a9bc(&a->mUnk_000);
        if (0 < a->mUnk_000.mUnk_14.mUnk_08) {
            func_ov000_0218a98c(&a->mUnk_000);
        }
        if (a->mUnk_000.mUnk_08.mUnk_08 == 0) {
            a->mUnk_000.mUnk_44(a, 2, 0, a->mUnk_000.mUnk_48);
        }
    }
}

void func_ov000_0218a93c(Unk0218a9bc *a, u8 b) {
    int v1;
    v1 = a->mUnk_40;
    if (v1 < 0x14) {
        a->mUnk_40 = v1 + 1;
        a->mUnk_2c[v1] = b;
    }
}

void func_ov000_0218a918(Unk0218b668 *a, SbServer *b) {
    int v1;
    v1 = func_ov000_0218ae68(&a->mUnk_000.mUnk_08, b);
    if (v1 == 0) {
        func_ov000_0218ae68(&a->mUnk_000.mUnk_14, b);
    }
}
