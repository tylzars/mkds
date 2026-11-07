#pragma once

#include "types.h"
#include "Main/Unknown/code_020de214.h"
#include "Main/Unknown/code_020df48c.h"
#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/unk_02158000.h"

void func_020dffac(Unk020e005c *a);
void func_020dff88(void *a);
u32 IsKoopaBlockKind(u32 a);
s32 func_020dff4c(Unk020e005c *a);
void CreateKoopaBlock(void);
void InitKoopaBlock(Unk020e005c *a, CourseMapRow *b);
Unk020de390 *CreateMkdEfBubbleKindData(void);
Unk020de334 *CreateMkdEfBubbleDrawList(void);
Unk020dfc44 *CreateMkdEfBubbleUpdateList(void);
/* writes the polygon alpha cap (mUnk_030 of its effect record), read only by draw routines */
void DrawMkdEfBubble(void *a, MkdEfBubbleObject *b, void *c, s32 d);
void func_020dfae4(void);
void UpdateMkdEfBubble(void *a, MkdEfBubbleObject *b); /* skipped for objects with mFlags & 4 (parked pool objects) */
void EnterMkdEfBubbleState0(MkdEfBubbleObject *a);
void UpdateMkdEfBubbleState0(MkdEfBubbleObject *a);
