#include "01/code_02187eb0.h"
#include "01/code_02188158.h"
#include "01/code_02188e88.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "01/unk_021a7000.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_02042000.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_020da000.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/code_020fd000.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/code_02042044.h"

Unk0206bcb0 *func_ov001_02188104(Unk02188950 *a, s32 b, s32 c) {
    Unk0206bcb0 *q;

    q = func_0207a974((u16) data_021759c0->mUnk_62);
    if (q != 0 && func_ov001_021881a8(a, (Vec3 *) &q->mUnk_80, (s32) (b), (s32) (c)) != 0 && (q->mUnk_48 & 0x40) == 0) {
        return q;
    }
    return 0;
}

Unk0206bcb0 *func_ov001_02188084(Unk02188950 *a, s32 b, s32 c, s32 d) {
    Unk0206bcb0 *q;

    q = func_0207a974((u16) data_021759c0->mUnk_62);
    if (q != 0 && (q->mUnk_48 & 0x40) == 0 && (c != 0 || d != 0)) {
        if (c == 0 || func_ov001_02188f04(a, &q->mUnk_80, c) != 0) {
            if (d == 0 || func_ov001_02188eac(a, a->mUnk_184 + b, &q->mUnk_80, d) != 0) {
                return q;
            }
        }
    }
    return 0;
}

Unk0206bcb0 *func_ov001_02188000(Unk02188950 *a, s32 b, s32 c) {
    Unk0206bcb0 *q;

    q = func_0207a974((u16) data_021759c0->mUnk_62);
    if (q != 0 && (q->mUnk_48 & 0x40) == 0 && (b != 0 || c != 0)) {
        if (b == 0 || func_ov001_02188f04(a, &q->mUnk_80, b) != 0) {
            if (c == 0 || func_ov001_02188eac(a, q->mUnk_236 + 0x8000, &q->mUnk_80, c) != 0) {
                return q;
            }
        }
    }
    return 0;
}

Unk02042044 *func_ov001_02187fc0(Unk02188950 *a) {
    if (a->mUnk_148 < data_02175620->mUnk_0c) {
        return func_02042044((u16) (a->mUnk_148), (u16) (a->mUnk_14c));
    }
    return 0;
}

s32 func_ov001_02187f7c(Unk02188950 *a) {
    if (a->mUnk_148 < data_02175620->mUnk_0c) {
        return func_02042044((u16) (a->mUnk_148), (u16) (a->mUnk_14c))->mUnk_0e;
    }
    return 0;
}

s32 func_ov001_02187f38(Unk02188950 *a) {
    if (a->mUnk_148 < data_02175620->mUnk_0c) {
        return func_02042044((u16) (a->mUnk_148), (u16) (a->mUnk_14c))->mUnk_10;
    }
    return 0;
}

Unk02042044 *func_ov001_02187ee8(Unk02188950 *a) {
    Unk02175620 *g = data_02175620;
    s32 n;

    if (a->mUnk_148 < g->mUnk_0c) {
        n = a->mUnk_14c + 1;
        if (n >= g->mUnk_08[(u16) a->mUnk_148].mUnk_02) {
            n = 0;
        }
        return func_02042044((u16) (a->mUnk_148), (u16) (n));
    }
    return 0;
}

void func_ov001_02187eb0(Unk02188950 *b) {
    Unk02175620 *g;
    Unk02175620_08 *e;
    s32 a;
    s32 n;

    g = data_02175620;
    a = b->mUnk_148;
    if (a < g->mUnk_0c) {
        e = &g->mUnk_08[(u16) a];
        n = b->mUnk_14c - 1;
        if (n <= 0) {
            n = e->mUnk_02 - 1;
        }
        b->mUnk_14c = n;
    }
}
