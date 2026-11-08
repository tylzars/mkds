#include "Main/Unknown/code_020646f0.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "ITCM/code_01ffdee4.h"
#include "Main/Unknown/code_02040de0.h"
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
#include "Main/Unknown/code_020ed5c0.h"
#include "code_02147cd8.h"

void func_020646f0(Kart *kart, s32 b) {
    MtxFx43 *rotationMatrix;
    CourseMap *courseMap;
    Vec3 startRotation;
    Vec3 e;
    Vec3 f;
    Vec3 g;
    Vec3 h;
    KartModelAnimationView *characterAnimation;
    s16 j;
    s16 k;
    s16 l;
    Vec3 *n;

    if (b == 0) {
        GetCourseMapKartStartPlacement(&kart->mPos, &startRotation, kart->mIndex);
        if (gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
            kart->mPos = data_0216549c[kart->mIndex];
        }
    } else {
        courseMap = gCourseMap;
        if (courseMap->mUnk_3c != NULL) {
            n = &kart->mPos;
            if (n != NULL) {
                *n = courseMap->mUnk_3c->mUnk_00;
            }
            startRotation = courseMap->mUnk_3c->mUnk_0c;
        }
    }
    if ((kart->mUnk_7c & 0x600) != 0) {
        j = kart->mPos.x >> 10;
        k = kart->mPos.y >> 10;
        l = kart->mPos.z >> 10;
        kart->mPos.x = j << 10;
        kart->mPos.y = k << 10;
        kart->mPos.z = l << 10;
    }
    g = kart->mPos;
    g.y = g.y + 0x1000;
    kart->mPos.y = kart->mPos.y - 0x1400;
    if (func_01ffdee4(&kart->mPos, (u32 *) &g, &kart->mTurnedForward, 0x5000, 1, -2, &e, &f, NULL, NULL, NULL, NULL,
                      NULL, NULL) != 0) {
        h.x = (s64) f.x * 0x5000 >> 12;
        h.y = (s64) f.y * 0x5000 >> 12;
        h.z = (s64) f.z * 0x5000 >> 12;
        VEC_Subtract(&e, &h, &e);
        VEC_Add(&kart->mPos, &e, &kart->mPos);
    }
    kart->mPos.y = kart->mPos.y - 0x1000;
    kart->mHeadingAngle = (u32) (startRotation.y * 0xb6) >> 12;
    QuaternionFromAxisAngle(&data_02154a3c, kart->mHeadingAngle, &kart->mUnk_e0_m);
    kart->mUnk_110_q = kart->mUnk_e0_m;
    Matrix4x3FromQuaternion(&kart->mUnk_120, &kart->mUnk_110_q);
    kart->mUnk_150_m = kart->mUnk_120_m;
    kart->mPrevPos = kart->mPos;
    kart->mDrawMatrixPos = kart->mPrevPos;
    kart->mUnk_174.x = kart->mDrawMatrixPos.x;
    kart->mUnk_174.y = kart->mDrawMatrixPos.y;
    kart->mUnk_174.z = kart->mDrawMatrixPos.z;
    rotationMatrix = &kart->mUnk_120_m;
    kart->mForward.x = rotationMatrix->mUnk_00[2].x;
    kart->mForward.y = rotationMatrix->mUnk_00[2].y;
    kart->mForward.z = rotationMatrix->mUnk_00[2].z;
    kart->mTurnedForward = kart->mForward;
    kart->mDrawMatrix = &kart->mUnk_150_m;
    characterAnimation = kart->mKartModelsEntry->mCharacterAnimation;
    if (characterAnimation == NULL) {
        return;
    }
    if (characterAnimation->mUnk_18 != 0) {
        characterAnimation->mUnk_0c = kart->mKartModelsEntry->mMiddleFrame;
    }
}
