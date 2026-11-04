#pragma once

#include "types.h"

typedef struct Gt2Buffer Gt2Buffer;

extern const s8 data_ov000_021b3e6c[];
extern const char data_ov000_021b3e90[];
extern const char data_ov000_021b3e98[];
extern const char data_ov000_021b3ea4[];
extern const char data_ov000_021b3ec8[];
extern const char data_ov000_021b3eec[];

s8 *func_ov000_02197b34(s8 *a, const s8 *b);
s8 *func_ov000_02197be0(s8 *buffer);
BOOL func_ov000_02197ca0(const s8 *a);
void RemoveBufferBytes(Gt2Buffer *buffer, int start, int shortenBy);
void AppendBufferBytes(Gt2Buffer *buffer, const u8 *b, int len);
