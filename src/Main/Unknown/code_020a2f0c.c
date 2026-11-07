#include "Main/Unknown/code_020a2f0c.h"
#include "Main/Unknown/code_020d22c0.h"

// Takes the balloon off its kart and parks it.
void ParkBalloon(Balloon *balloon, u16 kartIndex) {
    balloon->mKartIndex = -1;
    balloon->mDrawCount = 1;
    balloon->mDrawList = NULL;
    ParkMapObject(&balloon->mUnk_00);
}
