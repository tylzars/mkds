#include "Main/Unknown/code_0203c5f8.h"
#include "Main/Unknown/code_020b502c.h"
#include "code_0214d018.h"

u16 func_0203c5f8(u16 a, u8 *b, u8 *c, u16 *d) {
    u16 r = 1;
    u16 i;
    BOOL f = TRUE;
    u32 v1;
    Unk0217aa1c_144_00 v2;
    Unk0217aa1c_144_00 *q;
    BOOL k;
    Unk0217aa1c_144_00 *p;
    i = 1;
    if (gCourseMap->mUnk_018->mUnk_02 >= 1) {
        v1 = a * 0x8c;
        do {
            q = (Unk0217aa1c_144_00 *) ((u8 *) &data_0217561c->mUnk_14[0].mUnk_0c[0] + v1) + (i - 1);
            if (f != FALSE) {
                f = FALSE;
                r = i;
                v2 = *q;
            } else {
                p = &v2;
                k = FALSE;
                if ((u32) ((q->mUnk_02 * 60 + q->mUnk_03) * 1000 + q->mUnk_00) <=
                    (u32) ((v2.mUnk_02 * 60 + v2.mUnk_03) * 1000 + v2.mUnk_00)) {
                    k = TRUE;
                    if (q != p) {
                        func_0214d1fc(q, p, 4);
                    }
                } else {
                    if (p != &v2) {
                        func_0214d1fc(q, p, 4);
                    }
                }
                if (k != FALSE) {
                    r = i;
                    v2 = *q;
                }
            }
            i++;
        } while (i <= gCourseMap->mUnk_018->mUnk_02);
    }
    *b = v2.mUnk_02;
    *c = v2.mUnk_03;
    *d = v2.mUnk_00;
    return r;
}

void func_0203c778(s32 a, u16 b, u8 *c, u8 *d, u16 *e) {
    s32 k = b - 1;
    Unk0217aa1c_144_00 *p = (Unk0217aa1c_144_00 *) ((u8 *) &data_0217561c->mUnk_14[0].mUnk_0c[0] + a * 0x8c);
    Unk0217aa1c_144_00 *q = &p[k];
    *c = q->mUnk_02;
    *d = q->mUnk_03;
    *e = q->mUnk_00;
}

void func_0203c7cc(s32 a, u8 *b, u8 *c, u16 *d) {
    Unk0217561c_14 *p = (Unk0217561c_14 *) ((u8 *) &data_0217561c->mUnk_14[0] + a * 0x8c);
    BOOL g = TRUE;
    if (data_021759c0->mUnk_08 == 2) {
        if (data_021759c0->mUnk_18 == 1) {
            g = FALSE;
        }
    }
    if (g != FALSE) {
        BOOL h = FALSE;
        switch (p->mUnk_00) {
            case 1:
            case 2:
            case 3:
                h = TRUE;
                break;
        }
        if (h != FALSE) {
            Unk0217aa1c_144_00 *t = &p->mUnk_0c[5];
            *b = t->mUnk_02;
            *c = t->mUnk_03;
            *d = t->mUnk_00;
            return;
        }
    }
    *b = 0;
    *c = 0;
    *d = 0;
}

s32 func_0203c880(u32 param_1) {
    BOOL f = FALSE;
    switch (data_0217561c->mUnk_000[param_1].mUnk_14) {
        case 1:
        case 2:
        case 3:
            f = TRUE;
            break;
    }
    return f;
}
