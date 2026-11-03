#pragma once

#include "types.h"

typedef struct Gt2Socket Gt2Socket;
typedef struct Gt2Connection Gt2Connection;

u32 func_ov000_0219a0d0(Gt2Connection **a, u32 *b);
u32 func_ov000_0219a110(u32 *c, u32 d, int f, u32 g, u32 h);
void func_ov000_0219a220(Gt2Connection *a);
u32 CreateConnection(Gt2Socket *a, Gt2Connection **b, u32 c, u32 d);
