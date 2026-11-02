#pragma once

#include "types.h"
#include "00/code_02180608.h"

extern Unk021b0cd4 gSelectCharacterCallbacks;

void RegisterSelectCharacterCallbacks(void);
void func_ov000_021848ec(void);
void AdvanceWiFiSelectCharacterState(void);
void func_ov000_02184934(void);
void func_ov000_02184938(void);
void InitWiFiSelectCharacterState(void *a);
