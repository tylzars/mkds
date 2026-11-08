#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020de214.h"
#include "Main/Unknown/code_020de588.h"
#include "Main/Unknown/code_020e516c.h"
#include "Main/Unknown/code_020f9c6c.h"

// Object at 0xe8 and 0xec of MkdEfBubbleObject: a word at 0x24.
typedef struct Unk020df6c8_e8 {
    /* 00 */ u8 mUnk_00[0x24];
    /* 24 */ u32 mUnk_24;
} Unk020df6c8_e8;

// Object of at least 0xf4 bytes, made by CreateMapObject and filled in by InitMkdEfBubble.
typedef struct MkdEfBubbleObject {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ u16 mUnk_a8;
    /* aa */ u8 mUnk_aa[2];
    /* ac */ s32 mUnk_ac;
    /* b0 */ ShadowMatrix mUnk_b0;
    /* e4 */ u8 mUnk_e4;
    /* e5 */ u8 mUnk_e5[3];
    /* e8 */ Unk020df6c8_e8 *mUnk_e8;
    /* ec */ Unk020df6c8_e8 *mUnk_ec;
    /* f0 */ s32 mUnk_f0;
} MkdEfBubbleObject;

void CreateMkdEfBubble(void);
void InitMkdEfBubble(MkdEfBubbleObject *bubble, CourseMapRow *row);
MapObjectKindData *CreateGroupItemBoxKindData(void);
MapObjectList *CreateGroupItemBoxUpdateList(void);
void func_020df58c(void);
void UpdateGroupItemBox(void *unused, ItemBox *itemBox);
