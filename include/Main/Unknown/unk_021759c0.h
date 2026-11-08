#pragma once

#include "types.h"
#include "Main/Unknown/unk_02029930.h" // Unk02029930_f8
#include "tp.h"

typedef struct MicBuffer MicBuffer;

// A time as three parts, minute, second and millisecond; IsTimeLessThanStaffGhostTime sums them in milliseconds.
typedef struct MinuteSecondMillisecondTime {
    /* 00 */ u16 mMillisecond;
    /* 02 */ u8 mMinute;
    /* 03 */ u8 mSecond;
} MinuteSecondMillisecondTime;

// What drives an entry's kart: the player, the game's CPU, a recorded ghost, a player on another console, or nothing.
typedef enum { PLAYER_KIND_HUMAN, PLAYER_KIND_CPU, PLAYER_KIND_GHOST, PLAYER_KIND_PEER, PLAYER_KIND_NONE } PlayerKind;

// Bit set of the kinds 0, 2 and 3 (human, ghost, peer): the entries the mask tests pick out.
#define PLAYER_KIND_MASK_HUMAN_GHOST_PEER 0xd
// The 0x28 bytes from 0x08 of each KartEntry entry (code keeps pointers to them).
typedef struct KartEntryPlayer {
    /* 00 */ u32 mKind;
    /* 04 */ s32 mTeamIndex;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mIndex;
    /* 10 */ s32 mGhostRecordIndex;
    /* 14 */ u16 mUnk_14;
// Running number among the kind-1 entries; -1 when the entry has none.
    /* 16 */ s8 mNumber;
    /* 17 */ u8 mUnk_17;
    /* 18 */ void *mName;
    /* 1c */ void *mEmblemData;
    /* 20 */ s32 mUnk_20;
    /* 24 */ u8 mUnk_24;
    /* 25 */ u8 mUnk_25;
    /* 26 */ u8 mUnk_26;
    /* 27 */ u8 mUnk_27;
} KartEntryPlayer;

// 0x30-byte entries at 0x68 and 0x250 of the object behind gRaceSetup.
typedef struct KartEntry {
    /* 00 */ s32 mCharacterIndex;
    /* 04 */ s32 mKartIndex;
    // The 0x28-byte record of the entry's player: kind, team, index, name, emblem.
    /* 08 */ KartEntryPlayer mPlayer;
} KartEntry;

// Values of the mMode member of RaceSetup and of RaceSetupHeader (the other values stay literals). The member is set
// when the race is confirmed and is 0 in the menus before that.
// Grand Prix (also the value in the menus before a race is confirmed): code_0203b6ac.c:114 stores it as the next mode.
#define MODE_GRAND_PRIX 0
// Time attack: code_020bc11c.c:113 returns early in this mode (the end handling below is not run).
#define MODE_TIME_ATTACK 1
// Battle: code_020bc11c.c:119 reads the balloon or shine count of every kart only in this mode.
#define MODE_BATTLE 2
// Versus: code_0203ca38.c:36 (shared case with battle) reads the team setting mUseTeams.
#define MODE_VS 3
// Mission run: the mission row and column are read only while the mode has this value (code_02045874.c:372-373).
#define MODE_MISSION_RUN 4

// Values of the mCourseId member of RaceSetup and of RaceSetupHeader, and of the course id stored in the race
// Values of the mRaceKind member of RaceSetup and of RaceSetupHeader; 2 and 4 occur in the code and stay numbers.
// Normal race.
#define RACE_KIND_NORMAL 0
// Demo race that SetNextDemoRace sets up from the title screen.
#define RACE_KIND_DEMO 1
// Start scene: it creates RaceStartGp instead of the race HUD; set before each Grand Prix course and for mission
// column 9.
#define RACE_KIND_START_GP 3
// Award scene: the course is COURSE_ID_AWARD.
#define RACE_KIND_AWARD 5
// Staff roll: the course is COURSE_ID_STAFFROLL or COURSE_ID_STAFFROLLTRUE.
#define RACE_KIND_STAFF_ROLL 6

// setup. The value is the row of the course name table data_usa_02154228 (8 byte rows, the string pointer first):
// BuildCourseArchivePath formats the row's string as the first %s of "/data/Course/%s%s%s.carc". Each name below is
// that row's string without a trailing "_course", upper-cased, and the comment after it quotes the row index and the
// string. Only the values that occur at a compare, case label or store of the member are defined;
// the other rows stay literals.
#define COURSE_ID_OLD_YOSHI_GC 1  // row 1: "old_yoshi_gc"
#define COURSE_ID_OLD_BABY_GC 9  // row 9: "old_baby_gc"
#define COURSE_ID_OLD_MARIO_SFC 10  // row 10: "old_mario_sfc"
#define COURSE_ID_OLD_MOMO_64 11  // row 11: "old_momo_64"
#define COURSE_ID_OLD_KOOPA_AGB 0xc  // row 12: "old_koopa_agb"
#define COURSE_ID_OLD_PEACH_AGB 0xd  // row 13: "old_peach_agb"
#define COURSE_ID_OLD_LUIGI_GC 0xe  // row 14: "old_luigi_gc"
#define COURSE_ID_OLD_NOKO_SFC 0xf  // row 15: "old_noko_sfc"
#define COURSE_ID_OLD_FRAPPE_64 16  // row 16: "old_frappe_64"
#define COURSE_ID_CLOCK 0x11  // row 17: "clock_course"
#define COURSE_ID_MANSION 0x12  // row 18: "mansion_course"
#define COURSE_ID_AIRSHIP 0x13  // row 19: "airship_course"
#define COURSE_ID_CROSS 0x14  // row 20: "cross_course"
#define COURSE_ID_BANK 0x16  // row 22: "bank_course"
#define COURSE_ID_OLD_HYUDORO_64 23  // row 23: "old_hyudoro_64"
#define COURSE_ID_RIDGE 24  // row 24: "ridge_course"
#define COURSE_ID_MARIO 0x19  // row 25: "mario_course"
#define COURSE_ID_GARDEN 26  // row 26: "garden_course"
#define COURSE_ID_DESERT 27  // row 27: "desert_course"
#define COURSE_ID_TOWN 0x1c  // row 28: "town_course"
#define COURSE_ID_RAINBOW 0x1d  // row 29: "rainbow_course"
#define COURSE_ID_SNOW 0x1e  // row 30: "snow_course"
#define COURSE_ID_BEACH 0x1f  // row 31: "beach_course"
#define COURSE_ID_KOOPA 0x20  // row 32: "koopa_course"
#define COURSE_ID_PINBALL 0x21  // row 33: "pinball_course"
#define COURSE_ID_STADIUM 0x22  // row 34: "stadium_course"
#define COURSE_ID_OLD_DONUT_SFC 35  // row 35: "old_donut_sfc"
#define COURSE_ID_OLD_CHOCO_64 36  // row 36: "old_choco_64"
#define COURSE_ID_OLD_LUIGI_AGB 0x25  // row 37: "old_luigi_agb"
#define COURSE_ID_OLD_KINOKO_GC 0x26  // row 38: "old_kinoko_gc"
#define COURSE_ID_OLD_CHOCO_SFC 39  // row 39: "old_choco_sfc"
#define COURSE_ID_OLD_SKY_AGB 40  // row 40: "old_sky_agb"
#define COURSE_ID_MINI_BLOCK 41  // row 41: "mini_block_course"
#define COURSE_ID_MINI_BLOCK_64 0x2a  // row 42: "mini_block_64"
#define COURSE_ID_MINI_DOKAN_GC 0x2b  // row 43: "mini_dokan_gc"
#define COURSE_ID_MINI_STAGE1 0x2c  // row 44: "mini_stage1"
#define COURSE_ID_MINI_STAGE2 0x2d  // row 45: "mini_stage2"
#define COURSE_ID_MINI_STAGE3 0x2e  // row 46: "mini_stage3"
#define COURSE_ID_MINI_STAGE4 0x2f  // row 47: "mini_stage4"
#define COURSE_ID_MR_STAGE1 48  // row 48: "mr_stage1"
#define COURSE_ID_MR_STAGE2 0x31  // row 49: "mr_stage2"
#define COURSE_ID_MR_STAGE3 0x32  // row 50: "mr_stage3"
#define COURSE_ID_MR_STAGE4 0x33  // row 51: "mr_stage4"
#define COURSE_ID_AWARD 0x34  // row 52: "Award"
#define COURSE_ID_STAFFROLL 0x35  // row 53: "StaffRoll"
#define COURSE_ID_STAFFROLLTRUE 0x36  // row 54: "StaffRollTrue"

// The 0x68 bytes at 0x1e8 of the object behind gRaceSetup.
// Values of the mBattleKind member of RaceSetup and of RaceSetupHeader.
typedef enum { BATTLE_KIND_BALLOON, BATTLE_KIND_SHINE } BattleKind;

typedef struct RaceSetupHeader {
    /* 00 */ s32 mCourseId;
    /* 04 */ s32 mCupIndex;
    /* 08 */ s32 mMode;
    /* 0c */ s32 mRaceKind;
    /* 10 */ s32 mEngineIndex;
    /* 14 */ s32 mCpuDifficulty;
    /* 18 */ s32 mBattleKind;
    /* 1c */ s32 mRuleKind;
    /* 20 */ s32 mCourseListMode;
    /* 24 */ s32 mGhostRecordIndex;
    /* 28 */ Unk02029930_f8 mMissionFileRow;
    /* 54 */ s8 mMissionTableRow;
    /* 55 */ s8 mMissionTableColumn;
    /* 56 */ u8 mUnk_56[0x1];
    /* 57 */ s8 mMirrorMode;
    /* 58 */ u8 mUseTeams;
    /* 59 */ u8 mUnk_59[0x3];
    /* 5c */ s32 mUnk_5c;
    /* 60 */ u16 mCourseNumber;
    /* 62 */ s8 mEntryIndex;
    /* 63 */ u8 mFollowedKartIndex;
    /* 64 */ s8 mLapCount;
    /* 65 */ u8 mUnk_65[0x3];
} RaceSetupHeader;

// The 0x10 bytes at 0x28 of the object behind gRaceSetup (the same bytes as its mUnk_028 to mUnk_37).
typedef struct Unk021759c0_28 {
    /* 00 */ u16 mMissionTimeLimitFrameCount;
    /* 02 */ u16 mUnk_02;
    /* 04 */ s16 mUnk_04;
    /* 06 */ u8 mMissionTableValue;
    /* 07 */ u8 mMissionKind;
    /* 08 */ u8 mUnk_08[6];
    /* 0e */ u8 mUnk_0e;
    /* 0f */ u8 mUnk_0f;
} Unk021759c0_28;

#define CPU_DIFFICULTY_HARD 3
#define CPU_DIFFICULTY_NORMAL 2
// Difficulty of the CPU karts, the value of the CPU KART row (RaceSetup.mUnk_014 and the setup copy); 0 is not named.
#define CPU_DIFFICULTY_EASY 1
// Object behind gRaceSetup.
typedef struct RaceSetup {
    /* 00 */ s32 mCourseId;
    /* 004 */ s32 mCupIndex;
    /* 08 */ s32 mMode;
// Which kind of race scene this is (RACE_KIND_*): the display table and the scene code are chosen by it.
// The values 2 and 4 are not named.
    /* 00c */ u32 mRaceKind;
    /* 010 */ s32 mEngineIndex;
    /* 014 */ s32 mCpuDifficulty;
// Which battle this is (BattleKind): the end handling, the timer and the item tables differ.
    /* 018 */ s32 mBattleKind;
    /* 01c */ s32 mRuleKind;
    /* 020 */ s32 mCourseListMode;
    /* 024 */ u8 mUnk_024[0x4];
    union {
        Unk021759c0_28 mUnk_28_view;
        struct {
            /* 028 */ u16 mMissionTimeLimitFrameCount;
            /* 02a */ u16 mUnk_02a;
            /* 02c */ s16 mUnk_02c;
            /* 02e */ u8 mMissionTableValue;
            /* 2f */ u8 mMissionKind;
            /* 030 */ u8 mUnk_030[0x6];
            /* 036 */ u8 mUnk_036;
            /* 37 */ u8 mUnk_37;
        };
    };
    /* 038 */ u16 mFinishWaitFrameCount;
    /* 03a */ u8 mUnk_03a[0x2];
    /* 3c */ u16 mUnk_3c;
    /* 3e */ u16 mUnk_3e;
    /* 40 */ u16 mUnk_40;
    /* 42 */ u16 mUnk_42;
    /* 044 */ u16 mUnk_044;
    /* 046 */ u8 mUnk_046[0x2];
    /* 048 */ char mMissionRunStem[0xc];
    /* 54 */ s8 mMissionTableRow;
    /* 55 */ s8 mMissionTableColumn;
    /* 056 */ u8 mUnk_056[0x1];
// Nonzero in mirror mode: the side distance of the camera and the map object models are flipped.
    /* 57 */ s8 mMirrorMode;
    /* 58 */ s8 mUseTeams;
    /* 059 */ u8 mUnk_059[0x3];
    /* 05c */ s32 mUnk_05c;
    /* 60 */ u16 mCourseNumber;
    /* 62 */ s8 mEntryIndex;
    /* 063 */ u8 mFollowedKartIndex;
// Laps to run; 0 or less means the count of the course setting.
    /* 064 */ s8 mLapCount;
    /* 065 */ u8 mUnk_065[0x3];
    /* 68 */ KartEntry mCurrentEntries[8];
    /* 1e8 */ RaceSetupHeader mNextHeader;
    /* 250 */ KartEntry mNextEntries[8];
    /* 3d0 */ u8 mKartCount;
    /* 3d1 */ u8 mHumanAndPeerKartCount;
    /* 3d2 */ u8 mTeamKartCounts[2];
    /* 3d4 */ u8 mUnk_3d4;
    /* 3d5 */ s8 mUnk_3d5[3];
    /* 3d8 */ u16 mCourseCount;
    /* 3da */ u8 mUnk_3da[0x2];
    /* 3dc */ u8 *mCourseList;
    /* 3e0 */ u8 mCourseListIndex;
    /* 3e1 */ u8 mNextCpuNumber;
    /* 3e2 */ u16 mFirstGhostRecordMillisecond;
    /* 3e4 */ u8 mFirstGhostRecordMinute;
    /* 3e5 */ u8 mFirstGhostRecordSecond;
    /* 3e6 */ s8 mFirstGhostRecordFilled;
    /* 3e7 */ u8 mUnk_3e7[0x1];
    /* 3e8 */ MinuteSecondMillisecondTime mGhostTime;
    /* 3ec */ MinuteSecondMillisecondTime mGhostLapTimes[5];
} RaceSetup;

extern RaceSetup *gRaceSetup;

// Object behind gTouchMicInput; the members are the ones the code reads.
typedef struct TouchMicInput {
    /* 00 */ TPData mAutoSamples[5];
    /* 28 */ TPData mCalibratedPoint;
    /* 30 */ union {
        u32 mUnk_30;
        struct {
            s32 mTouchAutoSampling : 1;
            s32 mMicAutoSampling : 1;
            s32 mUnk_30_2 : 1;
            s32 mMicOverThreshold : 1;
        };
    };
    /* 34 */ u8 mUnk_34[0x8];
    /* 3c */ MicBuffer *mMicBuffer;
} TouchMicInput;

extern TouchMicInput *gTouchMicInput;
