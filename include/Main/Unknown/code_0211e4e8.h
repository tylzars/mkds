#pragma once

#include "types.h"

// Fixed-address objects written by InitSelectCupM.
typedef struct Unk04000008 {
    /* 00 */ vu16 mUnk_00;
} Unk04000008;

typedef struct Unk0400100e {
    /* 00 */ vu16 mUnk_00;
} Unk0400100e;

// Fixed-address objects written by WriteSelectCupMBgOffsets.
typedef struct Unk04000010 {
    /* 00 */ vu32 mUnk_00;
} Unk04000010;

typedef struct Unk0400101c {
    /* 00 */ vu32 mUnk_00;
} Unk0400101c;

void WriteSelectCupMBgOffsets(void);
s32 AdvanceSelectCupM(void);
void AdvanceSelectCupMState1(void);
void AdvanceSelectCupMState0(void);
void ReleaseSelectCupM(void);
void InitSelectCupM(void *a, void *b, void *c);
void StartSelectCupMState1(void);
void StartSelectCupMState0(void);
void InitSelectCupMCellsAndRequestCupPicture(void);
void LocateAndQueueSelectCupM(void);
