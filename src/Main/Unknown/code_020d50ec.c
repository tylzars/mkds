#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020e01f0.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020d6538.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_020d275c.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020ea55c.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020d8654.h"

// Calls func_0208b748 twice at the rock; skipped when bit 0 of mDistanceSquaredAndFlags is set, or when b is 0 and bit
// 1 is set. Then resets the rock.
void func_020d634c(Unk020d5bf0 *p, s32 b) {
    Unk020d634c u;
    Unk020d634c w;
    s32 y;
    u32 fl;
    s32 k;
    s32 j;
    s32 a;
    s16 c;
    s16 d;
    s32 e;
    s32 f;
    s16 g;
    s16 h;
    s32 i;

    fl = p->mMapObject.mDistanceSquaredAndFlags;
    y = p->mMapObject.mScale.y;
    if (!(fl & 1)) {
        if (b != 0 || !(fl & 3)) {
            if (y > 0x1000) {
                k = 1;
                j = 0;
            } else {
                k = 3;
                j = 2;
            }
            a = data_02156960[k];
            d = data_02156938[k];
            c = data_02156930[k];
            g = data_02156928[k];
            h = data_02156948[k];
            u.mUnk_00 = data_02156960[j] + (s32) (((s64) a * y) >> 12);
            i = data_02156940[k];
            u.mUnk_04 = data_02156940[j] + (s32) (((s64) i * y) >> 12);
            e = data_02156950[k];
            u.mUnk_06 = data_02156948[j] + (s32) (((s64) h * y) >> 12);
            w.mUnk_00 = data_02156950[j] + (s32) (((s64) e * y) >> 12);
            f = data_02156920[k];
            u.mUnk_08 = data_02156920[j] + (s32) (((s64) f * y) >> 12);
            w.mUnk_04 = data_02156928[j] + (s32) (((s64) g * y) >> 12);
            w.mUnk_06 = data_02156930[j] + (s32) (((s64) c * y) >> 12);
            w.mUnk_08 = data_02156938[j] + (s32) (((s64) d * y) >> 12);
            if (p->mMapObject.mKind == 0x192) {
                func_0208b748(0x54, &p->mMapObject.mPos, &u, func_020d6538);
                func_0208b748(0x57, &p->mMapObject.mPos, &w, func_020d6538);
            } else {
                func_0208b748(0x56, &p->mMapObject.mPos, &u, func_020d6538);
                func_0208b748(0x55, &p->mMapObject.mPos, &w, func_020d6538);
            }
        }
    }
    ResetRock(p);
}

void UpdateRock(void *a, Unk020d5bf0 *p) {
    s32 x;
    s32 z;
    s32 d;
    s32 v;
    s32 i;
    s64 r;
    s32 u;
    Vec3 *w;

    if (p->mUnk_0e0 > 0) {
        p->mUnk_0e0 -= 1;
        if (p->mUnk_0e0 != 0) {
            return;
        }
        p->mMapObject.mFlags &= ~2;
        p->mMapObject.mFlags &= ~8;
        p->mMapObject.mAlpha = 1;
        return;
    }
    x = p->mBasePos.x;
    z = p->mBasePos.z;
    func_020d84e4(&p->mUnk_0a4);
    func_020d8bc0(&p->mUnk_0a4.mUnk_00, &p->mBasePos);
    p->mMapObject.mUnk_10.x = p->mBasePos.x - x;
    p->mMapObject.mUnk_10.z = p->mBasePos.z - z;
    p->mOffsetX += p->mOffsetVelocityX;
    p->mOffsetZ += p->mOffsetVelocityZ;
    p->mMapObject.mUnk_10.x += p->mOffsetVelocityX;
    p->mMapObject.mUnk_10.z += p->mOffsetVelocityZ;
    p->mMapObject.mPos.x = p->mBasePos.x + p->mOffsetX;
    p->mMapObject.mPos.z = p->mBasePos.z + p->mOffsetZ;
    p->mOffsetX = (p->mOffsetX * 0x3f) >> 6;
    p->mOffsetZ = (p->mOffsetZ * 0x3f) >> 6;
    d = p->mBasePos.y - (p->mMapObject.mPos.y - p->mBottomOffset);
    if (d > 0) {
        p->mMapObject.mPos.y = p->mMapObject.mPos.y + d;
        v = p->mMapObject.mUnk_10.y;
        if (v < 0) {
            if (v >= -0x2000) {
                p->mMapObject.mUnk_10.y = 0;
            } else {
                p->mMapObject.mUnk_10.y = -(s32) (((s64) v * p->mBounceRatio) >> 12);
                p->mBounceSide = (p->mBounceSide == FALSE);
                if (p->mMapObject.mUnk_10.y > 0x4000) {
                    i = (u16) p->mUnk_0a4.mUnk_00.mUnk_0c;
                    p->mMapObject.mUnk_10.y = 0x4000;
                    if (p->mBounceSide != FALSE) {
                        p->mOffsetVelocityX = p->mSideVectors[i].x << 1;
                        p->mOffsetVelocityZ = p->mSideVectors[i].z >> 1;
                    } else {
                        p->mOffsetVelocityX = -p->mSideVectors[i].x >> 1;
                        p->mOffsetVelocityZ = -p->mSideVectors[i].z >> 1;
                    }
                } else {
                    p->mOffsetVelocityX = 0;
                    p->mOffsetVelocityZ = 0;
                }
            }
        }
        p->mSinceGroundFrames = 0;
    } else {
        p->mSinceGroundFrames += 1;
    }
    if (p->mSinceGroundFrames < 10) {
        StartMapObjectSoundWhileRequested(&p->mMapObject, 0x179);
    }
    p->mMapObject.mUnk_10.y = p->mMapObject.mUnk_10.y - 0x400;
    p->mMapObject.mPos.y = p->mMapObject.mPos.y + p->mMapObject.mUnk_10.y;
    if (p->mScalePerFrame != 0 && p->mMapObject.mScale.y < p->mScaleLimit) {
        r = p->mMapObject.mScale.y + p->mScalePerFrame;
        u = (r * 0x1e000) >> 12;
        FX_DivAsync(0x1000, u);
        w = &p->mMapObject.mScale;
        w->x = r;
        w->y = r;
        w->z = r;
        p->mBottomOffset = u;
        p->mMapObject.mExtent.x = (r * 0x1b000) >> 12;
        if (p->mMapObject.mCollisionSlotIndex >= 0) {
            SetCollisionSlotRadius(p->mMapObject.mCollisionSlotIndex, p->mMapObject.mExtent.x);
        }
        p->mMapObject.mViewRadius = ((s64) p->mMapObject.mKindData->mUnk_2c * r) >> 12;
        p->mBottomOffsetReciprocal = FX_GetDivResult();
    }
    if (p->mUnk_0a4.mUnk_00.mUnk_18 == 0) {
        func_020d634c(p, 0);
    } else if (p->mMapObject.mPos.y < 0) {
        func_020d634c(p, 0);
    }
}

// Calls func_020d634c with b = 1 when the byte at c is 1; returns the byte at d.
u8 func_020d5f8c(Unk020d5bf0 *a, s32 b, u8 *c, u8 *d) {
    if (*c == 1) {
        func_020d634c(a, 1);
    }
    return *d;
}

// Same body as func_020d5f8c.
u8 func_020d5f64(Unk020d5bf0 *a, s32 b, u8 *c, u8 *d) {
    if (*c == 1) {
        func_020d634c(a, 1);
    }
    return *d;
}

// Puts the rock back at its start: timer, position, speed and scale.
void ResetRock(Unk020d5bf0 *p) {
    s64 r;
    s32 u;
    s32 z;
    Vec3 *v;

    func_020d859c(&p->mUnk_0a4, 0, 1);
    func_020d8b18(&p->mUnk_0a4.mUnk_00, &p->mMapObject.mPos, &p->mMapObject.mUnk_10);
    p->mUnk_0e0 = p->mUnk_0dc;
    if (p->mUnk_0e0 != 0) {
        p->mMapObject.mFlags |= data_0215691c;
        p->mMapObject.mFlags |= data_02156914;
    }
    p->mBasePos = p->mMapObject.mPos;
    p->mBounceSide = TRUE;
    z = 0;
    p->mOffsetVelocityX = z;
    p->mOffsetVelocityZ = z;
    p->mOffsetX = z;
    p->mOffsetZ = z;
    p->mMapObject.mPos.y = p->mStartY;
    p->mMapObject.mUnk_10.y = 0x8000;
    p->mMapObject.mMatrix.mUnk_00[0] = data_021569d8;
    p->mMapObject.mMatrix.mUnk_00[1] = data_021569e4;
    p->mMapObject.mMatrix.mUnk_00[2] = data_021569f0;
    r = p->mStartScale;
    u = (r * 0x1e000) >> 12;
    FX_DivAsync(0x1000, u);
    v = &p->mMapObject.mScale;
    v->x = r;
    v->y = r;
    v->z = r;
    p->mBottomOffset = u;
    p->mMapObject.mExtent.x = (r * 0x1b000) >> 12;
    if (p->mMapObject.mCollisionSlotIndex >= 0) {
        SetCollisionSlotRadius(p->mMapObject.mCollisionSlotIndex, p->mMapObject.mExtent.x);
    }
    p->mMapObject.mViewRadius = ((s64) p->mMapObject.mKindData->mUnk_2c * r) >> 12;
    p->mBottomOffsetReciprocal = FX_GetDivResult();
}

#pragma thumb on
void CreateNsbmdAndShadowNsbmd(void *a, const char *name, const char *shadowName) {
    func_020ea588((void **) &gRock, FindCourseMapObjFile(name), NULL);
    func_020ea55c((void **) &gRockShadow, FindCourseMapObjFile(shadowName), 7);
    func_02084968(gRock, 0x3f, 2, 0x294a);
    SetNsbmdPolygonIdAll(gRock, 7);
}
#pragma thumb off

#pragma thumb on
void CreateRock(void *a) {
    CreateNsbmdAndShadowNsbmd(a, "rock.nsbmd", "rock_shadow.nsbmd");
}
#pragma thumb off

#pragma thumb on
void CreateRock2(void *a) {
    CreateNsbmdAndShadowNsbmd(a, "rock2.nsbmd", "rock2_shadow.nsbmd");
}
#pragma thumb off

#pragma thumb on
// Fills a Rock from its course map row; both Rock kinds use it.
void InitRock(Unk020d5bf0 *p, struct CourseMapRow *q) {
    Unk02042044 *t;
    s32 v;
    float f;

    func_020d7d4c(&p->mUnk_0a4, q, 0x3000, q->mUnk_2a);
    p->mUnk_0dc = q->mUnk_28;
    p->mSideVectors = func_020d8654(q);
    t = GetCourseMapGroupEntry(q->mUnk_26, 0);
    p->mStartY = t->mUnk_00.y;
    p->mStartScale = p->mMapObject.mScale.y;
    v = q->mUnk_2e;
    if (v > 0) {
        f = 0.5f + (v << 12);
    } else {
        f = (v << 12) - 0.5f;
    }
    p->mScalePerFrame = (s32) f / 60000;
    v = q->mUnk_30;
    if (v > 0) {
        f = 0.5f + (v << 12);
    } else {
        f = (v << 12) - 0.5f;
    }
    p->mScaleLimit = (s32) f / 1000 + 0x1000;
    ResetRock(p);
    p->mSinceGroundFrames = 0;
    p->mUnk_0e0 = q->mUnk_32;
    if (p->mUnk_0e0 != 0) {
        p->mMapObject.mFlags |= data_0215691c;
        p->mMapObject.mFlags |= data_02156914;
    } else {
        p->mMapObject.mFlags &= ~2;
        p->mMapObject.mFlags &= ~8;
        p->mMapObject.mAlpha = 0x1f;
    }
    p->mBounceRatio = (q->mUnk_2c << 12) / 100;
    if (p->mMapObject.mKind == 0x192) {
        CreateMapObjectSoundSourceFalloff4(&p->mMapObject);
    } else {
        CreateMapObjectSoundSourceFalloff3(&p->mMapObject);
    }
    p->mMapObject.mFlags |= data_02156918;
}
#pragma thumb off

#pragma thumb on
// Turns the stored offsets of the loaded collision file into pointers.
void LoadCourseCollisionData(Unk0217b614 *p, Unk0217b614 *a) {
    *p = *a;
    p->mUnk_00 = OFFSET_PTR(Vec3, a, (u32) p->mUnk_00);
    p->mUnk_04 = OFFSET_PTR(UnkVec16, a, (u32) p->mUnk_04);
    p->mUnk_08 = OFFSET_PTR(Unk0217b614_08, a, (u32) p->mUnk_08);
    p->mUnk_0c = OFFSET_PTR(u8, a, (u32) p->mUnk_0c);
    data_0217b610 = 0;
}
#pragma thumb off

#pragma thumb on
void InitCourseCollision(void) {
    LoadCourseCollisionData(&gCourseCollision, FindCourseFile("course_collision.kcl"));
}
#pragma thumb off

// Keeps the link c on the first object of the hit list a: clears it when b has the top bit or the object changed, sets
// it when b has a bit of 0x1e34ef.
void func_020d5aa0(void *a, u32 b, Unk020e04b0 *c, Vec3 *d, Vec3 *e) {
    Unk020d5a68 **q = a;
    Unk020d5a68 *p;

    if (c->mUnk_00 != NULL) {
        if (b & 0x80000000) {
            c->mUnk_00 = NULL;
            return;
        }
        func_020e0538(c, d);
        p = *q;
        if (p->mUnk_04 == 0 && c->mUnk_00 == p->mUnk_00) {
            return;
        }
        c->mUnk_00 = NULL;
        return;
    }
    if (b & 0x80000000) {
        return;
    }
    p = *q;
    if (p->mUnk_00 == NULL) {
        return;
    }
    if (p->mUnk_04 != 0) {
        return;
    }
    if (!(b & 0x1e34ef)) {
        return;
    }
    func_020e0584(p->mUnk_00, d, e, c);
}

// TRUE when b has the top bit, the hit list a has a non-zero word at 4, or its object differs from the link c.
BOOL func_020d5a68(void *a, u32 b, Unk020e04b0 *c) {
    Unk020d5a68 **q = a;

    if ((b & 0x80000000) || (*q)->mUnk_04 != 0 || c->mUnk_00 != (*q)->mUnk_00) {
        return TRUE;
    }
    return FALSE;
}

// Returns the value of the recorded hit with the highest bits inside the mask a.
u16 PickCollisionHitValue(u32 a) {
    s32 i;
    s32 r;
    u32 v;
    u32 w;
    s32 n;

    r = -1;
    i = 0;
    n = gCollisionHitCount;
    if (n > 0) {
        do {
            v = a & gCollisionHitBits[i];
            if (v != 0) {
                if (r < 0 || v > w) {
                    r = i;
                    w = v;
                }
            }
            i++;
        } while (i < n);
    }
    return gCollisionHitValues[r];
}

void InitCollisionSlots(void) {
    void *h;
    s16 i;
    s16 j;

    h = GetHeap(GetCurrentHeapCall());
    gCollisionSlotCount = 0;
    gFirstFreeCollisionSlot = 0;
    gCollisionSlotHighEnds = HeapAlloc(h, 0x400);
    gCollisionSlotLowEnds = HeapAlloc(h, 0x400);
    gCollisionSlots = HeapAlloc(h, 0x1c00);
    gCollisionSlotNextFree = HeapAlloc(h, 0x200);
    gFoundCollisionSlotIndices = HeapAlloc(h, 0x100);
    gFoundCollisionSlotFlags = HeapAlloc(h, 0x100);
    gFoundCollisionSlotObjects = HeapAlloc(h, 0x200);
    i = 0;
    do {
        gCollisionSlotNextFree[i] = i + 1;
        i++;
    } while (i < 0x100);
    j = 0;
    do {
        gCollisionSlots[j].mCenterPos = NULL;
        j++;
    } while (j < 0x100);
}

// Returns the new slot index, or -1 when all 0x100 slots are in use.
s32 CreateCollisionSlot(Vec3 *a, s32 b, s32 c, void *d) {
    CollisionSlot *e;
    s16 hi;
    s16 lo;
    s32 i;
    s32 p;
    s32 q;
    s32 s;
    s32 t;
    s32 j;
    s32 m;
    CollisionSlotEnd *f;
    CollisionSlotEnd *u;

    if (gCollisionSlotCount >= 0x100) {
        return -1;
    }
    i = gFirstFreeCollisionSlot;
    gFirstFreeCollisionSlot = gCollisionSlotNextFree[i];
    e = &gCollisionSlots[i];
    e->mHighZ = a->z + b;
    e->mLowZ = a->z - b;
    e->mCenterPos = a;
    e->mRadius = b;
    e->mFlags = c;
    e->mObject = d;
    hi = (a->x + b) >> 11;
    lo = (a->x - b) >> 11;
    if (gCollisionSlotCount == 0) {
        gCollisionSlotHighEnds[0].mOtherEndIndex = 0;
        gCollisionSlotHighEnds[0].mUnk_01 = 0;
        gCollisionSlotHighEnds[0].mEndX = hi;
        gCollisionSlotLowEnds[0].mOtherEndIndex = 0;
        gCollisionSlotLowEnds[0].mUnk_01 = i;
        gCollisionSlotLowEnds[0].mEndX = lo;
        gCollisionSlots[0].mHighEndIndex = 0;
        gCollisionSlots[0].mLowEndIndex = 0;
        gCollisionSlotCount = 1;
        return i;
    }
    p = 0;
    q = 0;
    s = gCollisionSlotCount;
    m = gCollisionSlotCount;
    for (;;) {
        t = p + s;
        j = q + s;
        if (t <= m) {
            if (hi > gCollisionSlotHighEnds[t - 1].mEndX) {
                p = t;
            }
        }
        if (j <= m) {
            if (lo > gCollisionSlotLowEnds[j - 1].mEndX) {
                q = j;
            }
        }
        if (s == 1) {
            break;
        }
        s = (s + 1) >> 1;
    }
    e->mHighEndIndex = p;
    e->mLowEndIndex = q;
    m = gCollisionSlotCount;
    if (m > p) {
        do {
            f = &gCollisionSlotHighEnds[m];
            *f = gCollisionSlotHighEnds[m - 1];
            u = &gCollisionSlotLowEnds[f->mOtherEndIndex];
            u->mOtherEndIndex += 1;
            gCollisionSlots[u->mUnk_01].mHighEndIndex += 1;
            m--;
            if (f->mUnk_01 >= q) {
                f->mUnk_01 += 1;
            }
        } while (m > p);
    }
    gCollisionSlotHighEnds[p].mOtherEndIndex = q;
    gCollisionSlotHighEnds[p].mEndX = hi;
    if (p == gCollisionSlotCount || gCollisionSlotHighEnds[p + 1].mUnk_01 > q) {
        gCollisionSlotHighEnds[p].mUnk_01 = q;
        for (j = p - 1; j >= 0 && gCollisionSlotHighEnds[j].mUnk_01 > q; j--) {
            gCollisionSlotHighEnds[j].mUnk_01 = q;
        }
    } else {
        gCollisionSlotHighEnds[p].mUnk_01 = gCollisionSlotHighEnds[p + 1].mUnk_01;
    }
    m = gCollisionSlotCount;
    if (m > q) {
        do {
            f = &gCollisionSlotLowEnds[m];
            *f = gCollisionSlotLowEnds[m - 1];
            gCollisionSlotHighEnds[f->mOtherEndIndex].mOtherEndIndex += 1;
            gCollisionSlots[f->mUnk_01].mLowEndIndex += 1;
            m--;
        } while (m > q);
    }
    gCollisionSlotLowEnds[q].mOtherEndIndex = p;
    gCollisionSlotLowEnds[q].mUnk_01 = i;
    gCollisionSlotLowEnds[q].mEndX = lo;
    gCollisionSlotCount += 1;
    return i;
}

// Always returns -1, which the caller stores as its slot index.
u32 FreeCollisionSlot(s32 a) {
    CollisionSlot *e;
    s32 s;
    s32 t;
    s32 k;
    s32 j;
    s32 v;
    CollisionSlotEnd *q;
    CollisionSlotEnd *c;

    if (a < 0 || a >= 0x100) {
        return -1;
    }
    e = &gCollisionSlots[a];
    s = e->mHighEndIndex;
    t = e->mLowEndIndex;
    if (e->mCenterPos == NULL) {
        return -1;
    }
    k = s;
    if (k < gCollisionSlotCount - 1) {
        do {
            q = &gCollisionSlotHighEnds[k];
            *q = gCollisionSlotHighEnds[k + 1];
            c = &gCollisionSlotLowEnds[q->mOtherEndIndex];
            c->mOtherEndIndex -= 1;
            gCollisionSlots[c->mUnk_01].mHighEndIndex -= 1;
            if (q->mUnk_01 > t) {
                q->mUnk_01 -= 1;
            }
            k++;
        } while (k < gCollisionSlotCount - 1);
    }
    k = t;
    if (k < gCollisionSlotCount - 1) {
        do {
            q = &gCollisionSlotLowEnds[k];
            *q = gCollisionSlotLowEnds[k + 1];
            gCollisionSlotHighEnds[q->mOtherEndIndex].mOtherEndIndex -= 1;
            gCollisionSlots[q->mUnk_01].mLowEndIndex -= 1;
            v = q->mOtherEndIndex;
            if (v < s) {
                c = &gCollisionSlotHighEnds[v];
                j = c->mUnk_01;
                if (j == t) {
                    while (gCollisionSlotLowEnds[j].mOtherEndIndex < (u32) v) {
                        j++;
                    }
                    c->mUnk_01 = j;
                }
            }
            k++;
        } while (k < gCollisionSlotCount - 1);
    }
    e->mCenterPos = NULL;
    gCollisionSlotNextFree[a] = gFirstFreeCollisionSlot;
    gFirstFreeCollisionSlot = a;
    gCollisionSlotCount -= 1;
    return -1;
}

// Fills the Found arrays with the slots whose x and z ranges lie within b of position a, whose flags share a bit with
// mask c and that are not disabled.
void FindCollisionSlotsAroundPos(Vec3 *a, s32 b, s32 c) {
    Vec3 *v = a;
    s32 hi;
    s32 lo;
    s32 s;
    s32 j;
    s32 k;
    s32 z;
    s32 m;
    s32 zhi;
    s32 p;
    s32 zlo;
    s32 t;
    CollisionSlot *e;
    s32 f;

    m = gCollisionSlotCount;
    k = v->x;
    z = v->z;
    hi = (s16) ((k + b) >> 11);
    lo = (s16) ((k - b) >> 11);
    p = 0;
    gFoundCollisionSlotCount = 0;
    k = 0;
    zhi = z + b;
    zlo = z - b;
    s = m - 1;
    for (;;) {
        t = p + s;
        j = k + s;
        if (t <= m) {
            if (lo > gCollisionSlotHighEnds[t - 1].mEndX) {
                p = t;
            }
        }
        if (j <= m) {
            if (hi >= gCollisionSlotLowEnds[j].mEndX) {
                k = j;
            }
        }
        if (s == 1) {
            break;
        }
        s = (s + 1) >> 1;
    }
    s = gCollisionSlotHighEnds[p].mUnk_01;
    if (k < s) {
        return;
    }
    do {
        if (gCollisionSlotLowEnds[k].mOtherEndIndex >= p) {
            e = &gCollisionSlots[gCollisionSlotLowEnds[k].mUnk_01];
            f = e->mFlags;
            if (e->mHighZ >= zlo && e->mLowZ <= zhi && (f & c) && !(f & 0x200)) {
                gFoundCollisionSlotIndices[gFoundCollisionSlotCount] = gCollisionSlotLowEnds[k].mUnk_01;
                gFoundCollisionSlotFlags[gFoundCollisionSlotCount] = f;
                gFoundCollisionSlotObjects[gFoundCollisionSlotCount] = e->mObject;
                gFoundCollisionSlotCount++;
                if (gFoundCollisionSlotCount == 0x80) {
                    return;
                }
            } else {
                continue;
            }
        }
        if (k == 0) {
            return;
        }
    } while (--k >= s);
}

// A slot with flag 0x400 also gets the flags of data_02156900 set.
void SetCollisionSlotRadius(s16 a, s32 b) {
    CollisionSlot *e;

    e = &gCollisionSlots[a];
    e->mRadius = b;
    if (e->mFlags & 0x400) {
        e->mFlags |= data_02156900;
    }
}

void DisableCollisionSlot(s16 a) {
    gCollisionSlots[a].mFlags |= data_021568fc;
}

void EnableCollisionSlot(s16 a) {
    gCollisionSlots[a].mFlags &= ~0x200;
}
