#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020d655c.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02061f7c.h"
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

u32 func_020d6d34(s32 a, s32 b, s32 c, s32 d, s32 e) {
    u32 v = data_0216ba2c[c][b][d];
    if (a != 0 && v == 1 && e != 0) {
        v = 2;
    }
    return v;
}

s32 func_020d6be0(Unk0206bcb0 *a, MapObject *b) {
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
        if (data_021759c0->mUnk_08 == 4 && buf[0] == 1 && data_021759c0->mUnk_08 == 4) {
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

s32 func_020d6a54(Unk020f41c4_A *a, MapObject *b, s32 *c) {
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
        v = data_0216bb7c[n][a->mUnk_44][r];
        if (f != 0) {
            v = 0;
        }
        buf[0] = v;
        t = b->mKindData->mUnk_20;
        v = data_0216ba2c[n][a->mUnk_44][r];
        if (f != 0 && v == 1 && t != 0) {
            v = 2;
        }
        buf[1] = v;
        if ((b->mFlags & 0x80) == 0) {
            buf[1] = b->mKindData->mUnk_04(b, a, &buf[0], &buf[1]);
        }
        if (data_021759c0->mUnk_08 == 4 && buf[0] == 1 && data_021759c0->mUnk_08 == 4) {
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
    v = data_0216ba2c[n][a->mUnk_44][r];
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

s32 func_020d6910(s32 a, void *b) {
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
    Unk02156adc *p = func_02036bec(func_020364e0(func_020364e8()), 0x40);
    *p = data_02156adc;
    p->mUnk_38 = 0x3e8000;
    p->mUnk_3c = -0x3e8000;
    return p;
}

Unk0217b650 *func_020d6850(void) {
    Unk0217b650 *p = func_02036bec(func_020364e0(func_020364e8()), 0x5c);
    data_0217b650 = p;
    *p = data_02156a80;
    func_020d49d8(&data_0217b650);
    return data_0217b650;
}

Unk0217b650 *func_020d67f0(void) {
    Unk0217b650 *p = func_02036bec(func_020364e0(func_020364e8()), 0x5c);
    data_0217b650 = p;
    *p = data_02156a24;
    func_020d49d8(&data_0217b650);
    return data_0217b650;
}

Unk0217b654 *func_020d6794(void) {
    Unk0217b654 *p = func_02036bec(func_020364e0(func_020364e8()), 0x28);
    data_0217b654 = p;
    *p = data_021569fc;
    func_020e6f50(&data_0217b654);
    return data_0217b654;
}

void func_020d673c(void) {
    s32 i = (s32) (func_02061fb8() << 25 >> 16) >> 4;
    func_02146d44(data_0217b650->mUnk_2c.mUnk_00, data_0215d4b4[i * 2], data_0215d4b4[i * 2 + 1]);
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
        v0.x = (s32) (((s64) b->mUnk_00.mUnk_10.z * (s64) b->mUnk_118) >> 12);
        v0.z = -(s32) (((s64) b->mUnk_00.mUnk_10.x * (s64) b->mUnk_118) >> 12);
        v0.y = 0;
        func_020397a8(&v0, &v2, &v1);
        func_02148504(&v2, &v1, &v2);
        func_02039860(&v2, &b->mUnk_00.mMatrix.mUnk_00[0]);
        func_020397a8(&v0, &v3, &v1);
        func_02148504(&v3, &v1, &v3);
        r = func_0214848c(&b->mUnk_00.mMatrix.mUnk_00[0], &v3);
        v3.x = v3.x - (s32) (((s64) b->mUnk_00.mMatrix.mUnk_00[0].x * (s64) r) >> 12);
        v3.y = v3.y - (s32) (((s64) b->mUnk_00.mMatrix.mUnk_00[0].y * (s64) r) >> 12);
        v3.z = v3.z - (s32) (((s64) b->mUnk_00.mMatrix.mUnk_00[0].z * (s64) r) >> 12);
        func_02039860(&v3, &b->mUnk_00.mMatrix.mUnk_00[1]);
        func_020397a8(&b->mUnk_00.mMatrix.mUnk_00[0], &b->mUnk_00.mMatrix.mUnk_00[1], &b->mUnk_00.mMatrix.mUnk_00[2]);
    }
    b->mUnk_00.mMatrix.mUnk_00[3].x = b->mUnk_00.mPos.x >> 4;
    b->mUnk_00.mMatrix.mUnk_00[3].y = b->mUnk_00.mPos.y >> 4;
    b->mUnk_00.mMatrix.mUnk_00[3].z = b->mUnk_00.mPos.z >> 4;
    func_020ea8a8(gRock, &b->mUnk_00.mMatrix, &b->mUnk_00.mUnk_1c, d);
    p = &data_0217b650->mUnk_2c;
    p->mUnk_24.x = b->mUnk_00.mPos.x >> 4;
    p->mUnk_24.y = b->mUnk_00.mPos.y >> 4;
    p->mUnk_24.z = b->mUnk_00.mPos.z >> 4;
    func_020ea868(gRockShadow, &data_0217b650->mUnk_2c, &b->mUnk_00.mUnk_1c, d);
}
