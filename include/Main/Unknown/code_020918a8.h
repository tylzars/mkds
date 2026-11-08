#pragma once

#include "types.h"
#include "Main/Unknown/code_020d22c0.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

// Object of 0xb0 bytes: the MapObject it starts with, then a halfword and three words.
typedef struct Unk020919e8 {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ u16 mUnk_a0;
    /* a2 */ u8 mUnk_a2[2];
    /* a4 */ s32 mUnk_a4;
    /* a8 */ s32 mUnk_a8;
    /* ac */ s32 mUnk_ac;
} Unk020919e8;

void CreateCowDrawList(void);
void DrawCow(void *a, Unk020919e8 *b);
void SetupDrawCow(void *a);
void CreateCow(void *a);
void CreateKanoke64UpdateList(void);
void CreateKanoke64DrawList(void);
void UpdateKanoke64(void *a, Unk020919e8 *p); /* Unk020919e8 is shared with Cow and kind 0x1a0 */
s16 func_02091f24(s32 angle);
s32 func_02091f44(s32 a, s32 b);
s16 func_02091f54(s32 angle);
u32 NextRandomBelow(RandomState64 *randomState64, u32 limit);
void InitKanoke64Objects(MapObjectList *mapObjectList);
void DrawKanoke64(void *a, Unk020919e8 *p);
void CreateKanoke64(void *a);
