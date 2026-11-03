#include "01/code_02187d14.h"
#include "Main/Unknown/code_020ac524.h"
#include "Main/Unknown/code_020da628.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020fd264.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "01/code_021a2034.h"
#include "code_02147288.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020de9ec.h"
#include "01/unk_021a7000.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_02042000.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_020da000.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/code_020fd000.h"

void func_ov001_02187e48(Unk02188950 *a, s32 b) {
    s32 v;
    s32 n;

    v = a->mUnk_000.mCourseMapRow->mUnk_26;
    n = a->mUnk_148 + 1;
    if (n >= v + b) {
        n = v;
    }
    a->mUnk_148 = (u16) n;
    a->mUnk_14c = 0;
}

void *func_ov001_02187e00(u16 a) {
    Unk020ac524 *p;

    p = func_020ac524(0xc9);
    if (p != NULL) {
        func_020de9ec((u32) p);
        p->mUnk_f2 = a;
        p->mUnk_f4 = a;
        p->mUnk_ac = 1;
        return func_020fd338(p, 0xa000);
    }
    return NULL;
}

void *func_ov001_02187dd4(void) {
    void *p;

    p = func_020ac524(0x191);
    if (p != NULL) {
        func_020da628(p);
        return func_020fd338(p, 0);
    }
    return NULL;
}

void func_ov001_02187d14(Unk02187d14 *c) {
    Unk02012f58 a;
    Unk02012f58 b;
    Vec3 v;
    Unk02188950 *p;
    Unk02061808 *q;

    p = c->mUnk_04->mUnk_2c;
    if (c->mUnk_00->mUnk_01 == p->mUnk_2e4) {
        q = func_02061808();
        func_02012f58(&a, NULL);
        func_0214755c(&q->mUnk_030, &b);
        func_0214733c(&a, &b, &a);
        p->mUnk_2e8.x = a.mUnk_00[3].x << 4;
        p->mUnk_2e8.y = a.mUnk_00[3].y << 4;
        p->mUnk_2e8.z = a.mUnk_00[3].z << 4;
        if (p->mUnk_300 != NULL) {
            v = p->mUnk_2e8;
            func_02147fd8(p->mUnk_2f4.x, &a.mUnk_00[0], &v, &v);
            func_02147fd8(p->mUnk_2f4.y, &a.mUnk_00[1], &v, &v);
            func_02147fd8(p->mUnk_2f4.z, &a.mUnk_00[2], &v, &v);
            func_020fd684(p->mUnk_300, &a.mUnk_00[0], &v);
        }
    }
}
