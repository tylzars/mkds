#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_0203b0a0.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0204b03c.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0205edcc.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_02056700.h"
#include "Main/Unknown/code_02057624.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0204b000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_0205b0f4.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/code_02060cb4.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a128c.h"
#include "Main/Unknown/code_021201e4.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "00/code_021832d8.h"
#include "00/code_0219b580.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0203c8dc.h"

#pragma opt_rebuildconditionals off

static inline BOOL func_0205f218_inline(void) {
    Unk0217aa00 *p;

    p = data_0217aa00;
    return (p == NULL ? 0 : p->mUnk_0000) != 0 && p->mUnk_0004 != 13;
}

u32 func_0205fe1c(u8 *a, TimeRecord *b, s32 c) {
    u8 d[10] = {0};
    u32 e;
    s32 f;
    u32 g;
    u8 m;
    s32 i;
    u16 k;
    u8 j;
    u32 n;
    s32 h;
    u8 q;
    s32 x;

    e = b->mMillisecond + (b->mSecond * 1000 + b->mMinute * 60000);
    if (e >= 240000) {
        return 0;
    }
    f = FindCupCourseIndex(c);
    if (f < 0 || f >= 32) {
        return 0;
    }
    g = b->mCharacterIndex * 37 + b->mKartIndex;
    if (g >= 0x200) {
        return 0;
    }
    e = ((e & 0x3ffff) << 14) | ((f & 0x1f) << 9);
    *(u32 *) &d[0] = e | (g & 0x1ff);
    MI_CpuCopy8(&b->mName, &d[4], 4);
    *(u16 *) &d[8] = 0;
    func_0204b284(d, 10, 1);
    x = 0xc3;
    for (h = 9; h >= 0; h--) {
        d[h] ^= x;
        x = d[h];
    }
    for (i = 0, n = 0; i < 16; i++) {
        k = 0;
        for (j = 0; j < 5; j++) {
            q = n;
            m = q + j;
            k = (u16) (k | ((d[(u8) (m / 8)] >> (u8) (7 - m % 8)) & 1)) << 1;
        }
        a[i] = data_usa_0215494c[(u8) (k / 2)];
        n += 5;
    }
    return 1;
}

s32 func_0205fdb4(s32 a, void *b) {
    TimeRecord c;
    BOOL d;

    d = FALSE;
    if (func_02056bc0(a, 0, &c) != 0 && c.mFilled != 0) {
        d = TRUE;
    }
    if (d == FALSE) {
        return 0;
    }
    return func_0205fe1c(b, &c, a);
}

s32 func_0205fd78(s32 a, s32 b, s32 *v1) {
    Unk02056a2c c;
    BOOL d;

    d = FALSE;
    func_020569dc(a, b, &c);
    if (c.mUnk_00 == 1) {
        d = TRUE;
        *v1 = c.mUnk_01;
    }
    return d;
}

u32 func_0205fd2c(KartAppear *a, u32 b, u32 c) {
    u8 d;
    u8 e;

    d = func_02056d98();
    e = a->mFileData->mUnk_06[c][b];
    if (e != 0 && e <= d) {
        return 1;
    }
    return 0;
}

BOOL func_0205fc98(KartAppear *a, u32 b, u32 c) {
    u8 d;
    u8 e;

    if (func_0205f218_inline() != FALSE) {
        d = data_0217aa08->mParticipantMinValue;
    } else {
        d = func_02056d98();
    }
    e = a->mFileData->mUnk_06[c][b];
    if (e != 0 && e <= d) {
        return TRUE;
    }
    return FALSE;
}

s32 func_0205fc28(s32 a) {
    if (func_0205f218_inline() == FALSE) {
        return func_02056dec(a);
    }
    return func_02056e00(a, data_0217aa08->mParticipantAndBits);
}

s32 func_0205fbb8(s32 a) {
    if (func_0205f218_inline() == FALSE) {
        return func_02056dec(a);
    }
    return func_02056e00(a, data_0217aa08->mParticipantOrBits);
}

void func_0205fa00(u32 a, s32 *b, u32 c, u32 d) {
    RaceSetup *p;
    BuddyRecord e;
    u16 *f;
    u16 *g;
    u8 h;
    s32 r;

    p = gRaceSetup;
    if (a == p->mEntryIndex) {
        return;
    }
    if (p->mCurrentEntries[a].mPlayer.mUnk_20 == 0) {
        return;
    }
    r = func_0206105c((const void *) p->mCurrentEntries[a].mPlayer.mUnk_20);
    if (r == -1) {
        return;
    }
    h = r;
    func_0205ee14(h, &e);
    if (e.mFilled == 0) {
        ResetBuddyRecord((u32) &e);
    }
    if (gRaceSetup->mCurrentEntries[a].mPlayer.mName != NULL) {
        MI_CpuCopy8(gRaceSetup->mCurrentEntries[a].mPlayer.mName, e.mName, 0x14);
    }
    switch (c) {
        case 0:
            f = &e.mResultCounts[0][0];
            g = &e.mResultCounts[0][1];
            break;
        case 1:
            f = &e.mResultCounts[1][0];
            g = &e.mResultCounts[1][1];
            break;
        case 2:
            f = &e.mResultCounts[2][0];
            g = &e.mResultCounts[2][1];
            break;
    }
    switch (d) {
        case 0:
            if (*f < 0xffff) {
                *f = *f + 1;
            }
            break;
        case 1:
            if (*g < 0xffff) {
                *g = *g + 1;
            }
            break;
    }
    e.mYear = b[0];
    e.mMonth = b[1];
    e.mDay = b[2];
    e.mFilled = 1;
    func_0205ee74(h, &e);
}

static inline u32 func_0205f700_inline(u16 i, u32 a) {
    if (GetKartRank(i) > a) {
        return 0;
    }
    return 1;
}

void func_0205f700(void) {
    BOOL v1;
    u32 t;
    u16 i;
    u32 a;
    u32 d;
    u32 e;
    s32 c;
    s32 r;
    s32 v2[3];

    v1 = FALSE;
    c = -1;
    if (func_0205f218_inline() == FALSE) {
        return;
    }
    if (gRaceSetup->mEntryIndex == -1) {
        return;
    }
    if (gRaceProgress->mUnk_000[(u16) gRaceSetup->mEntryIndex].mStatus == 4) {
        return;
    }
    if (gRaceProgress->mRaceDone == 0) {
        return;
    }
    GetClockDateOrDefault(v2);
    a = GetKartRank((u16) gRaceSetup->mEntryIndex);
    if (gRaceSetup->mUseTeams != 0) {
        c = gRaceSetup->mCurrentEntries[(u16) gRaceSetup->mEntryIndex].mPlayer.mTeamIndex;
    }
    d = data_0217aa08->mUnk_00->mUnk_34[0];
    e = data_0217aa08->mUnk_00->mUnk_34[1];
    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        if (i == gRaceSetup->mEntryIndex) {
            continue;
        }
        r = gRaceSetup->mCurrentEntries[i].mPlayer.mKind;
        if (r == PLAYER_KIND_CPU || r == PLAYER_KIND_NONE || r == PLAYER_KIND_GHOST) {
            continue;
        }
        if (gRaceSetup->mUseTeams != 0) {
            if (c == gRaceSetup->mCurrentEntries[i].mPlayer.mTeamIndex) {
                t = 2;
            } else {
                switch (gRaceSetup->mUnk_1c) {
                    case 0:
                    case 2:
                        t = func_0205f700_inline(i, a);
                        break;
                    case 1:
                        if (c == GetCupWinningTeam()) {
                            t = 0;
                        } else if (gRaceProgress->mUnk_000[i].mStatus == 4) {
                            t = 2;
                        } else {
                            t = 1;
                        }
                        break;
                }
            }
        } else {
            t = func_0205f700_inline(i, a);
        }
        if ((data_0217aa00->mUnk_0457 & (1 << data_0217aa00->mUnk_1e8c[data_0217aa00->mUnk_1e8c[i]])) == 0) {
            func_0205fa00(i, v2, 0, t);
        }
        if (t == 0) {
            if (d < data_usa_021653e0) {
                d++;
                v1 = TRUE;
            }
        } else if (t == 1) {
            if (e < data_usa_021653e0) {
                e++;
                v1 = TRUE;
            }
        }
    }
    if (v1 != FALSE) {
        data_0217aa08->mUnk_00->mUnk_34[0] = d;
        data_0217aa08->mUnk_00->mUnk_34[1] = e;
        func_0205edcc();
    } else {
        func_0205edf8();
    }
}

void func_0205f498(void) {
    u16 i;
    u32 a;
    u32 b;
    BOOL v1;
    u32 t;
    s32 r;
    s32 v2[5];

    v1 = FALSE;
    if (func_0205f218_inline() == FALSE) {
        return;
    }
    if (gRaceSetup->mEntryIndex == -1) {
        return;
    }
    if (gRaceProgress->mUnk_000[(u16) gRaceSetup->mEntryIndex].mStatus == 4) {
        return;
    }
    if (IsWinnerDecidedAndEndReached() == 0) {
        return;
    }
    GetClockDateOrDefault(v2);
    a = data_0217aa08->mUnk_00->mUnk_34[2];
    b = data_0217aa08->mUnk_00->mUnk_34[3];
    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        if (i == gRaceSetup->mEntryIndex) {
            continue;
        }
        r = gRaceSetup->mCurrentEntries[i].mPlayer.mKind;
        if (r == PLAYER_KIND_CPU || r == PLAYER_KIND_NONE || r == PLAYER_KIND_GHOST) {
            continue;
        }
        t = 2;
        if (IsKartOnWinningTeamAtEnd((u16) gRaceSetup->mEntryIndex) != 0) {
            if (IsKartOnWinningTeamAtEnd(i) == 0) {
                t = 0;
            }
        } else if (IsKartOnWinningTeamAtEnd(i) != 0) {
            if (gRaceProgress->mUnk_000[i].mStatus != 4) {
                t = 1;
            }
        }
        if ((data_0217aa00->mUnk_0457 & (1 << data_0217aa00->mUnk_1e8c[data_0217aa00->mUnk_1e8c[i]])) == 0) {
            func_0205fa00(i, v2, 1, t);
        }
        if (t == 0) {
            if (a < data_usa_021653e0) {
                v1 = TRUE;
                a++;
            }
        } else if (t == 1) {
            if (b < data_usa_021653e0) {
                v1 = TRUE;
                b++;
            }
        }
    }
    if (v1 != FALSE) {
        data_0217aa08->mUnk_00->mUnk_34[2] = a;
        data_0217aa08->mUnk_00->mUnk_34[3] = b;
        func_0205edcc();
    } else {
        func_0205edf8();
    }
}

void func_0205f218(void) {
    u16 i;
    u32 a;
    u32 b;
    BOOL v1;
    u32 t;
    s32 r;
    s32 v2[5];

    v1 = FALSE;
    if (func_0205f218_inline() == FALSE) {
        return;
    }
    if (gRaceSetup->mEntryIndex == -1) {
        return;
    }
    if (gRaceProgress->mUnk_000[(u16) gRaceSetup->mEntryIndex].mStatus == 4) {
        return;
    }
    if (IsWinnerDecidedAndEndReached() == 0) {
        return;
    }
    GetClockDateOrDefault(v2);
    GetKartRank((u16) gRaceSetup->mEntryIndex);
    a = data_0217aa08->mUnk_00->mUnk_34[2];
    b = data_0217aa08->mUnk_00->mUnk_34[3];
    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        if (i == gRaceSetup->mEntryIndex) {
            continue;
        }
        r = gRaceSetup->mCurrentEntries[i].mPlayer.mKind;
        if (r == PLAYER_KIND_CPU || r == PLAYER_KIND_NONE || r == PLAYER_KIND_GHOST) {
            continue;
        }
        t = 2;
        if (IsKartOnWinningTeamAtEnd((u16) gRaceSetup->mEntryIndex) != 0) {
            if (IsKartOnWinningTeamAtEnd(i) == 0) {
                t = 0;
            }
        } else if (IsKartOnWinningTeamAtEnd(i) != 0) {
            if (gRaceProgress->mUnk_000[i].mStatus != 4) {
                t = 1;
            }
        }
        if ((data_0217aa00->mUnk_0457 & (1 << data_0217aa00->mUnk_1e8c[data_0217aa00->mUnk_1e8c[i]])) == 0) {
            func_0205fa00(i, v2, 1, t);
        }
        if (t == 0) {
            if (a < data_usa_021653e0) {
                v1 = TRUE;
                a++;
            }
        } else if (t == 1) {
            if (b < data_usa_021653e0) {
                v1 = TRUE;
                b++;
            }
        }
    }
    if (v1 != FALSE) {
        data_0217aa08->mUnk_00->mUnk_34[2] = a;
        data_0217aa08->mUnk_00->mUnk_34[3] = b;
        func_0205edcc();
    } else {
        func_0205edf8();
    }
}

static inline u16 func_0205ef70_inline(u16 a) {
    s32 b;
    s32 c;
    s32 d;
    Unk0217aa1c_00 *p;

    b = GetLowByte(a);
    c = GetCourseIndexInCup();
    d = GetLowByte(b);
    p = &gCupRecords->mUnk_000[c][0];
    p += d;
    return p->mUnk_00;
}

void func_0205ef70(void) {
    u16 i;
    s32 c;
    u32 a;
    u32 b;
    u32 g;
    u16 h;
    u32 t;
    s8 m;
    s32 v1[3];

    a = data_0217aa08->mUnk_00->mUnk_34[4];
    b = data_0217aa08->mUnk_00->mUnk_34[5];
    func_0205b32c();
    if (gRaceSetup->mCourseNumber <= 3) {
        return;
    }
    if (gRaceProgress->mRaceDone == 0) {
        return;
    }
    if (gRaceProgress->mUnk_000[(u16) gRaceSetup->mEntryIndex].mStatus == 4) {
        return;
    }
    GetClockDateOrDefault(v1);
    c = GetKartCupRank((u16) gRaceSetup->mEntryIndex);
    h = func_0205ef70_inline(gRaceSetup->mEntryIndex);
    m = gWiFiSession->mKartCountCopy - 1;
    g = gWiFiSession->mKartCountCopy;
    if (m > 0) {
        if (b < m) {
            b = 0;
        } else {
            b -= m;
        }
    }
    if ((s16) (g - gRaceSetup->mKartCount) > 0) {
        a += (s16) (g - gRaceSetup->mKartCount);
        if (a > data_usa_021653e0) {
            a = data_usa_021653e0;
        }
    }
    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        t = 2;
        if (i != gRaceSetup->mEntryIndex) {
            if (c < GetKartCupRank(i)) {
                t = 0;
            } else if (c > GetKartCupRank(i)) {
                t = 1;
            }
            if (h == func_0205ef70_inline(i)) {
                t = 2;
            }
            func_0205fa00(i, v1, 2, t);
            if (t == 0) {
                if (a < data_usa_021653e0) {
                    a++;
                }
            } else if (t == 1) {
                if (b < data_usa_021653e0) {
                    b++;
                }
            }
        }
    }
    data_0217aa08->mUnk_00->mUnk_24 = GetPlayerRecordElo(func_ov000_0219bb50());
    data_0217aa08->mUnk_00->mUnk_34[4] = a;
    data_0217aa08->mUnk_00->mUnk_34[5] = b;
    func_0205edcc();
}

void func_0205eeb0(void) {
    if (gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
        switch (gRaceSetup->mMode) {
            case MODE_VS:
                func_0205f700();
                break;
            case MODE_MISSION_RUN:
                func_0203b230();
                break;
            case MODE_BATTLE:
                switch (gRaceSetup->mBattleKind) {
                    case BATTLE_KIND_BALLOON:
                        func_0205f498();
                        break;
                    case BATTLE_KIND_SHINE:
                        func_0205f218();
                        break;
                }
                break;
            case 5:
                func_0205ef70();
                break;
        }
    }
}

void func_0205ee74(u32 a, BuddyRecord *b) {
    MI_CpuCopy8(b, &data_0217aa08->mBuddyRecordBlock->mRecords[a], 0x24);
}

u32 func_0205ee14(u32 a, BuddyRecord *b) {
    if (b != NULL) {
        MI_CpuCopy8(&data_0217aa08->mBuddyRecordBlock->mRecords[a], b, 0x24);
    }
    return data_0217aa08->mBuddyRecordBlock->mRecords[a].mFilled != 0;
}
