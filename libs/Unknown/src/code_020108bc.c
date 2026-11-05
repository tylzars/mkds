#include "code_020108bc.h"
#include "code_0214c1bc.h"

void func_020108bc(Unk020108bc *a, int b) {
    u32 n;
    u32 m;
    u32 v;
    u32 s;
    u8 *d;

    if (b != 0) {
        GX_BeginLoadTex();
    }
    n = a->mUnk_0c << 3;
    if (n != 0) {
        GX_LoadTex((u8 *) a + a->mUnk_14, (a->mUnk_08 & 0xffff) << 3, n);
        a->mUnk_10 |= 1;
    }
    m = a->mUnk_1c << 3;
    if (m != 0) {
        v = a->mUnk_18 & 0xffff;
        s = v << 3;
        d = (u8 *) a + a->mUnk_28;
        GX_LoadTex((u8 *) a + a->mUnk_24, s, m);
        GX_LoadTex(d, 0x20000 + (((v << 3) & 0x1ffff) >> 1) + ((s & 0x40000) >> 2), m >> 1);
        a->mUnk_20 |= 1;
    }
    if (b != 0) {
        GX_EndLoadTex();
    }
}
