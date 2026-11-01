#include "Main/Unknown/code_02067cb0.h"
#include "Main/Unknown/code_0208b748.h"
#include "Main/Unknown/code_02081e3c.h"
#include "Main/Unknown/code_02081120.h"
#include "Main/Unknown/code_020ed5c0.h"

int func_02067ec4(Unk0206bcb0 *p, s32 *a, Unk020e71a0 *c) {
    if (p->mUnk_2a4 > 0x3000 || (c->mUnk_02 & 0x200)) {
        if (func_0206bcb0(p, 1, 0)) {
            if (p->mUnk_590->mUnk_058 == 0) {
                func_0208b7bc(0xc, &p->mUnk_80);
                func_0208b7bc(0xd, &p->mUnk_80);
                func_0208b7bc(0xe, &p->mUnk_80);
            }
            if (p->mUnk_7c & 1) {
                func_0207a6b0()->mUnk_14++;
            }
        }
        *a = 3;
    } else {
        *a = 2;
    }
    return 0xb;
}

int func_02067e10(Unk0206bcb0 *p, s32 *a, Unk020e71a0 *c) {
    if (p->mUnk_2a4 > 0x3000 || (c->mUnk_02 & 0x200)) {
        if (func_0206bcb0(p, 2, 0)) {
            if (p->mUnk_590->mUnk_058 == 0) {
                func_0208b7bc(0xc, &p->mUnk_80);
                func_0208b7bc(0xd, &p->mUnk_80);
                func_0208b7bc(0xe, &p->mUnk_80);
            }
            if (p->mUnk_7c & 1) {
                func_0207a6b0()->mUnk_14++;
            }
        }
        *a = 4;
    } else {
        *a = 2;
    }
    return 0xb;
}

int func_02067d88(Unk0206bcb0 *p, s32 *a, Unk020e71a0 *c) {
    if (p->mUnk_2a4 > 0x3000 || (c->mUnk_02 & 0x200)) {
        if (func_0206bcb0(p, 2, 0)) {
            if (p->mUnk_7c & 1) {
                func_0207a6b0()->mUnk_14++;
            }
            func_020812d0(p->mUnk_74);
        }
        *a = 4;
    } else {
        *a = 0;
    }
    return 0;
}

int func_02067d0c(Unk0206bcb0 *p, s32 *a) {
    if (func_0206bcb0(p, 2, 0)) {
        if (p->mUnk_7c & 0x10) {
            func_02081e3c(func_0208b7bc(0x4f, &p->mUnk_80), p->mUnk_74, 0x46);
        }
        if (p->mUnk_7c & 1) {
            func_0207a6b0()->mUnk_14++;
        }
    }
    *a = 5;
    return 0;
}

int func_02067cb0(Unk0206bcb0 *p, s32 *a) {
    if (func_0206b4d0(p)) {
        if (p->mUnk_7c & 1) {
            func_0207a6b0()->mUnk_14++;
        }
        p->mUnk_48 |= 0x20000;
    }
    *a = 7;
    return 2;
}
