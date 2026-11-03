#include "Main/Unknown/code_020fcf10.h"
#include "Main/Unknown/code_020fc2e8.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ee684.h"

void func_020fcf10(Unk020fc2e8 *p0, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    Vec3 t;
    Vec3 *v;
    Vec3 *v1;
    Vec3 *v2;
    Unk0206bcb0 *p;
    s32 s;

    p = p0->mUnk_228->mUnk_1fc;
    p0->mUnk_22c = p->mUnk_05c;
    v1 = &p0->mUnk_000.mUnk_50;
    v2 = &p0->mUnk_000.mUnk_5c;
    v = &p0->mUnk_238;
    if (p->mUnk_44 & 0x100) {
        p0->mUnk_22c.x = -p0->mUnk_22c.x;
        p0->mUnk_22c.y = -p0->mUnk_22c.y;
        p0->mUnk_22c.z = -p0->mUnk_22c.z;
    }
    func_020397a8(&p0->mUnk_22c, &p->mUnk_244, &t);
    s = (s32) (((s64) c * data_0215d4b4[(b >> 4) * 2 + 1]) >> 12);
    p0->mUnk_250.x = (s32) (((s64) t.x * s) >> 12);
    p0->mUnk_250.y = (s32) (((s64) t.y * s) >> 12);
    p0->mUnk_250.z = (s32) (((s64) t.z * s) >> 12);
    s = (s32) (((s64) c * data_0215d4b4[(b >> 4) * 2]) >> 12);
    func_02147fd8(s, &p0->mUnk_22c, &p0->mUnk_250, &p0->mUnk_250);
    func_02147fd8(0x1e000, &p0->mUnk_22c, &p0->mUnk_250, &t);
    if (func_0206c0b0(p) == 0) {
        p0->mUnk_244 = p->mUnk_98;
    }
    func_02148504(&t, &p0->mUnk_244, &t);
    func_021484d0(&t, v1, v);
    t.x = (s32) (((s64) v->x * d) >> 12);
    t.y = (s32) (((s64) v->y * d) >> 12);
    t.z = (s32) (((s64) v->z * d) >> 12);
    if ((s64) t.x * t.x + (s64) t.y * t.y + (s64) t.z * t.z >= (s64) a * a) {
        if ((s64) t.x * t.x + (s64) t.y * t.y + (s64) t.z * t.z >= 0x10) {
            func_02039860(&t, &t);
        }
        t.x = (s32) (((s64) t.x * a) >> 12);
        t.y = (s32) (((s64) t.y * a) >> 12);
        t.z = (s32) (((s64) t.z * a) >> 12);
    }
    v2->x = (v2->x * (s32) e + t.x) >> f;
    v2->y = (v2->y * (s32) e + t.y) >> f;
    v2->z = (v2->z * e + t.z) >> f;
    func_02148504(v2, v1, v1);
    if (func_01ffdee4(v1, &p0->mUnk_000.mUnk_0e4, 0, p0->mUnk_000.mUnk_dc, 4, p0->mUnk_000.mUnk_da, &t, NULL, NULL,
                      NULL, NULL, NULL, NULL, NULL) == 0) {
        return;
    }
    if ((p->mUnk_48 & 1) == 0) {
        v1->y += t.y;
        return;
    }
    func_02148504(v1, &t, v1);
}
