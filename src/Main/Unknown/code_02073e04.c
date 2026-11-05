#include "Main/Unknown/code_02073e04.h"
#include "Main/Unknown/code_02039774.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_02147cd8.h"

u32 func_02073e88(void) {
    return (u32) gCameraEntryChanged;
}

// Distance of the point a along the forward axis of the current camera.
int GetCameraForwardDistance(u32 a) {
    Camera *v1;
    u8 v2[12];
    v1 = GetCurrentCamera();
    Vec3Sub((const Vec3 *) a, &v1->mPos, (Vec3 *) (v2));
    return func_02039828(&v1->mForward, (const Vec3 *) v2);
}

// Distance of the point a along mSide of the current camera, times mSideDistanceSign (-1 in mirror mode).
int GetCameraSideDistance(u32 a) {
    Camera *v1;
    int v2;
    u8 v3[12];
    v1 = GetCurrentCamera();
    Vec3Sub((const Vec3 *) a, &v1->mPos, (Vec3 *) (v3));
    v2 = ((u32) func_02039828(&v1->mSide, (const Vec3 *) v3));
    return v1->mSideDistanceSign * v2;
}
