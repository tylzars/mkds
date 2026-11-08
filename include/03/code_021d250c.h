#pragma once

#include "types.h"

typedef struct Rect Rect;

void ComputeRectFromOriginAndSize(u16 *origin, u16 *size, Rect *rect);
void SetRectCorners(s32 left, s32 top, s32 right, s32 bottom, u16 *corners);
void SetPosition(u16 positionX, u16 positionY, u16 *output);
