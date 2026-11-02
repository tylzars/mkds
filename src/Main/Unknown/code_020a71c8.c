#include "Main/Unknown/code_020a71c8.h"

#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_020a49d4.h"
#include "Main/Unknown/code_020a73b0.h"
#include "Main/Unknown/code_020a7eb0.h"
#include "Main/Unknown/code_020a7eb4.h"
#include "Main/Unknown/code_020d22e0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020a737c.h"

void func_020a737c(void) {
    func_0209bfa8(&func_020a7fc4, &func_020a7f18, 0, (u32) 1, (u16) 1);
}

u32 func_020a7358(void) {
    return func_0209bef0(CreateSanboHAndSanboB, func_020a79c4, func_020a7eb0);
}

u32 func_020a7338(void) {
    return func_0209bf48(func_020a78c8, func_020a73b0, 0);
}

s32 func_020a72c8(u16 a, u16 b) {
    if (func_020a1154(a) != 0) {
        func_020a10f0(a, -1);
        if (b >= 8) {
            b = a;
        }
        func_020a5608(func_0207a974(a), func_0207a974(b));
        return 1;
    }
    return 0;
}

void func_020a7270(u16 a) {
    if (func_020a1154(a) == 0) {
        return;
    }
    func_020a10f0(a, -1);
    func_020a5608(func_0207a974(a), func_0207a974(a));
}

void func_020a71c8(void) {
    s32 i;
    Unk020e71a0 *o;
    Unk020e6fd4 *l;

    l = func_02100138(0x6b);
    if (l != 0) {
        for (i = 0; i < l->mUnk_04 && (o = l->mUnk_00[i]) != 0; i++) {
            if ((o->mUnk_02 & 0x100) == 0) {
                func_020d2398(o);
            }
        }
    }
    l = func_02100138(0x70);
    if (l != 0) {
        for (i = 0; i < l->mUnk_04 && (o = l->mUnk_00[i]) != 0; i++) {
            if ((o->mUnk_02 & 0x100) == 0) {
                func_020d2398(o);
            }
        }
    }
    func_020a5848();
}
