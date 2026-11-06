#pragma once

#include "types.h"
#include "code_0212bcac.h"
#include "code_0212d214.h"

// Sound source: the object a sound is started on. Kart, ItemObject and the object behind MapObject.mUnk_94 embed it as
// their first member. It holds the list of the sounds started on it, the pointer to the position the distance to the
// camera is measured to, and the number of its volume curve. A sound is started on it only while bit 0 of its mUnk_34
// member is set; InitSoundSource clears that bit. data_0217d048 is addressed in rows of twelve bytes; func_0210bfbc and
// func_0210c0bc address the container of one of those rows. Kart and the gItemPools elements (ItemObject) start with
// it: StartSoundWhileRequested and StartSound pass either one to StartSoundWhileRequestedEx and StartSoundEx.
// InitSoundSource writes the byte at 0x3c and the word at 0x40.
typedef struct SoundSource {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[8];
    // The sounds started on this source, as a list of PlayingSound entries.
    /* 0c */ NNSFndList mPlayingSounds;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u8 mUnk_1c[0xc];
    // Pointer to the owner's position (declared u32); the distance and the direction to the camera are measured to it.
    // Without one (0) a sound gets full volume and no direction.
    /* 28 */ u32 mOwnerPosSource;
    /* 2c */ void (*mUnk_2c)(void *a, void *b, u32 c);
    /* 30 */ void (*mUnk_30)(void *a, void *b, void *c);
    /* 34 */ u16 mUnk_34;
    /* 36 */ u8 mUnk_36[2];
    /* 38 */ u32 mUnk_38;
    // Number of the volume curve (element of gSoundFalloffs) of this source.
    /* 3c */ u8 mFalloffIndex;
    /* 3d */ u8 mUnk_3d[3];
    // Squared distance from the camera to the owner of the sound source. For a Kart it is the three-axis one, for map
    // and item objects the horizontal one with the low 5 and top 2 bits cleared; InitSoundSource stores 0xffffffff. The
    // sound pass takes its square root.
    /* 40 */ u32 mDistanceSquared;
} SoundSource;

// One sound started on a SoundSource, from the start request until it is stopped. The entries are taken from a pool of
// twelve and linked into the list of the source. The mUnk_00 member is the library player handle, NULL until the player
// is started. Returned by func_0210e128 and passed to func_0210bcf4; func_0210c084 writes its byte at 0x19.
// func_0210bf24 subtracts one NNSFndList from mUnk_10 to reach the SoundSource holding it.
typedef struct PlayingSound {
    /* 00 */ Unk0212c400 *mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ NNSFndList *mUnk_10;
    /* 14 */ s16 mUnk_14;
    // Number of the sound this entry plays.
    /* 16 */ u16 mSoundId;
    /* 18 */ u8 mUnk_18;
    /* 19 */ u8 mUnk_19;
    // Volume the sound was started with, 0 to 0x7f; the library turns it into a track volume through a table of 128
    // entries.
    /* 1a */ u8 mVolume;
} PlayingSound;

// Object at 0x20 of Unk0210bcf4: words at 0x08 and 0x0c.
typedef struct Unk0210bcf4_20 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
} Unk0210bcf4_20;

// Held on the stack by func_0210bcf4 and func_0210ca4c and passed to the three functions
// data_0217d018, data_0217d014 and data_0217d01c point at.
typedef struct Unk0210bcf4 {
    /* 00 */ SoundSource *mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ Unk0210bcf4_20 *mUnk_20;
} Unk0210bcf4;

u32 func_0210bcf4(u32 a, u32 b, u32 c, u32 d, u32 e);
u32 func_0210bee8(u32 a, u32 b, u32 c, u32 d, u32 e);
void func_0210bf24(u32 a, u32 b, u32 c, u32 d);
void func_0210bfbc(SoundSource *p);
void func_0210c084(PlayingSound *p, u32 b);
void func_0210c0bc(SoundSource *p);
void func_0210c134(SoundSource *a, u32 b);
