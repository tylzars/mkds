#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0207ffa4.h"

// LinkCursor followed by a halfword at 0x1c and a byte at 0x1e.
typedef struct Unk02080d34 {
    /* 00 */ LinkCursor mLinkCursor;
    /* 1c */ u16 mKartIndex;
    /* 1e */ u8 mUnk_1e;
} Unk02080d34;

void ResetPointLinkCursor(LinkCursor *linkCursor, PointLink *pointLink);
void InitRacePointLinkCursor(Unk02080d34 *racePointLinkCursor, u16 kartIndex);
BOOL IsPastBattlePointLink(LinkCursor *linkCursor, Vec3 *position);
BOOL IsWithinBattlePointLinkDistance(LinkCursor *linkCursor, Vec3 *position);
void func_02080e88(Unk0201ca6c *effect, Kart *kart);
void func_02080e9c(Kart *kart);
void func_02080ee4(Kart *kart);
void func_02080f44(Kart *kart);
void func_02080fb8(Kart *kart);
void func_02081000(Kart *kart);
void func_02081060(Kart *kart);
