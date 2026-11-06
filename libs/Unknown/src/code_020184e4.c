#include "code_020184e4.h"

#include "code_02146d78.h"
#include "code_02147288.h"
#include "code_02147cd8.h"
#include "code_0214a4dc.h"
#include "code_0214c1bc.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02173000.h"
#include "code_0214d018.h"
#include "registers.h"
#include "code_0201c4e8.h"
#include "code_0201c528.h"
#include "code_02146cbc.h"
#include "Main/Unknown/code_02146000.h"
#include "code_021471bc.h"

void SPLRandom_VecFx32(Vec3 *vec) {
    vec->x = (s32) (data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 8;
    vec->y = (s32) (data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 8;
    vec->z = (s32) (data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 8;
    VEC_Normalize(vec, vec);
}

void SPLRandom_VecFx32_XY(Vec3 *vec) {
    vec->x = (s32) (data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 8;
    vec->y = (s32) (data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 8;
    vec->z = 0;
    VEC_Normalize(vec, vec);
}

void SPLList_PushFront(Unk0201e494 *list, Unk0201e3c8 *node) {
    if (list->mUnk_00 == 0) {
        list->mUnk_00 = node;
        list->mUnk_08 = node;
        node->mUnk_00 = 0;
        node->mUnk_04 = node->mUnk_00;
    } else {
        node->mUnk_00 = list->mUnk_00;
        node->mUnk_04 = 0;
        list->mUnk_00->mUnk_04 = node;
        list->mUnk_00 = node;
    }
    list->mUnk_04++;
}

Unk0201e3c8 *SPLList_PopFront(Unk0201e494 *list) {
    Unk0201e3c8 *first;
    Unk0201e3c8 *node;

    node = 0;
    first = list->mUnk_00;
    if (first != 0) {
        node = first;
        list->mUnk_00 = first->mUnk_00;
        if (list->mUnk_00 != 0) {
            first->mUnk_00->mUnk_04 = 0;
        } else {
            list->mUnk_00 = 0;
            list->mUnk_08 = 0;
        }
        list->mUnk_04--;
    }
    return node;
}

Unk0201e3c8 *SPLList_Erase(Unk0201e494 *list, Unk0201e3c8 *node) {
    Unk0201e3c8 *next;

    next = node->mUnk_00;
    if (next == 0) {
        if (list->mUnk_00 == node) {
            list->mUnk_00 = 0;
            list->mUnk_08 = 0;
        } else {
            node->mUnk_04->mUnk_00 = 0;
            list->mUnk_08 = list->mUnk_08->mUnk_04;
        }
    } else {
        if (list->mUnk_00 == node) {
            list->mUnk_00 = next;
            list->mUnk_00->mUnk_04 = 0;
        } else {
            next->mUnk_04 = node->mUnk_04;
            node->mUnk_04->mUnk_00 = node->mUnk_00;
        }
    }
    list->mUnk_04--;
    return node;
}

void SPLBehavior_ApplyGravity(const Vec3s16 *gravity, Unk0201e3c8 *ptcl, Vec3 *acc, Unk0201ca6c *emtr) {
    acc->x = acc->x + gravity->x;
    acc->y = acc->y + gravity->y;
    acc->z = acc->z + gravity->z;
}

void SPLBehavior_ApplyRandom(const Unk0201e2cc *rng, Unk0201e3c8 *ptcl, Vec3 *acc, Unk0201ca6c *emtr) {
    if (ptcl->mUnk_26 % rng->mUnk_06 != 0) {
        return;
    }
    acc->x = acc->x + ((rng->mUnk_00 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) -
                        (rng->mUnk_00 << 8)) >>
                       8);
    acc->y = acc->y + ((rng->mUnk_02 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) -
                        (rng->mUnk_02 << 8)) >>
                       8);
    acc->z = acc->z + ((rng->mUnk_04 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) -
                        (rng->mUnk_04 << 8)) >>
                       8);
}

void SPLBehavior_ApplyMagnet(const Unk0201e248 *magnet, Unk0201e3c8 *ptcl, Vec3 *acc, Unk0201ca6c *emtr) {
    acc->x = acc->x + ((magnet->mUnk_0c * (magnet->mUnk_00.x - ptcl->mUnk_08.x - ptcl->mUnk_14.x)) >> 12);
    acc->y = acc->y + ((magnet->mUnk_0c * (magnet->mUnk_00.y - ptcl->mUnk_08.y - ptcl->mUnk_14.y)) >> 12);
    acc->z = acc->z + ((magnet->mUnk_0c * (magnet->mUnk_00.z - ptcl->mUnk_08.z - ptcl->mUnk_14.z)) >> 12);
}

void SPLBehavior_ApplySpin(const Unk0201e170 *spin, Unk0201e3c8 *ptcl, Vec3 *acc, Unk0201ca6c *emtr) {
    s32 buf[9];

    switch (spin->mUnk_02) {
        case 0:
            MTX_RotX33_(buf, gPairsByAngle[(spin->mUnk_00 >> 4) * 2], gPairsByAngle[(spin->mUnk_00 >> 4) * 2 + 1]);
            break;
        case 1:
            MTX_RotY33_(buf, gPairsByAngle[(spin->mUnk_00 >> 4) * 2], gPairsByAngle[(spin->mUnk_00 >> 4) * 2 + 1]);
            break;
        case 2:
            MTX_RotZ33_(buf, gPairsByAngle[(spin->mUnk_00 >> 4) * 2], gPairsByAngle[(spin->mUnk_00 >> 4) * 2 + 1]);
            break;
    }
    MTX_MultVec33(&ptcl->mUnk_08, buf, &ptcl->mUnk_08);
}

void SPLBehavior_ApplyCollisionPlane(const Unk0201e054 *plane, Unk0201e3c8 *ptcl, Vec3 *acc, Unk0201ca6c *emtr) {
    s32 lim;
    s32 y;

    lim = plane->mUnk_00;
    if (emtr->mUnk_74 != 0x80000000) {
        lim = emtr->mUnk_74;
    }
    switch (plane->mUnk_06_0) {
        case 0:
            y = ptcl->mUnk_38.y;
            if (y < lim) {
                if (y + ptcl->mUnk_08.y > lim) {
                    ptcl->mUnk_08.y = lim - y;
                    ptcl->mUnk_26 = ptcl->mUnk_24;
                    return;
                }
            }
            if (y >= lim) {
                if (y + ptcl->mUnk_08.y < lim) {
                    ptcl->mUnk_08.y = lim - y;
                    ptcl->mUnk_26 = ptcl->mUnk_24;
                }
            }
            break;
        case 1:
            y = ptcl->mUnk_38.y;
            if (y < lim && y + ptcl->mUnk_08.y > lim) {
                ptcl->mUnk_08.y = lim - y;
                ptcl->mUnk_14.y = -(s32) (((s64) ptcl->mUnk_14.y * plane->mUnk_04 + 0x800) >> 12);
            } else if (y >= lim && y + ptcl->mUnk_08.y < lim) {
                ptcl->mUnk_08.y = lim - y;
                ptcl->mUnk_14.y = -(s32) (((s64) ptcl->mUnk_14.y * plane->mUnk_04 + 0x800) >> 12);
            }
            break;
    }
}

void SPLBehavior_ApplyConvergence(const Unk0201e248 *conv, Unk0201e3c8 *ptcl, Vec3 *acc, Unk0201ca6c *emtr) {
    ptcl->mUnk_08.x =
        ptcl->mUnk_08.x + (s32) (((s64) conv->mUnk_0c * (conv->mUnk_00.x - ptcl->mUnk_08.x) + 0x800) >> 12);
    ptcl->mUnk_08.y =
        ptcl->mUnk_08.y + (s32) (((s64) conv->mUnk_0c * (conv->mUnk_00.y - ptcl->mUnk_08.y) + 0x800) >> 12);
    ptcl->mUnk_08.z =
        ptcl->mUnk_08.z + (s32) (((s64) conv->mUnk_0c * (conv->mUnk_00.z - ptcl->mUnk_08.z) + 0x800) >> 12);
}

void SPLAnim_Scale(Unk0201e3c8 *ptcl, Unk0201ca6c_20 *res, s32 lifeRate) {
    Unk0201ca6c_20_04 *scaleAnim;
    s32 a;
    s32 lo;
    s32 hi;

    scaleAnim = res->mUnk_04;
    lo = scaleAnim->mUnk_06;
    hi = scaleAnim->mUnk_07;
    if (lifeRate < lo) {
        a = scaleAnim->mUnk_00;
        ptcl->mUnk_34 = a + (lifeRate * (scaleAnim->mUnk_02 - a)) / lo;
        return;
    }
    if (lifeRate < hi) {
        ptcl->mUnk_34 = scaleAnim->mUnk_02;
        return;
    }
    a = scaleAnim->mUnk_04;
    ptcl->mUnk_34 = a + ((lifeRate - 0xff) * (a - scaleAnim->mUnk_02)) / (0xff - hi);
}

void SPLAnim_Color(Unk0201e3c8 *ptcl, Unk0201ca6c_20 *res, s32 lifeRate) {
    Unk0201ca6c_20_08 *colorAnim;
    Unk0201ca6c_20_00 *header;
    s32 lo;
    s32 mid;
    s32 hi;
    s32 br;
    s32 ar;
    s32 bg;
    s32 ag;
    s32 ab;
    s32 bb;
    s32 n;
    s32 m;

    colorAnim = res->mUnk_08;
    header = res->mUnk_00;
    lo = colorAnim->mUnk_04;
    mid = colorAnim->mUnk_05;
    hi = colorAnim->mUnk_06;
    if (lifeRate < lo) {
        ptcl->mUnk_36 = colorAnim->mUnk_00;
        return;
    }
    if (lifeRate < mid) {
        ar = colorAnim->mUnk_00 & 0x1f;
        ag = (colorAnim->mUnk_00 >> 5) & 0x1f;
        ab = (colorAnim->mUnk_00 >> 10) & 0x1f;
        br = header->mUnk_22 & 0x1f;
        bg = (header->mUnk_22 >> 5) & 0x1f;
        bb = (header->mUnk_22 >> 10) & 0x1f;
        if (colorAnim->mUnk_08_2 == 0) {
            ptcl->mUnk_36 = br | (bg << 5) | (bb << 10);
            return;
        }
        n = lifeRate - lo;
        m = mid - lo;
        ptcl->mUnk_36 =
            (ar + (n * (br - ar)) / m) | ((ag + (n * (bg - ag)) / m) << 5) | ((ab + (n * (bb - ab)) / m) << 10);
        return;
    }
    if (lifeRate < hi) {
        s32 cb; // PERM
        s32 er; // PERM
        s32 cr; // PERM
        s32 eg; // PERM
        s32 cg; // PERM
        s32 eb; // PERM
        er = header->mUnk_22 & 0x1f;
        eg = (header->mUnk_22 >> 5) & 0x1f;
        eb = (header->mUnk_22 >> 10) & 0x1f;
        cr = colorAnim->mUnk_02 & 0x1f;
        cg = (colorAnim->mUnk_02 >> 5) & 0x1f;
        cb = (colorAnim->mUnk_02 >> 10) & 0x1f;
        if (colorAnim->mUnk_08_2 == 0) {
            ptcl->mUnk_36 = cr | (cg << 5) | (cb << 10);
            return;
        }
        n = lifeRate - mid;
        m = hi - mid;
        ptcl->mUnk_36 =
            (er + (n * (cr - er)) / m) | ((eg + (n * (cg - eg)) / m) << 5) | ((eb + (n * (cb - eb)) / m) << 10);
        return;
    }
    ptcl->mUnk_36 = colorAnim->mUnk_02;
}

void SPLAnim_Alpha(Unk0201e3c8 *ptcl, Unk0201ca6c_20 *res, s32 lifeRate) {
    Unk0201ca6c_20_0c *alphaAnim;
    s32 a;
    s32 lo;
    s32 hi;

    alphaAnim = res->mUnk_0c;
    lo = alphaAnim->mUnk_04;
    hi = alphaAnim->mUnk_05;
    if (lifeRate < lo) {
        a = alphaAnim->mUnk_00_0 + (lifeRate * (alphaAnim->mUnk_00_5 - alphaAnim->mUnk_00_0)) / lo;
    } else if (lifeRate < hi) {
        a = alphaAnim->mUnk_00_5;
    } else {
        a = alphaAnim->mUnk_00_10 + ((lifeRate - 0xff) * (alphaAnim->mUnk_00_10 - alphaAnim->mUnk_00_5)) / (0xff - hi);
    }
    ptcl->mUnk_2e_5 =
        (a *
         (0xff -
          ((alphaAnim->mUnk_02_0 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 24)) >> 8))) >>
        8;
}

void SPLAnim_Texture(Unk0201e3c8 *ptcl, Unk0201ca6c_20 *res, s32 lifeRate) {
    Unk0201ca6c_20_10 *texAnim;
    s32 i;
    s32 s;
    s32 w;
    s32 n;

    texAnim = res->mUnk_10;
    i = 0;
    n = texAnim->mUnk_08_0;
    if (n <= 0) {
        return;
    }
    w = texAnim->mUnk_08_8;
    s = 0;
    do {
        if (lifeRate < s + w) {
            ptcl->mUnk_2c = texAnim->mUnk_00[i];
            return;
        }
        s += texAnim->mUnk_08_8;
        i++;
    } while (i < n);
}

void SPLAnim_ChildScale(Unk0201e3c8 *ptcl, Unk0201ca6c_20 *res, s32 lifeRate) {
    s32 a;

    a = res->mUnk_14->mUnk_04;
    ptcl->mUnk_34 = a + ((a - 0x1000) * (lifeRate - 0xff)) / 0xff;
}

void SPLAnim_ChildAlpha(Unk0201e3c8 *ptcl, Unk0201ca6c_20 *res, s32 lifeRate) {
    ptcl->mUnk_2e_5 = ((0xff - lifeRate) * 0x1f) / 0xff;
}

void SPLEmitter_ComputeOrthogonalAxes(Unk0201ca6c *emtr) {
    Vec3s16 up;
    Vec3s16 axis;
    s32 dot;

    up = data_02161ad0;
    switch (emtr->mUnk_20->mUnk_00->mUnk_00.mUnk_00_6) {
        case 2:
            axis.x = 0x1000;
            axis.y = 0;
            axis.z = 0;
            break;
        case 1:
            axis.x = 0;
            axis.y = 0x1000;
            axis.z = 0;
            break;
        case 0:
            axis.x = 0;
            axis.y = 0;
            axis.z = 0x1000;
            break;
        default:
            VEC_Fx16Normalize(&emtr->mUnk_50, &axis);
            break;
    }
    dot = VEC_Fx16DotProduct(&up, &axis);
    if (dot == 0x1000 || dot == -0x1000) {
        up.x = 0x1000;
        up.y = 0;
        up.z = 0;
    }
    emtr->mUnk_84.x = (s32) (((s64) axis.y * up.z + 0x800) >> 12) - (s32) (((s64) axis.z * up.y + 0x800) >> 12);
    emtr->mUnk_84.y = (s32) (((s64) axis.z * up.x + 0x800) >> 12) - (s32) (((s64) axis.x * up.z + 0x800) >> 12);
    emtr->mUnk_84.z = (s32) (((s64) axis.x * up.y + 0x800) >> 12) - (s32) (((s64) axis.y * up.x + 0x800) >> 12);
    emtr->mUnk_8a.x =
        (s32) (((s64) axis.y * emtr->mUnk_84.z + 0x800) >> 12) - (s32) (((s64) axis.z * emtr->mUnk_84.y + 0x800) >> 12);
    emtr->mUnk_8a.y =
        (s32) (((s64) axis.z * emtr->mUnk_84.x + 0x800) >> 12) - (s32) (((s64) axis.x * emtr->mUnk_84.z + 0x800) >> 12);
    emtr->mUnk_8a.z =
        (s32) (((s64) axis.x * emtr->mUnk_84.y + 0x800) >> 12) - (s32) (((s64) axis.y * emtr->mUnk_84.x + 0x800) >> 12);
    VEC_Fx16Normalize(&emtr->mUnk_84, &emtr->mUnk_84);
    VEC_Fx16Normalize(&emtr->mUnk_8a, &emtr->mUnk_8a);
}

void SPLUtil_TiltCoordinates(Vec3 *ptclPos, const Vec3 *pos, Unk0201ca6c *emtr) {
    Vec3s16 cross;

    VEC_Fx16CrossProduct(&emtr->mUnk_84, &emtr->mUnk_8a, &cross);
    VEC_Fx16Normalize(&cross, &cross);
    ptclPos->x =
        (s32) (((s64) pos->z * cross.x + 0x800) >> 12) + ((s32) (((s64) pos->x * emtr->mUnk_84.x + 0x800) >> 12) +
                                                          (s32) (((s64) pos->y * emtr->mUnk_8a.x + 0x800) >> 12));
    ptclPos->y =
        (s32) (((s64) pos->z * cross.y + 0x800) >> 12) + ((s32) (((s64) pos->x * emtr->mUnk_84.y + 0x800) >> 12) +
                                                          (s32) (((s64) pos->y * emtr->mUnk_8a.y + 0x800) >> 12));
    ptclPos->z =
        (s32) (((s64) pos->z * cross.z + 0x800) >> 12) + ((s32) (((s64) pos->x * emtr->mUnk_84.z + 0x800) >> 12) +
                                                          (s32) (((s64) pos->y * emtr->mUnk_8a.z + 0x800) >> 12));
}

void SPLEmitter_EmitParticles(Unk0201ca6c *emtr, Unk0201e494 *list) {
    Unk0201ca6c_20 *c;
    Unk0201ca6c_20_00 *d;
    Unk0201e3c8 *n0;
    s32 i;
    s32 n;
    s32 t;
    s32 s1;
    s32 s2;
    s32 acc;
    Vec3 v2;
    Vec3 v3;
    Vec3 v5;
    Vec3s16 a8;
    Vec3 v8;
    Vec3s16 a9;
    Vec3 v9;
    Vec3 v6;
    Vec3 v7;
    u16 ch[3];
    Vec3 u;
    Vec3 w;

    c = emtr->mUnk_20;
    t = emtr->mUnk_58 + emtr->mUnk_4e;
    d = c->mUnk_00;
    emtr->mUnk_4e = t & 0xfff;
    n = t >> 12;
    if (d->mUnk_00.mUnk_00_0 == 2 || d->mUnk_00.mUnk_00_0 == 3 || d->mUnk_00.mUnk_00_0 == 5 ||
        d->mUnk_00.mUnk_00_0 == 6 || d->mUnk_00.mUnk_00_0 == 7 || d->mUnk_00.mUnk_00_0 == 8 ||
        d->mUnk_00.mUnk_00_0 == 9) {
        SPLEmitter_ComputeOrthogonalAxes(emtr);
    }
    i = 0;
    if (i < n) {
        acc = 0;
        do {
            n0 = SPLList_PopFront(list);
            if (n0 == 0) {
                return;
            }
            SPLList_PushFront(&emtr->mUnk_08, n0);
            switch (d->mUnk_00.mUnk_00_0) {
                case 0:
                    n0->mUnk_08.x = n0->mUnk_08.y = n0->mUnk_08.z = 0;
                    break;
                case 1:
                    SPLRandom_VecFx32(&n0->mUnk_08);
                    n0->mUnk_08.x = ((s64) n0->mUnk_08.x * emtr->mUnk_5c + 0x800) >> 12;
                    n0->mUnk_08.y = ((s64) n0->mUnk_08.y * emtr->mUnk_5c + 0x800) >> 12;
                    n0->mUnk_08.z = ((s64) n0->mUnk_08.z * emtr->mUnk_5c + 0x800) >> 12;
                    break;
                case 2: {
                    SPLRandom_VecFx32_XY(&v2);
                    v2.x = ((s64) v2.x * emtr->mUnk_5c + 0x800) >> 12;
                    v2.y = ((s64) v2.y * emtr->mUnk_5c + 0x800) >> 12;
                    v2.z = 0;
                    SPLUtil_TiltCoordinates(&n0->mUnk_08, &v2, emtr);
                    break;
                }
                case 3: {
                    s32 k;
                    s32 a;
                    s32 b;
                    k = acc / n;
                    acc += 0x10000;
                    k >>= 4;
                    a = gPairsByAngle[k * 2];
                    b = gPairsByAngle[k * 2 + 1];
                    v3.x = ((s64) a * emtr->mUnk_5c + 0x800) >> 12;
                    v3.y = ((s64) b * emtr->mUnk_5c + 0x800) >> 12;
                    v3.z = 0;
                    SPLUtil_TiltCoordinates(&n0->mUnk_08, &v3, emtr);
                    break;
                }
                case 4: {
                    SPLRandom_VecFx32(&n0->mUnk_08);
                    n0->mUnk_08.x =
                        ((s64) (s32) (((s64) n0->mUnk_08.x * emtr->mUnk_5c + 0x800) >> 12) *
                             ((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                     0x100000) >>
                              8) +
                         0x800) >>
                        12;
                    n0->mUnk_08.y =
                        ((s64) (s32) (((s64) n0->mUnk_08.y * emtr->mUnk_5c + 0x800) >> 12) *
                             ((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                     0x100000) >>
                              8) +
                         0x800) >>
                        12;
                    n0->mUnk_08.z =
                        ((s64) (s32) (((s64) n0->mUnk_08.z * emtr->mUnk_5c + 0x800) >> 12) *
                             ((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                     0x100000) >>
                              8) +
                         0x800) >>
                        12;
                    break;
                }
                case 5: {
                    SPLRandom_VecFx32_XY(&v5);
                    v5.x = ((s64) (s32) (((s64) v5.x * emtr->mUnk_5c + 0x800) >> 12) *
                                ((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                        0x100000) >>
                                 8) +
                            0x800) >>
                           12;
                    v5.y = ((s64) (s32) (((s64) v5.y * emtr->mUnk_5c + 0x800) >> 12) *
                                ((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                        0x100000) >>
                                 8) +
                            0x800) >>
                           12;
                    SPLUtil_TiltCoordinates(&n0->mUnk_08, &v5, emtr);
                    break;
                }
                case 8: {
                    SPLRandom_VecFx32(&n0->mUnk_08);
                    VEC_Fx16CrossProduct(&emtr->mUnk_84, &emtr->mUnk_8a, &a8);
                    v8.x = a8.x;
                    v8.y = a8.y;
                    v8.z = a8.z;
                    if (VEC_DotProduct(&v8, &n0->mUnk_08) <= 0) {
                        n0->mUnk_08.x = -n0->mUnk_08.x;
                        n0->mUnk_08.y = -n0->mUnk_08.y;
                        n0->mUnk_08.z = -n0->mUnk_08.z;
                    }
                    n0->mUnk_08.x = ((s64) n0->mUnk_08.x * emtr->mUnk_5c + 0x800) >> 12;
                    n0->mUnk_08.y = ((s64) n0->mUnk_08.y * emtr->mUnk_5c + 0x800) >> 12;
                    n0->mUnk_08.z = ((s64) n0->mUnk_08.z * emtr->mUnk_5c + 0x800) >> 12;
                    break;
                }
                case 9: {
                    SPLRandom_VecFx32(&n0->mUnk_08);
                    VEC_Fx16CrossProduct(&emtr->mUnk_84, &emtr->mUnk_8a, &a9);
                    v9.x = a9.x;
                    v9.y = a9.y;
                    v9.z = a9.z;
                    if (VEC_DotProduct(&v9, &n0->mUnk_08) < 0) {
                        n0->mUnk_08.x = -n0->mUnk_08.x;
                        n0->mUnk_08.y = -n0->mUnk_08.y;
                        n0->mUnk_08.z = -n0->mUnk_08.z;
                    }
                    n0->mUnk_08.x =
                        ((s64) (s32) (((s64) n0->mUnk_08.x * emtr->mUnk_5c + 0x800) >> 12) *
                             (((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                      0x100000) >>
                               9) +
                              0x800) +
                         0x800) >>
                        12;
                    n0->mUnk_08.y =
                        ((s64) (s32) (((s64) n0->mUnk_08.y * emtr->mUnk_5c + 0x800) >> 12) *
                             (((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                      0x100000) >>
                               9) +
                              0x800) +
                         0x800) >>
                        12;
                    n0->mUnk_08.z =
                        ((s64) (s32) (((s64) n0->mUnk_08.z * emtr->mUnk_5c + 0x800) >> 12) *
                             (((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                      0x100000) >>
                               9) +
                              0x800) +
                         0x800) >>
                        12;
                    break;
                }
                case 6: {
                    SPLRandom_VecFx32_XY(&n0->mUnk_14);
                    v6.x = ((s64) n0->mUnk_14.x * emtr->mUnk_5c + 0x800) >> 12;
                    v6.y = ((s64) n0->mUnk_14.y * emtr->mUnk_5c + 0x800) >> 12;
                    v6.z = (emtr->mUnk_60 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) -
                            emtr->mUnk_60 * 0x100) >>
                           8;
                    SPLUtil_TiltCoordinates(&n0->mUnk_08, &v6, emtr);
                    break;
                }
                case 7: {
                    SPLRandom_VecFx32_XY(&n0->mUnk_14);
                    v7.x = ((s64) (s32) (((s64) n0->mUnk_14.x * emtr->mUnk_5c + 0x800) >> 12) *
                                ((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                        0x100000) >>
                                 8) +
                            0x800) >>
                           12;
                    v7.y = ((s64) (s32) (((s64) n0->mUnk_14.y * emtr->mUnk_5c + 0x800) >> 12) *
                                ((s32) (((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) * 0x1000 -
                                        0x100000) >>
                                 8) +
                            0x800) >>
                           12;
                    v7.z = (emtr->mUnk_60 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) -
                            emtr->mUnk_60 * 0x100) >>
                           8;
                    SPLUtil_TiltCoordinates(&n0->mUnk_08, &v7, emtr);
                    break;
                }
            }

            s1 = ((d->mUnk_42 + 0xff -
                   ((d->mUnk_42 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 24)) >> 7)) *
                  emtr->mUnk_64) >>
                 8;
            s2 = ((d->mUnk_42 + 0xff -
                   ((d->mUnk_42 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 24)) >> 7)) *
                  emtr->mUnk_68) >>
                 8;

            if (d->mUnk_00.mUnk_00_0 == 6) {
                w.x = (s32) (((s64) n0->mUnk_14.x * emtr->mUnk_84.x + 0x800) >> 12) +
                      (s32) (((s64) n0->mUnk_14.y * emtr->mUnk_8a.x + 0x800) >> 12);
                w.y = (s32) (((s64) n0->mUnk_14.x * emtr->mUnk_84.y + 0x800) >> 12) +
                      (s32) (((s64) n0->mUnk_14.y * emtr->mUnk_8a.y + 0x800) >> 12);
                w.z = (s32) (((s64) n0->mUnk_14.x * emtr->mUnk_84.z + 0x800) >> 12) +
                      (s32) (((s64) n0->mUnk_14.y * emtr->mUnk_8a.z + 0x800) >> 12);
                VEC_Normalize(&w, &u);
            } else if (n0->mUnk_08.x == 0 && n0->mUnk_08.y == 0 && n0->mUnk_08.z == 0) {
                SPLRandom_VecFx32(&u);
            } else {
                VEC_Normalize(&n0->mUnk_08, &u);
            }

            n0->mUnk_14.x = emtr->mUnk_40.x + ((s32) (((s64) u.x * s1 + 0x800) >> 12) +
                                               (s32) (((s64) emtr->mUnk_50.x * s2 + 0x800) >> 12));
            n0->mUnk_14.y = emtr->mUnk_40.y + ((s32) (((s64) u.y * s1 + 0x800) >> 12) +
                                               (s32) (((s64) emtr->mUnk_50.y * s2 + 0x800) >> 12));
            n0->mUnk_14.z = emtr->mUnk_40.z + ((s32) (((s64) u.z * s1 + 0x800) >> 12) +
                                               (s32) (((s64) emtr->mUnk_50.z * s2 + 0x800) >> 12));
            n0->mUnk_38 = emtr->mUnk_28;

            n0->mUnk_30 =
                ((d->mUnk_40 + 0xff -
                  ((d->mUnk_40 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 24)) >> 7)) *
                 emtr->mUnk_6c) >>
                8;
            n0->mUnk_34 = 0x1000;

            if (d->mUnk_00.mUnk_00_9 && c->mUnk_08->mUnk_08_0) {
                Unk0201ca6c_20_08 *q;
                u32 r;
                r = (data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 20;
                q = c->mUnk_08;
                ch[0] = q->mUnk_00;
                ch[1] = d->mUnk_22;
                ch[2] = q->mUnk_02;
                n0->mUnk_36 = ch[r % 3];
            } else {
                n0->mUnk_36 = d->mUnk_22;
            }

            n0->mUnk_2e_0 = emtr->mUnk_80_8;
            n0->mUnk_2e_5 = 0x1f;

            if (d->mUnk_00.mUnk_00_13) {
                n0->mUnk_20 = (data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173);
            } else {
                n0->mUnk_20 = emtr->mUnk_56;
            }

            if (d->mUnk_00.mUnk_00_12) {
                n0->mUnk_22 =
                    ((d->mUnk_36 - d->mUnk_34) * ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 20) +
                     (d->mUnk_34 << 12)) >>
                    12;
            } else {
                n0->mUnk_22 = 0;
            }

            n0->mUnk_24 =
                (((0xff -
                   ((d->mUnk_41 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 24)) >> 8)) *
                  emtr->mUnk_70) >>
                 8) +
                1;
            n0->mUnk_26 = 0;

            if (d->mUnk_00.mUnk_00_11 && c->mUnk_10->mUnk_08_16) {
                Unk0201ca6c_20_10 *q;
                u32 r;
                r = (data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 20;
                q = c->mUnk_10;
                n0->mUnk_2c = q->mUnk_00[r % q->mUnk_08_0];
            } else if (d->mUnk_00.mUnk_00_11 && !c->mUnk_10->mUnk_08_16) {
                n0->mUnk_2c = c->mUnk_10->mUnk_00[0];
            } else {
                n0->mUnk_2c = d->mUnk_47;
            }

            n0->mUnk_28 = 0xffff / c->mUnk_00->mUnk_48.mUnk_00_0;
            n0->mUnk_2a = 0xffff / n0->mUnk_24;
            n0->mUnk_2d = 0;
            if (d->mUnk_00.mUnk_00_20) {
                n0->mUnk_2d = (data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 24;
            }
        } while (++i < n);
    }
}

static inline s32 func_0201c74c_inline(s32 k0, Unk0201e3c8 *a) {
    return ((s64) a->mUnk_14.z * (s64) k0 + 0x800) >> 12;
}

static inline s32 func_0201c74c_inline2(s32 k0, Unk0201e3c8 *a) {
    return ((s64) a->mUnk_14.y * (s64) k0 + 0x800) >> 12;
}

static inline s32 func_0201c74c_inline3(s32 k0, Unk0201e3c8 *a) {
    return ((s64) a->mUnk_14.x * (s64) k0 + 0x800) >> 12;
}

static inline s32 func_0201c74c_inline4(Unk0201ca6c_20_14 *e) {
    return e->mUnk_09 + 1;
}

void SPLEmitter_EmitChildren(Unk0201e3c8 *ptcl, Unk0201ca6c *emtr, Unk0201e494 *list) {
    s32 k0;
    Unk0201e3c8 *n;
    s32 i;
    Unk0201ca6c_20_14 *e;
    Vec3 *d;
    u32 b;

    e = emtr->mUnk_20->mUnk_14;
    k0 = ((s64) (e->mUnk_08 << 12) * 16 + 0x800) >> 12;
    for (i = 0; i < e->mUnk_0c; i++) {
        {
            n = SPLList_PopFront(list);
            if (n == NULL) {
                return;
            }
            SPLList_PushFront(&emtr->mUnk_14, n);
            d = &n->mUnk_38;
            n->mUnk_08 = ptcl->mUnk_08;
            n->mUnk_14.x = func_0201c74c_inline3(k0, ptcl) +
                           ((e->mUnk_02 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) -
                             (e->mUnk_02 << 8)) >>
                            8);
            n->mUnk_14.y = func_0201c74c_inline2(k0, ptcl) +
                           ((e->mUnk_02 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) -
                             (e->mUnk_02 << 8)) >>
                            8);
            n->mUnk_14.z = func_0201c74c_inline(k0, ptcl) +
                           ((e->mUnk_02 * (s32) ((data_02173274 = data_02173274 * 0x5eedf715 + 0x1b0cb173) >> 23) -
                             (e->mUnk_02 << 8)) >>
                            8);
            *d = ptcl->mUnk_38;
            n->mUnk_30 = (((ptcl->mUnk_30 * ptcl->mUnk_34) >> 12) * func_0201c74c_inline4(e)) >> 6;
            n->mUnk_34 = 0x1000;
            if (e->mUnk_00_6) {
                n->mUnk_36 = e->mUnk_0a;
            } else {
                n->mUnk_36 = ptcl->mUnk_36;
            }
            n->mUnk_2e_0 = (ptcl->mUnk_2e_0 * (ptcl->mUnk_2e_5 + 1)) >> 5;
            n->mUnk_2e_5 = 0x1f;
            switch (e->mUnk_00_3) {
                case 2:
                    n->mUnk_20 = ptcl->mUnk_20;
                    n->mUnk_22 = ptcl->mUnk_22;
                    break;
                case 0:
                    n->mUnk_20 = 0;
                    n->mUnk_22 = 0;
                    break;
                case 1:
                    n->mUnk_20 = ptcl->mUnk_20;
                    n->mUnk_22 = 0;
                    break;
            }
            n->mUnk_24 = e->mUnk_06;
            n->mUnk_26 = 0;
            n->mUnk_2c = e->mUnk_0f;
            b = ptcl->mUnk_24;
            n->mUnk_28 = 0xffff / (s32) (b >> 1);
            n->mUnk_2a = 0xffff / ptcl->mUnk_24;
            n->mUnk_2d = 0;
        }
    }
}

void SPLUtil_DrawXYPlane(u32 a, u32 b, s32 c, s32 d) {
    u32 f;
    s32 s;

    reg_G3_BEGIN_VTXS = 1;
    s = ((s16) (d - 0x1000) >> 6) & 0x3ff;
    reg_G3_TEXCOORD = 0;
    reg_G3_VTX_10 = (((s16) (c - 0x1000) >> 6) & 0x3ff) | ((((s16) (d + 0x1000) >> 6) & 0x3ff) << 10);
    reg_G3_TEXCOORD = (a << 8) >> 16;
    f = (b << 8) >> 16;
    reg_G3_VTX_10 = (((s16) (c + 0x1000) >> 6) & 0x3ff) | ((((s16) (d + 0x1000) >> 6) & 0x3ff) << 10);
    reg_G3_TEXCOORD = ((a << 8) >> 16) | (f << 16);
    reg_G3_VTX_10 = (((s16) (c + 0x1000) >> 6) & 0x3ff) | (s << 10);
    reg_G3_TEXCOORD = f << 16;
    reg_G3_VTX_10 = (((s16) (c - 0x1000) >> 6) & 0x3ff) | (s << 10);
    reg_G3_END_VTXS = 0;
}

void SPLUtil_DrawXZPlane(u32 a, u32 b, s32 c, s32 d) {
    s32 r;
    u32 s;
    u32 e;
    u32 f;
    s32 p;
    s32 q;

    reg_G3_BEGIN_VTXS = 1;
    reg_G3_TEXCOORD = 0;
    q = ((s16) (c - 0x1000) >> 6) & 0x3ff;
    e = (a << 8) >> 16;
    f = (b << 8) >> 16;
    s = ((s16) (d - 0x1000) >> 6) & 0x3ff;
    p = ((s16) (d + 0x1000) >> 6) & 0x3ff;
    reg_G3_VTX_10 = q | (p << 20);
    reg_G3_TEXCOORD = e;
    r = ((s16) (c + 0x1000) >> 6) & 0x3ff;
    reg_G3_VTX_10 = r | (p << 20);
    reg_G3_TEXCOORD = e | (f << 16);
    reg_G3_VTX_10 = r | (s << 20);
    reg_G3_TEXCOORD = f << 16;
    reg_G3_VTX_10 = q | (s << 20);
    reg_G3_END_VTXS = 0;
}

void SPLUtil_RotateXYZ(s32 sinValue, s32 cosValue, MtxFx43 *mtx) {
    s32 t1;
    s32 t2;
    s32 x;
    s32 y;
    s32 z;

    t1 = ((s64) (0x1000 - cosValue) * (s64) 0x555 + 0x800) >> 12;
    t2 = ((s64) sinValue * (s64) 0x93d + 0x800) >> 12;
    y = t1 + t2;
    z = t1 - t2;
    x = t1 + cosValue;
    mtx->mUnk_00[0].x = x;
    mtx->mUnk_00[1].x = y;
    mtx->mUnk_00[2].x = z;
    mtx->mUnk_00[3].x = 0;
    mtx->mUnk_00[0].y = z;
    mtx->mUnk_00[1].y = x;
    mtx->mUnk_00[2].y = y;
    mtx->mUnk_00[3].y = 0;
    mtx->mUnk_00[0].z = y;
    mtx->mUnk_00[1].z = z;
    mtx->mUnk_00[2].z = x;
    mtx->mUnk_00[3].z = 0;
}

void SPLUtil_RotateY(s32 sinValue, s32 cosValue, MtxFx43 *mtx) {
    mtx->mUnk_00[0].x = cosValue;
    mtx->mUnk_00[1].x = 0;
    mtx->mUnk_00[2].x = sinValue;
    mtx->mUnk_00[3].x = 0;
    mtx->mUnk_00[0].y = 0;
    mtx->mUnk_00[1].y = 0x1000;
    mtx->mUnk_00[2].y = 0;
    mtx->mUnk_00[3].y = 0;
    mtx->mUnk_00[0].z = -sinValue;
    mtx->mUnk_00[1].z = 0;
    mtx->mUnk_00[2].z = cosValue;
    mtx->mUnk_00[3].z = 0;
}

void SPLDraw_Billboard(Unk020184e4 *mgr, Unk0201e3c8 *ptcl) {
    Vec3 t;
    MtxFx43 m;
    s32 k;
    s32 f0;
    s32 f1;
    s32 t0;
    s32 t1;
    u16 c0;
    u16 c1;
    s32 x;
    s32 y;
    s32 z;
    s32 s;
    MtxFx43 *q;
    u8 w;
    s32 h;

    s = mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_30;
    q = mgr->mUnk_44;
    w = mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_48.mUnk_00_28;
    h = ptcl->mUnk_34;
    c0 = ptcl->mUnk_36;
    c1 = mgr->mUnk_40->mUnk_72;
    k = (ptcl->mUnk_2e_0 * (ptcl->mUnk_2e_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->mUnk_2e_10 << 24) | (mgr->mUnk_3c | 0xc0) | (k << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (k == 0) {
        return;
    }
    f1 = ptcl->mUnk_30;
    f0 = ((s64) f1 * s + 0x800) >> 12;
    if (w == 0) {
        f0 = ((s64) f0 * h + 0x800) >> 12;
        f1 = ((s64) f1 * h + 0x800) >> 12;
    } else if (w == 1) {
        f0 = ((s64) f0 * h + 0x800) >> 12;
    } else {
        f1 = ((s64) f1 * h + 0x800) >> 12;
    }
    if (mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_00.mUnk_00_23 == 0) {
        t.x = ptcl->mUnk_08.x + ptcl->mUnk_38.x;
        t.y = ptcl->mUnk_08.y + ptcl->mUnk_38.y;
        t.z = ptcl->mUnk_08.z + ptcl->mUnk_38.z;
        MTX_MultVec43(&t, q, &t);
        t0 = gPairsByAngle[(ptcl->mUnk_20 >> 4) * 2];
        t1 = gPairsByAngle[(ptcl->mUnk_20 >> 4) * 2 + 1];
        m.mUnk_00[0].x = ((s64) t1 * f0 + 0x800) >> 12;
        m.mUnk_00[0].y = ((s64) t0 * f0 + 0x800) >> 12;
        m.mUnk_00[0].z = 0;
        m.mUnk_00[1].x = ((s64) -t0 * f1 + 0x800) >> 12;
        m.mUnk_00[1].y = ((s64) t1 * f1 + 0x800) >> 12;
        m.mUnk_00[1].z = 0;
        m.mUnk_00[2].x = 0;
        m.mUnk_00[2].y = 0;
        m.mUnk_00[2].z = 0x1000;
        m.mUnk_00[3].x = t.x;
        m.mUnk_00[3].y = t.y;
        m.mUnk_00[3].z = t.z;
        reg_G3_MTX_IDENTITY = 0;
        G3_MultMtx43(&m);
    } else {
        t.x = ptcl->mUnk_08.x + ptcl->mUnk_38.x - mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        t.y = ptcl->mUnk_08.y + ptcl->mUnk_38.y - mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        t.z = ptcl->mUnk_08.z + ptcl->mUnk_38.z - mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        MTX_MultVec43(&t, q, &t);
        t0 = gPairsByAngle[(ptcl->mUnk_20 >> 4) * 2];
        t1 = gPairsByAngle[(ptcl->mUnk_20 >> 4) * 2 + 1];
        m.mUnk_00[0].x = ((s64) t1 * f0 + 0x800) >> 12;
        m.mUnk_00[0].y = ((s64) t0 * f0 + 0x800) >> 12;
        m.mUnk_00[0].z = 0;
        m.mUnk_00[1].x = ((s64) -t0 * f1 + 0x800) >> 12;
        m.mUnk_00[1].y = ((s64) t1 * f1 + 0x800) >> 12;
        m.mUnk_00[1].z = 0;
        m.mUnk_00[2].x = 0;
        m.mUnk_00[2].y = 0;
        m.mUnk_00[2].z = 0x1000;
        m.mUnk_00[3].x = t.x;
        m.mUnk_00[3].y = t.y;
        m.mUnk_00[3].z = t.z;
        reg_G3_MTX_IDENTITY = 0;
        z = mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        y = mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        x = mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        reg_G3_MTX_TRANS = x;
        reg_G3_MTX_TRANS = y;
        reg_G3_MTX_TRANS = z;
        G3_MultMtx43(&m);
    }
    reg_G3_COLOR = (u16) ((((c0 & 0x1f) * (c1 & 0x1f)) >> 5) | ((((c0 & 0x3e0) * (c1 & 0x3e0)) >> 15) << 5) |
                          ((((c0 & 0x7c00) * (c1 & 0x7c00)) >> 25) << 10));
    SPLUtil_DrawXYPlane(mgr->mUnk_40->mUnk_78, mgr->mUnk_40->mUnk_7a, mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_50,
                        mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_52);
}

void SPLDraw_Child_Billboard(Unk020184e4 *mgr, Unk0201e3c8 *ptcl) {
    Vec3 t;
    MtxFx43 m;
    s32 k;
    s32 f0;
    s32 f1;
    s32 t0;
    s32 t1;
    u16 c0;
    u16 c1;
    s32 x;
    s32 y;
    s32 z;
    s32 s;
    MtxFx43 *q;

    s = mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_30;
    q = mgr->mUnk_44;
    k = (ptcl->mUnk_2e_0 * (ptcl->mUnk_2e_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->mUnk_2e_10 << 24) | (mgr->mUnk_3c | 0xc0) | (k << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (k == 0) {
        return;
    }
    f1 = ptcl->mUnk_30;
    f0 = ((s64) f1 * s + 0x800) >> 12;
    switch (mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_48.mUnk_00_28) {
        case 0:
            f0 = ((s64) f0 * ptcl->mUnk_34 + 0x800) >> 12;
            f1 = ((s64) f1 * ptcl->mUnk_34 + 0x800) >> 12;
            break;
        case 1:
            f0 = ((s64) f0 * ptcl->mUnk_34 + 0x800) >> 12;
            break;
        case 2:
            f1 = ((s64) f1 * ptcl->mUnk_34 + 0x800) >> 12;
            break;
    }
    if (mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_00.mUnk_00_23 == 0) {
        t.x = ptcl->mUnk_08.x + ptcl->mUnk_38.x;
        t.y = ptcl->mUnk_08.y + ptcl->mUnk_38.y;
        t.z = ptcl->mUnk_08.z + ptcl->mUnk_38.z;
        MTX_MultVec43(&t, q, &t);
        t0 = gPairsByAngle[(ptcl->mUnk_20 >> 4) * 2];
        t1 = gPairsByAngle[(ptcl->mUnk_20 >> 4) * 2 + 1];
        m.mUnk_00[0].x = ((s64) t1 * f0 + 0x800) >> 12;
        m.mUnk_00[0].y = ((s64) t0 * f0 + 0x800) >> 12;
        m.mUnk_00[0].z = 0;
        m.mUnk_00[1].x = ((s64) -t0 * f1 + 0x800) >> 12;
        m.mUnk_00[1].y = ((s64) t1 * f1 + 0x800) >> 12;
        m.mUnk_00[1].z = 0;
        m.mUnk_00[2].x = 0;
        m.mUnk_00[2].y = 0;
        m.mUnk_00[2].z = 0x1000;
        m.mUnk_00[3].x = t.x;
        m.mUnk_00[3].y = t.y;
        m.mUnk_00[3].z = t.z;
        reg_G3_MTX_IDENTITY = 0;
        G3_MultMtx43(&m);
    } else {
        t.x = ptcl->mUnk_08.x + ptcl->mUnk_38.x - mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        t.y = ptcl->mUnk_08.y + ptcl->mUnk_38.y - mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        t.z = ptcl->mUnk_08.z + ptcl->mUnk_38.z - mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        MTX_MultVec43(&t, q, &t);
        t0 = gPairsByAngle[(ptcl->mUnk_20 >> 4) * 2];
        t1 = gPairsByAngle[(ptcl->mUnk_20 >> 4) * 2 + 1];
        m.mUnk_00[0].x = ((s64) t1 * f0 + 0x800) >> 12;
        m.mUnk_00[0].y = ((s64) t0 * f0 + 0x800) >> 12;
        m.mUnk_00[0].z = 0;
        m.mUnk_00[1].x = ((s64) -t0 * f1 + 0x800) >> 12;
        m.mUnk_00[1].y = ((s64) t1 * f1 + 0x800) >> 12;
        m.mUnk_00[1].z = 0;
        m.mUnk_00[2].x = 0;
        m.mUnk_00[2].y = 0;
        m.mUnk_00[2].z = 0x1000;
        m.mUnk_00[3].x = t.x;
        m.mUnk_00[3].y = t.y;
        m.mUnk_00[3].z = t.z;
        reg_G3_MTX_IDENTITY = 0;
        z = mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        y = mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        x = mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        reg_G3_MTX_TRANS = x;
        reg_G3_MTX_TRANS = y;
        reg_G3_MTX_TRANS = z;
        G3_MultMtx43(&m);
    }
    c0 = ptcl->mUnk_36;
    c1 = mgr->mUnk_40->mUnk_72;
    reg_G3_COLOR = (u16) ((((c0 & 0x1f) * (c1 & 0x1f)) >> 5) | ((((c0 & 0x3e0) * (c1 & 0x3e0)) >> 15) << 5) |
                          ((((c0 & 0x7c00) * (c1 & 0x7c00)) >> 25) << 10));
    SPLUtil_DrawXYPlane(mgr->mUnk_40->mUnk_7c, mgr->mUnk_40->mUnk_7e, 0, 0);
}

void SPLDraw_DirectionalBillboard(Unk020184e4 *mgr, Unk0201e3c8 *ptcl) {
    Vec3 c;
    Vec3 pos;
    Vec3 v;
    Vec3 col;
    s32 m33[9];
    s32 buf[12];
    MtxFx43 *m;
    s32 a;
    s32 h;
    s32 w;
    s32 t;
    s32 u;
    s32 x;
    u16 k;
    u16 q;
    s16 s;
    s32 i;
    s32 j;
    s32 n;

    m = mgr->mUnk_44;
    s = mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_30;
    a = (ptcl->mUnk_2e_0 * (ptcl->mUnk_2e_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->mUnk_2e_10 << 24) | (mgr->mUnk_3c | 0xc0) | (a << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (a == 0) {
        return;
    }
    w = ptcl->mUnk_30;
    h = ((s64) w * s + 0x800) >> 12;
    switch (mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_48.mUnk_00_28) {
        case 0:
            h = ((s64) h * ptcl->mUnk_34 + 0x800) >> 12;
            w = ((s64) w * ptcl->mUnk_34 + 0x800) >> 12;
            break;
        case 1:
            h = ((s64) h * ptcl->mUnk_34 + 0x800) >> 12;
            break;
        case 2:
            w = ((s64) w * ptcl->mUnk_34 + 0x800) >> 12;
            break;
    }
    if (!mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_00.mUnk_00_23) {
        pos.x = ptcl->mUnk_08.x + ptcl->mUnk_38.x;
        pos.y = ptcl->mUnk_08.y + ptcl->mUnk_38.y;
        pos.z = ptcl->mUnk_08.z + ptcl->mUnk_38.z;
        v = ptcl->mUnk_14;
        col.x = m->mUnk_00[0].z;
        col.y = m->mUnk_00[1].z;
        col.z = m->mUnk_00[2].z;
        VEC_CrossProduct(&v, &col, &v);
        if (v.x == 0 && v.y == 0 && v.z == 0) {
            return;
        }
        VEC_Normalize(&v, &v);
        MI_Copy36B(m, m33);
        MTX_MultVec33(&v, m33, &v);
        MTX_MultVec43(&pos, m, &pos);
        c = ptcl->mUnk_14;
        VEC_Normalize(&c, &c);
        t = (s32) (((s64) c.x * -m->mUnk_00[0].z + 0x800) >> 12) +
            (s32) (((s64) c.y * -m->mUnk_00[1].z + 0x800) >> 12) + (s32) (((s64) c.z * -m->mUnk_00[2].z + 0x800) >> 12);
        if (t < 0) {
            t = -t;
        }
        u = ((s64) (0x1000 - t) * (s32) mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_48.mUnk_00_8 + 0x800) >> 12;
        x = ((s64) w * (u + 0x1000) + 0x800) >> 12;
        buf[0] = ((s64) v.x * h + 0x800) >> 12;
        buf[3] = ((s64) -v.y * x + 0x800) >> 12;
        buf[6] = 0;
        buf[9] = pos.x;
        buf[1] = ((s64) v.y * h + 0x800) >> 12;
        buf[4] = ((s64) v.x * x + 0x800) >> 12;
        buf[7] = 0;
        buf[10] = pos.y;
        buf[2] = 0;
        buf[5] = 0;
        buf[8] = 0x1000;
        buf[11] = pos.z;
        reg_G3_MTX_IDENTITY = 0;
        G3_MultMtx43(buf);
    } else {
        pos.x = ptcl->mUnk_08.x + ptcl->mUnk_38.x - mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        pos.y = ptcl->mUnk_08.y + ptcl->mUnk_38.y - mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        pos.z = ptcl->mUnk_08.z + ptcl->mUnk_38.z - mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        v = ptcl->mUnk_14;
        col.x = m->mUnk_00[0].z;
        col.y = m->mUnk_00[1].z;
        col.z = m->mUnk_00[2].z;
        VEC_CrossProduct(&v, &col, &v);
        if (v.x == 0 && v.y == 0 && v.z == 0) {
            return;
        }
        VEC_Normalize(&v, &v);
        MI_Copy36B(m, m33);
        MTX_MultVec33(&v, m33, &v);
        MTX_MultVec43(&pos, m, &pos);
        c = ptcl->mUnk_14;
        VEC_Normalize(&c, &c);
        t = (s32) (((s64) c.x * -m->mUnk_00[0].z + 0x800) >> 12) +
            (s32) (((s64) c.y * -m->mUnk_00[1].z + 0x800) >> 12) + (s32) (((s64) c.z * -m->mUnk_00[2].z + 0x800) >> 12);
        if (t < 0) {
            t = -t;
        }
        u = ((s64) (0x1000 - t) * (s32) mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_48.mUnk_00_8 + 0x800) >> 12;
        x = ((s64) w * (u + 0x1000) + 0x800) >> 12;
        buf[0] = ((s64) v.x * h + 0x800) >> 12;
        buf[3] = ((s64) -v.y * x + 0x800) >> 12;
        buf[6] = 0;
        buf[9] = pos.x;
        buf[1] = ((s64) v.y * h + 0x800) >> 12;
        buf[4] = ((s64) v.x * x + 0x800) >> 12;
        buf[7] = 0;
        buf[10] = pos.y;
        buf[2] = 0;
        buf[5] = 0;
        buf[8] = 0x1000;
        buf[11] = pos.z;
        reg_G3_MTX_IDENTITY = 0;
        n = mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        j = mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        i = mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        reg_G3_MTX_TRANS = i;
        reg_G3_MTX_TRANS = j;
        reg_G3_MTX_TRANS = n;
        G3_MultMtx43(buf);
    }
    q = ptcl->mUnk_36;
    k = mgr->mUnk_40->mUnk_72;
    reg_G3_COLOR = (u16) ((((q & 0x1f) * (k & 0x1f)) >> 5) | ((((q & 0x3e0) * (k & 0x3e0)) >> 15) << 5) |
                          ((((q & 0x7c00) * (k & 0x7c00)) >> 25) << 10));
    SPLUtil_DrawXYPlane(mgr->mUnk_40->mUnk_78, mgr->mUnk_40->mUnk_7a, mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_50,
                        mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_52);
}

void SPLDraw_Child_DirectionalBillboard(Unk020184e4 *mgr, Unk0201e3c8 *ptcl) {
    Vec3 c;
    Vec3 pos;
    Vec3 v;
    Vec3 col;
    s32 m33[9];
    s32 buf[12];
    MtxFx43 *m;
    s32 a;
    s32 h;
    s32 w;
    s32 t;
    s32 u;
    s32 x;
    u16 k;
    u16 q;
    s16 s;
    s32 i;
    s32 j;
    s32 n;

    m = mgr->mUnk_44;
    s = mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_30;
    a = (ptcl->mUnk_2e_0 * (ptcl->mUnk_2e_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->mUnk_2e_10 << 24) | (mgr->mUnk_3c | 0xc0) | (a << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (a == 0) {
        return;
    }
    w = ptcl->mUnk_30;
    h = ((s64) w * s + 0x800) >> 12;
    switch (mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_48.mUnk_00_28) {
        case 0:
            h = ((s64) h * ptcl->mUnk_34 + 0x800) >> 12;
            w = ((s64) w * ptcl->mUnk_34 + 0x800) >> 12;
            break;
        case 1:
            h = ((s64) h * ptcl->mUnk_34 + 0x800) >> 12;
            break;
        case 2:
            w = ((s64) w * ptcl->mUnk_34 + 0x800) >> 12;
            break;
    }
    if (!mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_00.mUnk_00_23) {
        pos.x = ptcl->mUnk_08.x + ptcl->mUnk_38.x;
        pos.y = ptcl->mUnk_08.y + ptcl->mUnk_38.y;
        pos.z = ptcl->mUnk_08.z + ptcl->mUnk_38.z;
        v = ptcl->mUnk_14;
        col.x = m->mUnk_00[0].z;
        col.y = m->mUnk_00[1].z;
        col.z = m->mUnk_00[2].z;
        VEC_CrossProduct(&v, &col, &v);
        if (v.x == 0 && v.y == 0 && v.z == 0) {
            return;
        }
        VEC_Normalize(&v, &v);
        MI_Copy36B(m, m33);
        MTX_MultVec33(&v, m33, &v);
        MTX_MultVec43(&pos, m, &pos);
        c = ptcl->mUnk_14;
        VEC_Normalize(&c, &c);
        t = (s32) (((s64) c.x * -m->mUnk_00[0].z + 0x800) >> 12) +
            (s32) (((s64) c.y * -m->mUnk_00[1].z + 0x800) >> 12) + (s32) (((s64) c.z * -m->mUnk_00[2].z + 0x800) >> 12);
        if (t < 0) {
            t = -t;
        }
        u = ((s64) (0x1000 - t) * (s32) mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_48.mUnk_00_8 + 0x800) >> 12;
        x = ((s64) w * (u + 0x1000) + 0x800) >> 12;
        buf[0] = ((s64) v.x * h + 0x800) >> 12;
        buf[3] = ((s64) -v.y * x + 0x800) >> 12;
        buf[6] = 0;
        buf[9] = pos.x;
        buf[1] = ((s64) v.y * h + 0x800) >> 12;
        buf[4] = ((s64) v.x * x + 0x800) >> 12;
        buf[7] = 0;
        buf[10] = pos.y;
        buf[2] = 0;
        buf[5] = 0;
        buf[8] = 0x1000;
        buf[11] = pos.z;
        reg_G3_MTX_IDENTITY = 0;
        G3_MultMtx43(buf);
    } else {
        pos.x = ptcl->mUnk_08.x + ptcl->mUnk_38.x - mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        pos.y = ptcl->mUnk_08.y + ptcl->mUnk_38.y - mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        pos.z = ptcl->mUnk_08.z + ptcl->mUnk_38.z - mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        v = ptcl->mUnk_14;
        col.x = m->mUnk_00[0].z;
        col.y = m->mUnk_00[1].z;
        col.z = m->mUnk_00[2].z;
        VEC_CrossProduct(&v, &col, &v);
        if (v.x == 0 && v.y == 0 && v.z == 0) {
            return;
        }
        VEC_Normalize(&v, &v);
        MI_Copy36B(m, m33);
        MTX_MultVec33(&v, m33, &v);
        MTX_MultVec43(&pos, m, &pos);
        c = ptcl->mUnk_14;
        VEC_Normalize(&c, &c);
        t = (s32) (((s64) c.x * -m->mUnk_00[0].z + 0x800) >> 12) +
            (s32) (((s64) c.y * -m->mUnk_00[1].z + 0x800) >> 12) + (s32) (((s64) c.z * -m->mUnk_00[2].z + 0x800) >> 12);
        if (t < 0) {
            t = -t;
        }
        u = ((s64) (0x1000 - t) * (s32) mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_48.mUnk_00_8 + 0x800) >> 12;
        x = ((s64) w * (u + 0x1000) + 0x800) >> 12;
        buf[0] = ((s64) v.x * h + 0x800) >> 12;
        buf[3] = ((s64) -v.y * x + 0x800) >> 12;
        buf[6] = 0;
        buf[9] = pos.x;
        buf[1] = ((s64) v.y * h + 0x800) >> 12;
        buf[4] = ((s64) v.x * x + 0x800) >> 12;
        buf[7] = 0;
        buf[10] = pos.y;
        buf[2] = 0;
        buf[5] = 0;
        buf[8] = 0x1000;
        buf[11] = pos.z;
        reg_G3_MTX_IDENTITY = 0;
        n = mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        j = mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        i = mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        reg_G3_MTX_TRANS = i;
        reg_G3_MTX_TRANS = j;
        reg_G3_MTX_TRANS = n;
        G3_MultMtx43(buf);
    }
    q = ptcl->mUnk_36;
    k = mgr->mUnk_40->mUnk_72;
    reg_G3_COLOR = (u16) ((((q & 0x1f) * (k & 0x1f)) >> 5) | ((((q & 0x3e0) * (k & 0x3e0)) >> 15) << 5) |
                          ((((q & 0x7c00) * (k & 0x7c00)) >> 25) << 10));
    SPLUtil_DrawXYPlane(mgr->mUnk_40->mUnk_7c, mgr->mUnk_40->mUnk_7e, 0, 0);
}

void SPLDraw_Polygon(Unk020184e4 *mgr, Unk0201e3c8 *ptcl) {
    MtxFx43 a;
    MtxFx43 b;
    MtxFx43 c;
    s32 k;
    s32 f0;
    s32 f1;
    u16 c0;
    u16 c1;
    s32 x;
    s32 y;
    s32 z;

    k = (ptcl->mUnk_2e_0 * (ptcl->mUnk_2e_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->mUnk_2e_10 << 24) | (mgr->mUnk_3c | 0xc0) | (k << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (k == 0) {
        return;
    }
    data_02161ac8[mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_00.mUnk_00_17](gPairsByAngle[(ptcl->mUnk_20 >> 4) * 2],
                                                                      gPairsByAngle[(ptcl->mUnk_20 >> 4) * 2 + 1], &b);
    f1 = ptcl->mUnk_30;
    f0 = ((s64) f1 * mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_30 + 0x800) >> 12;
    switch (mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_48.mUnk_00_28) {
        case 0:
            f0 = ((s64) f0 * ptcl->mUnk_34 + 0x800) >> 12;
            f1 = ((s64) f1 * ptcl->mUnk_34 + 0x800) >> 12;
            break;
        case 1:
            f0 = ((s64) f0 * ptcl->mUnk_34 + 0x800) >> 12;
            break;
        case 2:
            f1 = ((s64) f1 * ptcl->mUnk_34 + 0x800) >> 12;
            break;
    }
    MTX_Scale43_(&c, f0, f1, f1);
    MTX_Concat43(&c, &b, &a);
    if (mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_00.mUnk_00_23 == 0) {
        a.mUnk_00[3].x = ptcl->mUnk_08.x + ptcl->mUnk_38.x;
        a.mUnk_00[3].y = ptcl->mUnk_08.y + ptcl->mUnk_38.y;
        a.mUnk_00[3].z = ptcl->mUnk_08.z + ptcl->mUnk_38.z;
        G3_LoadMtx43(mgr->mUnk_44);
        G3_MultMtx43(&a);
    } else {
        a.mUnk_00[3].x = ptcl->mUnk_08.x + ptcl->mUnk_38.x - mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        a.mUnk_00[3].y = ptcl->mUnk_08.y + ptcl->mUnk_38.y - mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        a.mUnk_00[3].z = ptcl->mUnk_08.z + ptcl->mUnk_38.z - mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        reg_G3_MTX_IDENTITY = 0;
        z = mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        y = mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        x = mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        reg_G3_MTX_TRANS = x;
        reg_G3_MTX_TRANS = y;
        reg_G3_MTX_TRANS = z;
        G3_MultMtx43(mgr->mUnk_44);
        G3_MultMtx43(&a);
    }
    c0 = ptcl->mUnk_36;
    c1 = mgr->mUnk_40->mUnk_72;
    reg_G3_COLOR = (u16) ((((c0 & 0x1f) * (c1 & 0x1f)) >> 5) | ((((c0 & 0x3e0) * (c1 & 0x3e0)) >> 15) << 5) |
                          ((((c0 & 0x7c00) * (c1 & 0x7c00)) >> 25) << 10));
    data_02161ac0[mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_00.mUnk_00_19](mgr->mUnk_40->mUnk_78, mgr->mUnk_40->mUnk_7a,
                                                                      mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_50,
                                                                      mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_52);
}

void SPLDraw_Child_Polygon(Unk020184e4 *mgr, Unk0201e3c8 *ptcl) {
    MtxFx43 a;
    MtxFx43 b;
    MtxFx43 c;
    s32 k;
    s32 f0;
    s32 f1;
    u16 c0;
    u16 c1;
    s32 x;
    s32 y;
    s32 z;

    k = (ptcl->mUnk_2e_0 * (ptcl->mUnk_2e_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->mUnk_2e_10 << 24) | (mgr->mUnk_3c | 0xc0) | (k << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (k == 0) {
        return;
    }
    data_02161ac8[mgr->mUnk_40->mUnk_20->mUnk_14->mUnk_00_9](gPairsByAngle[(ptcl->mUnk_20 >> 4) * 2],
                                                             gPairsByAngle[(ptcl->mUnk_20 >> 4) * 2 + 1], &b);
    f1 = ptcl->mUnk_30;
    f0 = ((s64) f1 * mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_30 + 0x800) >> 12;
    switch (mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_48.mUnk_00_28) {
        case 0:
            f0 = ((s64) f0 * ptcl->mUnk_34 + 0x800) >> 12;
            f1 = ((s64) f1 * ptcl->mUnk_34 + 0x800) >> 12;
            break;
        case 1:
            f0 = ((s64) f0 * ptcl->mUnk_34 + 0x800) >> 12;
            break;
        case 2:
            f1 = ((s64) f1 * ptcl->mUnk_34 + 0x800) >> 12;
            break;
    }
    MTX_Scale43_(&c, f0, f1, f1);
    MTX_Concat43(&b, &c, &a);
    if (mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_00.mUnk_00_23 == 0) {
        a.mUnk_00[3].x = ptcl->mUnk_08.x + ptcl->mUnk_38.x;
        a.mUnk_00[3].y = ptcl->mUnk_08.y + ptcl->mUnk_38.y;
        a.mUnk_00[3].z = ptcl->mUnk_08.z + ptcl->mUnk_38.z;
        G3_LoadMtx43(mgr->mUnk_44);
        G3_MultMtx43(&a);
    } else {
        a.mUnk_00[3].x = ptcl->mUnk_08.x + ptcl->mUnk_38.x - mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        a.mUnk_00[3].y = ptcl->mUnk_08.y + ptcl->mUnk_38.y - mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        a.mUnk_00[3].z = ptcl->mUnk_08.z + ptcl->mUnk_38.z - mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        reg_G3_MTX_IDENTITY = 0;
        z = mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        y = mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        x = mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        reg_G3_MTX_TRANS = x;
        reg_G3_MTX_TRANS = y;
        reg_G3_MTX_TRANS = z;
        G3_MultMtx43(mgr->mUnk_44);
        G3_MultMtx43(&a);
    }
    c0 = ptcl->mUnk_36;
    c1 = mgr->mUnk_40->mUnk_72;
    reg_G3_COLOR = (u16) ((((c0 & 0x1f) * (c1 & 0x1f)) >> 5) | ((((c0 & 0x3e0) * (c1 & 0x3e0)) >> 15) << 5) |
                          ((((c0 & 0x7c00) * (c1 & 0x7c00)) >> 25) << 10));
    data_02161ac0[mgr->mUnk_40->mUnk_20->mUnk_14->mUnk_00_11](mgr->mUnk_40->mUnk_7c, mgr->mUnk_40->mUnk_7e, 0, 0);
}

void SPLDraw_DirectionalPolygon(Unk020184e4 *mgr, Unk0201e3c8 *ptcl) {
    MtxFx43 a;
    MtxFx43 b;
    MtxFx43 c;
    Vec3 v;
    Vec3 u;
    Vec3 w;
    Vec3 e;
    MtxFx43 d;
    s32 k;
    s32 f0;
    s32 f1;
    s32 s;
    u16 c0;
    u16 c1;
    s32 x;
    s32 y;
    s32 z;

    k = (ptcl->mUnk_2e_0 * (ptcl->mUnk_2e_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->mUnk_2e_10 << 24) | (mgr->mUnk_3c | 0xc0) | (k << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (k == 0) {
        return;
    }
    data_02161ac8[mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_00.mUnk_00_17](gPairsByAngle[(ptcl->mUnk_20 >> 4) * 2],
                                                                      gPairsByAngle[(ptcl->mUnk_20 >> 4) * 2 + 1], &b);
    MTX_Identity43_(&d);
    if (mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_48.mUnk_00_31 == 0) {
        VEC_Normalize(&ptcl->mUnk_14, &v);
    } else {
        VEC_Normalize(&ptcl->mUnk_08, &v);
        v.x = -v.x;
        v.y = -v.y;
        v.z = -v.z;
    }
    e.x = 0;
    e.y = 0x1000;
    e.z = 0;
    s = VEC_DotProduct(&v, &e);
    if (s > 0xccd || s < -0xccd) {
        e.x = 0x1000;
        e.y = 0;
        e.z = 0;
    }
    VEC_CrossProduct(&v, &e, &u);
    VEC_CrossProduct(&v, &u, &w);
    d.mUnk_00[0].x = u.x;
    d.mUnk_00[0].y = u.y;
    d.mUnk_00[0].z = u.z;
    d.mUnk_00[1].x = v.x;
    d.mUnk_00[1].y = v.y;
    d.mUnk_00[1].z = v.z;
    d.mUnk_00[2].x = w.x;
    d.mUnk_00[2].y = w.y;
    d.mUnk_00[2].z = w.z;
    MTX_Concat43(&b, &d, &b);
    f1 = ptcl->mUnk_30;
    f0 = ((s64) f1 * mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_30 + 0x800) >> 12;
    switch (mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_48.mUnk_00_28) {
        case 0:
            f0 = ((s64) f0 * ptcl->mUnk_34 + 0x800) >> 12;
            f1 = ((s64) f1 * ptcl->mUnk_34 + 0x800) >> 12;
            break;
        case 1:
            f0 = ((s64) f0 * ptcl->mUnk_34 + 0x800) >> 12;
            break;
        case 2:
            f1 = ((s64) f1 * ptcl->mUnk_34 + 0x800) >> 12;
            break;
    }
    MTX_Scale43_(&c, f0, f1, f1);
    MTX_Concat43(&c, &b, &a);
    if (mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_00.mUnk_00_23 == 0) {
        a.mUnk_00[3].x = ptcl->mUnk_08.x + ptcl->mUnk_38.x;
        a.mUnk_00[3].y = ptcl->mUnk_08.y + ptcl->mUnk_38.y;
        a.mUnk_00[3].z = ptcl->mUnk_08.z + ptcl->mUnk_38.z;
        G3_LoadMtx43(mgr->mUnk_44);
        G3_MultMtx43(&a);
    } else {
        a.mUnk_00[3].x = ptcl->mUnk_08.x + ptcl->mUnk_38.x - mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        a.mUnk_00[3].y = ptcl->mUnk_08.y + ptcl->mUnk_38.y - mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        a.mUnk_00[3].z = ptcl->mUnk_08.z + ptcl->mUnk_38.z - mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        reg_G3_MTX_IDENTITY = 0;
        z = mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        y = mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        x = mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        reg_G3_MTX_TRANS = x;
        reg_G3_MTX_TRANS = y;
        reg_G3_MTX_TRANS = z;
        G3_MultMtx43(mgr->mUnk_44);
        G3_MultMtx43(&a);
    }
    c0 = ptcl->mUnk_36;
    c1 = mgr->mUnk_40->mUnk_72;
    reg_G3_COLOR = (u16) ((((c0 & 0x1f) * (c1 & 0x1f)) >> 5) | ((((c0 & 0x3e0) * (c1 & 0x3e0)) >> 15) << 5) |
                          ((((c0 & 0x7c00) * (c1 & 0x7c00)) >> 25) << 10));
    data_02161ac0[mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_00.mUnk_00_19](mgr->mUnk_40->mUnk_78, mgr->mUnk_40->mUnk_7a,
                                                                      mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_50,
                                                                      mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_52);
}

void SPLDraw_Child_DirectionalPolygon(Unk020184e4 *mgr, Unk0201e3c8 *ptcl) {
    MtxFx43 a;
    MtxFx43 b;
    MtxFx43 c;
    Vec3 v;
    Vec3 u;
    Vec3 w;
    Vec3 e;
    MtxFx43 d;
    s32 k;
    s32 f0;
    s32 f1;
    s32 s;
    u16 c0;
    u16 c1;
    s32 x;
    s32 y;
    s32 z;

    k = (ptcl->mUnk_2e_0 * (ptcl->mUnk_2e_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (ptcl->mUnk_2e_10 << 24) | (mgr->mUnk_3c | 0xc0) | (k << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (k == 0) {
        return;
    }
    data_02161ac8[mgr->mUnk_40->mUnk_20->mUnk_14->mUnk_00_9](gPairsByAngle[(ptcl->mUnk_20 >> 4) * 2],
                                                             gPairsByAngle[(ptcl->mUnk_20 >> 4) * 2 + 1], &b);
    MTX_Identity43_(&d);
    if (mgr->mUnk_40->mUnk_20->mUnk_14->mUnk_10.mUnk_00_6 == 0) {
        VEC_Normalize(&ptcl->mUnk_14, &v);
    } else {
        VEC_Normalize(&ptcl->mUnk_08, &v);
        v.x = -v.x;
        v.y = -v.y;
        v.z = -v.z;
    }
    e.x = 0;
    e.y = 0x1000;
    e.z = 0;
    s = VEC_DotProduct(&v, &e);
    if (s > 0xccd || s < -0xccd) {
        e.x = 0x1000;
        e.y = 0;
        e.z = 0;
    }
    VEC_CrossProduct(&v, &e, &u);
    VEC_CrossProduct(&v, &u, &w);
    d.mUnk_00[0].x = u.x;
    d.mUnk_00[0].y = u.y;
    d.mUnk_00[0].z = u.z;
    d.mUnk_00[1].x = v.x;
    d.mUnk_00[1].y = v.y;
    d.mUnk_00[1].z = v.z;
    d.mUnk_00[2].x = w.x;
    d.mUnk_00[2].y = w.y;
    d.mUnk_00[2].z = w.z;
    MTX_Concat43(&b, &d, &b);
    f1 = ptcl->mUnk_30;
    f0 = ((s64) f1 * mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_30 + 0x800) >> 12;
    switch (mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_48.mUnk_00_28) {
        case 0:
            f0 = ((s64) f0 * ptcl->mUnk_34 + 0x800) >> 12;
            f1 = ((s64) f1 * ptcl->mUnk_34 + 0x800) >> 12;
            break;
        case 1:
            f0 = ((s64) f0 * ptcl->mUnk_34 + 0x800) >> 12;
            break;
        case 2:
            f1 = ((s64) f1 * ptcl->mUnk_34 + 0x800) >> 12;
            break;
    }
    MTX_Scale43_(&c, f0, f1, f1);
    MTX_Concat43(&b, &c, &a);
    if (mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_00.mUnk_00_23 == 0) {
        a.mUnk_00[3].x = ptcl->mUnk_08.x + ptcl->mUnk_38.x;
        a.mUnk_00[3].y = ptcl->mUnk_08.y + ptcl->mUnk_38.y;
        a.mUnk_00[3].z = ptcl->mUnk_08.z + ptcl->mUnk_38.z;
        G3_LoadMtx43(mgr->mUnk_44);
        G3_MultMtx43(&a);
    } else {
        a.mUnk_00[3].x = ptcl->mUnk_08.x + ptcl->mUnk_38.x - mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        a.mUnk_00[3].y = ptcl->mUnk_08.y + ptcl->mUnk_38.y - mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        a.mUnk_00[3].z = ptcl->mUnk_08.z + ptcl->mUnk_38.z - mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        reg_G3_MTX_IDENTITY = 0;
        z = mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        y = mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        x = mgr->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        reg_G3_MTX_TRANS = x;
        reg_G3_MTX_TRANS = y;
        reg_G3_MTX_TRANS = z;
        G3_MultMtx43(mgr->mUnk_44);
        G3_MultMtx43(&a);
    }
    c0 = ptcl->mUnk_36;
    c1 = mgr->mUnk_40->mUnk_72;
    reg_G3_COLOR = (u16) ((((c0 & 0x1f) * (c1 & 0x1f)) >> 5) | ((((c0 & 0x3e0) * (c1 & 0x3e0)) >> 15) << 5) |
                          ((((c0 & 0x7c00) * (c1 & 0x7c00)) >> 25) << 10));
    data_02161ac0[mgr->mUnk_40->mUnk_20->mUnk_14->mUnk_00_11](mgr->mUnk_40->mUnk_7c, mgr->mUnk_40->mUnk_7e, 0, 0);
}

typedef enum { UNK_02019DF8_KIND_0 } Unk02019df8_Kind;

static inline void func_02019df8_inline(u32 addr, Unk02019df8_Kind b0, Unk02019df8_Kind b4, Unk02019df8_Kind b8,
                                        Unk02019df8_Kind b12, Unk02019df8_Kind b14, Unk02019df8_Kind b16) {
    reg_G3_TEXIMAGE_PARAM =
        (addr >> 3) | (b0 << 26) | 0x40000000 | (b4 << 20) | (b8 << 23) | (b12 << 16) | (b14 << 18) | (b16 << 29);
}

void SPLUtil_SetTexture(Unk020184e4_2c *tex) {
    Unk020184e4_2c_0c w;
    u32 sx;
    u32 sy;

    w = tex->mUnk_0c;
    func_02019df8_inline(tex->mUnk_04, w.mUnk_00_0, w.mUnk_00_4, w.mUnk_00_8, w.mUnk_00_12, w.mUnk_00_14, w.mUnk_00_16);
    reg_G3_PLTT_BASE = tex->mUnk_08 >> (4 - (w.mUnk_00_0 == 2 ? 1 : 0));
    reg_G3_MTX_MODE = 3;
    reg_G3_MTX_IDENTITY = 0;
    sx = tex->mUnk_10 << 12;
    sy = tex->mUnk_12 << 12;
    reg_G3_MTX_SCALE = sx;
    reg_G3_MTX_SCALE = sy;
    reg_G3_MTX_SCALE = 0;
    reg_G3_MTX_MODE = 1;
}

void SPLUtil_SetTexture_Stub(Unk020184e4_2c *tex) {}

void SPLEmitter_Init(Unk0201ca6c *emtr, Unk0201ca6c_20 *res, Vec3 *pos) {
    Unk0201ca6c_20_00 *d;

    emtr->mUnk_20 = res;
    *(u32 *) &emtr->mUnk_24 = 0;
    emtr->mUnk_28.x = pos->x + emtr->mUnk_20->mUnk_00->mUnk_04.x;
    emtr->mUnk_28.y = pos->y + emtr->mUnk_20->mUnk_00->mUnk_04.y;
    emtr->mUnk_28.z = pos->z + emtr->mUnk_20->mUnk_00->mUnk_04.z;
    emtr->mUnk_40.x = 0;
    emtr->mUnk_40.y = 0;
    emtr->mUnk_40.z = 0;
    emtr->mUnk_34.x = emtr->mUnk_34.y = emtr->mUnk_34.z = 0;
    emtr->mUnk_4c = 0;
    emtr->mUnk_4e = 0;
    d = emtr->mUnk_20->mUnk_00;
    emtr->mUnk_50 = d->mUnk_1c;
    emtr->mUnk_56 = emtr->mUnk_20->mUnk_00->mUnk_38;
    emtr->mUnk_58 = emtr->mUnk_20->mUnk_00->mUnk_10;
    emtr->mUnk_5c = emtr->mUnk_20->mUnk_00->mUnk_14;
    emtr->mUnk_60 = emtr->mUnk_20->mUnk_00->mUnk_18;
    emtr->mUnk_64 = emtr->mUnk_20->mUnk_00->mUnk_24;
    emtr->mUnk_68 = emtr->mUnk_20->mUnk_00->mUnk_28;
    emtr->mUnk_6c = emtr->mUnk_20->mUnk_00->mUnk_2c;
    emtr->mUnk_70 = emtr->mUnk_20->mUnk_00->mUnk_3e;
    emtr->mUnk_72 = 0x7fff;
    emtr->mUnk_80_0 = emtr->mUnk_20->mUnk_00->mUnk_44;
    emtr->mUnk_80_8 = emtr->mUnk_20->mUnk_00->mUnk_45;
    emtr->mUnk_80_16 = 0;
    emtr->mUnk_80_19 = 0;
    emtr->mUnk_74 = 0x80000000;
    emtr->mUnk_78 = 0x1000 << emtr->mUnk_20->mUnk_00->mUnk_48.mUnk_00_24;
    emtr->mUnk_7a = 0x1000 << emtr->mUnk_20->mUnk_00->mUnk_48.mUnk_00_26;
    if (emtr->mUnk_20->mUnk_00->mUnk_4c_0) {
        emtr->mUnk_78 *= -1;
    }
    if (emtr->mUnk_20->mUnk_00->mUnk_4c_1) {
        emtr->mUnk_7a *= -1;
    }
    if (emtr->mUnk_20->mUnk_00->mUnk_00.mUnk_00_16) {
        emtr->mUnk_7c = 0x1000 << emtr->mUnk_20->mUnk_14->mUnk_10.mUnk_00_0;
        emtr->mUnk_7e = 0x1000 << emtr->mUnk_20->mUnk_14->mUnk_10.mUnk_00_2;
        if (emtr->mUnk_20->mUnk_14->mUnk_10.mUnk_00_4) {
            emtr->mUnk_7c *= -1;
        }
        if (emtr->mUnk_20->mUnk_14->mUnk_10.mUnk_00_5) {
            emtr->mUnk_7e *= -1;
        }
    }
    emtr->mUnk_00 = emtr->mUnk_04 = 0;
    emtr->mUnk_08.mUnk_00 = emtr->mUnk_14.mUnk_00 = 0;
    emtr->mUnk_08.mUnk_04 = emtr->mUnk_14.mUnk_04 = 0;
    emtr->mUnk_90 = 0;
    emtr->mUnk_94 = 0;
    emtr->mUnk_98 = 0;
}

void SPLEmitter_Update(Unk020184e4 *mgr, Unk0201ca6c *emtr) {
    Unk0201ca6c_20 *c;
    s32 cnt;
    Unk0201e3c8 *n0;
    s32 i;
    s32 n;
    Unk0201e3c8 *next;
    Unk0201ca6c_20_14 *e;
    Unk0201ca6c_20_00 *d;
    Unk0201ca6c_20_00_00 flags;
    s32 k0;
    s32 t;
    u8 b[2];
    Unk020192e0_28 tbl[4];
    Unk020192e0_28 tbl2[4];
    Vec3 v;

    c = emtr->mUnk_20;
    e = c->mUnk_14;
    d = c->mUnk_00;
    flags = d->mUnk_00;
    n = 0;
    k0 = d->mUnk_46 + 0x180;
    cnt = c->mUnk_1c;

    if (emtr->mUnk_90) {
        emtr->mUnk_90(emtr, 0);
    }

    if (d->mUnk_3c == 0 || emtr->mUnk_4c < d->mUnk_3c) {
        if (emtr->mUnk_4c % emtr->mUnk_80_0 == 0 && !emtr->mUnk_24.mUnk_00_0 && !emtr->mUnk_24.mUnk_00_1 &&
            emtr->mUnk_24.mUnk_00_4) {
            SPLEmitter_EmitParticles(emtr, &mgr->mUnk_04[2]);
        }
    }

    if (flags.mUnk_00_8) {
        tbl[n].mUnk_00 = SPLAnim_Scale;
        tbl[n++].mUnk_04 = c->mUnk_04->mUnk_08_0;
    }
    if (flags.mUnk_00_9 && !c->mUnk_08->mUnk_08_0) {
        tbl[n].mUnk_00 = SPLAnim_Color;
        tbl[n++].mUnk_04 = c->mUnk_08->mUnk_08_1;
    }
    if (flags.mUnk_00_10) {
        tbl[n].mUnk_00 = SPLAnim_Alpha;
        tbl[n++].mUnk_04 = c->mUnk_0c->mUnk_02_8;
    }
    if (flags.mUnk_00_11 && !c->mUnk_10->mUnk_08_16) {
        tbl[n].mUnk_00 = SPLAnim_Texture;
        tbl[n++].mUnk_04 = c->mUnk_10->mUnk_08_17;
    }

    for (n0 = emtr->mUnk_08.mUnk_00; n0; n0 = next) {
        next = n0->mUnk_00;
        b[0] = (n0->mUnk_2a * n0->mUnk_26) >> 8;
        b[1] = n0->mUnk_2d + ((n0->mUnk_28 * n0->mUnk_26) >> 8);
        for (i = 0; i < n; i++) {
            tbl[i].mUnk_00(n0, c, b[tbl[i].mUnk_04]);
        }
        v.x = v.y = v.z = 0;
        if (flags.mUnk_00_15) {
            n0->mUnk_38 = emtr->mUnk_28;
        }
        for (i = 0; i < cnt; i++) {
            c->mUnk_18[i].mUnk_00(c->mUnk_18[i].mUnk_04, n0, &v, emtr);
        }
        n0->mUnk_20 += n0->mUnk_22;
        n0->mUnk_14.x = (n0->mUnk_14.x * k0) >> 9;
        n0->mUnk_14.y = (n0->mUnk_14.y * k0) >> 9;
        n0->mUnk_14.z = (n0->mUnk_14.z * k0) >> 9;
        n0->mUnk_14.x += v.x;
        n0->mUnk_14.y += v.y;
        n0->mUnk_14.z += v.z;
        n0->mUnk_08.x += n0->mUnk_14.x + emtr->mUnk_34.x;
        n0->mUnk_08.y += n0->mUnk_14.y + emtr->mUnk_34.y;
        n0->mUnk_08.z += n0->mUnk_14.z + emtr->mUnk_34.z;
        if (flags.mUnk_00_16) {
            t = (n0->mUnk_26 << 12) - ((s32) (((s64) (n0->mUnk_24 << 12) * (e->mUnk_0d << 12) + 0x800) >> 12) >> 8);
            if (t >= 0 && (t >> 12) % e->mUnk_0e == 0) {
                SPLEmitter_EmitChildren(n0, emtr, &mgr->mUnk_04[2]);
            }
        }
        if (emtr->mUnk_20->mUnk_00->mUnk_00.mUnk_00_30) {
            n0->mUnk_2e_10 = mgr->mUnk_38_18;
        } else {
            n0->mUnk_2e_10 = mgr->mUnk_38_12;
            mgr->mUnk_38_12++;
            if (mgr->mUnk_38_12 > mgr->mUnk_38_6) {
                mgr->mUnk_38_12 = mgr->mUnk_38_0;
            }
        }
        n0->mUnk_26++;
        if (n0->mUnk_26 > n0->mUnk_24) {
            SPLList_PushFront(&mgr->mUnk_04[2], SPLList_Erase(&emtr->mUnk_08, n0));
        }
    }

    if (flags.mUnk_00_16) {
        n = 0;
        if (e->mUnk_00_1) {
            tbl2[n].mUnk_00 = SPLAnim_ChildScale;
            tbl2[n++].mUnk_04 = 0;
        }
        if (e->mUnk_00_2) {
            tbl2[n].mUnk_00 = SPLAnim_ChildAlpha;
            tbl2[n++].mUnk_04 = 0;
        }
        if (!e->mUnk_00_0) {
            cnt = 0;
        }
        for (n0 = emtr->mUnk_14.mUnk_00; n0; n0 = next) {
            next = n0->mUnk_00;
            b[0] = (n0->mUnk_26 << 8) / n0->mUnk_24;
            for (i = 0; i < n; i++) {
                tbl2[i].mUnk_00(n0, c, b[0]);
            }
            v.x = v.y = v.z = 0;
            if (e->mUnk_00_5) {
                n0->mUnk_38 = emtr->mUnk_28;
            }
            for (i = 0; i < cnt; i++) {
                c->mUnk_18[i].mUnk_00(c->mUnk_18[i].mUnk_04, n0, &v, emtr);
            }
            n0->mUnk_20 += n0->mUnk_22;
            n0->mUnk_14.x = (n0->mUnk_14.x * k0) >> 9;
            n0->mUnk_14.y = (n0->mUnk_14.y * k0) >> 9;
            n0->mUnk_14.z = (n0->mUnk_14.z * k0) >> 9;
            n0->mUnk_14.x += v.x;
            n0->mUnk_14.y += v.y;
            n0->mUnk_14.z += v.z;
            n0->mUnk_08.x += n0->mUnk_14.x + emtr->mUnk_34.x;
            n0->mUnk_08.y += n0->mUnk_14.y + emtr->mUnk_34.y;
            n0->mUnk_08.z += n0->mUnk_14.z + emtr->mUnk_34.z;
            if (emtr->mUnk_20->mUnk_00->mUnk_00.mUnk_00_31) {
                n0->mUnk_2e_10 = mgr->mUnk_38_18;
            } else {
                n0->mUnk_2e_10 = mgr->mUnk_38_12;
                mgr->mUnk_38_12++;
                if (mgr->mUnk_38_12 > mgr->mUnk_38_6) {
                    mgr->mUnk_38_12 = mgr->mUnk_38_0;
                }
            }
            n0->mUnk_26++;
            if (n0->mUnk_26 > n0->mUnk_24) {
                SPLList_PushFront(&mgr->mUnk_04[2], SPLList_Erase(&emtr->mUnk_14, n0));
            }
        }
    }

    emtr->mUnk_4c++;
    if (emtr->mUnk_90) {
        emtr->mUnk_90(emtr, 1);
    }
}

void SPLManager_DrawParticles(Unk020184e4 *mgr) {
    Unk0201ca6c *n;
    Unk0201ca6c_20_00 *d;
    void (*f)(Unk020184e4 *mgr, Unk0201e3c8 *b);
    void (*g)(Unk020184e4_2c *mgr);
    Unk0201e3c8 *e;

    n = mgr->mUnk_40;
    d = n->mUnk_20->mUnk_00;
    f = 0;
    SPLUtil_SetTexture(mgr->mUnk_2c + d->mUnk_47);
    switch (d->mUnk_00.mUnk_00_4) {
        case 0:
            f = SPLDraw_Billboard;
            break;
        case 1:
            f = SPLDraw_DirectionalBillboard;
            break;
        case 2:
            f = SPLDraw_Polygon;
            break;
        case 3:
            f = SPLDraw_DirectionalPolygon;
            break;
        case 4:
            f = SPLDraw_DirectionalPolygon;
            break;
    }
    if (d->mUnk_00.mUnk_00_11) {
        g = SPLUtil_SetTexture;
    } else {
        g = SPLUtil_SetTexture_Stub;
    }
    for (e = n->mUnk_08.mUnk_00; e != 0; e = e->mUnk_00) {
        g(mgr->mUnk_2c + e->mUnk_2c);
        f(mgr, e);
    }
}

void SPLManager_DrawChildParticles(Unk020184e4 *mgr) {
    Unk0201ca6c *n;
    Unk0201ca6c_20 *c;
    void (*f)(Unk020184e4 *mgr, Unk0201e3c8 *b);
    Unk0201e3c8 *e;

    n = mgr->mUnk_40;
    f = 0;
    c = n->mUnk_20;
    if (c->mUnk_00->mUnk_00.mUnk_00_16 == 0) {
        return;
    }
    SPLUtil_SetTexture(mgr->mUnk_2c + c->mUnk_14->mUnk_0f);
    switch (c->mUnk_14->mUnk_00_7) {
        case 0:
            f = SPLDraw_Child_Billboard;
            break;
        case 1:
            f = SPLDraw_Child_DirectionalBillboard;
            break;
        case 2:
            f = SPLDraw_Child_Polygon;
            break;
        case 3:
            f = SPLDraw_Child_DirectionalPolygon;
            break;
        case 4:
            f = SPLDraw_Child_DirectionalPolygon;
            break;
    }
    for (e = n->mUnk_14.mUnk_00; e != 0; e = e->mUnk_00) {
        f(mgr, e);
    }
}

void SPLManager_DoDraw(Unk020184e4 *mgr) {
    Unk0201ca6c_20_00 *d;

    d = mgr->mUnk_40->mUnk_20->mUnk_00;
    if (d->mUnk_00.mUnk_00_21) {
        SPLManager_DrawChildParticles(mgr);
        if (d->mUnk_00.mUnk_00_22) {
            return;
        }
        SPLManager_DrawParticles(mgr);
    } else {
        if (d->mUnk_00.mUnk_00_22 == 0) {
            SPLManager_DrawParticles(mgr);
        }
        SPLManager_DrawChildParticles(mgr);
    }
}

void SPLUtil_SetCylinderEmitterDir(Unk0201ca6c *emtr, Vec3 *p1, Vec3 *p2) {
    Vec3 dir;

    if (emtr->mUnk_20->mUnk_00->mUnk_00.mUnk_00_0 - 6 > 1) {
        return;
    }
    emtr->mUnk_28.x = (p2->x + p1->x) / 2;
    emtr->mUnk_28.y = (p2->y + p1->y) / 2;
    emtr->mUnk_28.z = (p2->z + p1->z) / 2;
    emtr->mUnk_60 = VEC_Distance(p1, p2) / 2;
    dir.x = p2->x - p1->x;
    dir.y = p2->y - p1->y;
    dir.z = p2->z - p1->z;
    VEC_Normalize(&dir, &dir);
    emtr->mUnk_50.x = dir.x;
    emtr->mUnk_50.y = dir.y;
    emtr->mUnk_50.z = dir.z;
}

u32 SPLUtil_AllocTextureVRAM(s32 size, s32 is4x4) {
    return (data_021619ec(size, is4x4, 0) & 0xffff) << 3;
}

u32 SPLUtil_AllocPaletteVRAM(s32 size, s32 is4Pltt) {
    return (data_021619f4(size, is4Pltt, 0) & 0xffff) << 3;
}

Unk020184e4 *SPLManager_New(void *(*alloc)(u32 size), u16 maxEmitters, u16 maxParticles, s32 fixPolyId, u16 minPolyId,
                            u16 maxPolyId) {
    Unk020184e4 *mgr;
    s32 i;
    u8 *block;

    mgr = alloc(0x4c);
    MI_CpuFill8(mgr, 0, 0x4c);
    mgr->mUnk_34 = maxEmitters;
    mgr->mUnk_36 = maxParticles;
    mgr->mUnk_38_0 = minPolyId;
    mgr->mUnk_38_6 = maxPolyId;
    mgr->mUnk_38_12 = mgr->mUnk_38_0;
    mgr->mUnk_38_18 = fixPolyId;
    mgr->mUnk_38_24 = 0;
    mgr->mUnk_38_25 = 0;
    mgr->mUnk_00 = alloc;
    mgr->mUnk_04[0].mUnk_04 = 0;
    mgr->mUnk_04[1].mUnk_04 = 0;
    mgr->mUnk_04[2].mUnk_04 = 0;
    mgr->mUnk_04[0].mUnk_00 = 0;
    mgr->mUnk_04[1].mUnk_00 = 0;
    mgr->mUnk_04[2].mUnk_00 = 0;
    mgr->mUnk_3c = 0;
    mgr->mUnk_48 = 0;
    block = alloc(maxEmitters * 0x9c);
    MI_CpuFill8(block, 0, maxEmitters * 0x9c);
    for (i = 0; i < maxEmitters; i++) {
        SPLList_PushFront(&mgr->mUnk_04[1], (Unk0201e3c8 *) block);
        block += 0x9c;
    }
    block = alloc(maxParticles * 0x44);
    MI_CpuFill8(block, 0, maxParticles * 0x44);
    for (i = 0; i < maxParticles; i++) {
        SPLList_PushFront(&mgr->mUnk_04[2], (Unk0201e3c8 *) block);
        block += 0x44;
    }
    mgr->mUnk_28 = 0;
    mgr->mUnk_2c = 0;
    mgr->mUnk_32 = 0;
    mgr->mUnk_30 = mgr->mUnk_32;
    return mgr;
}

void SPLManager_LoadResources(Unk020184e4 *mgr, Unk02018a1c *data) {
    s32 i;
    s32 off;
    Unk0201ca6c_20 *e;
    Unk0201ca6c_20_00_00 flags;
    Unk0201ca6c_20_18 *g;
    Unk020184e4_2c *h;
    Unk020184e4_2c_00 *d;

    off = 0x20;
    mgr->mUnk_30 = data->mUnk_08;
    mgr->mUnk_32 = data->mUnk_0a;
    mgr->mUnk_28 = mgr->mUnk_00(mgr->mUnk_30 << 5);
    MI_CpuFill8(mgr->mUnk_28, 0, mgr->mUnk_30 << 5);
    for (i = 0; i < mgr->mUnk_30; i++) {
        e = mgr->mUnk_28 + i;
        e->mUnk_00 = OFFSET_PTR(Unk0201ca6c_20_00, data, off);
        off += 0x58;
        flags = e->mUnk_00->mUnk_00;
        if (flags.mUnk_00_8) {
            e->mUnk_04 = OFFSET_PTR(Unk0201ca6c_20_04, data, off);
            off += 0xc;
        } else {
            e->mUnk_04 = 0;
        }
        if (flags.mUnk_00_9) {
            e->mUnk_08 = OFFSET_PTR(Unk0201ca6c_20_08, data, off);
            off += 0xc;
        } else {
            e->mUnk_08 = 0;
        }
        if (flags.mUnk_00_10) {
            e->mUnk_0c = OFFSET_PTR(Unk0201ca6c_20_0c, data, off);
            off += 8;
        } else {
            e->mUnk_0c = 0;
        }
        if (flags.mUnk_00_11) {
            e->mUnk_10 = OFFSET_PTR(Unk0201ca6c_20_10, data, off);
            off += 0xc;
        } else {
            e->mUnk_10 = 0;
        }
        if (flags.mUnk_00_16) {
            e->mUnk_14 = OFFSET_PTR(Unk0201ca6c_20_14, data, off);
            off += 0x14;
        } else {
            e->mUnk_14 = 0;
        }
        e->mUnk_1c = flags.mUnk_00_24 + flags.mUnk_00_25 + flags.mUnk_00_26 + flags.mUnk_00_27 + flags.mUnk_00_28 +
                     flags.mUnk_00_29;
        if (e->mUnk_1c != 0) {
            e->mUnk_18 = mgr->mUnk_00(e->mUnk_1c << 3);
            g = e->mUnk_18;
            if (flags.mUnk_00_24) {
                g->mUnk_04 = (u8 *) data + off;
                g->mUnk_00 = SPLBehavior_ApplyGravity;
                off += 8;
                g++;
            }
            if (flags.mUnk_00_25) {
                g->mUnk_04 = (u8 *) data + off;
                g->mUnk_00 = SPLBehavior_ApplyRandom;
                off += 8;
                g++;
            }
            if (flags.mUnk_00_26) {
                g->mUnk_04 = (u8 *) data + off;
                g->mUnk_00 = SPLBehavior_ApplyMagnet;
                off += 0x10;
                g++;
            }
            if (flags.mUnk_00_27) {
                g->mUnk_04 = (u8 *) data + off;
                g->mUnk_00 = SPLBehavior_ApplySpin;
                off += 4;
                g++;
            }
            if (flags.mUnk_00_28) {
                g->mUnk_04 = (u8 *) data + off;
                g->mUnk_00 = SPLBehavior_ApplyCollisionPlane;
                off += 8;
                g++;
            }
            if (flags.mUnk_00_29) {
                g->mUnk_04 = (u8 *) data + off;
                g->mUnk_00 = SPLBehavior_ApplyConvergence;
                off += 0x10;
            }
        } else {
            e->mUnk_18 = 0;
        }
    }
    mgr->mUnk_2c = mgr->mUnk_00(mgr->mUnk_32 * 0x14);
    MI_CpuFill8(mgr->mUnk_2c, 0, mgr->mUnk_32 * 0x14);
    for (i = 0; i < mgr->mUnk_32; i++) {
        h = mgr->mUnk_2c + i;
        d = OFFSET_PTR(Unk020184e4_2c_00, data, off);
        h->mUnk_00 = d;
        h->mUnk_10 = 1 << (d->mUnk_04.mUnk_00_4 + 3);
        h->mUnk_12 = 1 << (d->mUnk_04.mUnk_00_8 + 3);
        h->mUnk_0c = d->mUnk_04;
        off += d->mUnk_1c;
    }
}

s32 SPLManager_UploadTexturesEx(Unk020184e4 *mgr, u32 (*vramAlloc)(s32 size, s32 isSpecial)) {
    s32 i;
    Unk020184e4_2c *e;
    Unk020184e4_2c_00 *d;
    u32 t;

    GX_BeginLoadTex();
    for (i = 0; i < mgr->mUnk_32; i++) {
        e = mgr->mUnk_2c + i;
        d = e->mUnk_00;
        if (d->mUnk_04.mUnk_00_17) {
            e->mUnk_04 = mgr->mUnk_2c[d->mUnk_04.mUnk_00_18].mUnk_04;
        } else {
            t = vramAlloc(d->mUnk_08, d->mUnk_04.mUnk_00_0 == 5 ? 1 : 0);
            GX_LoadTex((u8 *) e->mUnk_00 + 0x20, t, d->mUnk_08);
            e->mUnk_04 = t;
        }
    }
    GX_EndLoadTex();
    return 1;
}

s32 SPLManager_UploadPalettesEx(Unk020184e4 *mgr, u32 (*vramAlloc)(s32 size, s32 isSpecial)) {
    s32 i;
    Unk020184e4_2c *e;
    Unk020184e4_2c_00 *d;
    u32 t;

    GX_BeginLoadTexPltt();
    for (i = 0; i < mgr->mUnk_32; i++) {
        e = mgr->mUnk_2c + i;
        d = e->mUnk_00;
        t = 0;
        if (d->mUnk_10 != 0) {
            t = vramAlloc(d->mUnk_10, d->mUnk_04.mUnk_00_0 == 2 ? 1 : 0);
            GX_LoadTexPltt((u8 *) e->mUnk_00 + d->mUnk_0c, t, d->mUnk_10);
        }
        e->mUnk_08 = t;
    }
    GX_EndLoadTexPltt();
    return 1;
}

s32 SPLManager_UploadTextures(Unk020184e4 *mgr) {
    return SPLManager_UploadTexturesEx(mgr, SPLUtil_AllocTextureVRAM);
}

s32 SPLManager_UploadPalettes(Unk020184e4 *mgr) {
    return SPLManager_UploadPalettesEx(mgr, SPLUtil_AllocPaletteVRAM);
}

void SPLManager_Update(Unk020184e4 *mgr) {
    Unk0201ca6c *emtr;
    Unk0201ca6c *next;
    Unk0201ca6c_20_00 *header;

    for (emtr = (Unk0201ca6c *) mgr->mUnk_04[0].mUnk_00; emtr != 0; emtr = next) {
        header = emtr->mUnk_20->mUnk_00;
        next = emtr->mUnk_00;
        if (emtr->mUnk_24.mUnk_00_4 == 0) {
            if (emtr->mUnk_4c >= header->mUnk_32) {
                emtr->mUnk_24.mUnk_00_4 = 1;
                emtr->mUnk_4c = 0;
            }
        }
        if (emtr->mUnk_24.mUnk_00_2 == 0) {
            if (emtr->mUnk_80_16 == 0 || mgr->mUnk_48 == emtr->mUnk_80_16 - 1) {
                SPLEmitter_Update(mgr, emtr);
            }
        }
        if ((header->mUnk_00.mUnk_00_14 && header->mUnk_3c != 0 && emtr->mUnk_24.mUnk_00_4 != 0 &&
             emtr->mUnk_4c > header->mUnk_3c) ||
            emtr->mUnk_24.mUnk_00_0 != 0) {
            if (emtr->mUnk_08.mUnk_04 == 0 && emtr->mUnk_14.mUnk_04 == 0) {
                SPLList_PushFront(&mgr->mUnk_04[1], SPLList_Erase(&mgr->mUnk_04[0], (Unk0201e3c8 *) emtr));
            }
        }
    }
    mgr->mUnk_48++;
    if (mgr->mUnk_48 > 1) {
        mgr->mUnk_48 = 0;
    }
}

void SPLManager_Draw(Unk020184e4 *mgr, MtxFx43 *viewMatrix) {
    Unk0201ca6c *emtr;

    reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 8;
    mgr->mUnk_44 = viewMatrix;
    if (mgr->mUnk_38_24 == 0) {
        for (emtr = (Unk0201ca6c *) mgr->mUnk_04[0].mUnk_00; emtr != 0; emtr = emtr->mUnk_00) {
            mgr->mUnk_40 = emtr;
            if (emtr->mUnk_24.mUnk_00_3 == 0) {
                SPLManager_DoDraw(mgr);
            }
        }
    } else {
        for (emtr = (Unk0201ca6c *) mgr->mUnk_04[0].mUnk_08; emtr != 0; emtr = emtr->mUnk_04) {
            mgr->mUnk_40 = emtr;
            if (emtr->mUnk_24.mUnk_00_3 == 0) {
                SPLManager_DoDraw(mgr);
            }
        }
    }
}

Unk0201ca6c *SPLManager_CreateEmitter(Unk020184e4 *mgr, s32 resourceId, Vec3 *pos) {
    Unk0201ca6c *emtr;

    emtr = 0;
    if (mgr->mUnk_04[1].mUnk_00 != 0) {
        emtr = (Unk0201ca6c *) SPLList_PopFront(&mgr->mUnk_04[1]);
        SPLEmitter_Init(emtr, mgr->mUnk_28 + resourceId, pos);
        SPLList_PushFront(&mgr->mUnk_04[0], (Unk0201e3c8 *) emtr);
        if (emtr->mUnk_20->mUnk_00->mUnk_00.mUnk_00_14) {
            emtr = 0;
        }
    }
    return emtr;
}

Unk0201ca6c *SPLManager_CreateEmitterWithCallbackEx(Unk020184e4 *mgr, s32 resourceId, Vec3 *pos, s32 param,
                                                    void (*initCallback)(Unk0201ca6c *emtr, s32 param)) {
    Unk0201ca6c *emtr;

    emtr = 0;
    if (mgr->mUnk_04[1].mUnk_00 != 0) {
        emtr = (Unk0201ca6c *) SPLList_PopFront(&mgr->mUnk_04[1]);
        SPLEmitter_Init(emtr, mgr->mUnk_28 + resourceId, pos);
        if (initCallback != 0) {
            initCallback(emtr, param);
        }
        SPLList_PushFront(&mgr->mUnk_04[0], (Unk0201e3c8 *) emtr);
        if (emtr->mUnk_20->mUnk_00->mUnk_00.mUnk_00_14) {
            emtr = 0;
        }
    }
    return emtr;
}

void SPLManager_DeleteEmitter(Unk020184e4 *mgr, Unk0201ca6c *emtr) {
    Unk0201e3c8 *particle;

    while ((particle = SPLList_PopFront(&emtr->mUnk_08)) != 0) {
        SPLList_PushFront(&mgr->mUnk_04[2], particle);
    }
    while ((particle = SPLList_PopFront(&emtr->mUnk_14)) != 0) {
        SPLList_PushFront(&mgr->mUnk_04[2], particle);
    }
    SPLList_Erase(&mgr->mUnk_04[0], (Unk0201e3c8 *) emtr);
    SPLList_PushFront(&mgr->mUnk_04[1], (Unk0201e3c8 *) emtr);
}
