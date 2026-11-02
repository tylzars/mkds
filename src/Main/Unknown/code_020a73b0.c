#include "Main/Unknown/code_020a73b0.h"

#include "Main/Unknown/code_0209b000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020a7eb0.h"

u32 func_020a7eb0(u32 p0) {
    return p0;
}

void func_020a79c4(void *a, Unk020a7f18 *p) {
    s32 i;
    s32 k;
    s32 w0;
    s32 w1;
    s32 w2;
    s32 m0[9];
    s32 m1[9];
    s32 f0[3];
    s32 f1[3];
    s32 f2[3];
    s32 g2[3];
    s32 f3[3];
    s32 g3[3];
    s32 t;

    w0 = 0x1e;
    func_01ff9048(0x14, &w0, 1);
    switch (p->mUnk_1fc) {
        case 0:
        case 1:
            func_01ff9048(0x19, func_020e6cf8(&p->mUnk_000.mUnk_04), 12);
            f0[0] = 0;
            f0[1] = 0xa00;
            f0[2] = 0;
            func_01ff9048(0x1c, f0, 3);
            for (i = 0; i < p->mUnk_1d0; i++) {
                if (p->mUnk_0b0[i].mUnk_3c != 0) {
                    k = ((u16) p->mUnk_0b0[i].mUnk_3c >> 4) * 2;
                    func_02146d60(m0, data_0215d4b4[k], data_0215d4b4[k + 1]);
                    func_01ff9048(0x1a, m0, 9);
                }
                if (i != 0) {
                    f1[0] = 0;
                    f1[1] = 0x1400;
                    f1[2] = 0x80;
                    func_01ff9048(0x1c, f1, 3);
                }
                if (i == 3) {
                    func_0209bbd0(a, gSanboH);
                    func_0209bb2c(a, gSanboH, p);
                } else {
                    func_0209bbd0(a, gSanboB);
                    func_0209bb2c(a, gSanboB, p);
                }
            }
            break;
        case 2:
            for (i = 0; i < p->mUnk_1d0; i++) {
                w1 = 0x1e;
                func_01ff9048(0x14, &w1, 1);
                f2[0] = 0;
                f2[1] = 0xa00;
                f2[2] = 0;
                func_01ff9048(0x1c, f2, 3);
                func_01ff9048(0x19, func_020e6cf8(&p->mUnk_0b0[i].mUnk_00), 12);
                if ((p->mUnk_000.mUnk_02 & 0x12) == 0 && p->mUnk_0b0[i].mUnk_3c != 0) {
                    k = ((u16) p->mUnk_0b0[i].mUnk_3c >> 4) * 2;
                    func_02146d60(m1, data_0215d4b4[k], data_0215d4b4[k + 1]);
                    func_01ff9048(0x1a, m1, 9);
                }
                t = p->mUnk_0b0[i].mUnk_18;
                if (t < 0x1000) {
                    g2[0] = t;
                    g2[1] = t;
                    g2[2] = 0;
                    func_01ff9048(0x1b, g2, 3);
                }
                if (i == 3) {
                    func_0209bbd0(a, gSanboH);
                    func_0209bb2c(a, gSanboH, p);
                } else {
                    func_0209bbd0(a, gSanboB);
                    func_0209bb2c(a, gSanboB, p);
                }
            }
            break;
        case 3:
            for (i = 0; i < p->mUnk_1d0; i++) {
                w2 = 0x1e;
                func_01ff9048(0x14, &w2, 1);
                func_01ff9048(0x19, func_020e6cf8(&p->mUnk_000.mUnk_04), 12);
                f3[2] = 0x80;
                f3[0] = 0;
                f3[1] = (i * 0x14000 + 0xa000) >> 4;
                func_01ff9048(0x1c, f3, 3);
                t = p->mUnk_0b0[i].mUnk_18;
                if (t < 0x1000) {
                    g3[0] = t;
                    g3[1] = t;
                    g3[2] = 0;
                    func_01ff9048(0x1b, g3, 3);
                }
                if (i == 3) {
                    func_0209bbd0(a, gSanboH);
                    func_0209bb2c(a, gSanboH, p);
                } else {
                    func_0209bbd0(a, gSanboB);
                    func_0209bb2c(a, gSanboB, p);
                }
            }
            break;
    }
}

void func_020a78c8(Unk020e6fd4 *l) {
    s32 j;
    s32 i;
    Unk020a7f18 *o;

    if (l == NULL) {
        return;
    }
    for (i = 0; i < l->mUnk_04 && (o = l->mUnk_00[i]) != NULL; i++) {
        o->mUnk_1d4 = (o->mUnk_000.mUnk_9c->mUnk_28 << 12) / 100;
        o->mUnk_1d0 = 4;
        for (j = 0; j < o->mUnk_1d0; j++) {
            o->mUnk_0b0[j].mUnk_1c = 0;
            o->mUnk_0b0[j].mUnk_28 = 0;
            o->mUnk_0b0[j].mUnk_2c = 0x71c;
            o->mUnk_0b0[j].mUnk_30 = 0;
            o->mUnk_0b0[j].mUnk_34 = 0x2d8;
            o->mUnk_0b0[j].mUnk_38 = 0;
            o->mUnk_0b0[j].mUnk_18 = 0x1000;
            o->mUnk_0b0[j].mUnk_3c = 0;
            o->mUnk_0b0[j].mUnk_44 = j * 0x14;
        }
    }
}

s32 func_020a78b0(s32 a) {
    return data_0215d4b4[(a >> 4) * 2];
}

s32 func_020a7894(s32 a, s32 b) {
    return ((s64) a * b + 0x800) >> 12;
}

void func_020a73b0(void *a, Unk020a7f18 *p) {
    Unk0210b7a8 s;
    s32 m;
    s32 k;
    s32 i;
    s32 j;
    s32 t;
    s32 v;

    if (p->mUnk_0a0-- <= 0) {
        t = p->mUnk_1d4;
        p->mUnk_1d8.mUnk_04 = t;
        p->mUnk_1d8.mUnk_10 = (s64) t * p->mUnk_1d8.mUnk_00->mUnk_00[p->mUnk_1d8.mUnk_0c].mUnk_34 >> 12;
        if (func_020d8cc8(&p->mUnk_1d8) != 0) {
            p->mUnk_0a0 = (u16) p->mUnk_1d8.mUnk_1c->mUnk_0e;
        } else {
            p->mUnk_0a0 = 0;
        }
        if (p->mUnk_1d8.mUnk_00->mUnk_08 != 0) {
            func_020d8bf8(&p->mUnk_1d8, &p->mUnk_000.mUnk_04, &p->mUnk_000.mUnk_10);
        } else {
            func_020d8918(&p->mUnk_1d8, &p->mUnk_000.mUnk_04, &p->mUnk_000.mUnk_10);
        }
    } else {
        p->mUnk_1d8.mUnk_04 = 0;
        p->mUnk_1d8.mUnk_10 = 0;
        p->mUnk_000.mUnk_10.x = 0;
        p->mUnk_000.mUnk_10.y = 0;
        p->mUnk_000.mUnk_10.z = 0;
    }
    switch (p->mUnk_1fc) {
        case 0:
            if ((p->mUnk_000.mUnk_02 & 0x12) != 0) {
                return;
            }
            for (i = 0; i < p->mUnk_1d0; i++) {
                if (p->mUnk_0a4 > 0) {
                    p->mUnk_0b0[i].mUnk_34 = 0xb61;
                } else if (p->mUnk_0b0[i].mUnk_34 > 0x38e) {
                    p->mUnk_0b0[i].mUnk_34 = p->mUnk_0b0[i].mUnk_34 - 0xb6;
                } else {
                    p->mUnk_0b0[i].mUnk_34 = 0x2d8;
                }
                if (p->mUnk_0b0[i].mUnk_44-- <= 0) {
                    p->mUnk_0b0[i].mUnk_44 = 0;
                    p->mUnk_0b0[i].mUnk_1c = p->mUnk_0b0[i].mUnk_1c + p->mUnk_0b0[i].mUnk_34;
                    p->mUnk_0b0[i].mUnk_24 =
                        p->mUnk_0b0[i].mUnk_28 +
                        func_020a7894(p->mUnk_0b0[i].mUnk_2c, func_020a78b0(p->mUnk_0b0[i].mUnk_1c)) -
                        p->mUnk_0b0[i].mUnk_20;
                    p->mUnk_0b0[i].mUnk_20 = p->mUnk_0b0[i].mUnk_20 + p->mUnk_0b0[i].mUnk_24;
                    t = p->mUnk_0b0[i].mUnk_2c;
                    if (t > 0) {
                        v = t + p->mUnk_0b0[i].mUnk_30;
                        if (v <= 0) {
                            v = 0;
                        }
                        p->mUnk_0b0[i].mUnk_2c = v;
                    } else if (t < 0) {
                        v = t + p->mUnk_0b0[i].mUnk_30;
                        if (v >= 0) {
                            v = 0;
                        }
                        p->mUnk_0b0[i].mUnk_2c = v;
                    }
                    t = p->mUnk_0b0[i].mUnk_34;
                    if (t > 0) {
                        v = t + p->mUnk_0b0[i].mUnk_38;
                        if (v <= 0) {
                            v = 0;
                        }
                        p->mUnk_0b0[i].mUnk_34 = v;
                    } else if (t < 0) {
                        v = t + p->mUnk_0b0[i].mUnk_38;
                        if (v >= 0) {
                            v = 0;
                        }
                        p->mUnk_0b0[i].mUnk_34 = v;
                    }
                    p->mUnk_0b0[i].mUnk_3c = (u16) p->mUnk_0b0[i].mUnk_20;
                }
            }
            if (p->mUnk_0a4 <= 0) {
                return;
            }
            p->mUnk_0a4 = p->mUnk_0a4 - 1;
            if (p->mUnk_0ac > 0) {
                p->mUnk_0ac = p->mUnk_0ac - 1;
                return;
            }
            if (p->mUnk_0b0[0].mUnk_1c <= 0x8000) {
                return;
            }
            if (p->mUnk_0b0[0].mUnk_1c >= 0xc000) {
                return;
            }
            s.mUnk_00 = 0x194;
            s.mUnk_04 = &p->mUnk_000.mUnk_04;
            s.mUnk_08 = 2;
            s.mUnk_0c = func_020d4ef4(&p->mUnk_000.mUnk_04);
            func_0210b7a8(&s);
            p->mUnk_0ac = 0x14;
            break;
        case 2:
            for (j = 0; j < p->mUnk_1d0; j++) {
                if (p->mUnk_0b0[j].mUnk_00.y > 0) {
                    p->mUnk_0b0[j].mUnk_00.x = p->mUnk_0b0[j].mUnk_00.x + p->mUnk_0b0[j].mUnk_0c.x;
                    p->mUnk_0b0[j].mUnk_00.y = p->mUnk_0b0[j].mUnk_00.y + p->mUnk_0b0[j].mUnk_0c.y;
                    p->mUnk_0b0[j].mUnk_00.z = p->mUnk_0b0[j].mUnk_00.z + p->mUnk_0b0[j].mUnk_0c.z;
                    p->mUnk_0b0[j].mUnk_0c.y = p->mUnk_0b0[j].mUnk_0c.y - 0x400;
                }
            }
            if ((p->mUnk_000.mUnk_02 & 0x12) == 0) {
                for (m = 0; m < p->mUnk_1d0; m++) {
                    p->mUnk_0b0[m].mUnk_3c = p->mUnk_0b0[m].mUnk_3c + p->mUnk_0b0[m].mUnk_40;
                }
            }
            if (p->mUnk_000.mUnk_9c->mUnk_2a != 0) {
                return;
            }
            if (p->mUnk_0a8-- > 0) {
                return;
            }
            for (k = 0; k < p->mUnk_1d0; k++) {
                p->mUnk_0b0[k].mUnk_1c = 0;
                p->mUnk_0b0[k].mUnk_18 = 0;
                p->mUnk_0b0[k].mUnk_3c = 0;
                p->mUnk_0b0[k].mUnk_44 = k * 0x14;
            }
            p->mUnk_1d0 = 1;
            p->mUnk_1fc = 3;
            p->mUnk_000.mUnk_02 = p->mUnk_000.mUnk_02 & ~1;
            p->mUnk_000.mUnk_02 = p->mUnk_000.mUnk_02 & ~8;
            break;
        case 3:
            p->mUnk_0b0[p->mUnk_1d0 - 1].mUnk_18 = p->mUnk_0b0[p->mUnk_1d0 - 1].mUnk_18 + 0xcd;
            if (p->mUnk_0b0[p->mUnk_1d0 - 1].mUnk_18 < 0x1000) {
                return;
            }
            p->mUnk_0b0[p->mUnk_1d0 - 1].mUnk_18 = 0x1000;
            p->mUnk_1d0 = p->mUnk_1d0 + 1;
            if (p->mUnk_1d0 > 4) {
                p->mUnk_1d0 = 4;
                p->mUnk_1fc = 0;
            }
            break;
    }
}
