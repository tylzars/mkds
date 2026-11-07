#include "Main/Unknown/code_02081374.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0208b000.h"
#include "code_02147cd8.h"
#include "code_0201c528.h"
#include "Main/Unknown/code_02077bc0.h"

void SetKartKillerEffectShown(s32 kartIndex, s32 shown) {
    Unk0201ca6c *effect = gKartEffects[kartIndex].mKillerEffect;

    if (effect == NULL) {
        return;
    }
    effect->mUnk_24.mUnk_00_3 = (shown == 0);
}

void func_020813ec(s32 kartIndex, Vec3 *direction) {
    Vec3s16 directionHalfwords;
    Vec3 effectVelocity;
    Vec3 effectPos;
    Kart *kart = GetKart(kartIndex);
    KartEffects *kartEffects = &gKartEffects[kartIndex];
    Unk0201ca6c *effect;

    if ((kart->mUnk_4c & 0x8000) && kartEffects->mUnk_28 == NULL && kart->mVelocityLength > 0x1000) {
        effect = StartEffect(0x53, kart->mPosSource);
        effect->mUnk_94 = kart;
        effect->mUnk_90 = func_02081374;
        kartEffects->mUnk_28 = effect;
    }
    if (kartEffects->mUnk_28 == NULL) {
        return;
    }
    effectVelocity.x = ((s64) kart->mEffectVelocity.x * 0xccd) >> 12;
    effectVelocity.y = ((s64) kart->mEffectVelocity.y * 0xccd) >> 12;
    effectVelocity.z = ((s64) kart->mEffectVelocity.z * 0xccd) >> 12;
    kartEffects->mUnk_28->mUnk_40 = effectVelocity;
    VEC_MultAdd(-kart->mRadius, direction, kart->mPosSource, &effectPos);
    func_0208b5b0(kartEffects->mUnk_28, &effectPos);
    directionHalfwords.x = direction->x;
    directionHalfwords.y = direction->y;
    directionHalfwords.z = direction->z;
    kartEffects->mUnk_28->mUnk_50 = directionHalfwords;
    kart->mUnk_48 |= 0x400;
}

void func_02081374(Unk0201ca6c *effect, s32 a) {
    Kart *kart;
    KartEffects *kartEffects;

    if (a != 0) {
        return;
    }
    kart = effect->mUnk_94;
    if ((kart->mUnk_48 & 0x400) && (kart->mUnk_44 & 0x80)) {
        if (kart->mVelocityLength >= 0x1333) {
            return;
        }
    }
    kartEffects = &gKartEffects[kart->mIndex];
    if (effect == kartEffects->mUnk_28) {
        effect->mUnk_24.mUnk_00_0 = 1;
        kartEffects->mUnk_28 = NULL;
    }
}
