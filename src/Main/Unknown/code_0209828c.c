#include "Main/Unknown/code_0209828c.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b6b0.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020ac524.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d7db4.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02146cbc.h"
#include "code_02148538.h"

void *func_0209828c(void) {
    data_usa_0217b0dc = (Unk020e6fd4 *) func_0209bf48(func_0209886c, func_020983c4, NULL);
    func_020e6f50(&data_usa_0217b0dc);
    return data_usa_0217b0dc;
}

void *func_020982d4(void) {
    data_usa_0217b0f0 = (Unk020982d4 *) func_0209bef0(CreatePakkunZHead, func_02098a58, func_02098b1c);
    data_usa_0217b0f0->mUnk_1c = 1;
    func_020d49d8(&data_usa_0217b0f0);
    return data_usa_0217b0f0;
}

void *func_02098328(void) {
    data_usa_0217b0e8 = (void *) func_0209bef0(CreatePakkunBody, func_02098954, func_020989fc);
    func_020d49d8(&data_usa_0217b0e8);
    return data_usa_0217b0e8;
}

void *func_02098374(void) {
    data_usa_0217b0f4 = (Unk020982d4 *) func_0209bf1c(CreatePakkunMouth, func_02098b68, NULL);
    data_usa_0217b0f4->mUnk_1c = 1;
    func_020d49d8(&data_usa_0217b0f4);
    return data_usa_0217b0f4;
}

static inline u32 func_020983c4_inline(u32 n) {
    Unk020f41c4_B *r;
    u32 t;
    u32 m;
    if (n == 0x10000) {
        r = func_020d22d0();
        r->mUnk_00 = r->mUnk_10 + (s64) r->mUnk_08 * (s64) r->mUnk_00;
        return (u16) ((r->mUnk_00 >> 32) * 0x10000 >> 32);
    }
    r = func_020d22d0();
    m = (u16) n;
    if (m == 0) {
        t = 0;
    } else {
        r->mUnk_00 = r->mUnk_10 + (s64) r->mUnk_08 * (s64) r->mUnk_00;
        if (m == 0) {
            t = r->mUnk_00 >> 32;
        } else {
            t = ((r->mUnk_00 >> 32) * m) >> 32;
        }
    }
    return (u16) t;
}

void func_020983c4(void *a, Unk020983c4 *p) {
    BOOL f;
    s32 t;
    s32 x;
    s32 y;
    Unk0210b7a8 s;
    switch (p->mUnk_0b4) {
        case 0:
            p->mUnk_1b8 += func_020983c4_inline((u16) (p->mUnk_1ba - 1)) + 1;
            if (p->mUnk_1b8 >= p->mUnk_1ba) {
                p->mUnk_1b8 -= p->mUnk_1ba;
            }
            p->mUnk_0b4 = 1;
        case 1:
            f = FALSE;
            if (p->mUnk_1dc < p->mUnk_1bc[p->mUnk_1b8]) {
                p->mUnk_1dc = p->mUnk_1dc + 0x6d;
                if (p->mUnk_1dc >= p->mUnk_1bc[p->mUnk_1b8]) {
                    f = TRUE;
                }
            } else {
                p->mUnk_1dc = p->mUnk_1dc - 0x6d;
                if (p->mUnk_1dc <= p->mUnk_1bc[p->mUnk_1b8]) {
                    f = TRUE;
                }
            }
            if (f != FALSE) {
                if (func_020983c4_inline(2) == 0) {
                    p->mUnk_0b4 = 2;
                } else {
                    p->mUnk_0b4 = 0;
                }
            }
            break;
        case 2:
            if (p->mUnk_1ec >= -4 && p->mUnk_1ec <= 4) {
                p->mUnk_1b4 = 0x1e;
                p->mUnk_0b4 = 3;
            }
            break;
        case 3:
            if (p->mUnk_1b4-- <= 0) {
                p->mUnk_1b4 = 0;
                if (p->mUnk_1e8 >= 0xffc) {
                    p->mUnk_1e8 = 0x1000;
                    p->mUnk_1e4 = 0;
                    p->mUnk_1f4 = 0x7b;
                    p->mUnk_0b4 = 4;
                }
            } else {
                p->mUnk_1e0 = p->mUnk_1e0 + 0xa4;
            }
            break;
        case 4:
            p->mUnk_1f0 = p->mUnk_1f0 + p->mUnk_1f4;
            p->mUnk_1f4 = p->mUnk_1f4 - 8;
            if (p->mUnk_1f4 <= 0) {
                if (p->mUnk_1f0 <= 0x119a) {
                    p->mUnk_0b4 = 5;
                }
            }
            break;
        case 5:
            p->mUnk_1f0 = p->mUnk_1f0 + p->mUnk_1f4;
            p->mUnk_1f4 = p->mUnk_1f4 - 8;
            if (p->mUnk_1f0 <= 0x1000) {
                p->mUnk_1f0 = 0x1000;
                p->mUnk_1e4 = 1;
            }
            p->mUnk_0a4 = p->mUnk_0a4 + p->mUnk_0a8;
            if (p->mUnk_0a4 >= p->mUnk_0b0) {
                p->mUnk_0a4 = p->mUnk_0ac;
            }
            if ((p->mUnk_0a4 >> 12) == 10) {
                func_02098f18(&p->mUnk_0b8[p->mUnk_1b8], p->mUnk_1fc + 0x46000);
                if ((p->mUnk_000.mUnk_78 & 4) == 0) {
                    if (p->mUnk_000.mUnk_70 == data_0217ca6c[2].mUnk_20) {
                        t = 2;
                    } else if (p->mUnk_000.mUnk_70 == data_0217ca6c[3].mUnk_20) {
                        t = 3;
                    } else {
                        t = 4;
                    }
                    s.mUnk_00 = 0x171;
                    s.mUnk_04 = &p->mUnk_000.mUnk_04;
                    s.mUnk_08 = t;
                    s.mUnk_0c = func_020d4ef4(&p->mUnk_000.mUnk_04);
                    func_0210b7a8(&s);
                }
            } else if (p->mUnk_0a4 == 0) {
                p->mUnk_1b4 = 0x1e;
                p->mUnk_0b4 = 6;
            }
            break;
        case 6:
            if (p->mUnk_1b4-- <= 0) {
                p->mUnk_1b4 = 0;
                p->mUnk_0b4 = 0;
            } else {
                p->mUnk_1e0 = p->mUnk_1e0 - 0xa4;
            }
            break;
    }
    if (p->mUnk_1e4 != 0) {
        p->mUnk_1e8 = p->mUnk_1e8 + p->mUnk_1ec;
        p->mUnk_1ec = p->mUnk_1ec + 4;
        if (p->mUnk_1e8 >= 0x1000) {
            p->mUnk_1ec = -0x52;
        }
    }
    x = (s32) (((s64) (p->mUnk_1e8 + p->mUnk_1f0 - 0x1000) * 0x2f000) >> 12);
    y = (s32) (((s64) p->mUnk_1f0 * 0x17000) >> 12);
    p->mUnk_1f8 = x + y;
}

void func_0209886c(void) {
    s32 i;
    Unk020983c4 *o;
    float f;
    if (data_usa_0217b0dc == NULL) {
        return;
    }
    for (i = 0; i < data_usa_0217b0dc->mUnk_04 && (o = (Unk020983c4 *) data_usa_0217b0dc->mUnk_00[i]) != NULL; i++) {
        if (func_0209b758(gPakkunMouth) - 1 > 0) {
            f = 0.5f + (float) ((func_0209b758(gPakkunMouth) - 1) << 12);
        } else {
            f = (float) ((func_0209b758(gPakkunMouth) - 1) << 12) - 0.5f;
        }
        o->mUnk_0a4 = 0;
        o->mUnk_0a8 = 0x1000;
        o->mUnk_0ac = 0;
        o->mUnk_0b0 = (s32) f;
        o->mUnk_1e0 = -0xa4;
    }
}

void func_02098954(void *a, Unk020983c4 *p) {
    s32 w;
    s32 v[3];
    s32 d;
    s32 y;
    s32 x;
    x = p->mUnk_1e8;
    y = p->mUnk_1f0;
    d = 0x3000 - x - y;
    w = 0x1e;
    func_01ff9048(0x14, &w, 1);
    func_01ff9048(0x19, func_020e6cbc(&p->mUnk_000.mUnk_04), 12);
    v[0] = d;
    v[1] = x + y - 0x1000;
    v[2] = d;
    func_01ff9048(0x1b, v, 3);
    func_01ff9048(0x1b, &p->mUnk_000.mUnk_1c, 3);
    func_0209bb2c(a, gPakkunBody, p);
}

void func_020989fc(void *a) {
    func_0209bbd0(a, gPakkunBody);
}

void CreatePakkunBody(void *a) {
    gPakkunBody = func_0209bd08(a, "PakkunBody.nsbmd");
    func_0209b940(gPakkunBody, 0x3f);
    func_0209b9a4(gPakkunBody, 0x1f);
}

void func_02098a58(void *a, Unk020983c4 *p) {
    s32 w;
    Vec3 v;
    s32 f[3];
    s32 t;
    v.x = p->mUnk_000.mUnk_04.x;
    v.y = p->mUnk_000.mUnk_04.y + p->mUnk_1f8;
    v.z = p->mUnk_000.mUnk_04.z;
    w = 0x1e;
    func_01ff9048(0x14, &w, 1);
    func_01ff9048(0x19, func_020e6cf8(&v), 12);
    t = p->mUnk_1f0;
    f[0] = t;
    f[1] = t;
    f[2] = t;
    func_01ff9048(0x1b, f, 3);
    func_01ff9048(0x1b, &p->mUnk_000.mUnk_1c, 3);
    func_0209b940(gPakkunZHead, p->mUnk_0a0);
    func_0209bb2c(a, gPakkunZHead, p);
}

void func_02098b1c(void *a) {
    func_0209bbd0(a, gPakkunZHead);
}

void CreatePakkunZHead(void *a) {
    gPakkunZHead = func_0209bd08(a, "PakkunZHead.nsbmd");
    func_0209b9a4(gPakkunZHead, 0x1e);
}

void func_02098b68(void *a, Unk020983c4 *p) {
    s32 w;
    s32 m[9];
    s32 n[9];
    s32 f[3];
    s32 g[3];
    s32 t;
    w = 0x1e;
    func_01ff9048(0x14, &w, 1);
    p->mUnk_000.mUnk_28.mUnk_00[3].x = p->mUnk_000.mUnk_04.x >> 4;
    p->mUnk_000.mUnk_28.mUnk_00[3].y = p->mUnk_000.mUnk_04.y >> 4;
    p->mUnk_000.mUnk_28.mUnk_00[3].z = p->mUnk_000.mUnk_04.z >> 4;
    func_01ff9048(0x19, &p->mUnk_000.mUnk_28, 12);
    f[1] = p->mUnk_1f8 >> 4;
    f[0] = 0;
    f[2] = 0;
    func_01ff9048(0x1c, f, 3);
    if (p->mUnk_1dc != 0) {
        func_02146d44(m, data_0215d4b4[((u16) p->mUnk_1dc >> 4) * 2], data_0215d4b4[((u16) p->mUnk_1dc >> 4) * 2 + 1]);
        func_01ff9048(0x1a, m, 9);
    }
    if (p->mUnk_1e0 != 0) {
        func_02146d28(n, data_0215d4b4[((u16) p->mUnk_1e0 >> 4) * 2], data_0215d4b4[((u16) p->mUnk_1e0 >> 4) * 2 + 1]);
        func_01ff9048(0x1a, n, 9);
    }
    t = p->mUnk_1f0;
    g[0] = t;
    g[1] = t;
    g[2] = t;
    func_01ff9048(0x1b, g, 3);
    func_01ff9048(0x1b, &p->mUnk_000.mUnk_1c, 3);
    func_0209b940(gPakkunMouth, p->mUnk_0a0);
    func_0209b77c(gPakkunMouth, p->mUnk_0a4 >> 12);
    func_0209bb2c(a, gPakkunMouth, p);
}

void CreatePakkunMouth(void *a) {
    gPakkunMouth = func_0209be84(a, "PakkunMouth.nsbmd");
    func_0209be50(gPakkunMouth, "PakkunMouth.nsbca");
    func_0209b9a4(gPakkunMouth, 0x1f);
}

void func_02098d4c(Unk020983c4 *p) {
    s32 v;
    s32 d;
    Vec3 a;
    Vec3 b;
    s32 i;
    p->mUnk_1d8 = (u32) (((s64) p->mUnk_000.mUnk_9c->mUnk_0c.y * 0xb60b60b60bLL + 0x80000000000LL) >> 32 << 4) >> 16;
    p->mUnk_1e4 = 1;
    p->mUnk_1e8 = 0x1000;
    p->mUnk_1ec = 0;
    p->mUnk_1f0 = 0x1000;
    p->mUnk_1f4 = 0;
    p->mUnk_1f8 = 0x46000;
    for (i = 0; i < 7; i++) {
        p->mUnk_0b8[i].mUnk_08 = 0xffff;
    }
    for (i = 0; i < 7; i++) {
        if (i == 0) {
            v = p->mUnk_000.mUnk_9c->mUnk_28;
        } else if (i == 1) {
            v = p->mUnk_000.mUnk_9c->mUnk_2a;
        } else if (i == 2) {
            v = p->mUnk_000.mUnk_9c->mUnk_2c;
        } else if (i == 3) {
            v = p->mUnk_000.mUnk_9c->mUnk_2e;
        } else if (i == 4) {
            v = p->mUnk_000.mUnk_9c->mUnk_30;
        } else if (i == 5) {
            v = p->mUnk_000.mUnk_9c->mUnk_32;
        } else {
            v = p->mUnk_000.mUnk_9c->mUnk_34;
        }
        if (v >= 0) {
            func_020d7db4(&p->mUnk_0b8[p->mUnk_1ba], (u16) v, 100);
            func_020d8918(&p->mUnk_0b8[p->mUnk_1ba], &a, &b);
            d = func_02148714(b.x, b.z) - p->mUnk_1d8;
            if (d > 0x8000) {
                d -= 0x10000;
            }
            p->mUnk_1bc[p->mUnk_1ba] = d;
            p->mUnk_1fc = p->mUnk_000.mUnk_04.y - a.y;
            p->mUnk_1ba++;
        }
    }
    p->mUnk_0a0 = func_020d3c2c();
    func_020ac588(0x1ab, 0x14, p);
}

void func_02098f18(Unk020e0144 *a, s32 b) {
    Unk0209905c *p;
    p = func_0209bbfc(func_02100138(0x1ab));
    if (p == NULL) {
        return;
    }
    p->mUnk_00.mUnk_02 = p->mUnk_00.mUnk_02 & ~1;
    p->mUnk_00.mUnk_02 = p->mUnk_00.mUnk_02 & ~8;
    p->mUnk_00.mUnk_02 = p->mUnk_00.mUnk_02 & ~2;
    p->mUnk_00.mUnk_02 = p->mUnk_00.mUnk_02 & ~8;
    p->mUnk_00.mUnk_66 = 0x1f;
    p->mUnk_a0.mUnk_08 = a->mUnk_08;
    p->mUnk_a0.mUnk_00 = a->mUnk_00;
    func_020d90a8(&p->mUnk_a0, 0, 1);
    p->mUnk_a0.mUnk_04 = 0x7800;
    p->mUnk_a0.mUnk_10 = ((s64) p->mUnk_a0.mUnk_00->mUnk_00[p->mUnk_a0.mUnk_0c].mUnk_34 * 0x7800) >> 12;
    p->mUnk_c4 = b;
    p->mUnk_c8 = -0x5000;
    p->mUnk_cc = 0;
    p->mUnk_d0 = func_0208b7bc(0x33, &p->mUnk_00.mUnk_04);
}

void *func_02099004(void) {
    return (void *) func_0209bf48(NULL, func_0209905c, NULL);
}
