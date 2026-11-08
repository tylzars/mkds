#pragma once

#include "types.h"
#include "Main/Unknown/code_020de588.h"
#include "Main/Unknown/code_020de214.h"

void func_020df3f8(void);
Unk020de390 *CreateItemBoxKindData(void);
MapObjectDrawList *CreateBoxDrawList(void);
MapObjectDrawList *CreateQuestionDrawList(void);
MapObjectDrawList *func_020df294(void);
Unk020de2d8 *CreateItemBoxUpdateList(void);
void SetupDrawBox(void);
void DrawBox(void *unused0, ItemBox *itemBox, void *unused1, u16 d);
void SetupDrawQuestion(void);
void DrawQuestion(void *unused0, ItemBox *itemBox, void *unused1, u16 d);
void func_020dee8c(void);
void func_020dec4c(void *unused, ItemBox *itemBox, u32 c, u32 d);
void UpdateItemBox(void *unused, ItemBox *itemBox);
