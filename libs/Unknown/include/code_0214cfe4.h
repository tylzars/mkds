#pragma once

#include "types.h"

void MemFillHalfwords(u16 value, void *dst, s32 size);
void MemCopyHalfwords(const void *src, void *dst, s32 size);
