#pragma once

#include "types.h"
#include "code_020184e4.h"

// The Stadium course emitters: six directions, the six emitters now running, and the countdown to the next round.
typedef struct StadiumEmitters {
    /* 00 */ Vec3 mDirections[6];
    /* 48 */ Unk0201ca6c *mEmitters[6];
    /* 60 */ s16 mEmitterTimer;
    /* 62 */ u8 mUnk_62[2];
} StadiumEmitters;

// Two halfwords at data_usa_021660f8.
typedef struct Unk021660f8 {
    s16 mUnk_00[2];
} Unk021660f8;

// Twenty-four halfwords at data_usa_02166108.
typedef struct Unk02166108 {
    s16 mUnk_00[24];
} Unk02166108;

// Function stored at gGetSPLManagerFunction: writes a word to the first argument and returns the object.
typedef SPLManager *Unk0217b050Func(s32 *a, s32 b);
extern Unk0217b050Func *gGetSPLManagerFunction;

extern StadiumEmitters *data_0217b048;
extern char data_usa_021660c8[];
extern char data_usa_021660e0[];
extern Unk021660f8 data_usa_021660f8;
extern Unk02166108 data_usa_02166108;
extern s32 data_usa_02155f48[];
extern Vec3 data_usa_02155f78[];
extern Vec3 data_usa_02155fc0;

void CopyKartPhysicalParams(u32 slot, u32 kartRow, u32 characterRow);
void CreateKartPhysicalParamTable(void *heap, u32 entryCount);
void CreateAwardEmitters(void);
void AdvanceStadiumEmitters(void);
SPLManager *GetSPLManagerForEffectId(s32 *outIndex, s32 effectId);
