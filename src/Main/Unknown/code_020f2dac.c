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

// Runs the countdown that starts the held objects, then counts the use timer down and, when it ends, takes one object
// off the held item.
void UpdateHeldItem(HeldItem *rec) {
    s32 i;
    u32 k;
    Unk020f40dc_Kind kind;
    s32 t;

    StartNextHeldItemObject(rec);
    if (rec->mUnk_0c == 0) {
        return;
    }
    if (rec->mTimer == 0) {
        return;
    }
    if (rec->mObjectStartFramesLeft != 0) {
        return;
    }
    rec->mTimer -= 1;
    if (rec->mTimer != 0) {
        return;
    }
    if (gRaceSetup->mMode == 5) {
        if (gRaceSetup->mEntryIndex == rec->mKartItems->mKartIndex) {
            kind = (Unk020f40dc_Kind) rec->mItemInfoIndex;
            func_020fe958(gItemInfos[kind].mObjectKind);
        }
    }
    rec->mObjectCount -= 1;
    k = gItemInfos[rec->mItemInfoIndex].mObjectKind;
    t = gItemPools[k].mReservedCount;
    gItemPools[(s32) k].mReservedCount = t - 1;
    if (rec->mObjectCount == 0) {
        rec->mItemInfoIndex = 0x13;
        rec->mObjectCount = 0;
        rec->mObjectStartFramesLeft = 0;
        rec->mUnk_0c = 0;
        rec->mTimer = 0;
        rec->mUnk_12 = 0;
        for (i = 0; i < 3; i++) {
            rec->mObjects[i] = NULL;
        }
    }
}

// Makes the item held and reserves its objects in the item's pool.
void SetHeldItem(HeldItem *rec, s32 kind) {
    u32 k;
    s32 t;

    k = gItemInfos[kind].mObjectCount;
    rec->mItemInfoIndex = kind;
    rec->mObjectCount = k;
    rec->mObjectStartFramesLeft = 0;
    SetupKartAiHeldItemEntry(rec->mKartItems->mKart);
    rec->mUnk_0c = gItemInfos[kind].mUnk_10;
    rec->mTimer = 0;
    rec->mUnk_12 = 0;
    k = gItemInfos[kind].mObjectKind;
    t = gItemPools[k].mReservedCount;
    gItemPools[(s32) k].mReservedCount = t + rec->mObjectCount;
}

void RemoveHeldItemObjects(HeldItem *rec, s32 n) {
    s32 i;
    int k;

    rec->mObjectCount -= n;
    k = gItemInfos[rec->mItemInfoIndex].mObjectKind;
    gItemPools[(s32) k].mReservedCount = gItemPools[k].mReservedCount - n;
    if (rec->mObjectCount == 0) {
        rec->mItemInfoIndex = 0x13;
        rec->mObjectCount = 0;
        rec->mObjectStartFramesLeft = 0;
        rec->mUnk_0c = 0;
        rec->mTimer = 0;
        rec->mUnk_12 = 0;
        for (i = 0; i < 3; i++) {
            rec->mObjects[i] = NULL;
        }
    }
}

void ResetHeldItem(HeldItem *rec) {
    s32 i;

    rec->mItemInfoIndex = 0x13;
    rec->mObjectCount = 0;
    rec->mObjectStartFramesLeft = 0;
    rec->mUnk_0c = 0;
    rec->mTimer = 0;
    rec->mUnk_12 = 0;
    for (i = 0; i < 3; i++) {
        rec->mObjects[i] = NULL;
    }
}

// Gives the held objects back to the pool, or the reserved count unless keep is set, then empties the record.
void ReleaseHeldItem(HeldItem *rec, s32 keep) {
    s32 t;
    s32 i;
    s32 n;
    s32 j;
    s32 m;
    Unk020f40dc_Kind kind = (Unk020f40dc_Kind) rec->mItemInfoIndex;
    u32 tab = gItemInfos[kind].mObjectKind;

    if (gRaceSetup->mMode == 5) {
        n = rec->mObjectCount;
        if (rec->mUnk_24 == FALSE) {
            for (i = 0; i < n; i++) {
                func_020fe828(tab);
            }
        }
    }
    if (rec->mObjectStartFramesLeft != 0) {
        m = rec->mObjectCount;
        for (j = 0; j < m; j++) {
            ReleaseItemPoolObject(&gItemPools[rec->mObjects[j]->mKind], rec->mObjects[j]);
        }
    } else if (keep == 0) {
        t = gItemPools[tab].mReservedCount;
        gItemPools[(s32) tab].mReservedCount = t - rec->mObjectCount;
    }
    rec->mItemInfoIndex = 0x13;
    rec->mObjectCount = 0;
    rec->mObjectStartFramesLeft = 0;
    rec->mUnk_0c = 0;
    rec->mTimer = 0;
    rec->mUnk_12 = 0;
    for (i = 0; i < 3; i++) {
        rec->mObjects[i] = NULL;
    }
}

static inline u32 TakeHeldItemObjects_inline(Unk020f41c4_B *r, u32 c) {
    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    if (c == 0) {
        return r->mUnk_00 >> 32;
    } else {
        return ((r->mUnk_00 >> 32) * c) >> 32;
    }
}

// Takes the held objects from their pool and gives each a starting velocity.
void TakeHeldItemObjects(HeldItem *rec) {
    Kart *owner = rec->mKartItems->mKart;
    Unk020f41c4_C *halves = OFFSET_PTR(Unk020f41c4_C, owner->mKartModelsEntry, 0x40);
    Vec3 *dir = &owner->mUnk_168;
    Vec3 *axis = &owner->mUnk_150;
    s32 i;
    s32 count;
    Unk020f41c4_B *st;
    Unk020f41c4_Row *row;
    ItemObject *elem;
    s32 kind = rec->mItemInfoIndex;
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

    if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
        st = &gRaceProgress->mLocalRandom;
    } else {
        st = &gRaceProgress->mRandom;
    }
    angle = (u16) TakeHeldItemObjects_inline(st, 0x10000);
    angle >>= 4;
    tab = gItemInfos[kind].mObjectKind;
    if (gItemKinds[tab].mUnk_80 != 0) {
        radius = 0x2000;
    } else {
        radius = 0x1800;
    }
    count = rec->mObjectCount;
    va = ((s64) radius * gPairsByAngle[angle * 2]) >> 12;
    vb = ((s64) radius * gPairsByAngle[angle * 2 + 1]) >> 12;
    TakeItemPoolObjects(&gItemPools[tab], count, rec->mObjects, owner->mIndex, &owner->mDrawMatrixPos);
    i = 0;
    if (i < count) {
        row = &data_0215961c[count - 1];
        do {
            x = row->mUnk_00[i].mUnk_00;
            y = row->mUnk_00[i].mUnk_04;
            w1 = ((s64) x * (0x1000 + (s32) TakeHeldItemObjects_inline(st, 0x333))) >> 12;
            w2 = ((s64) y * (0x1000 + (s32) TakeHeldItemObjects_inline(st, 0x333))) >> 12;
            d = (s32) (((s64) w1 * vb) >> 12) - (s32) (((s64) w2 * va) >> 12);
            elem = rec->mObjects[i];
            elem->mVelocity.x = ((s64) dir->x * d) >> 12;
            elem->mVelocity.y = ((s64) dir->y * d) >> 12;
            elem->mVelocity.z = ((s64) dir->z * d) >> 12;
            VEC_MultAdd((s32) (((s64) w2 * vb) >> 12) + (s32) (((s64) d * va) >> 12), axis, &elem->mVelocity,
                        &elem->mVelocity);
            elem->mScale.x = 0xcd;
            elem->mScale.y = 0xcd;
            elem->mScale.z = 0xcd;
            elem->mColorBlend = *halves;
            i++;
        } while (i < count);
    }
}

// Takes the held objects and starts the countdown that starts them one at a time.
void StartHeldItemObjects(HeldItem *rec) {
    rec->mObjectStartFramesLeft = 10;
    TakeHeldItemObjects(rec);
}

BOOL StartHeldItemTimer(HeldItem *rec, s32 v) {
    if (rec->mTimer != 0) {
        return FALSE;
    }
    rec->mTimer = v;
    return TRUE;
}

void func_020f4188(HeldItem *rec, s32 v) {
    rec->mUnk_12 = rec->mTimer - v;
}

void RemoveHeldItem(HeldItem *rec, s32 *kind, s32 *count) {
    s32 i;

    *kind = rec->mItemInfoIndex;
    *count = rec->mObjectCount;
    rec->mItemInfoIndex = 0x13;
    rec->mObjectCount = 0;
    rec->mObjectStartFramesLeft = 0;
    rec->mUnk_0c = 0;
    rec->mTimer = 0;
    rec->mUnk_12 = 0;
    for (i = 0; i < 3; i++) {
        rec->mObjects[i] = NULL;
    }
}

// Like SetHeldItem, but the count comes from the caller and nothing is reserved in the pool.
void SetHeldItemWithCount(HeldItem *rec, s32 kind, s32 count) {
    rec->mItemInfoIndex = kind;
    rec->mObjectCount = count;
    rec->mObjectStartFramesLeft = 0;
    SetupKartAiHeldItemEntry(rec->mKartItems->mKart);
    rec->mUnk_0c = gItemInfos[kind].mUnk_10;
    rec->mTimer = 0;
    rec->mUnk_12 = 0;
}

void RemoveReservedItemObjects(s32 idx, s32 amount) {
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

// Writes the link nearest pos among the link, its neighbours and their neighbours.
BOOL PickNearestNearbyItemPointLink(ItemPointLinkRef *in, ItemPointLinkRef *out, Vec3 *pos) {
    ItemPointLink *node = in->mLink;
    ItemPointLink *best;
    ItemPointLink *c;
    ItemPointLink *g;
    Vec3 *v = node->mPointPos;
    s32 n;
    ItemPointLink *c2;
    ItemPointLink *g2;
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
    ItemPointLink *n2 = node;

    best = node;
    dx = (v->x - pos->x) >> 12;
    dy = (v->y - pos->y) >> 12;
    dz = (v->z - pos->z) >> 12;
    bestDist = dx * dx + dy * dy + dz * dz;
    for (i = 0; i < n2->mNextCount; i++) {
        c = node->mNextLinks[i];
        if (c != NULL) {
            v = c->mPointPos;
            dx = (v->x - pos->x) >> 12;
            dy = (v->y - q->y) >> 12;
            dz = (v->z - q->z) >> 12;
            d = dx * dx + dy * dy + dz * dz;
            n = c->mNextCount;
            if (d < bestDist) {
                bestDist = d;
                best = c;
            }
            for (j = 0; j < n; j++) {
                g = c->mNextLinks[j];
                v = g->mPointPos;
                dx = (v->x - pos->x) >> 12;
                dy = (v->y - q->y) >> 12;
                dz = (v->z - q->z) >> 12;
                d = dx * dx + dy * dy + dz * dz;
                if (d < bestDist) {
                    bestDist = d;
                    best = g;
                }
            }
            m = c->mPreviousCount;
            for (k = 0; k < m; k++) {
                g = c->mPreviousLinks[k];
                if (g != node) {
                    v = g->mPointPos;
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
    for (i = 0; i < n2->mPreviousCount; i++) {
        c2 = node->mPreviousLinks[i];
        if (c2 != NULL) {
            v2 = c2->mPointPos;
            dx = (v2->x - pos->x) >> 12;
            dy = (v2->y - q->y) >> 12;
            dz = (v2->z - q->z) >> 12;
            d = dx * dx + dy * dy + dz * dz;
            m = c2->mPreviousCount;
            if (d < bestDist) {
                bestDist = d;
                best = c2;
            }
            for (j = 0; j < m; j++) {
                g2 = c2->mPreviousLinks[j];
                v2 = g2->mPointPos;
                dx = (v2->x - pos->x) >> 12;
                dy = (v2->y - q->y) >> 12;
                dz = (v2->z - q->z) >> 12;
                d = dx * dx + dy * dy + dz * dz;
                if (d < bestDist) {
                    bestDist = d;
                    best = g2;
                }
            }
            n = c2->mNextCount;
            for (k = 0; k < n; k++) {
                g2 = c2->mNextLinks[k];
                if (g2 != node) {
                    v2 = g2->mPointPos;
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
    out->mLink = best;
    out->mNextLinksUsed = 1;
    return best != node;
}

BOOL CopyCloserItemPointLinkRef(ItemPointLinkRef *a, ItemPointLinkRef *b, ItemPointLinkRef *out, Vec3 *pos) {
    Vec3 *va = a->mLink->mPointPos;
    Vec3 *vb = b->mLink->mPointPos;
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

// Follows the next links until one is nearer to pos than the start link.
BOOL FollowItemPointLinksToPos(ItemPointLinkRef *in, ItemPointLinkRef *out, Vec3 *pos) {
    ItemPointLink *node = in->mLink;
    s32 d;
    Vec3 *v;
    s32 dy;
    Vec3 *q;
    s32 dx;
    s32 start;
    s32 limit;
    s32 dz;
    ItemPointLink *child;
    ItemPointLink *cur;
    ItemPointLink *best;
    s32 bestDist;
    s32 i;

    v = node->mPointPos;
    dx = (v->x - pos->x) >> 12;
    dy = (v->y - pos->y) >> 12;
    dz = (v->z - pos->z) >> 12;
    start = dx * dx + dy * dy + dz * dz;
    limit = gCourseMap->mItemPointCount;
    q = pos;

    cur = node;
    do {
        best = NULL;
        bestDist = 0x7fffffff;
        for (i = 0; i < cur->mNextCount; i++) {
            child = cur->mNextLinks[i];
            if (child != NULL) {
                v = child->mPointPos;
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
            out->mLink = best;
            out->mNextLinksUsed = 1;
            return best != node;
        }
        limit--;
        cur = best;
    } while (limit > 1 && best != node);
    out->mLink = node;
    out->mNextLinksUsed = 1;
    return FALSE;
}

// Writes the link to go on to, leaning toward kart idx when it is close.
void PickNextItemPointLink(ItemPointLinkRef *in, ItemPointLinkRef *out, u32 idx, s32 flag) {
    ItemPointLink *node = in->mLink;
    s32 side = in->mNextLinksUsed;
    ItemPointLink *cur;
    ItemPointLink *child;
    s32 count2;
    s32 count;
    Vec3 *origin;
    BOOL found;
    s32 best;
    ItemPointLink *best2;
    Vec3 *pos;
    s32 i;
    Vec3 *c;
    Kart *other;
    s32 d;

    if (side != 0) {
        count = node->mNextCount;
        cur = node->mNextLinks[0];
    } else {
        count = node->mPreviousCount;
        cur = node->mPreviousLinks[0];
    }
    if (count <= 1 && (side != 0 ? cur->mPreviousCount : cur->mNextCount) <= 1) {
    done:
        out->mLink = cur;
        out->mNextLinksUsed = side;
        return;
    }
    origin = node->mPointPos;
    found = FALSE;
    best = 0x5f592e1;
    if (idx < 8) {
        other = GetKart(idx);
        pos = &other->mDrawMatrixPos;
        {
            s64 sq = (s64) (((const Vec3 *) pos)->x - ((const Vec3 *) origin)->x) *
                     (((const Vec3 *) pos)->x - ((const Vec3 *) origin)->x);
            sq += (s64) (((const Vec3 *) pos)->z - ((const Vec3 *) origin)->z) *
                  (((const Vec3 *) pos)->z - ((const Vec3 *) origin)->z);
            if (sq < 0x225510000000LL) {
                found = TRUE;
                for (i = 0; i < count; i++) {
                    child = side != 0 ? node->mNextLinks[i] : node->mPreviousLinks[i];
                    if (child != NULL) {
                        c = child->mPointPos;
                        d = ((pos->x - origin->x) >> 12) * ((c->x - origin->x) >> 12);
                        d += ((pos->z - origin->z) >> 12) * ((c->z - origin->z) >> 12);
                        if (d > 0) {
                            d = ((child->mPointPos->x - pos->x) >> 12) * ((child->mPointPos->x - pos->x) >> 12);
                            d += ((child->mPointPos->y - pos->y) >> 12) * ((child->mPointPos->y - pos->y) >> 12);
                            d += ((child->mPointPos->z - pos->z) >> 12) * ((child->mPointPos->z - pos->z) >> 12);
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
        if ((side != 0 ? cur->mPreviousCount : cur->mNextCount) > 1) {
            best2 = NULL;
            count2 = side != 0 ? cur->mPreviousCount : cur->mNextCount;
            for (i = 0; i < count2; i++) {
                child = side != 0 ? cur->mPreviousLinks[i] : cur->mNextLinks[i];
                if (child != NULL && child != node) {
                    if (found != FALSE) {
                        c = child->mPointPos;
                        d = ((pos->x - origin->x) >> 12) * ((c->x - origin->x) >> 12);
                        d += ((pos->z - origin->z) >> 12) * ((c->z - origin->z) >> 12);
                        if (d > 0) {
                            d = ((child->mPointPos->x - pos->x) >> 12) * ((child->mPointPos->x - pos->x) >> 12);
                            d += ((child->mPointPos->y - pos->y) >> 12) * ((child->mPointPos->y - pos->y) >> 12);
                            d += ((child->mPointPos->z - pos->z) >> 12) * ((child->mPointPos->z - pos->z) >> 12);
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

u8 GetItemPointLinkIndex(Unk020f36d8 *p) {
    s32 t = p->mUnk_00;

    if (t == 0) {
        return 0xff;
    }
    return (t - gCourseMap->mItemRoute0FirstLink) / 40;
}

s32 SetItemPointLinkRefFromIndex(u32 a, u32 *b) {
    if (a >= 0xff) {
        *b = 0;
    } else {
        *b = gCourseMap->mItemRoute0FirstLink + a * 0x28;
    }
    b[1] = 1;
    return 1;
}

u32 GetItemPointLinkDirection(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    value2 = *(const s8 *) ((value0) + (33));
    value2 = (value2 << 6);
    *(u32 *) ((value1) + (0)) = value2;
    value2 = *(const s8 *) ((value0) + (34));
    value2 = (value2 << 6);
    *(u32 *) ((value1) + (4)) = value2;
    value0 = *(const s8 *) ((value0) + (35));
    value0 = (value0 << 6);
    *(u32 *) ((value1) + (8)) = value0;
    return value0;
}

#pragma thumb on

// Sets each link's direction to its first next link; also fills data_0217bc38.
void InitItemPointLinkDirections(void) {
    ItemPointLink *e;
    Vec3 v;
    u32 n;
    u16 i;

    n = gCourseMap->mItemPointCount;
    e = gCourseMap->mItemPointLinks;
    i = 0;
    for (i = 0; i < 4; i++) {
        data_0217bc38[i] = 0;
    }
    for (i = 0; i < n; i++, e++) {
        if (e->mUnk_1c >= 0x3e8000) {
            data_0217bc38[e->mUnk_20] = (s32) e;
        }
    }
    e = gCourseMap->mItemPointLinks;
    for (i = 0; i < n; i++, e++) {
        VEC_Subtract(e->mNextLinks[0]->mPointPos, e->mPointPos, &v);
        if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&v, &v);
        }
        e->mDirectionX = v.x >> 6;
        e->mDirectionY = v.y >> 6;
        e->mDirectionZ = v.z >> 6;
    }
}

#pragma thumb off

static inline u32 ThrowBouncingItem_inline(Unk020f41c4_B *x, u32 n) {
    x->mUnk_00 = x->mUnk_08 * x->mUnk_00 + x->mUnk_10;
    return ((u64) (u32) (x->mUnk_00 >> 32) * n) >> 32;
}

// Gives a bouncing item its start velocity and position from the kart; c is 1 to throw forward.
void ThrowBouncingItem(BouncingItemObject *p, ItemInUse *a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    Vec3 v;
    s32 n;
    BOOL m;
    Vec3 *u;
    s32 dx;
    s32 dy;
    s32 dz;

    n = Vec3DotUnrounded(&a->mUnk_06c, &a->mUnk_02c.mUnk_18);
    m = (a->mKart->mUnk_48 & 1) != 0;
    n = ((s64) n * 0x1ec) >> 12;
    if (n < 0x666) {
        n = 0x666;
    }
    if (c != 0) {
        n = func_020edc9c(a, d, 0x1b33, 0x7000, &v);
    } else {
        n = func_020edb8c(a, n, 0x1000, 0x7000, &v);
    }
    if (c != 0) {
        if (a->mKartHopHeight > 0) {
            n += (s32) (((s64) a->mKartHopHeight * 0x14cd) >> 12);
        }
    }
    if (a->mKartVelocityLength < 0x3000) {
        v.z += ThrowBouncingItem_inline(&gRaceProgress->mRandom, 0xf6) - 0x7b;
        v.x += ThrowBouncingItem_inline(&gRaceProgress->mRandom, 0xf6) - 0x7b;
    }
    v.x = ((s64) v.x * n) >> 12;
    v.y = ((s64) v.y * n) >> 12;
    v.z = ((s64) v.z * n) >> 12;
    if (!m) {
        if (c != 0) {
            n = e + (s32) (((s64) a->mKartVelocityLength * 0x200) >> 12) + (s32) (((s64) a->mUnk_06c.y * 0x2000) >> 12);
        } else {
            n = f;
            dx = a->mUnk_06c.y > 0 ? 0x666 : 0x1333;
            n += (s32) (((s64) dx * a->mUnk_06c.y) >> 12);
        }
        VEC_MultAdd(n, &a->mUnk_02c.mUnk_0c, &v, &p->mItemObject.mVelocity);
    }
    if (c == 0) {
        VEC_Add(&p->mItemObject.mVelocity, &a->mKart->mUnk_1fc, &p->mItemObject.mVelocity);
    }
    if (c != 0) {
        p->mItemObject.mPos = a->mKart->mCollisionCenter;
        VEC_MultAdd(p->mItemObject.mScale.z * 10, &a->mUnk_02c.mUnk_18, &p->mItemObject.mPos, &p->mItemObject.mPos);
    } else {
        if (a->mKartHopHeight != 0 && a->mKartVelocityLength < 0x2000 && p->mItemObject.mScale.z < 0xccd) {
            VEC_Subtract(&a->mUnk_02c.mUnk_0c, &a->mUnk_02c.mUnk_18, &v);
            VEC_MultAdd(0x2000, &v, &p->mItemObject.mPos, &p->mItemObject.mPos);
        }
    }
    if (p->mItemObject.mScale.z < 0xccd) {
        u = &p->mItemObject.mScale;
        u->x = 0xccd;
        u->y = 0xccd;
        u->z = 0xccd;
    }
    p->mBouncesRemaining = b;
    p->mItemObject.mBounce = BounceItemObject;
    p->mItemObject.mFlags &= ~0x7000000;
    if (!m) {
        return;
    }
    n = VEC_DotProduct(&a->mUnk_02c.mUnk_0c, &p->mItemObject.mVelocity);
    dx = ((s64) a->mUnk_02c.mUnk_0c.x * n) >> 12;
    dy = ((s64) a->mUnk_02c.mUnk_0c.y * n) >> 12;
    dz = ((s64) a->mUnk_02c.mUnk_0c.z * n) >> 12;
    p->mItemObject.mVelocity.x -= dx;
    p->mItemObject.mVelocity.y -= dy;
    p->mItemObject.mVelocity.z -= dz;
    VEC_MultAdd(c != 0 ? 0x8800 : -0x1000, &a->mUnk_02c.mUnk_0c, &p->mItemObject.mVelocity, &p->mItemObject.mVelocity);
    p->mBouncesRemaining = 0;
}

void InitBouncingItem(BouncingItemObject *a, s32 b, Vec3 *c) {
    if (c != NULL) {
        a->mItemObject.mVelocity = *c;
    }
    if (a->mItemObject.mScale.z < 0xccd) {
        a->mItemObject.mScale.x = 0xccd;
        a->mItemObject.mScale.y = 0xccd;
        a->mItemObject.mScale.z = 0xccd;
    }
    a->mBouncesRemaining = b;
    a->mItemObject.mBounce = BounceItemObject;
    a->mItemObject.mFlags &= ~0x7000000;
}

// One step: moves by the velocity and reflects it at a surface while bounces are left.
void AdvanceBouncingItem(BouncingItemObject *a, s32 b, s32 c, s32 d, u32 *e) {
    Vec3 t;
    Vec3 u;
    Vec3 v;
    Vec3 *p;
    Vec3 *q;
    s32 n;

    p = &a->mItemObject.mVelocity;
    q = &a->mItemObject.mPos;
    VEC_Add(p, q, q);
    p->x = ((s64) p->x * c) >> 12;
    p->y = ((s64) p->y * c) >> 12;
    p->z = ((s64) p->z * c) >> 12;
    if (func_01ffdee4(q, &a->mItemObject.mPrevPos, 0, a->mItemObject.mUnk_dc, 0x24, a->mItemObject.mCollisionSlotIndex,
                      &t, &u, (s32 *) &v, &a->mItemObject.mCollisionBits, NULL, NULL, NULL, e) != 0) {
        VEC_Add(&t, q, q);
        if (a->mItemObject.mCollisionBits & 0x1e34ef) {
            n = a->mBouncesRemaining;
            a->mBouncesRemaining = n - 1;
            if (n <= 0) {
                func_020f9334(a, q, p, b, &u);
            } else {
                a->mItemObject.mFlags |= 0x10;
                n = VEC_DotProduct(&u, p);
                t.x = ((s64) u.x * n) >> 12;
                t.y = ((s64) u.y * n) >> 12;
                t.z = ((s64) u.z * n) >> 12;
                p->x -= t.x;
                p->y -= t.y;
                p->z -= t.z;
                p->x = ((s64) p->x * 0x8cd) >> 12;
                p->y = ((s64) p->y * 0x8cd) >> 12;
                p->z = ((s64) p->z * 0x8cd) >> 12;
                VEC_MultAdd(-d, &t, p, p);
                a->mItemObject.mNormal = u;
            }
        }
        if (a->mItemObject.mCollisionBits & 0x214300) {
            a->mItemObject.mFlags |= 0x20;
            BounceItemVelocityOffSurface(p, &v);
            if (func_020f9290(a, &v) != FALSE) {
                return;
            }
            a->mItemObject.mUnk_78 &= ~0x4000;
        }
        if (a->mItemObject.mCollisionBits & 0x8000) {
            func_020f7070(a, 1);
            return;
        }
    }
    a->mItemObject.mFlags &= ~0x4000000;
    if (a->mItemObject.mCollisionBits & 0x1e34ef) {
        return;
    }
    p->y -= b;
    if (p->y < -0xa000) {
        p->y = -0xa000;
    }
}

// Hit handler of bouncing items: reflects the velocity about the surface normal.
void BounceItemObject(ItemObject *a, Vec3 *b, Vec3 *c) {
    BounceItemVelocityOffSurface(&a->mVelocity, c);
    if (a->mFlags & 0x1000000) {
        return;
    }
    a->mFlags |= 0x1000000;
    a->mUnk_108.x = 0;
    a->mUnk_108.y = 0;
    a->mUnk_108.z = 0;
}
