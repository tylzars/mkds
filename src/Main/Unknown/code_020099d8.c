#include "Main/Unknown/code_020099d8.h"
#include "Main/Unknown/code_02009cc8.h"

#pragma thumb on

s32 func_02009aa8(Unk021425e8Func a, void *b, s32 c, u16 d, u16 e) {
    s32 v;
    v = func_02144048((UnkFunc *) a, NULL, b, c, e, 1, 3);
    func_02009928(0xf, v);
    return v;
}

int func_020099d8(void *a, u32 b, u32 c) {
    Unk0216fda8 *v1;
    u32 v2;
    s32 v3;
    u16 v4;
    u16 v5;
    v4 = b;
    v5 = c;
    v1 = data_0216fda8;
    if (v1->mUnk_528 == 0 || v1->mUnk_526 == 1) {
        return 1;
    }
    switch (v1->mUnk_524) {
        case 1:
            if (v1->mUnk_52c == 0) {
                v2 = 0x3e8;
            } else {
                v2 = 0;
            }
            v3 = func_02009aa8(v1->mUnk_508, a, v4, v2, v5);
            if (v3 == 2) {
                data_0216fda8->mUnk_50c = 1;
            }
            if (v3 == 2) {
                v3 = 0;
            }
            return v3;
        case 2:
            v3 = func_02009aa8(func_0200a1bc, a, v4, 0, v5);
            if (v3 == 2) {
                data_0216fda8->mUnk_50c = 1;
            }
            if (v3 == 2) {
                v3 = 0;
            }
            return v3;
        default:
            return 1;
    }
}

#pragma thumb off
