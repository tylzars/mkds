#pragma once

#include "types.h"
#include "Main/Unknown/code_020de588.h"
#include "Main/Unknown/code_020de214.h"

void func_020df3f8(void);
Unk020de390 *CreateItemBoxKindData(void);
Unk020de334 *CreateBoxDrawList(void);
Unk020de334 *CreateQuestionDrawList(void);
Unk020de334 *func_020df294(void);
Unk020de2d8 *CreateItemBoxUpdateList(void);
void SetupDrawBox(void);
void DrawBox(void *a, Unk020de6a8 *b, void *c, u16 d);
void SetupDrawQuestion(void);
void DrawQuestion(void *a, Unk020de6a8 *b, void *c, u16 d);
void func_020dee8c(void);
void func_020dec4c(void *a, Unk020de6a8 *b, u32 c, u32 d);
void UpdateItemBox(void *a, Unk020de6a8 *b);
