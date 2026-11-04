#pragma once

#include "types.h"

u32 Crc32(const u32 *a, const void *b, u32 c);
u16 Crc16(const u16 *a, const u8 *b, u32 c);
u8 Crc8(const u8 *a, const void *b, u32 c);
void Crc32Continue(const u32 *a, u32 *b, const u8 *c, u32 d);
void Crc32InitTable(u32 *a, u32 b);
void Crc16Continue(const u16 *a, u16 *b, const u8 *c, u32 d);
void Crc16InitTable(u16 *a, u32 b);
void Crc8Continue(const u8 *a, u8 *b, const u8 *c, u32 d);
void Crc8InitTable(u8 *a, u32 b);
