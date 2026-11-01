#include "01/code_021861f4.h"
#include "01/code_0218d520.h"
#include "01/unk_021a9000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d3000.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_02021000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020e6000.h"

void func_ov001_02186368(void *param_1, Unk02188950 *param_2) {
    s32 i;
    s32 depth;
    Unk0219b250_10_04 *obj;
    s32 level;
    s32 value;
    Vec3 v;
    s32 m[9];
    s32 k;

    depth = param_2->mUnk_168 >> 12;
    v.x = param_2->mUnk_000.mUnk_04.x >> 4;
    v.y = param_2->mUnk_000.mUnk_04.y >> 4;
    v.z = param_2->mUnk_000.mUnk_04.z >> 4;
    level = func_020e69bc(&v);
    if (level >= depth) {
        level = depth;
    }
    if (level > 0) {
        if (level >= 0x1f) {
            level = 0x1f;
        }
        if (level >= 0x1f) {
            func_02012ffc((Unk0201290c *) param_2->mUnk_304->mUnk_10->mUnk_04, 1);
            func_0209b940(param_2->mUnk_304, 3);
        } else if (param_2->mUnk_27c <= 1) {
            func_02012ffc((Unk0201290c *) param_2->mUnk_304->mUnk_10->mUnk_04, 1);
            func_0209b940(param_2->mUnk_304, 3);
        } else {
            obj = param_2->mUnk_304->mUnk_10->mUnk_04;
            func_02012ffc((Unk0201290c *) obj, 1);
            for (i = 0; i < obj->mUnk_18; i++) {
                func_0209b904(param_2->mUnk_304, func_020d3c44(), i);
            }
        }
        value = 0x1e;
        func_01ff9048(0x14, &value, 1);
        func_01ff9048(0x19, func_020e6b58(&param_2->mUnk_000.mUnk_04), 0xc);
        if (param_2->mUnk_000.mUnk_7e != 0) {
            k = param_2->mUnk_000.mUnk_7e >> 4;
            func_02146d44(m, data_0215d4b4[k * 2], data_0215d4b4[k * 2 + 1]);
            func_01ff9048(0x1a, m, 9);
        }
        func_01ff9048(0x1b, &param_2->mUnk_000.mUnk_1c.x, 3);
        func_0209b9a4(param_2->mUnk_304, level);
        func_0209b7a0(param_2->mUnk_304, param_2->mUnk_000.mUnk_02 & 0x400, 0);
        func_0209bb2c(param_1, param_2->mUnk_304, param_2);
    }
}

void func_ov001_021861f4(void *param_1, Unk02188950 *param_2, s32 param_3) {
    s32 depth;
    s32 value;
    Vec3 v;

    depth = param_2->mUnk_168 >> 12;
    if (param_2->mUnk_27c == 2) {
        v.x = param_2->mUnk_000.mUnk_04.x;
        v.y = param_2->mUnk_000.mUnk_04.y;
        v.z = param_2->mUnk_000.mUnk_04.z;
    } else if (param_2->mUnk_27c == 3) {
        v.x = param_2->mUnk_2e8.x;
        v.y = param_2->mUnk_000.mUnk_9c->mUnk_00.y;
        v.z = param_2->mUnk_2e8.z;
    } else {
        if (depth >= 4) {
            s32 t = depth - ((param_2->mUnk_000.mUnk_04.y - param_2->mUnk_000.mUnk_9c->mUnk_00.y) >> 15);

            if (t <= 4) {
                t = 4;
            }
            depth = (u16) t;
        }
        v.x = param_2->mUnk_000.mUnk_04.x;
        v.y = param_2->mUnk_000.mUnk_9c->mUnk_00.y;
        v.z = param_2->mUnk_000.mUnk_04.z;
    }
    if (depth > 0x10) {
        depth = 0x10;
    }
    if (param_3 != 0) {
        depth = 0x14 - depth;
    }
    if (depth > 0) {
        s32 m[9];
        Vec3 w;
        Vec3 u;
        s32 k;
        s32 a;
        s32 b;
        s32 c;

        value = 0x1e;
        func_01ff9048(0x14, &value, 1);
        func_01ff9048(0x19, func_020e6b58(&v), 0xc);
        k = (u16) param_2->mUnk_184 >> 4;
        func_02146d44(m, data_0215d4b4[k * 2], data_0215d4b4[k * 2 + 1]);
        func_01ff9048(0x1a, m, 9);
        c = param_2->mUnk_288 >> 4;
        b = param_2->mUnk_284 >> 4;
        a = param_2->mUnk_280 >> 4;
        w.x = a;
        w.y = b;
        w.z = c;
        func_01ff9048(0x1c, &w, 3);
        func_01ff9048(0x1b, &param_2->mUnk_298, 3);
        if (data_ov001_021a9ba0 == 0) {
            u.x = 0x1333;
            u.y = 0x1000;
            u.z = 0x1333;
            func_01ff9048(0x1b, &u, 3);
        }
        func_0209b940(param_2->mUnk_308, 3);
        func_0209b9a4(param_2->mUnk_308, depth);
        func_0209bb2c(param_1, param_2->mUnk_308, param_2);
    }
}
