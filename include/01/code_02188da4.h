#pragma once

#include "types.h"

typedef struct Unk02188950 Unk02188950;

void func_ov001_02188da4(Unk02188950 *mapObject, UnkFunc *callback);
void SetCourseCollisionCallback(Unk02188950 *mapObject, void (*callback)(Unk02188950 *));
void SetStoppedCallback(Unk02188950 *mapObject, UnkFunc *callback);
