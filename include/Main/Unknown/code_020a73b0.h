#pragma once

#include "types.h"
#include "Main/Unknown/code_020a7000.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObjectList

void UpdateSanbo(void *a, Sanbo *p); /* skipped for objects with mFlags & 4 (parked pool objects) */
s32 func_020a7894(s32 a, s32 b);
s32 func_020a78b0(s32 a);
void InitSanboObjects(MapObjectList *l);
void DrawSanbo(void *a, Sanbo *p);
