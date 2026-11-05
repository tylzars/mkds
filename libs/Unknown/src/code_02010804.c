#include "code_02010804.h"
#include "code_0214c1bc.h"

void func_02010870(Unk02010804 *a, u32 b) {
    a->mUnk_2c = b;
}

void func_02010804(Unk02010804 *a, int b) {
    if (b != 0) {
        GX_BeginLoadTexPltt();
    }
    GX_LoadTexPltt((u8 *) a + a->mUnk_38, (a->mUnk_2c & 0xffff) << 3, a->mUnk_30 << 3);
    a->mUnk_32 |= 1;
    if (b != 0) {
        GX_EndLoadTexPltt();
    }
}
