#pragma once

#include "types.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/unk_0217b000.h"

// Two words (the elements at member 0xc of RaceHudSubScreenCells).
typedef Unk0217b498_0c UnkPair020b502c;

// Object returned by func_020b57e4.
typedef struct {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ u8 mUnk_0c[4];
    /* 10 */ s32 mUnk_10;
} Unk020b57e4;

// One entry of the table at CourseMap.mEntryGroups.
typedef struct CourseMapEntryGroup {
    /* 00 */ u8 mUnk_00[1];
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mEntryCount;
} CourseMapEntryGroup;

// The one 0x28-byte record behind CourseMap.mSettings: per-course values read by unrelated consumers: fog
// (mFogEnabled, mFogTableMode, mFogOffset; the fog colour and the shift stay unnamed), four colours (mColors), a
// halfword that is the lap count outside mode 2 and the battle time in seconds in mode 2, start and limit values.
typedef struct CourseMapSettings {
    /* 00 */ u8 mUnk_00[2];
    // Lap count; in battle mode the same halfword is the time limit in seconds (times 60 frames into
    // RaceProgress.mTimeLimitFrameCount when Unk021759c0.mUnk_18 is 1).
    /* 02 */ u16 mLapCountOrBattleSeconds;
    /* 04 */ u8 mUnk_04;
    /* 05 */ u8 mFogEnabled;
    // 0, 1 or 2: which of three formulas fills the 32-entry table (8 words) loaded to 0x04000360 (next to
    // reg_G3X_FOG_COLOR and reg_G3X_FOG_OFFSET); other values leave it unfilled.
    /* 06 */ u8 mFogTableMode;
    /* 07 */ u8 mUnk_07;
    /* 08 */ u8 mUnk_08[8];
    // Divided by 512 it is the offset written to reg_G3X_FOG_OFFSET (scaled by the fade factor while fading).
    /* 10 */ s32 mFogOffset;
    // Bits 0 to 14: the course colour, used as the fog colour and as colour 0 of the main screen palette in the race
    // HUD set-up; bits 15 to 19: the fog alpha (the race code writes both to the fog colour register as colour | alpha
    // << 16).
    /* 14 */ s32 mColorAndFogAlpha;
    // Four 15-bit colours (5-5-5); one is picked by the lowest set bit of a 4-bit mask from the kart flags and blended
    // into a kart model entry.
    /* 18 */ u16 mColors[4];
    // Upper limit for the mDrawDistance of every map object (func_020d24d8); 0 means no limit; not applied when
    // Unk021759c0.mUnk_00c is 3.
    /* 20 */ s32 mMapObjectDrawDistanceMax;
    // Far plane distance of the cameras of this course; SetupCamera copies it to Camera.mFar and uses 0x640000 when it
    // is below 0x1000.
    /* 24 */ s32 mCameraFar;
} CourseMapSettings;

// 0x48-byte entries of the table at CourseMap.mShapes (GetCourseMapShape returns one).
typedef struct CourseMapShape {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ Vec3 mUnk_18;
    /* 24 */ Vec3 mUnk_24;
    /* 30 */ Vec3 mUnk_30;
    /* 3c */ u16 mUnk_3c;
    /* 3e */ s16 mUnk_3e;
    // For a shape of mKind 4: index of the point link that belongs to it, in CourseMap.mRacePointLinks (races) or
    // CourseMap.mBattlePointLinks (battles).
    /* 40 */ s16 mPointIndex;
    /* 42 */ u8 mShapeKind;
    // For a shape of mKind 1: index into CourseMap.mCameras of the camera entry used while a kart is inside the shape
    // (the only reader is GetCourseMapCameraIndexAtPos).
    /* 43 */ u8 mCameraIndex;
    /* 44 */ u8 mKind;
    /* 45 */ u8 mUnk_45[3];
} CourseMapShape;

// 0x18-byte entries of the table at CourseMap.mBattlePoints and mRacePoints (MoveToRandomForwardBattlePoint returns
// one).
typedef struct {
    /* 00 */ Vec3 mPos;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s16 mUnk_10[4];
} Unk02175620_84;

// 0x30-byte entries of the table at CourseMap.mUnk_bc (func_02080908 searches it).
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
// Used by CourseMap.mStartPlacements (record chosen by key, GetCourseMapStartPlacementWithOffsets) and by
// CourseMap.mKeyedPlacements (looked up by key through mKeyedPlacementIndexByKey; func_020705fc puts a kart at one in
// modes 2 and 4). The name only says where a kart is put.
typedef struct CourseMapPlacement {
    /* 00 */ Vec3 mPos;
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ s16 mUnk_18;
    // Key that selects the record: in mStartPlacements the caller of GetCourseMapStartPlacementWithOffsets compares it
    // with its key argument (several start placements), in mKeyedPlacements it is the position of the record in
    // mKeyedPlacementIndexByKey.
    /* 1a */ u16 mKey;
} CourseMapPlacement;

// 0x20-byte entries of CourseMap.mRespawns, read through mRespawnIndexBySlot: position at 0x00, rotation angles in
// degrees at 0x0c, node index at 0x18, index into the table CourseMap.mItemPointLinks at 0x1a, slot at 0x1c. Where a
// kart is put back after it falls (kart y < 0) or is flagged by the surface; the slot comes from the checkpoint the
// kart is in (mRespawnSlot) or, in mode 2, from a counter. Role word Respawn is not spelled in the tree; read from the
// callers.
typedef struct CourseMapRespawn {
    /* 00 */ Vec3 mPos;
    /* 0c */ Vec3 mUnk_0c;
    // Index of the point link of this respawn spot, in CourseMap.mRacePointLinks (races) or CourseMap.mBattlePointLinks
    // (battles); the respawn getters return it as a pointer.
    /* 18 */ u16 mPointIndex;
    // Index of the item point link of this respawn spot in CourseMap.mItemPointLinks (races; -1 in battle files, which
    // have no item points).
    /* 1a */ u16 mItemPointIndex;
    // Key of the record in mRespawnIndexBySlot (built in the loader; unused in mode 2).
    /* 1c */ s16 mSlot;
    /* 1e */ u8 mUnk_1e[2];
} CourseMapRespawn;

// The same two words as UnkPair020b502c.
typedef Unk0217b498_0c Unk02040d24;

// 0x24-byte entries of CourseMap.mCheckpoints: a gate across the course: two x/z end points (0x00..0x0c), a 2-D
// direction at 0x10, a word at 0x18 that is summed along the routes (func_02043078), neighbour links at 0x1c and 0x1e,
// mNumber, mRespawnSlot, a flag byte at 0x23. The race progress code tests the kart's x/z against these lines, keeps
// the entry the kart is in and counts a lap when it reaches entry 0 after all numbered ones. Role word Checkpoint is
// not spelled in the tree.
typedef struct CourseMapCheckpoint {
    // X of end point A of the checkpoint line (the two ends are A and B in the order of the file words; the position
    // tests compare a kart with the lines through consecutive A ends and consecutive B ends).
    /* 00 */ s32 mPointAX;
    // Z of end point A of the checkpoint line (the two ends are A and B in the order of the file words; the position
    // tests compare a kart with the lines through consecutive A ends and consecutive B ends).
    /* 04 */ s32 mPointAZ;
    // X of end point B of the checkpoint line (the two ends are A and B in the order of the file words; the position
    // tests compare a kart with the lines through consecutive A ends and consecutive B ends).
    /* 08 */ s32 mPointBX;
    // Z of end point B of the checkpoint line (the two ends are A and B in the order of the file words; the position
    // tests compare a kart with the lines through consecutive A ends and consecutive B ends).
    /* 0c */ s32 mPointBZ;
    // X and z of the direction the course runs through this checkpoint (scale 0x1000): the lap progress measures along
    // it, and a kart whose forward vector has a dot product with it below -1394 gets the 0x4 bit of
    // RaceProgressKart.mFlags (facing against the checkpoint).
    /* 10 */ Unk02040d24 mDirection;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s16 mUnk_1c;
    /* 1e */ s16 mUnk_1e;
    // Sequence number of the numbered checkpoints (-1 = none): the kart's counter advances only to the next number.
    /* 20 */ s16 mNumber;
    /* 22 */ u8 mRespawnSlot;
    /* 23 */ u8 mUnk_23;
} CourseMapCheckpoint;

// 0x0c-byte run of consecutive entries of a table: first entry, count, up to three forward links at 0x04 and three back
// links at 0x07 to other runs, stage index at 0x0a. Used by CourseMap.mCheckpointRoutes (the entries are checkpoints)
// and by mItemRoutes and mRaceRoutes (the entries are nodes of two other tables, built by BuildCourseMapItemRouteLinks
// and BuildCourseMapRaceRouteLinks).
typedef struct CourseMapRoute {
    /* 00 */ u16 mFirstEntry;
    /* 02 */ u16 mEntryCount;
    // Numbers of up to three routes that follow this route (255 = none); the last route of a lap names route 0.
    /* 04 */ u8 mNextRoutes[3];
    // Numbers of up to three routes that come before this route (255 = none).
    /* 07 */ u8 mPreviousRoutes[3];
    // Number of this route along the lap, counting routes that branch from the same point as one step (0 for the
    // first); added to the position inside the route and scaled by RaceProgress.mLapProgressScale.
    /* 0a */ u8 mLapProgressBase;
    /* 0b */ u8 mUnk_0b;
} CourseMapRoute;

// 0x14-byte entries of the table at CourseMap.mItemPoints.
typedef struct {
    /* 00 */ Vec3 mPos;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ u8 mUnk_10;
    /* 11 */ u8 mUnk_11[3];
} Unk02175620_54;

// 0x10-byte entries of the same table (used while CourseMap.mVersion is below 0x21).
typedef struct {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ s32 mUnk_0c;
} Unk02175620_54_10;

// 0x4c-byte entries of the table at CourseMap.mCameras.
typedef CourseMapCamera Unk02175620_7c;

// 0x14-byte entries of the table at CourseMap.mBattleRoutes.
typedef struct {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[8];
    /* 0c */ u8 mUnk_0c[8];
} Unk02175620_8c;

// 8-byte entries of the table at CourseMap.mEntryGroupTable.
typedef struct {
    /* 00 */ CourseMapEntryGroup *mGroup;
    /* 04 */ Unk02042044 *mEntries;
} Unk02175620_94;

// 0x28-byte nodes of the table at CourseMap.mRacePointLinks: two lists of node pointers.
typedef struct Unk02175620_a0 {
    /* 00 */ struct Unk02175620_a0 *mUnk_00[3];
    /* 0c */ struct Unk02175620_a0 *mUnk_0c[3];
    /* 18 */ Unk02175620_84 *mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s16 *mUnk_20;
    /* 24 */ u16 mUnk_24;
    /* 26 */ u16 mUnk_26;
} Unk02175620_a0;

// Node of the lists at CourseMap.mKind3ShapeLists: an entry of the table at mShapes and the next node.
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
    /* 010 */ Unk02042044 *mGroupEntries;
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
    // Records (position, rotation angles, battle point index, key) where the kart code puts or flies a kart to, found
    // by key through mKeyedPlacementIndexByKey; loaded from format version 0x1f on, empty in older files.
    /* 34 */ CourseMapPlacement *mKeyedPlacements;
    // Number of mKeyedPlacements.
    /* 38 */ u16 mKeyedPlacementCount;
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
    // Item point records (0x14 bytes, 0x10 before format version 0x21): a position and values; mItemPointLinks is built
    // from them.
    /* 54 */ Unk02175620_54 *mItemPoints;
    // Number of mItemPoints, and of mItemPointLinks.
    /* 58 */ u16 mItemPointCount;
    /* 5a */ u8 mUnk_5a[0x2];
    // Item routes: runs of consecutive item points (first point, count, up to three next and three previous routes).
    /* 5c */ CourseMapRoute *mItemRoutes;
    // Number of mItemRoutes; when it is not 0 CreateCourseMap builds mItemPointLinks, and ResetKartToRespawnPoint
    // stores an item point link outside battle; InitKartItems reads it through a raw overlay type.
    /* 60 */ u16 mItemRouteCount;
    /* 62 */ u8 mUnk_62[0x2];
    // Race point records (0x18 bytes: position, a value, 8 bytes), stored here instead of mBattlePoints when the course
    // has at most one start placement; mRacePointLinks is built from them.
    /* 64 */ Unk02175620_84 *mRacePoints;
    // Number of mRacePoints, and of mRacePointLinks.
    /* 68 */ u16 mRacePointCount;
    /* 6a */ u8 mUnk_6a[0x2];
    // Race routes over mRacePoints (first point, count, up to three next and three previous routes).
    /* 6c */ CourseMapRoute *mRaceRoutes;
    // Number of mRaceRoutes; the kart code tests it together with mBattleRouteCount (func_020733ec, func_02066ac0).
    /* 70 */ u16 mRaceRouteCount;
    /* 72 */ u8 mUnk_72[0x2];
    /* 74 */ CourseMapShape *mShapes;
    /* 78 */ u16 mShapeCount;
    /* 7a */ u8 mUnk_7a[0x2];
    /* 7c */ Unk02175620_7c *mCameras;
    /* 80 */ u16 mCameraCount;
    /* 82 */ u8 mUnk_82[0x2];
    // Battle point records (0x18 bytes: position, a value, 8 bytes), stored here instead of mRacePoints when the course
    // has several start placements; mBattlePointLinks is built from them.
    /* 84 */ Unk02175620_84 *mBattlePoints;
    // Number of mBattlePoints, and of mBattlePointLinks.
    /* 88 */ u16 mBattlePointCount;
    /* 8a */ u8 mUnk_8a[2];
    // Battle routes over mBattlePoints (first point, count, two lists of up to eight connecting routes, one for each
    // end of the route).
    /* 8c */ Unk02175620_8c *mBattleRoutes;
    // Number of mBattleRoutes; see mRaceRouteCount for the course test.
    /* 90 */ u16 mBattleRouteCount;
    /* 92 */ u8 mUnk_92[2];
    // One 8-byte record per element of mEntryGroups: the group record and the address of its first 0x14-byte entry in
    // mGroupEntries; built by func_02042fd8, read through GetCourseMapEntryGroupTableRow.
    /* 94 */ Unk02175620_94 *mEntryGroupTable;
    /* 98 */ u16 mNumberedCheckpointCount;
    // Last entry of the run that comes just before entry 0: first entry + count - 1 of the run named by the first back
    // link of the run that starts at entry 0 (0 when there are no runs). Karts start on it; going back over the line
    // from entry 0 onto it takes a lap off. With branches only the first back link is followed.
    /* 9a */ u16 mLastCheckpoint;
    // Largest CourseMapRoute.mLapProgressBase of the course, set once by CreateCourseMap;
    // RaceProgress.mLapProgressScale divides by it plus one.
    /* 9c */ u16 mLapProgressBaseMax;
    /* 9e */ u8 mUnk_9e[2];
    // One 0x28-byte link per race point (up to three next and three previous links, a pointer to the point, two
    // values), built from mRacePoints and mRaceRoutes; read by FindCourseMapKind4ShapeRacePointLink,
    // GetCourseMapRespawnRacePointLink and the kart follower set-up (func_02080d34).
    /* a0 */ Unk02175620_a0 *mRacePointLinks;
    /* a4 */ Unk02175620_bc *mUnk_a4;
    /* a8 */ s32 mUnk_a8;
    // One 0x28-byte link per item point (up to three next and three previous links, a pointer to the point, two
    // values), built from mItemPoints and mItemRoutes; followed by the kart item code and the item objects.
    /* ac */ struct Unk020f371c *mItemPointLinks;
    /* b0 */ s32 mUnk_b0;
    /* b4 */ s32 mUnk_b4;
    // One 0x30-byte link per battle point (up to eight neighbour links, a pointer to the point, two values, a link
    // count and a bit mask), built from mBattlePoints and mBattleRoutes; read by
    // FindCourseMapKind4ShapeBattlePointLink, GetCourseMapRespawnBattlePointLink and func_02040da8.
    /* b8 */ Unk02175620_bc *mBattlePointLinks;
    /* bc */ Unk02175620_bc *mUnk_bc;
    /* c0 */ Unk02175620_bc *mUnk_c0;
    // The first entry whose mChainStart is 1.
    /* c4 */ Unk02175620_7c *mFirstChainStartEntry;
    /* c8 */ Unk02175620_7c *mSecondChainStartEntry;
    /* cc */ Unk02175620_7c *mFirstKind6Entry;
    /* d0 */ Unk02175620_7c *mFirstKind7EntryInMode2;
    // The first entry of mKind 8, set only when the mode is 4; the loader does not set it to NULL first.
    /* d4 */ Unk02175620_7c *mFirstKind8EntryInMode4;
    /* d8 */ struct Unk02175620_d8 *mKind3ShapeLists[8];
    /* f8 */ u16 *mRespawnIndexBySlot;
    // Record index of mKeyedPlacements for each key, one halfword per record (BuildCourseMapKeyedPlacementIndexByKey).
    /* fc */ u16 *mKeyedPlacementIndexByKey;
    // Mode 2 only: the slot GetCourseMapRespawnSlot hands out next; counts up modulo mRespawnCount.
    /* 100 */ u16 mNextRespawnSlot;
    /* 102 */ u16 mKind4ShapeCount;
    /* 104 */ u32 mUnk_104;
    /* 108 */ s32 mUnk_108;
    // Format version from the file header halfword at 4; 0x1f adds the mKeyedPlacements section, 0x21 makes the
    // mItemPoints entries 0x14 bytes, 0x24 adds the mUnk_3c section.
    /* 10c */ u16 mVersion;
    /* 10e */ u8 mUnk_10e;
    /* 10f */ u8 mKind2ShapeCountInMode4;
} CourseMap;

typedef struct RaceHudSubScreenBgAffine {
    /* 00 */ s32 mMatrix0;
    /* 04 */ s32 mMatrix1;
    /* 08 */ s32 mMatrix2;
    /* 0c */ s32 mMatrix3;
    /* 10 */ s32 mCenterX;
    /* 14 */ s32 mCenterY;
    /* 18 */ s32 mX1;
    /* 1c */ s32 mY1;
} RaceHudSubScreenBgAffine;

typedef struct RaceHudSubScreenProjection {
    /* 00 */ UnkPair020b502c mCenter;
    /* 08 */ s32 mCenterRemainderX;
    /* 0c */ s32 mCenterRemainderY;
    /* 10 */ UnkPair020b502c mCenterWhole;
    /* 18 */ s32 mHalfSize;
    /* 1c */ s16 mAnglePairSecond;
    /* 1e */ s16 mAnglePairFirst;
    /* 20 */ s32 mAnglePairSecondScaled;
    /* 24 */ s32 mAnglePairFirstScaled;
    /* 28 */ s32 mUnk_28;
    /* 2c */ UnkPair020b502c mUnk_2c;
    /* 34 */ UnkPair020b502c mUnk_34;
    /* 3c */ s64 mUnk_3c;
    /* 44 */ s64 mUnk_44;
    /* 4c */ UnkPair020b502c mCourseMin;
    /* 54 */ UnkPair020b502c mCourseMax;
    /* 5c */ s64 mCourseInverseX;
    /* 64 */ s64 mCourseInverseZ;
    /* 6c */ UnkPair020b502c mUnk_6c;
    /* 74 */ UnkPair020b502c mUnk_74;
    /* 7c */ s64 mUnk_7c;
    /* 84 */ s64 mUnk_84;
    /* 8c */ s32 mScrollTimer;
    /* 90 */ Vec3 mScrollPosition;
} RaceHudSubScreenProjection;

extern CourseMap *gCourseMap;

#include "Main/Unknown/unk_02175628.h"

extern RaceHudSubScreenProjection *gRaceHudSubScreenProjection;

extern u16 func_020435bc(void);
s32 MulFixed12NoRound(s32 a, s32 b);
void UpdateRaceHudSubScreenProjectionAndBgAffine(RaceHudSubScreenBgAffine *p, s32 scale);
s32 func_020b523c(void);
s32 GetFixed12Whole(s32 x);
s32 GetAnglePairFirst(s32 x);
s32 GetAnglePairSecond(s32 x);
void UpdateRaceHudSubScreenScroll(void);
u16 func_020b5628(s32 idx, s32 mask);
u16 func_020b5644(Unk02175628 *p, s32 mask);
void func_020b5658(RaceHudSubScreenBgAffine *out);
s32 MulFx64c(s32 a, s64 k);
Unk020b57e4 *func_020b57e4(void);
void func_020b57f8(RaceHudSubScreenBgAffine *out);
void UpdateRaceHudSubScreenCenter(RaceHudSubScreenBgAffine *out);
BOOL ComputeRaceHudSubScreenPosition(const Vec3 *pos, UnkPair020b502c *out, s32 unk, s32 flag, s32 flag2);
void ComputeRaceHudSubScreenKartPosition(s32 idx, UnkPair020b502c *out, s32);
BOOL IsRaceHudSubScreenPairNearCenter(const UnkPair020b502c *p);
void ComputeRaceHudSubScreenCoursePosition(const Vec3 *pos, UnkPair020b502c *out);
void func_020b6078(s32 idx, UnkPair020b502c *out);
u16 func_020b6338(s32 idx);
u16 func_020b6368(void);
s32 func_020b6430(void);
s32 func_020b64e8(void);
u32 ClearRaceHudSubScreenProjection(void);
