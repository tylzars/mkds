#pragma once

#include "types.h"

typedef struct PointerStack PointerStack;

void *PopPointerStack(PointerStack *stack);
void PushPointerStack(PointerStack *stack, void *pointer);
