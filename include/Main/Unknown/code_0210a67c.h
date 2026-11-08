#pragma once

#include "types.h"

typedef struct Kart Kart;
typedef struct PlayingSound PlayingSound;

void SetKartPlayingSoundVolumePitch(Kart *kart, PlayingSound *playingSound, s32 pitchOffset);
void func_0210a77c(Kart *kart, PlayingSound *playingSound);
void UpdateKartPlayingSound(Kart *kart, PlayingSound *playingSound);
void func_0210a724(Kart *kart, PlayingSound *playingSound);
void func_0210a6ec(Kart *kart, PlayingSound *playingSound);
void func_0210a6b4(Kart *kart, PlayingSound *playingSound);
void func_0210a67c(Kart *kart, PlayingSound *playingSound);
