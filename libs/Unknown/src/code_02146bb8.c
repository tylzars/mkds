#include "code_02146bb8.h"
#include "registers.h"

void func_02146c24(Unk02146bb8 *a) {
    a->mUnk_00 = reg_CP_DIV_NUMER;
    a->mUnk_08 = reg_CP_DIV_DENOM;
    a->mUnk_18 = reg_CP_DIVCNT & 3;
    a->mUnk_10 = *(vu64 *) 0x040002B8;
    a->mUnk_1a = reg_CP_SQRTCNT & 1;
}

void func_02146bb8(const Unk02146bb8 *a) {
    reg_CP_DIV_NUMER = a->mUnk_00;
    reg_CP_DIV_DENOM = a->mUnk_08;
    reg_CP_DIVCNT = a->mUnk_18;
    *(vu64 *) 0x040002B8 = a->mUnk_10;
    reg_CP_SQRTCNT = a->mUnk_1a;
}
