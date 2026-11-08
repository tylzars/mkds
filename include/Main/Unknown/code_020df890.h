#pragma once

#include "types.h"
#include "Main/Unknown/code_020de214.h"
#include "Main/Unknown/code_020df48c.h"
#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/unk_02158000.h"

void UpdateKoopaBlockState2(Unk020e005c *koopaBlock);
void DrawAllKoopaBlocks(void *viewMatrix);
u32 IsKoopaBlockKind(u32 kind);
s32 func_020dff4c(Unk020e005c *koopaBlock);
void CreateKoopaBlock(void);
void InitKoopaBlock(Unk020e005c *koopaBlock, CourseMapRow *courseRow);
MapObjectKindData *CreateMkdEfBubbleKindData(void);
MapObjectDrawList *CreateMkdEfBubbleDrawList(void);
Unk020dfc44 *CreateMkdEfBubbleUpdateList(void);
/* writes the polygon alpha cap (mUnk_030 of its effect record), read only by draw routines */
void DrawMkdEfBubble(void *a, MkdEfBubbleObject *bubble, void *c, s32 alpha);
void AdvanceMkdEfBubbleAnimation(void);
void UpdateMkdEfBubble(void *a,
                       MkdEfBubbleObject *bubble); /* skipped for objects with mFlags & 4 (parked pool objects) */
void EnterMkdEfBubbleState0(MkdEfBubbleObject *bubble);
void UpdateMkdEfBubbleState0(MkdEfBubbleObject *bubble);
