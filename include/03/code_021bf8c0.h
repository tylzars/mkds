#pragma once

#include "types.h"
#include "03/code_021d3488.h"

void InitHlScr(void);
void UpdateLinkLevel(void);
void ReleaseLinkLevel(void);
void CreateLinkLevel(int row);
void ReleaseEditKeyboard(u32 task);
void AdvanceEditKeyboardSlideOutRow0(Unk021d34e0 *task);
void AdvanceEditKeyboardSlideOutRow1(Unk021d34e0 *task);
void AdvanceEditKeyboardSlideOutRow2(Unk021d34e0 *task);
void AdvanceEditKeyboardSlideOutRow3(Unk021d34e0 *task);
void AdvanceEditKeyboardSlideOutRow4(Unk021d34e0 *task);
void MoveEditKeyboardCursor(int direction);
void PlaceEditKeyboardCursor(void);
void SetEditKeyboardKeyHighlight(int keyIndex, int highlight);
void ChangeEditKeyboardPage(int page);
void SetEditKeyboardRowY(u32 page, s32 row, u32 yPos);
void func_ov003_021c0318(void);
