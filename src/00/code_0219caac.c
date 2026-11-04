#include "00/code_0219caac.h"
#include "code_0214d018.h"

u32 func_ov000_0219caf4(void) {
    return data_ov000_021b5664->mUnk_20;
}

void func_ov000_0219caac(Unk021b565c *a, Unk02152500 *b, GpConnection *c, u32 d, u32 e, void (*f)(), void *g) {
    data_ov000_021b565c = a;
    MemFill(a, 0, 0x264);
    data_ov000_021b565c->mUnk_00 = c;
    data_ov000_021b565c->mUnk_04 = 0;
    data_ov000_021b565c->mUnk_08 = d;
    data_ov000_021b565c->mUnk_0c = e;
    data_ov000_021b565c->mUnk_18 = f;
    data_ov000_021b565c->mUnk_1c = g;
    data_ov000_021b565c->mUnk_20 = b;
}
