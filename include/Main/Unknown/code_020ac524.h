#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Object of the list FindMapObjectKindUpdateList(0x70): the shared MapObject part, then the words and the pointer
// StartShineBalloon sets.
typedef struct ShineBalloonObject {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ s32 mTimer;
    /* ac */ Kart *mUnk_ac;
    /* b0 */ s32 mState;
} ShineBalloonObject;

void *FindParkedMapObject(s32 a);
void CreateParkedMapObjects(u32 a, s32 b, void *c);
void StartShineBalloon(Kart *a);
void *CreateShineBalloonUpdateList(void);
void *CreateShineBalloonDrawList(void);
