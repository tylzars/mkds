#include "Main/Unknown/code_020d6538.h"
#include "Main/Unknown/code_020ea670.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0216b000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "01/code_0218155c.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020d6dc0.h"
#include "Main/Unknown/code_020d7db4.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_020d849c.h"
#include "code_02146d78.h"
#include "code_02148538.h"
#include "registers.h"

#pragma thumb on

void func_020d7d4c(Unk020d84e4 *a, struct CourseMapRow *b, s32 c, s32 d) {
    func_020d7da8(&a->mUnk_00, b, c);
    a->mUnk_24 = c / 100;
    a->mUnk_28 = (c * d) / 100;
    func_020d859c(a, 0, 1);
}

void func_020d7d18(Unk020d849c *p, s32 a, Vec3 **b, s32 c) {
    func_020d80e4(&p->mUnk_00, a, 0, b[0], b[1], b[2], b[3]);
    func_020d84c0(p, c);
    p->mUnk_5c = 0;
}

BOOL func_020d7c84(Unk020d849c *p, s32 a, Vec3 **b) {
    s32 v;
    p->mUnk_5c = p->mUnk_5c - 0x1000000;
    p->mUnk_5c = ((s64) p->mUnk_5c * (s64) p->mUnk_00.mUnk_30) >> 12;
    func_020d80e4(&p->mUnk_00, a, 0, b[0], b[1], b[2], b[3]);
    v = p->mUnk_00.mUnk_34;
    if (v != 0) {
        p->mUnk_5c = ((s64) p->mUnk_5c * (s64) v) >> 24;
    }
    if (v != 0) {
        v = ((s64) p->mUnk_54 * (s64) v) >> 12;
    } else {
        v = 0x1000000;
    }
    p->mUnk_58 = v;
    if (p->mUnk_5c >= 0x1000000) {
        return TRUE;
    }
    return FALSE;
}

#pragma thumb off

void func_020d7bec(MtxFx43 *a) {
    s32 t;
    s32 i;
    t = FX_Atan2(a->mUnk_00[0].z, a->mUnk_00[2].z);
    t = (((s64) t * 0x28BE60DB9391LL) + 0x80000000000LL) >> 44;
    i = (u16) ((u16) t >> 1) >> 4;
    data_0217b660.mUnk_00[0] = 0;
    data_0217b660.mUnk_00[1] = gPairsByAngle[i * 2];
    data_0217b660.mUnk_00[2] = 0;
    data_0217b660.mUnk_00[3] = gPairsByAngle[i * 2 + 1];
}

void func_020d7b88(Vec3 *a, void *q) {
    Unk020d7b88 *b = q;
    s32 r = FX_Sqrt((a->y + 0x1000) << 1);
    FX_DivAsync(a->z, r);
    b->mUnk_00[1] = 0;
    b->mUnk_00[0] = FX_GetDivResult();
    FX_DivAsync(-a->x, r);
    b->mUnk_00[3] = r >> 1;
    b->mUnk_00[2] = FX_GetDivResult();
}

void func_020d7b34(s32 a, Unk020d7b88 *b) {
    s32 i = (u16) (a >> 1) >> 4;
    b->mUnk_00[0] = 0;
    b->mUnk_00[1] = gPairsByAngle[i * 2];
    b->mUnk_00[2] = 0;
    b->mUnk_00[3] = gPairsByAngle[i * 2 + 1];
}

void func_020d7a3c(void *p, s32 b, void *q) {
    Vec3 *a = p;
    Unk020d7b88 *c = q;
    s32 r;
    s32 d;
    s32 i;
    s32 s;
    s32 k;
    s64 w = (s64) ((a->y + 0x1000) << 1) << 32;
    reg_CP_SQRTCNT = 1;
    reg_CP_SQRT_PARAM = w;
    r = FX_GetSqrtResult();
    FX_DivAsync(a->z, r);
    i = (u16) (b >> 1) >> 4;
    s = gPairsByAngle[i * 2];
    k = gPairsByAngle[i * 2 + 1];
    c->mUnk_00[1] = ((r >> 1) * s) >> 12;
    c->mUnk_00[3] = ((r >> 1) * k) >> 12;
    d = FX_GetDivResult();
    FX_DivAsync(-a->x, r);
    c->mUnk_00[0] = (d * k) >> 12;
    c->mUnk_00[2] = (d * s) >> 12;
    d = FX_GetDivResult();
    c->mUnk_00[0] = c->mUnk_00[0] - ((d * s) >> 12);
    c->mUnk_00[2] = c->mUnk_00[2] + ((d * k) >> 12);
}

void func_020d79b0(void *p, u32 b, void *q) {
    Unk020d7b88 *a = p;
    Unk020d7b88 *c = q;
    s32 i = (u16) (b >> 1) >> 4;
    s32 s = gPairsByAngle[i * 2];
    s32 k = gPairsByAngle[i * 2 + 1];
    c->mUnk_00[0] = (a->mUnk_00[0] * k - a->mUnk_00[2] * s) >> 12;
    c->mUnk_00[1] = (a->mUnk_00[3] * s) >> 12;
    c->mUnk_00[2] = (a->mUnk_00[2] * k + a->mUnk_00[0] * s) >> 12;
    c->mUnk_00[3] = (a->mUnk_00[3] * k) >> 12;
}

void func_020d7938(Unk020d7b88 *a, Unk020d7b88 *b, Unk020d7b88 *c) {
    c->mUnk_00[0] = (a->mUnk_00[0] * b->mUnk_00[3] - a->mUnk_00[2] * b->mUnk_00[1]) >> 12;
    c->mUnk_00[1] = (a->mUnk_00[3] * b->mUnk_00[1]) >> 12;
    c->mUnk_00[2] = (a->mUnk_00[2] * b->mUnk_00[3] + a->mUnk_00[0] * b->mUnk_00[1]) >> 12;
    c->mUnk_00[3] = (a->mUnk_00[3] * b->mUnk_00[3]) >> 12;
}

void func_020d788c(Unk020d7b88 *a, s32 b, Unk020d7b88 *c) {
    Unk020d7b88 q = *a;
    s32 i = (u16) (b >> 1) >> 4;
    s32 s = gPairsByAngle[i * 2];
    s32 k = gPairsByAngle[i * 2 + 1];
    c->mUnk_00[0] = (q.mUnk_00[3] * s + q.mUnk_00[0] * k) >> 12;
    c->mUnk_00[1] = (q.mUnk_00[1] * k + q.mUnk_00[2] * s) >> 12;
    c->mUnk_00[2] = (q.mUnk_00[2] * k - q.mUnk_00[1] * s) >> 12;
    c->mUnk_00[3] = (q.mUnk_00[3] * k - q.mUnk_00[0] * s) >> 12;
}

void func_020d77e0(void *m, s32 b, void *o) {
    Unk020d7b88 *a = m;
    Unk020d7b88 *c = o;
    Unk020d7b88 q = *a;
    s32 i = (u16) (b >> 1) >> 4;
    s32 s = gPairsByAngle[i * 2];
    s32 k = gPairsByAngle[i * 2 + 1];
    c->mUnk_00[0] = (q.mUnk_00[0] * k - q.mUnk_00[2] * s) >> 12;
    c->mUnk_00[1] = (q.mUnk_00[3] * s + q.mUnk_00[1] * k) >> 12;
    c->mUnk_00[2] = (q.mUnk_00[2] * k + q.mUnk_00[0] * s) >> 12;
    c->mUnk_00[3] = (q.mUnk_00[3] * k - q.mUnk_00[1] * s) >> 12;
}

void func_020d7734(void *m, s32 b, void *o) {
    Unk020d7b88 *a = m;
    Unk020d7b88 *c = o;
    Unk020d7b88 q = *a;
    s32 i = (u16) (b >> 1) >> 4;
    s32 s = gPairsByAngle[i * 2];
    s32 k = gPairsByAngle[i * 2 + 1];
    c->mUnk_00[0] = (q.mUnk_00[0] * k + q.mUnk_00[1] * s) >> 12;
    c->mUnk_00[1] = (q.mUnk_00[1] * k - q.mUnk_00[0] * s) >> 12;
    c->mUnk_00[2] = (q.mUnk_00[3] * s + q.mUnk_00[2] * k) >> 12;
    c->mUnk_00[3] = (q.mUnk_00[3] * k - q.mUnk_00[2] * s) >> 12;
}

void func_020d76a8(Unk020d7b88 *a, s32 b, Unk020d7b88 *c) {
    Unk020d7b88 q = *a;
    s32 i = (u16) (b >> 1) >> 4;
    s32 s = gPairsByAngle[i * 2];
    s32 k = gPairsByAngle[i * 2 + 1];
    c->mUnk_00[0] = (q.mUnk_00[3] * s) >> 12;
    c->mUnk_00[1] = (q.mUnk_00[1] * k) >> 12;
    c->mUnk_00[2] = (-q.mUnk_00[1] * s) >> 12;
    c->mUnk_00[3] = (q.mUnk_00[3] * k) >> 12;
}

void func_020d759c(void *p, void *q, void *r, s32 d) {
    Unk020d7b88 *a = p;
    Unk020d7b88 *b = q;
    Unk020d7b88 *c = r;
    s32 v = a->mUnk_00[0] * b->mUnk_00[0] + a->mUnk_00[1] * b->mUnk_00[1] + a->mUnk_00[2] * b->mUnk_00[2] +
            a->mUnk_00[3] * b->mUnk_00[3];
    if (v < 0) {
        c->mUnk_00[0] = a->mUnk_00[0] + ((d * -(b->mUnk_00[0] + a->mUnk_00[0])) >> 12);
        c->mUnk_00[1] = a->mUnk_00[1] + ((d * -(b->mUnk_00[1] + a->mUnk_00[1])) >> 12);
        c->mUnk_00[2] = a->mUnk_00[2] + ((d * -(b->mUnk_00[2] + a->mUnk_00[2])) >> 12);
        c->mUnk_00[3] = a->mUnk_00[3] + ((d * -(b->mUnk_00[3] + a->mUnk_00[3])) >> 12);
    } else {
        c->mUnk_00[0] = a->mUnk_00[0] + ((d * (b->mUnk_00[0] - a->mUnk_00[0])) >> 12);
        c->mUnk_00[1] = a->mUnk_00[1] + ((d * (b->mUnk_00[1] - a->mUnk_00[1])) >> 12);
        c->mUnk_00[2] = a->mUnk_00[2] + ((d * (b->mUnk_00[2] - a->mUnk_00[2])) >> 12);
        c->mUnk_00[3] = a->mUnk_00[3] + ((d * (b->mUnk_00[3] - a->mUnk_00[3])) >> 12);
    }
}

void func_020d73f0(Unk020d7b88 *a, Unk020d7b88 *b) {
    s64 w;
    s32 r;
    s64 q;
    s64 t;
    w = a->mUnk_00[0] * a->mUnk_00[0] + a->mUnk_00[1] * a->mUnk_00[1] + a->mUnk_00[2] * a->mUnk_00[2] +
        a->mUnk_00[3] * a->mUnk_00[3];
    if (w > 0xE66666 && w < 0x119999A) {
        *b = *a;
        return;
    }
    reg_CP_DIVCNT = 2;
    reg_CP_DIV_NUMER = 0x1000000000000LL << 8;
    reg_CP_DIV_DENOM = w;
    reg_CP_SQRTCNT = 1;
    reg_CP_SQRT_PARAM = w << 2;
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    r = reg_CP_SQRT_RESULT;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    q = reg_CP_DIV_RESULT;
    t = q * r;
    b->mUnk_00[0] = (t * a->mUnk_00[0] + 0x100000000000LL) >> 45;
    b->mUnk_00[1] = (t * a->mUnk_00[1] + 0x100000000000LL) >> 45;
    b->mUnk_00[2] = (t * a->mUnk_00[2] + 0x100000000000LL) >> 45;
    b->mUnk_00[3] = (t * a->mUnk_00[3] + 0x100000000000LL) >> 45;
}

void func_020d720c(Vec3 *a, u32 *m) {
    Unk020d7b88 *b = (Unk020d7b88 *) m;
    Unk020d7b88 p;
    Unk020d7b88 q;
    Unk020d7b88 r;
    s32 i;
    s32 s;
    s32 c;
    s32 t;
    t = ((s64) a->x * 0xB60B60B60BLL + 0x80000000000LL) >> 44;
    i = (u16) ((u16) t >> 1) >> 4;
    p.mUnk_00[0] = gPairsByAngle[i * 2];
    p.mUnk_00[3] = gPairsByAngle[i * 2 + 1];
    p.mUnk_00[1] = 0;
    p.mUnk_00[2] = 0;
    q = p;
    t = ((s64) a->y * 0xB60B60B60BLL + 0x80000000000LL) >> 44;
    i = (u16) ((u16) t >> 1) >> 4;
    s = gPairsByAngle[i * 2];
    c = gPairsByAngle[i * 2 + 1];
    p.mUnk_00[0] = (q.mUnk_00[0] * c - q.mUnk_00[2] * s) >> 12;
    p.mUnk_00[2] = (q.mUnk_00[2] * c + q.mUnk_00[0] * s) >> 12;
    p.mUnk_00[1] = (q.mUnk_00[3] * s + q.mUnk_00[1] * c) >> 12;
    p.mUnk_00[3] = (q.mUnk_00[3] * c - q.mUnk_00[1] * s) >> 12;
    r = p;
    t = ((s64) a->z * 0xB60B60B60BLL + 0x80000000000LL) >> 44;
    i = (u16) ((u16) t >> 1) >> 4;
    s = gPairsByAngle[i * 2];
    c = gPairsByAngle[i * 2 + 1];
    b->mUnk_00[0] = (r.mUnk_00[0] * c + r.mUnk_00[1] * s) >> 12;
    b->mUnk_00[1] = (r.mUnk_00[1] * c - r.mUnk_00[0] * s) >> 12;
    b->mUnk_00[2] = (r.mUnk_00[3] * s + r.mUnk_00[2] * c) >> 12;
    b->mUnk_00[3] = (r.mUnk_00[3] * c - r.mUnk_00[2] * s) >> 12;
}

s32 Vec3NormalizeAndGetLengthOrZero(Vec3 *a, Vec3 *b) {
    s64 w;
    s32 r;
    s64 q;
    s64 t;
    w = (s64) a->x * a->x;
    w += (s64) a->y * a->y;
    w += (s64) a->z * a->z;
    if (w < 16) {
        return 0;
    }
    reg_CP_DIVCNT = 2;
    reg_CP_DIV_NUMER = 0x1000000000000LL << 8;
    reg_CP_DIV_DENOM = w;
    reg_CP_SQRTCNT = 1;
    reg_CP_SQRT_PARAM = w << 2;
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    r = reg_CP_SQRT_RESULT;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    q = reg_CP_DIV_RESULT;
    t = q * r;
    b->x = (t * a->x + 0x100000000000LL) >> 45;
    b->y = (t * a->y + 0x100000000000LL) >> 45;
    b->z = (t * a->z + 0x100000000000LL) >> 45;
    return (r + 1) >> 1;
}

s32 Vec3NormalizeXZAndGetLengthOrZero(Vec3 *a, Vec3 *b) {
    s64 w;
    s32 r;
    s64 q;
    s64 t;
    s32 x = a->x;
    s32 z = a->z;
    w = (s64) x * x + (s64) z * z;
    if (w < 16) {
        return 0;
    }
    reg_CP_DIVCNT = 2;
    reg_CP_DIV_NUMER = 0x1000000000000LL << 8;
    reg_CP_DIV_DENOM = w;
    reg_CP_SQRTCNT = 1;
    reg_CP_SQRT_PARAM = w << 2;
    while (reg_CP_SQRTCNT & 0x8000) {
    }
    r = reg_CP_SQRT_RESULT;
    while (reg_CP_DIVCNT & 0x8000) {
    }
    q = reg_CP_DIV_RESULT;
    t = q * r;
    b->x = (t * a->x + 0x100000000000LL) >> 45;
    b->z = (t * a->z + 0x100000000000LL) >> 45;
    return (r + 1) >> 1;
}

void Vec3RotateAroundY(Vec3 *a, s32 b, Vec3 *c) {
    s32 m[9];
    s32 i = b >> 4;
    MTX_RotY33_(m, gPairsByAngle[i * 2], gPairsByAngle[i * 2 + 1]);
    MTX_MultVec33(a, m, c);
}

void Matrix3x3FromVec3Degrees(Vec3 *a, s32 *b) {
    s32 m[9];
    s32 i;
    s32 j;
    s32 k;
    i = (u16) ((((s64) a->x * 0xB60B60B60BLL) + 0x80000000000LL) >> 44);
    j = (u16) ((((s64) a->y * 0xB60B60B60BLL) + 0x80000000000LL) >> 44);
    k = (u16) ((((s64) a->z * 0xB60B60B60BLL) + 0x80000000000LL) >> 44);
    MTX_RotX33_(b, gPairsByAngle[(i >> 4) * 2], gPairsByAngle[(i >> 4) * 2 + 1]);
    MTX_RotY33_(m, gPairsByAngle[(j >> 4) * 2], gPairsByAngle[(j >> 4) * 2 + 1]);
    MTX_Concat33(b, m, b);
    MTX_RotZ33_(m, gPairsByAngle[(k >> 4) * 2], gPairsByAngle[(k >> 4) * 2 + 1]);
    MTX_Concat33(b, m, b);
}

u32 func_020d6dc0(s32 a, s32 b, s32 c, s32 d) {
    u32 v = data_0216b96c[c][b][d];
    if (v == 1) {
        v = a != 0 ? 2 : 0;
    }
    return v;
}

u32 func_020d6d8c(u32 arg0, u32 arg1, u32 arg2, u32 arg3) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2 = arg2;
    u32 value3 = arg3;
    u32 value12;
    u32 value14;
    u32 compareLeft0;
    u32 compareRight0;
    value14 = (u32) &data_0216bb7c;
    value12 = 0x38u;
    value12 = (value2) * (value12) + (value14);
    value1 = *(const u32 *) ((value12) + ((value1 << 2)));
    compareLeft0 = value0;
    compareRight0 = 0u;
    value0 = *(const u8 *) ((value1) + (value3));
    if (compareLeft0 != compareRight0) {
        value0 = 0u;
    }
    return value0;
}

u32 func_020d6d34(s32 a, s32 b, s32 c, s32 d, s32 e) {
    u32 v = data_0216ba2c[c][b][d];
    if (a != 0 && v == 1 && e != 0) {
        v = 2;
    }
    return v;
}

s32 func_020d6be0(Kart *a, MapObject *b) {
    s32 r = b->mKind;
    s32 n = 0;
    s32 f;
    s32 v;
    s32 buf[2];
    f = b->mFlags & 0x800;
    while (r >= 100) {
        r -= 100;
        n++;
    }
    if (b->mKindData->mUnk_00 != NULL) {
        v = data_0216b9cc[n][a->mUnk_29c][r];
        if (f != 0 && v != 2 && v != 4) {
            v = 0;
        }
        buf[0] = v;
        v = data_0216b96c[n][a->mUnk_29c][r];
        if (v == 1) {
            v = f != 0 ? 2 : 0;
        }
        buf[1] = v;
        if ((b->mFlags & 0x80) == 0) {
            buf[1] = b->mKindData->mUnk_00(b, a, &buf[0], &buf[1]);
        }
        if (data_021759c0->mMode == MODE_MISSION_RUN && buf[0] == 1 && data_021759c0->mMode == MODE_MISSION_RUN) {
            func_ov001_0218175c(b->mKind);
        }
        return buf[1];
    }
    v = data_0216b96c[n][a->mUnk_29c][r];
    if (v != 1) {
        return v;
    }
    return f != 0 ? 2 : 0;
}

s32 func_020d6a54(ItemObject *a, MapObject *b, s32 *c) {
    s32 r = b->mKind;
    s32 n = 0;
    s32 f = b->mFlags & 0x800;
    s32 v;
    s32 buf[2];
    s32 t;
    while (r >= 100) {
        r -= 100;
        n++;
    }
    if (b->mKindData->mUnk_04 != NULL) {
        v = data_0216bb7c[n][a->mKind][r];
        if (f != 0) {
            v = 0;
        }
        buf[0] = v;
        t = b->mKindData->mUnk_20;
        v = data_0216ba2c[n][a->mKind][r];
        if (f != 0 && v == 1 && t != 0) {
            v = 2;
        }
        buf[1] = v;
        if ((b->mFlags & 0x80) == 0) {
            buf[1] = b->mKindData->mUnk_04(b, a, &buf[0], &buf[1]);
        }
        if (data_021759c0->mMode == MODE_MISSION_RUN && buf[0] == 1 && data_021759c0->mMode == MODE_MISSION_RUN) {
            func_ov001_0218175c(b->mKind);
        }
        if (c != NULL) {
            *c = buf[0];
        }
        return buf[1];
    }
    if (c != NULL) {
        *c = 0;
    }
    t = b->mKindData->mUnk_20;
    v = data_0216ba2c[n][a->mKind][r];
    if (f != 0 && v == 1 && t != 0) {
        v = 2;
    }
    return v;
}

s32 func_020d69e4(s32 a, MapObject *b) {
    s32 r = b->mKind;
    s32 n = 0;
    s32 v;
    s32 f;
    while (r >= 100) {
        r -= 100;
        n++;
    }
    f = b->mFlags & 0x800;
    v = data_0216b96c[n][a][r];
    if (v == 1) {
        v = f != 0 ? 2 : 0;
    }
    return v != 0 ? 1 : 0;
}

s32 func_020d6968(s32 a, MapObject *b) {
    s32 r = b->mKind;
    s32 n = 0;
    s32 v;
    s32 f;
    s32 x;
    while (r >= 100) {
        r -= 100;
        n++;
    }
    f = b->mFlags & 0x800;
    x = b->mKindData->mUnk_20;
    v = data_0216ba2c[n][a][r];
    if (f != 0 && v == 1 && x != 0) {
        v = 2;
    }
    return v != 0 ? 1 : 0;
}

s32 func_020d6910(s32 a, MapObject *b) {
    MapObject *p = b;
    s32 r = p->mKind;
    s32 n = 0;
    s32 v;
    s32 f;
    while (r >= 100) {
        r -= 100;
        n++;
    }
    f = p->mFlags & 0x800;
    v = data_0216bb7c[n][a][r];
    if (f != 0) {
        v = 0;
    }
    return v;
}

Unk02156adc *func_020d68b0(void) {
    Unk02156adc *p = HeapAlloc(GetHeap(func_020364e8()), 0x40);
    *p = data_02156adc;
    p->mUnk_38 = 0x3e8000;
    p->mUnk_3c = -0x3e8000;
    return p;
}

Unk0217b650 *func_020d6850(void) {
    Unk0217b650 *p = HeapAlloc(GetHeap(func_020364e8()), 0x5c);
    data_0217b650 = p;
    *p = data_02156a80;
    func_020d49d8(&data_0217b650);
    return data_0217b650;
}

Unk0217b650 *func_020d67f0(void) {
    Unk0217b650 *p = HeapAlloc(GetHeap(func_020364e8()), 0x5c);
    data_0217b650 = p;
    *p = data_02156a24;
    func_020d49d8(&data_0217b650);
    return data_0217b650;
}

Unk0217b654 *func_020d6794(void) {
    Unk0217b654 *p = HeapAlloc(GetHeap(func_020364e8()), 0x28);
    data_0217b654 = p;
    *p = data_021569fc;
    func_020e6f50(&data_0217b654);
    return data_0217b654;
}

void func_020d673c(void) {
    s32 i = (s32) (GetRaceUpdateFrames() << 25 >> 16) >> 4;
    MTX_RotY33_(data_0217b650->mUnk_2c.mUnk_00, gPairsByAngle[i * 2], gPairsByAngle[i * 2 + 1]);
}

void func_020d655c(void *a, Unk020d655c *b, void *c, s32 d) {
    Vec3 v0;
    Vec3 v1;
    Vec3 v2;
    Vec3 v3;
    Unk0217b650_2c *p;
    s32 r;
    if (func_020b2ec0() == 0) {
        v2 = b->mUnk_00.mMatrix.mUnk_00[0];
        v3 = b->mUnk_00.mMatrix.mUnk_00[1];
        v0.x = ((s64) b->mUnk_00.mUnk_10.z * (s64) b->mUnk_118) >> 12;
        v0.z = -(s32) (((s64) b->mUnk_00.mUnk_10.x * (s64) b->mUnk_118) >> 12);
        v0.y = 0;
        Vec3CrossUnrounded(&v0, &v2, &v1);
        VEC_Add(&v2, &v1, &v2);
        Vec3NormalizeAndGetLengthUnchecked(&v2, &b->mUnk_00.mMatrix.mUnk_00[0]);
        Vec3CrossUnrounded(&v0, &v3, &v1);
        VEC_Add(&v3, &v1, &v3);
        r = VEC_DotProduct(&b->mUnk_00.mMatrix.mUnk_00[0], &v3);
        v3.x = v3.x - (s32) (((s64) b->mUnk_00.mMatrix.mUnk_00[0].x * (s64) r) >> 12);
        v3.y = v3.y - (s32) (((s64) b->mUnk_00.mMatrix.mUnk_00[0].y * (s64) r) >> 12);
        v3.z = v3.z - (s32) (((s64) b->mUnk_00.mMatrix.mUnk_00[0].z * (s64) r) >> 12);
        Vec3NormalizeAndGetLengthUnchecked(&v3, &b->mUnk_00.mMatrix.mUnk_00[1]);
        Vec3CrossUnrounded(&b->mUnk_00.mMatrix.mUnk_00[0], &b->mUnk_00.mMatrix.mUnk_00[1],
                           &b->mUnk_00.mMatrix.mUnk_00[2]);
    }
    b->mUnk_00.mMatrix.mUnk_00[3].x = b->mUnk_00.mPos.x >> 4;
    b->mUnk_00.mMatrix.mUnk_00[3].y = b->mUnk_00.mPos.y >> 4;
    b->mUnk_00.mMatrix.mUnk_00[3].z = b->mUnk_00.mPos.z >> 4;
    func_020ea8a8(gRock, &b->mUnk_00.mMatrix, &b->mUnk_00.mScale, d);
    p = &data_0217b650->mUnk_2c;
    p->mUnk_24.x = b->mUnk_00.mPos.x >> 4;
    p->mUnk_24.y = b->mUnk_00.mPos.y >> 4;
    p->mUnk_24.z = b->mUnk_00.mPos.z >> 4;
    func_020ea868(gRockShadow, &data_0217b650->mUnk_2c, &b->mUnk_00.mScale, d);
}

void func_020d6538(Unk020d6538_a *p0, Unk020d634c *p1) {
    p0->mUnk_5c = p1->mUnk_00;
    p0->mUnk_64 = p1->mUnk_04;
    p0->mUnk_68 = p1->mUnk_06;
    p0->mUnk_6c = p1->mUnk_08;
}
