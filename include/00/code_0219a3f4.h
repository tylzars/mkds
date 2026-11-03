#pragma once

#include "types.h"

typedef struct Gt2Socket Gt2Socket;

void SetIncomingConnectionCallback(int a, u32 b);
void DeleteSocket(Gt2Socket *a);
