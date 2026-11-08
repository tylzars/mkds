#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020cffd0.h"
#include "Main/Unknown/code_020b4000.h"

// Object behind gEndingStaffRoll.
typedef struct EndingStaffRollObject {
    /* 000 */ s32 mStaffRollFrames;
    /* 004 */ Nclr *mEndingStaffRollMO00Nclr;
    /* 008 */ Ncgr *mEndingStaffRollM00Ncgr;
    /* 00c */ Unk020224e0_c *mCell;
    /* 010 */ RaceHudOamBuffer mOamBuffer;
} EndingStaffRollObject;

u16 UpdateEndingStaffRoll(void);
void DrawEndingStaffRoll(void);
