#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

void SetMapObjectScale(MapObject *d, Vec3 *e);
void func_020d2950(MapObject *b, s32 c);
// Allocates the sound source object of the map object (mUnk_94, 0x44 bytes) with volume curve 2
// (SoundSource.mFalloffIndex) and copies the curve's mUnk_20 into mUnk_70. Then it calls SetSoundSourceEnabled and,
// when bit 0 of the source's mUnk_34 is set, SetSoundSourceFlagBit.
void CreateMapObjectSoundSourceFalloff2(MapObject *a);
Unk0210b7ec *func_020d286c(MapObject *a);
// Allocates the sound source object of the map object (mUnk_94, 0x44 bytes) with volume curve 3
// (SoundSource.mFalloffIndex) and copies the curve's mUnk_20 into mUnk_70. Then it calls SetSoundSourceEnabled and,
// when bit 0 of the source's mUnk_34 is set, SetSoundSourceFlagBit.
void CreateMapObjectSoundSourceFalloff3(MapObject *a);
// Allocates the sound source object of the map object (mUnk_94, 0x44 bytes) with volume curve 4
// (SoundSource.mFalloffIndex) and copies the curve's mUnk_20 into mUnk_70. Then it calls SetSoundSourceEnabled and,
// when bit 0 of the source's mUnk_34 is set, SetSoundSourceFlagBit.
void CreateMapObjectSoundSourceFalloff4(MapObject *a);
