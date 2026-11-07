#include "Main/Unknown/code_0208b484.h"

#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020483e4.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_02018000.h"
#include "Main/Unknown/code_0208c534.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_0208d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02077bc0.h"

u32 func_0208bd04(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value2 = (u32) &data_0217b040;
    value12 = (u32) &HeapAlloc;
    value1 = value0;
    value0 = *(const u32 *) ((value2) + (0));
    value0 = (u32) HeapAlloc((void *) value0, value1);
    return value0;
}

void func_0208b934(void *a) {
    s32 e = 0x78;
    s32 f = 0x28;
    void *c = a;
    void *g;
    void *h;
    void *t;
    u8 j;
    Vec3 w;
    Vec3 v;
    RaceSetup *d;
    Vec3 *q;

    *(u32 *) &data_0217b050 = (u32) func_0208b484;
    if (GetCurrentSceneNumber() == 2) {
        d = gRaceSetup;
        if (d->mMode == MODE_MISSION_RUN) {
            *(u32 *) &data_0217b050 = (u32) func_0208b458;
            c = data_0217aa10->mUnk_a4;
            e = 0x96;
        }
        if (d->mCourseId == COURSE_ID_AWARD) {
            e = 0x12c;
            f = 0x32;
        }
    }
    data_0217b040 = c;
    data_0217b044 = SPLManager_New((void *(*) (u32)) func_0208bd04, f, e, 3, 0xe, GetSplMaxPolyId());
    g = FindMainRaceOrMainEffectFile(data_usa_02166138);
    SPLManager_LoadResources(data_0217b044, g);
    SPLManager_UploadTextures(data_0217b044);
    SPLManager_UploadPalettes(data_0217b044);
    ResizeMainEffectArchiveBlock(g, *OFFSET_PTR(u32, g, 0x18));
    data_0217b04c = SPLManager_New((void *(*) (u32)) func_0208bd04, 0x1e, 0x64, 3, 0xe, 0x1e);
    h = FindMainRaceOrMainEffectFile(data_usa_02166148);
    SPLManager_LoadResources(data_0217b04c, h);
    SPLManager_UploadTextures(data_0217b04c);
    SPLManager_UploadPalettes(data_0217b04c);
    data_0217b03c = NULL;
    data_0217b054 = NULL;
    data_0217b048 = NULL;
    if (GetCurrentSceneNumber() != 2) {
        return;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        t = NULL;
        data_0217b03c = SPLManager_New((void *(*) (u32)) func_0208bd04, 0x32, 0xc8, 3, 0xe, 0x1e);
        LoadFileIntoHeap(data_usa_02166168, c, &t);
        SPLManager_LoadResources(data_0217b03c, t);
        SPLManager_UploadTextures(data_0217b03c);
        SPLManager_UploadPalettes(data_0217b03c);
        data_0217b03c->mMiscPolygonAttr = 0x8000;
    }
    data_0217b044->mPolygonIDDrawOrder = 1;
    data_0217b04c->mPolygonIDDrawOrder = 1;
    if (data_0217b03c != NULL) {
        data_0217b03c->mPolygonIDDrawOrder = 1;
    }
    InitKartTurnEffects(a);
    if (gRaceSetup->mCourseId != COURSE_ID_RAINBOW) {
        data_0217b044->mMiscPolygonAttr = 0x8000;
    } else {
        data_0217b044->mMiscPolygonAttr = 0;
    }
    InitCourseCameraEffects();
    switch (gRaceSetup->mCourseId) {
        case COURSE_ID_STADIUM:
            w = data_usa_021660fc;
            data_0217b048 = HeapAlloc(c, 0x64);
            for (j = 0; j < 6; j++) {
                data_0217b048->mUnk_48[j] = NULL;
                VEC_Subtract(&data_usa_02155f78[j], &w, &v);
                q = &data_0217b048->mUnk_00[j];
                if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&v, q);
                }
            }
            data_0217b048->mUnk_60 = 1;
            data_0217b054 = (UnkFunc *) func_0208b190;
            break;
        case COURSE_ID_AWARD:
            func_0208afe4();
            break;
    }
}

void func_0208b8c8(void) {
    if (data_0217b054 != NULL) {
        data_0217b054();
    }
    SPLManager_Update(data_0217b044);
    SPLManager_Update(data_0217b04c);
    if (data_0217b03c != NULL) {
        SPLManager_Update(data_0217b03c);
    }
}

void func_0208b870(MtxFx43 *a) {
    SPLManager_Draw(data_0217b044, a);
    SPLManager_Draw(data_0217b04c, a);
    if (data_0217b03c != NULL) {
        SPLManager_Draw(data_0217b03c, a);
    }
}

void *StartEffect(u32 a, const Vec3 *b) {
    s32 e;
    Vec3 v;
    Unk0201ca6c *q;
    SPLManager *p = data_0217b050(&e, a);
    v.x = b->x >> 4;
    v.y = b->y >> 4;
    v.z = b->z >> 4;
    q = SPLManager_CreateEmitter(p, e, &v);
    if (q != NULL) {
        if (q->mUnk_20->mUnk_00->mUnk_54 & 0x80) {
            q->mUnk_80_16 = 1;
        } else if (q->mUnk_20->mUnk_00->mUnk_54 & 0x40) {
            q->mUnk_80_16 = 2;
        }
    }
    return q;
}

void func_0208b748(u32 a, const Vec3 *b, void *c, void (*d)()) {
    s32 e;
    Vec3 v;
    SPLManager *p = data_0217b050(&e, a);
    v.x = b->x >> 4;
    v.y = b->y >> 4;
    v.z = b->z >> 4;
    SPLManager_CreateEmitterWithCallbackEx(p, e, &v, (s32) c, (void (*)(Unk0201ca6c *, s32)) d);
}

void func_0208b710(Unk0201ca6c *a) {
    u32 v1;
    u8 v2[8];
    v1 = (*(UnkWordFunc *) (u32) data_0217b050)(v2, 0);
    SPLManager_DeleteEmitter((SPLManager *) v1, a);
}

void func_0208b6d0(Unk0201ca6c **a) {
    u32 v1;
    u8 v2[8];
    v1 = (*(UnkWordFunc *) (u32) data_0217b050)(v2, 0);
    SPLManager_DeleteEmitter((SPLManager *) v1, *a);
    *a = NULL;
}

void func_0208b6b0(void **p0) {
    *(u32 *) ((u8 *) *p0 + 36) = (*(u32 *) ((u8 *) *p0 + 36) & ~0x1u) | 0x1u;
    *p0 = NULL;
}

Unk0201ca6c *func_0208b60c(s32 a, Vec3 *b) {
    Vec3 v;
    Unk0201ca6c *q;
    v.x = b->x >> 4;
    v.y = b->y >> 4;
    v.z = b->z >> 4;
    q = SPLManager_CreateEmitter(data_0217b04c, a, &v);
    if (q != NULL) {
        if (q->mUnk_20->mUnk_00->mUnk_54 & 0x80) {
            q->mUnk_80_16 = 1;
        } else if (q->mUnk_20->mUnk_00->mUnk_54 & 0x40) {
            q->mUnk_80_16 = 2;
        }
    }
    return q;
}

void func_0208b5b0(void *v1, const Vec3 *b) {
    Unk0201ca6c *a = v1;
    s32 c = b->x;
    s32 d = b->y;
    s32 e = b->z;
    a->mUnk_28.x = (c >> 4) + a->mUnk_20->mUnk_00->mUnk_04.x;
    a->mUnk_28.y = (d >> 4) + a->mUnk_20->mUnk_00->mUnk_04.y;
    a->mUnk_28.z = (e >> 4) + a->mUnk_20->mUnk_00->mUnk_04.z;
}

void *func_0208b498(u32 a, Vec3 *b, u32 c, s32 d) {
    s32 e;
    Vec3 w;
    Vec3 v;
    Unk0201ca6c *q;
    SPLManager *p = data_0217b050(&e, a);
    v.x = b->x >> 4;
    v.y = b->y >> 4;
    v.z = b->z >> 4;
    q = SPLManager_CreateEmitter(p, e, &v);
    if (q != NULL) {
        if (q->mUnk_20->mUnk_00->mUnk_54 & 0x80) {
            q->mUnk_80_16 = 1;
        } else if (q->mUnk_20->mUnk_00->mUnk_54 & 0x40) {
            q->mUnk_80_16 = 2;
        }
    }
    if (q != NULL) {
        w = GetKart(c)->mEffectVelocity;
        w.x = ((s64) w.x * d) >> 12;
        w.y = ((s64) w.y * d) >> 12;
        w.z = ((s64) w.z * d) >> 12;
        q->mUnk_40 = w;
    }
    return q;
}

u32 func_0208b484(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    value2 = (u32) &data_0217b044;
    *(u32 *) ((value0) + (0)) = value1;
    value0 = *(const u32 *) ((value2) + (0));
    return value0;
}
