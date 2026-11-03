#pragma once

#include "types.h"

typedef struct Gt2Buffer Gt2Buffer;

void AppendBufferU16(Gt2Buffer *a, s32 b);
void AppendBufferByte(Gt2Buffer *a, u8 b);
int GetBufferUnusedSize(Gt2Buffer *a);
u32 InitBuffer(Gt2Buffer *a, int b);
