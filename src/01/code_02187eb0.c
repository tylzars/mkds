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

Unk0206bcb0 *func_ov001_02188104(Unk02188950 *param_1, s32 param_2, s32 param_3) {
    Unk0206bcb0 *q;

    q = func_0207a974((u16) data_021759c0->mUnk_62);
    if (q != 0 && func_ov001_021881a8(param_1, (Vec3 *) &q->mUnk_80, (s32) (param_2), (s32) (param_3)) != 0 &&
        (q->mUnk_48 & 0x40) == 0) {
        return q;
    }
    return 0;
}

Unk0206bcb0 *func_ov001_02188084(Unk02188950 *param_1, s32 param_2, s32 param_3, s32 param_4) {
    Unk0206bcb0 *q;

    q = func_0207a974((u16) data_021759c0->mUnk_62);
    if (q != 0 && (q->mUnk_48 & 0x40) == 0 && (param_3 != 0 || param_4 != 0)) {
        if (param_3 == 0 || func_ov001_02188f04(param_1, &q->mUnk_80, param_3) != 0) {
            if (param_4 == 0 || func_ov001_02188eac(param_1, param_1->mUnk_184 + param_2, &q->mUnk_80, param_4) != 0) {
                return q;
            }
        }
    }
    return 0;
}

Unk0206bcb0 *func_ov001_02188000(Unk02188950 *param_1, s32 param_2, s32 param_3) {
    Unk0206bcb0 *q;

    q = func_0207a974((u16) data_021759c0->mUnk_62);
    if (q != 0 && (q->mUnk_48 & 0x40) == 0 && (param_2 != 0 || param_3 != 0)) {
        if (param_2 == 0 || func_ov001_02188f04(param_1, &q->mUnk_80, param_2) != 0) {
            if (param_3 == 0 || func_ov001_02188eac(param_1, q->mUnk_236 + 0x8000, &q->mUnk_80, param_3) != 0) {
                return q;
            }
        }
    }
    return 0;
}

Unk02042044 *func_ov001_02187fc0(Unk02188950 *param_1) {
    if (param_1->mUnk_148 < data_02175620->mUnk_0c) {
        return func_02042044((u16) (param_1->mUnk_148), (u16) (param_1->mUnk_14c));
    }
    return 0;
}

s32 func_ov001_02187f7c(Unk02188950 *param_1) {
    if (param_1->mUnk_148 < data_02175620->mUnk_0c) {
        return func_02042044((u16) (param_1->mUnk_148), (u16) (param_1->mUnk_14c))->mUnk_0e;
    }
    return 0;
}

s32 func_ov001_02187f38(Unk02188950 *param_1) {
    if (param_1->mUnk_148 < data_02175620->mUnk_0c) {
        return func_02042044((u16) (param_1->mUnk_148), (u16) (param_1->mUnk_14c))->mUnk_10;
    }
    return 0;
}

Unk02042044 *func_ov001_02187ee8(Unk02188950 *param_1) {
    Unk02175620 *g = data_02175620;
    s32 n;

    if (param_1->mUnk_148 < g->mUnk_0c) {
        n = param_1->mUnk_14c + 1;
        if (n >= g->mUnk_08[(u16) param_1->mUnk_148].mUnk_02) {
            n = 0;
        }
        return func_02042044((u16) (param_1->mUnk_148), (u16) (n));
    }
    return 0;
}

void func_ov001_02187eb0(Unk02188950 *param_1) {
    Unk02175620 *g;
    Unk02175620_08 *e;
    s32 a;
    s32 n;

    g = data_02175620;
    a = param_1->mUnk_148;
    if (a < g->mUnk_0c) {
        e = &g->mUnk_08[(u16) a];
        n = param_1->mUnk_14c - 1;
        if (n <= 0) {
            n = e->mUnk_02 - 1;
        }
        param_1->mUnk_14c = n;
    }
}
