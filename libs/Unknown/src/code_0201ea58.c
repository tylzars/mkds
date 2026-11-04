#include "code_0201ea58.h"

s32 func_0201ebe8(Unk0201ea84 a, s32 b) {
    s32 v;

    v = a.mUnk_00_0;
    switch (a.mUnk_00_12) {
        case 1:
            v -= (b + 1) / 2;
            break;
        case 2:
            v -= b;
            break;
    }
    return v;
}

s32 func_0201eba0(Unk0201ea84 a, s32 b) {
    s32 v;

    v = a.mUnk_00_0;
    switch (a.mUnk_00_12) {
        case 1:
            v -= (b + 1) / 2;
            break;
        case 2:
            v -= b;
            break;
    }
    return v;
}

u16 func_0201eb98(Unk0201ea30 *a) {
    return a->mUnk_06;
}

Unk0201eb54 *RectTableGetEntry(Unk0201ea30 *a, s32 b) {
    Unk0201eb54 *p;

    p = (Unk0201eb54 *) (a + 1);
    if (b < 0 || b >= func_0201eb98(a)) {
        return 0;
    }
    return p + b;
}

s32 RectTableFindContaining(Unk0201ea30 *a, s32 b, s32 c) {
    s32 i;
    Unk0201eb54 *p;
    s32 x;
    s32 y;
    s32 x2;
    s32 y2;

    p = (Unk0201eb54 *) (a + 1);
    for (i = 0; i < func_0201eb98(a); i++) {
        x = func_0201ebe8(p->mUnk_00, p->mUnk_04);
        y = func_0201eba0(p->mUnk_02, p->mUnk_05);
        x2 = x + p->mUnk_04;
        y2 = y + p->mUnk_05;
        if (x <= b && b <= x2 && y <= c && c <= y2) {
            return i;
        }
        p++;
    }
    return -1;
}

void *func_0201ea58(Unk0201ea30 *a, s32 b) {
    u8 *p;
    s32 n;

    p = (u8 *) (a + 1);
    n = a->mUnk_06;
    if (b < 0 || b >= n) {
        return 0;
    }
    return p + b * 12;
}
