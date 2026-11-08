#pragma once

#include "types.h"

void SetupTxtSystemSubTextButtonEx(void *text, void *buttonText, u32 mainBlendPlanes, u32 subBlendPlanes,
                                   u32 openFromIndex, u32 closeToIndex);
void SetupTxtSystemSubTextTwoButtons(void *text, void *buttonText, void *secondButtonText, s32 selectedIndex);
void SetupTxtSystemSubTextTwoButtonsEx(void *text, void *buttonText, void *secondButtonText, u32 selectedIndex,
                                       u32 mainBlendPlanes, u32 subBlendPlanes, u32 openFromIndex, u32 closeToIndex);
void RequestTxtSystemClose(void);
s32 IsTxtSystemState2NoCloseRequest(void);
s32 IsTxtSystemState0NoOpenRequest(void);
s32 IsTxtSystemState2AfterState1(void);
