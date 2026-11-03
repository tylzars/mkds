#pragma once

#include "types.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_021258f0.h"
#include "01/code_02193000.h"
#include "01/code_0219853c.h"
#include "01/code_02198854.h"
#include "01/code_02199964.h"
#include "01/code_0219d5dc.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_02125da0.h"
#include "00/code_02182fdc.h"
#include "01/code_0219e824.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020472a8.h"

void func_ov001_02192e78(u16 a);
int func_ov001_02192e84(void);
u32 GetOptionPrevState(void);
void RequestOptionState(u32 a);
void SetOptionStateCallbacks(UnkFunc **a);
void func_ov001_02192ec4(void);
void AdvanceOptionStates(void);
void func_ov001_02192f8c(void);
void InitOptionStates(void *heap, s16 a);
void func_ov001_021930ac(void);
void LoadOptionData(void);
void ClearOptionStateCallbacks(void);
