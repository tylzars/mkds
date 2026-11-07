#pragma once

#include "types.h"

typedef struct MicBuffer MicBuffer;

void StopMicAutoSampling(MicBuffer *micBuffer);
void StartMicAutoSampling(MicBuffer *micBuffer);
void func_0210f114(MicBuffer *micBuffer);
