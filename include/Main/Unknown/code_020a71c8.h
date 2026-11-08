#pragma once

#include "types.h"

void ShineEndCallback(void);
void ShineKartEliminatedCallback(u16 a);
BOOL ShineKartHitCallback(u16 a, u16 b);
void *CreateSanboUpdateList(void);
void *CreateSanboDrawList(void);
