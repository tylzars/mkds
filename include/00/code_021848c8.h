#pragma once

#include "types.h"

typedef struct Unk021b0cd4 Unk021b0cd4;

extern Unk021b0cd4 gSelectCharacterCallbacks;

void RegisterSelectCharacterCallbacks(void);
void func_ov000_021848ec(void);
void AdvanceWiFiSelectCharacterState(void);
void func_ov000_02184934(void);
void func_ov000_02184938(void);
void InitWiFiSelectCharacterState(void *a);
