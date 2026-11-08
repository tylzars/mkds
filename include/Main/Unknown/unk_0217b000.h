#pragma once

#include "types.h"
#include "Main/Unknown/unk_02165000.h" // Unk02165ff0
#include "Main/Unknown/code_020846c0.h" // ResFileEntry
#include "code_0212d214.h"
#include "Main/Unknown/code_020ae770.h"
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020e516c.h"
#include "Main/Unknown/code_020e6b58.h"
#include "ITCM/code_01ffdee4.h" // CourseCollision
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_0209bc74.h" // MapObjectModel
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/code_0208fd8c.h"
#include "Main/Unknown/unk_0217d000.h" // Unk0217d3f0_2098
#include "Main/Unknown/types_02180728.h" // TextCanvas
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020ae630.h"
#include "Main/Unknown/code_02089fa0.h" // StemSet
#include "code_0214a748.h" // Unk0214ad4c

struct RandomState64;
struct MapObjects;
struct Water;
struct MenuScene;
struct Nscr;
struct Ncgr;
struct Nclr;
struct Unk02022aa8;
struct KartBalloons;

// Element of 0x14 bytes of the table behind gBoxRotations.
typedef struct BoxRotation {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
} BoxRotation;

// Element of 8 bytes of the table behind gQuestionRotations.
typedef struct QuestionRotation {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
} QuestionRotation;

// UnkPair020b502c of code_020b502c.h is this type.
typedef struct Unk0217b498_0c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk0217b498_0c;

typedef struct RaceHudSubScreenCell {
    /* 00 */ Unk0217b498_0c mDrawPos;
    /* 08 */ struct Unk020224e0_c *mCell;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u8 mUnk_12[2];
} RaceHudSubScreenCell;

typedef struct Unk0217b498_00 {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mFlags;
    /* 04 */ Vec3 mPos;
    /* 10 */ u8 mUnk_10[0xc];
    /* 1c */ s32 mScaleX;
    /* 20 */ u8 mUnk_20[0x5e];
    /* 7e */ u16 mAngle;
    /* 80 */ u8 mUnk_80[0x28];
    /* a8 */ s32 mUnk_a8;
    /* ac */ s32 mUnk_ac;
    /* b0 */ s32 mUnk_b0;
    /* b4 */ s32 mUnk_b4;
    /* b8 */ u16 mUnk_b8;
    /* ba */ u8 mUnk_ba[6];
    /* c0 */ u16 mUnk_c0;
} Unk0217b498_00;

// Shared by the gRaceHudSubScreenItemBoxCells..gRaceHudSubScreenFireball2Cells lists and the ov001 pointers.
typedef struct RaceHudSubScreenCells {
    /* 00 */ Unk0217b498_00 **mObjects;
    /* 04 */ s32 mCellCount;
    /* 08 */ s32 mObjectCount;
    /* 0c */ Unk0217b498_0c *mUnk_0c;
    /* 10 */ RaceHudSubScreenCell *mCells;
} RaceHudSubScreenCells;

// Halfwords from 0x02 of Unk0217b490 read by UpdateRaceHudSubScreenBgPalette when gRaceSetup->mUnk_00 is 0x20: six, two
// rows of three and two.
typedef struct Unk0217b490_02_03 {
    /* 00 */ u16 mUnk_00[6];
    /* 0c */ u16 mUnk_0c[2][3];
    /* 18 */ u16 mUnk_18[2];
} Unk0217b490_02_03;

// The halfwords from 0x02 of Unk0217b490 as UpdateRaceHudSubScreenBgPalette and func_020cfca4 index them for the values
// of gRaceSetup->mUnk_00: a run of 0x15 (0x1c, 0x1f, 0x2e), nine rows of three (0xf), five rows of four (0x11) and
// Unk0217b490_02_03 (0x20).
typedef union Unk0217b490_02 {
    u16 mUnk_00[0x15];
    u16 mUnk_01[9][3];
    u16 mUnk_02[5][4];
    Unk0217b490_02_03 mUnk_03;
} Unk0217b490_02;

// Object behind data_0217b490, 0x38 bytes (allocated by func_020cffa0).
typedef struct Unk0217b490 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ Unk0217b490_02 mUnk_02;
} Unk0217b490;

// Pair of numbers "course number, course count" drawn on the main screen before start-sequence frame 0xb4, only in mode
// 5 and in mode 3 with gRaceSetup->mUnk_1c == 2 (DrawRaceMNumberPair), one record behind gRaceMNumberPair (0x28
// bytes, InitRaceMNumberPair); mUnk_08 .. mUnk_20 are the slide-in animation state. mUnk_18 points into mUnk_08.
typedef struct RaceMNumberPair {
    // Copy of gRaceSetup->mCourseNumber taken in InitRaceMNumberPair.
    /* 00 */ s32 mCourseNumber;
    // Number of courses of the run: 4 in mode 5, gRaceSetup->mUnk_3d8 in mode 3 with mUnk_1c == 2, else 0 (not
    // drawn). mUnk_3d8 has another meaning (score threshold) in mode 2 and for mUnk_1c == 1; this member never copies
    // that one.
    /* 04 */ s32 mCourseCount;
    /* 08 */ s32 mScaleMatrix[4];
    /* 18 */ s32 *mCellMatrix;
    /* 1c */ s32 mScale;
    /* 20 */ u16 mMatrixIndex;
    /* 22 */ u8 mUnk_22[2];
    // X added to every sprite of the pair: 0, or eased by InterpolateS16 (func_020d1de8) for the slide-in.
    /* 24 */ s32 mOffsetX;
} RaceMNumberPair;

typedef struct WaterEfct WaterEfct;

// Object at gViewFrustum: six vectors between words at 0x00/0x04 and 0x50/0x54.
typedef struct ViewFrustum {
    /* 00 */ s32 mNear;
    /* 04 */ s32 mFar;
    /* 08 */ Vec3 mCameraPos;
    /* 14 */ Vec3 mViewDirection;
    /* 20 */ Vec3 mUnk_20;
    /* 2c */ Vec3 mUnk_2c;
    /* 38 */ Vec3 mUnk_38;
    /* 44 */ Vec3 mUnk_44;
    /* 50 */ BOOL mViewTestRefreshRequested;
    /* 54 */ BOOL mViewTestRefreshPending;
} ViewFrustum;

// Object behind gEmblemChoises, 0x6c bytes (InitEmblemChoises allocates it); DrawEmblemChoises calls the function at
// 0x0c.
typedef struct EmblemChoises {
    /* 00 */ s32 mShown;
    /* 04 */ s32 mUnk_04;
    /* 08 */ BOOL mGraphicsUploadRequested;
    /* 0c */ UnkFunc *mUnk_0c;
    /* 10 */ BOOL mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mResult;
    /* 20 */ s32 mChoisesIndex;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mChoisesCount;
    /* 2c */ void *mUnk_2c;
    /* 30 */ Unk0217d3f0_2098 mUnk_30;
    /* 50 */ TextCanvas mUnk_50;
    /* 60 */ struct Nclr *mChoisesSBNclr;
    /* 64 */ struct Ncgr *mChoisesSBNcgr;
    /* 68 */ struct Nscr *mChoisesS3Nscr;
} EmblemChoises;

// 16-byte rows of the table behind gGrpconfTbl (CreateMapObject reads the halfwords).
typedef struct GrpconfTblRow {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
} GrpconfTblRow;

extern void *gHole;
extern void *gCover;
extern void *gPoo;
extern u16 gSearchStartIndex;
extern s32 gEntryYDifferenceLimit;
extern Unk02165ff0 *data_0217b030;

// Objects whose layout isn't known yet.
struct SPLManager;

// Object behind gKartPhysicalParamTable (0x14 bytes), made once per race: the per-slot records (mKartParams) and
// character rows (mCharParams) and the two loaded files. mFirstBaseSpeedLimit is a copy of file word 0x10.
typedef struct KartPhysicalParamTable {
    /* 00 */ u8 *mKartParams;
    /* 04 */ u8 *mCharParams;
    /* 08 */ s32 mFirstBaseSpeedLimit;
    /* 0c */ u8 *mKartParamFile;
    /* 10 */ u8 *mCharParamFile;
} KartPhysicalParamTable;

extern KartPhysicalParamTable *gKartPhysicalParamTable;

extern struct SPLManager *data_0217b03c;

extern struct SPLManager *data_0217b044;
extern struct SPLManager *data_0217b04c;
extern UnkFunc *data_0217b054;

// Function pointers set by RegisterKartAiCallbacks (the targets take different parameters).
extern UnkFunc *gKartAiAdvanceCallback;
extern UnkFunc *gKartAiSetupCallback;
extern UnkFunc *gKartAiResetCallback;
extern UnkFunc *gKartAiLinkPosAndDirectionCallback;
extern UnkFunc *gKartAiSetupHeldItemEntryCallback;
extern UnkFunc *gKartAiSetupItemInUseEntryCallback;
extern UnkFunc *gKartAiRequestLinkCallback;
extern s32 (*gKartAiIsLinkRequestedCallback)();
// Table of KartTurnEffects, one per Kart, allocated by InitKartTurnEffects and indexed by Kart.mIndex.
extern struct KartTurnEffects *gKartTurnEffects;
struct ModelEffect;

// The ModelEffect pools: an active list, one free list per kind, and the next polygon id (10 to 13).
typedef struct ModelEffects {
    /* 00 */ NNSFndList mActiveList;
    /* 0c */ NNSFndList mFreeLists[5];
    /* 48 */ struct ModelEffect **mObjects[5];
    /* 5c */ u16 mNextPolygonId;
    /* 5e */ u8 mUnk_5e[2];
} ModelEffects;

extern ModelEffects *gModelEffects;
extern s32 data_0217b07c;
// Particle effect ids func_0208d978 starts with a kind 2 object; -1 marks an unused entry.
extern s32 gKind2EffectIds[2];
extern KartAiItemUseEntry *gBattleItemInUseEntries;

// The strip pool, 0x38 bytes: the active strips, the free strips, the free points and the texture file.
typedef struct PosStrips {
    // [0] active strips, [1] free strips, [2] free points.
    /* 00 */ NNSFndList mLists[3];
    /* 24 */ ResFileEntry mEffectFileEntry;
    /* 34 */ s32 mPolygonAttrBits;
} PosStrips;

extern PosStrips *gPosStrips;
extern UnkFunc *data_0217b090;
extern UnkFunc *data_0217b094;
extern UnkFunc *data_0217b098;
extern UnkFunc *data_0217b0a0;
extern UnkFunc *data_0217b0a8;
extern UnkFunc *data_0217b0ac;
extern KartAiItemUseEntry *gBattleHeldItemEntries;
extern s32 *gStaffGhostTime;
extern void *gSmanBottom;
extern void *gSmanTop;

// The 0x10 bytes at 0x784 of StemSets; the callbacks at 0x794 and 0x798 get their address.
typedef struct TimedQuad {
    /* 00 */ u16 mTimer;
    /* 02 */ s16 mUnk_02;
    /* 04 */ u16 mColor;
    /* 06 */ u8 mUnk_06[2];
    /* 08 */ BOOL mEnabled;
    /* 0c */ u8 mUnk_0c[4];
} TimedQuad;

// Object behind gStemSets, 0x79c bytes.
typedef struct StemSets {
    // Entries 0 to 7 are the sets; entry 8 is a copy of the one shown.
    /* 000 */ StemSet *mSets[9];
    /* 024 */ u8 mUnk_024[0x718];
    // Index of the set DrawStemSets draws; 9 means none.
    /* 73c */ s32 mShownIndex;
    /* 740 */ u16 mShownFrames;
    /* 742 */ u16 mShownFrameCount;
    /* 744 */ Unk0214ad4c mOrthoMtx;
    /* 784 */ TimedQuad mTimedQuad;
    /* 794 */ void (*mStartFunction)(TimedQuad *);
    /* 798 */ void (*mUpdateFunction)(TimedQuad *);
} StemSets;

extern StemSets *gStemSets;
extern u32 gUnparkedTeresaCount;
extern void *gChandelier;
// One kart's entry of Standings (0x70 bytes, indexed by kart index): its count, rank, side id, elimination status and
// last position, and the hit tracking of the kart (those members keep their address names). Slots past the kart count
// are unused: status 2, count -1.
typedef struct KartStanding {
    /* 00 */ BOOL mUnk_00;
    /* 04 */ BOOL mUnk_04;
    // 0 in play, 1 just eliminated (the update calls the kart handler once and sets 2), 2 eliminated and handled;
    // unused slots start at 2. Only compared, never switched on.
    /* 08 */ s32 mEliminationStatus;
    // Copy of the kart's position, refreshed every update while the kart's count is above 0 and no winner is decided.
    /* 0c */ Vec3 mPos;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ BOOL mUnk_20;
    /* 24 */ s32 mUnk_24[8];
    /* 44 */ u16 mHitByKartIndex;
    // Id of the side the kart plays for: the entry's team index 0 gives 1, 1 gives 3, any other value gives the kart's
    // own index; an unused slot gets the kart count. The winner test compares it between the karts still in play.
    /* 46 */ u16 mTeamId;
    // Position in the order by count, 0 = first. Starts as the kart's own index; a count step swaps it with neighbours
    // (karts still in play stay ahead of eliminated ones).
    /* 48 */ u16 mRankIndex;
    /* 4a */ u8 mUnk_4a[2];
    // The kart's count: balloons held where the balloon object exists (mode 2 with RaceSetup.mUnk_18 == 0, and mode
    // 4), shines held in the shine mode (mode 2 with mUnk_18 == 1). -1 for an unused slot and for a kart eliminated in
    // mode 2; 0 at the start; changed in steps of +1 / -1. The rank order is sorted by it.
    /* 4c */ s32 mBalloonOrShineCount;
    /* 50 */ u16 mBalloonsLeftToMake;
    /* 52 */ u8 mUnk_52[0x12];
    /* 64 */ s32 mUnk_64;
    /* 68 */ s32 mUnk_68;
    /* 6c */ s32 mInflatingBalloon;
} KartStanding;

// Per-kart table of the modes that play with kart counts (modes 2 and 4): the one object behind gStandings, made by
// InitStandings from InitRace and stepped once per UpdateRace call. It ranks the karts by count (mKarts), keeps who is
// eliminated, the winning side, the end timer and its callbacks. The name covers only the ranking and winner part: the
// kart-to-kart hit tracking, the four hit callbacks that act on a hit, a time-limit step and a random course point are
// in the same object too (those members keep their address names). 0x3c0 bytes, the allocation size.
typedef struct Standings {
    // One KartStanding per kart index; the entries past the kart count are unused slots.
    /* 000 */ KartStanding mKarts[8];
    // Called when a kart touches another kart in Battle and only the other kart has attacked, with the hit kart index
    // and the other kart index; set by the balloon object, its result is returned to the collision code.
    /* 380 */ s32 (*mKartHitByKartCallback)(s32, s32);
    // Called when two karts touch in Battle and both have attacked, with both kart indices; set by the balloon object.
    /* 384 */ void (*mKartsHitEachOtherCallback)(s32, s32);
    // Called with the hit kart index and the index of the kart that hit it (8 when none) when a hit of the kart ends,
    // and for a kart that hit itself; set by the balloon object and the shine mode, which take a balloon or shine from
    // the first kart.
    /* 388 */ s32 (*mKartHitCallback)(u16, u16);
    // Called with the kart index at the start of an elimination. Set by the balloon object (releases the kart's
    // balloons) and by the shine mode (drops the kart's shines).
    /* 38c */ void (*mKartEliminatedCallback)(u16);
    // Called when mEndTimer runs out and by the mode 4 end step. Set by the balloon object, the shine mode and the
    // overlay 1 objects.
    /* 390 */ void (*mEndCallback)(void);
    /* 394 */ u8 mUnk_394[8];
    // Called in Battle with the kart index and the address of a Vec3 when a kart is placed or pushed: the position
    // change of a kart set to a checkpoint position, the position change in func_02068494, and the push vector of a map
    // object that a kart pushed; set by the balloon object, which adds that Vec3 to the positions of the kart's
    // balloons.
    /* 39c */ void (*mKartOffsetCallback)(s32, s32);
    // Number of Shine16 objects placed and not yet finished: AddShineCount changes it (+1 placed, -1 finished); the
    // spawner stops placing at 3. Parking every shine at once, as the shine mode's end callback does, does not
    // subtract.
    /* 3a0 */ u16 mShineCount;
    /* 3a2 */ u16 mUnk_3a2;
    /* 3a4 */ u16 mUnk_3a4;
    /* 3a6 */ u8 mUnk_3a6[2];
    // Frames left before mEndCallback runs once a winner is decided: mode 2 stores 0x5a and counts it down; at 0 it
    // becomes -1 and the callback runs. A value below 0 means the end is reached. Mode 4 stores 0 and ends through the
    // race-progress end step, which sets -1 and runs the callback.
    /* 3a8 */ s32 mEndTimer;
    // Highest KartStanding.mBalloonOrShineCount over the karts, as of the last rank re-sort (the two functions that
    // swap ranks recompute it; AddBalloonOrShineCountAndMoveRank, which adds to a count, does not).
    /* 3ac */ s32 mHighestBalloonOrShineCount;
    // Lowest non-negative KartStanding.mBalloonOrShineCount over the karts, as of the last rank re-sort; 0xffff when no
    // kart has a non-negative count.
    /* 3b0 */ s32 mLowestBalloonOrShineCount;
    // Side id (KartStanding.mTeamId) of the winning side, -1 until a winner is decided. Set once every kart still in
    // play has the id of the rank 0 kart. In mode 4 the ids are kart indices (it is compared with the local entry
    // index).
    /* 3b4 */ s32 mWinnerTeamId;
    /* 3b8 */ u16 mUnk_3b8;
    /* 3ba */ u8 mUnk_3ba[2];
    // Pointer to entry 0 of the kind 0x69 object's KartBalloons array; set once by InitKartBalloons.
    /* 3bc */ struct KartBalloons *mKartBalloons;
} Standings;

// The Standings object, allocated by InitStandings in modes 2 and 4.
extern Standings *gStandings;
extern void *gBalloon;
extern Vec3 data_0217b208;
extern Vec3 data_0217b214;
// 8-byte entries of the tables KeyboardKeys points to (FindKeyboardRectByValue returns one).
typedef struct KeyboardRect {
    /* 00 */ u8 mX;
    /* 01 */ u8 mY;
    /* 02 */ u8 mWidth;
    /* 03 */ u8 mHeight;
    /* 04 */ s16 mNextRectOffset;
    /* 06 */ u16 mKeyId;
} KeyboardRect;

struct Ncgr;
struct KeyboardKeys;

// Set up by SetupKeyboardLayout (at 0x1c of KeyboardKeys, which mUnk_2c then points to); mUnk_08 is called with the
// KeyboardKeys (AsciiLayoutCallback is one).
typedef struct KeyboardLayout {
    /* 00 */ KeyboardRect *mRects;
    /* 04 */ struct Ncgr *mNcgr;
    /* 08 */ void (*mCallback)(struct KeyboardKeys *);
    /* 0c */ u16 mFixedKeyCount;
    /* 0e */ u16 mRectCount;
} KeyboardLayout;

// Four halfwords at 0x34 of KeyboardKeys (IsRepeatCounterFiring, AdvanceRepeatCounter).
typedef struct RepeatCounter {
    /* 00 */ u16 mRepeatFrames;
    /* 02 */ u16 mFirstFireFrame;
    /* 04 */ u16 mRepeatFireFrame;
    /* 06 */ u16 mUnk_06;
} RepeatCounter;

// Object at gKeyboardKeyRepeat: an RepeatCounter followed by two halfwords (AdvanceKeyboardKeyRepeat,
// SetupKeyboardKeyRepeat).
typedef struct KeyboardKeyRepeat {
    /* 00 */ RepeatCounter mCounter;
    /* 08 */ u16 mKeyMask;
    /* 0a */ u16 mRepeatKeys;
} KeyboardKeyRepeat;

// Object at gKeyboardKeys, 0x54 bytes. data_0217b280, data_0217b294, data_0217b2ac and data_0217b2b8 are the
// addresses of its members at 0x08, 0x1c, 0x34 and 0x40.
typedef struct KeyboardKeys {
    /* 00 */ KeyboardRect mButton0Rect;
    /* 08 */ KeyboardRect mButton1Rect;
    /* 10 */ KeyboardRect *mTouchStartRect;
    /* 14 */ KeyboardRect *mTouchRect;
    /* 18 */ KeyboardRect *mKeyDownRect;
    /* 1c */ KeyboardLayout mLayout;
    /* 2c */ KeyboardLayout *mCurrentLayout;
    /* 30 */ u16 *mCharMap;
    /* 34 */ RepeatCounter mTouchRepeat;
    /* 3c */ u16 mKeyId;
    /* 3e */ u16 mKeyValue;
    /* 40 */ u16 mChosenKeyId;
    /* 42 */ u16 mToggledKeyId;
    /* 44 */ KeyboardRect *mCursorRect;
    /* 48 */ u8 mUnk_48[4];
    /* 4c */ u16 (*mCursorCallback)(s32, u16);
    /* 50 */ s32 (*mKeyCallback)(u32, s32);
} KeyboardKeys;

extern KeyboardKeys gKeyboardKeys;
extern KeyboardKeyRepeat gKeyboardKeyRepeat;
extern u8 data_0217b280[];
extern u16 data_0217b2b8[2];
extern KeyboardLayout data_0217b294;
extern RepeatCounter data_0217b2ac;
// Object at gKeyboardInput, 0x28 bytes (AdvanceKeyboardInput updates it, ClearKeyboardInput clears it).
typedef struct KeyboardInput {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u16 mKeysPressed;
    /* 06 */ u16 mKeysDown;
    /* 08 */ u16 mKeysReleased;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mPrevSample[4];
    /* 14 */ u16 mLastTouchX;
    /* 16 */ u16 mLastTouchY;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mTouchStatus;
    /* 20 */ u16 mTouchDown;
    /* 22 */ u16 mUnk_22;
    /* 24 */ BOOL mTouchEnabled;
} KeyboardInput;

extern KeyboardInput gKeyboardInput;
extern u16 *gKbdmapAscii;
extern u16 *gKbdmapOther1;
extern u16 *gKbdmapOther2;
extern u16 *gKbdmapOther3;
extern u16 *gKbdmapKatakana;
extern u16 *gKbdmapAsciiShift;
extern u16 *gKbdmapKatakanaDakuten;
extern u16 *gKbdmapHiraganaDakuten;
extern u16 *gKbdmapHiraganaHandaku;
extern u16 *gKbdmapHiraganaSmall;
extern u16 *gKbdmapAsciiCaps;
extern u16 *gKbdmapKatakanaHandaku;
extern u16 *gKbdmapKatakanaSmall;
// Object behind gKeyboardTextEntry, 0x78 bytes, allocated in InitKeyboardTextEntry. UploadKeyboardBg2Data passes the
// pointers at 0x00 and 0x04 to DC_FlushRange with the words at 0x08 and 0x0c.
typedef struct KeyboardTextEntry {
    /* 00 */ void *mBg2Char;
    /* 04 */ void *mBg2Scr;
    /* 08 */ s32 mBg2CharSize;
    /* 0c */ s32 mBg2ScrSize;
    /* 10 */ struct Ncgr *mNcgrs[5];
    /* 24 */ struct Ncgr *mUnk_24;
    /* 28 */ void *mKbds[6];
    /* 40 */ u16 *mText;
    /* 44 */ u16 mTextCapacity;
    /* 46 */ u16 mTextIndex;
    /* 48 */ u16 mUnk_48;
    /* 4a */ u16 mTextLimit;
    /* 4c */ s32 mLayoutIndex;
    /* 50 */ s32 mOffsetX;
    /* 54 */ s32 mOffsetY;
    /* 58 */ s32 mButton0X0;
    /* 5c */ s32 mButton0Y0;
    /* 60 */ s32 mButton0X1;
    /* 64 */ s32 mButton0Y1;
    /* 68 */ s32 mButton1X0;
    /* 6c */ s32 mButton1Y0;
    /* 70 */ s32 mButton1X1;
    /* 74 */ s32 mButton1Y1;
} KeyboardTextEntry;

extern KeyboardTextEntry *gKeyboardTextEntry;
extern u16 *gKbdmapHiragana;
extern void *gShineBalloon;
typedef struct TitleStateHandlers {
    /* 00 */ UnkFunc *mUnk_00;
    /* 04 */ void (*mUpdate)(s32);
} TitleStateHandlers;

struct LayoutTableEntry;
struct Unk0201ea30;

// 0x8bc bytes.
typedef struct TitleScene {
    /* 000 */ s32 mStateFrames;
    // TRUE from every change of state (and creation) until the current state's handler has run; nothing reads it.
    /* 004 */ BOOL mStateChanged;
    /* 008 */ s32 mPrevState;
    /* 00c */ s32 mState;
    /* 010 */ s32 mNextState;
    /* 014 */ TitleStateHandlers mStateHandlers[7];
    /* 04c */ s32 mNoInputFrames;
    /* 050 */ BOOL mBlendDone;
    /* 054 */ s32 mSelectedIndex;
    /* 058 */ BOOL mSelectedPressed;
    /* 05c */ BOOL mPreferEntry4;
    /* 060 */ s16 mSelectedOffset;
    /* 062 */ u8 pad_62[2];
    /* 064 */ s32 mBlendFrames;
    /* 068 */ struct LayoutTableEntry *mTitleTable;
    /* 06c */ struct Unk0201ea30 *mTitleSBncl;
    /* 070 */ void *mTitleSBnbl;
    /* 074 */ struct Unk0201ea30 *mTitleSBnll;
    /* 078 */ struct Nclr *mTitleTrueMBOrMBNclr;
    /* 07c */ struct Ncgr *mTitleTrueMBOrMBNcgr;
    /* 080 */ struct Nclr *mTitleSBNclr;
    /* 084 */ struct Ncgr *mTitleSBNcgr;
    /* 088 */ struct Nscr *mTitleTrueM1OrM1Nscr;
    /* 08c */ struct Nscr *mTitleTrueM2OrM2Nscr;
    /* 090 */ struct Nscr *mTitleSBgNscr;
    /* 094 */ u8 pad_94[0xc];
    /* 0a0 */ struct Nclr *mTitleSONclr;
    /* 0a4 */ struct Ncgr *mTitleSNceNcgr;
    /* 0a8 */ struct Unk02021dc8 *mTitleSNceNcer;
    /* 0ac */ u8 pad_ac[4];
    /* 0b0 */ Unk020ae630 mMainOam;
    /* 4b4 */ Unk020ae630 mSubOam;
    /* 8b8 */ u8 *mUnk_8b8;
} TitleScene;

extern TitleScene *gTitleScene;
extern const TitleStateHandlers gTitleStateHandlers[7];
extern u8 data_0217b344[];
extern u16 *data_0217b34c;
// 0x20 bytes: four words, then four more words.
typedef struct Unk0217b350_858 {
    /* 00 */ s32 mUnk_00[4];
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
} Unk0217b350_858;

// On-screen display of the race, one record behind gRaceHud (0x914 bytes, allocated by func_020b03bc on the scene heap,
// set NULL by the release slot func_020af86c, never freed). It holds the two 0x400-byte sprite entry buffers the
// element draws append to (mUnk_004 for the main screen, mUnk_408 for the sub screen, copied to 0x07000000 /
// 0x07000400), the loaded graphics, the sub-screen page (mSubScreenState) and the goal-background delay; the elements
// themselves (time digits, number pair, goal page, new-record page) are separate objects. It does not exist in kinds 3,
// 5 and 6 of gRaceSetup->mUnk_00c (the scene slots run RaceStartGp / EndingStaffRoll there).
// Words from 0x828 to 0x910 are read and written by func_020aeb7c. The pointers at 0x80c to 0x824 are written through
// LoadNclrData, LoadNcgrData and LoadNscrData.
typedef struct RaceHud {
    // Calls of the step func_020af66c that ran its body (not in kinds 3, 5, 6, not before mEnabled); wraps to 0 at
    // 0xc00. An animation clock: read by the upload slot (value / 6 = scroll of the sub-screen page 0) and by
    // GetRaceHudUpdateFrames (value / 32).
    /* 000 */ s32 mUpdateFrames;
    /* 004 */ u8 mUnk_004[0x400];
    /* 404 */ u16 mUnk_404;
    /* 406 */ u16 mUnk_406;
    /* 408 */ u8 mUnk_408[0x400];
    /* 808 */ u16 mUnk_808;
    /* 80a */ u16 mUnk_80a;
    /* 80c */ struct Nclr *mNclrs[2];
    /* 814 */ struct Ncgr *mNcgrs[2];
    /* 81c */ struct Nscr *mNscrs[3];
    // Page of the sub screen (reg_GXS_DB_* / reg_G2S_DB_* = sub engine), 0..6, switched on by the step, the draw and
    // the upload slot; assigned by func_020aeb7c (per mode and race state), RequestRaceHudSubScreenState5 (5,
    // RaceGoalS) and RequestRaceHudSubScreenState6 (6, RaceNewRecordTa). 4 and 5 run the RaceGoalS page, 6 the
    // new-record page; what 0 and 1..3 show is not named (the player switches 0 and 1 with sounds 0x18 / 0x17).
    /* 828 */ s32 mSubScreenState;
    // Gate of the sub screen's page update and page upload.
    /* 82c */ BOOL mSubScreenEnabled;
    // Set when the state-5 page is requested; the upload loads its graphics once and clears it.
    /* 830 */ BOOL mSubScreenState5LoadPending;
    // Set when the state-6 page is requested; the upload loads its graphics once and clears it.
    /* 834 */ BOOL mSubScreenState6LoadPending;
    /* 838 */ BOOL mUnk_838;
    /* 83c */ BOOL mUnk_83c;
    /* 840 */ BOOL mUnk_840;
    /* 844 */ s32 mUnk_844;
    /* 848 */ s32 mUnk_848;
    /* 84c */ s32 mUnk_84c;
    /* 850 */ s32 mUnk_850;
    /* 854 */ s32 mUnk_854;
    /* 858 */ Unk0217b350_858 mUnk_858[2];
    // FALSE from func_020b03bc until the scene's screen set-up func_020af99c ends and sets it TRUE (never cleared
    // again); the step, the draw, the page choice and the upload slot return at once while FALSE.
    /* 898 */ BOOL mEnabled;
    /* 89c */ s32 mUnk_89c[8];
    /* 8bc */ s32 mUnk_8bc[8];
    /* 8dc */ s32 mUnk_8dc;
    /* 8e0 */ s32 mUnk_8e0;
    // Set once in func_020b03bc: 1 only in mode 1 with more than one kart; gates func_020b1a34 (the computation) and
    // the draw of the time difference.
    /* 8e4 */ s32 mUseTimeDifference;
    // ComputeTimeDifference's return: non-zero when the entry's summed lap times (GetKartLapTime) are >= the summed
    // reference times (gRaceSetup->mGhostLapTimes); the draw picks one of two sprites by it. Which sprite is plus or
    // minus is not named.
    /* 8e8 */ s32 mTimeDifferenceSign;
    // The difference as seven digits (SplitTimeDigits), written by func_020b1a34, read through GetRaceHudTimeDifference
    // by the draw.
    /* 8ec */ TimeDigits mTimeDifferenceDigits;
    // 1 once the per-frame step has run.
    /* 908 */ s32 mStepHasRun;
    /* 90c */ BOOL mUnk_90c;
    /* 910 */ s32 mUnk_910;
} RaceHud;

extern RaceHud *gRaceHud;
struct ChoisesS;
extern struct ChoisesS *gChoisesS;
struct RaceNcerNclrNcgrTables;
extern struct RaceNcerNclrNcgrTables *data_0217b3c4;
// 8-byte elements at the start of Unk0217b3d8.
typedef struct Unk0217b3d8_00 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk0217b3d8_00;

// 0xc-byte elements from 0xfc of Unk0217b3d8.
typedef struct Unk0217b3d8_fc {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
} Unk0217b3d8_fc;

// Object behind gRaceRankList, 0x15c bytes, allocated by InitRaceRankList.
typedef struct Unk0217b3d8 {
    /* 000 */ Unk0217b3d8_00 mUnk_000[8];
    /* 040 */ s32 mUnk_040[8];
    /* 060 */ s32 mUnk_060[8];
    /* 080 */ s32 mUnk_080[8];
    /* 0a0 */ s32 mUnk_0a0[8];
    /* 0c0 */ s32 mUnk_0c0[8];
    /* 0e0 */ s32 mUnk_0e0;
    /* 0e4 */ u16 mUnk_0e4;
    /* 0e6 */ u8 mUnk_0e6[2];
    /* 0e8 */ s32 mUnk_0e8[4];
    /* 0f8 */ u16 mUnk_0f8;
    /* 0fa */ u8 mUnk_0fa[2];
    /* 0fc */ Unk0217b3d8_fc mUnk_0fc[8];
} Unk0217b3d8;

extern Unk0217b3d8 *gRaceRankList;
// Object behind gRaceHudSubScreenCellGroups, 0x25c bytes, allocated by InitRaceHudSubScreenCellGroups.
typedef struct RaceHudSubScreenCellGroups {
    /* 000 */ u16 mUnk_000;
    /* 004 */ s32 mUnk_004;
    /* 008 */ s32 mUnk_008;
    /* 00c */ s32 mGroupCount;
    /* 010 */ void (*mClearFunctions[49])(void);
    /* 0d4 */ void (*mUpdateFunctions[49])(void);
    /* 198 */ void (*mDrawFunctions[49])(void *);
} RaceHudSubScreenCellGroups;

extern RaceHudSubScreenCellGroups *gRaceHudSubScreenCellGroups;
// Object behind gRaceGoalS, 0x20e4 bytes, allocated by InitRaceGoalS.
typedef struct RaceGoalS {
    /* 0000 */ s32 mRowVisible[8];
    /* 0020 */ s32 mShownNumbers[8];
    /* 0040 */ s32 mRowKartIndex[8];
    /* 0060 */ s32 mPreviousRowKartIndex[8];
    /* 0080 */ s32 mRankComparison[8];
    /* 00a0 */ s32 mOffsetX;
    /* 00a4 */ s32 mUnk_00a4;
    /* 00a8 */ s32 mHiddenRowCount;
    /* 00ac */ void *mUpdate;
    /* 00b0 */ s32 mUpdateFrames;
    /* 00b4 */ s32 mUnk_00b4;
    /* 00b8 */ struct Nclr *mRaceGoalSBNclr;
    /* 00bc */ struct Ncgr *mRaceGoalSBNcgr;
    /* 00c0 */ struct Nscr *mRaceGoalSNscrs[6];
    /* 00d8 */ u16 mRaceGoalSSpaceNscrCopies[2][0x800];
    /* 20d8 */ s32 mOffsetState;
    /* 20dc */ s32 mOffsetStateFrames;
    /* 20e0 */ s32 mOffset;
} RaceGoalS;

extern RaceGoalS *gRaceGoalS;
extern struct RaceStartGp *gRaceStartGp;
extern struct RaceGoalM *gRaceGoalM;
extern struct RaceNewRecordTa *gRaceNewRecordTa;
extern s32 data_0217b3f8;
extern EmblemChoises *gEmblemChoises;
extern struct MenuScene *data_0217b43c;
extern struct CupPicture *gCupPicture;
extern struct Unk0217b4b0 *data_0217b4b0;
extern struct RandomState64 *gRaceRandom;
extern struct RandomState64 *gMapObjectRandom;
// The same pointer as gWaterEfct, stored by SetCourseWaterEfct (the last call of CreateWaterEfct) and set to NULL in
// InitMapObjects; the water_efct getters and the level getter read this one.
extern WaterEfct *gCourseWaterEfct;
extern Vec3 *gFoundMapObjectVectors;
extern s32 data_0217b4e0;
// The same pointer as gWater, stored by SetCourseWater (the last call of each Create...Water) and set to NULL in
// InitMapObjects before the objects are created, so NULL means the course has no water; the update, draw, getters and
// camera read this one, while gWater (never cleared) is only the creators' variable.
extern struct Water *gCourseWater;
extern s32 gMapObjectKindCount;
extern struct MapObjects *gMapObjects;
extern s32 data_0217b4f4;
extern ViewFrustum gViewFrustum;
extern ViewFrustum gViewFrustumBeforeRotation;
extern struct RockDrawList *data_0217b650;
extern struct RockUpdateList *data_0217b654;
extern struct ShadowModel *gRockShadow;
extern struct Nsbmd *gRock;
extern struct Quaternion gViewYawQuaternion;
extern struct GroupPath *gGroupPaths;
extern struct Unk020db20c *gKuriboDrawList;
extern struct Unk020db1b0 *gKuriboUpdateList;
extern NsbmdModel *gKuribo;
extern struct Nsbmd *gDossun;
extern struct Unk020dbe74 *gDossunUpdateList;
extern struct ShadowModel *gDossunShadow;
extern struct Unk020dbed0 *gDossunDrawList;
extern MtxFx43 gDossunDrawMatrix;
extern struct Nsbmd *gWanwan;
extern struct ShadowModel *gWanwanRockShadow;
extern Unk020de334 *data_0217b6dc;
extern Unk020de2d8 *data_0217b6e0;
extern NsbmdModel *gWanwanKui;
extern NsbmdModel *gWanwanChain;
extern Unk020de2d8 *gEarthenPipeUpdateList;
extern NsbmdModel *gEarthenPipe1;
extern NsbmdModel *gEarthenPipe2;
extern Unk020de334 *gEarthenPipeDrawList;
extern u16 data_0217b6fc;
extern Unk020de334 *gQuestionDrawList;
extern BoxRotation *gBoxRotations;
extern QuestionRotation *gQuestionRotations;
extern Unk020de334 *gBoxDrawList;
extern NsbmdModel *gQuestion;
extern Unk020de334 *data_0217b714;
extern Unk020de2d8 *gItemBoxUpdateList;
extern NsbmdModel *gBox;
extern MtxFx43 data_0217b720;
extern u16 data_0217b750;
extern s32 data_0217b754;
extern Unk020de2d8 *gGroupItemBoxUpdateList;
extern s32 data_0217b75c;
extern Vec3 data_0217b760;
extern Unk020dfc44 *data_0217b76c;
extern void *gMkdEfBubble;
extern Unk020de334 *data_0217b774;
extern void *gMkdEfBubbleNsbta;
extern void *gKoopaBlock;
extern NsbmdModel *gChoropu;
extern NsbmdModel *gPukupuku;
extern Unk020e53ac *data_0217b814;
extern NsbmdModel *gObPakkunSf;
extern MtxFx43 *gTranslationMatrix;
extern MtxFx43 *gViewTransposeMatrix;
extern MtxFx43 *data_0217b84c;
extern MtxFx43 *data_0217b850;
extern MtxFx43 *gViewMatrix;
extern s32 *data_0217b858;
extern MtxFx43 *data_0217b85c;
extern MtxFx43 *data_0217b860;
extern u16 *data_0217b868;
extern s32 data_0217bc5c;
extern s32 data_0217bc60;

extern u16 data_0217b220;
#include "Main/Unknown/unk_0217b358.h"
#include "Main/Unknown/unk_0217b35c.h"
// Object behind data_0217b3c8, 0xc bytes, allocated by func_020ba520. The word at 0 is also read and written as two
// halfwords.
typedef struct Unk0217b3c8 {
    /* 00 */ union {
        s32 mUnk_00;
        u16 mUnk_00_h[2];
    };
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
} Unk0217b3c8;

extern Unk0217b3c8 *data_0217b3c8;
// Five words at 0x18 of Unk0217b3cc.
typedef struct Unk0217b3cc_18 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
} Unk0217b3cc_18;

// Object behind data_0217b3cc, 0x2c bytes, allocated by func_020bb530.
typedef struct Unk0217b3cc {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ Unk0217b3cc_18 mUnk_18;
} Unk0217b3cc;

extern Unk0217b3cc *data_0217b3cc;
// Object behind gRaceTimeDigits, 0x38 bytes, allocated by InitRaceTimeDigits.
typedef struct Unk0217b3d0 {
    /* 00 */ TimeDigits mUnk_00;
    /* 1c */ BOOL mUnk_1c;
    /* 20 */ s32 mUnk_20[6];
} Unk0217b3d0;

extern Unk0217b3d0 *gRaceTimeDigits;
// 0x18-byte elements of the tables at member 0x10 of RaceTaPositions.
typedef struct RaceTaPositionSample {
    /* 00 */ Vec3 mPos;
    /* 0c */ u16 mAngle;
    /* 0e */ u8 mUnk_0e[2];
    /* 10 */ s32 mKind;
    /* 14 */ s32 mUnk_14;
} RaceTaPositionSample;

// 0x40-byte elements of the table at member 0x790 of RaceTaPositions.
typedef struct Unk0217b3e4_790 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ Vec3 mUnk_04[3];
    /* 28 */ s32 mUnk_28[3];
    /* 34 */ s32 mUnk_34[3];
} Unk0217b3e4_790;

// 0x10-byte elements of the table at member 0x810 of RaceTaPositions.
typedef struct Matrix2x2 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
} Matrix2x2;

// Object behind gRaceTaPositions, 0x910 bytes, allocated by InitRaceTaPositions.
typedef struct RaceTaPositions {
    /* 000 */ s32 mVisible;
    /* 004 */ s32 mKartVisible[2];
    /* 00c */ s32 mSampleFrames;
    /* 010 */ RaceTaPositionSample mSamples[2][0x28];
    /* 790 */ Unk0217b3e4_790 mUnk_790[2];
    /* 810 */ Matrix2x2 mRotations[16];
} RaceTaPositions;

extern RaceTaPositions *gRaceTaPositions;
// Object behind gRaceLinkLevel.
typedef struct Unk0217b3ec {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
} Unk0217b3ec;

extern Unk0217b3ec *gRaceLinkLevel;
extern Unk0217b3ec *gRaceLapNumber;
// Object behind gRaceHudSubScreenSecondHand, 0x44 bytes allocated by CreateRaceHudSubScreenSecondHand: a table of
// object pointers and two counts (as in RaceHudSubScreenCells), three halfwords and two arrays of three pairs.
typedef struct RaceHudSubScreenSecondHand {
    /* 00 */ struct Unk020e1e98 **mObjects;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mObjectCount;
    /* 0c */ u16 mAngles[3];
    /* 12 */ u8 mUnk_12[2];
    /* 14 */ Unk0217b498_0c mDrawPositions[3];
    /* 2c */ Unk0217b498_0c mUnk_2c[3];
} RaceHudSubScreenSecondHand;

// Object behind gRaceHudSubScreenKarts, 0x194 bytes allocated by CreateRaceHudSubScreenKarts: arrays of eight entries
// and an RaceHudSubScreenCells pointer at 0x190.
typedef struct RaceHudSubScreenKarts {
    /* 000 */ s32 mUnk_000[8];
    /* 020 */ s32 mUnk_020[8];
    /* 040 */ s32 mUnk_040[8];
    /* 060 */ Unk0217b498_0c mUnk_060[8];
    /* 0a0 */ Vec3 mUnk_0a0[8];
    /* 100 */ u16 mUnk_100[8];
    /* 110 */ s32 mUnk_110[8];
    /* 130 */ s32 mUnk_130[8];
    /* 150 */ s32 mUnk_150[8];
    /* 170 */ s32 mUnk_170[8];
    /* 190 */ RaceHudSubScreenCells *mUnk_190;
} RaceHudSubScreenKarts;

extern RaceHudSubScreenSecondHand *gRaceHudSubScreenSecondHand;
extern RaceHudSubScreenKarts *gRaceHudSubScreenKarts;
extern struct RaceGoalTimes *gRaceGoalTimes;
extern u8 data_0217b4a8[];
extern struct EndingStaffRollObject *gEndingStaffRoll;
extern RaceMNumberPair *gRaceMNumberPair;
extern u16 data_0217b4c0;
extern u16 gWrappingPolygonId;
extern u16 gWrappingPolygonIdBase;
extern u16 data_0217b4cc;
extern u16 gNextPolygonId;
extern GrpconfTblRow *gGrpconfTbl;
extern MapObject **gFoundMapObjects;
extern u8 data_0217b7c4[];
extern u8 gMapObjectPositionByTableIndex[];
// Indexed by object kind; 14 slots, 13 files (kind 8 aliases kind 7)
extern NsbmdModel *gItemModels[];
struct ItemObject;

extern struct ItemObject **gCollidedItemObjects;

extern void *data_0217b040;
extern s32 gKeyboardOffsetX;
extern s32 gKeyboardOffsetY;
extern u16 *gCharTablePair3[2];
extern u16 *gCharTablePair2[2];
extern u16 *gCharTablePair1[2];
// Object at gKeyboardCanvas, 0x24 bytes.
typedef struct KeyboardCanvas {
    /* 00 */ struct Unk02022aa8 *mFont;
    /* 04 */ void *mBg2Char;
    /* 08 */ void *mUnk_08;
    /* 0c */ u16 *mBg2Scr;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
} KeyboardCanvas;

extern KeyboardCanvas gKeyboardCanvas;
struct Unk0217b340;
struct BmgBodySection;
struct Nclr;
struct Unk02021dc8;
extern struct Unk0217b340 *data_0217b360;
extern struct BmgBodySection *data_0217b364;
extern struct Nclr *gPlayerCharacterNclr[2];
extern struct Nclr *gPlayerCharacterLNclr;
extern struct Ncgr *gPlayerCharacterNcgr[2];
extern struct Ncgr *gPlayerCharacterLNcgr;
extern struct Unk02021dc8 *gPlayerCharacterNcer[2];
extern struct Unk02021dc8 *gPlayerCharacterLNcer;
extern void *gPlayerCharacterBncl[2];
extern struct Nclr *gPlayerCharacterShyguyNclr[2];
extern struct Nclr *gPlayerCharacterLShyguyNclr;
extern struct Unk02022aa8 *gFontTable[3];
extern struct Unk02022aa8 gLCFontS;
extern struct Unk02022aa8 gLCFontM;
extern struct Unk02022aa8 gMarioFont;
extern RaceHudSubScreenCells *gRaceHudSubScreenItemBoxCells;
extern RaceHudSubScreenCells *gRaceHudSubScreenEarthenPipeCells;
extern RaceHudSubScreenCells *gRaceHudSubScreenWanwanCells;
extern RaceHudSubScreenCells *gRaceHudSubScreenDossunCells;
extern RaceHudSubScreenCells *gRaceHudSubScreenSmanCells;
extern RaceHudSubScreenCells *gRaceHudSubScreenMoveTreeCells;
extern RaceHudSubScreenCells *gRaceHudSubScreenPukupukuCells;
extern RaceHudSubScreenCells *gRaceHudSubScreenChoropuCells;
extern RaceHudSubScreenCells *gRaceHudSubScreenKoopaBlockCells;
extern RaceHudSubScreenCells *data_0217b420;
extern RaceHudSubScreenCells *gRaceHudSubScreenItemCells;
extern RaceHudSubScreenCells *gRaceHudSubScreenCrabCells;
extern RaceHudSubScreenCells *gRaceHudSubScreenShine16Cells;
extern RaceHudSubScreenCells *gRaceHudSubScreenPendulumCells;
extern RaceHudSubScreenCells *gRaceHudSubScreenNsKiller2Cells;
extern RaceHudSubScreenCells *gRaceHudSubScreenFlipperCells;
extern RaceHudSubScreenCells *gRaceHudSubScreenWoodbox1Cells;
extern RaceHudSubScreenCells *gRaceHudSubScreenRockCells;
extern RaceHudSubScreenCells *gRaceHudSubScreenSanboCells;
extern RaceHudSubScreenCells *gRaceHudSubScreenRock2Cells;
extern RaceHudSubScreenCells *gRaceHudSubScreenCoverPooHoleCells;
extern RaceHudSubScreenCells *gRaceHudSubScreenObPakkunSfCells;
extern RaceHudSubScreenCells *gRaceHudSubScreenKuriboCells;
extern RaceHudSubScreenCells *gRaceHudSubScreenIronBallCells;
extern RaceHudSubScreenCells *data_0217b46c;
extern RaceHudSubScreenCells *gRaceHudSubScreenMkdEfBurnerCells;
extern RaceHudSubScreenCells *gRaceHudSubScreenBoundCells;
extern RaceHudSubScreenCells *gRaceHudSubScreenMkdEfBubbleCells;
extern RaceHudSubScreenCells *gRaceHudSubScreenBasabasaCells;
extern RaceHudSubScreenCells *gRaceHudSubScreenRainStarCells;
extern RaceHudSubScreenCells *data_0217b484;
extern RaceHudSubScreenCells *gRaceHudSubScreenBombKouraWCells;
extern Unk0217b490 *data_0217b490;
extern RaceHudSubScreenCells *gRaceHudSubScreenCreamCells;
extern RaceHudSubScreenCells *gRaceHudSubScreenBerryCells;
extern RaceHudSubScreenCells *gRaceHudSubScreenFireball2Cells;
// Which model the Jg shows and its row in gJgKindRows: 0 lap_count, 1 lap_final, 2 jg_reverse, 3 jg_flag, 4 none.
extern s32 gJgKind;
extern s32 data_0217b8ac;
extern s32 data_0217b8c4;
extern s32 gJgVisible;
extern s32 data_0217b900;

// The Jg's state machine record, seen only through its state halfword at 0xe.
typedef struct Unk0217b9ec {
    /* 000 */ u8 mUnk_000[0xe];
    /* 00e */ u16 mState;
} Unk0217b9ec;

extern Unk0217b9ec gJgStateMachine;
extern Vec3 *gItemPushVector;
extern void *gBridge;
extern void *gBridgeNsbca;
extern void *data_0217b7c0;
extern void *data_0217b7bc;
extern void *data_0217b7b4;
extern void *data_0217b780;
extern void *data_0217b784;
extern void *gCarAShadow;
extern void *gCarANsbtp;
extern void *gCarTire;
extern void *gTruckA;
extern void *gTruckAShadow;
extern struct Unk0217b79c *data_0217b79c;
extern void *gCarA;
extern void *data_0217b7a4;
extern void *gTruckANsbtp;
extern void *gBusA;
extern void *gBusAShadow;
extern void *data_0217b7c8;
extern void *gGearWhite;
extern void *gGearBlack;
extern void *gRotaryBridge;
extern void *data_0217b7e4;
extern void *gTestCylinder;
extern void *gRotaryRoom;
extern void **gFoundCollisionSlotObjects;
extern s16 gFoundCollisionSlotCount;
extern u16 *gFoundCollisionSlotFlags;
extern s16 gFirstFreeCollisionSlot;
extern s16 gCollisionSlotCount;
extern struct CollisionSlotEnd *gCollisionSlotHighEnds;
extern struct CollisionSlot *gCollisionSlots;
extern struct CollisionSlotEnd *gCollisionSlotLowEnds;
extern s16 *gCollisionSlotNextFree;
extern s16 *gFoundCollisionSlotIndices;
extern Vec3 gPukupukuDrawScale;
extern void *gPendulum;
extern void *gPendulumShadow;
extern void *gSecondHand;
extern void *data_0217b864;
extern s32 data_0217b8b4;
extern u16 gJgFinalLap;
extern u16 gJgState2FrameCount;
extern u16 gJgKartIndex;
extern u16 data_0217b870;
extern u16 gJgHighestLap;
extern s32 data_0217b8b8;
extern s32 data_0217b88c;
extern s32 data_0217b8cc;
extern s32 data_0217b8ec;
extern s32 data_0217b8f0;
extern s32 data_0217b8bc;
extern s32 data_0217b894;
extern s32 data_0217b8f8;
extern s32 gJgLapAndReverseEnabled;
extern u16 *data_0217b8c0;
extern Vec3 gJgTargetPos;
extern Vec3 data_0217b90c;
extern Vec3 data_0217b918;
extern Vec3 data_0217b93c;
extern Vec3 data_0217b99c;
extern Vec3 gJgPos;
extern Vec3 gJgEasedPos;
extern Vec3 data_0217b9b4;
extern Vec3 gJgVelocity;
extern Vec3 gJgPoints[];
extern s16 *data_0217b8a4;
extern s16 *data_0217b8a8;
extern s16 *data_0217b8a0;
extern s16 *data_0217b8e0;
extern s16 *data_0217b904;
extern s32 gJgTableIndex;
extern u32 data_0217bb04[];
extern Vec3 data_0217b96c;
extern s32 data_0217b8d0;
extern s32 data_0217b898;
extern s32 data_0217b89c;
extern s32 data_0217b8d8;
extern s32 data_0217b908;
// Copy of the kart's position, y minus the kart's hop height (state 4 stores it without that).
extern Vec3 gJgKartPos;
extern Vec3 gJgKind4Offset;
extern Vec3 gJgLapOffset;
extern Vec3 data_0217b984;
extern Vec3 gJgPoint7;
extern Vec3 gJgPoint1;
extern Vec3 gJgPoint2;
extern Vec3 *gJgPointPointers[4];
extern u16 gJgAlpha;
extern u16 gJgAngle;
extern Vec3 gJgKind3Offset;
extern Vec3 gJgKind2Offset;
extern void *data_0217b5d0[16];
extern s32 data_0217b610;
extern CourseCollision gCourseCollision;
extern u32 data_0217bbe8;
extern Vec3 gJgMatrixAxis2;
extern Vec3 data_0217badc;
extern Vec3 data_0217bac4;
extern Vec3 gJgInverseMatrixPos;
extern s32 gJgOffsetY;
extern s32 gJgOffsetX;
extern s32 data_0217b8f4;
extern u32 data_0217b8fc;
extern s32 gItemSlotPossibleItems[];
extern s32 data_0217bc58;
// Items the spin may show after a roll with a forced row: the items with a non-zero weight in that row plus the one
// picked. Written by PickItem, cleared by CreateItemSlotTables.
extern s32 gItemSlotSpinItems[];
extern u16 gItemSlotPossibleItemCount;
// Length of gItemSlotSpinItems; 0 means the spin uses gItemSlotPossibleItems.
extern u16 gItemSlotSpinItemCount;
extern u16 gItemWeightSums[];
extern s32 gKouraWState7ScaleLimit;
extern s32 gKouraWState7InverseLimit;
extern s32 gKouraWState7ScaleStep;
extern volatile s32 data_0217bd34;
extern s32 data_0217bd48;
extern s32 data_0217bd4c;
extern s32 data_0217bd50;
extern s32 data_0217bd54;
extern s32 data_0217bd58;
extern u8 gItemDataDelayedFreeHead[];
extern u8 gItemDataQueueUsedHead[];
extern u8 gItemDataQueueFreeHead[];
extern u8 gItemDataDelayedUsedHead[];
extern u8 gItemDataQueueLinks[][2];
extern u8 gItemDataDelayedLinks[][2];
extern u8 gItemDataBuffer[];
extern u8 data_0217bdc1[];
extern u8 data_0217bd81[];
extern void *gShine16;
extern void *gAirship;
extern void *gSanboH;
extern void *gSanboB;
extern void *gIronBall;

extern MapObjectModel *gFlipper;
extern void *gBasabasa;
extern void *gMkdEfBurner;
extern void *gCow;
extern void *gKanoke64;
extern void *gNsKiller2;
extern void *gNsKiller2S;
extern void *gNsKiller1;
extern void *gTeresa;
extern void *gBakuShadow;
extern void *gBakubaku;
extern void *gMoveTree;
extern void *gCrabHand;
extern void *gCrab;
extern void *gBerry;
extern void *gCream;
extern void *gBound;
extern void *gSunLOD;
extern void *gSun;
extern void *gFireball2;
extern void *gPuddle;
extern void *gPicture1;
extern void *gPicture2;
extern void *gRainStar;
