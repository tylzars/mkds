#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_0214d018.h"

static inline u32 func_0208b190_inline(Unk020f41c4_B *b, u32 n) {
    b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    if (n == 0) {
        return b->mUnk_00 >> 32;
    }
    return ((b->mUnk_00 >> 32) * n) >> 32;
}

Unk020184e4 *func_0208b458(s32 *a, s32 b) {
    if (b >= 0x3e8) {
        b -= 0x3e8;
        *a = b;
        return data_0217b03c;
    }
    *a = b;
    return data_0217b044;
}

void func_0208b190(void) {
    s16 i;
    s32 v2;
    Vec3 v3;
    s32 u[6];
    s32 w[6];
    s32 v1;
    s32 j;
    s32 k;
    s32 m;
    s32 n;
    Unk0217b050Func *f;
    Camera *g;

    data_0217b048->mUnk_60--;
    if (data_0217b048->mUnk_60 > 0) {
        return;
    }
    v1 = -0x1000;
    v2 = -1;
    g = GetCurrentCamera();
    v3 = g->mForward;
    for (i = 0; i < 6; i++) {
        Unk0217b048 *h = data_0217b048;
        if (h->mUnk_48[i] != NULL) {
            s32 e;
            Unk0201ca6c **r = &h->mUnk_48[i];
            SPLManager_DeleteEmitter(data_0217b050(&e, 0), *r);
            *r = NULL;
        }
    }
    for (i = 0; i < 6; i++) {
        s32 d = VEC_DotProduct(&v3, &data_0217b048->mUnk_00[i]);
        if (d >= v1) {
            v1 = d;
            v2 = i;
        }
    }
    j = v2 - 1;
    if (j < 0) {
        j = 5;
    }
    k = v2 + 1;
    if (k >= 6) {
        k = 0;
    }
    u[0] = data_usa_02155f48[j * 2];
    u[1] = data_usa_02155f48[j * 2 + 1];
    u[2] = data_usa_02155f48[v2 * 2];
    u[3] = data_usa_02155f48[v2 * 2 + 1];
    u[4] = data_usa_02155f48[k * 2];
    u[5] = data_usa_02155f48[k * 2 + 1];
    w[0] = w[1] = j;
    w[2] = w[3] = v2;
    w[4] = w[5] = k;
    for (m = 0; m < 6; m++) {
        s32 e;
        Vec3 v;
        Unk0201ca6c *q;
        Unk020184e4 *p;
        Vec3 *t = &data_usa_02155f78[w[m]];
        f = data_0217b050;
        p = f(&e, u[m]);
        v.x = t->x >> 4;
        v.y = t->y >> 4;
        v.z = t->z >> 4;
        q = SPLManager_CreateEmitter(p, e, &v);
        if (q != NULL) {
            if (q->mUnk_20->mUnk_00->mUnk_54 & 0x80) {
                q->mUnk_80_16 = 1;
            } else if (q->mUnk_20->mUnk_00->mUnk_54 & 0x40) {
                q->mUnk_80_16 = 2;
            }
        }
        data_0217b048->mUnk_48[m] = q;
    }
    n = func_0208b190_inline(&gRaceProgress->mLocalRandom, 0x19);
    data_0217b048->mUnk_60 = (u16) n + 0x14;
}

void func_0208afe4(void) {
    Unk02166108 a = data_usa_02166108;
    Unk021660f8 b = data_usa_021660f8;
    s32 x = data_usa_02155fc0.x;
    s32 y = data_usa_02155fc0.y;
    s32 z = data_usa_02155fc0.z;
    u16 i;
    s32 k = x >> 4;
    s32 l = y >> 4;
    s32 m = z >> 4;

    for (i = 0; i < 2; i++) {
        s32 e;
        Vec3 v;
        Unk0201ca6c *q;
        Unk020184e4 *p = data_0217b050(&e, b.mUnk_00[i]);
        v.x = k;
        v.y = l;
        v.z = m;
        q = SPLManager_CreateEmitter(p, e, &v);
        if (q != NULL) {
            if (q->mUnk_20->mUnk_00->mUnk_54 & 0x80) {
                q->mUnk_80_16 = 1;
            } else if (q->mUnk_20->mUnk_00->mUnk_54 & 0x40) {
                q->mUnk_80_16 = 2;
            }
        }
    }
    for (i = 0; i < 0x18; i++) {
        s32 e;
        Vec3 v;
        Unk0201ca6c *q;
        Unk020184e4 *p = data_0217b050(&e, a.mUnk_00[i]);
        v.x = x >> 4;
        v.y = l;
        v.z = m;
        q = SPLManager_CreateEmitter(p, e, &v);
        if (q != NULL) {
            if (q->mUnk_20->mUnk_00->mUnk_54 & 0x80) {
                q->mUnk_80_16 = 1;
            } else if (q->mUnk_20->mUnk_00->mUnk_54 & 0x40) {
                q->mUnk_80_16 = 2;
            }
        }
    }
}

void CreateKartPhysicalParamTable(void *a, u32 b) {
    gKartPhysicalParamTable = HeapAlloc(a, 0x14);
    gKartPhysicalParamTable->mKartParams = HeapAlloc(a, b * 0x98);
    gKartPhysicalParamTable->mCharParams = HeapAlloc(a, b * 8);
    gKartPhysicalParamTable->mKartParamFile = FindKartModelFile(data_usa_021660c8);
    gKartPhysicalParamTable->mCharParamFile = FindKartModelFile(data_usa_021660e0);
    gKartPhysicalParamTable->mFirstBaseSpeedLimit = *(s32 *) (gKartPhysicalParamTable->mKartParamFile + 0x10);
}

// Copies the kart row and the character row of the files to the slot after choosing the rows (rows 0 when
// func_02062eb0() != 0; character + 0x25 in mode 2).
void CopyKartPhysicalParams(u32 a, u32 b, u32 c) {
    u8 *p = gKartPhysicalParamTable->mKartParamFile;
    u8 *q = gKartPhysicalParamTable->mCharParamFile;
    if (func_02062eb0() != 0) {
        c = 0;
        b = c;
    } else if (gRaceSetup->mMode == MODE_BATTLE) {
        b = (u16) (c + 0x25);
    }
    MI_CpuCopy8(p + b * 0x98, gKartPhysicalParamTable->mKartParams + a * 0x98, 0x98);
    MI_CpuCopy8(q + c * 8, gKartPhysicalParamTable->mCharParams + a * 8, 8);
}
