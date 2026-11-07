#pragma once

#include "types.h"

typedef struct SoundSource SoundSource;
typedef struct PlayingSound PlayingSound;

// Starts sound a at volume b on the sound source p and returns its PlayingSound. A sound of the same id already on the
// source is stopped first. Returns NULL when bit 0 of data_0217c780 is clear, when the mUnk_10 member of data_0217d084
// is 0 or when the source is not enabled (bit 0 of its mUnk_34 member). The fourth parameter is stored in the mUnk_14
// member of the entry.
PlayingSound *StartSound(SoundSource *p, u32 a, u32 b, s16 c);
// Starts sound a on the source p and keeps it only while it is started again between two runs of the expiry step of
// func_0210cc3c, which UpdateSoundSources runs after UpdateRace has set data_0217d020. A sound already started this way
// on the source is refreshed with the new volume. Returns the PlayingSound, NULL under the conditions of StartSound.
PlayingSound *StartSoundWhileRequested(SoundSource *p, u32 a, u32 b, s32 c);
// Stops the first started sound with id a on the source p without a fade. A sound the library has not started yet is
// not stopped.
void StopSound(SoundSource *p, u32 a);
void func_02109054(SoundSource *p);
