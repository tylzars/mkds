#pragma once

#include "types.h"

// Called once from the start-up chain. Calls MI_SetWramBank(3) and MI_StopDma(0).
void MI_Init(void);
