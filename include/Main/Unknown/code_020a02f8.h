#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Object with the MapObject base at 0x00 (func_020a0318, func_020a066c, func_020a089c).
typedef struct Unk020a0318 {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ s32 mUnk_a8;
    /* ac */ s32 mUnk_ac;
    /* b0 */ s32 mUnk_b0;
    /* b4 */ s32 mUnk_b4;
    /* b8 */ BOOL mUnk_b8;
    /* bc */ u16 mUnk_bc;
    /* be */ u16 mUnk_be;
    /* c0 */ s32 mUnk_c0;
    /* c4 */ s32 mUnk_c4;
    /* c8 */ s32 mUnk_c8;
} Unk020a0318;

// Array of object pointers: pointer to the array and the number of entries (func_020a066c).
typedef struct Unk020a066c {
    /* 00 */ Unk020a0318 **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk020a066c;

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
#include "Main/Unknown/code_020b502c.h" // Unk02175620_84

u32 func_020a02f8(void);
void func_020a0318(void *a, Unk020a0318 *p);
void func_020a066c(Unk020a066c *p);
void func_020a089c(Unk020a0318 *p);
// Steps Standings once per UpdateRace call in battle and mission run: the end timer and end callback, the hand- over of
// eliminated karts, the hit tracking, and the copy of each kart's position.
void UpdateStandings(void);
// Ends the Standings end timer (mEndTimer = -1) and runs mEndCallback when it is set; the mode 4 end step of the race
// progress calls it.
void FinishStandings(void);
void InitStandings(void);
Unk02175620_84 *func_020a0f0c(void);
Vec3 *GetKartStandingPos(int arg0);
void func_020a1748(u16 a);
void func_020a1790(void);
void EliminateKart(u16 a);
void func_020a19f8(u16 a);
void func_020a1b6c(u16 a);
u16 func_020a1cd8(s32 a);
void func_020a1ddc(s32 a);
unsigned int func_020a1e3c(unsigned int p0);
