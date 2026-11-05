#include "01/code_02185b64.h"

#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "01/callees_0219b000.h"
#include "01/code_02185ef4.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_0209b000.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d2dec.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_02146000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "ITCM/code_01ff8000.h"

Unk0219b250 *gMissionGate;

void InitMissionGate(MissionGateObject *a) {
    s32 mtx[9];
    s32 r4;
    s32 r6;
    s16 saved;

    func_020d2450(a);
    a->mUnk_000.mAngle = (s32) (((s64) a->mUnk_000.mCourseMapRow->mUnk_0c.y * 0xB60B60B60BLL + 0x80000000000LL) >> 44);
    Matrix3x3FromPairY(mtx, gPairsByAngle[(a->mUnk_000.mAngle >> 4) * 2],
                       gPairsByAngle[(a->mUnk_000.mAngle >> 4) * 2 + 1]);
    Matrix3x3Multiply(mtx, &a->mUnk_000.mMatrix.mUnk_00[0].x, &a->mUnk_000.mMatrix.mUnk_00[0].x);
    r4 = (s32) (((s64) a->mUnk_000.mScale.x * 0xA000LL) >> 12);
    r6 = (s32) (((s64) a->mUnk_000.mScale.y * 0xF000LL) >> 12);
    saved = a->mUnk_000.mCourseMapRow->mUnk_28;
    a->mUnk_000.mCourseMapRow->mUnk_28 = 0x12;
    a->mUnk_0a0 = CreateMapObjectFromObject(&a->mUnk_000, 0x66);
    a->mUnk_0a4 = CreateMapObjectFromObject(&a->mUnk_000, 0x66);
    a->mUnk_000.mCourseMapRow->mUnk_28 = saved;
    Vec3AddScaled(-(a->mUnk_000.mUnk_58.x + r4), &a->mUnk_000.mMatrix.mUnk_00[0], &a->mUnk_000.mPos,
                  &a->mUnk_0a0->mPos);
    Vec3AddScaled(a->mUnk_000.mUnk_58.x + r4, &a->mUnk_000.mMatrix.mUnk_00[0], &a->mUnk_000.mPos, &a->mUnk_0a4->mPos);
    func_020d2950(a->mUnk_0a0, r4);
    func_020d2950(a->mUnk_0a4, r4);
    func_020d2584(a->mUnk_0a0, r6);
    func_020d2584(a->mUnk_0a4, r6);
}

u32 func_ov001_02185d74(MissionGateObject *c, Unk02185d74 *d, u8 *e, u8 *f) {
    u32 a = *e;
    u32 b = *f;

    if ((d->mUnk_48 & 0x200) != 0 || (data_021759c0->mMode == 4 ? func_020a1084(d->mUnk_74) : 0) != FALSE) {
        return 0;
    }
    if (a == 1) {
        c->mUnk_000.mFlags |= data_ov001_021a6580;
        c->mState = 2;
    }
    return b;
}

void LoadMissionGate(void *a) {
    gMissionGate = LoadMapObjectModelAnimated(a, "MissionGate.nsbmd");
    LoadMapObjectModelNsbtpAnimation(gMissionGate, "MissionGate.nsbtp");
    LoadMapObjectModelNsbmaAnimation(gMissionGate, "MissionGate.nsbma");
    SetMapObjectModelPolygonId(gMissionGate, 0x3f);
    func_0209ba08(gMissionGate, 2);
    func_020849a0(gMissionGate->mAnimatedModel, 0x294a);
}

void func_ov001_02185d18(void) {}

void DrawMissionGate(void *a, MissionGateObject *b) {
    s32 buf;

    buf = 0x1e;
    func_01ff9048((u32) (0x14), (void *) ((u32) &buf), 1);
    b->mUnk_000.mMatrix.mUnk_00[3].x = b->mUnk_000.mPos.x >> 4;
    b->mUnk_000.mMatrix.mUnk_00[3].y = b->mUnk_000.mPos.y >> 4;
    b->mUnk_000.mMatrix.mUnk_00[3].z = b->mUnk_000.mPos.z >> 4;
    func_01ff9048((u32) (0x19), (void *) ((u32) &b->mUnk_000.mMatrix), 0xc);
    func_01ff9048((u32) (0x1b), (void *) ((u32) &b->mUnk_000.mScale), 3);
    func_0209b688((void *) (gMissionGate), (u16) b->mUnk_000.mCourseMapRow->mUnk_28);
    SetMapObjectModelNsbmaFrameIndex(gMissionGate, b->mUnk_0a8);
    DrawMapObjectModel(a, gMissionGate, b);
}

void func_ov001_02185c4c(Unk02185c4c *a) {
    s32 i;
    MissionGateObject *e;

    if (a) {
        for (i = 0; i < a->mUnk_04 && (e = a->mUnk_00[i]) != NULL; i++) {
            if (e->mUnk_000.mCourseMapRow->mUnk_28 != 0) {
                e->mUnk_000.mFlags |= data_ov001_021a6580;
                e->mState = 0;
            } else {
                e->mUnk_000.mFlags &= ~1;
                e->mState = 1;
            }
        }
    }
}

void UpdateMissionGate(void *a, MissionGateObject *b) {
    s32 pos;

    switch (b->mState) {
        case 0:
            pos = data_021759c0->mMode == 4 ? func_ov001_02181820() : 0;
            if (pos >= b->mUnk_000.mCourseMapRow->mUnk_28 - 1) {
                b->mUnk_000.mFlags &= ~1;
                b->mState = 1;
            }
            break;
        case 2:
            pos = GetMapObjectModelNsbmaFrameCount(gMissionGate);
            b->mUnk_0a8++;
            if (b->mUnk_0a8 >= pos - 1) {
                b->mUnk_0a8 = GetMapObjectModelNsbmaFrameCount(gMissionGate) - 1;
                b->mState = 1;
            }
            break;
    }
}

void func_ov001_02185b98(void) {
    func_0209bfa8(&func_ov001_02185d74, NULL, NULL, (u32) (0), (u16) (1));
    return;
}

void func_ov001_02185b7c(void) {
    func_0209bf1c(LoadMissionGate, DrawMissionGate, func_ov001_02185d18);
}

void func_ov001_02185b64(void) {
    func_0209bf48(func_ov001_02185c4c, UpdateMissionGate, NULL);
}
