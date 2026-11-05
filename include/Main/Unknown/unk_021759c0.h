#pragma once

#include "types.h"
#include "Main/Unknown/unk_02029930.h" // Unk02029930_f8
#include "code_0214e308.h"

typedef struct Unk0210f090 Unk0210f090;

// Three values that func_020565e4 and func_0205660c fill: a halfword and two bytes.
typedef struct Unk020565e4 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
} Unk020565e4;

// Values of Unk021759c0_70.mKind that func_02045590 stores (entry 0 gets KIND_0, the others KIND_1).
typedef enum { UNK_021759C0_70_KIND_0, UNK_021759C0_70_KIND_1 } Unk021759c0_70_Kind;

// The 0x28 bytes from 0x08 of each KartEntry entry (code keeps pointers to them).
typedef struct Unk021759c0_70 {
    /* 00 */ s32 mKind;
    /* 04 */ s32 mTeamIndex;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mIndex;
    /* 10 */ s32 mUnk_10;
    /* 14 */ u16 mUnk_14;
    /* 16 */ s8 mUnk_16;
    /* 17 */ u8 mUnk_17;
    /* 18 */ void *mName;
    /* 1c */ void *mEmblemData;
    /* 20 */ s32 mUnk_20;
    /* 24 */ u8 mUnk_24;
    /* 25 */ u8 mUnk_25;
    /* 26 */ u8 mUnk_26;
    /* 27 */ u8 mUnk_27;
} Unk021759c0_70;

// 0x30-byte entries at 0x68 and 0x250 of the object behind data_021759c0.
typedef struct KartEntry {
    /* 00 */ s32 mCharacterIndex;
    /* 04 */ s32 mKartIndex;
    // The 0x28-byte record of the entry's player: kind, team, index, name, emblem.
    /* 08 */ Unk021759c0_70 mPlayer;
} KartEntry;

// Values of the mMode member of Unk021759c0 and of Unk021759c0_1e8 (the other values stay literals). The member is set
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

// The 0x68 bytes at 0x1e8 of the object behind data_021759c0.
typedef struct Unk021759c0_1e8 {
    /* 00 */ s32 mCourseId;
    /* 04 */ s32 mCupIndex;
    /* 08 */ s32 mMode;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mCourseListMode;
    /* 24 */ s32 mUnk_24;
    /* 28 */ Unk02029930_f8 mMissionFileRow;
    /* 54 */ s8 mMissionTableRow;
    /* 55 */ s8 mMissionTableColumn;
    /* 56 */ u8 mUnk_56[0x1];
    /* 57 */ s8 mUnk_57;
    /* 58 */ u8 mUseTeams;
    /* 59 */ u8 mUnk_59[0x3];
    /* 5c */ s32 mUnk_5c;
    /* 60 */ u16 mCourseNumber;
    /* 62 */ s8 mEntryIndex;
    /* 63 */ u8 mUnk_63;
    /* 64 */ s8 mUnk_64;
    /* 65 */ u8 mUnk_65[0x3];
} Unk021759c0_1e8;

// The 0x10 bytes at 0x28 of the object behind data_021759c0 (the same bytes as its mUnk_028 to mUnk_37).
typedef struct Unk021759c0_28 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ s16 mUnk_04;
    /* 06 */ u8 mUnk_06;
    /* 07 */ u8 mUnk_07;
    /* 08 */ u8 mUnk_08[6];
    /* 0e */ u8 mUnk_0e;
    /* 0f */ u8 mUnk_0f;
} Unk021759c0_28;

// Object behind data_021759c0.
typedef struct Unk021759c0 {
    /* 00 */ s32 mCourseId;
    /* 004 */ s32 mCupIndex;
    /* 08 */ s32 mMode;
    /* 00c */ u32 mUnk_00c;
    /* 010 */ s32 mUnk_010;
    /* 014 */ s32 mUnk_014;
    /* 018 */ s32 mUnk_18;
    /* 01c */ s32 mUnk_1c;
    /* 020 */ s32 mCourseListMode;
    /* 024 */ u8 mUnk_024[0x4];
    union {
        Unk021759c0_28 mUnk_28_view;
        struct {
            /* 028 */ u16 mUnk_028;
            /* 02a */ u16 mUnk_02a;
            /* 02c */ s16 mUnk_02c;
            /* 02e */ u8 mUnk_2e;
            /* 2f */ u8 mUnk_2f;
            /* 030 */ u8 mUnk_030[0x6];
            /* 036 */ u8 mUnk_036;
            /* 37 */ u8 mUnk_37;
        };
    };
    /* 038 */ u16 mUnk_038;
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
    /* 57 */ s8 mUnk_57;
    /* 58 */ s8 mUseTeams;
    /* 059 */ u8 mUnk_059[0x3];
    /* 05c */ s32 mUnk_05c;
    /* 60 */ u16 mCourseNumber;
    /* 62 */ s8 mEntryIndex;
    /* 063 */ u8 mUnk_063;
    /* 064 */ s8 mUnk_064;
    /* 065 */ u8 mUnk_065[0x3];
    /* 68 */ KartEntry mCurrentEntries[8];
    /* 1e8 */ Unk021759c0_1e8 mNextHeader;
    /* 250 */ KartEntry mNextEntries[8];
    /* 3d0 */ u8 mKartCount;
    /* 3d1 */ u8 mUnk_3d1;
    /* 3d2 */ u8 mTeamKartCounts[2];
    /* 3d4 */ u8 mUnk_3d4;
    /* 3d5 */ s8 mUnk_3d5[3];
    /* 3d8 */ u16 mUnk_3d8;
    /* 3da */ u8 mUnk_3da[0x2];
    /* 3dc */ u8 *mCourseList;
    /* 3e0 */ u8 mCourseListIndex;
    /* 3e1 */ u8 mUnk_3e1;
    /* 3e2 */ u16 mUnk_3e2;
    /* 3e4 */ u8 mUnk_3e4;
    /* 3e5 */ u8 mUnk_3e5;
    /* 3e6 */ s8 mUnk_3e6;
    /* 3e7 */ u8 mUnk_3e7[0x1];
    /* 3e8 */ Unk020565e4 mUnk_3e8;
    /* 3ec */ Unk020565e4 mUnk_3ec[5];
} Unk021759c0;

extern Unk021759c0 *data_021759c0;

// Object behind data_021759c4; the members are the ones the code reads.
typedef struct Unk021759c4 {
    /* 00 */ TouchSample mUnk_00[5];
    /* 28 */ TouchSample mUnk_28;
    /* 30 */ union {
        u32 mUnk_30;
        struct {
            s32 mUnk_30_0 : 1;
            s32 mUnk_30_1 : 1;
            s32 mUnk_30_2 : 1;
            s32 mUnk_30_3 : 1;
        };
    };
    /* 34 */ u8 mUnk_34[0x8];
    /* 3c */ Unk0210f090 *mUnk_3c;
} Unk021759c4;

extern Unk021759c4 *data_021759c4;
