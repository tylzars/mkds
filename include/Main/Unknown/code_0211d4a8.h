#pragma once

#include "types.h"

typedef struct Unk0215cd4c {
    /* 00 */ u16 mUnk_00[2];
} Unk0215cd4c;

extern Unk0215cd4c data_0215cd4c[];

// Fixed-address object read by MoveSelectRaceRuleRowPrevious and MoveSelectRaceRuleRowNext.
typedef struct Unk027ffc40 {
    /* 00 */ u16 mUnk_00;
} Unk027ffc40;

void MoveSelectRaceRuleRowPrevious(void);
void MoveSelectRaceRuleRowNext(void);
