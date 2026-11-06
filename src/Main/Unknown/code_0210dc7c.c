#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0210d740.h"
#include "Main/Unknown/code_0210d000.h"
#include "code_0212bcac.h"
#include "Main/Unknown/code_0210e33c.h"
#include "code_0212d214.h"

void func_0210e2c4(Unk0217c7c4 *a, void *b, s32 c, s32 d) {
    s32 i;
    u8 *p;

    a->mUnk_0c = b;
    a->mUnk_00 = c;
    a->mUnk_04 = 0;
    a->mUnk_08 = a->mUnk_0c;
    a->mUnk_10 = d;
    p = a->mUnk_08;
    for (i = 0; i < c; i++) {
        ((Unk0210e2c4 *) p)->mUnk_04 = 0;
        NNS_SndHandleInit(&((Unk0210e2c4 *) p)->mUnk_00);
        p += a->mUnk_10;
    }
}

void func_0210e280(Unk0217c7c4 *a) {
    s32 i;
    u8 *p;

    for (i = 0, p = a->mUnk_0c; i < a->mUnk_00; i++) {
        if (((Unk0210e2c4 *) p)->mUnk_00 != NULL) {
            ((Unk0210e2c4 *) p)->mUnk_04++;
        }
        p += a->mUnk_10;
    }
}

void *func_0210e128(Unk0217c7c4 *a) {
    s32 i;
    s32 t;
    s32 j;
    u8 *p;
    s32 n;
    s32 m;
    u8 *q;

    {
        s32 k;
        u8 *f;

        m = a->mUnk_04;
        t = -1;
        n = a->mUnk_00;
        f = NULL;
        j = -1;
        k = -1;
        q = NULL;
        p = a->mUnk_08;
        for (i = m; i < n; i++) {
            if (((Unk0210e2c4 *) p)->mUnk_00 == NULL) {
                f = p;
            } else {
                if (t < ((Unk0210e2c4 *) p)->mUnk_04) {
                    t = ((Unk0210e2c4 *) p)->mUnk_04;
                    j = i;
                    q = p;
                }
                f = NULL;
            }
            if (f != NULL) {
                k = i;
                break;
            }
            p += a->mUnk_10;
        }
        if (f == NULL) {
            p = a->mUnk_0c;
            for (i = 0; i < m; i++) {
                if (((Unk0210e2c4 *) p)->mUnk_00 == NULL) {
                    f = p;
                } else {
                    f = NULL;
                    if (t < ((Unk0210e2c4 *) p)->mUnk_04) {
                        t = ((Unk0210e2c4 *) p)->mUnk_04;
                        j = i;
                        q = p;
                    }
                }
                if (f != NULL) {
                    k = i;
                    break;
                }
                p += a->mUnk_10;
            }
        }
        if (f == NULL) {
            f = q;
            k = j;
            NNS_SndPlayerStopSeq(&((Unk0210e2c4 *) q)->mUnk_00, 0);
        }
        ((Unk0210e2c4 *) f)->mUnk_04 = 0;
        NNS_SndHandleInit(&((Unk0210e2c4 *) f)->mUnk_00);
        a->mUnk_04 = k;
        a->mUnk_04 = a->mUnk_04 + 1;
        a->mUnk_08 = f + a->mUnk_10;
        if (a->mUnk_04 >= a->mUnk_00) {
            a->mUnk_04 = 0;
            a->mUnk_08 = a->mUnk_0c;
        }
        return f;
    }
}

void func_0210e094(Unk0217d26c *a, s32 b, HeapStack *c) {
    s32 i;

    a->mUnk_00 = b;
    a->mUnk_04 = HeapStackAlloc(c, b << 4, NULL, NULL, 0);
    for (i = 0; i < a->mUnk_00; i++) {
        a->mUnk_04[i].mUnk_00 = -1;
        a->mUnk_04[i].mUnk_04 = NULL;
        a->mUnk_04[i].mUnk_08 = NULL;
        a->mUnk_04[i].mUnk_0c = 0;
    }
}

void func_0210e03c(Unk0217d26c *a) {
    s32 i;

    for (i = 0; i < a->mUnk_00; i++) {
        a->mUnk_04[i].mUnk_00 = -1;
        a->mUnk_04[i].mUnk_04 = NULL;
        a->mUnk_04[i].mUnk_08 = NULL;
        a->mUnk_04[i].mUnk_0c = 0;
    }
}

// The standalone copy expands itself twice before it calls itself.
#pragma inline_depth(2)
static inline void func_0210deac(Unk0217d26c *a, Unk0210ddf4 *b, s32 c) {
    Unk0210ddf4 v;

    for (; c < a->mUnk_00; c++) {
        if (b->mUnk_00 < a->mUnk_04[c].mUnk_00) {
            v = a->mUnk_04[c];
            a->mUnk_04[c] = *b;
            if (c + 1 < a->mUnk_00) {
                func_0210deac(a, &v, c + 1);
            }
            return;
        }
    }
}

void func_0210ddf4(Unk0217d26c *a, int b, void (*c)(void *, int), void *p, int d) {
    Unk0210ddf4 v;

    v.mUnk_00 = b;
    v.mUnk_08 = p;
    v.mUnk_0c = d;
    v.mUnk_04 = c;
    func_0210deac(a, &v, 0);
}

void func_0210dd44(Unk0217d26c *a) {
    s32 i;

    for (i = 0; i < a->mUnk_00; i++) {
        if (a->mUnk_04[i].mUnk_04 == NULL) {
            break;
        }
        a->mUnk_04[i].mUnk_04(a->mUnk_04[i].mUnk_08, a->mUnk_04[i].mUnk_0c);
    }
    for (i = 0; i < a->mUnk_00; i++) {
        a->mUnk_04[i].mUnk_00 = -1;
        a->mUnk_04[i].mUnk_04 = NULL;
        a->mUnk_04[i].mUnk_08 = NULL;
        a->mUnk_04[i].mUnk_0c = 0;
    }
}

u32 func_0210dccc(Unk0217d060 *a, u32 b, u32 c, u32 d, Unk0217c7b4 *e) {
    Unk0215c380 v;

    v.mUnk_00 = b;
    v.mUnk_04 = c;
    v.mUnk_08 = d;
    a->mUnk_00 = v;
    if (func_0210e3ec(e, a->mUnk_00) == 0) {
        func_0210e434(e);
        func_0210e33c(e, a->mUnk_00);
    }
    NNS_SndHandleInit(&a->mUnk_0c);
    data_0217d060 = a;
    a->mUnk_10 = e;
    return 1;
}

void func_0210dcb8(Unk0217d060 *a, u32 b) {
    func_0210d7dc(a->mUnk_00.mUnk_00, b, &a->mUnk_0c);
}

void func_0210dca8(Unk0217d060 *a, u32 b) {
    NNS_SndPlayerStopSeq(&a->mUnk_0c, b);
}

void func_0210dc7c(Unk0217d060 *a) {
    func_0210e434(a->mUnk_10);
    data_0217d060 = NULL;
}
