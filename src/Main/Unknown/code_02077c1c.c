#include "Main/Unknown/code_02077c1c.h"
#include "code_020176c0.h"
#include "code_02012b30.h"
#include "code_0214a5e0.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/code_02088338.h"
#include "Main/Unknown/code_0207adf8.h"

#pragma thumb on

void func_02077d68(void) {
    Unk0217ad08_1f4 *a;
    s32 b;
    Unk0217ad08_1f4 *p;
    s32 c;
    s32 i;
    char *e;

    a = data_0217ad08->mUnk_1f4;
    i = data_0217ad08->mUnk_266;
    p = &a[i];
    b = data_0217ad08->mUnk_020->mUnk_00;
    c = data_0217ad08->mUnk_020->mUnk_04;
    p->mUnk_30 = 0;
    func_0201797c(&p->mUnk_04->mUnk_00);
    p->mUnk_04 = func_02017988(p->mUnk_00, 0xf000, 0);
    if (b != -1 && p->mUnk_08 != 0) {
        func_02012b30(p->mUnk_08);
        func_02012b30(p->mUnk_0c);
        func_02012b30(p->mUnk_10);
        func_02012b30(p->mUnk_18);
        func_02012b30(p->mUnk_1c);
        func_02012b30(p->mUnk_20);
        func_02012b30(p->mUnk_24);
        func_02012b30(p->mUnk_28);
    }
    e = (char *) &data_0217ad08->mUnk_1c8[c];
    func_02048590(BuildCharacterNsbmdPath(b, 1), (u32) p->mUnk_04, (void **) &p->mUnk_08);
    func_02048590(BuildCharacterNsbtxPath(b, 1), (u32) p->mUnk_04, (void **) &p->mUnk_0c);
    func_02048590(func_0207b8f4(b, 2), (u32) p->mUnk_04, (void **) &p->mUnk_14);
    func_02048590(BuildEmblemNsbtxPath(b), (u32) p->mUnk_04, (void **) &p->mUnk_10);
    func_02048590(BuildKartNsbmdPath(c), (u32) p->mUnk_04, (void **) &p->mUnk_18);
    func_02048590(BuildKartNsbtxPath(c), (u32) p->mUnk_04, (void **) &p->mUnk_1c);
    func_02048590(BuildKartShadowNsbmdPath(c), (u32) p->mUnk_04, (void **) &p->mUnk_28);
    func_02048590(BuildTireNsbmdPath(c, e), (u32) p->mUnk_04, (void **) &p->mUnk_20);
    func_02048590(BuildTireNsbtxPath(c, e), (u32) p->mUnk_04, (void **) &p->mUnk_24);
}

void func_02077c1c(void) {
    Unk0217ad08_1f4 *p;
    Unk0217ad08_058 *q;
    Unk0217ad08_058 *e;
    Unk0217ad08_058_08 *r;

    func_0214a5e0(data_0217ad08->mUnk_024.mUnk_2c);
    if (data_0217aa0c->mUnk_f8 == 0) {
        p = &data_0217ad08->mUnk_1f4[data_0217ad08->mUnk_266];
        if (p->mUnk_2c != 0) {
            q = data_0217ad08->mUnk_020;
            if (p->mUnk_30 == 0) {
                func_02079078(p->mUnk_04, q->mUnk_10, q->mUnk_08, p->mUnk_08, p->mUnk_0c, p->mUnk_14);
                p->mUnk_30++;
                return;
            }
            if (p->mUnk_30 == 1) {
                func_02078f78(p->mUnk_10);
                data_0217ad08->mUnk_020->mUnk_b4 = data_0217ad08->mUnk_1d4;
                func_02079008(q->mUnk_1c, p->mUnk_28);
                func_02079014(q->mUnk_18, p->mUnk_20, p->mUnk_24);
                p->mUnk_30++;
                return;
            }
            func_02079038(q->mUnk_14, p->mUnk_18, p->mUnk_1c);
            func_0207851c((int) data_0217ad08->mUnk_020);
            func_0207940c(q->mUnk_14, q->mUnk_04, data_0217ad08->mUnk_1d0);
            func_020792c8((struct Unk0206bcb0_590 *) q, 1);
            p->mUnk_2c = 0;
            p->mUnk_30 = 0;
            if (data_0217ad08->mUnk_264 >= 0) {
                e = &data_0217ad08->mUnk_058[data_0217ad08->mUnk_264];
                if (q->mUnk_00 == e->mUnk_00) {
                    r = q->mUnk_08;
                    r->mUnk_0c = e->mUnk_08->mUnk_0c;
                    *r->mUnk_1c[r->mUnk_1a] = r->mUnk_0c;
                }
            }
            data_0217ad08->mUnk_264 = data_0217ad08->mUnk_266;
            data_0217ad08->mUnk_266 = data_0217ad08->mUnk_266 == 0 ? 1 : 0;
            data_0217ad08->mUnk_020 = &data_0217ad08->mUnk_058[data_0217ad08->mUnk_266];
        }
    }
}

#pragma thumb off
