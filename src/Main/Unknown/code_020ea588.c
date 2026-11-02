#include "Main/Unknown/code_020ea588.h"

#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020e6000.h"

void func_020ea5b0(Unk020e6488 *a, u32 b, Vec3 *c) {
    Vec3 v;

    if (c != 0) {
        v.x = c->x >> 4;
        v.y = c->y >> 4;
        v.z = c->z >> 4;
        func_020e6854(a, &v, 1, b);
    } else {
        func_020e6854(a, 0, 0, b);
    }
}

#pragma thumb on

void func_020ea588(void **a, void *b, void *c) {
    *a = func_02036bec(func_020364e0(func_020364e8()), 0x6c);
    func_02084e28(*a, b);
}

#pragma thumb off
