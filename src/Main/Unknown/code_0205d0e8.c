#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

// Zeroes the ten-byte records of the eight karts in the four courses and the team points and win counts.
void ResetCupRecords(void) {
    CupRecords *p;
    s32 course;
    s32 kart;
    s32 team;
    KartCourseResult *record;
    BOOL x;
    Unk0217aa1c_144_00 *teamRecord;

    p = gCupRecords;
    for (course = 0; course < 4; course++) {
        for (kart = 0; kart < 8; kart++) {
            record = &p->mUnk_000[course][kart];
            record->mUnk_03 = 0;
            record->mUnk_04 = 0;
            record->mTotalPoints = 0;
            record->mWinCount = 0;
            record->mUnk_02 = 0;
            record->mUnk_08 = 0;
            record->mUnk_09 = 0;
            record->mUnk_06 = 0;
        }
        for (team = 0; team < 2; team++) {
            teamRecord = &p->mUnk_144[course].mUnk_00[team];
            teamRecord->mUnk_00 = 0;
            teamRecord->mUnk_02 = 0;
        }
    }
    x = FALSE;
    if ((data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000) != 0 && data_0217aa00->mUnk_0004 != 13) {
        x = TRUE;
    }
    if (x != FALSE) {
        gCupRecords->mUnk_164_0 = 1;
    } else {
        gCupRecords->mUnk_164_0 = 0;
    }
    p->mUnk_140 = 0;
}

u8 GetCourseIndexInCup(void) {
    return (gRaceSetup->mCourseNumber - 1) % 4;
}

// Stores rank and points; the total adds the previous course's (max 9999), rank 1 raises the win count (max 99).
void SetKartCourseResult(u32 kart, s32 rank, u32 points) {
    RaceSetup *p;
    s8 i, j;
    s32 t, k, m;
    u16 previousTotal;
    u8 winCount;
    KartCourseResult *record;

    p = gRaceSetup;
    t = (p->mCourseNumber - 1) % 4;
    m = p->mMode;
    k = (u8) t - 1;
    i = k;
    if (m == MODE_BATTLE || m == MODE_VS || m == 5) {
        if (i < 0) {
            i = i + 4;
        }
    }
    if (i < 0) {
        previousTotal = 0;
    } else {
        previousTotal = gCupRecords->mUnk_000[i][(u8) kart].mTotalPoints;
    }
    j = k;
    if (m == MODE_BATTLE || m == MODE_VS || m == 5) {
        if (j < 0) {
            j = j + 4;
        }
    }
    if (j < 0) {
        winCount = 0;
    } else {
        winCount = gCupRecords->mUnk_000[j][(u8) kart].mWinCount;
    }
    record = &gCupRecords->mUnk_000[(u8) t][(u8) kart];
    record->mUnk_03 = rank;
    record->mUnk_04 = points;
    record->mTotalPoints = previousTotal + points;
    if (record->mTotalPoints > 9999) {
        record->mTotalPoints = 9999;
    }
    if (rank == 1) {
        winCount = winCount + 1;
    }
    if (winCount > 99) {
        winCount = 99;
    }
    record->mWinCount = winCount;
}

void ClearKartCourseTotalPoints(u32 kart) {
    gCupRecords->mUnk_000[(u8) ((gRaceSetup->mCourseNumber - 1) % 4)][(u8) kart].mTotalPoints = 0;
}

void func_0205d88c(u32 a, s32 b) {
    RaceSetup *p;
    s8 i;
    s32 m, t, k;
    u8 c;
    KartCourseResult *e;

    p = gRaceSetup;
    t = (p->mCourseNumber - 1) % 4;
    m = p->mMode;
    k = (u8) t - 1;
    i = k;
    if (m == MODE_BATTLE || m == MODE_VS || m == 5) {
        if (i < 0) {
            i = i + 4;
        }
    }
    if (i < 0) {
        c = 0;
    } else {
        c = gCupRecords->mUnk_000[i][(u8) a].mWinCount;
    }
    e = &gCupRecords->mUnk_000[(u8) t][(u8) a];
    e->mUnk_04 = 0;
    e->mUnk_03 = 1;
    e->mTotalPoints = 0;
    if (b != 0) {
        c = c + 1;
    }
    if (c > 99) {
        c = 99;
    }
    e->mWinCount = c;
}

void SetKartCourseFinishTime(u32 kart, Unk0217aa1c_144_00 *finishTime) {
    KartCourseResult *record;
    Unk0217aa1c_144_00 *recordTime;

    record = &gCupRecords->mUnk_000[(u8) ((gRaceSetup->mCourseNumber - 1) % 4)][(u8) kart];
    recordTime = (Unk0217aa1c_144_00 *) &record->mUnk_06;
    recordTime->mUnk_02 = finishTime->mUnk_02;
    recordTime->mUnk_03 = finishTime->mUnk_03;
    recordTime->mUnk_00 = finishTime->mUnk_00;
}

void GetKartCourseFinishTime(Unk0217aa1c_144_00 *finishTime, u32 kart, u32 course) {
    KartCourseResult *record;
    Unk0217aa1c_144_00 *recordTime;

    record = &gCupRecords->mUnk_000[course][(u8) kart];
    recordTime = (Unk0217aa1c_144_00 *) &record->mUnk_06;
    finishTime->mUnk_02 = recordTime->mUnk_02;
    finishTime->mUnk_03 = recordTime->mUnk_03;
    finishTime->mUnk_00 = recordTime->mUnk_00;
}

void SetKartCupRank(s32 kart, u8 rank) {
    gCupRecords->mUnk_000[(u8) ((gRaceSetup->mCourseNumber - 1) % 4)][(u8) kart].mUnk_02 = rank;
}

// Flags the team as winning this course and clears the flag of the other team.
void SetCupWinningTeam(s32 team) {
    s32 otherTeam;
    Unk0217aa1c_144_00 *p, *q;

    otherTeam = 0;
    if (team == 0) {
        otherTeam = 1;
    }
    p = gCupRecords->mUnk_144[(u8) ((gRaceSetup->mCourseNumber - 1) % 4)].mUnk_00;
    p[team].mUnk_03_0 = 1;
    q = gCupRecords->mUnk_144[(u8) ((gRaceSetup->mCourseNumber - 1) % 4)].mUnk_00;
    q[otherTeam].mUnk_03_0 = 0;
}

// Stores each team's win count (the winning team gains one, max 99) and its karts' total points (max 9999).
void SetTeamWinCountsAndPoints(s32 winningTeam) {
    s32 team;
    u16 kart, points;
    u32 winCount;
    s8 i;
    Unk0217aa1c_144 *v1;
    Unk0217aa1c_144_00 *teamRecord;

    for (team = 0; team < 2; team++) {
        points = 0;
        v1 = &gCupRecords->mUnk_144[(u8) ((gRaceSetup->mCourseNumber - 1) % 4)];
        teamRecord = &v1->mUnk_00[(s32) team];
        i = (u8) ((gRaceSetup->mCourseNumber - 1) % 4) - 1;
        if (gRaceSetup->mMode == MODE_BATTLE || gRaceSetup->mMode == MODE_VS || gRaceSetup->mMode == 5) {
            if (i < 0) {
                i = i + 4;
            }
        }
        if (i < 0) {
            winCount = 0;
        } else {
            winCount = gCupRecords->mUnk_144[i].mUnk_00[team].mUnk_02;
        }
        if (team == winningTeam) {
            winCount = (u8) (winCount + 1);
        }
        if (winCount > 99) {
            winCount = 99;
        }
        teamRecord->mUnk_02 = winCount;
        for (kart = 0; kart < (u32) gRaceSetup->mKartCount; kart++) {
            if (team == gRaceSetup->mCurrentEntries[kart].mPlayer.mTeamIndex) {
                points =
                    points + gCupRecords->mUnk_000[(u8) ((gRaceSetup->mCourseNumber - 1) % 4)][(u8) (s32) (u8) kart]
                                 .mTotalPoints;
            }
        }
        if (points > 9999) {
            points = 9999;
        }
        teamRecord->mUnk_00 = points;
    }
}

// Zero outside Grand Prix, VS and mode 5.
s32 GetKartCupRank(u32 kart) {
    s32 mode;
    KartCourseResult *v1;
    KartCourseResult *record;

    mode = gRaceSetup->mMode;
    if (mode == MODE_GRAND_PRIX || mode == MODE_VS || mode == 5) {
        v1 = gCupRecords->mUnk_000[(u8) ((gRaceSetup->mCourseNumber - 1) % 4)];
        record = &v1[(u8) kart];
        return record->mUnk_02;
    }
    return 0;
}

s32 GetCupWinningTeam(void) {
    s32 team, winningTeam;
    Unk0217aa1c_144 *p;

    winningTeam = -1;
    p = &gCupRecords->mUnk_144[(u8) ((gRaceSetup->mCourseNumber - 1) % 4)];
    for (team = 0; team < 2; team++) {
        if (p->mUnk_00[(u32) team].mUnk_03_0) {
            winningTeam = team;
            break;
        }
    }
    return winningTeam;
}

// 0 for the first course; battle, VS and mode 5 wrap to the fourth course.
u16 GetKartPreviousTotalPoints(u32 kart) {
    s32 mode;
    s8 previousCourse;

    mode = gRaceSetup->mMode;
    previousCourse = (u8) ((gRaceSetup->mCourseNumber - 1) % 4) - 1;
    if (mode == MODE_BATTLE || mode == MODE_VS || mode == 5) {
        if (previousCourse < 0) {
            previousCourse = previousCourse + 4;
        }
    }
    if (previousCourse < 0) {
        return 0;
    }
    return gCupRecords->mUnk_000[previousCourse][(u8) kart].mTotalPoints;
}

// 0 for the first course; battle, VS and mode 5 wrap to the fourth course.
u8 GetKartPreviousWinCount(u32 kart) {
    s32 mode;
    s8 previousCourse;

    mode = gRaceSetup->mMode;
    previousCourse = (u8) ((gRaceSetup->mCourseNumber - 1) % 4) - 1;
    if (mode == MODE_BATTLE || mode == MODE_VS || mode == 5) {
        if (previousCourse < 0) {
            previousCourse = previousCourse + 4;
        }
    }
    if (previousCourse < 0) {
        return 0;
    }
    return gCupRecords->mUnk_000[previousCourse][(u8) kart].mWinCount;
}

// The previous course's rank in Grand Prix, VS and mode 5 (VS and mode 5 wrap); else the kart count minus the index.
u8 GetKartStartRank(u32 kart) {
    RaceSetup *p;
    s32 mode;
    s8 previousCourse;
    u8 rank;

    p = gRaceSetup;
    mode = p->mMode;
    previousCourse = (u8) ((p->mCourseNumber - 1) % 4) - 1;
    if (mode == MODE_BATTLE || mode == MODE_VS || mode == 5) {
        if (previousCourse < 0) {
            previousCourse = previousCourse + 4;
        }
    }
    if (mode == MODE_GRAND_PRIX || mode == MODE_VS || mode == 5) {
        if (previousCourse < 0) {
            rank = p->mKartCount - kart;
        } else {
            rank = gCupRecords->mUnk_000[previousCourse][(u8) kart].mUnk_03;
        }
    } else {
        rank = p->mKartCount - kart;
    }
    if (rank == 0) {
        rank = p->mKartCount - kart;
    }
    return rank;
}

s32 func_0205d190(void) {
    RaceSetup *p;
    CupRecords *q;
    s32 a, x, y, z;
    u16 v, c;
    u32 d;

    p = gRaceSetup;
    q = gCupRecords;
    c = p->mEntryIndex;
    a = q->mUnk_140;
    d = (u8) c;
    v = q->mUnk_000[(u8) ((p->mCourseNumber - 1) % 4)][(u8) d].mTotalPoints;
    if (a >= 1000) {
        x = 0;
    } else if (a >= 700) {
        x = 1;
    } else if (a >= 400) {
        x = 2;
    } else if (a >= 200) {
        x = 3;
    } else if (a >= 0) {
        x = 4;
    } else {
        x = 5;
    }
    if (v >= 40) {
        y = 0;
    } else if (v >= 36) {
        y = 1;
    } else if (v >= 30) {
        y = 2;
    } else if (v >= 20) {
        y = 3;
    } else {
        y = 4;
    }
    z = x + y;
    if (z >= 8) {
        z = 7;
    }
    return 7 - z;
}

s32 func_0205d140(void) {
    s32 a;

    a = gCupRecords->mUnk_140;
    if (a >= 100) {
        return 7;
    }
    if (a >= 90) {
        return 6;
    }
    if (a >= 70) {
        return 5;
    }
    if (a >= 50) {
        return 4;
    }
    if (a >= 0) {
        return 3;
    }
    return 2;
}

// Copies the records of kart from over those of kart to in all four courses.
void CopyKartCupRecords(u8 from, u8 to) {
    s32 i;

    for (i = 0; i < 4; i++) {
        MI_CpuCopy8(&gCupRecords->mUnk_000[i][from], &gCupRecords->mUnk_000[i][to], 10);
    }
}
