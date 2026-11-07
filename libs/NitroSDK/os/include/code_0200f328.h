#pragma once

#include "types.h"

// Returns cp15 c9,c1,0 (data TCM region) with the low 12 bits cleared.
u32 OS_GetDTCMAddress(void);
// Sets bit 0 of cp15 c1,c0,0.
void OS_EnableProtectionUnit(void);
// Clears bit 0 of cp15 c1,c0,0.
void OS_DisableProtectionUnit(void);
// Writes param to cp15 c6,c1,0.
void OS_SetProtectionRegion1(u32 param);
// Writes param to cp15 c6,c2,0.
void OS_SetProtectionRegion2(u32 param);
void OSi_ExceptionHandler(void);
