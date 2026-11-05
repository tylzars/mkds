#include "Main/Unknown/code_020f2dac.h"

#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020f7000.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_020f92e8.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020f3678.h"
#include "Main/Unknown/code_020f36a0.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/code_02077bc0.h"

void func_020f4884(Unk020f40dc *rec) {
    s32 i;
    u32 k;
    Unk020f40dc_Kind kind;
    s32 t;

    func_020f49bc(rec);
    if (rec->mUnk_0c == 0) {
        return;
    }
    if (rec->mUnk_10 == 0) {
        return;
    }
    if (rec->mUnk_20 != 0) {
        return;
    }
    rec->mUnk_10 -= 1;
    if (rec->mUnk_10 != 0) {
        return;
    }
    if (data_021759c0->mMode == 5) {
        if (data_021759c0->mEntryIndex == rec->mUnk_04->mKartIndex) {
            kind = (Unk020f40dc_Kind) rec->mUnk_00;
            func_020fe958(gItemInfos[kind].mObjectKind);
        }
    }
    rec->mUnk_08 -= 1;
    k = gItemInfos[rec->mUnk_00].mObjectKind;
    t = gItemPools[k].mReservedCount;
    gItemPools[(s32) k].mReservedCount = t - 1;
    if (rec->mUnk_08 == 0) {
        rec->mUnk_00 = 0x13;
        rec->mUnk_08 = 0;
        rec->mUnk_20 = 0;
        rec->mUnk_0c = 0;
        rec->mUnk_10 = 0;
        rec->mUnk_12 = 0;
        for (i = 0; i < 3; i++) {
            rec->mUnk_14[i] = NULL;
        }
    }
}

void func_020f47e4(Unk020f40dc *rec, s32 kind) {
    u32 k;
    s32 t;

    k = gItemInfos[kind].mObjectCount;
    rec->mUnk_00 = kind;
    rec->mUnk_08 = k;
    rec->mUnk_20 = 0;
    func_0206c14c(rec->mUnk_04->mKart);
    rec->mUnk_0c = gItemInfos[kind].mUnk_10;
    rec->mUnk_10 = 0;
    rec->mUnk_12 = 0;
    k = gItemInfos[kind].mObjectKind;
    t = gItemPools[k].mReservedCount;
    gItemPools[(s32) k].mReservedCount = t + rec->mUnk_08;
}

void func_020f4754(Unk020f40dc *rec, s32 n) {
    s32 i;
    int k;

    rec->mUnk_08 -= n;
    k = gItemInfos[rec->mUnk_00].mObjectKind;
    gItemPools[(s32) k].mReservedCount = gItemPools[k].mReservedCount - n;
    if (rec->mUnk_08 == 0) {
        rec->mUnk_00 = 0x13;
        rec->mUnk_08 = 0;
        rec->mUnk_20 = 0;
        rec->mUnk_0c = 0;
        rec->mUnk_10 = 0;
        rec->mUnk_12 = 0;
        for (i = 0; i < 3; i++) {
            rec->mUnk_14[i] = NULL;
        }
    }
}

void func_020f4718(Unk020f40dc *rec) {
    s32 i;

    rec->mUnk_00 = 0x13;
    rec->mUnk_08 = 0;
    rec->mUnk_20 = 0;
    rec->mUnk_0c = 0;
    rec->mUnk_10 = 0;
    rec->mUnk_12 = 0;
    for (i = 0; i < 3; i++) {
        rec->mUnk_14[i] = NULL;
    }
}

void func_020f45f0(Unk020f40dc *rec, s32 keep) {
    s32 t;
    s32 i;
    s32 n;
    s32 j;
    s32 m;
    Unk020f40dc_Kind kind = (Unk020f40dc_Kind) rec->mUnk_00;
    u32 tab = gItemInfos[kind].mObjectKind;

    if (data_021759c0->mMode == 5) {
        n = rec->mUnk_08;
        if (rec->mUnk_24 == FALSE) {
            for (i = 0; i < n; i++) {
                func_020fe828(tab);
            }
        }
    }
    if (rec->mUnk_20 != 0) {
        m = rec->mUnk_08;
        for (j = 0; j < m; j++) {
            ReleaseItemPoolObject(&gItemPools[rec->mUnk_14[j]->mKind], rec->mUnk_14[j]);
        }
    } else if (keep == 0) {
        t = gItemPools[tab].mReservedCount;
        gItemPools[(s32) tab].mReservedCount = t - rec->mUnk_08;
    }
    rec->mUnk_00 = 0x13;
    rec->mUnk_08 = 0;
    rec->mUnk_20 = 0;
    rec->mUnk_0c = 0;
    rec->mUnk_10 = 0;
    rec->mUnk_12 = 0;
    for (i = 0; i < 3; i++) {
        rec->mUnk_14[i] = NULL;
    }
}

static inline u32 func_020f41c4_inline(Unk020f41c4_B *r, u32 c) {
    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    if (c == 0) {
        return (u32) (r->mUnk_00 >> 32);
    } else {
        return (u32) (((r->mUnk_00 >> 32) * c) >> 32);
    }
}

void func_020f41c4(Unk020f40dc *rec) {
    Kart *owner = rec->mUnk_04->mKart;
    Unk020f41c4_C *halves = (Unk020f41c4_C *) ((u8 *) owner->mKartModelsEntry + 0x40);
    Vec3 *dir = &owner->mUnk_168;
    Vec3 *axis = &owner->mUnk_150;
    s32 i;
    s32 count;
    Unk020f41c4_B *st;
    Unk020f41c4_Row *row;
    ItemObject *elem;
    s32 kind = rec->mUnk_00;
    s32 tab;
    s32 radius;
    s32 angle;
    s32 va;
    s32 vb;
    s32 w1;
    s32 w2;
    s32 d;
    s32 x;
    s32 y;

    if (data_021759c0->mMode == MODE_TIME_ATTACK) {
        st = &gRaceProgress->mLocalRandom;
    } else {
        st = &gRaceProgress->mRandom;
    }
    angle = (u16) func_020f41c4_inline(st, 0x10000);
    angle >>= 4;
    tab = gItemInfos[kind].mObjectKind;
    if (gItemKinds[tab].mUnk_80 != 0) {
        radius = 0x2000;
    } else {
        radius = 0x1800;
    }
    count = rec->mUnk_08;
    va = (s32) (((s64) radius * gPairsByAngle[angle * 2]) >> 12);
    vb = (s32) (((s64) radius * gPairsByAngle[angle * 2 + 1]) >> 12);
    func_020f1048(&gItemPools[tab], count, rec->mUnk_14, owner->mIndex, &owner->mUnk_98);
    i = 0;
    if (i < count) {
        row = &data_0215961c[count - 1];
        do {
            x = row->mUnk_00[i].mUnk_00;
            y = row->mUnk_00[i].mUnk_04;
            w1 = (s32) (((s64) x * (0x1000 + (s32) func_020f41c4_inline(st, 0x333))) >> 12);
            w2 = (s32) (((s64) y * (0x1000 + (s32) func_020f41c4_inline(st, 0x333))) >> 12);
            d = (s32) (((s64) w1 * vb) >> 12) - (s32) (((s64) w2 * va) >> 12);
            elem = rec->mUnk_14[i];
            elem->mVelocity.x = (s32) (((s64) dir->x * d) >> 12);
            elem->mVelocity.y = (s32) (((s64) dir->y * d) >> 12);
            elem->mVelocity.z = (s32) (((s64) dir->z * d) >> 12);
            Vec3AddScaled((s32) (((s64) w2 * vb) >> 12) + (s32) (((s64) d * va) >> 12), axis, &elem->mVelocity,
                          &elem->mVelocity);
            elem->mUnk_68.x = 0xcd;
            elem->mUnk_68.y = 0xcd;
            elem->mUnk_68.z = 0xcd;
            elem->mUnk_7c = *halves;
            i++;
        } while (i < count);
    }
}

void func_020f41b0(Unk020f40dc *rec) {
    rec->mUnk_20 = 10;
    func_020f41c4(rec);
}

BOOL func_020f4198(Unk020f40dc *rec, s32 v) {
    if (rec->mUnk_10 != 0) {
        return FALSE;
    }
    rec->mUnk_10 = v;
    return TRUE;
}

void func_020f4188(Unk020f40dc *rec, s32 v) {
    rec->mUnk_12 = rec->mUnk_10 - v;
}

void func_020f413c(Unk020f40dc *rec, s32 *kind, s32 *count) {
    s32 i;

    *kind = rec->mUnk_00;
    *count = rec->mUnk_08;
    rec->mUnk_00 = 0x13;
    rec->mUnk_08 = 0;
    rec->mUnk_20 = 0;
    rec->mUnk_0c = 0;
    rec->mUnk_10 = 0;
    rec->mUnk_12 = 0;
    for (i = 0; i < 3; i++) {
        rec->mUnk_14[i] = NULL;
    }
}

void func_020f40dc(Unk020f40dc *rec, s32 kind, s32 count) {
    rec->mUnk_00 = kind;
    rec->mUnk_08 = count;
    rec->mUnk_20 = 0;
    func_0206c14c(rec->mUnk_04->mKart);
    rec->mUnk_0c = gItemInfos[kind].mUnk_10;
    rec->mUnk_10 = 0;
    rec->mUnk_12 = 0;
}

void func_020f40a0(s32 idx, s32 amount) {
    int i = gItemInfos[idx].mObjectKind;

    gItemPools[(s32) i].mReservedCount = gItemPools[i].mReservedCount - amount;
}

s32 func_020f4090(s32 idx) {
    return data_0217bc38[idx];
}

void func_020f4020(Unk020f3fa8 *p, Vec3 *points, s32 scale) {
    s32 i;

    for (i = 0; i < 4; i++) {
        p->mUnk_64[i] = &p->mUnk_74[i];
        p->mUnk_74[i] = points[i];
    }
    p->mUnk_60 = 0;
    func_020d7d18(&p->mUnk_00, 1, p->mUnk_64, scale);
}

s32 func_020f3fa8(Unk020f3fa8 *p, Vec3 *v) {
    Vec3 *first;

    p->mUnk_74[p->mUnk_60] = *v;
    p->mUnk_60 += 1;
    p->mUnk_60 &= 3;
    first = p->mUnk_64[0];
    p->mUnk_64[0] = p->mUnk_64[1];
    p->mUnk_64[1] = p->mUnk_64[2];
    p->mUnk_64[2] = p->mUnk_64[3];
    p->mUnk_64[3] = first;
    return func_020d7c84(&p->mUnk_00, 1, p->mUnk_64);
}

BOOL func_020f3c54(Unk020f371c_Ref *in, Unk020f371c_Ref *out, Vec3 *pos) {
    Unk020f371c *node = in->mUnk_00;
    Unk020f371c *best;
    Unk020f371c *c;
    Unk020f371c *g;
    Vec3 *v = node->mUnk_18;
    s32 n;
    Unk020f371c *c2;
    Unk020f371c *g2;
    Vec3 *v2;
    s32 m;
    s32 d;
    s32 dx;
    s32 dy;
    s32 dz;
    s32 bestDist;
    s32 i;
    s32 j;
    s32 k;
    Vec3 *q = pos;
    Unk020f371c *n2 = node;

    best = node;
    dx = (v->x - pos->x) >> 12;
    dy = (v->y - pos->y) >> 12;
    dz = (v->z - pos->z) >> 12;
    bestDist = dx * dx + dy * dy + dz * dz;
    for (i = 0; i < n2->mUnk_24; i++) {
        c = node->mUnk_00[i];
        if (c != NULL) {
            v = c->mUnk_18;
            dx = (v->x - pos->x) >> 12;
            dy = (v->y - q->y) >> 12;
            dz = (v->z - q->z) >> 12;
            d = dx * dx + dy * dy + dz * dz;
            n = c->mUnk_24;
            if (d < bestDist) {
                bestDist = d;
                best = c;
            }
            for (j = 0; j < n; j++) {
                g = c->mUnk_00[j];
                v = g->mUnk_18;
                dx = (v->x - pos->x) >> 12;
                dy = (v->y - q->y) >> 12;
                dz = (v->z - q->z) >> 12;
                d = dx * dx + dy * dy + dz * dz;
                if (d < bestDist) {
                    bestDist = d;
                    best = g;
                }
            }
            m = c->mUnk_26;
            for (k = 0; k < m; k++) {
                g = c->mUnk_0c[k];
                if (g != node) {
                    v = g->mUnk_18;
                    dx = (v->x - pos->x) >> 12;
                    dy = (v->y - q->y) >> 12;
                    dz = (v->z - q->z) >> 12;
                    d = dx * dx + dy * dy + dz * dz;
                    if (d < bestDist) {
                        bestDist = d;
                        best = g;
                    }
                }
            }
        }
    }
    for (i = 0; i < n2->mUnk_26; i++) {
        c2 = node->mUnk_0c[i];
        if (c2 != NULL) {
            v2 = c2->mUnk_18;
            dx = (v2->x - pos->x) >> 12;
            dy = (v2->y - q->y) >> 12;
            dz = (v2->z - q->z) >> 12;
            d = dx * dx + dy * dy + dz * dz;
            m = c2->mUnk_26;
            if (d < bestDist) {
                bestDist = d;
                best = c2;
            }
            for (j = 0; j < m; j++) {
                g2 = c2->mUnk_0c[j];
                v2 = g2->mUnk_18;
                dx = (v2->x - pos->x) >> 12;
                dy = (v2->y - q->y) >> 12;
                dz = (v2->z - q->z) >> 12;
                d = dx * dx + dy * dy + dz * dz;
                if (d < bestDist) {
                    bestDist = d;
                    best = g2;
                }
            }
            n = c2->mUnk_24;
            for (k = 0; k < n; k++) {
                g2 = c2->mUnk_00[k];
                if (g2 != node) {
                    v2 = g2->mUnk_18;
                    dx = (v2->x - pos->x) >> 12;
                    dy = (v2->y - q->y) >> 12;
                    dz = (v2->z - q->z) >> 12;
                    d = dx * dx + dy * dy + dz * dz;
                    if (d < bestDist) {
                        bestDist = d;
                        best = g2;
                    }
                }
            }
        }
    }
    out->mUnk_00 = best;
    out->mUnk_04 = 1;
    return best != node;
}

BOOL func_020f3bb4(Unk020f371c_Ref *a, Unk020f371c_Ref *b, Unk020f371c_Ref *out, Vec3 *pos) {
    Vec3 *va = a->mUnk_00->mUnk_18;
    Vec3 *vb = b->mUnk_00->mUnk_18;
    s32 da = ((va->x - pos->x) >> 12) * ((va->x - pos->x) >> 12) + ((va->y - pos->y) >> 12) * ((va->y - pos->y) >> 12) +
             ((va->z - pos->z) >> 12) * ((va->z - pos->z) >> 12);
    s32 db = ((vb->x - pos->x) >> 12) * ((vb->x - pos->x) >> 12) + ((vb->y - pos->y) >> 12) * ((vb->y - pos->y) >> 12) +
             ((vb->z - pos->z) >> 12) * ((vb->z - pos->z) >> 12);

    if (db < da) {
        *out = *b;
        return TRUE;
    }
    return FALSE;
}

BOOL func_020f3a58(Unk020f371c_Ref *in, Unk020f371c_Ref *out, Vec3 *pos) {
    Unk020f371c *node = in->mUnk_00;
    s32 d;
    Vec3 *v;
    s32 dy;
    Vec3 *q;
    s32 dx;
    s32 start;
    s32 limit;
    s32 dz;
    Unk020f371c *child;
    Unk020f371c *cur;
    Unk020f371c *best;
    s32 bestDist;
    s32 i;

    v = node->mUnk_18;
    dx = (v->x - pos->x) >> 12;
    dy = (v->y - pos->y) >> 12;
    dz = (v->z - pos->z) >> 12;
    start = dx * dx + dy * dy + dz * dz;
    limit = gCourseMap->mUnk_58;
    q = pos;

    cur = node;
    do {
        best = NULL;
        bestDist = 0x7fffffff;
        for (i = 0; i < cur->mUnk_24; i++) {
            child = cur->mUnk_00[i];
            if (child != NULL) {
                v = child->mUnk_18;
                dx = (v->x - pos->x) >> 12;
                dy = (v->y - q->y) >> 12;
                dz = (v->z - q->z) >> 12;
                d = dx * dx + dy * dy + dz * dz;
                if (d < bestDist) {
                    bestDist = d;
                    best = child;
                }
            }
        }
        if (bestDist < start) {
            out->mUnk_00 = best;
            out->mUnk_04 = 1;
            return best != node;
        }
        limit--;
        cur = best;
    } while (limit > 1 && best != node);
    out->mUnk_00 = node;
    out->mUnk_04 = 1;
    return FALSE;
}

void func_020f371c(Unk020f371c_Ref *in, Unk020f371c_Ref *out, u32 idx, s32 flag) {
    Unk020f371c *node = in->mUnk_00;
    s32 side = in->mUnk_04;
    Unk020f371c *cur;
    Unk020f371c *child;
    s32 count2;
    s32 count;
    Vec3 *origin;
    BOOL found;
    s32 best;
    Unk020f371c *best2;
    Vec3 *pos;
    s32 i;
    Vec3 *c;
    Kart *other;
    s32 d;

    if (side != 0) {
        count = node->mUnk_24;
        cur = node->mUnk_00[0];
    } else {
        count = node->mUnk_26;
        cur = node->mUnk_0c[0];
    }
    if (count <= 1 && (side != 0 ? cur->mUnk_26 : cur->mUnk_24) <= 1) {
    done:
        out->mUnk_00 = cur;
        out->mUnk_04 = side;
        return;
    }
    origin = node->mUnk_18;
    found = FALSE;
    best = 0x5f592e1;
    if (idx < 8) {
        other = GetKart(idx);
        pos = &other->mUnk_98;
        {
            s64 sq = (s64) (((const Vec3 *) pos)->x - ((const Vec3 *) origin)->x) *
                     (((const Vec3 *) pos)->x - ((const Vec3 *) origin)->x);
            sq += (s64) (((const Vec3 *) pos)->z - ((const Vec3 *) origin)->z) *
                  (((const Vec3 *) pos)->z - ((const Vec3 *) origin)->z);
            if (sq < 0x225510000000LL) {
                found = TRUE;
                for (i = 0; i < count; i++) {
                    child = side != 0 ? node->mUnk_00[i] : node->mUnk_0c[i];
                    if (child != NULL) {
                        c = child->mUnk_18;
                        d = ((pos->x - origin->x) >> 12) * ((c->x - origin->x) >> 12);
                        d += ((pos->z - origin->z) >> 12) * ((c->z - origin->z) >> 12);
                        if (d > 0) {
                            d = ((child->mUnk_18->x - pos->x) >> 12) * ((child->mUnk_18->x - pos->x) >> 12);
                            d += ((child->mUnk_18->y - pos->y) >> 12) * ((child->mUnk_18->y - pos->y) >> 12);
                            d += ((child->mUnk_18->z - pos->z) >> 12) * ((child->mUnk_18->z - pos->z) >> 12);
                            if (d < best) {
                                best = d;
                                cur = child;
                            }
                        }
                    }
                }
            }
        }
    }
    if (side == 0 || (found != FALSE && flag != 0)) {
        if ((side != 0 ? cur->mUnk_26 : cur->mUnk_24) > 1) {
            best2 = NULL;
            count2 = side != 0 ? cur->mUnk_26 : cur->mUnk_24;
            for (i = 0; i < count2; i++) {
                child = side != 0 ? cur->mUnk_0c[i] : cur->mUnk_00[i];
                if (child != NULL && child != node) {
                    if (found != FALSE) {
                        c = child->mUnk_18;
                        d = ((pos->x - origin->x) >> 12) * ((c->x - origin->x) >> 12);
                        d += ((pos->z - origin->z) >> 12) * ((c->z - origin->z) >> 12);
                        if (d > 0) {
                            d = ((child->mUnk_18->x - pos->x) >> 12) * ((child->mUnk_18->x - pos->x) >> 12);
                            d += ((child->mUnk_18->y - pos->y) >> 12) * ((child->mUnk_18->y - pos->y) >> 12);
                            d += ((child->mUnk_18->z - pos->z) >> 12) * ((child->mUnk_18->z - pos->z) >> 12);
                            if (d < best) {
                                best = d;
                                best2 = child;
                            }
                        }
                    } else {
                        cur = child;
                        side = 1;
                        goto done;
                    }
                }
            }
            if (best2 != NULL) {
                cur = best2;
                side = side == 0 ? 1 : 0;
            }
        }
    }
    goto done;
}

u8 func_020f36d8(Unk020f36d8 *p) {
    s32 t = p->mUnk_00;

    if (t == 0) {
        return 0xff;
    }
    return (t - gCourseMap->mUnk_b0) / 40;
}

s32 func_020f36a0(u32 a, u32 *b) {
    if (a >= 0xff) {
        *b = 0;
    } else {
        *b = gCourseMap->mUnk_b0 + a * 0x28;
    }
    b[1] = 1;
    return 1;
}

u32 func_020f3678(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    value2 = (u32) * (const s8 *) ((value0) + (33));
    value2 = (value2 << 6);
    *(u32 *) ((value1) + (0)) = value2;
    value2 = (u32) * (const s8 *) ((value0) + (34));
    value2 = (value2 << 6);
    *(u32 *) ((value1) + (4)) = value2;
    value0 = (u32) * (const s8 *) ((value0) + (35));
    value0 = (value0 << 6);
    *(u32 *) ((value1) + (8)) = value0;
    return value0;
}

#pragma thumb on

void func_020f357c(void) {
    Unk020f371c *e;
    Vec3 v;
    u32 n;
    u16 i;

    n = gCourseMap->mUnk_58;
    e = gCourseMap->mUnk_ac;
    i = 0;
    for (i = 0; i < 4; i++) {
        data_0217bc38[i] = 0;
    }
    for (i = 0; i < n; i++, e++) {
        if (e->mUnk_1c >= 0x3e8000) {
            data_0217bc38[e->mUnk_20] = (s32) e;
        }
    }
    e = gCourseMap->mUnk_ac;
    for (i = 0; i < n; i++, e++) {
        Vec3Sub(e->mUnk_00[0]->mUnk_18, e->mUnk_18, &v);
        if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&v, &v);
        }
        e->mUnk_21 = v.x >> 6;
        e->mUnk_22 = v.y >> 6;
        e->mUnk_23 = v.z >> 6;
    }
}

#pragma thumb off

static inline u32 func_020f3150_inline(Unk020f41c4_B *x, u32 n) {
    x->mUnk_00 = x->mUnk_08 * x->mUnk_00 + x->mUnk_10;
    return (u32) (((u64) (u32) (x->mUnk_00 >> 32) * n) >> 32);
}

void func_020f3150(Unk020f2df0 *p, Unk020eda5c *a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    Vec3 v;
    s32 n;
    BOOL m;
    Vec3 *u;
    s32 dx;
    s32 dy;
    s32 dz;

    n = Vec3DotUnrounded(&a->mUnk_06c, &a->mUnk_02c.mUnk_18);
    m = (a->mUnk_010->mUnk_48 & 1) != 0;
    n = (s32) (((s64) n * 0x1ec) >> 12);
    if (n < 0x666) {
        n = 0x666;
    }
    if (c != 0) {
        n = func_020edc9c(a, d, 0x1b33, 0x7000, &v);
    } else {
        n = func_020edb8c(a, n, 0x1000, 0x7000, &v);
    }
    if (c != 0) {
        if (a->mUnk_07c > 0) {
            n += (s32) (((s64) a->mUnk_07c * 0x14cd) >> 12);
        }
    }
    if (a->mUnk_068 < 0x3000) {
        v.z += func_020f3150_inline(&gRaceProgress->mRandom, 0xf6) - 0x7b;
        v.x += func_020f3150_inline(&gRaceProgress->mRandom, 0xf6) - 0x7b;
    }
    v.x = (s32) (((s64) v.x * n) >> 12);
    v.y = (s32) (((s64) v.y * n) >> 12);
    v.z = (s32) (((s64) v.z * n) >> 12);
    if (!m) {
        if (c != 0) {
            n = e + (s32) (((s64) a->mUnk_068 * 0x200) >> 12) + (s32) (((s64) a->mUnk_06c.y * 0x2000) >> 12);
        } else {
            n = f;
            dx = a->mUnk_06c.y > 0 ? 0x666 : 0x1333;
            n += (s32) (((s64) dx * a->mUnk_06c.y) >> 12);
        }
        Vec3AddScaled(n, &a->mUnk_02c.mUnk_0c, &v, &p->mUnk_000.mVelocity);
    }
    if (c == 0) {
        Vec3Add(&p->mUnk_000.mVelocity, &a->mUnk_010->mUnk_1fc, &p->mUnk_000.mVelocity);
    }
    if (c != 0) {
        p->mUnk_000.mPos = a->mUnk_010->mCollisionCenter;
        Vec3AddScaled(p->mUnk_000.mUnk_68.z * 10, &a->mUnk_02c.mUnk_18, &p->mUnk_000.mPos, &p->mUnk_000.mPos);
    } else {
        if (a->mUnk_07c != 0 && a->mUnk_068 < 0x2000 && p->mUnk_000.mUnk_68.z < 0xccd) {
            Vec3Sub(&a->mUnk_02c.mUnk_0c, &a->mUnk_02c.mUnk_18, &v);
            Vec3AddScaled(0x2000, &v, &p->mUnk_000.mPos, &p->mUnk_000.mPos);
        }
    }
    if (p->mUnk_000.mUnk_68.z < 0xccd) {
        u = &p->mUnk_000.mUnk_68;
        u->x = 0xccd;
        u->y = 0xccd;
        u->z = 0xccd;
    }
    p->mUnk_12c = b;
    p->mUnk_000.mUnk_124 = func_020f2dac;
    p->mUnk_000.mFlags &= ~0x7000000;
    if (!m) {
        return;
    }
    n = Vec3Dot(&a->mUnk_02c.mUnk_0c, &p->mUnk_000.mVelocity);
    dx = (s32) (((s64) a->mUnk_02c.mUnk_0c.x * n) >> 12);
    dy = (s32) (((s64) a->mUnk_02c.mUnk_0c.y * n) >> 12);
    dz = (s32) (((s64) a->mUnk_02c.mUnk_0c.z * n) >> 12);
    p->mUnk_000.mVelocity.x -= dx;
    p->mUnk_000.mVelocity.y -= dy;
    p->mUnk_000.mVelocity.z -= dz;
    Vec3AddScaled(c != 0 ? 0x8800 : -0x1000, &a->mUnk_02c.mUnk_0c, &p->mUnk_000.mVelocity, &p->mUnk_000.mVelocity);
    p->mUnk_12c = 0;
}

void func_020f30ec(Unk020f2df0 *a, s32 b, Vec3 *c) {
    if (c != NULL) {
        a->mUnk_000.mVelocity = *c;
    }
    if (a->mUnk_000.mUnk_68.z < 0xccd) {
        a->mUnk_000.mUnk_68.x = 0xccd;
        a->mUnk_000.mUnk_68.y = 0xccd;
        a->mUnk_000.mUnk_68.z = 0xccd;
    }
    a->mUnk_12c = b;
    a->mUnk_000.mUnk_124 = func_020f2dac;
    a->mUnk_000.mFlags &= ~0x7000000;
}

void func_020f2df0(Unk020f2df0 *a, s32 b, s32 c, s32 d, u32 *e) {
    Vec3 t;
    Vec3 u;
    Vec3 v;
    Vec3 *p;
    Vec3 *q;
    s32 n;

    p = &a->mUnk_000.mVelocity;
    q = &a->mUnk_000.mPos;
    Vec3Add(p, q, q);
    p->x = (s32) (((s64) p->x * c) >> 12);
    p->y = (s32) (((s64) p->y * c) >> 12);
    p->z = (s32) (((s64) p->z * c) >> 12);
    if (func_01ffdee4(q, &a->mUnk_000.mPrevPos, 0, a->mUnk_000.mUnk_dc, 0x24, a->mUnk_000.mUnk_da, &t, &u, (s32 *) &v,
                      &a->mUnk_000.mUnk_fc, NULL, NULL, NULL, e) != 0) {
        Vec3Add(&t, q, q);
        if (a->mUnk_000.mUnk_fc & 0x1e34ef) {
            n = a->mUnk_12c;
            a->mUnk_12c = n - 1;
            if (n <= 0) {
                func_020f9334(a, q, p, b, &u);
            } else {
                a->mUnk_000.mFlags |= 0x10;
                n = Vec3Dot(&u, p);
                t.x = (s32) (((s64) u.x * n) >> 12);
                t.y = (s32) (((s64) u.y * n) >> 12);
                t.z = (s32) (((s64) u.z * n) >> 12);
                p->x -= t.x;
                p->y -= t.y;
                p->z -= t.z;
                p->x = (s32) (((s64) p->x * 0x8cd) >> 12);
                p->y = (s32) (((s64) p->y * 0x8cd) >> 12);
                p->z = (s32) (((s64) p->z * 0x8cd) >> 12);
                Vec3AddScaled(-d, &t, p, p);
                a->mUnk_000.mUnk_f0 = u;
            }
        }
        if (a->mUnk_000.mUnk_fc & 0x214300) {
            a->mUnk_000.mFlags |= 0x20;
            func_020f92e8(p, &v);
            if (func_020f9290(a, &v) != FALSE) {
                return;
            }
            a->mUnk_000.mUnk_78 &= ~0x4000;
        }
        if (a->mUnk_000.mUnk_fc & 0x8000) {
            func_020f7070(a, 1);
            return;
        }
    }
    a->mUnk_000.mFlags &= ~0x4000000;
    if (a->mUnk_000.mUnk_fc & 0x1e34ef) {
        return;
    }
    p->y -= b;
    if (p->y < -0xa000) {
        p->y = -0xa000;
    }
}

void func_020f2dac(ItemObject *a, Vec3 *b, Vec3 *c) {
    func_020f92e8(&a->mVelocity, c);
    if (a->mFlags & 0x1000000) {
        return;
    }
    a->mFlags |= 0x1000000;
    a->mUnk_108.x = 0;
    a->mUnk_108.y = 0;
    a->mUnk_108.z = 0;
}
