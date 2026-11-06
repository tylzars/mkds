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

    fl = p->mUnk_000.mDistanceSquaredAndFlags;
    y = p->mUnk_000.mScale.y;
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
            if (p->mUnk_000.mKind == 0x192) {
                func_0208b748(0x54, &p->mUnk_000.mPos, &u, func_020d6538);
                func_0208b748(0x57, &p->mUnk_000.mPos, &w, func_020d6538);
            } else {
                func_0208b748(0x56, &p->mUnk_000.mPos, &u, func_020d6538);
                func_0208b748(0x55, &p->mUnk_000.mPos, &w, func_020d6538);
            }
        }
    }
    func_020d5dd0(p);
}

void func_020d5fb4(void *a, Unk020d5bf0 *p) {
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
        p->mUnk_000.mFlags &= ~2;
        p->mUnk_000.mFlags &= ~8;
        p->mUnk_000.mAlpha = 1;
        return;
    }
    x = p->mUnk_0e4.x;
    z = p->mUnk_0e4.z;
    func_020d84e4(&p->mUnk_0a4);
    func_020d8bc0(&p->mUnk_0a4.mUnk_00, &p->mUnk_0e4);
    p->mUnk_000.mUnk_10.x = p->mUnk_0e4.x - x;
    p->mUnk_000.mUnk_10.z = p->mUnk_0e4.z - z;
    p->mUnk_100 += p->mUnk_0f8;
    p->mUnk_104 += p->mUnk_0fc;
    p->mUnk_000.mUnk_10.x += p->mUnk_0f8;
    p->mUnk_000.mUnk_10.z += p->mUnk_0fc;
    p->mUnk_000.mPos.x = p->mUnk_0e4.x + p->mUnk_100;
    p->mUnk_000.mPos.z = p->mUnk_0e4.z + p->mUnk_104;
    p->mUnk_100 = (p->mUnk_100 * 0x3f) >> 6;
    p->mUnk_104 = (p->mUnk_104 * 0x3f) >> 6;
    d = p->mUnk_0e4.y - (p->mUnk_000.mPos.y - p->mUnk_11c);
    if (d > 0) {
        p->mUnk_000.mPos.y = p->mUnk_000.mPos.y + d;
        v = p->mUnk_000.mUnk_10.y;
        if (v < 0) {
            if (v >= -0x2000) {
                p->mUnk_000.mUnk_10.y = 0;
            } else {
                p->mUnk_000.mUnk_10.y = -(s32) (((s64) v * p->mUnk_120) >> 12);
                p->mUnk_0f4 = (p->mUnk_0f4 == FALSE);
                if (p->mUnk_000.mUnk_10.y > 0x4000) {
                    i = (u16) p->mUnk_0a4.mUnk_00.mUnk_0c;
                    p->mUnk_000.mUnk_10.y = 0x4000;
                    if (p->mUnk_0f4 != FALSE) {
                        p->mUnk_0f8 = p->mUnk_0f0[i].x << 1;
                        p->mUnk_0fc = p->mUnk_0f0[i].z >> 1;
                    } else {
                        p->mUnk_0f8 = -p->mUnk_0f0[i].x >> 1;
                        p->mUnk_0fc = -p->mUnk_0f0[i].z >> 1;
                    }
                } else {
                    p->mUnk_0f8 = 0;
                    p->mUnk_0fc = 0;
                }
            }
        }
        p->mUnk_108 = 0;
    } else {
        p->mUnk_108 += 1;
    }
    if (p->mUnk_108 < 10) {
        StartMapObjectSoundWhileRequested(&p->mUnk_000, 0x179);
    }
    p->mUnk_000.mUnk_10.y = p->mUnk_000.mUnk_10.y - 0x400;
    p->mUnk_000.mPos.y = p->mUnk_000.mPos.y + p->mUnk_000.mUnk_10.y;
    if (p->mUnk_110 != 0 && p->mUnk_000.mScale.y < p->mUnk_114) {
        r = p->mUnk_000.mScale.y + p->mUnk_110;
        u = (r * 0x1e000) >> 12;
        FX_DivAsync(0x1000, u);
        w = &p->mUnk_000.mScale;
        w->x = r;
        w->y = r;
        w->z = r;
        p->mUnk_11c = u;
        p->mUnk_000.mExtent.x = (r * 0x1b000) >> 12;
        if (p->mUnk_000.mCollisionSlotIndex >= 0) {
            func_020d5148(p->mUnk_000.mCollisionSlotIndex, p->mUnk_000.mExtent.x);
        }
        p->mUnk_000.mViewRadius = ((s64) p->mUnk_000.mKindData->mUnk_2c * r) >> 12;
        p->mUnk_118 = FX_GetDivResult();
    }
    if (p->mUnk_0a4.mUnk_00.mUnk_18 == 0) {
        func_020d634c(p, 0);
    } else if (p->mUnk_000.mPos.y < 0) {
        func_020d634c(p, 0);
    }
}

u8 func_020d5f8c(Unk020d5bf0 *a, s32 b, u8 *c, u8 *d) {
    if (*c == 1) {
        func_020d634c(a, 1);
    }
    return *d;
}

u8 func_020d5f64(Unk020d5bf0 *a, s32 b, u8 *c, u8 *d) {
    if (*c == 1) {
        func_020d634c(a, 1);
    }
    return *d;
}

void func_020d5dd0(Unk020d5bf0 *p) {
    s64 r;
    s32 u;
    s32 z;
    Vec3 *v;

    func_020d859c(&p->mUnk_0a4, 0, 1);
    func_020d8b18(&p->mUnk_0a4.mUnk_00, &p->mUnk_000.mPos, &p->mUnk_000.mUnk_10);
    p->mUnk_0e0 = p->mUnk_0dc;
    if (p->mUnk_0e0 != 0) {
        p->mUnk_000.mFlags |= data_0215691c;
        p->mUnk_000.mFlags |= data_02156914;
    }
    p->mUnk_0e4 = p->mUnk_000.mPos;
    p->mUnk_0f4 = TRUE;
    z = 0;
    p->mUnk_0f8 = z;
    p->mUnk_0fc = z;
    p->mUnk_100 = z;
    p->mUnk_104 = z;
    p->mUnk_000.mPos.y = p->mUnk_0a0;
    p->mUnk_000.mUnk_10.y = 0x8000;
    p->mUnk_000.mMatrix.mUnk_00[0] = data_021569d8;
    p->mUnk_000.mMatrix.mUnk_00[1] = data_021569e4;
    p->mUnk_000.mMatrix.mUnk_00[2] = data_021569f0;
    r = p->mUnk_10c;
    u = (r * 0x1e000) >> 12;
    FX_DivAsync(0x1000, u);
    v = &p->mUnk_000.mScale;
    v->x = r;
    v->y = r;
    v->z = r;
    p->mUnk_11c = u;
    p->mUnk_000.mExtent.x = (r * 0x1b000) >> 12;
    if (p->mUnk_000.mCollisionSlotIndex >= 0) {
        func_020d5148(p->mUnk_000.mCollisionSlotIndex, p->mUnk_000.mExtent.x);
    }
    p->mUnk_000.mViewRadius = ((s64) p->mUnk_000.mKindData->mUnk_2c * r) >> 12;
    p->mUnk_118 = FX_GetDivResult();
}

#pragma thumb on
void CreateNsbmdAndShadowNsbmd(void *a, const char *name, const char *shadowName) {
    func_020ea588((void **) &gRock, FindCourseMapObjFile(name), NULL);
    func_020ea55c((void **) &gRockShadow, FindCourseMapObjFile(shadowName), 7);
    func_02084968(gRock, 0x3f, 2, 0x294a);
    func_020849c0(gRock, 7);
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
void func_020d5bf0(Unk020d5bf0 *p, struct CourseMapRow *q) {
    Unk02042044 *t;
    s32 v;
    float f;

    func_020d7d4c(&p->mUnk_0a4, q, 0x3000, q->mUnk_2a);
    p->mUnk_0dc = q->mUnk_28;
    p->mUnk_0f0 = func_020d8654(q);
    t = GetCourseMapGroupEntry(q->mUnk_26, 0);
    p->mUnk_0a0 = t->mUnk_00.y;
    p->mUnk_10c = p->mUnk_000.mScale.y;
    v = q->mUnk_2e;
    if (v > 0) {
        f = 0.5f + (v << 12);
    } else {
        f = (v << 12) - 0.5f;
    }
    p->mUnk_110 = (s32) f / 60000;
    v = q->mUnk_30;
    if (v > 0) {
        f = 0.5f + (v << 12);
    } else {
        f = (v << 12) - 0.5f;
    }
    p->mUnk_114 = (s32) f / 1000 + 0x1000;
    func_020d5dd0(p);
    p->mUnk_108 = 0;
    p->mUnk_0e0 = q->mUnk_32;
    if (p->mUnk_0e0 != 0) {
        p->mUnk_000.mFlags |= data_0215691c;
        p->mUnk_000.mFlags |= data_02156914;
    } else {
        p->mUnk_000.mFlags &= ~2;
        p->mUnk_000.mFlags &= ~8;
        p->mUnk_000.mAlpha = 0x1f;
    }
    p->mUnk_120 = (q->mUnk_2c << 12) / 100;
    if (p->mUnk_000.mKind == 0x192) {
        CreateMapObjectSoundSourceFalloff4(&p->mUnk_000);
    } else {
        CreateMapObjectSoundSourceFalloff3(&p->mUnk_000);
    }
    p->mUnk_000.mFlags |= data_02156918;
}
#pragma thumb off

#pragma thumb on
void func_020d5bac(Unk0217b614 *p, Unk0217b614 *a) {
    *p = *a;
    p->mUnk_00 = (Vec3 *) ((u32) a + (u32) p->mUnk_00);
    p->mUnk_04 = (UnkVec16 *) ((u32) a + (u32) p->mUnk_04);
    p->mUnk_08 = (Unk0217b614_08 *) ((u32) a + (u32) p->mUnk_08);
    p->mUnk_0c = (u8 *) ((u32) a + (u32) p->mUnk_0c);
    data_0217b610 = 0;
}
#pragma thumb off

#pragma thumb on
void InitCourseCollision(void) {
    func_020d5bac(&gCourseCollision, FindCourseFile("course_collision.kcl"));
}
#pragma thumb off

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

BOOL func_020d5a68(void *a, u32 b, Unk020e04b0 *c) {
    Unk020d5a68 **q = a;

    if ((b & 0x80000000) || (*q)->mUnk_04 != 0 || c->mUnk_00 != (*q)->mUnk_00) {
        return TRUE;
    }
    return FALSE;
}

u16 func_020d59f8(u32 a) {
    s32 i;
    s32 r;
    u32 v;
    u32 w;
    s32 n;

    r = -1;
    i = 0;
    n = data_027e0060;
    if (n > 0) {
        do {
            v = a & data_027e0084[i];
            if (v != 0) {
                if (r < 0 || v > w) {
                    r = i;
                    w = v;
                }
            }
            i++;
        } while (i < n);
    }
    return data_027e0064[r];
}

void func_020d58c0(void) {
    void *h;
    s16 i;
    s16 j;

    h = GetHeap(func_020364e8());
    data_0217b5b0 = 0;
    data_0217b5ac = 0;
    data_0217b5b4 = HeapAlloc(h, 0x400);
    data_0217b5c0 = HeapAlloc(h, 0x400);
    data_0217b5b8 = HeapAlloc(h, 0x1c00);
    data_0217b5c8 = HeapAlloc(h, 0x200);
    data_0217b5cc = HeapAlloc(h, 0x100);
    data_0217b5bc = HeapAlloc(h, 0x100);
    data_0217b5c4 = HeapAlloc(h, 0x200);
    i = 0;
    do {
        data_0217b5c8[i] = i + 1;
        i++;
    } while (i < 0x100);
    j = 0;
    do {
        data_0217b5b8[j].mUnk_0c = NULL;
        j++;
    } while (j < 0x100);
}

s32 func_020d555c(Vec3 *a, s32 b, s32 c, void *d) {
    Unk0217b5b8 *e;
    s16 hi;
    s16 lo;
    s32 i;
    s32 p;
    s32 q;
    s32 s;
    s32 t;
    s32 j;
    s32 m;
    Unk0217b5b4 *f;
    Unk0217b5b4 *u;

    if (data_0217b5b0 >= 0x100) {
        return -1;
    }
    i = data_0217b5ac;
    data_0217b5ac = data_0217b5c8[i];
    e = &data_0217b5b8[i];
    e->mUnk_04 = a->z + b;
    e->mUnk_08 = a->z - b;
    e->mUnk_0c = a;
    e->mUnk_10 = b;
    e->mUnk_14 = c;
    e->mUnk_18 = d;
    hi = (a->x + b) >> 11;
    lo = (a->x - b) >> 11;
    if (data_0217b5b0 == 0) {
        data_0217b5b4[0].mUnk_00 = 0;
        data_0217b5b4[0].mUnk_01 = 0;
        data_0217b5b4[0].mUnk_02 = hi;
        data_0217b5c0[0].mUnk_00 = 0;
        data_0217b5c0[0].mUnk_01 = i;
        data_0217b5c0[0].mUnk_02 = lo;
        data_0217b5b8[0].mUnk_00 = 0;
        data_0217b5b8[0].mUnk_02 = 0;
        data_0217b5b0 = 1;
        return i;
    }
    p = 0;
    q = 0;
    s = data_0217b5b0;
    m = data_0217b5b0;
    for (;;) {
        t = p + s;
        j = q + s;
        if (t <= m) {
            if (hi > data_0217b5b4[t - 1].mUnk_02) {
                p = t;
            }
        }
        if (j <= m) {
            if (lo > data_0217b5c0[j - 1].mUnk_02) {
                q = j;
            }
        }
        if (s == 1) {
            break;
        }
        s = (s + 1) >> 1;
    }
    e->mUnk_00 = p;
    e->mUnk_02 = q;
    m = data_0217b5b0;
    if (m > p) {
        do {
            f = &data_0217b5b4[m];
            *f = data_0217b5b4[m - 1];
            u = &data_0217b5c0[f->mUnk_00];
            u->mUnk_00 += 1;
            data_0217b5b8[u->mUnk_01].mUnk_00 += 1;
            m--;
            if (f->mUnk_01 >= q) {
                f->mUnk_01 += 1;
            }
        } while (m > p);
    }
    data_0217b5b4[p].mUnk_00 = q;
    data_0217b5b4[p].mUnk_02 = hi;
    if (p == data_0217b5b0 || data_0217b5b4[p + 1].mUnk_01 > q) {
        data_0217b5b4[p].mUnk_01 = q;
        for (j = p - 1; j >= 0 && data_0217b5b4[j].mUnk_01 > q; j--) {
            data_0217b5b4[j].mUnk_01 = q;
        }
    } else {
        data_0217b5b4[p].mUnk_01 = data_0217b5b4[p + 1].mUnk_01;
    }
    m = data_0217b5b0;
    if (m > q) {
        do {
            f = &data_0217b5c0[m];
            *f = data_0217b5c0[m - 1];
            data_0217b5b4[f->mUnk_00].mUnk_00 += 1;
            data_0217b5b8[f->mUnk_01].mUnk_02 += 1;
            m--;
        } while (m > q);
    }
    data_0217b5c0[q].mUnk_00 = p;
    data_0217b5c0[q].mUnk_01 = i;
    data_0217b5c0[q].mUnk_02 = lo;
    data_0217b5b0 += 1;
    return i;
}

u32 func_020d5344(s32 a) {
    Unk0217b5b8 *e;
    s32 s;
    s32 t;
    s32 k;
    s32 j;
    s32 v;
    Unk0217b5b4 *q;
    Unk0217b5b4 *c;

    if (a < 0 || a >= 0x100) {
        return -1;
    }
    e = &data_0217b5b8[a];
    s = e->mUnk_00;
    t = e->mUnk_02;
    if (e->mUnk_0c == NULL) {
        return -1;
    }
    k = s;
    if (k < data_0217b5b0 - 1) {
        do {
            q = &data_0217b5b4[k];
            *q = data_0217b5b4[k + 1];
            c = &data_0217b5c0[q->mUnk_00];
            c->mUnk_00 -= 1;
            data_0217b5b8[c->mUnk_01].mUnk_00 -= 1;
            if (q->mUnk_01 > t) {
                q->mUnk_01 -= 1;
            }
            k++;
        } while (k < data_0217b5b0 - 1);
    }
    k = t;
    if (k < data_0217b5b0 - 1) {
        do {
            q = &data_0217b5c0[k];
            *q = data_0217b5c0[k + 1];
            data_0217b5b4[q->mUnk_00].mUnk_00 -= 1;
            data_0217b5b8[q->mUnk_01].mUnk_02 -= 1;
            v = q->mUnk_00;
            if (v < s) {
                c = &data_0217b5b4[v];
                j = c->mUnk_01;
                if (j == t) {
                    while (data_0217b5c0[j].mUnk_00 < (u32) v) {
                        j++;
                    }
                    c->mUnk_01 = j;
                }
            }
            k++;
        } while (k < data_0217b5b0 - 1);
    }
    e->mUnk_0c = NULL;
    data_0217b5c8[a] = data_0217b5ac;
    data_0217b5ac = a;
    data_0217b5b0 -= 1;
    return -1;
}

void func_020d5180(Vec3 *a, s32 b, s32 c) {
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
    Unk0217b5b8 *e;
    s32 f;

    m = data_0217b5b0;
    k = v->x;
    z = v->z;
    hi = (s16) ((k + b) >> 11);
    lo = (s16) ((k - b) >> 11);
    p = 0;
    data_0217b5a8 = 0;
    k = 0;
    zhi = z + b;
    zlo = z - b;
    s = m - 1;
    for (;;) {
        t = p + s;
        j = k + s;
        if (t <= m) {
            if (lo > data_0217b5b4[t - 1].mUnk_02) {
                p = t;
            }
        }
        if (j <= m) {
            if (hi >= data_0217b5c0[j].mUnk_02) {
                k = j;
            }
        }
        if (s == 1) {
            break;
        }
        s = (s + 1) >> 1;
    }
    s = data_0217b5b4[p].mUnk_01;
    if (k < s) {
        return;
    }
    do {
        if (data_0217b5c0[k].mUnk_00 >= p) {
            e = &data_0217b5b8[data_0217b5c0[k].mUnk_01];
            f = e->mUnk_14;
            if (e->mUnk_04 >= zlo && e->mUnk_08 <= zhi && (f & c) && !(f & 0x200)) {
                data_0217b5cc[data_0217b5a8] = data_0217b5c0[k].mUnk_01;
                data_0217b5bc[data_0217b5a8] = f;
                data_0217b5c4[data_0217b5a8] = e->mUnk_18;
                data_0217b5a8++;
                if (data_0217b5a8 == 0x80) {
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

void func_020d5148(s16 a, s32 b) {
    Unk0217b5b8 *e;

    e = &data_0217b5b8[a];
    e->mUnk_10 = b;
    if (e->mUnk_14 & 0x400) {
        e->mUnk_14 |= data_02156900;
    }
}

void func_020d5114(s16 a) {
    data_0217b5b8[a].mUnk_14 |= data_021568fc;
}

void func_020d50ec(s16 a) {
    data_0217b5b8[a].mUnk_14 &= ~0x200;
}
