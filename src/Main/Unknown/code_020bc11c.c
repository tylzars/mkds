#include "Main/Unknown/code_020bc11c.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020b19b4.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0203c8c0.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020cffd0.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b1000.h"
#include "Main/Unknown/code_020b19f8.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020b85dc.h"
#include "code_020222ec.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_02044618.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020b1cf4.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020b33d8.h"
#include "Main/Unknown/code_020b6e00.h"
#include "Main/Unknown/code_020b8000.h"
#include "Main/Unknown/code_020b3000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_020be7fc.h"
#include "Main/Unknown/code_020be930.h"
#include "Main/Unknown/code_0203c5f8.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"

void StopRaceRankListItemInUse(int kartIndex) {
    gRaceRankList->mUnk_0fc[kartIndex].mUnk_00 = 0;
}

// Starts the 0x24-frame display of the item kart kartIndex has just put in use; its cell blinks.
void StartRaceRankListItemInUse(s32 kartIndex, s32 itemId, s32 b) {
    gRaceRankList->mUnk_0fc[kartIndex].mUnk_00 = 1;
    gRaceRankList->mUnk_0fc[kartIndex].mUnk_04 = itemId;
    gRaceRankList->mUnk_0fc[kartIndex].mUnk_08 = b;
}

void InitRaceRankList(void) {
    u8 i;

    gRaceRankList = HeapAlloc(GetHeap(func_020364e8()), 0x15c);
    for (i = 0; i < (s32) gRaceSetup->mKartCount; i++) {
        gRaceRankList->mUnk_080[i] = 1;
        gRaceRankList->mUnk_060[i] = gRaceRankList->mUnk_080[i];
        gRaceRankList->mUnk_0a0[i] = 0;
        gRaceRankList->mUnk_0c0[i] = 0;
    }
    gRaceRankList->mUnk_0e0 = 0;
    gRaceRankList->mUnk_0e4 = 0;
    gRaceRankList->mUnk_0e8[0] = 0xc4e;
    gRaceRankList->mUnk_0e8[1] = 0;
    gRaceRankList->mUnk_0e8[2] = 0;
    gRaceRankList->mUnk_0e8[3] = 0xc4e;
    gRaceRankList->mUnk_0f8 = 0;
}

u32 ClearRaceRankListPointer(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gRaceRankList;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

// Every 0x1c calls it re-reads each kart's rank and slides its row from the old rank slot to the new one.
void UpdateRaceRankList(void) {
    Unk0217b3d8_00 t[9] = {{0x1b, 0xf},  {0x1b, 0xf},  {0x1b, 0x26}, {0x1b, 0x3d}, {0x1b, 0x54},
                           {0x1b, 0x6b}, {0x1b, 0x82}, {0x1b, 0x99}, {0x1b, 0xb0}};
    Unk0217b3d8_00 v1;
    Unk0217b3d8_00 v2;
    Unk0217b3d8_00 v3;
    s32 b[8];
    s32 tick;
    s32 k;
    u8 i;
    KartItems *o;

    tick = gRaceRankList->mUnk_0f8;
    if (GetRaceStartSequenceFrames() <= 0x188) {
        gRaceRankList->mUnk_0e0 = (0x20 - (GetRaceStartSequenceFrames() - 0x168)) * 4;
    } else {
        gRaceRankList->mUnk_0e0 = 0;
    }
    if (GetRaceStartSequenceFrames() < 0x168) {
        return;
    }
    if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
        return;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        return;
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        for (i = 0; i < (s32) gRaceSetup->mKartCount; i++) {
            gRaceRankList->mUnk_0c0[i] = GetBalloonOrShineCount(i);
        }
    }
    for (i = 0; i < (s32) gRaceSetup->mKartCount; i++) {
        o = &gKartItems[i];
        gRaceRankList->mUnk_040[i] = o->mHeldItem.mItemInfoIndex == 0x13 ? o->mActiveItem : o->mHeldItem.mItemInfoIndex;
        if (gRaceRankList->mUnk_0f8 % 0x1c == 0) {
            gRaceRankList->mUnk_060[i] = gRaceRankList->mUnk_080[i];
            gRaceRankList->mUnk_080[i] = GetKartRank(i);
        }
        v1 = t[gRaceRankList->mUnk_060[i]];
        v2 = t[gRaceRankList->mUnk_080[i]];
        if (gRaceRankList->mUnk_060[i] > gRaceRankList->mUnk_080[i]) {
            if (tick < 10) {
                v3.mUnk_00 = v1.mUnk_00 + (tick * 16) / 10;
                v3.mUnk_04 = v1.mUnk_04;
            } else if (tick < 0x12) {
                k = tick - 10;
                v3.mUnk_00 = v1.mUnk_00 + (v2.mUnk_00 - v1.mUnk_00) * k / 8 + 0x10;
                v3.mUnk_04 = v1.mUnk_04 + (v2.mUnk_04 - v1.mUnk_04) * k / 8;
            } else {
                v3.mUnk_00 = v1.mUnk_00 + 0x10 - ((tick - 0x12) * 16) / 10;
                v3.mUnk_04 = v2.mUnk_04;
            }
        } else {
            v3.mUnk_00 = v1.mUnk_00 + tick * (v2.mUnk_00 - v1.mUnk_00) / 0x1c;
            v3.mUnk_04 = v1.mUnk_04 + tick * (v2.mUnk_04 - v1.mUnk_04) / 0x1c;
        }
        gRaceRankList->mUnk_000[i] = v3;
    }
    for (i = 0; i < (s32) gRaceSetup->mKartCount; i++) {
        gRaceRankList->mUnk_0a0[i] = i;
        b[i] = gRaceRankList->mUnk_080[i];
    }
    SortIndicesByKey(gRaceRankList->mUnk_0a0, b, gRaceSetup->mKartCount);
    gRaceRankList->mUnk_0f8++;
    if (gRaceRankList->mUnk_0f8 >= 0x1c) {
        gRaceRankList->mUnk_0f8 = 0;
    }
    for (i = 0; i < (s32) gRaceSetup->mKartCount; i++) {
        if (gRaceRankList->mUnk_0fc[i].mUnk_00 != 0) {
            gRaceRankList->mUnk_0fc[i].mUnk_00++;
            if (gRaceRankList->mUnk_0fc[i].mUnk_00 > 0x24) {
                gRaceRankList->mUnk_0fc[i].mUnk_00 = 0;
            }
        }
    }
}

void DrawRaceRankList(RaceHudOamBuffer *a) {
    s32 *e;
    Unk020224e0_o *p;

    if (GetRaceStartSequenceFrames() < 0x168) {
        return;
    }
    gRaceRankList->mUnk_0e4 = func_020ae5c4(a);
    switch (gRaceSetup->mMode) {
        case MODE_GRAND_PRIX:
        case MODE_VS:
        case 5:
            func_020bd7f8(a);
            break;
        case MODE_BATTLE:
            switch (GetRaceHudSubScreenState()) {
                case 0:
                    func_020bd178(a);
                    break;
                case 1:
                case 2:
                case 3:
                    func_020bcbe8(a);
                    break;
            }
            break;
    }
    e = gRaceRankList->mUnk_0e8;
    p = &a->mOams[gRaceRankList->mUnk_0e4 * 4];
    p[0].mUnk_00[3] = e[0] >> 4;
    p[1].mUnk_00[3] = e[1] >> 4;
    p[2].mUnk_00[3] = e[2] >> 4;
    p[3].mUnk_00[3] = e[3] >> 4;
}

// Returns the cell index beside the kart (0xc9 = none): cell 0x24 or 0x25, the item just used, the held item or 0x16.
u32 GetRaceRankListSNcerIndex(u16 kartIndex) {
    u32 cellIndex;
    Unk0217b3d8 *d;
    Unk0217b3d8_fc *e;
    s32 v;

    if (func_020b1cf4(kartIndex) != 0) {
        cellIndex = 0x25;
    } else if (gRaceSetup->mMode == MODE_BATTLE && IsKartOnWinningTeamAtEnd(kartIndex) != 0) {
        cellIndex = 0x24;
    } else if (gRaceSetup->mMode == MODE_BATTLE && IsKartEliminated(kartIndex) != FALSE) {
        cellIndex = 0xc9;
    } else if (gRaceSetup->mMode != MODE_BATTLE && IsKartEnded(kartIndex) != 0) {
        cellIndex = 0x24;
    } else if ((d = gRaceRankList)->mUnk_0fc[kartIndex].mUnk_00 != 0) {
        v = d->mUnk_0fc[kartIndex].mUnk_00 - 1;
        if (v % 12 < 6) {
            cellIndex = 0xc9;
        } else if ((e = (Unk0217b3d8_fc *) &d->mUnk_0fc[0].mUnk_04)[kartIndex].mUnk_00 == 5) {
            switch (d->mUnk_0fc[kartIndex].mUnk_08) {
                case 1:
                    cellIndex = 0x11;
                    break;
                case 2:
                    cellIndex = 0x12;
                    break;
                case 3:
                    cellIndex = 0x13;
                    break;
            }
        } else {
            cellIndex = LookupRaceSNcerIndex(kartIndex, e[kartIndex].mUnk_00);
        }
    } else if (d->mUnk_040[kartIndex] != 0x13) {
        cellIndex = LookupRaceSNcerIndex(kartIndex, d->mUnk_040[kartIndex]);
    } else if (gKartItems[kartIndex].mSlotState == 1) {
        cellIndex = 0x16;
    } else {
        cellIndex = 0xc9;
    }
    return cellIndex;
}

void func_020bdf08(RaceHudOamBuffer *a) {
    s32 t[8][2] = {{8, 0xf}, {8, 0x26}, {8, 0x3d}, {8, 0x54}, {8, 0x6b}, {8, 0x82}, {8, 0x99}, {8, 0xb0}};
    u16 i;
    s32 e;
    s32 j;
    s32 v;
    s32 y;
    s32 q1[2];
    s32 q2[2];
    Unk020224e0_c *c;

    e = gRaceRankList->mUnk_0e0;
    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        j = gRaceRankList->mUnk_060[i] - 1;
        c = GetRaceSNcerEntry(j + 0x35);
        q1[0] = (t[j][0] - e - 1) << 12;
        y = t[j][1];
        q1[1] = (y - 4) << 12;
        a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q1, 0, 1);
        v = 0;
        if (gRaceSetup->mMode == MODE_BATTLE && IsKartEliminated(i) != FALSE) {
            v = 1;
        } else if (gRaceSetup->mMode != MODE_BATTLE && (func_020b1cf4(i) != 0 || func_0207a84c(i) != 0)) {
            v = 1;
        }
        if (v != 0) {
            v = 3;
        } else if (i == GetFollowedKartOrEntryIndex()) {
            v = 0;
        } else if (gRaceSetup->mUseTeams != 0 && gRaceSetup->mCurrentEntries[i].mPlayer.mTeamIndex == 1) {
            v = 2;
        } else {
            v = 1;
        }
        c = GetRaceSNcerEntry(v + 0x75);
        q2[0] = -e << 12;
        q2[1] = y << 12;
        a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q2, 0, 1);
    }
}

void func_020bdb34(RaceHudOamBuffer *a) {
    u16 i;
    s32 k;
    Unk0217b3d8_00 p;
    s32 r;
    u16 f;
    s32 *d;
    s32 s;
    s32 q1[2];
    s32 q2[2];
    s32 q3[2];
    s32 q4[2];
    s32 v;
    Unk020224e0_c *c;

    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        k = gRaceRankList->mUnk_0a0[i];
        p = gRaceRankList->mUnk_000[k];
        r = GetRaceRankListSNcerIndex(k);
        p.mUnk_00 -= gRaceRankList->mUnk_0e0;
        if (r != 0xc9) {
            c = GetRaceSNcerEntry(r);
            q1[0] = (p.mUnk_00 + 0x45) << 12;
            q1[1] = p.mUnk_04 << 12;
            a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q1, 0, 1);
        }
        if (gRaceRankList->mUnk_060[k] > gRaceRankList->mUnk_080[k]) {
            f = gRaceRankList->mUnk_0e4;
        } else {
            f = 0;
        }
        if (gRaceRankList->mUnk_060[k] > gRaceRankList->mUnk_080[k]) {
            d = gRaceRankList->mUnk_0e8;
        } else {
            d = NULL;
        }
        c = GetRaceSNcerEntry(k + 8);
        q2[0] = p.mUnk_00 << 12;
        q2[1] = p.mUnk_04 << 12;
        a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, d, q2, f, 1);
        s = 0;
        if (gRaceSetup->mMode == MODE_BATTLE && IsKartEliminated((u16) k) != FALSE) {
            s = 1;
        } else if (gRaceSetup->mMode != MODE_BATTLE && (func_020b1cf4((u16) k) != 0 || func_0207a84c((u16) k) != 0)) {
            s = 1;
        }
        s = s != 0 ? 0x6d : 0x65;
        c = GetRaceSNcerEntry(s + k);
        q3[0] = (p.mUnk_00 + 0xa) << 12;
        q3[1] = p.mUnk_04 << 12;
        a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q3, 0, 1);
        v = 0;
        if (gRaceSetup->mMode == MODE_BATTLE && IsKartEliminated((u16) k) != FALSE) {
            v = 1;
        } else if (gRaceSetup->mMode != MODE_BATTLE && (func_020b1cf4((u16) k) != 0 || func_0207a84c((u16) k) != 0)) {
            v = 1;
        }
        if (v != 0) {
            v = 3;
        } else if ((u16) k == GetFollowedKartOrEntryIndex()) {
            v = 0;
        } else if (gRaceSetup->mUseTeams != 0 && gRaceSetup->mCurrentEntries[(u16) k].mPlayer.mTeamIndex == 1) {
            v = 2;
        } else {
            v = 1;
        }
        c = GetRaceSNcerEntry(v + 0x79);
        q4[0] = (p.mUnk_00 - 0xb) << 12;
        q4[1] = p.mUnk_04 << 12;
        a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q4, 0, 1);
    }
}

void func_020bd850(RaceHudOamBuffer *a) {
    u16 i;
    s32 k;
    Unk0217b3d8_00 p;
    s32 r;
    s32 *d;
    u16 f;
    s32 q1[2];
    s32 q2[2];
    s32 q3[2];
    s32 v;
    Unk020224e0_c *c;

    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        k = gRaceRankList->mUnk_0a0[i];
        p = gRaceRankList->mUnk_000[k];
        r = GetRaceRankListSNcerIndex(k);
        p.mUnk_00 -= gRaceRankList->mUnk_0e0;
        if (r != 0xc9) {
            c = GetRaceSNcerEntry(r);
            q1[0] = (p.mUnk_00 + 0x12) << 12;
            q1[1] = p.mUnk_04 << 12;
            a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q1, 0, 1);
        }
        if (gRaceRankList->mUnk_060[k] > gRaceRankList->mUnk_080[k]) {
            f = gRaceRankList->mUnk_0e4;
        } else {
            f = 0;
        }
        if (gRaceRankList->mUnk_060[k] > gRaceRankList->mUnk_080[k]) {
            d = gRaceRankList->mUnk_0e8;
        } else {
            d = NULL;
        }
        c = GetRaceSNcerEntry(k + 8);
        q2[0] = p.mUnk_00 << 12;
        q2[1] = p.mUnk_04 << 12;
        a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, d, q2, f, 1);
        v = 0;
        if (gRaceSetup->mMode == MODE_BATTLE && IsKartEliminated((u16) k) != FALSE) {
            v = 1;
        } else if (gRaceSetup->mMode != MODE_BATTLE && (func_020b1cf4((u16) k) != 0 || func_0207a84c((u16) k) != 0)) {
            v = 1;
        }
        if (v != 0) {
            v = 3;
        } else if ((u16) k == GetFollowedKartOrEntryIndex()) {
            v = 0;
        } else if (gRaceSetup->mUseTeams != 0 && gRaceSetup->mCurrentEntries[(u16) k].mPlayer.mTeamIndex == 1) {
            v = 2;
        } else {
            v = 1;
        }
        c = GetRaceSNcerEntry(v + 0x7d);
        q3[0] = (p.mUnk_00 - 0xb) << 12;
        q3[1] = p.mUnk_04 << 12;
        a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q3, 0, 1);
    }
}

void func_020bd7f8(RaceHudOamBuffer *a) {
    switch (GetRaceHudSubScreenState()) {
        case 0:
            func_020bdf08(a);
            func_020bdb34(a);
            break;
        case 1:
        case 2:
        case 3:
            func_020bdf08(a);
            func_020bd850(a);
            break;
    }
}

void func_020bd178(RaceHudOamBuffer *a) {
    s32 s;
    u16 i;
    u16 f;
    Unk0217b3d8_00 p;
    s32 *d;
    s32 k;
    s32 q1[2];
    s32 q2[2];
    s32 q3[2];
    s32 q4[2];
    s32 r;
    s32 q5[2];
    s32 q6[2];
    s32 q7[2];
    s32 q8[2];
    s32 q9[2];
    s32 v;
    Unk020224e0_c *c;

    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        k = gRaceRankList->mUnk_0a0[i];
        p = gRaceRankList->mUnk_000[k];
        r = GetRaceRankListSNcerIndex(k);
        p.mUnk_00 -= gRaceRankList->mUnk_0e0 + 0x13;
        if (r != 0xc9) {
            c = GetRaceSNcerEntry(r);
            q1[0] = (p.mUnk_00 + 0x45) << 12;
            q1[1] = p.mUnk_04 << 12;
            a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q1, 0, 1);
        }
        if (gRaceRankList->mUnk_060[k] > gRaceRankList->mUnk_080[k]) {
            f = gRaceRankList->mUnk_0e4;
        } else {
            f = 0;
        }
        if (gRaceRankList->mUnk_060[k] > gRaceRankList->mUnk_080[k]) {
            d = gRaceRankList->mUnk_0e8;
        } else {
            d = NULL;
        }
        c = GetRaceSNcerEntry(k + 8);
        q2[0] = (p.mUnk_00 + 1) << 12;
        q2[1] = p.mUnk_04 << 12;
        a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, d, q2, f, 1);
        s = 0;
        if (gRaceSetup->mMode == MODE_BATTLE && IsKartEliminated((u16) k) != FALSE) {
            s = 1;
        } else if (gRaceSetup->mMode != MODE_BATTLE && (func_020b1cf4((u16) k) != 0 || func_0207a84c((u16) k) != 0)) {
            s = 1;
        }
        s = s != 0 ? 0x6d : 0x65;
        c = GetRaceSNcerEntry(s + k);
        q3[0] = (p.mUnk_00 + 0xb) << 12;
        q3[1] = p.mUnk_04 << 12;
        a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q3, 0, 1);
        if (gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
            s32 t = gRaceRankList->mUnk_0c0[k];

            c = GetRaceSNcerEntry(0xc3);
            q4[0] = (p.mUnk_00 + 0x57) << 12;
            q4[1] = (p.mUnk_04 - 2) << 12;
            a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q4, 0, 1);
            c = GetRaceSNcerEntry(t + 0xb9);
            q5[0] = (p.mUnk_00 + 0x5c) << 12;
            q5[1] = p.mUnk_04 << 12;
            a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q5, 0, 1);
        } else {
            s32 t = gRaceRankList->mUnk_0c0[k] / 10;
            s32 u = gRaceRankList->mUnk_0c0[k] % 10;

            c = GetRaceSNcerEntry(0xc4);
            q6[0] = (p.mUnk_00 + 0x57) << 12;
            q6[1] = (p.mUnk_04 - 2) << 12;
            a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q6, 0, 1);
            c = GetRaceSNcerEntry(t + 0xb9);
            q7[0] = (p.mUnk_00 + 0x54) << 12;
            q7[1] = p.mUnk_04 << 12;
            a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q7, 0, 1);
            c = GetRaceSNcerEntry(u + 0xb9);
            q8[0] = (p.mUnk_00 + 0x5c) << 12;
            q8[1] = p.mUnk_04 << 12;
            a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q8, 0, 1);
        }
        v = 0;
        if (gRaceSetup->mMode == MODE_BATTLE && IsKartEliminated((u16) k) != FALSE) {
            v = 1;
        } else if (gRaceSetup->mMode != MODE_BATTLE && (func_020b1cf4((u16) k) != 0 || func_0207a84c((u16) k) != 0)) {
            v = 1;
        }
        if (v != 0) {
            v = 3;
        } else if ((u16) k == GetFollowedKartOrEntryIndex()) {
            v = 0;
        } else if (gRaceSetup->mUseTeams != 0 && gRaceSetup->mCurrentEntries[(u16) k].mPlayer.mTeamIndex == 1) {
            v = 2;
        } else {
            v = 1;
        }
        c = GetRaceSNcerEntry(v + 0x81);
        q9[0] = (p.mUnk_00 - 0xb) << 12;
        q9[1] = p.mUnk_04 << 12;
        a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q9, 0, 1);
    }
}

void func_020bcbe8(RaceHudOamBuffer *a) {
    u16 i;
    u16 f;
    Unk0217b3d8_00 p;
    s32 *d;
    s32 k;
    s32 q1[2];
    s32 q2[2];
    s32 q3[2];
    s32 q4[2];
    s32 r;
    s32 q5[2];
    s32 q6[2];
    s32 q7[2];
    s32 q8[2];
    s32 v;
    Unk020224e0_c *c;

    for (i = 0; i < (u32) gRaceSetup->mKartCount; i++) {
        k = gRaceRankList->mUnk_0a0[i];
        p = gRaceRankList->mUnk_000[k];
        r = GetRaceRankListSNcerIndex(k);
        p.mUnk_00 -= gRaceRankList->mUnk_0e0 + 0x13;
        if (r != 0xc9) {
            c = GetRaceSNcerEntry(r);
            q1[0] = (p.mUnk_00 + 0x12) << 12;
            q1[1] = p.mUnk_04 << 12;
            a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q1, 0, 1);
        }
        if (gRaceRankList->mUnk_060[k] > gRaceRankList->mUnk_080[k]) {
            f = gRaceRankList->mUnk_0e4;
        } else {
            f = 0;
        }
        if (gRaceRankList->mUnk_060[k] > gRaceRankList->mUnk_080[k]) {
            d = gRaceRankList->mUnk_0e8;
        } else {
            d = NULL;
        }
        c = GetRaceSNcerEntry(k + 8);
        q2[0] = (p.mUnk_00 + 1) << 12;
        q2[1] = p.mUnk_04 << 12;
        a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, d, q2, f, 1);
        if (gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
            s32 t = gRaceRankList->mUnk_0c0[k];

            c = GetRaceSNcerEntry(0xc3);
            q3[0] = (p.mUnk_00 + 0x25) << 12;
            q3[1] = (p.mUnk_04 - 2) << 12;
            a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q3, 0, 1);
            c = GetRaceSNcerEntry(t + 0xb9);
            q4[0] = (p.mUnk_00 + 0x2a) << 12;
            q4[1] = p.mUnk_04 << 12;
            a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q4, 0, 1);
        } else {
            s32 t = gRaceRankList->mUnk_0c0[k] / 10;
            s32 u = gRaceRankList->mUnk_0c0[k] % 10;

            c = GetRaceSNcerEntry(0xc4);
            q5[0] = (p.mUnk_00 + 0x25) << 12;
            q5[1] = (p.mUnk_04 - 2) << 12;
            a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q5, 0, 1);
            c = GetRaceSNcerEntry(t + 0xb9);
            q6[0] = (p.mUnk_00 + 0x22) << 12;
            q6[1] = p.mUnk_04 << 12;
            a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q6, 0, 1);
            c = GetRaceSNcerEntry(u + 0xb9);
            q7[0] = (p.mUnk_00 + 0x2a) << 12;
            q7[1] = p.mUnk_04 << 12;
            a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q7, 0, 1);
        }
        v = 0;
        if (gRaceSetup->mMode == MODE_BATTLE && IsKartEliminated((u16) k) != FALSE) {
            v = 1;
        } else if (gRaceSetup->mMode != MODE_BATTLE && (func_020b1cf4((u16) k) != 0 || func_0207a84c((u16) k) != 0)) {
            v = 1;
        }
        if (v != 0) {
            v = 3;
        } else if ((u16) k == GetFollowedKartOrEntryIndex()) {
            v = 0;
        } else if (gRaceSetup->mUseTeams != 0 && gRaceSetup->mCurrentEntries[(u16) k].mPlayer.mTeamIndex == 1) {
            v = 2;
        } else {
            v = 1;
        }
        c = GetRaceSNcerEntry(v + 0x85);
        q8[0] = (p.mUnk_00 - 0xb) << 12;
        q8[1] = p.mUnk_04 << 12;
        a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q8, 0, 1);
    }
}

void InitRaceLapNumber(void) {
    gRaceLapNumber = HeapAlloc(GetHeap(func_020364e8()), 0x14);
    gRaceLapNumber->mUnk_00 = 0;
    gRaceLapNumber->mUnk_04 = 0;
    gRaceLapNumber->mUnk_08 = (u16) (GetLapCount() - 1);
    gRaceLapNumber->mUnk_0c = 0;
    gRaceLapNumber->mUnk_10 = 1;
}

u32 ClearRaceLapNumberPointer(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gRaceLapNumber;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

// Values of the first argument DrawRaceLapAndTimeDifference passes to GetRaceTaMNcerEntry.
typedef enum { UNK_020B843C_ARG_0, UNK_020B843C_ARG_1 } Unk020b843c_Arg;

// Plays a sound when the displayed kart starts a lap before the last, and counts 0x78 frames for the lap number blink.
void UpdateRaceLapNumber(void) {
    Unk0217b3ec *d;
    NNSSndSeqPlayer **a;
    u32 v;

    if (gRaceSetup->mMode == MODE_BATTLE) {
        return;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        switch (gRaceSetup->mMissionKind) {
            case 2:
            case 4:
            case 6:
            case 10:
                break;
            default:
                return;
        }
    }
    gRaceLapNumber->mUnk_04 = gRaceLapNumber->mUnk_00;
    gRaceLapNumber->mUnk_00 = func_0203c8c0(GetFollowedKartOrEntryIndex()) - 1;
    if (gRaceLapNumber->mUnk_00 != gRaceLapNumber->mUnk_04 && gRaceLapNumber->mUnk_08 > 0) {
        if (gRaceLapNumber->mUnk_00 < gRaceLapNumber->mUnk_08) {
            v = 0x41;
            if (gRaceSetup->mCourseId == COURSE_ID_PINBALL) {
                v = 0x1c7;
            }
            if (data_0217c780 & 1) {
                a = func_0210e128(func_02108ea0(0));
                if (data_0217d084.mUnk_0c != 0) {
                    if (*a != NULL) {
                        NNS_SndPlayerStopSeq(a, 0);
                    }
                    if (*a != NULL) {
                        NNS_SndPlayerStopSeq(a, 0);
                    }
                    NNS_SndArcPlayerStartSeqArc(a, 0, v);
                }
            }
        }
        gRaceLapNumber->mUnk_0c = 1;
    }
    d = gRaceLapNumber;
    if (d->mUnk_0c != 0) {
        if ((d->mUnk_0c - 1) % 12 < 8) {
            d->mUnk_10 = 1;
        } else {
            d->mUnk_10 = 0;
        }
        gRaceLapNumber->mUnk_0c++;
        if (gRaceLapNumber->mUnk_0c > 0x78) {
            gRaceLapNumber->mUnk_0c = 0;
        }
    } else {
        d->mUnk_10 = 1;
    }
}

// Draws the lap label, the lap number while the blink shows it, a cell for last lap index 2 or 4, the time difference.
void DrawRaceLapAndTimeDifference(RaceHudOamBuffer *a) {
    s32 t[2] = {0xf8, 0x10};
    s32 *p;
    TimeDigits *r;
    s32 q1[2];
    s32 q2[2];
    s32 q3[2];
    s32 q4[2];
    s32 v;
    Unk020224e0_c *c;

    if (gRaceSetup->mRaceKind == 4) {
        return;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_DEMO) {
        return;
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        switch (gRaceSetup->mMissionKind) {
            case 2:
            case 4:
            case 6:
            case 10:
                if (gRaceLapNumber->mUnk_08 < 2) {
                    return;
                }
                break;
            default:
                return;
        }
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        return;
    }
    c = GetRaceMNcerEntry(0x20);
    q1[0] = t[0] << 12;
    q1[1] = t[1] << 12;
    a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q1, 0, 1);
    if (gRaceLapNumber->mUnk_10 != 0) {
        c = GetRaceMNcerEntry(gRaceLapNumber->mUnk_00 + 0x21);
        q2[0] = t[0] << 12;
        q2[1] = t[1] << 12;
        a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q2, 0, 1);
    }
    switch (gRaceLapNumber->mUnk_08) {
        case 2:
            c = GetRaceMNcerEntry(0x26);
            q3[0] = t[0] << 12;
            q3[1] = t[1] << 12;
            a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q3, 0, 1);
            break;
        case 4:
            c = GetRaceMNcerEntry(0x27);
            q4[0] = t[0] << 12;
            q4[1] = t[1] << 12;
            a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q4, 0, 1);
            break;
    }
    if (GetUseTimeDifference() == 0) {
        return;
    }
    if (func_020b1a20() == 0) {
        return;
    }
    v = func_020b1a0c();
    if (v % 0x24 >= 0x18) {
        return;
    }
    {
        s32 q5[2];
        s32 q6[2];
        s32 q7[2];
        s32 q8[2];
        s32 q9[2];
        s32 q10[2];
        s32 q11[2];
        s32 q12[2];
        s32 q13[2];
        s32 q14[2];
        s32 b[10] = {0x57, 0x61, 0x6a, 0x72, 0x7c, 0x85, 0x8e, 0x98, 0xa1, 0xaa};

        GetRaceHudTimeDifference(&p, &r);
        c = GetRaceTaMNcerEntry(*p != 0 ? UNK_020B843C_ARG_0 : UNK_020B843C_ARG_1);
        q5[0] = b[0] << 12;
        q5[1] = 0x58000;
        a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q5, 0, 1);
        if (r->mUnk_00[0] != 0) {
            c = GetRaceTaMNcerEntry(r->mUnk_00[0] + 2);
            q6[0] = b[1] << 12;
            q6[1] = 0x58000;
            a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q6, 0, 1);
        }
        c = GetRaceTaMNcerEntry(r->mUnk_00[1] + 2);
        q7[0] = b[2] << 12;
        q7[1] = 0x58000;
        a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q7, 0, 1);
        c = GetRaceTaMNcerEntry(0xc);
        q8[0] = b[3] << 12;
        q8[1] = 0x58000;
        a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q8, 0, 1);
        c = GetRaceTaMNcerEntry(r->mUnk_00[2] + 2);
        q9[0] = b[4] << 12;
        q9[1] = 0x58000;
        a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q9, 0, 1);
        c = GetRaceTaMNcerEntry(r->mUnk_00[3] + 2);
        q10[0] = b[5] << 12;
        q10[1] = 0x58000;
        a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q10, 0, 1);
        c = GetRaceTaMNcerEntry(0xc);
        q11[0] = b[6] << 12;
        q11[1] = 0x58000;
        a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q11, 0, 1);
        c = GetRaceTaMNcerEntry(r->mUnk_00[4] + 2);
        q12[0] = b[7] << 12;
        q12[1] = 0x58000;
        a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q12, 0, 1);
        c = GetRaceTaMNcerEntry(r->mUnk_00[5] + 2);
        q13[0] = b[8] << 12;
        q13[1] = 0x58000;
        a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q13, 0, 1);
        c = GetRaceTaMNcerEntry(r->mUnk_00[6] + 2);
        q14[0] = b[9] << 12;
        q14[1] = 0x58000;
        a->mOamCount += NNS_G2dMakeCellToOams(&a->mOams[a->mOamCount], 0x80 - a->mOamCount, c, NULL, q14, 0, 1);
    }
}

void InitRaceTimeDigits(void) {
    s32 i;

    gRaceTimeDigits = HeapAlloc(GetHeap(func_020364e8()), 0x38);
    gRaceTimeDigits->mUnk_00.mUnk_00[0] = 0;
    gRaceTimeDigits->mUnk_00.mUnk_00[1] = 0;
    gRaceTimeDigits->mUnk_00.mUnk_00[2] = 0;
    gRaceTimeDigits->mUnk_00.mUnk_00[3] = 0;
    gRaceTimeDigits->mUnk_00.mUnk_00[4] = 0;
    gRaceTimeDigits->mUnk_00.mUnk_00[5] = 0;
    gRaceTimeDigits->mUnk_00.mUnk_00[6] = 0;
    gRaceTimeDigits->mUnk_1c = FALSE;
    if (gRaceSetup->mMode == MODE_BATTLE) {
        if (gRaceSetup->mBattleKind == BATTLE_KIND_SHINE) {
            gRaceTimeDigits->mUnk_1c = TRUE;
        }
    }
    if (gRaceSetup->mMode == MODE_MISSION_RUN) {
        if (gRaceSetup->mMissionKind != 6) {
            gRaceTimeDigits->mUnk_1c = TRUE;
        }
    }
    for (i = 0; i < 6; i++) {
        gRaceTimeDigits->mUnk_20[i] = 0;
    }
}
