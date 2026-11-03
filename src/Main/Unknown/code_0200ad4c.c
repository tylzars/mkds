#include "Main/Unknown/code_0200ad4c.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200fc8c.h"
#include "code_0200fd1c.h"
#include "code_0214d018.h"

#pragma thumb on

void func_0200ae60(Unk0200adfc *a, u32 b, u32 c, u32 d, u32 e) {
    u32 v1;
    Unk0200adfc_30 *v2;
    v1 = func_0200fca0();
    v2 = a->mUnk_30;
    for (;;) {
        if (v2 >= a->mUnk_30 + 4) {
            func_0200fd1c();
        }
        if (v2->mUnk_0c == 0) {
            v2->mUnk_00 = b;
            v2->mUnk_04 = c;
            v2->mUnk_08 = (u8 *) d;
            v2->mUnk_0c = e;
            break;
        }
        v2++;
    }
    func_0200fcb4(v1);
}

u32 func_0200adfc(Unk0200adfc *a, u32 b, void *c, u32 d) {
    u32 v1;
    u32 v2;
    Unk0200adfc_30 *v3;
    s32 v4;
    v2 = 0;
    v1 = func_0200fca0();
    for (v3 = a->mUnk_30; v3 < a->mUnk_30 + 4; v3++) {
        if (v3->mUnk_0c >= 2) {
            v4 = b - v3->mUnk_00;
            if (v4 >= 0 && v4 + d <= v3->mUnk_04) {
                func_0214d1fc(v3->mUnk_08 + v4, c, d);
                v2 = 1;
                a->mUnk_00 = v2;
                break;
            }
        }
    }
    func_0200fcb4(v1);
    return v2;
}

u32 func_0200ada4(Unk02143a78 *a) {
    u16 v3;
    u16 i;
    u16 v2;
    u32 v1;
    v1 = func_02143280();
    if (v1 == 0) {
        return 0;
    }
    i = 0;
    v2 = a->mUnk_04;
    v3 = v2;
    for (; i < 16;) {
        if ((v1 & (1 << (v3 - 1))) != 0 && v2 != v3) {
            a->mUnk_04 = v3;
            break;
        }
        i++;
        v3 = v3 == 16 ? 1 : v3 + 1;
    }
    return 1;
}

u32 func_0200ad4c(void) {
    u32 v1;
    u32 v2;
    u32 v3;
    Unk0216fda8 *v4;
    v1 = 0;
    v2 = 0;
    v3 = 0;
    v4 = data_0216fda8;
    if (v4->mUnk_528 == 1) {
        if (v4->mUnk_50c == 0) {
            v3 = 1;
        }
    }
    if (v3 != 0) {
        if (v4->mUnk_526 == 0) {
            v2 = 1;
        }
    }
    if (v2 != 0) {
        if (v4->mUnk_52a != 0) {
            v1 = 1;
        }
    }
    return v1;
}

#pragma thumb off
