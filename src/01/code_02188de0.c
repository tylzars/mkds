#include "01/code_02188de0.h"
#include "01/code_0218c000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020a3000.h"

void func_ov001_02188de0(Unk02188950 *a, s32 b, s32 c, Vec3 *d, UnkFunc *e) {
    UnkFunc *cb;

    a->mUnk_1f8 = b;
    a->mUnk_1fc = c;
    if (d != 0) {
        a->mUnk_200 = *d;
    }
    cb = e;
    if (cb == 0) {
        cb = func_ov001_02188e88;
    }
    a->mUnk_20c = cb;
}
