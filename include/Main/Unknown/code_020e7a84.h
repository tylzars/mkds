#pragma once

#include "types.h"

typedef struct Unk020e6514 Unk020e6514;

// A row of gJgKindRows seen at offset 4 or 8: its first word points at an animation object.
typedef struct JgKindRowAnimationView {
    /* 00 */ Unk020e6514 *mUnk_00;
    /* 04 */ u8 mUnk_04[0x0c];
} JgKindRowAnimationView;

// Object at 0x00 of a gJgKindRows row, as DrawJg reads it: the word at 0x04.
typedef struct Unk020e9810 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ void *mUnk_04;
} Unk020e9810;

extern JgKindRowAnimationView gJgKindRowNsbcaAnimations[];
extern JgKindRowAnimationView gJgKindRowNsbmaAnimations[];

void UpdateJgState6(void);
void EnterJgState6(void);
void UpdateJgState5(void);
void EnterJgState5(void);
void UpdateJgState4(void);
void EnterJgState4(void);
void UpdateJgState3(void);
void EnterJgState3(void);
void UpdateJgState2(void);
void EnterJgState2(void);
void UpdateJgState1(void);
void EnterJgState1(void);
unsigned int func_020e8a74(unsigned int value);
void UpdateJgPosition(void);
void ComputeJgMatrixAndInverse(void);
void DrawJg(void);
void UpdateJg(void);
void AdvanceJgPointsAndSetTarget(Vec3 *offset, const Vec3 *endScale, const Vec3 *startScale);
void InitJgOffsets(void);
void CreateModelAnimation(u32 animationKind, void *model, void **animationSlot, void *nsbmdFile, void *animationFile);
