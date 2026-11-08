#pragma once

#include "types.h"

typedef struct Unk02188950 Unk02188950;

void StartStateFrameCountCallback(Unk02188950 *mapObject, s32 frameCount, void (*callback)(Unk02188950 *));
void func_ov001_02188e48(Unk02188950 *mapObject, s32 firstFrameIndex, void (*firstCallback)(Unk02188950 *),
                         s32 secondFrameIndex, void (*secondCallback)(Unk02188950 *));
void SetAnimationFrameCallback(Unk02188950 *mapObject, s32 frameIndex, UnkFunc *callback);
