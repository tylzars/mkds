#include "01/code_021a2a40.h"
#include "Main/Unknown/code_020ca820.h"
#include "01/code_021a5140.h"
#include "01/code_021928c8.h"
#include "01/code_02185000.h"
#include "01/code_02184000.h"
#include "01/code_021a6000.h"
#include "01/code_021a41c8.h"
#include "01/code_021a401c.h"
#include "01/code_021a30e0.h"
#include "01/code_021a4724.h"
#include "01/code_02180ce8.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ac2c4.h"
#include "Main/Unknown/code_020ca000.h"
#include "Main/Unknown/code_020ca69c.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_020ac000.h"
#include "code_0212df7c.h"

void func_ov001_021a2e0c(void) {
    void *entry_a;
    void *entry_b;
    s32 i;
    s32 h;
    s32 v;
    s32 w;
    s32 sel;
    s32 u;
    s32 t;
    u32 y;
    s32 x;
    void *entry_c;
    void *entry_d;

    if (func_ov001_02192a54() != 0) {
        y = func_ov001_02192a60();
        x = func_ov001_02192a6c();
        i = func_ov001_021850b4(gEmblem->mEmblemTemplateSLld, 0, x, y);
        while (i >= 0) {
            func_ov001_021a41c8(i, 1);
            y = func_ov001_02192a60();
            x = func_ov001_02192a6c();
            i = func_ov001_021850b4(gEmblem->mEmblemTemplateSLld, i + 1, x, y);
        }
    }
    if (func_ov001_02192a14(1) != 0) {
        func_ov001_021a41c8(data_ov001_021a7098[gEmblem->mUnk_1084], 0);
        return;
    }
    if (func_ov001_02192a14(2) != 0) {
        func_ov001_021a41c8(0, 0);
        return;
    }
    h = 0;
    v = 0;
    w = 0;
    h += (func_020ae408(8, 0x20) != 0) ? -1 : 0;
    h += (func_020ae408(8, 0x10) != 0) ? 1 : 0;
    v += (func_020ae408(8, 0x40) != 0) ? -1 : 0;
    v += (func_020ae408(8, 0x80) != 0) ? 1 : 0;
    w += (func_020ae408(8, 0x200) != 0) ? -1 : 0;
    w += (func_020ae408(8, 0x100) != 0) ? 1 : 0;
    gEmblem->mUnk_1080 = w + (func_ov001_021a63b4() - 1);
    t = gEmblem->mUnk_1080;
    if (t < 0) {
        t = 0xe;
    }
    gEmblem->mUnk_1080 = t;
    u = gEmblem->mUnk_1080;
    if (u > 0xe) {
        u = 0;
    }
    gEmblem->mUnk_1080 = u;
    sel = gEmblem->mUnk_1080;
    if (sel != func_ov001_021a63b4() - 1) {
        entry_c = func_ov001_02185160(gEmblem->mEmblemSLld, data_ov001_021a7018[sel]);
        entry_d = func_ov001_02185160(gEmblem->mEmblemSLld, 9);
        func_ov001_02184fd8(entry_d, func_ov001_02184fc8(entry_c), func_ov001_02184fb8(entry_c));
        entry_d = func_ov001_02185160(gEmblem->mEmblemSLld, 10);
        func_ov001_02184fd8(entry_d, func_ov001_02184fc8(entry_c), func_ov001_02184fb8(entry_c));
        func_ov001_021a63c0((u8) (gEmblem->mUnk_1080 + 1));
        func_0212ecc0(&data_0217d068, 0, 0x1f1);
    }
    sel = gEmblem->mUnk_1084;
    gEmblem->mUnk_1084 = data_ov001_021a73ac[v + 1][sel];
    gEmblem->mUnk_1084 = data_ov001_021a7508[h + 1][gEmblem->mUnk_1084];
    entry_a = func_ov001_02185160(gEmblem->mEmblemTemplateSLld, 2);
    entry_b = func_ov001_02185160(gEmblem->mEmblemTemplateSLld, data_ov001_021a7098[gEmblem->mUnk_1084]);
    func_ov001_02185018(entry_a, 0);
    func_ov001_02184fd8(entry_a, func_ov001_02184fc8(entry_b), func_ov001_02184fb8(entry_b));
    if (gEmblem->mUnk_1084 != sel) {
        func_02105ac0(0x1ef);
    }
    {
        s32 k;
        void *q;

        for (k = 0; k < 0x1d; k++) {
            q = func_ov001_02185160(gEmblem->mEmblemTemplateSLld, data_ov001_021a7098[k]);
            func_ov001_02185018(q, k == gEmblem->mUnk_1084 ? 1 : 0);
        }
    }
}

void func_ov001_021a2d90(void) {
    s32 i;
    u32 y;
    s32 x;

    if (func_ov001_02192a54() != 0) {
        y = func_ov001_02192a60();
        x = func_ov001_02192a6c();
        i = func_ov001_021850b4(gEmblem->mEmblemCameraSLld, 0, x, y);
        while (i >= 0) {
            func_ov001_021a41c8(i, 1);
            y = func_ov001_02192a60();
            x = func_ov001_02192a6c();
            i = func_ov001_021850b4(gEmblem->mEmblemCameraSLld, i + 1, x, y);
        }
    }
    if (func_ov001_02192a14(4) != 0) {
        func_ov001_021a41c8(1, 0);
    }
}

void func_ov001_021a2cf0(void) {
    s32 v;

    v = func_020ca69c();
    switch (v) {
        case -2:
        case 0:
            func_ov001_021a4aac();
            break;
        case 1:
            func_020ca688(0);
            func_020ac390((void *) func_ov001_02181174(), gEmblem->mUnk_087c, func_ov001_02181268());
            func_020569a8(gEmblem->mUnk_087c);
            gEmblem->mUnk_1090 = 0xb;
            gEmblem->mUnk_1098 = 1;
            break;
        case 2:
            func_020ca688(0);
            gEmblem->mUnk_1090 = 0xb;
            gEmblem->mUnk_1098 = 1;
            break;
    }
    func_020ca844();
    func_020ca83c();
}

void func_ov001_021a2a40(void) {
    s32 t;

    func_ov001_02192a78();
    gEmblem->mUnk_10a8 += 0x4cd;
    t = gEmblem->mUnk_10a8;
    if (t >= 0x100000) {
        t -= 0x100000;
    }
    gEmblem->mUnk_10a8 = t;
    func_020ae6ac((void *) ((int) gEmblem), (void *) ((int) gEmblem->mUnk_0404));
    func_ov001_0218516c(gEmblem->mEmblemMLld, (Unk0218516c *) gEmblem->mUnk_0000);
    switch (gEmblem->mUnk_1090) {
        case 0:
            if (gEmblem->mUnk_10b0 == 0) {
                func_ov001_021a30e0();
            }
            func_ov001_0218516c(gEmblem->mEmblemSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            break;
        case 1:
            if (gEmblem->mUnk_10b0 == 0) {
                func_ov001_021a2e0c();
            }
            func_ov001_0218516c(gEmblem->mEmblemTemplateSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            func_ov001_0218516c(gEmblem->mEmblemSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            break;
        case 2:
            func_ov001_021a499c();
            func_ov001_0218516c(gEmblem->mEmblemTemplateSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            func_ov001_0218516c(gEmblem->mEmblemSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            break;
        case 3:
            func_ov001_021a48a4();
            func_ov001_0218516c(gEmblem->mEmblemTemplateSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            func_ov001_0218516c(gEmblem->mEmblemSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            break;
        case 4:
            if (gEmblem->mUnk_10ac == 0) {
                func_ov001_021a401c();
            }
            if (gEmblem->mUnk_10b0 == 0) {
                func_ov001_021a2d90();
            }
            func_ov001_0218516c(gEmblem->mEmblemCameraSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            break;
        case 5:
            if (gEmblem->mUnk_10ac == 0) {
                func_ov001_021a401c();
            }
            func_ov001_021a4804();
            func_ov001_0218516c(gEmblem->mEmblemSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            break;
        case 6:
            if (gEmblem->mUnk_10ac == 0) {
                func_ov001_021a401c();
            }
            func_ov001_021a47b4();
            func_ov001_0218516c(gEmblem->mEmblemCameraSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            break;
        case 7:
            if (gEmblem->mUnk_10b0 == 0) {
                func_ov001_021a30e0();
            }
            func_ov001_021a4774();
            func_ov001_0218516c(gEmblem->mEmblemCameraSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            break;
        case 8:
            if (gEmblem->mUnk_10b0 == 0) {
                func_ov001_021a30e0();
            }
            func_ov001_021a4724();
            func_ov001_0218516c(gEmblem->mEmblemSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            break;
        case 10:
            func_ov001_021a2cf0();
            func_ov001_0218516c(gEmblem->mEmblemSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            break;
        case 11:
            func_ov001_0218516c(gEmblem->mEmblemSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            if (data_0217aa08->mUnk_28 == 0) {
                if (data_021759d4->mUnk_0c != 0) {
                    t = data_021759d4->mUnk_10;
                } else {
                    t = 0;
                }
            } else {
                t = 1;
            }
            if (t == 0) {
                gEmblem->mUnk_1090 = 0xc;
            }
            break;
        case 12:
            func_ov001_0218516c(gEmblem->mEmblemSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            break;
    }
    func_020ae630((void *) ((int) gEmblem), (void *) ((int) gEmblem->mUnk_0404));
    func_020783c8();
    func_020780b0();
    func_020ac390((void *) func_ov001_02181174(), gEmblem->mUnk_087c, func_ov001_02181268());
    func_020ac2c4((const u8 *) func_ov001_02181174(), gEmblem->mUnk_0a7c, func_ov001_02181268());
}
