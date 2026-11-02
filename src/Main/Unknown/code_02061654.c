#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"

void func_02061860(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217aa2c;
    value1 = 0u;
    *(u16 *) ((value0) + (0)) = (u16) value1;
}

void func_0206184c(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217aa2c;
    value1 = 0x48u;
    *(u16 *) ((value0) + (0)) = (u16) value1;
}

u32 func_0206183c(void) {
    return ((u32) data_0217aa64);
}

Unk02012f58 *func_0206182c(void) {
    return data_0217aa7c;
}

u32 func_02061818(void) {
    return ((u32) data_0217aa6c->mUnk_250);
}

void *func_02061808(void) {
    return (void *) ((u32) data_0217aa6c);
}

u32 func_020617f0(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217aa54;
    value1 = 1u;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    *(u32 *) ((value0) + (52)) = value1;
    return value0;
}

u32 func_020617d8(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217aa54;
    value1 = (u32) * (const u32 *) ((value0) + (0));
    value0 = (u32) * (const u32 *) ((value1) + (4));
    *(u32 *) ((value1) + (60)) = value0;
    return value0;
}

s32 func_020617a8(u32 *a) {
    Unk0217aa54 *b;
    s32 c;

    b = data_0217aa54;
    c = 0;
    if (b->mUnk_3c != 0) {
        c = 1;
        *a = b->mUnk_04 - b->mUnk_3c;
    }
    return c;
}

s32 func_02061788(void) {
    if (data_021759c0->mUnk_08 == 4) {
        return 0x2e;
    }
    return 0x1f;
}

u16 func_02061768(void) {
    if (data_021759c0->mUnk_08 == 4) {
        return 0x2d;
    }
    return 0x1e;
}

s32 func_0206174c(void *v) {
    Unk0217aa08_14 *a = v;

    if (a->mUnk_08_0 == 1) {
        return 1;
    }
    return 0;
}

s32 func_02061704(void *v, Unk02056bc0 *b) {
    Unk0217aa08_14 *a = v;

    if (a->mUnk_08_0 != 1) {
        return 0;
    }
    b->mUnk_02 = a->mUnk_08_8;
    b->mUnk_03 = a->mUnk_08_15;
    b->mUnk_00 = a->mUnk_08_22;
    return 1;
}

s32 func_020616c0(void *v, void *b) {
    Unk0217aa08_14 *a = v;

    if (a->mUnk_08_0 != 1) {
        return 0;
    }
    func_0214d1fc(a->mUnk_0c, b, 0x14);
    return 1;
}

s32 func_0206169c(void *v) {
    Unk0217aa08_14 *a = v;

    if (a->mUnk_08_0 != 1) {
        return -1;
    }
    return a->mUnk_04_0;
}

s32 func_02061678(void *v) {
    Unk0217aa08_14 *a = v;

    if (a->mUnk_08_0 != 1) {
        return -1;
    }
    return a->mUnk_04_4;
}

u32 func_02061654(void *v) {
    Unk0217aa08_14 *a = v;

    if (a->mUnk_08_0 != 1) {
        return 0;
    }
    return a->mUnk_04_10;
}
