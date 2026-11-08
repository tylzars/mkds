#pragma once

#include "types.h"

void InitStateMachine(void *rawStateMachine, UnkFunc *const *stateTable, s32 stateCount, void *object);
