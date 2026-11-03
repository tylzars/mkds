#include "Main/Unknown/code_0209905c.h"
#include "Main/Unknown/code_0208b498.h"
#include "Main/Unknown/code_0208b6b0.h"
#include "Main/Unknown/code_020d22e0.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0217c000.h"

u32 func_02099208(Unk0209905c *a, Unk0206bcb0 *b, u8 *c, u8 *d) {
    u32 v1 = *c;
    u8 v2 = *d;
    if (v1 == 1) {
        a->mUnk_00.mFlags = a->mUnk_00.mFlags | data_usa_02156590;
        a->mUnk_cc = 1;
        if (b->mUnk_29c == 1 || b->mUnk_29c == 3) {
            a->mUnk_00.mUnk_78 = a->mUnk_00.mUnk_78 | data_usa_02156594;
        }
        func_020d26f8(&a->mUnk_00, b);
    }
    return v2;
}

void func_0209905c(void *a, Unk0209905c *p) {
    s32 t;
    Unk0210b7a8 s;
    Unk0209905c_d0_08 *n;
    switch (p->mUnk_cc) {
        case 0:
            p->mUnk_c4 = p->mUnk_c4 + p->mUnk_c8;
            p->mUnk_c8 = p->mUnk_c8 - 0x1000;
            if (p->mUnk_c4 <= 0) {
                p->mUnk_c4 = 0;
                p->mUnk_c8 = 0x5800;
                if ((p->mUnk_00.mUnk_78 & 4) == 0) {
                    if (p->mUnk_00.mUnk_70 == data_0217ca6c[2].mUnk_20) {
                        t = 2;
                    } else if (p->mUnk_00.mUnk_70 == data_0217ca6c[3].mUnk_20) {
                        t = 3;
                    } else {
                        t = 4;
                    }
                    s.mUnk_00 = 0x1af;
                    s.mUnk_04 = &p->mUnk_00.mPos;
                    s.mUnk_08 = t;
                    s.mUnk_0c = func_020d4ef4(&p->mUnk_00.mPos);
                    func_0210b7a8(&s);
                }
            }
            if (func_020d8cc8(&p->mUnk_a0) != 0 && p->mUnk_a0.mUnk_18 == 0) {
                p->mUnk_cc = 1;
            } else {
                func_020d8918(&p->mUnk_a0, &p->mUnk_00.mPos, &p->mUnk_00.mUnk_10);
                p->mUnk_00.mPos.y = p->mUnk_00.mPos.y + (p->mUnk_c4 + 0xf000);
            }
            if (p->mUnk_d0 == NULL) {
                return;
            }
            if ((p->mUnk_00.mFlags & 0x12) != 0) {
                p->mUnk_d0->mUnk_24 |= 2;
                return;
            }
            func_0208b5b0(p->mUnk_d0, &p->mUnk_00.mPos);
            p->mUnk_d0->mUnk_24 &= ~2;
            return;
        case 1:
            if (p->mUnk_d0 != NULL) {
                for (n = p->mUnk_d0->mUnk_08; n != NULL; n = n->mUnk_00) {
                    n->mUnk_26 = n->mUnk_24;
                }
                func_0208b6b0((void **) &p->mUnk_d0);
            }
            func_020d2398(&p->mUnk_00);
            return;
    }
}
