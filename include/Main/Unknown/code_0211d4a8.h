#pragma once

#include "types.h"

typedef struct SelectRaceRuleRowEntries {
    /* 00 */ u16 mEntryIndices[2];
} SelectRaceRuleRowEntries;

extern SelectRaceRuleRowEntries gSelectRaceRuleRowEntries[];

// Fixed-address object read by MoveSelectRaceRuleRowPrevious and MoveSelectRaceRuleRowNext.
typedef struct Unk027ffc40 {
    /* 00 */ u16 mUnk_00;
} Unk027ffc40;

void MoveSelectRaceRuleRowPrevious(void);
void MoveSelectRaceRuleRowNext(void);
