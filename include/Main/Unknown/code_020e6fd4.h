#pragma once

#include "types.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_020e005c.h" // Unk020e005c_080
#include "Main/Unknown/code_0210b000.h" // Unk0210b7ec

struct MapObject;
struct CourseMapRow;

// Object behind MapObject.mUnk_94, passed to func_0210cfbc (which reads its halfword at 0x34).
typedef struct Unk020e71a0_94 {
    // Sound source of the map object (the sounds started on it).
    /* 00 */ SoundSource mSoundSource;
    /* 44 */ Unk0210b7ec mUnk_44;
    /* 54 */ u8 mUnk_54[0xc];
} Unk020e71a0_94;

// Object behind MapObject.mKindData, built once per Unk021000d0 (row->mUnk_04): kinds whose rows point at the same
// record share it (e.g. kinds 0x01/0x03/0x06/0x09/0x0c; 0x05/0x0e/0x0f). AddMapObjectToUpdateList copies its 0x04 into
// the callback slot at 0x1c of a Unk020e6fd4 and its 0x20 into the word at 0x18; func_020d6968 reads 0x20 and
// func_020f944c reads 0x28.
typedef struct MapObjectKindData {
    /* 00 */ s32 (*mUnk_00)(struct MapObject *e, void *a, s32 *b, s32 *c);
    /* 04 */ s32 (*mUnk_04)(struct MapObject *e, void *a, void *b, void *c);
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 (*mUnk_18)(struct MapObject *a, Vec3 *b, s32 c, Vec3 *d);
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
    /* 3c */ s32 mUnk_3c;
} MapObjectKindData;

// Element object up to 0xa0, which every kind shares: func_020e705c and func_020e71a0 read 0x78 and 0x94 of every
// object, func_020d6968 reads 0x00, 0x02 and 0x98. InitKuribo and InitDram pass the Unk020e005c_080 at 0x80 to
// func_02046be8.
// From 0xa0 on, the objects of func_020e72cc (Unk020e730c), InitDram (Dram), func_020ff97c (Unk020ff97c)
// and func_021052fc (Unk021052fc) use the bytes in different ways.
typedef struct MapObject {
    /* 00 */ u16 mKind;
    /* 02 */ u16 mFlags;
    /* 04 */ Vec3 mPos;
    /* 10 */ Vec3 mUnk_10;
    /* 1c */ Vec3 mScale;
    /* 28 */ MtxFx43 mMatrix;
    // Size of the collision shape along the object's local axes: the kind's size times mScale (a few kinds set a
    // component directly). x is the radius given to the collision slot, and the Vec3 length is the bounding radius.
    /* 58 */ Vec3 mExtent;
    // Index of the object's entry in the table of collision shapes (0x100 entries of position, radius, mask and
    // object), or -1 when its kind record word at 0x08 is 0 or the table was full. func_020e4ea8 also reads its lowest
    // bit as a mirror flag for the model.
    /* 64 */ s16 mCollisionSlotIndex;
    // Alpha of the object, 0 to 0x1f. The visibility pass lowers it by 1 per call while mDistanceSquaredAndFlags bit 0
    // is set and raises it by 1 up to 0x1f otherwise (func_020d4698 sets 0 or 0x1f at once); the draw group skips the
    // object at 0, the view test counts 1 or less as not drawn, and the model draw lowers the model's polygon alpha to
    // it.
    /* 66 */ u16 mAlpha;
    // Radius of the sphere that the view test checks against the view planes and adds to mDrawDistance: the kind's
    // value times the largest of mScale x, y, z (two kinds use their own factor).
    /* 68 */ s32 mViewRadius;
    // Horizontal distance from the camera, plus mViewRadius, beyond which the view test sets mDistanceSquaredAndFlags
    // bit 0 (the object fades out). The kind's value, capped by the course settings, and 0x270f000 when the game
    // record's mUnk_00c is 3.
    /* 6c */ s32 mDrawDistance;
    // Squared horizontal distance from the camera beyond which the view test sets mDistanceSquaredAndFlags bit 2.
    // Copied from the word at 0x20 of a volume curve of gSoundFalloffs (curve 2 at creation); the kinds compare it with
    // the words of curves 2 and 3 to find which curve they use.
    /* 70 */ s32 mFarDistanceSquared;
    // Mask of the non-zero decimal digits of the course row's number (bit d is digit d; a number of 10000 or more first
    // sets flag 0x80 in mFlags), or copied from the source object. The visibility pass and the kinds that test it treat
    // the object as out of view while a bit is shared with the word func_0207a780 returns.
    /* 74 */ u32 mDigitMask;
    // Result of the last view test of the object plus bits added by kinds. Bit 0: beyond mDrawDistance; bit 1: outside
    // the view planes (set with bit 0 when mAlpha is 1 or less); bit 2: beyond mFarDistanceSquared (func_020e71a0 also
    // sets it); bit 3: set when the object was tested in this pass; bit 4: set by kinds and kept by the test. Bits 5 to
    // 29: the squared horizontal distance to the camera in whole units (read with the mask 0x3fffffe0; a far constant
    // while mDigitMask is shared). Bit 30 is set by kinds and makes func_020d2668 skip the kind's sound; bit 31 is set
    // by kinds and cleared by ItemObject code, which passes the object on as the one hit.
    /* 78 */ u32 mDistanceSquaredAndFlags;
    // Non-zero when the view test of the object uses only two view planes (func_01ffd648) instead of five
    // (func_01ffd778). Copied from the kind's data at creation.
    /* 7c */ u16 mUseTwoPlaneViewTest;
    /* 7e */ u16 mAngle;
    // State machine of the kind: the table of state handlers, its size and the owner, with the current state, the next
    // state and the frames spent in the state.
    /* 80 */ Unk020e005c_080 mStateMachine;
    // The sound object of the map object, tested against NULL before use: a SoundSource at 0 (so the pointer also
    // serves as the source) and, in the 0x60-byte variant, an Unk0210b7ec behind it.
    /* 94 */ Unk020e71a0_94 *mSound;
    /* 98 */ MapObjectKindData *mKindData;
    /* 9c */ struct CourseMapRow *mCourseMapRow;
} MapObject;

// Object of func_020e72cc and func_020e730c: two u16s after the shared part.
typedef struct Unk020e730c {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ u16 mUnk_a0;
    /* a2 */ u16 mUnk_a2;
} Unk020e730c;

// Container of MapObject objects: the pointer array at 0x00 and its count at 0x04; func_020e6fd4 calls 0x1c for
// each object, func_020e705c calls 0x10, AddMapObjectToUpdateList adds an object, func_020e6fc4 and func_020e6fcc
// change the count.
typedef struct Unk020e6fd4 {
    /* 00 */ void **mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[2];
    /* 08 */ void (*mUnk_08)(struct Unk020e6fd4 *p);
    /* 0c */ void (*mUnk_0c)(struct Unk020e6fd4 *p);
    /* 10 */ UnkFunc *mUnk_10;
    /* 14 */ void (*mUnk_14)(struct Unk020e6fd4 *p);
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 (*mUnk_1c)(MapObject *e, void *a, void *b, void *c);
    /* 20 */ s32 mUnk_20;
    /* 24 */ void **mUnk_24;
} Unk020e6fd4;

typedef struct Unk020e6488 Unk020e6488;
typedef struct Unk020e6fd4 Unk020e6fd4;
typedef struct Unk0210b7a8 Unk0210b7a8;

// 0x40-byte block that func_020e7410 takes from data_02159370.
typedef struct Unk020e7410 {
    /* 00 */ u32 mUnk_00[0x10];
} Unk020e7410;

// Source rows read by the second loop of func_020e7460, 0x0c bytes each; a
// row's non-zero words are names looked up by FindSceneFile.
typedef struct Unk0216c324 {
    /* 00 */ const char *mUnk_00;
    /* 04 */ const char *mUnk_04;
    /* 08 */ const char *mUnk_08;
} Unk0216c324;

// 0x10-byte rows of the table at data_0217bae8: the second loop of func_020e7460
// writes three objects allocated through HeapAlloc into the rows from
// data_0217bb08 on, and the word at 0x0c of the first two rows receives the
// object func_020e6488 creates. func_020e9810 reads the words at 0x0c through
// data_0217baf4.
typedef struct Unk0217bb08 {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ Unk020e6488 *mUnk_0c;
} Unk0217bb08;

extern Unk0216c324 data_0216c324[];
// Filled in by func_020e7760; func_020e84b0 stores func_020d4ef4's return value
// at 0x0c and hands it to func_0210b760.
extern Unk0210b7a8 data_0217b9dc;
extern Unk0217bb08 data_0217bae8[];
extern Unk0217bb08 data_0217baf4[];
extern Unk0217bb08 data_0217bb08[];

void func_020e6fd4(Unk020e6fd4 *p);
void func_020e705c(Unk020e6fd4 *p);
void func_020e71a0(MapObject *p);
void func_020e72cc(Unk020e730c *p, struct CourseMapRow *q);
void func_020e730c(void);
u16 func_020e7388(int arg0);
Unk020e6fd4 *func_020e73b4(void);
Unk020e7410 *func_020e7410(void);
void func_020e7460(void);
void func_020e7760(void);
void func_020e79c4(void);
void func_020e7a18(void);
void func_020e7a40(void);
