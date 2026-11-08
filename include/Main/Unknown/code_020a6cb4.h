#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Object of the list func_02100138(0x6b): the shared MapObject part, then three words.
typedef struct Unk020a6cb4 {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ BOOL mHasShine;
    /* a4 */ BOOL mUnk_a4;
    /* a8 */ s32 mShineStartFrames;
} Unk020a6cb4;

void func_020a6cb4(s32 a);
void *CreateShineBattleUpdateList(void);
s32 CreateShineBattleKindData(void);
void func_020a6d8c(MapObjectList *a, Unk020a6cb4 *b);
void func_020a6e70(MapObjectList *a);
BOOL TryStartShine16AtRandomObject(MapObjectList *a);
