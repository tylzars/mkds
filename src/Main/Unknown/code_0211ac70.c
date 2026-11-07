#include "Main/Unknown/code_0211ac70.h"

#include "Main/Unknown/code_0202bb80.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02116ec0.h"
#include "Main/Unknown/code_0211ac88.h"
#include "Main/Unknown/code_0211b23c.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/code_0212b1a8.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0201ea58.h"
#include "Main/Unknown/code_0202b000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128244.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_0211b224.h"
#include "Main/Unknown/code_0211e4e8.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0202056c.h"
#include "Main/Unknown/code_02029000.h"
#include "Main/Unknown/code_0202c000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0205f000.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_02116dc8.h"
#include "Main/Unknown/code_02116dd4.h"
#include "Main/Unknown/code_02116000.h"
#include "Main/Unknown/code_02117000.h"
#include "Main/Unknown/code_0211d3a8.h"
#include "Main/Unknown/code_0211d3f4.h"
#include "Main/Unknown/code_0211d40c.h"
#include "Main/Unknown/code_0211d428.h"
#include "Main/Unknown/code_0211d44c.h"
#include "Main/Unknown/code_0211d62c.h"
#include "Main/Unknown/code_0211db90.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02127000.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_0212b000.h"
#include "code_02148950.h"
#include "registers.h"
#include "Main/Unknown/code_0211d000.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_0202b604.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_02125000.h"
#include "code_02016468.h"

#pragma thumb on

// Copies the rectangle of row b; which table is read depends on the mode's screen file.
void LookupSelectRaceRuleNscrRect(SelectRaceRuleNscrRect *a, s32 b) {
    SelectRaceRuleNscrRect v;

    if (gSelectRaceRule->mMode == 3) {
        v = gSelectRaceRuleMultiSimpleNscrRects[b];
    } else {
        v = gSelectRaceRuleSMenuNscrRects[b];
    }
    *a = v;
}

void AdvanceSelectRaceRuleHighlight(void) {
    SelectRaceRuleNscrRect buf;
    s32 i;

    for (i = 0; i < 5; i++) {
        if (gSelectRaceRule->mOnButton == 0 && gSelectRaceRule->mRow == i) {
            func_02124100(data_0215cd4c[i].mUnk_00[0], 1, gSelectRaceRule->mBnll, gSelectRaceRule->mTable,
                          gSelectRaceRule->mBncl);
        } else {
            func_02124100(data_0215cd4c[i].mUnk_00[0], 0, gSelectRaceRule->mBnll, gSelectRaceRule->mTable,
                          gSelectRaceRule->mBncl);
        }
    }
    if (data_021759d0->mUnk_20 != 2) {
        if (gSelectRaceRule->mOnButton != 0 && gSelectRaceRule->mUnk_84 != 0) {
            gSelectRaceRule->mTable[0x28].mUnk_00 = 0;
            gSelectRaceRule->mTable[0x29].mUnk_00 = 1;
            func_02124100(0xd, 1, gSelectRaceRule->mBnll, gSelectRaceRule->mTable, gSelectRaceRule->mBncl);
        } else {
            gSelectRaceRule->mTable[0x28].mUnk_00 = 1;
            gSelectRaceRule->mTable[0x29].mUnk_00 = 0;
            func_02124100(0xd, 0, gSelectRaceRule->mBnll, gSelectRaceRule->mTable, gSelectRaceRule->mBncl);
        }
    }
    if (gSelectRaceRule->mPrevOnButton == gSelectRaceRule->mOnButton &&
        gSelectRaceRule->mPrevRow == gSelectRaceRule->mRow) {
        return;
    }
    for (i = 0; i < 5; i++) {
        LookupSelectRaceRuleNscrRect(&buf, i);
        func_020b44a4(gSelectRaceRule->mNscr->mData, buf.mFirstColumn, buf.mFirstRow, buf.mColumnCount, buf.mRowCount,
                      buf.mTopBits);
    }
    if (gSelectRaceRule->mOnButton == 0) {
        LookupSelectRaceRuleNscrRect(&buf, gSelectRaceRule->mRow);
        func_020b44a4(gSelectRaceRule->mNscr->mData, buf.mFirstColumn, buf.mFirstRow, buf.mColumnCount, buf.mRowCount,
                      buf.mHighlightedTopBits);
    }
    CallQueueAppend(0x1b, 0, gSelectRaceRule->mNscr->mData, 0x600);
}

// Stores the count, kept from 1 to 10, and draws it.
void func_0211d910(s16 a) {
    u16 buf[0x40];
    u16 buf2[0x40];

    if (a < 1) {
        a = 1;
    }
    if (a > 0xa) {
        a = 0xa;
    }
    gSelectRaceRule->mWinCount = a;
    func_02124f4c(gSelectRaceRule->mWinCount, buf2);
    if (data_021759d0->mUnk_20 != 2) {
        func_0212426c(1, 9, gSelectRaceRule->mBnll,
                      GetBmgEntry(gSelectRaceRule->mRuleMessages, data_0216dc0c[3][SELECT_RACE_RULE_WIN]),
                      gSelectRaceRule->mBncl, gSelectRaceRule->mTable);
        func_02124248(1, 8, gSelectRaceRule->mBnll, buf2, gSelectRaceRule->mBncl, gSelectRaceRule->mTable, 0xb);
    } else {
        func_02124f4c(gSelectRaceRule->mWinCount, buf);
        func_0212513c(buf, GetBmgEntry(gSelectRaceRule->mRuleMessages, 0x16), buf2, 0x80);
        func_0212426c(1, 0xa, gSelectRaceRule->mBnll, buf2, gSelectRaceRule->mBncl, gSelectRaceRule->mTable);
    }
}

// Stores the count, kept from 1 to 0x20, and draws it.
void func_0211d844(s16 a) {
    u16 buf[0x40];
    u16 buf2[0x40];

    if (a < 1) {
        a = 1;
    }
    if (a > 0x20) {
        a = 0x20;
    }
    gSelectRaceRule->mRaceCount = a;
    func_02124f4c(gSelectRaceRule->mRaceCount, buf2);
    if (data_021759d0->mUnk_20 != 2) {
        func_0212426c(1, 9, gSelectRaceRule->mBnll,
                      GetBmgEntry(gSelectRaceRule->mRuleMessages, data_0216dc0c[3][SELECT_RACE_RULE_RACE]),
                      gSelectRaceRule->mBncl, gSelectRaceRule->mTable);
        func_02124248(1, 8, gSelectRaceRule->mBnll, buf2, gSelectRaceRule->mBncl, gSelectRaceRule->mTable, 0xb);
    } else {
        func_02124f4c(gSelectRaceRule->mRaceCount, buf);
        func_0212513c(buf, GetBmgEntry(gSelectRaceRule->mRuleMessages, 0x17), buf2, 0x80);
        func_0212426c(1, 0xa, gSelectRaceRule->mBnll, buf2, gSelectRaceRule->mBncl, gSelectRaceRule->mTable);
    }
}

void func_0211d66c(void) {
    u16 h = gSelectRaceRule->mBncl->mUnk_06;

    if (data_021759d0->mUnk_20 != 2) {
        switch (gSelectRaceRule->mRowValues[3]) {
            case SELECT_RACE_RULE_WIN:
            case SELECT_RACE_RULE_RACE:
                gSelectRaceRule->mTable[h + 9].mUnk_00 = 1;
                gSelectRaceRule->mTable[h + 10].mUnk_00 = 0;
                gSelectRaceRule->mTable[h + 8].mUnk_00 = 1;
                break;
            case SELECT_RACE_RULE_FREE:
                gSelectRaceRule->mTable[h + 9].mUnk_00 = 0;
                gSelectRaceRule->mTable[h + 10].mUnk_00 = 1;
                gSelectRaceRule->mTable[h + 8].mUnk_00 = 0;
                break;
        }
        switch (gSelectRaceRule->mRowValues[4]) {
            case 0:
            case 1:
                gSelectRaceRule->mTable[h + 11].mUnk_00 = 1;
                gSelectRaceRule->mTable[h + 12].mUnk_00 = 0;
                break;
            case 2:
                gSelectRaceRule->mTable[h + 11].mUnk_00 = 0;
                gSelectRaceRule->mTable[h + 12].mUnk_00 = 1;
                break;
        }
    } else {
        gSelectRaceRule->mTable[0x1e].mUnk_00 = 0;
        gSelectRaceRule->mTable[0x1f].mUnk_00 = 0;
        switch (gSelectRaceRule->mRowValues[3]) {
            case SELECT_RACE_RULE_WIN:
                gSelectRaceRule->mTable[h + 10].mUnk_00 = 1;
                func_0211d910(gSelectRaceRule->mWinCount);
                break;
            case SELECT_RACE_RULE_RACE:
                gSelectRaceRule->mTable[h + 10].mUnk_00 = 1;
                func_0211d844(gSelectRaceRule->mRaceCount);
                break;
            case SELECT_RACE_RULE_FREE:
                gSelectRaceRule->mTable[h + 10].mUnk_00 = 1;
                func_0212426c(1, 0xa, gSelectRaceRule->mBnll,
                              GetBmgEntry(gSelectRaceRule->mRuleMessages, data_0216dc0c[3][SELECT_RACE_RULE_FREE]),
                              gSelectRaceRule->mBncl, gSelectRaceRule->mTable);
                break;
        }
        switch (gSelectRaceRule->mRowValues[4]) {
            case 0:
            case 1:
                gSelectRaceRule->mTable[h + 11].mUnk_00 = 1;
                gSelectRaceRule->mTable[h + 12].mUnk_00 = 0;
                break;
            case 2:
                gSelectRaceRule->mTable[h + 11].mUnk_00 = 0;
                gSelectRaceRule->mTable[h + 12].mUnk_00 = 1;
                break;
        }
    }
    if (gSelectRaceRule->mMode == 3) {
        gSelectRaceRule->mTable[h + data_0215cd4c[0].mUnk_00[1]].mUnk_00 = 0;
        gSelectRaceRule->mTable[h + data_0215cd4c[2].mUnk_00[1]].mUnk_00 = 0;
    }
}

u16 GetSelectRaceRuleHumanCount(void) {
    return gSelectRaceRule->mTeamHumanCounts[0] + gSelectRaceRule->mTeamHumanCounts[1];
}

#pragma thumb off

#pragma thumb on

u16 GetSelectRaceRuleCpuCount(void) {
    SelectRaceRule *v1;
    v1 = gSelectRaceRule;
    if (v1->mRowValues[1] == 0) {
        return 0;
    }
    return v1->mUnk_b0[0] + v1->mUnk_b0[1];
}

#pragma thumb off

#pragma thumb on

// Moves the highlight to the next row, then onto the button, then back to row 0; a row with a zero table entry is
// skipped.
void MoveSelectRaceRuleRowNext(void) {
    u32 a = 1;
    u16 h = gSelectRaceRule->mBncl->mUnk_06;
    Unk027ffc40 *v;

    if (gSelectRaceRule->mOnButton != 0) {
        gSelectRaceRule->mRow = 0;
        gSelectRaceRule->mOnButton = 0;
        if (gSelectRaceRule->mTable[h + data_0215cd4c[gSelectRaceRule->mRow].mUnk_00[0]].mUnk_00 == 0 ||
            (GetSelectRaceRuleHumanCount() == 8 && gSelectRaceRule->mRow == 1)) {
            a = 0;
            MoveSelectRaceRuleRowNext();
        }
    } else {
        gSelectRaceRule->mRow++;
        if (gSelectRaceRule->mRow >= 5) {
            gSelectRaceRule->mRow--;
            gSelectRaceRule->mOnButton = a;
            v = (Unk027ffc40 *) 0x027ffc40;
            if (v->mUnk_00 != 2) {
                ResetPaletteBlendCycle();
            }
        } else if (gSelectRaceRule->mTable[h + data_0215cd4c[gSelectRaceRule->mRow].mUnk_00[0]].mUnk_00 == 0 ||
                   (GetSelectRaceRuleHumanCount() == 8 && gSelectRaceRule->mRow == 1)) {
            a = 0;
            MoveSelectRaceRuleRowNext();
        }
    }
    if (a != 0) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
    }
}

// Moves the highlight to the previous row, then onto the button, then to row 4; a row with a zero table entry is
// skipped.
void MoveSelectRaceRuleRowPrevious(void) {
    u32 a = 1;
    u16 h = gSelectRaceRule->mBncl->mUnk_06;
    Unk027ffc40 *v;

    if (gSelectRaceRule->mOnButton != 0) {
        gSelectRaceRule->mRow = 4;
        gSelectRaceRule->mOnButton = 0;
        if (gSelectRaceRule->mTable[h + data_0215cd4c[gSelectRaceRule->mRow].mUnk_00[0]].mUnk_00 == 0 ||
            (GetSelectRaceRuleHumanCount() == 8 && gSelectRaceRule->mRow == 1)) {
            a = 0;
            MoveSelectRaceRuleRowPrevious();
        }
    } else {
        gSelectRaceRule->mRow--;
        if (gSelectRaceRule->mRow < 0) {
            gSelectRaceRule->mRow++;
            gSelectRaceRule->mOnButton = a;
            v = (Unk027ffc40 *) 0x027ffc40;
            if (v->mUnk_00 != 2) {
                ResetPaletteBlendCycle();
            }
        } else if (gSelectRaceRule->mTable[h + data_0215cd4c[gSelectRaceRule->mRow].mUnk_00[0]].mUnk_00 == 0 ||
                   (GetSelectRaceRuleHumanCount() == 8 && gSelectRaceRule->mRow == 1)) {
            a = 0;
            MoveSelectRaceRuleRowPrevious();
        }
    }
    if (a != 0) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
    }
}

#pragma thumb off

#pragma thumb on

u16 GetSelectRaceRuleTeamPlayerCount(s32 a) {
    SelectRaceRule *p;
    p = gSelectRaceRule;
    if (p->mRowValues[1] == 0) {
        return p->mTeamHumanCounts[a];
    }
    return p->mTeamHumanCounts[a] + p->mUnk_b0[a];
}

u32 IsPlayerTeamPlayerCountNotOne(s32 a) {
    if (GetSelectRaceRuleTeamPlayerCount(gSelectRaceRule->mPlayerTeamIndices[a]) != 1) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

void SetSelectRaceRulePlayerTeam(u16 a, u32 b) {
    gSelectRaceRule->mPlayerTeamIndices[a] = b;
    func_0202b6a0(a, data_0215cca4[b]);
}

#pragma thumb off

#pragma thumb on

u32 IsSelectRaceRuleEntryHuman(u16 a) {
    u32 v1;
    v1 = GetSelectRaceRuleHumanCount();
    if (v1 > a) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

u32 GetOtherTeamIndex(u32 a) {
    u32 v = 2;

    switch (a) {
        case 0:
            v = 1;
            break;
        case 1:
            v = 0;
            break;
    }
    return v;
}

#pragma thumb off

#pragma thumb on

// Returns the team with more players, or 2 when they are equal or row 1 is 0.
u32 GetLargerTeamIndex(void) {
    u32 a;
    u32 b;
    if (gSelectRaceRule->mRowValues[1] != 0) {
        a = GetSelectRaceRuleTeamPlayerCount(0);
        b = GetSelectRaceRuleTeamPlayerCount(1);
        if (a > b) {
            return 0;
        }
        a = GetSelectRaceRuleTeamPlayerCount(0);
        b = GetSelectRaceRuleTeamPlayerCount(1);
        if (a < b) {
            return 1;
        }
    }
    return 2;
}

#pragma thumb off

#pragma thumb on

// Picks a random CPU entry; FALSE when there are none.
BOOL PickSelectRaceRuleCpuEntry(u16 *a) {
    Unk020f41c4_B *p;
    u32 n;
    u32 c;
    if (GetSelectRaceRuleCpuCount() == 0) {
        *a = 8;
        return FALSE;
    }
    switch (gSelectRaceRule->mMode) {
        case 0:
        case 1:
            c = GetSelectRaceRuleHumanCount();
            *a = c + func_020ae3b4(GetSelectRaceRuleCpuCount());
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            p = &data_0217aa00->mUnk_1ee8;
            n = GetSelectRaceRuleCpuCount();
            p->mUnk_00 = p->mUnk_10 + (u64) ((s64) p->mUnk_08 * (s64) p->mUnk_00);
            *a = GetSelectRaceRuleHumanCount() +
                 (n == 0 ? (u32) (p->mUnk_00 >> 32) : (u32) (((s64) (u32) (p->mUnk_00 >> 32) * (s64) n) >> 32));
            break;
    }
    return TRUE;
}

// Moves a player to a team unless it is alone in its team, then moves another player to even the teams.
void ChangeSelectRaceRulePlayerTeam(u16 a, u32 b) {
    u16 c;
    u16 v;
    c = 8;
    if (b == gSelectRaceRule->mPlayerTeamIndices[a]) {
        return;
    }
    if (IsPlayerTeamPlayerCountNotOne(a) == 0) {
        v = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mOwnIndex : 0;
        if (a == data_0217aa00->mUnk_1e52[v].mUnk_00) {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x16);
        }
        return;
    }
    SetSelectRaceRulePlayerTeam(a, b);
    if (IsSelectRaceRuleEntryHuman(a) != 0) {
        gSelectRaceRule->mTeamHumanCounts[b]++;
        gSelectRaceRule->mTeamHumanCounts[GetOtherTeamIndex(b)]--;
    } else {
        gSelectRaceRule->mUnk_b0[b]++;
        gSelectRaceRule->mUnk_b0[GetOtherTeamIndex(b)]--;
    }
    b = GetLargerTeamIndex();
    if (b != 2 && gSelectRaceRule->mUnk_b0[b] != 0) {
        PickSelectRaceRuleCpuEntry(&c);
        while (b != gSelectRaceRule->mPlayerTeamIndices[c]) {
            PickSelectRaceRuleCpuEntry(&c);
        }
        ChangeSelectRaceRulePlayerTeam(c, GetOtherTeamIndex(b));
    }
    v = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mOwnIndex : 0;
    if (a == data_0217aa00->mUnk_1e52[v].mUnk_00) {
        switch (gSelectRaceRule->mPlayerTeamIndices[a]) {
            case 0:
                gSelectRaceRule->mUnk_50[1][0] = 6;
                break;
            case 1:
                gSelectRaceRule->mUnk_50[1][1] = 6;
                break;
        }
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 4);
    }
}

void func_0211d09c(void) {
    s32 a;
    s32 i;
    u16 n;
    Unk020f41c4_B *p;
    a = 2;
    n = GetSelectRaceRuleHumanCount();
    gSelectRaceRule->mTeamHumanCounts[0] = 0;
    gSelectRaceRule->mTeamHumanCounts[1] = 0;
    for (i = 0; i < n; i++) {
        switch (gSelectRaceRule->mMode) {
            case 0:
            case 1:
                a = func_020ae3b4(2);
                break;
            case 2:
            case 3:
            case 4:
            case 5:
                p = &data_0217aa00->mUnk_1ee8;
                p->mUnk_00 = p->mUnk_10 + (u64) ((s64) p->mUnk_08 * (s64) p->mUnk_00);
                a = ((u64) (u32) (p->mUnk_00 >> 32) * 2) >> 32;
                break;
        }
        if (n / 2 <= gSelectRaceRule->mTeamHumanCounts[a]) {
            a = GetOtherTeamIndex(a);
        }
        SetSelectRaceRulePlayerTeam(i, a);
        gSelectRaceRule->mTeamHumanCounts[a]++;
    }
}

void func_0211cfd0(void) {
    s32 a;
    s32 i;
    Unk020f41c4_B *p;
    a = 2;
    GetSelectRaceRuleHumanCount();
    gSelectRaceRule->mUnk_b0[0] = 0;
    gSelectRaceRule->mUnk_b0[1] = 0;
    for (i = GetSelectRaceRuleHumanCount(); i < 8; i++) {
        switch (gSelectRaceRule->mMode) {
            case 0:
            case 1:
                a = func_020ae3b4(2);
                break;
            case 2:
            case 3:
            case 4:
            case 5:
                p = &data_0217aa00->mUnk_1ee8;
                p->mUnk_00 = p->mUnk_10 + (u64) ((s64) p->mUnk_08 * (s64) p->mUnk_00);
                a = ((u64) (u32) (p->mUnk_00 >> 32) * 2) >> 32;
                break;
        }
        if (GetSelectRaceRuleTeamPlayerCount(a) >= 4) {
            a = GetOtherTeamIndex(a);
        }
        SetSelectRaceRulePlayerTeam(i, a);
        gSelectRaceRule->mUnk_b0[a]++;
    }
}

// FALSE for a value of the highlighted row that the current mode does not offer.
BOOL IsSelectRaceRuleValueAllowed(void) {
    SelectRaceRule *p;
    p = gSelectRaceRule;
    if (p->mRow == 0 && p->mRowValues[0] == 3 && func_0205fbb8(0x10) == 0) {
        return FALSE;
    }
    p = gSelectRaceRule;
    switch (p->mMode) {
        case 0:
            if (p->mRow == 1 && p->mRowValues[1] == 0) {
                return FALSE;
            }
            if (p->mRow == 4 && p->mRowValues[4] == 2) {
                return FALSE;
            }
            break;
        case 1:
            if (p->mRow == 1 && p->mRowValues[1] == 0) {
                return FALSE;
            }
            if (p->mRow == 3 && p->mRowValues[3] == SELECT_RACE_RULE_RACE) {
                return FALSE;
            }
            if (p->mRow == 4 && p->mRowValues[4] == 2) {
                return FALSE;
            }
            break;
        case 2:
            if (p->mRow == 4 && p->mRowValues[4] == 1) {
                return FALSE;
            }
            break;
        case 3:
            if (p->mRow == 3 && p->mRowValues[3] == SELECT_RACE_RULE_RACE) {
                return FALSE;
            }
            if (p->mRow == 4 && p->mRowValues[4] == 1) {
                return FALSE;
            }
            break;
        case 4:
            if (p->mRow == 4 && p->mRowValues[4] == 1) {
                return FALSE;
            }
            break;
        case 5:
            if (p->mRow == 3 && p->mRowValues[3] == SELECT_RACE_RULE_RACE) {
                return FALSE;
            }
            if (p->mRow == 4 && p->mRowValues[4] == 1) {
                return FALSE;
            }
            break;
    }
    return TRUE;
}

BOOL func_0211ce24(void) {
    BOOL a;
    u8 b;
    switch (gSelectRaceRule->mMode) {
        case 0:
        case 1:
            if (GetSelectRaceRuleHumanCount() == 1) {
                return TRUE;
            }
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            a = TRUE;
            if (data_0217aa00->mUnk_0004 != 8 && data_0217aa00->mUnk_0004 != 9) {
                a = FALSE;
            }
            b = a != FALSE ? CountSetBits(data_0217aa00->mParticipantMask) : 0;
            if (b == GetSelectRaceRuleHumanCount()) {
                return TRUE;
            }
            break;
    }
    return FALSE;
}

s32 func_0211cdec(void) {
    BOOL a;
    a = TRUE;
    if (GetSelectRaceRuleTeamPlayerCount(0) == 0) {
        a = FALSE;
    }
    if (GetSelectRaceRuleTeamPlayerCount(1) == 0) {
        a = FALSE;
    }
    if (GetLargerTeamIndex() != 2) {
        a = FALSE;
    }
    if (func_0211ce24() == FALSE) {
        a = FALSE;
    }
    return a;
}

void MoveSelectRaceRuleValueNext(s32 a) {
    SelectRaceRule *p;
    s32 i;
    gSelectRaceRule->mRowValues[gSelectRaceRule->mRow]++;
    if (data_0215ccc0[gSelectRaceRule->mRow] <= gSelectRaceRule->mRowValues[gSelectRaceRule->mRow]) {
        gSelectRaceRule->mRowValues[gSelectRaceRule->mRow] = 0;
    }
    if (IsSelectRaceRuleValueAllowed() == FALSE) {
        MoveSelectRaceRuleValueNext(0);
    }
    p = gSelectRaceRule;
    if (p->mRow != 3) {
        func_0212426c(1, data_0215cd4e[p->mRow * 2], p->mBnll,
                      GetBmgEntry(p->mRuleMessages, data_0216dc0c[p->mRow][p->mRowValues[p->mRow]]), p->mBncl,
                      p->mTable);
    } else {
        switch (p->mRowValues[3]) {
            case SELECT_RACE_RULE_WIN:
                func_0211d910(p->mWinCount);
                break;
            case SELECT_RACE_RULE_RACE:
                func_0211d844(p->mRaceCount);
                break;
        }
        for (i = 0; i < 2; i++) {
            gSelectRaceRule->mUnk_50[0][i] = 0;
        }
    }
    if (gSelectRaceRule->mRow == 4) {
        for (i = 0; i < 2; i++) {
            gSelectRaceRule->mUnk_50[1][i] = 0;
        }
    }
    if (gSelectRaceRule->mRow == 1) {
        if (gSelectRaceRule->mRowValues[1] == 0) {
            if (func_0211cdec() == 0) {
                func_0211d09c();
            }
            func_0202b618(0);
        } else {
            if (func_0211cdec() == 0) {
                func_0211cfd0();
            }
            func_0202b618(1);
        }
    }
    gSelectRaceRule->mRowChangeTimers[gSelectRaceRule->mRow][1] = 6;
    if (a != 0) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 1);
    }
}

void MoveSelectRaceRuleValuePrevious(s32 a) {
    SelectRaceRule *p;
    s32 i;
    gSelectRaceRule->mRowValues[gSelectRaceRule->mRow]--;
    if (gSelectRaceRule->mRowValues[gSelectRaceRule->mRow] < 0) {
        gSelectRaceRule->mRowValues[gSelectRaceRule->mRow] = data_0215ccc0[gSelectRaceRule->mRow] - 1;
    }
    if (IsSelectRaceRuleValueAllowed() == FALSE) {
        MoveSelectRaceRuleValuePrevious(0);
    }
    p = gSelectRaceRule;
    if (p->mRow != 3) {
        func_0212426c(1, data_0215cd4e[p->mRow * 2], p->mBnll,
                      GetBmgEntry(p->mRuleMessages, data_0216dc0c[p->mRow][p->mRowValues[p->mRow]]), p->mBncl,
                      p->mTable);
    } else {
        switch (p->mRowValues[3]) {
            case SELECT_RACE_RULE_WIN:
                func_0211d910(p->mWinCount);
                break;
            case SELECT_RACE_RULE_RACE:
                func_0211d844(p->mRaceCount);
                break;
        }
        for (i = 0; i < 2; i++) {
            gSelectRaceRule->mUnk_50[0][i] = 0;
        }
    }
    if (gSelectRaceRule->mRow == 4) {
        for (i = 0; i < 2; i++) {
            gSelectRaceRule->mUnk_50[1][i] = 0;
        }
    }
    if (gSelectRaceRule->mRow == 1) {
        if (gSelectRaceRule->mRowValues[1] == 0) {
            if (func_0211cdec() == 0) {
                func_0211d09c();
            }
            func_0202b618(0);
        } else {
            if (func_0211cdec() == 0) {
                func_0211cfd0();
            }
            func_0202b618(1);
        }
    }
    gSelectRaceRule->mRowChangeTimers[gSelectRaceRule->mRow][0] = 6;
    if (a != 0) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 1);
    }
}

void IncrementSelectRaceRuleCourseCount(void) {
    BOOL a;
    SelectRaceRule *p;
    a = FALSE;
    p = gSelectRaceRule;
    if (p->mRow == 3) {
        switch (p->mRowValues[3]) {
            case SELECT_RACE_RULE_WIN:
                func_0211d910(p->mWinCount + 1);
                gSelectRaceRule->mUnk_50[0][1] = 6;
                a = TRUE;
                break;
            case SELECT_RACE_RULE_RACE:
                func_0211d844(p->mRaceCount + 1);
                gSelectRaceRule->mUnk_50[0][1] = 6;
                a = TRUE;
                break;
        }
        if (a != FALSE) {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x17);
        }
    }
}

void DecrementSelectRaceRuleCourseCount(void) {
    BOOL a;
    SelectRaceRule *p;
    a = FALSE;
    p = gSelectRaceRule;
    if (p->mRow == 3) {
        switch (p->mRowValues[3]) {
            case SELECT_RACE_RULE_WIN:
                func_0211d910(p->mWinCount - 1);
                gSelectRaceRule->mUnk_50[0][0] = 6;
                a = TRUE;
                break;
            case SELECT_RACE_RULE_RACE:
                func_0211d844(p->mRaceCount - 1);
                gSelectRaceRule->mUnk_50[0][0] = 6;
                a = TRUE;
                break;
        }
        if (a != FALSE) {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x17);
        }
    }
}

void AdvanceSelectRaceRuleRowObjects(void) {
    s32 i;
    s32 j;
    if (data_021759d0->mUnk_20 == 2) {
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 2; j++) {
                gSelectRaceRule->mTable[data_0215cd88[i][j]].mUnk_00 = 0;
                gSelectRaceRule->mTable[data_0215cdb0[i][j]].mUnk_00 = 0;
                gSelectRaceRule->mTable[data_0215cdc4[i][j]].mUnk_00 = 0;
            }
        }
        return;
    }
    for (i = 0; i < 5; i++) {
        if (GetSelectRaceRuleHumanCount() == 8 && i == 1) {
            for (j = 0; j < 2; j++) {
                gSelectRaceRule->mTable[data_0215cd88[i][j]].mUnk_00 = 0;
                gSelectRaceRule->mTable[data_0215cdb0[i][j]].mUnk_00 = 0;
                gSelectRaceRule->mTable[data_0215cdc4[i][j]].mUnk_00 = 0;
            }
        } else {
            gSelectRaceRule->mTable[data_0215cdb0[i][0]].mUnk_04 =
                -func_020adc64(6 - gSelectRaceRule->mRowChangeTimers[i][0]);
            gSelectRaceRule->mTable[data_0215cdb0[i][1]].mUnk_04 =
                func_020adc64(6 - gSelectRaceRule->mRowChangeTimers[i][1]);
            for (j = 0; j < 2; j++) {
                if (gSelectRaceRule->mRowChangeTimers[i][j] > 0) {
                    gSelectRaceRule->mRowChangeTimers[i][j]--;
                    gSelectRaceRule->mTable[data_0215cd88[i][j]].mUnk_00 = 0;
                    gSelectRaceRule->mTable[data_0215cdb0[i][j]].mUnk_00 = 1;
                    gSelectRaceRule->mTable[data_0215cdc4[i][j]].mUnk_00 = 0;
                } else if (gSelectRaceRule->mRow == i && gSelectRaceRule->mOnButton == 0) {
                    gSelectRaceRule->mTable[data_0215cd88[i][j]].mUnk_00 = 1;
                    gSelectRaceRule->mTable[data_0215cdb0[i][j]].mUnk_00 = 0;
                    gSelectRaceRule->mTable[data_0215cdc4[i][j]].mUnk_00 = 0;
                } else {
                    gSelectRaceRule->mTable[data_0215cd88[i][j]].mUnk_00 = 0;
                    gSelectRaceRule->mTable[data_0215cdb0[i][j]].mUnk_00 = 0;
                    gSelectRaceRule->mTable[data_0215cdc4[i][j]].mUnk_00 = 1;
                }
            }
        }
    }
    if (gSelectRaceRule->mMode == 3) {
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mTable[data_0215cd88[0][j]].mUnk_00 = 0;
            gSelectRaceRule->mTable[data_0215cd88[2][j]].mUnk_00 = 0;
            gSelectRaceRule->mTable[data_0215cdb0[0][j]].mUnk_00 = 0;
            gSelectRaceRule->mTable[data_0215cdb0[2][j]].mUnk_00 = 0;
            gSelectRaceRule->mTable[data_0215cdc4[0][j]].mUnk_00 = 0;
            gSelectRaceRule->mTable[data_0215cdc4[2][j]].mUnk_00 = 0;
        }
    }
}

void func_0211c810(u16 a, u32 b) {
    func_020294c0(a, b);
}

void func_0211c5ac(void) {
    u16 a[2];
    s32 i;
    u16 v;
    SelectRaceRule *p;
    a[0] = 8;
    a[1] = 8;
    for (i = 0; i < 8; i++) {
        func_0211c810(i, 3);
    }
    if (GetSelectRaceRuleCpuCount() != 0) {
        p = gSelectRaceRule;
        if (p->mRowValues[4] == 0) {
            PickSelectRaceRuleCpuEntry(&a[0]);
            func_0211c810(a[0], 0);
            if (GetSelectRaceRuleCpuCount() > 1) {
                PickSelectRaceRuleCpuEntry(&a[1]);
                while (a[0] == a[1]) {
                    PickSelectRaceRuleCpuEntry(&a[1]);
                }
                func_0211c810(a[1], 1);
            }
        } else if (p->mUnk_b0[GetOtherTeamIndex(p->mPlayerTeamIndices[0])] != 0) {
            PickSelectRaceRuleCpuEntry(&a[0]);
            v = a[0];
            while (gSelectRaceRule->mPlayerTeamIndices[v] !=
                   GetOtherTeamIndex(gSelectRaceRule->mPlayerTeamIndices[0])) {
                PickSelectRaceRuleCpuEntry(&a[0]);
                v = a[0];
            }
            func_0211c810(v, 0);
            if (gSelectRaceRule->mUnk_b0[gSelectRaceRule->mPlayerTeamIndices[0]] != 0) {
                PickSelectRaceRuleCpuEntry(&a[1]);
                while (gSelectRaceRule->mPlayerTeamIndices[0] != gSelectRaceRule->mPlayerTeamIndices[a[1]]) {
                    PickSelectRaceRuleCpuEntry(&a[1]);
                }
                func_0211c810(a[1], 1);
            } else if (gSelectRaceRule->mUnk_b0[GetOtherTeamIndex(gSelectRaceRule->mPlayerTeamIndices[0])] > 1) {
                PickSelectRaceRuleCpuEntry(&a[1]);
                while (gSelectRaceRule->mPlayerTeamIndices[a[1]] !=
                           GetOtherTeamIndex(gSelectRaceRule->mPlayerTeamIndices[0]) ||
                       a[0] == a[1]) {
                    PickSelectRaceRuleCpuEntry(&a[1]);
                }
                func_0211c810(a[1], 1);
            }
        } else if (gSelectRaceRule->mUnk_b0[gSelectRaceRule->mPlayerTeamIndices[0]] != 0) {
            PickSelectRaceRuleCpuEntry(&a[0]);
            while (gSelectRaceRule->mPlayerTeamIndices[0] != gSelectRaceRule->mPlayerTeamIndices[a[0]]) {
                PickSelectRaceRuleCpuEntry(&a[0]);
            }
            func_0211c810(a[0], 0);
            if (gSelectRaceRule->mUnk_b0[gSelectRaceRule->mPlayerTeamIndices[0]] > 1) {
                PickSelectRaceRuleCpuEntry(&a[1]);
                while (gSelectRaceRule->mPlayerTeamIndices[0] != gSelectRaceRule->mPlayerTeamIndices[a[1]] ||
                       a[0] == a[1]) {
                    PickSelectRaceRuleCpuEntry(&a[1]);
                }
                func_0211c810(a[1], 1);
            }
        }
    }
}

// Stores the rows' values and the kinds and teams of the 8 entries into the race setup copy.
void WriteSelectRaceRuleToRaceSetupCopy(void) {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (IsSelectRaceRuleEntryHuman(i) != 0) {
            SetPlayerKind(i, PLAYER_KIND_HUMAN);
            SetTeamIndex(i, data_0215cca4[gSelectRaceRule->mPlayerTeamIndices[i]]);
        } else if (gSelectRaceRule->mRowValues[1] != 0) {
            SetPlayerKind(i, PLAYER_KIND_CPU);
            SetTeamIndex(i, data_0215cca4[gSelectRaceRule->mPlayerTeamIndices[i]]);
        } else {
            SetPlayerKind(i, PLAYER_KIND_NONE);
            SetTeamIndex(i, data_0215cca4[gSelectRaceRule->mPlayerTeamIndices[i]]);
        }
    }
    if (gSelectRaceRule->mRowValues[0] == 3) {
        SetEngineIndex(data_0215cd18[2]);
        func_020295b0();
    } else {
        SetEngineIndex(data_0215cd18[gSelectRaceRule->mRowValues[0]]);
        func_020295a0();
    }
    SetCpuDifficulty(data_0215cd28[gSelectRaceRule->mRowValues[1]]);
    SetCourseListMode(data_0215cce4[gSelectRaceRule->mRowValues[2]]);
    SetRuleKind(data_0215ccf0[gSelectRaceRule->mRowValues[3]]);
    switch (gSelectRaceRule->mRowValues[3]) {
        case SELECT_RACE_RULE_WIN:
            func_02029550(gSelectRaceRule->mWinCount);
            break;
        case SELECT_RACE_RULE_RACE:
            func_02029550(gSelectRaceRule->mRaceCount);
            break;
    }
    if (gSelectRaceRule->mRowValues[4] == 0) {
        ClearUseTeams();
    } else {
        SetUseTeams();
    }
    func_0211c5ac();
}

void func_0211c14c(void) {
    s32 j;
    u16 v;
    if (data_021759d0->mUnk_20 != 2) {
        if (gSelectRaceRule->mRowValues[3] != SELECT_RACE_RULE_FREE) {
            if (gSelectRaceRule->mRow == 3 && gSelectRaceRule->mOnButton == 0) {
                gSelectRaceRule->mTable[30].mUnk_00 = 1;
                gSelectRaceRule->mTable[31].mUnk_00 = 0;
            } else {
                gSelectRaceRule->mTable[30].mUnk_00 = 0;
                gSelectRaceRule->mTable[31].mUnk_00 = 1;
            }
            for (j = 0; j < 2; j++) {
                if (gSelectRaceRule->mUnk_50[0][j] > 0) {
                    gSelectRaceRule->mUnk_50[0][j]--;
                    gSelectRaceRule->mTable[data_0215ccac[0][j]].mUnk_00 = 1;
                } else {
                    gSelectRaceRule->mTable[data_0215ccac[0][j]].mUnk_00 = 0;
                }
            }
        } else {
            gSelectRaceRule->mTable[30].mUnk_00 = 0;
            gSelectRaceRule->mTable[31].mUnk_00 = 0;
            for (j = 0; j < 2; j++) {
                gSelectRaceRule->mTable[data_0215ccac[0][j]].mUnk_00 = 0;
            }
        }
        if (gSelectRaceRule->mRowValues[4] == 2) {
            for (j = 0; j < 2; j++) {
                if (gSelectRaceRule->mRow == 4 && gSelectRaceRule->mOnButton == 0) {
                    v = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mOwnIndex : 0;
                    if (IsPlayerTeamPlayerCountNotOne(data_0217aa00->mUnk_1e52[v].mUnk_00) != 0) {
                        gSelectRaceRule->mTable[data_0215cc6c[j]].mUnk_00 = 1;
                        gSelectRaceRule->mTable[data_0215cc70[j]].mUnk_00 = 0;
                    } else {
                        gSelectRaceRule->mTable[data_0215cc6c[j]].mUnk_00 = 0;
                        gSelectRaceRule->mTable[data_0215cc70[j]].mUnk_00 = 1;
                    }
                } else {
                    gSelectRaceRule->mTable[data_0215cc6c[j]].mUnk_00 = 0;
                    gSelectRaceRule->mTable[data_0215cc70[j]].mUnk_00 = 1;
                }
                if (gSelectRaceRule->mUnk_50[1][j] > 0) {
                    gSelectRaceRule->mUnk_50[1][j]--;
                    gSelectRaceRule->mTable[data_0215ccac[1][j]].mUnk_00 = 1;
                } else {
                    gSelectRaceRule->mTable[data_0215ccac[1][j]].mUnk_00 = 0;
                }
            }
        } else {
            for (j = 0; j < 2; j++) {
                gSelectRaceRule->mTable[data_0215cc6c[j]].mUnk_00 = 0;
                gSelectRaceRule->mTable[data_0215cc70[j]].mUnk_00 = 0;
                gSelectRaceRule->mTable[data_0215ccac[1][j]].mUnk_00 = 0;
            }
        }
    } else {
        gSelectRaceRule->mTable[30].mUnk_00 = 0;
        gSelectRaceRule->mTable[31].mUnk_00 = 0;
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mTable[data_0215ccac[0][j]].mUnk_00 = 0;
        }
        if (gSelectRaceRule->mRowValues[4] == 2) {
            for (j = 0; j < 2; j++) {
                v = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mOwnIndex : 0;
                if (IsPlayerTeamPlayerCountNotOne(data_0217aa00->mUnk_1e52[v].mUnk_00) != 0) {
                    gSelectRaceRule->mTable[data_0215cc6c[j]].mUnk_00 = 1;
                    gSelectRaceRule->mTable[data_0215cc70[j]].mUnk_00 = 0;
                } else {
                    gSelectRaceRule->mTable[data_0215cc6c[j]].mUnk_00 = 1;
                    gSelectRaceRule->mTable[data_0215cc70[j]].mUnk_00 = 1;
                }
                if (gSelectRaceRule->mUnk_50[1][j] > 0) {
                    gSelectRaceRule->mUnk_50[1][j]--;
                    gSelectRaceRule->mTable[data_0215ccac[1][j]].mUnk_00 = 1;
                } else {
                    gSelectRaceRule->mTable[data_0215ccac[1][j]].mUnk_00 = 0;
                }
            }
        } else {
            for (j = 0; j < 2; j++) {
                gSelectRaceRule->mTable[data_0215cc6c[j]].mUnk_00 = 0;
                gSelectRaceRule->mTable[data_0215cc70[j]].mUnk_00 = 0;
                gSelectRaceRule->mTable[data_0215ccac[1][j]].mUnk_00 = 0;
            }
        }
    }
}

void func_0211c0cc(void) {
    SelectRaceRule *p;
    if (data_021759d0->mUnk_20 == 2) {
        gSelectRaceRule->mTable[gSelectRaceRule->mBncl->mUnk_06 + 14].mUnk_00 = 1;
        p = gSelectRaceRule;
        if (p->mRowValues[4] == 2) {
            func_0212426c(1, 0xe, gSelectRaceRule->mBnll, GetBmgEntry(p->mRuleMessages, 0x15), p->mBncl, p->mTable);
        } else {
            func_0212426c(1, 0xe, gSelectRaceRule->mBnll, GetBmgEntry(p->mRuleMessages, 0x14), p->mBncl, p->mTable);
        }
    }
}

void AdvanceSelectRaceRuleTeamInput(void) {
    s32 i;
    s32 a;
    BOOL c;
    BOOL b;
    u32 n;
    InputSlot *p;
    u16 y;
    if (gSelectRaceRule->mRowValues[4] == 2) {
        for (i = 0; i < 8; i++) {
            n = data_0215cdec[i];
            a = -1;
            c = FALSE;
            b = FALSE;
            p = &data_02175628[n];
            y = p->mHasPair;
            if (y == 0 && p->mNoPairCount < 5) {
                b = TRUE;
            }
            if (b == FALSE && p->mPrevHasPair == 0 && y != 0) {
                c = TRUE;
            }
            if (c != FALSE) {
                a = RectTableFindContaining(gSelectRaceRule->mBnbl, p->mPairX, p->mPairY - gSelectRaceRule->mOffsetY);
            }
            if (GetNewOrRepeatBits(n, PAD_KEY_L) != 0 || a == 0x11) {
                if (i == 0) {
                    if (a == 0x11) {
                        gSelectRaceRule->mRow = 4;
                        gSelectRaceRule->mOnButton = 0;
                    }
                    if (gSelectRaceRule->mOnButton == 0 && gSelectRaceRule->mRow == 4) {
                        ChangeSelectRaceRulePlayerTeam(i, 0);
                    }
                } else {
                    ChangeSelectRaceRulePlayerTeam(i, 0);
                }
            } else if (GetNewOrRepeatBits(n, PAD_KEY_R) != 0 || a == 0x12) {
                if (i == 0) {
                    if (a == 0x12) {
                        gSelectRaceRule->mRow = 4;
                        gSelectRaceRule->mOnButton = 0;
                    }
                    if (gSelectRaceRule->mOnButton == 0 && gSelectRaceRule->mRow == 4) {
                        ChangeSelectRaceRulePlayerTeam(i, 1);
                    }
                } else {
                    ChangeSelectRaceRulePlayerTeam(i, 1);
                }
            }
        }
    }
}

// Sets every row to the race setup copy's value and rebuilds the teams from its entries; first clears the copy when
// GetPreviousMenuScreenNumber() returns 8, 9 or 0xf.
void ReadRaceSetupCopyIntoSelectRaceRule(void) {
    s32 a;
    s32 i;
    u32 b;
    a = 3;
    if (GetPreviousMenuScreenNumber() == 8 || GetPreviousMenuScreenNumber() == 9 ||
        GetPreviousMenuScreenNumber() == 0xf) {
        ClearUseTeams();
        func_020295a0();
        SetEngineIndex(0);
        SetCpuDifficulty(0);
        SetCourseListMode(0);
        SetRuleKind(0);
        func_02029550(0);
    }
    if (GetUseTeams() != 0) {
        switch (gSelectRaceRule->mMode) {
            case 0:
            case 1:
                a = 1;
                break;
            case 2:
            case 3:
            case 4:
            case 5:
                a = 2;
                break;
        }
        for (i = 0; i < 8; i++) {
            b = data_0215cc9c[GetTeamIndex(i)];
            SetSelectRaceRulePlayerTeam(i, b);
            if (GetPlayerKind(i) == PLAYER_KIND_HUMAN) {
                gSelectRaceRule->mTeamHumanCounts[b]++;
            } else {
                gSelectRaceRule->mUnk_b0[b]++;
            }
        }
    } else {
        a = 0;
    }
    gSelectRaceRule->mRow = 4;
    while (a != gSelectRaceRule->mRowValues[4]) {
        MoveSelectRaceRuleValueNext(0);
    }
    if (func_0202967c() != 0) {
        b = 3;
    } else {
        b = data_0215ccfc[GetEngineIndex()];
    }
    a = 0;
    gSelectRaceRule->mRow = 0;
    while (b != gSelectRaceRule->mRowValues[0]) {
        MoveSelectRaceRuleValueNext(0);
    }
    b = data_0215cd08[GetCpuDifficulty()];
    gSelectRaceRule->mRow = 1;
    while (b != gSelectRaceRule->mRowValues[1]) {
        MoveSelectRaceRuleValueNext(0);
    }
    switch (gSelectRaceRule->mMode) {
        case 0:
        case 1:
            if (b == 0 && gSelectRaceRule->mRowValues[1] != 2) {
                do {
                    MoveSelectRaceRuleValueNext(0);
                } while (gSelectRaceRule->mRowValues[1] != 2);
            }
            break;
    }
    b = data_0215cccc[GetCourseListMode()];
    gSelectRaceRule->mRow = 2;
    while (b != gSelectRaceRule->mRowValues[2]) {
        MoveSelectRaceRuleValueNext(0);
    }
    b = data_0215ccd8[GetRuleKind()];
    gSelectRaceRule->mRow = 3;
    while (b != gSelectRaceRule->mRowValues[3]) {
        MoveSelectRaceRuleValueNext(0);
    }
    switch (gSelectRaceRule->mRowValues[3]) {
        case SELECT_RACE_RULE_WIN:
            func_0211d910(func_0202964c());
            break;
        case SELECT_RACE_RULE_RACE:
            func_0211d844(func_0202964c());
            break;
    }
    gSelectRaceRule->mRow = 0;
}

void SetSelectRaceRuleHumanCount(void) {
    BOOL a;
    u8 b;
    switch (gSelectRaceRule->mMode) {
        case 0:
        case 1:
            gSelectRaceRule->mTeamHumanCounts[0] = 1;
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            a = TRUE;
            if (data_0217aa00->mUnk_0004 != 8 && data_0217aa00->mUnk_0004 != 9) {
                a = FALSE;
            }
            b = a != FALSE ? CountSetBits(data_0217aa00->mParticipantMask) : 0;
            gSelectRaceRule->mTeamHumanCounts[0] = b;
            break;
    }
}

void ResetSelectRaceRulePositions(void) {
    s32 i;
    s32 j;
    s32 c;
    gSelectRaceRule->mNextState = 0;
    gSelectRaceRule->mStateFrames = 0;
    c = gSelectRaceRule->mOffsetY - 0xc0;
    gSelectRaceRule->mBg3Offset = c;
    c = gSelectRaceRule->mOffsetY - 0xc0;
    gSelectRaceRule->mBg3Offset = c;
    c = gSelectRaceRule->mBncl->mUnk_06;
    gSelectRaceRule->mTable[40].mUnk_06 = gSelectRaceRule->mOffsetY + 0xc0;
    gSelectRaceRule->mTable[41].mUnk_06 = gSelectRaceRule->mOffsetY + 0xc0;
    gSelectRaceRule->mTable[42].mUnk_06 = gSelectRaceRule->mOffsetY + 0xc0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mTable[data_0215cd88[i][j]].mUnk_06 = gSelectRaceRule->mOffsetY - 0xc0;
            gSelectRaceRule->mTable[data_0215cdb0[i][j]].mUnk_06 = gSelectRaceRule->mOffsetY - 0xc0;
            gSelectRaceRule->mTable[data_0215cdc4[i][j]].mUnk_06 = gSelectRaceRule->mOffsetY - 0xc0;
        }
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mTable[c + data_0215cd4c[i].mUnk_00[j]].mUnk_06 = gSelectRaceRule->mOffsetY - 0xc0;
        }
    }
    gSelectRaceRule->mTable[c + 10].mUnk_06 = gSelectRaceRule->mOffsetY - 0xc0;
    gSelectRaceRule->mTable[c + 12].mUnk_06 = gSelectRaceRule->mOffsetY - 0xc0;
    gSelectRaceRule->mTable[30].mUnk_06 = gSelectRaceRule->mOffsetY - 0xc0;
    gSelectRaceRule->mTable[31].mUnk_06 = gSelectRaceRule->mOffsetY - 0xc0;
    gSelectRaceRule->mTable[34].mUnk_06 = gSelectRaceRule->mOffsetY - 0xc0;
    gSelectRaceRule->mTable[37].mUnk_06 = gSelectRaceRule->mOffsetY - 0xc0;
    gSelectRaceRule->mTable[35].mUnk_06 = gSelectRaceRule->mOffsetY - 0xc0;
    gSelectRaceRule->mTable[38].mUnk_06 = gSelectRaceRule->mOffsetY - 0xc0;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mTable[data_0215ccac[i][j]].mUnk_06 = gSelectRaceRule->mOffsetY - 0xc0;
        }
    }
    if (data_021759d0->mUnk_20 != 2) {
        gSelectRaceRule->mTable[c + 13].mUnk_06 = gSelectRaceRule->mOffsetY + 0xc0;
        c += 8;
        gSelectRaceRule->mTable[c].mUnk_06 = gSelectRaceRule->mOffsetY + 0xc0;
    } else {
        c += 14;
        gSelectRaceRule->mTable[c].mUnk_06 = gSelectRaceRule->mOffsetY + 0xc0;
    }
}

// Requests state 1: stores mNextState = 1 and zeroes mStateFrames; the next AdvanceSelectRaceRule call copies it to
// mState and runs AdvanceSelectRaceRuleState1.
void RequestSelectRaceRuleState1(void) {
    gSelectRaceRule->mNextState = 1;
    gSelectRaceRule->mStateFrames = 0;
}

void RequestSelectRaceRuleState2(void) {
    gSelectRaceRule->mNextState = 2;
    gSelectRaceRule->mStateFrames = 0;
    switch (gSelectRaceRule->mMode) {
        case 0:
        case 1:
            RequestSelectReturnState1();
            break;
    }
}

// Requests state 3: stores mNextState = 3 and zeroes mStateFrames; the next AdvanceSelectRaceRule call copies it to
// mState and runs AdvanceSelectRaceRuleState3.
void RequestSelectRaceRuleState3(void) {
    gSelectRaceRule->mNextState = 3;
    gSelectRaceRule->mStateFrames = 0;
}

void RequestSelectRaceRuleState4(void) {
    gSelectRaceRule->mNextState = 4;
    gSelectRaceRule->mStateFrames = 0;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        StopPaletteBlend();
    }
    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
    WriteSelectRaceRuleToRaceSetupCopy();
}

void RequestSelectRaceRuleState5(void) {
    void *a;
    gSelectRaceRule->mNextState = 5;
    gSelectRaceRule->mStateFrames = 0;
    a = GetBmgEntry(gSelectRaceRule->mCommonMessages, 4);
    StartSelectChoises(a, GetBmgEntry(gSelectRaceRule->mCommonMessages, 2), 0);
}

// Requests state 6: stores mNextState = 6 and zeroes mStateFrames; the next AdvanceSelectRaceRule call copies it to
// mState and runs AdvanceSelectRaceRuleState6.
void RequestSelectRaceRuleState6(void) {
    gSelectRaceRule->mNextState = 6;
    gSelectRaceRule->mStateFrames = 0;
}

void RequestSelectRaceRuleState7(void) {
    gSelectRaceRule->mNextState = 7;
    gSelectRaceRule->mStateFrames = 0;
    RequestSelectChoisesState0();
}

// Requests state 8: stores mNextState = 8 and zeroes mStateFrames; the next AdvanceSelectRaceRule call copies it to
// mState and runs AdvanceSelectRaceRuleState8.
void RequestSelectRaceRuleState8(void) {
    gSelectRaceRule->mNextState = 8;
    gSelectRaceRule->mStateFrames = 0;
}

void InitSelectRaceRule(void *a, s32 b, void *c, s32 d) {
    void *h;
    s32 i;
    s32 j;
    s32 n;
    s32 e;
    SelectRaceRule *p;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x8200;
    h = CreateFrmHeapFromMaxFree(a);
    gSelectRaceRule = HeapAlloc(h, 0xbc);
    gSelectRaceRule->mHeap = h;
    gSelectRaceRule->mMode = d;
    gSelectRaceRule->mState = 0;
    gSelectRaceRule->mRow = 0;
    gSelectRaceRule->mPrevRow = 4;
    gSelectRaceRule->mOffsetY = 0;
    gSelectRaceRule->mOnButton = 0;
    gSelectRaceRule->mPrevOnButton = 0;
    gSelectRaceRule->mUnk_84 = 1;
    gSelectRaceRule->mWinCount = 0;
    gSelectRaceRule->mRaceCount = 0;
    gSelectRaceRule->mUnk_b4 = c;
    gSelectRaceRule->mResult = 0;
    for (i = 0; i < 2; i++) {
        gSelectRaceRule->mTeamHumanCounts[i] = 0;
        gSelectRaceRule->mUnk_b0[i] = 0;
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mRowChangeTimers[i][j] = 0;
        }
    }
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mUnk_50[i][j] = 0;
        }
    }
    LocateAndQueueSelectRaceRule();
    InitLayoutTable(gSelectRaceRule->mHeap, gSelectRaceRule->mBncl, gSelectRaceRule->mBnll, &gSelectRaceRule->mTable);
    gSelectRaceRule->mCommonMessages = FindFileInLoadedArchives(data_0216de38);
    gSelectRaceRule->mRuleMessages = FindSceneFile(data_0216de44);
    n = gSelectRaceRule->mBncl->mUnk_06;
    e = GX_GetSizeOfSubOBJ();
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            if (!(i == 3 && j == 1)) {
                e -= func_021243ac(gSelectRaceRule->mHeap, data_0215cd4c[i].mUnk_00[j], gSelectRaceRule->mBnll,
                                   data_0215cd60[i][j], data_0215cd74[i].h[j], i * 2 + j, gSelectRaceRule->mNcer,
                                   gSelectRaceRule->mBncl, gSelectRaceRule->mTable, e);
            }
        }
        p = gSelectRaceRule;
        func_0212426c(1, data_0215cd4c[i].mUnk_00[0], gSelectRaceRule->mBnll,
                      GetBmgEntry(p->mRuleMessages, data_0215ccb4[i]), p->mBncl, p->mTable);
        if (i != 3) {
            p = gSelectRaceRule;
            func_0212426c(1, data_0215cd4c[i].mUnk_00[1], gSelectRaceRule->mBnll,
                          GetBmgEntry(p->mRuleMessages, data_0216dc0c[i][p->mRowValues[i]]), p->mBncl, p->mTable);
        }
    }
    if (data_021759d0->mUnk_20 != 2) {
        p = gSelectRaceRule;
        e -= func_021243ac(p->mHeap, 9, p->mBnll, 0x96, 0xf, n + 3, p->mNcer, p->mBncl, p->mTable, e);
        p = gSelectRaceRule;
        e -= func_021243ac(p->mHeap, 0xa, p->mBnll, 0xc8, 0xf, n + 9, p->mNcer, p->mBncl, p->mTable, e);
        p = gSelectRaceRule;
        func_0212426c(1, 0xa, gSelectRaceRule->mBnll,
                      GetBmgEntry(p->mRuleMessages, data_0216dc0c[3][SELECT_RACE_RULE_FREE]), p->mBncl, p->mTable);
    } else {
        p = gSelectRaceRule;
        e -= func_021243ac(p->mHeap, 0xa, p->mBnll, 0xc8, 0xf, n + 3, p->mNcer, p->mBncl, p->mTable, e);
        p = gSelectRaceRule;
        func_0212426c(1, 0xa, gSelectRaceRule->mBnll,
                      GetBmgEntry(p->mRuleMessages, data_0216dc0c[3][SELECT_RACE_RULE_FREE]), p->mBncl, p->mTable);
    }
    p = gSelectRaceRule;
    e -= func_021243ac(p->mHeap, 0xc, p->mBnll, 0x37, 0xf, n + 0xb, p->mNcer, p->mBncl, p->mTable, e);
    p = gSelectRaceRule;
    func_0212426c(1, 0xc, gSelectRaceRule->mBnll, GetBmgEntry(p->mRuleMessages, data_0216dc0c[4][2]), p->mBncl,
                  p->mTable);
    if (data_021759d0->mUnk_20 != 2) {
        p = gSelectRaceRule;
        e -= func_021243ac(p->mHeap, 0xd, p->mBnll, 0x32, 0xd, 0x29, p->mNcer, p->mBncl, p->mTable, e);
        p = gSelectRaceRule;
        func_0212426c(1, 0xd, gSelectRaceRule->mBnll, GetBmgEntry(p->mCommonMessages, 4), p->mBncl, p->mTable);
        p = gSelectRaceRule;
        func_021243ac(p->mHeap, 8, p->mBnll, 0x15, 0xf, 0x1f, p->mNcer, p->mBncl, p->mTable, e);
    } else {
        p = gSelectRaceRule;
        func_021243ac(p->mHeap, 0xe, p->mBnll, 0xc8, 0xd, 0x2a, p->mNcer, p->mBncl, p->mTable, e);
    }
    func_0211d910(0);
    func_0211d844(0);
    switch (gSelectRaceRule->mMode) {
        case 2:
        case 4:
            func_021170f8();
            func_02116fb0();
            func_02117060();
            func_02116ef8();
            break;
        case 3:
        case 5:
            func_021170f8();
            func_02116fb0();
            func_02117060();
            func_02116ec0();
            break;
    }
    switch (gSelectRaceRule->mMode) {
        case 0:
        case 1:
            func_0202c0d4(0, 2);
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            func_0202c0d4(1, 2);
            break;
    }
    ReadRaceSetupCopyIntoSelectRaceRule();
    if (func_0211cdec() == 0) {
        SetSelectRaceRuleHumanCount();
        func_0211d09c();
        func_0211cfd0();
    }
    p = gSelectRaceRule;
    switch (p->mMode) {
        case 0:
            p->mRow = 1;
            if (gSelectRaceRule->mRowValues[1] == 0) {
                MoveSelectRaceRuleValueNext(0);
            }
            gSelectRaceRule->mRow = 0;
            break;
        case 1:
            p->mOffsetY = -0x1c;
            gSelectRaceRule->mRow = 1;
            if (gSelectRaceRule->mRowValues[1] == 0) {
                MoveSelectRaceRuleValueNext(0);
            }
            gSelectRaceRule->mRow = 3;
            if (gSelectRaceRule->mRowValues[3] == SELECT_RACE_RULE_RACE) {
                MoveSelectRaceRuleValuePrevious(0);
            }
            gSelectRaceRule->mRow = 1;
            break;
        case 2:
            p->mOffsetY = -0x1c;
            gSelectRaceRule->mRow = 1;
            if (GetSelectRaceRuleHumanCount() == 8) {
                gSelectRaceRule->mRow = 2;
            }
            break;
        case 3:
            p->mRow = 3;
            if (gSelectRaceRule->mRowValues[3] == SELECT_RACE_RULE_RACE) {
                MoveSelectRaceRuleValuePrevious(0);
            }
            gSelectRaceRule->mRow = 1;
            if (GetSelectRaceRuleHumanCount() == 8) {
                gSelectRaceRule->mRow = 3;
            }
            break;
        case 5:
            p->mOffsetY = -0x1c;
            gSelectRaceRule->mRow = 3;
            if (gSelectRaceRule->mRowValues[3] == SELECT_RACE_RULE_RACE) {
                MoveSelectRaceRuleValuePrevious(0);
            }
            gSelectRaceRule->mRow = 1;
            if (GetSelectRaceRuleHumanCount() == 8) {
                gSelectRaceRule->mRow = 2;
            }
            break;
    }
    switch (gSelectRaceRule->mMode) {
        case 1:
            gSelectRaceRule->mTable[n + data_0215cd4c[0].mUnk_00[0]].mUnk_00 = 0;
            break;
        case 2:
            gSelectRaceRule->mTable[n + data_0215cd4c[0].mUnk_00[0]].mUnk_00 = 0;
            break;
        case 3:
            gSelectRaceRule->mTable[n + data_0215cd4c[0].mUnk_00[0]].mUnk_00 = 0;
            gSelectRaceRule->mTable[n + data_0215cd4c[2].mUnk_00[0]].mUnk_00 = 0;
            gSelectRaceRule->mTable[n + data_0215cd4c[0].mUnk_00[1]].mUnk_00 = 0;
            gSelectRaceRule->mTable[n + data_0215cd4c[2].mUnk_00[1]].mUnk_00 = 0;
            for (j = 0; j < 2; j++) {
                gSelectRaceRule->mTable[data_0215cd88[0][j]].mUnk_00 = 0;
                gSelectRaceRule->mTable[data_0215cd88[2][j]].mUnk_00 = 0;
                gSelectRaceRule->mTable[data_0215cdb0[0][j]].mUnk_00 = 0;
                gSelectRaceRule->mTable[data_0215cdb0[2][j]].mUnk_00 = 0;
                gSelectRaceRule->mTable[data_0215cdc4[0][j]].mUnk_00 = 0;
                gSelectRaceRule->mTable[data_0215cdc4[2][j]].mUnk_00 = 0;
            }
            break;
        case 5:
            gSelectRaceRule->mTable[n + data_0215cd4c[0].mUnk_00[0]].mUnk_00 = 0;
            break;
    }
    if (GetSelectRaceRuleHumanCount() == 8 && gSelectRaceRule->mRowValues[1] != 0) {
        do {
            MoveSelectRaceRuleValuePrevious(0);
        } while (gSelectRaceRule->mRowValues[1] != 0);
    }
    ResetSelectRaceRulePositions();
    p = gSelectRaceRule;
    CreateWait(p->mHeap, p->mNcer, p->mBncl, 0x2a, 0xe, 1);
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        InitPaletteBlend(gSelectRaceRule->mHeap, gSelectRaceRule->mNclr, 9);
    }
    FrmHeapShrinkInParent(gSelectRaceRule->mHeap);
    AdvanceSelectRaceRuleHighlight();
}

void ReleaseSelectRaceRule(void) {
    SelectRaceRule *p;
    u32 a;
    u32 b;
    p = gSelectRaceRule;
    if (p->mResult == 1 && (p->mMode == 3 || p->mRowValues[2] == 1)) {
        a = ((reg_GX_DISPCNT) & 0x1f00) >> 8;
        a &= ~3;
        (reg_GX_DISPCNT) = ((reg_GX_DISPCNT) & 0xffffe0ff) | (a << 8);
    }
    b = (reg_G2_BG2CNT);
    b &= ~3;
    (reg_G2_BG2CNT) = b;
    (reg_G2_BG2CNT) = ((reg_G2_BG2CNT) & 0x43) | 0x9e10;
    func_02116dc8();
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        func_0212b91c();
    }
    HeapDestroy(gSelectRaceRule->mHeap);
    gSelectRaceRule = NULL;
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectRaceRuleState0(void) {
    int v1;
    v1 = AreBrightnessFadesClear();
    if (v1 != 0) {
        RequestSelectRaceRuleState1();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectRaceRuleState1(void) {
    SelectRaceRule *p;
    s32 i;
    s16 b;
    s32 j;
    s32 c;
    AdvanceSelectRaceRuleRowObjects();
    func_0211c14c();
    gSelectRaceRule->mStateFrames++;
    p = gSelectRaceRule;
    c = InterpolateS16(1, -192, 0, p->mStateFrames, 10);
    b = p->mOffsetY + c;
    p->mBg3Offset = b;
    c = gSelectRaceRule->mBncl->mUnk_06;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mTable[data_0215cd88[i][j]].mUnk_06 = b;
            gSelectRaceRule->mTable[data_0215cdb0[i][j]].mUnk_06 = b;
            gSelectRaceRule->mTable[data_0215cdc4[i][j]].mUnk_06 = b;
        }
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mTable[c + data_0215cd4c[i].mUnk_00[j]].mUnk_06 = b;
        }
    }
    gSelectRaceRule->mTable[c + 10].mUnk_06 = b;
    gSelectRaceRule->mTable[c + 12].mUnk_06 = b;
    gSelectRaceRule->mTable[34].mUnk_06 = b;
    gSelectRaceRule->mTable[37].mUnk_06 = b;
    gSelectRaceRule->mTable[35].mUnk_06 = b;
    gSelectRaceRule->mTable[38].mUnk_06 = b;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mTable[data_0215ccac[i][j]].mUnk_06 = b;
        }
    }
    if (data_021759d0->mUnk_20 != 2) {
        c += 8;
        gSelectRaceRule->mTable[c].mUnk_06 = b;
        gSelectRaceRule->mTable[30].mUnk_06 = b;
        gSelectRaceRule->mTable[31].mUnk_06 = b;
    }
    if (gSelectRaceRule->mStateFrames >= 10) {
        RequestSelectRaceRuleState2();
    }
}

void AdvanceSelectRaceRuleState2(void) {
    s16 a;
    s32 b;
    AdvanceSelectRaceRuleRowObjects();
    func_0211c14c();
    gSelectRaceRule->mStateFrames++;
    a = -LookupSelectReturnState1Bg2Offset(gSelectRaceRule->mStateFrames);
    b = gSelectRaceRule->mBncl->mUnk_06;
    if (data_021759d0->mUnk_20 != 2) {
        gSelectRaceRule->mTable[0x28].mUnk_06 = a;
        gSelectRaceRule->mTable[0x29].mUnk_06 = a;
        gSelectRaceRule->mTable[b + 13].mUnk_06 = a;
    } else {
        gSelectRaceRule->mTable[0x2a].mUnk_06 = a;
        gSelectRaceRule->mTable[b + 14].mUnk_06 = a;
    }
    switch (gSelectRaceRule->mMode) {
        case 0:
        case 1:
            if (gSelectRaceRule->mStateFrames >= 10 && IsSelectReturnState2NoState3Or4Request() != 0) {
                RequestSelectRaceRuleState3();
                return;
            }
            break;
        default:
            if (gSelectRaceRule->mStateFrames >= 10) {
                RequestSelectRaceRuleState3();
            }
            break;
    }
}

void AdvanceSelectRaceRuleState3(void) {
    InputSlot *p;
    InputSlot *q;
    InputSlot *r;
    u32 a;
    BOOL c;
    BOOL b;
    Unk02175628Index i;
    u32 d;
    u16 x;
    a = -1;
    i = UNK_02175628_INDEX_8;
    AdvanceSelectRaceRuleRowObjects();
    func_0211c14c();
    c = FALSE;
    b = FALSE;
    p = &data_02175674[i];
    x = data_02175674[i].mUnk_00;
    if (x == 0 && data_02175680[i].mUnk_00 < 5) {
        b = TRUE;
    }
    if (b == FALSE && data_0217567c[i].mUnk_00 == 0 && x != 0) {
        c = TRUE;
    }
    if (c != FALSE) {
        r = &data_02175672[i];
        q = &data_02175670[i];
        a = RectTableFindContaining(gSelectRaceRule->mBnbl, data_02175670[i].mUnk_00, data_02175672[i].mUnk_00);
        if (a != 0x13) {
            a = RectTableFindContaining(gSelectRaceRule->mBnbl, q->mUnk_00, r->mUnk_00 - gSelectRaceRule->mOffsetY);
            if (a == 0x13) {
                a = -1;
            }
        }
    }
    r = &data_02175628[i];
    if ((u16) (r->mUnk_00 & PAD_KEY_B) == 0) {
        c = FALSE;
        b = FALSE;
        x = p->mUnk_00;
        if (x == 0 && data_02175680[i].mUnk_00 < 5) {
            b = TRUE;
        }
        if (b == FALSE && data_0217567c[i].mUnk_00 == 0 && x != 0) {
            c = TRUE;
        }
        if (c == FALSE ||
            IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175670[i].mUnk_00, data_02175672[i].mUnk_00) == 0) {
            goto chain;
        }
    }
    switch (gSelectRaceRule->mMode) {
        case 0:
        case 1:
            SetSelectReturnSoundId(0xe);
            RequestSelectRaceRuleState8();
            gSelectRaceRule->mResult = 2;
            RequestSelectReturnState3WithSound(0);
            func_0202b7c0(1);
            break;
    }
    goto end;
chain:
    if (a <= 4) {
        d = data_0215cdd8[a];
        if (GetSelectRaceRuleHumanCount() != 8 || d != 1) {
            gSelectRaceRule->mRow = d;
            gSelectRaceRule->mOnButton = 0;
            MoveSelectRaceRuleValuePrevious(1);
        }
    } else if (a - 5 <= 4) {
        d = data_0215cd24[a];
        if (GetSelectRaceRuleHumanCount() != 8 || d != 1) {
            gSelectRaceRule->mRow = d;
            gSelectRaceRule->mOnButton = 0;
            MoveSelectRaceRuleValueNext(1);
        }
    } else if (a == 0x13) {
        if (gSelectRaceRule->mOnButton != 0) {
            gSelectRaceRule->mUnk_84 = 0;
        }
        gSelectRaceRule->mOnButton = 1;
        RequestSelectRaceRuleState4();
    } else if (a - 10 <= 4) {
        d = data_0215cd74[a].mUnk_00;
        if (GetSelectRaceRuleHumanCount() != 8 || d != 1) {
            gSelectRaceRule->mRow = d;
            gSelectRaceRule->mOnButton = 0;
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
        }
    } else if ((u16) (r->mUnk_00 & PAD_KEY_A) != 0) {
        if (gSelectRaceRule->mOnButton != 0) {
            RequestSelectRaceRuleState4();
            gSelectRaceRule->mUnk_84 = 0;
        } else {
            MoveSelectRaceRuleRowNext();
        }
    } else if (a == 0xf) {
        if (gSelectRaceRule->mRowValues[3] != SELECT_RACE_RULE_FREE) {
            gSelectRaceRule->mRow = 3;
            gSelectRaceRule->mOnButton = 0;
            DecrementSelectRaceRuleCourseCount();
        }
    } else if (a == 0x10) {
        if (gSelectRaceRule->mRowValues[3] != SELECT_RACE_RULE_FREE) {
            gSelectRaceRule->mRow = 3;
            gSelectRaceRule->mOnButton = 0;
            IncrementSelectRaceRuleCourseCount();
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
        MoveSelectRaceRuleRowPrevious();
    } else if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
        MoveSelectRaceRuleRowNext();
    } else if (GetNewOrRepeatBits(8, PAD_KEY_LEFT) != 0) {
        if (gSelectRaceRule->mOnButton == 0) {
            MoveSelectRaceRuleValuePrevious(1);
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_RIGHT) != 0) {
        if (gSelectRaceRule->mOnButton == 0) {
            MoveSelectRaceRuleValueNext(1);
        }
    } else if (GetNewOrRepeatBits(8, PAD_KEY_L) != 0) {
        DecrementSelectRaceRuleCourseCount();
    } else if (GetNewOrRepeatBits(8, PAD_KEY_R) != 0) {
        IncrementSelectRaceRuleCourseCount();
    }
end:
    if (gSelectRaceRule->mNextState != 4) {
        AdvanceSelectRaceRuleTeamInput();
    }
}

void AdvanceSelectRaceRuleState4(void) {
    AdvanceSelectRaceRuleRowObjects();
    func_0211c14c();
    gSelectRaceRule->mStateFrames++;
    if (gSelectRaceRule->mStateFrames == 5) {
        gSelectRaceRule->mUnk_84 = 1;
    }
    if (gSelectRaceRule->mStateFrames >= 10) {
        if (gSelectRaceRule->mMode == 3 || gSelectRaceRule->mRowValues[2] == 1) {
            RequestSelectRaceRuleState5();
            return;
        }
        RequestSelectRaceRuleState8();
        gSelectRaceRule->mResult = 1;
        func_0202b7c0(3);
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectRaceRuleState5(void) {
    int v1;
    v1 = IsSelectChoisesState1NoState0Request();
    if (v1 != 0) {
        RequestSelectRaceRuleState6();
    }
}

#pragma thumb off
