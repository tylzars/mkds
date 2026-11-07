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
void func_0211d66c(void);
void func_0211d844(s16 a);
void func_0211d910(s16 a);
void AdvanceSelectRaceRuleHighlight(void);
void LookupSelectRaceRuleNscrRect(SelectRaceRuleNscrRect *a, s32 b);
