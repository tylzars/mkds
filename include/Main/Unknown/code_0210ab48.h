#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"

// Object behind gKartSoundQueue: eight objects, a value for each of them, eight words, then four words.
typedef struct KartSoundQueue {
    /* 00 */ Kart *mKarts[8];
    /* 20 */ s32 mUnk_20[8];
    /* 40 */ u32 mFramesSinceStart[8];
    /* 60 */ s32 mCount;
    /* 64 */ BOOL mDisabled;
    /* 68 */ s32 mVolume;
    /* 6c */ s32 mDelayFrames;
} KartSoundQueue;

extern KartSoundQueue gKartSoundQueue;

void func_0210b4e0(Kart *a, s32 b, s32 c, s32 d);
void StartKartSurfaceSoundWhileRequested(Kart *a, s32 b, s32 c, s32 d, u32 e);
void func_0210b234(Kart *a, s32 b, s32 c, s32 d, s32 f);
void func_0210b198(s32 a, s32 b, u32 c, s32 d, s32 e);
void StartKartCollisionSound(Kart *a, s32 b, s16 d);
void func_0210af40(Kart *a, s32 b, s32 c);
void InitKartSoundQueue(void);
void UpdateKartSoundQueue(void);
void QueueKartSound(Kart *a, s32 b);
void StartQueuedKartSound(Kart *a, s32 b, s32 c, s32 d);
void func_0210ab48(s32 a, s32 b);
