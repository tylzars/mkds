#pragma once

#include "types.h"

typedef s32 UnkCompare(const void *a, const void *b);

#include "00/code_0218d000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_021a3678.h"
#include "00/code_021a3690.h"
#include "00/code_0218dc44.h"

void *func_ov000_0218d818(const void *a, u8 *b, s32 c, s32 d, UnkCompare *e, s32 *f);
void *func_ov000_0218d86c(const void *a, u8 *b, s32 c, s32 d, UnkCompare *e);
void func_ov000_0218d8b4(int *a);
void *func_ov000_0218d8dc(int *a, UnkCompare *b, const void *c);
void func_ov000_0218d938(int *a, UnkCompare *b, const void *c);
s32 func_ov000_0218d980(int *a, const void *b, UnkCompare *c, s32 d, s32 e);
void func_ov000_0218da04(unsigned int p0, unsigned int p1);
void func_ov000_0218da1c(Unk0218dc94 *a, const void *b, s32 c);
void func_ov000_0218da5c(Unk0218dc94 *a, s32 b);
void func_ov000_0218da9c(int *a, int b);
void func_ov000_0218daf8(u32 *a, u32 b, int c);
