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
void LookupSelectRaceRuleNscrRect(SelectRaceRuleNscrRect *outRect, s32 row) {
    SelectRaceRuleNscrRect rect;

    if (gSelectRaceRule->mMode == 3) {
        rect = gSelectRaceRuleMultiSimpleNscrRects[row];
    } else {
        rect = gSelectRaceRuleSMenuNscrRects[row];
    }
    *outRect = rect;
}

void AdvanceSelectRaceRuleHighlight(void) {
    SelectRaceRuleNscrRect nscrRect;
    s32 i;

    for (i = 0; i < 5; i++) {
        if (gSelectRaceRule->mOnButton == 0 && gSelectRaceRule->mRow == i) {
            SetLabelPaletteIndex(gSelectRaceRuleRowEntries[i].mEntryIndices[0], 1, gSelectRaceRule->mBnll,
                                 gSelectRaceRule->mTable, gSelectRaceRule->mBncl);
        } else {
            SetLabelPaletteIndex(gSelectRaceRuleRowEntries[i].mEntryIndices[0], 0, gSelectRaceRule->mBnll,
                                 gSelectRaceRule->mTable, gSelectRaceRule->mBncl);
        }
    }
    if (data_021759d0->mUnk_20 != 2) {
        if (gSelectRaceRule->mOnButton != 0 && gSelectRaceRule->mUnk_84 != 0) {
            gSelectRaceRule->mTable[0x28].mVisible = 0;
            gSelectRaceRule->mTable[0x29].mVisible = 1;
            SetLabelPaletteIndex(0xd, 1, gSelectRaceRule->mBnll, gSelectRaceRule->mTable, gSelectRaceRule->mBncl);
        } else {
            gSelectRaceRule->mTable[0x28].mVisible = 1;
            gSelectRaceRule->mTable[0x29].mVisible = 0;
            SetLabelPaletteIndex(0xd, 0, gSelectRaceRule->mBnll, gSelectRaceRule->mTable, gSelectRaceRule->mBncl);
        }
    }
    if (gSelectRaceRule->mPrevOnButton == gSelectRaceRule->mOnButton &&
        gSelectRaceRule->mPrevRow == gSelectRaceRule->mRow) {
        return;
    }
    for (i = 0; i < 5; i++) {
        LookupSelectRaceRuleNscrRect(&nscrRect, i);
        func_020b44a4(gSelectRaceRule->mNscr->mData, nscrRect.mFirstColumn, nscrRect.mFirstRow, nscrRect.mColumnCount,
                      nscrRect.mRowCount, nscrRect.mTopBits);
    }
    if (gSelectRaceRule->mOnButton == 0) {
        LookupSelectRaceRuleNscrRect(&nscrRect, gSelectRaceRule->mRow);
        func_020b44a4(gSelectRaceRule->mNscr->mData, nscrRect.mFirstColumn, nscrRect.mFirstRow, nscrRect.mColumnCount,
                      nscrRect.mRowCount, nscrRect.mHighlightedTopBits);
    }
    CallQueueAppend(0x1b, 0, gSelectRaceRule->mNscr->mData, 0x600);
}

// Stores the count, kept from 1 to 10, and draws it.
void SetAndPrintSelectRaceRuleWinCount(s16 count) {
    u16 numberText[0x40];
    u16 text[0x40];

    if (count < 1) {
        count = 1;
    }
    if (count > 0xa) {
        count = 0xa;
    }
    gSelectRaceRule->mWinCount = count;
    func_02124f4c(gSelectRaceRule->mWinCount, text);
    if (data_021759d0->mUnk_20 != 2) {
        func_0212426c(1, 9, gSelectRaceRule->mBnll,
                      GetBmgEntry(gSelectRaceRule->mRuleMessages, data_0216dc0c[3][SELECT_RACE_RULE_WIN]),
                      gSelectRaceRule->mBncl, gSelectRaceRule->mTable);
        func_02124248(1, 8, gSelectRaceRule->mBnll, text, gSelectRaceRule->mBncl, gSelectRaceRule->mTable, 0xb);
    } else {
        func_02124f4c(gSelectRaceRule->mWinCount, numberText);
        FormatMessageWithText(numberText, GetBmgEntry(gSelectRaceRule->mRuleMessages, 0x16), text, 0x80);
        func_0212426c(1, 0xa, gSelectRaceRule->mBnll, text, gSelectRaceRule->mBncl, gSelectRaceRule->mTable);
    }
}

// Stores the count, kept from 1 to 0x20, and draws it.
void SetAndPrintSelectRaceRuleRaceCount(s16 count) {
    u16 numberText[0x40];
    u16 text[0x40];

    if (count < 1) {
        count = 1;
    }
    if (count > 0x20) {
        count = 0x20;
    }
    gSelectRaceRule->mRaceCount = count;
    func_02124f4c(gSelectRaceRule->mRaceCount, text);
    if (data_021759d0->mUnk_20 != 2) {
        func_0212426c(1, 9, gSelectRaceRule->mBnll,
                      GetBmgEntry(gSelectRaceRule->mRuleMessages, data_0216dc0c[3][SELECT_RACE_RULE_RACE]),
                      gSelectRaceRule->mBncl, gSelectRaceRule->mTable);
        func_02124248(1, 8, gSelectRaceRule->mBnll, text, gSelectRaceRule->mBncl, gSelectRaceRule->mTable, 0xb);
    } else {
        func_02124f4c(gSelectRaceRule->mRaceCount, numberText);
        FormatMessageWithText(numberText, GetBmgEntry(gSelectRaceRule->mRuleMessages, 0x17), text, 0x80);
        func_0212426c(1, 0xa, gSelectRaceRule->mBnll, text, gSelectRaceRule->mBncl, gSelectRaceRule->mTable);
    }
}

void AdvanceSelectRaceRuleValueObjects(void) {
    u16 cellEntryCount = gSelectRaceRule->mBncl->mUnk_06;

    if (data_021759d0->mUnk_20 != 2) {
        switch (gSelectRaceRule->mRowValues[3]) {
            case SELECT_RACE_RULE_WIN:
            case SELECT_RACE_RULE_RACE:
                gSelectRaceRule->mTable[cellEntryCount + 9].mVisible = 1;
                gSelectRaceRule->mTable[cellEntryCount + 10].mVisible = 0;
                gSelectRaceRule->mTable[cellEntryCount + 8].mVisible = 1;
                break;
            case SELECT_RACE_RULE_FREE:
                gSelectRaceRule->mTable[cellEntryCount + 9].mVisible = 0;
                gSelectRaceRule->mTable[cellEntryCount + 10].mVisible = 1;
                gSelectRaceRule->mTable[cellEntryCount + 8].mVisible = 0;
                break;
        }
        switch (gSelectRaceRule->mRowValues[4]) {
            case 0:
            case 1:
                gSelectRaceRule->mTable[cellEntryCount + 11].mVisible = 1;
                gSelectRaceRule->mTable[cellEntryCount + 12].mVisible = 0;
                break;
            case 2:
                gSelectRaceRule->mTable[cellEntryCount + 11].mVisible = 0;
                gSelectRaceRule->mTable[cellEntryCount + 12].mVisible = 1;
                break;
        }
    } else {
        gSelectRaceRule->mTable[0x1e].mVisible = 0;
        gSelectRaceRule->mTable[0x1f].mVisible = 0;
        switch (gSelectRaceRule->mRowValues[3]) {
            case SELECT_RACE_RULE_WIN:
                gSelectRaceRule->mTable[cellEntryCount + 10].mVisible = 1;
                SetAndPrintSelectRaceRuleWinCount(gSelectRaceRule->mWinCount);
                break;
            case SELECT_RACE_RULE_RACE:
                gSelectRaceRule->mTable[cellEntryCount + 10].mVisible = 1;
                SetAndPrintSelectRaceRuleRaceCount(gSelectRaceRule->mRaceCount);
                break;
            case SELECT_RACE_RULE_FREE:
                gSelectRaceRule->mTable[cellEntryCount + 10].mVisible = 1;
                func_0212426c(1, 0xa, gSelectRaceRule->mBnll,
                              GetBmgEntry(gSelectRaceRule->mRuleMessages, data_0216dc0c[3][SELECT_RACE_RULE_FREE]),
                              gSelectRaceRule->mBncl, gSelectRaceRule->mTable);
                break;
        }
        switch (gSelectRaceRule->mRowValues[4]) {
            case 0:
            case 1:
                gSelectRaceRule->mTable[cellEntryCount + 11].mVisible = 1;
                gSelectRaceRule->mTable[cellEntryCount + 12].mVisible = 0;
                break;
            case 2:
                gSelectRaceRule->mTable[cellEntryCount + 11].mVisible = 0;
                gSelectRaceRule->mTable[cellEntryCount + 12].mVisible = 1;
                break;
        }
    }
    if (gSelectRaceRule->mMode == 3) {
        gSelectRaceRule->mTable[cellEntryCount + gSelectRaceRuleRowEntries[0].mEntryIndices[1]].mVisible = 0;
        gSelectRaceRule->mTable[cellEntryCount + gSelectRaceRuleRowEntries[2].mEntryIndices[1]].mVisible = 0;
    }
}

u16 GetSelectRaceRuleHumanCount(void) {
    return gSelectRaceRule->mTeamHumanCounts[0] + gSelectRaceRule->mTeamHumanCounts[1];
}

#pragma thumb off

#pragma thumb on

u16 GetSelectRaceRuleCpuCount(void) {
    SelectRaceRule *selectRaceRule;
    selectRaceRule = gSelectRaceRule;
    if (selectRaceRule->mRowValues[1] == 0) {
        return 0;
    }
    return selectRaceRule->mUnk_b0[0] + selectRaceRule->mUnk_b0[1];
}

#pragma thumb off

#pragma thumb on

// Moves the highlight to the next row, then onto the button, then back to row 0; a row with a zero table entry is
// skipped.
void MoveSelectRaceRuleRowNext(void) {
    u32 a = 1;
    u16 cellEntryCount = gSelectRaceRule->mBncl->mUnk_06;
    Unk027ffc40 *v;

    if (gSelectRaceRule->mOnButton != 0) {
        gSelectRaceRule->mRow = 0;
        gSelectRaceRule->mOnButton = 0;
        if (gSelectRaceRule->mTable[cellEntryCount + gSelectRaceRuleRowEntries[gSelectRaceRule->mRow].mEntryIndices[0]]
                    .mVisible == 0 ||
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
        } else if (gSelectRaceRule
                           ->mTable[cellEntryCount + gSelectRaceRuleRowEntries[gSelectRaceRule->mRow].mEntryIndices[0]]
                           .mVisible == 0 ||
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
    u16 cellEntryCount = gSelectRaceRule->mBncl->mUnk_06;
    Unk027ffc40 *v;

    if (gSelectRaceRule->mOnButton != 0) {
        gSelectRaceRule->mRow = 4;
        gSelectRaceRule->mOnButton = 0;
        if (gSelectRaceRule->mTable[cellEntryCount + gSelectRaceRuleRowEntries[gSelectRaceRule->mRow].mEntryIndices[0]]
                    .mVisible == 0 ||
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
        } else if (gSelectRaceRule
                           ->mTable[cellEntryCount + gSelectRaceRuleRowEntries[gSelectRaceRule->mRow].mEntryIndices[0]]
                           .mVisible == 0 ||
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

u16 GetSelectRaceRuleTeamPlayerCount(s32 team) {
    SelectRaceRule *selectRaceRule;
    selectRaceRule = gSelectRaceRule;
    if (selectRaceRule->mRowValues[1] == 0) {
        return selectRaceRule->mTeamHumanCounts[team];
    }
    return selectRaceRule->mTeamHumanCounts[team] + selectRaceRule->mUnk_b0[team];
}

u32 IsPlayerTeamPlayerCountNotOne(s32 entryIndex) {
    if (GetSelectRaceRuleTeamPlayerCount(gSelectRaceRule->mPlayerTeamIndices[entryIndex]) != 1) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

void SetSelectRaceRulePlayerTeam(u16 entryIndex, u32 team) {
    gSelectRaceRule->mPlayerTeamIndices[entryIndex] = team;
    SetEntryTeamIndex(entryIndex, data_0215cca4[team]);
}

#pragma thumb off

#pragma thumb on

u32 IsSelectRaceRuleEntryHuman(u16 entryIndex) {
    u32 humanCount;
    humanCount = GetSelectRaceRuleHumanCount();
    if (humanCount > entryIndex) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

u32 GetOtherTeamIndex(u32 team) {
    u32 otherTeam = 2;

    switch (team) {
        case 0:
            otherTeam = 1;
            break;
        case 1:
            otherTeam = 0;
            break;
    }
    return otherTeam;
}

#pragma thumb off

#pragma thumb on

// Returns the team with more players, or 2 when they are equal or row 1 is 0.
u32 GetLargerTeamIndex(void) {
    u32 team0PlayerCount;
    u32 team1PlayerCount;
    if (gSelectRaceRule->mRowValues[1] != 0) {
        team0PlayerCount = GetSelectRaceRuleTeamPlayerCount(0);
        team1PlayerCount = GetSelectRaceRuleTeamPlayerCount(1);
        if (team0PlayerCount > team1PlayerCount) {
            return 0;
        }
        team0PlayerCount = GetSelectRaceRuleTeamPlayerCount(0);
        team1PlayerCount = GetSelectRaceRuleTeamPlayerCount(1);
        if (team0PlayerCount < team1PlayerCount) {
            return 1;
        }
    }
    return 2;
}

#pragma thumb off

#pragma thumb on

// Picks a random CPU entry; FALSE when there are none.
BOOL PickSelectRaceRuleCpuEntry(u16 *entryOut) {
    RandomState64 *randomState;
    u32 cpuCount;
    u32 humanCount;
    if (GetSelectRaceRuleCpuCount() == 0) {
        *entryOut = 8;
        return FALSE;
    }
    switch (gSelectRaceRule->mMode) {
        case 0:
        case 1:
            humanCount = GetSelectRaceRuleHumanCount();
            *entryOut = humanCount + func_020ae3b4(GetSelectRaceRuleCpuCount());
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            randomState = &data_0217aa00->mUnk_1ee8;
            cpuCount = GetSelectRaceRuleCpuCount();
            randomState->mValue =
                randomState->mIncrement + (u64) ((s64) randomState->mMultiplier * (s64) randomState->mValue);
            *entryOut = GetSelectRaceRuleHumanCount() +
                        (cpuCount == 0 ? (u32) (randomState->mValue >> 32)
                                       : (u32) (((s64) (u32) (randomState->mValue >> 32) * (s64) cpuCount) >> 32));
            break;
    }
    return TRUE;
}

// Moves a player to a team unless it is alone in its team, then moves another player to even the teams.
void ChangeSelectRaceRulePlayerTeam(u16 entryIndex, u32 teamIndex) {
    u16 cpuEntry;
    u16 ownIndex;
    cpuEntry = 8;
    if (teamIndex == gSelectRaceRule->mPlayerTeamIndices[entryIndex]) {
        return;
    }
    if (IsPlayerTeamPlayerCountNotOne(entryIndex) == 0) {
        ownIndex = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mOwnIndex : 0;
        if (entryIndex == data_0217aa00->mUnk_1e52[ownIndex].mEntryIndex) {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x16);
        }
        return;
    }
    SetSelectRaceRulePlayerTeam(entryIndex, teamIndex);
    if (IsSelectRaceRuleEntryHuman(entryIndex) != 0) {
        gSelectRaceRule->mTeamHumanCounts[teamIndex]++;
        gSelectRaceRule->mTeamHumanCounts[GetOtherTeamIndex(teamIndex)]--;
    } else {
        gSelectRaceRule->mUnk_b0[teamIndex]++;
        gSelectRaceRule->mUnk_b0[GetOtherTeamIndex(teamIndex)]--;
    }
    teamIndex = GetLargerTeamIndex();
    if (teamIndex != 2 && gSelectRaceRule->mUnk_b0[teamIndex] != 0) {
        PickSelectRaceRuleCpuEntry(&cpuEntry);
        while (teamIndex != gSelectRaceRule->mPlayerTeamIndices[cpuEntry]) {
            PickSelectRaceRuleCpuEntry(&cpuEntry);
        }
        ChangeSelectRaceRulePlayerTeam(cpuEntry, GetOtherTeamIndex(teamIndex));
    }
    ownIndex = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mOwnIndex : 0;
    if (entryIndex == data_0217aa00->mUnk_1e52[ownIndex].mEntryIndex) {
        switch (gSelectRaceRule->mPlayerTeamIndices[entryIndex]) {
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
    s32 team;
    s32 i;
    u16 humanCount;
    RandomState64 *randomState;
    team = 2;
    humanCount = GetSelectRaceRuleHumanCount();
    gSelectRaceRule->mTeamHumanCounts[0] = 0;
    gSelectRaceRule->mTeamHumanCounts[1] = 0;
    for (i = 0; i < humanCount; i++) {
        switch (gSelectRaceRule->mMode) {
            case 0:
            case 1:
                team = func_020ae3b4(2);
                break;
            case 2:
            case 3:
            case 4:
            case 5:
                randomState = &data_0217aa00->mUnk_1ee8;
                randomState->mValue =
                    randomState->mIncrement + (u64) ((s64) randomState->mMultiplier * (s64) randomState->mValue);
                team = ((u64) (u32) (randomState->mValue >> 32) * 2) >> 32;
                break;
        }
        if (humanCount / 2 <= gSelectRaceRule->mTeamHumanCounts[team]) {
            team = GetOtherTeamIndex(team);
        }
        SetSelectRaceRulePlayerTeam(i, team);
        gSelectRaceRule->mTeamHumanCounts[team]++;
    }
}

void func_0211cfd0(void) {
    s32 team;
    s32 i;
    RandomState64 *randomState;
    team = 2;
    GetSelectRaceRuleHumanCount();
    gSelectRaceRule->mUnk_b0[0] = 0;
    gSelectRaceRule->mUnk_b0[1] = 0;
    for (i = GetSelectRaceRuleHumanCount(); i < 8; i++) {
        switch (gSelectRaceRule->mMode) {
            case 0:
            case 1:
                team = func_020ae3b4(2);
                break;
            case 2:
            case 3:
            case 4:
            case 5:
                randomState = &data_0217aa00->mUnk_1ee8;
                randomState->mValue =
                    randomState->mIncrement + (u64) ((s64) randomState->mMultiplier * (s64) randomState->mValue);
                team = ((u64) (u32) (randomState->mValue >> 32) * 2) >> 32;
                break;
        }
        if (GetSelectRaceRuleTeamPlayerCount(team) >= 4) {
            team = GetOtherTeamIndex(team);
        }
        SetSelectRaceRulePlayerTeam(i, team);
        gSelectRaceRule->mUnk_b0[team]++;
    }
}

// FALSE for a value of the highlighted row that the current mode does not offer.
BOOL IsSelectRaceRuleValueAllowed(void) {
    SelectRaceRule *selectRaceRule;
    selectRaceRule = gSelectRaceRule;
    if (selectRaceRule->mRow == 0 && selectRaceRule->mRowValues[0] == 3 && func_0205fbb8(0x10) == 0) {
        return FALSE;
    }
    selectRaceRule = gSelectRaceRule;
    switch (selectRaceRule->mMode) {
        case 0:
            if (selectRaceRule->mRow == 1 && selectRaceRule->mRowValues[1] == 0) {
                return FALSE;
            }
            if (selectRaceRule->mRow == 4 && selectRaceRule->mRowValues[4] == 2) {
                return FALSE;
            }
            break;
        case 1:
            if (selectRaceRule->mRow == 1 && selectRaceRule->mRowValues[1] == 0) {
                return FALSE;
            }
            if (selectRaceRule->mRow == 3 && selectRaceRule->mRowValues[3] == SELECT_RACE_RULE_RACE) {
                return FALSE;
            }
            if (selectRaceRule->mRow == 4 && selectRaceRule->mRowValues[4] == 2) {
                return FALSE;
            }
            break;
        case 2:
            if (selectRaceRule->mRow == 4 && selectRaceRule->mRowValues[4] == 1) {
                return FALSE;
            }
            break;
        case 3:
            if (selectRaceRule->mRow == 3 && selectRaceRule->mRowValues[3] == SELECT_RACE_RULE_RACE) {
                return FALSE;
            }
            if (selectRaceRule->mRow == 4 && selectRaceRule->mRowValues[4] == 1) {
                return FALSE;
            }
            break;
        case 4:
            if (selectRaceRule->mRow == 4 && selectRaceRule->mRowValues[4] == 1) {
                return FALSE;
            }
            break;
        case 5:
            if (selectRaceRule->mRow == 3 && selectRaceRule->mRowValues[3] == SELECT_RACE_RULE_RACE) {
                return FALSE;
            }
            if (selectRaceRule->mRow == 4 && selectRaceRule->mRowValues[4] == 1) {
                return FALSE;
            }
            break;
    }
    return TRUE;
}

BOOL DoesSelectRaceRuleHumanCountMatch(void) {
    BOOL usesMask;
    u8 participantCount;
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
            usesMask = TRUE;
            if (data_0217aa00->mUnk_0004 != 8 && data_0217aa00->mUnk_0004 != 9) {
                usesMask = FALSE;
            }
            participantCount = usesMask != FALSE ? CountSetBits(data_0217aa00->mParticipantMask) : 0;
            if (participantCount == GetSelectRaceRuleHumanCount()) {
                return TRUE;
            }
            break;
    }
    return FALSE;
}

s32 IsSelectRaceRuleTeamsValid(void) {
    BOOL valid;
    valid = TRUE;
    if (GetSelectRaceRuleTeamPlayerCount(0) == 0) {
        valid = FALSE;
    }
    if (GetSelectRaceRuleTeamPlayerCount(1) == 0) {
        valid = FALSE;
    }
    if (GetLargerTeamIndex() != 2) {
        valid = FALSE;
    }
    if (DoesSelectRaceRuleHumanCountMatch() == FALSE) {
        valid = FALSE;
    }
    return valid;
}

void MoveSelectRaceRuleValueNext(s32 playSound) {
    SelectRaceRule *selectRaceRule;
    s32 i;
    gSelectRaceRule->mRowValues[gSelectRaceRule->mRow]++;
    if (data_0215ccc0[gSelectRaceRule->mRow] <= gSelectRaceRule->mRowValues[gSelectRaceRule->mRow]) {
        gSelectRaceRule->mRowValues[gSelectRaceRule->mRow] = 0;
    }
    if (IsSelectRaceRuleValueAllowed() == FALSE) {
        MoveSelectRaceRuleValueNext(0);
    }
    selectRaceRule = gSelectRaceRule;
    if (selectRaceRule->mRow != 3) {
        func_0212426c(
            1, data_0215cd4e[selectRaceRule->mRow * 2], selectRaceRule->mBnll,
            GetBmgEntry(selectRaceRule->mRuleMessages,
                        data_0216dc0c[selectRaceRule->mRow][selectRaceRule->mRowValues[selectRaceRule->mRow]]),
            selectRaceRule->mBncl, selectRaceRule->mTable);
    } else {
        switch (selectRaceRule->mRowValues[3]) {
            case SELECT_RACE_RULE_WIN:
                SetAndPrintSelectRaceRuleWinCount(selectRaceRule->mWinCount);
                break;
            case SELECT_RACE_RULE_RACE:
                SetAndPrintSelectRaceRuleRaceCount(selectRaceRule->mRaceCount);
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
            if (IsSelectRaceRuleTeamsValid() == 0) {
                func_0211d09c();
            }
            func_0202b618(0);
        } else {
            if (IsSelectRaceRuleTeamsValid() == 0) {
                func_0211cfd0();
            }
            func_0202b618(1);
        }
    }
    gSelectRaceRule->mRowChangeTimers[gSelectRaceRule->mRow][1] = 6;
    if (playSound != 0) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 1);
    }
}

void MoveSelectRaceRuleValuePrevious(s32 playSound) {
    SelectRaceRule *selectRaceRule;
    s32 i;
    gSelectRaceRule->mRowValues[gSelectRaceRule->mRow]--;
    if (gSelectRaceRule->mRowValues[gSelectRaceRule->mRow] < 0) {
        gSelectRaceRule->mRowValues[gSelectRaceRule->mRow] = data_0215ccc0[gSelectRaceRule->mRow] - 1;
    }
    if (IsSelectRaceRuleValueAllowed() == FALSE) {
        MoveSelectRaceRuleValuePrevious(0);
    }
    selectRaceRule = gSelectRaceRule;
    if (selectRaceRule->mRow != 3) {
        func_0212426c(
            1, data_0215cd4e[selectRaceRule->mRow * 2], selectRaceRule->mBnll,
            GetBmgEntry(selectRaceRule->mRuleMessages,
                        data_0216dc0c[selectRaceRule->mRow][selectRaceRule->mRowValues[selectRaceRule->mRow]]),
            selectRaceRule->mBncl, selectRaceRule->mTable);
    } else {
        switch (selectRaceRule->mRowValues[3]) {
            case SELECT_RACE_RULE_WIN:
                SetAndPrintSelectRaceRuleWinCount(selectRaceRule->mWinCount);
                break;
            case SELECT_RACE_RULE_RACE:
                SetAndPrintSelectRaceRuleRaceCount(selectRaceRule->mRaceCount);
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
            if (IsSelectRaceRuleTeamsValid() == 0) {
                func_0211d09c();
            }
            func_0202b618(0);
        } else {
            if (IsSelectRaceRuleTeamsValid() == 0) {
                func_0211cfd0();
            }
            func_0202b618(1);
        }
    }
    gSelectRaceRule->mRowChangeTimers[gSelectRaceRule->mRow][0] = 6;
    if (playSound != 0) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 1);
    }
}

void IncrementSelectRaceRuleCourseCount(void) {
    BOOL changed;
    SelectRaceRule *selectRaceRule;
    changed = FALSE;
    selectRaceRule = gSelectRaceRule;
    if (selectRaceRule->mRow == 3) {
        switch (selectRaceRule->mRowValues[3]) {
            case SELECT_RACE_RULE_WIN:
                SetAndPrintSelectRaceRuleWinCount(selectRaceRule->mWinCount + 1);
                gSelectRaceRule->mUnk_50[0][1] = 6;
                changed = TRUE;
                break;
            case SELECT_RACE_RULE_RACE:
                SetAndPrintSelectRaceRuleRaceCount(selectRaceRule->mRaceCount + 1);
                gSelectRaceRule->mUnk_50[0][1] = 6;
                changed = TRUE;
                break;
        }
        if (changed != FALSE) {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x17);
        }
    }
}

void DecrementSelectRaceRuleCourseCount(void) {
    BOOL changed;
    SelectRaceRule *selectRaceRule;
    changed = FALSE;
    selectRaceRule = gSelectRaceRule;
    if (selectRaceRule->mRow == 3) {
        switch (selectRaceRule->mRowValues[3]) {
            case SELECT_RACE_RULE_WIN:
                SetAndPrintSelectRaceRuleWinCount(selectRaceRule->mWinCount - 1);
                gSelectRaceRule->mUnk_50[0][0] = 6;
                changed = TRUE;
                break;
            case SELECT_RACE_RULE_RACE:
                SetAndPrintSelectRaceRuleRaceCount(selectRaceRule->mRaceCount - 1);
                gSelectRaceRule->mUnk_50[0][0] = 6;
                changed = TRUE;
                break;
        }
        if (changed != FALSE) {
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
                gSelectRaceRule->mTable[data_0215cd88[i][j]].mVisible = 0;
                gSelectRaceRule->mTable[data_0215cdb0[i][j]].mVisible = 0;
                gSelectRaceRule->mTable[data_0215cdc4[i][j]].mVisible = 0;
            }
        }
        return;
    }
    for (i = 0; i < 5; i++) {
        if (GetSelectRaceRuleHumanCount() == 8 && i == 1) {
            for (j = 0; j < 2; j++) {
                gSelectRaceRule->mTable[data_0215cd88[i][j]].mVisible = 0;
                gSelectRaceRule->mTable[data_0215cdb0[i][j]].mVisible = 0;
                gSelectRaceRule->mTable[data_0215cdc4[i][j]].mVisible = 0;
            }
        } else {
            gSelectRaceRule->mTable[data_0215cdb0[i][0]].mOffsetX =
                -func_020adc64(6 - gSelectRaceRule->mRowChangeTimers[i][0]);
            gSelectRaceRule->mTable[data_0215cdb0[i][1]].mOffsetX =
                func_020adc64(6 - gSelectRaceRule->mRowChangeTimers[i][1]);
            for (j = 0; j < 2; j++) {
                if (gSelectRaceRule->mRowChangeTimers[i][j] > 0) {
                    gSelectRaceRule->mRowChangeTimers[i][j]--;
                    gSelectRaceRule->mTable[data_0215cd88[i][j]].mVisible = 0;
                    gSelectRaceRule->mTable[data_0215cdb0[i][j]].mVisible = 1;
                    gSelectRaceRule->mTable[data_0215cdc4[i][j]].mVisible = 0;
                } else if (gSelectRaceRule->mRow == i && gSelectRaceRule->mOnButton == 0) {
                    gSelectRaceRule->mTable[data_0215cd88[i][j]].mVisible = 1;
                    gSelectRaceRule->mTable[data_0215cdb0[i][j]].mVisible = 0;
                    gSelectRaceRule->mTable[data_0215cdc4[i][j]].mVisible = 0;
                } else {
                    gSelectRaceRule->mTable[data_0215cd88[i][j]].mVisible = 0;
                    gSelectRaceRule->mTable[data_0215cdb0[i][j]].mVisible = 0;
                    gSelectRaceRule->mTable[data_0215cdc4[i][j]].mVisible = 1;
                }
            }
        }
    }
    if (gSelectRaceRule->mMode == 3) {
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mTable[data_0215cd88[0][j]].mVisible = 0;
            gSelectRaceRule->mTable[data_0215cd88[2][j]].mVisible = 0;
            gSelectRaceRule->mTable[data_0215cdb0[0][j]].mVisible = 0;
            gSelectRaceRule->mTable[data_0215cdb0[2][j]].mVisible = 0;
            gSelectRaceRule->mTable[data_0215cdc4[0][j]].mVisible = 0;
            gSelectRaceRule->mTable[data_0215cdc4[2][j]].mVisible = 0;
        }
    }
}

void func_0211c810(u16 entryIndex, u32 value) {
    func_020294c0(entryIndex, value);
}

void func_0211c5ac(void) {
    u16 cpuEntries[2];
    s32 i;
    u16 cpuEntry;
    SelectRaceRule *selectRaceRule;
    cpuEntries[0] = 8;
    cpuEntries[1] = 8;
    for (i = 0; i < 8; i++) {
        func_0211c810(i, 3);
    }
    if (GetSelectRaceRuleCpuCount() != 0) {
        selectRaceRule = gSelectRaceRule;
        if (selectRaceRule->mRowValues[4] == 0) {
            PickSelectRaceRuleCpuEntry(&cpuEntries[0]);
            func_0211c810(cpuEntries[0], 0);
            if (GetSelectRaceRuleCpuCount() > 1) {
                PickSelectRaceRuleCpuEntry(&cpuEntries[1]);
                while (cpuEntries[0] == cpuEntries[1]) {
                    PickSelectRaceRuleCpuEntry(&cpuEntries[1]);
                }
                func_0211c810(cpuEntries[1], 1);
            }
        } else if (selectRaceRule->mUnk_b0[GetOtherTeamIndex(selectRaceRule->mPlayerTeamIndices[0])] != 0) {
            PickSelectRaceRuleCpuEntry(&cpuEntries[0]);
            cpuEntry = cpuEntries[0];
            while (gSelectRaceRule->mPlayerTeamIndices[cpuEntry] !=
                   GetOtherTeamIndex(gSelectRaceRule->mPlayerTeamIndices[0])) {
                PickSelectRaceRuleCpuEntry(&cpuEntries[0]);
                cpuEntry = cpuEntries[0];
            }
            func_0211c810(cpuEntry, 0);
            if (gSelectRaceRule->mUnk_b0[gSelectRaceRule->mPlayerTeamIndices[0]] != 0) {
                PickSelectRaceRuleCpuEntry(&cpuEntries[1]);
                while (gSelectRaceRule->mPlayerTeamIndices[0] != gSelectRaceRule->mPlayerTeamIndices[cpuEntries[1]]) {
                    PickSelectRaceRuleCpuEntry(&cpuEntries[1]);
                }
                func_0211c810(cpuEntries[1], 1);
            } else if (gSelectRaceRule->mUnk_b0[GetOtherTeamIndex(gSelectRaceRule->mPlayerTeamIndices[0])] > 1) {
                PickSelectRaceRuleCpuEntry(&cpuEntries[1]);
                while (gSelectRaceRule->mPlayerTeamIndices[cpuEntries[1]] !=
                           GetOtherTeamIndex(gSelectRaceRule->mPlayerTeamIndices[0]) ||
                       cpuEntries[0] == cpuEntries[1]) {
                    PickSelectRaceRuleCpuEntry(&cpuEntries[1]);
                }
                func_0211c810(cpuEntries[1], 1);
            }
        } else if (gSelectRaceRule->mUnk_b0[gSelectRaceRule->mPlayerTeamIndices[0]] != 0) {
            PickSelectRaceRuleCpuEntry(&cpuEntries[0]);
            while (gSelectRaceRule->mPlayerTeamIndices[0] != gSelectRaceRule->mPlayerTeamIndices[cpuEntries[0]]) {
                PickSelectRaceRuleCpuEntry(&cpuEntries[0]);
            }
            func_0211c810(cpuEntries[0], 0);
            if (gSelectRaceRule->mUnk_b0[gSelectRaceRule->mPlayerTeamIndices[0]] > 1) {
                PickSelectRaceRuleCpuEntry(&cpuEntries[1]);
                while (gSelectRaceRule->mPlayerTeamIndices[0] != gSelectRaceRule->mPlayerTeamIndices[cpuEntries[1]] ||
                       cpuEntries[0] == cpuEntries[1]) {
                    PickSelectRaceRuleCpuEntry(&cpuEntries[1]);
                }
                func_0211c810(cpuEntries[1], 1);
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
        SetMirrorMode();
    } else {
        SetEngineIndex(data_0215cd18[gSelectRaceRule->mRowValues[0]]);
        ClearMirrorMode();
    }
    SetCpuDifficulty(data_0215cd28[gSelectRaceRule->mRowValues[1]]);
    SetCourseListMode(data_0215cce4[gSelectRaceRule->mRowValues[2]]);
    SetRuleKind(data_0215ccf0[gSelectRaceRule->mRowValues[3]]);
    switch (gSelectRaceRule->mRowValues[3]) {
        case SELECT_RACE_RULE_WIN:
            SetRaceSetupCopyCourseCount(gSelectRaceRule->mWinCount);
            break;
        case SELECT_RACE_RULE_RACE:
            SetRaceSetupCopyCourseCount(gSelectRaceRule->mRaceCount);
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
    u16 ownIndex;
    if (data_021759d0->mUnk_20 != 2) {
        if (gSelectRaceRule->mRowValues[3] != SELECT_RACE_RULE_FREE) {
            if (gSelectRaceRule->mRow == 3 && gSelectRaceRule->mOnButton == 0) {
                gSelectRaceRule->mTable[30].mVisible = 1;
                gSelectRaceRule->mTable[31].mVisible = 0;
            } else {
                gSelectRaceRule->mTable[30].mVisible = 0;
                gSelectRaceRule->mTable[31].mVisible = 1;
            }
            for (j = 0; j < 2; j++) {
                if (gSelectRaceRule->mUnk_50[0][j] > 0) {
                    gSelectRaceRule->mUnk_50[0][j]--;
                    gSelectRaceRule->mTable[data_0215ccac[0][j]].mVisible = 1;
                } else {
                    gSelectRaceRule->mTable[data_0215ccac[0][j]].mVisible = 0;
                }
            }
        } else {
            gSelectRaceRule->mTable[30].mVisible = 0;
            gSelectRaceRule->mTable[31].mVisible = 0;
            for (j = 0; j < 2; j++) {
                gSelectRaceRule->mTable[data_0215ccac[0][j]].mVisible = 0;
            }
        }
        if (gSelectRaceRule->mRowValues[4] == 2) {
            for (j = 0; j < 2; j++) {
                if (gSelectRaceRule->mRow == 4 && gSelectRaceRule->mOnButton == 0) {
                    ownIndex = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mOwnIndex : 0;
                    if (IsPlayerTeamPlayerCountNotOne(data_0217aa00->mUnk_1e52[ownIndex].mEntryIndex) != 0) {
                        gSelectRaceRule->mTable[data_0215cc6c[j]].mVisible = 1;
                        gSelectRaceRule->mTable[data_0215cc70[j]].mVisible = 0;
                    } else {
                        gSelectRaceRule->mTable[data_0215cc6c[j]].mVisible = 0;
                        gSelectRaceRule->mTable[data_0215cc70[j]].mVisible = 1;
                    }
                } else {
                    gSelectRaceRule->mTable[data_0215cc6c[j]].mVisible = 0;
                    gSelectRaceRule->mTable[data_0215cc70[j]].mVisible = 1;
                }
                if (gSelectRaceRule->mUnk_50[1][j] > 0) {
                    gSelectRaceRule->mUnk_50[1][j]--;
                    gSelectRaceRule->mTable[data_0215ccac[1][j]].mVisible = 1;
                } else {
                    gSelectRaceRule->mTable[data_0215ccac[1][j]].mVisible = 0;
                }
            }
        } else {
            for (j = 0; j < 2; j++) {
                gSelectRaceRule->mTable[data_0215cc6c[j]].mVisible = 0;
                gSelectRaceRule->mTable[data_0215cc70[j]].mVisible = 0;
                gSelectRaceRule->mTable[data_0215ccac[1][j]].mVisible = 0;
            }
        }
    } else {
        gSelectRaceRule->mTable[30].mVisible = 0;
        gSelectRaceRule->mTable[31].mVisible = 0;
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mTable[data_0215ccac[0][j]].mVisible = 0;
        }
        if (gSelectRaceRule->mRowValues[4] == 2) {
            for (j = 0; j < 2; j++) {
                ownIndex = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mOwnIndex : 0;
                if (IsPlayerTeamPlayerCountNotOne(data_0217aa00->mUnk_1e52[ownIndex].mEntryIndex) != 0) {
                    gSelectRaceRule->mTable[data_0215cc6c[j]].mVisible = 1;
                    gSelectRaceRule->mTable[data_0215cc70[j]].mVisible = 0;
                } else {
                    gSelectRaceRule->mTable[data_0215cc6c[j]].mVisible = 1;
                    gSelectRaceRule->mTable[data_0215cc70[j]].mVisible = 1;
                }
                if (gSelectRaceRule->mUnk_50[1][j] > 0) {
                    gSelectRaceRule->mUnk_50[1][j]--;
                    gSelectRaceRule->mTable[data_0215ccac[1][j]].mVisible = 1;
                } else {
                    gSelectRaceRule->mTable[data_0215ccac[1][j]].mVisible = 0;
                }
            }
        } else {
            for (j = 0; j < 2; j++) {
                gSelectRaceRule->mTable[data_0215cc6c[j]].mVisible = 0;
                gSelectRaceRule->mTable[data_0215cc70[j]].mVisible = 0;
                gSelectRaceRule->mTable[data_0215ccac[1][j]].mVisible = 0;
            }
        }
    }
}

void func_0211c0cc(void) {
    SelectRaceRule *selectRaceRule;
    if (data_021759d0->mUnk_20 == 2) {
        gSelectRaceRule->mTable[gSelectRaceRule->mBncl->mUnk_06 + 14].mVisible = 1;
        selectRaceRule = gSelectRaceRule;
        if (selectRaceRule->mRowValues[4] == 2) {
            func_0212426c(1, 0xe, gSelectRaceRule->mBnll, GetBmgEntry(selectRaceRule->mRuleMessages, 0x15),
                          selectRaceRule->mBncl, selectRaceRule->mTable);
        } else {
            func_0212426c(1, 0xe, gSelectRaceRule->mBnll, GetBmgEntry(selectRaceRule->mRuleMessages, 0x14),
                          selectRaceRule->mBncl, selectRaceRule->mTable);
        }
    }
}

void AdvanceSelectRaceRuleTeamInput(void) {
    s32 i;
    s32 hitRectIndex;
    BOOL newPair;
    BOOL noPairForFewCalls;
    u32 slotIndex;
    InputSlot *inputSlot;
    u16 hasPair;
    if (gSelectRaceRule->mRowValues[4] == 2) {
        for (i = 0; i < 8; i++) {
            slotIndex = data_0215cdec[i];
            hitRectIndex = -1;
            newPair = FALSE;
            noPairForFewCalls = FALSE;
            inputSlot = &data_02175628[slotIndex];
            hasPair = inputSlot->mHasPair;
            if (hasPair == 0 && inputSlot->mNoPairCount < 5) {
                noPairForFewCalls = TRUE;
            }
            if (noPairForFewCalls == FALSE && inputSlot->mPrevHasPair == 0 && hasPair != 0) {
                newPair = TRUE;
            }
            if (newPair != FALSE) {
                hitRectIndex = RectTableFindContaining(gSelectRaceRule->mBnbl, inputSlot->mPairX,
                                                       inputSlot->mPairY - gSelectRaceRule->mOffsetY);
            }
            if (GetNewOrRepeatBits(slotIndex, PAD_KEY_L) != 0 || hitRectIndex == 0x11) {
                if (i == 0) {
                    if (hitRectIndex == 0x11) {
                        gSelectRaceRule->mRow = 4;
                        gSelectRaceRule->mOnButton = 0;
                    }
                    if (gSelectRaceRule->mOnButton == 0 && gSelectRaceRule->mRow == 4) {
                        ChangeSelectRaceRulePlayerTeam(i, 0);
                    }
                } else {
                    ChangeSelectRaceRulePlayerTeam(i, 0);
                }
            } else if (GetNewOrRepeatBits(slotIndex, PAD_KEY_R) != 0 || hitRectIndex == 0x12) {
                if (i == 0) {
                    if (hitRectIndex == 0x12) {
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
    s32 teamValue;
    s32 i;
    u32 value;
    teamValue = 3;
    if (GetPreviousMenuScreenNumber() == 8 || GetPreviousMenuScreenNumber() == 9 ||
        GetPreviousMenuScreenNumber() == 0xf) {
        ClearUseTeams();
        ClearMirrorMode();
        SetEngineIndex(0);
        SetCpuDifficulty(0);
        SetCourseListMode(0);
        SetRuleKind(0);
        SetRaceSetupCopyCourseCount(0);
    }
    if (GetUseTeams() != 0) {
        switch (gSelectRaceRule->mMode) {
            case 0:
            case 1:
                teamValue = 1;
                break;
            case 2:
            case 3:
            case 4:
            case 5:
                teamValue = 2;
                break;
        }
        for (i = 0; i < 8; i++) {
            value = data_0215cc9c[GetTeamIndex(i)];
            SetSelectRaceRulePlayerTeam(i, value);
            if (GetPlayerKind(i) == PLAYER_KIND_HUMAN) {
                gSelectRaceRule->mTeamHumanCounts[value]++;
            } else {
                gSelectRaceRule->mUnk_b0[value]++;
            }
        }
    } else {
        teamValue = 0;
    }
    gSelectRaceRule->mRow = 4;
    while (teamValue != gSelectRaceRule->mRowValues[4]) {
        MoveSelectRaceRuleValueNext(0);
    }
    if (GetMirrorMode() != 0) {
        value = 3;
    } else {
        value = data_0215ccfc[GetEngineIndex()];
    }
    teamValue = 0;
    gSelectRaceRule->mRow = 0;
    while (value != gSelectRaceRule->mRowValues[0]) {
        MoveSelectRaceRuleValueNext(0);
    }
    value = data_0215cd08[GetCpuDifficulty()];
    gSelectRaceRule->mRow = 1;
    while (value != gSelectRaceRule->mRowValues[1]) {
        MoveSelectRaceRuleValueNext(0);
    }
    switch (gSelectRaceRule->mMode) {
        case 0:
        case 1:
            if (value == 0 && gSelectRaceRule->mRowValues[1] != 2) {
                do {
                    MoveSelectRaceRuleValueNext(0);
                } while (gSelectRaceRule->mRowValues[1] != 2);
            }
            break;
    }
    value = data_0215cccc[GetCourseListMode()];
    gSelectRaceRule->mRow = 2;
    while (value != gSelectRaceRule->mRowValues[2]) {
        MoveSelectRaceRuleValueNext(0);
    }
    value = data_0215ccd8[GetRuleKind()];
    gSelectRaceRule->mRow = 3;
    while (value != gSelectRaceRule->mRowValues[3]) {
        MoveSelectRaceRuleValueNext(0);
    }
    switch (gSelectRaceRule->mRowValues[3]) {
        case SELECT_RACE_RULE_WIN:
            SetAndPrintSelectRaceRuleWinCount(GetRaceSetupCopyCourseCount());
            break;
        case SELECT_RACE_RULE_RACE:
            SetAndPrintSelectRaceRuleRaceCount(GetRaceSetupCopyCourseCount());
            break;
    }
    gSelectRaceRule->mRow = 0;
}

void SetSelectRaceRuleHumanCount(void) {
    BOOL usesMask;
    u8 participantCount;
    switch (gSelectRaceRule->mMode) {
        case 0:
        case 1:
            gSelectRaceRule->mTeamHumanCounts[0] = 1;
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            usesMask = TRUE;
            if (data_0217aa00->mUnk_0004 != 8 && data_0217aa00->mUnk_0004 != 9) {
                usesMask = FALSE;
            }
            participantCount = usesMask != FALSE ? CountSetBits(data_0217aa00->mParticipantMask) : 0;
            gSelectRaceRule->mTeamHumanCounts[0] = participantCount;
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
    gSelectRaceRule->mTable[40].mOffsetY = gSelectRaceRule->mOffsetY + 0xc0;
    gSelectRaceRule->mTable[41].mOffsetY = gSelectRaceRule->mOffsetY + 0xc0;
    gSelectRaceRule->mTable[42].mOffsetY = gSelectRaceRule->mOffsetY + 0xc0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mTable[data_0215cd88[i][j]].mOffsetY = gSelectRaceRule->mOffsetY - 0xc0;
            gSelectRaceRule->mTable[data_0215cdb0[i][j]].mOffsetY = gSelectRaceRule->mOffsetY - 0xc0;
            gSelectRaceRule->mTable[data_0215cdc4[i][j]].mOffsetY = gSelectRaceRule->mOffsetY - 0xc0;
        }
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mTable[c + gSelectRaceRuleRowEntries[i].mEntryIndices[j]].mOffsetY =
                gSelectRaceRule->mOffsetY - 0xc0;
        }
    }
    gSelectRaceRule->mTable[c + 10].mOffsetY = gSelectRaceRule->mOffsetY - 0xc0;
    gSelectRaceRule->mTable[c + 12].mOffsetY = gSelectRaceRule->mOffsetY - 0xc0;
    gSelectRaceRule->mTable[30].mOffsetY = gSelectRaceRule->mOffsetY - 0xc0;
    gSelectRaceRule->mTable[31].mOffsetY = gSelectRaceRule->mOffsetY - 0xc0;
    gSelectRaceRule->mTable[34].mOffsetY = gSelectRaceRule->mOffsetY - 0xc0;
    gSelectRaceRule->mTable[37].mOffsetY = gSelectRaceRule->mOffsetY - 0xc0;
    gSelectRaceRule->mTable[35].mOffsetY = gSelectRaceRule->mOffsetY - 0xc0;
    gSelectRaceRule->mTable[38].mOffsetY = gSelectRaceRule->mOffsetY - 0xc0;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mTable[data_0215ccac[i][j]].mOffsetY = gSelectRaceRule->mOffsetY - 0xc0;
        }
    }
    if (data_021759d0->mUnk_20 != 2) {
        gSelectRaceRule->mTable[c + 13].mOffsetY = gSelectRaceRule->mOffsetY + 0xc0;
        c += 8;
        gSelectRaceRule->mTable[c].mOffsetY = gSelectRaceRule->mOffsetY + 0xc0;
    } else {
        c += 14;
        gSelectRaceRule->mTable[c].mOffsetY = gSelectRaceRule->mOffsetY + 0xc0;
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
    void *message;
    gSelectRaceRule->mNextState = 5;
    gSelectRaceRule->mStateFrames = 0;
    message = GetBmgEntry(gSelectRaceRule->mCommonMessages, 4);
    StartSelectChoises(message, GetBmgEntry(gSelectRaceRule->mCommonMessages, 2), 0);
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

void InitSelectRaceRule(void *parentHeap, s32 b, void *oamList, s32 mode) {
    void *heap;
    s32 i;
    s32 j;
    s32 cellEntryCount;
    s32 remainingSubObjSize;
    SelectRaceRule *selectRaceRule;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x8200;
    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gSelectRaceRule = HeapAlloc(heap, 0xbc);
    gSelectRaceRule->mHeap = heap;
    gSelectRaceRule->mMode = mode;
    gSelectRaceRule->mState = 0;
    gSelectRaceRule->mRow = 0;
    gSelectRaceRule->mPrevRow = 4;
    gSelectRaceRule->mOffsetY = 0;
    gSelectRaceRule->mOnButton = 0;
    gSelectRaceRule->mPrevOnButton = 0;
    gSelectRaceRule->mUnk_84 = 1;
    gSelectRaceRule->mWinCount = 0;
    gSelectRaceRule->mRaceCount = 0;
    gSelectRaceRule->mOamList = oamList;
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
    cellEntryCount = gSelectRaceRule->mBncl->mUnk_06;
    remainingSubObjSize = GX_GetSizeOfSubOBJ();
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            if (!(i == 3 && j == 1)) {
                remainingSubObjSize -= InitLabelCanvas(
                    gSelectRaceRule->mHeap, gSelectRaceRuleRowEntries[i].mEntryIndices[j], gSelectRaceRule->mBnll,
                    data_0215cd60[i][j], data_0215cd74[i].h[j], i * 2 + j, gSelectRaceRule->mNcer,
                    gSelectRaceRule->mBncl, gSelectRaceRule->mTable, remainingSubObjSize);
            }
        }
        selectRaceRule = gSelectRaceRule;
        func_0212426c(1, gSelectRaceRuleRowEntries[i].mEntryIndices[0], gSelectRaceRule->mBnll,
                      GetBmgEntry(selectRaceRule->mRuleMessages, data_0215ccb4[i]), selectRaceRule->mBncl,
                      selectRaceRule->mTable);
        if (i != 3) {
            selectRaceRule = gSelectRaceRule;
            func_0212426c(1, gSelectRaceRuleRowEntries[i].mEntryIndices[1], gSelectRaceRule->mBnll,
                          GetBmgEntry(selectRaceRule->mRuleMessages, data_0216dc0c[i][selectRaceRule->mRowValues[i]]),
                          selectRaceRule->mBncl, selectRaceRule->mTable);
        }
    }
    if (data_021759d0->mUnk_20 != 2) {
        selectRaceRule = gSelectRaceRule;
        remainingSubObjSize -=
            InitLabelCanvas(selectRaceRule->mHeap, 9, selectRaceRule->mBnll, 0x96, 0xf, cellEntryCount + 3,
                            selectRaceRule->mNcer, selectRaceRule->mBncl, selectRaceRule->mTable, remainingSubObjSize);
        selectRaceRule = gSelectRaceRule;
        remainingSubObjSize -=
            InitLabelCanvas(selectRaceRule->mHeap, 0xa, selectRaceRule->mBnll, 0xc8, 0xf, cellEntryCount + 9,
                            selectRaceRule->mNcer, selectRaceRule->mBncl, selectRaceRule->mTable, remainingSubObjSize);
        selectRaceRule = gSelectRaceRule;
        func_0212426c(1, 0xa, gSelectRaceRule->mBnll,
                      GetBmgEntry(selectRaceRule->mRuleMessages, data_0216dc0c[3][SELECT_RACE_RULE_FREE]),
                      selectRaceRule->mBncl, selectRaceRule->mTable);
    } else {
        selectRaceRule = gSelectRaceRule;
        remainingSubObjSize -=
            InitLabelCanvas(selectRaceRule->mHeap, 0xa, selectRaceRule->mBnll, 0xc8, 0xf, cellEntryCount + 3,
                            selectRaceRule->mNcer, selectRaceRule->mBncl, selectRaceRule->mTable, remainingSubObjSize);
        selectRaceRule = gSelectRaceRule;
        func_0212426c(1, 0xa, gSelectRaceRule->mBnll,
                      GetBmgEntry(selectRaceRule->mRuleMessages, data_0216dc0c[3][SELECT_RACE_RULE_FREE]),
                      selectRaceRule->mBncl, selectRaceRule->mTable);
    }
    selectRaceRule = gSelectRaceRule;
    remainingSubObjSize -=
        InitLabelCanvas(selectRaceRule->mHeap, 0xc, selectRaceRule->mBnll, 0x37, 0xf, cellEntryCount + 0xb,
                        selectRaceRule->mNcer, selectRaceRule->mBncl, selectRaceRule->mTable, remainingSubObjSize);
    selectRaceRule = gSelectRaceRule;
    func_0212426c(1, 0xc, gSelectRaceRule->mBnll, GetBmgEntry(selectRaceRule->mRuleMessages, data_0216dc0c[4][2]),
                  selectRaceRule->mBncl, selectRaceRule->mTable);
    if (data_021759d0->mUnk_20 != 2) {
        selectRaceRule = gSelectRaceRule;
        remainingSubObjSize -=
            InitLabelCanvas(selectRaceRule->mHeap, 0xd, selectRaceRule->mBnll, 0x32, 0xd, 0x29, selectRaceRule->mNcer,
                            selectRaceRule->mBncl, selectRaceRule->mTable, remainingSubObjSize);
        selectRaceRule = gSelectRaceRule;
        func_0212426c(1, 0xd, gSelectRaceRule->mBnll, GetBmgEntry(selectRaceRule->mCommonMessages, 4),
                      selectRaceRule->mBncl, selectRaceRule->mTable);
        selectRaceRule = gSelectRaceRule;
        InitLabelCanvas(selectRaceRule->mHeap, 8, selectRaceRule->mBnll, 0x15, 0xf, 0x1f, selectRaceRule->mNcer,
                        selectRaceRule->mBncl, selectRaceRule->mTable, remainingSubObjSize);
    } else {
        selectRaceRule = gSelectRaceRule;
        InitLabelCanvas(selectRaceRule->mHeap, 0xe, selectRaceRule->mBnll, 0xc8, 0xd, 0x2a, selectRaceRule->mNcer,
                        selectRaceRule->mBncl, selectRaceRule->mTable, remainingSubObjSize);
    }
    SetAndPrintSelectRaceRuleWinCount(0);
    SetAndPrintSelectRaceRuleRaceCount(0);
    switch (gSelectRaceRule->mMode) {
        case 2:
        case 4:
            func_021170f8();
            FillRandomCharacterIndices();
            func_02117060();
            FillRandomKartIndices();
            break;
        case 3:
        case 5:
            func_021170f8();
            FillRandomCharacterIndices();
            func_02117060();
            SetKartIndicesFromCharacters();
            break;
    }
    switch (gSelectRaceRule->mMode) {
        case 0:
        case 1:
            SetupPlayerEntryList(0, PLAYER_ENTRY_LIST_RACE_RULE);
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            SetupPlayerEntryList(1, PLAYER_ENTRY_LIST_RACE_RULE);
            break;
    }
    ReadRaceSetupCopyIntoSelectRaceRule();
    if (IsSelectRaceRuleTeamsValid() == 0) {
        SetSelectRaceRuleHumanCount();
        func_0211d09c();
        func_0211cfd0();
    }
    selectRaceRule = gSelectRaceRule;
    switch (selectRaceRule->mMode) {
        case 0:
            selectRaceRule->mRow = 1;
            if (gSelectRaceRule->mRowValues[1] == 0) {
                MoveSelectRaceRuleValueNext(0);
            }
            gSelectRaceRule->mRow = 0;
            break;
        case 1:
            selectRaceRule->mOffsetY = -0x1c;
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
            selectRaceRule->mOffsetY = -0x1c;
            gSelectRaceRule->mRow = 1;
            if (GetSelectRaceRuleHumanCount() == 8) {
                gSelectRaceRule->mRow = 2;
            }
            break;
        case 3:
            selectRaceRule->mRow = 3;
            if (gSelectRaceRule->mRowValues[3] == SELECT_RACE_RULE_RACE) {
                MoveSelectRaceRuleValuePrevious(0);
            }
            gSelectRaceRule->mRow = 1;
            if (GetSelectRaceRuleHumanCount() == 8) {
                gSelectRaceRule->mRow = 3;
            }
            break;
        case 5:
            selectRaceRule->mOffsetY = -0x1c;
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
            gSelectRaceRule->mTable[cellEntryCount + gSelectRaceRuleRowEntries[0].mEntryIndices[0]].mVisible = 0;
            break;
        case 2:
            gSelectRaceRule->mTable[cellEntryCount + gSelectRaceRuleRowEntries[0].mEntryIndices[0]].mVisible = 0;
            break;
        case 3:
            gSelectRaceRule->mTable[cellEntryCount + gSelectRaceRuleRowEntries[0].mEntryIndices[0]].mVisible = 0;
            gSelectRaceRule->mTable[cellEntryCount + gSelectRaceRuleRowEntries[2].mEntryIndices[0]].mVisible = 0;
            gSelectRaceRule->mTable[cellEntryCount + gSelectRaceRuleRowEntries[0].mEntryIndices[1]].mVisible = 0;
            gSelectRaceRule->mTable[cellEntryCount + gSelectRaceRuleRowEntries[2].mEntryIndices[1]].mVisible = 0;
            for (j = 0; j < 2; j++) {
                gSelectRaceRule->mTable[data_0215cd88[0][j]].mVisible = 0;
                gSelectRaceRule->mTable[data_0215cd88[2][j]].mVisible = 0;
                gSelectRaceRule->mTable[data_0215cdb0[0][j]].mVisible = 0;
                gSelectRaceRule->mTable[data_0215cdb0[2][j]].mVisible = 0;
                gSelectRaceRule->mTable[data_0215cdc4[0][j]].mVisible = 0;
                gSelectRaceRule->mTable[data_0215cdc4[2][j]].mVisible = 0;
            }
            break;
        case 5:
            gSelectRaceRule->mTable[cellEntryCount + gSelectRaceRuleRowEntries[0].mEntryIndices[0]].mVisible = 0;
            break;
    }
    if (GetSelectRaceRuleHumanCount() == 8 && gSelectRaceRule->mRowValues[1] != 0) {
        do {
            MoveSelectRaceRuleValuePrevious(0);
        } while (gSelectRaceRule->mRowValues[1] != 0);
    }
    ResetSelectRaceRulePositions();
    selectRaceRule = gSelectRaceRule;
    CreateWait(selectRaceRule->mHeap, selectRaceRule->mNcer, selectRaceRule->mBncl, 0x2a, 0xe, 1);
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        InitPaletteBlend(gSelectRaceRule->mHeap, gSelectRaceRule->mNclr, 9);
    }
    FrmHeapShrinkInParent(gSelectRaceRule->mHeap);
    AdvanceSelectRaceRuleHighlight();
}

void ReleaseSelectRaceRule(void) {
    SelectRaceRule *selectRaceRule;
    u32 dispcntBits8To12;
    u32 bg2Control;
    selectRaceRule = gSelectRaceRule;
    if (selectRaceRule->mResult == 1 && (selectRaceRule->mMode == 3 || selectRaceRule->mRowValues[2] == 1)) {
        dispcntBits8To12 = ((reg_GX_DISPCNT) & 0x1f00) >> 8;
        dispcntBits8To12 &= ~3;
        (reg_GX_DISPCNT) = ((reg_GX_DISPCNT) & 0xffffe0ff) | (dispcntBits8To12 << 8);
    }
    bg2Control = (reg_G2_BG2CNT);
    bg2Control &= ~3;
    (reg_G2_BG2CNT) = bg2Control;
    (reg_G2_BG2CNT) = ((reg_G2_BG2CNT) & 0x43) | 0x9e10;
    ClearWaitPointer();
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        func_0212b91c();
    }
    HeapDestroy(gSelectRaceRule->mHeap);
    gSelectRaceRule = NULL;
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectRaceRuleState0(void) {
    int fadesClear;
    fadesClear = AreBrightnessFadesClear();
    if (fadesClear != 0) {
        RequestSelectRaceRuleState1();
    }
}

#pragma thumb off

#pragma thumb on

void AdvanceSelectRaceRuleState1(void) {
    SelectRaceRule *selectRaceRule;
    s32 i;
    s16 rowsOffsetY;
    s32 j;
    s32 c;
    AdvanceSelectRaceRuleRowObjects();
    func_0211c14c();
    gSelectRaceRule->mStateFrames++;
    selectRaceRule = gSelectRaceRule;
    c = InterpolateS16(1, -192, 0, selectRaceRule->mStateFrames, 10);
    rowsOffsetY = selectRaceRule->mOffsetY + c;
    selectRaceRule->mBg3Offset = rowsOffsetY;
    c = gSelectRaceRule->mBncl->mUnk_06;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mTable[data_0215cd88[i][j]].mOffsetY = rowsOffsetY;
            gSelectRaceRule->mTable[data_0215cdb0[i][j]].mOffsetY = rowsOffsetY;
            gSelectRaceRule->mTable[data_0215cdc4[i][j]].mOffsetY = rowsOffsetY;
        }
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mTable[c + gSelectRaceRuleRowEntries[i].mEntryIndices[j]].mOffsetY = rowsOffsetY;
        }
    }
    gSelectRaceRule->mTable[c + 10].mOffsetY = rowsOffsetY;
    gSelectRaceRule->mTable[c + 12].mOffsetY = rowsOffsetY;
    gSelectRaceRule->mTable[34].mOffsetY = rowsOffsetY;
    gSelectRaceRule->mTable[37].mOffsetY = rowsOffsetY;
    gSelectRaceRule->mTable[35].mOffsetY = rowsOffsetY;
    gSelectRaceRule->mTable[38].mOffsetY = rowsOffsetY;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            gSelectRaceRule->mTable[data_0215ccac[i][j]].mOffsetY = rowsOffsetY;
        }
    }
    if (data_021759d0->mUnk_20 != 2) {
        c += 8;
        gSelectRaceRule->mTable[c].mOffsetY = rowsOffsetY;
        gSelectRaceRule->mTable[30].mOffsetY = rowsOffsetY;
        gSelectRaceRule->mTable[31].mOffsetY = rowsOffsetY;
    }
    if (gSelectRaceRule->mStateFrames >= 10) {
        RequestSelectRaceRuleState2();
    }
}

void AdvanceSelectRaceRuleState2(void) {
    s16 returnOffsetY;
    s32 cellEntryCount;
    AdvanceSelectRaceRuleRowObjects();
    func_0211c14c();
    gSelectRaceRule->mStateFrames++;
    returnOffsetY = -LookupSelectReturnState1Bg2Offset(gSelectRaceRule->mStateFrames);
    cellEntryCount = gSelectRaceRule->mBncl->mUnk_06;
    if (data_021759d0->mUnk_20 != 2) {
        gSelectRaceRule->mTable[0x28].mOffsetY = returnOffsetY;
        gSelectRaceRule->mTable[0x29].mOffsetY = returnOffsetY;
        gSelectRaceRule->mTable[cellEntryCount + 13].mOffsetY = returnOffsetY;
    } else {
        gSelectRaceRule->mTable[0x2a].mOffsetY = returnOffsetY;
        gSelectRaceRule->mTable[cellEntryCount + 14].mOffsetY = returnOffsetY;
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
    u32 hitRectIndex;
    BOOL newPair;
    BOOL noPairForFewCalls;
    InputSlotIndex i;
    u32 row;
    u16 hasPair;
    hitRectIndex = -1;
    i = UNK_02175628_INDEX_8;
    AdvanceSelectRaceRuleRowObjects();
    func_0211c14c();
    newPair = FALSE;
    noPairForFewCalls = FALSE;
    p = &data_02175674[i];
    hasPair = data_02175674[i].mUnk_00;
    if (hasPair == 0 && data_02175680[i].mUnk_00 < 5) {
        noPairForFewCalls = TRUE;
    }
    if (noPairForFewCalls == FALSE && data_0217567c[i].mUnk_00 == 0 && hasPair != 0) {
        newPair = TRUE;
    }
    if (newPair != FALSE) {
        r = &data_02175672[i];
        q = &data_02175670[i];
        hitRectIndex =
            RectTableFindContaining(gSelectRaceRule->mBnbl, data_02175670[i].mUnk_00, data_02175672[i].mUnk_00);
        if (hitRectIndex != 0x13) {
            hitRectIndex =
                RectTableFindContaining(gSelectRaceRule->mBnbl, q->mUnk_00, r->mUnk_00 - gSelectRaceRule->mOffsetY);
            if (hitRectIndex == 0x13) {
                hitRectIndex = -1;
            }
        }
    }
    r = &data_02175628[i];
    if ((u16) (r->mUnk_00 & PAD_KEY_B) == 0) {
        newPair = FALSE;
        noPairForFewCalls = FALSE;
        hasPair = p->mUnk_00;
        if (hasPair == 0 && data_02175680[i].mUnk_00 < 5) {
            noPairForFewCalls = TRUE;
        }
        if (noPairForFewCalls == FALSE && data_0217567c[i].mUnk_00 == 0 && hasPair != 0) {
            newPair = TRUE;
        }
        if (newPair == FALSE ||
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
    if (hitRectIndex <= 4) {
        row = data_0215cdd8[hitRectIndex];
        if (GetSelectRaceRuleHumanCount() != 8 || row != 1) {
            gSelectRaceRule->mRow = row;
            gSelectRaceRule->mOnButton = 0;
            MoveSelectRaceRuleValuePrevious(1);
        }
    } else if (hitRectIndex - 5 <= 4) {
        row = data_0215cd24[hitRectIndex];
        if (GetSelectRaceRuleHumanCount() != 8 || row != 1) {
            gSelectRaceRule->mRow = row;
            gSelectRaceRule->mOnButton = 0;
            MoveSelectRaceRuleValueNext(1);
        }
    } else if (hitRectIndex == 0x13) {
        if (gSelectRaceRule->mOnButton != 0) {
            gSelectRaceRule->mUnk_84 = 0;
        }
        gSelectRaceRule->mOnButton = 1;
        RequestSelectRaceRuleState4();
    } else if (hitRectIndex - 10 <= 4) {
        row = data_0215cd74[hitRectIndex].mUnk_00;
        if (GetSelectRaceRuleHumanCount() != 8 || row != 1) {
            gSelectRaceRule->mRow = row;
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
    } else if (hitRectIndex == 0xf) {
        if (gSelectRaceRule->mRowValues[3] != SELECT_RACE_RULE_FREE) {
            gSelectRaceRule->mRow = 3;
            gSelectRaceRule->mOnButton = 0;
            DecrementSelectRaceRuleCourseCount();
        }
    } else if (hitRectIndex == 0x10) {
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
    int state1WithoutRequest;
    state1WithoutRequest = IsSelectChoisesState1NoState0Request();
    if (state1WithoutRequest != 0) {
        RequestSelectRaceRuleState6();
    }
}

#pragma thumb off
