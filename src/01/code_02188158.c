#include "01/code_02188158.h"

void func_ov001_02188200(Unk02188950 *a, UnkFunc *b) {
    a->mUnk_2d4 = b;
    return;
}

void func_ov001_021881f4(Unk02188950 *a, UnkFunc *b) {
    a->mUnk_2dc = b;
}

BOOL func_ov001_021881a8(Unk02188950 *a, Vec3 *b, s32 c, s32 d) {
    if ((c != 0 || d != 0) && (c == 0 || func_ov001_02188f04(a, b, c) != 0) &&
        (d == 0 || func_ov001_02188eac(a, a->mUnk_1a8, b, d) != 0)) {
        return TRUE;
    }
    return FALSE;
}

int func_ov001_02188158(Unk02188950 *a, u32 b, u32 c) {
    int v1;
    int v2;
    int v3;
    int v4;
    v1 = func_020fd7f0();
    v4 = 0;
    if (0 < v1) {
        do {
            v2 = func_020fd7a4(v4);
            if ((v2 != 0) && (v3 = func_ov001_021881a8(a, (Vec3 *) (v2 + 0x50), (s32) (b), (s32) (c)), v3 != 0)) {
                return v2;
            }
            v4 = v4 + 1;
        } while (v4 < v1);
    }
    return 0;
}
