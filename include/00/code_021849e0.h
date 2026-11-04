#pragma once

#include "types.h"

typedef struct Unk021b0cd4 Unk021b0cd4;

extern Unk021b0cd4 gSelectKartCallbacks;

void RegisterSelectKartCallbacks(void);
void func_ov000_02184a04(void);
void AdvanceWiFiSelectKartState(void);
void func_ov000_02184a50(void);
void func_ov000_02184a54(void);
void InitWiFiSelectKartState(void *a);
