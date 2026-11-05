#pragma once

#include "types.h"
#include "Main/Unknown/code_020a2e4c.h" // Balloon

// Object CreateBalloon sets the word at 0x1c of.
typedef struct Unk020a3eb8 {
    /* 00 */ u8 mUnk_00[0x1c];
    /* 1c */ s32 mUnk_1c;
} Unk020a3eb8;

void DrawBalloon(void *p, Balloon *a);
void func_020a3e38(void *p);
void CreateBalloon(Unk020a3eb8 *a); /* also sets word +0x1c of the group record to 1 */
