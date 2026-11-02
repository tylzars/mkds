#include "Main/Unknown/code_020f81b8.h"

#include "Main/Unknown/code_020f81c0.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020bb5cc.h"
#include "Main/Unknown/code_020f82c4.h"

void func_020f82e8(s32 a) {
    data_0217bc60 = 1800;
    if (a != 0) {
        data_0217bc60 += 300;
    }
}

void func_020f82c4(s32 a) {
    data_0217bc5c = 1800;
    if (a != 0) {
        data_0217bc5c += 300;
    }
}

void func_020f82a4(s32 a) {
    data_0217bc58 = 0x384;
    if (a != 0) {
        data_0217bc58 += 0x12c;
    }
}

void func_020f8258(void) {
    if (data_0217bc60 > 0) {
        data_0217bc60 = data_0217bc60 - 1;
    }
    if (data_0217bc5c > 0) {
        data_0217bc5c = data_0217bc5c - 1;
    }
    if (data_0217bc58 > 0) {
        data_0217bc58 = data_0217bc58 - 1;
    }
}

void func_020f81c0(Unk020ee684 *a) {
    Unk0217bc48 *e;
    Unk027e00cc *v;
    enum { K0 } k, j;

    if (a->mUnk_018->mUnk_1f8 == data_021759c0->mUnk_62) {
        func_020bb5cc();
    }
    k = a->mUnk_010;
    e = &data_0217bc48[k];
    j = e->mUnk_08;
    v = &data_027e00cc[j];
    v->mUnk_1c -= e->mUnk_0c;
    a->mUnk_000 = 0;
    a->mUnk_004 = 0;
    a->mUnk_00c = 0x13;
    a->mUnk_010 = 0x13;
    a->mUnk_014 = 0x13;
    a->mUnk_020 = 0;
}

void func_020f81b8(u32 p0, u32 p1) {
    *(u32 *) ((u8 *) p0 + 20) = p1;
}
