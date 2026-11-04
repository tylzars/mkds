#include "Main/Unknown/code_02046ad0.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_020fc2e8.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_020fcb9c.h"
#include "Main/Unknown/code_020fd254.h"
#include "Main/Unknown/code_0210a67c.h"
#include "Main/Unknown/code_0210b850.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/code_0210a000.h"
#include "Main/Unknown/code_020ee684.h"

void func_020fc94c(Unk020fc2e8 *p) {
    func_0210b850(&p->mUnk_300);
    p->mUnk_000.mUnk_00.mUnk_30 = (void (*)(void *, void *, void *)) func_0210a67c;
    p->mUnk_160 = 0;
    p->mUnk_000.mUnk_0c4 = p->mUnk_000.mUnk_50;
    func_020f9c40((s32) p);
    p->mUnk_000.mUnk_74 |= 0x200000;
    func_020fd254(p);
    if (data_0217561c->mUnk_4cc != 0) {
        p->mUnk_274 = 1;
        p->mUnk_276 = data_0217561c->mUnk_474[(p->mUnk_274 & 0xff) - 1];
    } else {
        p->mUnk_276 = data_0217561c->mUnk_474[(p->mUnk_274 & 0xff) - 1];
        while (func_0203c880(p->mUnk_276) != 0 && (u32) p->mUnk_274 < (u32) data_021759c0->mKartCount) {
            p->mUnk_274++;
            p->mUnk_276 = data_0217561c->mUnk_474[(p->mUnk_274 & 0xff) - 1];
        }
    }
    p->mUnk_260 = 0x32000;
    p->mUnk_264 = 0xf000;
    p->mUnk_268 = 0;
    p->mUnk_27c = 0x1a000;
    p->mUnk_298.x = 0;
    p->mUnk_298.y = 0;
    p->mUnk_298.z = 0;
    Vec3Sub(&p->mUnk_000.mUnk_5c, &p->mUnk_298, &p->mUnk_28c);
    p->mUnk_000.mUnk_d0 = &p->mUnk_000.mUnk_0c4;
    func_0208adc8(&p->mUnk_000.mUnk_7c, 1);
}

void func_020fc8ec(Unk020fc2e8 *e, s32 a) {
    Unk0206bcb0 *p;

    if (e->mUnk_228 != NULL) {
        return;
    }
    func_020fcb9c((s32) e, a);
    p = e->mUnk_228->mUnk_1fc;
    e->mUnk_2f8 = ((e->mUnk_000.mUnk_74 & 0x40000000) || (p->mUnk_48 & 1)) ? 2 : 3;
    e->mUnk_2fa = 1;
}

s32 func_020fc79c(Unk020eda5c *a, Unk020fc2e8 *e) {
    Unk0206bcb0 *p;

    func_020f9114(e);
    if (a->mUnk_00c->mUnk_1f0.mUnk_00 != NULL) {
        func_020ed268((Unk020ec8bc *) e, a, 0x14, 0xcc, 1, 1, 0, 0x6000, e->mUnk_276, 1);
        func_02046bcc(e->mUnk_2e8, 1);
    } else {
        func_020fcb9c((s32) e, (u16) data_0217561c->mUnk_474[0]);
        p = e->mUnk_228->mUnk_1fc;
        e->mUnk_2f8 = ((e->mUnk_000.mUnk_74 & 0x40000000) || (p->mUnk_48 & 1)) ? 2 : 3;
        e->mUnk_2fa = 1;
        if (e->mUnk_000.mUnk_74 & 0x8000000) {
            func_020fe71c(5, e->mUnk_228->mUnk_1f8, e->mUnk_000.mUnk_4e);
        }
    }
    func_020fc94c(e);
    // one 36-byte copy of the three vectors (three Vec3 assignments give 0x160 bytes against 0x150)
    *(Matrix3x3 *) &e->mUnk_000.mUnk_94 = *(Matrix3x3 *) &a->mUnk_02c.mUnk_00;
    if (e->mUnk_000.mUnk_74 & 0x8000000) {
        e->mUnk_2f8 = 0;
        e->mUnk_2fa = 1;
    }
    return 1;
}

void func_020fc654(Unk020fc2e8 *p) {
    Vec3 buf;
    s16 v;
    s32 a;

    a = p->mUnk_260;
    if (p->mUnk_000.mUnk_74 & 0x40000000) {
        p->mUnk_268 += 0x5dc;
        v = data_0215d4b4[(p->mUnk_268 >> 4) * 2];
        Vec3AddScaled(a + (s32) (((s64) p->mUnk_264 * v) >> 12), &p->mUnk_000.mUnk_f0, &p->mUnk_000.mUnk_50, &buf);
        Vec3Sub(&buf, &p->mUnk_000.mUnk_0c4, &buf);
        Vec3AddScaled(0x333, &buf, &p->mUnk_000.mUnk_0c4, &p->mUnk_000.mUnk_0c4);
    } else {
        p->mUnk_000.mUnk_0c4.y += p->mUnk_000.mUnk_5c.y >> 1;
        p->mUnk_268 += 0x5dc;
        v = data_0215d4b4[(p->mUnk_268 >> 4) * 2];
        a += (s32) (((s64) p->mUnk_264 * v) >> 12);
        a = a + p->mUnk_000.mUnk_50.y - p->mUnk_000.mUnk_0c4.y;
        p->mUnk_000.mUnk_0c4.y += (s32) (((s64) a * 0x19a) >> 12);
        p->mUnk_000.mUnk_0c4.x = p->mUnk_000.mUnk_50.x;
        p->mUnk_000.mUnk_0c4.z = p->mUnk_000.mUnk_50.z;
    }
}

void func_020fc2e8(Unk020fc2e8 *p, Vec3 *v, s32 v1, Vec3 *v2) {
    Vec3 buf;
    Vec3 v3;
    Vec3 *v4 = &p->mUnk_28c;
    Vec3 *v5 = &p->mUnk_298;
    s32 ok;

    if (v2 != NULL) {
        if ((s64) v->x * v->x + (s64) v->y * v->y + (s64) v->z * v->z >= 0x10) {
            func_02039860(v, &p->mUnk_000.mUnk_94.mUnk_00[2]);
        }
        v5->x = (s32) (((s64) v5->x * 0xccd) >> 12);
        v5->y = (s32) (((s64) v5->y * 0xccd) >> 12);
        v5->z = (s32) (((s64) v5->z * 0xccd) >> 12);
        Vec3AddScaled(0x3000, v5, v2, &buf);
        func_020397a8(&buf, &p->mUnk_000.mUnk_94.mUnk_00[2], &buf);
        if ((s64) buf.x * buf.x + (s64) buf.y * buf.y + (s64) buf.z * buf.z >= 0x10) {
            func_02039860(&buf, &p->mUnk_000.mUnk_94.mUnk_00[0]);
        }
    } else {
        if ((s64) v->x * v->x + (s64) v->y * v->y + (s64) v->z * v->z >= 0x10) {
            func_02039860(v, &buf);
        }
        if (buf.x * buf.x + buf.z * buf.z < 0x112510) {
            return;
        }
        p->mUnk_000.mUnk_94.mUnk_00[2] = buf;
        if (v1 != 0) {
            v5->x += (s32) (((s64) (v->x - v4->x - v5->x) * 0x148) >> 12);
            v5->z += (s32) (((s64) (v->z - v4->z - v5->z) * 0x148) >> 12);
        } else {
            v5->x = (s32) (((s64) v5->x * 0xc00) >> 12);
            v5->z = (s32) (((s64) v5->z * 0xc00) >> 12);
        }
        v3 = data_0216c6a8;
        v3.x = (s32) (((s64) v5->x * 0x3000) >> 12);
        v3.z = (s32) (((s64) v5->z * 0x3000) >> 12);
        buf = v3;
        func_020397a8(&buf, &p->mUnk_000.mUnk_94.mUnk_00[2], &p->mUnk_000.mUnk_94.mUnk_00[0]);
        if ((s64) p->mUnk_000.mUnk_94.mUnk_00[0].x * p->mUnk_000.mUnk_94.mUnk_00[0].x +
                (s64) p->mUnk_000.mUnk_94.mUnk_00[0].y * p->mUnk_000.mUnk_94.mUnk_00[0].y +
                (s64) p->mUnk_000.mUnk_94.mUnk_00[0].z * p->mUnk_000.mUnk_94.mUnk_00[0].z >=
            0x10) {
            ok = func_02039860(&p->mUnk_000.mUnk_94.mUnk_00[0], &p->mUnk_000.mUnk_94.mUnk_00[0]);
        } else {
            ok = 0;
        }
        if (ok == 0) {
            Vec3 t = {0, 0, 0};
            t.x = p->mUnk_000.mUnk_94.mUnk_00[0].z;
            t.z = -p->mUnk_000.mUnk_94.mUnk_00[0].x;
            p->mUnk_000.mUnk_94.mUnk_00[0] = t;
        }
    }
    func_020397a8(&p->mUnk_000.mUnk_94.mUnk_00[2], &p->mUnk_000.mUnk_94.mUnk_00[0], &p->mUnk_000.mUnk_94.mUnk_00[1]);
    *v4 = *v;
}
