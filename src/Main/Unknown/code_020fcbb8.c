#include "Main/Unknown/code_020fcbb8.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_020fcf10.h"
#include "Main/Unknown/unk_027e0000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_02077bc0.h"

void func_020fce94(ItemKouraW *p0, s32 a, s32 b, s32 c, u16 d) {
    p0->mAngle += d;
    func_020fcf10(p0, b, (u16) p0->mAngle, c, a, 1, 1);
}

void func_020fcce4(ItemKouraW *p0, s32 a, s32 b) {
    Vec3 v;
    s32 f;
    Vec3 *v1;
    Vec3 *v2;
    Kart *p;

    p = p0->mKartItems->mKart;
    f = (p->mUnk_48 & 1) ? 1 : 0;
    p0->mUnk_22c = p->mUnk_05c;
    v1 = &p0->mUnk_000.mPos;
    v2 = &p0->mUnk_000.mVelocity;
    if (p->mUnk_44 & 0x100) {
        p0->mUnk_22c.x = -p0->mUnk_22c.x;
        p0->mUnk_22c.y = -p0->mUnk_22c.y;
        p0->mUnk_22c.z = -p0->mUnk_22c.z;
    }
    if (func_0206c0b0(p) == FALSE) {
        p0->mUnk_244 = p->mUnk_98;
    }
    VEC_MultAdd(0x14ffa, &p0->mUnk_22c, &p0->mUnk_244, &v);
    if (f == 0) {
        v.y += b;
    } else {
        VEC_MultAdd(b, &p->mUnk_244, &v, &v);
    }
    VEC_Subtract(&v, v1, &v);
    v2->x = ((s64) v.x * a) >> 12;
    v2->y = ((s64) v.y * a) >> 12;
    v2->z = ((s64) v.z * a) >> 12;
    VEC_Add(v2, v1, v1);
    if (f == 0) {
        return;
    }
    if (func_01ffdee4(v1, &p0->mUnk_000.mPrevPos, 0, p0->mUnk_000.mUnk_dc, 4, p0->mUnk_000.mUnk_da, &v, NULL, NULL,
                      NULL, NULL, NULL, NULL, NULL) == 0) {
        return;
    }
    VEC_Add(v1, &v, v1);
}

BOOL func_020fcbb8(ItemKouraW *p0, s32 v1) {
    Kart *p;
    KartItems *e;
    Vec3 v;
    Vec3 *q;
    s32 f;
    s32 n;
    s32 dx;
    s32 dz;

    p = GetKart(v1);
    if (func_0206c0b0(p) != FALSE) {
        return FALSE;
    }
    e = &(gKartItems)[v1];
    q = &p->mUnk_98;
    if (e->mUnk_1f0.mLink != p0->mUnk_168) {
        f = ((p0->mUnk_000.mFlags & 0x40000000) || (p->mUnk_48 & 1)) ? 1 : 0;
        VEC_Subtract(q, &p0->mUnk_000.mPos, &v);
        dx = v.x >> 12;
        dz = v.z >> 12;
        if (dx * dx + dz * dz > (f ? 0x9c40 : 0x27100)) {
            return FALSE;
        }
        n = Vec3DotUnrounded(&p0->mUnk_000.mUnk_f0, &v) >> 12;
        if (n * n > 0x9c4) {
            return FALSE;
        }
    }
    if (p0->mUnk_000.mFlags & 0x10000000) {
        return FALSE;
    }
    p0->mKartItems = e;
    p0->mUnk_244 = *q;
    return TRUE;
}
