#include "Main/Unknown/code_020917d0.h"
#include "Main/Unknown/code_02090354.h"

#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/unk_02156000.h"

void func_0209188c(Unk0209188c *p0) {
    p0->mUnk_02 = (((p0->mUnk_02)) | ((data_0215645c)));
}

u8 func_02091828(Sman *a, Kart *b, u8 *c, u8 *d) {
    u8 r;
    r = *d;
    if (*c == 1) {
        a->mTopHeight = 0xf333;
        a->mTopHeightPerFrame = 0x8000;
        a->mTopRiseProgress = 0;
        a->mBottomScale = 0;
        a->mUnk_00.mFlags = a->mUnk_00.mFlags | *(u16 *) &data_02156458;
        a->mState = 1;
        func_020d26f8(&a->mUnk_00, b);
    }
    return r;
}

u8 func_020917d0(Sman *a, u32 b, u8 *c, u8 *d) {
    u8 v1;
    v1 = *d;
    if (*c == 1) {
        a->mTopHeight = 0xf333;
        a->mTopHeightPerFrame = 0x8000;
        a->mTopRiseProgress = 0;
        a->mBottomScale = 0;
        a->mUnk_00.mFlags = a->mUnk_00.mFlags | *(u16 *) &data_02156458;
        a->mState = 1;
    }
    return v1;
}
