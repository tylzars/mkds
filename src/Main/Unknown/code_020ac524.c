#include "Main/Unknown/code_020ac524.h"
#include "Main/Unknown/code_020ac6a8.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_02100084.h"
#include "Main/Unknown/code_021000c8.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020d2dec.h"
#include "Main/Unknown/code_020d22e0.h"

void *func_020ac658(void) {
    return (void *) func_0209bef0(func_020ac9c8, func_020ac890, func_020ac9b0);
}

void *func_020ac63c(void) {
    return (void *) func_0209bf48(0, func_020ac6a8, 0);
}

void func_020ac5e4(Unk0206bcb0 *a) {
    Unk020ac5e4 *o;

    o = func_0209bbfc(func_02100138(0x70));
    if (o == 0) {
        return;
    }
    o->mUnk_00.mUnk_04.x = 0;
    o->mUnk_00.mUnk_04.y = 0;
    o->mUnk_00.mUnk_04.z = 0;
    o->mUnk_00.mUnk_10.x = 0;
    o->mUnk_00.mUnk_10.y = 0;
    o->mUnk_00.mUnk_10.z = 0;
    o->mUnk_ac = a;
    o->mUnk_a0 = 0;
    o->mUnk_a4 = 0;
    o->mUnk_a8 = 0;
    o->mUnk_b0 = 0;
}

void func_020ac588(u32 a, s32 b, void *c) {
    s32 i;
    Unk020e71a0 *e;

    for (i = 0; i < b; i++) {
        e = func_020d34d4(c, a);
        if ((e->mUnk_02 & 0x100) == 0) {
            func_020d2398(e);
        }
    }
}

void *func_020ac524(s32 a) {
    Unk02100094 *v1;
    void **v2;
    s32 n;
    s32 i;
    Unk020e71a0 *e;

    v1 = func_02100138(a);
    v2 = func_0210008c(v1);
    n = func_021000c8(v1);
    for (i = 0; i < n; i++) {
        e = v2[i];
        if (e->mUnk_02 & 0x100) {
            return e;
        }
    }
    return 0;
}
