#pragma once

#include "types.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h" // Unk02175620_bc

// A position on point links: the current link, the previous link and the direction from one to the other.
typedef struct LinkCursor {
    /* 00 */ Unk02175620_bc *mLink;
    /* 04 */ Unk02175620_bc *mPreviousLink;
    /* 08 */ Vec3 mDirection;
    /* 14 */ Unk02175620_bc *mRequestedLink;
    /* 18 */ BOOL mUnk_18;
} LinkCursor;

#include "Main/Unknown/code_02080b1c.h"

void SetupPointLinkCursor(Unk02080b1c *cursor, u32 kartIndex, Unk02080b1c_00 *link);
void AdvanceBattlePointLinkCursorTo(LinkCursor *p, Unk02175620_bc *a);
s32 func_020800a0(LinkCursor *p);
