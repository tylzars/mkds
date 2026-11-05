#pragma once

#include "types.h"

typedef struct Gt2Socket Gt2Socket;

void SetIncomingConnectionCallback(Gt2Socket *a, void *b);
void DeleteSocket(Gt2Socket *a);
