#include "Main/Unknown/code_0209f650.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0203c8c0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d8bc0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_0210bafc.h"
#include "Main/Unknown/code_0210f744.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_0209bf70.h"

u16 FX_Atan2Idx(s32 a, s32 b);

static inline u16 func_0209f800_inline(u32 n) {
    Unk020f41c4_B *b;
    u32 m;
    u32 r;

    if (n == 0x10000) {
        b = GetMapObjectRandom();
        b->mValue = b->mMultiplier * b->mValue + b->mIncrement;
        return ((b->mValue >> 32) * 0x10000) >> 32;
    } else {
        b = GetMapObjectRandom();
        m = (u16) n;
        if (m == 0) {
            r = 0;
        } else {
            b->mValue = b->mMultiplier * b->mValue + b->mIncrement;
            if (m == 0) {
                r = b->mValue >> 32;
            } else {
                r = ((b->mValue >> 32) * m) >> 32;
            }
        }
    }
    return r;
}

static inline void func_0209f6d8_inline(TownMonte *p) {
    p->mUnk_a4 += p->mUnk_a8;
    p->mUnk_a8 += 0x4000;
    if (p->mUnk_a4 == 0) {
        p->mUnk_a4 += p->mUnk_a8;
        p->mUnk_a8 += 0x4000;
    } else if (p->mUnk_a4 >= 0x16c000) {
        p->mUnk_a8 = 0x4000 - p->mUnk_a8;
        p->mUnk_ac = p->mUnk_ac == 0 ? 1 : 0;
    }
}

static inline void func_0209fdb4_inline(Airship *p) {
    s32 t;

    p->mUnk_a8 = (u16) p->mUnk_a8 + p->mUnk_c0;
    p->mUnk_b0 = p->mUnk_b4 + func_020a0028(p->mUnk_b8 / 2, 0x1000 - func_020a0044((u16) p->mUnk_a8)) - p->mUnk_ac;
    p->mUnk_ac += p->mUnk_b0;
    if (p->mUnk_b8 > 0) {
        t = p->mUnk_b8 + p->mUnk_bc;
        if (t <= 0) {
            t = 0;
        }
        p->mUnk_b8 = t;
    } else if (p->mUnk_b8 < 0) {
        t = p->mUnk_b8 + p->mUnk_bc;
        if (t >= 0) {
            t = 0;
        }
        p->mUnk_b8 = t;
    }
    if (p->mUnk_c0 > 0) {
        t = p->mUnk_c0 + p->mUnk_c4;
        if (t <= 0) {
            t = 0;
        }
        p->mUnk_c0 = t;
    } else if (p->mUnk_c0 < 0) {
        t = p->mUnk_c0 + p->mUnk_c4;
        if (t >= 0) {
            t = 0;
        }
        p->mUnk_c0 = t;
    }
}

static inline BOOL func_0209fdb4_inline_b(void) {
    s32 i;

    for (i = 0; i < gRaceSetup->mKartCount; i++) {
        if (GetKartHighestLap((u16) i) >= 2) {
            return TRUE;
        }
    }
    return FALSE;
}

void UpdateAirship(void *a, Airship *p) {
    switch (p->mState) {
        case 0:
            if (func_0209fdb4_inline_b() != FALSE) {
                p->mState = 1;
            }
            break;
        case 1:
            p->mUnk_a0 += 0x1000;
            if (p->mUnk_a0 >= 0) {
                p->mUnk_a0 = 0;
                p->mState = 2;
            }
            func_0209fdb4_inline(p);
            break;
        case 2:
            func_020d8cc8(&p->mUnk_c8);
            func_020d8bf8(&p->mUnk_c8, &p->mUnk_00.mPos, &p->mUnk_00.mUnk_10);
            func_0209fdb4_inline(p);
            break;
    }
    p->mUnk_00.mAngle = FX_Atan2Idx(p->mUnk_00.mUnk_10.x, p->mUnk_00.mUnk_10.z);
}

void *CreateAirshipDrawList(void) {
    return CreateMapObjectDrawList1(CreateAirship, DrawAirship, NULL);
}

void *CreateAirshipUpdateList(void) {
    return CreateMapObjectUpdateList(InitAirshipObjects, UpdateAirship, NULL);
}

void func_0209fc78(MapObject *p) {
    s32 i;

    i = p->mCourseMapRow->mUnk_28;
    if (data_usa_0217b18c[i] == NULL) {
        data_usa_0217b18c[i] = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
        *data_usa_0217b18c[i] = *data_usa_0217b18c[0];
    }
    switch (i) {
        case 0x10:
            data_usa_0217b18c[i]->mUnk_24 = 0x127;
            break;
        case 0x11:
            data_usa_0217b18c[i]->mUnk_24 = 0x100;
            break;
        case 0x12:
            data_usa_0217b18c[i]->mUnk_24 = 0x1da;
            break;
        default:
            data_usa_0217b18c[i]->mUnk_24 = func_0210bafc(0, 8, i);
            break;
    }
    p->mKindData = data_usa_0217b18c[i];
}

void func_0209fc38(void) {
    s32 i;

    for (i = 0; i < 19; i++) {
        data_usa_0217b18c[i] = NULL;
    }
    data_usa_0217b18c[0] = (MapObjectKindData *) CreateEmptyMapObjectKindData();
}

void func_0209fc2c(void) {
    func_020e6c0c();
}

void CreateTownMonte(MapObjectModel *a) {
    a->mShadowModel = (void *) func_0209fc2c;
    SetMapObjectModelPolygonId(gTownMonte = CreateMapObjectModelNsbmdNsbtp(a, gTownMonteNsbmdName, gTownMonteNsbtpName),
                               0x3f);
}

void DrawTownMonte(void *a, TownMonte *p) {
    s32 v;
    s32 d;
    MtxFx43 *h;

    d = (0x16c000 - p->mUnk_a4) >> 12;
    v = 0x1e;
    func_01ff9048(0x14, &v, 1);
    if (p->mUnk_ac != 0) {
        h = func_020e6c3c(&p->mUnk_00.mPos, -d, d);
        func_01ff9048(0x19, h, 0xc);
    } else {
        h = func_020e6c3c(&p->mUnk_00.mPos, d, d);
        func_01ff9048(0x19, h, 0xc);
    }
    func_01ff9048(0x1b, &p->mUnk_00.mScale, 3);
    SetMapObjectModelNsbtpFrameIndex(gTownMonte, p->mNsbtpFrameIndex);
    func_0209bbd0(a, gTownMonte);
    DrawMapObjectModel(a, gTownMonte, p);
}

void InitTownMonteObjects(Unk0209f800 *a) {
    TownMonte *p;
    Unk020f41c4_B *r;
    s32 i;
    s32 j;
    u32 n;
    u16 m;

    if (a == NULL) {
        return;
    }
    for (i = 0; i < a->mUnk_04 && (p = a->mUnk_00[i]) != NULL; i++) {
        p->mUnk_a4 = 0;
        p->mUnk_a8 = 0;
        n = GetMapObjectModelNsbtpFrameCount(gTownMonte);
        p->mNsbtpFrameIndex = func_0209f800_inline(n);
        r = GetMapObjectRandom();
        r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
        m = ((r->mValue >> 32) * 0x1a) >> 32;
        for (j = 0; j < m; j++) {
            func_0209f6d8_inline(p);
        }
        if (p->mUnk_00.mCourseMapRow->mUnk_28 != 0) {
            if (p->mNsbtpFrameIndex == 0) {
                p->mUnk_a2 = 0x1a7;
            } else if (p->mNsbtpFrameIndex == 1) {
                p->mUnk_a2 = 0x1a8;
            } else if (p->mNsbtpFrameIndex == 2) {
                r = GetMapObjectRandom();
                r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
                p->mUnk_a2 = (u16) (((r->mValue >> 32) * 2) >> 32) != 0 ? 0x1a7 : 0x1a8;
            }
        }
    }
}

void UpdateTownMonte(void *a, TownMonte *p) {
    Unk0210b7a8 s;
    s32 t;
    u16 w;

    func_0209f6d8_inline(p);
    if (p->mUnk_a2 == 0) {
        return;
    }
    if (p->mUnk_00.mCourseMapRow->mUnk_28 != GetSeqVariableSinceChangeFrames(0)) {
        return;
    }
    w = p->mUnk_a2;
    if (p->mUnk_00.mDistanceSquaredAndFlags & 4) {
        return;
    }
    if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
        t = 2;
    } else if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
        t = 3;
    } else {
        t = 4;
    }
    s.mUnk_00 = w;
    s.mUnk_04 = &p->mUnk_00.mPos;
    s.mUnk_08 = t;
    s.mUnk_0c = GetHorizontalCameraDistanceSquared(&p->mUnk_00.mPos);
    func_0210b7a8(&s);
}

void *CreateTownMonteDrawList(void) {
    return CreateMapObjectDrawList2(CreateTownMonte, DrawTownMonte, NULL);
}

void *CreateTownMonteUpdateList(void) {
    return CreateMapObjectUpdateList(InitTownMonteObjects, UpdateTownMonte, NULL);
}

void CreateChandelier(void *a) {
    CreateMapObjectModelNsbcaAnimation(gChandelier = CreateMapObjectModelAnimated(a, gChandelierNsbmdName),
                                       gChandelierNsbcaName);
    SetMapObjectModelPolygonId(gChandelier, 0x3f);
}
