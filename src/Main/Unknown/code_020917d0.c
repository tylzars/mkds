#include "Main/Unknown/code_020917d0.h"
#include "Main/Unknown/code_02090354.h"

#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/unk_02156000.h"

void func_0209188c(Unk0209188c *mapObject) {
    mapObject->mUnk_02 = (((mapObject->mUnk_02)) | ((data_0215645c)));
}

u8 func_02091828(Sman *sman, Kart *kart, u8 *c, u8 *d) {
    u8 r;
    r = *d;
    if (*c == 1) {
        sman->mTopHeight = 0xf333;
        sman->mTopHeightPerFrame = 0x8000;
        sman->mTopRiseProgress = 0;
        sman->mBottomScale = 0;
        sman->mMapObject.mFlags = sman->mMapObject.mFlags | *(u16 *) &data_02156458;
        sman->mState = 1;
        StartSoundIfKartStarOrKiller(&sman->mMapObject, kart);
    }
    return r;
}

u8 func_020917d0(Sman *sman, u32 b, u8 *c, u8 *d) {
    u8 v1;
    v1 = *d;
    if (*c == 1) {
        sman->mTopHeight = 0xf333;
        sman->mTopHeightPerFrame = 0x8000;
        sman->mTopRiseProgress = 0;
        sman->mBottomScale = 0;
        sman->mMapObject.mFlags = sman->mMapObject.mFlags | *(u16 *) &data_02156458;
        sman->mState = 1;
    }
    return v1;
}
