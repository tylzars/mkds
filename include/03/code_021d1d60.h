#pragma once

#include "types.h"

typedef struct PointerStack PointerStack;

PointerStack *CreateFilledPointerStack(s32 count, void *buffer, s32 stride);
