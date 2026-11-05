#pragma once

#include "types.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/unk_0217b000.h"

// Two words (the elements at member 0xc of Unk0217b498).
typedef Unk0217b498_0c UnkPair020b502c;

// Object returned by func_020b57e4.
typedef struct {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ u8 mUnk_0c[4];
    /* 10 */ s32 mUnk_10;
} Unk020b57e4;

// One entry of the table at CourseMap::mEntryGroups.
typedef struct CourseMapEntryGroup {
    /* 00 */ u8 mUnk_00[1];
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mEntryCount;
} CourseMapEntryGroup;

// The one 0x28-byte record behind CourseMap::mSettings: per-course values read by unrelated consumers: fog
// (mFogEnabled, mFogTableMode, mFogOffset; the fog colour and the shift stay unnamed), four colours (mColors), a
// halfword that is the lap count outside mode 2 and the battle time in seconds in mode 2, start and limit values. Role
// word Settings is weak: a record of per-course parameters, no single consumer.
typedef struct CourseMapSettings {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04;
    /* 05 */ u8 mFogEnabled;
    // 0, 1 or 2: which of three formulas fills the 32-entry table (8 words) loaded to 0x04000360 (next to
    // reg_G3X_FOG_COLOR and reg_G3X_FOG_OFFSET); other values leave it unfilled.
    /* 06 */ u8 mFogTableMode;
    /* 07 */ u8 mUnk_07;
    /* 08 */ u8 mUnk_08[8];
    // Divided by 512 it is the offset written to reg_G3X_FOG_OFFSET (scaled by the fade factor while fading).
    /* 10 */ s32 mFogOffset;
    /* 14 */ s32 mUnk_14;
    // Four 15-bit colours (5-5-5); one is picked by the lowest set bit of a 4-bit mask from the kart flags and blended
    // into a kart model entry.
    /* 18 */ u16 mColors[4];
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
} CourseMapSettings;

// 0x48-byte entries of the table at CourseMap::mShapes (GetCourseMapShape returns one).
typedef struct CourseMapShape {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ Vec3 mUnk_18;
    /* 24 */ Vec3 mUnk_24;
    /* 30 */ Vec3 mUnk_30;
    /* 3c */ u16 mUnk_3c;
    /* 3e */ s16 mUnk_3e;
    /* 40 */ s16 mUnk_40;
    /* 42 */ u8 mShapeKind;
    /* 43 */ u8 mUnk_43;
    /* 44 */ u8 mKind;
    /* 45 */ u8 mUnk_45[3];
} CourseMapShape;

// 0x18-byte entries of the table at CourseMap::mUnk_84 (func_020a0f0c returns one).
typedef struct {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ u8 mUnk_10[8];
} Unk02175620_84;

// 0x30-byte entries of the table at CourseMap::mUnk_bc (func_02080908 searches it).
typedef struct Unk02175620_bc {
    /* 00 */ struct Unk02175620_bc *mUnk_00[3];
    /* 0c */ struct Unk02175620_bc *mUnk_0c;
    /* 10 */ u8 mUnk_10[8];
    /* 18 */ Vec3 *mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ Vec3 *mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s16 *mUnk_28;
    /* 2c */ u16 mUnk_2c;
    /* 2e */ u8 mUnk_2e;
    /* 2f */ u8 mUnk_2f;
} Unk02175620_bc;

struct CourseMapRow;

// 0x1c-byte records: position at 0x00, rotation angles in degrees at 0x0c, node index at 0x18, key halfword at 0x1a.
// Used by CourseMap::mStartPlacements (record chosen by key, GetCourseMapStartPlacementWithOffsets) and by
// CourseMap::mUnk_34 (looked up by key through mUnk_fc; func_020705fc puts a kart at one in modes 2 and 4). The name
// only says where a kart is put.
typedef struct CourseMapPlacement {
    /* 00 */ Vec3 mPos;
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ s16 mUnk_18;
    /* 1a */ u16 mUnk_1a;
} CourseMapPlacement;

// 0x20-byte entries of CourseMap::mRespawns, read through mRespawnIndexBySlot: position at 0x00, rotation angles in
// degrees at 0x0c, node index at 0x18, index into the table CourseMap::mUnk_ac at 0x1a, slot at 0x1c. Where a kart is
// put back after it falls (kart y < 0) or is flagged by the surface; the slot comes from the checkpoint the kart is in
// (mRespawnSlot) or, in mode 2, from a counter. Role word Respawn is not spelled in the tree; read from the callers
// (weak).
typedef struct CourseMapRespawn {
    /* 00 */ Vec3 mPos;
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ u16 mUnk_18;
    /* 1a */ u16 mUnk_1a;
    // Key of the record in mRespawnIndexBySlot (built in the loader; unused in mode 2).
    /* 1c */ s16 mSlot;
    /* 1e */ u8 mUnk_1e[2];
} CourseMapRespawn;

// The same two words as UnkPair020b502c.
typedef Unk0217b498_0c Unk02040d24;

// 0x24-byte entries of CourseMap::mCheckpoints: a gate across the course: two x/z end points (0x00..0x0c), a 2-D
// direction at 0x10, a word at 0x18 that is summed along the routes (func_02043078), neighbour links at 0x1c and 0x1e,
// mNumber, mRespawnSlot, a flag byte at 0x23. The race progress code tests the kart's x/z against these lines, keeps
// the entry the kart is in and counts a lap when it reaches entry 0 after all numbered ones. Role word Checkpoint is
// not spelled in the tree.
typedef struct CourseMapCheckpoint {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ Unk02040d24 mUnk_10;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s16 mUnk_1c;
    /* 1e */ s16 mUnk_1e;
    // Sequence number of the numbered checkpoints (-1 = none): the kart's counter advances only to the next number.
    /* 20 */ s16 mNumber;
    /* 22 */ u8 mRespawnSlot;
    /* 23 */ u8 mUnk_23;
} CourseMapCheckpoint;

// 0x0c-byte run of consecutive entries of a table: first entry, count, up to three forward links at 0x04 and three back
// links at 0x07 to other runs, stage index at 0x0a. Used by CourseMap::mCheckpointRoutes (the entries are checkpoints)
// and by mUnk_5c and mUnk_6c (the entries are nodes of two other tables, built by func_02042ec0 and func_02042d34).
// Route is weak: a run with branches; not a tree word.
typedef struct CourseMapRoute {
    /* 00 */ u16 mFirstEntry;
    /* 02 */ u16 mEntryCount;
    /* 04 */ u8 mUnk_04[3];
    /* 07 */ u8 mUnk_07;
    /* 08 */ u8 mUnk_08[2];
    /* 0a */ u8 mUnk_0a;
    /* 0b */ u8 mUnk_0b;
} CourseMapRoute;

// 0x14-byte entries of the table at CourseMap::mUnk_54.
typedef struct {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ s32 mUnk_0c;
    /* 10 */ u8 mUnk_10;
    /* 11 */ u8 mUnk_11[3];
} Unk02175620_54;

// 0x10-byte entries of the same table (used while CourseMap::mVersion is below 0x21).
typedef struct {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ s32 mUnk_0c;
} Unk02175620_54_10;

// 0x4c-byte entries of the table at CourseMap::mUnk_7c.
typedef CourseMapCamera Unk02175620_7c;

// 0x14-byte entries of the table at CourseMap::mUnk_8c.
typedef struct {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[8];
    /* 0c */ u8 mUnk_0c[8];
} Unk02175620_8c;

// 8-byte entries of the table at CourseMap::mUnk_94.
typedef struct {
    /* 00 */ CourseMapEntryGroup *mUnk_00;
    /* 04 */ void *mUnk_04;
} Unk02175620_94;

// 0x28-byte nodes of the table at CourseMap::mUnk_a0: two lists of node pointers.
typedef struct Unk02175620_a0 {
    /* 00 */ struct Unk02175620_a0 *mUnk_00[3];
    /* 0c */ struct Unk02175620_a0 *mUnk_0c[3];
    /* 18 */ Unk02175620_84 *mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ u8 *mUnk_20;
    /* 24 */ u16 mUnk_24;
    /* 26 */ u16 mUnk_26;
} Unk02175620_a0;

// Node of the lists at CourseMap::mKind3ShapeLists: an entry of the table at mShapes and the next node.
typedef struct Unk02175620_d8 {
    /* 00 */ CourseMapShape *mUnk_00;
    /* 04 */ struct Unk02175620_d8 *mUnk_04;
} Unk02175620_d8;

// Object behind the word at 0x3c of the object behind gCourseMap: two vectors and the halfword at 0x1a.
typedef struct Unk02175620_3c {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ u8 mUnk_18[2];
    /* 1a */ s16 mUnk_1a;
} Unk02175620_3c;

// Object behind gCourseMap.
typedef struct CourseMap {
    /* 00 */ struct CourseMapRow *mRows;
    /* 04 */ u16 mRowCount;
    /* 06 */ u8 mUnk_06[2];
    /* 08 */ CourseMapEntryGroup *mEntryGroups;
    /* 0c */ u16 mEntryGroupCount;
    /* 00e */ u8 mUnk_00e[0x2];
    /* 010 */ s32 mGroupEntries;
    /* 014 */ u16 mGroupEntryCount;
    /* 016 */ u8 mUnk_016[0x2];
    /* 018 */ CourseMapSettings *mSettings;
    /* 01c */ CourseMapPlacement *mStartPlacements;
    // Count of records of mStartPlacements; four of the five reads only test > 1 (several start spots: battle) or <= 1.
    /* 020 */ u16 mStartPlacementCount;
    /* 022 */ u8 mUnk_022[0x2];
    /* 024 */ CourseMapRespawn *mRespawns;
    /* 028 */ u16 mRespawnCount;
    /* 02a */ u8 mUnk_02a[0x2];
    /* 2c */ Unk020b57e4 *mUnk_2c;
    /* 30 */ u16 mUnk_30;
    /* 32 */ u8 mUnk_32[0x2];
    /* 34 */ CourseMapPlacement *mUnk_34;
    /* 38 */ u16 mUnk_38;
    /* 3a */ u8 mUnk_3a[0x2];
    /* 3c */ Unk02175620_3c *mUnk_3c;
    /* 40 */ u16 mUnk_40;
    /* 42 */ u8 mUnk_42[0x2];
    /* 44 */ CourseMapCheckpoint *mCheckpoints;
    /* 48 */ u16 mCheckpointCount;
    /* 4a */ u8 mUnk_4a[0x2];
    /* 4c */ CourseMapRoute *mCheckpointRoutes;
    /* 50 */ u16 mCheckpointRouteCount;
    /* 52 */ u8 mUnk_52[0x2];
    /* 54 */ Unk02175620_54 *mUnk_54;
    /* 58 */ u16 mUnk_58;
    /* 5a */ u8 mUnk_5a[0x2];
    /* 5c */ CourseMapRoute *mUnk_5c;
    /* 60 */ u16 mUnk_60;
    /* 62 */ u8 mUnk_62[0x2];
    /* 64 */ Unk02175620_84 *mUnk_64;
    /* 68 */ u16 mUnk_68;
    /* 6a */ u8 mUnk_6a[0x2];
    /* 6c */ CourseMapRoute *mUnk_6c;
    /* 70 */ u16 mUnk_70;
    /* 72 */ u8 mUnk_72[0x2];
    /* 74 */ CourseMapShape *mShapes;
    /* 78 */ u16 mShapeCount;
    /* 7a */ u8 mUnk_7a[0x2];
    /* 7c */ Unk02175620_7c *mUnk_7c;
    /* 80 */ u16 mUnk_80;
    /* 82 */ u8 mUnk_82[0x2];
    /* 84 */ Unk02175620_84 *mUnk_84;
    /* 88 */ u16 mUnk_88;
    /* 8a */ u8 mUnk_8a[2];
    /* 8c */ Unk02175620_8c *mUnk_8c;
    /* 90 */ u16 mUnk_90;
    /* 92 */ u8 mUnk_92[2];
    /* 94 */ Unk02175620_94 *mUnk_94;
    /* 98 */ u16 mNumberedCheckpointCount;
    // Last entry of the run that comes just before entry 0: first entry + count - 1 of the run named by the first back
    // link of the run that starts at entry 0 (0 when there are no runs). Karts start on it; going back over the line
    // from entry 0 onto it takes a lap off. With branches only the first back link is followed.
    /* 9a */ u16 mLastCheckpoint;
    /* 9c */ u16 mUnk_9c;
    /* 9e */ u8 mUnk_9e[2];
    /* a0 */ Unk02175620_a0 *mUnk_a0;
    /* a4 */ Unk02175620_bc *mUnk_a4;
    /* a8 */ s32 mUnk_a8;
    /* ac */ struct Unk020f371c *mUnk_ac;
    /* b0 */ s32 mUnk_b0;
    /* b4 */ s32 mUnk_b4;
    /* b8 */ Unk02175620_bc *mUnk_b8;
    /* bc */ Unk02175620_bc *mUnk_bc;
    /* c0 */ Unk02175620_bc *mUnk_c0;
    /* c4 */ Unk02175620_7c *mUnk_c4;
    /* c8 */ Unk02175620_7c *mUnk_c8;
    /* cc */ Unk02175620_7c *mUnk_cc;
    /* d0 */ Unk02175620_7c *mUnk_d0;
    /* d4 */ Unk02175620_7c *mUnk_d4;
    /* d8 */ struct Unk02175620_d8 *mKind3ShapeLists[8];
    /* f8 */ u16 *mRespawnIndexBySlot;
    /* fc */ u16 *mUnk_fc;
    // Mode 2 only: the slot GetCourseMapRespawnSlot hands out next; counts up modulo mRespawnCount.
    /* 100 */ u16 mNextRespawnSlot;
    /* 102 */ u16 mKind4ShapeCount;
    /* 104 */ u32 mUnk_104;
    /* 108 */ s32 mUnk_108;
    // Format version from the file header halfword at 4; 0x1f adds the mUnk_34 section, 0x21 makes the mUnk_54 entries
    // 0x14 bytes, 0x24 adds the mUnk_3c section.
    /* 10c */ u16 mVersion;
    /* 10e */ u8 mUnk_10e;
    /* 10f */ u8 mKind2ShapeCountInMode4;
} CourseMap;

// Eight words.
typedef struct {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
} Unk020b503c;

// Object behind data_0217b3c0.
typedef struct {
    /* 00 */ UnkPair020b502c mUnk_00;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ UnkPair020b502c mUnk_10;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s16 mUnk_1c;
    /* 1e */ s16 mUnk_1e;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ UnkPair020b502c mUnk_2c;
    /* 34 */ UnkPair020b502c mUnk_34;
    /* 3c */ s64 mUnk_3c;
    /* 44 */ s64 mUnk_44;
    /* 4c */ UnkPair020b502c mUnk_4c;
    /* 54 */ UnkPair020b502c mUnk_54;
    /* 5c */ s64 mUnk_5c;
    /* 64 */ s64 mUnk_64;
    /* 6c */ UnkPair020b502c mUnk_6c;
    /* 74 */ UnkPair020b502c mUnk_74;
    /* 7c */ s64 mUnk_7c;
    /* 84 */ s64 mUnk_84;
    /* 8c */ s32 mUnk_8c;
    /* 90 */ Vec3 mUnk_90;
} Unk0217b3c0;

extern CourseMap *gCourseMap;

#include "Main/Unknown/unk_02175628.h"

extern Unk0217b3c0 *data_0217b3c0;

extern u16 func_020435bc(void);
s32 func_020b502c(s32 a, s32 b);
void func_020b503c(Unk020b503c *p, s32 scale);
s32 func_020b523c(void);
s32 func_020b5250(s32 x);
s32 func_020b5258(s32 x);
s32 func_020b5270(s32 x);
void func_020b5290(void);
u16 func_020b5628(s32 idx, s32 mask);
u16 func_020b5644(Unk02175628 *p, s32 mask);
void func_020b5658(Unk020b503c *out);
s32 func_020b57b4(s32 a, s64 k);
Unk020b57e4 *func_020b57e4(void);
void func_020b57f8(Unk020b503c *out);
void func_020b58f8(Unk020b503c *out);
BOOL func_020b5ae8(const Vec3 *pos, UnkPair020b502c *out, s32 unk, s32 flag, s32 flag2);
void func_020b5dcc(s32 idx, UnkPair020b502c *out, s32);
BOOL func_020b5f68(const UnkPair020b502c *p);
void func_020b5fe4(const Vec3 *pos, UnkPair020b502c *out);
void func_020b6078(s32 idx, UnkPair020b502c *out);
u16 func_020b6338(s32 idx);
u16 func_020b6368(void);
s32 func_020b6430(void);
s32 func_020b64e8(void);
u32 func_020b65dc(void);
