#include "01/code_0218254c.h"
#include "01/code_02181000.h"
#include "01/code_02182000.h"
#include "01/code_02183000.h"
#include "01/unk_021a7000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_02108000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_020d7da8.h"

u8 func_ov001_0218274c(Unk02181c3c *param_1, Unk0218274c *param_2, u8 *param_3, u8 *param_4) {
    u8 a = *param_3;
    u8 b = *param_4;

    if (param_2->mUnk_48 & 0x200) {
        return 0;
    }
    if (a == 1) {
        if (param_1->mUnk_0f8 != 3 && param_1->mUnk_0f8 != 5 && param_1->mUnk_0f8 != 6) {
            func_020d2398(&param_1->mUnk_000);
            if (data_021759c0->mUnk_08 == 4) {
                func_ov001_021815d0(1);
            }
        }
    }
    return b;
}

void func_ov001_021826fc(Unk0219b478 *param_1) {
    data_ov001_021a9b98 = func_ov001_0219b478(param_1, data_ov001_021a78c0);
    func_ov001_0219b2e8(data_ov001_021a9b98, data_ov001_021a78cc);
    func_0209b940(data_ov001_021a9b98, 0x3f);
    func_0209ba08(data_ov001_021a9b98, 2);
    func_020849a0(data_ov001_021a9b98->mUnk_10, 0x294a);
    param_1->mUnk_1c = 1;
}

void func_ov001_0218263c(void *param_1, Unk02181c3c *param_2) {
    s32 a;
    Vec3 v;
    u32 t;
    s32 s;

    if (param_2->mUnk_0b0 > 0 && param_2->mUnk_0a0 != 0) {
        a = 0x1e;
        func_01ff9048((u32) (0x14), (void *) (&a), 1);
        func_01ff9048((u32) (0x19), (void *) (func_020e6cbc((Vec3 *) (&param_2->mUnk_000.mUnk_04))), 0xc);
        s = param_2->mUnk_0b0;
        if (s != 0x1000) {
            v.x = s;
            v.y = s;
            v.z = s;
            func_01ff9048((u32) (0x1b), (void *) (&v), 3);
        }
        func_01ff9048((u32) (0x1b), (void *) (&param_2->mUnk_000.mUnk_1c), 3);
        func_0209b940(data_ov001_021a9b98, func_020d3c44());
        t = param_2->mUnk_0a0;
        if (t >= 0x1f) {
            t = 0x1f;
        }
        func_0209b9a4(data_ov001_021a9b98, t);
        func_0209b688((void *) (data_ov001_021a9b98), (u16) param_2->mUnk_0a4);
        func_0209bbd0(param_1, data_ov001_021a9b98);
        func_0209bb2c((void *) (param_1), (void *) (data_ov001_021a9b98), (void *) (param_2));
    }
}

void func_ov001_02182550(Unk02181c3c_list *param_1) {
    int i;
    Unk02181c3c *p;
    s32 n;

    if (param_1 != 0) {
        for (i = 0; i < param_1->mUnk_04 && (p = param_1->mUnk_00[i]) != 0; i++) {
            p->mUnk_0d8 = p->mUnk_000.mUnk_9c->mUnk_00;
            p->mUnk_000.mUnk_04 = p->mUnk_0d8;
            p->mUnk_000.mUnk_04.y = p->mUnk_000.mUnk_04.y + 0xe000;
            if (p->mUnk_000.mUnk_9c->mUnk_26 >= 0) {
                func_020d7da8(&p->mUnk_0b4, p->mUnk_000.mUnk_9c, 0);
                n = (p->mUnk_000.mUnk_9c->mUnk_28 << 12) / 100;
                p->mUnk_0b4.mUnk_04 = n;
                p->mUnk_0b4.mUnk_10 = ((s64) n * p->mUnk_0b4.mUnk_00->mUnk_00[p->mUnk_0b4.mUnk_0c].mUnk_34) >> 12;
            } else {
                p->mUnk_0b4.mUnk_08 = 0xffff;
            }
            p->mUnk_0b0 = 0x1000;
            if (p->mUnk_000.mUnk_9c->mUnk_2a == 0) {
                p->mUnk_0a0 = 0x1f;
            } else {
                p->mUnk_0a0 = 0;
            }
        }
    }
}

void func_ov001_0218254c(void) {}
