#pragma once

#include "types.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "code_02146d78.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_020d849c.h"
#include "Main/Unknown/code_020d22c0.h" // Unk020f41c4_B
#include "Main/Unknown/unk_0217a000.h" // Unk0217aa1c_144_00

// Object whose first word is compared with a stored value.
typedef struct {
    /* 00 */ s32 mUnk_00;
} Unk020f36d8;

// Node with two lists of node pointers and a position pointer.
typedef struct Unk020f371c {
    /* 00 */ struct Unk020f371c *mUnk_00[3];
    /* 0c */ struct Unk020f371c *mUnk_0c[3];
    /* 18 */ Vec3 *mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ u8 mUnk_20;
    /* 21 */ u8 mUnk_21;
    /* 22 */ u8 mUnk_22;
    /* 23 */ u8 mUnk_23;
    /* 24 */ u16 mUnk_24;
    /* 26 */ u16 mUnk_26;
} Unk020f371c;

// A node and which of its two lists is used.
typedef struct {
    /* 00 */ Unk020f371c *mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk020f371c_Ref;

// Nine halfwords moved together.
typedef struct {
    /* 00 */ u16 mUnk_00[9];
} Unk020f41c4_C;

// Four positions and pointers to them.
typedef struct {
    /* 00 */ Unk020d849c mUnk_00;
    /* 60 */ s32 mUnk_60;
    /* 64 */ Vec3 *mUnk_64[4];
    /* 74 */ Vec3 mUnk_74[4];
} Unk020f3fa8;

extern Unk020f3fa8 data_0217bb88;

// Element returned through data_027e00cc: the first 0x12c bytes, which the elements of every entry share (the
// element sizes in the data_0217bc34 entries start at 0x12c).
typedef struct Unk020f41c4_A {
    /* 00 */ Unk0210bfbc mUnk_00;
    /* 44 */ s32 mUnk_44;
    /* 48 */ s32 mUnk_48;
    /* 4c */ s16 mUnk_4c;
    /* 4e */ s16 mUnk_4e;
    /* 050 */ Vec3 mUnk_50;
    /* 5c */ Vec3 mUnk_5c;
    /* 68 */ Vec3 mUnk_68;
    /* 74 */ u32 mUnk_74;
    /* 78 */ u16 mUnk_78;
    /* 7a */ u16 mUnk_7a;
    /* 7c */ Unk020f41c4_C mUnk_7c;
    /* 08e */ u8 mUnk_08e[2];
    /* 090 */ u16 *mUnk_90;
    /* 094 */ Unk02012f58 mUnk_94;
    /* 0c4 */ Vec3 mUnk_0c4;
    /* d0 */ Vec3 *mUnk_d0;
    /* 0d4 */ s32 mUnk_d4;
    /* 0d8 */ s16 mUnk_d8;
    /* 0da */ s16 mUnk_da;
    /* 0dc */ s32 mUnk_dc;
    /* e0 */ s32 mUnk_e0;
    /* 0e4 */ Vec3 mUnk_0e4;
    /* 0f0 */ Vec3 mUnk_f0;
    /* fc */ u32 mUnk_fc;
    /* 100 */ s32 mUnk_100;
    /* 104 */ struct Unk020e04b0 *mUnk_104;
    /* 108 */ Vec3 mUnk_108;
    /* 114 */ s16 mUnk_114;
    /* 116 */ s16 mUnk_116;
    /* 118 */ s16 mUnk_118;
    /* 11a */ s16 mUnk_11a;
    /* 11c */ s32 mUnk_11c;
    /* 120 */ void (*mUnk_120)(struct Unk020f41c4_A *);
    /* 124 */ void (*mUnk_124)(struct Unk020f41c4_A *, Vec3 *, Vec3 *);
    /* 128 */ u8 mUnk_128;
    /* 129 */ u8 mUnk_129[3];
} Unk020f41c4_A;

// One 0x8c entry per kart (mKarts[kart index]); the bytes of Unk0217561c_000's entry from its member 0x14 (A.X =
// B.X-0x14). mStatus: 0 racing, 1 goal reached (battle: alive), 2 battle loser, 3 ended without the goal, 4 removed.
// Placement: Race.
typedef struct RaceProgressKart {
    // 0 racing, 1 goal reached (battle: still alive at the end), 2 battle loser, 3 ended without the goal (time up, or
    // the race is over), 4 removed. Nothing switches on it, so it is a status, not a state.
    /* 00 */ s32 mStatus;
    // Frames of the current lap: counted every frame while the clock gate is on (capped at 0x57e40), read at the lap
    // pass as the time of the lap just ended, then reset.
    /* 04 */ s32 mLapFrames;
    /* 08 */ s32 mUnk_08;
    // Slot k-1 gets lap k, slot 5 the finish time. Slots of laps not yet run read 0:00.000 until the init clock value
    // is written, so GetKartBestLapTime is only meaningful after all laps.
    /* 0c */ Unk0217aa1c_144_00 mLapTimes[6];
    /* 24 */ s32 mLap;
    // Frames this kart spent in first place; written for the leader (or kart 0 in a one-kart race), read in
    // InitRaceProgress.
    /* 28 */ s32 mFirstPlaceFrames;
    /* 2c */ s32 mFinishTimeMs;
    // 0x1 local entry, 0x2 ended by the mode 2 end, 0x4 facing against the checkpoint, 0x8 finish just happened, 0x10
    // local entry ended by the goal and the post-goal wait runs, 0x20 same for a failure kind, 0x40 finish pending.
    /* 30 */ u16 mFlags;
    /* 32 */ u16 mCheckpoint;
    /* 34 */ s16 mUnk_34;
    /* 36 */ s16 mUnk_36;
    /* 38 */ u16 mRoute;
    /* 3a */ u16 mHighestLap;
    /* 3c */ union {
        u16 mUnk_3c;
        struct {
            u16 mUnk_3c_0 : 4;
            u16 mUnk_3c_4 : 4;
            u16 mUnk_3c_8 : 2;
        };
    };
    // Local entry in modes 0 and 4 only (written by FinishRaceProgressKart), else stays 0.
    /* 3e */ s16 mScore;
    /* 40 */ s32 mUnk_40;
    // ((mLap - 1) << 12 + mLapProgress) scaled by 1/laps: sort key after mLap. Fixed point, divisor unnamed.
    /* 44 */ s32 mRaceProgress;
    // Position within the lap, scaled by 1/(gCourseMap->mUnk_9c + 1). Fixed point, divisors unnamed.
    /* 48 */ s32 mLapProgress;
    /* 4c */ s32 mUnk_4c[0x10];
} RaceProgressKart;

// View of the same bytes as RaceProgressKart, shifted by 0x14 (array at RaceProgress::mUnk_000); the word at 0x14 and
// the halfword at 0x44.
typedef struct Unk0217561c_000 {
    /* 00 */ s32 mElapsedFrames;
    // Gate of the clock; cleared by func_0203e788 (finish request for ANY entry: mission goal, forced finish, kind 6),
    // not by the normal goal crossing; set only by StartRaceClock.
    /* 04 */ s32 mClockEnabled;
    /* 08 */ union {
        struct {
            /* 08 */ u16 mUnk_08;
            /* 0a */ u8 mUnk_0a;
            /* 0b */ u8 mUnk_0b;
        };
        Unk0217aa1c_144_00 mUnk_08_view;
    };
    // Frames from the file, 0 = course absent. Compared with mElapsedFrames.
    /* 0c */ u16 mRankTime;
    // Calls of FinishRaceProgressKart; set to the kart count when the race is over.
    /* 0e */ u16 mFinishedCount;
    // Only karts removed while not ended.
    /* 10 */ u16 mRemovedCount;
    /* 12 */ u8 mUnk_12[0x2];
    // Same bytes as RaceProgressKart::mStatus.
    /* 14 */ s32 mStatus;
    // Same bytes as RaceProgressKart::mLapFrames.
    /* 18 */ s32 mLapFrames;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ u16 mUnk_20;
    /* 22 */ u8 mUnk_22;
    /* 23 */ u8 mUnk_23;
    /* 24 */ u8 mUnk_24[0x10];
    /* 34 */ u16 mUnk_34;
    /* 36 */ u8 mUnk_36;
    /* 37 */ u8 mUnk_37;
    /* 38 */ s32 mLap;
    // Same bytes as RaceProgressKart::mFirstPlaceFrames.
    /* 3c */ s32 mFirstPlaceFrames;
    /* 40 */ s32 mUnk_40;
    // Same bytes as RaceProgressKart::mFlags.
    /* 44 */ u16 mFlags;
    /* 46 */ u16 mCheckpoint;
    /* 48 */ u16 mUnk_48;
    /* 4a */ u16 mUnk_4a;
    /* 4c */ u16 mUnk_4c;
    /* 4e */ u16 mUnk_4e;
    /* 50 */ union {
        u16 mUnk_50;
        struct {
            u16 mUnk_50_0 : 4;
            u16 mUnk_50_4 : 4;
            u16 mUnk_50_8 : 2;
        };
    };
    /* 52 */ s16 mUnk_52;
    /* 54 */ s32 mUnk_54;
    /* 58 */ s32 mUnk_58;
    /* 5c */ s32 mUnk_5c;
    /* 60 */ u8 mUnk_60[0x2c];
} Unk0217561c_000;

// Nine words.
typedef struct Unk0217561c_500 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
} Unk0217561c_500;

// 8-byte entries from 0x1c of the object behind RaceProgress::mUnk_4c8.
typedef struct RankTimeGpEntry {
    /* 00 */ u8 mCourseId;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} RankTimeGpEntry;

// Object behind RaceProgress::mRankTimeGpFile: header 0x1c bytes (score weights read by func_02040a8c: halfwords
// 0x0a..0x1a), then mEntryCount entries of 8 bytes. Placement: Race.
typedef struct RankTimeGp {
    /* 00 */ u8 mUnk_00[0x8];
    /* 08 */ u16 mEntryCount;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
    /* 14 */ u16 mUnk_14;
    /* 16 */ u16 mUnk_16;
    /* 18 */ u16 mUnk_18;
    /* 1a */ u16 mUnk_1a;
    /* 1c */ RankTimeGpEntry mUnk_1c[1];
} RankTimeGp;

// A row of the file behind RaceProgress::mRankPointFile: points for rank 1..8, first row of the file skipped.
// Placement: Race.
typedef struct RankPointRow {
    /* 00 */ u8 mPoints[8];
} RankPointRow;

// Race object behind gRaceProgress (0x524 bytes, made by CreateRaceProgress from InitRace, stepped every frame by
// UpdateRaceProgress). Per-kart progress and status (mKarts, 8 entries), the rank order (mKartAtRank), the race clock
// in the header bytes (the second view Unk0217561c_000 gives its first 0x14 bytes), two loaded files (rankpoint.rpt,
// ranktimeGP.rtt), three random generators (mRandom synced, mLocalRandom per console, a third with a fixed seed used in
// mode 5) and race-done / time-limit flags. 17 files use only the generators. Placement: Race.
typedef struct RaceProgress {
    union {
        struct {
            /* 000 */ Unk0217561c_000 mUnk_000[8];
            /* 460 */ u8 mUnk_460[0x14];
        };
        struct {
            /* 000 */ u8 mUnk_00_header[0x14];
            /* 014 */ RaceProgressKart mKarts[8];
        };
    };
    /* 474 */ s8 mKartAtRank[8];
    // Synced random generator; also stepped once per frame for the clock display jitter (GetRaceClockTime), only while
    // the clock gate is on.
    /* 47c */ Unk020f41c4_B mRandom;
    // Written once, never read; mNextHeader.mUnk_5c holds the same value.
    /* 494 */ s32 mSeed;
    // Random generator seeded from three func_0200f5ac calls, not from mSeed. Local means this console, not the local
    // player (mFlags bit 1 is the local entry). Mode 1 uses it where the other modes use mRandom.
    /* 498 */ Unk020f41c4_B mLocalRandom;
    /* 4b0 */ Unk020f41c4_B mUnk_4b0;
    /* 4c8 */ RankTimeGp *mRankTimeGpFile;
    // Set once, in every mode; gates the HUD and net code.
    /* 4cc */ s32 mRaceDone;
    /* 4d0 */ s32 mUnk_4d0;
    // Entry i is the fraction of the lap at numbered checkpoint i (fixed point), compared with a kart's mLapProgress.
    /* 4d4 */ s32 *mCheckpointLapProgress;
    /* 4d8 */ u8 mUnk_4d8[0x4];
    /* 4dc */ RankPointRow *mRankPointFile;
    /* 4e0 */ s32 mUnk_4e0;
    /* 4e4 */ s32 mUnk_4e4;
    /* 4e8 */ s32 mUnk_4e8;
    // Read only by ComputeRaceTime: the clock counts down from mTimeLimitFrameCount. Set at init: TRUE in mode 4
    // (unless mUnk_2f is 6) and in mode 2 if mUnk_18 is 1.
    /* 4ec */ BOOL mTimeCountsDown;
    /* 4f0 */ s32 mUnk_4f0;
    // In frames; 0 = none, clock cap 0x57e40. Compared with the frame clock; mode 2 value is mSettings->mUnk_02 * 0x3c.
    /* 4f4 */ u32 mTimeLimitFrameCount;
    /* 4f8 */ u8 mStartPlacementOffset;
    /* 4f9 */ u8 mUnk_4f9;
    // Mode 4 only: counted while the local entry ended with flag 0x10, zeroed by func_0203e788. No init write (zero
    // from the allocation).
    /* 4fa */ u16 mFramesSinceFinish;
    /* 4fc */ u16 mUnk_4fc;
    /* 4fe */ u16 mUnk_4fe;
    /* 500 */ Unk0217561c_500 mUnk_500;
} RaceProgress;

// Entry of the table behind data_0217bc34.
typedef struct {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ u8 mUnk_14[4];
    /* 18 */ void (*mUnk_18)(void *);
    /* 1c */ void (*mUnk_1c)(void *);
    /* 20 */ void (*mUnk_20)(void *, void *);
    /* 24 */ s32 (*mUnk_24)(void *, void *);
    /* 28 */ void (*mUnk_28)(struct Unk020f41c4_A *);
    /* 2c */ void (*mUnk_2c)(void *, void *, void *);
    /* 30 */ s32 (*mUnk_30)(Vec3 *, s32, s32, s32, u16);
    /* 34 */ UnkWordFunc *mUnk_34;
    /* 38 */ void (*mUnk_38)(void *);
    /* 3c */ void (*mUnk_3c)(void *);
    /* 40 */ s32 mUnk_40;
    /* 44 */ s32 mUnk_44;
    /* 48 */ void *(*mUnk_48)(void *, void *, s32);
    /* 4c */ s32 mUnk_4c;
    /* 50 */ void (*mUnk_50)(void *);
    /* 54 */ s32 mUnk_54;
    /* 58 */ u32 mUnk_58;
    /* 5c */ s32 mUnk_5c;
    /* 60 */ s32 mUnk_60;
    /* 64 */ s32 mUnk_64;
    /* 68 */ s32 mUnk_68;
    /* 6c */ s32 mUnk_6c;
    /* 70 */ s32 mUnk_70;
    /* 74 */ s32 mUnk_74;
    /* 78 */ s32 mUnk_78;
    /* 7c */ s32 mUnk_7c;
    /* 80 */ s32 mUnk_80;
    /* 84 */ s32 mUnk_84;
    /* 88 */ s32 mUnk_88;
    /* 8c */ u8 mUnk_8c[4];
    /* 90 */ s32 mUnk_90;
    /* 94 */ s32 mUnk_94;
    /* 98 */ s32 mUnk_98;
    /* 9c */ s32 mUnk_9c;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ s32 mUnk_a4;
} Unk0217bc34;

extern Unk0217bc34 data_02159dac;

extern Unk0217bc34 data_0215a244;

extern Unk0217bc34 data_0215a308;

extern Unk0217bc34 data_02159e70;

extern Unk0217bc34 data_0215a4dc;

extern Unk0217bc34 data_02159f84;

extern Unk0217bc34 data_02159abc;

extern Unk0217bc34 data_02159cdc;

extern Unk0217bc34 data_021599f8;

extern Unk0217bc34 data_021596bc;

extern Unk0217bc34 data_0215978c;

extern Unk0217bc34 data_02159854;

extern Unk0217bc34 data_02159934;

// Two words of a row of data_0215961c.
typedef struct {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk020f41c4_Pair;

// Row of data_0215961c.
typedef struct {
    /* 00 */ Unk020f41c4_Pair mUnk_00[3];
} Unk020f41c4_Row;

// One of the 18 items: the object kind and the number of objects it takes from the pool, the use kind and the hook
// called after its use. gItemInfos holds the heap copy of 18 static records of this type; the roulette may roll an item
// only while mEnabled is set.
typedef struct ItemInfo {
    // Gate of the roll and of the hand-over of the rolled item; set per mode by CreateItemInfos
    /* 00 */ BOOL mEnabled;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mObjectKind;
    /* 0c */ s32 mObjectCount;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ UnkFunc *mUnk_18;
} ItemInfo;

extern ItemInfo data_0215a4c0;

extern ItemInfo data_0215a174;

extern ItemInfo data_0215a2ec;

extern ItemInfo data_02159d90;

extern ItemInfo data_021599dc;

extern ItemInfo data_021598fc;

extern ItemInfo data_02159680;

extern ItemInfo data_02159f4c;

extern ItemInfo data_02159aa0;

extern ItemInfo data_02159cc0;

extern ItemInfo data_02159e54;

extern ItemInfo data_02159664;

extern ItemInfo data_021596a0;

extern ItemInfo data_02159f68;

extern ItemInfo data_02159770;

extern ItemInfo data_02159838;

extern ItemInfo data_02159918;

// Entry of the table behind data_027e00cc.
typedef struct {
    /* 00 */ s32 mUnk_00;
    /* 04 */ Unk020f41c4_A **mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ void (*mUnk_24)(void *, void *, void *);
    /* 28 */ s32 (*mUnk_28)(Vec3 *, s32, s32, s32, u16);
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
    /* 3c */ s32 mUnk_3c;
    /* 40 */ s32 mUnk_40;
} Unk027e00cc;

// Value of the first word of Unk020f40dc.
typedef enum { UNK_020F40DC_KIND_0 } Unk020f40dc_Kind;

// Object handled by func_020f40dc and the functions after it.
typedef struct {
    /* 00 */ s32 mUnk_00;
    /* 04 */ struct KartItems *mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s16 mUnk_10;
    /* 12 */ s16 mUnk_12;
    /* 14 */ Unk020f41c4_A *mUnk_14[3];
    /* 20 */ s32 mUnk_20;
    /* 24 */ BOOL mUnk_24;
} Unk020f40dc;

extern Kart *GetKart(s32 idx);
#include "Main/Unknown/code_020d6dc0.h"

extern s32 data_0217bc38[];
extern Unk0217bc34 *data_0217bc34;
extern RaceProgress *gRaceProgress;
extern Unk020f41c4_Row data_0215961c[];
extern ItemInfo *gItemInfos;
extern Unk027e00cc *data_027e00cc;

u8 func_020f36d8(Unk020f36d8 *p);
void func_020f371c(Unk020f371c_Ref *in, Unk020f371c_Ref *out, u32 idx, s32 flag);
BOOL func_020f3a58(Unk020f371c_Ref *in, Unk020f371c_Ref *out, Vec3 *pos);
BOOL func_020f3bb4(Unk020f371c_Ref *a, Unk020f371c_Ref *b, Unk020f371c_Ref *out, Vec3 *pos);
BOOL func_020f3c54(Unk020f371c_Ref *in, Unk020f371c_Ref *out, Vec3 *pos);
s32 func_020f3fa8(Unk020f3fa8 *p, Vec3 *v);
void func_020f4020(Unk020f3fa8 *p, Vec3 *points, s32 scale);
s32 func_020f4090(s32 idx);
void func_020f40a0(s32 idx, s32 amount);
void func_020f40dc(Unk020f40dc *rec, s32 kind, s32 count);
void func_020f413c(Unk020f40dc *rec, s32 *kind, s32 *count);
void func_020f4188(Unk020f40dc *rec, s32 v);
BOOL func_020f4198(Unk020f40dc *rec, s32 v);
void func_020f41b0(Unk020f40dc *rec);
void func_020f41c4(Unk020f40dc *rec);
void func_020f45f0(Unk020f40dc *rec, s32 keep);
void func_020f4718(Unk020f40dc *rec);
void func_020f4754(Unk020f40dc *rec, s32 n);
void func_020f47e4(Unk020f40dc *rec, s32 kind);
void func_020f4884(Unk020f40dc *rec);
