#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0207ffa4.h"

// LinkCursor followed by a halfword at 0x1c and a byte at 0x1e.
typedef struct Unk02080d34 {
    /* 00 */ LinkCursor mUnk_00;
    /* 1c */ u16 mKartIndex;
    /* 1e */ u8 mUnk_1e;
} Unk02080d34;

void ResetPointLinkCursor(LinkCursor *p, PointLink *a);
void InitRacePointLinkCursor(Unk02080d34 *p, u16 kartIndex);
s32 IsPastBattlePointLink(LinkCursor *p, Vec3 *a);
s32 IsWithinBattlePointLinkDistance(LinkCursor *p, Vec3 *a);
void func_02080e88(Unk0206c1ac *p, Kart *q);
void func_02080e9c(Kart *p);
void func_02080ee4(Kart *p);
void func_02080f44(Kart *p);
void func_02080fb8(Kart *p);
void func_02081000(Kart *p);
void func_02081060(Kart *p);
