#include "03/code_021cce78.h"
#include "03/code_021ccd18.h"
#include "03/code_021cd190.h"
#include "03/code_021d1000.h"
#include "03/code_021d250c.h"
#include "03/code_021d27d8.h"
#include "03/code_021d3000.h"
#include "03/code_021d34c0.h"
#include "03/code_021d3544.h"
#include "code_02134d30.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0200eddc.h"

void func_ov003_021cce78(void) {
    func_ov003_021d34c0(0, data_ov003_021da268->mUnk_0c);
    func_ov003_021d197c(data_ov003_021da268->mResource);
    func_ov003_021d2808(&data_ov003_021da268);
}

void func_ov003_021ccea4(u32 a, u32 b, u16 c, u16 d, u32 e) {
    (data_ov003_021da268 = func_ov003_021d283c(0x20, 4))->mUnk_1b = a;
    data_ov003_021da268->mUnk_19 = b;
    data_ov003_021da268->mOffset = e;
    func_ov003_021d2544(c, d, &data_ov003_021da268->mX);
    data_ov003_021da268->mResource = func_ov003_021d1be4(0, data_ov003_021d662c[a], 1);
    func_ov003_021d17d4(data_ov003_021da268->mResource, -1, c, d + e);
    func_ov003_021d1790(data_ov003_021da268->mResource, -1, 1);
    data_ov003_021da268->mUnk_0c = func_ov003_021d3544(0, (u32) func_ov003_021ccd18, 0, 0x80);
}

void func_ov003_021ccf30(Unk021ccf30 *a) {
    Unk021ccf30_1300 *v1 = (Unk021ccf30_1300 *) ((u8 *) data_ov003_021da26c + 0x1300);
    s32 i;
    s32 j;
    func_0200ee3c((u8 *) data_ov003_021da26c + 0xf00, 0x400);
    for (i = 0; i < a->mUnk_0e; i++) {
        Unk021ccf30_10 *p = a->mUnk_10[i];
        if (p->mUnk_0c[0] != 0 && p->mUnk_3c == 0) {
            Unk021ccf30_1300 *e;
            Unk021ccf30_1300 *q;
            j = 0;
            e = v1;
            for (; j < 0x14; j++) {
                if (func_02134d30(p->mUnk_04, e->mUnk_20, 6) == 0) {
                    break;
                }
                e++;
            }
            if (j == 0x14) {
                j = 0;
                e = v1;
                for (; j < 0x14; j++) {
                    if (func_02134d30(e->mUnk_20, data_ov003_021d6638, 6) == 0) {
                        break;
                    }
                    e++;
                }
                if (j == 0x14) {
                    return;
                }
            }
            q = &v1[j];
            func_0214d1fc(p->mUnk_04, q->mUnk_20, 6);
            func_0214d1fc(p->mUnk_0c, q, 0x20);
            q->mUnk_26 = a->mUnk_50[i];
            if ((p->mUnk_2c & 0x10) == 0) {
                q->mUnk_28 = 0;
            } else {
                Unk02142f24 v2;
                s32 k;
                s32 n;
                q->mUnk_28 = 1;
                v2 = func_02142f24((const u16 *) p);
                k = 0;
                n = v2.mUnk_00;
                for (; k < n; k++) {
                    if (v2.mUnk_04[k].mUnk_00 == 0x30) {
                        q->mUnk_28 = 2;
                        break;
                    }
                    if (v2.mUnk_04[k].mUnk_00 == 0xdd && v2.mUnk_04[k].mUnk_01 >= 4 &&
                        func_02134d30(v2.mUnk_04[k].mUnk_04, data_ov003_021d6634, 4) == 0) {
                        q->mUnk_28 = 2;
                        break;
                    }
                }
            }
        }
    }
}

void func_ov003_021cd080(Unk021425e8 *a) {
    if (a->mUnk_02 == 0 && *((u8 *) data_ov003_021da26c + 0x1e48) == 0 && a->mUnk_00 == 0x26) {
        switch (a->mUnk_08_0) {
            case 5:
                func_ov003_021ccf30((Unk021ccf30 *) a);
                func_ov003_021cd190();
                break;
            case 4:
                func_ov003_021cd190();
                break;
            default:
                func_0200fd1c();
                break;
        }
    }
}
