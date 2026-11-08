#pragma once

#include "types.h"

// Rectangle of the ScreenMap behind one row, with the top bits it is filled with plain and highlighted.
typedef struct SelectRaceRuleNscrRect {
    /* 00 */ u32 mFirstColumn;
    /* 04 */ u32 mFirstRow;
    /* 08 */ u32 mColumnCount;
    /* 0c */ u32 mRowCount;
    /* 10 */ u16 mTopBits;
    /* 12 */ u16 mHighlightedTopBits;
} SelectRaceRuleNscrRect;

extern SelectRaceRuleNscrRect gSelectRaceRuleSMenuNscrRects[];
extern SelectRaceRuleNscrRect gSelectRaceRuleMultiSimpleNscrRects[];

void AdvanceSelectRaceRuleState5(void);
u16 GetSelectRaceRuleHumanCount(void);
void AdvanceSelectRaceRuleValueObjects(void);
void SetAndPrintSelectRaceRuleRaceCount(s16 count);
void SetAndPrintSelectRaceRuleWinCount(s16 count);
void AdvanceSelectRaceRuleHighlight(void);
void LookupSelectRaceRuleNscrRect(SelectRaceRuleNscrRect *outRect, s32 row);
