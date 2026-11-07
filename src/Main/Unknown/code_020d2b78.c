#include "Main/Unknown/code_020d2b78.h"

#include "Main/Unknown/code_020d2c2c.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020d3dbc.h"
#include "Main/Unknown/code_020d6000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020d6538.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d2d94.h"
#include "Main/Unknown/code_020d94dc.h"

#pragma thumb on

void func_020d2d94(void) {
    int v1;
    MapObjectList **v2;
    void **v3;
    MapObjectList **v4;
    v2 = gMapObjects->mDrawLists;
    v4 = gMapObjects->mUpdateLists;
    v1 = 0;
    do {
        if (*v2 != NULL) {
            v3 = *(void ***) ((s32) *v2 + 0x28);
            if (v3 != NULL) {
                *v3 = NULL;
            }
            *v2 = NULL;
        }
        v2 = v2 + 1;
        v1 = v1 + 1;
    } while (v1 < 0x18);
    v1 = 0;
    do {
        if (*v4 != NULL) {
            v3 = (*v4)->mUnk_24;
            if (v3 != NULL) {
                *v3 = NULL;
            }
            *v4 = NULL;
        }
        v4 = v4 + 1;
        v1 = v1 + 1;
    } while (v1 < 0x10);
}

#pragma thumb off

#pragma thumb on

s32 func_020d2c2c(Vec3 *b, Vec3 *c, s32 d, s16 e, s32 f, Vec3 *g) {
    s32 a;
    s32 i;
    a = 0;
    func_01ffd900(e, 0x2000);
    i = 0;
    if (data_0217b5a8 != 0) {
        Vec3 v;
        Vec3 mn;
        Vec3 mx;
        ItemObject *q;
        MapObject *p;
        s32 r;
        s32 t;
        {
            Vec3 z1 = {0, 0, 0};
            mn = z1;
        }
        {
            Vec3 z2 = {0, 0, 0};
            mx = z2;
        }
        q = &gMapObjects->mUnk_18c;
        for (; i < data_0217b5a8; i++) {
            p = data_0217b5c4[i];
            if (IsSphereHittingMapObject(b, d, p, &v) != FALSE) {
                if (!(p->mFlags & 0x40) && func_020d6968(f, p) != 0) {
                    t = v.x;
                    mn.x = ((const Vec3 *) &v)->x < mn.x ? t : mn.x;
                    mn.y = v.y < mn.y ? v.y : mn.y;
                    mn.z = v.z < mn.z ? v.z : mn.z;
                    mx.x = t > mx.x ? t : mx.x;
                    mx.y = v.y > mx.y ? v.y : mx.y;
                    mx.z = v.z > mx.z ? v.z : mx.z;
                }
                q->mPos = *b;
                q->mVelocity = *c;
                q->mKind = f;
                r = func_020d6a54(q, p, NULL);
                if (r > a) {
                    a = r;
                }
            }
        }
        if (a != 0 && g != NULL) {
            g->x = mx.x + mn.x;
            g->y = mx.y + mn.y;
            if (g->y < 0) {
                g->y = 0;
            }
            g->z = mx.z + mn.z;
        }
    }
    return a;
}

#pragma thumb off

#pragma thumb on

u32 func_020d2c20(void) {
    return (data_0217b4ec);
}

// The water_efct.nsbmd file: WaterEfct's if gCourseWaterEfct exists, else the Water's own when mUnk_170 is non-zero,
// else NULL; passed as an effect model file to SetupModelEffectKind.
void *GetWaterEfctNsbmdFile(void) {
    Water *v1;
    if (gCourseWaterEfct != NULL) {
        return gCourseWaterEfct->mNsbmdFile;
    }
    v1 = gCourseWater;
    if ((v1 != NULL) && (v1->mUnk_170 != 0)) {
        return v1->mEfctNsbmdFile;
    }
    return NULL;
}

// The water_efct.nsbca file, same rule as GetWaterEfctNsbmdFile.
void *GetWaterEfctNsbcaFile(void) {
    Water *v1;
    if (gCourseWaterEfct != NULL) {
        return gCourseWaterEfct->mNsbcaFile;
    }
    v1 = gCourseWater;
    if ((v1 != NULL) && (v1->mUnk_170 != 0)) {
        return v1->mEfctNsbcaFile;
    }
    return NULL;
}

// The water_efct.nsbma file, same rule as GetWaterEfctNsbmdFile.
void *GetWaterEfctNsbmaFile(void) {
    Water *v1;
    if (gCourseWaterEfct != NULL) {
        return gCourseWaterEfct->mNsbmaFile;
    }
    v1 = gCourseWater;
    if ((v1 != NULL) && (v1->mUnk_170 != 0)) {
        return v1->mEfctNsbmaFile;
    }
    return NULL;
}

#pragma thumb off
