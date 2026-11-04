#include "Main/Unknown/code_02081374.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0208b000.h"
#include "code_02147cd8.h"
#include "code_0201c528.h"

void func_0208155c(s32 a, s32 b) {
    Unk0201ca6c *p = data_0217ae84[a].mUnk_2c;

    if (p == NULL) {
        return;
    }
    p->mUnk_24.mUnk_00_3 = (b == 0);
}

void func_020813ec(s32 a, Vec3 *b) {
    Vec3s16 h;
    Vec3 v;
    Vec3 w;
    Kart *q = GetKart(a);
    Unk0217ae84 *e = &data_0217ae84[a];
    Unk0201ca6c *p;

    if ((q->mUnk_4c & 0x8000) && e->mUnk_28 == NULL && q->mVelocityLength > 0x1000) {
        p = func_0208b7bc(0x53, q->mUnk_508);
        p->mUnk_94 = q;
        p->mUnk_90 = func_02081374;
        e->mUnk_28 = p;
    }
    if (e->mUnk_28 == NULL) {
        return;
    }
    v.x = (s32) (((s64) q->mUnk_3b0.x * 0xccd) >> 12);
    v.y = (s32) (((s64) q->mUnk_3b0.y * 0xccd) >> 12);
    v.z = (s32) (((s64) q->mUnk_3b0.z * 0xccd) >> 12);
    e->mUnk_28->mUnk_40 = v;
    Vec3AddScaled(-q->mUnk_1d0, b, q->mUnk_508, &w);
    func_0208b5b0(e->mUnk_28, &w);
    h.x = b->x;
    h.y = b->y;
    h.z = b->z;
    e->mUnk_28->mUnk_50 = h;
    q->mUnk_48 |= 0x400;
}

void func_02081374(Unk0201ca6c *p, s32 a) {
    Kart *q;
    Unk0217ae84 *e;

    if (a != 0) {
        return;
    }
    q = p->mUnk_94;
    if ((q->mUnk_48 & 0x400) && (q->mUnk_44 & 0x80)) {
        if (q->mVelocityLength >= 0x1333) {
            return;
        }
    }
    e = &data_0217ae84[q->mIndex];
    if (p == e->mUnk_28) {
        p->mUnk_24.mUnk_00_0 = 1;
        e->mUnk_28 = NULL;
    }
}
