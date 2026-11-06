#pragma once

#include "types.h"
#include "Main/Unknown/code_020a2e4c.h" // Balloon

void func_020a2f30(Balloon *a, u16 b, s32 c);
void func_020a2f9c(Balloon *a, u16 b, s32 c);
Balloon *func_020a2fe4(u16 a, Vec3 *b);
void func_020a305c(void);
void *func_020a3114(void);
void *func_020a3130(void);
void UpdateBalloon(void *p, Balloon *a); /* skipped for objects with mFlags & 4 (parked pool objects) */
void func_020a35b0(Balloon *a);
