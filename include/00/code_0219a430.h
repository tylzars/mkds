#pragma once

#include "types.h"

typedef struct Gt2Socket Gt2Socket;
typedef struct Gt2Connection Gt2Connection;

u32 CreateSocket(Gt2Socket **a, const u8 *b, u32 c, u32 d, u32 e);
Gt2Connection *FindConnection(Gt2Socket *a, u32 b, u32 c);
void func_ov000_0219a5dc(Gt2Connection **a);
