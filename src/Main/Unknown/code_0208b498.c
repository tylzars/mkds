#include "Main/Unknown/code_0208b498.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"

Unk0201ca6c *func_0208b60c(s32 a, Vec3 *b) {
    Vec3 v;
    Unk0201ca6c *q;
    v.x = b->x >> 4;
    v.y = b->y >> 4;
    v.z = b->z >> 4;
    q = func_02018600(data_0217b04c, a, &v);
    if (q != NULL) {
        if (q->mUnk_20->mUnk_00->mUnk_54 & 0x80) {
            q->mUnk_80_16 = 1;
        } else if (q->mUnk_20->mUnk_00->mUnk_54 & 0x40) {
            q->mUnk_80_16 = 2;
        }
    }
    return q;
}

void func_0208b5b0(void *v1, const Vec3 *b) {
    Unk0201ca6c *a = v1;
    s32 c = b->x;
    s32 d = b->y;
    s32 e = b->z;
    a->mUnk_28.x = (c >> 4) + a->mUnk_20->mUnk_00->mUnk_04.x;
    a->mUnk_28.y = (d >> 4) + a->mUnk_20->mUnk_00->mUnk_04.y;
    a->mUnk_28.z = (e >> 4) + a->mUnk_20->mUnk_00->mUnk_04.z;
}

void *func_0208b498(u32 a, Vec3 *b, u32 c, s32 d) {
    s32 e;
    Vec3 w;
    Vec3 v;
    Unk0201ca6c *q;
    Unk020184e4 *p = data_0217b050(&e, a);
    v.x = b->x >> 4;
    v.y = b->y >> 4;
    v.z = b->z >> 4;
    q = func_02018600(p, e, &v);
    if (q != NULL) {
        if (q->mUnk_20->mUnk_00->mUnk_54 & 0x80) {
            q->mUnk_80_16 = 1;
        } else if (q->mUnk_20->mUnk_00->mUnk_54 & 0x40) {
            q->mUnk_80_16 = 2;
        }
    }
    if (q != NULL) {
        w = func_0207a974(c)->mUnk_3b0;
        w.x = ((s64) w.x * d) >> 12;
        w.y = ((s64) w.y * d) >> 12;
        w.z = ((s64) w.z * d) >> 12;
        q->mUnk_40 = w;
    }
    return q;
}
