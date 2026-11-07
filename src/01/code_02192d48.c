#include "01/code_02192d48.h"

#include "01/code_02192000.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "01/code_02193000.h"
#include "01/unk_021a9000.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_02146cbc.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "ITCM/code_01ff8000.h"

Unk0219b250 *gStopSign;

void InitStopSign(Unk02188950 *a) {
    s32 m[9];
    func_020d2450(a);
    a->mUnk_000.mAngle = (a->mUnk_000.mCourseMapRow->mUnk_0c.y * 0xb60b60b60bLL + 0x80000000000LL) >> 44;
    MTX_RotY33_(m, gPairsByAngle[(a->mUnk_000.mAngle >> 4) * 2], gPairsByAngle[(a->mUnk_000.mAngle >> 4) * 2 + 1]);
    MTX_Concat33(m, &a->mUnk_000.mMatrix.mUnk_00[0].x, &a->mUnk_000.mMatrix.mUnk_00[0].x);
}

void LoadStopSign(Unk0219b478 *a) {
    gStopSign = LoadMapObjectModelAnimated(a, "StopSign.nsbmd");
    SetMapObjectModelPolygonId(gStopSign, 0x3f);
    func_0209ba08(gStopSign, 2);
    func_020849a0(gStopSign->mAnimatedModel, 0x294a);
}

void DrawStopSign(void *a, StopSignObject *b) {
    s32 v = 0x1e;
    func_01ff9048(0x14, &v, 1);
    b->mUnk_4c = b->mUnk_04 >> 4;
    b->mUnk_50 = b->mUnk_08 >> 4;
    b->mUnk_54 = b->mUnk_0c >> 4;
    func_01ff9048(0x19, b->mUnk_28, 0xc);
    func_01ff9048(0x1b, b->mUnk_1c, 3);
    DrawMapObjectModel(a, gStopSign, b);
}

void func_ov001_02192d60(void) {
    CreateMapObjectKindData(NULL, NULL, NULL, 0, 1);
}

void *func_ov001_02192d48(void) {
    return CreateMapObjectDrawList1(LoadStopSign, DrawStopSign, NULL);
}
