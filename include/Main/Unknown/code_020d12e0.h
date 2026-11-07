#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020cffd0.h"
#include "Main/Unknown/code_020b4000.h"

// Object behind gEndingStaffRoll.
typedef struct Unk0217b4ac {
    /* 000 */ s32 mUnk_00;
    /* 004 */ Nclr *mEndingStaffRollMO00Nclr;
    /* 008 */ Ncgr *mEndingStaffRollM00Ncgr;
    /* 00c */ Unk020224e0_c *mUnk_0c;
    /* 010 */ RaceHudOamBuffer mUnk_10;
} Unk0217b4ac;

u16 UpdateEndingStaffRoll(void);
void DrawEndingStaffRoll(void);
