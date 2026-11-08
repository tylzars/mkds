#include "Main/Unknown/code_02024974.h"

#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02086058.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0210c1b0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_0210bafc.h"
#include "code_02147cd8.h"

u32 func_020250a8(void) {
    u32 quotient;
    u32 divisor;

    divisor = *(const u32 *) &data_02161ae4;
    quotient = FX_Div(0x1000, divisor);
    divisor = *(const u32 *) &data_02161ae0;
    data_02174e10 = quotient;
    quotient = FX_Div(0x1000, divisor);
    divisor = *(const u32 *) &data_02161adc;
    data_02174e0c = quotient;
    quotient = FX_Div(0x1000, divisor);
    data_02174e08 = quotient;
    return quotient;
}

void func_0202506c(Kart *kart, KartSound *soundRecord) {
    PlayingSound *playingSound;

    playingSound = StartSoundWhileRequested(&kart->mSoundSource, soundRecord->mUnk_00, soundRecord->mUnk_04,
                                            (soundRecord->mUnk_08 << 4) >> 16);
    if (playingSound != NULL) {
        playingSound->mFlags |= 0x80;
    }
}

void func_02025030(Kart *kart, KartSound *soundRecord) {
    PlayingSound *playingSound;

    playingSound = StartSoundWhileRequested(&kart->mSoundSource, soundRecord->mUnk_58, soundRecord->mUnk_04,
                                            (soundRecord->mUnk_08 << 4) >> 16);
    if (playingSound != NULL) {
        playingSound->mFlags |= 0x80;
    }
}

void func_02024fe8(Kart *kart, KartSound *soundRecord) {
    u32 soundId;

    soundId = GetSurfaceSoundId(3, kart->mSurfaceKind, kart->mSurfaceVariant);
    StartSoundWhileRequested(&kart->mSoundSource, soundId, soundRecord->mUnk_04, (soundRecord->mUnk_08 << 4) >> 16);
}

void func_02024fc0(Kart *kart, KartSound *soundRecord) {
    s32 clampedValue;

    clampedValue = soundRecord->mUnk_08;
    if (clampedValue > 0x440000) {
        clampedValue = 0x440000;
    }
    StartSoundWhileRequested(&kart->mSoundSource, soundRecord->mUnk_5c, soundRecord->mUnk_04,
                             (clampedValue << 4) >> 16);
}

s32 func_02024eec(KartSound *soundRecord, s32 b, s32 c) {
    s32 currentValue;
    s32 previousTarget;
    s32 step;
    s32 targetHighBits;
    s32 factor;

    currentValue = soundRecord->mUnk_08;
    previousTarget = soundRecord->mUnk_0c;
    step = soundRecord->mUnk_10;
    if (currentValue == -1) {
        b = 0;
        step = b;
        soundRecord->mUnk_0c = b;
    } else {
        targetHighBits = b & 0x7fff0000;
        if ((currentValue & 0x7fff0000) == targetHighBits) {
            soundRecord->mUnk_0c = b;
            step = 0;
        } else if ((previousTarget & 0x7fff0000) != targetHighBits) {
            soundRecord->mUnk_0c = b;
            if (b < currentValue) {
                factor = data_02174e0c;
            } else if (c != 0) {
                factor = data_02174e08;
            } else {
                factor = data_02174e10;
            }
            step = ((s64) factor * (b - currentValue) + 0x800) >> 12;
            b = step + currentValue;
        } else if (step != 0) {
            b = step + currentValue;
        }
    }
    if (b > 0x880000) {
        b = 0x880000;
    }
    if (b < 0) {
        b = 0;
    }
    soundRecord->mUnk_10 = step;
    return b;
}

void func_02024a88(Kart *kart) {
    KartSound *soundRecord;
    s32 f;
    s32 g;
    s32 h;
    s32 i;
    s32 baseSpeedLimit;
    s32 velocityLength;
    s32 aboveSpeedLimit;
    s32 kartFlags;

    soundRecord = (KartSound *) &kart->mUnk_450;
    kartFlags = kart->mUnk_48;
    f = (kartFlags & 2) != 0 ? 1 : 0;
    g = (kartFlags & 4) != 0 ? 1 : 0;
    if ((kart->mUnk_4c & 0x10000000) != 0) {
        soundRecord->mUnk_08 = 0x6c0000;
        soundRecord->mUnk_0c = 0x6c0000;
        soundRecord->mUnk_10 = 0;
        if (f != 0) {
            soundRecord->mUnk_00 = soundRecord->mUnk_60;
        } else {
            soundRecord->mUnk_00 = soundRecord->mUnk_50;
        }
        soundRecord->mUnk_14 = f;
        soundRecord->mUnk_04 = 0x46;
        StartSoundWhileRequested(&kart->mSoundSource, 0xfc, 0x7f, 0);
        return;
    }
    if ((s32) GetRaceUpdateFrames() < 5) {
        return;
    }
    if (gSceneSoundState.mRaceState == 0) {
        h = kart->mUnk_4d4;
        if (h > 0xcd && gRaceSetup->mCurrentEntries[kart->mIndex].mPlayer.mKind != PLAYER_KIND_CPU) {
            if (f != 0) {
                if ((kart->mUnk_4c & KART_4C_HEADING_SWING) != 0) {
                    i = 0;
                } else {
                    i = ((s64) h * 0x580000 + 0x800) >> 12;
                }
                g = func_02024eec((KartSound *) &kart->mUnk_450, i, 0);
                soundRecord->mUnk_04 = 0x7f;
                soundRecord->mUnk_00 = soundRecord->mUnk_44;
                AddSoundRequest(&data_0217d274, func_02086080(kart->mIndex), (void (*)(void *, int)) func_02024fc0,
                                kart, (s32) soundRecord);
            } else {
                i = ((s64) h * 0x480000 + 0x800) >> 12;
                g = func_02024eec((KartSound *) &kart->mUnk_450, i, 0);
                soundRecord->mUnk_04 = 0x46;
                soundRecord->mUnk_00 = soundRecord->mUnk_44;
                AddSoundRequest(&data_0217d274, func_02086080(kart->mIndex), (void (*)(void *, int)) func_02024fc0,
                                kart, (s32) soundRecord);
            }
        } else {
            soundRecord->mUnk_0c = 0;
            soundRecord->mUnk_10 = 0;
            soundRecord->mUnk_04 = 0x3c;
            AddSoundRequest(&data_0217d274, func_02086080(kart->mIndex), (void (*)(void *, int)) func_02025030, kart,
                            (s32) soundRecord);
            g = -1;
        }
        soundRecord->mUnk_08 = g;
        soundRecord->mUnk_14 = f;
        return;
    }
    baseSpeedLimit = kart->mPhysicalParam->mBaseSpeedLimit;
    velocityLength = kart->mVelocityLength;
    h = velocityLength - baseSpeedLimit;
    aboveSpeedLimit = h > 0 ? 1 : 0;
    if (g != 0 && kart->mForwardSpeed > 0 && (kart->mUnk_44 & KART_44_ON_GROUND) != 0) {
        g = ((s64) soundRecord->mUnk_24 * velocityLength + 0x800) >> 12;
        if (g > 0x280000) {
            g = 0x280000;
        }
        soundRecord->mUnk_04 = data_02153158[(kart->mVelocityLengthRatio >> 8) & 0xff];
        AddSoundRequest(&data_0217d274, func_02086080(kart->mIndex), (void (*)(void *, int)) func_02024fe8, kart,
                        (s32) soundRecord);
    } else if (f != 0 || (g != 0 && kart->mForwardSpeed < 0)) {
        if (aboveSpeedLimit != 0) {
            i = (s32) (((s64) h * soundRecord->mUnk_18 + 0x800) >> 12) + 0x580000;
        } else {
            i = ((s64) soundRecord->mUnk_1c * velocityLength + 0x800) >> 12;
        }
        g = func_02024eec((KartSound *) &kart->mUnk_450, i, aboveSpeedLimit);
        soundRecord->mUnk_04 = 0x7f;
        if (soundRecord->mUnk_14 == 0) {
            soundRecord->mUnk_00 = kart->mVelocityLengthRatio < 0x333 ? soundRecord->mUnk_64 : soundRecord->mUnk_60;
        }
        AddSoundRequest(&data_0217d274, func_02086080(kart->mIndex), (void (*)(void *, int)) func_0202506c, kart,
                        (s32) soundRecord);
    } else {
        if (aboveSpeedLimit != 0) {
            i = (s32) (((s64) h * soundRecord->mUnk_18 + 0x800) >> 12) + 0x480000;
        } else {
            i = ((s64) soundRecord->mUnk_20 * velocityLength + 0x800) >> 12;
        }
        g = func_02024eec((KartSound *) &kart->mUnk_450, i, aboveSpeedLimit);
        soundRecord->mUnk_04 = 0x32;
        if (kart->mVelocityLengthRatio < 0x19a) {
            soundRecord->mUnk_00 = soundRecord->mUnk_58;
        } else if (kart->mVelocityLengthRatio < 0x4cd) {
            soundRecord->mUnk_00 = soundRecord->mUnk_54;
        } else {
            soundRecord->mUnk_00 = soundRecord->mUnk_50;
        }
        AddSoundRequest(&data_0217d274, func_02086080(kart->mIndex), (void (*)(void *, int)) func_0202506c, kart,
                        (s32) soundRecord);
    }
    soundRecord->mUnk_08 = g;
    soundRecord->mUnk_14 = f;
}

void func_02024a28(SoundSource *soundSource, u16 soundId, s32 b, s32 c) {
    u8 t;
    u8 volume;

    if (c == 2) {
        t = (b << 7) >> 12;
        volume = t + 0x14;
        if (volume > 0x7f) {
            volume = 0x7f;
        } else if (volume < 0x32) {
            volume = 0x32;
        }
    } else {
        volume = 0x7f;
    }
    StartSoundEx(soundSource, 0, soundId, volume, 0);
}

void func_020249b8(Kart *kart, s32 b, s32 c) {
    s32 d;
    u8 volume;

    if (b <= 0) {
        return;
    }
    if (b >= 0x1000) {
        return;
    }
    d = (b << 14) >> 16;
    volume = (b << 7) >> 12;
    if (d > 0x400) {
        d = 0x400;
    }
    if (volume > 0x7f) {
        volume = 0x7f;
    }
    StartSoundWhileRequested(&kart->mSoundSource, c > 0 ? 0x150 : 0x151, volume, d);
}

s32 func_02024974(s32 a, s32 b, u32 c, u32 d) {
    s32 r;
    s32 t;

    r = b != 0 ? 4 : 0;
    if (a == 0) {
        if (c == d) {
            t = 0;
        } else if (c == d + 1) {
            t = 1;
        } else {
            t = 2;
        }
        r += t;
    } else {
        r += 3;
    }
    return r + 0x130;
}
