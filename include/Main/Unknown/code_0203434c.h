#pragma once

#include "types.h"

typedef struct SceneNumbersView SceneNumbersView;

// What GetSlotGhostBuffer returns points to one: func_02034370 sets bit 0 of the word at 0x08.
typedef struct Unk0202ddd8 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u32 mUnk_08_0 : 1;
    /* 08 */ u32 mUnk_08_1 : 31;
} Unk0202ddd8;

void func_0203434c(void);
s32 func_02034370(SceneNumbersView *sceneNumbers);
