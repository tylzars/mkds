#include "Main/Unknown/code_0210b870.h"

#include "Main/Unknown/code_02109054.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_0210bad4.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_0212bcac.h"

u32 func_0210bac0(void) {
    u32 counterAddress;
    u32 zero;
    counterAddress = (u32) &data_0217ccac;
    zero = 0u;
    *(u32 *) ((counterAddress) + (0)) = zero;
    return counterAddress;
}

void func_0210ba78(void *mapSound, s32 baseSoundId) {
    Kart *mapSoundCopy;
    s32 counter;

    mapSoundCopy = mapSound;
    counter = *(s32 *) data_0217ccac;
    StartSound(&mapSoundCopy->mSoundSource, baseSoundId + counter, (0x7f - (counter >> 1)) & 0xff, 0);
    *(u32 *) data_0217ccac = *(u32 *) (u32) data_0217ccac + 0xa;
}

void func_0210ba38(struct Unk020e71a0_94 *mapSound, s32 soundId) {
    AddSoundRequest(&data_0217d29c, mapSound->mSoundSource.mDistanceSquared + 0x15f90,
                    (void (*)(void *, int)) func_0210bad4, mapSound, soundId);
}

void func_0210b98c(struct Unk020e71a0_94 *mapSound, s32 soundId) {
    s32 distanceOffset;

    distanceOffset = 0;
    switch (soundId - 0x130) {
        case 0:
            distanceOffset = 0x640;
            break;
        case 1:
            distanceOffset = 0x1900;
            break;
        case 2:
            distanceOffset = 0x3840;
            break;
        case 8:
            distanceOffset = 0x6400;
            break;
        case 9:
            distanceOffset = 0xe100;
            break;
        case 3:
            distanceOffset = 0x9c40;
            break;
        case 7:
            distanceOffset = 0x19;
            break;
    }
    AddSoundRequest(&data_0217d29c, mapSound->mSoundSource.mDistanceSquared + distanceOffset, func_0210ba78, mapSound,
                    soundId);
}

void func_0210b924(void *position, s32 distanceSquared) {
    Unk0216ca48 requestCopy;
    Unk0216ca48 *request;

    request = &requestCopy;
    *request = data_0216ca48;
    request->mUnk_04 = position;
    request->mUnk_0c = distanceSquared;
    if (data_0217c780 & 1) {
        func_0210bf24(0, request->mUnk_00, (u32) request->mUnk_04, request);
    }
}

void func_0210b8f4(void *position, s32 distanceSquared) {
    AddSoundRequest(&data_0217d29c, distanceSquared, func_0210b924, position, distanceSquared);
}

int func_0210b8bc(void *soundSource, s32 fixedValue) {
    s32 clampedValue;

    clampedValue = fixedValue >> 12;
    if (clampedValue > 0x1e) {
        clampedValue = 0x1e;
    }
    return (s32) StartSound(soundSource, 0x1ce, ((clampedValue * 2) + 0x3c) & 0xff, clampedValue - 0xa);
}

void func_0210b874(struct Unk020e71a0_94 *mapSound, s32 fixedValue) {
    s32 pitchAndModSpeed;
    NNSSndSeqPlayer **handle;

    pitchAndModSpeed = (fixedValue >> 12) + 5;
    handle =
        (NNSSndSeqPlayer **) StartSoundWhileRequested(&mapSound->mSoundSource, 0x1cd, 0x7f, (s16) pitchAndModSpeed);
    if (handle != NULL) {
        NNS_SndPlayerSetTrackModSpeed(handle, 0xffff, pitchAndModSpeed);
    }
}

void func_0210b870(void) {}
