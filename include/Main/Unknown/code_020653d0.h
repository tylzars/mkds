#pragma once

#include "types.h"

typedef struct Kart Kart;

// Second parameter of func_020653d0.
typedef struct ParticipantKartRecord {
    /* 00 */ s16 mPosX;
    /* 02 */ s16 mPosY;
    /* 04 */ s16 mPosZ;
    /* 06 */ s16 mForwardSpeed;
    /* 08 */ s16 mTurnAngle;
    /* 0a */ u16 mHeadingAngle;
    /* 0c */ u32 mFlags;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
} ParticipantKartRecord;

void func_020653d0(Kart *kart, ParticipantKartRecord *record, s32 stepCount);
