#include "01/code_02185ef4.h"

#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0209b60c.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "01/code_0219e000.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020d3c94.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020eb000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020fd264.h"
#include "Main/Unknown/code_02117000.h"
#include "Main/Unknown/code_02118000.h"
#include "Main/Unknown/code_0211e000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "01/code_0218d520.h"
#include "01/unk_021a9000.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/code_0209b000.h"
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
#include "Main/Unknown/code_020d3000.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_02021000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020e6000.h"
#include "01/code_02188950.h"
#include "01/code_02188158.h"
#include "01/code_02188e88.h"
#include "01/code_0219b240.h"
#include "ITCM/code_01ffd000.h"
#include "code_02146d78.h"
#include "01/code_02186000.h"
#include "01/code_02187000.h"
#include "01/code_0219b250.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_02148000.h"
#include "01/callees_0219b000.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/code_020d2000.h"
#include "01/code_021a2034.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_02042000.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_020da000.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/code_020fd000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"

void func_ov001_02187b94(void *a, Vec3 *b, Vec3 *c, s32 d) {
    Vec3 local;
    Vec3 zero;
    Vec3 *p;
    s32 *z;

    if (a != NULL && b != NULL) {
        local = data_ov001_021a7a64;
        p = &local;
        func_020fd684(a, p, b);
        if (c != NULL) {
            func_020fd540(&a, c, d);
        } else {
            z = (s32 *) &zero;
            z[0] = 0;
            z[1] = 0;
            z[2] = 0;
            func_020fd540(&a, &zero, d);
        }
    }
}

void func_ov001_02187b2c(void *a, Vec3 *b, Vec3 *c, s32 d) {
    Vec3 local;
    Vec3 zero;
    Vec3 *p;
    s32 *z;

    if (a != NULL && b != NULL) {
        local = data_ov001_021a7a70;
        p = &local;
        func_020f4e78(a, p, b);
        if (c != NULL) {
            func_020f4dfc(&a, c, d);
        } else {
            z = (s32 *) &zero;
            z[0] = 0;
            z[1] = 0;
            z[2] = 0;
            func_020f4dfc(&a, &zero, d);
        }
    }
}

void func_ov001_02187af4(Unk02188950 *a) {
    s32 i;

    for (i = 0; i < 5; i++) {
        if (a->mUnk_0bc[i].mUnk_14 != NULL) {
            func_0208b6b0(&a->mUnk_0bc[i].mUnk_14);
        }
    }
    a->mUnk_0b8 = 0;
}

// Writes to param_3 a point for entry param_2 of param_1->mUnk_0bc: param_1->mUnk_004 plus the entry's mUnk_08
// combined with the pair of gPairsByAngle values selected by param_1->mUnk_184. The entry's mUnk_00 (1-5) selects
// the variant; other values write nothing.
void func_ov001_02187684(Unk02188950 *a, int b, Vec3 *c) {
    Camera *obj;
    s32 x;
    s32 y;
    s32 z;
    s32 t;

    switch (a->mUnk_0bc[b].mKind) {
        case 1:
            c->x = a->mUnk_000.mPos.x +
                   (s32) (((s64) a->mUnk_0bc[b].mOffset.z * gPairsByAngle[((u16) a->mAngle >> 4) * 2]) >> 12) +
                   (s32) (((s64) a->mUnk_0bc[b].mOffset.x * gPairsByAngle[((u16) a->mAngle >> 4) * 2 + 1]) >> 12);
            c->y = a->mUnk_000.mPos.y + a->mUnk_0bc[b].mOffset.y;
            c->z = a->mUnk_000.mPos.z +
                   (s32) (((s64) a->mUnk_0bc[b].mOffset.z * gPairsByAngle[((u16) a->mAngle >> 4) * 2 + 1]) >> 12) -
                   (s32) (((s64) a->mUnk_0bc[b].mOffset.x * gPairsByAngle[((u16) a->mAngle >> 4) * 2]) >> 12);
            break;
        case 3:
            // As case 1 with mUnk_024 of the object from GetCurrentCamera added, then halved.
            obj = GetCurrentCamera();
            c->x = a->mUnk_000.mPos.x + obj->mPos.x +
                   (s32) (((s64) a->mUnk_0bc[b].mOffset.z * gPairsByAngle[((u16) a->mAngle >> 4) * 2]) >> 12) +
                   (s32) (((s64) a->mUnk_0bc[b].mOffset.x * gPairsByAngle[((u16) a->mAngle >> 4) * 2 + 1]) >> 12);
            c->y = a->mUnk_000.mPos.y + obj->mPos.y + a->mUnk_0bc[b].mOffset.y;
            c->z = a->mUnk_000.mPos.z + obj->mPos.z +
                   (s32) (((s64) a->mUnk_0bc[b].mOffset.z * gPairsByAngle[((u16) a->mAngle >> 4) * 2 + 1]) >> 12) -
                   (s32) (((s64) a->mUnk_0bc[b].mOffset.x * gPairsByAngle[((u16) a->mAngle >> 4) * 2]) >> 12);
            c->x >>= 1;
            c->y >>= 1;
            c->z >>= 1;
            break;
        case 2:
            // The entry's mUnk_08 is first multiplied per component by param_1->mUnk_01c, mUnk_020 and mUnk_024.
            t = a->mUnk_0bc[b].mOffset.y;
            y = (s32) (((s64) t * a->mUnk_000.mScale.y) >> 12);
            t = a->mUnk_0bc[b].mOffset.x;
            x = (s32) (((s64) t * a->mUnk_000.mScale.x) >> 12);
            t = a->mUnk_0bc[b].mOffset.z;
            z = (s32) (((s64) t * a->mUnk_000.mScale.z) >> 12);
            c->x = a->mUnk_000.mPos.x + (s32) (((s64) z * gPairsByAngle[((u16) a->mAngle >> 4) * 2]) >> 12) +
                   (s32) (((s64) x * gPairsByAngle[((u16) a->mAngle >> 4) * 2 + 1]) >> 12);
            c->y = a->mUnk_000.mPos.y + y;
            c->z = a->mUnk_000.mPos.z + (s32) (((s64) z * gPairsByAngle[((u16) a->mAngle >> 4) * 2 + 1]) >> 12) -
                   (s32) (((s64) x * gPairsByAngle[((u16) a->mAngle >> 4) * 2]) >> 12);
            break;
        case 4:
            c->x = a->mUnk_000.mPos.x +
                   (s32) (((s64) a->mUnk_0bc[b].mOffset.z * gPairsByAngle[((u16) a->mAngle >> 4) * 2]) >> 12) +
                   (s32) (((s64) a->mUnk_0bc[b].mOffset.x * gPairsByAngle[((u16) a->mAngle >> 4) * 2 + 1]) >> 12);
            c->y = a->mUnk_000.mCourseMapRow->mUnk_00.y + a->mUnk_0bc[b].mOffset.y;
            c->z = a->mUnk_000.mPos.z +
                   (s32) (((s64) a->mUnk_0bc[b].mOffset.z * gPairsByAngle[((u16) a->mAngle >> 4) * 2 + 1]) >> 12) -
                   (s32) (((s64) a->mUnk_0bc[b].mOffset.x * gPairsByAngle[((u16) a->mAngle >> 4) * 2]) >> 12);
            break;
        case 5:
            c->x = a->mUnk_000.mPos.x +
                   (s32) (((s64) a->mUnk_0bc[b].mOffset.z * gPairsByAngle[((u16) a->mAngle >> 4) * 2]) >> 12) +
                   (s32) (((s64) a->mUnk_0bc[b].mOffset.x * gPairsByAngle[((u16) a->mAngle >> 4) * 2 + 1]) >> 12);
            c->y = a->mUnk_0bc[b].mOffset.y - GetHeightAboveWaterOrEfct(0);
            c->z = a->mUnk_000.mPos.z +
                   (s32) (((s64) a->mUnk_0bc[b].mOffset.z * gPairsByAngle[((u16) a->mAngle >> 4) * 2 + 1]) >> 12) -
                   (s32) (((s64) a->mUnk_0bc[b].mOffset.x * gPairsByAngle[((u16) a->mAngle >> 4) * 2]) >> 12);
            break;
    }
}

void func_ov001_02187614(Unk02188950 *a, s32 b, s32 c, s32 d, s32 e, u32 f, s32 g) {
    Vec3 pos;

    a->mUnk_0bc[b].mTimer = g;
    if ((a->mUnk_000.mFlags & 0x400) != 0) {
        c = -c;
    }
    a->mUnk_0bc[b].mOffset.x = c << 4;
    a->mUnk_0bc[b].mOffset.y = d << 4;
    a->mUnk_0bc[b].mOffset.z = e << 4;
    func_ov001_02187684(a, b, &pos);
    if (f != 0) {
        if (a->mUnk_0bc[b].mUnk_14 != NULL) {
            func_0208b6b0(&a->mUnk_0bc[b].mUnk_14);
        }
        a->mUnk_0bc[b].mUnk_14 = StartEffect(f, &pos);
    }
}

void func_ov001_021875c0(Unk02188950 *a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    int i;

    for (i = 0; i < 5; i++) {
        if (a->mUnk_0bc[i].mUnk_14 == NULL) {
            a->mUnk_0bc[i].mKind = 1;
            func_ov001_02187614(a, i, b, c, d, e, f);
            return;
        }
    }
}

void func_ov001_0218756c(Unk02188950 *a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    int i;

    for (i = 0; i < 5; i++) {
        if (a->mUnk_0bc[i].mUnk_14 == NULL) {
            a->mUnk_0bc[i].mKind = 2;
            func_ov001_02187614(a, i, b, c, d, e, f);
            return;
        }
    }
}

void func_ov001_02187518(Unk02188950 *a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    int i;

    for (i = 0; i < 5; i++) {
        if (a->mUnk_0bc[i].mUnk_14 == NULL) {
            a->mUnk_0bc[i].mKind = 4;
            func_ov001_02187614(a, i, b, c, d, e, f);
            return;
        }
    }
}

void func_ov001_021874c4(Unk02188950 *a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    int i;

    for (i = 0; i < 5; i++) {
        if (a->mUnk_0bc[i].mUnk_14 == NULL) {
            a->mUnk_0bc[i].mKind = 5;
            func_ov001_02187614(a, i, b, c, d, e, f);
            return;
        }
    }
}

void func_ov001_02187444(Unk02188950 *a, u32 b, int c) {
    int i;

    for (i = 0; i < 5; i++) {
        if (a->mUnk_0bc[i].mUnk_14 == NULL) {
            a->mUnk_0bc[i].mOffset.x = a->mUnk_000.mPos.x;
            a->mUnk_0bc[i].mOffset.y = -GetHeightAboveWaterOrEfct(0);
            a->mUnk_0bc[i].mOffset.z = a->mUnk_000.mPos.z;
            if (a->mUnk_0bc[i].mUnk_14 != NULL) {
                func_0208b6b0(&a->mUnk_0bc[i].mUnk_14);
            }
            func_0208e490(b, &a->mUnk_0bc[i].mOffset, 1);
            a->mUnk_0bc[i].mKind = 0;
            a->mUnk_0bc[i].mTimer = c;
            return;
        }
    }
}

void func_ov001_0218742c(Unk0206c1ac *a, const UnkVec16 *b) {
    a->mUnk_50 = *b;
}

void func_ov001_021872e0(Unk02188950 *a, int b, int c, int d, int e, int f, int g, int h, u32 l) {
    int i;
    Vec3 pos;
    UnkVec16 rot;

    for (i = 0; i < 5; i++) {
        if (a->mUnk_0bc[i].mUnk_14 == NULL) {
            a->mUnk_0bc[i].mKind = 1;
            a->mUnk_0bc[i].mTimer = l;
            a->mUnk_0bc[i].mOffset.x = b << 4;
            a->mUnk_0bc[i].mOffset.y = c << 4;
            a->mUnk_0bc[i].mOffset.z = d << 4;
            func_ov001_02187684(a, i, &pos);
            if (h != 0) {
                if (a->mUnk_0bc[i].mUnk_14 != NULL) {
                    func_0208b6b0(&a->mUnk_0bc[i].mUnk_14);
                }
                rot.x = ((s64) g * gPairsByAngle[((u16) a->mAngle >> 4) * 2] >> 12) +
                        ((s64) e * gPairsByAngle[((u16) a->mAngle >> 4) * 2 + 1] >> 12);
                rot.y = f;
                rot.z = ((s64) g * gPairsByAngle[((u16) a->mAngle >> 4) * 2 + 1] >> 12) -
                        ((s64) e * gPairsByAngle[((u16) a->mAngle >> 4) * 2] >> 12);
                func_0208b748(h, &pos, &rot, func_ov001_0218742c);
            }
        }
    }
}

void func_ov001_02187218(Unk02188950 *a, int b, s32 (*c)(Unk02188950 *)) {
    a->mUnk_158 = NULL;
    a->mUnk_15c = c;
    a->mUnk_150 = b;
    a->mUnk_0b0 = 0;
    a->mUnk_0b4 = a->mUnk_0b4 > 0 ? a->mUnk_0b4 - 1 : 0;
    a->mUnk_2bc = FALSE;
    a->mUnk_2c0 = TRUE;
    if (a->mUnk_2c4 == FALSE) {
        a->mUnk_1d8 = 0;
        a->mUnk_1d4 = NULL;
        a->mUnk_1dc = NULL;
        a->mUnk_1e0 = 0;
        a->mUnk_1e4 = NULL;
        a->mUnk_1e8 = 0;
        a->mUnk_1ec = NULL;
        a->mUnk_1f0 = 0;
        a->mUnk_1f4 = NULL;
        a->mUnk_20c = NULL;
        a->mUnk_224 = NULL;
        a->mUnk_228 = NULL;
        a->mUnk_22c = NULL;
        func_ov001_02187af4(a);
    }
}

void func_ov001_0218720c(Unk02188950 *a) {
    a->mUnk_2c0 = FALSE;
}

u32 func_ov001_021871f8(Unk02188950 *a, int b) {
    if (a->mUnk_150 < b) {
        return 1;
    }
    return 0;
}

BOOL func_ov001_021871d0(Unk02188950 *a) {
    if ((a->mUnk_2c8 & 0x800) != 0 && a->mVelocity.y <= 0) {
        return TRUE;
    }
    return FALSE;
}

void func_ov001_021870e4(void *a, Unk02188950 *b, const char *c, const char *d, const char *e) {
    if (a != NULL && c != NULL) {
        b->mNsbmd = LoadMapObjectModelAnimated((Unk0219b478 *) (a), (char *) (c));
        if (d != NULL) {
            LoadMapObjectModelNsbcaAnimation((Unk0219b250 *) (b->mNsbmd), (char *) (d));
        }
    }
    if (e != NULL) {
        b->mPrm = LoadMissionRunFile((char *) (e));
    }
    b->mAngle = (u16) (((s64) b->mUnk_000.mCourseMapRow->mUnk_0c.y * 0xb60b60b60bLL + 0x80000000000LL) >> 44);
    b->mUnk_168 = 0x1f000;
    if (b->mPrm != NULL) {
        func_020d2950(&b->mUnk_000, b->mPrm->mUnk_00c << 2);
        b->mUnk_000.mScale.x = b->mPrm->mUnk_004;
        b->mUnk_000.mScale.y = b->mPrm->mUnk_004;
        b->mUnk_000.mScale.z = b->mPrm->mUnk_004;
    }
    b->mUnk_238 = b->mUnk_000.mPos;
    b->mUnk_2bc = FALSE;
    b->mUnk_2c0 = TRUE;
    b->mUnk_148 = b->mUnk_000.mCourseMapRow->mUnk_26;
}

void func_ov001_021870b0(void *a, Unk02188950 *b, const char *c) {
    if (a != NULL && c != NULL) {
        b->mShadowNsbmd = LoadMapObjectModelShadow((Unk0219b478 *) (a), (char *) (c));
        SetMapObjectModelPolygonId(b->mShadowNsbmd, 0x3f);
        data_ov001_021a9ba0 = 0;
    }
}

void func_ov001_02187098(void) {
    if (data_ov001_021a9ba0 == 0) {
        data_ov001_021a9ba0++;
    } else {
        data_ov001_021a9ba0 = 0;
    }
}

int func_ov001_02187074(int a, int b, int c) {
    int v1;
    if (c < a) {
        v1 = c + b;
        if (c + b >= a) {
            v1 = a;
        }
        return v1;
    }
    if (c > a) {
        v1 = c - b;
        if (c - b <= a) {
            v1 = a;
        }
        return v1;
    }
    return c;
}

u16 func_ov001_02187024(Vec3 *a, Vec3 *b, s32 c, s32 d) {
    s32 diff = (u16) (FX_Atan2Idx(a->x - b->x, a->z - b->z) - d);
    s32 res;

    if (c < 0) {
        c = -c;
    }
    if (diff > 0x8000) {
        diff -= 0x10000;
    }
    res = -c;
    if (diff >= res) {
        if (diff <= c) {
            c = diff;
        }
        res = c;
    }
    return d + res;
}

u16 func_ov001_02186fb4(Vec3 *a, Vec3 *b, s32 c, s32 d, s32 e) {
    s32 diff = (u16) (FX_Atan2Idx(a->x - b->x, a->z - b->z) - e);
    s32 limit;
    s32 res;
    s32 target;

    if (c < 0) {
        limit = -c;
    } else {
        limit = c;
    }
    if (diff > 0x8000) {
        diff -= 0x10000;
    }
    if (c < 0) {
        diff += d;
        target = diff - 0x4000;
    } else {
        diff -= d;
        target = diff + 0x4000;
    }
    res = -limit;
    if (target >= res) {
        if (target <= limit) {
            limit = target;
        }
        res = limit;
    }
    return e + res;
}

void func_ov001_021864ac(u32 a, Unk02188950 *b) {
    Vec3 pos;
    Vec3 v44;
    Vec3 v50;
    Vec3 v5c;
    Vec3 dir;
    Vec3 vel;
    s32 s;
    s32 dx;
    s32 dy;
    s32 dz;
    s32 cur;
    s32 prev;
    s32 i;
    s32 idx;
    s64 speed;

    if (b->mUnk_158 == NULL && b->mUnk_15c != NULL) {
        b->mUnk_158 = b->mUnk_15c;
        b->mUnk_15c = NULL;
    }
    if (b->mUnk_158 != NULL && b->mUnk_158(b)) {
        b->mUnk_158 = NULL;
        b->mUnk_154 = 0;
        b->mUnk_0b0 = 0;
        b->mUnk_150 = 0;
    }

    switch (b->mAngleState) {
        case 1:
            b->mAngle = b->mMoveAngle;
            break;
        case 2:
            if (b->mUnk_19c > 0) {
                b->mUnk_194 = func_ov001_02187074(b->mUnk_198, b->mUnk_19c, b->mUnk_194);
            }
            if (b->mUnk_194 > 0) {
                b->mAngle = func_ov001_02187024(&b->mAnglePoint, &b->mUnk_000.mPos, b->mUnk_194, b->mAngle);
            }
            break;
        case 3:
            if (b->mUnk_19c > 0) {
                b->mUnk_194 = func_ov001_02187074(b->mUnk_198, b->mUnk_19c, b->mUnk_194);
            }
            if (b->mUnk_194 > 0) {
                b->mAngle = func_ov001_02187024(&b->mUnk_000.mPos, &b->mAnglePoint, b->mUnk_194, b->mAngle);
            }
            break;
        case 4:
            if (b->mUnk_19c > 0) {
                b->mUnk_194 = func_ov001_02187074(b->mUnk_198, b->mUnk_19c, b->mUnk_194);
            }
            if (b->mUnk_194 > 0) {
                b->mAngle =
                    func_ov001_02186fb4(&b->mAnglePoint, &b->mUnk_000.mPos, b->mUnk_194, b->mUnk_1a0, b->mAngle);
            }
            break;
        case 5:
            if (b->mUnk_19c > 0) {
                b->mUnk_194 = func_ov001_02187074(b->mUnk_198, b->mUnk_19c, b->mUnk_194);
            }
            if (b->mUnk_194 > 0) {
                b->mAngle += b->mUnk_194;
            }
            break;
        case 6:
        case 7:
        case 8:
            if (b->mUnk_19c > 0) {
                b->mUnk_194 = func_ov001_02187074(b->mUnk_198, b->mUnk_19c, b->mUnk_194);
            }
            if (b->mAngleState == 6) {
                if (func_ov001_02187024(&b->mAnglePoint, &b->mUnk_000.mPos, b->mUnk_194, b->mAngle) - b->mAngle >= 0) {
                    b->mAngleState = 8;
                } else {
                    b->mAngleState = 7;
                }
            }
            if (b->mAngleState == 8) {
                b->mAngle += b->mUnk_194;
            } else if (b->mAngleState == 7) {
                b->mAngle -= b->mUnk_194;
            }
            break;
    }

    switch (b->mMoveAngleMode) {
        case 1:
            b->mMoveAngle = b->mAngle;
            break;
        case 2:
            if (b->mUnk_1c0 > 0) {
                b->mUnk_1b8 = func_ov001_02187074(b->mUnk_1bc, b->mUnk_1c0, b->mUnk_1b8);
            }
            if (b->mUnk_1b8 > 0) {
                b->mMoveAngle = func_ov001_02187024(&b->mMoveAnglePoint, &b->mUnk_000.mPos, b->mUnk_1b8, b->mMoveAngle);
            }
            break;
        case 3:
            if (b->mUnk_1c0 > 0) {
                b->mUnk_1b8 = func_ov001_02187074(b->mUnk_1bc, b->mUnk_1c0, b->mUnk_1b8);
            }
            if (b->mUnk_1b8 > 0) {
                b->mMoveAngle = func_ov001_02187024(&b->mUnk_000.mPos, &b->mMoveAnglePoint, b->mUnk_1b8, b->mMoveAngle);
            }
            break;
        case 4:
            if (b->mUnk_1c0 > 0) {
                b->mUnk_1b8 = func_ov001_02187074(b->mUnk_1bc, b->mUnk_1c0, b->mUnk_1b8);
            }
            if (b->mUnk_1b8 > 0) {
                b->mMoveAngle = func_ov001_02186fb4(&b->mMoveAnglePoint, &b->mUnk_000.mPos, b->mUnk_1b8, b->mUnk_1c4,
                                                    b->mMoveAngle);
            }
            break;
    }

    if (b->mUnk_17c > 0) {
        b->mSpeed = func_ov001_02187074(b->mUnk_178, b->mUnk_17c, b->mSpeed);
    }
    if (b->mUnk_274 > 0) {
        b->mUnk_244 = func_ov001_02187074(b->mUnk_250, b->mUnk_274, b->mUnk_244);
        b->mUnk_248 = func_ov001_02187074(b->mUnk_254, b->mUnk_274, b->mUnk_248);
        b->mUnk_24c = func_ov001_02187074(b->mUnk_258, b->mUnk_274, b->mUnk_24c);
    }
    if (b->mUnk_278 > 0) {
        b->mUnk_25c = func_ov001_02187074(b->mUnk_268, b->mUnk_278, b->mUnk_25c);
        b->mUnk_260 = func_ov001_02187074(b->mUnk_26c, b->mUnk_278, b->mUnk_260);
        b->mUnk_264 = func_ov001_02187074(b->mUnk_270, b->mUnk_278, b->mUnk_264);
    }
    if (b->mUnk_2b0 > 0) {
        b->mUnk_280 = func_ov001_02187074(b->mUnk_28c, b->mUnk_2b0, b->mUnk_280);
        b->mUnk_284 = func_ov001_02187074(b->mUnk_290, b->mUnk_2b0, b->mUnk_284);
        b->mUnk_288 = func_ov001_02187074(b->mUnk_294, b->mUnk_2b0, b->mUnk_288);
    }
    if (b->mUnk_2b4 > 0) {
        b->mUnk_298 = func_ov001_02187074(b->mUnk_2a4, b->mUnk_2b4, b->mUnk_298);
        b->mUnk_29c = func_ov001_02187074(b->mUnk_2a8, b->mUnk_2b4, b->mUnk_29c);
        b->mUnk_2a0 = func_ov001_02187074(b->mUnk_2ac, b->mUnk_2b4, b->mUnk_2a0);
    }

    if (b->mUnk_2c0 != FALSE) {
        b->mVelocity.y -= b->mPrm->mUnk_01c;
    }
    if (-b->mPrm->mUnk_018 < *(s32 *) &b->mVelocity && *(s32 *) &b->mVelocity < b->mPrm->mUnk_018 &&
        -b->mPrm->mUnk_018 < b->mVelocity.z && b->mVelocity.z < b->mPrm->mUnk_018) {
        b->mVelocity.x = 0;
        b->mVelocity.z = 0;
    } else if (b->mUnk_2c8 & 0x1e34ef) {
        s = b->mPrm->mUnk_010;
        b->mVelocity.x = (s32) (((s64) b->mVelocity.x * s) >> 12);
        b->mVelocity.y = (s32) (((s64) b->mVelocity.y * s) >> 12);
        b->mVelocity.z = (s32) (((s64) b->mVelocity.z * s) >> 12);
    } else {
        s = b->mPrm->mUnk_014;
        b->mVelocity.x = (s32) (((s64) b->mVelocity.x * s) >> 12);
        b->mVelocity.y = (s32) (((s64) b->mVelocity.y * s) >> 12);
        b->mVelocity.z = (s32) (((s64) b->mVelocity.z * s) >> 12);
    }

    idx = ((u16) b->mMoveAngle >> 4) * 2;
    speed = b->mSpeed;
    dy = b->mVelocity.y;
    dz = b->mVelocity.z + (s32) ((speed * gPairsByAngle[idx + 1]) >> 12);
    dx = b->mVelocity.x + (s32) ((speed * gPairsByAngle[idx]) >> 12);
    b->mUnk_000.mPos.x += dx;
    b->mUnk_000.mPos.y += dy;
    b->mUnk_000.mPos.z += dz;

    pos.x = b->mUnk_000.mPos.x;
    pos.y = b->mUnk_000.mPos.y + 0x14000;
    pos.z = b->mUnk_000.mPos.z;
    b->mUnk_2c8 = 0;
    if (func_01ffdee4(&pos, NULL, 0, 0x14000, b->mUnk_2b8 == 1 ? (u16) 4 : (u16) 1, -2, &v44, &v50, &v5c, &b->mUnk_2c8,
                      NULL, NULL, NULL, NULL)) {
        if (b->mUnk_2b8 == 2 || b->mUnk_2b8 == 3) {
            b->mUnk_000.mPos.y += v44.y;
        } else {
            b->mUnk_000.mPos.x += v44.x;
            b->mUnk_000.mPos.y += v44.y;
            b->mUnk_000.mPos.z += v44.z;
        }
    }
    if (b->mUnk_2b8 != 2 && (b->mUnk_2c8 & 0x214300)) {
        if ((s64) v5c.x * v5c.x + (s64) v5c.y * v5c.y + (s64) v5c.z * v5c.z >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&v5c, &dir);
        }
        dir.y = 0;
        VEC_MultAdd(b->mPrm->mUnk_030, &dir, &b->mVelocity, &b->mVelocity);
    }

    if (b->mUnk_2c8 & 0x1e34ef) {
        if (b->mVelocity.y > 0) {
            b->mUnk_2c8 &= ~0x1e34ef;
        } else if (b->mUnk_2bc != FALSE) {
            b->mVelocity.y = (s32) (((s64) b->mVelocity.y * -b->mPrm->mUnk_020) >> 12);
            if (b->mVelocity.y < b->mPrm->mUnk_018) {
                b->mUnk_2bc = FALSE;
                b->mVelocity.y = 0;
            }
        } else {
            b->mVelocity.y = 0;
        }
    }
    if (b->mUnk_000.mPos.y < 0) {
        b->mUnk_000.mPos.y = 0;
        b->mUnk_2c8 |= data_ov001_021a6584;
    }
    if (b->mUnk_170 > 0) {
        b->mUnk_168 = func_ov001_02187074(b->mUnk_16c, b->mUnk_170, b->mUnk_168);
        if (b->mUnk_168 == b->mUnk_16c) {
            b->mUnk_170 = 0;
        }
    }
    if (b->mUnk_164 > 0) {
        b->mUnk_000.mScale.x = b->mUnk_000.mScale.y = b->mUnk_000.mScale.z =
            func_ov001_02187074(b->mUnk_160, b->mUnk_164, b->mUnk_000.mScale.x);
    }
    if (b->mUnk_234 == 1) {
        Matrix3x3FromPairY(&b->mUnk_000.mMatrix.mUnk_00[0].x, gPairsByAngle[((u16) b->mAngle >> 4) * 2],
                           gPairsByAngle[((u16) b->mAngle >> 4) * 2 + 1]);
        Vec3MultiplyMatrix3x3((Vec3 *) &b->mUnk_244, &b->mUnk_000.mMatrix.mUnk_00[0].x, &b->mUnk_238);
        VEC_Add(&b->mUnk_238, &b->mUnk_000.mPos, &b->mUnk_238);
    } else {
        b->mUnk_238.x = b->mUnk_000.mPos.x + b->mUnk_244;
        b->mUnk_238.y = b->mUnk_000.mPos.y + b->mUnk_248;
        b->mUnk_238.z = b->mUnk_000.mPos.z + b->mUnk_24c;
    }
    b->mUnk_000.mAngle = b->mAngle;

    if (b->mNsbmd != NULL) {
        prev = GetMapObjectModelNsbcaFrameIndex(b->mNsbmd);
        func_ov001_0219b250(b->mNsbmd);
        cur = GetMapObjectModelNsbcaFrameIndex(b->mNsbmd);
        if (b->mUnk_1d8 != 0) {
            if (prev < b->mUnk_1d8 && b->mUnk_1d8 <= cur) {
                func_ov001_02188e94(b, &b->mUnk_1dc);
            } else if ((u32) cur < (u32) prev && (b->mUnk_1d8 <= cur || prev < b->mUnk_1d8)) {
                func_ov001_02188e94(b, &b->mUnk_1dc);
            }
        }
        if (b->mUnk_1e0 != 0) {
            if (prev < b->mUnk_1e0 && b->mUnk_1e0 <= cur) {
                b->mUnk_1e4(b);
            } else if ((u32) cur < (u32) prev && (b->mUnk_1e0 <= cur || prev < b->mUnk_1e0)) {
                b->mUnk_1e4(b);
            }
        }
        if (b->mUnk_1e8 != 0) {
            if (prev < b->mUnk_1e8 && b->mUnk_1e8 <= cur) {
                b->mUnk_1ec(b);
            } else if ((u32) cur < (u32) prev && (b->mUnk_1e8 <= cur || prev < b->mUnk_1e8)) {
                b->mUnk_1ec(b);
            }
        }
        if (!func_ov001_0219b240(b->mNsbmd)) {
            func_ov001_02188e94(b, &b->mUnk_1d4);
        }
    }

    b->mUnk_0b0++;
    if (b->mUnk_1f0 != 0 && b->mUnk_0b0 == b->mUnk_1f0) {
        b->mUnk_1f0 = 0;
        b->mUnk_0b0 = 0;
        func_ov001_02188e94(b, &b->mUnk_1f4);
    }
    if (b->mUnk_20c != NULL && func_ov001_021881a8(b, &b->mUnk_200, (s32) (b->mUnk_1f8), (s32) (b->mUnk_1fc))) {
        func_ov001_02188e94(b, &b->mUnk_20c);
    }
    if (b->mUnk_224 != NULL && !func_ov001_021881a8(b, &b->mUnk_218, (s32) (b->mUnk_210), (s32) (b->mUnk_214))) {
        func_ov001_02188e94(b, &b->mUnk_224);
    }
    if (b->mUnk_228 != NULL && b->mVelocity.y == 0 && -b->mPrm->mUnk_018 < b->mSpeed && b->mPrm->mUnk_018 > b->mSpeed &&
        -b->mPrm->mUnk_018 < b->mVelocity.x && b->mPrm->mUnk_018 > b->mVelocity.x &&
        -b->mPrm->mUnk_018 < b->mVelocity.z && b->mPrm->mUnk_018 > b->mVelocity.z && (b->mUnk_2c8 & 0x1e34ef)) {
        func_ov001_02188e94(b, &b->mUnk_228);
    }
    if (b->mUnk_22c != NULL && b->mVelocity.y <= 0 && (b->mUnk_2c8 & 0x1e34ef)) {
        func_ov001_02188e94(b, &b->mUnk_22c);
    }

    for (i = 0; i < 5; i++) {
        func_ov001_02187684(b, i, &vel);
        if (b->mUnk_0bc[i].mUnk_14 != NULL) {
            if (b->mUnk_0bc[i].mTimer > 0 && --b->mUnk_0bc[i].mTimer == 0) {
                func_0208b6b0(&b->mUnk_0bc[i].mUnk_14);
            } else {
                func_0208b5b0(b->mUnk_0bc[i].mUnk_14, &vel);
            }
        }
    }
    if (b->mTimer > 0) {
        b->mTimer--;
    }
}

void func_ov001_02186368(void *a, Unk02188950 *b) {
    s32 i;
    s32 depth;
    Unk0219b250_10_04 *obj;
    s32 level;
    s32 value;
    Vec3 v;
    s32 m[9];
    s32 k;

    depth = b->mUnk_168 >> 12;
    v.x = b->mUnk_000.mPos.x >> 4;
    v.y = b->mUnk_000.mPos.y >> 4;
    v.z = b->mUnk_000.mPos.z >> 4;
    level = func_020e69bc(&v);
    if (level >= depth) {
        level = depth;
    }
    if (level > 0) {
        if (level >= 0x1f) {
            level = 0x1f;
        }
        if (level >= 0x1f) {
            func_02012ffc((Unk0201290c *) b->mNsbmd->mAnimatedModel->mUnk_04, 1);
            SetMapObjectModelPolygonId(b->mNsbmd, 3);
        } else if (b->mUnk_27c <= 1) {
            func_02012ffc((Unk0201290c *) b->mNsbmd->mAnimatedModel->mUnk_04, 1);
            SetMapObjectModelPolygonId(b->mNsbmd, 3);
        } else {
            obj = b->mNsbmd->mAnimatedModel->mUnk_04;
            func_02012ffc((Unk0201290c *) obj, 1);
            for (i = 0; i < obj->mUnk_18; i++) {
                func_0209b904(b->mNsbmd, func_020d3c44(), i);
            }
        }
        value = 0x1e;
        func_01ff9048(0x14, &value, 1);
        func_01ff9048(0x19, func_020e6b58(&b->mUnk_000.mPos), 0xc);
        if (b->mUnk_000.mAngle != 0) {
            k = b->mUnk_000.mAngle >> 4;
            Matrix3x3FromPairY(m, gPairsByAngle[k * 2], gPairsByAngle[k * 2 + 1]);
            func_01ff9048(0x1a, m, 9);
        }
        func_01ff9048(0x1b, &b->mUnk_000.mScale.x, 3);
        func_0209b9a4(b->mNsbmd, level);
        func_0209b7a0(b->mNsbmd, b->mUnk_000.mFlags & 0x400, 0);
        DrawMapObjectModel(a, b->mNsbmd, b);
    }
}

void func_ov001_021861f4(void *d, Unk02188950 *e, s32 f) {
    s32 depth;
    s32 value;
    Vec3 v;

    depth = e->mUnk_168 >> 12;
    if (e->mUnk_27c == 2) {
        v.x = e->mUnk_000.mPos.x;
        v.y = e->mUnk_000.mPos.y;
        v.z = e->mUnk_000.mPos.z;
    } else if (e->mUnk_27c == 3) {
        v.x = e->mUnk_2e8.x;
        v.y = e->mUnk_000.mCourseMapRow->mUnk_00.y;
        v.z = e->mUnk_2e8.z;
    } else {
        if (depth >= 4) {
            s32 t = depth - ((e->mUnk_000.mPos.y - e->mUnk_000.mCourseMapRow->mUnk_00.y) >> 15);

            if (t <= 4) {
                t = 4;
            }
            depth = (u16) t;
        }
        v.x = e->mUnk_000.mPos.x;
        v.y = e->mUnk_000.mCourseMapRow->mUnk_00.y;
        v.z = e->mUnk_000.mPos.z;
    }
    if (depth > 0x10) {
        depth = 0x10;
    }
    if (f != 0) {
        depth = 0x14 - depth;
    }
    if (depth > 0) {
        s32 m[9];
        Vec3 w;
        Vec3 u;
        s32 k;
        s32 a;
        s32 b;
        s32 c;

        value = 0x1e;
        func_01ff9048(0x14, &value, 1);
        func_01ff9048(0x19, func_020e6b58(&v), 0xc);
        k = (u16) e->mAngle >> 4;
        Matrix3x3FromPairY(m, gPairsByAngle[k * 2], gPairsByAngle[k * 2 + 1]);
        func_01ff9048(0x1a, m, 9);
        c = e->mUnk_288 >> 4;
        b = e->mUnk_284 >> 4;
        a = e->mUnk_280 >> 4;
        w.x = a;
        w.y = b;
        w.z = c;
        func_01ff9048(0x1c, &w, 3);
        func_01ff9048(0x1b, &e->mUnk_298, 3);
        if (data_ov001_021a9ba0 == 0) {
            u.x = 0x1333;
            u.y = 0x1000;
            u.z = 0x1333;
            func_01ff9048(0x1b, &u, 3);
        }
        SetMapObjectModelPolygonId(e->mShadowNsbmd, 3);
        func_0209b9a4(e->mShadowNsbmd, depth);
        DrawMapObjectModel(d, e->mShadowNsbmd, e);
    }
}

s32 func_ov001_021860cc(Unk02188950 *a, Vec3 *b, s32 c, Vec3 *d) {
    s32 d1;
    s32 d2;
    s32 d3;

    switch (a->mUnk_234) {
        case 0:
            c += a->mUnk_25c;
            d1 = b->x - a->mUnk_238.x;
            d2 = b->y - a->mUnk_238.y;
            d3 = b->z - a->mUnk_238.z;
            if ((s64) d3 * d3 + ((s64) d1 * d1 + (s64) d2 * d2) < (s64) c * c) {
                func_020eb3f0(b, &a->mUnk_238, c, d);
                return 1;
            }
            return 0;
        case 2:
            return func_020ead80(b, &a->mUnk_238, &a->mUnk_000.mMatrix.mUnk_00[0], a->mUnk_25c, a->mUnk_260,
                                 a->mUnk_260, c, d);
        case 1:
            return func_020eafc4(b, &a->mUnk_238, &a->mUnk_000.mMatrix.mUnk_00[0], (Vec3 *) &a->mUnk_25c,
                                 (Vec3 *) &a->mUnk_25c, c, d);
        default:
            return 0;
    }
}

s32 func_ov001_02185fb0(Unk02188950 *a, Unk02185fb0_1 *b, u8 *c, u8 *d) {
    Vec3 v;
    s64 k;
    u32 mode;
    UnkFunc *fn;

    mode = *c;
    a->mUnk_2d8 = *d;
    a->mUnk_000.mUnk_10.x = 0;
    a->mUnk_000.mUnk_10.y = 0;
    a->mUnk_000.mUnk_10.z = 0;
    if (mode == 1) {
        v.x = a->mUnk_000.mPos.x - b->mUnk_80;
        v.y = 0;
        v.z = a->mUnk_000.mPos.z - b->mUnk_88;
        if ((s64) v.z * v.z + ((s64) v.x * v.x + (s64) v.y * v.y) >= 16) {
            Vec3NormalizeAndGetLengthUnchecked(&v, &v);
            k = -a->mPrm->mUnk_024;
            a->mUnk_000.mUnk_10.x = (s32) (((s64) v.x * k) >> 12);
            a->mUnk_000.mUnk_10.y = (s32) (((s64) v.y * k) >> 12);
            a->mUnk_000.mUnk_10.z = (s32) (((s64) v.z * k) >> 12);
            VEC_MultAdd(a->mPrm->mUnk_028, &v, &a->mVelocity, &a->mVelocity);
        }
        fn = a->mUnk_2d4;
        a->mUnk_2d4 = NULL;
        if (fn) {
            fn(a, b);
        }
    }
    if (a->mTimer == 0) {
        a->mTimer = 0x1f;
    }
    return a->mUnk_2d8;
}

s32 func_ov001_02185f04(Unk02188950 *a, Unk02185f04_1 *b, u8 *c, u8 *d) {
    Vec3 v;
    UnkFunc *fn;

    a->mUnk_2e0 = *d;
    v.x = a->mUnk_000.mPos.x - b->mUnk_50;
    v.y = 0;
    v.z = a->mUnk_000.mPos.z - b->mUnk_58;
    if ((s64) v.z * v.z + ((s64) v.x * v.x + (s64) v.y * v.y) >= 16) {
        Vec3NormalizeAndGetLengthUnchecked(&v, &v);
        VEC_MultAdd(a->mPrm->mUnk_02c, &v, &a->mVelocity, &a->mVelocity);
    }
    fn = a->mUnk_2dc;
    a->mUnk_2dc = NULL;
    if (fn) {
        fn(a, b);
    }
    return a->mUnk_2e0;
}

void *func_ov001_02185ef4(void) {
    return (void *) func_0209bf48(NULL, NULL, NULL);
}
