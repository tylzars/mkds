#include "ITCM/code_01ffb930.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/unk_02165000.h"

void func_01ffb9e0(Kart *p) {
    if ((p->mUnk_44 & 0x400) || p->mState != KART_STATE_NORMAL) {
        p->mForwardSpeed = (s64) p->mForwardSpeed * p->mPhysicalParam->mUnk_2c >> 12;
    }
    if (!(p->mUnk_48 & 0x2000)) {
        return;
    }
    p->mForwardSpeed = (s64) p->mForwardSpeed * 0xe66 >> 12;
}

void ApplyKartGravity(Kart *p) {
    p->mVerticalSpeed = p->mVerticalSpeed + p->mGravity;
}

void func_01ffb930(s32 *a, Kart *p) {
    s32 b;
    u32 f;
    s32 c;

    if (p->mState != KART_STATE_NORMAL) {
        return;
    }
    f = p->mUnk_44;
    if (f & KART_44_DRIFTING) {
        return;
    }
    if (!(f & KART_44_ON_GROUND)) {
        return;
    }
    if (*a <= 0x3000) {
        return;
    }
    b = p->mUnk_2d4;
    if (b <= 0) {
        b = -b;
    }
    c = (s64) *a * data_usa_021654d8 >> 12;
    *a -= (s32) ((s64) c * b >> 12);
}
