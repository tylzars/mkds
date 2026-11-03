#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0210b870.h"

#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_0210bad4.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_0212bcac.h"

void func_0210ba78(void *p0, s32 b) {
    Unk0206bcb0 *p;
    s32 c;

    p = p0;
    c = *(s32 *) data_0217ccac;
    func_021090c4(&p->mUnk_00, b + c, (0x7f - (c >> 1)) & 0xff, 0);
    *(u32 *) data_0217ccac = *(u32 *) (u32) data_0217ccac + 0xa;
}

void func_0210ba38(struct Unk020e71a0_94 *p, s32 b) {
    func_0210ddf4(&data_0217d29c, p->mUnk_00.mUnk_40 + 0x15f90, (void (*)(void *, int)) func_0210bad4, p, b);
}

void func_0210b98c(struct Unk020e71a0_94 *p, s32 b) {
    s32 c;

    c = 0;
    switch (b - 0x130) {
        case 0:
            c = 0x640;
            break;
        case 1:
            c = 0x1900;
            break;
        case 2:
            c = 0x3840;
            break;
        case 8:
            c = 0x6400;
            break;
        case 9:
            c = 0xe100;
            break;
        case 3:
            c = 0x9c40;
            break;
        case 7:
            c = 0x19;
            break;
    }
    func_0210ddf4(&data_0217d29c, p->mUnk_00.mUnk_40 + c, func_0210ba78, p, b);
}

void func_0210b924(void *p, s32 b) {
    Unk0216ca48 v;
    Unk0216ca48 *q;

    q = &v;
    *q = data_0216ca48;
    q->mUnk_04 = p;
    q->mUnk_0c = b;
    if (data_0217c780 & 1) {
        func_0210bf24(0, q->mUnk_00, (u32) q->mUnk_04, (u32) q);
    }
}

void func_0210b8f4(void *p, s32 b) {
    func_0210ddf4(&data_0217d29c, b, func_0210b924, p, b);
}

int func_0210b8bc(void *p, s32 b) {
    s32 c;

    c = b >> 12;
    if (c > 0x1e) {
        c = 0x1e;
    }
    return (s32) func_021090c4(p, 0x1ce, ((c * 2) + 0x3c) & 0xff, c - 0xa);
}

void func_0210b874(struct Unk020e71a0_94 *p, s32 b) {
    s32 c;
    Unk0212c400 **v;

    c = (b >> 12) + 5;
    v = (Unk0212c400 **) func_02109078(&p->mUnk_00, 0x1cd, 0x7f, (s16) c);
    if (v != NULL) {
        func_0212c4c4(v, 0xffff, c);
    }
}

void func_0210b870(void) {}
