#include "01/code_02188cd8.h"
#include "01/code_0219b1c4.h"
#include "01/code_0218c000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020a3000.h"

void func_ov001_02188d8c(Unk02188950 *a, Vec3 *b) {
    if (b != 0) {
        a->mUnk_200 = *b;
    }
}

void func_ov001_02188d64(Unk02188950 *a, s32 b, s32 c) {
    func_ov001_0219b208(a->mUnk_304, (u16) b, c, 0);
    a->mUnk_1d4 = 0;
}

void func_ov001_02188d30(Unk02188950 *a, s32 b, s32 c, UnkFunc *d) {
    func_ov001_0219b208(a->mUnk_304, (u16) b, c, 1);
    if (d == 0) {
        d = func_ov001_02188e88;
    }
    a->mUnk_1d4 = d;
}

void func_ov001_02188d1c(Unk02188950 *a, s32 b, s32 c) {
    a->mUnk_16c = b;
    a->mUnk_170 = c;
}

void func_ov001_02188d08(Unk02188950 *a, s32 b, s32 c) {
    a->mUnk_160 = b;
    a->mUnk_164 = c;
}

void func_ov001_02188cec(Unk02188950 *a, s32 b) {
    a->mUnk_174 = b;
    a->mUnk_178 = 0;
    a->mUnk_17c = 0;
}

void func_ov001_02188cd8(Unk02188950 *a, s32 b, s32 c) {
    a->mUnk_178 = b;
    a->mUnk_17c = c;
}
