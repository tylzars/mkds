#include "Main/Unknown/code_020add90.h"
#include "code_02022aa8.h"
#include "code_0214cfe4.h"

void func_020addb8(void *a, u16 b, s32 c) {
    volatile u16 v = b;

    func_0214cfe4(v, a, c);
}

u32 func_020add90(Unk02022aa8 *a, u32 b) {
    u32 r;

    r = func_02022ce4(a, b);
    if (r == 0xffff) {
        r = a->mUnk_00->mUnk_02;
    }
    return r;
}
