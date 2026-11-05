#pragma once

#include "types.h"
#include "Main/Unknown/code_020e5d0c.h" // Unk020e6488
#include "Main/Unknown/code_020ea670.h" // Unk020ea670
#include "Main/Unknown/code_02087d0c.h" // Unk02087d0c

// The draw group (Unk020e6fd4), not the bundle: the creators' first argument; they store 1 or 2 at 0x18.
typedef struct Unk0209bc74_a {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ s32 mUnk_18;
} Unk0209bc74_a;

// Three words written to the start of the objects of CreateMapObjectModelNsbmdNsbtp, CreateMapObjectModelNsbmd,
// CreateMapObjectModelShadow and CreateMapObjectModelAnimated.
typedef struct Unk0209bc74_00 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
} Unk0209bc74_00;

// Object at 0x14 of MapObjectModel (0x74 bytes): two halfwords at 0x6c and 0x6e.
typedef struct Unk0209bc74_14 {
    /* 00 */ u8 mUnk_00[0x6c];
    /* 6c */ u16 mUnk_6c;
    /* 6e */ u16 mUnk_6e;
} Unk0209bc74_14;

// The model bundle of one map object kind: one per kind (the global g<Stem> that Create<Stem> stores), shared by every
// object of the kind; 0x2c bytes, the allocation size. A creator builds exactly one of mNsbmdModel / mAnimatedModel /
// mShadowModel and leaves the others 0; the draw tests each. Overlay 1 reaches the same bytes through Unk0219b250.
typedef struct MapObjectModel {
    // Three words (1.0 = 0x1000 each) sent to the geometry engine as the scale command (0x1b) by every draw; only the
    // mirror setter changes them (it flips the sign of x and y).
    /* 00 */ Unk0209bc74_00 mScale;
    // Unk020e6488 built from an .nsbmd (and an optional .nsbtp) by CreateMapObjectModelNsbmd / NsbmdNsbtp; 0 in the
    // other bundles. The other models are built from an .nsbmd too.
    /* 0c */ Unk020e6488 *mNsbmdModel;
    // The 0x6c model instance of CreateMapObjectModelAnimated; the animation objects attach to this model. A bundle
    // made this way may attach none (NsKiller1, Berry, Cream).
    /* 10 */ Unk020ea670 *mAnimatedModel;
    // The 0x74 shadow model object (the type the kart, killer item and jg shadows use) built from an .nsbmd shadow file
    // by CreateMapObjectModelShadow; Unk02188950.mShadowNsbmd points at a bundle that holds one.
    /* 14 */ Unk0209bc74_14 *mShadowModel;
    // The .nsbmd file as FindCourseMapObjFile returned it (pointer into the archive), used by the animation creators;
    // 0 unless the Animated creator ran (overlay 1: the file LoadMissionRunFile read).
    /* 18 */ void *mNsbmdFile;
    // Slot table of the 0x38-byte animation objects: 0 .nsbca, 1 .nsbtp, 2 .nsbma, 3 .nsbta; filled by the
    // Create...Animation functions (slot 2 only by overlay 1, never in a main-code bundle).
    /* 1c */ Unk02087d0c *mAnimations[4];
} MapObjectModel;

extern Unk0209bc74_00 data_021565a0;
extern Unk0209bc74_00 data_021565ac;
extern Unk0209bc74_00 data_021565b8;
extern Unk0209bc74_00 data_021565c4;
