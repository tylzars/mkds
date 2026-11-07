#pragma once

#include "types.h"

void SetupTxtSystemSubTextButtonEx(void *a, void *b, u32 c, u32 d, u32 e, u32 f);
void SetupTxtSystemSubTextTwoButtons(void *a, void *b, void *c, s32 d);
void SetupTxtSystemSubTextTwoButtonsEx(void *a, void *b, void *c, u32 d, u32 e, u32 f, u32 g, u32 h);
void RequestTxtSystemClose(void);
s32 IsTxtSystemState2NoCloseRequest(void);
s32 IsTxtSystemState0NoOpenRequest(void);
s32 IsTxtSystemState2AfterState1(void);
