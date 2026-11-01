#include "01/code_0218d520.h"
#include "01/code_02187000.h"
#include "01/code_02187e78.h"
#include "01/code_021874c4.h"
#include "01/code_02188000.h"
#include "01/code_02188158.h"
#include "01/code_02188218.h"
#include "01/code_02188e24.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02100000.h"
#include "Main/Unknown/unk_021759c0.h"

void func_ov001_0218dc20(Unk02188950 *param_1) {
    Unk0218dabc *r7 = param_1->mUnk_0a4;
    int r5;
    u16 ang = (u16) (r7->mUnk_184 + 0x8000);
    int idx;

    switch (param_1->mUnk_0a8) {
        case 1:
            r5 = param_1->mUnk_0a0->mUnk_0c0;
            break;
        case 2:
            r5 = param_1->mUnk_0a0->mUnk_0c4;
            break;
        case 3:
            r5 = param_1->mUnk_0a0->mUnk_0c8;
            break;
        case 4:
            r5 = param_1->mUnk_0a0->mUnk_0cc;
            break;
    }
    idx = (ang >> 4) * 2;
    param_1->mUnk_000.mUnk_04.x = r7->mUnk_004 + (s32) (((s64) r5 * data_0215d4b4[idx]) >> 12);
    param_1->mUnk_000.mUnk_04.z = param_1->mUnk_0a4->mUnk_00c + (s32) (((s64) r5 * data_0215d4b4[idx + 1]) >> 12);
}

void func_ov001_0218dba8(Unk02188950 *param_1) {
    int diff;
    int step;
    int limit;
    s32 cur;

    param_1->mUnk_13c = param_1->mUnk_13c - 1;
    if (param_1->mUnk_13c <= 0) {
        param_1->mUnk_13c = 0;
        cur = param_1->mUnk_184;
        diff = (u16) (param_1->mUnk_0a4->mUnk_184 - cur);
        if (diff > 0x8000) {
            diff -= 0x10000;
        }
        limit = param_1->mUnk_194;
        step = diff < -limit ? -limit : (diff > limit ? limit : diff);
        param_1->mUnk_184 = (u16) (cur + step);
        param_1->mUnk_1a8 = param_1->mUnk_184;
    }
}

void func_ov001_0218dadc(Unk02188950 *param_1) {
    Unk0218dabc *r7 = param_1->mUnk_0a4;
    int r5;
    u16 ang = (u16) (r7->mUnk_184 + 0x8000);
    int idx;

    switch (param_1->mUnk_0a8) {
        case 1:
            r5 = param_1->mUnk_0a0->mUnk_0c0;
            break;
        case 2:
            r5 = param_1->mUnk_0a0->mUnk_0c4;
            break;
        case 3:
            r5 = param_1->mUnk_0a0->mUnk_0c8;
            break;
        case 4:
            r5 = param_1->mUnk_0a0->mUnk_0cc;
            break;
    }
    idx = (ang >> 4) * 2;
    param_1->mUnk_000.mUnk_04.x = r7->mUnk_004 + (s32) (((s64) r5 * data_0215d4b4[idx]) >> 12);
    param_1->mUnk_000.mUnk_04.y = param_1->mUnk_0a4->mUnk_008;
    param_1->mUnk_000.mUnk_04.z = param_1->mUnk_0a4->mUnk_00c + (s32) (((s64) r5 * data_0215d4b4[idx + 1]) >> 12);
}

void func_ov001_0218dabc(Unk02188950 *param_1) {
    param_1->mUnk_184 = param_1->mUnk_0a4->mUnk_184;
    param_1->mUnk_1a8 = param_1->mUnk_184;
}

void func_ov001_0218da1c(Unk02188950 *param_1) {
    func_ov001_02187af4(param_1);
    func_ov001_021875c0(param_1, 0, param_1->mUnk_248 >> 4, 0, 0x427, 0xf);
    func_ov001_021875c0(param_1, 0, param_1->mUnk_248 >> 4, 0, 0x426, 0xf);
    func_020d2774(&param_1->mUnk_000, (u32) (0x24d));
    func_ov001_02188230(param_1);
    if (func_ov001_02188220(param_1) == 2) {
        func_020d2774(&param_1->mUnk_000, (u32) (0x24c));
    } else if (func_ov001_02188220(param_1) >= 3) {
        param_1->mUnk_0ac = 0;
    }
    func_0209b688((void *) (param_1->mUnk_304), (u16) (func_ov001_02188220(param_1)));
}

void func_ov001_0218d9cc(Unk02188950 *param_1) {
    Unk0218d87c *list;
    int i;
    Unk02188950 *q;

    list = func_02100138(0x1fe);
    if (list != 0) {
        for (i = 0; i < list->mUnk_04 && (q = list->mUnk_00[i]) != 0; i++) {
            func_ov001_02188e24(q, (s32) (q->mUnk_0a8 * 15), (UnkFunc *) func_ov001_0218da1c);
        }
    }
    func_ov001_0218da1c(param_1);
}

void func_ov001_0218d950(Unk02188950 *param_1) {
    s32 prod;
    float f;
    Unk0219b250_Item *s;

    func_ov001_02187218(param_1, 1, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_088), (s32) (param_1->mUnk_0a0->mUnk_08c));
    prod = param_1->mUnk_0a0->mUnk_0d0 * param_1->mUnk_0a8;
    if (prod > 0) {
        f = 0.5f + (float) (prod << 12);
    } else {
        f = (float) (prod << 12) - 0.5f;
    }
    s = param_1->mUnk_304->mUnk_1c;
    s->mUnk_0c = (s32) f;
    *s->mUnk_1c[s->mUnk_1a] = s->mUnk_0c;
}

void func_ov001_0218d8f4(Unk02188950 *param_1, int param_2) {
    Unk0218d87c *list;
    int i;

    list = func_02100138(0x1fe);
    if (list != 0) {
        for (i = 0; i < list->mUnk_04 && list->mUnk_00[i] != 0; i++) {
            func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_088),
                                (s32) (param_1->mUnk_0a0->mUnk_08c * param_2 / 100));
        }
    }
}

void func_ov001_0218d87c(Unk02188950 *param_1, int param_2) {
    Unk0218d87c *list;
    int i;
    Unk02188950 *q;

    list = func_02100138(0x1fe);
    if (list != 0) {
        for (i = 0; i < list->mUnk_04 && (q = list->mUnk_00[i]) != 0; i++) {
            q->mUnk_13c = q->mUnk_0a0->mUnk_0d8 * q->mUnk_0a8 * 100 / param_2;
            q->mUnk_194 = param_1->mUnk_0a0->mUnk_0d4 * param_2 / 100;
        }
    }
}

void func_ov001_0218d824(Unk02188950 *param_1, int param_2) {
    Unk02188950_a0 *a;

    a = param_1->mUnk_0a0;
    func_ov001_02188cd8(param_1, (s32) (a->mUnk_090 * param_2 / 100), (s32) (a->mUnk_094));
    a = param_1->mUnk_0a0;
    func_ov001_02188c48(param_1, a->mUnk_098 * param_2 / 100, a->mUnk_09c);
    func_ov001_02188998(param_1, (Vec3 *) func_ov001_02187ee8(param_1));
}

void func_ov001_0218d800(Unk02188950 *param_1) {
    param_1->mUnk_150 = 1;
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_088), (s32) (param_1->mUnk_0a0->mUnk_08c));
}

int func_ov001_0218d520(Unk02188950 *param_1) {
    int r4;
    s32 t;
    s32 *v;

    if (func_ov001_021881a8(param_1, (Vec3 *) func_ov001_02187fc0(param_1), (s32) (param_1->mUnk_0a0->mUnk_0a0), 0)) {
        if (func_020a1154(data_021759c0->mUnk_62) <= 1) {
            r4 = 0x1000 - param_1->mUnk_0a0->mUnk_0ac;
            t = func_ov001_02187f38(param_1);
            r4 = (s32) (((s64) t * r4) >> 12);
        } else if (func_020a1154(data_021759c0->mUnk_62) <= 2) {
            r4 = 0x1000 - param_1->mUnk_0a0->mUnk_0a8;
            t = func_ov001_02187f38(param_1);
            r4 = (s32) (((s64) t * r4) >> 12);
        } else {
            r4 = func_ov001_02187f38(param_1);
        }
        if (func_ov001_02187f7c(param_1) >= 1) {
            func_ov001_0218d9cc(param_1);
        }
        if ((data_021759c0->mUnk_08 == 4 ? func_020a126c() : 0) == 0 && param_1->mUnk_0a8 == 0 &&
            func_ov001_021871f8(param_1, 3) != 0) {
            if (func_ov001_02188084(param_1, (s32) (param_1->mUnk_0a0->mUnk_120), (s32) (param_1->mUnk_0a0->mUnk_124),
                                    (s32) (param_1->mUnk_0a0->mUnk_128))) {
                param_1->mUnk_0a8 = param_1->mUnk_0a0->mUnk_12c;
                param_1->mUnk_150 = 3;
                func_ov001_02188d30(param_1, (s32) (param_1->mUnk_0a0->mUnk_118), (s32) (param_1->mUnk_0a0->mUnk_11c),
                                    (UnkFunc *) (func_ov001_0218d800));
                r4 -= param_1->mUnk_0a0->mUnk_130;
                func_020d2774(&param_1->mUnk_000, (u32) (0x24b));
            } else if (func_ov001_02188084(param_1, (s32) (param_1->mUnk_0a0->mUnk_10c),
                                           (s32) (param_1->mUnk_0a0->mUnk_110), (s32) (param_1->mUnk_0a0->mUnk_114))) {
                param_1->mUnk_0a8 = param_1->mUnk_0a0->mUnk_12c;
                param_1->mUnk_150 = 3;
                func_ov001_02188d30(param_1, (s32) (param_1->mUnk_0a0->mUnk_104), (s32) (param_1->mUnk_0a0->mUnk_108),
                                    (UnkFunc *) (func_ov001_0218d800));
                r4 -= param_1->mUnk_0a0->mUnk_130;
                func_020d2774(&param_1->mUnk_000, (u32) (0x24b));
            }
        }
        func_ov001_0218d824(param_1, r4);
        func_ov001_0218d87c(param_1, r4);
        func_ov001_02187e78(param_1);
        if (param_1->mUnk_14c == 0) {
            func_ov001_02187e48(param_1, 4);
        }
    }
    if (param_1->mUnk_0a8 > 0) {
        param_1->mUnk_0a8 = param_1->mUnk_0a8 - 1;
    }
    if (func_ov001_021871f8(param_1, 5)) {
        if (func_ov001_02188220(param_1) == 2) {
            param_1->mUnk_140 = param_1->mUnk_140 + 1 >= 6 ? 0 : param_1->mUnk_140 + 1;
            if (param_1->mUnk_140 == 0) {
                func_ov001_021875c0(param_1, 0, 0, 0, 0x3f9, 0x1c);
            }
            param_1->mUnk_144 = param_1->mUnk_144 + 1 >= 0x12 ? 0 : param_1->mUnk_144 + 1;
            if (param_1->mUnk_144 == 0) {
                func_020d2774(&param_1->mUnk_000, (u32) (0x24f));
            }
        } else if (func_ov001_02188220(param_1) == 1) {
            param_1->mUnk_140 = param_1->mUnk_140 + 1 >= 0x12 ? 0 : param_1->mUnk_140 + 1;
            if (param_1->mUnk_140 == 0) {
                func_ov001_021875c0(param_1, 0, 0, 0, 0x3f8, 0x1c);
                func_020d2774(&param_1->mUnk_000, (u32) (0x24e));
            }
        }
    }
    return 0;
}
